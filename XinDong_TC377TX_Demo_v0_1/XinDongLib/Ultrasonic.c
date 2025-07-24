#include "Ultrasonic.h"

IfxGtm_Tim_In timDriver_pulseIn;

volatile float32    ultrasonicDistance = 0;
volatile uint8      ultrasonicReady = 0;

void Ultrasonic_PulseIn_ISR(void)
{
    /* 1) 读取当前计数值 */
    uint32 cnt = timDriver_pulseIn.channel->CNT.B.CNT;

    /* 2) 读取中断通知位域 */
    Ifx_GTM_TIM_CH_IRQ_NOTIFY_Bits flags = timDriver_pulseIn.channel->IRQ.NOTIFY.B;

    /* 3) 判断事件类型并保存 */
    if (flags.NEWVAL) {
        // 收到回波脉冲结束（新的测量值就绪）
        ultrasonicDistance = (cnt / 100.0) * SPEED_SOUND_MM_MS;
        ultrasonicReady = 1;
    } else if (flags.TODET) {
        // 达到超时阈值
        ultrasonicDistance = 17150;  // 或其他你定义的“超时”标志值
        ultrasonicReady = 0;
    } else {
        // 其它情况（如溢出、毛刺等）也可根据需要处理
        ultrasonicDistance = 17151;
        ultrasonicReady = 0;
    }

    /* 4) 清除所有中断标志位 */
    // 直接写 1 清（rw 类型位写 1 即清除），覆盖 NEWVAL、ECNTOFL、CNTOFL、GPROFL、TODET、GLITCHDET
    timDriver_pulseIn.channel->IRQ.NOTIFY.U = 0x3F;
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
    timDriver_pulseIn.channel->IRQ.NOTIFY.U = 0x03F;

    // enable new value and timeout interrupt
    IfxGtm_Tim_Ch_setChannelNotification(timDriver_pulseIn.channel, 1, 1, 0, 0);
    // timer in gated mode will start when rising edge hits
}
