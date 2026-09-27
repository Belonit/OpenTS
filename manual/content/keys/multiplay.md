---
key: Multiplay
summary: Offers the country as a choice when a skirmish or multiplayer game is being set up.
see_also: [MultiplayPassive, Side, Color]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[GDI]
Multiplay=yes
```

The skirmish and LAN setup screens list only the countries with `Multiplay=yes`, each under its [`Name=`](/keys/name/). Leave the flag off a country meant only for the campaign to keep it out of the list. [`Side`](/keys/side/#scope-multiplayer-settings) covers how a player's choice is stored.

A computer player seated from the menu gets a random country with the flag. A [launch file](/formats/spawn-ini/) can name a computer player's country instead. If no country has the flag, computer players take the first country in the rules.

The in-game list of player names and kills beside the radar shows only houses whose country has the flag. A house of any other country plays without appearing there.

Nothing else reads the flag. Whether a house takes part in the contest at all is set by [`MultiplayPassive`](/keys/multiplaypassive/).
