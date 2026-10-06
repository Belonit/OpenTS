---
title: Declare sides in the side list alone
category: fix
release: 0.2.0
targets:
- type: key
  id: Side
  scope: housetype
  effect: changed
- type: key
  id: Side
  scope: themes
  effect: changed
- type: key
  id: SpeechSide
  effect: changed
- type: format
  id: rules-registries
  effect: changed
breaking: true
migration:
- Declare every side under `[Sides]` in `rules.ini`, listing its countries directly. Expand any side names used in those lists into country names.
- For a country already listed under `[Sides]`, edit that list to change its side; its own `Side=` no longer overrides the list.
credit: [ZivDero]
---

A country listed under `[Sides]` in `rules.ini` now keeps that side whatever `Side=` its section sets. Several shipped missions, such as `gdi10b.map`, write `Side=GDI` in their `[Nod]` section, and that no longer moves Nod onto GDI's side.

A `Side=` on a country or a theme, or a mission's `[Basic] SpeechSide=`, that names a side missing from `[Sides]` used to create that side. It is now ignored and logged.

A `[Sides]` value now lists countries only. A side name in it used to add all of that side's countries. Now it adds only the country of the same name, and is skipped when no country has that name.
