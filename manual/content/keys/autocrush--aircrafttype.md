---
key: AutoCrush
scope: aircrafttype
label: Per-type automatic crushing
no_effect: true
see_also: ["Crusher", "PlayerAutoCrush"]
when_omitted:
  kind: value
  value: "no"
---

The flag looks like a per-type version of the rules-wide [`PlayerAutoCrush`](/keys/playerautocrush/), which lets a human player's vehicles run over an enemy on their own initiative. Neither test that reads it can change the result:

- The decision to drive over an attacker counts the flag only for a house a human plays. The engine makes that decision only for a computer house's vehicles.
- A vehicle closing on its target drives onto it instead of firing when the target is close enough. That test runs only for a computer house, and it accepts either this flag or a computer owner, so the flag never decides it.

Crushing itself is unaffected. A [`Crusher=yes`](/keys/crusher/) vehicle ordered onto something crushable still runs it over. A computer house's crusher still drives over an attacker once the house's [`IQ`](/keys/iq/) reaches the [rules-wide threshold](/keys/autocrush/#scope-global-rules). The stock harvester sets `AutoCrush=yes` and the Devil's Tongue sets `AutoCrush=no`, and neither setting makes a difference.
