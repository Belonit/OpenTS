---
title: Name an AI trigger's side by its position
category: fix
release: 0.2.0
targets:
- type: format
  id: ai_triggers
  effect: changed
credit: [ZivDero]
---

The side field of an AI trigger record now gives a position in the `[Sides]` list of `rules.ini`, counted from one, and the trigger runs only for houses whose country belongs to that side. The field used to recognize only `1`, for houses acting as the first country in `[Houses]`, and `2`, for the second. Every other value let the trigger run for any house; `0` still does, but a value past the end of `[Sides]` now matches no house.

On the shipped rules the first two countries belong to the first two sides, so `1` and `2` select the same houses as before. ts-patches and Vinifera compare the field with a country's position in `[Houses]`. An AI file written for them works unchanged when every country has the same position in `[Houses]` as its side has in `[Sides]`. Otherwise, replace each value with the position of that country's side.
