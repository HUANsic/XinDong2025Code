/**********************************************************************************************************************
 * Author: Yikai Huang
 * Description:
 * 
 * Version:
 *********************************************************************************************************************/

#ifndef XINDONGLIB_IMU_H_
#define XINDONGLIB_IMU_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "XinDong_Config.h"
#include "EI2C.h"
#include <math.h>

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
extern float mpudata[7];//���ٶȡ����ٶ�����
extern float mpudata_int[7];//�������ݣ������ٶȻ��߽Ƕ�

#define MPU6050_ID (0xd0)

// define registers of mpu6050
#define        PWR_MGMT_1          0x6B        //��Դ
#define        SMPLRT_DIV          0x19        //����Ƶ�ʷ�Ƶ: 0x07
#define        CONFIG              0x1A        //��������: 0x06(5Hz)
#define        GYRO_CONFIG         0x1B        //gyro����:
#define        ACCEL_CONFIG        0x1C        //accelerator data����: 0x01

#define iic_ctrl1 0x25 //iic slave 0 control register
#define iic_ctrl2 0x26
#define iic_ctrl3 0x27
//initialize ���ȡ��

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

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
extern float mpudata[];
extern float mpudata_int[];
extern float offset_test[];
extern float factor_test[];

//IFX_EXTERN MPU6050_data mpu_data;

IFX_EXTERN MPU6050_angle mpu_angle;

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
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

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void mpu6050_Init(void);

// void mpu6050Configure(void);

void mpu6050_write_register(uint8 reg,uint8 data);

// sint16 GetData(uint8 reg);

//float MPU6050_Get_Data(unsigned id);
void MPU6050_Get_Data(void);

void MPU6050_Calibrate(void);

void MPU6050_int(float dt);

#endif /* XINDONGLIB_IMU_H_ */
