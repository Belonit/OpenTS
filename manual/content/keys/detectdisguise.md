---
key: DetectDisguise
summary: Lets an object see a disguised soldier for what it is when it scans for a target.
see_also: [Disguised, Disguise, AIDetectDisguise, "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

```ini title="rules.ini"
[DOG] ; an InfantryType registered in [InfantryTypes]
DetectDisguise=yes
```

An object of a type set this way can pick a disguised soldier as a target when it scans. A [`Disguised=yes`](/keys/disguised/) soldier is normally [rejected as a scan candidate](/systems/target-selection/#why-a-candidate-is-rejected), so nothing finds one by scanning. This flag lifts that rejection, and the object scores the soldier like any other candidate.

The scanning object needs no weapon. [Scan radius](/systems/target-selection/#scan-radius) gives the reach of each scan.

The flag belongs to the scanning object's type, so it works the same for a player's object and a computer's. A computer house can also see through every disguise with [`AIDetectDisguise=yes`](/keys/aidetectdisguise/), whatever its objects' types set.

Every other rule about a candidate still applies. In particular, an ally is rejected before the disguise is considered, so the flag cannot turn an object on a friendly spy unless the scanning object is an infantryman that has gone berserk.

The flag changes nothing else about the disguise. To other players the soldier still shows the disguise's name and artwork, drawn in the viewing player's colors, and appears on radar in that player's color. A vehicle still refuses to run it over on its own initiative.
