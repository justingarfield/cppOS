
#ifndef __DESCRIPTOR_PRIVILEGE_LEVEL_H
#define __DESCRIPTOR_PRIVILEGE_LEVEL_H

    // Represents the IDT Descriptor Privilege Levels allowed for Gate Descriptors.
    enum DescriptorPrivilegeLevel {
        Ring0,
        Ring1,
        Ring2,
        Ring3
    };

#endif
