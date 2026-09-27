---
title: Keep the deploy cursor on a vehicle that repairs
category: fix
release: 0.2.0
targets:
- type: key
  id: DeploysInto
  effect: changed
credit: [ZivDero, Rampastring]
---

A vehicle that can deploy and whose weapon repairs allied units used to show the select cursor over itself, so clicking it did not deploy it. It now shows the deploy cursor, or the no-deploy cursor where it cannot deploy, as other deployable vehicles do. No shipped vehicle both repairs and deploys.
