/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include <optional>


enum class MovieFrameAction
{
	Wait,
	Present,
	Drop,
};


constexpr MovieFrameAction Select_Movie_Frame(double clock, double currentpts,
	std::optional<double> nextpts)
{
	if (currentpts > clock) {
		return(MovieFrameAction::Wait);
	}
	if (nextpts.has_value() && *nextpts <= clock) {
		return(MovieFrameAction::Drop);
	}
	return(MovieFrameAction::Present);
}
