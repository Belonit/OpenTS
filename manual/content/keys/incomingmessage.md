---
key: IncomingMessage
summary: Sound played whenever a line is added to the on-screen message list.
see_also: [MessageDelay]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
IncomingMessage=Message1 ; the stock sound, an ID registered in SOUND.INI
```

The sound plays each time a line is added to the message list shown over the battlefield. Despite the name, that is not limited to chat. Lines the game adds itself also play it, such as the low power warning, ion storm notices, text from a trigger action and the notice that a player was defeated.

Each chat line plays the sound once, including the lines you send. A line too wide for the message area is split into several lines, and each piece plays the sound.
