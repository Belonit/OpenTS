---
key: SidebarImage
summary: The name of the shape file drawn as the superweapon's sidebar cameo.
see_also: ["system:superweapons"]
when_omitted:
  kind: computed
  note: The name of the section that declares the superweapon.
---

Write the name without an extension. The engine adds `.SHP` and looks the file up in the mix files when the rules are read, so a value that already ends in `.SHP` is not found. When no file matches, the cameo falls back to the generic `XXICON.SHP`. Only the first 24 characters are kept.

```ini title="rules.ini"
[MyIonStrike]      ; example superweapon section
Type=IonCannon
SidebarImage=IONCICON
```

A weapon listed in `[SuperWeaponTypes]` with no section of its own has no cameo artwork. Loading a saved game gives it one: the engine then looks up the section name and falls back to `XXICON.SHP` in the same way.
