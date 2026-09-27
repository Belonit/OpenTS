---
format_id: tutorial-ini
title: TUTORIAL.INI
summary: Holds the numbered lines a text trigger prints, which a scenario may replace or add to.
kind: file
source_files:
- code/tutorial.cpp
- code/init.cpp
- code/scenario.cpp
- code/taction.cpp
related:
- type: action
  id: TACTION_TEXT_TRIGGER
- type: key
  id: MessageDelay
- type: format
  id: opents-ini
filenames:
- TUTORIAL.INI
---

`[Tutorial]` keys are the numbers that [Text Trigger...](/mapping/actions/taction-text-trigger/) names, and each value is the line that trigger prints. The game reads the file once at startup. Without the file there are no lines, unless a scenario supplies its own. [OPENTS.INI](/formats/opents-ini/#the-files-it-reads) can change the file name.

A scenario can have its own `[Tutorial]` section. While that scenario is played, a number both define prints the scenario's line, and a number the file does not have is added for that scenario only. The next mission starts from the file's lines again.

The game reads this section only from the scenario file, the one that holds the mission's `[Actions]`. A `[Tutorial]` section in a campaign mission's companion `.INI` or in a rules file has no effect.

```ini title="TUTORIAL.INI"
[Tutorial]
120=Hold the ridge until the transports arrive.
```

```ini title="map file"
[Tutorial]
120=Hold the bridge instead.
200=A line of this mission's own.
```

Write each key as a whole number and nothing else. A key such as `120a` is skipped and written to the debug log; it is not read as `120`. Two spellings of one number, such as `120` and `0120`, are the same line, and the later value wins.

A scenario cannot blank a line. A key with nothing after the `=` is ignored, so the file's line with that number is still printed.

Neither the file's lines nor a scenario's are translated, so a scenario's replacement line appears in the language it was written in for every player.

A saved game stores the scenario's lines. The file's lines are not saved, so a loaded game prints the lines from the `TUTORIAL.INI` read when the game was launched.
