---
enum_id: RadarEventType
slug: radar-event
title: Radar event
summary: Radar-notification kinds used by trigger actions that create map events.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [radar-event]
source_files: [code/revent.hh]
values:
  - { constant: RADAREVENT_COMBAT, value: 0, input: "0", meaning: "Combat event." }
  - { constant: RADAREVENT_NONCOMBAT, value: 1, input: "1", meaning: "Non-combat event." }
  - { constant: RADAREVENT_DROPZONE, value: 2, input: "2", meaning: "Drop-zone event." }
  - { constant: RADAREVENT_BASE_ATTACKED, value: 3, input: "3", meaning: "Base-under-attack event." }
  - { constant: RADAREVENT_HARVESTER_ATTACKED, value: 4, input: "4", meaning: "Harvester-under-attack event." }
  - { constant: RADAREVENT_ENEMY_SENSED, value: 5, input: "5", meaning: "Enemy-detected event." }
---

A radar event is a spinning box on the radar map that closes in on one cell to draw the player's eye there. The game raises three kinds by itself:

- base attacked, when one of the player's structures is damaged and EVA announces that the base is under attack, at most once per [`SpeakDelay`](/keys/speakdelay/) wait;
- harvester attacked, when one of the player's harvesters takes damage and survives;
- enemy sensed, when a cloaked or underground enemy is detected.

A map can raise any of the six kinds with the [Create Radar Event](/mapping/actions/taction-radar-event/) trigger action.

The kind sets the box's colors. Combat, base-attacked and harvester-attacked events pulse between orange and dark red. Non-combat and drop-zone events pulse between two greens, and enemy-sensed events pulse yellow.

Three comma-separated lists under `[General]` in `rules.ini` set timings and spacing per kind: [`RadarEventDurations`](/keys/radareventdurations/), [`RadarEventVisibilityDurations`](/keys/radareventvisibilitydurations/) and [`RadarEventSuppressionDistances`](/keys/radareventsuppressiondistances/). Each list takes one entry per kind, in the order of the table below. Give every list all six entries; each key page describes what a shorter list does.
