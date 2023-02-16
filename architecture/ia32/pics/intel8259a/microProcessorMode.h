
#ifndef __MICRO_PROCESSOR_MODE_H
#define __MICRO_PROCESSOR_MODE_H

    // Represents the Mode the 8259A runs in depending on the Micro-Processor.
    // The 8259A supports Intel 80/86 and MCS 80/85.
    enum MicroProcessorMode {

        // Micro-processor is an MCS80 or MCS85
        MCS80orMCS85 = 0,

        // Micro-processor is an Intel 8086 or Intel 8080
        Intel8086or8080
        
    };

#endif
