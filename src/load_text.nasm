section .data 
msg db "Welcome To Talon Apex", 0xa
msg_len equ $ - msg 

section .text 
global say_hello

say_hello:
  mov rax,1
  mov rdi,1
  mov rsi,msg
  mov rdx,msg_len
  syscall
  ret 

