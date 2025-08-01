/**********************************************************************************************************************
 * Author:
 * Description:
 * 
 * Version:
 *********************************************************************************************************************/

#ifndef XINDONGLIB_IO_H_
#define XINDONGLIB_IO_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "XinDong_Config.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

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
// Initialize all IO peripherals and pins
void IO_Init(void);

/* LED Control Function Declarations */
/**
 * @brief Turns on the LED with the specified number (1-4)
 * @param ledNum LED number (valid range: 1-4)
 * @note No action is taken for invalid LED numbers
 */
void IO_LED_On(int ledNum);

/**
 * @brief Turns off the LED with the specified number (1-4)
 * @param ledNum LED number (valid range: 1-4)
 * @note No action is taken for invalid LED numbers
 */
void IO_LED_Off(int ledNum);

void IO_LED_Set(uint8 ledNum, uint8 state);

/**
 * @brief Toggles the state of the specified LED (1-4)
 * @param ledNum LED number (valid range: 1-4)
 * @note If the LED is on, it will turn off, and vice versa
 * @note No action is taken for invalid LED numbers
 */
void IO_LED_Toggle(int ledNum);

/* Switch Control Function Declarations */
/**
 * @brief Reads the state of the specified DIP switch (1-4)
 * @param swNum Switch number (valid range: 1-4)
 * @return boolean Switch state (TRUE/FALSE as defined by hardware)
 * @retval TRUE Typically indicates switch is pressed/active
 * @retval FALSE Indicates switch is not pressed/inactive or invalid number
 */
boolean IO_DIP_Read(int swNum);

//define functions below in main
void Reed_Triggered(void);

#endif /* XINDONGLIB_IO_H_ */
