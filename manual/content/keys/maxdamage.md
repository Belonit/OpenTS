---
key: MaxDamage
summary: The most strength one object can lose to one hit of ordinary damage.
see_also: ["MinDamage", "Verses", "AtomDamage"]
when_omitted:
  kind: value
  value: "1000"
---

No object loses more than this much strength to one hit, after the warhead's [`Verses`](/keys/verses/), the distance from the blast and [`MinDamage`](/keys/mindamage/) have been applied. The cap is the last step of [the damage calculation](/systems/warheads/#what-the-target-loses), so it also overrides a higher `MinDamage`. It applies to each object separately: a blast that reaches several objects can take up to this much from each of them.

Two kinds of damage are not capped:

- Healing, which is negative damage.
- Forced damage, which the engine deals directly and which skips the whole calculation. An exploding crate, for example, deals its full damage to the unit that picked it up, even above this cap.
