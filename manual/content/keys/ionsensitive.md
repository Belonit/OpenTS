---
key: IonSensitive
summary: Stops the weapon from firing while an ion storm is running.
see_also: ["system:ion-storms"]
when_omitted:
  kind: value
  value: "no"
---

While an ion storm is active, no object can fire an `IonSensitive=yes` weapon, in either weapon slot. The weapon's reload, range and ammunition are unchanged.

```ini title="rules.ini"
[MyRailgun] ; example WeaponType
IonSensitive=yes
```

During the storm, an object with two weapons can still fire the other one, if that weapon is not ion-sensitive and can hit the target.

Aircraft cannot fire at all during [a storm](/systems/ion-storms/#aircraft), whatever their weapons set, so this key changes nothing for them.
