---
key: PlayerAutoCrush
summary: Parsed crushing permission that the engine never uses.
no_effect: true
see_also: ["Crush", "AutoCrush", "Crusher"]
when_omitted:
  kind: value
  value: "no"
---

The only test that reads this setting would let a player's vehicle run over an attacker automatically. That test runs only for vehicles of computer-controlled houses, so it never sees a player's vehicle, and the setting changes nothing.

[`Crush`](/keys/crush/) covers what decides whether a computer-controlled vehicle drives over an attacker or shoots it.
