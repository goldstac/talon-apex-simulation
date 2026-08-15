SRC="main.cpp bootloader.cpp kernel/extra/make_dirs.cpp kernel/extra/initramfs.cpp logo.cpp update.cpp kernel/kernel.c extra/apex-dep/calculator.c"
g++ -o main $SRC
