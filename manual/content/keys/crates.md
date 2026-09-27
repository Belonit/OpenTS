---
key: Crates
summary: Starting state of the crates option for a multiplayer or skirmish match.
see_also: ["system:crates"]
when_omitted:
  kind: value
  value: "yes"
---

The value is read when the game starts and becomes the starting state of the match's crate option. The match setup, or the spawn settings for a spawned match, then sets the option for each match. Placing crates at scenario start and replacing expired crates both follow the match option alone.

:::caution[Crates=no still stops pickup replacements]
A collected crate is replaced only when both this key and the match option are on. With `Crates=no` and crates switched on for the match, expired crates are still replaced but collected ones are not. With crates switched off for the match, neither kind is replaced, whatever this key says.

A map's own `[MultiplayerDefaults]` section can set this key for its scenario. That value does not change the match option, but `Crates=no` there also stops pickup replacements. [How long a crate lasts](/systems/crates/#how-long-a-crate-lasts) covers both kinds of replacement.
:::
