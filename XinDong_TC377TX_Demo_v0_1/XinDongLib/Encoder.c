#include "Encoder.h"

uint32           g_intCount;            /* Interrupt counter                                                         */
IfxGpt12_IncrEnc g_gpt12IncrEnc;        /* Incremental encoder handle                                                */

void Encoder_Overflow_ISR(void) {
    g_intCount++;
    IfxGpt12_IncrEnc_onZeroIrq(&g_gpt12IncrEnc);
}

void Encoder_Init() {
    /* Initialize global clocks */
    IfxGpt12_enableModule(&MODULE_GPT120);
    /* Set the GPT1 block prescaler */
    IfxGpt12_setGpt1BlockPrescaler(&MODULE_GPT120, IfxGpt12_Gpt1BlockPrescaler_8);
    /* Set the GPT2 block prescaler */
    IfxGpt12_setGpt2BlockPrescaler(&MODULE_GPT120, IfxGpt12_Gpt2BlockPrescaler_4);

    IfxGpt12_IncrEnc_Config gpt12Config;
    IfxGpt12_IncrEnc_initConfig(&gpt12Config, &MODULE_GPT120);

    /* Configure sensor, T3 used as position acquisition core */

    /* Configure position sensor offset */
    gpt12Config.base.offset             = ENCODER_OFFSET;
    /* The sensor direction is reversed */
    gpt12Config.base.reversed           = ENCODER_REVERSED;
    /* Sensor resolution (number of pulses per revolution) */
    gpt12Config.base.resolution         = ENCODER_RESOLUTION;
    /* Resolution multiplier for encoder interface, Timer T3 is clocked by each transition on both of the external
     * input pins. */
    gpt12Config.base.resolutionFactor   = IfxStdIf_Pos_ResolutionFactor_fourFold;

    /* Configure speed parameters */

    /* Threshold used for speed calculation using pulse count mode or time diff. mode in rad/s */
    gpt12Config.base.speedModeThreshold = ENCODER_SPEED_MODE_THRESHOLD;
    /* Absolute minimal allowed speed. below speed is recognized as 0 rad/s */
    gpt12Config.base.minSpeed           = ENCODER_BASE_MIN_SPEED;
    /* Absolute maximal allowed speed. Above speed is recognized as error */
    gpt12Config.base.maxSpeed           = ENCODER_BASE_MAX_SPEED;
    gpt12Config.base.speedFilterEnabled        = TRUE;
    gpt12Config.base.speedFilerCutOffFrequency = 1000;
    /* Configure Handler */

    /* Update period in seconds */
    gpt12Config.base.updatePeriod       = ENCODER_UPDATE_PERIOD;
    /* Interrupt isrPriority of the zero interrupt */
    gpt12Config.zeroIsrPriority    = ENCODER_OVERFLOW_PRIORITY;
    /* Interrupt service provider for the zero interrupt */
    gpt12Config.zeroIsrProvider    = ENCODER_OVERFLOW_TOS;

    /* Configure Hardware Resources */
    gpt12Config.pinA               = &ENCODER_A_GPT12_PIN;                   /* Encoder A signal, connected to T3IN   */
    gpt12Config.pinB               = &ENCODER_B_GPT12_PIN;                   /* Encoder B signal, connected to T3EUD  */
    gpt12Config.pinDriver          = IfxPort_PadDriver_cmosAutomotiveSpeed3;/* Pad Driver                            */

    /* Initialize the Incremental Encoder handle */
    IfxGpt12_IncrEnc_init(&g_gpt12IncrEnc, &gpt12Config);
    /* Calculate value for the T2 timer */
    sint32 resolution = g_gpt12IncrEnc.resolution - 1;
    /* Set the timer T2 mode of operation to reload mode */
    IfxGpt12_T2_setMode(&MODULE_GPT120, IfxGpt12_Mode_reload);
    /* Set value for the T2 timer */
    IfxGpt12_T2_setTimerValue(&MODULE_GPT120, (uint16)resolution);
    /* Set the input edge selection for the reload mode of the T2 timer */
    IfxGpt12_T2_setReloadInputMode(&MODULE_GPT120, IfxGpt12_ReloadInputMode_bothEdgesTxOTL);
}

inline float Encoder_GetValue(){
    return (float)IfxGpt12_IncrEnc_getRawPosition(&g_gpt12IncrEnc);
}

