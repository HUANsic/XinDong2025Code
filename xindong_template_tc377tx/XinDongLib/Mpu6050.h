/*
 * mpu6050.h
 *
 *  Created on: 2018楠烇拷1閺堬拷11閺冿拷
 *      Author: TEC
 */

#ifndef _MPU6050_H_
#define _MPU6050_H_

#include "Configuration.h"
#include <I2c/I2c/IfxI2c_I2c.h>
#include <Port/Std/IfxPort.h>
#include <Stm/Std/IfxStm.h>
#include <math.h>

//改这里定义SCL和SDA
//#define SCL &MODULE_P11, 10
//#define SDA &MODULE_P11, 12
extern float mpudata[7];//角速度、加速度数据
extern float mpudata_int[7];//积分数据，代表速度或者角度
#define SCL &MODULE_P13, 1
#define SDA &MODULE_P13, 2

#define MPU6050_SCL_HIGH IfxPort_setPinState(SCL, IfxPort_State_high)
#define MPU6050_SCL_LOW  IfxPort_setPinState(SCL, IfxPort_State_low)

#define MPU6050_SDA_HIGH IfxPort_setPinState(SDA, IfxPort_State_high)
#define MPU6050_SDA_LOW  IfxPort_setPinState(SDA, IfxPort_State_low)

#define MPU6050_SCL_STATE IfxPort_getPinState(SCL)
#define MPU6050_SDA_STATE IfxPort_getPinState(SDA)

#define MPU6050_ID (0xd0)

// define registers of mpu6050
#define        PWR_MGMT_1          0x6B        //电源
#define        SMPLRT_DIV          0x19        //采样频率分频: 0x07
#define        CONFIG              0x1A        //数据设置: 0x06(5Hz)
#define        GYRO_CONFIG         0x1B        //gyro量程:
#define        ACCEL_CONFIG        0x1C        //accelerator data量程: 0x01

#define iic_ctrl1 0x25 //iic slave 0 control register
#define iic_ctrl2 0x26
#define iic_ctrl3 0x27
//initialize 后读取，

#define IIC_LEN 0x2 //length of bytes of the data


#define        ACCEL_XOUT_H        0x3B
#define        ACCEL_XOUT_L        0x3C
#define        ACCEL_YOUT_H        0x3D
#define        ACCEL_YOUT_L        0x3E
#define        ACCEL_ZOUT_H        0x3F
#define        ACCEL_ZOUT_L        0x40

#define        TEMP_OUT_H          0x41
#define        TEMP_OUT_L          0x42

#define        GYRO_XOUT_H         0x43
#define        GYRO_XOUT_L         0x44
#define        GYRO_YOUT_H         0x45
#define        GYRO_YOUT_L         0x46
#define        GYRO_ZOUT_H         0x47
#define        GYRO_ZOUT_L         0x48



typedef struct
{
    float acc_x;
    float acc_y;
    float acc_z;
    float gyro_x;
    float gyro_y;
    float gyro_z;
}MPU6050_data;

typedef struct
{
    float Pitch;
    float Roll;
    float Yaw;
}MPU6050_angle;

extern float mpudata[];
extern float mpudata_int[];
extern float offset_test[];
extern float factor_test[];

//IFX_EXTERN MPU6050_data mpu_data;

IFX_EXTERN MPU6050_angle mpu_angle;

void mpu6050_Init(void);

uint8 mpu6050Start(void);

void mpu6050Stop(void);

void mpu6050_master_sendNACK(void);

uint8 mpu6050_master_waitACK(void);

void mpu6050SendByte(uint8 data);

uint8 mpu6050receiveByte(void);

uint8 mpu6050_write_register(uint8 reg,uint8 data);

//uint8 mpu6050_read_register(uint8 reg);
uint8 mpu6050_read_register(uint8 reg);

void mpu6050_master_sendACK(void);

void mpu6050Configure(void);

sint16 GetData(uint8 reg);

//float MPU6050_Get_Data(unsigned id);
void MPU6050_Get_Data(void);

void delay_ms(uint32 time);

void delay_us(uint32 time);

void MPU6050_Calibrate(void);

void MPU6050_int(float dt);


#endif




