#include "UNIT_4RELAY.h"



void UNIT_4RELAY::write1Byte(uint8_t address, uint8_t Register_address, uint8_t data)
{
    Wire.beginTransmission(address);
    Wire.write(Register_address);  
    Wire.write(data);
    Wire.endTransmission();

}


uint8_t  UNIT_4RELAY::read1Byte(uint8_t address, uint8_t Register_address)
{
    Wire.beginTransmission(address);   // Initialize the Tx buffer
    Wire.write(Register_address);            // Put slave register address in Tx buffer
    Wire.endTransmission();
    Wire.requestFrom(address, 1);
    uint8_t data = Wire.read();
    return data; 
}



void UNIT_4RELAY::relayALL(bool state)
{
    write1Byte(addr,relay_Reg,state*(0x0f));
}

void UNIT_4RELAY::LED_ALL(bool state)
{
    write1Byte(addr,relay_Reg,state*(0xf0));
}

void UNIT_4RELAY::relayWrite( uint8_t number, bool state )
{
    uint8_t StateFromDevice = read1Byte(addr, relay_Reg);
    if( state == 0 )
    {
        StateFromDevice &= ~( 0x01 << number );
    }
    else
    {
        StateFromDevice |= ( 0x01 << number );
    }
    write1Byte(addr,relay_Reg,StateFromDevice);
}

void UNIT_4RELAY::LEDWrite( uint8_t number, bool state )
{
    uint8_t StateFromDevice = read1Byte(addr, relay_Reg);
    if( state == 0 )
    {
        StateFromDevice &= ~( 0x10 << number );
    }
    else
    {
        StateFromDevice |= ( 0x10 << number );
    }
    write1Byte(addr,0x11,StateFromDevice);
}

void UNIT_4RELAY::switchMode( bool mode )
{
    write1Byte(addr, 0x10 ,mode);
}

void UNIT_4RELAY::Init(bool mode)
{
    write1Byte(addr,mode_Reg,mode);
    write1Byte(addr,relay_Reg,0);
}
