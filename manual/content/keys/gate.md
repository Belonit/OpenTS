---
key: Gate
summary: Makes the BuildingType a gate that opens for allied units wanting to pass.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "no"
---

A `Gate=yes` structure blocks movement while closed and opens for allied units. Infantry, walkers, hovercraft and driven vehicles ask a closed allied gate to open as they reach it, then wait until the door is fully open. A closed enemy gate never opens for them: an armed unit treats it as something to destroy, and an unarmed unit cannot pass. [Gates](/systems/walls-and-gates/#gates) covers opening, holding and closing. [`GateCloseDelay`](/keys/gateclosedelay/) sets how long the gate stays open, and [`DeployTime`](/keys/deploytime/) how long the door takes to move.

The flag also changes placement. A gate may be placed on a cell holding one of its house's laser fence sections, and placing it takes that fence down. Placing it also removes the brick, sandbag and Nod walls its house owns in its footprint, under the conditions [Placing a gate](/systems/walls-and-gates/#placing-a-gate) gives. That section also names the `[General]` gate keys that let a gate be placed over walls.

[`GateStages`](/keys/gatestages/) sets which frames the door and the buildup animation use. [Buildup](/systems/production/#buildup) covers the buildup animation's timing.

On the sidebar, a gate's cameo sorts after walls and before base defenses that share its [`CameoSortOrder`](/keys/cameosortorder/), as [the order of the strips](/systems/sidebar/#the-order-of-the-strips) describes.
