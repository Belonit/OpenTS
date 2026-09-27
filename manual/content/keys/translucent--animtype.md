---
key: Translucent
scope: animtype
label: Animation fade by stage
see_also: ["Translucency", "TranslucencyDetailLevel", "End"]
when_omitted:
  kind: value
  value: "no"
---

The animation fades further as it plays. It is drawn solid through the first fifth of its stages, a quarter faded after that, half faded past two fifths and three quarters faded past three fifths. The fade follows the stage on screen, so a looping, [`Reverse`](/keys/reverse/) or [`PingPong`](/keys/pingpong/) animation fades back in when it returns to an earlier stage.

The thresholds are fractions of the animation's stage count, so changing [`End=`](/keys/end/) moves all three, and a short animation reaches its faintest level within a few stages.

While the flag is set, [`Translucency=`](/keys/translucency/#scope-animtype) is ignored.

The fade applies only at the detail settings that [`TranslucencyDetailLevel`](/keys/translucencydetaillevel/) allows.

For an animation that a structure runs, the fade by stage replaces the structure's cloaking fade. Once the structure has cloaked completely, the animation is not drawn, even for its owner. [`Translucency=`](/keys/translucency/#scope-animtype) describes how an animation with no fade differs.

A [`Tiled=yes`](/keys/tiled/) animation applies the fade to every copy it draws.
