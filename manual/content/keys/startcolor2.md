---
key: StartColor2
summary: The other end of the color range a spark or railgun particle is created at.
see_also: ["StartColor1", "ColorList", "ColorSpeed"]
when_omitted:
  kind: value
  value: 0,0,0
---

[`StartColor1`](/keys/startcolor1/) explains how the pair is written, how a particle's starting color is picked between them, and what happens when both are black. If only one of the pair is set, the other stays black, so particles start anywhere between the set color and black.

:::note[A partial triplet reads as the default]
`StartColor2=255` names one channel where three are needed, so the far end of the range keeps its default color and the debug log records the line. [INI syntax](/formats/ini-syntax/#malformed-values) has the rule.
:::
