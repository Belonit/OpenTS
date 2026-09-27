---
command_id: VeterancyFilterAddLower
---

Adds a rank of the group that [`VeterancyFilter`](/commands/veterancyfilter/) remembered to the selection, keeping what is already selected:

- With one rank of the group selected, it adds the next lower rank the group holds, wrapping from rookie back to elite. If the group holds no other rank, nothing changes.
- With two of the group's three ranks selected, it adds the third, so the whole group is selected again.
- With the whole group selected, nothing changes.

It does nothing when the selection is not the remembered group or all of one or two of its ranks, including before `VeterancyFilter` has narrowed any selection.
