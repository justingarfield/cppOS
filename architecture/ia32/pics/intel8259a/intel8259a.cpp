/*
 * Represents an Intel 8259 PIC.
 *
 * The Intel 8259A Programmable Interrupt Controller handles up to eight vectored priority interrupts for the CPU.
 * It is cascadable for up to 64 vectored priority interrupts without additional circuitry. It is packaged in a 28-pin
 * DIP, uses NMOS technology and requires a single a5V supply. Circuitry is static, requiring no clock input.
 * The 8259A is designed to minimize the software and real time overhead in handling multi-level priority interrupts.
 * It has several modes, permitting optimization for a variety of system requirements.
 * The 8259A is fully upward compatible with the Intel 8259. Software originally written for the 8259 will operate
 * the 8259A in all 8259 equivalent modes (MCS-80/85, Non-Buffered, Edge Triggered).
 *
 * See: https://en.wikipedia.org/wiki/Intel_8259
 * See also: http://wiki.osdev.org/8259_PIC
 *
 */

#include "8259.h"

Intel8259PIC::Intel8259PIC(uint16_t commandPortAddress, uint16_t dataPortAddress)
{   
    this->commandPort = new Port8BitSlow(commandPortAddress);
    this->dataPort = new Port8BitSlow(dataPortAddress);
}

Intel8259PIC::~Intel8259PIC()
{
    
}

// Tells the PIC to run its initialization command
void Intel8259PIC::Initialize()
{
    this->commandPort.WriteCommand(0x11);
}

void Intel8259PIC::WriteCommand(uint32_t data)
{

}

uint32_t Intel8259PIC::ReadCommand()
{

}

void Intel8259PIC::WriteData(uint32_t data)
{

}

uint32_t Intel8259PIC::ReadData()
{

}

bool Intel8259PIC::IsICW4Needed() {

    

}