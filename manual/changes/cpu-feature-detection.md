---
title: Remove MMX and CMOV detection
category: internal
release: 0.2.0
breaking: true
targets: []
credit: [tinix0]
---

MMX and CMOV detection and their flags have been removed. The affected routines now use C++ implementations. `Get_CPU_Type` still reports the processor family and vendor, without an MMX flag argument.
