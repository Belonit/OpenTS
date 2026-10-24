/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2026 OpenTS contributors
 *
 * See LICENSE.md for applicable additional terms and warranty disclaimers.
 ******************************************************************************/


#pragma once

#include "chat.hh"

class HouseClass;
class IPXAddressClass;
struct GlobalPacketType;


bool Chat_Can_Open(ChatScopeType scope);
bool Chat_Reaches(HouseClass const * from, HouseClass const * to, ChatScopeType scope);
bool Chat_Begin(ChatScopeType scope, int house = -1);
void Chat_Send(char const * text);
void Chat_Receive(GlobalPacketType const & packet, IPXAddressClass & from);
void Chat_Show(HouseClass const * sender, ChatScopeType scope, int target, char const * text);

// This machine's choices of whose lines to hide and who its lines go to; never sent or saved.
bool Chat_Is_Muted(HouseClass const * house);
void Chat_Set_Muted(HouseClass const * house, bool muted);
bool Chat_Sends_To(HouseClass const * house);
void Chat_Set_Sends_To(HouseClass const * house, bool sends);
void Chat_Reset_Filters(void);
