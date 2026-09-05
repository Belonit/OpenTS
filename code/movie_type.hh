/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

#pragma once

/**********************************************************************
**	This is the complete list of movie identifiers allowed in the game.
*/
enum MovieType {
	MOVIE_NONE=-1,

	MOVIE_CAP_TRAT,
	MOVIE_COUP,
	MOVIE_VEGAWIN,
	MOVIE_DISKDEST,
	MOVIE_INTRO,
	MOVIE_GDI_M02,
	MOVIE_GDI_M03,
	MOVIE_GDI_M04,
	MOVIE_GDI_M05,
	MOVIE_GDI_M06,
	MOVIE_GDI_M07,
	MOVIE_GDI_M08,
	MOVIE_GDI_M09A,
	MOVIE_GDI_M09B,
	MOVIE_GDI_M09C,
	MOVIE_GDI_M10A,
	MOVIE_GDIM09CW,
	MOVIE_GDI_M11,
	MOVIE_GDI_M12A,
	MOVIE_HIDESEEK,
	MOVIE_ICESKATE,
	MOVIE_MECHATAK,
	MOVIE_EVA,
	MOVIE_NOD_M02,
	MOVIE_NOD_M03,
	MOVIE_NOD_M04,
	MOVIE_NOD_M06,
	MOVIE_NOWCNOT,
	MOVIE_ORCASTRK,
	MOVIE_PODASSLT,
	MOVIE_RETRBTN,
	MOVIE_TENEVICT,
	MOVIE_TRAINROB,
	MOVIE_NOD06ABW,
	MOVIE_EMPULSE,
	MOVIE_NOD_M09,
	MOVIE_STARTUP,
	MOVIE_ICBMLNCH,
	MOVIE_BEACHEAD,
	MOVIE_GDI_FINL,
	MOVIE_NOD_M05,
	MOVIE_GENNODL1,
	MOVIE_GDIM09D1,
	MOVIE_GDI01_SB,
	MOVIE_GDI02_SB,
	MOVIE_GDI03_SB,
	MOVIE_NOD_M07,
	MOVIE_NOD_M08,
	MOVIE_NOD_M10,
	MOVIE_NOD_M11,
	MOVIE_NOD_M12,
	MOVIE_NOD_FINL,
	MOVIE_NOD01_SB,
	MOVIE_NOD02_SB,
	MOVIE_GENWIN01,
	MOVIE_UFOGUARD,
	MOVIE_WWLOGO,
	MOVIE_KILL_GDI,
	MOVIE_KILLMECH,
	MOVIE_UNSTPBLE,
	MOVIE_N_LOGO_W,
	MOVIE_N_LOGO_L,
	MOVIE_NOD_FLAG,
	MOVIE_GDI_LOGO,
	MOVIE_GDI_FLAG,
	MOVIE_DAMBREAK,

	/*
	**	Firestorm movies start here
	*/
	MOVIE_FSGDIM02,
	MOVIE_FSGDIM03,
	MOVIE_FSGDIM07,
	MOVIE_FSNODM02,
	MOVIE_FSNODM06,
	MOVIE_FS_TITLE,
	MOVIE_FSNODM01,
	MOVIE_FSNODM03,
	MOVIE_FSNODM04,
	MOVIE_FSNODM07,
	MOVIE_FSNODM09,
	MOVIE_FSNODM05,
	MOVIE_FSNODM08,
	MOVIE_MEKATAK2,
	MOVIE_FSGDIM04,
	MOVIE_FSGDIM05,
	MOVIE_FSGDIM06,
	MOVIE_FSGDIM08,
	MOVIE_FSGDIM09,
	MOVIE_FSGDIFNL,
	MOVIE_FSGDIINT,
	MOVIE_FS_SB01,
	MOVIE_TS_TITLE,
	MOVIE_FSNODFNL,

	MOVIE_COUNT,
	MOVIE_FIRST=0
};
