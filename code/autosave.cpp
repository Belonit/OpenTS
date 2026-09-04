/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "autosave.h"


void AutosaveClass::Set_Interval(int frames)
{
	IntervalFrames = frames > 0 ? frames : 0;
}


void AutosaveClass::Seed_Slots(int campaign, int skirmish)
{
	CampaignSlot = Held_Slot(campaign);
	SkirmishSlot = Held_Slot(skirmish);
}


void AutosaveClass::Schedule(int frame)
{
	NextFrame = IntervalFrames > 0 ? frame + IntervalFrames : -1;
	IsArmed = false;
}


bool AutosaveClass::Is_Due(int frame) const
{
	return(!IsArmed && NextFrame >= 0 && frame >= NextFrame);
}


void AutosaveClass::Arm(void)
{
	IsArmed = true;
}


bool AutosaveClass::Take_Armed(void)
{
	bool armed = IsArmed;
	IsArmed = false;
	return(armed);
}


int AutosaveClass::Advance(KindType kind)
{
	int & slot = kind == KindType::Campaign ? CampaignSlot : SkirmishSlot;
	int written = slot;

	slot = (slot + 1) % SLOT_COUNT;

	return(written);
}


/// <summary>
/// The file a slot is written under, counted from one as the client counts it.
/// </summary>
std::string AutosaveClass::File_Name(KindType kind, int slot)
{
	char const * prefix = kind == KindType::Campaign ? "AUTOSAVE" : "AUTOSAVE_SKIRMISH";

	return(prefix + std::to_string(slot + 1) + ".SAV");
}


int AutosaveClass::Held_Slot(int slot)
{
	return(slot >= 0 && slot < SLOT_COUNT ? slot : 0);
}


std::string Quick_Save_File_Name(AutosaveClass::KindType kind)
{
	return(kind == AutosaveClass::KindType::Campaign ? "QUICKSAVE.SAV" : "QUICKSAVE_SKIRMISH.SAV");
}
