---
title: The pointer comes back after switching away during loading
category: fix
release: 0.2.0
targets: []
credit: [ZivDero]
---

Switching to another program while the game had hidden its pointer, for example during scenario loading, could leave the pointer hidden after you switched back. Opening a menu showed it again only until the menu closed. The pointer now reappears as soon as the game shows it again.
