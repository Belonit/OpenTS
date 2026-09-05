#!/usr/bin/env bash

set -euo pipefail

# FFmpeg probes the MSVC librarian without arguments and identifies it by this banner.
if [[ $# -eq 0 ]]; then
	echo "Microsoft (R) Library Manager"
	exit 0
fi

exec llvm-lib "$@"
