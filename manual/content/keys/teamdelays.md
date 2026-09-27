---
key: TeamDelays
summary: The frames a house waits between team creation passes, one entry per difficulty.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: ""
  note: The list stays empty, and the game crashes when the scenario loads and a house takes its delay from the list.
---

Each entry is the number of frames a house waits between [team creation passes](/systems/ai-team-production/#when-the-pass-runs). A house takes the entry for its [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot). For a computer house, the first entry applies at the Hard setting and the last at Easy. The stock rules set `2250,2700,3600`, or two and a half to four minutes at 15 frames a second.

Give one entry for each of the three slots. A house whose slot lies past the end of a shorter list gets an unpredictable delay.

A house's first countdown is this value plus `175` frames for each place the house holds in the house list, so houses do not all run the pass on the same frame. After each pass, the countdown restarts at this value alone. An entry of `0` makes the house run a pass every frame.
