
#ifndef __TRAP_GATE_H
#define __TRAP_GATE_H

#include "gateDescriptor.h"

struct TrapGate : GateDescriptor
{

    public:
        TrapGate(uint16_t segmentSelectorAddress, bool isPresent);
    
};

#endif
