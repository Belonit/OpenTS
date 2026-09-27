---
command_id: HealthFilterAddLower
---

Adds one condition band to the selection and keeps what is already selected. The bands come from the group that [`HealthFilter`](/commands/healthfilter/) remembered:

- With one band of the group selected, it adds the next band the group holds, in the order red, yellow, green, wrapping from green back to red.
- With two bands selected, it adds the third, so the whole group is selected again.
- With the whole group selected, nothing changes.

It does nothing when the selection is not the remembered group or all of one or two of its bands, including before `HealthFilter` has narrowed any selection.
