---
key: GDIWallDefense
summary: Seeds the first side's AIWallDefense.
see_also: [AIWallDefense, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side keeps the AIWallDefense its section sets, or 0 when it sets none.
---

The value becomes the [`AIWallDefense`](/keys/aiwalldefense/) of the first side in the rules' [`[Sides]`](/formats/rules-registries/) list, in each rules file that sets this key. An `AIWallDefense=` in that side's own section of the same file overrides it. A file that omits this key leaves the side's value alone. No key seeds this value for any other side, and nothing else reads this key.
