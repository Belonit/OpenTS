---
key: WebRadius
summary: The radius in cells of the area a web covers.
see_also: [Webby, Particle, WebDuration]
when_omitted:
  kind: value
  value: "2"
---

The radius is in whole cells, not leptons. A web covers every cell whose offset from the impact cell falls inside a circle of this radius. At `2` that is a rounded block of 13 cells, and at `3` it is 29 cells.

```ini title="rules.ini"
[MyWebWH] ; example WarheadType
Webby=yes
Particle=MyWebSys ; example ParticleSystemType
WebRadius=3 ; 29 cells
```

[`Webby`](/keys/webby/) covers what the web does in each covered cell. Which objects in a cell it catches depends on the cell's height. A covered cell whose ground lies within three height levels of the impact point catches the objects on its ground, not those on a bridge above it. A cell three or more levels above or below catches only the objects on a bridge there, so infantry on the ground in that cell is not webbed.

At `0` only the impact cell is covered. A negative figure covers no cells: no particle is released, nobody is webbed, and the shot shows only its impact animation.

Every covered cell creates a separate particle system, so the number of systems one detonation creates grows with the square of this figure.

The setting is read only while the warhead is [`Webby=yes`](/keys/webby/).
