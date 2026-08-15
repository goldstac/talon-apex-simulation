# Changelog

## V0.0.5 Features (under development)

- `cat proc/cpuinfo` and `cat proc/gpuinfo` now read from real files under `filesystem/proc/` instead of hardcoded shell blocks
- `make_dirs` generates `filesystem/proc/cpuinfo` and `filesystem/proc/gpuinfo` with content on first boot
- `!ping` prints an extra "System Is Responsive" message