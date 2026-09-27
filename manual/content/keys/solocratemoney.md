---
key: SoloCrateMoney
summary: Credits a campaign crate pays when its result is money.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "2000"
---

In a campaign, a crate whose result is money pays exactly this many credits. That includes a result that turns into money, such as a free vehicle that cannot be placed. Outside a campaign the key has no effect, and money crates pay a random amount.

Set it to `0` to give campaign crates that random payout as well. [Money and free units](/systems/crates/#money-and-free-units) gives the range, which depends on [`CrateMoneyBonus`](/keys/cratemoneybonus/), and says which house receives the credits.
