---
key: Owner
summary: The countries that may own the type.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ""
---

The value is a comma-separated list of country IDs from `[Houses]`, matched without regard to case. Do not put spaces after the commas: a name with a leading space matches no country. A name that matches no country is skipped.

```ini title="rules.ini"
[MYWEAP] ; example war factory BuildingType
Owner=GDI,Nod
```

The list decides these things:

- **Production.** A BuildingType with an empty list cannot be built, except under [`DoubleOwned=yes`](/keys/doubleowned/) outside campaign games. Otherwise the house also needs a construction yard that [acts as](/keys/actslike/) one of the listed countries, unless [`MultiMCV=yes`](/keys/multimcv/) is set. For every kind of object, the factory that builds it must share at least one country with it, so a factory and a product with no country in common never pair up. [Ownership](/systems/production/#ownership) gives the full test.
- **Computer base planning.** [Base planning](/systems/ai-base-building/) and the role lists it uses consider only types whose list includes the country the house acts as.
- **Multiplayer starting units.** A house receives a starting vehicle or infantry type only if the type lists the house's country. [`AllowedToStartInMultiplayer`](/keys/allowedtostartinmultiplayer/) must also be set.
- **Dropship loadout.** The [loadout screen](/keys/allowableunits/) offers only types that list the player's country.
- **Crate vehicles.** A crate's random vehicle reward picks only [`CrateGoodie=yes`](/keys/crategoodie/) types that list the country the collector's house acts as.

Outside campaign games, [`DoubleOwned=yes`](/keys/doubleowned/) replaces the list for production only, with a mask of the first 31 countries in `[Houses]`. The other uses read the list as written.

The list can name only the first 32 countries in `[Houses]`. Do not rely on a later country owning any type.
