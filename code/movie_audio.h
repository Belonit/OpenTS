/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <vector>


struct MovieAudioFormat
{
	int SampleRate = 0;
	int Channels = 0;

	explicit operator bool(void) const { return(SampleRate > 0 && Channels > 0); }
};


class MovieAudioPlayback
{
	private:
		class Implementation;
		std::unique_ptr<Implementation> Impl;

	public:
		MovieAudioPlayback(MovieAudioFormat format, int volume);
		~MovieAudioPlayback(void);

		MovieAudioPlayback(MovieAudioPlayback const &) = delete;
		MovieAudioPlayback & operator=(MovieAudioPlayback const &) = delete;

		void Submit(std::vector<std::int16_t> &&samples);
		void Finish(void);
		bool Needs_Data(void) const;
		bool Start(double position);
		void Update(void);
		void Pause(void);
		void Resume(void);
		bool Is_Finished(void) const;
		bool Has_Failed(void) const;
		std::optional<double> Get_Playback_Position(void);
};
