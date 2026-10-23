---
key: Description
scope: aircrafttype
label: Buildable type sidebar tooltip text
see_also: ["system:sidebar", Cameo, SidebarCameoText]
when_omitted:
  kind: value
  value: ""
---

`Description=` adds its text below the name and price in the sidebar cameo tooltip for any `TechnoTypeClass` type: aircraft, structures, infantry, and vehicles. The tooltip shows the name and price whether or not [`SidebarCameoText`](/keys/sidebarcameotext/) captions the cameo. The setting is read from the type's section in `rules.ini`.

```ini title="rules.ini"
[MYTANK]                         ; example UnitType section
Description=Heavy armored tank
```
