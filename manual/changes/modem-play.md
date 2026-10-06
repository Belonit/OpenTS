---
title: Remove modem and null-modem play
category: feature
release: 0.1.0
breaking: true
targets:
- type: command
  id: fixed:cancel-modem-operation
  effect: removed
- type: key
  id: ModemName
  effect: removed
- type: key
  id: Port
  effect: removed
- type: key
  id: IRQ
  effect: removed
- type: key
  id: Baud
  effect: removed
- type: key
  id: Compression
  effect: removed
- type: key
  id: ErrorCorrection
  effect: removed
- type: key
  id: DialMethod
  effect: removed
- type: key
  id: InitStringIndex
  effect: removed
- type: key
  id: CallWaitStringIndex
  effect: removed
- type: key
  id: CallWaitString
  effect: removed
- type: key
  id: PhoneIndex
  effect: removed
credit: [ZivDero]
---

Modem and null-modem games, their setup screens and phone book have been removed. Their `sun.ini` settings are ignored.
