#ifndef _UNIT_4RELAY_H_
#define _UNIT_4RELAY_H_

#include <Wire.h>

#include "pins_arduino.h"

#define DEVICE_I2C_ADDR 0X26
#define mode_Reg        0X10
#define relay_Reg       0X11

class UNIT_4RELAY {
   private:
    TwoWire *_wire;
    uint8_t _sda;
    uint8_t _scl;
    uint32_t _freq;
    void write1Byte(uint8_t address, uint8_t register_address, uint8_t data);
    uint8_t read1Byte(uint8_t address, uint8_t register_address);

   public:
    void begin(TwoWire *wire = &Wire, uint8_t sda = SDA, uint8_t scl = SCL,
               uint32_t freq = 4000000UL);
    void Init(bool mode);

    void relayWrite(uint8_t number, bool state);
    void relayALL(bool state);

    void LEDWrite(uint8_t number, bool state);
    void LED_ALL(bool state);

    void switchMode(bool mode);
};

#endif
