---
key: Suffix
scope: housetype
label: Country filename extension
summary: Parsed country filename extension that the engine never uses.
no_effect: true
see_also: [Prefix, Name]
when_omitted:
  kind: value
  value: ""
  note: No suffix is stored.
---

The value is cut to three characters and stored on the country. Nothing in the game reads it.

```ini title="rules.ini"
[GDI]
Suffix=GDI
```
