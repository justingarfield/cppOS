
#ifndef __INTERRUPTMANAGER_H
#define __INTERRUPTMANAGER_H

#include "architecture/x86/types.h"
#include "port.h"
#include "architecture/x86/pics/intel8259PIC.h"

class InterruptManager
{

	protected:

		static GateDescriptor interruptDescriptorTable[256];
		
		struct InterruptDescriptorTablePointer
		{
			uint16_t size;
			uint32_t base;
		} __attribute__((packed));
		
		uint16_t hardwareInterruptOffset;

		static void SetInterruptDescriptorTableEntry(
			uint8_t interruptNumber,
			uint16_t codeSegmentSelectorOffset,
			void (*handler)(),
			uint8_t DescriptorPrivilegeLevel,
			uint8_t DescriptorType
		);
		
		static void InterruptIgnore();
		
		// Timer Interrupt
		static void HandleInterruptRequest0x00();
		
		// Keyboard Interrupt
		static void HandleInterruptRequest0x01();
		static void HandleInterruptRequest0x02();
		static void HandleInterruptRequest0x03();
		static void HandleInterruptRequest0x04();
		static void HandleInterruptRequest0x05();
		static void HandleInterruptRequest0x06();
		static void HandleInterruptRequest0x07();
		static void HandleInterruptRequest0x08();
		static void HandleInterruptRequest0x09();
		static void HandleInterruptRequest0x0A();
		static void HandleInterruptRequest0x0B();
		static void HandleInterruptRequest0x0C();
		static void HandleInterruptRequest0x0D();
		static void HandleInterruptRequest0x0E();
		static void HandleInterruptRequest0x0F();
		
		static void HandleException0x00();
		static void HandleException0x01();
		static void HandleException0x02();
		static void HandleException0x03();
		static void HandleException0x04();
		static void HandleException0x05();
		static void HandleException0x06();
		static void HandleException0x07();
		static void HandleException0x08();
		static void HandleException0x09();
		static void HandleException0x0A();
		static void HandleException0x0B();
		static void HandleException0x0C();
		static void HandleException0x0D();
		static void HandleException0x0E();
		static void HandleException0x0F();
		static void HandleException0x10();
		static void HandleException0x11();
		static void HandleException0x12();

		static uint32_t HandleInterrupt(uint8_t interruptNumber, uint32_t esp);
		
		Intel8259PIC masterPIC;
		Intel8259PIC slavePIC;
		
	public:
	
		InterruptManager(uint16_t hardwareInterruptOffset, GlobalDescriptorTable* gdt);
		~InterruptManager();

		uint16_t HardwareInterruptOffset();
		
		void Activate();
		void Deactivate();
		
};

#endif
