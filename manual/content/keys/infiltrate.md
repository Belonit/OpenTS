---
key: Infiltrate
summary: Allows a soldier to be given a structure as a target and to be sent into it.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

`Infiltrate=yes` lets a soldier be sent into a structure. What happens when it arrives comes from other flags: [`Engineer=yes`](/keys/engineer/#scope-infantrytype) repairs, captures or damages the structure, and [`Agent=yes`](/keys/agent/) spies on it. A soldier with neither flag is [consumed on arrival](/systems/capture/#the-soldier-is-consumed) and nothing else happens. A [`C4=yes`](/keys/c4/) soldier ordered to attack a `Repairable=yes` structure is not sent inside; it arms a charge there instead.

The flag changes how the soldier is ordered and how it moves:

- An unarmed soldier of the type gets the attack cursor over non-allied objects, as an armed one does.
- Over a non-allied [`Capturable=yes`](/keys/capturable/) structure, the attack cursor becomes the enter cursor. The [capture page](/systems/capture/#the-cursor) covers the cursor rules.
- An attack order against a structure becomes a capture order, which sends the soldier into it, except in the `C4=yes` case above.
- The soldier keeps a destination in another movement zone. Other soldiers drop such a destination unless they are on an Enter mission.

A computer-owned unarmed soldier of the type [scans only for capturable structures](/systems/target-selection/#what-each-kind-of-object-considers). In the [Spy on bldg @ waypt...](/mapping/missions/tmission-spy/) team mission, members with this flag walk into the target while the rest of the team attacks it.

`C4=yes` and `Engineer=yes` each turn this flag on after the section is read, so an explicit `Infiltrate=no` in the same section has no effect. `Agent=yes` does not, so a spy type needs `Infiltrate=yes` written in its section.
