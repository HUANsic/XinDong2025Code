/**********************************************************************************************************************
 * Author: Zonghuan Wu
 * Description:
 * 
 * Version:
 *********************************************************************************************************************/

#ifndef XINDONGLIB_INTERRUPTS_H_
#define XINDONGLIB_INTERRUPTS_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "XinDong_Config.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
// Interrupt Priorities
#define     ENCODER_OVERFLOW_PRIORITY		1
#define     ULTRASONIC_PULSEIN_PRIORITY		2

#define     TIME_PERIODIC_PRIORITY			30

#define     IO_REED_PRIORITY				40

#define     SERIAL_RX_PRIORITY				42
#define     SERIAL_TX_PRIORITY				43
#define     SERIAL_ERR_PRIORITY				11
#define     BLE_RX_PRIORITY					50
#define     BLE_TX_PRIORITY					51
#define     BLE_ERR_PRIORITY				12

#define     CAMERA_PCLK_PRIORITY			21
#define     CAMERA_VSYNC_PRIORITY			23
#define     CAMERA_HSYNC_PRIORITY			22
#define     CAMERA_DMA_CPLT_PRIORITY		14
#define     CAMERA_DMA_ERR_PRIORITY			13
#define		CAMERA_NEW_IMAGE_PRIORITY		24			// didn't find example code for this, so not used yet

// Interrupt Type Of Service
#define     ENCODER_OVERFLOW_TOS			IfxSrc_Tos_cpu0
#define     ULTRASONIC_PULSEIN_TOS			IfxSrc_Tos_cpu0

#define     TIME_PERIODIC_TOS				IfxSrc_Tos_cpu0

#define     IO_REED_TOS						IfxSrc_Tos_cpu0

#define     SERIAL_RX_TOS					IfxSrc_Tos_cpu0
#define     SERIAL_TX_TOS					IfxSrc_Tos_cpu0
#define     SERIAL_ERR_TOS					IfxSrc_Tos_cpu0
#define     BLE_RX_TOS						IfxSrc_Tos_cpu0
#define     BLE_TX_TOS						IfxSrc_Tos_cpu0
#define     BLE_ERR_TOS						IfxSrc_Tos_cpu0

#define     CAMERA_PCLK_TOS					IfxSrc_Tos_cpu1
#define     CAMERA_VSYNC_TOS				IfxSrc_Tos_cpu1
#define     CAMERA_HSYNC_TOS				IfxSrc_Tos_cpu1
#define     CAMERA_DMA_CPLT_TOS				IfxSrc_Tos_cpu1
#define     CAMERA_DMA_ERR_TOS				IfxSrc_Tos_cpu1
#define		CAMERA_NEW_IMAGE_TOS			IfxSrc_Tos_cpu1			// didn't find example code for this, so not used yet

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void Reed_Init(void);

// define functions below in YOUR code
void Encoder_Overflow_ISR(void);

void Time_Periodic_ISR(void);

void IO_Reed_ISR(void);

void Serial_Tx_ISR(void);

void Serial_Rx_ISR(void);

void Serial_Err_ISR(void);

void BLE_Tx_ISR(void);

void BLE_Rx_ISR(void);

void BLE_Err_ISR(void);

void Ultrasonic_PulseIn_ISR(void);

void IO_Pclk_ISR(void);

void IO_Vsync_ISR(void);

void IO_Hsync_ISR(void);


#endif /* XINDONGLIB_INTERRUPTS_H_ */
