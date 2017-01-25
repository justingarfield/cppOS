
#ifndef __INTERRUPT_GATE_H
#define __INTERRUPT_GATE_H

#include "gateDescriptor.h"
#include "gateDescriptorType.h"

struct InterruptGate : GateDescriptor
{
    
    public:
        InterruptGate(uint16_t segmentSelectorAddress, bool isPresent);
        ~InterruptGate();
   
};

#endif
