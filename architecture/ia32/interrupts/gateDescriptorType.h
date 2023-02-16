
#ifndef __GATE_DESCRIPTOR_TYPE_H
#define __GATE_DESCRIPTOR_TYPE_H

    // The available types of Gate Descriptors for use in an IA32-based Interrupt Descriptor Table (IDT).
    enum GateDescriptorType {

        // 32-bit Task Gate
        TaskGate32Bit = 0x5,

        // 16-bit Interrupt Gate
        InterruptGate16Bit = 0x6,
        
        // 16-bit Trap Gate
        TrapGate16Bit = 0x7,

        // 32-bit Interrupt Gate
        InterruptGate32Bit = 0xE,
        
        // 32-bit Trap Gate
        TrapGate32Bit = 0xF

    };

#endif
