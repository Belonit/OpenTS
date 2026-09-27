---
key: GDIHunterSeeker
summary: Seeds the first side's HunterSeeker.
see_also: [HunterSeeker, "system:superweapons"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[General]
GDIHunterSeeker=GHUNTER
```

The value becomes the [`HunterSeeker`](/keys/hunterseeker/#scope-side) of the first side in the rules' [`[Sides]`](/formats/rules-registries/) list, in each rules file that sets this key. A `HunterSeeker=` in that side's own section of the same file overrides it. A file that omits this key leaves the side's value alone. [`NodHunterSeeker`](/keys/nodhunterseeker/) does the same for the second side, and nothing else reads this key.
