---
key: Secondary
summary: The WeaponType in the object type's second weapon slot.
see_also: ["system:target-selection"]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[MYTANK] ; example UnitType
Primary=MyCannon      ; each names its own weapon section
Secondary=MyMachineGun
```

An object fires its second weapon only at targets where it scores higher than the weapon in the first slot. Each weapon scores by its warhead's [`Verses`](/keys/verses/) value against the target's armor. The score doubles while the target is in that weapon's range and drops to zero while the weapon cannot fire at it. A tie goes to the first slot. [Which weapon the score assumes](/systems/target-selection/#which-weapon-the-score-assumes) gives the full rule, including how a web weapon overrides the scores.

An elite object keeps this weapon: only the first slot switches to [`Elite`](/keys/elite/). A structure fitted with an upgrade that has a second weapon of its own uses the upgrade's weapon in this slot instead.

A laser or sonic weapon in this slot takes some of its settings from the weapon in the first slot, as [`IsLaser`](/keys/islaser/) and [`IsSonic`](/keys/issonic/) describe.

Writing `none` or `<none>` empties the slot. An ID with no section of its own registers a WeaponType with only its defaults.

:::danger[Give an object with a web weapon a Secondary]
If the first slot's warhead is [`Webby=yes`](/keys/webby/) and this slot is empty, the game can crash when the object is attacked by something the web weapon can fire at but cannot web. That covers every vehicle and structure, a landed aircraft, and any infantry that is immobilized or [`IsWebImmune=yes`](/keys/iswebimmune/). The crash comes when the object decides whether to fight back.
:::
