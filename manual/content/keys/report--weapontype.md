---
key: Report
scope: weapontype
label: Firing sounds
see_also: ["Anim", "DropPodWeapon"]
when_omitted:
  kind: value
  value: ""
---

An object plays the same entry of this list for every shot it fires. The entry is chosen at random when the object is created and kept for its whole life. A list of several entries therefore varies the sound between objects, not between shots, and two objects of the same type may still pick the same entry.

```ini title="rules.ini"
[MyGatling] ; example WeaponType
Report=TSGUN4,CHAINGN1,INFGUN3 ; registered sound names
```

An entry that does not match a registered sound is dropped from the list. `Report=none` therefore gives an empty list, and a misspelled name makes the list shorter.

`Report=` with nothing after the `=` counts as not set and keeps whatever an earlier rules file set. It cannot clear an inherited list; `Report=none` does.

Three other paths play the list, and each picks a new random entry every time it plays:

- An EM pulse cannon firing at the cell it was aimed at.
- A [`Jellyfish=yes`](/keys/jellyfish/) unit stinging the nine cells around and under it. It checks the cells one at a time. From the first cell where it stings something, it plays the list for that cell and again for every cell it checks after it, whether or not it stings anything there.
- A descending drop pod laying [covering fire](/keys/droppodweapon/) on the cell below it.

:::caution[Give weapons on those paths at least one sound]
With an empty list, the ordinary firing path plays nothing. The EM pulse cannon, the jellyfish sting and the drop pod's covering fire instead play the first sound in the sound list, which in the retail sound list is `FIRSTRM1`, the Firestorm defense burning sound. A weapon used by one of those paths needs at least one entry that matches a registered sound.
:::
