---
key: LocalSize
summary: The part of the playfield the player can see, scroll to and play in, in cells.
see_also: ["system:map-visibility", Size]
when_omitted:
  kind: value
  value: "the whole playfield, trimmed like a written value"
---

The rectangle is trimmed to fit the [playfield](/keys/size/#scope-scenarios) before use. Its origin is raised to at least `2,2`. Its width and height are then reduced so that it ends at least two cells short of the playfield's width and six cells short of its height. The cells outside the trimmed rectangle form the map border.

The playable area limits scrolling, the edges that reinforcements arrive from, and where crates and drop pods land.

Once a vehicle or infantryman has been inside the playable area, it cannot move back out unless it is a train, is on a retreat mission, or belongs to a team that is leaving the map.

A vehicle or infantryman that has been inside and then enters a cell outside the playable area is taken off the map. It stays if it belongs to a team that is not leaving the map, or if it is a train heading to a destination inside the area.

An aircraft that has been inside and is outside the playable area is taken off the map only when it has no target and is either a [loaner](/keys/landable/#what-a-loaner-does) with no team or on a team that is leaving the map. Any other aircraft stays.

The playable area also shapes what the player sees:

- A vehicle, infantryman or structure reveals no ground until it has been inside the playable area. Aircraft are exempt. [Who looks, and when](/systems/map-visibility/#who-looks-and-when) gives the full rule.
- The radar map shows only the playable area.
- The [Goto nearby shroud](/mapping/missions/tmission-goto-shroud/) team mission and the [Reveal zone of waypoint...](/mapping/actions/taction-reveal-zone/) action consider only cells inside it.

The [Resize Player View...](/mapping/actions/taction-resize-player-view/) action replaces the playable area during play, and its rectangle is trimmed the same way. When the new area takes in a vehicle, infantryman or aircraft, that object looks around at once, so widening the area reveals the ground around it straight away. In a campaign, only the player's objects get this look. A structure never does.
