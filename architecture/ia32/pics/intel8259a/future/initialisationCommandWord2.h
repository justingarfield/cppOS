/*
 * Defines the contract for Initialisation Command Word 1 (ICW1) 
 * for an Intel 8259 Programmable Interrupt Controller (PIC).
 *
 */

// Make sure we only define this once
#ifndef __8259_PIC_ICW2_H
#define __8259_PIC_ICW2_H

#include "initialisationCommandWord.h"

class InitialisationCommandWord2 : InitialisationCommandWord
{
    
    protected:
        uint8_t offset;

    public:
        InitialisationCommandWord2(uint8_t offset);
        ~InitialisationCommandWord2();

};

#endif