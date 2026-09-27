---
key: ContentScan
scope: global-rules
label: IQ threshold
see_also: ["system:difficulty", "system:target-selection", IQ]
when_omitted:
  kind: value
  value: "4"
---

A house whose [`IQ`](/keys/iq/) is at or above this value would add the worth of a transport's passengers to the transport's worth as a target. The [difficulty section's flag](/keys/contentscan/#scope-difficulty-settings) is an alternative: either one alone would switch the addition on.

The setting has no effect, because nothing uses that worth. It is read only by a superweapon-targeting step that the game never runs, so no value changes anything at any `IQ`.
