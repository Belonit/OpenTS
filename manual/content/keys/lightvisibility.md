---
key: LightVisibility
summary: The radius, in leptons, that a structure's glow reaches.
see_also: [LightIntensity, LightRedTint, LightGreenTint, LightBlueTint]
when_omitted:
  kind: value
  value: "5000"
---

```ini title="rules.ini"
[MYLAMP] ; example light post BuildingType
LightVisibility=2560  ; ten cells at 256 leptons each
LightIntensity=0.2
LightRedTint=0.05
LightGreenTint=0.05
LightBlueTint=0.01
```

The value is a radius in leptons, not cells. A cell is 256 leptons across, so the built-in `5000` reaches a little over nineteen cells.

The structure's [`LightIntensity`](/keys/lightintensity/) and its three tints are strongest at its center and fall off in a straight line to nothing at this radius. A wider radius therefore also lights every cell already inside it more strongly.

The radius has no effect when `LightIntensity` is `0`.

:::caution[Keep the radius above zero]
Set `LightVisibility` above `0` on any structure with a light. At `0`, the game divides by zero when it lights a cell whose center lies exactly on the structure's center, which crashes the game. A foundation with an odd number of cells along each side, such as 1x1 or 3x3, puts its center on a cell's center.
:::
