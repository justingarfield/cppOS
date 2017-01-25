// C/C++ programs expect the Stack Pointer (ESP) to be set before running.
// This sets the Stack Pointer (ESP) and then jumps into the Kernel.

// "Magic Number", so that the Boot Loader will see us
.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

.section .text
.extern kernelMain
.extern callConstructors
.global loader

loader:
	mov $kernel_stack, %esp
	
	call callConstructors
	
	push %eax
	push %ebx
	call kernelMain

// In-case kernelMain exits, infinite loop
_stop:
	cli # Clear interrupts
	hlt # Halt CPU
	jmp _stop
	
.section .bss
.space 2*1024*1024; # 2MiB
kernel_stack:
