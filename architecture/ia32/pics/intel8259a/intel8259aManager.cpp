
#include "intel8259a.h"

Intel8259AManager::Intel8259AManager(uint16_t hardwareIntteruptOffset)
{

    // Keep a record of the Hardware Interrupt Offset
	this->hardwareInterruptOffset = hardwareInterruptOffset;

}

// Tell the Interrupt Manager to inform the PICs to start forwarding Interrupt Requests.
void StartInterrupts()
{
    asm("sti");
}

// Tell the Interrupt Manager to inform the PICs to stop forwarding Interrupt Requests.
void StopInterrupts()
{
    asm("cli");
}

// Initalize / Configure the system PICs with Default Settings.
// Default Settings are those commonly found in most IA32 systems and work with most Hyper-Visors.
Intel8259AManager::InitializeWithDefaultSettings()
{

    this->masterPIC = Intel8259A(0x20, 0x21);
    this->slavePIC = Intel8259A(0xA0, 0xA1);

    this->masterPIC.Write(0x11);
    this->slavePIC.Write(0x11);

    // remap
    this->masterPIC.Write(hardwareInterruptOffset);
    this->slavePIC.Write(hardwareInterruptOffset+8);

    this->masterPIC.Write(0x04);
    this->slavePIC.Write(0x02);

    this->masterPIC.Write(0x01);
    this->slavePIC.Write(0x01);

    this->masterPIC.Write(0x00);
    this->slavePIC.Write(0x00);

}
