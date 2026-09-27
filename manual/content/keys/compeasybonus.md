---
key: CompEasyBonus
summary: Whether a computer house drops one difficulty slot when the session holds more than one human seat.
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: "yes"
---

Outside a campaign, `CompEasyBonus=yes` makes each computer house play one difficulty setting harder when the session has more than one human seat. Observer seats count, so one player with an observer against computer houses still gets the bonus. At the Easy setting the computer plays as it would at Normal, and at Normal as it would at Hard. At Hard nothing changes. A skirmish against the computer alone has one human seat, so the bonus never applies there.

Despite its name, the bonus never makes the computer easier. [Difficulty settings](/systems/difficulty/#the-computers-bonus-with-more-than-one-human) explains why moving a computer house down one difficulty slot makes it stronger.

A computer seat whose [launch file](/formats/spawn-ini/) sets its `[HouseHandicaps]` entry plays at that entry's slot instead, with no bonus.

The new slot applies everywhere the house reads its slot: the combat and production figures from its difficulty section, each per-difficulty list in `[General]`, and the [difficulty flag its AI triggers are tested against](/systems/ai-team-production/#difficulty).
