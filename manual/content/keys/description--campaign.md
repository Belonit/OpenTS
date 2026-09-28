---
key: Description
scope: campaign
label: Campaign list entry
see_also: ["Scenario", "RequiredAddon", "FinalMovie"]
when_omitted:
  kind: computed
  note: The campaign's section name, as its `[Battles]` entry writes it, stands in as the row text.
---

The text is the campaign's row in the mission selection list, and the only part of a campaign the player sees before choosing it. At most 127 characters are kept; a longer value is cut. A campaign that the running expansion does not allow is left out of the list, so its text is never shown ([`RequiredAddon`](/keys/requiredaddon-campaign/#scope-campaign)).

Each value in a `[Battles]` section names one campaign, and that name is also the section the campaign's settings are read from, this key included. The number to the left of the `=` is ignored.

```ini title="BATTLE.INI"
[Battles]
1=GDI1

[GDI1]
Description=REUNION
Scenario=Maps/Missions/GDI1A.MAP
CD=0
```

The list is built from several battle files, read in this order:

1. every `BATTLE*.INI` file that [the file search](/formats/opents-ini/#the-order-files-are-searched-for-in) finds, in alphabetical order;
2. the base battle file, `BATTLE.INI` unless the deployment [names another](/formats/opents-ini/#the-files-it-reads), when step 1 did not find it;
3. the expansion's battle file, `BATTLEFS.INI` unless the deployment names another, when it exists. It is read here even if step 1 already read it.

A campaign named in more than one file gets one row, placed where it was first named. Each later file that names it updates its settings, so the last file to set `Description` for a campaign decides its text. The expansion's battle file is read last. Where it names a campaign in its `[Battles]` section and sets a value for it, that value wins over every other file's.

Keep campaign names to 24 characters. A longer name is cut to its first 24, and the campaign's settings are read from the section with that shortened name. A longer name also gets a new row each time a `[Battles]` section names it.
