# UNIT 4_RELAY Library

4-Relay unit is an integrated 4-way relay module which can be controlled by I2C protocol. The maximum control voltage of each relay is AC-250V/DC-28V, the rated current is 10A and the instantaneous current can hold up to 16A. Each relay can be controlled independently, each on it's own. Each relay has status (LED) indictor as well to show the state of the relay at any given time.
 

## API

**Syntax:**

```cpp
void relayWrite(uint8_t number, bool state);
```

**Description:**

Set the status of the relay corresponding to the number 

**Param:**

|Param | Description |type| 
|:-----: |:-----: |:-----:| 
|number |the number of relay (0~3) |uint8_t| 
|state |the state of relay (1:enable/0:disable)  |bool| 

----------

**Syntax:**

```cpp
void relayALL(bool state);
```

**Description**

Set the status of all relays

**Param**

|Param | Description |type| 
|:-----: |:-----: |:-----:| 
|state|the state of all relays(1:enable/0:disable)|bool|


----------

**Syntax**

```cpp
void LEDWrite(uint8_t number, bool state); 
```

**Description**

Set the status of all LEDs

**Param**

|Param | Description |type| 
|:-----:|:-----:|:-----:|
|state |the state of all LEDs (1:enable/0:disable)  |bool| 

----------

**Syntax**

```cpp
void LED_ALL(bool state);
```

**Description**

Set the status of the LED corresponding to the number 

**Param**

|Param | Description |type| 
|:-----:|:-----:|:-----:|
|number |the number of LED (0~3) |uint8_t| 
|state |the state of LED (1:enable/0:disable)  |bool| 

----------


**Syntax**

```cpp
void switchMode(bool mode);
```

**Description**

Switch the working mode of device

**Param**

|Param | Description |type| 
|:-----: |:-----: |:-----:| 
|mode|working mode(1:Sync/0:Async)|bool|

----------

**Syntax**

```cpp
void Init(bool mode);
```

**Description**

Set the initial state of the device 

**Param**

|Param | Description |type| 
|:-----: |:-----: |:-----:| 
|mode|initial working mode(1:Sync/0:Async)|bool|

## Protocol

Protocol type I2C
I2C Address: 0x26

## Mode control Reg 0x10

|Bit | Desc |R/W| 
|:-----: |:-----: |:-----:| 
|7 |R |R/W| 
|6 |R |R/W| 
|5 |R |R/W| 
|4 |R |R/W| 
|3 |R |R/W|
|2 |R |R/W|
|1 |R |R/W|
|0 |Sync Mode 0:Async 1:Sync|R/W|

## RELAY control Reg 0x11

|Bit | Desc |R/W| 
|:-----: |:-----: |:-----:| 
|7 |LED1 / 1: ON 0:OFF |R/W| 
|6 |LED2 / 1: ON 0:OFF |R/W| 
|5 |LED3 / 1: ON 0:OFF |R/W| 
|4 |LED4 / 1: ON 0:OFF |R/W| 
|3 |RELAY1 / 1: ON 0:OFF	 |R/W|
|2 |RELAY2 / 1: ON 0:OFF	 |R/W|
|1 |RELAY3 / 1: ON 0:OFF	 |R/W|
|0 |RELAY4 / 1: ON 0:OFF	 |R/W|