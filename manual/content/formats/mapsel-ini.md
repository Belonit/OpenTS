---
format_id: mapsel-ini
title: MAPSEL.INI
summary: Lists each campaign house's stages in order, and the mission, map-screen presentation and choices each stage sets.
kind: file
filenames:
  - MAPSEL.INI
  - MAPSEL01.INI
source_files:
  - code/mschoice.cpp
  - code/mapsel.cpp
related:
  - type: system
    id: campaign-progression
  - type: format
    id: vqa
  - type: format
    id: aud
---

When a campaign mission is won and the campaign continues, the next mission comes from this file. That holds whether the player picks a region on the map selection screen or the mission names its successor. [Campaign progression and carry-over](/systems/campaign-progression/) covers that sequence and the state carried across it.

## Which file is read

The base game reads `MAPSEL.INI`. After a mission whose [`RequiredAddOn`](/keys/requiredaddon-scenarios/) names an expansion, the game reads `MAPSEL<nn>.INI` instead, where `<nn>` is the expansion's two-digit number. After a Firestorm mission it reads `MAPSEL01.INI`.

The game reads the house section named after the player's house, the house the mission's [`Player=`](/keys/player/#scope-scenarios) sets. A campaign played as GDI never reads the Nod section. A missing file, or a house section with no numbered entries, fails the read; [the win sequence](/systems/campaign-progression/#the-win-sequence) covers what happens then.

The file is read again at every advance, so an edit takes effect at the next advance.

## House sections

A house section lists the stages of that house's campaign in order. Each numbered key from `1` upward names a stage section. The list ends at the first missing number, so number the entries from `1` without gaps. At most 100 stages are read.

A stage's position in the list is its stage number, which the campaign keeps to find the current stage at the next advance. Inserting, removing or reordering entries changes the stage numbers, so a campaign saved before the edit continues from whichever stage now holds its number.

Two further keys name the sections that hold the map selection screen's decoration:

- `Anims=` names the section of animations and the screen's palette. The screen does not open without it.
- `Sounds=` names the section of sound effects.

## Stage sections

Each stage has a section whose name is the label the house list uses. Three of its keys describe the stage as a destination: the mission it plays, and the description and voice-over the map selection screen gives a region that leads to it.

| Key | Value |
| --- | --- |
| `Scenario=` | The mission file the stage plays. [`NextScenario=`](/keys/nextscenario/) must match this value to reach the stage. |
| `Description=` | Text printed in the area `TextRect=` sets when the cursor enters a region that leads to the stage. A number selects an entry of the game's string table. A value starting with a letter names a section of this file; every entry of that section, in order, is joined with single spaces into one description of up to 1,023 characters. |
| `VoiceOver=` | An [AUD](/formats/aud/) file streamed about half a second after the cursor enters a region that leads to the stage. It does not start if the cursor leaves the region first, and fades out when the cursor leaves. |

The other keys build the map selection screen that appears after the stage's own mission is won.

| Key | Value |
| --- | --- |
| `MapVQ=` | The [VQA](/formats/vqa/) movie the screen opens with. A stage without it skips the screen, provided the palette and click map load; if either fails to load, an error box appears. [When the choice fails](/systems/campaign-progression/#when-the-choice-fails) says what loads next in both cases. |
| `Overlays=` | Up to two comma-separated shape file names, faded in one after the other over the movie's last frame. A third name is ignored. |
| `ClickMap=` | A 256-color PCX file whose pixel colors mark out the selectable regions. Its top-left pixel is the top-left corner of the 640 by 400 presentation area. The screen does not open without it. |
| `Targets=` | `<count>,<x>,<y>,<x>,<y>...`: the number of target markers, then the center of each in the 640 by 400 presentation area. The first marker belongs to the choice with the lowest key number, the second to the next, and so on. Give no more markers than the stage has choices. |
| `Text1=` to `Text7=` | Captions shown over the movie, each `<x>,<y>,<delay>,<text>`. The delay counts 16-millisecond ticks from the start of the movie, about 60 to the second. The text ends at its first comma. |

The game moves each caption from `<x>,<y>` to the right by half the difference between the width of `TextRect=` and the caption's width, and down by less than half a line. A caption whose `<x>` is the left edge of `TextRect=` is therefore centered on that area's width. Keep captions inside `TextRect=`; the part outside it may not be drawn.

Once its delay has run, a caption appears with its first `<delay>` + 1 characters already drawn, and the rest are typed out one at a time. A caption of `<delay>` + 1 characters or fewer appears whole.

The numbered keys of a stage section are its choices. Each key is a click-map pixel color from `0` to `255`, and its value is the label of the stage that color selects. When the player clicks, the game reads the color under the cursor from the click map and looks it up among these keys. A color with no entry selects nothing. Labels are matched without regard to case. The key numbers are colors, so they need not start at `1` or run without gaps.

List every stage a choice names in the house section. A region whose stage is not listed shows no description while the cursor is over it, and clicking it crashes the game.

This excerpt shows a house list and two stage sections, and the two shapes a choice list takes:

```ini title="MAPSEL.INI"
[GDI]
Anims=Anims
Sounds=GDISFX
1=GDI01   ;1A
2=GDI02   ;2A
3=GDI03   ;3A1
4=GDI04   ;3A2

[GDI01]
Scenario=GDI1A.MAP
Description=768
VoiceOver=GDI-01.AUD
MapVQ=GDIMAP01.VQA
Overlays=RG02A.SHP,RN02A.SHP
Targets=1,180,80
ClickMap=GDICLK01.PCX
2=GDI02 ;2A

[GDI02]
Scenario=GDI2A.MAP
Description=769
VoiceOver=GDI-02.AUD
MapVQ=GDIMAP01.VQA
Overlays=RG03AB.SHP,RN03AB.SHP
Targets=2,290,88,218,108
ClickMap=GDICLK01.PCX
3=GDI04 ;3A2
4=GDI05 ;3B
```

`[GDI]` lists stages 1 to 4 in the order written. Winning `GDI1A.MAP`, the mission of stage `[GDI01]`, shows one choice: color 2 leads to `[GDI02]`. Winning `GDI2A.MAP` shows two. Color 3 leads to `[GDI04]`, with its marker at 290,88, and color 4 leads to `[GDI05]`, with its marker at 218,108. For the second choice to work, `[GDI]` must also list `GDI05`, which this excerpt leaves out. The excerpt also leaves out the animation and sound sections the house section names; both are described below.

## How a stage is chosen

Both ways of advancing end at a stage of this file, never directly at a mission file.

With the map screen, the movie of the stage just won plays, its overlays and target markers appear, and the player clicks one of the regions its click map colors. The music track `MAPS` plays meanwhile, or `FSMAP` when the game requires Firestorm. The clicked region's entry names the next stage, and that stage's `Scenario=` value is the mission that loads.

Without the screen, when the mission sets [`SkipMapSelect=yes`](/keys/skipmapselect/), the name given by [`NextScenario=`](/keys/nextscenario/) or [`AltNextScenario=`](/keys/altnextscenario/) is compared, ignoring case, with the `Scenario=` value of each stage the current stage offers. The stages are tried in order of their key numbers, and the first match is taken. Only stages that the current stage offers can be reached this way.

## Animation and sound sections

The section named by `Anims=` sets the screen's text area, its palette and its looping animations:

- `TextRect=` is `<x>,<y>,<width>,<height>`, the area stage descriptions are printed in, relative to the 640 by 400 presentation area. If it is left out, descriptions use the whole area.
- `Palette=` names the palette the animations and target markers are drawn with. The screen does not open without it.
- The numbered keys from `1` upward each hold `<file>,<x>,<y>,<delay>`: a shape file, its position in the presentation area, and the delay between its frames in 16-millisecond ticks. The list ends at the first missing number, and at most 100 are read.

The section named by `Sounds=` assigns a sample to each sound event of the screen. Each key is an event name, and each value is `<file>,<volume>`. The volume is a percentage, limited to the range `0` to `100`. Without a volume the sample plays at full volume, and a volume of `0` leaves the event silent. The events are:

| Event | Plays when |
| --- | --- |
| `Overlay` | Each overlay appears. |
| `TargetFlyIn` | Each target marker appears. |
| `EnterRegion` | The cursor enters a region that has a choice. |
| `ExitRegion` | The cursor leaves a region that has a choice. |
| `MouseOnMap` | The cursor moves from color `0` of the click map onto any other color. |
| `MouseOffMap` | The cursor moves back onto color `0`. |
| `Click` | The player clicks a region that has a choice. |

An event the section does not set is silent.
