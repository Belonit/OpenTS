---
key: IsPowered
summary: Whether the superweapon stops charging while its house is short of power.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "yes"
---

With `IsPowered=yes`, a weapon that a structure grants is suspended while its house is short of power or none of its granting structures is switched on. A suspended weapon stops charging and cannot be fired. It resumes when power returns and a granting structure is on. `IsPowered=no` keeps the weapon charging through both conditions.

The value decides only whether a held weapon is suspended. A weapon granted while its house is already short of power arrives suspended even with `IsPowered=no`, and resumes on the same terms. [Power output and drain](/systems/power/#superweapons) covers suspension in full.

:::caution[Suspension can cost the whole charge]
An ordinary weapon resumes charging from where it stopped. Two kinds of weapon lose their progress instead:

- A [`UseChargeDrain=yes`](/keys/usechargedrain/) weapon restarts from a full [`RechargeTime`](/keys/rechargetime/) when it resumes.
- A [`ManualControl=yes`](/keys/manualcontrol/) weapon stays stopped when it resumes. Its next start begins again from a full delay.

`IsPowered=no` protects both kinds, unless the weapon was granted during a shortfall and arrived suspended.
:::
