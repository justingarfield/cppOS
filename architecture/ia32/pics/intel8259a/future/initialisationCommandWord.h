/*
 * Defines the base for an Intel 8259 Programmable Interrupt 
 * Controller (PIC) Initialisation Command Word (ICW).
 *
 */

// Make sure we only define this once
#ifndef __8259_PIC_ICW_H
#define __8259_PIC_ICW_H

class InitialisationCommandWord
{
    
    protected:
        char icwValue;

}

#endif