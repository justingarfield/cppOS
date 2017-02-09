
#include "utils.h"
#include "architecture/types.h"
#include "architecture/ia32/globalDescriptorTable.h"
#include "architecture/ia32/interrupts/interruptManager.h"
#include "architecture/ia32/pics/intel8259a/intel8259aManager.h"

extern "C" void kernelMain(const void* multiboot_structure, uint32_t magicnumber)
{

	clearScreen();

	printf("==================================================\n");
	printf("#               Welcome to cppOS                 #\n");
	printf("==================================================\n");
	printf("\n");

	printf("Initializing PIC Manager...");
	Intel8259AManager picManager(0x20);
	printf("Done\n");

	printf("Disabling Interrupts...");
	picManager.StopInterrupts();
	printf("Done\n");
	
	printf("Initializing Global Descriptor Table (GDT)...");
	GlobalDescriptorTable globalDescriptorTable;
	printf("Done\n");

	printf("Initializing Interrupt Manager...");
	InterruptManager interruptManager(0x20, &globalDescriptorTable, &picManager);
	printf("Done\n");
	
	printf("Activating Interrupts...");
	picManager.StartInterrupts();
	printf("Done\n\n\n");
	
	// Keep the Kernel running
	while(1);
	
}
