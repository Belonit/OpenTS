---
key: Engineer
scope: infantrytype
label: Engineer soldier
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

An engineer that walks into a structure restores an allied one, captures or damages a non-allied one, or repairs a bridge at a bridge repair hut. [Engineers, capture and sabotage](/systems/capture/#walking-in) covers each case, and [An engineer over a structure](/systems/capture/#an-engineer-over-a-structure) covers the cursor a player sees.

`Engineer=yes` also turns [`Infiltrate=yes`](/keys/infiltrate/) on after the section is read, so an `Infiltrate=no` in the same section has no effect. The forced value stays. If a later rules layer writes `Engineer=no` over the type, the soldier loses the engineer behavior but keeps `Infiltrate`. It still gets the enter cursor over a non-allied [`Capturable=yes`](/keys/capturable/) structure it can reach, still walks in, and is consumed there with no effect.

The flag also changes how the engineer moves and fights:

- It is given its target as a movement destination, instead of closing to weapon range.
- It may step into the cell of its target or destination on the guard, area guard and patrol missions. Other soldiers may do so only on the capture, sabotage and enter missions.
- It does not scan for targets on plain guard. [Target selection](/systems/target-selection/#what-each-kind-of-object-considers) treats an engineer as a special case throughout.
- A computer-owned engineer that is damaged on guard or area guard switches to hunt. An idle computer-owned engineer outside a team goes on area guard once its house's IQ reaches [`GuardArea`](/keys/guardarea/).
- Damage an engineer deals never lights the small fires a structure can catch when it is damaged.
