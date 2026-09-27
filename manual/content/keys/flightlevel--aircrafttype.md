---
key: FlightLevel
scope: aircrafttype
label: Type cruising altitude
see_also: ["IsDropship", "SlowdownDistance"]
when_omitted:
  kind: value
  value: "-1"
  note: The type flies at the `[General]` FlightLevel.
---

The height above the ground, in leptons, at which objects of this type cruise. The stock rules set `FlightLevel=1600` on the dropship and `400` on the two hunter-seeker drones. Every other stock aircraft flies at the [rules-wide altitude](/keys/flightlevel/#scope-global-rules) of `600`.

```ini title="rules.ini"
[DSHP] ; the stock dropship, an AircraftType
FlightLevel=1600
```

Writing `-1` is the same as leaving the key out: the type uses the rules-wide altitude.

Only objects on the flying locomotor use this height: aircraft, and vehicles such as the hunter-seeker drones. On a type that moves any other way, the key has no effect.

An aircraft placed outside the playable area, or one flown in to deliver something and leave, appears at this height. Any other aircraft placed on the map starts on the ground. An object climbs to this height when it takes off and holds it while it cruises.

Two kinds of type fly lower as they arrive:

- An [`IsDropship=yes`](/keys/isdropship/) type drops to a third of this height once it is within its [`SlowdownDistance`](/keys/slowdowndistance/) of its destination.
- A [hunter seeker](/keys/hunterseeker/#scope-aircrafttype) dives from this height onto its target within [`HunterSeekerDescendProximity`](/keys/hunterseekerdescendproximity/). Farther out, it climbs above this height to clear high ground ahead, as that key describes.
