---
title: Music
summary: Music tracks fade out or crossfade when another is queued, and pause with all other game sound while the game is in the background.
category: audio-speech
keys: [ScoreVolume, IsScoreRepeat, IsScoreShuffle]
---

The game plays one music track at a time; two overlap only while one fades out as the other starts. [THEME.INI](/formats/theme-ini/) declares the tracks, and each track streams from the file its [`Sound=`](/keys/sound/) names, or from the file named after its ID. The file can be a `.WAV`, `.OGG`, `.FLAC`, `.MP3` or `.AUD` file; [AUD audio](/formats/aud/) explains where the game looks for it. A track's [`Volume=`](/keys/volume/#scope-themes) sets its loudness relative to the other tracks.

The player's music settings are stored in `sun.ini` under `[Audio]`, and the sound options screen changes them. [`ScoreVolume`](/keys/scorevolume/) sets the music volume. [`IsScoreShuffle`](/keys/isscoreshuffle/) picks the next track at random, and [`IsScoreRepeat`](/keys/isscorerepeat/) plays every track again when it ends. The values below are examples; the key pages give the defaults.

```ini title="sun.ini"
[Audio]
ScoreVolume=1.0
IsScoreShuffle=yes
IsScoreRepeat=no
```

## Changing tracks

A queued track fades out the current track over [`FadeOut=`](/keys/fadeout/) seconds, a second and a half by default, then starts once the fade has finished. With [`CrossFade=`](/keys/crossfade/) set, the queued track starts at once and fades in while the current track fades out. The [Play music theme](/mapping/actions/taction-play-music/) trigger action and the [Play music](/mapping/missions/tmission-play-music/) team mission queue their track.

Only one track can wait at a time, so a request to queue a track is ignored while another track is waiting.

The main menu, map selection and the score screen start their tracks immediately instead. The current track stops at once, with no fade. An ion storm without a storm sound pauses the current track and resumes it when the storm ends; [Ion storms](/systems/ion-storms/#storm-audio) describes both kinds of storm audio. Replaying the briefing video during a mission pauses the current track, and it resumes from the same point when the video ends.

On the sound options screen, playing a track from the list stops the current track at once and starts the chosen one. The [next track](/commands/nexttheme/) and [previous track](/commands/prevtheme/) commands do the same with the allowed track after or before the current one.

The Stop button on the sound options screen fades the current track out. No music plays again until a track starts immediately, the player plays a track from the list or uses the next or previous track command, or a new scenario starts. Play music theme actions and Play music team missions are ignored in the meantime.

An ion storm that plays the storm track still plays it after Stop, and a Play music theme action or Play music team mission during that storm is carried out. Without such a request, the music is silent again once the storm ends.

Starting a scenario stops the current track. The game then plays the scenario's [`Theme=`](/keys/theme/) track if it names one, and otherwise the next allowed track. There are two exceptions:

1. In a campaign mission with no briefing movie and no action movie, the `Theme=` track starts at once behind the mission briefing screen. When the mission begins, that track fades out and the next allowed track follows, unless the `Theme=` track repeats.
2. In a scenario with an action movie, the game requests the `Theme=` track only when that movie plays. If the movie does not play, for example when the player restarts a mission after a defeat, the game starts with the next allowed track.

A request for a track whose file cannot be played produces no music. A queued request still fades out the current track, and an immediate one still stops it. During a game, the next allowed track is chosen about a second later, as if the failed track had just ended. The failed track is chosen again only when no other track is allowed, even when it repeats.

## Choosing the next track

When a track ends, the game chooses the next one from the allowed tracks. With shuffle on, it picks at random and avoids the track that just ended unless no other track is allowed. With shuffle off, it takes the next allowed track in THEME.INI order and wraps around at the end of the list. When no track is allowed, no music plays.

A track is allowed when all of these hold:

1. The game found a file for it that it can play.
2. It has [`Normal=yes`](/keys/normal/).
3. Its [`Side=`](/keys/side/#scope-themes) is unset or lists the side of the player's country.
4. Its [`RequiredAddon=`](/keys/requiredaddon-campaign/#scope-themes) is unset or `0`, names the expansion that is running, or is `-1` while any expansion is running.
5. In a campaign mission, the current mission number has reached its [`Scenario=`](/keys/scenario/#scope-themes).

A track with [`Repeat=yes`](/keys/repeat/) starts again from its beginning each time it reaches its end, with no gap, whatever the shuffle setting. The repeat option does the same for every track. Changing the option applies to the track already playing, except in about the last five seconds before its end: switched on then, the track ends and starts again after a short gap; switched off then, it plays once more.

A repeating track gives way to any queued track, including one queued by a Play music theme action or a Play music team mission, however the repeating track was started. A request for the next allowed track leaves a repeating track playing, as it would pick that track again.

A track that was started immediately, and that does not repeat, ends without a queued successor. During a game, the next allowed track then follows, chosen as if the ended track had been picked from the playlist. Outside a game, for example on the score screen or in the menus, the music stops unless another track has been queued.

## Focus and volume

While the player has switched to another application, all game sound pauses where it is, music included. It resumes from the same point when the player switches back.

A change to the music volume applies at once to the track already playing.

At zero, no track starts, and a request to queue a track is discarded. A track that was already playing continues without sound. When the volume is raised again, that track becomes audible from the point it has reached. If it has ended in the meantime, the next track is chosen as described above. A track started immediately while the volume is zero stops the silent track and waits. It plays from the beginning when the volume is raised.
