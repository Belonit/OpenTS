---
command_id: ScreenCapture
---

Saves the current frame as a PNG file in a `Screenshots` folder, named `SCRN0000.png`, `SCRN0001.png` and so on. Each capture takes the lowest number not yet used in that folder, so it never overwrites an earlier capture.

The `Screenshots` folder is in the [user directory](/using/game-data/#keeping-the-data-somewhere-else) when one is set, and otherwise in the folder that holds the game executable. Each capture creates the folder if it is missing, including after it was deleted while the game was running.

The picture is the whole frame at the game's render resolution, whatever the window size. It includes the sidebar. It does not show the mouse pointer, or any menu, dialog or developer tool drawn over the game.

If the file cannot be written, any partial file is deleted and the failure is recorded in the [debug log](/using/debug-logging/).
