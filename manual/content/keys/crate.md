---
key: Crate
summary: Whether the overlay is a crate, which infantry and vehicles collect by entering its cell.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "no"
---

Any overlay with `Crate=yes` is a crate. Infantry, walkers, hovercraft and driven vehicles collect it by entering its cell, and the collector receives a result. Infantry of a computer-controlled house never enter a crate's cell, and in a campaign that house's vehicles do not either. [Collecting a crate](/systems/crates/#collecting-a-crate) lists every exception.

In a campaign, the result depends on which overlay the crate is. The overlays named by [`CrateImg`](/keys/crateimg/) and [`WoodCrateImg`](/keys/woodcrateimg/) give their configured results, and any other overlay with `Crate=yes` gives money. Crates the game places by itself always use the `WoodCrateImg` overlay. [Choosing the result](/systems/crates/#choosing-the-result) covers what each overlay delivers.
