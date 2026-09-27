---
key: CrushSound
scope: animtype
label: Crushed sound
no_effect: true
see_also: [Crushable, Report]
when_omitted:
  kind: value
  value: none
---

The sound plays only when a crusher runs over its victim, and an animation can never be run over: a crusher finds its victims among a cell's occupants or in the cell's overlay, and an animation is neither. [`Crushable`](/keys/crushable/#scope-animtype) gives the details.

An animation's own sound is [`Report`](/keys/report/#scope-animtype), read from the same `art.ini` section.
