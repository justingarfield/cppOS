
#ifndef __TASK_GATE_H
#define __TASK_GATE_H

#include "gateDescriptor.h"
#include "gateDescriptorType.h"

struct TaskGate : GateDescriptor
{

    public:
        TaskGate(uint16_t tssSegmentSelectorAddress, bool isPresent);

};

#endif
