---
key: SoundLatency
summary: A former movie sound offset that the engine still reads and saves but no longer uses.
no_effect: true
see_also: [SoundVolume, StretchMovies]
when_omitted:
  kind: value
  value: "9"
---

The offset once corrected for the delay of emulated DirectSound drivers when a movie's picture was kept in step with its sound. Movies now time their picture from the audio output itself, including the output device's delay, so the offset has nothing left to correct.

No options screen offers the setting. Saving the options writes it back to `sun.ini` with the rest. A value from 0 to 65535 is written back unchanged, and any other value is wrapped into that range.
