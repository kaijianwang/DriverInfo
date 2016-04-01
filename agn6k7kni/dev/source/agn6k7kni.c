/***************************************************************************** 
 *  (c)  2014, National Instruments, Corporation.  All Rights Reserved.      * 
 *****************************************************************************/
 
/*****************************************************************************
 *  Agilent N6900/N7900 Series Instrument Driver                               
 *  LabWindows/CVI Instrument Driver                                     
 *  Original Release: Friday, December 30, 2013                                  
 *  By: Yang Liu, National Instruments                              
 *      PH. (+8621)50509810                              
 *                                                                           
 *  Modification History:                                                    
 *                                                                           
 *       11/28/2013 - [YL] - Instrument Driver Created.
 *       12/30/2013 - [YL] - Instrument Driver Released.
 *                                                                           
 *****************************************************************************/

#include <ansi_c.h>
#include <string.h>
#include <stdio.h>  
#include <formatio.h>
#include "agn6k7kni.h"

/*****************************************************************************
 *--------------------- Hidden Attribute Declarations -----------------------*
 *****************************************************************************/

#define AGN6K7KNI_ATTR_OPC_TIMEOUT                         (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 1L)   /* ViInt32      */
#define AGN6K7KNI_ATTR_USE_SPECIFIC_SIMULATION             (IVI_INHERENT_ATTR_BASE         + 23L)  /* ViBoolean    */
#define AGN6K7KNI_ATTR_VISA_RM_SESSION                     (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 5L)   /* ViSession    */
#define AGN6K7KNI_ATTR_IO_SESSION                          (IVI_INHERENT_ATTR_BASE         + 322L) /* ViSession    */
#define AGN6K7KNI_ATTR_OPC_CALLBACK                        (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 6L)   /* ViAddr       */
#define AGN6K7KNI_ATTR_CHECK_STATUS_CALLBACK               (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 7L)   /* ViAddr       */
#define AGN6K7KNI_ATTR_USER_INTERCHANGE_CHECK_CALLBACK     (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 8L)   /* ViAddr       */

#define AGN6K7KNI_ATTR_ARB_WFM_TYPE                        (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 148L) /* ViInt32      */
#define AGN6K7KNI_ATTR_MEASUREMENT_TYPE                    (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 160L) /* ViInt32      */
#define AGN6K7KNI_ATTR_THRESHOLD_LEVEL_WHOUR               (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 183L) /* ViReal64     */
#define AGN6K7KNI_ATTR_THRESHOLD_LEVEL_VOLTAGE             (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 184L) /* ViReal64     */
#define AGN6K7KNI_ATTR_THRESHOLD_LEVEL_POWER               (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 185L) /* ViReal64     */
#define AGN6K7KNI_ATTR_THRESHOLD_LEVEL_CURRENT             (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 186L) /* ViReal64     */
#define AGN6K7KNI_ATTR_THRESHOLD_LEVEL_AHOUR               (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 187L) /* ViReal64     */
#define AGN6K7KNI_ATTR_INSTR_MODEL                         (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 188L) /* ViInt32      */
#define AGN6K7KNI_ATTR_INSTR_OPTION                        (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 189L) /* ViInt32      */
#define AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER         (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 190L) /* ViInt32      */
#define AGN6K7KNI_ATTR_INSTR_MODULES_RANGES                (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 191L) /* ViAddr       */


/*****************************************************************************
 *---------------------------- Useful Macros --------------------------------*
 *****************************************************************************/

    /*- I/O buffer size -----------------------------------------------------*/
#define BUFFER_SIZE                                         512L        
#define AGN6K7KNI_IO_SESSION_TYPE                           IVI_VAL_VISA_SESSION_TYPE


    /*- 488.2 Event Status Register (ESR) Bits ------------------------------*/
#define IEEE_488_2_ERROR_MASK                               0x3C

    
    /*- List of channels passed to the Ivi_BuildChannelTable function -------*/ 
#define CHANNEL_LIST                                        "1"


    /*- Repeated capabilities definition and lists of values passed to the --*/
    /*- Ivi_BuildRepCapTable function ---------------------------------------*/
#define DIGITAL_PIN_REP_CAP_NAME                            "Digital_Pin"
#define DIGITAL_PIN_LIST                                    "1,2,3,4,5,6,7"     
        

    /*- Default definition of ID Query Response for simulation --------------*/
#define AGN6K7KNI_SIMULATION_ID_QUERY                       

#define MAX_HEADER_COMMAND_LENGTH                           25
#define MAX_DOUBLE_FORMAT_LENGTH                            15
#define MAX_BOOLEAN_FORMAT_LENGTH                           4
                    
    /*- Macros for access to enum range table -------------------------------*/
#define agn6k7kni_GetCmdFromIntValue(value, table, cmd) \
        Ivi_GetViInt32EntryFromValue (value, table, VI_NULL, VI_NULL,\
                                      VI_NULL, VI_NULL, cmd, VI_NULL)

#define agn6k7kni_GetValueFromCmd(buffer, table, value) \
        Ivi_GetViInt32EntryFromString (buffer, table, value, VI_NULL,\
        VI_NULL, VI_NULL, VI_NULL)

    /*- Constant values and macros for N6900/N7900 Series model definition --*/
    /*- and model check -----------------------------------------------------*/
enum
{
    /*- Agilent N6900 Series 1 kw -------------------------------------------*/
    N6950A = 6950, N6951A = 6951, N6952A = 6952, N6953A = 6953, N6954A = 6954,
    /*- Agilent N6900 Series 2 kw -------------------------------------------*/
    N6970A = 6970, N6971A = 6971, N6972A = 6972, N6973A = 6973, N6974A = 6974, 
    /*- Agilent N6900 High Voltage Series 2 kw ------------------------------*/
    N6976A = 6976, N6977A = 6977,
    /*- Agilent N7900 Series 1 kw -------------------------------------------*/
    N7950A = 7950, N7951A = 7951, N7952A = 7952, N7953A = 7953, N7954A = 7954, 
    /*- Agilent N9900 Series 2 kw -------------------------------------------*/
    N7970A = 7970, N7971A = 7971, N7972A = 7972, N7973A = 7973, N7974A = 7974,
    /*- Agilent N7900 High Voltage Series 2 kw ------------------------------*/
    N7976A = 7976, N7977A = 7977
};

#define AGN6K7KNI_MODEL_NOT_FOUND                          (-1L) 

static IviStringValueTable agn6k7kni_ModelTable =
{
    {N6950A,   "N6950A"},
    {N6951A,   "N6951A"},  
    {N6952A,   "N6952A"},  
    {N6953A,   "N6953A"},  
    {N6954A,   "N6954A"},  
    {N6970A,   "N6970A"},  
    {N6971A,   "N6971A"}, 
    {N6972A,   "N6972A"}, 
    {N6973A,   "N6973A"}, 
    {N6974A,   "N6974A"},
    {N6976A,   "N6976A"},
    {N6977A,   "N6977A"},  
    {N7950A,   "N7950A"},
    {N7951A,   "N7951A"},  
    {N7952A,   "N7952A"},  
    {N7953A,   "N7953A"},  
    {N7954A,   "N7954A"},  
    {N7970A,   "N7970A"},  
    {N7971A,   "N7971A"}, 
    {N7972A,   "N7972A"}, 
    {N7973A,   "N7973A"}, 
    {N7974A,   "N7974A"},
    {N7976A,   "N7976A"},
    {N7977A,   "N7977A"},
    {VI_NULL,   VI_NULL}
};

#define IS_79XXA(modelType)     ((modelType >= N7950A) && (modelType <= N7977A))

enum
{
    N7909A = (1L << 0),
    OPT057 = (1L << 1),
    OPT760 = (1L << 2),
    OPT761 = (1L << 3)
};

static IviStringValueTable agn6k7kni_OptionTable =
{
    {N7909A,   "N7909A"},
    {OPT057,   "BBR"},
    {OPT760,   "760"},
    {OPT761,   "761"},
    {VI_NULL,   VI_NULL}
};

#define AGN6K7KNI_OPTION_NOT_INSTALLED                     (0L)
#define AGN6K7KNI_OPTION_NOT_SUPPORTED                     (-1L)

#define IS_DISSIPATOR_INSTALLED(optionFlag)     (optionFlag & N7909A)

    /*- Define structure with ranges for instrument modules -----------------*/
typedef struct
{
    ViReal64    minCurrent;
    ViReal64    maxCurrent;
    ViReal64    minVoltage;
    ViReal64    maxVoltage;
    ViReal64    maxResistance;
    ViReal64    maxOVPLimit;
    ViReal64    lowerRange;
} SInstrumentRanges, *SInstrumentRangesPtr;

/*****************************************************************************/
/*= Typedefs for string-value-revision tables. ==============================*/
/*****************************************************************************/
typedef struct { 
    ViInt32       value;        /* Attribute ID */ 
    ViConstString string;       /* Command */
    ViConstString repCommand;   /* Extension for Reapted Command */
} agn6k7kniStringValueEntry;

typedef agn6k7kniStringValueEntry agn6k7kniStringValueTable[];


    /*- Macros for the wrapper of empty channel name */
#define VALID_CHANNELNAME(channelName) \
        (VI_NULL == channelName ? "" : channelName)

static agn6k7kniStringValueTable agn6k7kniEnum_commands = 
{   /* Attribute ID,                                        SCPI command                    */
    {AGN6K7KNI_ATTR_OCP_DELAY_START_TIME,                   ":CURR:PROT:DEL:STAR",          ""},
    {AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY,                  ":OUTP:REL:POL",                ""},
    {AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH,                      ":VOLT:BWID",                   ""},
    {AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE,            ":TRIG:ACQ:VOLT:SLOP",          ""},
    {AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE,            ":TRIG:ACQ:CURR:SLOP",          ""},
    {AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE,                     ":TRIG:ARB:SOUR",               ""},
    {AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE,                     ":TRIG:ACQ:SOUR",               ""},
    {AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE,                 ":VOLT:MODE",                   ""},
    {AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE,                 ":CURR:MODE",                   ""},
    {AGN6K7KNI_ATTR_TRIGGER_SOURCE,                         ":TRIG:TRAN:SOUR",              ""},
    {AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE,               ":OUTP:COUP:OFF:SOUR",          ""},
    {AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE,                ":OUTP:COUP:ON:SOUR",           ""},
    {AGN6K7KNI_ATTR_ARB_WFM_TYPE,                           ":ARB:FUNC:TYPE",               ""},
    {AGN6K7KNI_ATTR_FUNCTION,                               ":FUNC",                        ""},
    {AGN6K7KNI_ATTR_LIST_STEP,                              ":LIST:STEP",                   ""},
    {AGN6K7KNI_ATTR_MEASUREMENT_WINDOW,                     ":SENS:WIND",                   ""},
    {AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE,                   ":OUTP:INH:MODE",               ""},
    {AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY,                   ":DIG:PIN",                     ":POL"},
    {AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION,                   ":DIG:PIN",                     ":FUNC"},
    {AGN6K7KNI_ATTR_CALIBRATION_LEVEL,                      ":CAL:LEV",                     ""},
    {AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE,                 ":OUTP:PROT:USER:SOUR",         ""},  
    {VI_NULL,                                               VI_NULL,                        VI_NULL}
};

static agn6k7kniStringValueTable agn6k7kniViBoolean_commands = 
{   /* Attribute ID,                                        SCPI command                    */
    {AGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED,                ":CURR:SHAR",                   ""},
    {AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED,               ":CURR:SLEW:MAX",               ""},
    {AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED,               ":VOLT:SLEW:MAX",               ""},
    {AGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED,                 ":OUTP:PROT:WDOG",              ""},
    {AGN6K7KNI_ATTR_OCP_ENABLED,                            ":CURR:PROT:STAT",              ""},
    {AGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED,              ":OUTP:REL:LOCK",               ""},
    {AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED,                   ":OUTP:REL:POL:ENAB",           ""},
    {AGN6K7KNI_ATTR_RESISTANCE_ENABLED,                     ":RES:STAT",                    ""},
    {AGN6K7KNI_ATTR_OUTPUT_ENABLED,                         ":OUTP",                        ""},
    {AGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED,               ":STEP:TOUT",                   ""},
    {AGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED,                  ":OUTP:COUP",                   ""},
    {AGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED,             ":ARB:TERM:LAST",               ""},
    {AGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED,            ":LIST:TERM:LAST",              ""},
    {AGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED,            ":SENS:ELOG:FUNC:CURR:MINM",    ""},
    {AGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED,                   ":SENS:ELOG:FUNC:CURR",         ""},
    {AGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED,            ":SENS:ELOG:FUNC:VOLT:MINM",    ""},
    {AGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED,                   ":SENS:ELOG:FUNC:VOLT",         ""},
    {AGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED,                ":OUTP:PROT:USER",              ""},
    {AGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED,                ":SENS:FAUL:STAT",              ""},
    {AGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED,     ":DIG:TOUT:BUS",                ""},
    {AGN6K7KNI_ATTR_OUTPUT_RANGE_AUTO,                      ":SENS:CURR:RANG:AUTO",         ""},
    {AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE_AUTO,                ":SENS:ELOG:CURR:RANG:AUTO",    ""},
    {AGN6K7KNI_ATTR_INITIATE_CONTINUOUS,                    ":INIT:CONT:TRAN",              ""},
    {VI_NULL,                                               VI_NULL,                        VI_NULL}
};

static agn6k7kniStringValueTable agn6k7kniViReal64_commands = 
{   /* Attribute ID,                                        SCPI command                    */
    {AGN6K7KNI_ATTR_OUTPUT_RANGE,                           ":SENS:CURR:RANG",              ""},
    {AGN6K7KNI_ATTR_OCP_DELAY,                              ":CURR:PROT:DEL",               ""},
    {AGN6K7KNI_ATTR_RESISTANCE_LEVEL,                       ":RES",                         ""},
    {AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE,                      ":VOLT:SLEW",                   ""},
    {AGN6K7KNI_ATTR_CURRENT_SLEW_RATE,                      ":CURR:SLEW",                   ""},
    {AGN6K7KNI_ATTR_CURRENT_LEVEL,                          ":CURR",                        ""},
    {AGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE,                 ":CURR:LIM:NEG",                ""},
    {AGN6K7KNI_ATTR_VOLTAGE_LIMIT,                          ":VOLT:LIM",                    ""},
    {AGN6K7KNI_ATTR_CURRENT_LIMIT,                          ":CURR:LIM",                    ""},
    {AGN6K7KNI_ATTR_OVP_LIMIT,                              ":VOLT:PROT",                   ""},
    {AGN6K7KNI_ATTR_VOLTAGE_LEVEL,                          ":VOLT",                        ""},
    {AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL,            ":TRIG:ACQ:VOLT",               ""},
    {AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL,            ":TRIG:ACQ:CURR",               ""},
    {AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL,                ":CURR:TRIG",                   ""},
    {AGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL,                ":VOLT:TRIG",                   ""},
    {AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET,                    ":OUTP:COUP:DOFF",              ""},
    {AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE,                      ":OUTP:DEL:RISE",               ""},
    {AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL,                      ":OUTP:DEL:FALL",               ""},
    {AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME,                    ":ARB:VOLT:CDW:DWEL",           ""},
    {AGN6K7KNI_ATTR_MEASUREMENT_TIME,                       ":SENS:SWE:NPLC",               ""},
    {AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL,                    ":SENS:SWE:TINT",               ""},
    {AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE,                     ":SENS:ELOG:CURR:RANG",         ""},
    {AGN6K7KNI_ATTR_ELOG_PERIOD,                            ":SENS:ELOG:PER",               ""},
    {AGN6K7KNI_ATTR_CALIBRATION_DATA,                       ":CAL:DATA",                    ""},
    {VI_NULL,                                               VI_NULL,                        VI_NULL}
};

static agn6k7kniStringValueTable agn6k7kniViInt32_commands = 
{   /* Attribute ID,                                        SCPI command                    */
    {AGN6K7KNI_ATTR_WATCHDOG_DELAY,                         ":OUTP:PROT:WDOG:DEL",          ""},
    {AGN6K7KNI_ATTR_ARB_WFM_COUNT,                          ":ARB:COUN",                    ""},
    {AGN6K7KNI_ATTR_FUNCTION,                               ":FUNC",                        ""},
    {AGN6K7KNI_ATTR_LIST_COUNT,                             ":LIST:COUN",                   ""},
    {AGN6K7KNI_ATTR_SWEEP_POINT,                            ":SENS:SWE:POIN",               ""},
    {AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT,                     ":SENS:SWE:OFFS:POIN",          ""},
    {AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA,                    ":DIG:OUTP:DATA",               ""},
    {AGN6K7KNI_ATTR_DIGITAL_INPUT_DATA,                     ":DIG:INP:DATA",                ""}, 
    {AGN6K7KNI_ATTR_CALIBRATION_COUNT,                      ":CAL:COUN",                    ""},
    {VI_NULL,                                               VI_NULL,                        VI_NULL}
};

/*****************************************************************************
 *----------------- Value Definition and Range Tables -----------------------*
 *****************************************************************************/

static IviRangeTableEntry outputStateRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_OUTPUT_CONSTANT_VOLTAGE, 0, 0, "OPER", 0},
        {AGN6K7KNI_VAL_OUTPUT_CONSTANT_CURRENT, 0, 0, "OPER", 1},
        {AGN6K7KNI_VAL_OUTPUT_UNREGULATED, 0, 0, "QUES1", 1024},
        {AGN6K7KNI_VAL_OUTPUT_OVER_VOLTAGE, 0, 0, "QUES1", 1},
        {AGN6K7KNI_VAL_OUTPUT_OVER_VOLTAGE_NEGATIVE, 0, 0, "QUES1", 64},
        {AGN6K7KNI_VAL_OUTPUT_OVER_CURRENT, 0, 0, "QUES1", 2},
        {AGN6K7KNI_VAL_OUTPUT_OVER_POWER, 0, 0, "QUES1", 8},
        {AGN6K7KNI_VAL_OUTPUT_OVER_POWER_NEGATIVE, 0, 0, "QUES1", 32},
        {AGN6K7KNI_VAL_OUTPUT_OVER_TEMPERATURE, 0, 0, "QUES1", 16},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable outputStateRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        outputStateRangeTableEntries,
    };

static IviRangeTableEntry attrFunctionRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_FUNCTION_VOLTAGE, 0, 0, "VOLT", 0},
        {AGN6K7KNI_VAL_FUNCTION_CURRENT, 0, 0, "CURR", 1},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrFunctionRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrFunctionRangeTableEntries,
    };

static IviRangeTableEntry attrSlewRateRangeTableEntries[] =
    {
        {0, 9.9E37, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrSlewRateRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSlewRateRangeTableEntries,
    };

static IviRangeTableEntry attrVoltageBandwidthRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_HIGH, 0, 0, "HIGH1", 0},
        {AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_LOW, 0, 0, "LOW", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrVoltageBandwidthRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrVoltageBandwidthRangeTableEntries,
    };

static IviRangeTableEntry attrOutputRelayPolarityRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_RELAY_POLARITY_NORMAL, 0, 0, "NORM", 0},
        {AGN6K7KNI_VAL_RELAY_POLARITY_REVERSE, 0, 0, "REV", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrOutputRelayPolarityRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOutputRelayPolarityRangeTableEntries,
    };

static IviRangeTableEntry attrOcpDelayRangeTableEntries[] =
    {
        {0, 0.255, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrOcpDelayRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOcpDelayRangeTableEntries,
    };

static IviRangeTableEntry attrOcpDelayStartTimeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_OCP_DELAY_START_SCHANGE, 0, 0, "SCH", 0},
        {AGN6K7KNI_VAL_OCP_DELAY_START_CCTRANS, 0, 0, "CCTR", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrOcpDelayStartTimeRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOcpDelayStartTimeRangeTableEntries,
    };

static IviRangeTableEntry attrWatchdogDelayRangeTableEntries[] =
    {
        {1, 3600, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrWatchdogDelayRangeTable =
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrWatchdogDelayRangeTableEntries,
    };

static IviRangeTableEntry attrTransientModeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED, 0, 0, "FIX", 0},
        {AGN6K7KNI_VAL_TRANSIENT_MODE_STEP, 0, 0, "STEP", 0},
        {AGN6K7KNI_VAL_TRANSIENT_MODE_LIST, 0, 0, "LIST", 0},
        {AGN6K7KNI_VAL_TRANSIENT_MODE_ARB, 0, 0, "ARB", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrTransientModeRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrTransientModeRangeTableEntries,
    };

static IviRangeTableEntry attrTriggerSourceRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_SOFTWARE_TRIG, 0, 0, "BUS", 0},
        {AGN6K7KNI_VAL_TRIG_EXTERNAL, 0, 0, "EXT", 0},
        {AGN6K7KNI_VAL_TRIG_IMMEDIATE, 0, 0, "IMM", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR1, 0, 0, "EXPR1", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR2, 0, 0, "EXPR2", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR3, 0, 0, "EXPR3", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR4, 0, 0, "EXPR4", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR5, 0, 0, "EXPR5", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR6, 0, 0, "EXPR6", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR7, 0, 0, "EXPR7", 0},
        {AGN6K7KNI_VAL_TRIG_EXPR8, 0, 0, "EXPR8", 0},
        {AGN6K7KNI_VAL_TRIG_PIN1, 0, 0, "PIN1", 0},
        {AGN6K7KNI_VAL_TRIG_PIN2, 0, 0, "PIN2", 0},
        {AGN6K7KNI_VAL_TRIG_PIN3, 0, 0, "PIN3", 0},
        {AGN6K7KNI_VAL_TRIG_PIN4, 0, 0, "PIN4", 0},
        {AGN6K7KNI_VAL_TRIG_PIN5, 0, 0, "PIN5", 0},
        {AGN6K7KNI_VAL_TRIG_PIN6, 0, 0, "PIN6", 0},
        {AGN6K7KNI_VAL_TRIG_PIN7, 0, 0, "PIN7", 0},
        {AGN6K7KNI_VAL_TRIG_CURRENT, 0, 0, "CURR1", 0},
        {AGN6K7KNI_VAL_TRIG_TRANSIENT, 0, 0, "TRAN1", 0},
        {AGN6K7KNI_VAL_TRIG_VOLTAGE, 0, 0, "VOLT1", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrTriggerSourceRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrTriggerSourceRangeTableEntries,
    };

static IviRangeTableEntry attrListStepRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_LIST_STEP_AUTO, 0, 0, "AUTO", 0},
        {AGN6K7KNI_VAL_LIST_STEP_ONCE, 0, 0, "ONCE", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrListStepRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrListStepRangeTableEntries,
    };

static IviRangeTableEntry attrListCountRangeTableEntries[] =
    {
        {1, 4096, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrListCountRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrListCountRangeTableEntries,
    };

static IviRangeTableEntry attrArbWfmCountRangeTableEntries[] =
    {
        {1, 256, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrArbWfmCountRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrArbWfmCountRangeTableEntries,
    };

static IviRangeTableEntry attrArbWfmTypeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_ARB_WFM_TYPE_VOLT, 0, 0, "VOLT", 0},
        {AGN6K7KNI_VAL_ARB_WFM_TYPE_CURR, 0, 0, "CURR", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrArbWfmTypeRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrArbWfmTypeRangeTableEntries,
    };

static IviRangeTableEntry attrConstantDwellTimeRangeTableEntries[] =
    {
        {0.00001024, 0.30, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrConstantDwellTimeRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrConstantDwellTimeRangeTableEntries,
    };

static IviRangeTableEntry attrOutputDelayRangeTableEntries[] =
    {
        {0, 1023, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrOutputDelayRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOutputDelayRangeTableEntries,
    };

static IviRangeTableEntry attrOutputDelayOffsetRangeTableEntries[] =
    {
        {0, 1.023, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrOutputDelayOffsetRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOutputDelayOffsetRangeTableEntries,
    };

static IviRangeTableEntry attrExpressionSourceRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_NONE, 0, 0, "NONE", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR1, 0, 0, "EXPR1", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR2, 0, 0, "EXPR2", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR3, 0, 0, "EXPR3", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR4, 0, 0, "EXPR4", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR5, 0, 0, "EXPR5", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR6, 0, 0, "EXPR6", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR7, 0, 0, "EXPR7", 0},
        {AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR8, 0, 0, "EXPR8", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrExpressionSourceRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrExpressionSourceRangeTableEntries,
    };

static IviRangeTableEntry attrMeasurementTypeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_DC, 0, 0, "CURR", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_RMS, 0, 0, "CURR:ACDC", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_HIGH, 0, 0, "CURR:HIGH", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_LOW, 0, 0, "CURR:LOW", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_MAX, 0, 0, "CURR:MAX", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_CURRENT_MIN, 0, 0, "CURR:MIN", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_DC, 0, 0, "VOLT", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_RMS, 0, 0, "VOLT:ACDC", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_HIGH, 0, 0, "VOLT:HIGH", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_LOW, 0, 0, "VOLT:LOW", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_MAX, 0, 0, "VOLT:MAX", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_MIN, 0, 0, "VOLT:MIN", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_POWER_DC, 0, 0, "POW", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_AHO, 0, 0, "AHO", 0},
        {AGN6K7KNI_VAL_MEAS_TYPE_WHO, 0, 0, "WHO", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrMeasurementTypeRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrMeasurementTypeRangeTableEntries,
    };

static IviRangeTableEntry attrSweepOffsetPointRangeTableEntries[] =
    {
        {-524287, 2000000000, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrSweepOffsetPointRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSweepOffsetPointRangeTableEntries,
    };

static IviRangeTableEntry attrSweepPointRangeTableEntries[] =
    {
        {1, 524288, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrSweepPointRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSweepPointRangeTableEntries,
    };

static IviRangeTableEntry attrSweepTimeIntervalRangeTableEntries[] =
    {
        {0.00000512, 40000, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrSweepTimeIntervalRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrSweepTimeIntervalRangeTableEntries,
    };

static IviRangeTableEntry attrMeasurementTimeRangeTableEntries[] =
    {
        {0.0003072, 1258290000000.0, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrMeasurementTimeRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrMeasurementTimeRangeTableEntries,
    };

static IviRangeTableEntry attrMeasurementWindowRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_MEAS_WINDOW_HANNING, 0, 0, "HANN", 0},
        {AGN6K7KNI_VAL_MEAS_WINDOW_RECT, 0, 0, "RECT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrMeasurementWindowRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrMeasurementWindowRangeTableEntries,
    };

static IviRangeTableEntry attrAcqTriggeredSlopeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS, 0, 0, "POS", 0},
        {AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_NEG, 0, 0, "NEG", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrAcqTriggeredSlopeRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAcqTriggeredSlopeRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdFunctionRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR, 0, 0, "AHO", 0},
        {AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT, 0, 0, "CURR", 0},
        {AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER, 0, 0, "POW", 0},
        {AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE, 0, 0, "VOLT", 0},
        {AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR, 0, 0, "WHO", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdFunctionRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdFunctionRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdOperationRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT, 0, 0, "GT", 0},
        {AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT, 0, 0, "LT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdOperationRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdOperationRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdLevelWhourRangeTableEntries[] =
    {
        {0, +1.127837E+12, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdLevelWhourRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdLevelWhourRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdLevelAhourRangeTableEntries[] =
    {
        {0, +2.251165E+10, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdLevelAhourRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdLevelAhourRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdLevelCurrentRangeTableEntries[] =
    {
        {0, +6.248237E+01, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdLevelCurrentRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdLevelCurrentRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdLevelVoltageRangeTableEntries[] =
    {
        {0, +5.008797E+01, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdLevelVoltageRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdLevelVoltageRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdLevelPowerRangeTableEntries[] =
    {
        {0, +3.130377E+03, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdLevelPowerRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdLevelPowerRangeTableEntries,
    };

static IviRangeTableEntry attrDigitalPinFunctionRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO, 0, 0, "DIO", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN, 0, 0, "DINP", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1, 0, 0, "EXPR1", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2, 0, 0, "EXPR2", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3, 0, 0, "EXPR3", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4, 0, 0, "EXPR4", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5, 0, 0, "EXPR5", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6, 0, 0, "EXPR6", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7, 0, 0, "EXPR7", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8, 0, 0, "EXPR8", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT, 0, 0, "FAUL", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT, 0, 0, "INH", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE, 0, 0, "ONC", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE, 0, 0, "OFFC", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT, 0, 0, "TINP", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT, 0, 0, "TOUT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrDigitalPinFunctionRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrDigitalPinFunctionRangeTableEntries,
    };

static IviRangeTableEntry attrDigitalPinPolarityRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS, 0, 0, "POS", 0},
        {AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG, 0, 0, "NEG", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrDigitalPinPolarityRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrDigitalPinPolarityRangeTableEntries,
    };

static IviRangeTableEntry attrThresholdComparatorNumberRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_1, 0, 0, "", 0},
        {AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_2, 0, 0, "", 0},
        {AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_3, 0, 0, "", 0},
        {AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_4, 0, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrThresholdComparatorNumberRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrThresholdComparatorNumberRangeTableEntries,
    };



static IviRangeTableEntry attrDigitalDataRangeTableEntries[] =
    {
        {0, 127, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrDigitalDataRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrDigitalDataRangeTableEntries,
    };

static IviRangeTableEntry attrElogPeriodRangeTableEntries[] =
    {
        {0.0001024, 60, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrElogPeriodRangeTable = 
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrElogPeriodRangeTableEntries,
    };

static IviRangeTableEntry attrCalibrationLevelRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_CAL_LEVEL_P1, 0, 0, "P1", 0},
        {AGN6K7KNI_VAL_CAL_LEVEL_P2, 0, 0, "P2", 0},
        {AGN6K7KNI_VAL_CAL_LEVEL_P3, 0, 0, "P3", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrCalibrationLevelRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrCalibrationLevelRangeTableEntries,
    };

static IviRangeTableEntry calibrationModeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_CAL_MODE_VOLTAGE, 0, 0, "VOLT", 0},
        {AGN6K7KNI_VAL_CAL_MODE_CMRR, 0, 0, "VOLT:CMRR", 0},
        {AGN6K7KNI_VAL_CAL_MODE_TC, 0, 0, "CURR:TC", 0},
        {AGN6K7KNI_VAL_CAL_MODE_CURRENT_HIGH_RANGE, 0, 0, "CURR", 0},
        {AGN6K7KNI_VAL_CAL_MODE_CURRENT_LOW_RANGE, 0, 0, "CURR:MEAS", 0},
        {AGN6K7KNI_VAL_CAL_MODE_CURRENT_SHARING, 0, 0, "CURR:SHAR", 0},
        {AGN6K7KNI_VAL_CAL_MODE_BOTTOM_OUT_RES, 0, 0, "RES:BOUT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable calibrationModeRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        calibrationModeRangeTableEntries,
    };

static IviRangeTableEntry attrDigitalInhibitModeRangeTableEntries[] =
    {
        {AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_LATCHING, 0, 0, "LATC", 0},
        {AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_LIVE, 0, 0, "LIVE", 0},
        {AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_OFF, 0, 0, "OFF", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };

static IviRangeTable attrDigitalInhibitModeRangeTable = 
    {
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrDigitalInhibitModeRangeTableEntries,
    };

/*****************************************************************************
 *-------------- Utility Function Declarations (Non-Exported) ---------------*
 *****************************************************************************/

static ViStatus agn6k7kni_IviInit (
    ViRsrc resourceName,
    ViBoolean IDQuery,
    ViBoolean reset, 
    ViSession vi);

static ViStatus agn6k7kni_IviClose (
    ViSession vi);   

static ViStatus agn6k7kni_InitAttributes (
    ViSession vi, 
    ViInt32 modelType, 
    ViInt32 optionFlag);

static ViStatus agn6k7kni_DefaultInstrSetup (
    ViSession openInstrSession);

static ViStatus agn6k7kni_CheckStatus (
    ViSession vi);

static ViStatus agn6k7kni_GetDriverSetupOption (
    ViSession vi,
    ViConstString optionTag,
    ViInt32 optionValueSize,
    ViChar optionValue[]);

static ViStatus agn6k7kni_GetModelFromBuffer (
    ViSession vi, 
    ViConstString buffer,
    ViInt32 *modelType);

static ViStatus agn6k7kni_GetOptionsFromBuffer (
    ViSession vi, 
    ViString buffer,
    ViInt32 *optionFlag);

static void agn6k7kni_TrimWhiteSpace (
    ViChar s[]); 

static ViStatus agn6k7kni_ReadUnknownLengthData (
    ViSession vi,
    ViSession io,
    ViString *pData,
    ViInt32 *pDataCount);

static ViStatus agn6k7kni_GetViReal64ArrayFromBuffer (
    ViReal64    measurementArray[],
    ViInt32     arraySize,
    ViChar*     pdata,
    ViInt32*    pActualPoints);

static ViStatus agn6k7kni_CreateModelTable (
    ViSession   vi,
    ViInt32     modelType,
    SInstrumentRangesPtr    *pInstrumentModel);
                                                
static ViStatus agn6k7kni_GetStringFromTable( 
    agn6k7kniStringValueTable table, 
    ViInt32 value,
    ViConstString* string );

static ViStatus agn6k7kni_GetValueFromTable( 
    agn6k7kniStringValueTable table,
    ViConstString string, 
    ViInt32* value );

/*****************************************************************************
 *----------------- Callback Declarations (Non-Exported) --------------------*
 *****************************************************************************/

    /*- Global Session Callbacks --------------------------------------------*/
    
static ViStatus _VI_FUNC agn6k7kni_CheckStatusCallback (
    ViSession vi, 
    ViSession io);

static ViStatus _VI_FUNC agn6k7kni_WaitForOPCCallback (
    ViSession vi, 
    ViSession io);

    /*- Attribute callbacks -------------------------------------------------*/

static ViStatus _VI_FUNC agn6k7kniEnum_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC agn6k7kniEnum_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniViBoolean_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);

static ViStatus _VI_FUNC agn6k7kniViBoolean_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC agn6k7kniViReal64_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC agn6k7kniViReal64_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC agn6k7kniViInt32_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniViInt32_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC agn6k7kniAttrDriverRevision_ReadCallback (
    ViSession vi,
    ViSession io, 
    ViConstString channelName,
    ViAttr attributeId, 
    const ViConstString cacheValue);

static ViStatus _VI_FUNC agn6k7kniAttrInstrumentManufacturer_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue);

static ViStatus _VI_FUNC agn6k7kniAttrInstrumentModel_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue);

static ViStatus _VI_FUNC agn6k7kniAttrFirmwareRevision_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue);

static ViStatus _VI_FUNC agn6k7kniAttrIdQueryResponse_ReadCallback (
    ViSession vi,
    ViSession io, 
    ViConstString channelName, 
    ViAttr attributeId, 
    const ViConstString cacheValue);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevel_ReadCallback (
    ViSession vi,
    ViSession io, 
    ViConstString channelName,
    ViAttr attributeId, 
    ViReal64 *value); 

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevel_WriteCallback (
    ViSession vi,
    ViSession io, 
    ViConstString channelName,
    ViAttr attributeId, 
    ViReal64 value);      

static ViStatus _VI_FUNC agn6k7kniAttrListCount_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC agn6k7kniAttrListCount_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniAttrArbWfmCount_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC agn6k7kniAttrArbWfmCount_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniAttrListCount_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniAttrArbWfmCount_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdFunction_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdFunction_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdOperation_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdOperation_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelAhour_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelAhour_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelCurrent_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelCurrent_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelPower_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelPower_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelVoltage_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelVoltage_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelWhour_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelWhour_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

/*****************************************************************************
 *------------ User-Callable Functions (Exportable Functions) ---------------*
 *****************************************************************************/
 
/*****************************************************************************
 * Function: agn6k7kni_init   
 * Purpose:  VXIplug&play required function.  Calls the   
 *           agn6k7kni_InitWithOptions function.   
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_init (
    ViRsrc resourceName, 
    ViBoolean IDQuery,
    ViBoolean resetDevice, 
    ViSession *newVi)
{   
    ViStatus    error = VI_SUCCESS;

    if (newVi == VI_NULL)
    {
        Ivi_SetErrorInfo (VI_NULL, VI_FALSE, IVI_ERROR_INVALID_PARAMETER, VI_ERROR_PARAMETER4, 
                          "Null address for Instrument Handle");
        checkErr( IVI_ERROR_INVALID_PARAMETER);
    }

    checkErr( agn6k7kni_InitWithOptions (resourceName, IDQuery, resetDevice, "", newVi));

Error:  
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_InitWithOptions                                       
 * Purpose:  This function creates a new IVI session and calls the 
 *           IviInit function.                                     
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_InitWithOptions (
    ViRsrc          resourceName,
    ViBoolean       IDQuery,
    ViBoolean       resetDevice,
    ViConstString   optionString,
    ViSession      *newVi)
{   
    ViStatus    error = VI_SUCCESS;
    ViSession   vi = VI_NULL;
    ViChar      newResourceName[IVI_MAX_MESSAGE_BUF_SIZE] = "";
    ViChar      newOptionString[IVI_MAX_MESSAGE_BUF_SIZE] = "";
    ViBoolean   isLogicalName = VI_FALSE;
    
    if (newVi == VI_NULL)
    {
        Ivi_SetErrorInfo (VI_NULL, VI_FALSE, IVI_ERROR_INVALID_PARAMETER, VI_ERROR_PARAMETER5, 
                          "Null address for Instrument Handle");
        checkErr( IVI_ERROR_INVALID_PARAMETER);
    }

    *newVi = VI_NULL;
    
    checkErr( Ivi_GetInfoFromResourceName( resourceName, 
                                           (ViString)optionString,
                                           newResourceName,
                                           newOptionString,
                                           &isLogicalName));
    
        /* create a new interchangeable driver */
    checkErr( Ivi_SpecificDriverNew ("agn6k7kni", newOptionString, &vi));  
    if (!isLogicalName)
    {
        ViInt32 oldFlag = 0;
        
        checkErr (Ivi_GetAttributeFlags (vi, IVI_ATTR_IO_RESOURCE_DESCRIPTOR, &oldFlag));
        checkErr (Ivi_SetAttributeFlags (vi, IVI_ATTR_IO_RESOURCE_DESCRIPTOR, 
                                         oldFlag & 0xfffb | 0x0010));
        checkErr (Ivi_SetAttributeViString (vi, "", IVI_ATTR_IO_RESOURCE_DESCRIPTOR, 0, 
                                            newResourceName));
    }
        /* init the driver */
    checkErr( agn6k7kni_IviInit (newResourceName, IDQuery, resetDevice, vi)); 
    if (isLogicalName)
        checkErr( Ivi_ApplyDefaultSetup (vi));
    *newVi = vi;
    
Error:
    if (error < VI_SUCCESS) 
        Ivi_Dispose (vi);
        
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_close                                                           
 * Purpose:  This function closes the instrument.                            
 *
 *           Notes:  
 *           (1) This function must unlock the session before calling
 *               Ivi_Dispose.
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_close (
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    checkErr( agn6k7kni_IviClose (vi));

Error:    
    Ivi_UnlockSession (vi, VI_NULL);
    Ivi_Dispose (vi);  

    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_reset                                                         
 * Purpose:  This function resets the instrument.                          
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_reset (
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */
        
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viPrintf (io, "*RST"));
    }
    
    checkErr( agn6k7kni_DefaultInstrSetup (vi));                                
    
    checkErr( agn6k7kni_CheckStatus (vi));                                      

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_ResetWithDefaults
 * Purpose:  This function resets the instrument and applies default settings
 *           from the IVI Configuration Store based on the logical name
 *           from which the session was created.
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_ResetWithDefaults (
    ViSession vi)
{
    ViStatus error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    checkErr( agn6k7kni_reset(vi));
    checkErr( Ivi_ApplyDefaultSetup(vi));
    
Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/***************************************************************************** 
 *  Function: agn6k7kni_Disable
 *  Purpose:  This function places the instrument in a quiescent state as 
 *            quickly as possible.
 *              
 *            Notes:
 *            (1) Note: This function is not supported.  
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_Disable (
    ViSession vi)
{
    ViStatus error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));

    /* This function is not supported. */
 
Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_self_test                                                       
 * Purpose:  This function executes the instrument self-test and returns the 
 *           result.                                                         
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_self_test (
    ViSession vi, 
    ViInt16 *testResult, 
    ViChar testMessage[])
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (testResult == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Test Result");
    if (testMessage == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Test Message");

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */
    
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viPrintf (io, "*TST?"));
            
        viCheckErr( viScanf (io, "%hd,\"%256[^\"]", testResult, testMessage));
    
    }
    else
    {
            /* Simulate Self Test */
        *testResult = 0;
        strcpy (testMessage, "No error.");
    }
    
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_revision_query                                                  
 * Purpose:  This function returns the driver and instrument revisions.      
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_revision_query (
    ViSession vi, 
    ViChar driverRev[], 
    ViChar instrRev[])
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (driverRev == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Driver Revision");
    if (instrRev == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Instrument Revision");

    checkErr( Ivi_GetAttributeViString (vi, VI_NULL, AGN6K7KNI_ATTR_SPECIFIC_DRIVER_REVISION, 
                                        0, 256, driverRev));
    checkErr( Ivi_GetAttributeViString (vi, "", AGN6K7KNI_ATTR_INSTRUMENT_FIRMWARE_REVISION, 
                                        0, 256, instrRev));
    checkErr( agn6k7kni_CheckStatus (vi));

Error:    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_error_query                                                     
 * Purpose:  This function queries the instrument error queue and returns   
 *           the result.                                                     
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_error_query (
    ViSession vi, 
    ViInt32 *errCode, 
    ViChar errMessage[])
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (errCode == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Error Code");
    if (errMessage == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Error Message");

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */
    
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viPrintf(io, ":SYST:ERR?"));
    
        viCheckErr( viScanf (io, "%ld,\"%256[^\"]", errCode, errMessage));
    
    }
    else
    {
            /* Simulate Error Query */
        *errCode = 0;
        strcpy (errMessage, "No error.");
    }

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_error_message                                                  
 * Purpose:  This function translates the error codes returned by this       
 *           instrument driver into user-readable strings.  
 *
 *           Note:  The caller can pass VI_NULL for the vi parameter.  This 
 *           is useful if one of the init functions fail.
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_error_message (
    ViSession vi,
    ViStatus errorCode,
    ViChar errorMessage[256])
{
    ViStatus    error = VI_SUCCESS;
    
    static      IviStringValueTable errorTable = 
    {
            {AGN6K7KNI_ERROR_TRIGGER_NOT_SOFTWARE,  "Trigger type is not software."},
            {AGN6K7KNI_ERROR_INVALID_OPTION_TYPE,   "Option type is invalid."},                     
            
            IVIDCPWR_ERROR_CODES_AND_MSGS,
            {VI_NULL,                               VI_NULL}
    };
        
    if (vi)
        Ivi_LockSession(vi, VI_NULL);

        /* all VISA and IVI error codes are handled as well as codes in the table */
    if (errorMessage == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Error Message");

    checkErr( Ivi_GetSpecificDriverStatusDesc(vi, errorCode, errorMessage, errorTable));

Error:
    if (vi)
        Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_InvalidateAllAttributes
 * Purpose:  This function invalidates the cached value of all attributes.
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_InvalidateAllAttributes (ViSession vi)
{
    return Ivi_InvalidateAllAttributes(vi);
}

ViStatus _VI_FUNC agn6k7kni_GetErrorInfo (
    ViSession vi, 
    ViStatus *primaryError, 
    ViStatus *secondaryError, 
    ViChar errorElaboration[256])  
{                                                                                                           
    return Ivi_GetErrorInfo(vi, primaryError, secondaryError, errorElaboration);                                
}     

ViStatus _VI_FUNC agn6k7kni_ClearErrorInfo (
    ViSession vi)                                                        
{                                                                                                           
    return Ivi_ClearErrorInfo (vi);                                                                             
}

/*****************************************************************************
 * Function: agn6k7kni_GetError and agn6k7kni_ClearError Functions                       
 * Purpose:  These functions enable the instrument driver user to  
 *           get or clear the error information the driver associates with the
 *           IVI session.                                                        
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_GetError (
    ViSession vi, 
    ViStatus *errorCode, 
    ViInt32 bufferSize,
    ViChar description[])  
{
    ViStatus error = VI_SUCCESS;
    ViStatus primary = VI_SUCCESS,
             secondary = VI_SUCCESS;
    ViChar   elaboration[256] = "";
    ViChar   errorMessage[1024] = "";
    ViChar  *appendPoint = errorMessage;
    ViInt32  actualSize = 0;
    ViBoolean locked = VI_FALSE;

    /* Lock Session */
    if (vi != 0)
    {
        checkErr( Ivi_LockSession(vi, &locked));
    }

    /* Test for nulls and acquire error data */
    if (bufferSize != 0)
    {
        if (errorCode == VI_NULL)
        {
            viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Error");
        }
        if (description == VI_NULL)
        {
            viCheckParm( IVI_ERROR_INVALID_PARAMETER, 4, "Null address for Description");
        }
        checkErr( Ivi_GetErrorInfo (vi, &primary, &secondary, elaboration));
    }

    else
    {
        checkErr( Ivi_GetAttributeViString(vi, VI_NULL, IVI_ATTR_ERROR_ELABORATION, 0, 256, 
                                           elaboration));
        checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, IVI_ATTR_SECONDARY_ERROR, 0, &secondary));
        checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, IVI_ATTR_PRIMARY_ERROR, 0, &primary));
    }
        
    /* Format data */
    if (primary != VI_SUCCESS)
    {
        ViChar msg[256] = "";
        checkErr( agn6k7kni_error_message (vi, primary, msg));
        appendPoint += sprintf(appendPoint, "Primary Error: (Hex 0x%08X) %s\n", primary, msg);
    }
    
    if (secondary != VI_SUCCESS)
    {
        ViChar msg[256] = "";
        checkErr( agn6k7kni_error_message (vi, secondary, msg));
        appendPoint += sprintf(appendPoint, "Secondary Error: (Hex 0x%08X) %s\n", secondary, msg);
    }
    
    if (elaboration[0])
    {
        sprintf(appendPoint, "Elaboration: %s", elaboration);
    }
    
    actualSize = (ViInt32)(strlen(errorMessage) + 1);
    
    /* Prepare return values */
    if (bufferSize == 0)
    {
        error = actualSize;
    }
    else 
    {
        if (bufferSize > 0)
        {
            if (actualSize > bufferSize)
            {
                error = actualSize;
                actualSize = bufferSize;
            }
        }
        memcpy(description, errorMessage, actualSize-1);
        description[actualSize-1] = '\0';
    }
    
    if (errorCode) 
    {
        *errorCode = primary;
    }
    
Error:
    /* Unlock Session */
    Ivi_UnlockSession (vi, &locked);
    return error;
}   

ViStatus _VI_FUNC agn6k7kni_ClearError (
    ViSession vi)                                                        
{                                                                                                           
    return Ivi_ClearErrorInfo (vi);                                                                             
}

/*****************************************************************************
 * Function: agn6k7kni_GetNextCoercionRecord                        
 * Purpose:  This function enables the instrument driver user to obtain
 *           the coercion information associated with the IVI session.                                                              
 *           This function retrieves and clears the oldest instance in which 
 *           the instrument driver coerced a value the instrument driver user
 *           specified to another value.                     
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_GetNextCoercionRecord (
    ViSession vi,
    ViInt32 bufferSize,
    ViChar  record[])
{
    return Ivi_GetNextCoercionString (vi, bufferSize, record);
}

/**************************************************************************** 
 *  Function: agn6k7kni_GetNextInterchangeWarning,
 *            agn6k7kni_ResetInterchangeCheck, and
 *            agn6k7kni_ClearInterchangeWarnings
 *  Purpose:  These functions allow the user to retrieve interchangeability
 *            warnings, reset the driver's interchangeability checking 
 *            state, and clear all previously logged interchangeability warnings.
 ****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_GetNextInterchangeWarning (
    ViSession vi, 
    ViInt32 bufferSize, 
    ViChar warnString[])
{
    return Ivi_GetNextInterchangeCheckString (vi, bufferSize, warnString);
}

ViStatus _VI_FUNC agn6k7kni_ResetInterchangeCheck (
    ViSession vi)
{
    return Ivi_ResetInterchangeCheck (vi);
}

ViStatus _VI_FUNC agn6k7kni_ClearInterchangeWarnings (
    ViSession vi)
{
    return Ivi_ClearInterchangeWarnings (vi);
}

/*****************************************************************************
 * Function: agn6k7kni_LockSession and agn6k7kni_UnlockSession Functions                        
 * Purpose:  These functions enable the instrument driver user to lock the 
 *           session around a sequence of driver calls during which other
 *           execution threads must not disturb the instrument state.
 *                                                                          
 *           NOTE:  The callerHasLock parameter must be a local variable 
 *           initialized to VI_FALSE and passed by reference, or you can pass 
 *           VI_NULL.                     
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_LockSession (
    ViSession vi, 
    ViBoolean *callerHasLock)  
{                                              
    return Ivi_LockSession(vi,callerHasLock);      
}         

ViStatus _VI_FUNC agn6k7kni_UnlockSession (
    ViSession vi, 
    ViBoolean *callerHasLock) 
{                                              
    return Ivi_UnlockSession(vi,callerHasLock);    
}
    
/**************************************************************************** 
 *  Function: agn6k7kni_GetChannelName
 *  Purpose:  This function returns the highest-level channel name that
 *            corresponds to the specific driver channel string that is in
 *            the channel table at an index you specify.
 ****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_GetChannelName (
    ViSession vi, 
    ViInt32 index,
    ViInt32 bufferSize,
    ViChar name[])
{
    ViStatus         error = VI_SUCCESS;
    ViConstString    channelName;
    ViInt32          actualSize = 0;
    ViInt32         channelCount;

    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    /* Check parameters */
    if (bufferSize != 0)
    {
        if (name == VI_NULL)
        {
            viCheckParm( IVI_ERROR_INVALID_PARAMETER, 4, "Null address for Channel Name");
        }
    }
        
    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, IVI_ATTR_CHANNEL_COUNT, 0, &channelCount));
    if ( (index<1) || (index>channelCount) )
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Channel Index");
    
    /* Get channel name */
    viCheckParm( Ivi_GetNthChannelString (vi, index, &channelName), 2, "Index");
    checkErr( Ivi_GetUserChannelName (vi, channelName, &channelName));
    
    actualSize = (ViInt32)(strlen(channelName) + 1);
    
    /* Prepare return values */
    if (bufferSize == 0)
    {
        error = actualSize;
    }
    else 
    {
        if (bufferSize > 0)
        {
            if (actualSize > bufferSize)
            {
                error = actualSize;
                actualSize = bufferSize;
            }
        }
        memcpy(name, channelName, actualSize-1);
        name[actualSize-1] = '\0';
    }

Error:    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}   
    
/*===========================================================================*
 *= IviDCPwr Base Capability Group Functions ================================*
 *===========================================================================*/         
                           
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureCurrentSharing
 * Purpose:   Configures the current sharing settings on paralleled units. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureCurrentSharing (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED,
                                            0, enabled), 3, "Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureWatchdogTimer
 * Purpose:   This function configures the watchdog timer. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureWatchdogTimer (
    ViSession vi, 
    ViBoolean enabled, 
    ViInt32 delay)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED,
                                            0, enabled), 2, "Enabled");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_WATCHDOG_DELAY,
                                          0, delay), 3, "Delay");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOCP
 * Purpose:   This function configures the Over-Current Protection. 
 *            When over-current protection is enabled, the power supply turns 
 *            off the output if the output current reaches the current limit 
 *            setting and transitions from constant voltage (CV) to current 
 *            limit (CL+ or CL-) mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOCP (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled, 
    ViReal64 delay, 
    ViInt32 delayStartTime)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_OCP_ENABLED,
                                            0, enabled), 3, "Enabled");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_OCP_DELAY,
                                           0, delay), 4, "Delay");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_OCP_DELAY_START_TIME,
                                          0, delayStartTime), 5, "Delay Start Time");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputResistance
 * Purpose:   This function configures the output resistance of the APS. 
 *            Output resistance programming is mainly used in battery testing 
 *            applications and only applies in Voltage Priority mode. 
 *            It is used to emulate the internal resistance of a non-ideal 
 *            voltage source such as a battery.
 *            
 *            Notes:
 *            (1) Output resistance programming is mainly used in battery 
 *                testing applications and only applies in Voltage Priority 
 *                mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputResistance (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled, 
    ViReal64 resistance)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_RESISTANCE_ENABLED,
                                            0, enabled), 3, "Enabled");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_RESISTANCE_LEVEL,
                                           0, resistance), 4, "Resistance");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputBandwidth
 * Purpose:   This function sets the voltage bandwidth modes. Voltage bandwidth 
 *            modes allow you to optimize output response time with capacitive 
 *            loads. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputBandwidth (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 bandwidth)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH,
                                          0, bandwidth), 3, "Bandwidth");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureSlewRate
 * Purpose:   This function sets the voltage or current slew rate for the active 
 *            priority mode.
 *            
 *            Max slew rate (V/s) = (Current limit setting (A) - 
 *                                  Load current (A))/(Load capacitance (F))
 *            
 *            Notes:
 *            (1) Use agn6k7kni_ConfigureOutputPriorityMode function to 
 *                configure the active priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureSlewRate (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 slewRate)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     priorityMode = 0;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");
    
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_FUNCTION, 0, &priorityMode));
    if (slewRate == AGN6K7KNI_VAL_SLEW_RATE_MAX)
    {
        if (priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE)
        {
            viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, 
                                                    AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED, 
                                                    0, VI_TRUE), 3, "Slew Rate");     
        }
        else
        {
            viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, 
                                                    AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED, 
                                                    0, VI_TRUE), 3, "Slew Rate");     
        }
    }
    else
    {
        if (priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE)
        {
            checkErr( Ivi_SetAttributeViBoolean (vi, channelName, 
                                                 AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED, 
                                                 0, VI_FALSE));
            viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, 
                                                   AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE, 
                                                   0, slewRate), 3, "Slew Rate");
        }
        else
        {
            checkErr( Ivi_SetAttributeViBoolean (vi, channelName, 
                                                 AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED, 
                                                 0, VI_FALSE));
            viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,     
                                                   AGN6K7KNI_ATTR_CURRENT_SLEW_RATE, 
                                                   0, slewRate), 3, "Slew Rate");
        }
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureCurrentLevel
 * Purpose:   This function sets the current level when the output is operating 
              in current priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureCurrentLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_CURRENT_LEVEL,
                                           0, level), 3, "Level");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureNegativeCurrentLimit
 * Purpose:   This function configures the negative current limit. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureNegativeCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 limit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE,
                                           0, limit), 3, "Limit");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureVoltageLimit
 * Purpose:   This function sets the voltage limit when in current priority 
 *            mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureVoltageLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 limit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_VOLTAGE_LIMIT,
                                           0, limit), 3, "Limit");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputPriorityMode
 * Purpose:   This function selects either voltage priority or current priority 
 *            mode.
 *            
 *            Voltage priority mode is used when you want the output voltage 
 *            to remain constant. The output voltage will remain at its 
 *            programmed setting as long as the load current remains within the 
 *            positive or negative current limit setting.
 *            
 *            Current priority mode is used when you want the output current to 
 *            remain constant. The output current will remain at its programmed 
 *            setting as long as the load voltage remains within the voltage 
 *            limit setting. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputPriorityMode (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 priorityMode)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_FUNCTION, 0, 
                                          priorityMode), 2, "Priority Mode");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputRelay
 * Purpose:   This function configures the output relay. 
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputRelay (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean polarityEnabled, 
    ViInt32 polarity, 
    ViBoolean lockEnabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");   
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED,
                                            0, polarityEnabled), 3, "Polarity Enabled");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY,
                                          0, polarity), 4, "Polarity");
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, 
                                            AGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED,
                                            0, lockEnabled), 5, "Lock Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureCurrentLimit
 * Purpose:   This function configures the current protection state and 
 *            positive current limit. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 behavior, 
    ViReal64 limit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_CURRENT_LIMIT,
                                           0, limit), 4, "Limit");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputEnabled
 * Purpose:   This function configures the output state of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputEnabled (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_ENABLED, 0, 
                                            enabled), 3, "Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputRange
 * Purpose:   This function configures the output range of the APS.
 *
 *            Notes:
 *            (1) This function supports N79XX models only.
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputRange (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 rangeType, 
    ViReal64 range)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    
    if (range == AGN6K7KNI_VAL_OUTPUT_RANGE_AUTO)
    {
        viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_RANGE_AUTO,
                                                0, VI_TRUE), 4, "Range");          
    }
    else
    {   
        checkErr( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_RANGE_AUTO,
                                             0, VI_FALSE)); 
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_RANGE,
                                               0, range), 4, "Range");  
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOVP
 * Purpose:   This function configures the Over-Voltage Protection. 
 *            The over-voltage protection will turn the output off if the output 
 *            voltage reaches the programmed over-voltage limit. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOVP (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled, 
    ViReal64 limit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");   
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_OVP_LIMIT,
                                           0, limit), 4, "Limit");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureVoltageLevel
 * Purpose:   This function sets the output voltage level when the output is 
 *            operating in voltage priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureVoltageLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");   
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_VOLTAGE_LEVEL,
                                           0, level), 3, "Level");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_QueryMaxCurrentLimit
 * Purpose:   This function returns the maximum programmable current limit that 
 *            the APS accepts for a particular voltage level on a channel for 
 *            the output range to which the power supply is currentl configured. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_QueryMaxCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 voltageLevel, 
    ViReal64* maxCurrentLimit)
{
    ViStatus    error = VI_SUCCESS;
    SInstrumentRangesPtr    pInstrumentModel = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (maxCurrentLimit == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 4, "Null value for Max Current Limit.");
    }
    
    checkErr( Ivi_CoerceChannelName (vi, channelName, &channelName) );  
    checkErr( Ivi_GetAttributeViAddr( vi, VI_NULL, AGN6K7KNI_ATTR_INSTR_MODULES_RANGES,
                                      0, (ViAddr *)&pInstrumentModel));
    
    if (Ivi_RangeChecking(vi))
    {
        if (voltageLevel < pInstrumentModel->minVoltage ||
            voltageLevel > pInstrumentModel->maxVoltage)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 3, "Voltage Level"); 
        }
    }
    
    if (!Ivi_Simulating(vi))
    {
        ViSession   io = Ivi_IOSession(vi);
        
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viQueryf (io, ":CURR? MAX,(@%s)", "%lf", channelName, maxCurrentLimit));        
    }
    else
    {
        *maxCurrentLimit = pInstrumentModel->maxCurrent;    
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_QueryMaxVoltageLevel
 * Purpose:   This function returns the maximum programmable voltage level that 
 *            the APS accepts for a particular current limit on a channel for 
 *            the output range to which the power supply is currently configured.
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_QueryMaxVoltageLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 currentLimit, 
    ViReal64 *maxVoltageLevel)
{
    ViStatus    error = VI_SUCCESS;
    SInstrumentRangesPtr    pInstrumentModel = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (maxVoltageLevel == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 4, "Null value for Max Voltage Level.");
    }
    
    checkErr( Ivi_CoerceChannelName (vi, channelName, &channelName) );  
    checkErr( Ivi_GetAttributeViAddr( vi, VI_NULL, AGN6K7KNI_ATTR_INSTR_MODULES_RANGES,
          0, (ViAddr *)&pInstrumentModel));
    
    if (Ivi_RangeChecking(vi))
    {
        if (currentLimit < pInstrumentModel->minCurrent ||
            currentLimit > pInstrumentModel->maxCurrent)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 3, "Current Limit"); 
        }
    }
    
    if (!Ivi_Simulating(vi))
    {
        ViSession   io = Ivi_IOSession(vi);
        
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viQueryf (io, ":VOLT? MAX,(@%s)", "%lf", channelName, maxVoltageLevel));        
    }
    else
    {
        *maxVoltageLevel = pInstrumentModel->maxVoltage;    
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_QueryOutputState
 * Purpose:   This function returns whether the power supply is in a particular 
 *            output state.
 *
 *            A constant voltage condition occurs when the output voltage is 
 *            equal to the value of the AGN6K7KNI_ATTR_VOLTAGE_LEVEL attribute
 *            and the current is less than or equal to the value of the
 *            AGN6K7KNI_ATTR_CURRENT_LIMIT attribute.
 *
 *            A constant current condition occurs when the output current is
 *            equal to the value of the AGN6K7KNI_ATTR_CURRENT_LIMIT attribute.
 *
 *            An unregulated condition occurs when the output voltage is less
 *            than the value of the AGN6K7KNI_ATTR_VOLTAGE_LEVEL attribute and
 *            the current is less than the value of the
 *            AGN6K7KNI_ATTR_CURRENT_LIMIT attribute.
 *
 *            An over-voltage condition occurs when the output voltage is equal 
 *            to or greater than the value of the AGN6K7KNI_ATTR_OVP_LIMIT 
 *            attribute and the AGN6K7KNI_ATTR_OVP_ENABLED attribute is set to 
 *            VI_TRUE.
 *
 *            An over-current condition occurs when the output current is equal 
 *            to or greater than the value of the AGN6K7KNI_ATTR_CURRENT_LIMIT 
 *            attribute.
 *          
 *            When either an over-voltage condition or an over-current condition 
 *            occurs, the power supply's output protection disables the output.  
 *            If the power supply is in an over-voltage or over-current state, 
 *            it does not produce power until the output protection is reset.  
 *            The agn6k7kni_ResetOutputProtection function resets the output 
 *            protection.  Once the output protection is reset, the power supply 
 *            resumes generating a power signal. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_QueryOutputState (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 outputState, 
    ViBoolean* inState)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command = VI_NULL; 
    ViInt32     value = 0,
                commandValue = 0;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (inState == VI_NULL)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 4, "Null value for In State.");
    }
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_GetViInt32EntryFromValue(outputState, &outputStateRangeTable, VI_NULL, 
                                              VI_NULL, VI_NULL, VI_NULL, &command, &commandValue), 
                                              3, "Output State");       
    
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viQueryf (io, ":STAT:%s:COND? (@%s)", "%ld", command, channelName, &value));
    }
    *inState = ((value & commandValue) != 0); 
    
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ResetOutputProtection
 * Purpose:   Clear the protection function and restore normal operation.
 *            
 *            SCPI Commands:
 *            OUTPut:PROTection:CLEar 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ResetOutputProtection (
    ViSession vi, 
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viPrintf (io, ":OUTP:PROT:CLE (@%s)", channelName));
    }
    
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Trigger Extension Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTriggerOutEnabled
 * Purpose:   This function configures whether a trigger out is generated when 
 *            a transient step occurs. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggerOutEnabled (
    ViSession vi, 
    ViConstString channelName, 
    ViBoolean enabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED,
                                            0, enabled), 3, "Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureAcqTriggeredCurrent
 * Purpose:   This function sets the triggered current for the acquisition 
 *            system. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureAcqTriggeredCurrent (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level, 
    ViInt32 slope)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");           
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL,
                                           0, level), 3, "Level");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE,
                                          0, slope), 4, "Slope");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureAcqTriggeredVoltage
 * Purpose:   This function sets the triggered voltage for the acquisition 
 *            system. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureAcqTriggeredVoltage (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level, 
    ViInt32 slope)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, 
                                           AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL, 0, level), 
                                           3, "Level");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, 
                                          AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE, 0, slope), 
                                          4, "Slope");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureArbTriggerSource
 * Purpose:   This function configures the trigger source for arbitrary waveforms.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureArbTriggerSource (
    ViSession vi, 
    ViInt32 arbTriggerSource)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE,
                                          0, arbTriggerSource), 3, "Arb Trigger Source");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureAcqTriggerSource
 * Purpose:   Configures the trigger source for the acquisition system. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureAcqTriggerSource (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 acquireSource)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE,
                                          0, acquireSource), 3, "Acquire Source");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTriggeredCurrentLevel
 * Purpose:   This function sets the triggered current level when the output is 
 *            operating in current priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggeredCurrentLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL,
                                           0, level), 3, "Level");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTransientMode
 * Purpose:   This function configures the output transient mode for the active 
 *            priority mode.
 *            
 *            Notes:
 *            (1) Use agn6k7kni_ConfigureOutputPriorityMode function to 
 *                configure the active priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTransientMode (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 transientMode)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     priorityMode = 0;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_FUNCTION, 0, &priorityMode)); 
    
    if (priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE)
    {
        viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE,
                                              0, transientMode), 3, "Transient Mode");
    }
    else
    {
        viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE,
                                              0, transientMode), 3, "Transient Mode");       
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_Abort
 * Purpose:   This function cancels any triggered actions. It also resets the 
 *            WTG-tran and TRAN-active bits in the Operation Status registers. 
 *            
 *            Notes:
 *            (1) This function does not turn off continuous triggers. In this 
                  case, the trigger system will automatically re-initiate.
 *            
 *            SCPI Command:
 *            ABORt:TRANsient
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_Abort (
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
   if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":ABOR:TRAN"));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_InitiateDatalog
 * Purpose:   This function initiates the external data logging.
 *            
 *            SCPI Command:
 *            INITiate[:IMMediate]:ELOG
 *            
 *            Notes:
 *            (1) It takes a few milliseconds for the instrument to be ready to 
 *                receive a trigger signal after receiving the INITiate command. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_InitiateDatalog (
    ViSession vi,
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":INIT:ELOG (@%s)", channelName));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                               

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_AbortDatalog
 * Purpose:   This function stops external data logging. It also resets the 
 *            WTG-tran and TRAN-active bits in the Operation Status registers.
 *
 *            Notes:
 *            (1) This function supports N79XX models only.
 *            (2) This function does not turn off continuous triggers. In this
 *                case, the trigger system will automatically re-initiate.
 *
 *            SCPI Command:
 *            ABORt:ELOG
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_AbortDatalog (
    ViSession vi,
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":ABOR:ELOG (@%s)", channelName));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTriggeredCurrentLimit
 * Purpose:   This function is used to comply with the IVI DC Power 
 *            specification only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggeredCurrentLimit (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 limit)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LIMIT,
                 0, limit), 3, "Limit");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTriggeredVoltageLevel
 * Purpose:   This function sets the triggered voltage level when the output is 
 *            operating in voltage priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggeredVoltageLevel (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 level)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL,
                                           0, level), 3, "Level");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTriggerSource
 * Purpose:   Configures the trigger source the APS waits for before changing 
 *            the output signal. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggerSource (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 source)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_TRIGGER_SOURCE,
                                          0, source), 3, "Source");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_Initiate
 * Purpose:   This function initiates the transient trigger system.
 *            
 *            SCPI Command:
 *            INITiate[:IMMediate]:TRANsient
 *            
 *            Notes:
 *            (1) It takes a few milliseconds for the instrument to be ready to 
 *                receive a trigger signal after receiving the INITiate command. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_Initiate (
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
   if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":INIT:TRAN"));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                               

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr SoftwareTrigger Extension Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_SendSoftwareTrigger
 * Purpose:   Generates an immediate transient trigger. This overrides any 
 *            selected trigger source.
 *            
 *            SCPI Command:
 *            TRIGger:TRANsient[:IMMediate] 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_SendSoftwareTrigger (
                  ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
   if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 
        viCheckErr( viPrintf (io, ":TRIG:TRAN"));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Measurement Extension Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_FetchArray
 * Purpose:   This function fetches the instantaneous measurement.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only.
 *            
 *            SCPI Command:
 *            FETCh:ARRay:CURRent[:DC]? [<start_index>, <points>]
 *            FETCh:ARRay:VOLTage[:DC]? [<start_index>, <points>]
 *            FETCh:ARRay:POWer[:DC]? [<start_index>, <points>] 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_FetchArray (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 maximumTime, 
    ViInt32 measurementType, 
    ViInt32 startIndex, 
    ViInt32 length, 
    ViInt32 arraySize, 
    ViReal64 measurementArray[], 
    ViInt32 *actualPoints)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     pointNumber = 0;
    ViString    pData = NULL;  
    IviRangeTablePtr table = VI_NULL;
    ViString    commandValue = VI_NULL;
    ViSession   io = VI_NULL;
    ViInt32     oldTimeout = 0;
    ViBoolean   needToRestoreTimeout = VI_FALSE;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_SWEEP_POINT, 0, &pointNumber));

    if (startIndex < 0 || startIndex > pointNumber)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 5, "Start index out of range."); 
    }   
    
    if (length < 1 || length > pointNumber - startIndex)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 6, "Length is too long.");
    }
    
    if (arraySize < 1)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 7, "Array Size is too small."); 
    }
        
    if (measurementArray == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 8, "Null value for Measurement.");
    }
    
    if (actualPoints == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 9, "Null value for Actual Points."); 
    }
    
    checkErr( Ivi_GetAttrRangeTable (vi, channelName, AGN6K7KNI_ATTR_MEASUREMENT_TYPE, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(measurementType, table, &commandValue));
    
    if (!Ivi_Simulating(vi))
    {
        io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        
        viCheckErr( viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));      
        viCheckErr( viSetAttribute (io, VI_ATTR_TMO_VALUE, maximumTime));
        needToRestoreTimeout = VI_TRUE;
    
        viCheckErr( viPrintf (io, ":FETC:ARR:%s? (@%s)", commandValue, channelName));
        checkErr( agn6k7kni_ReadUnknownLengthData( vi, io, &pData, NULL));
        viCheckErr( agn6k7kni_GetViReal64ArrayFromBuffer(measurementArray, arraySize, pData, 
                                                         actualPoints));
    }
   
    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */   

Error:
    if (needToRestoreTimeout)
    {
        viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout);  
    }
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_MeasureArray
 * Purpose:   This function takes a measurement on the output signal and fetches 
 *            the instantaneous measurement.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only.
 *            
 *            SCPI Command:
 *            FETCh:ARRay:CURRent[:DC]? [<start_index>, <points>]
 *            FETCh:ARRay:VOLTage[:DC]? [<start_index>, <points>]
 *            FETCh:ARRay:POWer[:DC]? [<start_index>, <points>] 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_MeasureArray (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 measurementType, 
    ViInt32 startIndex, 
    ViInt32 length, 
    ViInt32 arraySize, 
    ViReal64 measurementArray[], 
    ViInt32 *actualPoints)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     pointNumber = 0;
    ViString    pData = NULL;  
    IviRangeTablePtr table = VI_NULL;
    ViString    commandValue = VI_NULL;
    ViSession   io = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_SWEEP_POINT, 0, 
                                      &pointNumber));

    if (startIndex < 0 || startIndex > pointNumber)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 4, "Start index out of range."); 
    }   
    
    if (length < 1 || length > pointNumber - startIndex)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 5, "Length is too long.");
    }
    
    if (arraySize < 1)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 6, "Array Size is too small."); 
    }
        
    if (measurementArray == VI_NULL)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 7, "Null value for Measurement.");
    }
    
    if (actualPoints == VI_NULL)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 8, "Null value for Actual Points."); 
    }
    
    checkErr( Ivi_GetAttrRangeTable (vi, channelName, AGN6K7KNI_ATTR_MEASUREMENT_TYPE, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(measurementType, table, &commandValue));
    
    if (!Ivi_Simulating(vi))
    {
        io = Ivi_IOSession(vi);
        
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
    
        viCheckErr( viPrintf (io, ":MEAS:ARR:%s? (@%s)", commandValue, channelName));
        checkErr( agn6k7kni_ReadUnknownLengthData( vi, io, &pData, NULL));
        viCheckErr( agn6k7kni_GetViReal64ArrayFromBuffer(measurementArray, arraySize, pData, 
                                                         actualPoints));
    }
   
    checkErr( agn6k7kni_CheckStatus(vi));  

Error:
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_MeasureTemperature
 * Purpose:   This function returns the ambient temperature measured at the air 
 *            inlet on the right side of the unit. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_MeasureTemperature (
    ViSession vi, 
    ViReal64 *ambientTemperature, 
    ViReal64 *overTemperatureMargin)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    /* Parameter Validation */
    if (ambientTemperature == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null value for ambient temperature");   
    }
    
    if (overTemperatureMargin == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Null value for over temperature margin"); 
    }
    
    /* Read temperature measurement */
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        
        viCheckErr( viQueryf(io, "SYST:TEMP:AMB?", "%lf", ambientTemperature));
        viCheckErr( viQueryf(io, "OUTP:PROT:TEMP:MARG?", "%lf", overTemperatureMargin));
    }
    else
    {
        *ambientTemperature = 23.5;
        *overTemperatureMargin = 47.0;
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ResetAhoWhoMeasurements
 * Purpose:   This function resets the amp-hour or watt-hour measurement to zero.  
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ResetAhoWhoMeasurements (
    ViSession vi,
    ViConstString channelName,
    ViInt32 measurementType)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        if (measurementType == AGN6K7KNI_VAL_MEAS_TYPE_AHO)
        {
            viCheckErr( viPrintf (io, ":SENS:AHO:RES (@%s)", channelName));
        }
        else if (measurementType == AGN6K7KNI_VAL_MEAS_TYPE_WHO) 
        {
            viCheckErr( viPrintf (io, ":SENS:WHO:RES (@%s)", channelName));  
        }
        else
        {
            viCheckParm(IVI_ERROR_INVALID_PARAMETER, 3, "Measurement Type");
        }
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               

/*******************************************************************************
 * Function:  agn6k7kni_InitiateAcquisition
 * Purpose:   This function initiates a measurement acquisition.  After you
 *            call this function, the APS leaves the Idle state and acquires a
 *            measurements for each channel you specify.
 *
 *            Notes:
 *            (1) This function does not check the instrument status.
 *                Typically, you call this function only in a sequence of calls 
 *                to other low-level driver functions.  The sequence performs 
 *                one operation.  You use the low-level functions to optimize 
 *                one or more aspects of interaction with the instrument.  If 
 *                you want to check the instrument status, call the 
 *                agn6k7kni_error_query function at the conclusion of the 
 *                sequence.
 *
 *            SCPI Command:
 *            INITiate[:IMMediate]:ACQuire
*******************************************************************************/
ViStatus _VI_FUNC agn6k7kni_InitiateAcquisition (
    ViSession vi, 
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":INIT:ACQ (@%s)", channelName));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                               

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;   
}

/*******************************************************************************
 * Function:  agn6k7kni_AbortAcquisition
 * Purpose:   This function cancels any triggered measurements. It also resets 
 *            the WTG-tran and TRAN-active bits in the Operation Status 
 *            registers. 
 *            
 *            SCPI Command:
 *            ABORt:ACQuire
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_AbortAcquisition (
    ViSession vi,
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":ABOR:ACQ (@%s)", channelName));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_SendAcquisitionTrigger
 * Purpose:   This function triggers the acquisition system.
 *            
 *            SCPI Command:
 *            TRIGger:ACQuire[:IMMediate]
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_SendAcquisitionTrigger (  
    ViSession vi,
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":TRIG:ACQ (@%s)", channelName));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_QueryAcquisitionWtgState
 * Purpose:   This function queries whether the measurement system is waiting
 *            for a trigger.
*******************************************************************************/
ViStatus _VI_FUNC agn6k7kni_QueryAcquisitionWtgState (       
    ViSession vi,
    ViConstString channelName,
    ViBoolean *wtgStatus)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     value = 0;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viQueryf (io, ":STAT:OPER:COND? (@%s)", "%ld", channelName, &value));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    *wtgStatus = (value & (1 << 3)) != 0;
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_SendDatalogTrigger
 * Purpose:   This function triggers the external datalog system.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only.
 *
 *            SCPI Command:
 *            TRIGger:ELOG[:IMMediate]
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_SendDatalogTrigger (  
    ViSession vi,
    ViConstString channelName)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":TRIG:ELOG (@%s)", channelName));  
    }  

    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */                                    

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_FetchDatalog
 * Purpose:   This function fetches the most recent external datalog records.
 *
 *            Notes:
 *            (1) This function supports N79XX models only.
 *
 *            SCPI Command:
 *            FETCh:ELOG? <maxrecords>
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_FetchDatalog (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 maximumTime, 
    ViInt32 maximumRecords, 
    ViReal64 measurementArray[], 
    ViInt32 *actualRecords)
{
    ViStatus    error = VI_SUCCESS;
    ViString    pData = NULL;  
    ViSession   io = VI_NULL;
    ViInt32     oldTimeout = 0;
    ViBoolean   needToRestoreTimeout = VI_FALSE;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");
    
    if (maximumRecords < 1 || maximumRecords > 16384)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 4, "Maximum Records out of range."); 
    }
        
    if (measurementArray == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 5, "Null value for Measurement Array.");
    }
    
    if (actualRecords == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 6, "Null value for Actual Records."); 
    }
    
    if (!Ivi_Simulating(vi))
    {
        io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        
        viCheckErr( viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));      
        viCheckErr( viSetAttribute (io, VI_ATTR_TMO_VALUE, maximumTime));
        needToRestoreTimeout = VI_TRUE;
    
        viCheckErr( viPrintf (io, ":FETC:ELOG? %ld, (@%s)", maximumRecords, channelName));
        checkErr( agn6k7kni_ReadUnknownLengthData( vi, io, &pData, NULL));
        viCheckErr( agn6k7kni_GetViReal64ArrayFromBuffer(measurementArray, maximumRecords, pData, 
                    actualRecords));
    }
   
    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */   

Error:
    if (needToRestoreTimeout)
    {
        viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout);  
    }
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               

/*******************************************************************************
 * Function:  agn6k7kni_Fetch
 * Purpose:   This function fetches measured value.
 *            
 *            SCPI Command:
 *            FETCh[:SCALar]:CURRent[:DC]?
 *            FETCh[:SCALar]:CURRent:ACDC?
 *            FETCh[:SCALar]:CURRent:HIGH?
 *            FETCh[:SCALar]:CURRent:LOW?
 *            FETCh[:SCALar]:CURRent:MAXimum?
 *            FETCh[:SCALar]:CURRent:MINimum?
 *            FETCh[:SCALar]:VOLTage[:DC]?
 *            FETCh[:SCALar]:VOLTage:ACDC?
 *            FETCh[:SCALar]:VOLTage:HIGH?
 *            FETCh[:SCALar]:VOLTage:LOW?
 *            FETCh[:SCALar]:VOLTage:MAXimum?
 *            FETCh[:SCALar]:VOLTage:MINimum?
 *            FETCh[:SCALar]:POWer[:DC]?
 *            FETCh:AHOur?
 *            FETCh:WHOur? 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_Fetch (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 maximumTime, 
    ViInt32 measurementType, 
    ViReal64 *measurement)
{
    ViStatus    error = VI_SUCCESS;
    ViSession   io = VI_NULL;
    ViString    commandValue = VI_NULL;
    ViInt32     oldTimeout = 0;
    ViBoolean   needToRestoreTimeout = VI_FALSE;
    IviRangeTablePtr    table = VI_NULL; 

    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (measurement == VI_NULL)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 5, "Null value for measurement.");
    }
    
    viCheckParm (Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");
    
    checkErr( Ivi_GetAttrRangeTable (vi, channelName, AGN6K7KNI_ATTR_MEASUREMENT_TYPE, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(measurementType, table, &commandValue));
    
    if (!Ivi_Simulating(vi))
    {
        io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        
        viCheckErr( viGetAttribute (io, VI_ATTR_TMO_VALUE, &oldTimeout));      
        viCheckErr( viSetAttribute (io, VI_ATTR_TMO_VALUE, maximumTime));
        needToRestoreTimeout = VI_TRUE;
    
        viCheckErr( viQueryf (io, ":FETC:%s? (@%s)", "%Le", commandValue, 
                              VALID_CHANNELNAME (channelName), measurement));       
    }
   
    /*
        Do not invoke the agn6k7kni_CheckStatus function here.  It is invoked 
        by the high-level driver functions when this function is used internally.  
        After the user calls this function, the user can check for errors by 
        calling the agn6k7kni_error_query function.
    */   

Error:
    if (needToRestoreTimeout)
    {
        viSetAttribute (io, VI_ATTR_TMO_VALUE, oldTimeout);  
    }
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureWindowing
 * Purpose:   This function configures the measurement windowing of the APS.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureWindowing (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 windowType)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_MEASUREMENT_WINDOW,
                                          0, windowType), 3, "Window Type");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureSampling
 * Purpose:   This function configures the measurement sampling settings of the 
 *            APS. 
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureSampling (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 points, 
    ViReal64 timeInterval, 
    ViInt32 offset)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_SWEEP_POINT,
                                          0, points), 3, "Points");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL,
                                           0, timeInterval), 4, "Time Interval");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT,
                                          0, offset), 5, "Offset");
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_ConfigureNPLC
 * Purpose:   This function configures the measurement period expressed in
 *            number of power line cycles of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureNPLC (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 NPLC)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name"); 
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_MEASUREMENT_TIME,
                                           0, NPLC), 3, "NPLC");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_Measure
 * Purpose:   This function takes a measurement on the output signal and returns 
 *            the measured value. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_Measure (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 measurementType, 
    ViReal64 *measurement)
{
    ViStatus    error = VI_SUCCESS;
    ViSession   io = VI_NULL;
    ViString    commandValue = VI_NULL;
    IviRangeTablePtr    table = VI_NULL; 

    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (measurement == VI_NULL)
    {
        viCheckParm (IVI_ERROR_INVALID_PARAMETER, 4, "Null value for measurement.");
    }
    
    checkErr( Ivi_CoerceChannelName (vi, channelName, &channelName) );
    
    checkErr( Ivi_GetAttrRangeTable (vi, channelName, AGN6K7KNI_ATTR_MEASUREMENT_TYPE, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(measurementType, table, &commandValue));
    
    if (!Ivi_Simulating(vi))
    {
        io = Ivi_IOSession(vi);
        
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viQueryf (io, ":MEAS:%s? (@%s)", "%lf", commandValue, channelName, measurement));       
    }
   
    checkErr( agn6k7kni_CheckStatus(vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr List Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureTriggerOutList
 * Purpose:   This function configures which list steps generate a trigger 
 *            signal at the beginning of step (BOSTep) or end of step (EOSTep). 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureTriggerOutList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 listSize, 
    ViBoolean BOSTList[], 
    ViBoolean EOSTList[])
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     i = 0;
    ViPBuf      pStart = VI_NULL,
                pEnd = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
                                  
    if (Ivi_RangeChecking(vi))
    {
        if (listSize < 1 || listSize > 512)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 3, "List Size");
        }
    }
        
    viCheckErr( Ivi_Alloc( vi, 2*MAX_HEADER_COMMAND_LENGTH+listSize*(MAX_BOOLEAN_FORMAT_LENGTH+1),
                (ViAddr*)&pStart));
    
    pEnd = pStart + sprintf(pStart, "%s ", ":LIST:TOUT:BOST");
    for (i = 0; i < listSize; ++i)
    {
        pEnd += sprintf(pEnd, "%s,", BOSTList[i] ? "ON" : "OFF");
    }
    pEnd += sprintf(pEnd, "(@%s);%s ", channelName, ":LIST:TOUT:EOST");
    for (i = 0; i < listSize; ++i)
    {
        pEnd += sprintf(pEnd, "%s,", EOSTList[i] ? "ON" : "OFF");
    }
    pEnd += sprintf(pEnd, "(@%s)", channelName);
    
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus(vi, VI_TRUE));
        
        viCheckErr( viPrintf (io, pStart));
    }
    
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    if (pStart)
    {
        Ivi_Free (vi, pStart);
    }
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureLevelList
 * Purpose:   This function configures the voltage or current setting for each 
 *            list step in volts.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only.
 *            (2) This function only apply in the presently active priority 
 *                mode. Use agn6k7kni_ConfigureOutputPriorityMode function to 
 *                configure the active priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureLevelList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 listSize, 
    ViReal64 levelList[])
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     priorityMode = 0;
    ViInt32     i = 0;
    ViPBuf      pStart = VI_NULL,
                pEnd = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_FUNCTION, 0, &priorityMode));
    
    if (Ivi_RangeChecking(vi))
    {
        ViReal64 upper = 0.0,
                 lower = 0.0;
        
        if (listSize < 1 || listSize > 512)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 3, "List Size");
        }
        
        if (priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE)
        {
            checkErr( Ivi_GetAttrMinMaxViReal64(vi, VI_NULL, AGN6K7KNI_ATTR_VOLTAGE_LEVEL, 
                      &lower, &upper, VI_NULL, VI_NULL)); 
        }
        else
        {
            checkErr( Ivi_GetAttrMinMaxViReal64(vi, VI_NULL, AGN6K7KNI_ATTR_CURRENT_LEVEL, 
                      &lower, &upper, VI_NULL, VI_NULL));   
        }
        
        for (i = 0; i < listSize; ++i)
        {
            if (levelList[i] < lower || levelList[i] > upper)
            {
                viCheckParm( IVI_ERROR_INVALID_VALUE, 4, "Level");
            }
        }   
    }
        
    viCheckErr( Ivi_Alloc( vi, MAX_HEADER_COMMAND_LENGTH+listSize*(MAX_DOUBLE_FORMAT_LENGTH+1),
                (ViAddr*)&pStart));
    
    pEnd = pStart + sprintf(pStart, "%s ", priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE ?  
                            ":LIST:VOLT" : ":LIST:CURR");
    
    for (i = 0; i < listSize; ++i)
    {
        pEnd += sprintf(pEnd, "%le,", levelList[i]);
    }
    pEnd += sprintf(pEnd, "(@%s)", channelName);
    
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus(vi, VI_TRUE));
        
        viCheckErr( viPrintf (io, pStart));
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    if (pStart)
    {
        Ivi_Free (vi, pStart);
    }
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureDwellList
 * Purpose:   This function configures the dwell time for each list step.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureDwellList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 listSize, 
    ViReal64 dwellList[])
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     i = 0;
    ViPBuf      pStart = VI_NULL,
                pEnd = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    
    if (Ivi_RangeChecking(vi))
    {
        if (listSize < 1 || listSize > 512)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 3, "List Size");
        }
        
        for (i = 0; i < listSize; ++i)
        {
            if (dwellList[i] < 0.0 || dwellList[i] > 262.144)
            {
                viCheckParm( IVI_ERROR_INVALID_VALUE, 4, "Dwell");
            }
        }   
    }
        
    viCheckErr( Ivi_Alloc( vi, MAX_HEADER_COMMAND_LENGTH+listSize*(MAX_DOUBLE_FORMAT_LENGTH+1),
                           (ViAddr*)&pStart));
    
    pEnd = pStart + sprintf(pStart, "%s ", ":LIST:DWELL");
    
    for (i = 0; i < listSize; ++i)
    {
        pEnd += sprintf(pEnd, "%le,", dwellList[i]);
    }
    pEnd += sprintf(pEnd, "(@%s)", channelName);
    
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus(vi, VI_TRUE));
        
        viCheckErr( viPrintf (io, pStart));
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    if (pStart)
    {
        Ivi_Free (vi, pStart);
    }
    
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureList
 * Purpose:   This function configures the list transient of the APS.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureList (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 repeatCount, 
    ViInt32 paceType, 
    ViBoolean terminateLastEnabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_LIST_COUNT,
                                          0, repeatCount), 3, "Repeat Count");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_LIST_STEP,
                                          0, paceType), 4, "Pace Type");
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, 
                                            AGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED,
                                            0, terminateLastEnabled), 5, "Terminate Last Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Arbitrary Waveform Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureConstantDwellWaveform
 * Purpose:   This function configures the voltage constant dwell arbitrary 
 *            waveform settings.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only.
 *            (2) This function only apply in the presently active priority 
 *                mode. Use agn6k7kni_ConfigureOutputPriorityMode function to 
 *                configure the active priority mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureConstantDwellWaveform (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 arrSize, 
    ViReal64 levelArr[], 
    ViReal64 constantDwellTime)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     priorityMode = 0,
                i = 0;
    ViPBuf      pStart = VI_NULL,
                pEnd = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_FUNCTION, 0, &priorityMode));
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME,
                                           0, constantDwellTime), 5, "Constant Dwell Time");
    
    if (Ivi_RangeChecking(vi))
    {
        ViReal64 upper = 0.0,
                 lower = 0.0;
        
        if (arrSize < 1 || arrSize > 65535)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 3, "List Size");
        }
        
        if (priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE)
        {
            checkErr( Ivi_GetAttrMinMaxViReal64(vi, VI_NULL, AGN6K7KNI_ATTR_VOLTAGE_LEVEL, 
                      &lower, &upper, VI_NULL, VI_NULL)); 
        }
        else
        {
            checkErr( Ivi_GetAttrMinMaxViReal64(vi, VI_NULL, AGN6K7KNI_ATTR_CURRENT_LEVEL, 
                      &lower, &upper, VI_NULL, VI_NULL));   
        }
        
        for (i = 0; i < arrSize; ++i)
        {
            if (levelArr[i] < lower || levelArr[i] > upper)
            {
                viCheckParm( IVI_ERROR_INVALID_VALUE, 4, "Level");
            }
        }           
    }
    
    viCheckErr( Ivi_Alloc( vi, MAX_HEADER_COMMAND_LENGTH+arrSize*(MAX_DOUBLE_FORMAT_LENGTH+1),
                (ViAddr*)&pStart));
    
    pEnd = pStart + sprintf(pStart, "%s ", priorityMode == AGN6K7KNI_VAL_FUNCTION_VOLTAGE ?  
                            ":ARB:VOLT:CDW" : ":ARB:CURR:CDW");
    
    for (i = 0; i < arrSize; ++i)
    {
        pEnd += sprintf(pEnd, "%le,", levelArr[i]);
    }
    pEnd += sprintf(pEnd, "(@%s)", channelName);
    
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus(vi, VI_TRUE));
        
        viCheckErr( viPrintf (io, pStart));
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureArbWaveform
 * Purpose:   This function configures the arbitrary waveform settings.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only.
 *            (2) This function only apply in the presently active priority 
 *                mode. Use agn6k7kni_ConfigureOutputPriorityMode function to 
 *                configure the active priority mode.
 *            
 *            SCPI Command:
 *            [SOURce:]ARB:FUNCtion:TYPE CURRent|VOLTage 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureArbWaveform (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 repeatCount, 
    ViBoolean terminateLastEnabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_ARB_WFM_COUNT,
                                          0, repeatCount), 3, "Repeat Count");
    viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED,
                                            0, terminateLastEnabled), 4, "Terminate Last Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Sequence Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_QueryMaxOutputDelayOffset
 * Purpose:   This function query the delay offset of the slowest unit. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_QueryMaxOutputDelayOffset (
    ViSession vi, 
    ViReal64 *maxDelayOffset)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (maxDelayOffset == VI_NULL)
    {
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null value for Max Delay Offset.");
    }
    
    if (!Ivi_Simulating (vi))
    {
        ViSession io = Ivi_IOSession(vi);

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viQueryf (io, ":OUTP:COUP:MAX:DOFF?", "%lf", maxDelayOffset));
    }
    else
    {
        *maxDelayOffset = 0.03799;
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*******************************************************************************
 * Function:  agn6k7kni_QueryCalibrationCount
 * Purpose:   This function queries the number of times the unit has been
 *            calibrated.
*******************************************************************************/
ViStatus _VI_FUNC agn6k7kni_QueryCalibrationCount (
    ViSession vi,
    ViInt32 *calibrationCount)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    viCheckParm( Ivi_GetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_CALIBRATION_COUNT,
                                          0, calibrationCount), 2, "Calibration Count");
    
Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}
    
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputSequenceDelay
 * Purpose:   This function sets the output turn-on and turn-off sequence
 *            delay of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputSequenceDelay (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 riseDelay, 
    ViReal64 fallDelay)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE,
                                           0, riseDelay), 3, "Rise Delay");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL,
                                           0, fallDelay), 4, "Fall Delay");
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputSequencing
 * Purpose:   This function configures the output sequencing of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputSequencing (
    ViSession vi, 
    ViBoolean enabled, 
    ViReal64 delayOffset)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED,
                                            0, enabled), 2, "Enabled");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET,
                                           0, delayOffset), 3, "Delay Offset");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Miscellaneous Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureSenseFaultDetection
 * Purpose:   This function configures the remote sense fault detection state. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureSenseFaultDetection (
    ViSession vi, 
    ViBoolean enabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED,
                                            0, enabled), 2, "Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Digital Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureInhibitInputMode
 * Purpose:   This function configures the operating mode of the remote inhibit 
 *            digital pin. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureInhibitInputMode (
    ViSession vi, 
    ViInt32 inhibitMode)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE,
                                          0, inhibitMode), 2, "Inhibit Mode");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureBusTriggerEnabled
 * Purpose:   This function configures the BUS triggers state on digital port 
 *            pins. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureBusTriggerEnabled (
    ViSession vi, 
    ViBoolean enabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, 
                                            AGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED,
                                            0, enabled), 3, "Enabled");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ReadInputData
 * Purpose:   This function reads the state of the digital control port. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ReadInputData (
    ViSession vi, 
    ViInt32 *inputData)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_GetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_DIGITAL_INPUT_DATA,
                                          0, inputData), 2, "Input Data");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_WriteOutputData
 * Purpose:   This function write the state of the digital control port. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_WriteOutputData (
    ViSession vi, 
    ViInt32 outputData)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA,
                                          0, outputData), 2, "Output Data");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigurePin
 * Purpose:   Configures the digital input and output port of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigurePin (
    ViSession vi, 
    ViConstString pinName, 
    ViInt32 pinFunction, 
    ViInt32 pinPolarity)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceRepCapName(vi, pinName, DIGITAL_PIN_REP_CAP_NAME, &pinName), 
                                      2, "Pin Name");  
    viCheckParm( Ivi_SetAttributeViInt32 (vi, pinName, AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION,
                                          0, pinFunction), 3, "Pin Function");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, pinName, AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY,
                                          0, pinPolarity), 4, "Pin Polarity");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Datalog Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureElog
 * Purpose:   This function configures the external data logging (Elog) function 
 *            of the APS.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureElog (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 function, 
    ViBoolean enabled, 
    ViBoolean minMaxEnabled)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    
    if (function == AGN6K7KNI_VAL_ELOG_MEAS_FUNC_VOLTAGE)
    {
        viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED,
                                                0, enabled), 4, "Enabled");
        viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED,
                                                0, minMaxEnabled), 5, "Min Max Enabled");  
    }
    else
    {
        viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED,
                                                0, enabled), 4, "Enabled");
        viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED,
                                                0, minMaxEnabled), 5, "Min Max Enabled");          
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureElogMeasurement
 * Purpose:   This function configures the measurement parameters for external 
 *            datalog function.
 *            
 *            Notes:
 *            (1) This function supports N79XX models only. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureElogMeasurement (
    ViSession vi, 
    ViConstString channelName, 
    ViReal64 integrationTime, 
    ViReal64 range)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_CoerceChannelName (vi, channelName, &channelName), 2, "Channel Name");  
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_ELOG_PERIOD,
                                           0, integrationTime), 3, "Integration Time");
    
    if (range == AGN6K7KNI_VAL_ELOG_CURRENT_RANGE_AUTO)
    {
        viCheckParm( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE_AUTO,
                                                0, VI_TRUE), 4, "Range");          
    }
    else
    {   
        checkErr( Ivi_SetAttributeViBoolean (vi, channelName, AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE_AUTO,
                                             0, VI_FALSE)); 
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE,
                                               0, range), 4, "Range");  
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Calibration Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureCalibrationMode
 * Purpose:   This function configures the calibration mode of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureCalibrationMode (
    ViSession vi, 
    ViInt32 mode, 
    ViReal64 level)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command = VI_NULL;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_GetViInt32EntryFromValue( mode, &calibrationModeRangeTable, VI_NULL, 
                 VI_NULL, VI_NULL, VI_NULL, &command, VI_NULL), 2, "Mode");
    
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        
        switch (mode)
        {
            case AGN6K7KNI_VAL_CAL_MODE_VOLTAGE:  
            case AGN6K7KNI_VAL_CAL_MODE_CURRENT_HIGH_RANGE: 
            case AGN6K7KNI_VAL_CAL_MODE_CURRENT_LOW_RANGE:
                viCheckErr( viPrintf(io, ":CAL:%s %lf", command, level));
                break;
            case AGN6K7KNI_VAL_CAL_MODE_CMRR:   
            case AGN6K7KNI_VAL_CAL_MODE_TC:
            case AGN6K7KNI_VAL_CAL_MODE_CURRENT_SHARING:  
            case AGN6K7KNI_VAL_CAL_MODE_BOTTOM_OUT_RES: 
                viCheckErr( viPrintf(io, ":CAL:%s", command));
                break;
        };
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureCalibration
 * Purpose:   This function selects the calibration level and sets the 
 *            calibration data. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureCalibration (
    ViSession vi, 
    ViInt32 calibrationLevel, 
    ViReal64 calibrationData)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_CALIBRATION_LEVEL,
                                          0, calibrationLevel), 2, "Calibration Level");
    
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL, AGN6K7KNI_ATTR_CALIBRATION_DATA,
                                           0, calibrationData), 3, "Calibration Data");
    
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureCalibrationEnabled
 * Purpose:   This function enables or disables calibration mode. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureCalibrationEnabled (
    ViSession vi, 
    ViBoolean enabled, 
    ViConstString password)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     i = 0,
                len = 0;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (Ivi_RangeChecking(vi))
    {
        if ((len = (ViInt32)(strlen(password))) > 15)
        {
            viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Password length too long.");
        }
        
        for (i = 0; i < len; ++i)
        {
            if (password[i] < '0' || password[i] > '9')
            {
                viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Password contains invalid character.");   
            }
        }
    }

    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE)); 

        viCheckErr( viPrintf (io, ":CAL:STAT %s,%s", enabled ? "ON" : "OFF", password));   
    }
     
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr System Group Functions =============================*
 *===========================================================================*/         
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureOutputCoupleSource
 * Purpose:   This function configures the output on/off couple source. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureOutputCoupleSource (
    ViSession vi, 
    ViInt32 onCoupleSource, 
    ViInt32 offCoupleSource)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE,
                                          0, onCoupleSource), 2, "On Couple Source");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE,
                                          0, offCoupleSource), 3, "Off Couple Source");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureUserProtection
 * Purpose:   This function configures the User-defined protection of the APS. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureUserProtection (
    ViSession vi, 
    ViBoolean enabled, 
    ViInt32 source)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    viCheckParm( Ivi_SetAttributeViBoolean (vi, VI_NULL, AGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED,
                                            0, enabled), 2, "Enabled");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE,
                                          0, source), 3, "Source");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_DefineSignalExpression
 * Purpose:   This function defines signal expressions.
 *            
 *            SCPI Command:
 *            SYSTem:SIGNal:DEFine EXPRession<1-8>, <"expression"> 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_DefineSignalExpression (
    ViSession vi, 
    ViInt32 expressionNumber, 
    ViConstString expression)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    if (Ivi_RangeChecking(vi))
    {
        if (expressionNumber < 1 || expressionNumber > 8)
        {
            viCheckParm( IVI_ERROR_INVALID_VALUE, 2, "Expression Number"); 
        }
    }
    
    if (!Ivi_Simulating(vi))
    {
        ViSession io = Ivi_IOSession(vi);
        checkErr( Ivi_SetNeedToCheckStatus(vi, VI_TRUE));
        
        viCheckErr( viPrintf (io, ":SYST:SIGN:DEF EXPR%ld, \"%s\"", expressionNumber, expression));
    }
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            
                
/*******************************************************************************
 * Function:  agn6k7kni_ConfigureThresholdComparators
 * Purpose:   This function configures the threshold comparators of the APS.
 *            
 *            The APS models have four built-in level comparators that can 
 *            generate an output signal based on the comparison of two input 
 *            signals. 
*******************************************************************************/            
ViStatus _VI_FUNC agn6k7kni_ConfigureThresholdComparators (
    ViSession vi, 
    ViConstString channelName, 
    ViInt32 comparatorNumber, 
    ViInt32 function, 
    ViInt32 operation, 
    ViReal64 level)
{
    ViStatus    error = VI_SUCCESS;
    
    checkErr( Ivi_LockSession (vi, VI_NULL));
    
    
    checkErr( Ivi_CoerceChannelName (vi, channelName, &channelName) ); 
    
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER,
                                          0, comparatorNumber), 3, "Comparator Number");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_FUNCTION,
                                          0, function), 4, "Function");
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_OPERATION,
                                          0, operation), 5, "Operation");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL,
                                           0, level), 6, "Level");                              
                 
    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}               
            

/*===========================================================================*
 *= IviDCPwr Memory Group Functions =============================*
 *===========================================================================*/         
            
/*****************************************************************************
 * Function: agn6k7kni_GetAttribute<type> Functions                                    
 * Purpose:  These functions enable the instrument driver user to get 
 *           attribute values directly.  There are typesafe versions for 
 *           ViInt32, ViReal64, ViString, ViBoolean, and ViSession attributes.                                         
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_GetAttributeViInt32 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViInt32 *value)
{                                                                                                           
    return Ivi_GetAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                    value);
}   

ViStatus _VI_FUNC agn6k7kni_GetAttributeViReal64 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViReal64 *value)
{                                                                                                           
    return Ivi_GetAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                     value);
}   

ViStatus _VI_FUNC agn6k7kni_GetAttributeViString (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViInt32 bufSize, 
    ViChar value[]) 
{   
    return Ivi_GetAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                     bufSize, value);
} 

ViStatus _VI_FUNC agn6k7kni_GetAttributeViBoolean (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViBoolean *value)
{                                                                                                           
    return Ivi_GetAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                      value);
}        

ViStatus _VI_FUNC agn6k7kni_GetAttributeViSession (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViSession *value)
{                                                                                                           
    return Ivi_GetAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                      value);
}                                                                                                           

/*****************************************************************************
 * Function: agn6k7kni_SetAttribute<type> Functions                                    
 * Purpose:  These functions enable the instrument driver user to set 
 *           attribute values directly.  There are typesafe versions for 
 *           ViInt32, ViReal64, ViString, ViBoolean, and ViSession datatypes.                                         
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_SetAttributeViInt32 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViInt32 value)
{                                                                                                           
    return Ivi_SetAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                    value);
}     

ViStatus _VI_FUNC agn6k7kni_SetAttributeViReal64 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViReal64 value)
{                                                                                                           
    return Ivi_SetAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                     value);
}      

ViStatus _VI_FUNC agn6k7kni_SetAttributeViString (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViConstString value) 
{   
    return Ivi_SetAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                     value);
}  

ViStatus _VI_FUNC agn6k7kni_SetAttributeViBoolean (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViBoolean value)
{                                                                                                           
    return Ivi_SetAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                      value);
}    

ViStatus _VI_FUNC agn6k7kni_SetAttributeViSession (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViSession value)
{                                                                                                           
    return Ivi_SetAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                      value);
}                                                                                                           

/*****************************************************************************
 * Function: agn6k7kni_CheckAttribute<type> Functions                                  
 * Purpose:  These functions enable the instrument driver user to check  
 *           attribute values directly.  These functions check the value you
 *           specify even if you set the AGN6K7KNI_ATTR_RANGE_CHECK 
 *           attribute to VI_FALSE.  There are typesafe versions for ViInt32, 
 *           ViReal64, ViString, ViBoolean, and ViSession datatypes.                         
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_CheckAttributeViInt32 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViInt32 value)
{                                                                                                           
    return Ivi_CheckAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                      value);
}

ViStatus _VI_FUNC agn6k7kni_CheckAttributeViReal64 (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViReal64 value)
{                                                                                                           
    return Ivi_CheckAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                       value);
}    

ViStatus _VI_FUNC agn6k7kni_CheckAttributeViString (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViConstString value)  
{   
    return Ivi_CheckAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                       value);
}   

ViStatus _VI_FUNC agn6k7kni_CheckAttributeViBoolean (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViBoolean value)
{                                                                                                           
    return Ivi_CheckAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                        value);
}       

ViStatus _VI_FUNC agn6k7kni_CheckAttributeViSession (
    ViSession vi, 
    ViConstString channelName, 
    ViAttr attributeId, 
    ViSession value)
{                                                                                                           
    return Ivi_CheckAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL, 
                                        value);
}                                                                                                           

/*****************************************************************************
 * Function: WriteInstrData and ReadInstrData Functions                      
 * Purpose:  These functions enable the instrument driver user to  
 *           write and read commands directly to and from the instrument.            
 *                                                                           
 *           Note:  These functions bypass the IVI attribute state caching.  
 *                  WriteInstrData invalidates the cached values for all 
 *                  attributes.
 *****************************************************************************/
ViStatus _VI_FUNC agn6k7kni_WriteInstrData (
    ViSession vi, 
    ViConstString writeBuffer)   
{   
    return Ivi_WriteInstrData (vi, writeBuffer);    
}   

ViStatus _VI_FUNC agn6k7kni_ReadInstrData (
    ViSession vi, 
    ViInt32 numBytes, 
    ViChar rdBuf[], 
    ViInt32 *bytesRead)  
{   
    return Ivi_ReadInstrData (vi, numBytes, rdBuf, bytesRead);   
}           
    
/*****************************************************************************
 *-------------------- Utility Functions (Not Exported) ---------------------*
 *****************************************************************************/
 
/*****************************************************************************
 * Function: agn6k7kni_IviInit                                                       
 * Purpose:  This function is called by agn6k7kni_InitWithOptions  
 *           or by an IVI class driver.  This function initializes the I/O 
 *           interface, optionally resets the device, optionally performs an
 *           ID query, and sends a default setup to the instrument.                
 *****************************************************************************/
static ViStatus agn6k7kni_IviInit (
    ViRsrc resourceName, 
    ViBoolean IDQuery,
    ViBoolean reset, 
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    ViSession   io = VI_NULL;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViInt32     modelType = AGN6K7KNI_MODEL_NOT_FOUND;
    ViInt32     optionFlag = AGN6K7KNI_OPTION_NOT_INSTALLED;
    
    
    checkErr( Ivi_BuildChannelTable (vi, CHANNEL_LIST, VI_FALSE, VI_NULL));
    
    checkErr( Ivi_BuildRepCapTable (vi, DIGITAL_PIN_REP_CAP_NAME, DIGITAL_PIN_LIST));
    

    if (!Ivi_Simulating(vi))
    {
        ViSession   rmSession = VI_NULL;

        /* Open instrument session */
        checkErr( Ivi_GetAttributeViSession (vi, VI_NULL, IVI_ATTR_VISA_RM_SESSION, 0,
                                             &rmSession)); 
        viCheckErr( viOpen (rmSession, resourceName, VI_NULL, VI_NULL, &io));
        /* io session owned by driver now */
        checkErr( Ivi_SetAttributeViSession (vi, VI_NULL, IVI_ATTR_IO_SESSION, 0, io));  

        /* Configure VISA Formatted I/O */
        viCheckErr( viSetAttribute (io, VI_ATTR_TMO_VALUE, 5000 ));
        viCheckErr( viSetBuf (io, VI_READ_BUF | VI_WRITE_BUF, 4000));
        viCheckErr( viSetAttribute (io, VI_ATTR_WR_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS));
        viCheckErr( viSetAttribute (io, VI_ATTR_RD_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS));
        
        /*- Identification Query --------------------------------------------*/
        if (IDQuery)                               
        {
            viCheckErr( viQueryf (io, "*IDN?", "%512[^\n\r]", rdBuffer)); 
            checkErr( agn6k7kni_GetModelFromBuffer( vi, rdBuffer, &modelType));
        
            if (modelType ==  AGN6K7KNI_MODEL_NOT_FOUND)
            {             
                viCheckErr( VI_ERROR_FAIL_ID_QUERY);
            }
        }
        
        viCheckErr( viQueryf(io, "*OPT?", "%512[^\n\r]", rdBuffer));
        checkErr( agn6k7kni_GetOptionsFromBuffer( vi, rdBuffer, &optionFlag));
        
        if (optionFlag == AGN6K7KNI_OPTION_NOT_SUPPORTED)
        {
            checkErr( AGN6K7KNI_ERROR_INVALID_OPTION_TYPE);
        }
    }
    
    /*- Simulation or IDQuery == VI_FALSE -----------------------------------*/
    if( (Ivi_Simulating(vi)) || (!IDQuery) )
    {
        checkErr( agn6k7kni_GetDriverSetupOption (vi, "Model", BUFFER_SIZE, rdBuffer));
    
        if (Ivi_GetValueFromTable (agn6k7kni_ModelTable, rdBuffer, &modelType) < VI_SUCCESS)
        {
            modelType = N6950A;
        }
    }
    
    /* Add attributes */ 
    checkErr( agn6k7kni_InitAttributes (vi, modelType, optionFlag));  
    
    /*- Reset instrument ----------------------------------------------------*/
    if (reset) 
        checkErr( agn6k7kni_reset (vi));
    else  /*- Send Default Instrument Setup ---------------------------------*/
        checkErr( agn6k7kni_DefaultInstrSetup (vi));

    checkErr( agn6k7kni_CheckStatus (vi));

Error:
    if (error < VI_SUCCESS)
    {
        if (!Ivi_Simulating (vi) && io)
            viClose (io);
    }
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_IviClose                                                        
 * Purpose:  This function performs all of the drivers clean-up operations   
 *           except for closing the IVI session.  This function is called by 
 *           agn6k7kni_close or by an IVI class driver. 
 *
 *           Note:  This function must close the I/O session and set 
 *           IVI_ATTR_IO_SESSION to 0.
 *****************************************************************************/
static ViStatus agn6k7kni_IviClose (
    ViSession vi)
{
    ViStatus error = VI_SUCCESS;
    ViSession io = VI_NULL;

        /* Do not lock here.  The caller manages the lock. */

    checkErr( Ivi_GetAttributeViSession (vi, VI_NULL, IVI_ATTR_IO_SESSION, 0, &io));

Error:
    Ivi_SetAttributeViSession (vi, VI_NULL, IVI_ATTR_IO_SESSION, 0, VI_NULL);
    if(io)                                                      
    {
        viClose (io);
    }
    return error;   
}

/*****************************************************************************
 * Function: agn6k7kni_CheckStatus                                                 
 * Purpose:  This function checks the status of the instrument to detect 
 *           whether the instrument has encountered an error.  This function  
 *           is called at the end of most exported driver functions.  If the    
 *           instrument reports an error, this function returns      
 *           IVI_ERROR_INSTRUMENT_SPECIFIC.  The user can set the 
 *           agn6k7kni_ATTR_QUERY_INSTRUMENT_STATUS attribute to VI_FALSE to disable this 
 *           check and increase execution speed.                                   
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus agn6k7kni_CheckStatus (
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;

    if (Ivi_QueryInstrStatus (vi) && Ivi_NeedToCheckStatus (vi) && !Ivi_Simulating (vi))
    {
        checkErr( agn6k7kni_CheckStatusCallback (vi, Ivi_IOSession(vi)));
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_FALSE));
    }
        
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_DefaultInstrSetup                                               
 * Purpose:  This function sends a default setup to the instrument.  The    
 *           agn6k7kni_reset function calls this function.  The 
 *           agn6k7kni_IviInit function calls this function when the
 *           user passes VI_FALSE for the reset parameter.  This function is 
 *           useful for configuring settings that other instrument driver 
 *           functions require.    
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus agn6k7kni_DefaultInstrSetup (
    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
        
    /* Invalidate all attributes */
    checkErr( Ivi_InvalidateAllAttributes (vi));
    
    if (!Ivi_Simulating(vi))
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        
        viCheckErr( viPrintf (io, "*CLS;*ESE 1;*SRE 32"));
    }
Error:
    return error;
}

/*****************************************************************************
 *  Function: agn6k7kni_GetDriverSetupOption
 *  Purpose:  Get the value of a DriverSetup option.  The driver setup string
 *            is part of the option string the user passes to the
 *            agn6k7kni_InitWithOptions function.  Specifically it is the part
 *            that follows "DriverSetup=".  This function assumes the 
 *            DriverSetup string has the following format:
 *              "OptionTag1 : OptionValue1; OptionTag2 : OptionValue2"
 *            Leading and trailing white space is removed from the option
 *            value and both the option tag and option value may contain
 *            white space.  The option tag is case sensitive.
 *
 *            Example:
 *
 *              "DriverSetup= Model : InstrX ; Special Option:Feature Y "
 *
 *              optionTag "Model"          returns optionValue "InstrX"
 *
 *              optionTag "Special Option" returns optionValue "Feature Y"
 *****************************************************************************/
static ViStatus agn6k7kni_GetDriverSetupOption (
    ViSession vi,
    ViConstString optionTag,
    ViInt32 optionValueSize,
    ViChar optionValue[])
{
    ViStatus error = VI_SUCCESS;
    ViChar   setup[BUFFER_SIZE];
    ViChar*  searchOrigin;
    ViChar*  start;
    ViChar*  end;
    ViUInt32 n;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if ((optionValue != VI_NULL) && (optionValueSize > 0))
        optionValue[0] = 0;

    if ((optionTag != VI_NULL) && (optionValue != VI_NULL) && (optionValueSize > 1))
    {
        checkErr( Ivi_GetAttributeViString (vi, "", AGN6K7KNI_ATTR_DRIVER_SETUP,
                                            0, BUFFER_SIZE, setup));
        searchOrigin = setup;
        while (searchOrigin != VI_NULL)
        {
            searchOrigin = strstr(searchOrigin, optionTag);
            if (searchOrigin)
            {
                searchOrigin += strlen(optionTag);
                start = searchOrigin;
                while (isspace(*start)) start++;
                if (*start == ':')
                {
                    start++;
                    while (isspace(*start)) start++;
                    if (*start)
                    {
                        end = strchr (start, ';');
                        if (start != end)
                        {
                            end = (end) ? end-1 : &setup[strlen(setup)-1];
                            while (isspace(*end)) end--;
                            n = (ViInt32)(end - start + 1);
                            if (n > optionValueSize - 1)
                                n = optionValueSize - 1;
                            strncpy(optionValue, start, n);
                            optionValue[n] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
        
Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 *  Function: agn6k7kni_GetStringFromTable
 *  Purpose:  Read the string command from rangetable    
 *****************************************************************************/
static ViStatus agn6k7kni_GetStringFromTable(
    agn6k7kniStringValueTable table,
    ViInt32 value,
    ViConstString *string)
{
    ViStatus    error = VI_SUCCESS;
    ViBoolean   found = VI_FALSE;
    ViInt32     i;
    
    for( i = 0; table[i].string; i++)
    {
        if ( table[i].value == value )
        {
            *string = table[i].string;
            found = VI_TRUE;
            break;
        }
    }
    
    if ( !found )
        error = IVI_ERROR_INVALID_VALUE;

    return error;
}

/*****************************************************************************
 *  Function: agn6k7kni_GetRepCommandFromTable
 *  Purpose:  Read the repeated command from range table to concat with the 
 *            string command.
 *****************************************************************************/
static ViStatus agn6k7kni_GetRepCommandFromTable(
    agn6k7kniStringValueTable table,
    ViInt32 value,
    ViConstString *repCommand)
{
    ViStatus    error = VI_SUCCESS;
    ViBoolean   found = VI_FALSE;
    ViInt32     i;

    for( i = 0; table[i].repCommand; i++)
    {
        if ( table[i].value == value )
        {
            *repCommand = table[i].repCommand;
            found = VI_TRUE;
            break;
        }
    }

    if ( !found )
        error = IVI_ERROR_INVALID_VALUE;

    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_GetModelFromBuffer
 * Purpose:  This function returns model number from buffer. If table 
 *           agn6k7kni_ModelTable does not contains this model, function
 *           returns VI_ERROR_FAIL_ID_QUERY;
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus agn6k7kni_GetModelFromBuffer (
    ViSession vi, 
    ViConstString buffer,
    ViInt32 *modelType)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      tmpBuffer[BUFFER_SIZE];

    sscanf(buffer, "%*[^,],%[^,]", tmpBuffer);
    agn6k7kni_TrimWhiteSpace(tmpBuffer);
    if (Ivi_GetValueFromTable (agn6k7kni_ModelTable, tmpBuffer, modelType) < VI_SUCCESS)
        *modelType = AGN6K7KNI_MODEL_NOT_FOUND;

    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_GetOptionsFromBuffer
 * Purpose:  This function returns installed option flag from buffer. If table 
 *           agn6k7kni_OptionTable does not contains this model, function
 *           returns VI_ERROR_FAIL_OPT_QUERY;
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus agn6k7kni_GetOptionsFromBuffer (
    ViSession vi, 
    ViString buffer,
    ViInt32 *optionFlag)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      tmpBuffer[BUFFER_SIZE] = "";
    ViChar      *pDelim = buffer;
    ViInt32     optionValue = 0;

    if(buffer[0] == '0')
    {
        *optionFlag = AGN6K7KNI_OPTION_NOT_INSTALLED;
    }

    while(pDelim != 0)
    {
        if(pDelim = strchr(buffer, ';'))
        {
            *pDelim = '\0';
        }

        sscanf(buffer, "%*s%s", tmpBuffer);
        if (Ivi_GetValueFromTable (agn6k7kni_OptionTable, tmpBuffer, &optionValue) < VI_SUCCESS)
        {
            *optionFlag = AGN6K7KNI_OPTION_NOT_SUPPORTED;
            break;
        }
        *optionFlag |= optionValue;
        
        if (pDelim != 0)
        {
            buffer = pDelim + 1;
        }
    }

    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_TrimWhiteSpace
 * Purpose:  This function removes surrounding white space around a string
 *****************************************************************************/
static void agn6k7kni_TrimWhiteSpace(
    ViChar s[])
{
    ViChar  *start = s,
            *end;
    size_t lengthWithoutLeadingWS;

    if (start)
        {
        while (*start && isspace((unsigned char)*start))
            start++;

        lengthWithoutLeadingWS = strlen( start);
        memmove( s, start, lengthWithoutLeadingWS);
        end = s + lengthWithoutLeadingWS;
        while (end > s && isspace((unsigned char)*(end-1)))
            end--;
        
        *end = '\0';
        }
}

/*****************************************************************************
 * Function: agn6k7kni_ReadUnknownLengthData
 * Purpose:  This function reads data from the instrument. This functions
 *           reads all data from the instrument independent on the buffer size.
 *
 * WARNING: 1) DON'T USE FOR BINARY TRANSFER (we should improve this function
 *                                            for binary transfers)
 *          2) USE free() function FOR pData pointer in function, which call
 *             this function.
 *****************************************************************************/
static ViStatus agn6k7kni_ReadUnknownLengthData (
    ViSession vi,
    ViSession io,
    ViString *pData,
    ViInt32 *pDataCount)
{
    ViStatus    error = VI_SUCCESS;
    ViChar*     pdata = VI_NULL;
    ViChar*     pend  = VI_NULL;
    ViUInt32    count = 0;

    if (!Ivi_Simulating (vi))
    {
        ViChar      buffer[BUFFER_SIZE];
        ViChar*     pbuffer = VI_NULL;
        ViUInt32    allocated_count = 0;
        ViUInt32    readed_count;

        while ((error = viRead (io, buffer, BUFFER_SIZE, &readed_count)) == VI_SUCCESS_MAX_CNT)
        {
            if (allocated_count)
            {
                if (allocated_count <= count + readed_count)
                {
                    allocated_count += (allocated_count - count) + BUFFER_SIZE;
                    pdata = realloc (pdata, allocated_count);
                }

                pend = pdata + count;
            }
            else
            {
                allocated_count = 2 * BUFFER_SIZE;
                pdata = malloc(allocated_count);
                pend  = pdata;
            }

            memcpy(pend, buffer, readed_count);
            count += readed_count;
        }

        if (readed_count > 0)
        {
            /*
             * Check if the last character is alnum.
             * if this character is not alnum we know that it's '\n'.
             * Remove it.
             *
             * WARNING: NOT SAFE FOR BINARY TRANSFERS
             */
            if (!isalnum(buffer[readed_count-1]))
                readed_count--;
            buffer[readed_count] = '\0';
        }

        /*
         * If function is read more data as BUFFER_SIZE, we must
         * copy last data from static buffer to dynamic buffer
         */
        if (pdata)
        {
            /*
             * For sure, check if the  buffer has enought element.
             * This condition should be FALSE every time.
             */
            if (allocated_count <= count + readed_count)
            {
                allocated_count += (allocated_count - count) + BUFFER_SIZE;
                pdata = realloc (pdata, allocated_count);
            }
            pend = pdata + count;
            memcpy(pend, buffer, readed_count+1);
            pbuffer = pdata;
        }
        else
        {
            count = readed_count;
            pdata = malloc(sizeof(ViChar) * (readed_count+1));
            memcpy( pdata, buffer,  readed_count);
            *(pdata + readed_count) = '\0';
        }

        viCheckErr( error);
    }

Error:
    if ( pDataCount ) *pDataCount = (ViInt32)count;

    if ( error < VI_SUCCESS && pdata)
    {
        free (pdata);
        pdata = NULL;
        if ( pDataCount ) *pDataCount = 0;
    }

    *pData = pdata;
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_GetViReal64ArrayFromBuffer
 * Purpose:  This function convert data which are formated in the string to
 *           double array.
 *
 * WARNING: Data in the string are modified.
 *****************************************************************************/
static ViStatus agn6k7kni_GetViReal64ArrayFromBuffer (
    ViReal64    measurementArray[],
    ViInt32     arraySize,
    ViChar*     pdata,
    ViInt32*    pActualPoints)
{
    ViInt32 i = 0;
    ViChar* ptok;
    ViChar* pend;

    ptok = pend = pdata;
    do
    {
        if ( i >= arraySize )
            break;

        pend = strchr(pend, ',');
        if (pend != NULL)
            *pend++ = '\0';

        measurementArray[i++] = atof( ptok);

        ptok = pend;
    } while ( pend != NULL );

    if (pActualPoints)
        *pActualPoints = i;

    return VI_SUCCESS;

}

/*****************************************************************************
 * Function: agn6k7kni_CreateModelTable
 * Purpose:  This function create the model table.
 *****************************************************************************/
static ViStatus agn6k7kni_CreateModelTable (
    ViSession vi,
    ViInt32 modelType,
    SInstrumentRangesPtr *pInstrumentModel)
{
    ViStatus    error = VI_SUCCESS;
    SInstrumentRangesPtr    instrRanges = VI_NULL;
    
    /* Allocate memory for instrument model table, this memory will be freed
       by Ivi_Dispose function in agn6k7kni_Close funtion. */
    checkErr( Ivi_Alloc( vi, (ViInt32)sizeof(SInstrumentRanges), (ViAddr *)&instrRanges));
    memset (instrRanges, 0, sizeof(SInstrumentRanges));
    
    switch (modelType)
    {
        case N6950A: case N7950A:
            instrRanges->maxVoltage = 9.18; instrRanges->minVoltage = 0.009; 
            instrRanges->maxCurrent = 102.0; instrRanges->minCurrent = -10.2; 
            instrRanges->maxResistance = 0.1; instrRanges->maxOVPLimit = 10.8;
            instrRanges->lowerRange = 10.0;
            break;
        case N6951A: case N7951A:
            instrRanges->maxVoltage = 20.4; instrRanges->minVoltage = 0.02; 
            instrRanges->maxCurrent = 51.0; instrRanges->minCurrent = -5.1; 
            instrRanges->maxResistance = 0.4; instrRanges->maxOVPLimit = 24.0;
            instrRanges->lowerRange = 5.0;
            break;
        case N6952A: case N7952A:
            instrRanges->maxVoltage = 40.8; instrRanges->minVoltage = 0.04; 
            instrRanges->maxCurrent = 25.5; instrRanges->minCurrent = -2.55; 
            instrRanges->maxResistance = 1.6; instrRanges->maxOVPLimit = 48.0; 
            instrRanges->lowerRange = 2.5;
            break;
        case N6953A: case N7953A:
            instrRanges->maxVoltage = 61.2; instrRanges->minVoltage = 0.06; 
            instrRanges->maxCurrent = 17.0; instrRanges->minCurrent = -1.7; 
            instrRanges->maxResistance = 3.4; instrRanges->maxOVPLimit = 72.0;
            instrRanges->lowerRange = 1.67;
            break;
        case N6954A: case N7954A:
            instrRanges->maxVoltage = 81.6; instrRanges->minVoltage = 0.08; 
            instrRanges->maxCurrent = 12.75; instrRanges->minCurrent = -1.275; 
            instrRanges->maxResistance = 6.4; instrRanges->maxOVPLimit = 96.0;
            instrRanges->lowerRange = 1.25;
            break;
        case N6970A: case N7970A:
            instrRanges->maxVoltage = 9.18; instrRanges->minVoltage = 0.009; 
            instrRanges->maxCurrent = 102.0; instrRanges->minCurrent = -10.2; 
            instrRanges->maxResistance = 0.05; instrRanges->maxOVPLimit = 10.8;
            instrRanges->lowerRange = 10.0; 
            break;
        case N6971A: case N7971A:
            instrRanges->maxVoltage = 20.4; instrRanges->minVoltage = 0.02; 
            instrRanges->maxCurrent = 51.0; instrRanges->minCurrent = -5.1; 
            instrRanges->maxResistance = 0.2; instrRanges->maxOVPLimit = 24.0;
            instrRanges->lowerRange = 5.0; 
            break;
        case N6972A: case N7972A:
            instrRanges->maxVoltage = 40.8; instrRanges->minVoltage = 0.04; 
            instrRanges->maxCurrent = 25.5; instrRanges->minCurrent = -2.55; 
            instrRanges->maxResistance = 0.8; instrRanges->maxOVPLimit = 48.0; 
            instrRanges->lowerRange = 2.5;
            break;
        case N6973A: case N7973A:
            instrRanges->maxVoltage = 61.2; instrRanges->minVoltage = 0.06; 
            instrRanges->maxCurrent = 17.0; instrRanges->minCurrent = -1.7; 
            instrRanges->maxResistance = 1.7; instrRanges->maxOVPLimit = 72.0;
            instrRanges->lowerRange = 1.67;
            break;
        case N6974A: case N7974A:
            instrRanges->maxVoltage = 81.6; instrRanges->minVoltage = 0.08; 
            instrRanges->maxCurrent = 12.75; instrRanges->minCurrent = -1.275; 
            instrRanges->maxResistance = 3.2; instrRanges->maxOVPLimit = 96.0;
            instrRanges->lowerRange = 1.25;
            break;
        case N6976A: case N7976A:
            instrRanges->maxVoltage = 122.4; instrRanges->minVoltage = 0.12;
            instrRanges->maxCurrent = 17.0; instrRanges->minCurrent = -1.7;
            instrRanges->maxResistance = 6.8; instrRanges->maxOVPLimit = 144.0;
            instrRanges->lowerRange = 1.67;
            break;
        case N6977A: case N7977A:
            instrRanges->maxVoltage = 163.2; instrRanges->minVoltage = 0.16; 
            instrRanges->maxCurrent = 12.75; instrRanges->minCurrent = -1.275; 
            instrRanges->maxResistance = 12.8; instrRanges->maxOVPLimit = 192.0;
            instrRanges->lowerRange = 1.25;
            break;
    };
    
Error:
    *pInstrumentModel = instrRanges;
    return error;
}
    
/*****************************************************************************
 *------------------------ Global Session Callbacks -------------------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: agn6k7kni_CheckStatusCallback                                               
 * Purpose:  This function queries the instrument to determine if it has 
 *           encountered an error.  If the instrument has encountered an 
 *           error, this function returns the IVI_ERROR_INSTRUMENT_SPECIFIC 
 *           error code.  This function is called by the 
 *           agn6k7kni_CheckStatus utility function.  The 
 *           Ivi_SetAttribute and Ivi_GetAttribute functions invoke this 
 *           function when the optionFlags parameter includes the
 *           IVI_VAL_DIRECT_USER_CALL flag.
 *           
 *           The user can disable calls to this function by setting the 
 *           AGN6K7KNI_QUERY_INSTRUMENT_STATUS attribute to VI_FALSE.  The driver can 
 *           disable the check status callback for a particular attribute by 
 *           setting the IVI_VAL_DONT_CHECK_STATUS flag.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kni_CheckStatusCallback (
    ViSession vi, 
    ViSession io)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     esr = 0;    
    
    /* Query instrument status */
    viCheckErr( viQueryf (io, "*ESR?", "%hd", &esr));
    if (esr & IEEE_488_2_ERROR_MASK)
    {
        viCheckErr( IVI_ERROR_INSTR_SPECIFIC);
    }
            
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_WaitForOPCCallback                                               
 * Purpose:  This function waits until the instrument has finished processing 
 *           all pending operations.  This function is called by the 
 *           agn6k7kni_WaitForOPC utility function.  The IVI engine invokes
 *           this function in the following two cases:
 *           - Before invoking the read callback for attributes for which the 
 *             IVI_VAL_WAIT_FOR_OPC_BEFORE_READS flag is set.
 *           - After invoking the write callback for attributes for which the 
 *             IVI_VAL_WAIT_FOR_OPC_AFTER_WRITES flag is set.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kni_WaitForOPCCallback (
    ViSession vi, 
    ViSession io)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     opcTimeout;
    ViUInt16    statusByte;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, AGN6K7KNI_ATTR_OPC_TIMEOUT, 
                                       0, &opcTimeout));

    viCheckErr( viEnableEvent (io, VI_EVENT_SERVICE_REQ, VI_QUEUE, VI_NULL));

    viCheckErr( viPrintf (io, "*OPC"));

    /* wait for SRQ */ 
    viCheckErr( viWaitOnEvent (io, VI_EVENT_SERVICE_REQ, opcTimeout, VI_NULL, VI_NULL));
    viCheckErr( viDisableEvent (io, VI_EVENT_SERVICE_REQ, VI_QUEUE));

    /* clean up after SRQ */ 
    viCheckErr( viBufWrite (io, "*CLS", 4, VI_NULL));
    viCheckErr( viReadSTB (io, &statusByte));
    
Error:
    viDiscardEvents (io, VI_EVENT_SERVICE_REQ, VI_QUEUE);

    return error;
}   
    
/*****************************************************************************
 *----------------- Attribute Range Tables and Callbacks --------------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: agn6k7kniEnum_WriteCallback                                               
 * Purpose:  This function sets the enum value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniEnum_WriteCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViInt32         value)
{
    ViStatus            error = VI_SUCCESS;
    ViString            command,
                        commandValue;
    ViString            repCommand;                     
    IviRangeTablePtr    table;
    ViInt32             flag = 0;

    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniEnum_commands, attributeId, &command)); 
    viCheckErr (agn6k7kni_GetRepCommandFromTable (agn6k7kniEnum_commands, attributeId, &repCommand));

    checkErr( Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(value, table, &commandValue));
    
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag));
    
    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viPrintf (io, "%s%s %s, (@%s)", command, repCommand, 
                        commandValue, VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, "%s%s%s %s", command, VALID_CHANNELNAME (channelName), 
                        repCommand, commandValue));
        }
    }
    
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniEnum_ReadCallback                                               
 * Purpose:  This function reads the enum value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniEnum_ReadCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViInt32*        value
)
{
    ViStatus            error = VI_SUCCESS;
    ViString            command;
    ViString            repCommand; 
    IviRangeTablePtr    table;
    ViInt32             flag = 0;

    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniEnum_commands, attributeId, &command)); 
    viCheckErr (agn6k7kni_GetRepCommandFromTable (agn6k7kniEnum_commands, attributeId, &repCommand));
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag));

    checkErr( Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));

    if (!Ivi_Simulating (vi))
    {
        ViChar  rdBuffer[BUFFER_SIZE];
        size_t  rdBufferSize = sizeof(rdBuffer);

        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viPrintf (io, "%s%s? (@%s)", command, repCommand, 
                                  VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, "%s%s%s?", command, VALID_CHANNELNAME (channelName), 
                                  repCommand));   
        }
        viCheckErr( viScanf(io, "%#s", &rdBufferSize, rdBuffer));
        viCheckErr( agn6k7kni_GetValueFromCmd(rdBuffer, table, value));
    }
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniViBoolean_WriteCallback                                               
 * Purpose:  This function sets the bool value of the ViBoolean attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniViBoolean_WriteCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViBoolean       value
)
{
    ViStatus        error = VI_SUCCESS;
    ViString        command;
    ViString        repCommand;
    ViInt32         flag = 0; 

    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniViBoolean_commands, attributeId, &command)); 
    viCheckErr( agn6k7kni_GetRepCommandFromTable (agn6k7kniViBoolean_commands, attributeId, 
                                                  &repCommand));
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag)); 
    
    
    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viPrintf (io, "%s%s %s, (@%s)", command, repCommand, 
                        value ? "ON" : "OFF", VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, "%s%s%s %s", command, VALID_CHANNELNAME (channelName), 
                                  repCommand, value ? "ON" : "OFF"));
        }
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniViBoolean_ReadCallback                                               
 * Purpose:  This function reads the bool value of the ViBoolean attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniViBoolean_ReadCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViBoolean*      value)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command;
    ViString    repCommand; 
    ViInt32     flag = 0;  
    
    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniViBoolean_commands, attributeId, &command)); 
    viCheckErr( agn6k7kni_GetRepCommandFromTable (agn6k7kniViBoolean_commands, attributeId, 
                                                  &repCommand));
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag)); 

    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viQueryf (io, "%s%s? (@%s)", "%hd", command, repCommand, 
                        VALID_CHANNELNAME (channelName), value));
        }
        else
        {
            viCheckErr( viQueryf (io, "%s%s%s?", "%hd", command, VALID_CHANNELNAME (channelName), 
                        repCommand, value));            
        }
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniViReal64_WriteCallback                                               
 * Purpose:  This function sets the bool value of the ViReal64 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniViReal64_WriteCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViReal64        value)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command;
    ViString    repCommand;     
    ViInt32     flag = 0;

    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniViReal64_commands, attributeId, &command));
    viCheckErr( agn6k7kni_GetRepCommandFromTable (agn6k7kniViReal64_commands, attributeId, 
                                                  &repCommand));   
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag));
    
    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viPrintf (io, "%s%s %Le, (@%s)", command, repCommand, 
                        value, VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, "%s%s%s %Le", command, VALID_CHANNELNAME (channelName), 
                        repCommand, value));
        }
    }
    
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniViReal64_ReadCallback                                               
 * Purpose:  This function reads the bool value of the ViReal64 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniViReal64_ReadCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViReal64*       value)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command;
    ViString    repCommand;
    ViInt32     flag = 0;
    
    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniViReal64_commands, attributeId, &command)); 
    viCheckErr (agn6k7kni_GetRepCommandFromTable (agn6k7kniViReal64_commands, attributeId, 
                                                  &repCommand));   
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag)); 
    
    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viQueryf (io, "%s%s? (@%s)", "%le", command, repCommand, 
                        VALID_CHANNELNAME (channelName), value));
        }
        else
        {
            viCheckErr( viPrintf (io, "%s%s%s?", "%le", command, VALID_CHANNELNAME (channelName), 
                        repCommand, value));
        }
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniViInt32_WriteCallback                                               
 * Purpose:  This function sets the bool value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniViInt32_WriteCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViInt32         value
)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command;
    ViString    repCommand;
    ViInt32     flag = 0; 

    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniViInt32_commands, attributeId, &command)); 
    viCheckErr (agn6k7kni_GetRepCommandFromTable (agn6k7kniViInt32_commands, attributeId, 
                                                  &repCommand));    
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag));
    
    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viPrintf (io, "%s%s %ld, (@%s)", command, repCommand, 
                        value, VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, "%s%s%s %ld", command, VALID_CHANNELNAME (channelName), 
                        repCommand, value));
        }
    }
    
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kniViInt32_ReadCallback                                               
 * Purpose:  This function reads the bool value of the ViInt32 attribute.
 *****************************************************************************/
static ViStatus _VI_FUNC agn6k7kniViInt32_ReadCallback (
    ViSession       vi,
    ViSession       io,
    ViConstString   channelName,
    ViAttr          attributeId,
    ViInt32*        value)
{
    ViStatus    error = VI_SUCCESS;
    ViString    command;
    ViString    repCommand;
    ViInt32     flag = 0; 
    
    viCheckErr( agn6k7kni_GetStringFromTable (agn6k7kniViInt32_commands, attributeId, &command)); 
    viCheckErr (agn6k7kni_GetRepCommandFromTable (agn6k7kniViInt32_commands, attributeId, 
                                                  &repCommand));
    viCheckErr( Ivi_GetAttributeFlags(vi, attributeId, &flag));  

    if (!Ivi_Simulating (vi))
    {
        if ((flag & IVI_VAL_MULTI_CHANNEL) != 0)
        {
            viCheckErr( viQueryf (io, "%s%s? (@%s)", "%ld", command, repCommand,  
                        VALID_CHANNELNAME (channelName), value)); 
        }
        else
        {
            viCheckErr( viQueryf (io, "%s%s%s?", "%ld", command, VALID_CHANNELNAME (channelName), 
                        repCommand, value)); 
        }
    }
    
Error:
    return error;
}

/*- AGN6K7KNI_ATTR_ID_QUERY_RESPONSE -*/

static ViStatus _VI_FUNC agn6k7kniAttrIdQueryResponse_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViUInt32    retCnt;
    
    viCheckErr( viPrintf (io, "*IDN?"));
    viCheckErr( viRead (io, rdBuffer, BUFFER_SIZE-1, &retCnt));
    rdBuffer[retCnt] = 0;

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));
    
Error:
    return error;
}
    
/*- AGN6K7KNI_ATTR_SPECIFIC_DRIVER_REVISION -*/

static ViStatus _VI_FUNC agn6k7kniAttrDriverRevision_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      driverRevision[256];
    
    
    sprintf (driverRevision, 
             "Driver: agn6k7kni %d.%d, Compiler: %s %3.2f, "
             "Components: IVIEngine %.2f, VISA-Spec %.2f",
             AGN6K7KNI_MAJOR_VERSION, AGN6K7KNI_MINOR_VERSION, 
             IVI_COMPILER_NAME, IVI_COMPILER_VER_NUM, 
             IVI_ENGINE_MAJOR_VERSION + IVI_ENGINE_MINOR_VERSION/1000.0, 
             Ivi_ConvertVISAVer(VI_SPEC_VERSION));

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, driverRevision));    
Error:
    return error;
}


/*- AGN6K7KNI_ATTR_INSTRUMENT_FIRMWARE_REVISION -*/

static ViStatus _VI_FUNC agn6k7kniAttrFirmwareRevision_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      idQ[BUFFER_SIZE], rdBuffer[BUFFER_SIZE];
    
    checkErr( Ivi_GetAttributeViString (vi, "", AGN6K7KNI_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));

    sscanf (idQ, "%*[^,],%*[^,],%*[^,],%256[^\n]", rdBuffer);

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));
    
Error:
    return error;
}

/*- AGN6K7KNI_ATTR_INSTRUMENT_MANUFACTURER -*/

static ViStatus _VI_FUNC agn6k7kniAttrInstrumentManufacturer_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViChar      idQ[BUFFER_SIZE];
    
    checkErr( Ivi_GetAttributeViString (vi, "", AGN6K7KNI_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));
    sscanf (idQ, "%256[^,]", rdBuffer);

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));
    
Error:
    return error;
}

    

/*- AGN6K7KNI_ATTR_INSTRUMENT_MODEL -*/

static ViStatus _VI_FUNC agn6k7kniAttrInstrumentModel_ReadCallback (
    ViSession vi, 
    ViSession io,
    ViConstString channelName, 
    ViAttr attributeId,
    const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViChar      idQ[BUFFER_SIZE];
    
    checkErr( Ivi_GetAttributeViString (vi, "", AGN6K7KNI_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));
    sscanf (idQ, "%*[^,],%256[^,]", rdBuffer);

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));
    
Error:
    return error;
}
        
/* AGN6K7KNI_ATTR_THRESHOLD_LEVEL */        
static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevel_ReadCallback (
    ViSession vi,
    ViSession io, 
    ViConstString channelName,
    ViAttr attributeId, 
    ViReal64 *value)                                                                                                                                                                                                       
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     thresholdFunction = 0;
    
    viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_FUNCTION, 
                0, &thresholdFunction));

    switch (thresholdFunction)
    {
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR:
            checkErr( Ivi_GetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_AHOUR, 
                      VI_NULL, value));  
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT:
            checkErr( Ivi_GetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_CURRENT, 
                      VI_NULL, value));  
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER:
            checkErr( Ivi_GetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_POWER, 
                      VI_NULL, value));
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE:
            checkErr( Ivi_GetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_VOLTAGE, 
                      VI_NULL, value));
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR:
            checkErr( Ivi_GetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_WHOUR, 
                      VI_NULL, value)); 
            break;
    }
    
Error:
    return error;
}                                                               
        
static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevel_WriteCallback (ViSession vi,
                                                                  ViSession io, 
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)                                                                                                                                                                                                      
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     thresholdFunction = 0;
    
    viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_FUNCTION, 
                0, &thresholdFunction));
    
    switch (thresholdFunction)
    {
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR:
            checkErr( Ivi_SetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_AHOUR, 
                      VI_NULL, value));  
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT:
            checkErr( Ivi_SetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_CURRENT, 
                      VI_NULL, value));  
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER:
            checkErr( Ivi_SetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_POWER, 
                      VI_NULL, value));
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE:
            checkErr( Ivi_SetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_VOLTAGE, 
                      VI_NULL, value));
            break;
        case AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR:
            checkErr( Ivi_SetAttributeViReal64(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_WHOUR, 
                      VI_NULL, value)); 
            break;
    }

Error:
    return error;
}                                                               
        
/* AGN6K7KNI_ATTR_LIST_COUNT */
    
static ViStatus _VI_FUNC agn6k7kniAttrListCount_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value)
{
    ViStatus    error = VI_SUCCESS;
    ViReal64    retValue = 0.0;

    if (!Ivi_Simulating (vi))
    {
        viCheckErr( viQueryf (io, ":LIST:COUN? (@%s)", "%lf", VALID_CHANNELNAME (channelName), 
                    &retValue)); 
        
        if (retValue >= 9.9e37)
        {
            *value = AGN6K7KNI_VAL_LIST_COUNT_INFINITY;
        }
        else
        {
            *value = (ViInt32) retValue;
        }
    }
    else
    {
        *value = 0; 
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrListCount_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        if (value == AGN6K7KNI_VAL_LIST_COUNT_INFINITY)
        {
            viCheckErr( viPrintf (io, ":LIST:COUN INF, (@%s)", VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, ":LIST:COUN %ld, (@%s)", value, VALID_CHANNELNAME (channelName)));
        }
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrListCount_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    
    if ( value != AGN6K7KNI_VAL_LIST_COUNT_INFINITY)
    {
        checkErr( Ivi_DefaultCheckCallbackViInt32(vi, channelName, attributeId, value));
    }

Error:
    return error;
}

/* AGN6K7KNI_ATTR_ARB_WFM_COUNT */ 

static ViStatus _VI_FUNC agn6k7kniAttrArbWfmCount_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value)
{
    ViStatus    error = VI_SUCCESS;
    ViReal64    retValue = 0.0;

    if (!Ivi_Simulating (vi))
    {
        viCheckErr( viQueryf (io, ":ARB:COUN? (@%s)", "%lf", VALID_CHANNELNAME (channelName), 
                    &retValue)); 
        
        if (retValue >= 9.9e37)
        {
            *value = AGN6K7KNI_VAL_ARB_COUNT_INFINITY;
        }
        else
        {
            *value = (ViInt32) retValue;
        }
    }
    else
    {
        *value = 0; 
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrArbWfmCount_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        if (value == AGN6K7KNI_VAL_ARB_COUNT_INFINITY)
        {
            viCheckErr( viPrintf (io, ":ARB:COUN INF, (@%s)", VALID_CHANNELNAME (channelName)));
        }
        else
        {
            viCheckErr( viPrintf (io, ":ARB:COUN %ld, (@%s)", value, VALID_CHANNELNAME (channelName)));
        }
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrArbWfmCount_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    
    if ( value != AGN6K7KNI_VAL_ARB_COUNT_INFINITY)
    {
        checkErr( Ivi_DefaultCheckCallbackViInt32(vi, channelName, attributeId, value));
    }

Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_FUNCTION */ 

static ViStatus _VI_FUNC agn6k7kniAttrThresholdFunction_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value)
{
    ViStatus            error = VI_SUCCESS;
    IviRangeTablePtr    table = VI_NULL;

    checkErr( Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));

    if (!Ivi_Simulating (vi))
    {
        ViChar  rdBuffer[BUFFER_SIZE];
        size_t  rdBufferSize = sizeof(rdBuffer);
        ViInt32 comparatorNumber = 0; 
        
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:FUNC? (@%s)", comparatorNumber, VALID_CHANNELNAME (channelName))); 
        viCheckErr( viScanf(io, "%#s", &rdBufferSize, rdBuffer));
        viCheckErr( agn6k7kni_GetValueFromCmd(rdBuffer, table, value));
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdFunction_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value)
{
    ViStatus            error = VI_SUCCESS;
    ViString            commandValue = VI_NULL;
    IviRangeTablePtr    table = VI_NULL;
    
    checkErr( Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(value, table, &commandValue));

    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:FUNC %s, (@%s)", comparatorNumber, commandValue, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_OPERATION */  

static ViStatus _VI_FUNC agn6k7kniAttrThresholdOperation_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value)
{
    ViStatus            error = VI_SUCCESS;
    IviRangeTablePtr    table;

    checkErr( Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));

    if (!Ivi_Simulating (vi))
    {
        ViChar  rdBuffer[BUFFER_SIZE];
        size_t  rdBufferSize = sizeof(rdBuffer);
        ViInt32 comparatorNumber = 0;
        
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));

        viCheckErr( viPrintf (io, ":SENS:THR%ld:OPER? (@%s)", comparatorNumber, 
                              VALID_CHANNELNAME (channelName)));
        
        viCheckErr( viScanf(io, "%#s", &rdBufferSize, rdBuffer));
        viCheckErr( agn6k7kni_GetValueFromCmd(rdBuffer, table, value));
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdOperation_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value)
{
    ViStatus            error = VI_SUCCESS;
    ViString            commandValue;
    IviRangeTablePtr    table;

    checkErr( Ivi_GetAttrRangeTable (vi, channelName, attributeId, &table));
    viCheckErr( agn6k7kni_GetCmdFromIntValue(value, table, &commandValue));
    
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:OPER %s, (@%s)", comparatorNumber, commandValue, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_LEVEL_AHOUR */ 

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelAhour_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
          
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));

        viCheckErr( viQueryf (io, ":SENS:THR%ld:AHOUR? (@%s)", "%lf", comparatorNumber, 
                    VALID_CHANNELNAME (channelName), value));
    }
    else
    {
        *value = 0.0;
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelAhour_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value)
{
    ViStatus            error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:AHOUR %lf, (@%s)", comparatorNumber, value, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_LEVEL_CURRENT */

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelCurrent_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
          
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));

        viCheckErr( viQueryf (io, ":SENS:THR%ld:CURR? (@%s)", "%lf", comparatorNumber, 
                    VALID_CHANNELNAME (channelName), value));
    }
    else
    {
        *value = 0.0;
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelCurrent_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value)
{
    ViStatus            error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:CURR %lf, (@%s)", comparatorNumber, value, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_LEVEL_POWER */ 

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelPower_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
          
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));

        viCheckErr( viQueryf (io, ":SENS:THR%ld:POW? (@%s)", "%lf", comparatorNumber, 
                    VALID_CHANNELNAME (channelName), value));
    }
    else
    {
        *value = 0.0;
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelPower_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value)
{
    ViStatus            error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:POW %lf, (@%s)", comparatorNumber, value, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_LEVEL_VOLTAGE */ 

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelVoltage_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
          
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));

        viCheckErr( viQueryf (io, ":SENS:THR%ld:VOLT? (@%s)", "%lf", comparatorNumber, 
                    VALID_CHANNELNAME (channelName), value));
    }
    else
    {
        *value = 0.0;
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelVoltage_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value)
{
    ViStatus            error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:VOLT %lf, (@%s)", comparatorNumber, value, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/* AGN6K7KNI_ATTR_THRESHOLD_LEVEL_WHOUR */ 

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelWhour_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
          
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));

        viCheckErr( viQueryf (io, ":SENS:THR%ld:WHOUR? (@%s)", "%lf", comparatorNumber, 
                    VALID_CHANNELNAME (channelName), value));
    }
    else
    {
        *value = 0.0;
    }
    
Error:
    return error;
}

static ViStatus _VI_FUNC agn6k7kniAttrThresholdLevelWhour_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value)
{
    ViStatus            error = VI_SUCCESS;
    
    if (!Ivi_Simulating (vi))
    {
        ViInt32 comparatorNumber = 0; 
        viCheckErr( Ivi_GetAttributeViInt32(vi, channelName, AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER, 
                    0, &comparatorNumber));
        
        viCheckErr( viPrintf (io, ":SENS:THR%ld:WHOUR %lf, (@%s)", comparatorNumber, value, 
                    VALID_CHANNELNAME (channelName)));
    }
    
Error:
    return error;
}

/*****************************************************************************
 * Function: agn6k7kni_InitAttributes                                                  
 * Purpose:  This function adds attributes to the IVI session, initializes   
 *           instrument attributes, and sets attribute invalidation          
 *           dependencies.                                                   
 *****************************************************************************/
static ViStatus agn6k7kni_InitAttributes (
    ViSession vi, 
    ViInt32 modelType, 
    ViInt32 optionFlag)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     flags = 0;
    IviRangeTablePtr    voltageLevelRangeTablePtr = VI_NULL,
                        currentLevelRangeTablePtr = VI_NULL,
                        currentLimitPositiveRangeTablePtr = VI_NULL,
                        currentLimitNegativeRangeTablePtr = VI_NULL,
                        outputResistanceRangeTablePtr = VI_NULL,
                        ovpLimitRangeTablePtr = VI_NULL,
                        outputRangeRangeTablePtr = VI_NULL;
    SInstrumentRangesPtr    pInstrumentModel = VI_NULL; 
    
    checkErr( agn6k7kni_CreateModelTable(vi, modelType, &pInstrumentModel));
    
    if (IS_DISSIPATOR_INSTALLED(optionFlag))
    {
        pInstrumentModel->minCurrent *= 10.0;
    }
    
    viCheckErr( Ivi_RangeTableNew(vi, 2, IVI_VAL_RANGED, VI_TRUE, VI_TRUE, &voltageLevelRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (voltageLevelRangeTablePtr, 0, pInstrumentModel->minVoltage, 
                pInstrumentModel->maxVoltage, 0.0, "", 0));
    
    viCheckErr( Ivi_RangeTableNew(vi, 2, IVI_VAL_RANGED, VI_TRUE, VI_TRUE, &currentLevelRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (currentLevelRangeTablePtr, 0, pInstrumentModel->minCurrent, 
                pInstrumentModel->maxCurrent, 0.0, "", 0));
    
    viCheckErr( Ivi_RangeTableNew(vi, 2, IVI_VAL_RANGED, VI_TRUE, VI_TRUE, &currentLimitPositiveRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (currentLimitPositiveRangeTablePtr, 0, 0.0, pInstrumentModel->maxCurrent, 
                0.0, "", 0));
    
    viCheckErr( Ivi_RangeTableNew(vi, 2, IVI_VAL_RANGED, VI_TRUE, VI_TRUE, &currentLimitNegativeRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (currentLimitNegativeRangeTablePtr, 0, pInstrumentModel->minCurrent, 0.0, 
                0.0, "", 0));
    
    viCheckErr( Ivi_RangeTableNew(vi, 2, IVI_VAL_RANGED, VI_TRUE, VI_TRUE, &outputResistanceRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (outputResistanceRangeTablePtr, 0, 0.0, pInstrumentModel->maxResistance, 
                0.0, "", 0));
    
    viCheckErr( Ivi_RangeTableNew(vi, 2, IVI_VAL_RANGED, VI_TRUE, VI_TRUE, &ovpLimitRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (ovpLimitRangeTablePtr, 0, 0.0, pInstrumentModel->maxOVPLimit, 0.0, "", 0));
    
    viCheckErr( Ivi_RangeTableNew(vi, 3, IVI_VAL_COERCED, VI_FALSE, VI_TRUE, &outputRangeRangeTablePtr));
    viCheckErr( Ivi_SetRangeTableEntry (outputRangeRangeTablePtr, 0, pInstrumentModel->minCurrent, 
                pInstrumentModel->lowerRange, pInstrumentModel->lowerRange, "", 0));
    viCheckErr( Ivi_SetRangeTableEntry (outputRangeRangeTablePtr, 1, pInstrumentModel->lowerRange, 
                pInstrumentModel->maxCurrent, pInstrumentModel->maxCurrent, "", 0));

    checkErr( Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION,
                                       0, AGN6K7KNI_MAJOR_VERSION));
    checkErr( Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_SPECIFIC_DRIVER_MINOR_VERSION,
                                       0, AGN6K7KNI_MINOR_VERSION));
    checkErr( Ivi_SetAttributeViString (vi, "", AGN6K7KNI_ATTR_IO_SESSION_TYPE,
                                        0, AGN6K7KNI_IO_SESSION_TYPE));

    checkErr( Ivi_SetAttrReadCallbackViString (vi, AGN6K7KNI_ATTR_SPECIFIC_DRIVER_REVISION,
                                               agn6k7kniAttrDriverRevision_ReadCallback));
    checkErr( Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION,
                                       0, AGN6K7KNI_CLASS_SPEC_MAJOR_VERSION));
    checkErr( Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION,
                                       0, AGN6K7KNI_CLASS_SPEC_MINOR_VERSION));
    checkErr( Ivi_SetAttributeViString (vi, "", AGN6K7KNI_ATTR_SUPPORTED_INSTRUMENT_MODELS,
                                        0, AGN6K7KNI_SUPPORTED_INSTRUMENT_MODELS));


    checkErr( Ivi_GetAttributeFlags (vi, AGN6K7KNI_ATTR_INSTRUMENT_FIRMWARE_REVISION, &flags));
    checkErr( Ivi_SetAttributeFlags (vi, AGN6K7KNI_ATTR_INSTRUMENT_FIRMWARE_REVISION, 
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr( Ivi_SetAttrReadCallbackViString (vi, AGN6K7KNI_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                               agn6k7kniAttrFirmwareRevision_ReadCallback));

    checkErr( Ivi_GetAttributeFlags (vi, AGN6K7KNI_ATTR_INSTRUMENT_MANUFACTURER, &flags));
    checkErr( Ivi_SetAttributeFlags (vi, AGN6K7KNI_ATTR_INSTRUMENT_MANUFACTURER, 
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr( Ivi_SetAttrReadCallbackViString (vi, AGN6K7KNI_ATTR_INSTRUMENT_MANUFACTURER,
                                               agn6k7kniAttrInstrumentManufacturer_ReadCallback));
    
    checkErr( Ivi_GetAttributeFlags (vi, AGN6K7KNI_ATTR_INSTRUMENT_MODEL, &flags));
    checkErr( Ivi_SetAttributeFlags (vi, AGN6K7KNI_ATTR_INSTRUMENT_MODEL, 
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr( Ivi_SetAttrReadCallbackViString (vi, AGN6K7KNI_ATTR_INSTRUMENT_MODEL,
                                               agn6k7kniAttrInstrumentModel_ReadCallback));

    checkErr( Ivi_SetAttributeViString (vi, "", AGN6K7KNI_ATTR_SPECIFIC_DRIVER_VENDOR,
                                        0, AGN6K7KNI_DRIVER_VENDOR));
    checkErr( Ivi_SetAttributeViString (vi, "", AGN6K7KNI_ATTR_SPECIFIC_DRIVER_DESCRIPTION,
                                        0, AGN6K7KNI_DRIVER_DESCRIPTION));
    checkErr( Ivi_SetAttributeViAddr (vi, VI_NULL, IVI_ATTR_OPC_CALLBACK, 0,
                                      agn6k7kni_WaitForOPCCallback));
    checkErr( Ivi_SetAttributeViAddr (vi, VI_NULL, IVI_ATTR_CHECK_STATUS_CALLBACK, 0,
                                      agn6k7kni_CheckStatusCallback));
        
    checkErr( Ivi_SetAttributeViString (vi, "", AGN6K7KNI_ATTR_GROUP_CAPABILITIES, 0,
                                        "IviDCPwrBase,"
                                        "IviDCPwrTrigger,"
                                        "IviDCPwrSoftwareTrigger,"
                                        "IviDCPwrMeasurement"));

    /*- Add instrument specific attributes ----------------------------------*/
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED,
                                         "AGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED",
                                         VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED,
                                         "AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED",
                                         VI_TRUE, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED,
                                         "AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED",
                                         VI_TRUE, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_WATCHDOG_DELAY,
                                       "AGN6K7KNI_ATTR_WATCHDOG_DELAY", 60, 0,
                                       agn6k7kniViInt32_ReadCallback,
                                       agn6k7kniViInt32_WriteCallback,
                                       &attrWatchdogDelayRangeTable));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED,
                                         "AGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED",
                                         VI_FALSE, 0,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_OCP_DELAY_START_TIME,
                                       "AGN6K7KNI_ATTR_OCP_DELAY_START_TIME",
                                       AGN6K7KNI_VAL_OCP_DELAY_START_SCHANGE,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrOcpDelayStartTimeRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_OCP_DELAY,
                                        "AGN6K7KNI_ATTR_OCP_DELAY", 0.02,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrOcpDelayRangeTable, 0));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_OCP_ENABLED,
                                         "AGN6K7KNI_ATTR_OCP_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_RESISTANCE_LEVEL,
                                        "AGN6K7KNI_ATTR_RESISTANCE_LEVEL", 0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        outputResistanceRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_RESISTANCE_ENABLED,
                                         "AGN6K7KNI_ATTR_RESISTANCE_ENABLED",
                                         VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH,
                                       "AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH",
                                       AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_HIGH,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrVoltageBandwidthRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE,
                                        "AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE", 9.9E+37,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrSlewRateRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_CURRENT_SLEW_RATE,
                                        "AGN6K7KNI_ATTR_CURRENT_SLEW_RATE", 9.9E+37,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrSlewRateRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_CURRENT_LEVEL,
                                        "AGN6K7KNI_ATTR_CURRENT_LEVEL",
                                        pInstrumentModel->maxCurrent/100.0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        currentLevelRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE,
                                        "AGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE",
                                        pInstrumentModel->minCurrent,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        currentLimitNegativeRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_VOLTAGE_LIMIT,
                                        "AGN6K7KNI_ATTR_VOLTAGE_LIMIT",
                                        pInstrumentModel->maxVoltage,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        voltageLevelRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_CURRENT_LIMIT,
                                        "AGN6K7KNI_ATTR_CURRENT_LIMIT",
                                        pInstrumentModel->maxCurrent/100.0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        currentLimitPositiveRangeTablePtr, 0));
	checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_CURRENT_LIMIT_BEHAVIOR,
	                                   "AGN6K7KNI_ATTR_CURRENT_LIMIT_BEHAVIOR",
	                                   VI_NULL,
	                                   IVI_VAL_MULTI_CHANNEL | IVI_VAL_NOT_SUPPORTED,
	                                   VI_NULL, VI_NULL, VI_NULL));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_OUTPUT_ENABLED,
                                         "AGN6K7KNI_ATTR_OUTPUT_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_OVP_ENABLED,
                                         "AGN6K7KNI_ATTR_OVP_ENABLED", VI_TRUE,
                                         IVI_VAL_MULTI_CHANNEL, VI_NULL, VI_NULL));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_OVP_LIMIT,
                                        "AGN6K7KNI_ATTR_OVP_LIMIT",
                                        pInstrumentModel->maxVoltage,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        ovpLimitRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_VOLTAGE_LEVEL,
                                        "AGN6K7KNI_ATTR_VOLTAGE_LEVEL",
                                        pInstrumentModel->minVoltage,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        voltageLevelRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED,
                                         "AGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED",
                                         VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi,
                                       AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE,
                                       "AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE",
                                       AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrAcqTriggeredSlopeRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi,
                                       AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE,
                                       "AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE",
                                       AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrAcqTriggeredSlopeRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi,
                                        AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL,
                                        "AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL",
                                        pInstrumentModel->minVoltage, IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        voltageLevelRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi,
                                        AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL,
                                        "AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL",
                                        pInstrumentModel->minCurrent,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback, VI_NULL, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE,
                                       "AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE",
                                       AGN6K7KNI_VAL_SOFTWARE_TRIG, 0,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrTriggerSourceRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE,
                                       "AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE",
                                       AGN6K7KNI_VAL_SOFTWARE_TRIG,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrTriggerSourceRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE,
                                       "AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE",
                                       AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrTransientModeRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE,
                                       "AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE",
                                       AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrTransientModeRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL,
                                        "AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL",
                                        pInstrumentModel->maxCurrent/100.0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        currentLevelRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_TRIGGER_SOURCE,
                                       "AGN6K7KNI_ATTR_TRIGGER_SOURCE",
                                       AGN6K7KNI_VAL_SOFTWARE_TRIG,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrTriggerSourceRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LIMIT,
                                        "AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LIMIT",
                                        VI_NULL,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NOT_SUPPORTED,
                                        VI_NULL, VI_NULL, VI_NULL, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL,
                                        "AGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL",
                                        pInstrumentModel->minVoltage, IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        voltageLevelRangeTablePtr, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE,
                                       "AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE",
                                       AGN6K7KNI_VAL_EXPRESSION_SOURCE_NONE, 0,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrExpressionSourceRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE,
                                       "AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE",
                                       AGN6K7KNI_VAL_EXPRESSION_SOURCE_NONE, 0,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrExpressionSourceRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET,
                                        "AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET", 0, 0,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrOutputDelayOffsetRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE,
                                        "AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE", 0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrOutputDelayRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL,
                                        "AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL", 0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrOutputDelayRangeTable, 0));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED,
                                         "AGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED",
                                         VI_TRUE, 0, agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi,
                                         AGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED,
                                         "AGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED",
                                         VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME,
                                        "AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME", 0.001,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrConstantDwellTimeRangeTable, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_ARB_WFM_TYPE,
                                       "AGN6K7KNI_ATTR_ARB_WFM_TYPE",
                                       AGN6K7KNI_VAL_ARB_WFM_TYPE_VOLT,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrArbWfmTypeRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_ARB_WFM_COUNT,
                                       "AGN6K7KNI_ATTR_ARB_WFM_COUNT",
                                       AGN6K7KNI_VAL_ARB_COUNT_INFINITY,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniAttrArbWfmCount_ReadCallback,
                                       agn6k7kniAttrArbWfmCount_WriteCallback,
                                       &attrArbWfmCountRangeTable));
    checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi, AGN6K7KNI_ATTR_ARB_WFM_COUNT,
                                               agn6k7kniAttrArbWfmCount_CheckCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_FUNCTION,
                                       "AGN6K7KNI_ATTR_FUNCTION",
                                       AGN6K7KNI_VAL_FUNCTION_VOLTAGE,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrFunctionRangeTable));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_INITIATE_CONTINUOUS,
                                         "AGN6K7KNI_ATTR_INITIATE_CONTINUOUS",
                                         VI_NULL, IVI_VAL_MULTI_CHANNEL,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_MEASUREMENT_TIME,
                                        "AGN6K7KNI_ATTR_MEASUREMENT_TIME", 1,
                                        IVI_VAL_MULTI_CHANNEL,
                                        agn6k7kniViReal64_ReadCallback,
                                        agn6k7kniViReal64_WriteCallback,
                                        &attrMeasurementTimeRangeTable, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_MEASUREMENT_TYPE,
                                       "AGN6K7KNI_ATTR_MEASUREMENT_TYPE",
                                       AGN6K7KNI_VAL_MEAS_TYPE_VOLTAGE_DC,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                       VI_NULL, VI_NULL,
                                       &attrMeasurementTypeRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE,
                                       "AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE",
                                       AGN6K7KNI_VAL_EXPRESSION_SOURCE_NONE, 0,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrExpressionSourceRangeTable));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED,
                                         "AGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED",
                                         VI_FALSE, 0,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED,
                                         "AGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED",
                                         VI_TRUE, 0, agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE,
                                       "AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE",
                                       AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_OFF, 0,
                                       agn6k7kniEnum_ReadCallback,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrDigitalInhibitModeRangeTable));
    checkErr (Ivi_AddAttributeViBoolean (vi,
                                         AGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED,
                                         "AGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED",
                                         VI_FALSE, 0,
                                         agn6k7kniViBoolean_ReadCallback,
                                         agn6k7kniViBoolean_WriteCallback));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_DIGITAL_INPUT_DATA,
                                       "AGN6K7KNI_ATTR_DIGITAL_INPUT_DATA", 0,
                                       IVI_VAL_NOT_USER_WRITABLE,
                                       agn6k7kniViInt32_ReadCallback, VI_NULL,
                                       &attrDigitalDataRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA,
                                       "AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA", 0, 0,
                                       agn6k7kniViInt32_ReadCallback,
                                       agn6k7kniViInt32_WriteCallback,
                                       &attrDigitalDataRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi,
                                       AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER,
                                       "AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER",
                                       AGN6K7KNI_VAL_THRESHOLD_COMPARATOR_1,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                       VI_NULL, VI_NULL,
                                       &attrThresholdComparatorNumberRangeTable));
    checkErr (Ivi_AddRepeatedAttributeViInt32(vi, DIGITAL_PIN_REP_CAP_NAME, AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY,
                        "AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY", AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS,
                        0 ,agn6k7kniEnum_ReadCallback,
                        agn6k7kniEnum_WriteCallback,
                        &attrDigitalPinPolarityRangeTable));
    checkErr (Ivi_AddRepeatedAttributeViInt32(vi, DIGITAL_PIN_REP_CAP_NAME, AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION,
                        "AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION", AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN,
                        0 ,agn6k7kniEnum_ReadCallback,
                        agn6k7kniEnum_WriteCallback,
                        &attrDigitalPinFunctionRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_WHOUR,
                                        "AGN6K7KNI_ATTR_THRESHOLD_LEVEL_WHOUR", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        agn6k7kniAttrThresholdLevelWhour_ReadCallback,
                                        agn6k7kniAttrThresholdLevelWhour_WriteCallback,
                                        &attrThresholdLevelWhourRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_VOLTAGE,
                                        "AGN6K7KNI_ATTR_THRESHOLD_LEVEL_VOLTAGE", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        agn6k7kniAttrThresholdLevelVoltage_ReadCallback,
                                        agn6k7kniAttrThresholdLevelVoltage_WriteCallback,
                                        &attrThresholdLevelVoltageRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_POWER,
                                        "AGN6K7KNI_ATTR_THRESHOLD_LEVEL_POWER", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        agn6k7kniAttrThresholdLevelPower_ReadCallback,
                                        agn6k7kniAttrThresholdLevelPower_WriteCallback,
                                        &attrThresholdLevelPowerRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_CURRENT,
                                        "AGN6K7KNI_ATTR_THRESHOLD_LEVEL_CURRENT", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        agn6k7kniAttrThresholdLevelCurrent_ReadCallback,
                                        agn6k7kniAttrThresholdLevelCurrent_WriteCallback,
                                        &attrThresholdLevelCurrentRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_THRESHOLD_LEVEL_AHOUR,
                                        "AGN6K7KNI_ATTR_THRESHOLD_LEVEL_AHOUR", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        agn6k7kniAttrThresholdLevelAhour_ReadCallback,
                                        agn6k7kniAttrThresholdLevelAhour_WriteCallback,
                                        &attrThresholdLevelAhourRangeTable, 0));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_THRESHOLD_LEVEL,
                                        "AGN6K7KNI_ATTR_THRESHOLD_LEVEL", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        agn6k7kniAttrThresholdLevel_ReadCallback,
                                        agn6k7kniAttrThresholdLevel_WriteCallback,
                                        VI_NULL, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_THRESHOLD_OPERATION,
                                       "AGN6K7KNI_ATTR_THRESHOLD_OPERATION",
                                       AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniAttrThresholdOperation_ReadCallback,
                                       agn6k7kniAttrThresholdOperation_WriteCallback,
                                       &attrThresholdOperationRangeTable));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_THRESHOLD_FUNCTION,
                                       "AGN6K7KNI_ATTR_THRESHOLD_FUNCTION",
                                       AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE,
                                       IVI_VAL_MULTI_CHANNEL,
                                       agn6k7kniAttrThresholdFunction_ReadCallback,
                                       agn6k7kniAttrThresholdFunction_WriteCallback,
                                       &attrThresholdFunctionRangeTable));
    checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_CALIBRATION_DATA,
                                        "AGN6K7KNI_ATTR_CALIBRATION_DATA", VI_NULL,
                                        IVI_VAL_NOT_USER_READABLE, VI_NULL,
                                        agn6k7kniViReal64_WriteCallback, VI_NULL, 0));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_CALIBRATION_LEVEL,
                                       "AGN6K7KNI_ATTR_CALIBRATION_LEVEL",
                                       AGN6K7KNI_VAL_CAL_LEVEL_P1, 0, VI_NULL,
                                       agn6k7kniEnum_WriteCallback,
                                       &attrCalibrationLevelRangeTable));

        
        /*- End of Instrument Specific Attributes -------------------------------*/
    
    checkErr (Ivi_AddAttributeViString (vi, AGN6K7KNI_ATTR_ID_QUERY_RESPONSE,
                                        "AGN6K7KNI_ATTR_ID_QUERY_RESPONSE", "",
                                        IVI_VAL_NOT_USER_WRITABLE,
                                        agn6k7kniAttrIdQueryResponse_ReadCallback,
                                        VI_NULL));
                                               
    checkErr( Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_OPC_TIMEOUT,
                                       "AGN6K7KNI_ATTR_OPC_TIMEOUT",
                                       5000, IVI_VAL_HIDDEN | IVI_VAL_DONT_CHECK_STATUS,
                                       VI_NULL, VI_NULL, VI_NULL)); 
    checkErr( Ivi_AddAttributeViInt32 (vi,
                                       AGN6K7KNI_ATTR_VISA_RM_SESSION,
                                       "AGN6K7KNI_ATTR_VISA_RM_SESSION",
                                       VI_NULL,
                                       IVI_VAL_HIDDEN | IVI_VAL_DONT_CHECK_STATUS,
                                       VI_NULL, VI_NULL, VI_NULL));
    checkErr( Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_OPC_CALLBACK,
                                       "AGN6K7KNI_ATTR_OPC_CALLBACK",
                                       VI_NULL,
                                       IVI_VAL_HIDDEN | IVI_VAL_DONT_CHECK_STATUS,
                                       VI_NULL, VI_NULL, VI_NULL));
    checkErr( Ivi_AddAttributeViInt32 (vi,
                                       AGN6K7KNI_ATTR_CHECK_STATUS_CALLBACK,
                                       "AGN6K7KNI_ATTR_CHECK_STATUS_CALLBACK",
                                       VI_NULL,
                                       IVI_VAL_HIDDEN | IVI_VAL_DONT_CHECK_STATUS,
                                       VI_NULL, VI_NULL, VI_NULL));
    checkErr( Ivi_AddAttributeViInt32 (vi,
                                       AGN6K7KNI_ATTR_USER_INTERCHANGE_CHECK_CALLBACK,
                                       "AGN6K7KNI_ATTR_USER_INTERCHANGE_CHECK_CALLBACK",
                                       VI_NULL,
                                       IVI_VAL_HIDDEN | IVI_VAL_DONT_CHECK_STATUS,
                                       VI_NULL, VI_NULL, VI_NULL));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_INSTR_MODEL,
                                       "AGN6K7KNI_ATTR_INSTR_MODEL", modelType,
                                       IVI_VAL_HIDDEN, VI_NULL, VI_NULL, VI_NULL));
    checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_INSTR_OPTION,
                                       "AGN6K7KNI_ATTR_INSTR_OPTION", optionFlag,
                                       IVI_VAL_HIDDEN, VI_NULL, VI_NULL, VI_NULL));
    
    checkErr (Ivi_AddAttributeViAddr (vi, AGN6K7KNI_ATTR_INSTR_MODULES_RANGES,
                                      "AGN6K7KNI_ATTR_INSTR_MODULES_RANGES",
                                      pInstrumentModel, IVI_VAL_HIDDEN, VI_NULL,
                                      VI_NULL));
    
    
            /*- Setup attribute invalidations -----------------------------------*/
    checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED,
                                            AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED, VI_TRUE));
    checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED,
                                            AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED, VI_TRUE));
    
    if (IS_79XXA(modelType))
    {
        checkErr (Ivi_AddAttributeViBoolean (vi,
                                             AGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED,
                                             "AGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED",
                                             VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY,
                                           "AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY",
                                           AGN6K7KNI_VAL_RELAY_POLARITY_NORMAL,
                                           IVI_VAL_MULTI_CHANNEL,
                                           agn6k7kniEnum_ReadCallback,
                                           agn6k7kniEnum_WriteCallback,
                                           &attrOutputRelayPolarityRangeTable));
        checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED,
                                             "AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED",
                                             VI_TRUE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL,
                                            "AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL",
                                            0.00000512, IVI_VAL_MULTI_CHANNEL,
                                            agn6k7kniViReal64_ReadCallback,
                                            agn6k7kniViReal64_WriteCallback,
                                            &attrSweepTimeIntervalRangeTable, 0));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_SWEEP_POINT,
                                           "AGN6K7KNI_ATTR_SWEEP_POINT", 3906,
                                           IVI_VAL_MULTI_CHANNEL,
                                           agn6k7kniViInt32_ReadCallback,
                                           agn6k7kniViInt32_WriteCallback,
                                           &attrSweepPointRangeTable));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT,
                                           "AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT", 0,
                                           IVI_VAL_MULTI_CHANNEL,
                                           agn6k7kniViInt32_ReadCallback,
                                           agn6k7kniViInt32_WriteCallback,
                                           &attrSweepOffsetPointRangeTable));
        checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_OUTPUT_RANGE_AUTO,
                                             "AGN6K7KNI_ATTR_OUTPUT_RANGE_AUTO", VI_TRUE,
                                             IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_OUTPUT_RANGE,
                                            "AGN6K7KNI_ATTR_OUTPUT_RANGE",
                                            pInstrumentModel->maxCurrent,
                                            IVI_VAL_MULTI_CHANNEL,
                                            agn6k7kniViReal64_ReadCallback,
                                            agn6k7kniViReal64_WriteCallback,
                                            outputRangeRangeTablePtr, 0));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_MEASUREMENT_WINDOW,
                                           "AGN6K7KNI_ATTR_MEASUREMENT_WINDOW",
                                           AGN6K7KNI_VAL_MEAS_WINDOW_RECT,
                                           IVI_VAL_MULTI_CHANNEL,
                                           agn6k7kniEnum_ReadCallback,
                                           agn6k7kniEnum_WriteCallback,
                                           &attrMeasurementWindowRangeTable));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_LIST_COUNT,
                                           "AGN6K7KNI_ATTR_LIST_COUNT", 1,
                                           IVI_VAL_MULTI_CHANNEL,
                                           agn6k7kniAttrListCount_ReadCallback,
                                           agn6k7kniAttrListCount_WriteCallback,
                                           &attrListCountRangeTable));
        checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi, AGN6K7KNI_ATTR_LIST_COUNT,
                                                   agn6k7kniAttrListCount_CheckCallback));
        checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED,
                                             "AGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED",
                                             VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_LIST_STEP,
                                           "AGN6K7KNI_ATTR_LIST_STEP",
                                           AGN6K7KNI_VAL_LIST_STEP_AUTO,
                                           IVI_VAL_MULTI_CHANNEL,
                                           agn6k7kniEnum_ReadCallback,
                                           agn6k7kniEnum_WriteCallback,
                                           &attrListStepRangeTable));
        checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE_AUTO,
                                             "AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE_AUTO",
                                             VI_TRUE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE,
                                            "AGN6K7KNI_ATTR_ELOG_CURRENT_RANGE",
                                            pInstrumentModel->maxCurrent, IVI_VAL_MULTI_CHANNEL,
                                            agn6k7kniViReal64_ReadCallback,
                                            agn6k7kniViReal64_WriteCallback,
                                            outputRangeRangeTablePtr, 0));
        checkErr (Ivi_AddAttributeViReal64 (vi, AGN6K7KNI_ATTR_ELOG_PERIOD,
                                            "AGN6K7KNI_ATTR_ELOG_PERIOD", 60,
                                            IVI_VAL_MULTI_CHANNEL,
                                            agn6k7kniViReal64_ReadCallback,
                                            agn6k7kniViReal64_WriteCallback,
                                            &attrElogPeriodRangeTable, 0));
        checkErr (Ivi_AddAttributeViBoolean (vi,
                                             AGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED,
                                             "AGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED",
                                             VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED,
                                             "AGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED",
                                             VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViBoolean (vi,
                                             AGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED,
                                             "AGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED",
                                             VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViBoolean (vi, AGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED,
                                             "AGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED",
                                             VI_FALSE, IVI_VAL_MULTI_CHANNEL,
                                             agn6k7kniViBoolean_ReadCallback,
                                             agn6k7kniViBoolean_WriteCallback));
        checkErr (Ivi_AddAttributeViInt32 (vi, AGN6K7KNI_ATTR_CALIBRATION_COUNT,
                                           "AGN6K7KNI_ATTR_CALIBRATION_COUNT", VI_NULL,
                                           IVI_VAL_NOT_USER_WRITABLE | IVI_VAL_NEVER_CACHE,
                                           agn6k7kniViInt32_ReadCallback, VI_NULL,
                                           VI_NULL));
        
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_OUTPUT_ENABLED,
                                                AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_MEASUREMENT_TIME,
                                                AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_MEASUREMENT_TIME,
                                                AGN6K7KNI_ATTR_SWEEP_POINT, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_MEASUREMENT_TIME,
                                                AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL,
                                                AGN6K7KNI_ATTR_MEASUREMENT_TIME, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_SWEEP_POINT,
                                                AGN6K7KNI_ATTR_MEASUREMENT_TIME, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi, AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT,
                                                AGN6K7KNI_ATTR_MEASUREMENT_TIME, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi,
                                                AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER,
                                                AGN6K7KNI_ATTR_THRESHOLD_LEVEL, VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi,
                                                AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER,
                                                AGN6K7KNI_ATTR_THRESHOLD_OPERATION,
                                                VI_TRUE));
        checkErr (Ivi_AddAttributeInvalidation (vi,
                                                AGN6K7KNI_ATTR_THRESHOLD_COMPARATOR_NUMBER,
                                                AGN6K7KNI_ATTR_THRESHOLD_FUNCTION,
                                                VI_TRUE));
    }

Error:
    return error;
}

/*****************************************************************************
 *------------------- End Instrument Driver Source Code ---------------------*
 *****************************************************************************/
