---
key: Doggie
summary: Gives the soldier the attack dog's panic, its habit of bedding down in Tiberium, and a death that leaves no corpse.
see_also: [Fraidycat, Fearless, ConditionRed, DeadBodies, InfDeath, "system:tiberium"]
when_omitted:
  kind: value
  value: "no"
---

## Fear

Fear is a figure from `0` to `255` that a soldier gains when it is shot at. An ordinary soldier frightened by a hit goes to `100`. A dog goes to `200` instead when the hit leaves its health at or below [`ConditionRed`](/keys/conditionred/). A [`Fearless=yes`](/keys/fearless/) dog is not frightened at all.

At `200` or above, a dog that is standing still with no destination does one of these:

- if it stands on Tiberium, it lies down;
- otherwise it looks for Tiberium within 16 cells and walks there.

A dog never gets the ordinary infantry response to fear, at any fear level. It does not drop prone when frightened or stand up as it calms down, and an armed dog does not reload when its fear returns to zero. Its fear still falls by one point per logic frame, as other infantry's does.

## Sleeping in Tiberium

A dog also lies down outside panic. On the Guard mission, a dog standing on Tiberium turns to face east and lies down, provided it is not already prone and has no target, no destination and no turn in progress. This is how dogs come to be found asleep in the fields.

A prone dog stands up again when it is given a destination.

## Death

Where a warhead's [`InfDeath`](/keys/infdeath/) would set an ordinary soldier alight or electrocute it, a dog plays the `Die5` run of its [`Sequence`](/keys/sequence/) section instead. When a dog's death sequence finishes, the dog is removed without leaving one of the [`DeadBodies`](/keys/deadbodies/) corpses.
