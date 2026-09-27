---
key: AV
summary: Narrows the target categories the weapon contributes to a scan down to vehicles alone.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

When an object scans for a target, its primary and secondary weapons can add the kinds of target their projectiles are able to attack. A weapon whose projectile is `AV=yes` adds vehicles only. [`AA`](/keys/aa/) and [`AG`](/keys/ag/) on that projectile then add nothing to the scan.

Infantry and vehicles add their weapons' kinds only when the scan names no kind. Structures always add them, and aircraft never do. [What each kind of object considers](/systems/target-selection/#what-each-kind-of-object-considers) gives the full rules.

`AV` does not limit what the weapon may fire at. A target from any other source, such as a player's order, a team script or retaliation, is checked against `AA` and `AG` only.
