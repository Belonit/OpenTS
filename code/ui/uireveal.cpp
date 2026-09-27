/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "ui/uireveal.h"


static const int UI_REVEAL_STEP = 24;
static const int UI_REVEAL_PERIOD = 40;
static const int UI_REVEAL_TIGHTEN = 240;


static int UI_Reveal_Half(float full, float scale)
{
	return((int)(full / scale / 2.0f));
}


static int UI_Reveal_Due(int frame, int half)
{
	int period = UI_REVEAL_PERIOD - (UI_REVEAL_TIGHTEN * frame) / half;
	if (period < 1) {
		period = 1;
	}
	return((frame + 1) * period);
}


float UI_Reveal_Width(float full, float scale, int elapsed, float shown)
{
	if (scale <= 0.0f) {
		scale = 1.0f;
	}

	int half = UI_Reveal_Half(full, scale);
	if (full <= 0.0f || half <= 0 || elapsed < 0) {
		return(full);
	}

	float step = (float)UI_REVEAL_STEP * scale;
	int next = shown <= 0.0f ? 0 : (int)(shown / step + 0.5f);

	int frame = 0;
	int deadline = 0;

	while (frame < next && UI_REVEAL_STEP * frame < half * 2) {
		int due = UI_Reveal_Due(frame, half);
		if (due > deadline) {
			deadline = due;
		}
		if (deadline > elapsed) {
			break;
		}
		frame++;
	}

	float width = (float)(UI_REVEAL_STEP * (frame + 1)) * scale;
	return(width >= full ? full : width);
}


// The original kept its side bars up for one more wait after the last band.
bool UI_Reveal_Finished(float full, float scale, int elapsed)
{
	if (scale <= 0.0f) {
		scale = 1.0f;
	}

	int half = UI_Reveal_Half(full, scale);
	if (full <= 0.0f || half <= 0 || elapsed < 0) {
		return(true);
	}

	int deadline = 0;
	for (int frame = 0; UI_REVEAL_STEP * frame < half * 2; frame++) {
		int due = UI_Reveal_Due(frame, half);
		if (due > deadline) {
			deadline = due;
		}
	}
	return(elapsed >= deadline);
}
