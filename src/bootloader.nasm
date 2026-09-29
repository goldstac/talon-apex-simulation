section .data 
   
   bootloader_name db "Flash Bootloader",0xa
   bootloader_name_len equ $ - bootloader_name

   bootloader_print_boot_option_text db "Boot Option's",0xa
   bootloader_print_boot_option_text_len equ $ - bootloader_print_boot_option_text

   bootloader_options db "1 : [TALON APEX]",0xa
   bootloader_options_len equ $ - bootloader_options

   bootloader_input_text db "Enter Boot Option $ > "
   bootloader_input_text_len equ $ - bootloader_input_text

section .bss 
buf resb 64
global buf

section .text 
   global bootloader 
bootloader: 
    mov rax,1
    mov rdi,1
    mov rsi,bootloader_name
    mov rdx,bootloader_name_len
    syscall

    mov rax,1
    mov rdi,1
    mov rsi,bootloader_print_boot_option_text
    mov rdx,bootloader_print_boot_option_text_len
    syscall

    mov rax,1
    mov rdi,1
    mov rsi,bootloader_options
    mov rdx,bootloader_options_len
    syscall

    mov rax,1
    mov rdi,1
    mov rsi,bootloader_input_text
    mov rdx,bootloader_input_text_len
    syscall

    mov rax,0
    mov rdi,0
    mov rsi,buf
    mov rdx,64
    syscall
    ret 


