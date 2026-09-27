---
key: SidebarSorting
summary: Keeps each sidebar strip in a fixed order that depends only on the rules.
see_also: ["system:sidebar"]
when_omitted:
  kind: value
  value: "yes"
---

With sorting on, each strip is kept in the order that [the sidebar page](/systems/sidebar/#the-order-of-the-strips) describes. With `SidebarSorting=no`, each new cameo goes to the end of its strip, so the order depends on when each type was offered.

The game reads the setting once at startup, and no dialog changes it.

A saved game loaded with sorting off keeps the order its strips had when it was saved, because the order in which the cameos arrived is not recorded.
