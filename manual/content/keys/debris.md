---
key: Debris
summary: Animations a Tiberium type can leave behind when a chain reaction wipes one of its cells.
see_also: ["system:tiberium", "Color", "ChainReaction"]
when_omitted:
  kind: value
  value: "none"
  note: An empty list, which leaves nothing behind after a chain reaction.
---

When an animation with [`TiberiumChainReaction=yes`](/keys/tiberiumchainreaction/) clears a cell of this type, it has a one-in-three chance of leaving one animation from this list, picked at random. The debris starts 10 leptons above the animation's position and is recolored with the type's [`Color`](/keys/color/#scope-tiberium).

A cell that detonates through an overlay's [`ChainReaction=yes`](/keys/chainreaction/) leaves no debris.
