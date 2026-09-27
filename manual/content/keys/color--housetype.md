---
key: Color
scope: housetype
label: Country color
see_also: [Multiplay, Side]
when_omitted:
  kind: computed
  note: The first color scheme in the loaded list.
---

The value names an entry in `[Colors]`, in any letter case. A name that matches no entry leaves the country on the scheme it already had. [The `Color` overview](/keys/color/) describes `[Colors]` and the other `Color=` settings.

```ini title="rules.ini"
[GDI]
Color=Gold
```

Every house of this country starts with this scheme and draws everything it owns in it. The setting has a visible effect only in a campaign game, and there a house record in the scenario map can override it for that one house with [`Color=`](/keys/color/#scope-house-per-scenario).

In a skirmish or multiplayer game, each human player's house takes the color picked in the lobby, and each computer player gets an unused color at random or the one a launch file names. The `Neutral` and `Special` houses are drawn in `LightGrey`. The country's `Color=` is not used.

Lobby setup also changes the country's scheme, and the alliance, declaration-of-war and connection messages about a player take their color from the country, not the house. In a lobby game these messages therefore show one of the first four schemes declared in `[Colors]`, chosen by the lobby color of the last house of that country to be set up. They do not show the player's color.
