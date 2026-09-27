---
key: CD
scope: campaign
label: Campaign disc
see_also: ["Scenario", "FinalMovie", "RequiredAddon"]
when_omitted:
  kind: value
  value: "-1"
---

`0` names the GDI disc, `1` the Nod disc and `2` the Firestorm disc, and `-1` names none. The game never asks for a disc. The number decides two things: whether the campaign opens with an introduction movie, and which side's artwork its loading screen shows.

Only a campaign whose value is below `2`, `-1` included, can open with an introduction movie before its first mission's briefing, and the value picks which movie. [Campaign progression](/systems/campaign-progression/#the-campaign-level-number) gives the movie file names, the fallback when a file is missing, and the other conditions the movie waits for.

A campaign mission's loading screen shows GDI artwork for `0` and Nod artwork for `1`. Each side has two pictures for each screen size, and one of the two is picked at random on every load. A negative value, `-1` included, gets the GDI artwork.

For a value above `1`, the campaign's [`Scenario`](/keys/scenario/#scope-campaign) value decides instead. If it contains `GDI` anywhere, folder names included and in any letter case, the loading screen shows GDI artwork for every mission of the campaign; otherwise it shows Nod artwork.

A launch file's [`CustomLoadScreen`](/formats/spawn-ini/#what-a-player-is-shown) replaces this artwork whatever this value is, as long as the named picture is found.
