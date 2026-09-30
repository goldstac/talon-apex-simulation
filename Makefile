build:
	nasm -f elf64 src/bootloader.nasm -o bin/bootloader.o
	nasm -f elf64 src/input.nasm -o bin/input.o
	gcc src/*.c bin/*.o -o bin/main -no-pie
