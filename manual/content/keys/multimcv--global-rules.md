---
key: MultiMCV
scope: global-rules
label: Any yard builds for its owner
summary: Lets a construction yard build every structure its type's Owner list allows, whatever country the yard acts as.
see_also: [BuildConst, BaseUnit, ActsLike, "system:production"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[General]
MultiMCV=yes
```

`MultiMCV=yes` stops the country a construction yard acts as from limiting what it builds. The yard type's [`Owner`](/keys/owner/) list still does.

With `no`, a construction yard builds a structure only when the structure's `Owner` list includes the country the yard [acts as](/keys/actslike/). A yard acts as the country of the house that created it, or of the MCV it deployed from, and keeps that country when captured. A captured yard therefore goes on building its original country's structures.

With `yes`, the sidebar and the [factory search](/systems/production/#what-counts-as-a-factory) skip that test. One ownership test remains: the yard type's `Owner` list and the structure's `Owner` list must share a country.

The difference matters when a house deploys a yard type from another country's tree, such as an MCV it built at a captured war factory. That MCV and the yard it deploys into act as the country of the house that built the MCV. With `no`, that yard builds only structures whose `Owner` list includes that house's country and shares a country with the yard type's `Owner` list. With `yes`, it builds every structure whose `Owner` list shares a country with the yard type's `Owner` list.

The key is shared with Vinifera, where it has the same meaning and default.
