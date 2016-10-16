nasm -f elf32 src/kernel.asm -o obj/kasm.o
gcc -m32 -c src/kernel.c -o kc.o -ffreestanding
gcc -m32 -c src/system.c -o obj/system.o -ffreestanding
gcc -m32 -c src/isr.c -o obj/isr.o -ffreestanding
gcc -m32 -c src/idt.c -o obj/idt.o -ffreestanding
gcc -m32 -c src/util.c -o obj/util.o -ffreestanding
gcc -m32 -c src/string.c -o obj/string.o -ffreestanding
gcc -m32 -c src/screen.c -o obj/screen.o -ffreestanding
gcc -m32 -c src/kb.c -o obj/kb.o -ffreestanding
gcc -m32 -c src/shell.c -o obj/shell.o -ffreestanding
ld -m elf_i386 -T src/link.ld -o erikOS/boot/kernel.bin obj/kasm.o kc.o obj/shell.o obj/system.o obj/string.o obj/screen.o obj/kb.o obj/idt.o obj/util.o obj/isr.o
qemu-system-i386 -kernel erikOS/boot/kernel.bin

grub-mkrescue -o erikOS.iso erikOS/

