/*
 * Defines a contract representing an Intel 8259 PIC.
 *
 * See: https://en.wikipedia.org/wiki/Intel_8259
 * See also: http://wiki.osdev.org/8259_PIC
 *
 */

// Make sure we only define this once
#ifndef __8259_PIC_H
#define __8259_PIC_H

// Include the required libraries for this to function
#include "../types.h"
#include "../../../port.h"

// The representation of an Intel 8259 PIC.
class Intel8259PIC
{

    protected:

        // Port allowing the raw rading/writing of commands to the underlying PIC
        Port8BitSlow commandPort;

        // Port allowing the raw reading/writing of data to the underlying PIC
        Port8BitSlow dataPort;

        // Initialisation Control Word 1 (ICW1)
        InitialisationCommandWord1 initialisationCommandWord1;

        // Initialisation Control Word 2 (ICW2)
        InitialisationCommandWord2 initialisationCommandWord2;

        // Initialisation Control Word 3 (ICW3)
        InitialisationCommandWord3 initialisationCommandWord3;

        // Initialisation Control Word 4 (ICW4)
        InitialisationCommandWord4 initialisationCommandWord4;


    public:
        // Constructor taking the PIC's Command Port and Data Port addresses.
        Intel8259PIC(uint16_t commandPortAddress, uint16_t dataPortAddress);

        /// Destructor that currently does nothing.
        // TODO: Make this tell the PIC to re-init maybe? Check docs and search for recommendations.
		~Intel8259PIC();
        
        // Tells the PIC to run its initialization command
        void Initialize();

        bool IsICW4Needed();

        void WriteCommand(uint32_t data);
		uint32_t ReadCommand();

        void WriteData(uint32_t data);
		uint32_t ReadData();

};

#endif