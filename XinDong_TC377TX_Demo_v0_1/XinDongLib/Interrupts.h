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

#define		SWINT_1S_PERIODIC_PRIORITY		0
#define		SWINT_100MS_PERIODIC_PRIORITY	0
#define		SWINT_10MS_PERIODIC_PRIORITY	0
#define		SWINT_PID_PERIODIC_PRIORITY		0
#define		SWINT_USER0_PRIORITY			0
#define		SWINT_USER1_PRIORITY			0
#define		SWINT_USER2_PRIORITY			0
#define		SWINT_USER3_PRIORITY			0

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

#define		SWINT_1S_PERIODIC_TOS			IfxSrc_Tos_cpu2
#define		SWINT_100MS_PERIODIC_TOS		IfxSrc_Tos_cpu2
#define		SWINT_10MS_PERIODIC_TOS		IfxSrc_Tos_cpu2
#define		SWINT_PID_PERIODIC_TOS			IfxSrc_Tos_cpu2
#define		SWINT_USER0_TOS					IfxSrc_Tos_cpu2
#define		SWINT_USER1_TOS					IfxSrc_Tos_cpu2
#define		SWINT_USER2_TOS					IfxSrc_Tos_cpu2
#define		SWINT_USER3_TOS					IfxSrc_Tos_cpu2

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
void Interrupts_Init(void);

void SWINT_Trigger_10ms(void);

void SWINT_Trigger_100ms(void);

void SWINT_Trigger_1s(void);

void SWINT_Trigger_pid(void);

void SWINT_Trigger_user0(void);

void SWINT_Trigger_user1(void);

void SWINT_Trigger_user2(void);

void SWINT_Trigger_user3(void);

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

// define below functions in main
void Periodic_1s_ISR(void);

void Periodic_100ms_ISR(void);

void Periodic_10ms_ISR(void);

void Periodic_PID_ISR(void);

void SWINT_User0_ISR(void);

void SWINT_User1_ISR(void);

void SWINT_User2_ISR(void);

void SWINT_User3_ISR(void);

#endif /* XINDONGLIB_INTERRUPTS_H_ */
