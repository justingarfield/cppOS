
InitialisationCommandWord3::InitialisationCommandWord3(bool interrupt0HasSlave, bool interrupt1HasSlave, bool interrupt2HasSlave, bool interrupt3HasSlave, 
                                    bool interrupt4HasSlave, bool interrupt5HasSlave, bool interrupt6HasSlave, bool interrupt7HasSlave)
{
    
    // Map Interrupt Slaves
    this.interrupt0HasSlave = interrupt0HasSlave;
    this.interrupt1HasSlave = interrupt1HasSlave;
    this.interrupt2HasSlave = interrupt2HasSlave;
    this.interrupt3HasSlave = interrupt3HasSlave;
    this.interrupt4HasSlave = interrupt4HasSlave;
    this.interrupt5HasSlave = interrupt5HasSlave;
    this.interrupt6HasSlave = interrupt6HasSlave;
    this.interrupt7HasSlave = interrupt7HasSlave;

    this.icwValue = 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x01 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x02 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x04 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x08 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x10 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x20 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x40 : 0x00;
    this.icwValue += this.interrupt0HasSlave ? 0x80 : 0x00;

}

// Constructor used when working with a Slave PIC.
InitialisationCommandWord3::InitialisationCommandWord3(uint8_t cascadeIdentity)
{

    this.cascadeIdentity = cascadeIdentity;

    this.icwValue = 0x00;
    this.icwValue += this.cascadeIdentity;
    
}

InitialisationCommandWord3::~InitialisationCommandWord3()
{

}