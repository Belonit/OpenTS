---
key: MultipleFactoryCap
scope: global-rules
label: Limit the multiple-factory adjustment
summary: The most factories of one category that count toward the MultipleFactory build-time adjustment.
see_also: [MultipleFactory, "system:production"]
when_omitted:
  kind: value
  value: "0"
---

`MultipleFactoryCap` sets how many factories of one category count toward [`MultipleFactory`](/keys/multiplefactory/). Factories past that number do not change build times. At `MultipleFactoryCap=3`, the second and third factory each apply `MultipleFactory`, and a fourth has no effect. A value of `1` turns the adjustment off, and `0` or below lets every factory count.
