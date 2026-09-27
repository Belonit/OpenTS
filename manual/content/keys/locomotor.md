---
key: Locomotor
summary: The class identifier of the locomotion object created to move each instance of the type.
when_omitted:
  kind: value
  value: "{4A582747-9839-11D1-B709-00A024DDAFD1}"
  note: The teleport locomotor. No stock type names this identifier, and the only stock type that leaves the key out is the crate-goodie `BASEUNIT` shell.
---

The value is a class identifier in the usual braced form. Each aircraft, infantryman and vehicle gets a locomotor of the named class when it is created, and that class decides how it travels: whether it drives, walks, hovers, flies, burrows or strides. [Locomotion and piggybacking](/internals/locomotion/) explains how an object can for a time be moved by a different locomotor than its type names. The engine registers ten classes:

| Identifier | Movement |
| --- | --- |
| `{4A582741-9839-11D1-B709-00A024DDAFD1}` | Drive: wheeled and tracked ground travel along the cell grid |
| `{4A582742-9839-11D1-B709-00A024DDAFD1}` | Hover: floats at [`HoverHeight`](/keys/hoverheight/) above the surface |
| `{4A582743-9839-11D1-B709-00A024DDAFD1}` | Tunnel: burrows out of sight and travels underground |
| `{4A582744-9839-11D1-B709-00A024DDAFD1}` | Walk: infantry |
| `{4A582745-9839-11D1-B709-00A024DDAFD1}` | Ballistic: the falling [drop pod](/systems/drop-pods/) |
| `{4A582746-9839-11D1-B709-00A024DDAFD1}` | Flyer: aircraft |
| `{4A582747-9839-11D1-B709-00A024DDAFD1}` | Teleport |
| `{55D141B8-DB94-11D1-AC98-006008055BB5}` | Mech: the striding walk of stock walkers such as the Titan and Juggernaut |
| `{92612C46-F71F-11D1-AC9F-006008055BB5}` | Jumpjet: powered hover flight, tuned by `[JumpjetControls]` |
| `{3DC0B295-6546-11D3-80B0-00902792494C}` | Levitate: the stock jellyfish |

A structure never gets a locomotor, so the key does nothing in a BuildingType's section.

Reinforcements that would otherwise drive in from the map edge come up from underground near their arrival point instead, but only when every member of the group names the tunnel locomotor. A single member with any other locomotor makes the whole group drive in.

A vehicle leaving a war factory drives out according to the locomotor it is using at that moment:

- A drive locomotor follows the factory's exit track.
- A tunnel locomotor is given a temporary drive locomotor to follow the exit track and clear the door.
- Any other locomotor is ordered to a fixed cell just beyond the factory.

Text that is not a well-formed class identifier is ignored, and the type keeps the value it had before this assignment.

:::danger[An identifier that names no locomotor crashes the game]
A well-formed identifier that matches none of the ten classes above leaves the object without a locomotor. The game crashes as the first aircraft, infantryman or vehicle of that type is created. For a type the map places, that happens while the scenario is loading.
:::
