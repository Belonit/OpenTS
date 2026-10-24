/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#pragma once

#include "ui/uiscreen.h"

#include <memory>
#include <string>
#include <vector>

class UIViewClass;


struct UIDiplomacyRow
{
	int House = -1;
	std::string Name;
	std::string Color;
	std::string NameTip;
	std::string Kills;

	bool HasAlly = false;
	bool Ally = false;
	bool AllyEnabled = false;
	std::string AllyTip;
	std::string Theirs;
	bool TheirsYes = false;

	bool HasGive = false;
	bool Give = false;
	bool GiveEnabled = false;
	std::string GiveTip;
	std::string Given;
	bool GivenYes = false;

	bool HasChat = false;
	bool Send = false;
	bool Mute = false;

	std::string Latency;
	bool LatencyFair = false;
	bool LatencyPoor = false;
	bool Waiting = false;
	std::string WaitingTip;

	bool operator==(UIDiplomacyRow const &) const = default;
};


struct UIDiplomacyState
{
	std::vector<UIDiplomacyRow> Players;
	std::vector<UIDiplomacyRow> Observers;
	bool ShowControl = false;
	bool ShowChat = false;
	std::string Info;
	std::string Footer;

	bool operator==(UIDiplomacyState const &) const = default;
};


// The game side of the screen; houses are named by heap index.
class UIDiplomacyServiceClass
{
	public:
		virtual ~UIDiplomacyServiceClass(void) = default;
		virtual void Toggle_Alliance(int house) = 0;
		virtual void Toggle_Control(int house) = 0;
		virtual void Set_Sends_To(int house, bool sends) = 0;
		virtual void Set_Muted(int house, bool muted) = 0;
		virtual bool Chat_Edit_Open(void) = 0;
};


class UIDiplomacyPresenterClass : public UIPresenterClass
{
	public:
		explicit UIDiplomacyPresenterClass(UIDiplomacyServiceClass & service);
		virtual void Execute(UIIntent const & intent) override;
		virtual void Refresh(void) override;

		bool Keys_Belong_To_Game(void) const;
		bool Take_Acted(void);

		UIDiplomacyState State;
		bool Closed = false;

	private:
		UIDiplomacyRow const * Row_Of(int house) const;

		UIDiplomacyServiceClass & Service;
		bool Acted = false;
};


std::unique_ptr<UIViewClass> UI_Diplomacy_View(UIDiplomacyPresenterClass & presenter);

// Engine side, in uidiplomacydlg.cpp.
void UI_Diplomacy_Toggle(void);
void UI_Diplomacy_Update(void);
void UI_Diplomacy_Close(void);
bool UI_Diplomacy_Is_Shown(void);
