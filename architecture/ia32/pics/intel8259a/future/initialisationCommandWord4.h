/*
 * Defines the contract for Initialisation Command Word 4 (ICW4) 
 * for an Intel 8259 Programmable Interrupt Controller (PIC).
 *
 */

// Make sure we only define this once
#ifndef __8259_PIC_ICW4_H
#define __8259_PIC_ICW4_H

#include "initialisationCommandWord.h"
#include "microProcessorMode.h"

class InitialisationCommandWord4 : InitialisationCommandWord
{
    
    protected:
        
        // Is Special Fully Nested Mode programmed?
        bool specialFullyNestedModeProgrammed = false;

        bool automaticEndOfInterrupt = false;

        // 
        bool isMaster = false;

        // Which Micro Processor Mode we're running in (MCS80/85 or 8086/8080)
        MicroProcessorMode microProcessorMode;

    public:
        InitialisationCommandWord4(MicroProcessorMode microProcessorMode);
        ~InitialisationCommandWord4();

};

#endif