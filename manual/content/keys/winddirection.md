---
key: WindDirection
summary: The facing that smoke and gas particles drift toward.
see_also: [WindEffect, BehavesLike]
when_omitted:
  kind: value
  value: "-1"
---

`WindDirection` sets one wind direction for the whole map. The value is a facing: `0` is north, toward the top-right of the screen, and each step of `1` turns 45 degrees clockwise, up to `7` for north-west. Each facing sets a base step of up to two leptons along each map axis. The direction stays the same for the whole match.

Only particles whose [`BehavesLike`](/keys/behaveslike/#scope-particletype) is `Gas`, `WeakGas` or `Smoke` drift with the wind. Their ParticleType's [`WindEffect`](/keys/windeffect/) sets how often and how far they drift, and at `0` they do not drift at all. At facing `3`, south-east, the base step of a `Gas` or `WeakGas` particle is 1 lepton along the map's X axis and 2 along its Y axis. Every other facing gives all three behaviors the same base step.

```ini title="rules.ini"
[General]
WindDirection=2  ; drift east
```

:::caution[Set a facing from 0 to 7 before giving any particle wind]
The engine does not check the value, and the default is outside that range. When the key is left out or set outside `0` to `7`, any particle that drifts moves by an unrelated distance in an unrelated direction.
:::
