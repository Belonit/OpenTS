/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "always.h"

#include "movie_player.h"

#include "_keyboar.h"
#include "_xmouse.h"
#include "ccfile.h"
#include "dsaudio.h"
#include "globals.h"
#include "keyboard.h"
#include "movie.h"
#include "movie_audio.h"
#include "movie_decoder.h"
#include "movie_scheduler.h"
#include "msgloop.h"
#include "surface.h"
#include "theme.h"
#include "vector.h"
#include "video.h"
#include "win.h"

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <deque>
#include <memory>
#include <optional>
#include <string>
#include <thread>
#include <utility>


namespace {

std::deque<std::unique_ptr<MoviePlayback>> InGameMovies;
bool FullscreenMoviePlaying = false;


std::optional<std::string> Find_Movie_File(char const *name)
{
	if (name == nullptr || *name == '\0') {
		return(std::nullopt);
	}

	std::string stem(name);
	std::size_t separator = stem.find_last_of("/\\");
	std::size_t extension = stem.find_last_of('.');
	if (extension != std::string::npos
		&& (separator == std::string::npos || extension > separator)) {
		stem.resize(extension);
	}
	if (stem.empty()) {
		return(std::nullopt);
	}

	static constexpr char const * Extensions[] = {".WEBM", ".BIK", ".VQA"};
	for (char const *candidateextension : Extensions) {
		std::string candidate = stem + candidateextension;
		if (CCFileClass(candidate.c_str()).Is_Available()) {
			return(candidate);
		}
	}
	return(std::nullopt);
}

} // namespace


bool Movie_Is_Available(char const *name)
{
	return(Find_Movie_File(name).has_value());
}


MoviePlayback::MoviePlayback(std::unique_ptr<MovieDecoder> decoder, Surface *surface,
	Rect framerect, Rect displayrect, int volume, bool fullscreen) :
	Decoder(std::move(decoder)),
	AudioPlayback(Decoder->Get_Audio_Format(), volume),
	DrawSurface(surface),
	FrameRect(framerect),
	DisplayRect(displayrect),
	Fullscreen(fullscreen)
{
}


MoviePlayback::~MoviePlayback(void) = default;


MovieAdvance MoviePlayback::Advance(void)
{
	if (Fullscreen) {
		Video_Present_If_Dirty();
	}
	using SteadyClock = std::chrono::steady_clock;
	if (AudioPlayback.Has_Failed()) {
		return(MovieAdvance::Failed);
	}
	if (Is_Paused()) {
		return(MovieAdvance::Waiting);
	}
	if (!Pump_Decoder()) {
		return(MovieAdvance::Failed);
	}

	if (!ClockStarted) {
		WallClockStart = SteadyClock::now();
		ClockStarted = true;
	}
	if (!AudioStarted) {
		AudioStarted = AudioPlayback.Start(Playback_Position(SteadyClock::now()));
		if (AudioPlayback.Has_Failed()) {
			return(MovieAdvance::Failed);
		}
	}

	for (;;) {
		if (!Decoder->Has_Frame()) {
			double position = Playback_Position(SteadyClock::now());
			if (position < LastPresentedFrameEnd) {
				return(MovieAdvance::Waiting);
			}
			return(AudioPlayback.Is_Finished()
				? MovieAdvance::Finished : MovieAdvance::Waiting);
		}

		double position = Playback_Position(SteadyClock::now());
		std::optional<double> nextpts = Decoder->Next_Frame_Time();
		MovieFrameAction action = Select_Movie_Frame(position,
			Decoder->Frame().PresentationTime, nextpts);
		if (action == MovieFrameAction::Wait) {
			return(MovieAdvance::Waiting);
		}
		if (action == MovieFrameAction::Drop) {
			Decoder->Pop_Frame();
			if (!Pump_Decoder()) {
				return(MovieAdvance::Failed);
			}
			continue;
		}
		break;
	}

	MovieFrame const &frame = Decoder->Frame();
	if (!Present_Frame(frame)) {
		return(MovieAdvance::Failed);
	}
	LastPresentedFrameEnd = frame.EndTime;
	LastPresentedFrame = Decoder->Take_Frame();
	return(MovieAdvance::FrameReady);
}


bool MoviePlayback::Redraw(void)
{
	return(LastPresentedFrame.has_value() && Present_Frame(*LastPresentedFrame));
}


void MoviePlayback::Pause(void)
{
	bool waspaused = Is_Paused();
	UserPaused = true;
	Update_Pause_State(waspaused);
}


void MoviePlayback::Resume(void)
{
	bool waspaused = Is_Paused();
	UserPaused = false;
	Update_Pause_State(waspaused);
}


void MoviePlayback::Set_Focused(bool focused)
{
	bool waspaused = Is_Paused();
	FocusPaused = !focused;
	Update_Pause_State(waspaused);
}


void MoviePlayback::Update_Pause_State(bool waspaused)
{
	bool ispaused = Is_Paused();
	if (waspaused == ispaused) {
		return;
	}
	if (ispaused) {
		if (ClockStarted) {
			WallClockOffset = Playback_Position(std::chrono::steady_clock::now());
		}
		AudioPlayback.Pause();
	} else {
		if (AudioStarted) {
			AudioPlayback.Resume();
		}
		WallClockStart = std::chrono::steady_clock::now();
	}
}


bool MoviePlayback::Pump_Decoder(void)
{
	if (!Decoder->Pump(AudioPlayback.Needs_Data())) {
		return(false);
	}
	AudioPlayback.Submit(Decoder->Take_Audio());
	if (Decoder->Audio_Finished()) {
		AudioPlayback.Finish();
	}
	AudioPlayback.Update();
	return(!AudioPlayback.Has_Failed());
}


double MoviePlayback::Playback_Position(std::chrono::steady_clock::time_point now)
{
	std::optional<double> audioposition = AudioPlayback.Get_Playback_Position();
	if (audioposition.has_value()) {
		WallClockOffset = *audioposition;
		WallClockStart = now;
	}
	return(WallClockOffset + std::chrono::duration<double>(now - WallClockStart).count());
}


bool MoviePlayback::Present_Frame(MovieFrame const &frame)
{
	if (Fullscreen) {
		VideoBgraFrameView videoframe = {
			frame.Pixels.data(),
			Decoder->Get_Width(),
			Decoder->Get_Height(),
			Decoder->Get_Pitch(),
		};
		if (!Video_Set_Override_Frame(videoframe, DisplayRect, VIDEO_SCALE_LINEAR)) {
			return(false);
		}
		Video_Present_If_Dirty();
		return(true);
	}

	if (DrawSurface == nullptr) {
		return(false);
	}
	if (FrameRect.Width <= 0 || FrameRect.Height <= 0 || Decoder->Get_Width() <= 0
		|| Decoder->Get_Height() <= 0 || Decoder->Get_Pitch() <= 0) {
		return(false);
	}
	std::int64_t frameleft = FrameRect.X;
	std::int64_t frametop = FrameRect.Y;
	std::int64_t left = std::max(frameleft, std::int64_t(0));
	std::int64_t top = std::max(frametop, std::int64_t(0));
	std::int64_t right = std::min(frameleft + FrameRect.Width, static_cast<std::int64_t>(DrawSurface->Get_Width()));
	std::int64_t bottom = std::min(frametop + FrameRect.Height, static_cast<std::int64_t>(DrawSurface->Get_Height()));
	if (left >= right || top >= bottom) {
		return(false);
	}
	int sourcex = static_cast<int>(left - frameleft);
	int sourcey = static_cast<int>(top - frametop);
	int copywidth = std::min(static_cast<int>(right - left), Decoder->Get_Width() - sourcex);
	int copyheight = std::min(static_cast<int>(bottom - top), Decoder->Get_Height() - sourcey);
	if (copywidth <= 0 || copyheight <= 0) {
		return(false);
	}

	unsigned char *destination = static_cast<unsigned char *>(DrawSurface->Lock());
	if (destination == nullptr) {
		return(false);
	}
	destination += top * DrawSurface->Stride() + left * sizeof(std::uint16_t);
	unsigned char const *source = frame.Pixels.data() + sourcey * Decoder->Get_Pitch() + sourcex * sizeof(std::uint16_t);
	for (int y = 0; y < copyheight; ++y) {
		std::memcpy(destination + y * DrawSurface->Stride(),
			source + y * Decoder->Get_Pitch(),
			copywidth * sizeof(std::uint16_t));
	}
	return(DrawSurface->Unlock());
}


int MoviePlayback::Get_Width(void) const
{
	return(Decoder->Get_Width());
}


int MoviePlayback::Get_Height(void) const
{
	return(Decoder->Get_Height());
}


static std::unique_ptr<MoviePlayback> Create_Movie(char const *name, Surface *surface,
	Rect framerect, Rect displayrect, int volume, bool fullscreen)
{
	if (name == nullptr || surface == nullptr) {
		return(nullptr);
	}
	std::optional<std::string> filename = Find_Movie_File(name);
	if (!filename.has_value()) {
		return(nullptr);
	}

	auto decoder = MovieDecoder::Create(filename->c_str(),
		fullscreen ? MOVIE_PIXEL_BGRA8888 : MOVIE_PIXEL_RGB565,
		Audio_Available());
	if (decoder == nullptr) {
		return(nullptr);
	}

	int width = decoder->Get_Width();
	int height = decoder->Get_Height();
	if (framerect == Rect(0, 0, 0, 0)) {
		framerect = Rect(Point2D(0, 0), width, height);
	}
	if (displayrect == Rect(0, 0, 0, 0)) {
		if (fullscreen) {
			displayrect.Set((surface->Get_Width() - width) / 2,
				(surface->Get_Height() - height) / 2, width, height);
		} else {
			displayrect = framerect;
		}
	}

	return(std::make_unique<MoviePlayback>(std::move(decoder), surface, framerect,
		displayrect, volume, fullscreen));
}


std::unique_ptr<MoviePlayback> Movie_Create_Fullscreen(char const *name, Surface *surface,
	Rect displayrect, int volume)
{
	return(Create_Movie(name, surface, Rect(0, 0, 0, 0), displayrect, volume, true));
}


std::unique_ptr<MoviePlayback> Movie_Create_On_Surface(char const *name, Surface *surface,
	Rect framerect, int volume)
{
	return(Create_Movie(name, surface, framerect, framerect, volume, false));
}


void Movie_Play(MoviePlayback &movie, ThemeType theme)
{
	if (FullscreenMoviePlaying) {
		return;
	}
	FullscreenMoviePlaying = true;

	Hide_Mouse();
	if (theme != THEME_NONE) {
		Theme.Queue_Song(theme);
	}

	KeyNumType const escape_release = static_cast<KeyNumType>(
		static_cast<int>(KN_ESC) | static_cast<int>(WWKEY_RLS_BIT)
	);
	for (;;) {
		Windows_Message_Handler();
		if (Keyboard->Check() && Keyboard->Get() == escape_release) {
			break;
		}

		movie.Set_Focused(GameInFocus);
		MovieAdvance result = movie.Advance();
		if (result == MovieAdvance::Finished || result == MovieAdvance::Failed) {
			break;
		}
		if (result == MovieAdvance::Waiting) {
			std::this_thread::sleep_for(std::chrono::milliseconds(movie.Is_Paused() ? 33 : 1));
		}
	}

	Video_Clear_Override_Frame();
	Show_Mouse();
	FullscreenMoviePlaying = false;
}


void Movie_Queue_InGame(std::unique_ptr<MoviePlayback> movie)
{
	if (movie != nullptr) {
		InGameMovies.push_back(std::move(movie));
	}
}


MoviePlayback * Movie_Get_InGame(void)
{
	return(InGameMovies.empty() ? nullptr : InGameMovies.front().get());
}


void Movie_Remove_InGame(void)
{
	if (!InGameMovies.empty()) {
		InGameMovies.pop_front();
	}
}


void Movie_Clear_InGame(void)
{
	InGameMovies.clear();
}
