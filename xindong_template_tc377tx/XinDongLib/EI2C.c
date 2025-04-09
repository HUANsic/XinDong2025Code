#include "EI2C.h"

/*
 * 	Use shifted address!!! e.g. 0xA0
 */

//void EI2C_SCL_Rise(void);
//void EI2C_SCL_Fall(void);
//void EI2C_SDA_High(void);
//void EI2C_SDA_Low(void);
//boolean EI2C_SDA_State(void);
//boolean EI2C_SCL_State(void);
//void EI2C_Hold(void);
//void EI2C_Start(void);
//void EI2C_Restart(void);
//void EI2C_Stop(void);
//void EI2C_SendBit(boolean bit);
//boolean EI2C_ReadBit(void);
//boolean EI2C_SendByte(uint8 byte);
//uint8 EI2C_ReadByte(boolean ack);

uint8 initialized = 0;

inline void EI2C_SCL_Rise() {
	IfxPort_setPinState(SCL, IfxPort_State_high);
}

inline void EI2C_SCL_Fall() {
	IfxPort_setPinState(SCL, IfxPort_State_low);
}

inline void EI2C_SDA_High() {
	IfxPort_setPinState(SDA, IfxPort_State_high);
}

inline void EI2C_SDA_Low() {
	IfxPort_setPinState(SDA, IfxPort_State_low);
}

inline boolean EI2C_SDA_State() {
	return IfxPort_getPinState(SDA);
}

inline boolean EI2C_SCL_State() {
	return IfxPort_getPinState(SCL);
}

void EI2C_Hold() {
	uint16 i;
	// for MPU6050, max SCL freq is 400kHz, so time step must be larger than 625ns
	// with 200MHz CPU frequency, 625ns is 125 instruction cycles, so 25 for cycles
	// increase if your module can't handle it
	for (i = 0; i < 100; i++)
		__asm("NOP");
	(void) i;
}

/*          ___         ___ ___
 *  SCL        |       |
 *             |___ ___|
 *
 *          ___ ___ ___ ___
 *  SDA            |       |
 *          ___ ___|       |___
 */
void EI2C_Start() {
	/// can not assume line is in proper state: SDA = SCL = PullUp
	EI2C_Hold();
	EI2C_SCL_Fall();
	EI2C_Hold();
	EI2C_SDA_High();
	EI2C_Hold();
	EI2C_SCL_Rise();
	EI2C_Hold();
	EI2C_SDA_Low();
	EI2C_Hold();
}

/*          ___         ___ ___ ___ ___
 *  SCL        |       |
 *             |___ ___|
 *
 *          ___ ___         ___ ___
 *  SDA            |       |       |
 *          ___ ___|___ ___|       |___
 */
void EI2C_Restart() {
	/// can not assume line is in proper state: SDA = SCL = PullUp
	EI2C_Hold();
	EI2C_SCL_Fall();
	EI2C_Hold();
	EI2C_SDA_Low();
	EI2C_Hold();
	EI2C_SCL_Rise();
	EI2C_Hold();
	EI2C_SDA_High();
	EI2C_Hold();
	EI2C_Hold();
	EI2C_SDA_Low();
	EI2C_Hold();
}

/*          ___         ___ ___
 *  SCL        |       |
 *             |___ ___|
 *
 *          ___ ___         ___
 *  SDA            |       |
 *          ___ ___|___ ___|
 */
void EI2C_Stop() {
	// can not assume line is in proper state: SDA = SCL = PullUp
	EI2C_Hold();
	EI2C_SCL_Fall();
	EI2C_Hold();
	EI2C_SDA_Low();
	EI2C_Hold();
	EI2C_SCL_Rise();
	EI2C_Hold();
	EI2C_SDA_High();
	EI2C_Hold();
}

/*          ___         ___
 *  SCL        |       |
 *             |___ ___|
 *
 *          ___ ___ ___ ___
 *  SDA            |
 *          ___ ___|___ ___
 */
void EI2C_SendBit(boolean bit) {
	EI2C_Hold();
	EI2C_SCL_Fall();
	EI2C_Hold();
	if (bit)
		EI2C_SDA_High();
	else
		EI2C_SDA_Low();
	EI2C_Hold();
	EI2C_SCL_Rise();
	EI2C_Hold();
}

/*          ___         ___
 *  SCL        |       |
 *             |___ ___|
 *
 *          ___ ___ ___ ___
 *  SDA            |
 *          ___ ___|___ ___
 *                     ^
 *                Sample Here
 */
boolean EI2C_ReadBit() {
	boolean bit;
	EI2C_Hold();
	EI2C_SCL_Fall();
	EI2C_Hold();
	EI2C_SDA_High();    // release line
	EI2C_Hold();
	EI2C_SCL_Rise();
	while (!EI2C_SCL_State())
		;       // enable clock stretching
	bit = EI2C_SDA_State();
	EI2C_Hold();
	return bit;
}

/*           ___  ___  ___  ___  ___  ___  ___  ___  ___
 *          |    |    |    |    |    |    |    |    |
 *  I2C     | T  | T  | T  | T  | T  | T  | T  | T  | R
 *          |___ |___ |___ |___ |___ |___ |___ |___ |___
 */
boolean EI2C_SendByte(uint8 byte) {
	uint8 i;
	for (i = 0; i < 8; i++) {
		EI2C_SendBit(byte & 0x80);
		byte <<= 1;
	}
	return EI2C_ReadBit();
}

/*           ___  ___  ___  ___  ___  ___  ___  ___  ___
 *          |    |    |    |    |    |    |    |    |
 *  I2C     | R  | R  | R  | R  | R  | R  | R  | R  | T
 *          |___ |___ |___ |___ |___ |___ |___ |___ |___
 */
uint8 EI2C_ReadByte(boolean ack) {
	uint8 i, retVal = 0;
	for (i = 0; i < 8; i++) {
		retVal <<= 1;
		retVal |= EI2C_ReadBit() ? 1 : 0;
	}
	EI2C_SendBit(!ack);
	return retVal;
}

void HAL_EI2C_Init() {
	if (!initialized) {
		IfxPort_setPinMode(SCL, IfxPort_Mode_outputOpenDrainGeneral);
		IfxPort_setPinMode(SDA, IfxPort_Mode_outputOpenDrainGeneral);
		EI2C_SCL_Rise();
		EI2C_SDA_High();
		initialized = 1;
	}
}

/*           ___  ____ ___  ____ ___  ____ ____ ___  ____ ___  ____ ___  ___
 *          |    |    |    |    |    |    |    |    |    |    |    |    |
 *  Master  | S  |AD+W|    | RA |    | S  |AD+R|    |    |ACK |    |NACK| P
 *          |___ |____|___ |____|___ |____|____|___ |____|___ |____|___ |___
 *          |    |    |    |    |    |    |    |    |    |    |    |    |
 *  Slave   |    |    |ACK |    |ACK |    |    |ACK | D  |    | D  |    |
 *          |___ |____|___ |____|___ |____|____|___ |____|___ |____|___ |___
 */
EI2C_Status HAL_EI2C_Mem_Read(uint8 slaveAddress, uint8 MemAddress, uint8 *pData, uint16 size) {
	EI2C_Start();
	if (EI2C_SendByte(slaveAddress))
		return EI2C_NO_DEVICE;       // no device
	if (EI2C_SendByte(MemAddress))
		return EI2C_INVALID_ADDRESS;       // invalid address
	EI2C_Restart();
	if (EI2C_SendByte(slaveAddress | 1))
		return EI2C_NO_DEVICE;       // no device
	while (--size) {        // keep the last one
		*pData = EI2C_ReadByte(1);
		pData++;
	}
	*pData = EI2C_ReadByte(0);
	EI2C_Stop();
	return EI2C_OK;
}

/*           ___  ____ ___  ____ ___  ____ ___  ____ ___  ___
 *          |    |    |    |    |    |    |    |    |    |
 *  Master  | S  |AD+W|    | RA |    | D  |    | D  |    | P
 *          |___ |____|___ |____|___ |____|___ |____|___ |___
 *          |    |    |    |    |    |    |    |    |    |
 *  Slave   |    |    |ACK |    |ACK |    |ACK |    |ACK |
 *          |___ |____|___ |____|___ |____|___ |____|___ |___
 */
EI2C_Status HAL_EI2C_Mem_Write(uint8 slaveAddress, uint8 MemAddress, uint8 *pData, uint16 size) {
	EI2C_Start();
	if (EI2C_SendByte(slaveAddress))
		return EI2C_NO_DEVICE;       // no device
	if (EI2C_SendByte(MemAddress))
		return EI2C_INVALID_ADDRESS;       // invalid address
	while (size--) {
		if (EI2C_SendByte(*pData))
			return EI2C_ACK_MISSING;   // acknowledge missing
		pData++;
	}
	EI2C_Stop();
	return EI2C_OK;
}

EI2C_Status HAL_EI2C_Call(uint8 slaveAddress) {
	EI2C_Start();
	if (EI2C_SendByte(slaveAddress))
		return EI2C_NO_DEVICE;       // no device
	EI2C_Stop();
	return EI2C_OK;
}
