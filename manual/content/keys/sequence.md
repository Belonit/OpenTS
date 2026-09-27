---
key: Sequence
summary: The art.ini section that lays out the frames of every action an infantry type performs.
see_also: ["FireUp", "FireProne", "Crawls", "JumpJet", "Crew"]
when_omitted:
  kind: value
  value: none
---

The value names another section of the same file. That section has one entry per action the soldier can perform, and each entry has up to four fields:

1. the first frame of the run;
2. the number of frames in the run;
3. the number of frames from one facing to the next;
4. optionally, a compass point the soldier turns to when the run ends: `N`, `NE`, `E`, `SE`, `S`, `SW`, `W` or `NW`, in capitals. `Struggle` and the death runs ignore it.

```ini title="art.ini"
[E1] ; the Image ID of the stock Light Infantry
Sequence=E1Sequence

[E1Sequence]
Ready=0,1,1      ; one frame per facing, frames 0-7
Walk=8,6,6       ; six frames per facing, frames 8-55
Idle1=56,15,0,W  ; one run of 15 shared by every facing, ending facing west
Prone=86,1,6     ; the first frame of each crawl run
Crawl=86,6,6
```

The frame drawn is the run's first frame, plus the animation stage wrapped to the frame count, plus the per-facing jump times the soldier's facing. The facing counts as one of eight directions, numbered from `0`. A jump of `0` makes the run the same for every facing, as the `Idle1` entry above is. A [`JumpJet=yes`](/keys/jumpjet/) soldier with a target uses the direction to that target in place of its own heading while its jumpjet locomotor is in control.

An action whose entry is missing from the section gets a frame count of `0`, and an action with a frame count of `0` never starts. A soldier whose section omits `Idle1` never plays it.

## Entry names

The table lists every entry a sequence section may have and the action each one drives.

| Entry | Action |
| --- | --- |
| `Ready` | Standing at rest |
| `Guard` | Standing on guard; never played |
| `Prone` | Lying prone at rest |
| `Walk` | Walking upright |
| `FireUp` | Firing upright |
| `Down` | Lying down |
| `Crawl` | Moving while prone |
| `Up` | Getting up |
| `FireProne` | Firing while prone |
| `Idle1`, `Idle2` | The two idle animations |
| `Die1` | The gun death, for [`InfDeath=1`](/keys/infdeath/) |
| `Die2` | The explosion death, for `InfDeath=2` |
| `Die3`, `Die4` | Two further death animations; never played |
| `Die5` | The burning death of a [`Doggie=yes`](/keys/doggie/) type, for `InfDeath=4` or `5` |
| `Hover` | Hovering on jump jets |
| `Fly` | Flying on jump jets |
| `Tumble` | Tumbling on jump jets; never played |
| `FireFly` | Firing while flying |
| `Struggle` | Struggling inside a web |

:::danger[An infantry type with no sequence crashes the game]
A type with no `Sequence` has no animation table. The game crashes the first time an instance of the type animates, and whenever the game is saved, even if no instance exists. A type registered only by being named elsewhere, as [`Crew`](/keys/crew/) describes, has no section of its own and crashes the same way.

Naming a section the file does not contain is a different failure. Every action then has a frame count of `0`, so the soldier starts no action and stands on the first frame of its artwork.
:::
