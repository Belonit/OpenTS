---
key: OnFire
summary: The three flames a structure shows when a sparky warhead knocks it down a damage level.
see_also: [Sparky, SmallFire, LargeFire, TreeFire]
when_omitted:
  kind: value
  value: ""
---

```ini title="rules.ini"
[AudioVisual]
OnFire=MYFIRE_SM,MYFIRE_MD,MYFIRE_LG ; AnimTypes registered in [Animations]
```

The game uses the first three entries, by position. The first two are the common flames and the third is the rare one; [`Sparky`](/keys/sparky/) covers the roll that picks between them. Entries after the third are never used.

[`SmallFire`](/keys/smallfire/) and [`LargeFire`](/keys/largefire/) supply the other structure fires, and [`TreeFire`](/keys/treefire/) supplies the flames on a burning terrain object.

:::danger[Give `OnFire` three entries]
The sparky roll takes each entry by position without checking the list length, and the list is empty until a rules file sets it. A roll that lands on a missing entry either crashes the game or creates an animation from unrelated memory. [`Sparky`](/keys/sparky/) gives the odds.
:::
