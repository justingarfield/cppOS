
#ifndef __SEGMENT_DESCRIPTOR_H
#define __SEGMENT_DESCRIPTOR_H

    #include "../types.h"

    class SegmentDescriptor
    {

        private:
            uint16_t limit_lo;
            uint16_t base_lo;
            uint8_t base_hi;
            uint8_t type;
            uint8_t limit_hi;
            uint8_t base_vhi;
            
        public:
            SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type);
            ~SegmentDescriptor();
            
            uint32_t Base();
            uint32_t Limit();
            
    } __attribute__((packed));

#endif