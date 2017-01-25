
#include "intel8259PIC.h"

Intel8259PICManager::Intel8259PICManager()
{

}

Intel8259PICManager::~Intel8259PICManager()
{
    
}

Intel8259PICManager::IsICW4Needed()
{
    
    return useSpecialFullyNestMode;

}

Intel8259PICManager::RunInitializationSequence()
{

    // The 5th bit is always set to 1, so start with 16
    uint8_t icw1 = 16;
    
    // If the ICW4 needed
    if (IsICW4Needed())
        icw1 + 1;

    // If there is more than a one Intel 8259 PIC in the system, we need
    // to enable Cascading.
    // TODO: Verify if you would ever use multiple 8259 PICs individiually somehow. I don't think you can from a wiring standpoint.
    if (systemPICCount > 1)
        icw1 + 2;

    // Call Address Interval (ADI) is ignored for Intel 8086/8080.
    if (microProcessorMode == MicroProcessorMode::MCS80orMCS85 && use4ByteCallAddressInterval)
        icw1 + 4;

    // If level-triggered mode is enabled, then tell the PICs here so that they
    // know how to behave together.
    if (useLevelTriggeredMode)
        icw1 + 8;

}