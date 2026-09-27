---
enum_id: PipEnum
slug: pip-color
title: Pip color
summary: Named pip colors accepted for object status markers.
representation: token
bindings:
  key_value_types: [pipenum]
  scripting_parameter_types: []
source_files: [code/pip.hh, code/ccini.cpp]
values:
  - { constant: PIP_EMPTY, value: 0, input: "empty", meaning: "Empty pip slot." }
  - { constant: PIP_GREEN, value: 1, input: "green", meaning: "Green filled pip." }
  - { constant: PIP_YELLOW, value: 2, input: "yellow", meaning: "Yellow filled pip." }
  - { constant: PIP_WHITE, value: 3, input: "white", meaning: "White filled pip." }
  - { constant: PIP_RED, value: 4, input: "red", meaning: "Red filled pip." }
  - { constant: PIP_BLUE, value: 5, input: "blue", meaning: "Blue filled pip." }
---

A **pip** is one of the small markers drawn in a row beneath a selected object. These six colors are the values [`Pip`](/keys/pip/) accepts, in any letter case. `Pip` sets the color of the pips a transport draws for an infantry passenger.

The engine also draws a medic cross and the veteran and elite marks. No rules key can select those.
