
#include "interruptManager.h"
#include "gateDescriptor.h"
#include "interruptGate.h"
#include "optimized/gateDescriptorPacked.h"

#include "../globalDescriptorTable.h"
#include "../pics/intel8259a/intel8259aManager.h"
#include "../../types.h"
#include "../../../utils.h"

GateDescriptorPacked InterruptManager::interruptDescriptorTable[256];

void InterruptManager::SetInterruptDescriptorTableEntry(uint8_t interrupt,
    uint16_t codeSegmentSelector, void (*handler)(), uint8_t DescriptorPrivilegeLevel, uint8_t DescriptorType)
{
    // address of pointer to code segment (relative to global descriptor table)
    // and address of the handler (relative to segment)
    interruptDescriptorTable[interrupt].handlerAddressLowBits = ((uint32_t) handler) & 0xFFFF;
    interruptDescriptorTable[interrupt].handlerAddressHighBits = (((uint32_t) handler) >> 16) & 0xFFFF;
    interruptDescriptorTable[interrupt].segmentSelector = codeSegmentSelector;

    const uint8_t IDT_DESC_PRESENT = 0x80;
    interruptDescriptorTable[interrupt].access = IDT_DESC_PRESENT | DescriptorType | ((DescriptorPrivilegeLevel & 3) << 5);
    interruptDescriptorTable[interrupt].reserved = 0;
}

// Instansiate an Interrupt Manager with Master and Slave PICs defined.
InterruptManager::InterruptManager(uint16_t hardwareInterruptOffset, GlobalDescriptorTable* globalDescriptorTable, Intel8259AManager* picManager)
{

    //this->picManager = picManager;

    // Keep a record of the Hardware Interrupt Offset
	this->hardwareInterruptOffset = hardwareInterruptOffset;

	uint16_t codeSegmentSelector = globalDescriptorTable->CodeSegmentSelector();

	const uint8_t IDT_INTERRUPT_GATE = 0xE;
	for(uint8_t i = 255; i > 1; --i) {
		SetInterruptDescriptorTableEntry(i, codeSegmentSelector, &InterruptIgnore, 0, IDT_INTERRUPT_GATE);
	}

	SetInterruptDescriptorTableEntry(0, codeSegmentSelector, &InterruptIgnore, 0, IDT_INTERRUPT_GATE);

    /*
    for (uint8_t interruptNumber = 0x1F; interruptNumber > 0; --interruptNumber) {

        SetInterruptDescriptorTableEntry(interruptNumber, codeSegmentSelector, &HandleException0x00, 0, IDT_INTERRUPT_GATE);
    }
    */

    // Handle Interrupts 0-31 as Exceptions
	SetInterruptDescriptorTableEntry(0x00, codeSegmentSelector, &HandleException0x00, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x01, codeSegmentSelector, &HandleException0x01, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x02, codeSegmentSelector, &HandleException0x02, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x03, codeSegmentSelector, &HandleException0x03, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x04, codeSegmentSelector, &HandleException0x04, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x05, codeSegmentSelector, &HandleException0x05, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x06, codeSegmentSelector, &HandleException0x06, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x07, codeSegmentSelector, &HandleException0x07, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x08, codeSegmentSelector, &HandleException0x08, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x09, codeSegmentSelector, &HandleException0x09, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0A, codeSegmentSelector, &HandleException0x0A, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0B, codeSegmentSelector, &HandleException0x0B, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0C, codeSegmentSelector, &HandleException0x0C, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0D, codeSegmentSelector, &HandleException0x0D, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0E, codeSegmentSelector, &HandleException0x0E, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x0F, codeSegmentSelector, &HandleException0x0F, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x10, codeSegmentSelector, &HandleException0x10, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x11, codeSegmentSelector, &HandleException0x11, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x12, codeSegmentSelector, &HandleException0x12, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x13, codeSegmentSelector, &HandleException0x13, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x14, codeSegmentSelector, &HandleException0x14, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x15, codeSegmentSelector, &HandleException0x15, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x16, codeSegmentSelector, &HandleException0x16, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x17, codeSegmentSelector, &HandleException0x17, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x18, codeSegmentSelector, &HandleException0x18, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x19, codeSegmentSelector, &HandleException0x19, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x1A, codeSegmentSelector, &HandleException0x1A, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x1B, codeSegmentSelector, &HandleException0x1B, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x1C, codeSegmentSelector, &HandleException0x1C, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x1D, codeSegmentSelector, &HandleException0x1D, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x1E, codeSegmentSelector, &HandleException0x1E, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(0x1F, codeSegmentSelector, &HandleException0x1F, 0, IDT_INTERRUPT_GATE);

    // Handle Interrupts 0-15 (but starting at 0x20 as an offset)
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x00, codeSegmentSelector, &HandleInterruptRequest0x00, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x01, codeSegmentSelector, &HandleInterruptRequest0x01, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x02, codeSegmentSelector, &HandleInterruptRequest0x02, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x03, codeSegmentSelector, &HandleInterruptRequest0x03, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x04, codeSegmentSelector, &HandleInterruptRequest0x04, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x05, codeSegmentSelector, &HandleInterruptRequest0x05, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x06, codeSegmentSelector, &HandleInterruptRequest0x06, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x07, codeSegmentSelector, &HandleInterruptRequest0x07, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x08, codeSegmentSelector, &HandleInterruptRequest0x08, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x09, codeSegmentSelector, &HandleInterruptRequest0x09, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0A, codeSegmentSelector, &HandleInterruptRequest0x0A, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0B, codeSegmentSelector, &HandleInterruptRequest0x0B, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0C, codeSegmentSelector, &HandleInterruptRequest0x0C, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0D, codeSegmentSelector, &HandleInterruptRequest0x0D, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0E, codeSegmentSelector, &HandleInterruptRequest0x0E, 0, IDT_INTERRUPT_GATE);
    SetInterruptDescriptorTableEntry(hardwareInterruptOffset + 0x0F, codeSegmentSelector, &HandleInterruptRequest0x0F, 0, IDT_INTERRUPT_GATE);

	// Create a new Intel 8259A PIC Manager and Initalize / Configure the system PICs with Default Settings.
	picManager->InitializeWithDefaultSettings();

	InterruptDescriptorTablePointer idtPointer;
	idtPointer.limit = sizeof(interruptDescriptorTable); // size of table in bytes
	idtPointer.base = (uint32_t)interruptDescriptorTable; // a linear address
	//asm volatile("lidt (%0)" : : "p" (&idtPointer));
    asm volatile("lidt %0" : : "m" (idtPointer));

}

// Deconstructor
InterruptManager::~InterruptManager()
{
	// TODO: Deactivate PICs here
}

uint32_t InterruptManager::HandleInterrupt(uint8_t interrupt, uint32_t esp)
{
    /*
    char* foo = "INTERRUPT 0x00";
    char* hex = "0123456789ABCDEF";

    foo[12] = hex[(interrupt >> 4) & 0xF];
    foo[13] = hex[interrupt & 0xF];
    //printf(foo);

    /* If the IDT entry that was invoked was greater than 40
    *  (meaning IRQ8 - 15), then we need to send an EOI to
    *  the slave controller */
    /*if (interrupt >= 40)
    {
        this->picManager.slavePIC.WriteCommand(0x20);
    }

    /* In either case, we need to send an EOI to the master
    *  interrupt controller too */
    //this->picManager.masterPIC.WriteCommand(0x20);
    printf("NO MORE TRIPLE FAULT...YAY!!!\n\n");
    return esp;
}
