#include "Ultrasonic.h"

IfxGtm_Tim_In timDriver_pulseIn;

void Ultrasonic_PulseIn_ISR(void) {
	;		// do something
}

void Ultrasonic_Init() {
    // initialize trigger pin
    IfxPort_setPinMode(ULTRA_TRIG_PORT, ULTRA_TRIG_PIN, IfxPort_Mode_outputPushPullGeneral);
    IfxPort_setPinState(ULTRA_TRIG_PORT, ULTRA_TRIG_PIN, IfxPort_State_low);

    IfxGtm_Tim_In_Config config;

    IfxGtm_Tim_In_initConfig(&config, &MODULE_GTM);
    config.timIndex = ULTRA_ECHO_TIM_PIN.tim;
    config.channelIndex = ULTRA_ECHO_TIM_PIN.channel;
    config.isrProvider = ULTRASONIC_PULSEIN_TOS;
    config.isrPriority = ULTRASONIC_PULSEIN_PRIORITY;
    config.capture.activeEdge = IfxGtm_Tim_In_ActiveEdge_raising;
    config.filter.inputPin = &ULTRA_ECHO_TIM_PIN;
    config.mode = IfxGtm_Tim_Mode_gatedPeriodic;

    IfxGtm_Tim_In_init(&timDriver_pulseIn, &config);
}

void Ultrasonic_Trigger() {
    // generate 10us pulse
    uint16 i;
    IfxPort_setPinState(ULTRA_TRIG_PORT, ULTRA_TRIG_PIN, IfxPort_State_high);
    Time_Delay_us(10);
    IfxPort_setPinState(ULTRA_TRIG_PORT, ULTRA_TRIG_PIN, IfxPort_State_low);

    // force CNT to zero on next CLK, and trigger a time out for previous run
    timDriver_pulseIn.channel->CNTS.B.CNTS = 0;
    while (timDriver_pulseIn.channel->CNT.B.CNT != 0)
        ;       // wait for it

    // set time out to 5k/100k=50ms, here timer update is "time out"!!!
    timDriver_pulseIn.channel->CNTS.B.CNTS = 5000;

    // clear all interrupt flags
    timDriver_pulseIn.channel->IRQ.NOTIFY.U = 0x01F;

    // enable new value and timeout interrupt
    IfxGtm_Tim_Ch_setChannelNotification(timDriver_pulseIn.channel, 1, 1, 0, 0);
    // timer in gated mode will start when rising edge hits
}
