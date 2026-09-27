---
key: CrateImg
summary: The OverlayType whose crates deliver the SilverCrate result in a campaign.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: none
---

In a campaign, collecting a crate of this OverlayType gives the [`SilverCrate`](/keys/silvercrate/) result. Outside a campaign, it gives a random result like any other crate. The OverlayType must set [`Crate=yes`](/keys/crate/) to be collected at all.

Unless [`WoodCrateImg`](/keys/woodcrateimg/) names the same overlay, the engine never places this overlay itself. It appears only where a map draws it into its overlay layer.

:::caution[Name a different overlay from WoodCrateImg]
When this setting and [`WoodCrateImg`](/keys/woodcrateimg/) name the same overlay, every crate of that overlay gives the [`WoodCrate`](/keys/woodcrate/) result, and `SilverCrate` never applies. The shipped rules name the same overlay in both settings. To use `SilverCrate`, add a second OverlayType with `Crate=yes`, name it here only, and draw it into the map.
:::
