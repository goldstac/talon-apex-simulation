section .data 
   shell_prompt db "talon@admin $ > "
   shell_prompt_len equ $ - shell_prompt

section .bss
   user_input resb 64
   global user_input
section .text 
   global input

input:

   mov rax,1
   mov rdi,1
   mov rsi,shell_prompt
   mov rdx,shell_prompt_len
   syscall 

   mov rax,0
   mov rdi,0
   mov rsi,user_input
   mov rdx,64
   syscall
   ret

