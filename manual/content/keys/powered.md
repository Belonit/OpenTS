---
key: Powered
summary: Whether the structure stops working while its house cannot meet its drain.
see_also: ["system:power"]
when_omitted:
  kind: value
  value: "no"
---

While its house is short of power, a structure stops firing if its type is both `Powered=yes` and has a negative [`Power=`](/keys/power/#scope-buildingtype). If its type also keeps the default [`TogglePower=yes`](/keys/togglepower/), the structure goes out of service as well. Its spotlight and laser fence go down, its cloak field shrinks away, and its powered animations pause. Setting only one of the two keys spares the structure from these shutdowns.

Other effects of a shortfall, such as the loss of radar and the pause in superweapon charging, do not read `Powered=`. [What low power costs](/systems/power/#what-low-power-costs) lists each effect and the keys it reads.

```ini title="rules.ini"
[MYOBELISK] ; example laser defense that goes dark at low power
Power=-150
Powered=yes
```

Three effects of `Powered=yes` need no drain:

- The structure can be switched off. The power cursor and the [Turn off building](/mapping/actions/taction-turn-off-attached/) trigger action accept a structure that either drains power or is `Powered=yes`. The power cursor also requires [`TogglePower=yes`](/keys/togglepower/).
- A structure that [produces cash](/systems/produce-cash/#power) pauses its income while its house is short of power or while it is switched off.
- A [`CloakGenerator=yes`](/keys/cloakgenerator/) structure waits for its house to have full power before it rebuilds its field. At `Powered=no` it rebuilds the field during a shortfall.
