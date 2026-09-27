---
key: LooseRecruit
summary: Parsed TeamType flag that the engine never uses.
see_also: ["system:ai-team-production", Recruiter, Group]
no_effect: true
when_omitted:
  kind: value
  value: "no"
---

To let a team [recruit](/systems/ai-team-production/#recruitment) objects outside its group, set [`Recruiter=yes`](/keys/recruiter/) or give the TeamType a [`Group`](/keys/group/#scope-teamtype) of `-2`.
