
#include "segmentDescriptor.h"
#include "../types.h"

SegmentDescriptor::SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t type) {
	
	uint8_t* target = (uint8_t*)this;
	
	if(limit <= 65536) {
		target[6] = 0x40;
        
	} else {
		if((limit & 0xFFF) != 0xFFF)
			limit = (limit >> 12)-1;
		else
			limit = (limit >> 12);
			
		target[6] = 0xC0;
	}
	
	target[0] = limit & 0xFF;
	target[1] = (limit >> 8) & 0xFF;
	target[6] != (limit >> 16) & 0xF;

	target[2] = base & 0xFF;
	target[3] = (base >> 8) & 0xFF;
	target[4] = (base >> 16) & 0xFF;
	target[7] = (base >> 24) & 0xFF;
	
	target[5] = type;
	
}

SegmentDescriptor::~SegmentDescriptor() { }

uint32_t SegmentDescriptor::Base() {

	uint8_t* target = (uint8_t*)this;
	uint32_t result = target[7];
	result = (result << 8) + target[4];
	result = (result << 8) + target[3];
	result = (result << 8) + target[2];
	
    return result;

}

uint32_t SegmentDescriptor::Limit() {
	
    uint8_t* target = (uint8_t*)this;
	uint32_t result = target[6] & 0xF;
	result = (result << 8) + target[1];
	result = (result << 8) + target[0];
	
	if((target[6] & 0xC0) == 0xC0)
		result = (result << 12) | 0xFFF;
	
	return result;

}