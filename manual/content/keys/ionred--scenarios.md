---
key: IonRed
scope: scenarios
label: Scenario lighting
see_also: [Red, IonGreen, IonBlue, "system:ion-storms"]
when_omitted:
  kind: context-dependent
  note: The value this scenario's Red key sets, read earlier in the same section. With neither key present that is 1, leaving the red channel unchanged.
---

While an ion storm runs, `IonRed` replaces [`Red`](/keys/red/) as the multiplier on the red channel of every terrain palette. It also tints the lit [house color schemes](/glossary/#color-scheme), which `Red` never reaches. [`IonGreen`](/keys/iongreen/) and [`IonBlue`](/keys/ionblue/) do the same for the green and blue channels. The scale matches the ordinary tint keys: `1` leaves colors unchanged, `0` removes the channel, and values are clamped to the range 0 through 2.

The ion tint replaces the ordinary tint; the two are not combined. With `Red=.7` and `IonRed=1.2`, a storm draws the red channel at `1.2`.

The three ion tints are applied on the frame the storm breaks and removed on the frame it ends. Neither switch fades, so the whole map changes color in one step while its [ambient level](/keys/ionambient/) is still changing.

A terrain palette first built during a storm, such as one for a newly lit cell, takes the ion tints at once, so it matches the rest of the map.
