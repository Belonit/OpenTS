---
key: RechargeTime
summary: The minutes a superweapon takes to charge, and for a charge-draining weapon the base the drain is scaled from.
see_also: ["system:superweapons"]
when_omitted:
  kind: value
  value: "5"
---

`RechargeTime=` is the weapon's charge delay in minutes. Fractions of a minute are accepted; the stock chem missile uses `.3`. The game converts the value at 900 frames a minute and drops any part of a frame. [Charging](/systems/superweapons/#charging) covers which events start, stop and restart the countdown.

For a [`UseChargeDrain=yes`](/keys/usechargedrain/) weapon, a full charge becomes an effect lasting `RechargeTime` times [`ChargeToDrainRatio`](/keys/chargetodrainratio/), so raising the delay also lengthens the longest effect.

```ini title="rules.ini"
[MyIonStrike] ; example superweapon section
Type=IonCannon
RechargeTime=8.5
```

:::caution[`RechargeTime=0` counts as unset]
A value of exactly `0` is ignored, like a missing key. The weapon keeps the delay from the last file that set one, or five minutes if none has, so `0` cannot undo a delay an earlier rules file set. For a near-instant recharge, write `0.002` or more, which gives a one-frame delay. A smaller positive value drops to a zero-frame delay, which the charge clock on the cameo does not handle.
:::
