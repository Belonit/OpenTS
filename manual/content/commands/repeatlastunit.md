---
command_id: RepeatLastUnit
---

Queues another vehicle of the type the player built most recently, as a click on its cameo would. A vehicle counts once it has left the factory. Nothing happens until the player has built a vehicle in the current game, or while the [sidebar](/systems/sidebar/) no longer offers that type.

The new vehicle queues behind whatever the war factory is already building. If a vehicle of that type is on hold, the press resumes it and queues no second one. If the queue already holds [`MaximumQueuedObjects`](/keys/maximumqueuedobjects/) entries or the type has reached its [`BuildLimit`](/keys/buildlimit/), the order is dropped.
