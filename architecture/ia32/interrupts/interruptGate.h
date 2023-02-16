
#ifndef __INTERRUPT_GATE_H
#define __INTERRUPT_GATE_H

#include "../../types.h"
#include "gateDescriptor.h"

struct InterruptGate : GateDescriptor
{

    protected:
        uint32_t offsetAddress;
    
    public:
        InterruptGate(uint32_t offsetAddress, uint16_t segmentSelectorAddress, bool isPresent);
   
};

#endif
