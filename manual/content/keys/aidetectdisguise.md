---
key: AIDetectDisguise
summary: Lets every computer house see a disguised soldier for what it is when it scans for a target.
see_also: [DetectDisguise, Disguised, "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[AI]
AIDetectDisguise=yes
```

With `AIDetectDisguise=yes`, the units and structures of a computer house can pick a [`Disguised=yes`](/keys/disguised/) soldier as a target when they scan for one. A computer opponent will then attack a spy walking into its base. The units and structures of a player-controlled house still pass the disguised soldier over, unless their type sets `DetectDisguise=yes`.

The test is on who controls the house, not on which house is local, so every machine in a network game makes the same choice. In a campaign, a house the mission gives to the player counts as player-controlled.

To give the ability to particular types instead of a whole side, set [`DetectDisguise=yes`](/keys/detectdisguise/) on those types. The two settings work independently, and either one is enough.
