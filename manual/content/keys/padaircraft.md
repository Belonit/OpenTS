---
key: PadAircraft
summary: The AircraftTypes bundled into the price of the pad they dock at.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: ""
---

The first structure listed in [`Dock=`](/keys/dock/) of the first aircraft here is priced as if it included one of these aircraft, at their average [`Cost=`](/keys/cost/#scope-aircrafttype). Its repairs are priced from its written cost minus that share, so they cost less than the written cost alone would give. Its purchase price and sell refund still follow its written cost, to within a few credits of rounding, because the game adds the share back onto the price.

No structure takes the share when [`SeparateAircraft=yes`](/keys/separateaircraft/) is set, when the list is empty, when the first aircraft has no `Dock=`, or when the dock structure's [`FreeUnit=`](/keys/freeunit/) is an aircraft. The share never applies to any other structure, so a second pad type is priced from its written cost alone.

Separately, a [`HoverPad=yes`](/keys/hoverpad/) structure receives one of the first aircraft in the list the first time it opens, docked on the pad and on guard. It receives none when it opens because it was captured, when its `FreeUnit=` is an aircraft, when the list is empty, or when `SeparateAircraft=yes` is set. Apart from a pad whose `FreeUnit=` is an aircraft, every `HoverPad=yes` structure gets the aircraft, whichever structure takes the price share.
