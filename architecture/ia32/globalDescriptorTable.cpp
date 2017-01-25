
#include "globalDescriptorTable.h"
#include "../types.h"

// Constructor
GlobalDescriptorTable::GlobalDescriptorTable()
	: nullSegmentSelector(0, 0, 0),
        unusedSegmentSelector(0, 0, 0),
        codeSegmentSelector(0, 64*1024*1024, 0x9A),
        dataSegmentSelector(0, 64*1024*1024, 0x92)
{
	
	uint32_t gdtProvisioner[2];
	gdtProvisioner[0] = (uint32_t)this; // GDT 32-bit Linear Base Address
	gdtProvisioner[1] = sizeof(GlobalDescriptorTable) << 16; // GDT 16-bit Table Limit
	
	// "p" enforces a memory address contraint to the input
	asm volatile("lgdt (%0)" : : "p" ((uint8_t *)gdtProvisioner + 2));
	
}

// Destructor
GlobalDescriptorTable::~GlobalDescriptorTable() { }

uint16_t GlobalDescriptorTable::DataSegmentSelector()
{
    return (uint8_t*)&dataSegmentSelector - (uint8_t*)this;
}

uint16_t GlobalDescriptorTable::CodeSegmentSelector()
{
    return (uint8_t*)&codeSegmentSelector - (uint8_t*)this;
}