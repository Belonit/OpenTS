---
title: Report a crash with a minidump and a readable report
category: feature
release: 0.1.0
breaking: true
targets:
- type: command
  id: launch:no-exception-trap
  effect: removed
- type: command
  id: launch:exception-test
  effect: added
credit: [ZivDero]
---

Crashes now write a minidump, a readable report and the end of the debug log into a separate folder under `Exceptions` beside the executable. This includes startup crashes, crashes on other threads and unrecoverable engine errors. Attach that folder when reporting a crash; see [Crash reports](/using/crash-reports/).

The `-XE` option has been removed; an attached debugger handles a crash before the crash reporter.
