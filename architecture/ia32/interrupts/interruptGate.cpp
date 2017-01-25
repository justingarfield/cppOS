
#include "interruptGate.h"
#include "gateDescriptorType.h"
#include "descriptorPrivilegeLevel.h"


InterruptGate::InterruptGate(uint16_t segmentSelectorAddress, bool isPresent)
{

    this.segmentSelectorAddress = segmentSelectorAddress;
    this.isPresent = isPresent;
    this.gateDescriptorType = GateDescriptorType::InterruptGate32Bit;
    this.descriptorPrivilegeLevel = DescriptorPrivilegeLevel::Ring0;

}

InterruptGate::~InterruptGate()
{



}