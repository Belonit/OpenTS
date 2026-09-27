---
title: Score the economy column by what each player spent
category: fix
release: 0.2.0
targets:
- type: system
  id: multiplayer-score-screen
  effect: changed
credit:
- Rampastring
- ZivDero
---

The economy column on the multiplayer score screen now shows what each player spent, as a percentage of what the biggest spender spent. It used to compare what a player still had standing with everything that player ever had. A player who was wiped out therefore read zero however much they had built, and a player who lost nothing read 100 for building little.

The figures beside the bars in every column now end at their exact values. The longest bar's figure used to stop one step short, so the biggest spender's economy could read 99.
