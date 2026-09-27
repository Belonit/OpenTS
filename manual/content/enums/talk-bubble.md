---
enum_id: TalkType
slug: talk-bubble
title: Talk bubble
summary: Speech-bubble styles a team mission or trigger action can show over a team member.
representation: integer
bindings:
  key_value_types: []
  scripting_parameter_types: [talk-bubble]
source_files: [code/talk.hh, code/techno.cpp, code/objtype.cpp]
values:
  - { constant: TALK_NONE, value: 0, input: "0", meaning: "Takes down the current bubble." }
  - { constant: TALK_1, value: 1, input: "1", meaning: "Standard talk bubble." }
  - { constant: TALK_QUESTION, value: 2, input: "2", meaning: "Question-mark bubble." }
  - { constant: TALK_EXCLAMATION, value: 3, input: "3", meaning: "Exclamation-mark bubble." }
---

Each value above `0` draws one frame of `TALKBUBL.SHP`, with frames counted from `0`. Value `1` draws the file's first frame, `2` its second and `3` its third, so replacing the file changes what each value shows.

A value above `3` draws a later frame of the file. If the file has no frame at that position, or the value is below `0`, nothing is drawn. The bubble is still placed, so it takes the current bubble away and uncovers the ground around the speaker.

[`TalkBubbleTime`](/keys/talkbubbletime/) covers how long a bubble stays up, what else placing one does, and how a second one displaces the first.
