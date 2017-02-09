
.set IRQ_BASE, 0x20

.section .text

.extern _ZN16InterruptManager15HandleInterruptEhj

.macro HandleException num
.global _ZN16InterruptManager19HandleException\num\()Ev
_ZN16InterruptManager19HandleException\num\()Ev:
	movb $\num, (interruptNumber)
	jmp int_bottom
.endm

.macro HandleInterruptRequest num
.global _ZN16InterruptManager26HandleInterruptRequest\num\()Ev
_ZN16InterruptManager26HandleInterruptRequest\num\()Ev:
	movb $\num + IRQ_BASE, (interruptNumber)
	jmp int_bottom
.endm

# Interrupts 0-31 are reserved by the Intel 64 and IA-32 architectures for architecture-defined exceptions and interrupts
HandleException 0x00
HandleException 0x01
HandleException 0x02
HandleException 0x03
HandleException 0x04
HandleException 0x05
HandleException 0x06
HandleException 0x07
HandleException 0x08
HandleException 0x09
HandleException 0x0A
HandleException 0x0B
HandleException 0x0C
HandleException 0x0D
HandleException 0x0E
HandleException 0x0F
HandleException 0x10
HandleException 0x11
HandleException 0x12
HandleException 0x13
HandleException 0x14
HandleException 0x15
HandleException 0x16
HandleException 0x17
HandleException 0x18
HandleException 0x19
HandleException 0x1A
HandleException 0x1B
HandleException 0x1C
HandleException 0x1D
HandleException 0x1E
HandleException 0x1F

HandleInterruptRequest 0x00
HandleInterruptRequest 0x01
HandleInterruptRequest 0x02
HandleInterruptRequest 0x03
HandleInterruptRequest 0x04
HandleInterruptRequest 0x05
HandleInterruptRequest 0x06
HandleInterruptRequest 0x07
HandleInterruptRequest 0x08
HandleInterruptRequest 0x09
HandleInterruptRequest 0x0A
HandleInterruptRequest 0x0B
HandleInterruptRequest 0x0C
HandleInterruptRequest 0x0D
HandleInterruptRequest 0x0E
HandleInterruptRequest 0x0F

int_bottom:

	# Push all General Purpose Registers (AX, CX, DX, BX, original SP, BP, SI, and DI) onto the Stack
    pusha
    
    # Push ds, es, fs, and gs Register values onto the Stack
    push %ds
    push %es
    push %fs
    push %gs

    # C++ Handler
    push %esp
    push (interruptNumber)
    call _ZN16InterruptManager15HandleInterruptEhj
    add %esp, 6
    mov %eax, %esp

    # Pop gs, fs, es, and ds Register values off of the Stack
    pop %gs
    pop %fs
    pop %es
    pop %ds

    # Pop all General Purpose Registers (AX, CX, DX, BX, original SP, BP, SI, and DI) off the Stack
    popa
	
.global _ZN16InterruptManager15InterruptIgnoreEv
_ZN16InterruptManager15InterruptIgnoreEv:
	iret

.data
	interruptNumber: .byte 0
