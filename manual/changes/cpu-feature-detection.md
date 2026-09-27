---
title: Remove MMX and CMOV detection
category: internal
release: 0.2.0
breaking: true
migration:
- Remove any code that calls `Detect_MMX_Availability`, `Detect_CMOV_Availability`, or `Processor`; all have been removed.
- Remove any use of `UseMMX`, `UseCMOV`, and `HasCMOV`; the flags have been removed along with the assembly that read them.
- Drop the MMX flag argument from `Get_CPU_Type` calls; the parameter is gone.
targets: []
credit: [tinix0]
---

OpenTS no longer detects whether the processor supports MMX or CMOV. The routines that used to choose a path by those flags are C++ now and take one path on every processor. Every processor OpenTS runs on has both features, because the builds already require SSE2, which means a Pentium 4 or Athlon 64 onward.

The processor family and vendor CPUID reports are still read and returned through `Get_CPU_Type` and the `CPUType` and `VendorID` globals.
