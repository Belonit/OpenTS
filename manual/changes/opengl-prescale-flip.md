---
title: Keep the pixel-art scaled frame upright on OpenGL
category: fix
release: 0.2.0
targets: []
credit: [EJ]
---

On OpenGL, the default pixel-art filter showed the picture upside down whenever it enlarged the frame by a factor that is not a whole number, as it usually does in fullscreen. The picture is now upright. Other renderers, the other filters, and whole-number enlargements already showed it upright and are unchanged.
