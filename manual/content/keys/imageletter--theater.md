---
key: ImageLetter
scope: theater
label: Theater image letter
see_also: [NewTheater, Theater]
when_omitted:
  kind: context-dependent
  note: "`T` for TEMPERATE and `A` for SNOW, which keep their original settings; none for any other theater, whose artwork is then never renamed."
---

`ImageLetter` is the letter that theater-named artwork carries as the second character of its file name. In a theater lettered `T`, `GACNST.SHP` loads as `GTCNST.SHP`; in a theater lettered `A`, it loads as `GACNST.SHP`. [`NewTheater`](/keys/newtheater/) says which artwork is renamed this way.

```ini title="rules.ini"
[DESERT]
ImageLetter=D   ; GACNST.SHP loads as GDCNST.SHP
```

Only the first character of the value is read, and it is converted to upper case. An empty value keeps the letter the theater already has, so TEMPERATE and SNOW always keep one.

The letters of all declared theaters also decide which names are renamed. A name is rewritten only when its second letter is already the image letter of some declared theater, ignoring case. Declaring a letter therefore also renames any theater-named artwork whose second letter matches it. Once a theater lettered `I` is declared, `CITY01` loads as `CTTY01` in a theater lettered `T`. Pick a letter that no unrelated artwork uses as its second character.
