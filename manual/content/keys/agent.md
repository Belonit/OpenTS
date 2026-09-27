---
key: Agent
summary: Makes a soldier spy on the structure it walks into.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

When a spy walks into a structure, its house is recorded as spying on that structure and the spy is consumed. [Infiltrating it](/systems/capture/#infiltrating-it) covers what the spying house then sees.

Write [`Infiltrate=yes`](/keys/infiltrate/) in the same section. `Agent=yes` does not turn `Infiltrate` on, and without it the soldier cannot be sent into a structure at all.

A type that also sets [`Engineer=yes`](/keys/engineer/#scope-infantrytype) behaves as an engineer and never spies, because the engineer handling takes the arrival first.

A spy sent at another house's deployed vehicle takes that vehicle instead of spying on it, the same as any other soldier. [The vehicle branch](/systems/capture/#the-vehicle-branch) covers it.
