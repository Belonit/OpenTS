---
key: WebbedInfantry
summary: The artwork an infantryman is drawn with while a web holds him.
see_also: [Webby, WebDuration, WebDurationVariation, IsWebImmune, Disguise]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
WebbedInfantry=MYWEBGUY ; an AnimType registered in [Animations]
```

While a web holds an infantryman, he is drawn with this animation's artwork in place of his own.

A [`Webby=yes`](/keys/webby/) hit puts an infantryman who is not [`IsWebImmune=yes`](/keys/iswebimmune/) into his struggling sequence, and [`WebDuration`](/keys/webduration/) sets how long he stays in it. The substitute artwork is used for as long as he is in that sequence.

Only the artwork changes. The frame shown is still picked from the soldier's own struggling sequence, and his facing, house colors and position are unchanged. Build the substitute so its frames line up with the struggling frames of every infantry type that can be webbed.

With the key unset, a webbed soldier struggles in his own artwork.

The web artwork takes precedence over the [`Disguise`](/keys/disguise/) artwork, so a webbed spy shows the web instead of his cover.
