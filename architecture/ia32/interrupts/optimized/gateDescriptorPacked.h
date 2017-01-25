
#ifndef __GATE_DESCRIPTOR_PACKED_H
#define __GATE_DESCRIPTOR_PACKED_H

// Gate Descriptors are used in the Interrupt Descriptor Table (IDT) 
struct GateDescriptorPacked
{

    // First 2-Bytes (bits 0-15) of the Gate Descriptor Offset
    uint16_t handlerAddressLowBits;

    // Bytes 3 and 4 (bits 16-31) are the Segment Selector of the Gate Descriptor
    uint16_t segmentSelector;

    // Byte 5 (bits 32-39) are Reserved and always 0
    uint8_t reserved;

    // Byte 6 (bits 40-47) are used to set type and access of descriptor Gate
    uint8_t access;

    // Upper 2-Bytes (bits 48-63) of the Gate Descriptor Offset
    uint16_t handlerAddressHighBits;
    
} __attribute__((packed)); // ensures that packing doesn't occur at compile time and screw with alignment since we need this to be laid-out exactly in memory

#endif
