---
key: Armor
scope: housetype
label: Armor bias
see_also: ["system:difficulty", Verses]
when_omitted:
  kind: value
  value: "1.0"
---

Damage to the objects of a house of this country is divided by this value. A value above 1 makes them harder to destroy, and one below 1 makes them easier.

```ini title="rules.ini"
[NOD]
Armor=1.25 ; example: NOD's objects take 20% less damage from each hit
```

Outside a campaign game, the house multiplies this value by [the difficulty section's `Armor=`](/keys/armor/#scope-difficulty-settings) once, [when it is given its difficulty slot](/systems/difficulty/#how-the-figures-are-combined). A campaign game leaves the country's value out, so it affects skirmish and multiplayer games only.

The division applies to every hit except damage that bypasses armor, such as a planted C4 charge. Healing is never reduced. The division comes before the veteran armor bonus, and the two together cannot bring a hit below 1 point. The warhead's [`Verses`](/keys/verses/) percentage and the falloff with distance are applied after that.

:::caution[Keep the value above 0]
The country value and the difficulty value are multiplied before anything is divided by them, so a `0` in either section has the same effect. Every hit on that house's objects is then reduced to 1 point before `Verses` and the distance falloff are applied, however strong the weapon.
:::
