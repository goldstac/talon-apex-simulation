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
| `talon -qi` | Show quick system/version info |
| `kernel -v` | Show kernel version |
| `bootloader --version` | Show bootloader version |
| `penguinfetch` | Print the Talon Apex logo |
| `update` | Check for and apply updates via GitHub releases |
| `vim <file>` | Open `file` in `vim` from the simulated Desktop |
| `nvim <file>` | Open `file` in `neovim` from the simulated Desktop |
| `echo <text>` | Print text |
| `which <name>` | Search `filesystem/bin/` for a binary |
| `echo $SHELL` | Print the shell name |
| `date` | Print the current date |
| `whoami` | Print the current user (`admin`) |
| `clear` | Clear the screen |
| `--version` | Print the OS version |
| `exit` | Quit the shell |

## System Information

| Component | Version |
| --- | --- |
| Talon Apex OS | `V0.0.4` *(current dev, not yet released — latest release is `v0.0.3`)* |
| Talon Apex Kernel | `V1.0.0` |
| Flash Bootloader | `V0.0.2` |

## Build & Run

Requires `g++` (C++17).

```sh
./quick.sh
./main
```

Or build manually:

```sh
g++ -o main main.cpp bootloader.cpp kernel/extra/make_dirs.cpp logo.cpp update.cpp kernel/kernel.c
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
├── update.cpp          # Self-updater using GitHub releases
├── logo.cpp            # penguinfetch logo
├── kernel/
│   ├── kernel.c        # Fake kernel init sequence
│   └── extra/          # make_dirs, initramfs, compat helpers
├── filesystem/         # Simulated filesystem (bin, boot, home, proc, rootfs, tmpfs)
└── .github/workflows/  # Build & release automation
```

## License

Licensed under the [GNU General Public License v3.0](LICENSE).