---
key: BridgeStrength
summary: How hard a bridge is to bring down, and the damage a demolition charge does to one.
see_also: ["DestroyableBridges", "IonCannonWarhead", "C4Warhead"]
when_omitted:
  kind: value
  value: "1000"
---

A lower `BridgeStrength` makes bridges easier to damage. The same value is also the damage of the charge an infantryman sets to demolish a bridge.

A blast can damage a bridge span in its own cell only when all of these hold:

- bridge destruction is on: [`DestroyableBridges`](/keys/destroyablebridges/) in a campaign, or the [`BridgeDestruction`](/keys/bridgedestruction/) option in any other game;
- the warhead sets [`Wall=yes`](/keys/wall/#scope-warheadtype);
- at an elevated bridge, the blast goes off near deck height, so a blast on the ground beneath the span cannot damage it.

The blast then rolls a whole number from 1 to `BridgeStrength` and damages the span when the roll is below the blast's raw damage, before armor. A blast of 200 damage against `BridgeStrength=1000` succeeds 199 times in 1000. At `BridgeStrength=1`, any blast of 2 or more damage always succeeds.

A blast with [`IonCannonWarhead`](/keys/ioncannonwarhead/) skips the roll. At an elevated road or rail bridge, it also gets up to four attempts at the span and stops at the first that succeeds. Every other warhead gets one attempt. At a low bridge, the ion cannon skips the roll but otherwise damages the span like any other warhead.

When an infantryman demolishes a bridge from its deck, three blasts go off at its feet, each with `BridgeStrength` damage and [`C4Warhead`](/keys/c4warhead/). The first is credited to the infantryman and the other two to nobody. Raising the value to make bridges harder to shell therefore also makes this charge deadlier to everything standing nearby.

:::caution[A low bridge takes two hits per roll]
One successful roll damages a low bridge twice, so low bridges come down faster than the roll alone suggests.
:::
