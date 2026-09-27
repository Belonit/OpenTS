---
key: WoodCrateImg
summary: The OverlayType used for every crate the engine places itself.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: none
---

`WoodCrateImg` names the overlay of every crate the engine places itself. The engine places a crate itself in two cases:

- the random crates placed outside a campaign;
- the crate a destroyed [`CarriesCrate=yes`](/keys/carriescrate/) vehicle drops when the scenario allows it.

In a campaign, a collected crate of this overlay gives the [`WoodCrate`](/keys/woodcrate/) result. The OverlayType must set [`Crate=yes`](/keys/crate/) for crates placed with it to be collected.

:::danger[Name an OverlayType before the engine places a crate]
With no OverlayType named here, the game crashes the first time it places a crate. Outside a campaign, a match with crates enabled places random crates while the scenario loads, so it crashes before play starts unless [`CrateMaximum`](/keys/cratemaximum/) is `0` or below. A vehicle's crate drop crashes the same way.
:::

Naming the same OverlayType here and in [`CrateImg`](/keys/crateimg/) makes [`SilverCrate`](/keys/silvercrate/) unreachable. [In a campaign](/systems/crates/#in-a-campaign) explains why.
