/*
 * Defines a contract representing an Intel 8259 PIC.
 *
 * See: https://en.wikipedia.org/wiki/Intel_8259
 * See also: http://wiki.osdev.org/8259_PIC
 *
 */

#ifndef __INTEL_8259A_H
#define __INTEL_8259A_H

#include "../../../types.h"
#include "../../../port.h"

// The representation of an Intel 8259A PIC.
class Intel8259A
{

    protected:

        // Port allowing the raw rading/writing of commands to the underlying PIC
        Port8BitSlow commandPort;

        // Port allowing the raw reading/writing of data to the underlying PIC
        Port8BitSlow dataPort;

    public:

        // Constructor taking the PIC's Command Port and Data Port addresses.
        Intel8259A(uint16_t commandPortAddress, uint16_t dataPortAddress);

        // Destructor that currently does nothing.
        // TODO: Make this tell the PIC to re-init maybe? Check docs and search for recommendations.
		~Intel8259A();

        void WriteCommand(uint8_t data);
		uint8_t ReadCommand();

        void WriteData(uint8_t data);
		uint8_t ReadData();

};

#endif