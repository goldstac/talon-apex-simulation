# talon-apex-simulation

A simulated operating system written in C++17. **Talon Apex** ("Talon OS") boots through a fake bootloader, loads a fake kernel, then drops you into a toy shell with a virtual filesystem — no virtualization, all just a regular executable that fakes the whole experience in your terminal.

## Overview

When you run the binary, the following boot sequence plays out:

1. **Flash Bootloader** — prompts you to pick a boot option
2. **Kernel init** — `Talon Apex Kernel` prints fake boot messages and cleans a fake `/dev` device
3. **Directory check** — creates/verifies the simulated `filesystem/` tree on first boot
4. **Shell** — drops you into `admin@talon [~/Desktop]`

## Features

- Interactive boot loader with boot-option menu
- Fake kernel init sequence
- `penguinfetch` — colorful penguin-style system logo
- Simulated hardware info via virtual `proc` files
- Built-in shell commands
- `vim` / `nvim` integration for editing files in the simulated home directory
- Self-updater that checks GitHub releases and downloads the newest binary
- Cross-platform builds for Linux, Windows, and macOS

## Commands

| Command | Description |
| --- | --- |
| `cat proc/cpuinfo` | Show simulated CPU info (Intel Core Ultra 9 285K) |
| `cat proc/gpuinfo` | Show simulated GPU info (Nvidia RTX 5090) |
| `cat proc/meminfo` | Show simulated memory info (64 GB DDR5) |
| `cd <dir>` | Change directory (supports `~`, `..`, `/boot` style paths — explore anywhere inside `filesystem/`, can't leave it) |
| `ls` | List files/dirs in the current directory (`ls <dir>` to list another) |
| `t!qi` | Show quick system/version info |
| `kernel -v` | Show kernel version |
| `bootloader --version` | Show bootloader version |
| `penguinfetch` | Print the Talon Apex logo |
| `update` | Check for and apply updates via GitHub releases |
| `vim <file>` | Open `file` in `vim` from the simulated Desktop |
| `nvim <file>` | Open `file` in `neovim` from the simulated Desktop |
| `nano <file>` | Open `file` in `nano` from the current directory |
| `pwd` | Print the current directory |
| `echo <text>` | Print text |
| `which <name>` | Search `filesystem/bin/` for a binary |
| `echo $SHELL` | Print the shell name (`Penguin`) |
| `touch <file>` | Create an empty file in the simulated Desktop |
| `t!fs` | Print the virtual filesystem tree |
| `!ping` | Print `Pong!` |
| `date` | Print the current date |
| `whoami` | Print the current user (`admin`) |
| `clear` | Clear the screen |
| `--version` | Print the OS version |
| `exit` | Quit the shell |

### In development

| Command | Status |
| --- | --- |
| `systeminfo` | Coming soon |

## System Information

| Component | Version |
| --- | --- |
| Talon Apex OS | `V0.0.4` *(latest release)* |
| Talon Apex Kernel | `V1.0.0` |
| Flash Bootloader | `V0.0.2` |

## Build & Run

Requires `g++` (C++17).

> **Tip:** the easiest way to get Talon Apex is to download the prebuilt binary for your platform from the [latest release](https://github.com/goldstac/talon-apex-simulation/releases) — no compiler needed. Building from source works too if you prefer.

```sh
./quick.sh
./main
```

Or build manually:

```sh
g++ -o main main.cpp bootloader.cpp kernel/extra/make_dirs.cpp kernel/extra/initramfs.cpp logo.cpp update.cpp kernel/kernel.c
./main
```

## Cross-platform releases

GitHub Actions (`.github/workflows/release.yml`) builds and attaches binaries for every tagged `v*` release:

- `talon-os-linux`
- `talon-os-windows.exe`
- `talon-os-macos`

## Project structure

```
.
├── main.cpp            # Shell entry point and command loop
├── bootloader.cpp      # Flash Bootloader boot menu
├── bootloader.h
├── update.cpp          # Self-updater using GitHub releases
├── update.h
├── logo.cpp            # penguinfetch logo
├── logo.h
├── version.h           # Source of truth for OS/kernel/bootloader versions
├── create_bin.cpp      # Helper placeholder for bin creation
├── quick.sh            # Build script
├── tag.sh              # Tag and push a release
├── kernel/
│   ├── kernel.c        # Fake kernel init sequence
│   ├── kernel.h
│   └── extra/          # make_dirs, initramfs, compat helpers
├── extra/
│   └── push.cpp        # Source of the `push` helper binary
├── filesystem/         # Simulated filesystem (bin, boot, home, proc, rootfs, tmpfs)
├── tmpfs/              # Root-level tmpfs mirror
├── .opencode/          # opencode agent configs
└── .github/workflows/  # Build & release automation
```

## License

Licensed under the [GNU General Public License v3.0](LICENSE).