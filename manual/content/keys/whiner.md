---
key: Whiner
summary: Parsed flag that the engine never reaches.
see_also: ["system:base-attacked"]
no_effect: true
when_omitted:
  kind: value
  value: "no"
---

`Whiner=yes` has no effect. If the engine read the flag, damage from an attacker to a computer-controlled team member would count as an [attack on its house's base](/systems/base-attacked/). The engine checks the flag only when an infantry, vehicle or aircraft that belongs to no team takes damage. Such an object has no team type, so the flag is never read. Damage to a team member goes to its team instead, which responds as [answering damage](/systems/ai-team-execution/#answering-damage) describes.

Every team in the shipped `ai.ini` and `aifs.ini` sets the key, and 58 of the 420 set `Whiner=yes`. Those teams behave exactly as the others do.
