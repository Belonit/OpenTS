---
key: ExpireSound
scope: animtype
label: Animation impact sound
see_also: ["ExpireAnim", "BounceSound", "Report"]
when_omitted:
  kind: value
  value: none
---

The sound that plays where a thrown animation ends, unless it ends low over water as [`ExpireAnim`](/keys/expireanim/#scope-animtype) defines it. It does not depend on `ExpireAnim`: an animation with no impact animation still plays this sound.

An unrecognized sound name counts as omitted.
