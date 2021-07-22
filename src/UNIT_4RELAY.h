#ifndef _UNIT_4RELAY_H_
#define _UNIT_4RELAY_H_
        
#include <Wire.h>

#define addr 0X26
#define mode_Reg 0X10
#define relay_Reg 0X11


class UNIT_4RELAY
{
    private:
        void write1Byte(uint8_t address, uint8_t register_address, uint8_t data);
        uint8_t  read1Byte(uint8_t address, uint8_t register_address);
    public: 
        void relayWrite(uint8_t number, bool state);
        void relayALL(bool state);
         
        void LEDWrite(uint8_t number, bool state); 
        void LED_ALL(bool state);

        void switchMode(bool mode);
        void Init(bool mode);

};
#endif
