
#include "interruptGate.h"
#include "gateDescriptorType.h"
#include "descriptorPrivilegeLevel.h"

InterruptGate::InterruptGate(uint32_t offsetAddress, uint16_t segmentSelectorAddress, bool isPresent)
{
    this->offsetAddress = offsetAddress;
    this->segmentSelectorAddress = segmentSelectorAddress;
    this->isPresent = isPresent;
    this->gateDescriptorType = InterruptGate32Bit;
    this->descriptorPrivilegeLevel = Ring0;
}
