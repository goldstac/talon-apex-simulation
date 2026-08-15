# Changelog

## V0.0.5 Features (under development)

- `cat proc/cpuinfo`, `cat proc/gpuinfo`, and `cat proc/meminfo` now read their content from real files under `filesystem/proc/`
- `make_dirs` generates `filesystem/proc/cpuinfo` and `filesystem/proc/gpuinfo` with content on first boot
- New `filesystem/proc/meminfo` file with simulated memory info (64 GB DDR5)
- `!ping` prints an extra "System Is Responsive" message
- New `Talon Calculator` under `extra/apex-dep/calculator.c` — hardened with input validation, divide-by-zero guard, and stdin flush after use
- Fixed `initramfs`: bootloader now creates `initramfs.img` and `initramfs_uncompressed.img` after the directory check
- `cd` is now functional: tracks the working directory, supports `~`, `..`, `/boot`-style paths, and can explore anywhere inside `filesystem/` (sandboxed — can't leave it)
- The shell prompt now shows the current directory (e.g. `[~/.cache]`)
- `touch`, `vim`, and `nvim` now operate in the current directory