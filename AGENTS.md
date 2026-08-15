# AGENTS.md

Guidelines for AI agents working in this repo.

## Versioning

- **`version.h` is user-only.** Never touch it — the user bumps it when releasing so the code knows the new version.
- **`udev.md` is the user's way of telling you what's under development.** The user sets the version there (e.g. `V0.0.5 (udev)`).
- Always read `version.h` and `udev.md` before touching `CHANGELOG.md`.

## Changelog

- When `udev.md` says `(udev)`, the changelog section is `## V0.0.X Features (under development)` — append new features/commands there.
- When the user flips `udev.md` to `(stable)` and bumps `version.h`, rename that section to plain `## V0.0.X` (no tags, no dates). The user handles the merge, tag, and release.
- A new dev version in `udev.md` gets a fresh `## V0.0.Y Features (under development)` section.

## Project notes

- Simulated OS in C++, built with `g++ -std=c++17` (`./quick.sh` then `./main`)
- Shell command handlers live in `main.cpp` (chain of `else if` on the input string)
- Simulated hardware info lives as plain-text files under `filesystem/proc/` (`cpuinfo`, `gpuinfo`) — created on first boot by `kernel/extra/make_dirs.cpp`
- Versions are defined in `version.h` (`TALON_VERSION`, `KERNEL_VERSION`, `BOOTLOADER_VERSION`)