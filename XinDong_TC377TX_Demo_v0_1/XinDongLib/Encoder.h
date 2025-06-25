/**********************************************************************************************************************
 * Author: Chao Xu
 * Description:
 * 
 * Version:
 *********************************************************************************************************************/

#ifndef XINDONGLIB_ENCODER_H_
#define XINDONGLIB_ENCODER_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxGpt12.h"
#include "IfxGpt12_IncrEnc.h"
#include "Bsp.h"

#include "XinDong_Config.h"
#include "Interrupts.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define UPDATE_FREQ_HZ              10000                           /* Encoder function update frequency.            */
#define SPEED_PULSE_COUNTING_RPM    1200                            /* Speed point when switching from one to
                                                                       another position sensing method value.        */
#define SPEED_MIN_RPM               (0.0f)                          /* Minimum speed limit value.                    */
#define SPEED_MAX_RPM               (2000.0f)                       /* Maximum speed limit value.                    */
#define ENCODER_OFFSET              0                               /* Encoder offset                                */
#define ENCODER_REVERSED            TRUE                            /* Encoder reversed?                             */
#define ENCODER_RESOLUTION          2048                            /* Encoder resolution - pulses per revolution.   */
#define ENCODER_UPDATE_PERIOD       (1/ ((float32)UPDATE_FREQ_HZ))  /* Encoder function update period.               */
/* Use pulse counting if there is less than user defined counting rpm */
#define ENCODER_SPEED_MODE_THRESHOLD    2 * IFX_PI * SPEED_PULSE_COUNTING_RPM / 60
#define ENCODER_BASE_MIN_SPEED      (float32) (SPEED_MIN_RPM / 60.0 * 2 * IFX_PI) /* Minimum base speed              */
#define ENCODER_BASE_MAX_SPEED      (float32) (SPEED_MAX_RPM / 60.0 * 2 * IFX_PI) /* Maximum base speed              */
#define ENCODER_EMULATOR_SPEED      5                               /* Encoder emulator initial speed [rad/s]        */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
 typedef struct
{
    uint32           dummy;                         /* Dummy variable                                                */

    struct
    {
        boolean          run;                       /* Status: TRUE: the encoder turn                                */
        IfxStdIf_Pos_Dir direction;                 /* Direction                                                     */
        uint32           step;                      /* Current step                                                  */
        sint32           rawPosition;               /* Expected rawPosition                                          */
        sint32           positionMask;              /* Mask for rawPosition value                                    */
        uint32           resolution;                /* Encoder resolution                                            */
        uint32           multiplicationFactor;      /* Encoder multiplication factor                                 */
        float32          updatePeriod;              /* Refresh period                                                */
        float32          speed;                     /* Requested encoder speed in rad/s                              */
    } control;
    struct
    {
        float32          speed;                     /* Acquired encoder speed in rad/s                               */
        sint32           rawPosition;               /* Acquired rawPosition                                          */
        IfxStdIf_Pos_Dir direction;                 /* Acquired direction                                            */
    }status;
} Encoder;

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void Encoder_Init();

inline float Encoder_GetValue();

#endif /* XINDONGLIB_ENCODER_H_ */
