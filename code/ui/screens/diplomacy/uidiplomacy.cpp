/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/

#include "ui/screens/diplomacy/uidiplomacy.h"

#include "ui/rml/rmlview.h"

#include <RmlUi/Core/ElementDocument.h>
#include <RmlUi/Core/Event.h>
#include <RmlUi/Core/Input.h>
#include <chrono>
#include <string>


UIDiplomacyPresenterClass::UIDiplomacyPresenterClass(UIDiplomacyServiceClass & service) :
	Service(service)
{
}


void UIDiplomacyPresenterClass::Execute(UIIntent const & intent)
{
	if (intent.Name == "close" || intent.Name == "cancel" || intent.Name == "ok") {
		Closed = true;
		return;
	}

	UIDiplomacyRow const * row = Row_Of(intent.Value);
	if (row == nullptr) {
		return;
	}

	// A refused click still counts, so the screen puts back the box the click changed.
	if (intent.Name == "ally") {
		Acted = true;
		if (row->HasAlly && row->AllyEnabled) {
			Service.Toggle_Alliance(row->House);
		}

	} else if (intent.Name == "give") {
		Acted = true;
		if (row->HasGive && row->GiveEnabled) {
			Service.Toggle_Control(row->House);
		}

	} else if (intent.Name == "send") {
		Acted = true;
		if (row->HasChat) {
			Service.Set_Sends_To(row->House, !row->Send);
		}

	} else if (intent.Name == "mute") {
		Acted = true;
		if (row->HasChat) {
			Service.Set_Muted(row->House, !row->Mute);
		}
	}
}


void UIDiplomacyPresenterClass::Refresh(void)
{
}


/// <summary>
/// Whether keys pressed while the screen is up must reach the game untouched, as they must
/// while a chat line is being typed.
/// </summary>
bool UIDiplomacyPresenterClass::Keys_Belong_To_Game(void) const
{
	return(Service.Chat_Edit_Open());
}


/// <summary>
/// Returns whether an action was asked for since the last call, and clears the record.
/// </summary>
bool UIDiplomacyPresenterClass::Take_Acted(void)
{
	bool const acted = Acted;
	Acted = false;
	return(acted);
}


UIDiplomacyRow const * UIDiplomacyPresenterClass::Row_Of(int house) const
{
	for (UIDiplomacyRow const & row : State.Players) {
		if (row.House == house) {
			return(&row);
		}
	}
	for (UIDiplomacyRow const & row : State.Observers) {
		if (row.House == house) {
			return(&row);
		}
	}
	return(nullptr);
}


namespace
{

// The key press that opened the screen can repeat into it; repeats this soon after opening
// are ignored, so holding Tab does not close and reopen the screen.
constexpr std::chrono::milliseconds UI_DIPLOMACY_TAB_GUARD(300);


class UIDiplomacyViewClass : public UIRmlViewClass
{
	public:
		explicit UIDiplomacyViewClass(UIDiplomacyPresenterClass & presenter) :
			UIRmlViewClass(presenter, "diplomacy.rml", "diplomacy"),
			Data(presenter),
			Opened(std::chrono::steady_clock::now())
		{
		}

		virtual void Sync(void) override
		{
			Model.DirtyVariable("players");
			Model.DirtyVariable("observers");
			Model.DirtyVariable("showcontrol");
			Model.DirtyVariable("showchat");
			Model.DirtyVariable("info");
			Model.DirtyVariable("footer");
			Fit_Frame();
		}

	protected:
		virtual bool Bind(Rml::DataModelConstructor & model) override
		{
			Rml::StructHandle<UIDiplomacyRow> row = model.RegisterStruct<UIDiplomacyRow>();
			if (!row) {
				return(false);
			}
			row.RegisterMember("house", &UIDiplomacyRow::House);
			row.RegisterMember("name", &UIDiplomacyRow::Name);
			row.RegisterMember("color", &UIDiplomacyRow::Color);
			row.RegisterMember("nametip", &UIDiplomacyRow::NameTip);
			row.RegisterMember("kills", &UIDiplomacyRow::Kills);
			row.RegisterMember("hasally", &UIDiplomacyRow::HasAlly);
			row.RegisterMember("ally", &UIDiplomacyRow::Ally);
			row.RegisterMember("allyenabled", &UIDiplomacyRow::AllyEnabled);
			row.RegisterMember("allytip", &UIDiplomacyRow::AllyTip);
			row.RegisterMember("theirs", &UIDiplomacyRow::Theirs);
			row.RegisterMember("theirsyes", &UIDiplomacyRow::TheirsYes);
			row.RegisterMember("hasgive", &UIDiplomacyRow::HasGive);
			row.RegisterMember("give", &UIDiplomacyRow::Give);
			row.RegisterMember("giveenabled", &UIDiplomacyRow::GiveEnabled);
			row.RegisterMember("givetip", &UIDiplomacyRow::GiveTip);
			row.RegisterMember("given", &UIDiplomacyRow::Given);
			row.RegisterMember("givenyes", &UIDiplomacyRow::GivenYes);
			row.RegisterMember("haschat", &UIDiplomacyRow::HasChat);
			row.RegisterMember("send", &UIDiplomacyRow::Send);
			row.RegisterMember("mute", &UIDiplomacyRow::Mute);
			row.RegisterMember("latency", &UIDiplomacyRow::Latency);
			row.RegisterMember("latencyfair", &UIDiplomacyRow::LatencyFair);
			row.RegisterMember("latencypoor", &UIDiplomacyRow::LatencyPoor);
			row.RegisterMember("waiting", &UIDiplomacyRow::Waiting);
			row.RegisterMember("waitingtip", &UIDiplomacyRow::WaitingTip);

			UIDiplomacyState & state = Data.State;
			return(model.RegisterArray<std::vector<UIDiplomacyRow>>()
				&& model.Bind("players", &state.Players)
				&& model.Bind("observers", &state.Observers)
				&& model.Bind("showcontrol", &state.ShowControl)
				&& model.Bind("showchat", &state.ShowChat)
				&& model.Bind("info", &state.Info)
				&& model.Bind("footer", &state.Footer));
		}

		virtual void Loaded(void) override
		{
			Opened = std::chrono::steady_clock::now();
		}

		virtual void ProcessEvent(Rml::Event & event) override
		{
			if (event.GetId() != Rml::EventId::Keydown) {
				UIRmlViewClass::ProcessEvent(event);
				return;
			}

			// Focus left on a clicked box would let Enter or Space click it again.
			if (Document() != nullptr) {
				Document()->Focus();
			}

			if (Data.Keys_Belong_To_Game()) {
				return;
			}

			int const key = event.GetParameter<int>("key_identifier", 0);
			if (key == Rml::Input::KI_TAB) {
				if (std::chrono::steady_clock::now() - Opened >= UI_DIPLOMACY_TAB_GUARD) {
					Queue("close");
				}
				event.StopPropagation();
				return;
			}

			if (key == Rml::Input::KI_ESCAPE) {
				Queue("close");
				event.StopPropagation();
			}
		}

	private:
		// Sizes the frame to the rows it holds; the numbers follow diplomacy.rcss.
		void Fit_Frame(void)
		{
			Rml::Element * reveal = (Document() != nullptr) ? Document()->GetElementById("reveal") : nullptr;
			if (reveal == nullptr) {
				return;
			}

			int const players = (int)Data.State.Players.size();
			int const observers = (int)Data.State.Observers.size();
			int height = 44 + 53 + 22 * players + 47;
			if (observers > 0) {
				height += 41 + 22 * observers;
			}
			if (height == FittedHeight) {
				return;
			}

			FittedHeight = height;
			reveal->SetProperty("height", std::to_string(height) + "dp");
			reveal->SetProperty("margin-top", std::to_string(-height / 2) + "dp");
		}

		UIDiplomacyPresenterClass & Data;
		std::chrono::steady_clock::time_point Opened;
		int FittedHeight = 0;
};

}


std::unique_ptr<UIViewClass> UI_Diplomacy_View(UIDiplomacyPresenterClass & presenter)
{
	return(std::make_unique<UIDiplomacyViewClass>(presenter));
}
