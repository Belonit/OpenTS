---
title: Human houses raise no teams from AI triggers
category: fix
release: 0.2.0
targets:
- type: system
  id: ai-team-production
  effect: changed
- type: action
  id: TACTION_BEGIN_AI_TRIGGERS
  effect: changed
credit: [ZivDero, Rampastring]
---

A human house whose AI-trigger switch was on, for example after an AI triggers begin... action named it, used to raise teams from its AI triggers and take the player's units into them. Only computer houses raise teams from AI triggers now. Teams that map triggers create directly are unchanged.

Rampastring is credited for the Vinifera fix this follows.
