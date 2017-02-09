
#ifndef __GLOBAL_DESCRIPTOR_TABLE_POINTER_H
#define __GLOBAL_DESCRIPTOR_TABLE_POINTER_H

    // The Global Descriptor Table Pointer is used when calling the LGDT assembly instruction to load the GDT. 
    struct GlobalDescriptorTablePointerPacked
    {
        
        uint16_t size;

        uint32_t offset;

    } __attribute__((packed)); // ensures that packing doesn't occur at compile time and screw with alignment since we need this to be laid-out exactly in memory

#endif
