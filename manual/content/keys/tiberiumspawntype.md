---
key: TiberiumSpawnType
summary: The overlay a landing animation plants its Tiberium from.
see_also: ["IsTiberium", "TiberiumSpreadRadius", "system:tiberium"]
when_omitted:
  kind: value
  value: none
---

Each cell that takes Tiberium gets one of four overlay types, chosen at random: the one named here or one of the three that follow it in `[OverlayTypes]`. A patch therefore mixes the four overlays. [`IsTiberium`](/keys/istiberium/#scope-animtype) covers which cells take Tiberium and the growth stage they start at.

The setting applies only to an animation that sets `IsTiberium=yes` and is thrown by [`Bouncer=yes`](/keys/bouncer/) or [`IsMeteor=yes`](/keys/ismeteor/#scope-animtype). Such an animation with no type named here plants nothing, whatever [`TiberiumSpreadRadius`](/keys/tiberiumspreadradius/) says.

The shipped small meteor, `METSMALL`, sets `IsTiberium` but names no type here, so it plants nothing itself. The Tiberium left by a meteor strike comes from the debris it breaks into:

```ini title="art.ini"
[METDEBRI]              ; the chunks a meteor breaks into
Bouncer=yes
IsTiberium=true
TiberiumSpawnType=TIB01 ; the first of the green Tiberium overlays
```

The fragment omits the rest of the section, including the [`LoopCount=-1`](/keys/loopcount/) that keeps a thrown animation playing until it lands.

:::danger[Name a listed overlay type with three more after it]
The three overlay types that follow the named one are taken by position, with no check that they exist. If the named type is one of the last three entries in `[OverlayTypes]`, the pick can run past the end of the list and crash the game when it plants the Tiberium. In the shipped rules, those last three entries are `TROCK05`, `VEINHOLEDUMMY` and `CRATE`. A name missing from `[OverlayTypes]` is added at the end of the list, so a misspelled name can crash the game the same way.
:::
