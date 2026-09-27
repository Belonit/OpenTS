---
key: Delay
scope: sounds
label: Silence between cycles
see_also: [Loop, Control]
when_omitted:
  kind: value
  value: "0"
---

The silence between the cycles of a looping sound. With `PREDELAY` in the sound's [`Control=`](/keys/control/), the same silence also comes once before the first sample, whether or not the sound loops. Without `LOOP` or `PREDELAY`, the key has no effect.

One number gives a fixed silence. Two numbers, in either order, give a range, and each silence draws its own length from it. The numbers are milliseconds. If either number has a decimal point, both are read as seconds: `250 750` and `0.25 0.75` mean the same thing, but `250 0.75` means 0.75 to 250 seconds. Negative numbers are read as `0`.

```ini title="sound01.ini"
[CRICKETS]
Control=LOOP
Delay=500 1500
```

`CRICKETS` repeats with a silence of half a second to a second and a half between cycles.

The silence is measured in real time, so game speed does not change it.

With a delay, each cycle after a silence must win a voice again under [`Limit=`](/keys/limit/) and [`Priority=`](/keys/priority/#scope-sounds), and a cycle that loses ends the play. The attack still plays only before the first cycle, and the decay only after the last. Without a delay, the cycles follow one another with no gap.
