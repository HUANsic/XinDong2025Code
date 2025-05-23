/*
 * Generated by TASKING Pin Mapper for AURIX
 * - device  : TC37XPD
 * - package : LFBGA292
 */

/*
 * Instructions on how to build this generated file and the Infineon's iLLD library with the TASKING  VX-toolset
 * for TriCore:
 * 1. Provide appropriate include paths to the compiler (-I option) to locate the iLLD library.
 * 2. Provide macro IFX_CFG_USE_COMPILER_DEFAULT_LINKER to the compiler (-D option) to prevent multiple
 *    definitions of symbol '_START' (in cstart.c and IfxCpu_CStart0.c).
 * 3. Disable compiler option 'Automatic inclusion of .sfr files' (-H option) to prevent macros to be redefined.
 */

#ifndef AURIX_PIN_MAPPINGS_H_
#define AURIX_PIN_MAPPINGS_H_

/* Infineon's iLLD library include files */

#include <Port/Io/IfxPort_Io.h>

#include <_PinMap/IfxPort_PinMap.h>


/* Symbolic names for GPIO ports */

// p00_0
#define IFXCFG_PORT_GPIO15                      IfxPort_P00_0
#define IFXCFG_PORT_GPIO15_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO15_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p00_1
#define IFXCFG_PORT_GPIO18                      IfxPort_P00_1
#define IFXCFG_PORT_GPIO18_MODE                 IfxPort_Mode_outputOpenDrainGeneral
#define IFXCFG_PORT_GPIO18_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p00_2
#define IFXCFG_PORT_GPIO17                      IfxPort_P00_2
#define IFXCFG_PORT_GPIO17_MODE                 IfxPort_Mode_outputOpenDrainGeneral
#define IFXCFG_PORT_GPIO17_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p00_3
#define IFXCFG_PORT_GPIO14                      IfxPort_P00_3
#define IFXCFG_PORT_GPIO14_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO14_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p00_7
#define IFXCFG_PORT_GPIO19                      IfxPort_P00_7
#define IFXCFG_PORT_GPIO19_MODE                 IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO19_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed1

// p00_8
#define IFXCFG_PORT_GPIO16                      IfxPort_P00_8
#define IFXCFG_PORT_GPIO16_MODE                 IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO16_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed1

// p00_9
#define IFXCFG_PORT_GPIO20                      IfxPort_P00_9
#define IFXCFG_PORT_GPIO20_MODE                 IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO20_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_0
#define IFXCFG_PORT_GPIO6                       IfxPort_P02_0
#define IFXCFG_PORT_GPIO6_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO6_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_1
#define IFXCFG_PORT_GPIO7                       IfxPort_P02_1
#define IFXCFG_PORT_GPIO7_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO7_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_2
#define IFXCFG_PORT_GPIO8                       IfxPort_P02_2
#define IFXCFG_PORT_GPIO8_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO8_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_3
#define IFXCFG_PORT_GPIO9                       IfxPort_P02_3
#define IFXCFG_PORT_GPIO9_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO9_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_6
#define IFXCFG_PORT_GPIO12                      IfxPort_P02_6
#define IFXCFG_PORT_GPIO12_MODE                 IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO12_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_7
#define IFXCFG_PORT_GPIO5                       IfxPort_P02_7
#define IFXCFG_PORT_GPIO5_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO5_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p02_8
#define IFXCFG_PORT_GPIO13                      IfxPort_P02_8
#define IFXCFG_PORT_GPIO13_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO13_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p15_0
#define IFXCFG_PORT_GPIO23                      IfxPort_P15_0
#define IFXCFG_PORT_GPIO23_MODE                 IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO23_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed1

// p20_7
#define IFXCFG_PORT_GPIO10                      IfxPort_P20_7
#define IFXCFG_PORT_GPIO10_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO10_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p20_8
#define IFXCFG_PORT_GPIO11                      IfxPort_P20_8
#define IFXCFG_PORT_GPIO11_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO11_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p20_9
#define IFXCFG_PORT_GPIO21                      IfxPort_P20_9
#define IFXCFG_PORT_GPIO21_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO21_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p20_10
#define IFXCFG_PORT_GPIO22                      IfxPort_P20_10
#define IFXCFG_PORT_GPIO22_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO22_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4

// p20_11
#define IFXCFG_PORT_GPIO1                       IfxPort_P20_11
#define IFXCFG_PORT_GPIO1_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO1_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p20_12
#define IFXCFG_PORT_GPIO2                       IfxPort_P20_12
#define IFXCFG_PORT_GPIO2_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO2_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p20_13
#define IFXCFG_PORT_GPIO3                       IfxPort_P20_13
#define IFXCFG_PORT_GPIO3_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO3_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p20_14
#define IFXCFG_PORT_GPIO4                       IfxPort_P20_14
#define IFXCFG_PORT_GPIO4_MODE                  IfxPort_Mode_inputNoPullDevice
#define IFXCFG_PORT_GPIO4_PAD_DRIVER            IfxPort_PadDriver_cmosAutomotiveSpeed1

// p21_6
#define IFXCFG_PORT_GPIO24                      IfxPort_P21_6
#define IFXCFG_PORT_GPIO24_MODE                 IfxPort_Mode_outputPushPullGeneral
#define IFXCFG_PORT_GPIO24_PAD_DRIVER           IfxPort_PadDriver_cmosAutomotiveSpeed4


/* Generic port I/O configuration */

#define IFXCFG_P00_0_IO_CONFIG                  { &IFXCFG_PORT_GPIO15, IFXCFG_PORT_GPIO15_MODE, IFXCFG_PORT_GPIO15_PAD_DRIVER }
#define IFXCFG_P00_1_IO_CONFIG                  { &IFXCFG_PORT_GPIO18, IFXCFG_PORT_GPIO18_MODE, IFXCFG_PORT_GPIO18_PAD_DRIVER }
#define IFXCFG_P00_2_IO_CONFIG                  { &IFXCFG_PORT_GPIO17, IFXCFG_PORT_GPIO17_MODE, IFXCFG_PORT_GPIO17_PAD_DRIVER }
#define IFXCFG_P00_3_IO_CONFIG                  { &IFXCFG_PORT_GPIO14, IFXCFG_PORT_GPIO14_MODE, IFXCFG_PORT_GPIO14_PAD_DRIVER }
#define IFXCFG_P00_7_IO_CONFIG                  { &IFXCFG_PORT_GPIO19, IFXCFG_PORT_GPIO19_MODE, IFXCFG_PORT_GPIO19_PAD_DRIVER }
#define IFXCFG_P00_8_IO_CONFIG                  { &IFXCFG_PORT_GPIO16, IFXCFG_PORT_GPIO16_MODE, IFXCFG_PORT_GPIO16_PAD_DRIVER }
#define IFXCFG_P00_9_IO_CONFIG                  { &IFXCFG_PORT_GPIO20, IFXCFG_PORT_GPIO20_MODE, IFXCFG_PORT_GPIO20_PAD_DRIVER }
#define IFXCFG_P02_0_IO_CONFIG                  { &IFXCFG_PORT_GPIO6, IFXCFG_PORT_GPIO6_MODE, IFXCFG_PORT_GPIO6_PAD_DRIVER }
#define IFXCFG_P02_1_IO_CONFIG                  { &IFXCFG_PORT_GPIO7, IFXCFG_PORT_GPIO7_MODE, IFXCFG_PORT_GPIO7_PAD_DRIVER }
#define IFXCFG_P02_2_IO_CONFIG                  { &IFXCFG_PORT_GPIO8, IFXCFG_PORT_GPIO8_MODE, IFXCFG_PORT_GPIO8_PAD_DRIVER }
#define IFXCFG_P02_3_IO_CONFIG                  { &IFXCFG_PORT_GPIO9, IFXCFG_PORT_GPIO9_MODE, IFXCFG_PORT_GPIO9_PAD_DRIVER }
#define IFXCFG_P02_6_IO_CONFIG                  { &IFXCFG_PORT_GPIO12, IFXCFG_PORT_GPIO12_MODE, IFXCFG_PORT_GPIO12_PAD_DRIVER }
#define IFXCFG_P02_7_IO_CONFIG                  { &IFXCFG_PORT_GPIO5, IFXCFG_PORT_GPIO5_MODE, IFXCFG_PORT_GPIO5_PAD_DRIVER }
#define IFXCFG_P02_8_IO_CONFIG                  { &IFXCFG_PORT_GPIO13, IFXCFG_PORT_GPIO13_MODE, IFXCFG_PORT_GPIO13_PAD_DRIVER }
#define IFXCFG_P15_0_IO_CONFIG                  { &IFXCFG_PORT_GPIO23, IFXCFG_PORT_GPIO23_MODE, IFXCFG_PORT_GPIO23_PAD_DRIVER }
#define IFXCFG_P20_7_IO_CONFIG                  { &IFXCFG_PORT_GPIO10, IFXCFG_PORT_GPIO10_MODE, IFXCFG_PORT_GPIO10_PAD_DRIVER }
#define IFXCFG_P20_8_IO_CONFIG                  { &IFXCFG_PORT_GPIO11, IFXCFG_PORT_GPIO11_MODE, IFXCFG_PORT_GPIO11_PAD_DRIVER }
#define IFXCFG_P20_9_IO_CONFIG                  { &IFXCFG_PORT_GPIO21, IFXCFG_PORT_GPIO21_MODE, IFXCFG_PORT_GPIO21_PAD_DRIVER }
#define IFXCFG_P20_10_IO_CONFIG                 { &IFXCFG_PORT_GPIO22, IFXCFG_PORT_GPIO22_MODE, IFXCFG_PORT_GPIO22_PAD_DRIVER }
#define IFXCFG_P20_11_IO_CONFIG                 { &IFXCFG_PORT_GPIO1, IFXCFG_PORT_GPIO1_MODE, IFXCFG_PORT_GPIO1_PAD_DRIVER }
#define IFXCFG_P20_12_IO_CONFIG                 { &IFXCFG_PORT_GPIO2, IFXCFG_PORT_GPIO2_MODE, IFXCFG_PORT_GPIO2_PAD_DRIVER }
#define IFXCFG_P20_13_IO_CONFIG                 { &IFXCFG_PORT_GPIO3, IFXCFG_PORT_GPIO3_MODE, IFXCFG_PORT_GPIO3_PAD_DRIVER }
#define IFXCFG_P20_14_IO_CONFIG                 { &IFXCFG_PORT_GPIO4, IFXCFG_PORT_GPIO4_MODE, IFXCFG_PORT_GPIO4_PAD_DRIVER }
#define IFXCFG_P21_6_IO_CONFIG                  { &IFXCFG_PORT_GPIO24, IFXCFG_PORT_GPIO24_MODE, IFXCFG_PORT_GPIO24_PAD_DRIVER }


/* Generic alternate I/O configuration */

// asclin2
#define IFXCFG_P33_8_IO_CONFIG                  { &IfxPort_P33_8, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }
#define IFXCFG_P33_9_IO_CONFIG                  { &IfxPort_P33_9, IfxPort_Mode_outputPushPullAlt2, IfxPort_PadDriver_cmosAutomotiveSpeed4 }

// asclin3
#define IFXCFG_P15_6_IO_CONFIG                  { &IfxPort_P15_6, IfxPort_Mode_outputPushPullAlt2, IfxPort_PadDriver_cmosAutomotiveSpeed4 }
#define IFXCFG_P15_7_IO_CONFIG                  { &IfxPort_P15_7, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// eruin0
#define IFXCFG_P15_4_IO_CONFIG                  { &IfxPort_P15_4, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// eruin3
#define IFXCFG_P10_3_IO_CONFIG                  { &IfxPort_P10_3, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// eruin5
#define IFXCFG_P15_8_IO_CONFIG                  { &IfxPort_P15_8, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// eruin6
#define IFXCFG_P11_10_IO_CONFIG                 { &IfxPort_P11_10, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// gptone0
#define IFXCFG_P33_6_IO_CONFIG                  { &IfxPort_P33_6, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }
#define IFXCFG_P33_7_IO_CONFIG                  { &IfxPort_P33_7, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// gtm0_tim0_ch3
#define IFXCFG_P21_5_IO_CONFIG                  { &IfxPort_P21_5, IfxPort_Mode_inputNoPullDevice, IfxPort_PadDriver_cmosAutomotiveSpeed1 }

// i2c0
#define IFXCFG_P13_1_IO_CONFIG                  { &IfxPort_P13_1, IfxPort_Mode_outputPushPullAlt6, IfxPort_PadDriver_cmosAutomotiveSpeed4 }
#define IFXCFG_P13_1_IO_CONFIG_IN               { &IfxPort_P13_1, IfxPort_Mode_inputPullUp, IfxPort_PadDriver_cmosAutomotiveSpeed4 }
#define IFXCFG_P13_2_IO_CONFIG                  { &IfxPort_P13_2, IfxPort_Mode_outputPushPullAlt6, IfxPort_PadDriver_cmosAutomotiveSpeed4 }
#define IFXCFG_P13_2_IO_CONFIG_IN               { &IfxPort_P13_2, IfxPort_Mode_inputPullUp, IfxPort_PadDriver_cmosAutomotiveSpeed4 }

// tout53
#define IFXCFG_P21_2_IO_CONFIG                  { &IfxPort_P21_2, IfxPort_Mode_outputPushPullAlt1, IfxPort_PadDriver_cmosAutomotiveSpeed4 }

// tout54
#define IFXCFG_P21_3_IO_CONFIG                  { &IfxPort_P21_3, IfxPort_Mode_outputPushPullAlt1, IfxPort_PadDriver_cmosAutomotiveSpeed4 }

// tout94
#define IFXCFG_P13_3_IO_CONFIG                  { &IfxPort_P13_3, IfxPort_Mode_outputPushPullAlt1, IfxPort_PadDriver_cmosAutomotiveSpeed4 }


/* Initialization routines */

extern void gpio_init_pins(void);

extern void asclin2_init_pins(void);

extern void asclin3_init_pins(void);

extern void eruin0_init_pins(void);

extern void eruin3_init_pins(void);

extern void eruin5_init_pins(void);

extern void eruin6_init_pins(void);

extern void gptone0_init_pins(void);

extern void gtm0_tim0_ch3_init_pins(void);

extern void i2c0_init_pins(void);

extern void tout53_init_pins(void);

extern void tout54_init_pins(void);

extern void tout94_init_pins(void);


#endif /* AURIX_PIN_MAPPINGS_H_ */
