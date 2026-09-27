---
key: ScrollMethod
summary: Which of three coast-scroll behaviors the held right mouse button drives.
see_also: [ScrollRate, AutoScroll]
when_omitted:
  kind: value
  value: "0"
---

Coast scrolling moves the tactical map while the right mouse button is held down and dragged. It starts once the pointer has moved a short distance from the point where the button went down. From then on, the further the pointer is from that point, the further the map moves. [`ScrollRate`](/keys/scrollrate/) plus one divides every distance in the table below.

| Value | Behavior |
| --- | --- |
| `0` | The map scrolls steadily toward the side the pointer was dragged to, by the pointer's offset every sixtieth of a second. The pointer stays where it is. |
| `1` | Each movement of the pointer scrolls the map once, by twelve times the movement, and the pointer is put back on the press point. How far the map moves depends on how far the mouse moves, not on how long the button is held. |
| `2` | The same as `1`, but the map scrolls the opposite way, so the ground follows the hand as if dragged. |

The game controls dialog offers `0` and `1` as a single check box and saves the choice to `sun.ini` when accepted. A ticked box stores `0` and a cleared one stores `1`. `2` is available only by editing the file, and the box shows it as cleared, so accepting the dialog replaces it with `1`.

:::caution[Keep the value between 0 and 2]
Any other value gives coast scrolling a distance of zero. Dragging with the right button then shows the coast-scroll cursor but does not move the map.
:::
