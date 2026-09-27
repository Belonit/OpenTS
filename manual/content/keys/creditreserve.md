---
key: CreditReserve
summary: The balance a computer house must hold before it will start repairing one of its buildings.
see_also: ["system:repair"]
when_omitted:
  kind: value
  value: "1000"
---

A computer house starts repairing a damaged building only while its available money is at or above this value. The reserve affects only the decision to start. Once the repair runs, each step is paid from the house's money even if that takes the balance below the reserve.

While the balance is below the reserve, the computer considers [selling the damaged building](/systems/repair/#when-the-computer-repairs) instead. Raising the value therefore makes a computer house start fewer repairs and consider more sales. That section lists the other tests each decision needs.

The reserve also applies to a player's house when a map gives that house an `IQ` high enough for automatic repair, as the same section explains.
