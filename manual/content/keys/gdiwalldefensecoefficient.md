---
key: GDIWallDefenseCoefficient
summary: Seeds the first side's AIWallDefenseCoefficient.
see_also: [AIWallDefenseCoefficient, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side keeps the AIWallDefenseCoefficient its section sets, or 0 when it sets none.
---

The value becomes the [`AIWallDefenseCoefficient`](/keys/aiwalldefensecoefficient/) of the first side in the rules' [`[Sides]`](/formats/rules-registries/) list, in each rules file that sets this key. An `AIWallDefenseCoefficient=` in that side's own section of the same file overrides it. A file that omits this key leaves the side's value alone. No key seeds this value for any other side, and nothing else reads this key.
