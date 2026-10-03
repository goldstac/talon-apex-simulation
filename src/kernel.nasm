section .data 

   kernel_name db "Talon Kernel",0xa
   kernel_name_len equ $ - kernel_name
   global kernel_name

   kernel_version db "0.0.1",0xa
   kernel_version_len equ $ - kernel_version
   global kernel_version

   welcome_message db "Welcome To Talon Apex",0xa
   welcome_message_len equ $ - welcome_message 

   os_architecture db "x86_64",0xa
   os_architecture_len equ $ - os_architecture
   global os_architecture

   
section .text 
   global name
name:
   mov rax,1
   mov rdi,1
   mov rsi,kernel_name
   mov rdx,kernel_name_len
   syscall
   ret 
   global kernel_version
kernel_version:
   mov rax,1
   mov rdi,1
   mov rsi,kernel_version
   mov rdx,kernel_version_len
   syscall
   ret
   global welcome_msg
welcome_msg:
   mov rax,1
   mov rdi,1
   mov rsi,welcome_message
   mov rdx,welcome_message_len
   syscall
   ret 
   global os_architecture_msg
os_architecture_msg:
   mov rax,1
   mov rdi,1
   mov rsi,os_architecture
   mov rdx,os_architecture_len
   syscall 
   ret

