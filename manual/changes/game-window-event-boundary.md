---
title: Separate game window responses from native events
category: internal
release: 0.2.0
targets: []
credit: [Krisztiaan]
---

A port to another windowing system can now call the game's handling of paint, right-button-release and mouse-wheel messages from its own event loop, and pass the game the display's refresh rate when it changes. Controls and rendering are unchanged.
