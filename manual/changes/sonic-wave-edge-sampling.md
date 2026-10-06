---
title: Hold the sonic ripple's samples inside the view
category: fix
release: 0.1.0
targets: []
credit: [ZivDero]
---

Scrolling a sonic wave past the bottom or sides of the view no longer risks a crash. Pixels whose replacement would come from outside the view keep their original color.
