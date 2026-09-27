---
key: Primary
summary: The WeaponType in the object type's first weapon slot.
see_also: ["system:target-selection", "system:veterancy"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYTANK] ; example UnitType
Primary=MyCannon ; names the [MyCannon] weapon section
```

The first weapon slot decides whether an object counts as armed. It also decides two other things:

- If the first slot's projectile is not anti-ground ([`AG=no`](/keys/ag/)), a target scan skips targets standing at the map's lowest height level, such as an aircraft landed there. The test uses absolute height, so a landed aircraft on raised ground can still be picked.
- When neither slot's warhead is [`Webby=yes`](/keys/webby/) and both slots rate equally against a target, the object fires the first slot.

Writing `none` or `<none>` empties the slot. A name with no matching weapon section is still accepted, and the slot gets a weapon of that name with every setting at its default.

## An empty first slot

An object whose first slot is empty is unarmed for targeting:

- It does not retaliate when attacked, except against [vein damage](/systems/veins/#standing-in-veins).
- When scanning for targets without a range limit, it accepts any target within its [`GuardRange`](/keys/guardrange/) instead of testing weapon range.
- If it is a structure, objects of a human house that are not on a team do not pick it as a target automatically. Engineers still do. The rule covers every structure except one that can undeploy into a vehicle; a construction yard is covered even if it can undeploy.

## What fills the slot at runtime

An elite object fires its [`Elite`](/keys/elite/) weapon from this slot. A structure first checks its installed upgrades, and the first upgrade with a weapon in this slot replaces it. [The elite weapon](/systems/veterancy/#the-elite-weapon) covers both rules. These substitutions also decide whether the object counts as armed.

:::danger[This assignment can change weapon numbering]
A weapon missing from the rules [`[Weapons]` list](/formats/rules-registries/) is numbered when a key such as this one first names it. Adding, removing or renaming an unlisted weapon here therefore shifts the weapon numbers stored in [Do Explosion At](/mapping/actions/taction-do-explosion/) trigger actions. List the weapon in `[Weapons]` to fix its number.
:::
