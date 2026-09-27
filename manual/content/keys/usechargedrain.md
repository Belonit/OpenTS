---
key: UseChargeDrain
summary: Whether a fired superweapon spends its charge over a timed drain that can be ended early.
see_also: ["system:superweapons", "system:power"]
when_omitted:
  kind: value
  value: "no"
---

`UseChargeDrain=yes` makes a fired superweapon spend its charge over time. For a house under human control, firing the ready weapon delivers its [`Type=`](/keys/type/#scope-superweapontype) effect once, moves the weapon to the discharged state and starts a drain, a countdown that spends the charge. The drain's length is the charge built up, scaled by [`ChargeToDrainRatio`](/keys/chargetodrainratio/).

Firing the weapon again during the drain ends it. The unspent drain goes back into the charge, so the weapon is ready again at once. When the drain runs out instead, the weapon starts charging from a full [`RechargeTime`](/keys/rechargetime/). [Charge-draining weapons](/systems/superweapons/#charge-draining-weapons) gives the conversion in both directions.

`Type=Firestorm` is the behavior built for this cycle. Its wall stays raised while the drain runs and comes down when the drain ends, whether it runs out or is ended by hand. [The firestorm generator and its charge](/systems/laser-fences/#the-firestorm-generator-and-its-charge) covers the wall.

The weapon's sidebar cameo always shows a clock, including while the weapon is ready or discharged. A human-controlled house can fire it only while it is ready or discharged, not while it is charging or suspended. [The sidebar cameo](/systems/superweapons/#the-sidebar-cameo) lists its captions.

For a computer house, firing never starts a drain or changes the countdown. Once the weapon has first charged, the superweapon AI can fire it again on any later pass, even while it is charging or suspended. The firestorm trigger actions switch a computer house's wall at any time, whatever the weapon's state. A computer house's firestorm wall therefore stays up until something else lowers it, as [Computer houses](/systems/laser-fences/#computer-houses) describes.

:::caution[Use it only with `Type=Firestorm`]
Any other behavior delivers its effect each time the weapon is fired from ready. Ending a drain at once returns all the charge it took, so a player can alternate the two: fire the effect, end the drain, and fire the effect again, with no recharge between shots. A computer house never drains the weapon, so it can fire the effect again on its next AI pass. While that house's firestorm wall is up, firing any of its charge-draining weapons does nothing.
:::

:::caution[Keep the house powered to keep the charge]
When a suspended charge-draining weapon resumes, it starts charging from a full `RechargeTime`, however little time it spent suspended. An ordinary weapon resumes where its countdown stopped. Suspending any charge-draining weapon also lowers its house's firestorm wall. [Power](/systems/power/#superweapons) covers when a weapon is suspended.
:::
