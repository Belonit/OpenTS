---
key: FireUp
summary: The stage of the upright firing animation at which an infantry type releases its round.
see_also: ["FireProne", "Sequence", "JumpJet"]
when_omitted:
  kind: value
  value: "0"
---

A standing soldier releases its round when its firing animation reaches this stage. Stages count the frames of the `FireUp` run in the type's [`Sequence`](/keys/sequence/) section, starting from `0`. At `0` the round leaves on the same update the animation starts.

```ini title="art.ini"
[E1] ; the Image ID of the stock Light Infantry
Sequence=E1Sequence
FireUp=2 ; the third stage of E1Sequence's six-frame FireUp run
```

A prone soldier uses [`FireProne`](/keys/fireprone/) in place of this key. A [`JumpJet=yes`](/keys/jumpjet/) soldier plays its `FireFly` run in place of `FireUp` while its jumpjet locomotor is in control, and still releases the round at this stage.

If the soldier cannot fire when the stage arrives, it abandons the firing animation and returns to standing, or to prone if it was lying down.

:::caution[Keep `FireUp` no higher than the frame count of the `FireUp` run]
The firing animation ends once its stage reaches the frame count, so a higher `FireUp` is never reached. A soldier standing still then returns to its standing animation, starts the firing animation again, and never releases a round. A soldier that moves on to an animation whose stage keeps counting, such as walking, releases the round if that animation reaches the figure while the soldier still holds its target.
:::
