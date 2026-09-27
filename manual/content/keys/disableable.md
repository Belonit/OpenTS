---
key: Disableable
summary: Parsed flag that the engine never uses.
no_effect: true
see_also: ["system:emp-pulse", "system:power", Powered]
when_omitted:
  kind: value
  value: "yes"
---

`Disableable=no` does not protect a structure from being shut down. Other settings decide that:

- An EM pulse powers off and stuns every structure it reaches unless the structure's type sets [`ImmuneToEMP=yes`](/keys/immunetoemp/). [What a pulse reaches](/systems/emp-pulse/#what-a-pulse-reaches) lists the other exceptions.
- Low power shuts down only a structure whose type sets [`Powered=yes`](/keys/powered/) and drains power.
