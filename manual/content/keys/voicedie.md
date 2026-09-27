---
key: VoiceDie
summary: The responses an object speaks as it is destroyed.
see_also: [VoiceFeedback, VoiceSelect, VoiceMove, VoiceAttack, MaxDebris]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
VoiceDie=MYTANK_Die1,MYTANK_Die2 ; sound IDs registered in SOUND.INI
```

When damage destroys an object, it speaks one entry picked at random from this list. The response plays before the object's debris, its explosion animation and any [`Explodes=yes`](/keys/explodes/#scope-aircrafttype) blast.

Unlike the order responses, it is a placed sound at the object's position, so it fades and pans with where the object is on screen; see [Placed sounds](/systems/sound-effects/#placed-sounds). The owner does not matter: an enemy object dying in view is heard the same as one of the player's own.

Names are matched as described in [Writing the list](/keys/voiceselect/#writing-the-list).
