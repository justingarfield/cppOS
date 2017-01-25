
InitialisationCommandWord1::InitialisationCommandWord1(bool icw4Needed, bool singlePICSystem, bool fourByteCallAddressInterval, bool operatingInLevelInterruptMode)
{

    // Map Values
    this.icw4Needed = icw4Needed;
    this.singlePICSystem = singlePICSystem;
    this.fourByteCallAddressInterval = fourByteCallAddressInterval;
    this.operatingInLevelInterruptMode = operatingInLevelInterruptMode;

    this.icwValue = 0x00;
    this.icwValue += this.icw4Needed ? 0x01 : 0x00;
    this.icwValue += !this.singlePICSystem ? 0x02 : 0x00;
    this.icwValue += this.fourByteCallAddressInterval ? 0x04 : 0x00;
    this.icwValue += this.operatingInLevelInterruptMode ? 0x08 : 0x00;
    // TODO: Deal with MCS80 environments (extra bits)

}

InitialisationCommandWord1::~InitialisationCommandWord1()
{

}