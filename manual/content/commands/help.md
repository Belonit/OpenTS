---
command_id: launch:help
---

The summary goes to the debug console, which stays open until a key is pressed. A Debug build always opens that console. A Release build opens it only when [`-XC`](/using/command-line/#console-debug) comes before `-?`, and otherwise shows nothing.

The summary is the original game's. It lists `-DESTNET`, `-SOCKET`, `-STEALTH` and `-MESSAGES`, of which OpenTS accepts only [`-STEALTH`](/using/command-line/#stealth), which has no effect.
