/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include "movie_audio.h"

#include <cstdint>
#include <memory>
#include <optional>
#include <vector>


enum MoviePixelFormat
{
	MOVIE_PIXEL_RGB565,
	MOVIE_PIXEL_BGRA8888,
};


struct MovieFrame
{
	std::vector<std::uint8_t> Pixels;
	double PresentationTime = 0.0;
	double EndTime = 0.0;
};


class MovieDecoder
{
	private:
		class Implementation;
		std::unique_ptr<Implementation> Impl;

		MovieDecoder(char const * filename, MoviePixelFormat format);

	public:
		~MovieDecoder(void);

		MovieDecoder(MovieDecoder const &) = delete;
		MovieDecoder & operator=(MovieDecoder const &) = delete;

		static std::unique_ptr<MovieDecoder> Create(char const * filename, MoviePixelFormat format, bool decodeaudio);
		bool Pump(bool prefetchaudio);
		bool Has_Frame(void) const;
		MovieFrame const & Frame(void) const;
		MovieFrame Take_Frame(void);
		void Pop_Frame(void);
		std::optional<double> Next_Frame_Time(void) const;

		MovieAudioFormat Get_Audio_Format(void) const;
		std::vector<std::int16_t> Take_Audio(void);
		bool Audio_Finished(void) const;

		int Get_Width(void) const;
		int Get_Height(void) const;
		int Get_Pitch(void) const;
};
