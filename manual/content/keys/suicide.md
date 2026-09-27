---
key: Suicide
summary: Stops the team and its members from answering anything but their script.
see_also: [Annoyance, Reinforce, "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

`Suicide=yes` switches off three reactions that would otherwise pull a team or its members away from the team's script:

- The team ignores damage to its members. A team that has not started does not stop to regroup, and a team that is under way does not turn on the attacker or [reform](/keys/annoyance/).
- Members on the Move mission do not [look for targets along the way](/systems/target-selection/#when-an-object-scans). Only computer houses make that scan, so this change affects only them.
- Members do not [retaliate](/systems/target-selection/#retaliation), whichever house owns them. Damage from a veinhole warhead is the exception, which a member answers as any other object would.

Members still attack the targets the team's script gives them. On any mission other than Move, a member still scans for targets as it would without this setting.
