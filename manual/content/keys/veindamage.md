---
key: VeinDamage
summary: Raw damage a vein cell deals on every second frame.
see_also: ["system:veins", "VeinholeWarhead", "ImmuneToVeins"]
when_omitted:
  kind: value
  value: "2"
---

`VeinDamage` is the raw damage of each hit in a [vein attack](/systems/veins/#standing-in-veins). A hit lands on every other frame and strikes every vulnerable building, vehicle, infantryman and aircraft in the cell at once.

The damage is dealt with [`VeinholeWarhead`](/keys/veinholewarhead/), whose modifier for each object's armor scales it as for any other warhead. With no warhead set, vein attacks deal no damage whatever this value is.

An object can take this damage more than once every other frame when its cell runs several attacks at once. [`VeinAttack`](/keys/veinattack/) explains when that happens.
