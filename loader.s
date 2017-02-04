
# Set the symbol "MAGIC" to be 0x1badb002. This is what Multiboot 1 looks for in its header
.set MAGIC, 0x1badb002

# Set the symbol "FLAGS" to 3? (Verify why we have to do this...does this do something with Endianess?)
# According to the multiboot header file, if this is always 3, then we have:
# 0x00000001 - is there basic lower/upper memory information?
# 0x00000002 - is there a boot device set?
.set FLAGS, (1<<0 | 1<<1)

# The MAGIC and FLAGS symbols plus CHECKSUM one must equal 0 mod 2^32 (4294967296).
.set CHECKSUM, -(MAGIC + FLAGS)


# Generate the actual Multiboot 1 Header section.
# This is what a Multiboot v1-compliant Bootloader will look for
.section .multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM


# The .text section is used for keeping the actual code. 
# This section must begin with the declaration global <label>
# to provide an entry point.
#
# Tell the assembler that kernelMain and callConstructors are in external source somewhere 
# (we may not need .extern mordern-day...AS now defaults to assuming undefined symbols are going to be linked in from external source)
#
# Also make sure that "bootstrapKernel" is made global and viewable to anything else the linker is working with

.section .text
	.extern kernelMain # TODO: Research the effect of removing this
	.extern callConstructors # TODO: Research the effect of removing this
	.global bootstrapKernel # <<<--- IMPORTANT: This will tell the linker that this is the entry point for our code

	# The code in this label is responsible for setting up the Stack Pointer for the Kernel's Stack
	# and also calling the main entry point to the Kernel itself (over in C++)
	bootstrapKernel:

		# Move the current value of the ESP Register into the kernelStack memory location (is this correct?)
		mov $kernelStack, %esp
		
		# Push the contents of the EAX and EBX Registers onto the Stack
		push %eax # TODO: Figure out if this is multiboot_structure
		push %ebx # TODO: Figure out if this is magicNumber
		
		# Call the kernelMain function and pass control to the Kernel itself
		call kernelMain # Linked in from kernel.cpp

	# In-case kernelMain exits, infinite loop
	_stop:
		cli # Clear interrupts
		hlt # Halt CPU
		jmp _stop


# The bss section is used for declaring variables.
# Here we pad out 2MiB worth of space before declaring the Kernel's Stack
.section .bss
	.space 2*1024*1024; # 2MiB
	kernelStack:
