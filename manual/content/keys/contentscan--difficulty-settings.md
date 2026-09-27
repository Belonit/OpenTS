---
key: ContentScan
scope: difficulty-settings
label: Difficulty cargo scan
see_also: ["system:difficulty", "system:target-selection", IQ]
when_omitted:
  kind: value
  value: "no"
  note: The difficulty block is re-read from fixed defaults whenever its section is present, so a later file that contains the section but not this key sets it back to no.
---

`ContentScan=yes` in a difficulty section would make every house in that [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot) add the worth of a transport's passengers to the transport's worth as a target. The [`[IQ]` threshold](/keys/contentscan/#scope-global-rules) is an alternative: either one alone would switch the addition on.

The setting has no effect, because nothing uses that worth. It is read only by a superweapon-targeting step that the game never runs. [Target selection](/systems/target-selection/) describes what a computer house does weigh when it chooses a target, and passengers play no part in it.
