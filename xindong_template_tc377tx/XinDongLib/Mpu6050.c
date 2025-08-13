//mpu6050.c

//https://www.cnblogs.com/dchipnau/p/5310088.html(姿态融合)

#include "Mpu6050.h"
#include "ServeSource.h"
#include "Hardware.h"
//mpu6050calibration

float mpudata[7]={0,0,0,0,0,0,0};//角速度、加速度数据
float mpudata_int[7]={0,0,0,0,0,0,0};//积分数据，代表速度或者角度

float offset[7]={0,0,0,0,0,0,-13};//标定得到的offset，默认为0
float factor[7]={0,1,1,1,1,1,17};//标定得到的factor，默认为1

float offset_test[7]={0,0,0,0,0,0,0};
float factor_test[7]={0,0,0,0,0,0,0};

void mpu6050_Init(void)
{
    //port configuration
    IfxPort_setPinMode(SCL, IfxPort_Mode_outputOpenDrainGeneral);
    IfxPort_setPinMode(SDA, IfxPort_Mode_outputOpenDrainGeneral);
    //mpu6050 configuration
    mpu6050Configure();
}

void mpu6050Configure(void)
{
    delay_ms(100);
    mpu6050_write_register(PWR_MGMT_1, 0x00);
    mpu6050_write_register(SMPLRT_DIV, 0x07);
    mpu6050_write_register(CONFIG, 0x06);
    mpu6050_write_register(GYRO_CONFIG, 0x18);
    mpu6050_write_register(ACCEL_CONFIG, 0x01);
}//mpu6050 configuration

// i2c start singal
uint8 mpu6050Start(void)
{
    MPU6050_SDA_HIGH;
    delay_us(1);
    MPU6050_SCL_HIGH;
    delay_us(1);
    if(!MPU6050_SDA_STATE) {
        return 0;
    }
    MPU6050_SDA_LOW;
    delay_us(1);
    if(MPU6050_SDA_STATE) {
        return 0;
    }
    MPU6050_SCL_LOW;
    return 1;
}

// i2c stop signal
void mpu6050Stop(void)
{

    MPU6050_SCL_LOW;
    delay_us(1);
    MPU6050_SDA_LOW;
    delay_us(1);
    MPU6050_SCL_HIGH;
    delay_us(1);
    MPU6050_SDA_HIGH;
    delay_us(1);
}

void mpu6050_master_sendNACK(void)
{
    delay_us(1);
    MPU6050_SCL_LOW;
    delay_us(1);
    MPU6050_SDA_HIGH;//高电平非应答
    delay_us(1);
    MPU6050_SCL_HIGH;
    delay_us(1);
    MPU6050_SCL_LOW;
    delay_us(1);
}

void mpu6050_master_sendACK(void)
{
    delay_us(1);
    MPU6050_SCL_LOW;
    delay_us(1);
    MPU6050_SDA_LOW;//低电平应答
    delay_us(1);
    MPU6050_SCL_HIGH;
    delay_us(1);
    MPU6050_SCL_LOW;
    delay_us(1);
}

uint8 mpu6050_master_waitACK(void)
{
    MPU6050_SCL_LOW;
    MPU6050_SDA_HIGH;
    delay_us(1);
    MPU6050_SCL_HIGH;
    delay_us(1);
    if (MPU6050_SDA_STATE)//非应答
    {
        MPU6050_SCL_LOW;
        delay_us(1);
        return 0;
    }
    //应答
    MPU6050_SCL_LOW;
    delay_us(1);
    return 1;
}

void mpu6050SendByte(uint8 data)
{
    uint8 i;
    MPU6050_SCL_LOW;
    for (i=0; i<8; i++)
    {
        if(data & 0x80)
        {
            MPU6050_SDA_HIGH;
        }
        else
        {
            MPU6050_SDA_LOW;
        }
        data <<= 1;
        delay_us(1);
        MPU6050_SCL_HIGH;
        delay_us(1);
        MPU6050_SCL_LOW;
        delay_us(1);
    }
}

uint8 mpu6050receiveByte(void)
{
    uint8 i;
    sint8 data = 0;
    for(i=0;i<8;i++)
    {
        MPU6050_SCL_LOW;
        MPU6050_SCL_HIGH;
        delay_us(1);
        data <<= 0x01U;
        if(MPU6050_SDA_STATE)
        {
            data |= 0x01U;
        }
        MPU6050_SCL_LOW;
        delay_us(1);
    }
    return data;
}

uint8 mpu6050_write_register(uint8 reg,uint8 data)
{
    if (!mpu6050Start())
    {
        return 0;
    }
    mpu6050SendByte(MPU6050_ID);//发送从机地址和读/写选择位
    if (!mpu6050_master_waitACK())//等待应答
    {
        mpu6050Stop();
        return 0;
    }
    mpu6050SendByte(reg);//应答后发送内部寄存器地址
    mpu6050_master_waitACK();//等待应答
    mpu6050SendByte(data);//应答后发送写入的数据
    mpu6050_master_waitACK();//等待应答
    mpu6050Stop();
    return 1;
}


sint16 GetData(uint8 regh)
{
    uint8 data1 = 0;
    uint8 data2 = 0;

    //read first byte
    mpu6050Start();
    mpu6050SendByte(MPU6050_ID);//发送从机地址和读/写选择位
    if (!mpu6050_master_waitACK())//等待应答
    {
        mpu6050Stop();
        return 0;
    }
    mpu6050SendByte(regh);//应答后发送内部寄存器地址
    mpu6050_master_waitACK();//等待应答
    mpu6050Start();//restart
    mpu6050SendByte(MPU6050_ID + 1);//发送从机地址和读/写选择位
    mpu6050_master_waitACK();//等待应答
    data1=mpu6050receiveByte();//应答后读取数据
    mpu6050_master_sendNACK();//读取数据完成后发送非应答

    //read second byte
    mpu6050Start();//restart
    mpu6050SendByte(MPU6050_ID);//发送从机地址和读/写选择位
    if (!mpu6050_master_waitACK())//等待应答
    {
        mpu6050Stop();
        return 0;
    }
    mpu6050SendByte(regh+1);//应答后发送内部寄存器地址
    mpu6050_master_waitACK();//等待应答
    mpu6050Start();//restart
    mpu6050SendByte(MPU6050_ID + 1);//发送从机地址和读/写选择位
    mpu6050_master_waitACK();//等待应答
    data2=mpu6050receiveByte();//应答后读取数据
    mpu6050_master_sendNACK();//读取数据完成后发送非应答

    mpu6050Stop();
    return (data1<<8)|data2;
}


void MPU6050_Get_Data(void)
{
    int i;
    for(i=1;i<4;i++)
    {
        mpudata[i]=(GetData(0x3B+2*i-2)-offset[i])/factor[i];
        if (mpudata[i]<100/factor[i] && mpudata[i]>-100/factor[i])
        {
            mpudata[i]=0;
        }
    }
    for(i=4;i<7;i++)
    {
        mpudata[i]=(GetData(0x3B+2*i)-offset[i])/factor[i];
        if (mpudata[i]<10/factor[i] && mpudata[i]>-10/factor[i])
        {
            mpudata[i]=0;
        }
    }
}

void MPU6050_Calibrate(void)//标定函数
{
    int i;
    for(i=1;i<4;i++)
    {
        offset_test[i]=mpudata[i];
        factor_test[i]=mpudata[i];
    }
    for(i=4;i<7;i++)
    {
        offset_test[i]=mpudata[i];
        factor_test[i]=mpudata_int[i]/90;
    }
}

void MPU6050_int(float dt)//积分函数
{
    int i;
    for(i=1;i<7;i++)
    {
        mpudata_int[i]=mpudata_int[i]+dt*mpudata[i];
    }
}
