---
key: UseIonStorms
summary: Makes the random map generator load `ION.INI`, the file that sets up a generated map's ion storms.
see_also: ["system:ion-storms"]
when_omitted:
  kind: value
  value: "no"
  note: "`ION.INI` is not loaded, so generation adds no ion storm triggers."
---

With `UseIonStorms=yes`, the generator loads the file `ION.INI` and takes three things from it:

- its `[General]` section, applied over the loaded rules;
- the six ion lighting values in its `[Lighting]` section, which replace the generated map's;
- its trigger types and tag types, which are added to the map.

The option schedules no storm itself. Storms come from the file's triggers, as [Ion storms](/systems/ion-storms/#random-maps) describes. [Map seed files](/formats/map-seed/) covers the section the option is written in.

```ini title="map seed file"
[RandomMap]
UseIonStorms=yes
```

`ION.INI` is opened by name through the ordinary file search, so a loose file in the game directory takes precedence over one in an archive. [MIX archives](/formats/mix/) covers that search.

Without the Firestorm addon, the option is turned off before any map is built, whether it comes from a seed file or the dialog. The dialog shows its check box only with Firestorm, and its randomize button checks the box about half the time.
