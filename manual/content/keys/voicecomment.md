---
key: VoiceComment
summary: The idle remark and the delivered remark a soldier speaks, in that order.
see_also: [Passengers]
when_omitted:
  kind: value
  value: ""
---

The first entry is a remark an idle soldier sometimes makes. The second is a remark it makes when a structure or a transport aircraft delivers it. Entries past the second are never played. Both remarks play as sound effects at the soldier's position.

| Entry | Played when |
| --- | --- |
| First | One time in three when an idle outcome calls for the second idle animation, if the soldier is unselected and owned by the local player |
| Second | The soldier completes its first step onto a cell after being delivered |

```ini title="rules.ini"
[MYCIVILIAN] ; example InfantryType
VoiceComment=21-I000,21-I002 ; sound IDs registered in SOUND.INI
```

Each time the idle timer set by [`IdleActionFrequency`](/keys/idleactionfrequency/) runs out, the soldier draws one of eleven equally likely outcomes. Three of them play the second idle animation, and each of those three speaks the first entry one time in three. An eligible soldier therefore makes the idle remark on about one idle in eleven. The remark does not need the animation: a type whose art has no second idle animation still speaks on the roll.

A soldier is delivered when it is unloaded from a landed transport aircraft, or when it walks out of a structure's exit after the structure builds it or after a hospital or armory finishes with it. A jump-jet soldier that flies off from the exit, such as toward a rally point, is not delivered. Neither is a reinforcement that appears from a structure. The soldier makes the delivered remark once per delivery, so a soldier delivered again speaks again. Infantry unloaded from a ground transport or dropped by parachute are not delivered and make no remark.

Each entry must match a sound ID registered in [SOUND.INI](/formats/sound-ini/). An unmatched entry is dropped, and every later entry moves forward one place. If the first entry is misspelled, for example, the second becomes the idle remark and the soldier has no delivered remark. A space after a comma makes the following name unmatched.
