---
key: Difficulty
summary: The campaign difficulty as a slider position, 0 for Easy, 1 for Normal and 2 for Hard.
see_also: ["system:difficulty"]
when_omitted:
  kind: value
  value: "1"
---

A campaign started from the menu is played at this difficulty. Every house under the player's control takes this value as its [difficulty slot](/systems/difficulty/#from-the-setting-to-a-slot), and every other house takes `2` minus it.

The value is taken when the campaign starts, and every later mission of that campaign keeps it. A loaded save keeps the difficulty it was saved with. A campaign started by a launch file uses the file's difficulty instead, and skirmish and multiplayer games use the AI difficulty chosen for the session.

The campaign selection screen and the game controls dialog each have a three-step slider that sets this value. The game controls slider changes it only while no game is running.

The game limits the value to `0` through `2` when it reads `sun.ini`. A value outside that range becomes the nearer end, and the corrected value is written back with the other options.
