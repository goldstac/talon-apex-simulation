section .data 
msg db "Welcome To Talon Apex",0xa
msg_len equ $ - msg
section .bss
buf resb 64
section .text 
global bootloader
bootloader:
 mov rax,1
 mov rdi,1
 mov rsi,msg
 mov rdx,msg_len
 syscall
 mov rax,0
 mov rdi,0
 mov rsi,buf
 mov rdx,64
 syscall 
 ret

