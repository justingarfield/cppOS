#ifndef __INTEL_8259_PIC_MANAGER_H
#define __INTEL_8259_PIC_MANAGER_H

    #include "microProcessorMode.h"
    #include "../types.h"

    // The Intel 8259 PIC Manager is used to orchestrate the overall initialization
    // and Configuration of one-or-more Intel 8259 PICs in a system. Since there can
    // be multiple PICs, something is required to be the gate-keeper to make sure
    // they're all playing nice together.
    class Intel8259PICManager {
        
        private:

            // How many PICs are available in the system
            uint8_t systemPICCount;
            
            bool useSpecialFullyNestMode;

            MicroProcessorMode microProcessorMode;

            bool use4ByteCallAddressInterval;

            bool useLevelTriggeredMode;
            
        public:

            Intel8259PICManager();
            ~Intel8259PICManager();

            // Returns a value indicating if Initiailzation Command Word 4 is needed.
            // This is used during ICW1.
            bool IsICW4Needed();
            
            // Tells the PIC Manager to run through the steps required to initialize
            // one-or-more Intel 8259 PICs.
            void RunInitializationSequence();

    };

#endif