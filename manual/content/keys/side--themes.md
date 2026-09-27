---
key: Side
scope: themes
label: Track side restriction
see_also: [Normal, Scenario]
when_omitted:
  kind: value
  value: <none>
  note: No restriction, which offers the track to every side.
---

`Side=` restricts the music track to players of one side. The track is allowed only while the local player's country belongs to the side named here, so every country on that side gets it. A country's side comes from `[Sides]` or its own [`Side=`](/keys/side/#scope-housetype).

```ini title="theme.ini"
[DUSKHOUR]
Name=Dusk Hour
Length=4.11
Side=GDI
```

For a player of any other side, the track is missing from the automatic playlist and from the sound options track list, and the [next track](/commands/nexttheme/) and [previous track](/commands/prevtheme/) commands skip it. Other ways of starting the track, listed under [`Normal`](/keys/normal/), still play it.

While no game is loaded there is no player's country to compare, so the restriction is not applied.

A value that names no side declared in `[Sides]` is ignored, and the track stays unrestricted.
