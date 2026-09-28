---
key: Cost
summary: The credit price of one object of this type, or the multiplier a country or a difficulty applies to every price it pays.
---

An object's `Cost=` is the base for most credit amounts in the game: what a factory charges, what selling refunds, the score a kill or capture adds, and the experience a kill awards. [`Points=`](/keys/points/) affects none of these.

## What a structure gives away

A structure with a [`FreeUnit=`](/keys/freeunit/), and the pad dock, have a second, reduced price: their `Cost=` minus one or two deductions.

- A `FreeUnit=` deducts that unit's `Cost=`.
- The pad dock deducts the average `Cost=` of the whole [`PadAircraft=`](/keys/padaircraft/) list, rounded down. The pad dock is the first structure type in the [`Dock=`](/keys/dock/) list of the first `PadAircraft=` entry. No structure is the pad dock when [`SeparateAircraft=yes`](/keys/separateaircraft/) is set, and a structure whose `FreeUnit=` is an aircraft never is.

One pad aircraft goes to each [`HoverPad=yes`](/keys/hoverpad/) structure, as `PadAircraft=` explains. A pad dock that is not one of them gets the reduced price and gives no aircraft.

A structure with a `FreeUnit=` never has a reduced price below `0`. A pad dock with no `FreeUnit=` goes below `0` when its `Cost=` is below its deduction.

The full price adds the deductions back. A factory charges it, selling refunds it, and a kill scores and awards experience from it, so these all work from the written `Cost=`. A refinery with `Cost=2000` that gives a 1400-credit harvester still costs 2000 to buy and is still worth 2000 when destroyed.

The exception is a structure with a `FreeUnit=` whose deductions exceed its `Cost=`. Its reduced price stops at `0`, so its full price is the total of the deductions, which is more than its `Cost=`.

The reduced price is used in two places:

- **Repair.** Each [repair step](/systems/repair/#the-cost-of-one-step) is priced from it, so a structure that comes with something costs less to repair than its `Cost=` suggests. A pad dock with a negative reduced price pays 1 credit per step.
- **Anger.** Damage to the structure raises its owner's [anger](/systems/base-attacked/#anger-and-the-declared-enemy) toward the attacker in proportion to the reduced price. Hitting a refinery that gives a harvester therefore raises less anger than its `Cost=` suggests, and hitting a pad dock with a negative reduced price lowers anger.

## What a house pays

The country and difficulty forms of this key are price multipliers. A [country](/keys/cost/#scope-housetype) sets one and a [difficulty](/keys/cost/#scope-difficulty-settings) sets the other. A house multiplies the price of every object it buys by:

- **In a skirmish or a multiplayer match**, its country's multiplier times its difficulty's.
- **In a single-player campaign**, its difficulty's alone. The country's multiplier has no effect in a campaign.

Under a price multiplier, the reduced price and each deduction are multiplied separately, and each drops any fraction. The full price of a structure with a reduced price can therefore differ by a few credits from `Cost=` times the multiplier.
