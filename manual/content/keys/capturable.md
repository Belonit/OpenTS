---
key: Capturable
summary: Lets an engineer capture the structure, and shows the enter cursor over it.
see_also: ["system:capture"]
when_omitted:
  kind: value
  value: "no"
---

An engineer that walks into a non-allied `Capturable=yes` structure takes it for its own house. At `Capturable=no` the engineer is used up and the structure stays with its owner, however the engineer was sent there.

The flag also decides which cursors a player's soldiers get over a non-allied structure. [The cursor](/systems/capture/#the-cursor) gives the full rules.

- Over a visible [`Repairable=yes`](/keys/repairable/) structure, an engineer gets the enter cursor only when this is set. While the structure is above [`EngineerCaptureLevel`](/keys/engineercapturelevel/), the engineer gets the damage action instead. Over a fogged record of a `Repairable=yes` structure, the enter cursor appears whatever `Capturable` says.
- Every [`Infiltrate=yes`](/keys/infiltrate/) soldier, a spy included, gets the enter cursor over a `Capturable=yes`, [`LegalTarget=yes`](/keys/legaltarget/) structure.

An unarmed `Infiltrate=yes` soldier that has no other destination walks to a `Capturable=yes` structure given to it as a target.

A computer house's scan for structures to capture considers only `Capturable=yes` ones, as [a rejected candidate](/systems/target-selection/#why-a-candidate-is-rejected) describes.

Two outcomes ignore the flag:

- A structure that undeploys into a vehicle, other than a [`ConstructionYard=yes`](/keys/constructionyard/) type, is [taken through the vehicle branch](/systems/capture/#the-vehicle-branch), which changes its owner whatever this is set to.
- Outside campaign games, the multiplayer engineer option has engineers [damage a structure instead of taking it](/systems/capture/#damaging-it-instead). `Capturable=no` does not protect a structure from that damage.
