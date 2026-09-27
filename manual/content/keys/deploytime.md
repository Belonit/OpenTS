---
key: DeployTime
summary: How long a gate or a factory door takes to open or close, in game minutes.
see_also: ["system:walls-and-gates", "Gate"]
when_omitted:
  kind: value
  value: "0"
---

The figure is in game minutes and may be a fraction. One game minute is 900 frames, so `.044` is about 40 frames and `1` is 900. The stock gates and war factories use `.044`.

```ini title="rules.ini"
[GAGATE_A]
Gate=yes
DeployTime=.044   ; about 40 frames each way
```

The same figure times both opening and closing. Two kinds of structure use it:

| Structure | What the figure times |
| --- | --- |
| A [`Gate=yes`](/keys/gate/) BuildingType | The [gate's movement](/systems/walls-and-gates/#holding-and-closing) between shut and open. How far the movement has got picks which of the [`GateStages`](/keys/gatestages/) frames to draw. |
| A [`WeaponsFactory=yes`](/keys/weaponsfactory/) BuildingType | The door opening for and closing behind each finished vehicle. The vehicle drives out only once the door is fully open, and the factory releases no other vehicle until the door has closed again, so a longer figure delays every vehicle's exit. How far the door has got picks which frame of [`DoorAnim`](/keys/dooranim/) to draw, out of [`DoorStages`](/keys/doorstages/). |

Both frame counts are set in `art.ini`.

At `0` the gate or door switches straight between its shut and open frames without drawing any frame in between.

The figure does not time a vehicle deploying into a structure; [`DeploysInto`](/keys/deploysinto/) covers that.

:::caution[Only a structure uses the figure]
On an aircraft, a vehicle or an infantry type the figure changes nothing a player can see:

- A transport aircraft starts opening when a passenger approaches to board and starts closing once it is full, but nothing that draws or moves the aircraft reads the count.
- A transport vehicle never starts the count, so it loads and unloads with no delay at all.
- An InfantryType stores the figure and never uses it.
:::
