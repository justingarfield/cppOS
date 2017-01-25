/*
 * Defines the contract for Initialisation Command Word 3 (ICW3) 
 * for an Intel 8259 Programmable Interrupt Controller (PIC).
 *
 */

// Make sure we only define this once
#ifndef __8259_PIC_ICW3_H
#define __8259_PIC_ICW3_H

#include "initialisationCommandWord.h"

class InitialisationCommandWord3 : InitialisationCommandWord
{
    
    protected:

        // Does Interrupt 0 have a Slave PIC attached?
        bool interrupt0HasSlave = false;

        // Does Interrupt 1 have a Slave PIC attached?
        bool interrupt1HasSlave = false;

        // Does Interrupt 2 have a Slave PIC attached?
        bool interrupt2HasSlave = false;

        // Does Interrupt 3 have a Slave PIC attached?
        bool interrupt3HasSlave = false;

        // Does Interrupt 4 have a Slave PIC attached?
        bool interrupt4HasSlave = false;

        // Does Interrupt 5 have a Slave PIC attached?
        bool interrupt5HasSlave = false;

        // Does Interrupt 6 have a Slave PIC attached?
        bool interrupt6HasSlave = false;

        // Does Interrupt 7 have a Slave PIC attached?
        bool interrupt7HasSlave = false;

        // A Slave PIC's Identity in a Cascade
        uint8_t cascadeIdentity = 0x00;

    public:

        // Constructor used when working with a Master PIC.
        InitialisationCommandWord3(bool interrupt0HasSlave, bool interrupt1HasSlave, bool interrupt2HasSlave, bool interrupt3HasSlave, 
                                    bool interrupt4HasSlave, bool interrupt5HasSlave, bool interrupt6HasSlave, bool interrupt7HasSlave);

        // Constructor used when working with a Slave PIC.
        InitialisationCommandWord3(uint8_t cascadeIdentity);

        ~InitialisationCommandWord3();

};

#endif