---
key: Translucency
scope: animtype
label: Animation fade
see_also: ["Translucent", "TranslucencyDetailLevel", "DetailLevel"]
when_omitted:
  kind: value
  value: "0"
---

Only three values fade the animation: `25` draws it a quarter faded, `50` half faded and `75` three quarters faded. Any other value above `0`, such as `76`, draws it solid. `0` or a negative value sets no fade.

The value is ignored while [`Translucent=yes`](/keys/translucent/#scope-animtype), which fades the animation by stage instead.

The fade applies only at the detail settings that [`TranslucencyDetailLevel`](/keys/translucencydetaillevel/) allows.

For an animation that a structure runs, a value above `0` replaces the structure's fade while the structure cloaks and uncloaks, so the animation keeps its own level throughout. An animation that sets no fade follows the structure instead: a quarter faded as the cloak begins, then half faded.

Once the structure has cloaked completely, an animation with a value above `0` is no longer drawn. This holds even for a player who can still see the structure faintly, such as its owner. An animation that sets no fade stays half faded for that player, and disappears only for a player from whom the structure is hidden.

```ini title="art.ini"
[MYBANG16] ; a blast ring, drawn half faded at any detail setting
Image=MYBANG16
Translucency=50
UseNormalLight=yes
Report=EXPNEW11
```
