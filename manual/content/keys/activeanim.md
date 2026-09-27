---
key: ActiveAnim
summary: The animation the structure runs in its first active slot.
see_also: ["ActiveAnimDamaged", "ActiveAnimX", "ActiveAnimY", "ActiveAnimYSort", "ActiveAnimZAdjust", "ActiveAnimPowered", "ActiveAnimPoweredLight", "ActiveAnimTwo", "ActiveAnimThree", "ActiveAnimFour", "system:building-animations", "system:power"]
when_omitted:
  kind: value
  value: ""
---

`ActiveAnim=` names the animation, registered in `[Animations]`, that the structure runs in its first active slot. The animation is a separate object pinned to a point on the structure's artwork, playing at its own rate. [Building and emptying a slot](/systems/building-animations/#building-and-emptying-a-slot) covers what happens when the name is too long or not registered.

```ini title="art.ini"
[MYPOWR]                     ; example power plant's Image ID art entry
ActiveAnim=MYSMOKE           ; an AnimType registered in [Animations]
ActiveAnimDamaged=MYFIRE     ; used at ConditionYellow and below
ActiveAnimX=-12              ; twelve pixels left of the drawing point
ActiveAnimY=-30              ; thirty pixels up, onto the chimney
ActiveAnimZAdjust=-5         ; drawn over the structure, not behind it
ActiveAnimPowered=no         ; keeps playing through a power shortfall
```

A BuildingType has four active slots. Slots two, three and four take the same eight settings under the [`ActiveAnimTwo`](/keys/activeanimtwo/), [`ActiveAnimThree`](/keys/activeanimthree/) and [`ActiveAnimFour`](/keys/activeanimfour/) prefixes. [Building animations](/systems/building-animations/) explains the damaged form, the offset, the two draw-order biases and the two power flags.

## When the slot runs

The slot starts when the structure comes online: when its construction finishes, or when the scenario places it. A non-looping animation empties the slot when it plays to its end, and a looping one holds it. All four active slots empty when the structure itself starts to be sold or undeployed, and when it is removed from the game. Selling a structure that has upgrade plugs sells its top plug first, and the active slots keep running.

These events start the slot again if it is empty:

- A repair step that the house can pay for.
- An upgrade plug installed on a structure below maximum strength. Installing the plug also restores the structure to maximum strength.
- The house rechecking its power at full power, when the slot sets [`ActiveAnimPowered=no`](/keys/activeanimpowered/) and [`ActiveAnimPoweredLight=yes`](/keys/activeanimpoweredlight/).
- A [`UnitRepair=yes`](/keys/unitrepair/) service depot ending a repair. This event starts slot one only.

## What belongs to this slot alone

Two structure flags affect the first active slot and no other:

- On a [`SensorArray=yes`](/keys/sensorarray/) structure, the slot starts 30 game frames after the other active slots when the structure first comes online. Every later start has no delay.
- A [`UnitRepair=yes`](/keys/unitrepair/) service depot stops the slot when it begins repairing a vehicle. It starts the slot again when the repair ends because the vehicle is fully repaired, the vehicle leaves, or the house cannot pay for the next repair step. A vehicle left on the pad after an unpaid step is repaired again once the house can pay, and that stops the slot again. If the depot drops the repair mission partway through a repair, the slot stays empty until one of the events above starts it. [A service depot](/keys/specialanim/#a-service-depot) covers the whole sequence.

:::caution[A service depot restarts its animations healthy]
The depot starts this slot in its healthy form. [Starting any slot in one form](/systems/building-animations/#the-damaged-form) switches every animation the structure is running to that form. A depot at or below [`ConditionYellow`](/keys/conditionyellow/) therefore shows healthy animations after each visit, until it next takes damage or is repaired.
:::

A type with four or more [`Upgrades=`](/keys/upgrades/) gives up this slot in two ways. When the art is read, any `PowerUp4` settings that are present replace the matching `ActiveAnim` settings, whether or not a plug is ever installed. Installing a fourth plug then replaces the type's healthy `ActiveAnim` name with the `[Animations]` entry named after the plug's Image ID. Every structure of the type runs that animation the next time this slot starts in its healthy form. A start in the damaged form still uses the old damaged name. [The upgrade slots and the active slots share one array](/systems/building-animations/#the-upgrade-slots-and-the-active-slots-share-one-array) covers the details.
