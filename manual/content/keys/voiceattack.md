---
key: VoiceAttack
summary: The responses an object speaks when the player orders it to attack.
see_also: [VoiceMove, VoiceSelect, VoiceDie, VoiceFeedback]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
VoiceAttack=MYTANK_Atk1,MYTANK_Atk2 ; sound IDs registered in SOUND.INI
```

An object speaks this list when the player orders it to attack. The response plays as the order is given, before the object checks whether it can reach the target, so an object that cannot hit the target still acknowledges the order. A structure given an attack order speaks this list too.

Every other order a unit takes from the player uses [`VoiceMove`](/keys/voicemove/). An attack the object starts without a player order, such as retaliation, guarding, or an order from a computer house, plays no response.

One entry is picked at random and played as a sound without a place, so it does not fade with the object's distance from the view; see [Placed sounds](/systems/sound-effects/#placed-sounds). An order given to a group produces at most one response, as `VoiceMove` describes.

Names are matched as described in [Writing the list](/keys/voiceselect/#writing-the-list).
