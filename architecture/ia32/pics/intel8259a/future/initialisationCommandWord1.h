/*
 * Defines the contract for Initialisation Command Word 1 (ICW1) 
 * for an Intel 8259 Programmable Interrupt Controller (PIC).
 *
 */

// Make sure we only define this once
#ifndef __8259_PIC_ICW1_H
#define __8259_PIC_ICW1_H

#include "initialisationCommandWord.h"

class InitialisationCommandWord1 : InitialisationCommandWord
{
    
    protected:
        
        // Is Initialisation Command Word 4 needed?
        bool icw4Needed = false;

        // Is this the only 8259(A) in the system?
        bool singlePICSystem = false;

        // Is the Call Address Interval 4-bytes? (defaults to 8-bytes)
        bool fourByteCallAddressInterval = false;
        
        // Is operating in Level Interrupt Mode? (defaults to Edge-triggered mode)
        bool operatingInLevelInterruptMode = false;

    public:
        InitialisationCommandWord1(bool icw4Needed, bool singlePICSystem, bool fourByteCallAddressInterval, bool operatingInLevelInterruptMode);
        ~InitialisationCommandWord1();

};

#endif