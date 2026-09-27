---
key: BerzerkAllowed
summary: Whether a cyborg turns berserk when a hit takes it below half strength.
see_also: ["Cyborg", "ConditionRed"]
when_omitted:
  kind: value
  value: "no"
---

With `BerzerkAllowed=yes`, a [`Cyborg=yes`](/keys/cyborg/) infantryman goes berserk when one hit takes it from at least half its maximum strength to below half. The hit must not be one that would destroy it. If the same hit also takes it below [`ConditionRed`](/keys/conditionred/), it does not go berserk. Once berserk, a soldier stays berserk.

A berserk soldier attacks allies as well as enemies. Its target search no longer skips allied objects, including allies standing in the cells it scans. A soldier that goes berserk from damage is also put on the guard-area mission.

The [Go Berzerk](/mapping/actions/taction-go-berzerk/) trigger action and the [Go Berzerk](/mapping/missions/tmission-berzerk/) team mission make infantry berserk directly. Neither reads this setting, and neither requires the infantry to be a cyborg or to be damaged.
