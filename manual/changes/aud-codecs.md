---
title: Decode delta-compressed AUD files and refuse unknown codecs
category: fix
release: 0.2.0
targets:
- type: format
  id: aud
  effect: changed
credit: [ZivDero]
---

An `.AUD` file compressed with the Westwood delta codec used to play as noise, and so did a file whose compression code the game does not recognize. A delta-compressed file now plays correctly, and a file with an unrecognized code does not play.
