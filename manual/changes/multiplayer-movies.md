---
title: Movies in multiplayer with a vote to skip
category: feature
release: 0.2.0
targets:
- type: system
  id: multiplayer-movies
  effect: added
- type: format
  id: spawn-ini
  effect: changed
- type: format
  id: vqa
  effect: changed
- type: key
  id: Win
  effect: changed
- type: key
  id: Lose
  effect: changed
- type: action
  id: TACTION_PLAY_MOVIE
  effect: changed
- type: action
  id: TACTION_PLAY_INGAME_MOVIE
  effect: changed
credit: [ZivDero, Rampastring]
---

A launch file with `PlayMoviesInMultiplayer=yes` under `[Settings]` now plays the scenario's movies in the skirmish or network game it starts: the opening movies, the movies that triggers and scripts play, radar movies, and the `Win` or `Lose` movie after the score screen. The key used to be read but had no effect.

In a network game, pressing Escape during a full-screen movie casts a vote to skip it, and the movie ends early only once every player has voted. The `Win` and `Lose` movies after the score screen are the exception: Escape ends them on that machine alone.

Rampastring is credited for the Vinifera feature this one follows.
