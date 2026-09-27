---
key: DefenseRatio
summary: Parsed defensive share of a computer base that the engine never uses.
no_effect: true
see_also: ["system:ai-base-building", DefenseLimit, GDIBaseDefenseCoefficient, NodBaseDefenseCoefficient]
when_omitted:
  kind: value
  value: ".5"
---

To change how many defenses a computer base plans, set [`AIBaseDefenseCoefficient`](/keys/aibasedefensecoefficient/) in the house's side section. It scales the defense placeholders added as [the plan's build cost grows](/systems/ai-base-building/#building-the-plan). [`GDIBaseDefenseCoefficient`](/keys/gdibasedefensecoefficient/) and [`NodBaseDefenseCoefficient`](/keys/nodbasedefensecoefficient/) set that coefficient for the first and second sides.
