
#include "trapGate.h"
#include "gateDescriptorType.h"
#include "descriptorPrivilegeLevel.h"

TrapGate::TrapGate(uint16_t segmentSelectorAddress, bool isPresent)
{

    this->segmentSelectorAddress = segmentSelectorAddress;
    this->isPresent = isPresent;
    this->gateDescriptorType = TrapGate32Bit;
    this->descriptorPrivilegeLevel = Ring0;

}
