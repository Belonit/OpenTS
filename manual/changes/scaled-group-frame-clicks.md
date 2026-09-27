---
title: Deliver clicks through group frames when the picture is scaled
category: fix
release: 0.2.0
targets: []
credit:
- ZivDero
---

When the picture was scaled to fit the window, a dialog control inside a group frame ignored mouse clicks. A group frame is the thin box drawn around a set of related options. In the skirmish lobby, the Game Speed slider and the Re-Deployable MCV, Short Game and Multi Engineer checkboxes could not be clicked, while the controls around them worked. Controls inside a group frame now respond to clicks at any window size.
