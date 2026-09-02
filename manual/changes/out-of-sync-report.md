---
title: Write an out-of-sync report with bounded histories
category: feature
release: 0.2.0
targets:
- type: system
  id: developer-mode
  effect: changed
- type: command
  id: launch:desync-test
  effect: added
credit:
- ZivDero
- Rampastring
- dkeeton
---

When a multiplayer game goes out of sync the engine now writes its diagnostic report into the
`Debug` folder beside the executable, named for the local player and the frame, rather than a
`SYNC<n>.TXT` in the working directory. The report is written once per frame and names every
player whose checksum disagreed on it along with both sides' values, records the session identity
and seed so two players' reports can be lined up, keys each object to its stable identifier, and
no longer draws from the shared random generator while it is written. It also carries bounded,
newest-first histories of the recent random draws, target assignments, mission orders, facing
assignments, animation creations and events, so a divergence can be traced to the point it
began. The divergence is now detected before any of the frame's events run, so two players'
reports describe the same point in the game, and the new `-DESYNCTEST=<frame>` launch option
corrupts the local checksum once so that the report can be checked without waiting for a real
divergence. The out-of-sync message box now reads "The game is out of sync." instead of
"Reconnection Error!".

Rampastring is credited for the ts-patches state histories this follows and for the Vinifera
check that reads a frame's checksums before its events run. dkeeton is credited for the expanded
ts-patches sync file, including the FPU control word this report carries.
