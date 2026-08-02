// initramfs.h
#ifndef INITRAMFS_H
#define INITRAMFS_H

#ifdef __cplusplus
extern "C" {
#endif

void create_file_initramfs(const char* filepath);
void create_tmpfs_initramfs(void);

#ifdef __cplusplus
}
#endif

#endif