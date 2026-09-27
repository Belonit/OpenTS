---
key: IsVeins
scope: animtype
label: Vein attack animation
see_also: ["system:veins", "VeinAttack", "VeinDamage"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="art.ini"
[VEINATAC] ; the AnimType named by [AudioVisual] VeinAttack
IsVeins=yes
```

`IsVeins=yes` makes an animation act as a [vein attack](/systems/veins/#standing-in-veins). On every other frame, the animation deals [`VeinDamage`](/keys/veindamage/) to every object in its cell that veins can harm.

When the animation is removed, its cell can start another attack.

The animation is drawn in the local player's color scheme.

:::caution[The animation named by VeinAttack needs the flag]
Without the flag, the [`VeinAttack`](/keys/veinattack/) animation plays as ordinary artwork and deals no damage. Its cell also never starts another attack for the rest of the scenario.
:::
