---
title: Separate native window handling from video presentation
category: internal
release: 0.2.0
targets: []
credit: [Krisztiaan]
---

The video presenter no longer queries the Win32 window. The application shell passes it the native window handle, the drawable size in physical pixels and the display refresh rate, so a port to another windowing system can supply them from its own window.
