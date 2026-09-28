build:
	nasm -f elf64 src/*.nasm -o bin/bootloader.o
	gcc src/*.c bin/*.o -o bin/main -no-pie
