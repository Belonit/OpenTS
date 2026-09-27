---
key: Tag
summary: The TagType attached to every member of a team of this type.
see_also: [OnTransOnly, Script, TaskForce]
when_omitted:
  kind: value
  value: none
---

Each team of this type creates one tag from the named TagType when the team is created. That tag is attached to each member as it joins, replacing any tag the member already had. All members share the one tag, so a trigger behind it that can fire only once fires once for the whole team, not once per member. [`OnTransOnly=yes`](/keys/ontransonly/) limits the tag to members that can carry passengers.

A member that leaves the team loses the tag if a computer house owns it. A member owned by a human player keeps it, so a tag on a player's reinforcement team stays with its members after they leave the team.

The value is matched against the IDs registered under `[Tags]`. `<none>` and `none` clear the reference. A name that is not registered there is not an error: the game creates a new TagType under that name with no triggers, so a misspelled name gives the team a tag that never fires.
