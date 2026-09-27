---
key: EngineerDamage
summary: Parsed engineer damage figure that the engine never uses.
see_also: ["system:capture", "EngineerCaptureLevel"]
no_effect: true
when_omitted:
  kind: value
  value: "0"
---

Outside a campaign game with the multiplayer engineer option on, the damage an engineer deals follows [`ConditionRed`](/keys/conditionred/) and uses [`C4Warhead`](/keys/c4warhead/), as [Damaging it instead](/systems/capture/#damaging-it-instead) explains.
