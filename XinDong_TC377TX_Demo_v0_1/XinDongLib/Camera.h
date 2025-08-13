/**********************************************************************************************************************
 * Author: Yuhui Liao
 * Description:
 * 
 * Version:
 *********************************************************************************************************************/

#ifndef XINDONGLIB_CAMERA_H_
#define XINDONGLIB_CAMERA_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include    "XinDong_Config.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define     CAM_IMAGE_WIDTH         188
#define     CAM_IMAGE_HEIGHT        120

#define PIN_IRQ_MODE_RISING             IfxPort_InputMode_pullDown     /*!< 上升沿（下拉）触发中断 */
#define PIN_IRQ_MODE_FALLING            IfxPort_InputMode_pullUp       /*!< 下降沿（上拉）触发中断 */
#define PIN_IRQ_MODE_RISING_FALLING     IfxPort_InputMode_noPullDevice /*!< 双边沿（开漏）触发中断 */

/* SCCB接口读写通讯地址bit0 */
#define ATK_MC2640_SCCB_WRITE   0x00
#define ATK_MC2640_SCCB_READ    0x01

/* ATK-MC2640模块制造商ID和产品ID */
#define ATK_MC2640_MID  0x7FA2
#define ATK_MC2640_PID  0x2642

/* ATK-MC2640 SCCB通讯地址 */
#define ATK_MC2640_SCCB_ADDR                    0x30

/* 错误代码 */
#define ATK_MC2640_EOK      0   /* 没有错误 */
#define ATK_MC2640_ERROR    1   /* 错误 */
#define ATK_MC2640_EINVAL   2   /* 非法参数 */
#define ATK_MC2640_ENOMEM   3   /* 内存不足 */
#define ATK_MC2640_EEMPTY   4   /* 资源为空 */

#define ATK_MC2640_REG_BANK_SEL  ATK_MC2640_REG_DSP_RA_DLMT

/* ATK-MC2640模块DSP寄存器块 */
#define ATK_MC2640_REG_DSP_R_BYPASS         0x05
#define ATK_MC2640_REG_DSP_Qs               0x44
#define ATK_MC2640_REG_DSP_CTRLI            0x50
#define ATK_MC2640_REG_DSP_HSIZE            0x51
#define ATK_MC2640_REG_DSP_VSIZE            0x52
#define ATK_MC2640_REG_DSP_XOFFL            0x53
#define ATK_MC2640_REG_DSP_YOFFL            0x54
#define ATK_MC2640_REG_DSP_VHYX             0x55
#define ATK_MC2640_REG_DSP_DPRP             0x56
#define ATK_MC2640_REG_DSP_TEST             0x57
#define ATK_MC2640_REG_DSP_ZMOW             0x5A
#define ATK_MC2640_REG_DSP_ZMOH             0x5B
#define ATK_MC2640_REG_DSP_ZMHH             0x5C
#define ATK_MC2640_REG_DSP_BPADDR           0x7C
#define ATK_MC2640_REG_DSP_BPDATA           0x7D
#define ATK_MC2640_REG_DSP_CTRL2            0x86
#define ATK_MC2640_REG_DSP_CTRL3            0x87
#define ATK_MC2640_REG_DSP_SIZEL            0x8C
#define ATK_MC2640_REG_DSP_HSIZE8           0xC0
#define ATK_MC2640_REG_DSP_VSIZE8           0xC1
#define ATK_MC2640_REG_DSP_CTRL0            0xC2
#define ATK_MC2640_REG_DSP_CTRL1            0xC3
#define ATK_MC2640_REG_DSP_R_DVP_SP         0xD3
#define ATK_MC2640_REG_DSP_IMAGE_MODE       0xDA
#define ATK_MC2640_REG_DSP_RESET            0xE0
#define ATK_MC2640_REG_DSP_MS_SP            0xF0
#define ATK_MC2640_REG_DSP_SS_ID            0xF7
#define ATK_MC2640_REG_DSP_SS_CTRL          0xF8
#define ATK_MC2640_REG_DSP_MC_BIST          0xF9
#define ATK_MC2640_REG_DSP_MC_AL            0xFA
#define ATK_MC2640_REG_DSP_MC_AH            0xFB
#define ATK_MC2640_REG_DSP_MC_D             0xFC
#define ATK_MC2640_REG_DSP_P_CMD            0xFD
#define ATK_MC2640_REG_DSP_P_STATUS         0xFE
#define ATK_MC2640_REG_DSP_RA_DLMT          0xFF

/* ATK-MC2640模块Sensor寄存器块 */
#define ATK_MC2640_REG_SENSOR_GAIN          0x00
#define ATK_MC2640_REG_SENSOR_COM1          0x03
#define ATK_MC2640_REG_SENSOR_REG04         0x04
#define ATK_MC2640_REG_SENSOR_REG08         0x08
#define ATK_MC2640_REG_SENSOR_COM2          0x09
#define ATK_MC2640_REG_SENSOR_PIDH          0x0A
#define ATK_MC2640_REG_SENSOR_PIDL          0x0B
#define ATK_MC2640_REG_SENSOR_COM3          0x0C
#define ATK_MC2640_REG_SENSOR_COM4          0x0D
#define ATK_MC2640_REG_SENSOR_AEC           0x10
#define ATK_MC2640_REG_SENSOR_CLKRC         0x11
#define ATK_MC2640_REG_SENSOR_COM7          0x12
#define ATK_MC2640_REG_SENSOR_COM8          0x13
#define ATK_MC2640_REG_SENSOR_COM9          0x14
#define ATK_MC2640_REG_SENSOR_COM10         0x15
#define ATK_MC2640_REG_SENSOR_HREFST        0x17
#define ATK_MC2640_REG_SENSOR_HREFEND       0x18
#define ATK_MC2640_REG_SENSOR_VSTRT         0x19
#define ATK_MC2640_REG_SENSOR_VEND          0x1A
#define ATK_MC2640_REG_SENSOR_MIDH          0x1C
#define ATK_MC2640_REG_SENSOR_MIDL          0x1D
#define ATK_MC2640_REG_SENSOR_AEW           0x24
#define ATK_MC2640_REG_SENSOR_AEB           0x25
#define ATK_MC2640_REG_SENSOR_VV            0x26
#define ATK_MC2640_REG_SENSOR_REG2A         0x2A
#define ATK_MC2640_REG_SENSOR_FRARL         0x2B
#define ATK_MC2640_REG_SENSOR_ADDVSL        0x2D
#define ATK_MC2640_REG_SENSOR_ADDVSH        0x2E
#define ATK_MC2640_REG_SENSOR_YAVG          0x2F
#define ATK_MC2640_REG_SENSOR_HSDY          0x30
#define ATK_MC2640_REG_SENSOR_HEDY          0x31
#define ATK_MC2640_REG_SENSOR_REG32         0x32
#define ATK_MC2640_REG_SENSOR_ARCOM2        0x34
#define ATK_MC2640_REG_SENSOR_REG45         0x45
#define ATK_MC2640_REG_SENSOR_FLL           0x46
#define ATK_MC2640_REG_SENSOR_FLH           0x47
#define ATK_MC2640_REG_SENSOR_COM19         0x48
#define ATK_MC2640_REG_SENSOR_ZOOMS         0x49
#define ATK_MC2640_REG_SENSOR_COM22         0x4B
#define ATK_MC2640_REG_SENSOR_COM25         0x4E
#define ATK_MC2640_REG_SENSOR_BD50          0x4F
#define ATK_MC2640_REG_SENSOR_BD60          0x50
#define ATK_MC2640_REG_SENSOR_REG5D         0x5D
#define ATK_MC2640_REG_SENSOR_REG5E         0x5E
#define ATK_MC2640_REG_SENSOR_REG5F         0x5F
#define ATK_MC2640_REG_SENSOR_REG60         0x60
#define ATK_MC2640_REG_SENSOR_HISTO_LOW     0x61
#define ATK_MC2640_REG_SENSOR_HISTO_HIGH    0x62
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
/* ATK-MC2640模块灯光模式枚举 */
typedef enum
{
    ATK_MC2640_LIGHT_MODE_AUTO = 0x00,          /* Auto */
    ATK_MC2640_LIGHT_MODE_SUNNY,                /* Sunny */
    ATK_MC2640_LIGHT_MODE_CLOUDY,               /* Cloudy */
    ATK_MC2640_LIGHT_MODE_OFFICE,               /* Office */
    ATK_MC2640_LIGHT_MODE_HOME,                 /* Home */
} atk_mc2640_light_mode_t;

/* ATK-MC2640模块色彩饱和度枚举 */
typedef enum
{
    ATK_MC2640_COLOR_SATURATION_0 = 0x00,       /* +2 */
    ATK_MC2640_COLOR_SATURATION_1,              /* +1 */
    ATK_MC2640_COLOR_SATURATION_2,              /* 0 */
    ATK_MC2640_COLOR_SATURATION_3,              /* -1 */
    ATK_MC2640_COLOR_SATURATION_4,              /* -2 */
} atk_mc2640_color_saturation_t;

/* ATK-MC2640模块亮度枚举 */
typedef enum
{
    ATK_MC2640_BRIGHTNESS_0 = 0x00,             /* +2 */
    ATK_MC2640_BRIGHTNESS_1,                    /* +1 */
    ATK_MC2640_BRIGHTNESS_2,                    /* 0 */
    ATK_MC2640_BRIGHTNESS_3,                    /* -1 */
    ATK_MC2640_BRIGHTNESS_4,                    /* -2 */
} atk_mc2640_brightness_t;

/* ATK-MC2640模块对比度枚举 */
typedef enum
{
    ATK_MC2640_CONTRAST_0 = 0x00,               /* +2 */
    ATK_MC2640_CONTRAST_1,                      /* +1 */
    ATK_MC2640_CONTRAST_2,                      /* 0 */
    ATK_MC2640_CONTRAST_3,                      /* -1 */
    ATK_MC2640_CONTRAST_4,                      /* -2 */
} atk_mc2640_contrast_t;

/* ATK-MC2640模块特殊效果枚举 */
typedef enum
{
    ATK_MC2640_SPECIAL_EFFECT_ANTIQUE = 0x00,   /* Antique */
    ATK_MC2640_SPECIAL_EFFECT_BLUISH,           /* Bluish */
    ATK_MC2640_SPECIAL_EFFECT_GREENISH,         /* Greenish */
    ATK_MC2640_SPECIAL_EFFECT_REDISH,           /* Redish */
    ATK_MC2640_SPECIAL_EFFECT_BW,               /* B&W */
    ATK_MC2640_SPECIAL_EFFECT_NEGATIVE,         /* Negative */
    ATK_MC2640_SPECIAL_EFFECT_BW_NEGATIVE,      /* B&W Negative */
    ATK_MC2640_SPECIAL_EFFECT_NORMAL,           /* Normal */
} atk_mc2640_special_effect_t;

/* ATK-MC2640输出图像格式枚举 */
typedef enum
{
    ATK_MC2640_OUTPUT_FORMAT_RGB565 = 0x00,     /* RGB565 */
    ATK_MC2640_OUTPUT_FORMAT_JPEG,              /* JPEG */
} atk_mc2640_output_format_t;

/* ATK-MC2640获取帧数据方式枚举 */
typedef enum
{
    ATK_MC2640_GET_TYPE_DTS_8B_NOINC = 0x00,    /* 图像数据以字节方式写入目的地址，目的地址固定不变 */
    ATK_MC2640_GET_TYPE_DTS_8B_INC,             /* 图像数据以字节方式写入目的地址，目的地址自动增加 */
    ATK_MC2640_GET_TYPE_DTS_16B_NOINC,          /* 图像数据以半字方式写入目的地址，目的地址固定不变 */
    ATK_MC2640_GET_TYPE_DTS_16B_INC,            /* 图像数据以半字方式写入目的地址，目的地址自动增加 */
    ATK_MC2640_GET_TYPE_DTS_32B_NOINC,          /* 图像数据以字方式写入目的地址，目的地址固定不变 */
    ATK_MC2640_GET_TYPE_DTS_32B_INC,            /* 图像数据以字方式写入目的地址，目的地址自动增加 */
} atk_mc2640_get_type_t;

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
// get the latest image buffer; this returned buffer will be readable and writable to the caller; the caller must release the previous buffer before getting another
void* Camera_GetLatest(void);

// release the image buffer; make sure the returned value IS ZERO (NULLPTR), otherwise the buffer failed to release, and the occupied buffer is returned
void* Camera_Release(uint16 (*img_ptr)[CAM_IMAGE_WIDTH]);

uint8 Camera_Init(void);

#endif /* XINDONGLIB_CAMERA_H_ */
