---
key: IonImmune
summary: Exempts the team's members from ion storm lightning damage and from being aimed at.
see_also: [IonStormWarhead, LightningRod, "system:ion-storms"]
when_omitted:
  kind: value
  value: "no"
---

`IonImmune=yes` protects the members of teams of this type from ion storm lightning in two ways:

- An aimed bolt does not [pick a member as its target](/systems/ion-storms/#where-it-strikes), unless the member's type sets [`LightningRod=yes`](/keys/lightningrod/).
- A member takes no damage from an explosion whose warhead is the one [`IonStormWarhead`](/keys/ionstormwarhead/) names. This covers a random bolt that lands on the team, a bolt aimed at a lightning rod member, and any other weapon that uses that warhead.

```ini title="ai.ini or map file"
[MyStormTeam] ; example TeamType
Name=Storm walkers
IonImmune=yes
```

The immunity comes from the team, not the object type. A member loses it when it leaves the team, and an object on no team never has it.

The storm's other effects still apply. An immune team's aircraft and hovercraft lose power, its airborne aircraft crash, and its jumpjet infantry are destroyed if they move while off the ground. [Battlefield effects](/systems/ion-storms/#battlefield-effects) describes them.
