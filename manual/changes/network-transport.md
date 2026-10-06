---
title: Play network games over UDP instead of IPX
category: feature
release: 0.1.0
breaking: true
migration:
- Allow UDP port 1234 between players on the same broadcast network. IPX network settings no longer apply.
targets:
- type: key
  id: Socket
  effect: removed
- type: key
  id: NetCard
  effect: removed
- type: key
  id: DestNet
  effect: removed
- type: command
  id: launch:destination-network
  effect: removed
- type: command
  id: launch:socket
  effect: removed
credit: [ZivDero, tomsons26]
---

LAN games now use UDP instead of IPX and discover games by broadcasting on each attached network. The IPX network options and the `-SOCKET` and `-DESTNET` launch options have been removed. One machine can host only one LAN game at a time.
