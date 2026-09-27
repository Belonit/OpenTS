---
key: LightningRod
summary: Raises the type's chance of being picked as the target of an ion storm lightning bolt.
see_also: [IonImmune, IonLightningRandomness, "system:ion-storms"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[GAPOWR]
LightningRod=yes
```

Each aimed bolt draws its target from a [candidate list](/systems/ion-storms/#where-it-strikes). An object without the flag enters that list with a 2% chance. With the flag:

- a structure that is switched on enters with a 42% chance;
- a vehicle or infantryman whose locomotor has power enters with a 12% chance.

A switched-off structure, or a vehicle or infantryman whose locomotor has lost power, keeps the 2% chance. Aircraft never enter the list, with or without the flag.

:::caution[Lightning rods on ion-immune teams]
A member of a team whose TeamType sets [`IonImmune=yes`](/keys/ionimmune/) is normally left out of the candidate list. With `LightningRod=yes` it is put back in and bolts can be aimed at it, but their blast still does it no damage.
:::
