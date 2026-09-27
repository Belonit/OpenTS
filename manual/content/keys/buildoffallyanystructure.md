---
key: BuildOffAllyAnyStructure
summary: Which of an ally's buildings can anchor a placement when the match allows building off allies.
see_also: [BaseNormal, ConstructionYard, "system:base-adjacency"]
when_omitted:
  kind: value
  value: "yes"
---

```ini title="rules.ini"
[MultiplayerDefaults]
BuildOffAllyAnyStructure=no
```

With `no`, an ally's building anchors a placement only when its type is a [`ConstructionYard=yes`](/keys/constructionyard/) type. With `yes`, any ally building anchors one. Either way, the building's type must also have [`BaseNormal=yes`](/keys/basenormal/), the same test the player's own buildings pass.

The key applies only when the match allows [building off an ally](/systems/base-adjacency/#building-off-an-ally). It never changes which of the player's own buildings anchor a placement.
