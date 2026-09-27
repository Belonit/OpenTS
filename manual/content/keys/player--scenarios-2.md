---
key: Player
scope: scenarios-2
label: Presentation side
see_also: [SpeechSide, Theater]
when_omitted:
  kind: value
  value: "GDI"
---

```ini title="map file"
[Basic]
Player=Nod
```

In a campaign mission, the country named by `Player` also selects the side the mission is presented as. The side supplies the interface and sidebar artwork. It also supplies the voice set, unless [`SpeechSide`](/keys/speechside/) names another side.

A name that matches no country is presented as the first country's side, and a country with no side is presented as the first side.

If the side's artwork files cannot be loaded, the first side's artwork is used. If that fails too, the mission does not load. The voice set falls back the same way.
