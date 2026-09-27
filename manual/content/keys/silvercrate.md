---
key: SilverCrate
summary: The crate result delivered by a CrateImg crate in a campaign.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: HealBase
---

In a campaign, a crate whose overlay is the one named by [`CrateImg`](/keys/crateimg/) gives this result. Campaign crates are not drawn at random: the overlay alone decides the result. The value is one of the [crate result](/reference/enums/crate/) tokens, and an unrecognized token gives `Money`.

The setting has no effect while `CrateImg` and [`WoodCrateImg`](/keys/woodcrateimg/) name the same OverlayType, as they do in the shipped rules. [Choosing the result in a campaign](/systems/crates/#in-a-campaign) explains why and what a second overlay type needs.
