
#include "taskGate.h"
#include "gateDescriptorType.h"
#include "descriptorPrivilegeLevel.h"

TaskGate::TaskGate(uint16_t tssSegmentSelectorAddress, bool isPresent)
{

    this->segmentSelectorAddress = tssSegmentSelectorAddress;
    this->isPresent = isPresent;
    this->gateDescriptorType = TaskGate32Bit;
    this->descriptorPrivilegeLevel = Ring0;

}
