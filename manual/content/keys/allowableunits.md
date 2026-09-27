---
key: AllowableUnits
summary: The infantry and vehicle types offered on a mission's dropship loadout screen.
see_also: [AllowableUnitMaximums, StartingDropships, TechLevel]
when_omitted:
  kind: value
  value: ""
  note: The loadout screen offers every infantry and vehicle type that passes the filter described on this page.
---

```ini title="map file"
[Basic]
StartingDropships=2
AllowableUnits=E1,E2,SMECH
AllowableUnitMaximums=-1,-1,2
```

The list sets which cameos the dropship loadout screen offers. That screen appears before a mission whose [`StartingDropships`](/keys/startingdropships/) is above zero, and the list has no other effect.

With the list empty, the screen builds its own selection from every infantry and vehicle type. It leaves out a type when **Any of** these is true:

- its build level is above the house's tech level;
- it is civilian infantry;
- its build level is `-1`;
- it costs `10` or less;
- the player's house may not own it.

With the list populated, the screen offers exactly the types named, and that filter no longer applies. A named type is left out only when the player's house may not own it or its [`AllowableUnitMaximums`](/keys/allowableunitmaximums/) entry is `0`. Build level and cost are ignored, so a mission can offer a unit the player could not otherwise build.

Each name pairs with the number at the same position in [`AllowableUnitMaximums`](/keys/allowableunitmaximums/), so write both lists in the same order.

:::caution[Check every ID in the list]
A name that matches no registered type is left out of the list, and the names after it move up one position. Every maximum written after the unknown name then applies to the wrong type. A space beside a comma also breaks the match, so `E1, E2` leaves out `E2`. Write the names without spaces.
:::
