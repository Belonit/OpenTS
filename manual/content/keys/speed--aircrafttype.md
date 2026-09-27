---
key: Speed
scope: aircrafttype
label: Object top speed
see_also: ["Accelerates", "SpeedType"]
when_omitted:
  kind: value
  value: "0"
  note: Zero is immobile. Every stock type that moves sets the key.
---

`Speed` is a percentage of the engine's top speed, not a distance. The value is clamped to the range `0` to `100` and stored on a scale of 0 to 255: `Speed=50` stores 128, and `Speed=100` or anything higher stores 255.

```ini title="rules.ini"
[HARV]
Speed=5 ; stores 12 of 255
```

The stored value is how many leptons the object covers in one game frame at full throttle, before any modifier. A cell is 256 leptons across.

Infantry and vehicles have that distance scaled by:

- their owner's [combined ground speed bias](/systems/difficulty/#how-the-figures-are-combined);
- the veteran speed ability ([`VeteranSpeed`](/keys/veteranspeed/));
- a limpet attached to a vehicle ([`LimpetFactor`](/keys/limpetfactor/));
- a [speed crate](/systems/crates/);
- the throttle the locomotor currently holds;
- one half, for a vehicle carrying the flag in capture the flag.

A prone soldier moves at a speed set by [`Crawls`](/keys/crawls/).

An aircraft on the fly locomotor moves at its type's speed times its throttle; none of the modifiers above apply. A unit on the jumpjet locomotor ignores this key for travel and uses the [jumpjet speed](/keys/speed/#scope-global-rules) instead.

:::caution[Writing `-1` is the same as leaving the key out]
`Speed=-1` keeps whatever speed the type already had. To make a type immobile, write `Speed=0`.
:::
