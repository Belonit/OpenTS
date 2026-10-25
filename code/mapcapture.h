/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/


#pragma once


// Renders one map to a PNG for a lobby preview, as a headless task.
namespace MapCapture
{
	void Request_Map(char const * name);
	void Request_Output(char const * path);
}
