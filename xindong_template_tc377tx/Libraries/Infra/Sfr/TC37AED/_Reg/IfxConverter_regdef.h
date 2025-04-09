/**
 * \file IfxConverter_regdef.h
 * \brief
 * \copyright Copyright (c) 2020 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC37xED_UM_V1.5.0
 * Specification: TC3xx User Manual V1.5.0
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxSfr_Converter_Registers Converter Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Converter_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Converter_Registers
 * 
 * \defgroup IfxSfr_Converter_Registers_union Register unions
 * \ingroup IfxSfr_Converter_Registers
 * 
 * \defgroup IfxSfr_Converter_Registers_struct Memory map
 * \ingroup IfxSfr_Converter_Registers
 */
#ifndef IFXCONVERTER_REGDEF_H
#define IFXCONVERTER_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Converter_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_CONVERTER_ACCEN0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID 0 - EN0 (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID 1 - EN1 (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID 2 - EN2 (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID 3 - EN3 (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID 4 - EN4 (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID 5 - EN5 (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID 6 - EN6 (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID 7 - EN7 (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID 8 - EN8 (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID 9 - EN9 (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID 10 - EN10 (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID 11 - EN11 (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID 12 - EN12 (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID 13 - EN13 (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID 14 - EN14 (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID 15 - EN15 (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID 16 - EN16 (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID 17 - EN17 (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID 18 - EN18 (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID 19 - EN19 (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID 20 - EN20 (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID 21 - EN21 (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID 22 - EN22 (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID 23 - EN23 (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID 24 - EN24 (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID 25 - EN25 (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID 26 - EN26 (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID 27 - EN27 (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID 28 - EN28 (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID 29 - EN29 (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID 30 - EN30 (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID 31 - EN31 (rw) */
} Ifx_CONVERTER_ACCEN0_Bits;

/** \brief Converter Control Block Control Register */
typedef struct _Ifx_CONVERTER_CCCTRL_Bits
{
    Ifx_UReg_32Bit reserved_0:28;     /**< \brief [27:0] \internal Reserved */
    Ifx_UReg_32Bit TC:4;              /**< \brief [31:28] Test Control - TC (rw) */
} Ifx_CONVERTER_CCCTRL_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_CONVERTER_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_CONVERTER_CLC_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_CONVERTER_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number - MOD_NUMBER (r) */
} Ifx_CONVERTER_ID_Bits;

/** \brief Kernel Reset Register 0 */
typedef struct _Ifx_CONVERTER_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_CONVERTER_KRST0_Bits;

/** \brief Kernel Reset Register 1 */
typedef struct _Ifx_CONVERTER_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_CONVERTER_KRST1_Bits;

/** \brief Kernel Reset Status Clear Register */
typedef struct _Ifx_CONVERTER_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_CONVERTER_KRSTCLR_Bits;

/** \brief OCDS Control and Status Register */
typedef struct _Ifx_CONVERTER_OCS_Bits
{
    Ifx_UReg_32Bit reserved_0:24;     /**< \brief [23:0] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_CONVERTER_OCS_Bits;

/** \brief Phase Synchronizer Configuration Register */
typedef struct _Ifx_CONVERTER_PHSCFG_Bits
{
    Ifx_UReg_32Bit PHSDIV:4;          /**< \brief [3:0] Phase Synchronizer Divider - PHSDIV (rwh) */
    Ifx_UReg_32Bit reserved_4:11;     /**< \brief [14:4] \internal Reserved */
    Ifx_UReg_32Bit PDWC:1;            /**< \brief [15:15] Write Control for Phase Sync. Divider - PDWC (w) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_CONVERTER_PHSCFG_Bits;

/** \brief Phase Synchronizer Safety Control Register */
typedef struct _Ifx_CONVERTER_PHSSFTY_Bits
{
    Ifx_UReg_32Bit ALF:1;             /**< \brief [0:0] Alarm Flag for Safety Features (rh) */
    Ifx_UReg_32Bit reserved_1:3;      /**< \brief [3:1] \internal Reserved */
    Ifx_UReg_32Bit FIPD0:1;           /**< \brief [4:4] Fault Injection Phase sync Divider (w) */
    Ifx_UReg_32Bit FICN0:1;           /**< \brief [5:5] Fault Injection Counter (w) */
    Ifx_UReg_32Bit reserved_6:10;     /**< \brief [15:6] \internal Reserved */
    Ifx_UReg_32Bit ALFCLR:1;          /**< \brief [16:16] Alarm Flag ALF Clear (w) */
    Ifx_UReg_32Bit reserved_17:3;     /**< \brief [19:17] \internal Reserved */
    Ifx_UReg_32Bit FIPD1:1;           /**< \brief [20:20] Fault Injection Phase sync Divider (w) */
    Ifx_UReg_32Bit FICN1:1;           /**< \brief [21:21] Fault Injection Phase sync Divider (w) */
    Ifx_UReg_32Bit reserved_22:10;    /**< \brief [31:22] \internal Reserved */
} Ifx_CONVERTER_PHSSFTY_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_converter_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_ACCEN0_Bits B;      /**< \brief Bitfield access */
} Ifx_CONVERTER_ACCEN0;

/** \brief Converter Control Block Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_CCCTRL_Bits B;      /**< \brief Bitfield access */
} Ifx_CONVERTER_CCCTRL;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_CLC_Bits B;         /**< \brief Bitfield access */
} Ifx_CONVERTER_CLC;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_ID_Bits B;          /**< \brief Bitfield access */
} Ifx_CONVERTER_ID;

/** \brief Kernel Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_KRST0_Bits B;       /**< \brief Bitfield access */
} Ifx_CONVERTER_KRST0;

/** \brief Kernel Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_KRST1_Bits B;       /**< \brief Bitfield access */
} Ifx_CONVERTER_KRST1;

/** \brief Kernel Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_KRSTCLR_Bits B;     /**< \brief Bitfield access */
} Ifx_CONVERTER_KRSTCLR;

/** \brief OCDS Control and Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_OCS_Bits B;         /**< \brief Bitfield access */
} Ifx_CONVERTER_OCS;

/** \brief Phase Synchronizer Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_PHSCFG_Bits B;      /**< \brief Bitfield access */
} Ifx_CONVERTER_PHSCFG;

/** \brief Phase Synchronizer Safety Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_CONVERTER_PHSSFTY_Bits B;     /**< \brief Bitfield access */
} Ifx_CONVERTER_PHSSFTY;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Converter_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief CONVERTER object */
typedef volatile struct _Ifx_CONVERTER
{
       Ifx_CONVERTER_CLC                   CLC;                    /**< \brief 0, Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_CONVERTER_ID                    ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[28];         /**< \brief C, \internal Reserved */
       Ifx_CONVERTER_OCS                   OCS;                    /**< \brief 28, OCDS Control and Status Register*/
       Ifx_CONVERTER_KRSTCLR               KRSTCLR;                /**< \brief 2C, Kernel Reset Status Clear Register*/
       Ifx_CONVERTER_KRST1                 KRST1;                  /**< \brief 30, Kernel Reset Register 1*/
       Ifx_CONVERTER_KRST0                 KRST0;                  /**< \brief 34, Kernel Reset Register 0*/
       Ifx_UReg_8Bit                       reserved_38[4];         /**< \brief 38, \internal Reserved */
       Ifx_CONVERTER_ACCEN0                ACCEN0;                 /**< \brief 3C, Access Enable Register 0*/
       Ifx_UReg_8Bit                       reserved_40[60];        /**< \brief 40, \internal Reserved */
       Ifx_CONVERTER_CCCTRL                CCCTRL;                 /**< \brief 7C, Converter Control Block Control Register*/
       Ifx_CONVERTER_PHSCFG                PHSCFG;                 /**< \brief 80, Phase Synchronizer Configuration Register*/
       Ifx_CONVERTER_PHSSFTY               PHSSFTY;                /**< \brief 84, Phase Synchronizer Safety Control Register*/
       Ifx_UReg_8Bit                       reserved_88[120];       /**< \brief 88, \internal Reserved */
} Ifx_CONVERTER;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXCONVERTER_REGDEF_H */
