
#ifndef __DESCRIPTOR_PRIVILEGE_LEVEL_H
#define __DESCRIPTOR_PRIVILEGE_LEVEL_H

    // Represents the Interrupt Descriptor Table (IDT) Descriptor Privilege Levels allowed for Gate Descriptors.
    enum DescriptorPrivilegeLevel {
        
        // Kernel Space Ring - This is the privilege level that Kernel-space code runs, such as handling interrupts, direct hardware access, etc.
        Ring0,
        
        // System Services Ring
        // DOCUMENTATION: Need better documentation on this Ring
        Ring1,  
        
        // System Services Ring
        // DOCUMENTATION: Need better documentation on this Ring
        Ring2,

        // App / User Ring - This is the privilege level that normal User-space applications run, such as Desktop Apps, Games, Web Services, etc.
        Ring3

    };

#endif
