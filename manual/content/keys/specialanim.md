---
key: SpecialAnim
summary: The animation the structure runs in its first special slot.
see_also: ["SpecialAnimDamaged", "SpecialAnimX", "SpecialAnimY", "SpecialAnimYSort", "SpecialAnimZAdjust", "SpecialAnimPowered", "SpecialAnimPoweredLight", "SpecialAnimTwo", "SpecialAnimThree", "ActiveAnim", "UnitRepair", "SiloDamage", "FirestormWall", "system:building-animations"]
when_omitted:
  kind: value
  value: ""
---

The value names an animation registered in `[Animations]`. The structure runs it as an attached animation: a separate animation pinned to a point on the structure's artwork, playing at its own rate, and created and removed as the structure changes state. A name that no `[Animations]` entry registers creates nothing. [Building animations](/systems/building-animations/) covers what the seven companion settings do and which art entry each of them is read from.

## What starts a special animation

The active slots are filled when the structure comes online. A special slot is filled only by an event, and only three flags on the structure's type raise those events: [`UnitRepair=yes`](/keys/unitrepair/), [`SiloDamage=yes`](/keys/silodamage/) and [`FirestormWall=yes`](/keys/firestormwall/). A structure with none of the three runs no special animation, whatever its special-slot settings say, except through the power route at the end of this section.

The three slots are not interchangeable. Which of them a structure uses depends on which flag it has.

### A service depot

On a `UnitRepair=yes` depot the three slots are one sequence around [the repair cycle](/systems/repair/#one-step-at-a-time):

- The **first** slot starts when the depot begins repairing a vehicle, together with the structure's [`ProductionAnim`](/keys/productionanim/). Active slot one stops at the same moment.
- The **second** slot starts when the first slot's animation plays to its end, but only if the depot is still on its repair mission and still in contact with the vehicle.
- The **third** slot starts when the visit ends: the vehicle left, the repair finished, or the house could not pay for the next step. At that moment the second slot and `ProductionAnim` stop and active slot one starts again.

A depot can also leave its repair mission while the second slot or `ProductionAnim` is still running. On its next update it starts the third slot and stops the other two, but active slot one stays empty.

This example sets up a service depot:

```ini title="art.ini"
[MYDEPOT] ; example service depot, UnitRepair=yes and no Image= in rules.ini
SpecialAnim=MYDEPTC1         ; runs as the repair begins
SpecialAnimTwo=MYDEPTC2      ; takes over once MYDEPTC1 plays out
SpecialAnimThree=MYDEPTC3    ; runs as the vehicle is released
SpecialAnimZAdjust=-100      ; all three drawn over the structure
SpecialAnimTwoZAdjust=-100
SpecialAnimThreeZAdjust=-100
```

:::caution[A looping first animation stalls the sequence]
The second slot waits for the first animation to play out, and the repair cycle never stops the first. A looping `SpecialAnim` therefore holds the first slot until the structure begins to be sold or is taken off the map. The second slot never appears, and the first keeps running between visits as well as during them.
:::

### A storage structure

On a `SiloDamage=yes` structure, the first slot is the fill indicator. The structure sets its frame from the amount of Tiberium stored, so it does not play on its own. [`SiloDamage`](/keys/silodamage/) gives the frame for each fill level. The indicator never uses the second or third slot.

The indicator always starts from `SpecialAnim=`, never from [`SpecialAnimDamaged=`](/keys/specialanimdamaged/). A missing or unregistered `SpecialAnim=` crashes the game; [`SiloDamage`](/keys/silodamage/) says when.

### A firestorm wall section

A `FirestormWall=yes` section fills the first two slots with animations named in `[AudioVisual]`, at fixed offsets and a fixed depth bias of -10. [The firestorm wall](/systems/laser-fences/#raising-and-lowering-the-wall) covers when each of the two appears. The section's `SpecialAnim=` and [`SpecialAnimTwo=`](/keys/specialanimtwo/), with their offsets and biases, are not used for them. Raising or lowering the wall never starts the third slot.

### A powered light on any structure

Each time a house rechecks its power at full power, it creates every missing `…PoweredLight=yes` animation on its structures, special slots included. A special slot with [`SpecialAnimPowered=no`](/keys/specialanimpowered/) and [`SpecialAnimPoweredLight=yes`](/keys/specialanimpoweredlight/) therefore runs on any structure, whatever its flags. This is the only way a structure with none of the three flags runs a special animation. [Power](/systems/building-animations/#power) covers what the two flags do and which of them is used.
