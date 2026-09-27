---
title: Radio contact protocol
summary: Synchronous object messages, reciprocal contact state, docking flows, and teardown rules.
category: simulation-systems
source_files:
  - code/radio.hh
  - code/radio.h
  - code/radio.cpp
  - code/object.cpp
  - code/techno.cpp
  - code/foot.cpp
  - code/unit.cpp
  - code/aircraft.cpp
  - code/building.cpp
  - code/swizzle.h
  - code/savestream.h
---

`RadioClass` delivers messages between two technos: aircraft, infantry, vehicles and structures. `TechnoClass` is the only class derived directly from it. The engine uses these messages to coordinate docking, loading, repair, production, transport and the movement that goes with them. Messages are never queued or sent over the network, and they have nothing to do with EVA or unit voices.

## Contact state

Each radio holds one contact, a non-owning `RadioClass*` named `Radio`. `Transmit_Message` sends to the contact when the caller names no destination. Sending to an explicit destination does not make that object the contact, unless the message is a `RADIO_HELLO` the receiver accepts.

| Member or interface | Contract |
| --- | --- |
| `Radio` | Current contact, or null. The `RADIO_HELLO` handshake makes contacts reciprocal. |
| `In_Radio_Contact()` | True when `Radio` is non-null. |
| `Contact_With_Whom()` | The contact, cast to `TechnoClass*`. |
| `Old[3]` | The three most recent messages this radio received, newest first. `RadioClass::Receive_Message` updates it in every build, and Debug builds show it in the object's debug dump. |
| `Transmit_Message(...)` | Calls the receiver's `Receive_Message` at once and returns its answer, with the exceptions listed under Dispatch rules. |
| `Receive_Message(...)` | Handles a message, starting at the receiver's most derived override. |

A message equal to the newest `Old` entry is not recorded again, so `A, A` records one `A` but `A, B, A` records all three. A derived handler that answers without calling the base does not update the history.

Delivery is synchronous. The receiver's handler runs inside the sender's `Transmit_Message` call and can send further messages before it returns. No message waits for a later frame.

## Dispatch rules

`Transmit_Message(message, param, to)` applies these rules in order:

1. A null `to` is replaced with the sender's contact.
2. If there is still no destination, the result is `RADIO_STATIC`.
3. Sending `RADIO_OVER_OUT` to the current contact clears the sender's `Radio` before the receiver is called.
4. `RADIO_HELLO` first sends `RADIO_OVER_OUT` to the sender's current contact, if it has one, so even a refused HELLO ends the old contact. It then calls the proposed receiver. The sender stores the receiver as its contact only when the answer is `RADIO_ROGER`, and returns any other answer as `RADIO_NEGATIVE`.
5. Every other message calls `to->Receive_Message(...)`. `Transmit_Message` does not change the sender's contact for these messages, but the receiver's handler can, for example by sending `RADIO_HELLO` back.

The sender passed to `Receive_Message` is `Dynamic_Cast<TechnoClass*>(this)`, so a sender that is not a techno arrives as null.

### `RADIO_HELLO` acceptance

No override handles `RADIO_HELLO`, so `RadioClass::Receive_Message` decides it. The receiver accepts only when all of these are true, tested in this order:

1. The receiver's `Strength` is nonzero.
2. The receiver has no contact, or its contact is already the sender.
3. The sender is non-null.
4. The sender's house treats the receiver as an ally.
5. The receiver reports `Is_Techno()`.
6. The receiver's house treats the sender as an ally.

On acceptance the receiver stores the sender as its contact and answers `RADIO_ROGER`. The sender then stores the receiver, which completes the reciprocal pair.

A receiver with nonzero `Strength` that fails any other test answers `RADIO_NEGATIVE`. A receiver with zero `Strength` answers `RADIO_STATIC`, because nothing else in its handler chain accepts HELLO. The sender sees `RADIO_NEGATIVE` in both cases.

## Messages and responses

`RadioMessageType` holds both requests and answers. A receiver can answer with a general response, or with another protocol message that tells the sender what to do next, such as `RADIO_YEA_NOW_WHAT` or `RADIO_RUN_AWAY`. The table groups representative messages; the comments on the enum in `radio.hh` list all of them.

| Group | Representative messages | Purpose |
| --- | --- | --- |
| Contact and tethering | `RADIO_HELLO`, `RADIO_OVER_OUT`, `RADIO_TETHER`, `RADIO_UNTETHER` | Establish or end contact, or tether and untether two objects. |
| General responses | `RADIO_STATIC`, `RADIO_ROGER`, `RADIO_NEGATIVE`, `RADIO_CANT`, `RADIO_ALL_DONE` | Report no receiver or no handler, acceptance, refusal, failure, or completion. |
| Docking and cargo | `RADIO_CAN_LOAD`, `RADIO_DOCKING`, `RADIO_MOVE_HERE`, `RADIO_IM_IN`, `RADIO_UNLOAD`, `RADIO_UNLOADED` | Coordinate passengers, transports, harvesters, depots, helipads, and production exits. |
| Service and production | `RADIO_BUILDING`, `RADIO_COMPLETE`, `RADIO_REPAIR`, `RADIO_RELOAD`, `RADIO_PREPARED` | Advance construction, repair, and rearming. |
| Combat and display | `RADIO_ATTACK_THIS`, `RADIO_REDRAW` | Assign a target, or ask the receiver to redraw. |

## Receiver overrides

`Receive_Message` runs from the receiver's most derived class toward `ObjectClass`. `UnitClass`, `AircraftClass`, `BuildingClass`, `FootClass` and `TechnoClass` override it, handle their own messages, and pass the rest to `BASECLASS::Receive_Message`. `InfantryClass` has no override. `ObjectClass` handles only `RADIO_REDRAW`, so a message that no class in the chain handles returns `RADIO_STATIC`.

Some handled cases also call the base implementation, before or after their own effects. That call keeps shared behavior such as the message history, contact teardown on `RADIO_OVER_OUT`, tethering, and `ObjectClass` handling of `RADIO_REDRAW`. An override that answers a message without calling the base skips all of that behavior for the message.

## Parameter channel

The message parameter is an `intptr_t&`, so a handler can both read it and write it:

- `FootClass` answers `RADIO_NEED_TO_MOVE` by writing its current navigation target, `NavCom`, into it.
- `RADIO_MOVE_HERE` carries the destination. Structure, vehicle and aircraft handlers write a cell or object pointer into it before they send it, and `FootClass` reads it through an `ObjectClass*` cast.
- `RADIO_ATTACK_THIS` carries the target as an `AbstractClass*`.

:::caution[Agree on what the parameter holds]
Each message defines what its parameter holds, and nothing checks it. Keep every sender and receiver of a message in agreement: a receiver that expects a pointer dereferences whatever integer the sender wrote. The parameter is never saved or sent over the network.
:::

The overloads without a parameter argument pass the global `LParam` by reference. Use them only for messages whose handlers neither read nor write the parameter. For any other message, pass a local variable; otherwise a nested message can overwrite a value its caller still needs.

## Refinery docking trace

Docking a harvester at a refinery uses explicit destinations, contact setup, protocol answers and a pointer parameter. The same path serves any structure with `IsDockUnload` or `IsWeeder`.

1. On each update of its `MISSION_ENTER`, the harvester sends `RADIO_DOCKING` to its contact or, when it has none, to the structure it was ordered to enter. If the answer is not `RADIO_ROGER` and the harvester is not tethered, it sends `RADIO_OVER_OUT` and goes idle.
2. A refinery that is switched off answers `RADIO_NEGATIVE`. Otherwise, a refinery with no contact sends `RADIO_HELLO` back to the harvester and ignores the answer. Whether the refinery may serve the harvester at all is a separate question, answered by `RADIO_CAN_LOAD`.
3. The refinery sends `RADIO_NEED_TO_MOVE` to its contact without a parameter, so the `NavCom` that `FootClass` writes goes into the shared `LParam`, which the refinery does not use. The contact answers `RADIO_ROGER` when it has no navigation target or its locomotor is not moving, and `RADIO_NEGATIVE` otherwise.
4. The refinery continues when that answer is `RADIO_ROGER` or when the contact is heading somewhere other than the refinery's docking cell. It puts `&Map[Get_Cell() + Cell(2, 1)]` in `param` and sends `RADIO_MOVE_HERE`.
5. If the harvester already stands in that cell, `FootClass` answers `RADIO_YEA_NOW_WHAT`. Otherwise it takes the cell as its destination and answers `RADIO_ROGER`.
6. On `RADIO_YEA_NOW_WHAT`, the refinery sends `RADIO_TETHER` to its contact and `RADIO_BACKUP_NOW` to the harvester.
7. The harvester turns to face east. Once it faces east and is not moving, a harvester that is tethered, in contact with the refinery and still on `MISSION_ENTER` sends `RADIO_IM_IN` to it, and the refinery switches it to `MISSION_UNLOAD`.

Past the power check in step 2, the refinery answers every `RADIO_DOCKING` with `RADIO_ROGER`, whether or not contact was established. The harvester therefore repeats the exchange on its next mission update until it reaches step 7.

The handlers for this exchange are split across `UnitClass`, `FootClass`, `TechnoClass` and `BuildingClass`. Before changing one answer, trace every sender that branches on it.

## Teardown, persistence, and synchronization

Each cleanup path affects contact differently:

| Path | Effect |
| --- | --- |
| `RADIO_OVER_OUT` | Negotiated teardown. The sender clears `Radio` only when the destination, explicit or default, is its current contact. The receiver clears its own only when the sender is its current contact. |
| `Limbo()` | Sends `RADIO_OVER_OUT` to the contact before the base limbo transition, unless the object is already in limbo. |
| `Detach(target, all)` | Emergency pointer cleanup. Clears `Radio` only when it equals `target` and `all` is true. Sends no message. |
| Destructor | Sends nothing and clears nothing. Limbo or the detach sweep must already have removed every reference to the object. |
| `Serialize()` | Saves `Radio` as a swizzled pointer, which loading remaps to the loaded contact, and saves the `Old` history. |
| `Compute_CRC()` | Adds the contact's ID and RTTI to the multiplayer sync checksum when there is a contact. |

A new way for an object to leave play must either send `RADIO_OVER_OUT` while both objects are still valid or take part in the detach sweep. A new contact-like pointer between two objects also needs swizzled serialization and a decision on whether it belongs in the sync checksum.

Saves store the `Old` history as raw `RadioMessageType` numbers. Renumbering the enum changes which messages a loaded save's history shows.
