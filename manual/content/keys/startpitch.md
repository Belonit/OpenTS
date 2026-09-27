---
key: StartPitch
summary: The barrel elevation a Juggernaut or artillery structure returns to before it packs up, in eighths of a turn, where 2 is level.
see_also: [StartFacing, IsJuggernaut, Artillary, TickTank, UndeploysInto]
when_omitted:
  kind: value
  value: "2"
---

```ini title="rules.ini"
[DJUGG] ; the stock deployed Juggernaut
IsJuggernaut=yes
StartPitch=2 ; level
```

The value uses the same eighth-of-a-turn steps as [`StartFacing`](/keys/startfacing/), applied to barrel elevation. `2` is level.

`StartPitch` matters only when a structure packs up into a vehicle:

- Before an [`IsJuggernaut=yes`](/keys/isjuggernaut/) structure packs up, it moves its barrel back to this elevation and turns back to `StartFacing`. Its pack-up animation starts only once both have arrived.
- An [`Artillary=yes`](/keys/artillary/) structure does the same after its pack-up animation. Its [`UndeploysInto`](/keys/undeploysinto/) vehicle is created only once both have arrived.
- For both kinds, the vehicle that results starts with its barrel at this elevation, so the barrel does not jump between the two forms.

A structure's barrel is always level when the structure is placed on the map, whatever this key says. The barrel does not return to this elevation while the structure idles.
