---
key: Crawls
summary: Chooses whether a prone soldier of this type crawls at about two thirds of its speed or moves at about half again its speed.
see_also: ["Sequence", "Speed"]
when_omitted:
  kind: value
  value: "yes"
---

The flag sets how fast a prone soldier of the type moves:

| Value | Prone speed |
| --- | --- |
| `yes` | About two thirds of the soldier's upright speed. The third removed is rounded down, so a slow soldier keeps a little more. |
| `no` | About one and a half times its upright speed, with the added half rounded down, so the soldier moves faster lying down than standing |

The flag does not choose an animation. A prone soldier that moves plays the `Crawl` run of its [`Sequence`](/keys/sequence/) section at either value.
