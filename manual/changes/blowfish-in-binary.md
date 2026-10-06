---
title: Compile Blowfish into the binary
category: internal
release: 0.1.0
targets: []
credit: [ZivDero, tomsons26]
---

OpenTS now includes the Blowfish cipher in the executable and no longer needs `blowfish.dll`. A missing or unregistered DLL no longer prevents startup. Encrypted data is unchanged.
