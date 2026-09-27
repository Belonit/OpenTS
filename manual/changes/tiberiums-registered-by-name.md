---
title: Register Tiberium types by name
category: fix
release: 0.2.0
targets:
- type: format
  id: rules-registries
  effect: changed
- type: system
  id: tiberium
  effect: changed
credit: [ZivDero]
---

Each `[Tiberiums]` entry now registers the type it names, as the other rules lists do, and the number on the entry is ignored. Before, an entry whose number matched a registered type's Tiberium slot updated that type and ignored the name.

A map or any later rules file now changes a Tiberium type by writing its section alone. Before, the type also had to be listed in that file's `[Tiberiums]`.

Once four types are registered, an entry naming a new type is skipped. Before, a fifth type overran the four Tiberium compartments that harvesters, storage structures and houses hold.
