---
title: Read the multiplayer 155mm and ARTYHE values from the rules
category: balance
release: 0.2.0
targets:
- type: key
  id: Verses
  effect: changed
- type: key
  id: ProneDamage
  effect: changed
- type: key
  id: Damage
  effect: changed
- type: key
  id: ROF
  effect: changed
breaking: true
migration:
- 'Add an [`MPLAYER.INI`](/formats/multiplayer-rules/) with `[155mm] Damage=115` and `ROF=150` to keep the artillery figures a match used before. Without it the weapon fires at whatever `RULES.INI` gives it, which in stock data is `Damage=150` and `ROF=110`.'
- 'Add `[ARTYHE] Verses=40%,85%,68%,35%,35%` and `ProneDamage=30%` to the same file to keep the artillery warhead. Stock data leaves `Verses=100%,85%,68%,35%,35%` and `ProneDamage=150%` in force outside campaigns, so artillery becomes markedly stronger against unarmored targets and against prone soldiers.'
credit:
- ZivDero
---

Outside campaigns, the game no longer replaces the values of the `155mm` weapon and the `ARTYHE` warhead with fixed multiplayer figures. Both now take [`Damage`](/keys/damage/), [`ROF`](/keys/rof/), [`Verses`](/keys/verses/) and [`ProneDamage`](/keys/pronedamage/) from the rules in every game type. With the retail `RULES.INI`, artillery in skirmish and network games therefore deals more damage per shot, fires more often, and hits unarmored targets and prone infantry much harder than before.
