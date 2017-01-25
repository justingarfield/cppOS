/*
 * 2.4.1 Global Descriptor Table Register (GDTR)
The GDTR register holds the base address (32 bits in protected mode; 64 bits in IA-32e mode) and the 16-bit table
limit for the GDT. The base address specifies the linear address of byte 0 of the GDT; the table limit specifies the
number of bytes in the table.
The LGDT and SGDT instructions load and store the GDTR register, respectively. On power up or reset of the
processor, the base address is set to the default value of 0 and the limit is set to 0FFFFH. A new base address must
be loaded into the GDTR as part of the processor initialization process for protected-mode operation.
See also: Section 3.5.1, “Segment Descriptor Tables.”
 */

#ifndef __GLOBAL_DESCRIPTOR_TABLE_H
#define __GLOBAL_DESCRIPTOR_TABLE_H

    #include "segmentDescriptor.h"

    class GlobalDescriptorTable
    {

        private:
            SegmentDescriptor nullSegmentSelector;
            SegmentDescriptor unusedSegmentSelector;
            SegmentDescriptor codeSegmentSelector;
            SegmentDescriptor dataSegmentSelector;
            
        public:
            GlobalDescriptorTable();
            ~GlobalDescriptorTable();

            uint16_t CodeSegmentSelector();
            uint16_t DataSegmentSelector();

    };

#endif