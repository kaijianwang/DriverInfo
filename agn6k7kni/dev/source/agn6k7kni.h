/***************************************************************************** 
 *  (c) 2014, National Instruments, Corporation.  All Rights Reserved.       * 
 *****************************************************************************/

/*****************************************************************************
 * Agilent N6900/N7900 Series Advanced Power System                          
 *                                                                          
 * Title:    agn6k7kni.h                                        
 * Purpose:  Agilent N6900/N7900 Series instrument driver declarations.                                
 *                                                                         
 *****************************************************************************/

#ifndef __AGN6K7KNI_HEADER
#define __AGN6K7KNI_HEADER

#include <ivi.h>
#include <iviDcpwr.h>   
    

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/*****************************************************************************
 *----------------- Instrument Driver Revision Information ------------------*
 *****************************************************************************/
#define AGN6K7KNI_MAJOR_VERSION                1     /* Instrument driver major version   */
#define AGN6K7KNI_MINOR_VERSION                0     /* Instrument driver minor version   */
    
#define AGN6K7KNI_CLASS_SPEC_MAJOR_VERSION     3     /* Class specification major version */
#define AGN6K7KNI_CLASS_SPEC_MINOR_VERSION     0     /* Class specification minor version */        
                                                                    
#define AGN6K7KNI_SUPPORTED_INSTRUMENT_MODELS  "N6950A, N6951A, N6952A, N6953A, N6954A," \
                                               "N6970A, N6971A, N6972A, N6973A, N6974A, N6976A, N6977A," \
                                               "N7950A, N7951A, N7952A, N7953A, N7954A," \
                                               "N7970A, N7971A, N7972A, N7973A, N7974A, N7976A, N7977A"
#define AGN6K7KNI_DRIVER_VENDOR                "National Instruments"
                                               
#ifdef _IVI_mswin64_ 
#define AGN6K7KNI_DRIVER_DESCRIPTION           "Agilent N6900/N7900 Series Advanced Power System Instrument Driver " \
                                               "[Compiled for 64-bit]"
#else
#define AGN6K7KNI_DRIVER_DESCRIPTION           "Agilent N6900/N7900 Series Advanced Power System Instrument Driver"
#endif
                    
/***************************************************************************** 
 *------------------------------- Useful Macros -----------------------------* 
 *****************************************************************************/

    /*- Defined values for rangeType parameter of function ------------------*/
    /*- ConfigureOutputRange ------------------------------------------------*/
#define AGN6K7KNI_VAL_RANGE_CURRENT                     IVIDCPWR_VAL_RANGE_CURRENT              
#define AGN6K7KNI_VAL_RANGE_VOLTAGE                     IVIDCPWR_VAL_RANGE_VOLTAGE              

    /*- Defined values for outputState parameter of function ----------------*/
    /*- QueryOutputState ----------------------------------------------------*/
#define AGN6K7KNI_VAL_OUTPUT_CONSTANT_VOLTAGE           IVIDCPWR_VAL_OUTPUT_CONSTANT_VOLTAGE
#define AGN6K7KNI_VAL_OUTPUT_CONSTANT_CURRENT           IVIDCPWR_VAL_OUTPUT_CONSTANT_CURRENT
#define AGN6K7KNI_VAL_OUTPUT_OVER_VOLTAGE               IVIDCPWR_VAL_OUTPUT_OVER_VOLTAGE       
#define AGN6K7KNI_VAL_OUTPUT_OVER_CURRENT               IVIDCPWR_VAL_OUTPUT_OVER_CURRENT       
#define AGN6K7KNI_VAL_OUTPUT_UNREGULATED                IVIDCPWR_VAL_OUTPUT_UNREGULATED
#define AGN6K7KNI_VAL_OUTPUT_OVER_VOLTAGE_NEGATIVE     (IVIDCPWR_VAL_OUTPUT_STATE_SPECIFIC_EXT_BASE + 0L)
#define AGN6K7KNI_VAL_OUTPUT_OVER_POWER                (IVIDCPWR_VAL_OUTPUT_STATE_SPECIFIC_EXT_BASE + 1L)
#define AGN6K7KNI_VAL_OUTPUT_OVER_POWER_NEGATIVE       (IVIDCPWR_VAL_OUTPUT_STATE_SPECIFIC_EXT_BASE + 2L)
#define AGN6K7KNI_VAL_OUTPUT_OVER_TEMPERATURE          (IVIDCPWR_VAL_OUTPUT_STATE_SPECIFIC_EXT_BASE + 3L)
    
    /*- Defined values for slewRate parameter of function -------------------*/
    /*- ConfigureSlewRate ---------------------------------------------------*/
#define AGN6K7KNI_VAL_SLEW_RATE_MAX                    (-1L)

    /*- Defined values for listCount parameter of function ------------------*/
    /*- ConfigureList -------------------------------------------------------*/
#define AGN6K7KNI_VAL_LIST_COUNT_INFINITY              (-1L)
    
    /*- Defined values for arbCount parameter of function -------------------*/
    /*- ConfigureArbWaveform ------------------------------------------------*/
#define AGN6K7KNI_VAL_ARB_COUNT_INFINITY               (-1L) 
    
    /*- Defined values for range parameter of function ----------------------*/
    /*- ConfigureOutputRange ------------------------------------------------*/
#define AGN6K7KNI_VAL_OUTPUT_RANGE_AUTO                (-1000L)
    
    /*- Defined values for range parameter of function ----------------------*/
    /*- ConfigureElogMeasurement --------------------------------------------*/
#define AGN6K7KNI_VAL_ELOG_CURRENT_RANGE_AUTO          (-1000L)

/***************************************************************************** 
 *---------------------------- Attribute Defines ----------------------------* 
 *****************************************************************************/

    /*- IVI Inherent Instrument Attributes ----------------------------------*/    

        /*- User Options ----------------------------------------------------*/
#define AGN6K7KNI_ATTR_RANGE_CHECK                      IVI_ATTR_RANGE_CHECK                       /* ViBoolean */
#define AGN6K7KNI_ATTR_QUERY_INSTRUMENT_STATUS          IVI_ATTR_QUERY_INSTRUMENT_STATUS           /* ViBoolean */
#define AGN6K7KNI_ATTR_CACHE                            IVI_ATTR_CACHE                             /* ViBoolean */
#define AGN6K7KNI_ATTR_SIMULATE                         IVI_ATTR_SIMULATE                          /* ViBoolean */
#define AGN6K7KNI_ATTR_RECORD_COERCIONS                 IVI_ATTR_RECORD_COERCIONS                  /* ViBoolean */
#define AGN6K7KNI_ATTR_INTERCHANGE_CHECK                IVI_ATTR_INTERCHANGE_CHECK                 /* ViBoolean */
        
        /*- Driver Information ----------------------------------------------*/
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_PREFIX           IVI_ATTR_SPECIFIC_DRIVER_PREFIX            /* ViString, read-only  */
#define AGN6K7KNI_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS       /* ViString, read-only  */
#define AGN6K7KNI_ATTR_GROUP_CAPABILITIES               IVI_ATTR_GROUP_CAPABILITIES                /* ViString, read-only  */
#define AGN6K7KNI_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER           /* ViString, read-only  */
#define AGN6K7KNI_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL                  /* ViString, read-only  */
#define AGN6K7KNI_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION      /* ViString, read-only  */
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION          /* ViString, read-only  */
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_VENDOR           IVI_ATTR_SPECIFIC_DRIVER_VENDOR            /* ViString, read-only  */
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_DESCRIPTION      IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION       /* ViString, read-only  */

#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION     IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION   /* ViInt32, read-only   */
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION     IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION   /* ViInt32, read-only   */

        /*- Advanced Session Information ------------------------------------*/
#define AGN6K7KNI_ATTR_LOGICAL_NAME                     IVI_ATTR_LOGICAL_NAME                      /* ViString, read-only  */
#define AGN6K7KNI_ATTR_IO_RESOURCE_DESCRIPTOR           IVI_ATTR_IO_RESOURCE_DESCRIPTOR            /* ViString, read-only  */
#define AGN6K7KNI_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                      /* ViString, read-only  */      

     /*- Instrument-Specific Attributes -------------------------------------*/

        /*- IviDCPwr Base Capability Group Attributes -----------------------*/
#define AGN6K7KNI_ATTR_CURRENT_LIMIT                    IVIDCPWR_ATTR_CURRENT_LIMIT                /* ViReal64     */
#define AGN6K7KNI_ATTR_CURRENT_LIMIT_BEHAVIOR           IVIDCPWR_ATTR_CURRENT_LIMIT_BEHAVIOR       /* ViInt32      */
#define AGN6K7KNI_ATTR_OUTPUT_ENABLED                   IVIDCPWR_ATTR_OUTPUT_ENABLED               /* ViBoolean    */
#define AGN6K7KNI_ATTR_OVP_ENABLED                      IVIDCPWR_ATTR_OVP_ENABLED                  /* ViBoolean    */
#define AGN6K7KNI_ATTR_OVP_LIMIT                        IVIDCPWR_ATTR_OVP_LIMIT                    /* ViReal64     */
#define AGN6K7KNI_ATTR_VOLTAGE_LEVEL                    IVIDCPWR_ATTR_VOLTAGE_LEVEL                /* ViReal64     */
#define AGN6K7KNI_ATTR_CHANNEL_COUNT                    IVI_ATTR_CHANNEL_COUNT                     /* ViInt32, read-only  */

        /*- IviDCPwr Trigger Extension Group Attributes ---------------------*/
#define AGN6K7KNI_ATTR_TRIGGER_SOURCE                   IVIDCPWR_ATTR_TRIGGER_SOURCE               /* ViInt32      */
#define AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LIMIT          IVIDCPWR_ATTR_TRIGGERED_CURRENT_LIMIT      /* ViReal64     */
#define AGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL          IVIDCPWR_ATTR_TRIGGERED_VOLTAGE_LEVEL      /* ViReal64     */

    /*- agn6k7kni-Specific Attributes ---------------------------------------*/
#define AGN6K7KNI_ATTR_ID_QUERY_RESPONSE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)        /* ViString, Read Only */

        /*- Base Capability Group Attributes --------------------------------*/
#define AGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1001L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1002L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1003L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_OUTPUT_RANGE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1004L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_WATCHDOG_DELAY                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1005L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1006L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_OCP_DELAY_START_TIME            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1007L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_OCP_DELAY                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1008L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_OCP_ENABLED                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1009L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1010L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1011L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1012L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_RESISTANCE_LEVEL                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1013L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_RESISTANCE_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1014L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1015L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1016L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_CURRENT_SLEW_RATE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1017L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_CURRENT_LEVEL                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1018L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1019L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_VOLTAGE_LIMIT                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1020L)     /* ViReal64     */

        /*- Trigger Extension Group Attributes ------------------------------*/
#define AGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2001L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2002L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2003L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2004L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2005L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2006L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2007L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2008L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2009L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2010L)     /* ViReal64     */

        /*- Waveform/Sequence Attributes ------------------------------------*/
#define AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3001L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3002L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3003L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3004L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3005L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3006L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3007L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3008L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_ARB_WFM_COUNT                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3010L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_FUNCTION                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3011L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3012L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_LIST_STEP                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3013L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_LIST_COUNT                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3014L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_INITIATE_CONTINUOUS             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3015L)     /* ViBoolean    */

        /*- Measurement Group Attributes ------------------------------------*/
#define AGN6K7KNI_ATTR_MEASUREMENT_WINDOW              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4001L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_MEASUREMENT_TIME                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4002L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4003L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_SWEEP_POINT                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4004L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4005L)     /* ViInt32      */

        /*- Datalog Group Attributes ----------------------------------------*/
#define AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5001L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_ELOG_PERIOD                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5002L)     /* ViReal64     */

        /*- Miscellaneous Group Attributes ----------------------------------*/
#define AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6001L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6002L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6005L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6006L)     /* ViInt32      */

#define AGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6007L)     /* ViBoolean    */  

#define AGN6K7KNI_ATTR_DIGITAL_INPUT_DATA              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6008L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6009L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6012L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6013L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_THRESHOLD_LEVEL                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6019L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_THRESHOLD_OPERATION             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6020L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_THRESHOLD_FUNCTION              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6021L)     /* ViInt32      */

        /*- Calibration Attributes ------------------------------------------*/
#define AGN6K7KNI_ATTR_CALIBRATION_DATA                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7001L)     /* ViReal64     */
#define AGN6K7KNI_ATTR_CALIBRATION_LEVEL               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7003L)     /* ViInt32      */
#define AGN6K7KNI_ATTR_OUTPUT_RANGE_AUTO               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7005L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7006L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7007L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7008L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7009L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE_AUTO         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7010L)     /* ViBoolean    */
#define AGN6K7KNI_ATTR_CALIBRATION_COUNT               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7011L)     /* ViInt32      */

         
    /*- Obsolete Inherent Instrument Attributes -----------------------------*/
        /* Driver Information  */
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION     /* ViInt32,  read-only */
#define AGN6K7KNI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION     /* ViInt32,  read-only */
                                                                                                   
        /* Advanced Session Information */                                                         
#define AGN6K7KNI_ATTR_IO_SESSION_TYPE                  IVI_ATTR_IO_SESSION_TYPE                   /* ViString, read-only  */

/*****************************************************************************
 *------------------------ Attribute Value Defines --------------------------*
******************************************************************************/

/* Instrument specific attribute value definitions */

    /*- Defined values for attribute AGN6K7KNI_ATTR_FUNCTION ----------------*/
#define AGN6K7KNI_VAL_FUNCTION_VOLTAGE                 (1)
#define AGN6K7KNI_VAL_FUNCTION_CURRENT                 (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH -------*/
#define AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_HIGH           (1)
#define AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_LOW            (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY ---*/
#define AGN6K7KNI_VAL_RELAY_POLARITY_NORMAL            (1)
#define AGN6K7KNI_VAL_RELAY_POLARITY_REVERSE           (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_OCP_DELAY_START_TIME ----*/
#define AGN6K7KNI_VAL_OCP_DELAY_START_SCHANGE          (1)
#define AGN6K7KNI_VAL_OCP_DELAY_START_CCTRANS          (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE --*/
    /*- Defined values for attribute AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE --*/
#define AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED             (1)
#define AGN6K7KNI_VAL_TRANSIENT_MODE_STEP              (2)
#define AGN6K7KNI_VAL_TRANSIENT_MODE_LIST              (3)
#define AGN6K7KNI_VAL_TRANSIENT_MODE_ARB               (4)

    /*- Defined values for attribute AGN6K7KNI_ATTR_TRIGGER_SOURCE ----------*/
    /*- Defined values for attribute AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ------*/
    /*- Defined values for attribute AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ------*/
#define AGN6K7KNI_VAL_TRIG_IMMEDIATE                    IVIDCPWR_VAL_TRIG_IMMEDIATE
#define AGN6K7KNI_VAL_TRIG_EXTERNAL                     IVIDCPWR_VAL_TRIG_EXTERNAL
#define AGN6K7KNI_VAL_SOFTWARE_TRIG                     IVIDCPWR_VAL_SOFTWARE_TRIG
#define AGN6K7KNI_VAL_TRIG_EXPR1                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 0L)
#define AGN6K7KNI_VAL_TRIG_EXPR2                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 1L)
#define AGN6K7KNI_VAL_TRIG_EXPR3                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 2L)
#define AGN6K7KNI_VAL_TRIG_EXPR4                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 3L)
#define AGN6K7KNI_VAL_TRIG_EXPR5                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 4L)
#define AGN6K7KNI_VAL_TRIG_EXPR6                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 5L)
#define AGN6K7KNI_VAL_TRIG_EXPR7                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 6L)
#define AGN6K7KNI_VAL_TRIG_EXPR8                       (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 7L)
#define AGN6K7KNI_VAL_TRIG_PIN1                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 8L)
#define AGN6K7KNI_VAL_TRIG_PIN2                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 9L)
#define AGN6K7KNI_VAL_TRIG_PIN3                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 10L)
#define AGN6K7KNI_VAL_TRIG_PIN4                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 11L)
#define AGN6K7KNI_VAL_TRIG_PIN5                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 12L)
#define AGN6K7KNI_VAL_TRIG_PIN6                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 13L)
#define AGN6K7KNI_VAL_TRIG_PIN7                        (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 14L)
#define AGN6K7KNI_VAL_TRIG_CURRENT                     (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 15L) 
#define AGN6K7KNI_VAL_TRIG_TRANSIENT                   (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 16L) 
#define AGN6K7KNI_VAL_TRIG_VOLTAGE                     (IVIDCPWR_VAL_TRIG_SRC_SPECIFIC_EXT_BASE + 17L) 

    /*- Defined values for attribute AGN6K7KNI_ATTR_LIST_STEP ---------------*/
#define AGN6K7KNI_VAL_LIST_STEP_AUTO                   (1)
#define AGN6K7KNI_VAL_LIST_STEP_ONCE                   (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_ARB_WFM_TYPE ------------*/
#define AGN6K7KNI_VAL_ARB_WFM_TYPE_VOLT                (1)
#define AGN6K7KNI_VAL_ARB_WFM_TYPE_CURR                (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_MEASUREMENT_TYPE --------*/
#define AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_DC              IVIDCPWR_VAL_MEASURE_CURRENT
#define AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_DC              IVIDCPWR_VAL_MEASURE_VOLTAGE  
#define AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_RMS            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 0L)
#define AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_HIGH           (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 1L)
#define AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_LOW            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 2L)
#define AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_MAX            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 3L)
#define AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_MIN            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 4L)
#define AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_RMS            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 5L)
#define AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_HIGH           (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 6L)
#define AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_LOW            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 7L)
#define AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_MAX            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 8L)
#define AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_MIN            (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 9L)
#define AGN6K7KNI_VAL_MEAS_TYPE_POWER_DC               (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 10L)
#define AGN6K7KNI_VAL_MEAS_TYPE_AHO                    (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 11L)
#define AGN6K7KNI_VAL_MEAS_TYPE_WHO                    (IVIDCPWR_VAL_MEASURE_SPECIFIC_EXT_BASE + 12L)

    /*- Defined values for attribute AGN6K7KNI_ATTR_MEASUREMENT_WINDOW ------*/
#define AGN6K7KNI_VAL_MEAS_WINDOW_HANNING              (1)
#define AGN6K7KNI_VAL_MEAS_WINDOW_RECT                 (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE -*/
    /*- Defined values for attribute AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE -*/
#define AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS               (1)
#define AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_NEG               (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ------*/
#define AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR             (1)
#define AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT           (2)
#define AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER             (3)
#define AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE           (4)
#define AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR             (5)

    /*- Defined values for attribute AGN6K7KNI_ATTR_THRESHOLD_OPERATION -----*/
#define AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT           (1)
#define AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT           (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ----*/
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO             (1)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN             (2)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1           (3)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2           (4)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3           (5)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4           (6)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5           (7)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6           (8)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7           (9)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8           (10)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT           (11)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT         (12)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE       (13)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE      (14)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT      (15)
#define AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT     (16)

    /*- Defined values for attribute AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ----*/
#define AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS              (1)
#define AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG              (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER -*/
#define AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_1           (1)
#define AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_2           (2)
#define AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_3           (3)
#define AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_4           (4)

    /*- Defined values for attribute AGN6K7KNI_ATTR_ELOG_MEASUREMENT_FUNCTION -*/
#define AGN6K7KNI_VAL_ELOG_MEAS_FUNC_VOLTAGE           (1)
#define AGN6K7KNI_VAL_ELOG_MEAS_FUNC_CURRENT           (2)

    /*- Defined values for attribute AGN6K7KNI_ATTR_CALIBRATION_LEVEL -------*/
#define AGN6K7KNI_VAL_CAL_LEVEL_P1                     (1)
#define AGN6K7KNI_VAL_CAL_LEVEL_P2                     (2)
#define AGN6K7KNI_VAL_CAL_LEVEL_P3                     (3)

    /*- Defined values for attribute AGN6K7KNI_ATTR_CALIBRATION_MODE --------*/
#define AGN6K7KNI_VAL_CAL_MODE_VOLTAGE                 (1)
#define AGN6K7KNI_VAL_CAL_MODE_CMRR                    (2)
#define AGN6K7KNI_VAL_CAL_MODE_TC                      (3)
#define AGN6K7KNI_VAL_CAL_MODE_CURRENT_HIGH_RANGE      (4)
#define AGN6K7KNI_VAL_CAL_MODE_CURRENT_LOW_RANGE       (5)
#define AGN6K7KNI_VAL_CAL_MODE_CURRENT_SHARING         (6)
#define AGN6K7KNI_VAL_CAL_MODE_BOTTOM_OUT_RES          (7)

    /*- Defined values for attribute AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE ----*/
#define AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_LATCHING    (1)
#define AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_LIVE        (2)
#define AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_OFF         (3)

    /*- Defined values for attribute AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE -*/
    /*- Defined values for attribute AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE -*/
    /*- Defined values for attribute AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE --*/
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_NONE           (0)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR1          (1)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR2          (2)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR3          (3)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR4          (4)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR5          (5)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR6          (6)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR7          (7)
#define AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR8          (8)
  
    /*- Defined values for attribute AGN6K7KNI_ATTR_CURRENT_LIMIT_BEHAVIOR --*/  
#define AGN6K7KNI_VAL_CURRENT_REGULATE                  IVIDCPWR_VAL_CURRENT_REGULATE

/*****************************************************************************
*---------------- Instrument Driver Function Declarations -------------------*
******************************************************************************/

    /*- Init and Close Functions --------------------------------------------*/
ViStatus _VI_FUNC  agn6k7kni_init (
    ViRsrc resourceName, 
    ViBoolean IDQuery,
    ViBoolean resetDevice, 
    ViSession *vi);
     
ViStatus _VI_FUNC  agn6k7kni_InitWithOptions (
    ViRsrc resourceName, 
    ViBoolean IDQuery,
    ViBoolean resetDevice, 
    ViConstString optionString, 
    ViSession *newVi);

ViStatus _VI_FUNC  agn6k7kni_close (
    ViSession vi);   

    /*- Coercion Info Functions ---------------------------------------------*/
ViStatus _VI_FUNC  agn6k7kni_GetNextCoercionRecord (
    ViSession vi,
    ViInt32 bufferSize,
    ViChar record[]);
    
    /*- Locking Functions ---------------------------------------------------*/
ViStatus _VI_FUNC  agn6k7kni_LockSession (
    ViSession vi, 
    ViBoolean *callerHasLock);  

ViStatus _VI_FUNC  agn6k7kni_UnlockSession (
    ViSession vi, 
    ViBoolean *callerHasLock);

    /*- Channel Info Functions ----------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_GetChannelName (
    ViSession vi, ViInt32 index, 
    ViInt32 bufferSize, 
    ViChar name[]);
                                   
    /*- Configuration Functions ---------------------------------------------*/

        /*- Output ----------------------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_ConfigureVoltageLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level);

ViStatus _VI_FUNC agn6k7kni_ConfigureCurrentSharing (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputResistance (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled, 
    ViReal64 resistance);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputBandwidth (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 bandwidth);

ViStatus _VI_FUNC agn6k7kni_ConfigureSlewRate (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 slewRate);

ViStatus _VI_FUNC agn6k7kni_ConfigureCurrentLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level);

ViStatus _VI_FUNC agn6k7kni_ConfigureNegativeCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 limit);

ViStatus _VI_FUNC agn6k7kni_ConfigureVoltageLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 limit);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputPriorityMode (
    ViSession vi,   
    ViConstString channelName, 
    ViInt32 priorityMode);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputRelay (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean polarityEnabled, 
    ViInt32 polarity, 
    ViBoolean lockEnabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 behavior, 
    ViReal64 limit);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputEnabled (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputSequenceDelay (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 riseDelay, 
    ViReal64 fallDelay);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputSequencing ( 
    ViSession vi, 
    ViBoolean enabled, 
    ViReal64 delayOffset);

        /*- Protection ------------------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_ConfigureWatchdogTimer (
    ViSession vi, 
    ViBoolean enabled, 
    ViInt32 delay);

ViStatus _VI_FUNC agn6k7kni_ConfigureOCP (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled, 
    ViReal64 delay, 
    ViInt32 delayStartTime);

ViStatus _VI_FUNC agn6k7kni_ConfigureOVP (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled, 
    ViReal64 limit);

ViStatus _VI_FUNC agn6k7kni_ConfigureSenseFaultDetection (
    ViSession vi, 
    ViBoolean enabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureInhibitInputMode (
    ViSession vi,
    ViInt32 inhibitMode);

        /*- System ----------------------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_ConfigureBusTriggerEnabled (
    ViSession vi, 
    ViBoolean enabled);

ViStatus _VI_FUNC agn6k7kni_ReadInputData (
    ViSession vi, 
    ViInt32* inputData);

ViStatus _VI_FUNC agn6k7kni_WriteOutputData (
    ViSession vi, 
    ViInt32 outputData);

ViStatus _VI_FUNC agn6k7kni_ConfigurePin (
    ViSession vi,
    ViConstString pinName, 
    ViInt32 pinFunction, 
    ViInt32 pinPolarity);

ViStatus _VI_FUNC agn6k7kni_ConfigureElog (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 function, 
    ViBoolean enabled, 
    ViBoolean minMaxEnabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureElogMeasurement (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 integrationTime, 
    ViReal64 range);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputCoupleSource (
    ViSession vi, 
    ViInt32 onCoupleSource, 
    ViInt32 offCoupleSource);

ViStatus _VI_FUNC agn6k7kni_ConfigureUserProtection (
    ViSession vi, 
    ViBoolean enabled, 
    ViInt32 source);

ViStatus _VI_FUNC agn6k7kni_DefineSignalExpression (
    ViSession vi, 
    ViInt32 expressionNumber, 
    ViConstString expression);

ViStatus _VI_FUNC agn6k7kni_ConfigureThresholdComparators (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 comparatorNumber, 
    ViInt32 function, 
    ViInt32 operation, 
    ViReal64 level);

        /*- Transient -------------------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggerOutEnabled (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureAcqTriggeredCurrent (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level, 
    ViInt32 slope);

ViStatus _VI_FUNC agn6k7kni_ConfigureAcqTriggeredVoltage (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level, 
    ViInt32 slope);

ViStatus _VI_FUNC agn6k7kni_ConfigureArbTriggerSource (
    ViSession vi, 
    ViInt32 arbTriggerSource);

ViStatus _VI_FUNC agn6k7kni_ConfigureTriggeredCurrentLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level);

ViStatus _VI_FUNC agn6k7kni_ConfigureTransientMode (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 transientMode);

ViStatus _VI_FUNC agn6k7kni_ConfigureTriggeredCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 limit);

ViStatus _VI_FUNC agn6k7kni_ConfigureTriggeredVoltageLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level);

ViStatus _VI_FUNC agn6k7kni_ConfigureTriggerSource (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 source);

ViStatus _VI_FUNC agn6k7kni_ConfigureTriggerOutList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 listSize, 
    ViBoolean BOSTList[], 
    ViBoolean EOSTList[]);

ViStatus _VI_FUNC agn6k7kni_ConfigureLevelList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 listSize, 
    ViReal64 levelList[]);

ViStatus _VI_FUNC agn6k7kni_ConfigureDwellList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 listSize, 
    ViReal64 dwellList[]);

ViStatus _VI_FUNC agn6k7kni_ConfigureList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 repeatCount, 
    ViInt32 paceType, 
    ViBoolean terminateLastEnabled);

ViStatus _VI_FUNC agn6k7kni_ConfigureConstantDwellWaveform (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 arrSize, 
    ViReal64 levelArr[], 
    ViReal64 constantDwellTime);

ViStatus _VI_FUNC agn6k7kni_ConfigureArbWaveform (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 repeatCount, 
    ViBoolean terminateLastEnabled);

        /*- Measurement -----------------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_ConfigureAcqTriggerSource ( 
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 acquireSource);

ViStatus _VI_FUNC agn6k7kni_ConfigureWindowing (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 windowType);

ViStatus _VI_FUNC agn6k7kni_ConfigureSampling (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 points, 
    ViReal64 timeInterval, 
    ViInt32 offset);

ViStatus _VI_FUNC agn6k7kni_ConfigureNPLC (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 NPLC);

ViStatus _VI_FUNC agn6k7kni_ConfigureOutputRange (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 rangeType, 
    ViReal64 range);

        /*- Calibration -----------------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_ConfigureCalibrationMode (
    ViSession vi, 
    ViInt32 mode, 
    ViReal64 level);

ViStatus _VI_FUNC agn6k7kni_ConfigureCalibration (
    ViSession vi, 
    ViInt32 calibrationLevel, 
    ViReal64 calibrationData);

ViStatus _VI_FUNC agn6k7kni_ConfigureCalibrationEnabled (
    ViSession vi, 
    ViBoolean enabled, 
    ViConstString password);

    /*- Action/Status Functions ---------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_QueryMaxCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 voltageLevel, 
    ViReal64* maxCurrentLimit);

ViStatus _VI_FUNC agn6k7kni_QueryMaxVoltageLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 currentLimit, 
    ViReal64* maxVoltageLevel);

ViStatus _VI_FUNC agn6k7kni_QueryOutputState (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 outputState, 
    ViBoolean* inState);

ViStatus _VI_FUNC agn6k7kni_ResetOutputProtection (
    ViSession vi, 
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_ResetAhoWhoMeasurements (
    ViSession vi,
    ViConstString channelName,
    ViInt32 measurementType);

ViStatus _VI_FUNC agn6k7kni_QueryMaxOutputDelayOffset (
    ViSession vi, 
    ViReal64 *maxDelayOffset);

ViStatus _VI_FUNC agn6k7kni_QueryCalibrationCount (
    ViSession vi,
    ViInt32 *calibrationCount);

        /*- Action/Status Low-level -----------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_Abort (
    ViSession vi);

ViStatus _VI_FUNC agn6k7kni_Initiate (
    ViSession vi);

ViStatus _VI_FUNC agn6k7kni_SendSoftwareTrigger (
    ViSession vi);

    /*- Measurement Functions -----------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_MeasureTemperature (
    ViSession vi, 
    ViReal64 *ambientTemperature, 
    ViReal64 *overTemperatureMargin);

ViStatus _VI_FUNC agn6k7kni_Measure (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 measurementType, 
    ViReal64 *measurement);

ViStatus _VI_FUNC agn6k7kni_MeasureArray (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 measurementType, 
    ViInt32 startIndex, 
    ViInt32 length, 
    ViInt32 arraySize, 
    ViReal64 measurementArray[], 
    ViInt32 *actualPoints);
        
        /*- Measurement Low-Level -------------------------------------------*/
ViStatus _VI_FUNC agn6k7kni_InitiateDatalog (
    ViSession vi,
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_AbortDatalog (
    ViSession vi,
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_FetchArray (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 maximumTime, 
    ViInt32 measurementType, 
    ViInt32 startIndex, 
    ViInt32 length, 
    ViInt32 arraySize, 
    ViReal64 measurementArray[], 
    ViInt32 *actualPoints);

ViStatus _VI_FUNC agn6k7kni_InitiateAcquisition (
    ViSession vi, 
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_AbortAcquisition (
    ViSession vi,
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_SendAcquisitionTrigger (
    ViSession vi,
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_QueryAcquisitionWtgState (       
    ViSession vi,
    ViConstString channelName,
    ViBoolean *wtgStatus);

ViStatus _VI_FUNC agn6k7kni_SendDatalogTrigger (  
    ViSession vi,
    ViConstString channelName);

ViStatus _VI_FUNC agn6k7kni_FetchDatalog (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 maximumTime, 
    ViInt32 maximumRecords, 
    ViReal64 measurementArray[], 
    ViInt32 *actualRecords);

ViStatus _VI_FUNC agn6k7kni_Fetch (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 maximumTime, 
    ViInt32 measurementType, 
    ViReal64 *measurement);

    /*- Utility Functions ---------------------------------------------------*/
ViStatus _VI_FUNC  agn6k7kni_error_query (
    ViSession vi, 
    ViInt32 *errorCode,
    ViChar errorMessage[]);

ViStatus _VI_FUNC  agn6k7kni_GetError (
    ViSession vi, 
    ViStatus *code, 
    ViInt32 bufferSize, 
    ViChar description[]);

ViStatus _VI_FUNC  agn6k7kni_ClearError (
    ViSession vi);

ViStatus _VI_FUNC  agn6k7kni_error_message (
    ViSession vi, 
    ViStatus errorCode,
    ViChar errorMessage[256]);
    
ViStatus _VI_FUNC  agn6k7kni_GetErrorInfo (
    ViSession vi, 
    ViStatus *primaryError, 
    ViStatus *secondaryError, 
    ViChar errorElaboration[256]);

ViStatus _VI_FUNC  agn6k7kni_ClearErrorInfo (
    ViSession vi);

ViStatus _VI_FUNC agn6k7kni_GetNextInterchangeWarning (
    ViSession vi, 
    ViInt32 bufferSize, 
    ViChar warnString[]);

ViStatus _VI_FUNC agn6k7kni_ResetInterchangeCheck (
    ViSession vi);

ViStatus _VI_FUNC agn6k7kni_ClearInterchangeWarnings (
    ViSession vi);

ViStatus _VI_FUNC agn6k7kni_InvalidateAllAttributes (
    ViSession vi);

ViStatus _VI_FUNC  agn6k7kni_reset (
    ViSession vi);

ViStatus _VI_FUNC  agn6k7kni_ResetWithDefaults (
    ViSession vi);

ViStatus _VI_FUNC  agn6k7kni_self_test (
    ViSession vi, 
    ViInt16 *selfTestResult,
    ViChar selfTestMessage[]);

ViStatus _VI_FUNC  agn6k7kni_revision_query (
    ViSession vi, 
    ViChar instrumentDriverRevision[],
    ViChar firmwareRevision[]);

ViStatus _VI_FUNC  agn6k7kni_Disable (
    ViSession vi);

ViStatus _VI_FUNC  agn6k7kni_WriteInstrData (
    ViSession vi, 
    ViConstString writeBuffer); 

ViStatus _VI_FUNC  agn6k7kni_ReadInstrData  (
    ViSession vi, 
    ViInt32 numBytes, 
    ViChar rdBuf[], 
    ViInt32 *bytesRead);

        /*- Set, Get, and Check Attribute -----------------------------------*/
ViStatus _VI_FUNC  agn6k7kni_GetAttributeViInt32 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViInt32 *value);

ViStatus _VI_FUNC  agn6k7kni_GetAttributeViReal64 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViReal64 *value);

ViStatus _VI_FUNC  agn6k7kni_GetAttributeViString (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViInt32 bufSize, 
    ViChar value[]); 

ViStatus _VI_FUNC  agn6k7kni_GetAttributeViSession (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViSession *value);

ViStatus _VI_FUNC  agn6k7kni_GetAttributeViBoolean (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViBoolean *value);

ViStatus _VI_FUNC  agn6k7kni_SetAttributeViInt32 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViInt32 value);

ViStatus _VI_FUNC  agn6k7kni_SetAttributeViReal64 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViReal64 value);

ViStatus _VI_FUNC  agn6k7kni_SetAttributeViString (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViConstString value); 

ViStatus _VI_FUNC  agn6k7kni_SetAttributeViSession (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViSession value);

ViStatus _VI_FUNC  agn6k7kni_SetAttributeViBoolean (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViBoolean value);

ViStatus _VI_FUNC  agn6k7kni_CheckAttributeViInt32 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute,
    ViInt32 value);

ViStatus _VI_FUNC  agn6k7kni_CheckAttributeViReal64 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViReal64 value);

ViStatus _VI_FUNC  agn6k7kni_CheckAttributeViString (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViConstString value); 

ViStatus _VI_FUNC  agn6k7kni_CheckAttributeViSession (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViSession value);

ViStatus _VI_FUNC  agn6k7kni_CheckAttributeViBoolean (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attribute, 
    ViBoolean value);

/*****************************************************************************
 *------------------------ Error And Completion Codes -----------------------*
 *****************************************************************************/

#define AGN6K7KNI_ERROR_TRIGGER_NOT_SOFTWARE            IVIDCPWR_ERROR_TRIGGER_NOT_SOFTWARE
#define AGN6K7KNI_ERROR_INVALID_OPTION_TYPE            (IVI_SPECIFIC_ERROR_BASE + 1L)

/***************************************************************************** 
 *---------------------------- End Include File -----------------------------* 
 *****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __AGN6K7KNI_HEADER */
