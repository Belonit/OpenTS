---
title: Cloakable=yes works on aircraft
category: fix
release: 0.2.0
targets:
- type: key
  id: Cloakable
  effect: changed
credit: [ZivDero, CCHyper]
---

`Cloakable=yes` in an aircraft section used to grant nothing, because aircraft did not copy the flag from their type. Aircraft now copy it like vehicles and infantry, so an aircraft type with `Cloakable=yes` can cloak by itself.

CCHyper is credited for the Vinifera fix this follows.
