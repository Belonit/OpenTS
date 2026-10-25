---
command_id: launch:exception-test
---

| Fault | What the game does |
| --- | --- |
| `av-read` | Reads from an invalid address during startup. |
| `av-write` | Writes to an invalid address during startup. |
| `stack` | Calls itself until the stack overflows. |
| `purecall` | Calls a pure virtual function. |
| `terminate` | Calls `std::terminate`. |
| `invalidparam` | Passes an invalid parameter to a C runtime function. |
| `fatal` | Stops with the engine's own fatal error, `Requested test failure 1.` |
| `worker` | Writes to an invalid address on a second thread. |
| `sectionfault` | Writes to an invalid address, then faults again while the report's frame chain is written, so that the rest of the report can be checked. |
| `wndproc` | Writes to an invalid address inside the window procedure, once the window is open. |
| `timer` | Writes to an invalid address on a timer thread, 200 milliseconds after the window opens. |

Any other value raises nothing. [Crash reports](/using/crash-reports/) describes what a crash leaves.
