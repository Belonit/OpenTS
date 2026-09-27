---
title: Bound the weapon a Do Explosion At action names
category: fix
release: 0.2.0
targets:
- type: action
  id: TACTION_DO_EXPLOSION
  effect: changed
credit: [ZivDero]
---

Do Explosion At used to read past the end of the rules weapon list when its weapon number was negative or past the last weapon. It now detonates nothing in that case.
