---
key: IonStormWarning
summary: Seconds of warning between a scripted ion storm being ordered and the storm breaking.
see_also: ["system:ion-storms"]
when_omitted:
  kind: value
  value: "31"
---

```ini title="rules.ini"
[General]
IonStormWarning=31
```

A storm ordered by the [Ion Storm start...](/mapping/actions/taction-ion-storm-start/) trigger action or the [Ion storm start in...](/mapping/missions/tmission-ion-storm-start/) team mission breaks this many seconds later.

During the countdown, EVA announces the approaching storm and an on-screen message shows for ten seconds each time the remaining time reaches a multiple of 15 seconds. At `31` the announcements come 30 and 15 seconds before the storm. At `15` or less there are none.

At `0` the storm breaks on the frame the action or mission runs, with no EVA warning beforehand.

[The warning](/systems/ion-storms/#the-warning) covers a second storm ordered while a countdown is already running.
