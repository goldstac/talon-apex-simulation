# Changelog

## V0.0.5 Features (under development)

- `cat proc/cpuinfo`, `cat proc/gpuinfo`, and `cat proc/meminfo` now read their content from real files under `filesystem/proc/`
- `make_dirs` generates `filesystem/proc/cpuinfo` and `filesystem/proc/gpuinfo` with content on first boot
- `make_dirs` silently creates placeholder binaries (`push`, `calculator`, `cat`, `ls`, `echo`) in `filesystem/bin/` on first boot
- New `filesystem/proc/meminfo` file with simulated memory info (64 GB DDR5)
- `!ping` prints an extra "System Is Responsive" message
- New `Talon Calculator` under `extra/apex-dep/calculator.c` — hardened with input validation, divide-by-zero guard, and stdin flush after use
- Fixed `initramfs`: bootloader now creates `initramfs.img` and `initramfs_uncompressed.img` after the directory check
- `cd` is now functional: tracks the working directory, supports `~`, `..`, `/boot`-style paths, and can explore anywhere inside `filesystem/` (sandboxed — can't leave it)
- The shell prompt now shows the current directory (e.g. `[~/.cache]`)
- Bootloader now validates the boot option: only `1` is accepted, invalid input exits cleanly instead of breaking the shell loop
- New `pwd` command that prints the current directory
- New `nano` command that opens files from the current directory (like `vim`/`nvim`)
- `touch` no longer prints "enter a filename" when a filename is given
- New `ls` command that lists the contents of the current directory (or `ls <dir>` for another)
- New `rm` command to delete files and `rm -rf` to recursively delete directories
- New `mkdir` command to create directories
- New system logging to `filesystem/var/log/system.log`: boot events, every shell command, unknown commands, and errors
- New `talonlogd` system config at `filesystem/etc/talonlogd.conf` — first boot prompts for `log_time_true` (timestamps in logs on/off), later boots read it silently
- New `dmesg` command to view the system log
- New crash system: removing a critical path (`rm -rf boot`, etc.) logs a `CRITICAL` entry, and the system halts with a crash screen showing the last log entries when it detects corruption
- `touch`, `vim`, and `nvim` now operate in the current directory