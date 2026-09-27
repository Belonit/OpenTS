---
key: Group
scope: taskforce
label: TaskForce recruitment group
see_also: ["system:ai-team-production"]
when_omitted:
  kind: value
  value: "-1"
---

A TeamType that uses this TaskForce and leaves its own [`Group`](/keys/group/#scope-teamtype) at `-1` uses this value in its place, both as its [recruitment group](/systems/ai-team-production/#recruitment) and as the group it gives its members. A TeamType that sets its own `Group` to any other value, including the wildcard `-2`, ignores this one.
