---
key: FreeBuildup
summary: Releases the structure's construction artwork once it is no longer needed.
see_also: ["Buildup", "DemandLoadBuildup"]
when_omitted:
  kind: value
  value: "no"
---

With [`DemandLoadBuildup=yes`](/keys/demandloadbuildup/), this flag unloads the type's construction artwork after each use. That happens after a structure of the type is created, when a structure finishes its construction animation, when a structure of the type is removed from the game, and once more by the time the first structure of the type is drawn. The artwork is read from disk again the next time it is needed.

Without `DemandLoadBuildup=yes`, the flag has no effect, and the construction artwork loaded with the rules stays loaded.
