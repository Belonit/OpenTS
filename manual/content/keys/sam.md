---
key: SAM
summary: Gives a defense an anti-aircraft attack routine that keeps only airborne targets.
see_also: [AA, Powered, "system:power", "system:target-selection"]
when_omitted:
  kind: value
  value: "no"
---

`SAM=yes` replaces a defense's ordinary attack behavior with an anti-aircraft routine that engages only aircraft in flight.

The structure never keeps a target that is not in the air. It drops such a target on its next update, whether [target selection](/systems/target-selection/), retaliation or a player's attack order supplied it. Range and whether the weapon could hit are not considered at this step.

On the attack mission the structure alternates between two states, and checks its state on every frame:

1. **Tracking.** While its type is `Powered=yes` with drain and its house is short of power, the structure waits in this state; [Defenses](/systems/power/#defenses) covers that test. If the target is not an aircraft above the ground, the structure drops it and returns to guard. Otherwise it turns toward the target, and switches to firing once it faces within 45 degrees of it.
2. **Firing.** The structure checks the target again the same way, then asks whether its first weapon slot can fire:
   - If the structure is switched off or stunned by an [EM pulse](/systems/emp-pulse/), or the target is illegal, cannot be hit by that weapon, or is out of range, the structure drops the target and returns to tracking.
   - If the structure has a turret that does not face the target closely enough, it returns to tracking and keeps the target. A turret must face within 11.25 degrees of the target, or exactly at it for a voxel turret. A structure without a turret is not tested for facing here.
   - If the weapon is refused for any other reason, such as reloading, the structure stays in this state and tries again on the next frame.
   - If the shot is clear, the structure fires its first and then its second weapon slot, and returns to tracking.

Tracking turns the turret only when it faces more than 45 degrees away from the target, and firing needs a much closer facing. A turreted structure whose target lies between the two limits therefore neither turns toward the target nor fires at it. This lasts until the target moves within the firing limit, which lets the structure fire, or more than 45 degrees away, which makes tracking turn the turret onto it again.

The routine never chooses between the weapon slots. The second weapon slot fires whenever the first slot's shot is clear, without its own range, reload or anti-aircraft check. When the second slot has a weapon, its reload time sets the wait before the next volley.

:::caution[The flag does not make the weapon anti-air]
A shot at an airborne target needs [`AA=yes`](/keys/aa/) on the weapon's projectile. Without it, the structure drops every ground target, and its first weapon slot refuses every aircraft, so it never fires.
:::
