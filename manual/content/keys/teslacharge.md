---
key: TeslaCharge
summary: Sound a structure makes as its electric weapon begins charging.
see_also: [TeslaZap, Charges, TurretChargeAnimRate]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
TeslaCharge=TESLCHG ; a sound ID registered in SOUND.INI
```

The sound plays at a structure's position each time the structure starts charging. A structure starts a charge when all of the following hold:

- its primary weapon sets [`Charges=yes`](/keys/charges/);
- it is not building itself up or being sold;
- it has a target;
- its house has full power;
- it is switched on;
- it is not already charging or charged;
- it has finished reloading;
- one of its two weapons could fire at the target once turned toward it, which includes having the target in range.

A structure whose [`Ammo`](/keys/ammo/) has run out still starts a charge and plays the sound when the rest holds.

Every charging structure plays the sound, whoever owns it. Its volume depends on its distance from the view, like any sound placed on the map.

A structure that loses power, is switched off or loses its target drops its charge without a sound. The next charge plays the sound again. [`Charges`](/keys/charges/) covers when firing spends the charge.
