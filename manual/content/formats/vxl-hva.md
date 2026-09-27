---
format_id: vxl-hva
title: VXL and HVA models
summary: Draws an object from a voxel model whose layers are placed by a companion motion file.
kind: binary
extensions:
  - .VXL
  - .HVA
role: model
related:
  - { type: format, id: mix }
  - { type: format, id: save-games }
source_files:
  - code/objtype.cpp
  - code/builtype.cpp
  - code/techtype.cpp
  - code/unit.cpp
  - code/vanimtype.cpp
  - code/voxel.hh
  - code/voxlib.cpp
  - code/motlib.cpp
---

A voxel model is a `.VXL` and a `.HVA` under the same base name, loaded as a pair. The `.VXL` holds the model itself, divided into layers. The `.HVA` holds one transform per layer per frame, and those transforms place each layer. One pair is one piece of an object, so a turreted voxel vehicle draws from three pairs: body, turret and barrel.

Both files are looked up like any other game file, so either can sit in a [MIX archive](/formats/mix/) or loose in the game directory.

## Which pairs a type loads

A vehicle, aircraft, infantry, structure or projectile type marked [`Voxel=yes`](/keys/voxel/) loads its pairs when the rules are read. Each base name is built from the type's [Image ID](/keys/image/). The kind of type and its [`Turret`](/keys/turret/) setting decide which pieces are looked for; the files present do not. Every type that is not a vehicle therefore looks for a turret and a barrel, whether or not it could draw them.

| Base name | Looked for when |
| --- | --- |
| `<Image ID>` | Always; this is the body |
| `<Image ID>TUR` | The type is not a vehicle, or is a vehicle with `Turret=yes` |
| `<Image ID>BARL` | The same condition as the turret |
| `<Image ID>W` | The type is a vehicle without a turret whose rules section is named exactly `APC` |

A piece is loaded only when its `.VXL` exists. Once the `.VXL` exists, the `.HVA` is required: a piece whose `.HVA` is missing counts as a failed piece, as [When a set fails](#when-a-set-fails) describes.

Other objects load voxel models by different rules:

- A vehicle drawn from shapes that has `Turret=yes` and whose shape file was found loads the `<Image ID>TUR` and `<Image ID>BARL` pairs. It draws only the barrel from them; its turret comes from its shapes. A piece that fails here affects nothing else.
- A structure with [`TurretAnimIsVoxel=yes`](/keys/turretanimisvoxel/) or [`BarrelAnimIsVoxel=yes`](/keys/barrelanimisvoxel/) loads its voxel turret and barrel from a name derived from its turret animation, or from [`VoxelBarrelFile`](/keys/voxelbarrelfile/). `TurretAnimIsVoxel` and `VoxelBarrelFile` cover how the name is formed.
- A voxel animation type loads `<Image ID>.VXL` alone, with no motion file. When it borrows a model through [`ShareSource`](/keys/sharesource/), it uses the body, turret or barrel pair of another type instead.
- `DPOD.VXL` and `DPOD.HVA` are loaded once at startup under those fixed names. Nothing in the game draws them.

:::danger[Ship a .VXL for every voxel animation type]
If a voxel animation type that does not borrow a model through `ShareSource` has a missing or unreadable `.VXL`, the game crashes the first time the animation is drawn.
:::

:::danger[Ship a complete .HVA with every voxel turret and barrel]
Each piece below is loaded even when its `.VXL` has no `.HVA` beside it. The game then crashes the first time that piece is drawn.

- The `<Image ID>BARL` barrel of a vehicle drawn from shapes.
- The voxel turret and barrel of a structure.

A structure's voxel turret or barrel `.HVA` that is present but ends early crashes the game the same way.

On a vehicle drawn from shapes, a `<Image ID>TUR.HVA` or `<Image ID>BARL.HVA` that ends early crashes the game while the rules are read. This happens only when the matching `.VXL` loads.

A vehicle drawn from shapes does not draw its `<Image ID>TUR` model, so a missing `<Image ID>TUR.HVA` has no effect there.
:::

Voxel artwork is not stored in a save game. [Save games](/formats/save-games/) covers what a restored type loads in its place, and `ShareSource` covers what happens to a borrowed model.

## When a set fails

A `Voxel=yes` type's set fails when any of these holds:

- `<Image ID>.VXL` is missing.
- A piece's `.VXL` is present but its `.HVA` is missing.
- A `.VXL` or `.HVA` that is present cannot be read in full.

When the set fails, the type keeps no body model and no turret or `W` model, whatever else loaded. A barrel model that loaded is kept. [`Voxel`](/keys/voxel/) covers how each kind of object is drawn without its body model.

:::danger[Keep every .VXL readable]
A `.VXL` that is present but cannot be read in full, beside a `.HVA` that loads, crashes the game while the pair is loaded. This applies to the pieces of a `Voxel=yes` type and to a structure's voxel turret and barrel.
:::

## What the model file holds

The loader reads a `.VXL` in this order:

- a header, holding an internal name, the number of palettes, the number of layers, the number of layer info records and the size of the voxel body;
- one palette per the header's count, each a pair of remap bounds followed by a red, a green and a blue byte for each of 256 colors;
- one header per layer, holding a name and the index of the first info record belonging to that layer;
- the voxel body, run length encoded down each column, with a color index and a normal index for every voxel in a run;
- one record per layer info, holding the offsets within the body of its two span tables and of its voxel data, the scale the layer was built at, a placement transform, two opposite corners of its bounding box, its X, Y and Z sizes in voxels, and which normal table its voxels index.

A layer names its first info record, and the format lets it own several that follow, so the layer count and the info count need not agree. The game uses only each layer's first info record.

Several parts of the file do not affect how the model is drawn:

- The palettes are skipped. Every model is drawn with the colors from `VOXELS.VPL`, which the game reads at startup. The palette count must still be correct, because it sets how far the loader skips to reach the layer headers.
- The internal names in the header and in each layer header are not read. Files are found by filename, and each model layer is matched to the motion layer in the same position.
- The placement transform is not used. A layer's position comes entirely from the motion file.

The normal table selector of a layer takes these values:

| Selector | Effect |
| --- | --- |
| `0` | The layer has no usable normals and is drawn without lighting. |
| `1` to `4` | The layer is lit. On the first layer, the value also selects which of the engine's four normal tables shades the whole model. |

Give every lit layer the same selector as the first layer, because all of them are shaded from the first layer's table. If the first layer's selector is `0`, the model's other lit layers are shaded with the lighting left from the voxel model drawn before it.

Keep the first layer's selector at 4 or below. The game does not check it, and a larger value reads past the end of the engine's normal tables whenever the model is drawn.

## What the motion file holds

The loader reads a `.HVA` as a header holding an internal name, the number of frames and the number of layers. A table of layer names follows, sixteen bytes each and one per layer, and it is skipped. Then, frame by frame, one transform of twelve floating point values is read for each layer.

Give the `.HVA` the same number of layers as its `.VXL`, in the same order. Layers are matched by position, and the game does not compare the two counts. A model layer beyond the motion file's count is placed with a transform meant for another layer, or with data from past the end of the file's transforms.

When a pair is loaded, the translation of every transform is multiplied by the scale recorded in the model's first layer. That brings the animation into the model's scale. Give every model at least one layer. For a model with none, the game reads the scale from memory outside the model, which can crash the game while the pair loads or scale the animation unpredictably.

Frames are taken modulo the frame count, so an animation that runs past its last frame starts again at the first. A file that declares no frames still loads, and the game crashes the first time the model is drawn.

:::danger[Do not ship an empty model or motion file]
An empty `.VXL` or `.HVA` is loaded with unpredictable layer, layer info and frame counts. If a count is too large to allocate, the game crashes while it loads the file. Otherwise the load usually fails at the first read past the end of the file. An empty file can also load as a model with no layers or a motion file with no frames, with the crashes described above.
:::
