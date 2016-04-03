/***********************************************************************************
 *  Copyright 2016, National Instruments, Corporation.  All Rights Reserved.
 **********************************************************************************/

/******************************************************************************
 *                       Tektronix AFG1000 Series Arbitrary Function Generator
 *
 * Title:    tkafg1k.h
 * Purpose:  Tektronix AFG1000 Series Arbitrary Function Generator
 *           instrument driver declarations.
 *
 *****************************************************************************/

#ifndef __TKAFG1K_HEADER
#define __TKAFG1K_HEADER

#include <ivi.h>
#include <ivifgen.h>

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define TKAFG1K_MAJOR_VERSION                  1   /* Instrument driver major version   */
#define TKAFG1K_MINOR_VERSION                  0   /* Instrument driver minor version   */

#define TKAFG1K_CLASS_SPEC_MAJOR_VERSION       3   /* Class specification major version */
#define TKAFG1K_CLASS_SPEC_MINOR_VERSION       0   /* Class specification minor version */

#define TKAFG1K_SUPPORTED_INSTRUMENT_MODELS    "AFG1022, AFG1062"

#define TKAFG1K_DRIVER_VENDOR                  "National Instruments"

#ifdef _IVI_mswin64_
#define TKAFG1K_DRIVER_DESCRIPTION             "Tektronix AFG1000 Series Arbitrary Funtion Generator [Compiled for 64-bit]"
#else
#define TKAFG1K_DRIVER_DESCRIPTION             "Tektronix AFG1000 Series Arbitrary Funtion Generator"
#endif

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

/*- IVI Inherent Instrument Attributes ---------------------------------*/

/* User Options */
#define TKAFG1K_ATTR_RANGE_CHECK                                 IVI_ATTR_RANGE_CHECK                           /* ViBoolean */
#define TKAFG1K_ATTR_QUERY_INSTRUMENT_STATUS                     IVI_ATTR_QUERY_INSTRUMENT_STATUS               /* ViBoolean */
#define TKAFG1K_ATTR_CACHE                                       IVI_ATTR_CACHE                                 /* ViBoolean */
#define TKAFG1K_ATTR_SIMULATE                                    IVI_ATTR_SIMULATE                              /* ViBoolean */
#define TKAFG1K_ATTR_RECORD_COERCIONS                            IVI_ATTR_RECORD_COERCIONS                      /* ViBoolean */
#define TKAFG1K_ATTR_INTERCHANGE_CHECK                           IVI_ATTR_INTERCHANGE_CHECK                     /* ViBoolean */

/* Driver Information  */
#define TKAFG1K_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX                   /* ViString, read-only  */
#define TKAFG1K_ATTR_SUPPORTED_INSTRUMENT_MODELS                 IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS              /* ViString, read-only  */
#define TKAFG1K_ATTR_GROUP_CAPABILITIES                          IVI_ATTR_GROUP_CAPABILITIES                       /* ViString, read-only  */
#define TKAFG1K_ATTR_INSTRUMENT_MANUFACTURER                     IVI_ATTR_INSTRUMENT_MANUFACTURER                  /* ViString, read-only  */
#define TKAFG1K_ATTR_INSTRUMENT_MODEL                            IVI_ATTR_INSTRUMENT_MODEL                         /* ViString, read-only  */
#define TKAFG1K_ATTR_INSTRUMENT_FIRMWARE_REVISION                IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION             /* ViString, read-only  */
#define TKAFG1K_ATTR_SPECIFIC_DRIVER_REVISION                    IVI_ATTR_SPECIFIC_DRIVER_REVISION                 /* ViString, read-only  */
#define TKAFG1K_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR                   /* ViString, read-only  */
#define TKAFG1K_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION              /* ViString, read-only  */
#define TKAFG1K_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION /* ViInt32, read-only */
#define TKAFG1K_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION /* ViInt32, read-only */

/* Advanced Session Information */
#define TKAFG1K_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                          /* ViString, read-only  */
#define TKAFG1K_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR                /* ViString, read-only  */
#define TKAFG1K_ATTR_DRIVER_SETUP                                IVI_ATTR_DRIVER_SETUP                          /* ViString, read-only  */

/*- Instrument-Specific Attributes -------------------------------------*/

/*- Basic Instrument Operation -----------------------------------------*/
#define TKAFG1K_ATTR_CHANNEL_COUNT             IVI_ATTR_CHANNEL_COUNT                                           /* ViInt32,  read-only  */
#define TKAFG1K_ATTR_OUTPUT_MODE               IVIFGEN_ATTR_OUTPUT_MODE                                         /* ViInt32                        */
#define TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)                             /* ViInt32,   multi-channel       */
#define TKAFG1K_ATTR_OUTPUT_ENABLED            IVIFGEN_ATTR_OUTPUT_ENABLED                                      /* ViBoolean, multi-channel       */
#define TKAFG1K_ATTR_OUTPUT_IMPEDANCE          IVIFGEN_ATTR_OUTPUT_IMPEDANCE                                    /* ViReal64,  multi-channel, ohms */
#define TKAFG1K_ATTR_OPERATION_MODE            IVIFGEN_ATTR_OPERATION_MODE                                      /* ViInt32,   multi-channel       */
#define TKAFG1K_ATTR_ACTIVE_MEMORY             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)                            /* ViInt32                        */

/*- Standard Waveform Generation ---------------------------------------*/
#define TKAFG1K_ATTR_FUNC_WAVEFORM             IVIFGEN_ATTR_FUNC_WAVEFORM                                       /* ViInt32,  multi-channel           */
#define TKAFG1K_ATTR_FUNC_AMPLITUDE            IVIFGEN_ATTR_FUNC_AMPLITUDE                                      /* ViReal64, multi-channel, volts    */
#define TKAFG1K_ATTR_FUNC_DC_OFFSET            IVIFGEN_ATTR_FUNC_DC_OFFSET                                      /* ViReal64, multi-channel, volts    */
#define TKAFG1K_ATTR_FUNC_FREQUENCY            IVIFGEN_ATTR_FUNC_FREQUENCY                                      /* ViReal64, multi-channel, hertz    */
#define TKAFG1K_ATTR_FUNC_START_PHASE          IVIFGEN_ATTR_FUNC_START_PHASE                                    /* ViReal64, multi-channel, degrees  */
#define TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH      IVIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH                                /* ViReal64, multi-channel, percent  */

#define TKAFG1K_ATTR_PULSE_DUTY_CYCLE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)

/*- Arbitrary Waveform Generation --------------------------------------*/
#define TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE       IVIFGEN_ATTR_ARB_WAVEFORM_HANDLE                                 /* ViInt32,  multi-channel         */
#define TKAFG1K_ATTR_ARB_GAIN                  IVIFGEN_ATTR_ARB_GAIN                                            /* ViReal64, multi-channel         */
#define TKAFG1K_ATTR_ARB_OFFSET                IVIFGEN_ATTR_ARB_OFFSET                                          /* ViReal64, multi-channel, volts  */
#define TKAFG1K_ATTR_ARB_SAMPLE_RATE           IVIFGEN_ATTR_ARB_SAMPLE_RATE                                     /* ViReal64, samples-per-second    */

#define TKAFG1K_ATTR_MAX_NUM_WAVEFORMS         IVIFGEN_ATTR_MAX_NUM_WAVEFORMS                                   /* ViInt32,  read-only             */
#define TKAFG1K_ATTR_WAVEFORM_QUANTUM          IVIFGEN_ATTR_WAVEFORM_QUANTUM                                    /* ViInt32,  read-only             */
#define TKAFG1K_ATTR_MIN_WAVEFORM_SIZE         IVIFGEN_ATTR_MIN_WAVEFORM_SIZE                                   /* ViInt32,  read-only             */
#define TKAFG1K_ATTR_MAX_WAVEFORM_SIZE         IVIFGEN_ATTR_MAX_WAVEFORM_SIZE                                   /* ViInt32,  read-only             */

#define TKAFG1K_ATTR_ARB_FREQUENCY             IVIFGEN_ATTR_ARB_FREQUENCY                                       /* ViReal64, multi-channel         */



/*- Burst Configuration ------------------------------------------------*/
#define TKAFG1K_ATTR_BURST_COUNT    IVIFGEN_ATTR_BURST_COUNT                                                    /* ViInt32, multi-channel */
#define TKAFG1K_ATTR_BURST_MODE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)


/*- Ampitude Modulation Generation -------------------------------------*/
#define TKAFG1K_ATTR_AM_ENABLED                          IVIFGEN_ATTR_AM_ENABLED                                /* ViBoolean, multi-channel             */
#define TKAFG1K_ATTR_AM_SOURCE                           IVIFGEN_ATTR_AM_SOURCE                                 /* ViInt32,   multi-channel             */
#define TKAFG1K_ATTR_AM_INTERNAL_DEPTH                   IVIFGEN_ATTR_AM_INTERNAL_DEPTH                         /* ViReal64,  percent                   */
#define TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM                IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM                      /* ViInt32                              */
#define TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY               IVIFGEN_ATTR_AM_INTERNAL_FREQUENCY                     /* ViReal64,  hertz                     */
#define TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)                  /* ViReal64,  multi-channel, percent    */
#define TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)                  /* ViInt32,   multi-channel             */
#define TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)                  /* ViReal64,  multi-channel, hertz      */

/*- Frequency Modulation Generation ------------------------------------*/
#define TKAFG1K_ATTR_FM_ENABLED                          IVIFGEN_ATTR_FM_ENABLED                                /* ViBoolean, multi-channel             */
#define TKAFG1K_ATTR_FM_SOURCE                           IVIFGEN_ATTR_FM_SOURCE                                 /* ViInt32,   multi-channel             */
#define TKAFG1K_ATTR_FM_INTERNAL_DEVIATION               IVIFGEN_ATTR_FM_INTERNAL_DEVIATION                     /* ViReal64,  hertz                     */
#define TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM                IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM                      /* ViInt32                              */
#define TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY               IVIFGEN_ATTR_FM_INTERNAL_FREQUENCY                     /* ViReal64,  hertz                     */
#define TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)                  /* ViReal64,  multi-channel, hertz      */
#define TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 24L)                  /* ViInt32,   multi-channel             */
#define TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)                  /* ViReal64,  multi-channel, hertz      */

/*- FSK Modulation Generation ------------------------------------------*/
#define TKAFG1K_ATTR_FSK_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)                  /* ViBoolean, multi-channel             */
#define TKAFG1K_ATTR_FSK_HOP_FREQUENCY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)                  /* ViReal64,  multi-channel, hertz      */
#define TKAFG1K_ATTR_FSK_INTERNAL_RATE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)                  /* ViReal64, multi-channel, hertz       */
#define TKAFG1K_ATTR_FSK_SOURCE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)                  /* ViInt32,  multi-channel              */

/*- Phase Modulation Generation ----------------------------------------*/
#define TKAFG1K_ATTR_PM_ENABLED                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)                  /* ViBoolean, multi-channel             */
#define TKAFG1K_ATTR_PM_SOURCE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 31L)                  /* ViInt32,   multi-channel             */
#define TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)                  /* ViReal64, multi-channel, deg         */
#define TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)                  /* ViReal64, multi-channel, hertz       */
#define TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L)                  /* ViInt32,  multi-channel              */

/*- Pulse Width Modulation Generation ----------------------------------*/
#define TKAFG1K_ATTR_PWM_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)                  /* ViBoolean, multi-channel             */
#define TKAFG1K_ATTR_PWM_SOURCE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)                  /* ViInt32,   multi-channel             */
#define TKAFG1K_ATTR_PWM_DEVIATION                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)                  /* ViReal64, multi-channel, percent     */
#define TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)                  /* ViReal64, multi-channel, hertz       */
#define TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)                  /* ViInt32,  multi-channel              */

/*- Miscellaneous Attributes -------------------------------------------*/
#define TKAFG1K_ATTR_ID_QUERY_RESPONSE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)                   /* ViString(Read Only) */
#define TKAFG1K_ATTR_SWEEP_START_FREQUENCY               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L)
#define TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L)
#define TKAFG1K_ATTR_ASK_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L)
#define TKAFG1K_ATTR_PSK_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 49L)
#define TKAFG1K_ATTR_ASK_SOURCE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 50L)
#define TKAFG1K_ATTR_PSK_SOURCE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L)
#define TKAFG1K_ATTR_ASK_INTERNAL_RATE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L)
#define TKAFG1K_ATTR_PSK_INTERNAL_RATE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L)
#define TKAFG1K_ATTR_ASK_AMPLITUDE                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 54L)
#define TKAFG1K_ATTR_PSK_DEVIATION                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 55L)
#define TKAFG1K_ATTR_REF_CLOCK_SOURCE                    IVIFGEN_ATTR_REF_CLOCK_SOURCE


/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/
/*- Defined Value for Instrument models -------------------------------*/
#define TKAFG1K_VAL_MODEL_AFG1022    0
#define TKAFG1K_VAL_MODEL_AFG1062    1


/*- Defined values for attribute TKAFG1K_ATTR_OPERATION_MODE --------------*/
#define TKAFG1K_VAL_OPERATE_CONTINUOUS       IVIFGEN_VAL_OPERATE_CONTINUOUS
#define TKAFG1K_VAL_OPERATE_MODULATION       (IVIFGEN_VAL_OP_MODE_SPECIFIC_EXT_BASE + 1)
#define TKAFG1K_VAL_OPERATE_SWEEP            (IVIFGEN_VAL_OP_MODE_SPECIFIC_EXT_BASE + 2)
#define TKAFG1K_VAL_OPERATE_BURST            IVIFGEN_VAL_OPERATE_BURST

/*- Defined values for attribute TKAFG1K_ATTR_ACTIVE_MEMORY --------------*/
#define TKAFG1K_VAL_OUTPUT_EMEM              (0L)

/*- Defined values for attribute TKAFG1K_ATTR_OUTPUT_MODE --------------*/
#define TKAFG1K_VAL_OUTPUT_FUNC              IVIFGEN_VAL_OUTPUT_FUNC
#define TKAFG1K_VAL_OUTPUT_ARB               IVIFGEN_VAL_OUTPUT_ARB

/*- Defined values for attribute TKAFG1K_ATTR_OUTPUT_IMPEDANCE ------*/
#define TKAFG1K_VAL_IMPEDANCE_INFINITY       0

/*- Defined values for attribute TKAFG1K_ATTR_REF_CLOCK_SOURCE ------*/
#define TKAFG1K_VAL_REF_CLOCK_INTERNAL       IVIFGEN_VAL_REF_CLOCK_INTERNAL
#define TKAFG1K_VAL_REF_CLOCK_EXTERNAL       IVIFGEN_VAL_REF_CLOCK_EXTERNAL

/*- Defined values for attribute TKAFG1K_ATTR_FUNC_WAVEFORM ---------*/
#define TKAFG1K_VAL_WFM_SINE                 IVIFGEN_VAL_WFM_SINE
#define TKAFG1K_VAL_WFM_SQUARE               IVIFGEN_VAL_WFM_SQUARE
/*- Extended standard waveform -*/
#define TKAFG1K_VAL_WFM_RAMP                 (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 1)
#define TKAFG1K_VAL_WFM_PULS                 (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 2)
#define TKAFG1K_VAL_WFM_PRN                  (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 3)
#define TKAFG1K_VAL_WFM_STAIRDOWN            (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 4)
#define TKAFG1K_VAL_WFM_STAIRUP              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 5)
#define TKAFG1K_VAL_WFM_STAIR                (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 6)
#define TKAFG1K_VAL_WFM_TRAPEZOID            (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 7)
#define TKAFG1K_VAL_WFM_ROUNDHALF            (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 8)
#define TKAFG1K_VAL_WFM_ABSSINE              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 9)
#define TKAFG1K_VAL_WFM_ABSHALFSINE          (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 10)
#define TKAFG1K_VAL_WFM_CLIPPEDSINE          (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 11)
#define TKAFG1K_VAL_WFM_CHOPPEDSINE          (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 12)
#define TKAFG1K_VAL_WFM_NEGRAMP              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 13)
#define TKAFG1K_VAL_WFM_OSCDECAY             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 14)
#define TKAFG1K_VAL_WFM_OSCRISE              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 15)
#define TKAFG1K_VAL_WFM_CODEDPULSE           (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 16)
#define TKAFG1K_VAL_WFM_POSPULSE             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 17)
#define TKAFG1K_VAL_WFM_NEGPULSE             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 18)
#define TKAFG1K_VAL_WFM_EXPRISE              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 19)
#define TKAFG1K_VAL_WFM_EXPDECAY             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 20)
#define TKAFG1K_VAL_WFM_SINC                 (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 21)
#define TKAFG1K_VAL_WFM_TAN                  (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 22)
#define TKAFG1K_VAL_WFM_COTAN                (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 23)
#define TKAFG1K_VAL_WFM_SQUAREROOT           (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 24)
#define TKAFG1K_VAL_WFM_X_2                  (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 25)
#define TKAFG1K_VAL_WFM_HAVERSINE            (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 26)
#define TKAFG1K_VAL_WFM_LORENTZ              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 27)
#define TKAFG1K_VAL_WFM_LN_X                 (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 28)
#define TKAFG1K_VAL_WFM_X_3                  (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 29)
#define TKAFG1K_VAL_WFM_CAUCHYDISTR          (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 30)
#define TKAFG1K_VAL_WFM_BESSELJ              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 31)
#define TKAFG1K_VAL_WFM_BESSELY              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 32)
#define TKAFG1K_VAL_WFM_ERRORFUNC            (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 33)
#define TKAFG1K_VAL_WFM_AIRY                 (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 34)
#define TKAFG1K_VAL_WFM_RECTANGLE            (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 35)
#define TKAFG1K_VAL_WFM_GAUSS                (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 36)
#define TKAFG1K_VAL_WFM_HAMMING              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 37)
#define TKAFG1K_VAL_WFM_HANNING              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 38)
#define TKAFG1K_VAL_WFM_BARTLETT             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 39)
#define TKAFG1K_VAL_WFM_BLACKMAN             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 40)
#define TKAFG1K_VAL_WFM_LAYLIGHT             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 41)
#define TKAFG1K_VAL_WFM_TRIANGLE             (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 42)
#define TKAFG1K_VAL_WFM_DC                   (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 43)
#define TKAFG1K_VAL_WFM_HEART                (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 44)
#define TKAFG1K_VAL_WFM_ROUND                (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 45)
#define TKAFG1K_VAL_WFM_CHIRP                (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 46)
#define TKAFG1K_VAL_WFM_RHOMBUS              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 47)
#define TKAFG1K_VAL_WFM_CARDIAC              (IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE + 48)

#define TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE    (10000L)
/*- Extended arbitrary waveform -*/
#define TKAFG1K_VAL_WFM_EMEM                 (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 1)
#define TKAFG1K_VAL_WFM_USER0                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 2)
#define TKAFG1K_VAL_WFM_USER1                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 3)
#define TKAFG1K_VAL_WFM_USER2                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 4)
#define TKAFG1K_VAL_WFM_USER3                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 5)
#define TKAFG1K_VAL_WFM_USER4                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 6)
#define TKAFG1K_VAL_WFM_USER5                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 7)
#define TKAFG1K_VAL_WFM_USER6                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 8)
#define TKAFG1K_VAL_WFM_USER7                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 9)
#define TKAFG1K_VAL_WFM_USER8                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 10)
#define TKAFG1K_VAL_WFM_USER9                (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 11)
#define TKAFG1K_VAL_WFM_USER10               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 12)
#define TKAFG1K_VAL_WFM_USER11               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 13)
#define TKAFG1K_VAL_WFM_USER12               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 14)
#define TKAFG1K_VAL_WFM_USER13               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 15)
#define TKAFG1K_VAL_WFM_USER14               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 16)
#define TKAFG1K_VAL_WFM_USER15               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 17)
#define TKAFG1K_VAL_WFM_USER16               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 18)
#define TKAFG1K_VAL_WFM_USER17               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 19)
#define TKAFG1K_VAL_WFM_USER18               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 20)
#define TKAFG1K_VAL_WFM_USER19               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 21)
#define TKAFG1K_VAL_WFM_USER20               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 22)
#define TKAFG1K_VAL_WFM_USER21               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 23)
#define TKAFG1K_VAL_WFM_USER22               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 24)
#define TKAFG1K_VAL_WFM_USER23               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 25)
#define TKAFG1K_VAL_WFM_USER24               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 26)
#define TKAFG1K_VAL_WFM_USER25               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 27)
#define TKAFG1K_VAL_WFM_USER26               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 28)
#define TKAFG1K_VAL_WFM_USER27               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 29)
#define TKAFG1K_VAL_WFM_USER28               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 30)
#define TKAFG1K_VAL_WFM_USER29               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 31)
#define TKAFG1K_VAL_WFM_USER30               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 32)
#define TKAFG1K_VAL_WFM_USER31               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 33)
#define TKAFG1K_VAL_WFM_USER32               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 34)
#define TKAFG1K_VAL_WFM_USER33               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 35)
#define TKAFG1K_VAL_WFM_USER34               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 36)
#define TKAFG1K_VAL_WFM_USER35               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 37)
#define TKAFG1K_VAL_WFM_USER36               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 38)
#define TKAFG1K_VAL_WFM_USER37               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 39)
#define TKAFG1K_VAL_WFM_USER38               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 40)
#define TKAFG1K_VAL_WFM_USER39               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 41)
#define TKAFG1K_VAL_WFM_USER40               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 42)
#define TKAFG1K_VAL_WFM_USER41               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 43)
#define TKAFG1K_VAL_WFM_USER42               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 44)
#define TKAFG1K_VAL_WFM_USER43               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 45)
#define TKAFG1K_VAL_WFM_USER44               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 46)
#define TKAFG1K_VAL_WFM_USER45               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 47)
#define TKAFG1K_VAL_WFM_USER46               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 48)
#define TKAFG1K_VAL_WFM_USER47               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 49)
#define TKAFG1K_VAL_WFM_USER48               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 50)
#define TKAFG1K_VAL_WFM_USER49               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 51)
#define TKAFG1K_VAL_WFM_USER50               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 52)
#define TKAFG1K_VAL_WFM_USER51               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 53)
#define TKAFG1K_VAL_WFM_USER52               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 54)
#define TKAFG1K_VAL_WFM_USER53               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 55)
#define TKAFG1K_VAL_WFM_USER54               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 56)
#define TKAFG1K_VAL_WFM_USER55               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 57)
#define TKAFG1K_VAL_WFM_USER56               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 58)
#define TKAFG1K_VAL_WFM_USER57               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 59)
#define TKAFG1K_VAL_WFM_USER58               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 60)
#define TKAFG1K_VAL_WFM_USER59               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 61)
#define TKAFG1K_VAL_WFM_USER60               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 62)
#define TKAFG1K_VAL_WFM_USER61               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 63)
#define TKAFG1K_VAL_WFM_USER62               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 64)
#define TKAFG1K_VAL_WFM_USER63               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 65)
#define TKAFG1K_VAL_WFM_USER64               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 66)
#define TKAFG1K_VAL_WFM_USER65               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 67)
#define TKAFG1K_VAL_WFM_USER66               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 68)
#define TKAFG1K_VAL_WFM_USER67               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 69)
#define TKAFG1K_VAL_WFM_USER68               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 70)
#define TKAFG1K_VAL_WFM_USER69               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 71)
#define TKAFG1K_VAL_WFM_USER70               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 72)
#define TKAFG1K_VAL_WFM_USER71               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 73)
#define TKAFG1K_VAL_WFM_USER72               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 74)
#define TKAFG1K_VAL_WFM_USER73               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 75)
#define TKAFG1K_VAL_WFM_USER74               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 76)
#define TKAFG1K_VAL_WFM_USER75               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 77)
#define TKAFG1K_VAL_WFM_USER76               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 78)
#define TKAFG1K_VAL_WFM_USER77               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 79)
#define TKAFG1K_VAL_WFM_USER78               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 80)
#define TKAFG1K_VAL_WFM_USER79               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 81)
#define TKAFG1K_VAL_WFM_USER80               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 82)
#define TKAFG1K_VAL_WFM_USER81               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 83)
#define TKAFG1K_VAL_WFM_USER82               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 84)
#define TKAFG1K_VAL_WFM_USER83               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 85)
#define TKAFG1K_VAL_WFM_USER84               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 86)
#define TKAFG1K_VAL_WFM_USER85               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 87)
#define TKAFG1K_VAL_WFM_USER86               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 88)
#define TKAFG1K_VAL_WFM_USER87               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 89)
#define TKAFG1K_VAL_WFM_USER88               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 90)
#define TKAFG1K_VAL_WFM_USER89               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 91)
#define TKAFG1K_VAL_WFM_USER90               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 92)
#define TKAFG1K_VAL_WFM_USER91               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 93)
#define TKAFG1K_VAL_WFM_USER92               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 94)
#define TKAFG1K_VAL_WFM_USER93               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 95)
#define TKAFG1K_VAL_WFM_USER94               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 96)
#define TKAFG1K_VAL_WFM_USER95               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 97)
#define TKAFG1K_VAL_WFM_USER96               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 98)
#define TKAFG1K_VAL_WFM_USER97               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 99)
#define TKAFG1K_VAL_WFM_USER98               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 100)
#define TKAFG1K_VAL_WFM_USER99               (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 101)
#define TKAFG1K_VAL_WFM_USER100              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 102)
#define TKAFG1K_VAL_WFM_USER101              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 103)
#define TKAFG1K_VAL_WFM_USER102              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 104)
#define TKAFG1K_VAL_WFM_USER103              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 105)
#define TKAFG1K_VAL_WFM_USER104              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 106)
#define TKAFG1K_VAL_WFM_USER105              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 107)
#define TKAFG1K_VAL_WFM_USER106              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 108)
#define TKAFG1K_VAL_WFM_USER107              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 109)
#define TKAFG1K_VAL_WFM_USER108              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 110)
#define TKAFG1K_VAL_WFM_USER109              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 111)
#define TKAFG1K_VAL_WFM_USER110              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 112)
#define TKAFG1K_VAL_WFM_USER111              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 113)
#define TKAFG1K_VAL_WFM_USER112              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 114)
#define TKAFG1K_VAL_WFM_USER113              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 115)
#define TKAFG1K_VAL_WFM_USER114              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 116)
#define TKAFG1K_VAL_WFM_USER115              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 117)
#define TKAFG1K_VAL_WFM_USER116              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 118)
#define TKAFG1K_VAL_WFM_USER117              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 119)
#define TKAFG1K_VAL_WFM_USER118              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 120)
#define TKAFG1K_VAL_WFM_USER119              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 121)
#define TKAFG1K_VAL_WFM_USER120              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 122)
#define TKAFG1K_VAL_WFM_USER121              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 123)
#define TKAFG1K_VAL_WFM_USER122              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 124)
#define TKAFG1K_VAL_WFM_USER123              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 125)
#define TKAFG1K_VAL_WFM_USER124              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 126)
#define TKAFG1K_VAL_WFM_USER125              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 127)
#define TKAFG1K_VAL_WFM_USER126              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 128)
#define TKAFG1K_VAL_WFM_USER127              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 129)
#define TKAFG1K_VAL_WFM_USER128              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 130)
#define TKAFG1K_VAL_WFM_USER129              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 131)
#define TKAFG1K_VAL_WFM_USER130              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 132)
#define TKAFG1K_VAL_WFM_USER131              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 133)
#define TKAFG1K_VAL_WFM_USER132              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 134)
#define TKAFG1K_VAL_WFM_USER133              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 135)
#define TKAFG1K_VAL_WFM_USER134              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 136)
#define TKAFG1K_VAL_WFM_USER135              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 137)
#define TKAFG1K_VAL_WFM_USER136              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 138)
#define TKAFG1K_VAL_WFM_USER137              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 139)
#define TKAFG1K_VAL_WFM_USER138              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 140)
#define TKAFG1K_VAL_WFM_USER139              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 141)
#define TKAFG1K_VAL_WFM_USER140              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 142)
#define TKAFG1K_VAL_WFM_USER141              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 143)
#define TKAFG1K_VAL_WFM_USER142              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 144)
#define TKAFG1K_VAL_WFM_USER143              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 145)
#define TKAFG1K_VAL_WFM_USER144              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 146)
#define TKAFG1K_VAL_WFM_USER145              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 147)
#define TKAFG1K_VAL_WFM_USER146              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 148)
#define TKAFG1K_VAL_WFM_USER147              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 149)
#define TKAFG1K_VAL_WFM_USER148              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 150)
#define TKAFG1K_VAL_WFM_USER149              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 151)
#define TKAFG1K_VAL_WFM_USER150              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 152)
#define TKAFG1K_VAL_WFM_USER151              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 153)
#define TKAFG1K_VAL_WFM_USER152              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 154)
#define TKAFG1K_VAL_WFM_USER153              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 155)
#define TKAFG1K_VAL_WFM_USER154              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 156)
#define TKAFG1K_VAL_WFM_USER155              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 157)
#define TKAFG1K_VAL_WFM_USER156              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 158)
#define TKAFG1K_VAL_WFM_USER157              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 159)
#define TKAFG1K_VAL_WFM_USER158              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 160)
#define TKAFG1K_VAL_WFM_USER159              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 161)
#define TKAFG1K_VAL_WFM_USER160              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 162)
#define TKAFG1K_VAL_WFM_USER161              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 163)
#define TKAFG1K_VAL_WFM_USER162              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 164)
#define TKAFG1K_VAL_WFM_USER163              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 165)
#define TKAFG1K_VAL_WFM_USER164              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 166)
#define TKAFG1K_VAL_WFM_USER165              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 167)
#define TKAFG1K_VAL_WFM_USER166              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 168)
#define TKAFG1K_VAL_WFM_USER167              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 169)
#define TKAFG1K_VAL_WFM_USER168              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 170)
#define TKAFG1K_VAL_WFM_USER169              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 171)
#define TKAFG1K_VAL_WFM_USER170              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 172)
#define TKAFG1K_VAL_WFM_USER171              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 173)
#define TKAFG1K_VAL_WFM_USER172              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 174)
#define TKAFG1K_VAL_WFM_USER173              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 175)
#define TKAFG1K_VAL_WFM_USER174              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 176)
#define TKAFG1K_VAL_WFM_USER175              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 177)
#define TKAFG1K_VAL_WFM_USER176              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 178)
#define TKAFG1K_VAL_WFM_USER177              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 179)
#define TKAFG1K_VAL_WFM_USER178              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 180)
#define TKAFG1K_VAL_WFM_USER179              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 181)
#define TKAFG1K_VAL_WFM_USER180              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 182)
#define TKAFG1K_VAL_WFM_USER181              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 183)
#define TKAFG1K_VAL_WFM_USER182              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 184)
#define TKAFG1K_VAL_WFM_USER183              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 185)
#define TKAFG1K_VAL_WFM_USER184              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 186)
#define TKAFG1K_VAL_WFM_USER185              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 187)
#define TKAFG1K_VAL_WFM_USER186              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 188)
#define TKAFG1K_VAL_WFM_USER187              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 189)
#define TKAFG1K_VAL_WFM_USER188              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 190)
#define TKAFG1K_VAL_WFM_USER189              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 191)
#define TKAFG1K_VAL_WFM_USER190              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 192)
#define TKAFG1K_VAL_WFM_USER191              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 193)
#define TKAFG1K_VAL_WFM_USER192              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 194)
#define TKAFG1K_VAL_WFM_USER193              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 195)
#define TKAFG1K_VAL_WFM_USER194              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 196)
#define TKAFG1K_VAL_WFM_USER195              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 197)
#define TKAFG1K_VAL_WFM_USER196              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 198)
#define TKAFG1K_VAL_WFM_USER197              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 199)
#define TKAFG1K_VAL_WFM_USER198              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 200)
#define TKAFG1K_VAL_WFM_USER199              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 201)
#define TKAFG1K_VAL_WFM_USER200              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 202)
#define TKAFG1K_VAL_WFM_USER201              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 203)
#define TKAFG1K_VAL_WFM_USER202              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 204)
#define TKAFG1K_VAL_WFM_USER203              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 205)
#define TKAFG1K_VAL_WFM_USER204              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 206)
#define TKAFG1K_VAL_WFM_USER205              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 207)
#define TKAFG1K_VAL_WFM_USER206              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 208)
#define TKAFG1K_VAL_WFM_USER207              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 209)
#define TKAFG1K_VAL_WFM_USER208              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 210)
#define TKAFG1K_VAL_WFM_USER209              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 211)
#define TKAFG1K_VAL_WFM_USER210              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 212)
#define TKAFG1K_VAL_WFM_USER211              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 213)
#define TKAFG1K_VAL_WFM_USER212              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 214)
#define TKAFG1K_VAL_WFM_USER213              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 215)
#define TKAFG1K_VAL_WFM_USER214              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 216)
#define TKAFG1K_VAL_WFM_USER215              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 217)
#define TKAFG1K_VAL_WFM_USER216              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 218)
#define TKAFG1K_VAL_WFM_USER217              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 219)
#define TKAFG1K_VAL_WFM_USER218              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 220)
#define TKAFG1K_VAL_WFM_USER219              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 221)
#define TKAFG1K_VAL_WFM_USER220              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 222)
#define TKAFG1K_VAL_WFM_USER221              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 223)
#define TKAFG1K_VAL_WFM_USER222              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 224)
#define TKAFG1K_VAL_WFM_USER223              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 225)
#define TKAFG1K_VAL_WFM_USER224              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 226)
#define TKAFG1K_VAL_WFM_USER225              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 227)
#define TKAFG1K_VAL_WFM_USER226              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 228)
#define TKAFG1K_VAL_WFM_USER227              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 229)
#define TKAFG1K_VAL_WFM_USER228              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 230)
#define TKAFG1K_VAL_WFM_USER229              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 231)
#define TKAFG1K_VAL_WFM_USER230              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 232)
#define TKAFG1K_VAL_WFM_USER231              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 233)
#define TKAFG1K_VAL_WFM_USER232              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 234)
#define TKAFG1K_VAL_WFM_USER233              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 235)
#define TKAFG1K_VAL_WFM_USER234              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 236)
#define TKAFG1K_VAL_WFM_USER235              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 237)
#define TKAFG1K_VAL_WFM_USER236              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 238)
#define TKAFG1K_VAL_WFM_USER237              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 239)
#define TKAFG1K_VAL_WFM_USER238              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 240)
#define TKAFG1K_VAL_WFM_USER239              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 241)
#define TKAFG1K_VAL_WFM_USER240              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 242)
#define TKAFG1K_VAL_WFM_USER241              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 243)
#define TKAFG1K_VAL_WFM_USER242              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 244)
#define TKAFG1K_VAL_WFM_USER243              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 245)
#define TKAFG1K_VAL_WFM_USER244              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 246)
#define TKAFG1K_VAL_WFM_USER245              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 247)
#define TKAFG1K_VAL_WFM_USER246              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 248)
#define TKAFG1K_VAL_WFM_USER247              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 249)
#define TKAFG1K_VAL_WFM_USER248              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 250)
#define TKAFG1K_VAL_WFM_USER249              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 251)
#define TKAFG1K_VAL_WFM_USER250              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 252)
#define TKAFG1K_VAL_WFM_USER251              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 253)
#define TKAFG1K_VAL_WFM_USER252              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 254)
#define TKAFG1K_VAL_WFM_USER253              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 255)
#define TKAFG1K_VAL_WFM_USER254              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 256)
#define TKAFG1K_VAL_WFM_USER255              (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + 257)




/*- Memory slot for the arbitrary waveform -*/
#define TKAFG1K_VAL_WFM_SLOT1           (0L)
#define TKAFG1K_VAL_WFM_SLOT2           (1L)
#define TKAFG1K_VAL_WFM_SLOT3           (2L)
#define TKAFG1K_VAL_WFM_SLOT4           (3L)

/*- Waveform point value opeartion -*/
#define TKAFG1K_VAL_WFM_SETPOINT        (0L)
#define TKAFG1K_VAL_WFM_GETPOINT        (1L)

/*- Defined values for Arbitrary Waveform Handles ---------------------------------*/
#define TKAFG1K_VAL_ALL_WAVEFORMS       IVIFGEN_VAL_ALL_WAVEFORMS

/*- Defined values for standard shape arbitrary waveform --------------------------*/
#define TKAFG1K_VAL_ARB_WFM_SINE        (1L)
#define TKAFG1K_VAL_ARB_WFM_SQUARE      (2L)
#define TKAFG1K_VAL_ARB_WFM_PULS        (3L)
#define TKAFG1K_VAL_ARB_WFM_RAMP        (4L)
#define TKAFG1K_VAL_ARB_WFM_PRN         (5L)

/*- Defined values for attribute TKAFG1K_ATTR_TRIGGER_SOURCE ----------------------*/
#define TKAFG1K_VAL_EXTERNAL            IVIFGEN_VAL_EXTERNAL
#define TKAFG1K_VAL_INTERNAL_TRIGGER    IVIFGEN_VAL_INTERNAL_TRIGGER

/*- Defined values for attribute TKAFG1K_ATTR_TRIGGER_MODE ------------------------*/
#define TKAFG1K_VAL_TRIGGER_TRIGGER     1
#define TKAFG1K_VAL_TRIGGER_SYNC        2

/*- Defined values for attribute TKAFG1K_ATTR_TRIGGER_SLOPE -----------------------*/
#define TKAFG1K_VAL_TRIGGER_POSITIVE    1
#define TKAFG1K_VAL_TRIGGER_NEGATIVE    2

/*- Deifined value for attribute TKAFG1K_ATTR_BURST_COUNT -------------------------*/
#define TKAFG1K_VAL_BURST_INFINITY      0


/*- Defined value for attribute TKAFG1K_ATTR_BURST_MODE ---------------------------*/
#define TKAFG1K_VAL_BURST_TRIGGER                         1
#define TKAFG1K_VAL_BURST_GATE                            2

/*- Defined value for attribute TKAFG1K_ATTR_SWEEP_TYPE ---------------------------*/
#define TKAFG1K_VAL_SWEEP_LINEAR                          1
#define TKAFG1K_VAL_SWEEP_LOGARITHMIC                     2

/*- Defined value for attribute TKAFG1K_ATTR_SWEEP_MODE ---------------------------*/
#define TKAFG1K_VAL_SWEEP_AUTO                            1
#define TKAFG1K_VAL_SWEEP_MANUAL                          2

/*- Defined values for attribute TKAFG1K_ATTR_AM_SOURCE -*/
#define TKAFG1K_VAL_AM_INTERNAL                           IVIFGEN_VAL_AM_INTERNAL
#define TKAFG1K_VAL_AM_EXTERNAL                           IVIFGEN_VAL_AM_EXTERNAL

/*- Defined values for attribute TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM -*/
#define TKAFG1K_VAL_AM_INTERNAL_SINE                      IVIFGEN_VAL_AM_INTERNAL_SINE
#define TKAFG1K_VAL_AM_INTERNAL_SQUARE                    IVIFGEN_VAL_AM_INTERNAL_SQUARE
#define TKAFG1K_VAL_AM_INTERNAL_RAMP_UP                   IVIFGEN_VAL_AM_INTERNAL_RAMP_UP
#define TKAFG1K_VAL_AM_INTERNAL_PRN                       (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 1)
#define TKAFG1K_VAL_AM_INTERNAL_EMEM                      (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 2)
#define TKAFG1K_VAL_AM_INTERNAL_USER0                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 3)
#define TKAFG1K_VAL_AM_INTERNAL_USER1                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 4)
#define TKAFG1K_VAL_AM_INTERNAL_USER2                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 5)
#define TKAFG1K_VAL_AM_INTERNAL_USER3                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 6)
#define TKAFG1K_VAL_AM_INTERNAL_USER4                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 7)
#define TKAFG1K_VAL_AM_INTERNAL_USER5                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 8)
#define TKAFG1K_VAL_AM_INTERNAL_USER6                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 9)
#define TKAFG1K_VAL_AM_INTERNAL_USER7                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 10)
#define TKAFG1K_VAL_AM_INTERNAL_USER8                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 11)
#define TKAFG1K_VAL_AM_INTERNAL_USER9                     (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 12)
#define TKAFG1K_VAL_AM_INTERNAL_USER10                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 13)
#define TKAFG1K_VAL_AM_INTERNAL_USER11                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 14)
#define TKAFG1K_VAL_AM_INTERNAL_USER12                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 15)
#define TKAFG1K_VAL_AM_INTERNAL_USER13                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 16)
#define TKAFG1K_VAL_AM_INTERNAL_USER14                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 17)
#define TKAFG1K_VAL_AM_INTERNAL_USER15                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 18)
#define TKAFG1K_VAL_AM_INTERNAL_USER16                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 19)
#define TKAFG1K_VAL_AM_INTERNAL_USER17                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 20)
#define TKAFG1K_VAL_AM_INTERNAL_USER18                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 21)
#define TKAFG1K_VAL_AM_INTERNAL_USER19                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 22)
#define TKAFG1K_VAL_AM_INTERNAL_USER20                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 23)
#define TKAFG1K_VAL_AM_INTERNAL_USER21                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 24)
#define TKAFG1K_VAL_AM_INTERNAL_USER22                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 25)
#define TKAFG1K_VAL_AM_INTERNAL_USER23                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 26)
#define TKAFG1K_VAL_AM_INTERNAL_USER24                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 27)
#define TKAFG1K_VAL_AM_INTERNAL_USER25                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 28)
#define TKAFG1K_VAL_AM_INTERNAL_USER26                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 29)
#define TKAFG1K_VAL_AM_INTERNAL_USER27                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 30)
#define TKAFG1K_VAL_AM_INTERNAL_USER28                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 31)
#define TKAFG1K_VAL_AM_INTERNAL_USER29                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 32)
#define TKAFG1K_VAL_AM_INTERNAL_USER30                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 33)
#define TKAFG1K_VAL_AM_INTERNAL_USER31                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 34)
#define TKAFG1K_VAL_AM_INTERNAL_USER32                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 35)
#define TKAFG1K_VAL_AM_INTERNAL_USER33                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 36)
#define TKAFG1K_VAL_AM_INTERNAL_USER34                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 37)
#define TKAFG1K_VAL_AM_INTERNAL_USER35                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 38)
#define TKAFG1K_VAL_AM_INTERNAL_USER36                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 39)
#define TKAFG1K_VAL_AM_INTERNAL_USER37                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 40)
#define TKAFG1K_VAL_AM_INTERNAL_USER38                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 41)
#define TKAFG1K_VAL_AM_INTERNAL_USER39                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 42)
#define TKAFG1K_VAL_AM_INTERNAL_USER40                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 43)
#define TKAFG1K_VAL_AM_INTERNAL_USER41                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 44)
#define TKAFG1K_VAL_AM_INTERNAL_USER42                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 45)
#define TKAFG1K_VAL_AM_INTERNAL_USER43                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 46)
#define TKAFG1K_VAL_AM_INTERNAL_USER44                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 47)
#define TKAFG1K_VAL_AM_INTERNAL_USER45                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 48)
#define TKAFG1K_VAL_AM_INTERNAL_USER46                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 49)
#define TKAFG1K_VAL_AM_INTERNAL_USER47                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 50)
#define TKAFG1K_VAL_AM_INTERNAL_USER48                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 51)
#define TKAFG1K_VAL_AM_INTERNAL_USER49                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 52)
#define TKAFG1K_VAL_AM_INTERNAL_USER50                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 53)
#define TKAFG1K_VAL_AM_INTERNAL_USER51                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 54)
#define TKAFG1K_VAL_AM_INTERNAL_USER52                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 55)
#define TKAFG1K_VAL_AM_INTERNAL_USER53                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 56)
#define TKAFG1K_VAL_AM_INTERNAL_USER54                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 57)
#define TKAFG1K_VAL_AM_INTERNAL_USER55                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 58)
#define TKAFG1K_VAL_AM_INTERNAL_USER56                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 59)
#define TKAFG1K_VAL_AM_INTERNAL_USER57                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 60)
#define TKAFG1K_VAL_AM_INTERNAL_USER58                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 61)
#define TKAFG1K_VAL_AM_INTERNAL_USER59                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 62)
#define TKAFG1K_VAL_AM_INTERNAL_USER60                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 63)
#define TKAFG1K_VAL_AM_INTERNAL_USER61                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 64)
#define TKAFG1K_VAL_AM_INTERNAL_USER62                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 65)
#define TKAFG1K_VAL_AM_INTERNAL_USER63                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 66)
#define TKAFG1K_VAL_AM_INTERNAL_USER64                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 67)
#define TKAFG1K_VAL_AM_INTERNAL_USER65                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 68)
#define TKAFG1K_VAL_AM_INTERNAL_USER66                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 69)
#define TKAFG1K_VAL_AM_INTERNAL_USER67                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 70)
#define TKAFG1K_VAL_AM_INTERNAL_USER68                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 71)
#define TKAFG1K_VAL_AM_INTERNAL_USER69                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 72)
#define TKAFG1K_VAL_AM_INTERNAL_USER70                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 73)
#define TKAFG1K_VAL_AM_INTERNAL_USER71                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 74)
#define TKAFG1K_VAL_AM_INTERNAL_USER72                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 75)
#define TKAFG1K_VAL_AM_INTERNAL_USER73                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 76)
#define TKAFG1K_VAL_AM_INTERNAL_USER74                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 77)
#define TKAFG1K_VAL_AM_INTERNAL_USER75                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 78)
#define TKAFG1K_VAL_AM_INTERNAL_USER76                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 79)
#define TKAFG1K_VAL_AM_INTERNAL_USER77                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 80)
#define TKAFG1K_VAL_AM_INTERNAL_USER78                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 81)
#define TKAFG1K_VAL_AM_INTERNAL_USER79                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 82)
#define TKAFG1K_VAL_AM_INTERNAL_USER80                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 83)
#define TKAFG1K_VAL_AM_INTERNAL_USER81                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 84)
#define TKAFG1K_VAL_AM_INTERNAL_USER82                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 85)
#define TKAFG1K_VAL_AM_INTERNAL_USER83                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 86)
#define TKAFG1K_VAL_AM_INTERNAL_USER84                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 87)
#define TKAFG1K_VAL_AM_INTERNAL_USER85                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 88)
#define TKAFG1K_VAL_AM_INTERNAL_USER86                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 89)
#define TKAFG1K_VAL_AM_INTERNAL_USER87                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 90)
#define TKAFG1K_VAL_AM_INTERNAL_USER88                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 91)
#define TKAFG1K_VAL_AM_INTERNAL_USER89                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 92)
#define TKAFG1K_VAL_AM_INTERNAL_USER90                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 93)
#define TKAFG1K_VAL_AM_INTERNAL_USER91                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 94)
#define TKAFG1K_VAL_AM_INTERNAL_USER92                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 95)
#define TKAFG1K_VAL_AM_INTERNAL_USER93                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 96)
#define TKAFG1K_VAL_AM_INTERNAL_USER94                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 97)
#define TKAFG1K_VAL_AM_INTERNAL_USER95                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 98)
#define TKAFG1K_VAL_AM_INTERNAL_USER96                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 99)
#define TKAFG1K_VAL_AM_INTERNAL_USER97                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 100)
#define TKAFG1K_VAL_AM_INTERNAL_USER98                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 101)
#define TKAFG1K_VAL_AM_INTERNAL_USER99                    (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 102)
#define TKAFG1K_VAL_AM_INTERNAL_USER100                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 103)
#define TKAFG1K_VAL_AM_INTERNAL_USER101                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 104)
#define TKAFG1K_VAL_AM_INTERNAL_USER102                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 105)
#define TKAFG1K_VAL_AM_INTERNAL_USER103                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 106)
#define TKAFG1K_VAL_AM_INTERNAL_USER104                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 107)
#define TKAFG1K_VAL_AM_INTERNAL_USER105                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 108)
#define TKAFG1K_VAL_AM_INTERNAL_USER106                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 109)
#define TKAFG1K_VAL_AM_INTERNAL_USER107                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 110)
#define TKAFG1K_VAL_AM_INTERNAL_USER108                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 111)
#define TKAFG1K_VAL_AM_INTERNAL_USER109                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 112)
#define TKAFG1K_VAL_AM_INTERNAL_USER110                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 113)
#define TKAFG1K_VAL_AM_INTERNAL_USER111                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 114)
#define TKAFG1K_VAL_AM_INTERNAL_USER112                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 115)
#define TKAFG1K_VAL_AM_INTERNAL_USER113                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 116)
#define TKAFG1K_VAL_AM_INTERNAL_USER114                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 117)
#define TKAFG1K_VAL_AM_INTERNAL_USER115                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 118)
#define TKAFG1K_VAL_AM_INTERNAL_USER116                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 119)
#define TKAFG1K_VAL_AM_INTERNAL_USER117                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 120)
#define TKAFG1K_VAL_AM_INTERNAL_USER118                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 121)
#define TKAFG1K_VAL_AM_INTERNAL_USER119                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 122)
#define TKAFG1K_VAL_AM_INTERNAL_USER120                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 123)
#define TKAFG1K_VAL_AM_INTERNAL_USER121                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 124)
#define TKAFG1K_VAL_AM_INTERNAL_USER122                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 125)
#define TKAFG1K_VAL_AM_INTERNAL_USER123                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 126)
#define TKAFG1K_VAL_AM_INTERNAL_USER124                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 127)
#define TKAFG1K_VAL_AM_INTERNAL_USER125                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 128)
#define TKAFG1K_VAL_AM_INTERNAL_USER126                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 129)
#define TKAFG1K_VAL_AM_INTERNAL_USER127                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 130)
#define TKAFG1K_VAL_AM_INTERNAL_USER128                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 131)
#define TKAFG1K_VAL_AM_INTERNAL_USER129                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 132)
#define TKAFG1K_VAL_AM_INTERNAL_USER130                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 133)
#define TKAFG1K_VAL_AM_INTERNAL_USER131                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 134)
#define TKAFG1K_VAL_AM_INTERNAL_USER132                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 135)
#define TKAFG1K_VAL_AM_INTERNAL_USER133                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 136)
#define TKAFG1K_VAL_AM_INTERNAL_USER134                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 137)
#define TKAFG1K_VAL_AM_INTERNAL_USER135                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 138)
#define TKAFG1K_VAL_AM_INTERNAL_USER136                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 139)
#define TKAFG1K_VAL_AM_INTERNAL_USER137                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 140)
#define TKAFG1K_VAL_AM_INTERNAL_USER138                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 141)
#define TKAFG1K_VAL_AM_INTERNAL_USER139                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 142)
#define TKAFG1K_VAL_AM_INTERNAL_USER140                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 143)
#define TKAFG1K_VAL_AM_INTERNAL_USER141                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 144)
#define TKAFG1K_VAL_AM_INTERNAL_USER142                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 145)
#define TKAFG1K_VAL_AM_INTERNAL_USER143                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 146)
#define TKAFG1K_VAL_AM_INTERNAL_USER144                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 147)
#define TKAFG1K_VAL_AM_INTERNAL_USER145                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 148)
#define TKAFG1K_VAL_AM_INTERNAL_USER146                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 149)
#define TKAFG1K_VAL_AM_INTERNAL_USER147                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 150)
#define TKAFG1K_VAL_AM_INTERNAL_USER148                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 151)
#define TKAFG1K_VAL_AM_INTERNAL_USER149                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 152)
#define TKAFG1K_VAL_AM_INTERNAL_USER150                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 153)
#define TKAFG1K_VAL_AM_INTERNAL_USER151                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 154)
#define TKAFG1K_VAL_AM_INTERNAL_USER152                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 155)
#define TKAFG1K_VAL_AM_INTERNAL_USER153                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 156)
#define TKAFG1K_VAL_AM_INTERNAL_USER154                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 157)
#define TKAFG1K_VAL_AM_INTERNAL_USER155                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 158)
#define TKAFG1K_VAL_AM_INTERNAL_USER156                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 159)
#define TKAFG1K_VAL_AM_INTERNAL_USER157                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 160)
#define TKAFG1K_VAL_AM_INTERNAL_USER158                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 161)
#define TKAFG1K_VAL_AM_INTERNAL_USER159                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 162)
#define TKAFG1K_VAL_AM_INTERNAL_USER160                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 163)
#define TKAFG1K_VAL_AM_INTERNAL_USER161                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 164)
#define TKAFG1K_VAL_AM_INTERNAL_USER162                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 165)
#define TKAFG1K_VAL_AM_INTERNAL_USER163                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 166)
#define TKAFG1K_VAL_AM_INTERNAL_USER164                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 167)
#define TKAFG1K_VAL_AM_INTERNAL_USER165                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 168)
#define TKAFG1K_VAL_AM_INTERNAL_USER166                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 169)
#define TKAFG1K_VAL_AM_INTERNAL_USER167                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 170)
#define TKAFG1K_VAL_AM_INTERNAL_USER168                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 171)
#define TKAFG1K_VAL_AM_INTERNAL_USER169                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 172)
#define TKAFG1K_VAL_AM_INTERNAL_USER170                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 173)
#define TKAFG1K_VAL_AM_INTERNAL_USER171                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 174)
#define TKAFG1K_VAL_AM_INTERNAL_USER172                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 175)
#define TKAFG1K_VAL_AM_INTERNAL_USER173                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 176)
#define TKAFG1K_VAL_AM_INTERNAL_USER174                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 177)
#define TKAFG1K_VAL_AM_INTERNAL_USER175                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 178)
#define TKAFG1K_VAL_AM_INTERNAL_USER176                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 179)
#define TKAFG1K_VAL_AM_INTERNAL_USER177                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 180)
#define TKAFG1K_VAL_AM_INTERNAL_USER178                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 181)
#define TKAFG1K_VAL_AM_INTERNAL_USER179                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 182)
#define TKAFG1K_VAL_AM_INTERNAL_USER180                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 183)
#define TKAFG1K_VAL_AM_INTERNAL_USER181                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 184)
#define TKAFG1K_VAL_AM_INTERNAL_USER182                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 185)
#define TKAFG1K_VAL_AM_INTERNAL_USER183                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 186)
#define TKAFG1K_VAL_AM_INTERNAL_USER184                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 187)
#define TKAFG1K_VAL_AM_INTERNAL_USER185                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 188)
#define TKAFG1K_VAL_AM_INTERNAL_USER186                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 189)
#define TKAFG1K_VAL_AM_INTERNAL_USER187                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 190)
#define TKAFG1K_VAL_AM_INTERNAL_USER188                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 191)
#define TKAFG1K_VAL_AM_INTERNAL_USER189                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 192)
#define TKAFG1K_VAL_AM_INTERNAL_USER190                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 193)
#define TKAFG1K_VAL_AM_INTERNAL_USER191                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 194)
#define TKAFG1K_VAL_AM_INTERNAL_USER192                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 195)
#define TKAFG1K_VAL_AM_INTERNAL_USER193                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 196)
#define TKAFG1K_VAL_AM_INTERNAL_USER194                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 197)
#define TKAFG1K_VAL_AM_INTERNAL_USER195                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 198)
#define TKAFG1K_VAL_AM_INTERNAL_USER196                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 199)
#define TKAFG1K_VAL_AM_INTERNAL_USER197                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 200)
#define TKAFG1K_VAL_AM_INTERNAL_USER198                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 201)
#define TKAFG1K_VAL_AM_INTERNAL_USER199                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 202)
#define TKAFG1K_VAL_AM_INTERNAL_USER200                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 203)
#define TKAFG1K_VAL_AM_INTERNAL_USER201                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 204)
#define TKAFG1K_VAL_AM_INTERNAL_USER202                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 205)
#define TKAFG1K_VAL_AM_INTERNAL_USER203                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 206)
#define TKAFG1K_VAL_AM_INTERNAL_USER204                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 207)
#define TKAFG1K_VAL_AM_INTERNAL_USER205                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 208)
#define TKAFG1K_VAL_AM_INTERNAL_USER206                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 209)
#define TKAFG1K_VAL_AM_INTERNAL_USER207                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 210)
#define TKAFG1K_VAL_AM_INTERNAL_USER208                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 211)
#define TKAFG1K_VAL_AM_INTERNAL_USER209                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 212)
#define TKAFG1K_VAL_AM_INTERNAL_USER210                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 213)
#define TKAFG1K_VAL_AM_INTERNAL_USER211                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 214)
#define TKAFG1K_VAL_AM_INTERNAL_USER212                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 215)
#define TKAFG1K_VAL_AM_INTERNAL_USER213                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 216)
#define TKAFG1K_VAL_AM_INTERNAL_USER214                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 217)
#define TKAFG1K_VAL_AM_INTERNAL_USER215                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 218)
#define TKAFG1K_VAL_AM_INTERNAL_USER216                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 219)
#define TKAFG1K_VAL_AM_INTERNAL_USER217                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 220)
#define TKAFG1K_VAL_AM_INTERNAL_USER218                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 221)
#define TKAFG1K_VAL_AM_INTERNAL_USER219                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 222)
#define TKAFG1K_VAL_AM_INTERNAL_USER220                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 223)
#define TKAFG1K_VAL_AM_INTERNAL_USER221                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 224)
#define TKAFG1K_VAL_AM_INTERNAL_USER222                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 225)
#define TKAFG1K_VAL_AM_INTERNAL_USER223                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 226)
#define TKAFG1K_VAL_AM_INTERNAL_USER224                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 227)
#define TKAFG1K_VAL_AM_INTERNAL_USER225                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 228)
#define TKAFG1K_VAL_AM_INTERNAL_USER226                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 229)
#define TKAFG1K_VAL_AM_INTERNAL_USER227                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 230)
#define TKAFG1K_VAL_AM_INTERNAL_USER228                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 231)
#define TKAFG1K_VAL_AM_INTERNAL_USER229                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 232)
#define TKAFG1K_VAL_AM_INTERNAL_USER230                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 233)
#define TKAFG1K_VAL_AM_INTERNAL_USER231                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 234)
#define TKAFG1K_VAL_AM_INTERNAL_USER232                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 235)
#define TKAFG1K_VAL_AM_INTERNAL_USER233                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 236)
#define TKAFG1K_VAL_AM_INTERNAL_USER234                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 237)
#define TKAFG1K_VAL_AM_INTERNAL_USER235                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 238)
#define TKAFG1K_VAL_AM_INTERNAL_USER236                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 239)
#define TKAFG1K_VAL_AM_INTERNAL_USER237                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 240)
#define TKAFG1K_VAL_AM_INTERNAL_USER238                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 241)
#define TKAFG1K_VAL_AM_INTERNAL_USER239                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 242)
#define TKAFG1K_VAL_AM_INTERNAL_USER240                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 243)
#define TKAFG1K_VAL_AM_INTERNAL_USER241                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 244)
#define TKAFG1K_VAL_AM_INTERNAL_USER242                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 245)
#define TKAFG1K_VAL_AM_INTERNAL_USER243                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 246)
#define TKAFG1K_VAL_AM_INTERNAL_USER244                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 247)
#define TKAFG1K_VAL_AM_INTERNAL_USER245                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 248)
#define TKAFG1K_VAL_AM_INTERNAL_USER246                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 249)
#define TKAFG1K_VAL_AM_INTERNAL_USER247                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 250)
#define TKAFG1K_VAL_AM_INTERNAL_USER248                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 251)
#define TKAFG1K_VAL_AM_INTERNAL_USER249                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 252)
#define TKAFG1K_VAL_AM_INTERNAL_USER250                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 253)
#define TKAFG1K_VAL_AM_INTERNAL_USER251                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 254)
#define TKAFG1K_VAL_AM_INTERNAL_USER252                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 255)
#define TKAFG1K_VAL_AM_INTERNAL_USER253                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 256)
#define TKAFG1K_VAL_AM_INTERNAL_USER254                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 257)
#define TKAFG1K_VAL_AM_INTERNAL_USER255                   (IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 258)

/*- Defined values for attribute TKAFG1K_ATTR_FSK_SOURCE -*/
#define TKAFG1K_VAL_FSK_INTERNAL                          (0L)
#define TKAFG1K_VAL_FSK_EXTERNAL                          (1L)

/*- Defined values for attribute TKAFG1K_ATTR_FM_SOURCE -*/
#define TKAFG1K_VAL_FM_INTERNAL                           IVIFGEN_VAL_FM_INTERNAL
#define TKAFG1K_VAL_FM_EXTERNAL                           IVIFGEN_VAL_FM_EXTERNAL

/*- Defined values for attribute TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM -*/
#define TKAFG1K_VAL_FM_INTERNAL_SINE                      IVIFGEN_VAL_FM_INTERNAL_SINE
#define TKAFG1K_VAL_FM_INTERNAL_SQUARE                    IVIFGEN_VAL_FM_INTERNAL_SQUARE
#define TKAFG1K_VAL_FM_INTERNAL_RAMP_UP                   IVIFGEN_VAL_FM_INTERNAL_RAMP_UP
#define TKAFG1K_VAL_FM_INTERNAL_PRN                       (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 1)
#define TKAFG1K_VAL_FM_INTERNAL_EMEM                      (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 2)
#define TKAFG1K_VAL_FM_INTERNAL_USER0                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 3)
#define TKAFG1K_VAL_FM_INTERNAL_USER1                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 4)
#define TKAFG1K_VAL_FM_INTERNAL_USER2                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 5)
#define TKAFG1K_VAL_FM_INTERNAL_USER3                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 6)
#define TKAFG1K_VAL_FM_INTERNAL_USER4                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 7)
#define TKAFG1K_VAL_FM_INTERNAL_USER5                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 8)
#define TKAFG1K_VAL_FM_INTERNAL_USER6                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 9)
#define TKAFG1K_VAL_FM_INTERNAL_USER7                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 10)
#define TKAFG1K_VAL_FM_INTERNAL_USER8                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 11)
#define TKAFG1K_VAL_FM_INTERNAL_USER9                     (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 12)
#define TKAFG1K_VAL_FM_INTERNAL_USER10                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 13)
#define TKAFG1K_VAL_FM_INTERNAL_USER11                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 14)
#define TKAFG1K_VAL_FM_INTERNAL_USER12                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 15)
#define TKAFG1K_VAL_FM_INTERNAL_USER13                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 16)
#define TKAFG1K_VAL_FM_INTERNAL_USER14                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 17)
#define TKAFG1K_VAL_FM_INTERNAL_USER15                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 18)
#define TKAFG1K_VAL_FM_INTERNAL_USER16                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 19)
#define TKAFG1K_VAL_FM_INTERNAL_USER17                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 20)
#define TKAFG1K_VAL_FM_INTERNAL_USER18                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 21)
#define TKAFG1K_VAL_FM_INTERNAL_USER19                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 22)
#define TKAFG1K_VAL_FM_INTERNAL_USER20                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 23)
#define TKAFG1K_VAL_FM_INTERNAL_USER21                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 24)
#define TKAFG1K_VAL_FM_INTERNAL_USER22                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 25)
#define TKAFG1K_VAL_FM_INTERNAL_USER23                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 26)
#define TKAFG1K_VAL_FM_INTERNAL_USER24                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 27)
#define TKAFG1K_VAL_FM_INTERNAL_USER25                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 28)
#define TKAFG1K_VAL_FM_INTERNAL_USER26                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 29)
#define TKAFG1K_VAL_FM_INTERNAL_USER27                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 30)
#define TKAFG1K_VAL_FM_INTERNAL_USER28                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 31)
#define TKAFG1K_VAL_FM_INTERNAL_USER29                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 32)
#define TKAFG1K_VAL_FM_INTERNAL_USER30                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 33)
#define TKAFG1K_VAL_FM_INTERNAL_USER31                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 34)
#define TKAFG1K_VAL_FM_INTERNAL_USER32                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 35)
#define TKAFG1K_VAL_FM_INTERNAL_USER33                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 36)
#define TKAFG1K_VAL_FM_INTERNAL_USER34                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 37)
#define TKAFG1K_VAL_FM_INTERNAL_USER35                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 38)
#define TKAFG1K_VAL_FM_INTERNAL_USER36                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 39)
#define TKAFG1K_VAL_FM_INTERNAL_USER37                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 40)
#define TKAFG1K_VAL_FM_INTERNAL_USER38                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 41)
#define TKAFG1K_VAL_FM_INTERNAL_USER39                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 42)
#define TKAFG1K_VAL_FM_INTERNAL_USER40                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 43)
#define TKAFG1K_VAL_FM_INTERNAL_USER41                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 44)
#define TKAFG1K_VAL_FM_INTERNAL_USER42                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 45)
#define TKAFG1K_VAL_FM_INTERNAL_USER43                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 46)
#define TKAFG1K_VAL_FM_INTERNAL_USER44                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 47)
#define TKAFG1K_VAL_FM_INTERNAL_USER45                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 48)
#define TKAFG1K_VAL_FM_INTERNAL_USER46                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 49)
#define TKAFG1K_VAL_FM_INTERNAL_USER47                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 50)
#define TKAFG1K_VAL_FM_INTERNAL_USER48                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 51)
#define TKAFG1K_VAL_FM_INTERNAL_USER49                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 52)
#define TKAFG1K_VAL_FM_INTERNAL_USER50                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 53)
#define TKAFG1K_VAL_FM_INTERNAL_USER51                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 54)
#define TKAFG1K_VAL_FM_INTERNAL_USER52                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 55)
#define TKAFG1K_VAL_FM_INTERNAL_USER53                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 56)
#define TKAFG1K_VAL_FM_INTERNAL_USER54                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 57)
#define TKAFG1K_VAL_FM_INTERNAL_USER55                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 58)
#define TKAFG1K_VAL_FM_INTERNAL_USER56                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 59)
#define TKAFG1K_VAL_FM_INTERNAL_USER57                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 60)
#define TKAFG1K_VAL_FM_INTERNAL_USER58                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 61)
#define TKAFG1K_VAL_FM_INTERNAL_USER59                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 62)
#define TKAFG1K_VAL_FM_INTERNAL_USER60                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 63)
#define TKAFG1K_VAL_FM_INTERNAL_USER61                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 64)
#define TKAFG1K_VAL_FM_INTERNAL_USER62                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 65)
#define TKAFG1K_VAL_FM_INTERNAL_USER63                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 66)
#define TKAFG1K_VAL_FM_INTERNAL_USER64                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 67)
#define TKAFG1K_VAL_FM_INTERNAL_USER65                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 68)
#define TKAFG1K_VAL_FM_INTERNAL_USER66                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 69)
#define TKAFG1K_VAL_FM_INTERNAL_USER67                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 70)
#define TKAFG1K_VAL_FM_INTERNAL_USER68                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 71)
#define TKAFG1K_VAL_FM_INTERNAL_USER69                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 72)
#define TKAFG1K_VAL_FM_INTERNAL_USER70                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 73)
#define TKAFG1K_VAL_FM_INTERNAL_USER71                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 74)
#define TKAFG1K_VAL_FM_INTERNAL_USER72                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 75)
#define TKAFG1K_VAL_FM_INTERNAL_USER73                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 76)
#define TKAFG1K_VAL_FM_INTERNAL_USER74                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 77)
#define TKAFG1K_VAL_FM_INTERNAL_USER75                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 78)
#define TKAFG1K_VAL_FM_INTERNAL_USER76                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 79)
#define TKAFG1K_VAL_FM_INTERNAL_USER77                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 80)
#define TKAFG1K_VAL_FM_INTERNAL_USER78                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 81)
#define TKAFG1K_VAL_FM_INTERNAL_USER79                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 82)
#define TKAFG1K_VAL_FM_INTERNAL_USER80                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 83)
#define TKAFG1K_VAL_FM_INTERNAL_USER81                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 84)
#define TKAFG1K_VAL_FM_INTERNAL_USER82                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 85)
#define TKAFG1K_VAL_FM_INTERNAL_USER83                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 86)
#define TKAFG1K_VAL_FM_INTERNAL_USER84                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 87)
#define TKAFG1K_VAL_FM_INTERNAL_USER85                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 88)
#define TKAFG1K_VAL_FM_INTERNAL_USER86                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 89)
#define TKAFG1K_VAL_FM_INTERNAL_USER87                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 90)
#define TKAFG1K_VAL_FM_INTERNAL_USER88                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 91)
#define TKAFG1K_VAL_FM_INTERNAL_USER89                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 92)
#define TKAFG1K_VAL_FM_INTERNAL_USER90                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 93)
#define TKAFG1K_VAL_FM_INTERNAL_USER91                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 94)
#define TKAFG1K_VAL_FM_INTERNAL_USER92                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 95)
#define TKAFG1K_VAL_FM_INTERNAL_USER93                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 96)
#define TKAFG1K_VAL_FM_INTERNAL_USER94                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 97)
#define TKAFG1K_VAL_FM_INTERNAL_USER95                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 98)
#define TKAFG1K_VAL_FM_INTERNAL_USER96                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 99)
#define TKAFG1K_VAL_FM_INTERNAL_USER97                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 100)
#define TKAFG1K_VAL_FM_INTERNAL_USER98                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 101)
#define TKAFG1K_VAL_FM_INTERNAL_USER99                    (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 102)
#define TKAFG1K_VAL_FM_INTERNAL_USER100                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 103)
#define TKAFG1K_VAL_FM_INTERNAL_USER101                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 104)
#define TKAFG1K_VAL_FM_INTERNAL_USER102                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 105)
#define TKAFG1K_VAL_FM_INTERNAL_USER103                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 106)
#define TKAFG1K_VAL_FM_INTERNAL_USER104                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 107)
#define TKAFG1K_VAL_FM_INTERNAL_USER105                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 108)
#define TKAFG1K_VAL_FM_INTERNAL_USER106                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 109)
#define TKAFG1K_VAL_FM_INTERNAL_USER107                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 110)
#define TKAFG1K_VAL_FM_INTERNAL_USER108                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 111)
#define TKAFG1K_VAL_FM_INTERNAL_USER109                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 112)
#define TKAFG1K_VAL_FM_INTERNAL_USER110                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 113)
#define TKAFG1K_VAL_FM_INTERNAL_USER111                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 114)
#define TKAFG1K_VAL_FM_INTERNAL_USER112                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 115)
#define TKAFG1K_VAL_FM_INTERNAL_USER113                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 116)
#define TKAFG1K_VAL_FM_INTERNAL_USER114                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 117)
#define TKAFG1K_VAL_FM_INTERNAL_USER115                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 118)
#define TKAFG1K_VAL_FM_INTERNAL_USER116                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 119)
#define TKAFG1K_VAL_FM_INTERNAL_USER117                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 120)
#define TKAFG1K_VAL_FM_INTERNAL_USER118                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 121)
#define TKAFG1K_VAL_FM_INTERNAL_USER119                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 122)
#define TKAFG1K_VAL_FM_INTERNAL_USER120                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 123)
#define TKAFG1K_VAL_FM_INTERNAL_USER121                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 124)
#define TKAFG1K_VAL_FM_INTERNAL_USER122                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 125)
#define TKAFG1K_VAL_FM_INTERNAL_USER123                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 126)
#define TKAFG1K_VAL_FM_INTERNAL_USER124                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 127)
#define TKAFG1K_VAL_FM_INTERNAL_USER125                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 128)
#define TKAFG1K_VAL_FM_INTERNAL_USER126                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 129)
#define TKAFG1K_VAL_FM_INTERNAL_USER127                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 130)
#define TKAFG1K_VAL_FM_INTERNAL_USER128                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 131)
#define TKAFG1K_VAL_FM_INTERNAL_USER129                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 132)
#define TKAFG1K_VAL_FM_INTERNAL_USER130                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 133)
#define TKAFG1K_VAL_FM_INTERNAL_USER131                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 134)
#define TKAFG1K_VAL_FM_INTERNAL_USER132                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 135)
#define TKAFG1K_VAL_FM_INTERNAL_USER133                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 136)
#define TKAFG1K_VAL_FM_INTERNAL_USER134                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 137)
#define TKAFG1K_VAL_FM_INTERNAL_USER135                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 138)
#define TKAFG1K_VAL_FM_INTERNAL_USER136                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 139)
#define TKAFG1K_VAL_FM_INTERNAL_USER137                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 140)
#define TKAFG1K_VAL_FM_INTERNAL_USER138                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 141)
#define TKAFG1K_VAL_FM_INTERNAL_USER139                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 142)
#define TKAFG1K_VAL_FM_INTERNAL_USER140                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 143)
#define TKAFG1K_VAL_FM_INTERNAL_USER141                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 144)
#define TKAFG1K_VAL_FM_INTERNAL_USER142                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 145)
#define TKAFG1K_VAL_FM_INTERNAL_USER143                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 146)
#define TKAFG1K_VAL_FM_INTERNAL_USER144                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 147)
#define TKAFG1K_VAL_FM_INTERNAL_USER145                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 148)
#define TKAFG1K_VAL_FM_INTERNAL_USER146                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 149)
#define TKAFG1K_VAL_FM_INTERNAL_USER147                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 150)
#define TKAFG1K_VAL_FM_INTERNAL_USER148                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 151)
#define TKAFG1K_VAL_FM_INTERNAL_USER149                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 152)
#define TKAFG1K_VAL_FM_INTERNAL_USER150                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 153)
#define TKAFG1K_VAL_FM_INTERNAL_USER151                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 154)
#define TKAFG1K_VAL_FM_INTERNAL_USER152                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 155)
#define TKAFG1K_VAL_FM_INTERNAL_USER153                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 156)
#define TKAFG1K_VAL_FM_INTERNAL_USER154                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 157)
#define TKAFG1K_VAL_FM_INTERNAL_USER155                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 158)
#define TKAFG1K_VAL_FM_INTERNAL_USER156                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 159)
#define TKAFG1K_VAL_FM_INTERNAL_USER157                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 160)
#define TKAFG1K_VAL_FM_INTERNAL_USER158                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 161)
#define TKAFG1K_VAL_FM_INTERNAL_USER159                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 162)
#define TKAFG1K_VAL_FM_INTERNAL_USER160                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 163)
#define TKAFG1K_VAL_FM_INTERNAL_USER161                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 164)
#define TKAFG1K_VAL_FM_INTERNAL_USER162                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 165)
#define TKAFG1K_VAL_FM_INTERNAL_USER163                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 166)
#define TKAFG1K_VAL_FM_INTERNAL_USER164                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 167)
#define TKAFG1K_VAL_FM_INTERNAL_USER165                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 168)
#define TKAFG1K_VAL_FM_INTERNAL_USER166                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 169)
#define TKAFG1K_VAL_FM_INTERNAL_USER167                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 170)
#define TKAFG1K_VAL_FM_INTERNAL_USER168                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 171)
#define TKAFG1K_VAL_FM_INTERNAL_USER169                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 172)
#define TKAFG1K_VAL_FM_INTERNAL_USER170                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 173)
#define TKAFG1K_VAL_FM_INTERNAL_USER171                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 174)
#define TKAFG1K_VAL_FM_INTERNAL_USER172                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 175)
#define TKAFG1K_VAL_FM_INTERNAL_USER173                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 176)
#define TKAFG1K_VAL_FM_INTERNAL_USER174                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 177)
#define TKAFG1K_VAL_FM_INTERNAL_USER175                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 178)
#define TKAFG1K_VAL_FM_INTERNAL_USER176                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 179)
#define TKAFG1K_VAL_FM_INTERNAL_USER177                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 180)
#define TKAFG1K_VAL_FM_INTERNAL_USER178                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 181)
#define TKAFG1K_VAL_FM_INTERNAL_USER179                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 182)
#define TKAFG1K_VAL_FM_INTERNAL_USER180                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 183)
#define TKAFG1K_VAL_FM_INTERNAL_USER181                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 184)
#define TKAFG1K_VAL_FM_INTERNAL_USER182                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 185)
#define TKAFG1K_VAL_FM_INTERNAL_USER183                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 186)
#define TKAFG1K_VAL_FM_INTERNAL_USER184                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 187)
#define TKAFG1K_VAL_FM_INTERNAL_USER185                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 188)
#define TKAFG1K_VAL_FM_INTERNAL_USER186                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 189)
#define TKAFG1K_VAL_FM_INTERNAL_USER187                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 190)
#define TKAFG1K_VAL_FM_INTERNAL_USER188                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 191)
#define TKAFG1K_VAL_FM_INTERNAL_USER189                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 192)
#define TKAFG1K_VAL_FM_INTERNAL_USER190                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 193)
#define TKAFG1K_VAL_FM_INTERNAL_USER191                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 194)
#define TKAFG1K_VAL_FM_INTERNAL_USER192                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 195)
#define TKAFG1K_VAL_FM_INTERNAL_USER193                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 196)
#define TKAFG1K_VAL_FM_INTERNAL_USER194                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 197)
#define TKAFG1K_VAL_FM_INTERNAL_USER195                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 198)
#define TKAFG1K_VAL_FM_INTERNAL_USER196                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 199)
#define TKAFG1K_VAL_FM_INTERNAL_USER197                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 200)
#define TKAFG1K_VAL_FM_INTERNAL_USER198                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 201)
#define TKAFG1K_VAL_FM_INTERNAL_USER199                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 202)
#define TKAFG1K_VAL_FM_INTERNAL_USER200                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 203)
#define TKAFG1K_VAL_FM_INTERNAL_USER201                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 204)
#define TKAFG1K_VAL_FM_INTERNAL_USER202                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 205)
#define TKAFG1K_VAL_FM_INTERNAL_USER203                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 206)
#define TKAFG1K_VAL_FM_INTERNAL_USER204                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 207)
#define TKAFG1K_VAL_FM_INTERNAL_USER205                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 208)
#define TKAFG1K_VAL_FM_INTERNAL_USER206                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 209)
#define TKAFG1K_VAL_FM_INTERNAL_USER207                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 210)
#define TKAFG1K_VAL_FM_INTERNAL_USER208                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 211)
#define TKAFG1K_VAL_FM_INTERNAL_USER209                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 212)
#define TKAFG1K_VAL_FM_INTERNAL_USER210                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 213)
#define TKAFG1K_VAL_FM_INTERNAL_USER211                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 214)
#define TKAFG1K_VAL_FM_INTERNAL_USER212                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 215)
#define TKAFG1K_VAL_FM_INTERNAL_USER213                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 216)
#define TKAFG1K_VAL_FM_INTERNAL_USER214                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 217)
#define TKAFG1K_VAL_FM_INTERNAL_USER215                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 218)
#define TKAFG1K_VAL_FM_INTERNAL_USER216                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 219)
#define TKAFG1K_VAL_FM_INTERNAL_USER217                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 220)
#define TKAFG1K_VAL_FM_INTERNAL_USER218                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 221)
#define TKAFG1K_VAL_FM_INTERNAL_USER219                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 222)
#define TKAFG1K_VAL_FM_INTERNAL_USER220                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 223)
#define TKAFG1K_VAL_FM_INTERNAL_USER221                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 224)
#define TKAFG1K_VAL_FM_INTERNAL_USER222                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 225)
#define TKAFG1K_VAL_FM_INTERNAL_USER223                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 226)
#define TKAFG1K_VAL_FM_INTERNAL_USER224                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 227)
#define TKAFG1K_VAL_FM_INTERNAL_USER225                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 228)
#define TKAFG1K_VAL_FM_INTERNAL_USER226                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 229)
#define TKAFG1K_VAL_FM_INTERNAL_USER227                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 230)
#define TKAFG1K_VAL_FM_INTERNAL_USER228                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 231)
#define TKAFG1K_VAL_FM_INTERNAL_USER229                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 232)
#define TKAFG1K_VAL_FM_INTERNAL_USER230                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 233)
#define TKAFG1K_VAL_FM_INTERNAL_USER231                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 234)
#define TKAFG1K_VAL_FM_INTERNAL_USER232                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 235)
#define TKAFG1K_VAL_FM_INTERNAL_USER233                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 236)
#define TKAFG1K_VAL_FM_INTERNAL_USER234                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 237)
#define TKAFG1K_VAL_FM_INTERNAL_USER235                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 238)
#define TKAFG1K_VAL_FM_INTERNAL_USER236                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 239)
#define TKAFG1K_VAL_FM_INTERNAL_USER237                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 240)
#define TKAFG1K_VAL_FM_INTERNAL_USER238                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 241)
#define TKAFG1K_VAL_FM_INTERNAL_USER239                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 242)
#define TKAFG1K_VAL_FM_INTERNAL_USER240                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 243)
#define TKAFG1K_VAL_FM_INTERNAL_USER241                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 244)
#define TKAFG1K_VAL_FM_INTERNAL_USER242                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 245)
#define TKAFG1K_VAL_FM_INTERNAL_USER243                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 246)
#define TKAFG1K_VAL_FM_INTERNAL_USER244                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 247)
#define TKAFG1K_VAL_FM_INTERNAL_USER245                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 248)
#define TKAFG1K_VAL_FM_INTERNAL_USER246                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 249)
#define TKAFG1K_VAL_FM_INTERNAL_USER247                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 250)
#define TKAFG1K_VAL_FM_INTERNAL_USER248                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 251)
#define TKAFG1K_VAL_FM_INTERNAL_USER249                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 252)
#define TKAFG1K_VAL_FM_INTERNAL_USER250                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 253)
#define TKAFG1K_VAL_FM_INTERNAL_USER251                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 254)
#define TKAFG1K_VAL_FM_INTERNAL_USER252                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 255)
#define TKAFG1K_VAL_FM_INTERNAL_USER253                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 256)
#define TKAFG1K_VAL_FM_INTERNAL_USER254                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 257)
#define TKAFG1K_VAL_FM_INTERNAL_USER255                   (IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 258)

/*- Defined values for attribute TKAFG1K_ATTR_PM_SOURCE -*/
#define TKAFG1K_VAL_PM_INTERNAL                           (0L)
#define TKAFG1K_VAL_PM_EXTERNAL                           (1L)

#define TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE     (1000L)
/*- Defined values for attribute TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL -*/
#define TKAFG1K_VAL_PM_INTERNAL_SINE                      (1L)
#define TKAFG1K_VAL_PM_INTERNAL_SQUARE                    (2L)
#define TKAFG1K_VAL_PM_INTERNAL_RAMP_UP                   (4L)
#define TKAFG1K_VAL_PM_INTERNAL_PRN                       (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 1)
#define TKAFG1K_VAL_PM_INTERNAL_EMEM                      (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 2)
#define TKAFG1K_VAL_PM_INTERNAL_USER0                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 3)
#define TKAFG1K_VAL_PM_INTERNAL_USER1                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 4)
#define TKAFG1K_VAL_PM_INTERNAL_USER2                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 5)
#define TKAFG1K_VAL_PM_INTERNAL_USER3                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 6)
#define TKAFG1K_VAL_PM_INTERNAL_USER4                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 7)
#define TKAFG1K_VAL_PM_INTERNAL_USER5                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 8)
#define TKAFG1K_VAL_PM_INTERNAL_USER6                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 9)
#define TKAFG1K_VAL_PM_INTERNAL_USER7                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 10)
#define TKAFG1K_VAL_PM_INTERNAL_USER8                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 11)
#define TKAFG1K_VAL_PM_INTERNAL_USER9                     (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 12)
#define TKAFG1K_VAL_PM_INTERNAL_USER10                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 13)
#define TKAFG1K_VAL_PM_INTERNAL_USER11                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 14)
#define TKAFG1K_VAL_PM_INTERNAL_USER12                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 15)
#define TKAFG1K_VAL_PM_INTERNAL_USER13                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 16)
#define TKAFG1K_VAL_PM_INTERNAL_USER14                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 17)
#define TKAFG1K_VAL_PM_INTERNAL_USER15                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 18)
#define TKAFG1K_VAL_PM_INTERNAL_USER16                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 19)
#define TKAFG1K_VAL_PM_INTERNAL_USER17                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 20)
#define TKAFG1K_VAL_PM_INTERNAL_USER18                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 21)
#define TKAFG1K_VAL_PM_INTERNAL_USER19                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 22)
#define TKAFG1K_VAL_PM_INTERNAL_USER20                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 23)
#define TKAFG1K_VAL_PM_INTERNAL_USER21                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 24)
#define TKAFG1K_VAL_PM_INTERNAL_USER22                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 25)
#define TKAFG1K_VAL_PM_INTERNAL_USER23                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 26)
#define TKAFG1K_VAL_PM_INTERNAL_USER24                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 27)
#define TKAFG1K_VAL_PM_INTERNAL_USER25                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 28)
#define TKAFG1K_VAL_PM_INTERNAL_USER26                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 29)
#define TKAFG1K_VAL_PM_INTERNAL_USER27                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 30)
#define TKAFG1K_VAL_PM_INTERNAL_USER28                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 31)
#define TKAFG1K_VAL_PM_INTERNAL_USER29                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 32)
#define TKAFG1K_VAL_PM_INTERNAL_USER30                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 33)
#define TKAFG1K_VAL_PM_INTERNAL_USER31                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 34)
#define TKAFG1K_VAL_PM_INTERNAL_USER32                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 35)
#define TKAFG1K_VAL_PM_INTERNAL_USER33                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 36)
#define TKAFG1K_VAL_PM_INTERNAL_USER34                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 37)
#define TKAFG1K_VAL_PM_INTERNAL_USER35                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 38)
#define TKAFG1K_VAL_PM_INTERNAL_USER36                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 39)
#define TKAFG1K_VAL_PM_INTERNAL_USER37                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 40)
#define TKAFG1K_VAL_PM_INTERNAL_USER38                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 41)
#define TKAFG1K_VAL_PM_INTERNAL_USER39                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 42)
#define TKAFG1K_VAL_PM_INTERNAL_USER40                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 43)
#define TKAFG1K_VAL_PM_INTERNAL_USER41                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 44)
#define TKAFG1K_VAL_PM_INTERNAL_USER42                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 45)
#define TKAFG1K_VAL_PM_INTERNAL_USER43                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 46)
#define TKAFG1K_VAL_PM_INTERNAL_USER44                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 47)
#define TKAFG1K_VAL_PM_INTERNAL_USER45                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 48)
#define TKAFG1K_VAL_PM_INTERNAL_USER46                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 49)
#define TKAFG1K_VAL_PM_INTERNAL_USER47                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 50)
#define TKAFG1K_VAL_PM_INTERNAL_USER48                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 51)
#define TKAFG1K_VAL_PM_INTERNAL_USER49                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 52)
#define TKAFG1K_VAL_PM_INTERNAL_USER50                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 53)
#define TKAFG1K_VAL_PM_INTERNAL_USER51                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 54)
#define TKAFG1K_VAL_PM_INTERNAL_USER52                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 55)
#define TKAFG1K_VAL_PM_INTERNAL_USER53                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 56)
#define TKAFG1K_VAL_PM_INTERNAL_USER54                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 57)
#define TKAFG1K_VAL_PM_INTERNAL_USER55                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 58)
#define TKAFG1K_VAL_PM_INTERNAL_USER56                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 59)
#define TKAFG1K_VAL_PM_INTERNAL_USER57                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 60)
#define TKAFG1K_VAL_PM_INTERNAL_USER58                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 61)
#define TKAFG1K_VAL_PM_INTERNAL_USER59                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 62)
#define TKAFG1K_VAL_PM_INTERNAL_USER60                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 63)
#define TKAFG1K_VAL_PM_INTERNAL_USER61                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 64)
#define TKAFG1K_VAL_PM_INTERNAL_USER62                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 65)
#define TKAFG1K_VAL_PM_INTERNAL_USER63                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 66)
#define TKAFG1K_VAL_PM_INTERNAL_USER64                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 67)
#define TKAFG1K_VAL_PM_INTERNAL_USER65                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 68)
#define TKAFG1K_VAL_PM_INTERNAL_USER66                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 69)
#define TKAFG1K_VAL_PM_INTERNAL_USER67                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 70)
#define TKAFG1K_VAL_PM_INTERNAL_USER68                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 71)
#define TKAFG1K_VAL_PM_INTERNAL_USER69                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 72)
#define TKAFG1K_VAL_PM_INTERNAL_USER70                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 73)
#define TKAFG1K_VAL_PM_INTERNAL_USER71                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 74)
#define TKAFG1K_VAL_PM_INTERNAL_USER72                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 75)
#define TKAFG1K_VAL_PM_INTERNAL_USER73                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 76)
#define TKAFG1K_VAL_PM_INTERNAL_USER74                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 77)
#define TKAFG1K_VAL_PM_INTERNAL_USER75                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 78)
#define TKAFG1K_VAL_PM_INTERNAL_USER76                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 79)
#define TKAFG1K_VAL_PM_INTERNAL_USER77                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 80)
#define TKAFG1K_VAL_PM_INTERNAL_USER78                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 81)
#define TKAFG1K_VAL_PM_INTERNAL_USER79                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 82)
#define TKAFG1K_VAL_PM_INTERNAL_USER80                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 83)
#define TKAFG1K_VAL_PM_INTERNAL_USER81                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 84)
#define TKAFG1K_VAL_PM_INTERNAL_USER82                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 85)
#define TKAFG1K_VAL_PM_INTERNAL_USER83                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 86)
#define TKAFG1K_VAL_PM_INTERNAL_USER84                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 87)
#define TKAFG1K_VAL_PM_INTERNAL_USER85                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 88)
#define TKAFG1K_VAL_PM_INTERNAL_USER86                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 89)
#define TKAFG1K_VAL_PM_INTERNAL_USER87                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 90)
#define TKAFG1K_VAL_PM_INTERNAL_USER88                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 91)
#define TKAFG1K_VAL_PM_INTERNAL_USER89                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 92)
#define TKAFG1K_VAL_PM_INTERNAL_USER90                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 93)
#define TKAFG1K_VAL_PM_INTERNAL_USER91                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 94)
#define TKAFG1K_VAL_PM_INTERNAL_USER92                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 95)
#define TKAFG1K_VAL_PM_INTERNAL_USER93                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 96)
#define TKAFG1K_VAL_PM_INTERNAL_USER94                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 97)
#define TKAFG1K_VAL_PM_INTERNAL_USER95                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 98)
#define TKAFG1K_VAL_PM_INTERNAL_USER96                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 99)
#define TKAFG1K_VAL_PM_INTERNAL_USER97                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 100)
#define TKAFG1K_VAL_PM_INTERNAL_USER98                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 101)
#define TKAFG1K_VAL_PM_INTERNAL_USER99                    (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 102)
#define TKAFG1K_VAL_PM_INTERNAL_USER100                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 103)
#define TKAFG1K_VAL_PM_INTERNAL_USER101                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 104)
#define TKAFG1K_VAL_PM_INTERNAL_USER102                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 105)
#define TKAFG1K_VAL_PM_INTERNAL_USER103                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 106)
#define TKAFG1K_VAL_PM_INTERNAL_USER104                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 107)
#define TKAFG1K_VAL_PM_INTERNAL_USER105                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 108)
#define TKAFG1K_VAL_PM_INTERNAL_USER106                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 109)
#define TKAFG1K_VAL_PM_INTERNAL_USER107                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 110)
#define TKAFG1K_VAL_PM_INTERNAL_USER108                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 111)
#define TKAFG1K_VAL_PM_INTERNAL_USER109                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 112)
#define TKAFG1K_VAL_PM_INTERNAL_USER110                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 113)
#define TKAFG1K_VAL_PM_INTERNAL_USER111                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 114)
#define TKAFG1K_VAL_PM_INTERNAL_USER112                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 115)
#define TKAFG1K_VAL_PM_INTERNAL_USER113                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 116)
#define TKAFG1K_VAL_PM_INTERNAL_USER114                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 117)
#define TKAFG1K_VAL_PM_INTERNAL_USER115                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 118)
#define TKAFG1K_VAL_PM_INTERNAL_USER116                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 119)
#define TKAFG1K_VAL_PM_INTERNAL_USER117                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 120)
#define TKAFG1K_VAL_PM_INTERNAL_USER118                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 121)
#define TKAFG1K_VAL_PM_INTERNAL_USER119                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 122)
#define TKAFG1K_VAL_PM_INTERNAL_USER120                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 123)
#define TKAFG1K_VAL_PM_INTERNAL_USER121                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 124)
#define TKAFG1K_VAL_PM_INTERNAL_USER122                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 125)
#define TKAFG1K_VAL_PM_INTERNAL_USER123                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 126)
#define TKAFG1K_VAL_PM_INTERNAL_USER124                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 127)
#define TKAFG1K_VAL_PM_INTERNAL_USER125                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 128)
#define TKAFG1K_VAL_PM_INTERNAL_USER126                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 129)
#define TKAFG1K_VAL_PM_INTERNAL_USER127                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 130)
#define TKAFG1K_VAL_PM_INTERNAL_USER128                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 131)
#define TKAFG1K_VAL_PM_INTERNAL_USER129                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 132)
#define TKAFG1K_VAL_PM_INTERNAL_USER130                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 133)
#define TKAFG1K_VAL_PM_INTERNAL_USER131                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 134)
#define TKAFG1K_VAL_PM_INTERNAL_USER132                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 135)
#define TKAFG1K_VAL_PM_INTERNAL_USER133                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 136)
#define TKAFG1K_VAL_PM_INTERNAL_USER134                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 137)
#define TKAFG1K_VAL_PM_INTERNAL_USER135                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 138)
#define TKAFG1K_VAL_PM_INTERNAL_USER136                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 139)
#define TKAFG1K_VAL_PM_INTERNAL_USER137                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 140)
#define TKAFG1K_VAL_PM_INTERNAL_USER138                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 141)
#define TKAFG1K_VAL_PM_INTERNAL_USER139                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 142)
#define TKAFG1K_VAL_PM_INTERNAL_USER140                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 143)
#define TKAFG1K_VAL_PM_INTERNAL_USER141                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 144)
#define TKAFG1K_VAL_PM_INTERNAL_USER142                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 145)
#define TKAFG1K_VAL_PM_INTERNAL_USER143                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 146)
#define TKAFG1K_VAL_PM_INTERNAL_USER144                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 147)
#define TKAFG1K_VAL_PM_INTERNAL_USER145                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 148)
#define TKAFG1K_VAL_PM_INTERNAL_USER146                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 149)
#define TKAFG1K_VAL_PM_INTERNAL_USER147                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 150)
#define TKAFG1K_VAL_PM_INTERNAL_USER148                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 151)
#define TKAFG1K_VAL_PM_INTERNAL_USER149                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 152)
#define TKAFG1K_VAL_PM_INTERNAL_USER150                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 153)
#define TKAFG1K_VAL_PM_INTERNAL_USER151                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 154)
#define TKAFG1K_VAL_PM_INTERNAL_USER152                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 155)
#define TKAFG1K_VAL_PM_INTERNAL_USER153                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 156)
#define TKAFG1K_VAL_PM_INTERNAL_USER154                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 157)
#define TKAFG1K_VAL_PM_INTERNAL_USER155                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 158)
#define TKAFG1K_VAL_PM_INTERNAL_USER156                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 159)
#define TKAFG1K_VAL_PM_INTERNAL_USER157                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 160)
#define TKAFG1K_VAL_PM_INTERNAL_USER158                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 161)
#define TKAFG1K_VAL_PM_INTERNAL_USER159                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 162)
#define TKAFG1K_VAL_PM_INTERNAL_USER160                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 163)
#define TKAFG1K_VAL_PM_INTERNAL_USER161                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 164)
#define TKAFG1K_VAL_PM_INTERNAL_USER162                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 165)
#define TKAFG1K_VAL_PM_INTERNAL_USER163                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 166)
#define TKAFG1K_VAL_PM_INTERNAL_USER164                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 167)
#define TKAFG1K_VAL_PM_INTERNAL_USER165                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 168)
#define TKAFG1K_VAL_PM_INTERNAL_USER166                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 169)
#define TKAFG1K_VAL_PM_INTERNAL_USER167                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 170)
#define TKAFG1K_VAL_PM_INTERNAL_USER168                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 171)
#define TKAFG1K_VAL_PM_INTERNAL_USER169                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 172)
#define TKAFG1K_VAL_PM_INTERNAL_USER170                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 173)
#define TKAFG1K_VAL_PM_INTERNAL_USER171                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 174)
#define TKAFG1K_VAL_PM_INTERNAL_USER172                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 175)
#define TKAFG1K_VAL_PM_INTERNAL_USER173                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 176)
#define TKAFG1K_VAL_PM_INTERNAL_USER174                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 177)
#define TKAFG1K_VAL_PM_INTERNAL_USER175                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 178)
#define TKAFG1K_VAL_PM_INTERNAL_USER176                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 179)
#define TKAFG1K_VAL_PM_INTERNAL_USER177                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 180)
#define TKAFG1K_VAL_PM_INTERNAL_USER178                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 181)
#define TKAFG1K_VAL_PM_INTERNAL_USER179                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 182)
#define TKAFG1K_VAL_PM_INTERNAL_USER180                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 183)
#define TKAFG1K_VAL_PM_INTERNAL_USER181                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 184)
#define TKAFG1K_VAL_PM_INTERNAL_USER182                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 185)
#define TKAFG1K_VAL_PM_INTERNAL_USER183                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 186)
#define TKAFG1K_VAL_PM_INTERNAL_USER184                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 187)
#define TKAFG1K_VAL_PM_INTERNAL_USER185                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 188)
#define TKAFG1K_VAL_PM_INTERNAL_USER186                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 189)
#define TKAFG1K_VAL_PM_INTERNAL_USER187                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 190)
#define TKAFG1K_VAL_PM_INTERNAL_USER188                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 191)
#define TKAFG1K_VAL_PM_INTERNAL_USER189                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 192)
#define TKAFG1K_VAL_PM_INTERNAL_USER190                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 193)
#define TKAFG1K_VAL_PM_INTERNAL_USER191                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 194)
#define TKAFG1K_VAL_PM_INTERNAL_USER192                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 195)
#define TKAFG1K_VAL_PM_INTERNAL_USER193                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 196)
#define TKAFG1K_VAL_PM_INTERNAL_USER194                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 197)
#define TKAFG1K_VAL_PM_INTERNAL_USER195                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 198)
#define TKAFG1K_VAL_PM_INTERNAL_USER196                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 199)
#define TKAFG1K_VAL_PM_INTERNAL_USER197                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 200)
#define TKAFG1K_VAL_PM_INTERNAL_USER198                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 201)
#define TKAFG1K_VAL_PM_INTERNAL_USER199                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 202)
#define TKAFG1K_VAL_PM_INTERNAL_USER200                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 203)
#define TKAFG1K_VAL_PM_INTERNAL_USER201                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 204)
#define TKAFG1K_VAL_PM_INTERNAL_USER202                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 205)
#define TKAFG1K_VAL_PM_INTERNAL_USER203                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 206)
#define TKAFG1K_VAL_PM_INTERNAL_USER204                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 207)
#define TKAFG1K_VAL_PM_INTERNAL_USER205                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 208)
#define TKAFG1K_VAL_PM_INTERNAL_USER206                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 209)
#define TKAFG1K_VAL_PM_INTERNAL_USER207                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 210)
#define TKAFG1K_VAL_PM_INTERNAL_USER208                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 211)
#define TKAFG1K_VAL_PM_INTERNAL_USER209                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 212)
#define TKAFG1K_VAL_PM_INTERNAL_USER210                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 213)
#define TKAFG1K_VAL_PM_INTERNAL_USER211                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 214)
#define TKAFG1K_VAL_PM_INTERNAL_USER212                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 215)
#define TKAFG1K_VAL_PM_INTERNAL_USER213                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 216)
#define TKAFG1K_VAL_PM_INTERNAL_USER214                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 217)
#define TKAFG1K_VAL_PM_INTERNAL_USER215                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 218)
#define TKAFG1K_VAL_PM_INTERNAL_USER216                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 219)
#define TKAFG1K_VAL_PM_INTERNAL_USER217                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 220)
#define TKAFG1K_VAL_PM_INTERNAL_USER218                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 221)
#define TKAFG1K_VAL_PM_INTERNAL_USER219                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 222)
#define TKAFG1K_VAL_PM_INTERNAL_USER220                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 223)
#define TKAFG1K_VAL_PM_INTERNAL_USER221                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 224)
#define TKAFG1K_VAL_PM_INTERNAL_USER222                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 225)
#define TKAFG1K_VAL_PM_INTERNAL_USER223                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 226)
#define TKAFG1K_VAL_PM_INTERNAL_USER224                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 227)
#define TKAFG1K_VAL_PM_INTERNAL_USER225                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 228)
#define TKAFG1K_VAL_PM_INTERNAL_USER226                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 229)
#define TKAFG1K_VAL_PM_INTERNAL_USER227                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 230)
#define TKAFG1K_VAL_PM_INTERNAL_USER228                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 231)
#define TKAFG1K_VAL_PM_INTERNAL_USER229                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 232)
#define TKAFG1K_VAL_PM_INTERNAL_USER230                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 233)
#define TKAFG1K_VAL_PM_INTERNAL_USER231                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 234)
#define TKAFG1K_VAL_PM_INTERNAL_USER232                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 235)
#define TKAFG1K_VAL_PM_INTERNAL_USER233                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 236)
#define TKAFG1K_VAL_PM_INTERNAL_USER234                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 237)
#define TKAFG1K_VAL_PM_INTERNAL_USER235                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 238)
#define TKAFG1K_VAL_PM_INTERNAL_USER236                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 239)
#define TKAFG1K_VAL_PM_INTERNAL_USER237                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 240)
#define TKAFG1K_VAL_PM_INTERNAL_USER238                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 241)
#define TKAFG1K_VAL_PM_INTERNAL_USER239                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 242)
#define TKAFG1K_VAL_PM_INTERNAL_USER240                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 243)
#define TKAFG1K_VAL_PM_INTERNAL_USER241                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 244)
#define TKAFG1K_VAL_PM_INTERNAL_USER242                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 245)
#define TKAFG1K_VAL_PM_INTERNAL_USER243                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 246)
#define TKAFG1K_VAL_PM_INTERNAL_USER244                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 247)
#define TKAFG1K_VAL_PM_INTERNAL_USER245                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 248)
#define TKAFG1K_VAL_PM_INTERNAL_USER246                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 249)
#define TKAFG1K_VAL_PM_INTERNAL_USER247                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 250)
#define TKAFG1K_VAL_PM_INTERNAL_USER248                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 251)
#define TKAFG1K_VAL_PM_INTERNAL_USER249                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 252)
#define TKAFG1K_VAL_PM_INTERNAL_USER250                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 253)
#define TKAFG1K_VAL_PM_INTERNAL_USER251                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 254)
#define TKAFG1K_VAL_PM_INTERNAL_USER252                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 255)
#define TKAFG1K_VAL_PM_INTERNAL_USER253                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 256)
#define TKAFG1K_VAL_PM_INTERNAL_USER254                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 257)
#define TKAFG1K_VAL_PM_INTERNAL_USER255                   (TKAFG1K_VAL_PM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 258)

/*- Defined values for attribute TKAFG1K_ATTR_PWM_SOURCE -*/
#define TKAFG1K_VAL_PWM_INTERNAL                          (0L)
#define TKAFG1K_VAL_PWM_EXTERNAL                          (1L)

#define TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE    (1000L)
/*- Defined values for attribute TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM -*/
#define TKAFG1K_VAL_PWM_INTERNAL_SINE                     (1L)
#define TKAFG1K_VAL_PWM_INTERNAL_SQUARE                   (2L)
#define TKAFG1K_VAL_PWM_INTERNAL_TRIANGLE                 (3L)
#define TKAFG1K_VAL_PWM_INTERNAL_RAMP_UP                  (4L)
#define TKAFG1K_VAL_PWM_INTERNAL_RAMP_DOWN                (5L)
#define TKAFG1K_VAL_PWM_INTERNAL_PRN                      (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 1)
#define TKAFG1K_VAL_PWM_INTERNAL_EMEM                     (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 2)
#define TKAFG1K_VAL_PWM_INTERNAL_USER0                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 3)
#define TKAFG1K_VAL_PWM_INTERNAL_USER1                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 4)
#define TKAFG1K_VAL_PWM_INTERNAL_USER2                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 5)
#define TKAFG1K_VAL_PWM_INTERNAL_USER3                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 6)
#define TKAFG1K_VAL_PWM_INTERNAL_USER4                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 7)
#define TKAFG1K_VAL_PWM_INTERNAL_USER5                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 8)
#define TKAFG1K_VAL_PWM_INTERNAL_USER6                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 9)
#define TKAFG1K_VAL_PWM_INTERNAL_USER7                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 10)
#define TKAFG1K_VAL_PWM_INTERNAL_USER8                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 11)
#define TKAFG1K_VAL_PWM_INTERNAL_USER9                    (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 12)
#define TKAFG1K_VAL_PWM_INTERNAL_USER10                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 13)
#define TKAFG1K_VAL_PWM_INTERNAL_USER11                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 14)
#define TKAFG1K_VAL_PWM_INTERNAL_USER12                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 15)
#define TKAFG1K_VAL_PWM_INTERNAL_USER13                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 16)
#define TKAFG1K_VAL_PWM_INTERNAL_USER14                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 17)
#define TKAFG1K_VAL_PWM_INTERNAL_USER15                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 18)
#define TKAFG1K_VAL_PWM_INTERNAL_USER16                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 19)
#define TKAFG1K_VAL_PWM_INTERNAL_USER17                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 20)
#define TKAFG1K_VAL_PWM_INTERNAL_USER18                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 21)
#define TKAFG1K_VAL_PWM_INTERNAL_USER19                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 22)
#define TKAFG1K_VAL_PWM_INTERNAL_USER20                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 23)
#define TKAFG1K_VAL_PWM_INTERNAL_USER21                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 24)
#define TKAFG1K_VAL_PWM_INTERNAL_USER22                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 25)
#define TKAFG1K_VAL_PWM_INTERNAL_USER23                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 26)
#define TKAFG1K_VAL_PWM_INTERNAL_USER24                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 27)
#define TKAFG1K_VAL_PWM_INTERNAL_USER25                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 28)
#define TKAFG1K_VAL_PWM_INTERNAL_USER26                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 29)
#define TKAFG1K_VAL_PWM_INTERNAL_USER27                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 30)
#define TKAFG1K_VAL_PWM_INTERNAL_USER28                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 31)
#define TKAFG1K_VAL_PWM_INTERNAL_USER29                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 32)
#define TKAFG1K_VAL_PWM_INTERNAL_USER30                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 33)
#define TKAFG1K_VAL_PWM_INTERNAL_USER31                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 34)
#define TKAFG1K_VAL_PWM_INTERNAL_USER32                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 35)
#define TKAFG1K_VAL_PWM_INTERNAL_USER33                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 36)
#define TKAFG1K_VAL_PWM_INTERNAL_USER34                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 37)
#define TKAFG1K_VAL_PWM_INTERNAL_USER35                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 38)
#define TKAFG1K_VAL_PWM_INTERNAL_USER36                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 39)
#define TKAFG1K_VAL_PWM_INTERNAL_USER37                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 40)
#define TKAFG1K_VAL_PWM_INTERNAL_USER38                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 41)
#define TKAFG1K_VAL_PWM_INTERNAL_USER39                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 42)
#define TKAFG1K_VAL_PWM_INTERNAL_USER40                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 43)
#define TKAFG1K_VAL_PWM_INTERNAL_USER41                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 44)
#define TKAFG1K_VAL_PWM_INTERNAL_USER42                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 45)
#define TKAFG1K_VAL_PWM_INTERNAL_USER43                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 46)
#define TKAFG1K_VAL_PWM_INTERNAL_USER44                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 47)
#define TKAFG1K_VAL_PWM_INTERNAL_USER45                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 48)
#define TKAFG1K_VAL_PWM_INTERNAL_USER46                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 49)
#define TKAFG1K_VAL_PWM_INTERNAL_USER47                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 50)
#define TKAFG1K_VAL_PWM_INTERNAL_USER48                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 51)
#define TKAFG1K_VAL_PWM_INTERNAL_USER49                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 52)
#define TKAFG1K_VAL_PWM_INTERNAL_USER50                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 53)
#define TKAFG1K_VAL_PWM_INTERNAL_USER51                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 54)
#define TKAFG1K_VAL_PWM_INTERNAL_USER52                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 55)
#define TKAFG1K_VAL_PWM_INTERNAL_USER53                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 56)
#define TKAFG1K_VAL_PWM_INTERNAL_USER54                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 57)
#define TKAFG1K_VAL_PWM_INTERNAL_USER55                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 58)
#define TKAFG1K_VAL_PWM_INTERNAL_USER56                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 59)
#define TKAFG1K_VAL_PWM_INTERNAL_USER57                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 60)
#define TKAFG1K_VAL_PWM_INTERNAL_USER58                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 61)
#define TKAFG1K_VAL_PWM_INTERNAL_USER59                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 62)
#define TKAFG1K_VAL_PWM_INTERNAL_USER60                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 63)
#define TKAFG1K_VAL_PWM_INTERNAL_USER61                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 64)
#define TKAFG1K_VAL_PWM_INTERNAL_USER62                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 65)
#define TKAFG1K_VAL_PWM_INTERNAL_USER63                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 66)
#define TKAFG1K_VAL_PWM_INTERNAL_USER64                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 67)
#define TKAFG1K_VAL_PWM_INTERNAL_USER65                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 68)
#define TKAFG1K_VAL_PWM_INTERNAL_USER66                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 69)
#define TKAFG1K_VAL_PWM_INTERNAL_USER67                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 70)
#define TKAFG1K_VAL_PWM_INTERNAL_USER68                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 71)
#define TKAFG1K_VAL_PWM_INTERNAL_USER69                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 72)
#define TKAFG1K_VAL_PWM_INTERNAL_USER70                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 73)
#define TKAFG1K_VAL_PWM_INTERNAL_USER71                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 74)
#define TKAFG1K_VAL_PWM_INTERNAL_USER72                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 75)
#define TKAFG1K_VAL_PWM_INTERNAL_USER73                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 76)
#define TKAFG1K_VAL_PWM_INTERNAL_USER74                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 77)
#define TKAFG1K_VAL_PWM_INTERNAL_USER75                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 78)
#define TKAFG1K_VAL_PWM_INTERNAL_USER76                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 79)
#define TKAFG1K_VAL_PWM_INTERNAL_USER77                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 80)
#define TKAFG1K_VAL_PWM_INTERNAL_USER78                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 81)
#define TKAFG1K_VAL_PWM_INTERNAL_USER79                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 82)
#define TKAFG1K_VAL_PWM_INTERNAL_USER80                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 83)
#define TKAFG1K_VAL_PWM_INTERNAL_USER81                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 84)
#define TKAFG1K_VAL_PWM_INTERNAL_USER82                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 85)
#define TKAFG1K_VAL_PWM_INTERNAL_USER83                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 86)
#define TKAFG1K_VAL_PWM_INTERNAL_USER84                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 87)
#define TKAFG1K_VAL_PWM_INTERNAL_USER85                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 88)
#define TKAFG1K_VAL_PWM_INTERNAL_USER86                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 89)
#define TKAFG1K_VAL_PWM_INTERNAL_USER87                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 90)
#define TKAFG1K_VAL_PWM_INTERNAL_USER88                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 91)
#define TKAFG1K_VAL_PWM_INTERNAL_USER89                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 92)
#define TKAFG1K_VAL_PWM_INTERNAL_USER90                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 93)
#define TKAFG1K_VAL_PWM_INTERNAL_USER91                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 94)
#define TKAFG1K_VAL_PWM_INTERNAL_USER92                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 95)
#define TKAFG1K_VAL_PWM_INTERNAL_USER93                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 96)
#define TKAFG1K_VAL_PWM_INTERNAL_USER94                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 97)
#define TKAFG1K_VAL_PWM_INTERNAL_USER95                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 98)
#define TKAFG1K_VAL_PWM_INTERNAL_USER96                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 99)
#define TKAFG1K_VAL_PWM_INTERNAL_USER97                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 100)
#define TKAFG1K_VAL_PWM_INTERNAL_USER98                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 101)
#define TKAFG1K_VAL_PWM_INTERNAL_USER99                   (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 102)
#define TKAFG1K_VAL_PWM_INTERNAL_USER100                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 103)
#define TKAFG1K_VAL_PWM_INTERNAL_USER101                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 104)
#define TKAFG1K_VAL_PWM_INTERNAL_USER102                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 105)
#define TKAFG1K_VAL_PWM_INTERNAL_USER103                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 106)
#define TKAFG1K_VAL_PWM_INTERNAL_USER104                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 107)
#define TKAFG1K_VAL_PWM_INTERNAL_USER105                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 108)
#define TKAFG1K_VAL_PWM_INTERNAL_USER106                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 109)
#define TKAFG1K_VAL_PWM_INTERNAL_USER107                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 110)
#define TKAFG1K_VAL_PWM_INTERNAL_USER108                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 111)
#define TKAFG1K_VAL_PWM_INTERNAL_USER109                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 112)
#define TKAFG1K_VAL_PWM_INTERNAL_USER110                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 113)
#define TKAFG1K_VAL_PWM_INTERNAL_USER111                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 114)
#define TKAFG1K_VAL_PWM_INTERNAL_USER112                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 115)
#define TKAFG1K_VAL_PWM_INTERNAL_USER113                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 116)
#define TKAFG1K_VAL_PWM_INTERNAL_USER114                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 117)
#define TKAFG1K_VAL_PWM_INTERNAL_USER115                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 118)
#define TKAFG1K_VAL_PWM_INTERNAL_USER116                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 119)
#define TKAFG1K_VAL_PWM_INTERNAL_USER117                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 120)
#define TKAFG1K_VAL_PWM_INTERNAL_USER118                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 121)
#define TKAFG1K_VAL_PWM_INTERNAL_USER119                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 122)
#define TKAFG1K_VAL_PWM_INTERNAL_USER120                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 123)
#define TKAFG1K_VAL_PWM_INTERNAL_USER121                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 124)
#define TKAFG1K_VAL_PWM_INTERNAL_USER122                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 125)
#define TKAFG1K_VAL_PWM_INTERNAL_USER123                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 126)
#define TKAFG1K_VAL_PWM_INTERNAL_USER124                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 127)
#define TKAFG1K_VAL_PWM_INTERNAL_USER125                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 128)
#define TKAFG1K_VAL_PWM_INTERNAL_USER126                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 129)
#define TKAFG1K_VAL_PWM_INTERNAL_USER127                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 130)
#define TKAFG1K_VAL_PWM_INTERNAL_USER128                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 131)
#define TKAFG1K_VAL_PWM_INTERNAL_USER129                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 132)
#define TKAFG1K_VAL_PWM_INTERNAL_USER130                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 133)
#define TKAFG1K_VAL_PWM_INTERNAL_USER131                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 134)
#define TKAFG1K_VAL_PWM_INTERNAL_USER132                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 135)
#define TKAFG1K_VAL_PWM_INTERNAL_USER133                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 136)
#define TKAFG1K_VAL_PWM_INTERNAL_USER134                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 137)
#define TKAFG1K_VAL_PWM_INTERNAL_USER135                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 138)
#define TKAFG1K_VAL_PWM_INTERNAL_USER136                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 139)
#define TKAFG1K_VAL_PWM_INTERNAL_USER137                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 140)
#define TKAFG1K_VAL_PWM_INTERNAL_USER138                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 141)
#define TKAFG1K_VAL_PWM_INTERNAL_USER139                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 142)
#define TKAFG1K_VAL_PWM_INTERNAL_USER140                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 143)
#define TKAFG1K_VAL_PWM_INTERNAL_USER141                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 144)
#define TKAFG1K_VAL_PWM_INTERNAL_USER142                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 145)
#define TKAFG1K_VAL_PWM_INTERNAL_USER143                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 146)
#define TKAFG1K_VAL_PWM_INTERNAL_USER144                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 147)
#define TKAFG1K_VAL_PWM_INTERNAL_USER145                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 148)
#define TKAFG1K_VAL_PWM_INTERNAL_USER146                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 149)
#define TKAFG1K_VAL_PWM_INTERNAL_USER147                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 150)
#define TKAFG1K_VAL_PWM_INTERNAL_USER148                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 151)
#define TKAFG1K_VAL_PWM_INTERNAL_USER149                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 152)
#define TKAFG1K_VAL_PWM_INTERNAL_USER150                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 153)
#define TKAFG1K_VAL_PWM_INTERNAL_USER151                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 154)
#define TKAFG1K_VAL_PWM_INTERNAL_USER152                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 155)
#define TKAFG1K_VAL_PWM_INTERNAL_USER153                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 156)
#define TKAFG1K_VAL_PWM_INTERNAL_USER154                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 157)
#define TKAFG1K_VAL_PWM_INTERNAL_USER155                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 158)
#define TKAFG1K_VAL_PWM_INTERNAL_USER156                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 159)
#define TKAFG1K_VAL_PWM_INTERNAL_USER157                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 160)
#define TKAFG1K_VAL_PWM_INTERNAL_USER158                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 161)
#define TKAFG1K_VAL_PWM_INTERNAL_USER159                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 162)
#define TKAFG1K_VAL_PWM_INTERNAL_USER160                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 163)
#define TKAFG1K_VAL_PWM_INTERNAL_USER161                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 164)
#define TKAFG1K_VAL_PWM_INTERNAL_USER162                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 165)
#define TKAFG1K_VAL_PWM_INTERNAL_USER163                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 166)
#define TKAFG1K_VAL_PWM_INTERNAL_USER164                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 167)
#define TKAFG1K_VAL_PWM_INTERNAL_USER165                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 168)
#define TKAFG1K_VAL_PWM_INTERNAL_USER166                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 169)
#define TKAFG1K_VAL_PWM_INTERNAL_USER167                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 170)
#define TKAFG1K_VAL_PWM_INTERNAL_USER168                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 171)
#define TKAFG1K_VAL_PWM_INTERNAL_USER169                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 172)
#define TKAFG1K_VAL_PWM_INTERNAL_USER170                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 173)
#define TKAFG1K_VAL_PWM_INTERNAL_USER171                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 174)
#define TKAFG1K_VAL_PWM_INTERNAL_USER172                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 175)
#define TKAFG1K_VAL_PWM_INTERNAL_USER173                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 176)
#define TKAFG1K_VAL_PWM_INTERNAL_USER174                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 177)
#define TKAFG1K_VAL_PWM_INTERNAL_USER175                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 178)
#define TKAFG1K_VAL_PWM_INTERNAL_USER176                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 179)
#define TKAFG1K_VAL_PWM_INTERNAL_USER177                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 180)
#define TKAFG1K_VAL_PWM_INTERNAL_USER178                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 181)
#define TKAFG1K_VAL_PWM_INTERNAL_USER179                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 182)
#define TKAFG1K_VAL_PWM_INTERNAL_USER180                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 183)
#define TKAFG1K_VAL_PWM_INTERNAL_USER181                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 184)
#define TKAFG1K_VAL_PWM_INTERNAL_USER182                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 185)
#define TKAFG1K_VAL_PWM_INTERNAL_USER183                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 186)
#define TKAFG1K_VAL_PWM_INTERNAL_USER184                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 187)
#define TKAFG1K_VAL_PWM_INTERNAL_USER185                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 188)
#define TKAFG1K_VAL_PWM_INTERNAL_USER186                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 189)
#define TKAFG1K_VAL_PWM_INTERNAL_USER187                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 190)
#define TKAFG1K_VAL_PWM_INTERNAL_USER188                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 191)
#define TKAFG1K_VAL_PWM_INTERNAL_USER189                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 192)
#define TKAFG1K_VAL_PWM_INTERNAL_USER190                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 193)
#define TKAFG1K_VAL_PWM_INTERNAL_USER191                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 194)
#define TKAFG1K_VAL_PWM_INTERNAL_USER192                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 195)
#define TKAFG1K_VAL_PWM_INTERNAL_USER193                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 196)
#define TKAFG1K_VAL_PWM_INTERNAL_USER194                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 197)
#define TKAFG1K_VAL_PWM_INTERNAL_USER195                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 198)
#define TKAFG1K_VAL_PWM_INTERNAL_USER196                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 199)
#define TKAFG1K_VAL_PWM_INTERNAL_USER197                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 200)
#define TKAFG1K_VAL_PWM_INTERNAL_USER198                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 201)
#define TKAFG1K_VAL_PWM_INTERNAL_USER199                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 202)
#define TKAFG1K_VAL_PWM_INTERNAL_USER200                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 203)
#define TKAFG1K_VAL_PWM_INTERNAL_USER201                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 204)
#define TKAFG1K_VAL_PWM_INTERNAL_USER202                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 205)
#define TKAFG1K_VAL_PWM_INTERNAL_USER203                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 206)
#define TKAFG1K_VAL_PWM_INTERNAL_USER204                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 207)
#define TKAFG1K_VAL_PWM_INTERNAL_USER205                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 208)
#define TKAFG1K_VAL_PWM_INTERNAL_USER206                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 209)
#define TKAFG1K_VAL_PWM_INTERNAL_USER207                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 210)
#define TKAFG1K_VAL_PWM_INTERNAL_USER208                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 211)
#define TKAFG1K_VAL_PWM_INTERNAL_USER209                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 212)
#define TKAFG1K_VAL_PWM_INTERNAL_USER210                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 213)
#define TKAFG1K_VAL_PWM_INTERNAL_USER211                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 214)
#define TKAFG1K_VAL_PWM_INTERNAL_USER212                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 215)
#define TKAFG1K_VAL_PWM_INTERNAL_USER213                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 216)
#define TKAFG1K_VAL_PWM_INTERNAL_USER214                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 217)
#define TKAFG1K_VAL_PWM_INTERNAL_USER215                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 218)
#define TKAFG1K_VAL_PWM_INTERNAL_USER216                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 219)
#define TKAFG1K_VAL_PWM_INTERNAL_USER217                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 220)
#define TKAFG1K_VAL_PWM_INTERNAL_USER218                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 221)
#define TKAFG1K_VAL_PWM_INTERNAL_USER219                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 222)
#define TKAFG1K_VAL_PWM_INTERNAL_USER220                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 223)
#define TKAFG1K_VAL_PWM_INTERNAL_USER221                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 224)
#define TKAFG1K_VAL_PWM_INTERNAL_USER222                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 225)
#define TKAFG1K_VAL_PWM_INTERNAL_USER223                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 226)
#define TKAFG1K_VAL_PWM_INTERNAL_USER224                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 227)
#define TKAFG1K_VAL_PWM_INTERNAL_USER225                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 228)
#define TKAFG1K_VAL_PWM_INTERNAL_USER226                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 229)
#define TKAFG1K_VAL_PWM_INTERNAL_USER227                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 230)
#define TKAFG1K_VAL_PWM_INTERNAL_USER228                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 231)
#define TKAFG1K_VAL_PWM_INTERNAL_USER229                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 232)
#define TKAFG1K_VAL_PWM_INTERNAL_USER230                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 233)
#define TKAFG1K_VAL_PWM_INTERNAL_USER231                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 234)
#define TKAFG1K_VAL_PWM_INTERNAL_USER232                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 235)
#define TKAFG1K_VAL_PWM_INTERNAL_USER233                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 236)
#define TKAFG1K_VAL_PWM_INTERNAL_USER234                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 237)
#define TKAFG1K_VAL_PWM_INTERNAL_USER235                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 238)
#define TKAFG1K_VAL_PWM_INTERNAL_USER236                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 239)
#define TKAFG1K_VAL_PWM_INTERNAL_USER237                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 240)
#define TKAFG1K_VAL_PWM_INTERNAL_USER238                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 241)
#define TKAFG1K_VAL_PWM_INTERNAL_USER239                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 242)
#define TKAFG1K_VAL_PWM_INTERNAL_USER240                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 243)
#define TKAFG1K_VAL_PWM_INTERNAL_USER241                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 244)
#define TKAFG1K_VAL_PWM_INTERNAL_USER242                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 245)
#define TKAFG1K_VAL_PWM_INTERNAL_USER243                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 246)
#define TKAFG1K_VAL_PWM_INTERNAL_USER244                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 247)
#define TKAFG1K_VAL_PWM_INTERNAL_USER245                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 248)
#define TKAFG1K_VAL_PWM_INTERNAL_USER246                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 249)
#define TKAFG1K_VAL_PWM_INTERNAL_USER247                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 250)
#define TKAFG1K_VAL_PWM_INTERNAL_USER248                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 251)
#define TKAFG1K_VAL_PWM_INTERNAL_USER249                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 252)
#define TKAFG1K_VAL_PWM_INTERNAL_USER250                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 253)
#define TKAFG1K_VAL_PWM_INTERNAL_USER251                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 254)
#define TKAFG1K_VAL_PWM_INTERNAL_USER252                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 255)
#define TKAFG1K_VAL_PWM_INTERNAL_USER253                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 256)
#define TKAFG1K_VAL_PWM_INTERNAL_USER254                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 257)
#define TKAFG1K_VAL_PWM_INTERNAL_USER255                  (TKAFG1K_VAL_PWM_INTERNAL_WFM_SPECIFIC_EXT_BASE + 258)


#define TKAFG1K_VAL_MODULATION_AM                         0
#define TKAFG1K_VAL_MODULATION_FM                         1
#define TKAFG1K_VAL_MODULATION_PM                         2
#define TKAFG1K_VAL_MODULATION_FSK                        3
#define TKAFG1K_VAL_MODULATION_PWM                        4
#define TKAFG1K_VAL_MODULATION_ASK                        5
#define TKAFG1K_VAL_MODULATION_PSK                        6


/*- Defined values for function tkafg1k_SaveLoadWaveformData -*/
#define TKAFG1K_VAL_WAVE_OPERATION_STORE    0
#define TKAFG1K_VAL_WAVE_OPERATION_LOAD     1

#define TKAFG1K_VAL_WFM_USER                10002

#define TKAFG1K_VAL_WFM_ARB                 1004

#define TKAFG1K_VAL_PSK_INTERNAL            0
#define TKAFG1K_VAL_PSK_EXTERNAL            1


#define TKAFG1K_VAL_ASK_INTERNAL            0
#define TKAFG1K_VAL_ASK_EXTERNAL            1

#define TKAFG1K_VAL_REF_CLOCK_RTSI_CLOCK    IVIFGEN_VAL_REF_CLOCK_RTSI_CLOCK


/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/
#define TKAFG1K_ERROR_NO_WFMS_AVAILABLE               IVIFGEN_ERROR_NO_WFMS_AVAILABLE

#define TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL          (IVI_SPECIFIC_ERROR_BASE + 0x11)      /* 0xBFFA4011 */

#define TKAFG1K_ERROR_ABORT_GENERATION_UNSUPPORTED    (IVI_SPECIFIC_ERROR_BASE + 0x21)      /* 0xBFFA4021 */
#define TKAFG1K_ERROR_DISABLE_UNSUPPORTED             (IVI_SPECIFIC_ERROR_BASE + 0x22)      /* 0xBFFA4022 */

#define TKAFG1K_ERROR_CHANNELS_DIFFERENT              (IVI_SPECIFIC_ERROR_BASE + 0x31)      /* 0xBFFA4031 */
#define TKAFG1K_ERROR_COMBINATION_UNSUPPORTED         (IVI_SPECIFIC_ERROR_BASE + 0x32)      /* 0xBFFA4032 */
#define TKAFG1K_ERROR_INVALID_GROUP_VALUE             (IVI_SPECIFIC_ERROR_BASE + 0x33)      /* 0xBFFA4033 */
#define TKAFG1K_ERROR_INIT_FAIL                       (IVI_SPECIFIC_ERROR_BASE + 0x34)      /* 0xBFFA4034 */

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close Functions -------------------------------------------*/
ViStatus _VI_FUNC  tkafg1k_init (ViRsrc resourceName, ViBoolean IDQuery,
                                 ViBoolean resetDevice, ViSession *vi);
ViStatus _VI_FUNC  tkafg1k_InitWithOptions (ViRsrc resourceName,
                                            ViBoolean IDQuery,
                                            ViBoolean resetDevice,
                                            ViConstString optionString,
                                            ViSession *newVi);
ViStatus _VI_FUNC  tkafg1k_close (ViSession vi);

/*- Coercion Info Functions --------------------------------------------*/
ViStatus _VI_FUNC  tkafg1k_GetNextCoercionRecord (ViSession vi,
                                                  ViInt32 bufferSize,
                                                  ViChar record[]);

/*- Locking Functions --------------------------------------------------*/
ViStatus _VI_FUNC  tkafg1k_LockSession (ViSession vi,
                                        ViBoolean *callerHasLock);
ViStatus _VI_FUNC  tkafg1k_UnlockSession (ViSession vi,
                                          ViBoolean *callerHasLock);

/*- Channel Info Functions ---------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_GetChannelName (ViSession vi, ViInt32 index,
                                          ViInt32 bufferSize, ViChar name[]);

/*- Basic Instrument Operation -----------------------------------------*/

ViStatus _VI_FUNC tkafg1k_ConfigureOperationMode (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 outputMode);

ViStatus _VI_FUNC tkafg1k_ConfigureOutputMode (ViSession vi,

                                               ViInt32 outputMode);

ViStatus _VI_FUNC tkafg1k_ConfigureOutputModeByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViInt32 outputMode);

ViStatus _VI_FUNC tkafg1k_ConfigureRefClockSource (ViSession vi,
                                                   ViInt32 refClockSource);

ViStatus _VI_FUNC tkafg1k_ConfigureOutputImpedance (ViSession vi,
                                                    ViConstString channelName,
                                                    ViReal64 outputImpedance);

ViStatus _VI_FUNC tkafg1k_ConfigureOutputEnabled (ViSession vi,
                                                  ViConstString channelName,
                                                  ViBoolean enabled);

ViStatus _VI_FUNC tkafg1k_InitiateGeneration (ViSession vi);

ViStatus _VI_FUNC tkafg1k_AbortGeneration (ViSession vi);

/*- Standard Function Output --------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigureStandardWaveform (ViSession vi,
                                                     ViConstString channelName,
                                                     ViInt32 waveform,
                                                     ViReal64 amplitude,
                                                     ViReal64 dcOffset,
                                                     ViReal64 frequency,
                                                     ViReal64 startPhase);

ViStatus _VI_FUNC tkafg1k_ConfigurePulseDutyCycle (ViSession vi,
                                                   ViConstString channelName,
                                                   ViReal64 dutyCycle);


/*- Arbitrary Waveform Output -------------------------------------------*/
ViStatus _VI_FUNC  tkafg1k_ConfigureSampleRate (ViSession vi,
                                                ViReal64 sampleRate);

ViStatus _VI_FUNC  tkafg1k_QueryArbWfmCapabilities (ViSession vi,
                                                    ViInt32 *maxNumWfms,
                                                    ViInt32 *wfmQuantum,
                                                    ViInt32 *minWfmSize,
                                                    ViInt32 *maxWfmSize);

ViStatus _VI_FUNC  tkafg1k_CreateArbWaveform (ViSession vi,
                                              ViInt32 wfmSize,
                                              ViReal64 wfmData[],
                                              ViInt32 *wfmHandle);


ViStatus _VI_FUNC  tkafg1k_CreateStandardShapeArbWfm (ViSession vi,
                                                      ViInt32 wfmSize,
                                                      ViInt32 wfmType,
                                                      ViInt32 *wfmHandle);

ViStatus _VI_FUNC  tkafg1k_GetArbitraryWaveformBySlot (ViSession vi,
                                                       ViInt32 slot,
                                                       ViInt32 *wfmHandle);

ViStatus _VI_FUNC  tkafg1k_CreateArbWaveformBySlot (ViSession vi,
                                                    ViInt32 slot,
                                                    ViInt32 wfmSize,
                                                    ViReal64 wfmData[],
                                                    ViBoolean overwrite,
                                                    ViInt32 *wfmHandle);


ViStatus _VI_FUNC  tkafg1k_CreateStandardShapeArbWfmBySlot (ViSession vi,
                                                            ViInt32 slot,
                                                            ViInt32 wfmSize,
                                                            ViInt32 wfmType,
                                                            ViBoolean overwrite,
                                                            ViInt32 *wfmHandle);


ViStatus _VI_FUNC  tkafg1k_ClearArbWaveform (ViSession vi, ViInt32 wfmHandle);

ViStatus _VI_FUNC  tkafg1k_ConfigureArbWaveform (ViSession vi,
                                                 ViConstString channelName,
                                                 ViInt32 wfmHandle,
                                                 ViReal64 arbGain,
                                                 ViReal64 arbOffset);

/*- Arbitrary Frequency -------------------------------------------------*/
ViStatus _VI_FUNC  tkafg1k_ConfigureArbFrequency (ViSession vi,
                                                  ViConstString channelName,
                                                  ViReal64 arbFrequency);


/*- Burst Configuration -------------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigureBurstEnabled (ViSession vi,
                                                 ViConstString channelName,
                                                 ViBoolean enabled);

ViStatus _VI_FUNC tkafg1k_ConfigureBurstCount (ViSession vi,
                                               ViConstString channelName,
                                               ViInt32 burstCount);

ViStatus _VI_FUNC tkafg1k_ConfigureBurstMode (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 burstMode);


/*- Sweep Configuration------------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigureSweep (ViSession vi,
                                          ViConstString channelName,
                                          ViReal64 startFrequency,
                                          ViReal64 stopFrequency);
ViStatus _VI_FUNC tkafg1k_ConfigureSweepEnabled (ViSession vi,
                                                 ViConstString channelName,
                                                 ViBoolean enabled);



/*- Amplitude Modulation ------------------------------------------------*/

ViStatus _VI_FUNC  tkafg1k_ConfigureAMEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled);

ViStatus _VI_FUNC  tkafg1k_ConfigureAMSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source);

ViStatus _VI_FUNC  tkafg1k_ConfigureAMInternal (ViSession vi,
                                                ViReal64 amDepth,
                                                ViInt32 amWaveform,
                                                ViReal64 amFrequency);

ViStatus _VI_FUNC tkafg1k_ConfigureAMInternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 amDepth,
                                                        ViInt32 amWaveform,
                                                        ViReal64 amFrequency);

ViStatus _VI_FUNC tkafg1k_ConfigureAMExternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 amDepth);

/*- Frequency Modulation ------------------------------------------------*/

ViStatus _VI_FUNC  tkafg1k_ConfigureFMEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled);

ViStatus _VI_FUNC  tkafg1k_ConfigureFMSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source);

ViStatus _VI_FUNC  tkafg1k_ConfigureFMInternal (ViSession vi,
                                                ViReal64 fmDeviation,
                                                ViInt32 fmWaveform,
                                                ViReal64 fmFrequency);

ViStatus _VI_FUNC  tkafg1k_ConfigureFMInternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 fmDeviance,
                                                         ViInt32 fmWaveform,
                                                         ViReal64 fmFrequency);

ViStatus _VI_FUNC tkafg1k_ConfigureFMExternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 fmDeviance);

/*- Phase Modulation ----------------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigurePMEnabled (ViSession vi,
                                              ViConstString channelName,
                                              ViBoolean enabled);

ViStatus _VI_FUNC tkafg1k_ConfigurePMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source);

ViStatus _VI_FUNC tkafg1k_ConfigurePMInternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 pmDeviation,
                                                        ViInt32 pmWaveform,
                                                        ViReal64 pmFrequency);

ViStatus _VI_FUNC tkafg1k_ConfigurePMExternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 pmDeviation);

/*- FSK Modulation -----------------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigureFSKEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled);

ViStatus _VI_FUNC tkafg1k_ConfigureFSKSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source);

ViStatus _VI_FUNC tkafg1k_ConfigureFSKInternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 hopFrequency,
                                                         ViReal64 rate);

ViStatus _VI_FUNC tkafg1k_ConfigureFSKExternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 hopFrequency);

/*- PWM Modulation -----------------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigurePWMEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled);

ViStatus _VI_FUNC tkafg1k_ConfigurePWMSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source);

ViStatus _VI_FUNC tkafg1k_ConfigurePWMInternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 pwmDeviation,
                                                         ViInt32 pwmWaveform,
                                                         ViReal64 pwmFrequency);

ViStatus _VI_FUNC tkafg1k_ConfigurePWMExternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 pwmDeviation);
/*- ASK Modulation -----------------------------------------------------*/
ViStatus _VI_FUNC tkafg1k_ConfigureASKEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled);
ViStatus _VI_FUNC tkafg1k_ConfigureASKSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source);
ViStatus _VI_FUNC tkafg1k_ConfigureASKInternalByChan (ViSession vi,
                                                      ViConstString channelName,
                                                      ViReal64 amplitude,
                                                      ViReal64 rate);
ViStatus _VI_FUNC tkafg1k_ConfigureASKExternalByChan (ViSession vi,
                                                      ViConstString channelName,
                                                      ViReal64 amplitude);




/*- PSK Modulation -----------------------------------------------------*/

ViStatus _VI_FUNC tkafg1k_ConfigurePSKEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled);
ViStatus _VI_FUNC tkafg1k_ConfigurePSKSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source);
ViStatus _VI_FUNC tkafg1k_ConfigurePSKInternalByChan (ViSession vi,
                                                      ViConstString channelName,
                                                      ViReal64 deviation,
                                                      ViReal64 rate);

ViStatus _VI_FUNC tkafg1k_ConfigurePSKExternalByChan (ViSession vi,
                                                      ViConstString channelName,
                                                      ViReal64 deviation);



/*- Error Functions ----------------------------------------------------*/
ViStatus _VI_FUNC  tkafg1k_error_query (ViSession vi, ViInt32 *errorCode,
                                        ViChar errorMessage[]);

ViStatus _VI_FUNC  tkafg1k_GetError (ViSession vi, ViStatus *code,
                                     ViInt32 bufferSize,
                                     ViChar description[]);
ViStatus _VI_FUNC  tkafg1k_ClearError (ViSession vi);

ViStatus _VI_FUNC tkafg1k_error_message (ViSession vi, ViStatus errorCode,
                                         ViChar errorMessage[256]);

/*- Interchangeability Checking Functions ------------------------------*/
ViStatus _VI_FUNC tkafg1k_GetNextInterchangeWarning (ViSession vi,
                                                     ViInt32 bufferSize,
                                                     ViChar warnString[]);
ViStatus _VI_FUNC tkafg1k_ResetInterchangeCheck (ViSession vi);
ViStatus _VI_FUNC tkafg1k_ClearInterchangeWarnings (ViSession vi);

/*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC   tkafg1k_InvalidateAllAttributes (ViSession vi);
ViStatus _VI_FUNC   tkafg1k_reset (ViSession vi);
ViStatus _VI_FUNC   tkafg1k_self_test (ViSession vi, ViInt16 *selfTestResult,
                                       ViChar selfTestMessage[]);

ViStatus _VI_FUNC   tkafg1k_ResetWithDefaults (ViSession vi);
ViStatus _VI_FUNC   tkafg1k_revision_query (ViSession vi,
                                            ViChar instrumentDriverRevision[],
                                            ViChar firmwareRevision[]);
ViStatus _VI_FUNC   tkafg1k_Disable (ViSession vi);


ViStatus _VI_FUNC   tkafg1k_SetGetWaveformPointValue (ViSession vi,
                                                      ViInt32 pointIndex,
                                                      ViInt32 pointValue,
                                                      ViInt32 operationSelect,
                                                      ViInt32 editMemory,
                                                      ViInt32 *queryValue);

ViStatus _VI_FUNC   tkafg1k_viWrite (ViSession vi,
                                     ViByte buffer[],
                                     ViInt64 count,
                                     ViInt64 *returnCount);
ViStatus _VI_FUNC   tkafg1k_viRead (ViSession vi,
                                    ViInt64 bufferSize,
                                    ViByte buffer[],
                                    ViInt64 *returnCount);

/* Obsolete Direct IO Functions. */
ViStatus _VI_FUNC   tkafg1k_WriteInstrData (ViSession vi,
                                            ViConstString writeBuffer);
ViStatus _VI_FUNC   tkafg1k_ReadInstrData (ViSession vi, ViInt32 numBytes,
                                           ViChar rdBuf[],
                                           ViInt32 *bytesRead);


/*- Set, Get, and Check Attribute Functions ----------------------------*/
ViStatus _VI_FUNC  tkafg1k_GetAttributeViInt32 (ViSession vi,
                                                ViConstString channelName,
                                                ViAttr attribute,
                                                ViInt32 *value);
ViStatus _VI_FUNC  tkafg1k_GetAttributeViReal64 (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attribute,
                                                 ViReal64 *value);
ViStatus _VI_FUNC  tkafg1k_GetAttributeViString (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attribute,
                                                 ViInt32 bufSize,
                                                 ViChar value[]);
ViStatus _VI_FUNC  tkafg1k_GetAttributeViSession (ViSession vi,
                                                  ViConstString channelName,
                                                  ViAttr attribute,
                                                  ViSession *value);
ViStatus _VI_FUNC  tkafg1k_GetAttributeViBoolean (ViSession vi,
                                                  ViConstString channelName,
                                                  ViAttr attribute,
                                                  ViBoolean *value);

ViStatus _VI_FUNC  tkafg1k_SetAttributeViInt32 (ViSession vi,
                                                ViConstString channelName,
                                                ViAttr attribute,
                                                ViInt32 value);
ViStatus _VI_FUNC  tkafg1k_SetAttributeViReal64 (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attribute,
                                                 ViReal64 value);
ViStatus _VI_FUNC  tkafg1k_SetAttributeViString (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attribute,
                                                 ViConstString value);
ViStatus _VI_FUNC  tkafg1k_SetAttributeViSession (ViSession vi,
                                                  ViConstString channelName,
                                                  ViAttr attribute,
                                                  ViSession value);
ViStatus _VI_FUNC  tkafg1k_SetAttributeViBoolean (ViSession vi,
                                                  ViConstString channelName,
                                                  ViAttr attribute,
                                                  ViBoolean value);

ViStatus _VI_FUNC  tkafg1k_CheckAttributeViInt32 (ViSession vi,
                                                  ViConstString channelName,
                                                  ViAttr attribute,
                                                  ViInt32 value);
ViStatus _VI_FUNC  tkafg1k_CheckAttributeViReal64 (ViSession vi,
                                                   ViConstString channelName,
                                                   ViAttr attribute,
                                                   ViReal64 value);
ViStatus _VI_FUNC  tkafg1k_CheckAttributeViString (ViSession vi,
                                                   ViConstString channelName,
                                                   ViAttr attribute,
                                                   ViConstString value);
ViStatus _VI_FUNC  tkafg1k_CheckAttributeViSession (ViSession vi,
                                                    ViConstString channelName,
                                                    ViAttr attribute,
                                                    ViSession value);
ViStatus _VI_FUNC  tkafg1k_CheckAttributeViBoolean (ViSession vi,
                                                    ViConstString channelName,
                                                    ViAttr attribute,
                                                    ViBoolean value);

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __tkafg1k_HEADER */
