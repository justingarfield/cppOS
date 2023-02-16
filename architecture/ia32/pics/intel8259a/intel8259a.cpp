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

#include "intel8259a.h"

Intel8259A::Intel8259A(uint16_t commandPortAddress, uint16_t dataPortAddress) : commandPort(commandPortAddress), dataPort(dataPortAddress) {
    
}

 // Destructor that currently does nothing.
// TODO: Make this tell the PIC to re-init maybe? Check docs and search for recommendations.
Intel8259A::~Intel8259A() { }

void Intel8259A::WriteCommand(uint8_t data) {
    this->commandPort.Write(data);
}

uint8_t Intel8259A::ReadCommand() {
    return this->commandPort.Read();
}

void Intel8259A::WriteData(uint8_t data) {
    this->dataPort.Write(data);
}

uint8_t Intel8259A::ReadData() {
    return this->dataPort.Read();
}
