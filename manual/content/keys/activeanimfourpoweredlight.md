---
key: ActiveAnimFourPoweredLight
summary: Whether the fourth active slot's animation is destroyed and recreated with its house's power.
see_also: ["ActiveAnimFour", "ActiveAnimFourPowered", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

With `yes`, the [`ActiveAnimFour`](/keys/activeanimfour/) animation is removed while its house is short of power, and created again when the house has full power. The flag works only with [`ActiveAnimFourPowered=no`](/keys/activeanimfourpowered/) written beside it. While `ActiveAnimFourPowered` is `yes`, the animation freezes instead and this flag is ignored.

A shortfall removes the animation only on some structures; [Fields, fences and lights](/systems/power/#fields-fences-and-lights) says which.

Each time the house [rechecks its power](/systems/power/#when-the-tally-is-rebuilt) at full power, it creates the animation if the slot is empty. A non-looping animation therefore plays again at each recheck, even if no shortfall removed it.

Despite its name, the flag does not tint or light anything.
