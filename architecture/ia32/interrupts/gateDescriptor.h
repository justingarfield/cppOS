
#ifndef __GATE_DESCRIPTOR_H
#define __GATE_DESCRIPTOR_H

#include "descriptorPrivilegeLevel.h";
#include "gateDescriptorType.h";

// Gate Descriptors are used in the Interrupt Descriptor Table (IDT) 
class GateDescriptor
{


    protected:

        // Byte 6 (bits 40-47) are used to set type and access of descriptor Gate
        uint8_t access;

        uint16_t segmentSelectorAddress;

        // The level of privilege the Descriptor Gate has (0 = Kernel Mode, 3 = User / App Space)
        DescriptorPrivilegeLevel descriptorPrivilegeLevel;

        // Is the Interrupt Gate Present or is it an empty filler?
        // TODO: Determine if this should even be exposed to a consumer. Right now the InterruptManager
        //      could just easily populate an IDT's empty members or just simply not attempt to populate
        //      a full IDT...May need to start with padded empties at first if it turns out to be hard to
        //      work with a non-256 full IDT.
        bool isPresent;

        // What type of Gate Descriptor is it? (Trap, Interrupt, Task)
        GateDescriptorType gateDescriptorType;
    

    private:

        GateDescriptor(uint16_t segmentSelectorAddress, bool isPresent, GateDescriptorType gateDescriptorType);
        ~GateDescriptor();


};

#endif
