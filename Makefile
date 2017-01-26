
GPPPARAMS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = 	kernel.o \
			loader.o \
			utils.o \
			architecture/ia32/interrupts/gateDescriptor.o \
			architecture/ia32/interrupts/interruptDescriptorTable.o \
			architecture/ia32/interrupts/interruptGate.o \
			architecture/ia32/interrupts/interruptManager.o \
			architecture/ia32/interrupts/interruptStubs.o \
			architecture/ia32/interrupts/taskGate.o \
			architecture/ia32/interrupts/trapGate.o \
			architecture/ia32/pics/intel8259a/intel8259a.o \
			architecture/ia32/pics/intel8259a/intel8259aManager.o \
			architecture/ia32/globalDescriptorTable.o \
			architecture/ia32/segmentDescriptor.o \
			architecture/port.o

%.o: %.cpp
	g++ $(GPPPARAMS) -g -o $@ -c $<
	
%.o: %.s
	as $(ASPARAMS) -o $@ $<
	
cppOS.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)
	
install: cppOS.bin
	sudo cp $< /boot/cppOS.bin

cppOS.iso: cppOS.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "cppOS" {' >> iso/boot/grub/grub.cfg
	echo '	multiboot /boot/cppOS.bin' >> iso/boot/grub/grub.cfg
	echo '	boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

debug: cppOS.bin
	qemu-system-x86_64 -kernel cppOS.bin -s -S &
	gdb cppOS.bin -symbols . -tui -ex "target remote localhost:1234"

run: cppOS.iso
	qemu-system-x86_64 -kernel cppOS.bin

.PHONY: clean
clean:
	rm -f $(objects) cppOS.bin cppOS.iso

