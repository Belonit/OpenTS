---
key: CloakingSpeed
summary: The number of game frames an object spends on each stage of its cloaking fade.
see_also: [CloakingStages, "system:cloaking"]
when_omitted:
  kind: value
  value: "7"
---

A vehicle, infantryman or aircraft advances one [`CloakingStages`](/keys/cloakingstages/) stage every `CloakingSpeed` frames while it fades out or back in. A lower value makes it disappear and reappear faster. [The four states](/systems/cloaking/#the-four-states) shows what each stage looks like and where each fade ends.

```ini title="rules.ini"
[MYTANK] ; a UnitType registered in [VehicleTypes]
CloakingSpeed=2 ; with the stock 9 stages: hidden after about 10 frames, visible again after about 16
```

A structure does not use this value. It fades through fifteen fixed translucency levels, one per frame.

:::caution[Keep `CloakingSpeed` above 0]
At `CloakingSpeed=0`, an object can still hide, because the fade out runs at one frame per stage instead. The fade back into view never advances. Once the object starts to reappear, it stays on the first stage of that fade and can neither become visible nor hide again. With the stock `CloakingStages`, other players see it as a ripple and its owner sees it as shadowy.

An object part way through a fade counts as cloaked. A stuck vehicle or infantryman therefore never fires again. A stuck aircraft can still fire, because only a fully hidden aircraft is refused a shot.
:::
