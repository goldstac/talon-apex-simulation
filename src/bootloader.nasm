section .data 
msg_welcome db "Welcome To Talon Apex",0xa
msg_welcome_len equ $ - msg_welcome

msg_user_input db "admin@talon $ > "
msg_user_input_len equ $ - msg_user_input
section .bss
buf resb 64
global buf

section .text 
global bootloader

bootloader:
  mov rax,1 ;prints welcome
  mov rdi,1
  mov rsi,msg_welcome
  mov rdx,msg_welcome_len
  syscall

  mov rax,1 ; prints shell prompt
  mov rdi,1
  mov rsi,msg_user_input
  mov rdx,msg_user_input_len
  syscall 

  mov rax,0 ; ask for user input
  mov rdi,0
  mov rsi,buf
  mov rdx,64
  syscall 
  ret

