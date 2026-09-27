---
key: BaseDefenseDelay
summary: Minutes during which no house calls up base defenders again against an attacker that a call-up has already covered.
see_also: ["system:base-attacked", ComputerBaseDefenseResponse]
when_omitted:
  kind: value
  value: ".25"
---

When a computer house's call-up against an attacker is more than covered, no house calls up defenders against that attacker again for this many minutes. A call-up is more than covered in either of two cases:

- the `ThreatPosed` of the defenders it orders adds up to more than its [strength budget](/systems/base-attacked/#the-strength-budget);
- objects already targeting the attacker push the budget below zero, so it orders no defenders.

The cooldown belongs to the attacker, not to the house that answered. While it runs, every house [refuses the call-up](/systems/base-attacked/#when-the-call-up-is-refused) against that attacker, including the house that set it.

These call-ups set no cooldown, and the next hit from the attacker triggers another:

- a call-up that ran out of qualifying defenders before their total exceeded the budget;
- a call-up whose budget is exactly zero, from the start or once objects already targeting the attacker are counted;
- a call-up against an attacker with `ThreatPosed=0`.
