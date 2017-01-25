
#include "utils.h"
#include "architecture/types.h"
#include "architecture/ia32/globalDescriptorTable.h"
#include "architecture/ia32/interrupts/interruptManager.h"

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
	for(constructor* i = &start_ctors; i != &end_ctors; i++)
		(*i)();
}

extern "C" void kernelMain(const void* multiboot_structure, uint32_t magicnumber)
{

	clearScreen();

	printf("==================================================\n");
	printf("#               Welcome to cppOS                 #\n");
	printf("==================================================\n");
	printf("\n");

	printf("Initializing Global Descriptor Table (GDT)...");
	GlobalDescriptorTable globalDescriptorTable;
	printf("Done\n");
	
	printf("Initializing Interrupt Manager...");
	InterruptManager interruptManager(0x20, &globalDescriptorTable);
	printf("Done\n");
	
	//printf("Activating Interrupts...")
	//interrupts.Activate();
	//printf("Done\n");
	
	// Keep the Kernel running
	while(1);
	
}
