---
key: Description
scope: superweapontype
label: Superweapon sidebar tooltip text
see_also: ["system:superweapons", SidebarImage]
when_omitted:
  kind: value
  value: ""
---

`Description=` adds its text below the superweapon's name in its sidebar cameo tooltip. An empty or omitted value leaves the tooltip with the name alone.

```ini title="rules.ini"
[MyIonStrike]                    ; example superweapon section
Description=Target a structure with a powerful ion blast
```
