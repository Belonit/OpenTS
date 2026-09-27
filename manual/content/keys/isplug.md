---
key: IsPlug
summary: Rates the structure as an upgrade host when a computer house chooses an ion cannon target.
see_also: [AIIonCannonPlugValue, PowersUpBuilding, "system:superweapons"]
when_omitted:
  kind: value
  value: "no"
---

The flag's only effect is on [the rating a computer house gives each ion cannon target](/systems/superweapons/#the-computers-use). A flagged structure that reaches the plug test is rated with [`AIIonCannonPlugValue`](/keys/aiioncannonplugvalue/) in place of the rating an ordinary structure gets.

:::caution[The flag does not make a structure an upgrade plug]
[`PowersUpBuilding=`](/keys/powersupbuilding/) names the host a plug fits into, and everything a fitted plug brings comes from that key, such as [a turret for a host that has none](/keys/turret/) or [a superweapon granted without the `AuxBuilding=` test](/systems/superweapons/#from-a-structure-or-a-plug). A plug without `IsPlug=` fits and behaves the same.

A plug is absorbed into its host and deleted as it is placed, so it never stands on the map for the computer to rate. The shipped rules therefore put this flag on the GDI Upgrade Center, the host that accepts plugs, and not on the plugs.
:::
