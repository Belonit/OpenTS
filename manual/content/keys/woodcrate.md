---
key: WoodCrate
summary: The crate result delivered by a WoodCrateImg crate in a campaign.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: Money
---

`WoodCrate` is the result of every campaign crate whose overlay is the one [`WoodCrateImg`](/keys/woodcrateimg/) names. Campaign crates are not drawn at random; the overlay alone decides the result. Outside a campaign this setting is not used.

The value is one of the [crate result](/reference/enums/crate/) tokens. An unrecognized token gives `Money`, so a misspelled result behaves exactly like `Money`.

When `WoodCrateImg` and [`CrateImg`](/keys/crateimg/) name the same OverlayType, every crate of that overlay gives this result. [In a campaign](/systems/crates/#in-a-campaign) explains why.
