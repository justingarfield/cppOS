
#ifndef __GATE_DESCRIPTOR_TYPE_H
#define __GATE_DESCRIPTOR_TYPE_H

    // The available types of Gate Descriptors for use in IA32
    enum GateDescriptorType {
        TaskGate32Bit = 0x5,
        InterruptGate16Bit = 0x6,
        TrapGate16Bit = 0x7,
        InterruptGate32Bit = 0xE,
        TrapGate32Bit = 0xF
    };

#endif
