---
key: IsWebImmune
summary: Keeps a webbing warhead from pinning the soldier in place.
see_also: [Webby, WebDuration, WebbedInfantry, "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

An immune soldier takes a [`Webby=yes`](/keys/webby/) warhead as ordinary damage, scaled by the warhead's [`Verses`](/keys/verses/) percentages, and keeps moving.

A soldier without immunity takes no damage from a web hit. Instead it plays its struggling animation for [`WebDuration`](/keys/webduration/) frames, give or take the warhead's variation, and the paralyzed trigger event springs on the soldier's tag.

```ini title="rules.ini"
[MYCYBORG] ; example InfantryType
IsWebImmune=yes
```

Immunity also changes which weapon is fired at the soldier. An object armed with a web weapon treats an immune soldier as a target it cannot web, as it treats a vehicle, and picks its other weapon slot. [An empty second slot is a hazard](/systems/target-selection/#which-weapon-the-score-assumes) on any object with a web weapon.
