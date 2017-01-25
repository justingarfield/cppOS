
#ifndef __SEGMENT_DESCRIPTOR_H
#define __SEGMENT_DESCRIPTOR_H

    #include "../types.h"

    class SegmentDescriptor
    {

        private:

            // Bits 0-15 of the Limit
            uint16_t limit_lo;

            // Bits 16-19 of the Limit
            uint8_t limit_hi;

            // Bits 0-15 of the Base
            uint16_t base_lo;

            // Bits 16-23 of the Base
            uint8_t base_hi;

            // Bits 24-31 of the Base
            uint8_t base_vhi;
            
            // Access byte (bits 40-47)
            uint8_t access;

            // Flags (bits 52-55)
            uint8_t flags;
            
            
        public:
            SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags);
            ~SegmentDescriptor();
            
            uint32_t Base();
            uint32_t Limit();
            
    } __attribute__((packed));

#endif