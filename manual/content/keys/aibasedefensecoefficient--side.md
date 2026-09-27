---
key: AIBaseDefenseCoefficient
scope: side
label: Side base defense coefficient
see_also: [AIBaseDefensePlaceholders, "system:ai-base-building"]
when_omitted:
  kind: computed
  note: The first side takes GDIBaseDefenseCoefficient and the second NodBaseDefenseCoefficient, as each rules file sets them; any other side uses 1.
---

```ini title="rules.ini"
[GDI]
AIBaseDefenseCoefficient=1.5
```

Scales how many base defenses a computer house playing for this side mixes into its base plan as the plan grows more expensive. A higher value gives more defenses, earlier in the plan. The house applies it when it [generates its plan](/systems/ai-base-building/#building-the-plan).

Before each plan entry from the fourth on, the house works out how many defenses it wants so far:

1. It takes `C`, the combined cost at this house's prices of the structures already copied into the plan, not counting the first (normally the construction yard). Towers and placeholders add nothing to `C`.
2. It computes `(C - 2000) / 1500` and truncates it to a whole number.
3. It multiplies that by this value and truncates again.

When the result exceeds the defenses already planned, the difference goes into the plan as `-1` placeholders. The [defense planner](/systems/ai-base-building/#base-defenses) later fills each placeholder with a defense structure.

For example, at a coefficient of `1.5`:

- When `C` is 4300, `(4300 - 2000) / 1500` truncates to 1, and 1 times 1.5 truncates to 1. One placeholder goes in.
- When `C` later reaches 6100, `(6100 - 2000) / 1500` truncates to 2, and 2 times 1.5 is 3. With one already planned, two more placeholders go in ahead of the next entry.

The formula has no difficulty term, but a harder game [plans more extra refineries](/systems/ai-base-building/#building-the-plan), and their cost counts toward `C`. At the same coefficient, a harder game therefore reaches each defense threshold earlier in the plan.

This value does not scale the block of [`AIBaseDefensePlaceholders`](/keys/aibasedefenseplaceholders/) placeholders added after the last entry.

At `0`, the house mixes no defenses into the plan. Any trailing block and any defenses along its perimeter wall remain.
