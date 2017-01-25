
#include "../../types.h"
#include "gateDescriptor.h"

// Instansiate an Interrupt Manager with Master and Slave PICs defined.
InterruptManager::InterruptManager(uint16_t hardwareIntteruptOffset, GlobalDescriptorTable* globalDescriptorTable)
	: masterPIC(0x0020, 0x0021), slavePIC(0x00A0, 0x00A1)
{

    // Keep a record of the Hardware Interrupt Offset
	this->hardwareInterruptOffset = hardwareInterruptOffset;

	uint16_t codeSegmentSelector = globalDescriptorTable->CodeSegmentSelector();

	const uint8_t IDT_INTERRUPT_GATE = 0xE;
	for(uint8_t i = 255; i > 1; --i) {
		SetInterruptDescriptorTableEntry(i, codeSegmentSelector, &InterruptIgnore, 0, IDT_INTERRUPT_GATE);

	SetInterruptDescriptorTableEntry(0, codeSegmentSelector, &InterruptIgnore, 0, IDT_INTERRUPT_GATE);

    

    //=====    Handle Intel 8259A initialization sequence    =====
    
    bool multiplePICs = true;

    masterPIC.Initialize();
    slavePIC.Initialize();

    InitialisationCommandWord1 initialisationCommandWord1(false, multiplePICs, false, false);
    
    InitialisationCommandWord2 initialisationCommandWord2();
    
    // ICW3 is only issued if there is more than one PIC
    if (multiplePICs)
        InitialisationCommandWord3 initialisationCommandWord3();

    InitialisationCommandWord4 initialisationCommandWord4();

    //============================================================

	InterruptDescriptorTablePointer idt;
	idt.size = 256 * sizeof(GateDescriptor) - 1;
	idt.base = (uint32_t)interruptDescriptorTable;
	asm volatile("lidt %0" : : "m" (idt));

}

// Deconstructor
InterruptManager::~InterruptManager()
{
		Deactivate();
}

void InterruptManager::Activate()
{
	asm("sti");
}

void InterruptManager::Deactivate()
{

}