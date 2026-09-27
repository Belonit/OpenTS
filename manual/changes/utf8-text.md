---
title: Read and show text as UTF-8
category: feature
release: 0.2.0
targets:
- type: format
  id: ini-syntax
  effect: changed
credit:
- ZivDero
---

Game text, INI files, typed input, player names and chat are now UTF-8. The shipped fonts draw the Western European letters and symbols they contain and show `?` for any other character, so `é` and `œ` display but Cyrillic and Greek do not.

The 12-point metal font, used for the sidebar and the credits roll, used to draw the wrong glyph for an accented letter. The title-screen copyright and the first line of the command-line usage text showed `Â©` in place of `©`.

An INI line that is not valid UTF-8 is read as Windows-1252, so existing maps and mods keep their accented names, and a file whose digest was computed over Windows-1252 text still verifies. The game saves INI files as UTF-8 without a byte order mark.

Player names now hold 64 bytes and chat lines 224, and an accented Latin letter takes two bytes.

OpenTS now supports only Windows 10 version 1903 or later, the first version that lets a program use UTF-8 as its code page.
