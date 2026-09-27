---
key: ConditionRed
summary: The fraction of maximum strength at or below which an object counts as critically damaged.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: ".5"
---

At or below this fraction of its maximum strength, an object's health bar and selection pips turn red. The same threshold changes several behaviors:

- A hit that takes an object from above the threshold to below it springs the [Quarter health](/mapping/events/tevent-enter-red/) trigger events.
- An airborne aircraft below the threshold trails `SGRYSMK1` smoke. The animation is fixed in the engine.
- A computer house sells a damaged structure only while the structure is below the threshold. [When the computer repairs](/systems/repair/#when-the-computer-repairs) lists the other conditions.
- An engineer targets an allied structure only while the structure is at or below the threshold.
- Outside a campaign, with the multiplayer engineer option on, an engineer that enters an enemy structure above the threshold [damages it instead of capturing it](/systems/capture/#damaging-it-instead). A structure the Neutral house owns is captured as usual.
- An object at or below the threshold [starts to cloak](/systems/cloaking/#starting-a-cloak) only by chance, frame by frame.
- A [`Doggie=yes`](/keys/doggie/) soldier that an attacker hits at or below the threshold panics, unless it is already scared or is fearless.
- Below the threshold, [`ConditionRedSparkingProbability`](/keys/conditionredsparkingprobability/) sets the chance of damage sparks.

The engine default equals the default of [`ConditionYellow`](/keys/conditionyellow/). With neither key set, an object turns red at the moment it would turn yellow, and the yellow stage never shows.
