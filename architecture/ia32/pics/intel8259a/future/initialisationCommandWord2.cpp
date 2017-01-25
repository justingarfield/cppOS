
InitialisationCommandWord2::InitialisationCommandWord2(uint8_t offset)
{
    this.offset = offset;

    this.icwValue = 0x00;
    this.icwValue += offset;

}

~InitialisationCommandWord2()
{

}