---
key: AllyReveal
summary: Whether a house's objects also reveal terrain for its allies.
see_also: ["system:map-visibility"]
when_omitted:
  kind: value
  value: "yes"
---

At `yes`, each [look](/systems/map-visibility/#whose-looks-count) an object makes uncovers the map for every house its owner counts as an ally, as well as for the owner. An ally's sight therefore shows on screen. At `no`, an object's looks uncover the map only for its owner and for any house that has spied on the owner's radar.

Outside a campaign, every human player discovers each structure as it is placed, and a discovered object [looks at once](/systems/map-visibility/#who-looks-and-when). At `yes`, a structure placed by an ally therefore uncovers the ground around it as soon as it is placed.

The setting also decides whether forming an alliance reveals anything at once. At `yes`, when a house makes another its ally, every object of the house that made the alliance looks, so the new ally sees what those objects see. Outside a campaign, the objects of a [passive house](/keys/multiplaypassive/) never look, so its alliances reveal nothing.

The [Enable Ally Reveal](/mapping/actions/taction-enable-ally-reveal/) and [Disable Ally Reveal](/mapping/actions/taction-disable-ally-reveal/) trigger actions change this setting for the rest of the scenario. Saved games keep the change.
