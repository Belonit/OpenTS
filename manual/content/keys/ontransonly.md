---
key: OnTransOnly
summary: Restricts the team's tag to the members that can carry passengers.
see_also: [Tag, Passengers]
when_omitted:
  kind: value
  value: "no"
---

A team whose TeamType names a [`Tag`](/keys/tag/) normally attaches that tag to every member as it joins. With this set, only a member whose type sets [`Passengers`](/keys/passengers/) above zero receives it. Every other member joins keeping whatever tag it already had.

The setting has no effect on a TeamType without a `Tag`.
