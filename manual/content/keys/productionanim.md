---
key: ProductionAnim
summary: The animation a structure plays as it delivers what it built, after a harvester unloads, or while it repairs a vehicle.
see_also: ["ProductionAnimDamaged", "ProductionAnimX", "ProductionAnimY", "ProductionAnimYSort", "ProductionAnimZAdjust", "PreProductionAnim", "ActiveAnim", "system:production"]
when_omitted:
  kind: value
  value: ""
---

`ProductionAnim` names an animation registered in `[Animations]`. The structure plays it in its production slot, one of the animation slots that [Building animations](/systems/building-animations/) describes. The animation is drawn at a fixed point on the structure and runs at its own rate. The slot holds one animation at a time.

Only the first 15 characters of the name are kept, and a name that no `[Animations]` entry registers creates nothing.

Five kinds of structure start the production animation, each at a different moment.

| Structure | Starts when | Stops when |
| --- | --- | --- |
| [`ConstructionYard=yes`](/keys/constructionyard/) | A structure it built finishes its buildup | The animation ends |
| [`Refinery=yes`](/keys/refinery/) | The docked harvester has unloaded the last of its load, or the docked harvester is given a destination and a queued mission other than harvesting | The animation ends |
| [`UnitRepair=yes`](/keys/unitrepair/) | The depot begins repairing the vehicle on it | The repair finishes, the house cannot pay for the next repair step, the vehicle leaves or loses contact with the depot, or the depot stops repairing |
| [`WeaponsFactory=yes`](/keys/weaponsfactory/) | The door begins opening for a finished vehicle | The animation ends |
| Any other structure with [`Factory=`](/keys/factory/) | A finished vehicle or soldier leaves it | The animation ends |

A looping animation never ends by itself, so on every row but the service depot it keeps playing until the structure is sold, undeployed or removed.

The last row covers barracks, and structures that build vehicles without `WeaponsFactory=yes`. A [`Hospital=yes`](/keys/hospital/) or [`Armory=yes`](/keys/armory/) structure does not start the animation when a healed or upgraded soldier leaves, unless its `Factory=` is `InfantryType`. Tiberian Sun ships no structure in that row with a `ProductionAnim`, so the row matters only to a mod that adds one.

:::caution[Give a refinery an animation that ends]
A docked harvester that has finished unloading waits at the refinery until the refinery's production animation ends. If the animation loops, the harvester stays docked and does not go back to harvesting.
:::

:::caution[A damaged structure starts the healthy animation]
Only the construction yard chooses between `ProductionAnim` and [`ProductionAnimDamaged=`](/keys/productionanimdamaged/) by its health. Every other structure starts the healthy `ProductionAnim` even when damaged, and that start switches every animation the damaged structure is running to its healthy form. The damaged forms return at the next hit or repair step that finds the structure at [`ConditionYellow`](/keys/conditionyellow/) or below.
:::

The production animation has no power settings and always behaves as `…Powered=yes`, so a power shortfall or an EMP pulse can freeze it on its current frame. [Power](/systems/building-animations/#power) covers when it freezes and when it resumes.

## Where the settings are read

The two animation names, `ProductionAnim` and `ProductionAnimDamaged`, are read from the structure's `[<Image ID>]` art entry. The X and Y offsets and the two draw-order biases are read from the art entry named after the BuildingType itself, and only when the Image ID entry names at least one of the two animations. For an ordinary structure, which sets no [`Image=`](/keys/image/), both are the same entry. A type that borrows another structure's artwork must write the names and the offsets in two different entries. [Where each setting is read from](/systems/building-animations/#where-each-setting-is-read-from) gives the same split for every slot.

```ini title="rules.ini"
[MYPROC] ; example refinery BuildingType
Image=NAREFN ; its art entries are read from [NAREFN]
```

```ini title="art.ini"
[NAREFN] ; the Image ID entry supplies the two names
ProductionAnim=NAREFN_AR
PreProductionAnim=NAREFN_A

[MYPROC] ; the type's own entry supplies the offsets and biases
ProductionAnimX=-2
ProductionAnimY=2
ProductionAnimZAdjust=-100
```
