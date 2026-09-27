---
key: IsTemple
summary: Rates the structure as a temple when a computer house chooses an ion cannon target.
see_also: [AIIonCannonTempleValue, "system:superweapons"]
when_omitted:
  kind: value
  value: "no"
---

The flag's only effect is on [the rating a computer house gives each ion cannon target](/systems/superweapons/#the-computers-use). A flagged structure that reaches the temple test is rated with [`AIIonCannonTempleValue`](/keys/aiioncannontemplevalue/) in place of the rating an ordinary structure gets.

Nothing a temple does on the map comes from the flag. Its superweapon comes from [`SuperWeapon=`](/keys/superweapon/). Clearing the flag does not remove the superweapon or stop the structure satisfying other types' prerequisites.
