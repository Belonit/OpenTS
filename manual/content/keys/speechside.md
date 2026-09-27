---
key: SpeechSide
summary: The side whose voice set narrates a campaign mission.
see_also: [Player, RequiredAddOn]
when_omitted:
  kind: context-dependent
  note: The side of the country the scenario's Player entry names.
---

```ini title="map file"
[Basic]
Player=Nod
SpeechSide=GDI
```

The named side supplies the mission's voice archive. The archive number is the side's position in the rules `[Sides]` list plus one, so the first side uses `SPEECH01.MIX` and the second `SPEECH02.MIX`. Each enabled expansion's voice archive for the same position is mounted with it. The stock Firestorm missions `fsnod07` to `fsnod09` use the key so that a Nod mission is narrated by GDI.

The key is read only in a campaign mission, and it changes speech alone. The side taken from [`Player`](/keys/player/#scope-scenarios-2) still decides the mission's art and interface. Writing `<none>` is the same as leaving the key out.

The stock game ships voice archives for the first two sides only. A side with no voice archive, such as the `Civilian` and `Mutant` sides the stock rules also declare, is narrated by the first side. The mission fails to load only when the first side's archive is missing as well. A name that matches no side is ignored, and the side taken from `Player` narrates.
