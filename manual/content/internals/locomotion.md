---
title: Locomotion and piggybacking
summary: Defines runtime locomotor ownership, temporary replacement, restoration, and persistence identity.
category: simulation-systems
source_files:
  - code/iloco.h
  - code/ipiggy.h
  - code/loco.h
  - code/foot.h
  - code/foot.cpp
  - code/techtype.h
  - code/techtype.cpp
  - code/droppod.h
  - code/droppod.cpp
  - code/drive.cpp
  - code/walk.cpp
---

Every aircraft, infantryman and vehicle moves through one locomotor: the `ILocomotion` object that its `FootClass::Locomotion` pointer owns. The locomotor is a separate object linked to that `FootClass`. `FootClass` does not inherit movement behavior from it.

## Object locomotion

The [`Locomotor`](/keys/locomotor/) key sets `TechnoTypeClass::Locomotor`, the class identifier of the type's ordinary locomotor. The aircraft, infantry and vehicle constructors create a locomotor of that class, link it to the new object with `Link_To_Object`, and store it in `FootClass::Locomotion`.

Movement, destination, layer, cell occupation and locomotor-specific drawing queries all go to the locomotor currently in `FootClass::Locomotion`. That locomotor can be a temporary one, so code that depends on how an object moves must check the class of the current `Locomotion` pointer. The type's `Locomotor` identifier names only the ordinary locomotor.

## Piggybacking

A piggyback lets a temporary locomotor, the carrier, move an object while it holds the object's previous locomotor for later restoration. Only the drive, walk and drop-pod locomotors can be carriers, because only they derive from `IPiggyback`. `LocomotionClass` does not derive from it and supplies none of its four methods. A new carrier must derive from `IPiggyback` and implement `Begin_Piggyback`, `End_Piggyback`, `Is_Ok_To_End` and `Is_Piggybacking`.

A piggyback has three steps:

| Step | Effect |
| --- | --- |
| `carrier->Begin_Piggyback(previous)` | The carrier takes ownership of `previous` and answers `true`. It answers `false` and leaves `previous` with the caller when `previous` is empty or the carrier already holds a locomotor. |
| Assign the carrier to `FootClass::Locomotion` | The carrier now moves the object. Link the carrier to the same object with `Link_To_Object` before this assignment. |
| `carrier->End_Piggyback()` | Returns the carried locomotor to the caller, which assigns it back to `FootClass::Locomotion`. Returns an empty pointer when the carrier holds nothing. |

The engine starts a piggyback in these cases:

- A passenger delivered by drop pod gets a drop-pod carrier for the fall.
- A tunneler that surfaces, or leaves a war factory, gets a drive carrier.
- A jumpjet infantryman on a trip it should make on foot gets a walk carrier.

`FootClass::Link_DropPod` creates the drop-pod locomotor, hands it the passenger's current locomotor through `Begin_Piggyback`, and makes the drop pod the passenger's `Locomotion`. At touchdown the drop pod takes the carried locomotor back with `End_Piggyback` and restores it before placing the passenger on the ground. A drop pod that carries nothing stays the passenger's locomotor.

### Ending a piggyback

`Is_Piggybacking` reports whether the carrier holds a locomotor. `Is_Ok_To_End` reports whether that locomotor may be restored now. Code that restores the carried locomotor whenever it can, such as the switch to idle mode, checks `Is_Ok_To_End` first.

Every carrier answers `false` to `Is_Ok_To_End` while it reports movement or holds nothing. The drive carrier also answers `false` while it is locked, and the walk carrier while a movement step is in progress.

A drop pod always reports movement, so its `Is_Ok_To_End` never answers `true`. Touchdown therefore calls `End_Piggyback` directly.

## Persistence identity

`FootClass::Serialize` saves the current locomotor as a separate record headed by its class identifier, and loading creates a locomotor of that class from the record. Each carrier also saves whether it holds a locomotor and, when it does, saves that locomotor as a nested record with its own class identifier. A save made during a piggyback therefore records the carrier's class identifier for `Locomotion` and restores both the carrier and the locomotor it will hand back.
