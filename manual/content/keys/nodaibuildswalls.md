---
key: NodAIBuildsWalls
summary: Seeds the second side's AIBuildsWalls.
see_also: [AIBuildsWalls, "system:ai-base-building"]
when_omitted:
  kind: value
  value: "yes"
---

When a rules file sets this key, its value becomes the [`AIBuildsWalls`](/keys/aibuildswalls/#scope-side) setting of the second side listed in [`[Sides]`](/formats/rules-registries/). An `AIBuildsWalls=` in that side's section of the same file overrides it. A file that omits this key leaves the side's value as it was. Nothing else reads the key.

No `[General]` key does the same for the first side; set `AIBuildsWalls=` in its section instead. Computer houses build walls only when both their side's setting and [`AIBuildsWalls`](/keys/aibuildswalls/#scope-global-rules) in `[General]` allow it.
