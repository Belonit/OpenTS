---
key: WaterCaves
summary: The tile set that supplies the eight cave mouths cut into a cliff at the water line.
see_also: [WaterfallEast, WaterSet]
when_omitted:
  kind: value
  value: "-1"
  note: No tile set is bound to the role.
---

The [random map generator](/formats/map-seed/) treats all eight pieces as cliff on every cell they cover. Several of its passes avoid or build around cliff cells: raising high ground, seeding hills, laying shore pieces, and placing bridges and urban areas.

Outside the generator nothing reads the role. On any map, a cave mouth's land type, and so where units can go, comes from its tile artwork.

With the role unresolved, the generator treats no tile as a cave mouth.
