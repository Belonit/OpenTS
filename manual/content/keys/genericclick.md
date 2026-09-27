---
key: GenericClick
summary: Sound for a structure's repair or sale starting or stopping, and for pressing a dialog control.
see_also: [GenericBeep, ScoldSound, SellSound]
when_omitted:
  kind: value
  value: none
---

```ini title="rules.ini"
[AudioVisual]
GenericClick=BUTTON1 ; a sound ID registered in SOUND.INI
```

The sound plays for two unrelated kinds of event: a structure's repair or sale starting or stopping, and the player pressing a dialog control.

## In the game world

Clicking a structure with the repair cursor plays the sound at the structure's position. It plays both when repair starts on a damaged structure and when repair stops. Starting repair on an undamaged structure plays [`ScoldSound`](/keys/scoldsound/) instead; repair still turns on, but no wrench appears.

Repair that starts or stops without a repair click plays the sound at the structure's position in these cases:

- repair starts by itself, for a house whose [`IQ`](/keys/iq/) reaches [`RepairSell`](/keys/repairsell/);
- repair stops because the structure is sold;
- repair stops because an engineer restores the structure to full strength.

Repair that ends because the structure is fully repaired, or because the house runs out of money, is silent.

Clicking the sell cursor on a structure that has build-up artwork plays the sound without a map position. It plays even when the structure is already being sold and the click changes nothing.

Repair and sell sounds play only for a structure owned by a house the local player controls. The test looks at the owner, not at who acted: a trigger that sells one of the player's structures plays the sound, while repairs and sales on a computer house's structures are silent. The sidebar does not play this sound.

## In dialogs

The game's dialog controls play the sound without a map position when the player presses them with the left mouse button. This covers buttons, check boxes, radio buttons, sliders, drop-down lists and their items, and list items. A slider plays it when pressed, whether or not its value changes. A disabled control plays nothing.

From the keyboard, Enter on a focused button plays the sound, and so does Space on a focused button, check box or radio button.

The buttons on the mission briefing screen play it once each time one is pressed.
