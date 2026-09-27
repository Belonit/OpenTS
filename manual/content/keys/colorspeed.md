---
key: ColorSpeed
summary: How fast a spark or railgun particle slides from one of its colors to the next.
see_also: ["ColorList", "StartColor1", "StartColor2"]
when_omitted:
  kind: value
  value: "0"
---

Larger values make a [`Spark` or `Railgun`](/keys/behaveslike/#scope-particletype) particle move through its [`ColorList`](/keys/colorlist/) faster. Other behaviors ignore the setting.

Each fade from one color to the next runs from 0 to 1. Every frame, the particle adds this value plus a random amount below `0.05` to its progress. When progress passes 1, the particle starts the fade to the following color from 0. On the fade to the last color, it stops there and keeps that color.

At `0.13` the particle reaches the next color about every seven frames, and at `0.01` about every thirty. With the key omitted, the random amount alone moves it on about every forty frames.

The random amount is drawn for each particle every frame, so particles created together drift out of step in color.

A negative value slows the fade. Below `-0.025`, progress falls on average and runs below 0, so the particle does not reach its next color and is drawn in colors outside its list.
