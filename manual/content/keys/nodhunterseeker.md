---
key: NodHunterSeeker
summary: Seeds the second side's HunterSeeker.
see_also: [HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

Each rules file that sets this key copies its value into the [`HunterSeeker`](/keys/hunterseeker/#scope-side) of the second side in the rules' [`[Sides]`](/formats/rules-registries/) list. A `HunterSeeker=` in that side's own section of the same file then overrides it. [`GDIHunterSeeker`](/keys/gdihunterseeker/) does the same for the first side. Nothing else reads this key.
