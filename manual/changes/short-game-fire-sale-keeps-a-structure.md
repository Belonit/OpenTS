---
title: Keep a structure in a Short Game fire sale
category: balance
release: 0.2.0
targets:
- type: key
  id: FireSaleKeepThreshold
  effect: added
- type: key
  id: FireSaleStructureWeight
  effect: added
credit: [ZivDero, Rampastring]
---

In a Short Game skirmish or multiplayer match, a computer house's fire sale now leaves one structure standing while its vehicles and infantry, plus 2 for each structure not yet being sold, count 8 or more. The house therefore fights on with its army instead of being defeated as its last structure is sold. The structure kept is one that keeps the house in the match, and none is kept when a structure the sale cannot sell already stands. [`FireSaleKeepThreshold`](/keys/firesalekeepthreshold/) and [`FireSaleStructureWeight`](/keys/firesalestructureweight/) in `[AI]` set the two numbers.

Rampastring is credited for the ts-patches change this follows.
