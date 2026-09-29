---
key: RequiredAddon
scope: campaign
label: Campaign expansion
see_also: ["Description", "Scenario"]
when_omitted:
  kind: value
  value: "0"
---

`0` marks a base-game campaign and `1` a Firestorm campaign. The mission list shows base-game campaigns only while no expansion is running, and Firestorm campaigns only while Firestorm is running, so the two sets never appear together.

`-1` shows the campaign whenever any expansion is running. Any other number matches no expansion, so the campaign never appears in the list.
