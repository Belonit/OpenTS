---
key: VoiceMove
summary: The responses a unit speaks when the player gives it an order other than an attack.
see_also: [VoiceAttack, VoiceSelect, VoiceDie, VoiceFeedback]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
VoiceMove=MYTANK_Move1,MYTANK_Move2 ; sound IDs registered in SOUND.INI
```

A unit, meaning a vehicle, infantryman or aircraft, speaks this list when the player clicks to give it any order except an attack, which uses [`VoiceAttack`](/keys/voiceattack/). The orders include moving, guarding, harvesting, entering a transport or structure, capturing, and clicking the unit itself to deploy or unload it. A structure's click orders other than an attack, such as setting a rally point, play no response.

The [guard key](/commands/guardobject/) also uses this list, and it can reach an armed structure that packs up into a vehicle. The deploy key plays no response from this list.

One entry is picked at random and played as a sound without a place, so it does not fade with the object's distance from the view; see [Placed sounds](/systems/sound-effects/#placed-sounds).

An order given to a group produces at most one response. For an order given by clicking, only the first object the order reaches can answer, so the group is silent if that object has no list or the order does not apply to it. With the guard key, only the first selected object that takes the guard order can answer.

Names are matched as described in [Writing the list](/keys/voiceselect/#writing-the-list).
