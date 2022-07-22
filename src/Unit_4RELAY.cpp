#include "UNIT_4RELAY.h"

void UNIT_4RELAY::Init(bool mode) {
    write1Byte(DEVICE_I2C_ADDR, mode_Reg, mode);
    write1Byte(DEVICE_I2C_ADDR, relay_Reg, 0);
}

void UNIT_4RELAY::begin(TwoWire *wire, uint8_t sda, uint8_t scl,
                        uint32_t freq) {
    _wire = wire;
    _sda  = sda;
    _scl  = scl;
    _freq = freq;
    _wire->begin(DEVICE_I2C_ADDR, _sda, _scl, _freq);
}

void UNIT_4RELAY::write1Byte(uint8_t address, uint8_t Register_address,
                             uint8_t data) {
    _wire->beginTransmission(address);
    _wire->write(Register_address);
    _wire->write(data);
    _wire->endTransmission();
}

uint8_t UNIT_4RELAY::read1Byte(uint8_t address, uint8_t Register_address) {
    _wire->beginTransmission(address);  // Initialize the Tx buffer
    _wire->write(Register_address);  // Put slave register address in Tx buffer
    _wire->endTransmission();
    _wire->requestFrom(address, uint8_t(1));
    uint8_t data = _wire->read();
    return data;
}

void UNIT_4RELAY::relayALL(bool state) {
    write1Byte(DEVICE_I2C_ADDR, relay_Reg, state * (0x0f));
}

void UNIT_4RELAY::LED_ALL(bool state) {
    write1Byte(DEVICE_I2C_ADDR, relay_Reg, state * (0xf0));
}

void UNIT_4RELAY::relayWrite(uint8_t number, bool state) {
    uint8_t StateFromDevice = read1Byte(DEVICE_I2C_ADDR, relay_Reg);
    if (state == 0) {
        StateFromDevice &= ~(0x01 << number);
    } else {
        StateFromDevice |= (0x01 << number);
    }
    write1Byte(DEVICE_I2C_ADDR, relay_Reg, StateFromDevice);
}

void UNIT_4RELAY::LEDWrite(uint8_t number, bool state) {
    uint8_t StateFromDevice = read1Byte(DEVICE_I2C_ADDR, relay_Reg);
    if (state == 0) {
        StateFromDevice &= ~(0x10 << number);
    } else {
        StateFromDevice |= (0x10 << number);
    }
    write1Byte(DEVICE_I2C_ADDR, 0x11, StateFromDevice);
}

void UNIT_4RELAY::switchMode(bool mode) {
    write1Byte(DEVICE_I2C_ADDR, 0x10, mode);
}
