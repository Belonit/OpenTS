---
key: DoubleOwned
summary: Opens the type's production to every country, outside campaign games only.
see_also: ["system:production"]
when_omitted:
  kind: value
  value: "no"
---

Outside campaign games, the production checks treat the type as owned by every country. Its [`Owner=`](/keys/owner/) list then stops limiting who can produce it:

- A structure passes the [ownership gate](/systems/production/#ownership) from any construction yard the house owns, whatever country that yard acts as.
- The factory search accepts any factory of the house, whatever country its type lists.
- A factory type with the flag can produce objects of any country.

In a campaign game the flag does nothing and `Owner=` applies as written. One section can therefore restrict a type in a campaign and open it to every country in skirmish and multiplayer games.

Other rules that read `Owner=` ignore the flag. These include a computer house planning its base, the units a player starts a multiplayer game with, and the vehicle a crate gives.
