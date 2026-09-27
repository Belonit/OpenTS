---
key: OptionsChanged
summary: Sound played when the classic main menu recognizes a typed code.
see_also: [PlayerJoined, PlayerLeft, SystemError]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
OptionsChanged=OPTCHG ; a sound ID registered in SOUND.INI
```

The sound plays each time the classic main menu recognizes a typed code. That menu appears only when the graphical main menu cannot be built, so a game whose graphical menu loads never plays this sound. [The main-menu code recognizer](/systems/developer-mode/#the-main-menu-code-recognizer) lists the codes.

Nothing else plays this sound, including the options screens its name suggests.
