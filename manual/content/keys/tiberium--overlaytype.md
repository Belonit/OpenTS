---
key: Tiberium
scope: overlaytype
label: Tiberium overlay
see_also: ["system:tiberium", "ChainReaction", "Image"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[MYTIB] ; an OverlayType registered in [OverlayTypes]
Tiberium=yes
```

`Tiberium=yes` marks an overlay as Tiberium. When the section is read, the flag also changes two of the overlay's other settings:

- Its armor becomes wood, even if the section sets [`Armor=`](/keys/armor/).
- A [`Land=Clear`](/keys/land/) setting becomes the `Tiberium` [land type](/reference/enums/land-type/).

Harvesters collect only from cells whose land type is `Tiberium`. A Tiberium overlay that sets another `Land`, such as `Rock`, keeps it, and harvesters cannot collect it.

A flagged overlay belongs to the type in the rules' [`[Tiberiums]` list](/formats/rules-registries/) whose overlay set contains it. One that is in no type's set counts as the first type in the list. Bails a harvester lifts from the overlay are worth that type's [`Value=`](/keys/value/).
