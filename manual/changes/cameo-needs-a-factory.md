---
title: Only offer a cameo some structure can build
category: fix
release: 0.2.0
targets:
- type: system
  id: sidebar
  effect: changed
credit: [ZivDero]
---

A type can pass the player's build checks while none of the player's factories can produce it, for example because its [`Owner=`](/keys/owner/) shares no country with any of them. Such a type used to appear on the sidebar and vanish again in a loop, and the new construction options announcement played each time it appeared. It is now kept off the sidebar.
