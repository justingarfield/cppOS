#ifndef __INTEL_8259A_MANAGER_H
#define __INTEL_8259A_MANAGER_H

    #include "intel8259a.h"
    #include "microProcessorMode.h"
    #include "../../../types.h"

    // The Intel 8259A PIC Manager is used to orchestrate the overall initialization
    // and Configuration of one-or-more Intel 8259A PICs in a system. Since there can
    // be multiple PICs, something is required to be the gate-keeper to make sure
    // they're all playing nice together.
    class Intel8259AManager {
        
        private:
            Intel8259A masterPIC;
            Intel8259A slavePIC;
            uint16_t hardwareInterruptOffset;
            
        public:

            // Instansiates a new Intel 8259A PIC Manager that can be used to communicate with,
            // initialize, and configure Intel 8259A PICs in a system. 
            Intel8259AManager(uint16_t hardwareInterruptOffset);

            // Tell the Interrupt Manager to inform the PICs to start forwarding Interrupt Requests.
            void StartInterrupts();

            // Tell the Interrupt Manager to inform the PICs to stop forwarding Interrupt Requests.
            void StopInterrupts();

            // Initalize / Configure the system PICs with Default Settings.
            // Default Settings are those commonly found in most IA32 systems and work with most Hyper-Visors.
            void InitializeWithDefaultSettings();

    };

#endif