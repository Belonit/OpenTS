---
key: SidebarCameoText
summary: Draws each sidebar cameo's object name across the bottom of the cameo.
see_also: ["system:sidebar"]
when_omitted:
  kind: value
  value: "yes"
---

The caption is the object's name alone, wrapped to the width of the cameo. The setting also changes the cameo's tooltip: with captions on, the tooltip shows only the price, and with captions off it shows the name and the price. [Captions and tooltips](/systems/sidebar/#captions-and-tooltips) describes both.

The game controls dialog has the same switch. Accepting the dialog applies the change at once and saves it to `sun.ini`.

A loaded saved game shows captions as they were when it was saved, whatever the setting says. The setting applies again from the next scenario that starts.
