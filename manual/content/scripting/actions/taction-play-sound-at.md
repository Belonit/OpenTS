---
type: action
id: TACTION_PLAY_SOUND_AT
title: Play Sound Effect At...
summary: Plays a sound effect at the waypoint the action names, and keeps an endless loop playing there.
caveats:
  - The sound is a [placed sound](/systems/sound-effects/#placed-sounds), so it fades and pans with the waypoint's position relative to the view.
  - A sound that is not an endless loop plays only if the waypoint is in range when the action runs. It is not started later, and it is not restarted after it ends or fades out.
related:
  - type: action
    id: TACTION_PLAY_SOUND
  - type: action
    id: TACTION_PLAY_SOUND_RANDOM
---

## An endless loop stays put

An endless loop stays at the waypoint after the action runs. A sound is an endless loop when its section has `LOOP` in [`Control`](/keys/control/) and sets [`Loop=0`](/keys/loop/). A loop with a `Loop=` count behaves like any other sound.

While the waypoint is out of range, the loop is silent. Each time the waypoint comes back into range, the loop starts again without its attack sample. The sound's [`Range`](/keys/range/#scope-sounds) in `SOUND.INI` sets how far it carries.

Nothing stops such a loop before the scenario ends. It is kept in a [save game](/formats/save-games/) and resumes after a load.

The action holds up to 200 sounds at once: every endless loop it has placed, and every other sound while it is still playing. While all 200 are held, the action plays nothing.
