
#include "intel8259aManager.h"

Intel8259AManager::Intel8259AManager(uint16_t hardwareIntteruptOffset) : masterPIC(0x20, 0x21), slavePIC(0xA0, 0xA1)
{

    // Keep a record of the Hardware Interrupt Offset
	this->hardwareInterruptOffset = hardwareInterruptOffset;

}

// Tell the Interrupt Manager to inform the PICs to start forwarding Interrupt Requests.
void Intel8259AManager::StartInterrupts()
{
    asm("sti");
}

// Tell the Interrupt Manager to inform the PICs to stop forwarding Interrupt Requests.
void Intel8259AManager::StopInterrupts()
{
    asm("cli");
}

// Initalize / Configure the system PICs with Default Settings.
// Default Settings are those commonly found in most IA32 systems and work with most Hyper-Visors.
void Intel8259AManager::InitializeWithDefaultSettings()
{
    
    this->masterPIC.WriteCommand(0x11);
    this->slavePIC.WriteCommand(0x11);

    // remap
    this->masterPIC.WriteData(hardwareInterruptOffset);
    this->slavePIC.WriteData(hardwareInterruptOffset+8);

    this->masterPIC.WriteData(0x04);
    this->slavePIC.WriteData(0x02);

    this->masterPIC.WriteData(0x01);
    this->slavePIC.WriteData(0x01);

    this->masterPIC.WriteData(0x00);
    this->slavePIC.WriteData(0x00);

}
