---
key: FiringSyncFrame2
summary: The countdown value at which the second round of a burst leaves a shape-drawn vehicle.
see_also: ["FiringSyncFrame1", "FiringFrames", "Burst"]
when_omitted:
  kind: value
  value: "-1"
---

This setting ties the second round of a [`Burst`](/keys/burst/) to the firing animation, as [`FiringSyncFrame1`](/keys/firingsyncframe1/) does for the first round. That page explains the countdown the value is matched against and which weapons the setting covers. A weapon with `Burst=1` never fires a second round, so this setting has no effect on it.

When both settings are used, give this one the lower value to release both rounds during one animation. The countdown only falls, so a higher value has already passed when the first round leaves, and the second round waits for the next animation.

Rounds after the second cannot be tied to the animation.

:::caution[A value the countdown never reaches stops the weapon after one round]
Keep the value between `0` and `2 × FiringFrames − 1`, or leave it at `-1`. Any other value is never matched, so the vehicle fires the first round of a burst and its primary weapon then stops firing. It fires one more round only after it has gone without a target for its weapon's [`ROF`](/keys/rof/#scope-weapontype) delay.
:::
