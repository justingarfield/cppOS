
#include "taskGate.h"
#include "gateDescriptorType.h"
#include "descriptorPrivilegeLevel.h"

TaskGate::TaskGate(uint16_t tssSegmentSelectorAddress, bool isPresent)
{

    this.segmentSelectorAddress = tssSegmentSelectorAddress;
    this.isPresent = isPresent;
    this.gateDescriptorType = GateDescriptorType::TaskGate32Bit;
    this.descriptorPrivilegeLevel = DescriptorPrivilegeLevel::Ring0;

}

TaskGate::~TaskGate()
{



}