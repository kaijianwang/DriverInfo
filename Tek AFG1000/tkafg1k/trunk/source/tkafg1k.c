/***************************************************************************** 
 * Copyright 2016, National Instruments, Corporation.  All Rights Reserved.      * 
 *****************************************************************************/

/*****************************************************************************
 *  Tektronics AFG1000 Series Arbitrary Funtion Generator Instrument Driver
 *  LabWindows/CVI Instrument Driver
 *  Original Release: Monday, March 30, 2016
 *  By: Kaijian Wang, National Instruments
 *      PH. 86-21-50509800-3512 
 *
******************************************************************************/

#include <utility.h>
#include <string.h>
#include <stdio.h>
#include <formatio.h>
#include <math.h>

#include "tkafg1k.h"

/*****************************************************************************
 *--------------------- Hidden Attribute Declarations -----------------------*
 *****************************************************************************/
#define TKAFG1K_ATTR_WFM_STRUCTURE                  (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 102L)     /* ViAddr */
#define TKAFG1K_ATTR_AMPLITUDE                      (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 103L)
#define TKAFG1K_ATTR_FREQUENCY                      (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 104L)
#define TKAFG1K_ATTR_OFFSET                         (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 105L)
#define TKAFG1K_ATTR_WAVEFORM                       (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 106L)
#define TKAFG1K_ATTR_ORIGINAL_WAVEFORM              (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 107L)

#define TKAFG1K_ATTR_CONTINUOUS_ENABLED             (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 111L)
#define TKAFG1K_ATTR_MODULATION_ENABLED             (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 112L)
#define TKAFG1K_ATTR_BURST_ENABLED                  (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 114L)
#define TKAFG1K_ATTR_ORIGINAL_MODULATION            (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 115L)


#define TKAFG1K_ATTR_MODEL                          (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 117L)
#define TKAFG1K_ATTR_SWEEP_ENABLED          (IVI_SPECIFIC_PRIVATE_ATTR_BASE + 119L)

/*****************************************************************************
 *------------- Attribute Range Definition for Different Model --------------*
 *****************************************************************************/

/*- Frequency Range ---------------------------------------------------------*/
	/*- Maximum Frequency Value for model 1022-*/
#define AFG1022_VAL_MAX_FREQ_SINE                   (25000000.00)
#define AFG1022_VAL_MAX_FREQ_SINE_IN_BURST          (25000000.00)
#define AFG1022_VAL_MAX_FREQ_SQUARE                 (12500000.00)
#define AFG1022_VAL_MAX_FREQ_SQUARE_IN_BURST        (12500000.00)
#define AFG1022_VAL_MAX_FREQ_PULSE                  (12500000.00)
#define AFG1022_VAL_MAX_FREQ_PULSE_IN_BURST         (12500000.00)   
#define AFG1022_VAL_MAX_FREQ_RAMP                   (1000000.00)
#define AFG1022_VAL_MAX_FREQ_RAMP_IN_BURST          (1000000.00)
#define AFG1022_VAL_MAX_FREQ_DEFAULT                (1000000.00)
#define AFG1022_VAL_MAX_FREQ_DEFAULT_IN_BURST       (1000000.00)   
#define AFG1022_VAL_MAX_FREQ_ARB                    (10000000.00)
#define AFG1022_VAL_MAX_FREQ_ARB_IN_BURST           (10000000.00)
	/*- Maximum Frequency Value for model 1062-*/
#define AFG1062_VAL_MAX_FREQ_SINE                   (60000000.00)
#define AFG1062_VAL_MAX_FREQ_SINE_IN_BURST          (30000000.00)
#define AFG1062_VAL_MAX_FREQ_SQUARE                 (30000000.00)
#define AFG1062_VAL_MAX_FREQ_SQUARE_IN_BURST        (15000000.00) 
#define AFG1062_VAL_MAX_FREQ_PULSE                  (30000000.00)
#define AFG1062_VAL_MAX_FREQ_PULSE_IN_BURST         (15000000.00)   
#define AFG1062_VAL_MAX_FREQ_RAMP                   (2000000.00)
#define AFG1062_VAL_MAX_FREQ_RAMP_IN_BURST          (2000000.00)
#define AFG1062_VAL_MAX_FREQ_DEFAULT                (2000000.00)
#define AFG1062_VAL_MAX_FREQ_DEFAULT_IN_BURST       (2000000.00)
#define AFG1062_VAL_MAX_FREQ_ARB                    (30000000.00)
#define AFG1062_VAL_MAX_FREQ_ARB_IN_BURST           (30000000.00)


    /*- Minmum Frequency Value for all models -*/
#define TKAFG1K_VAL_MIN_FREQ                        (0.000001)
    
	/*- Minmum In Burst Frequency Value for all models -*/
#define TKAFG1K_VAL_MIN_FREQ_IN_BURST               (0.002)


/*- Amplitude Range ---------------------------------------------------------*/
    /*- Maximum/Minimum Amplitude Value for model 1022 -*/
#define AFG1022_VAL_MAX_AMPL_IN_50OHM               (10.0)
#define AFG1022_VAL_MAX_AMPL_IN_OPEN                (20.0)
#define AFG1022_VAL_MIN_AMPL_IN_50OHM               (1.0e-3)
#define AFG1022_VAL_MIN_AMPL_IN_OPEN                (2.0e-3)

    /*- Maximum/Minimum Amplitude Value for model 1062 -*/
#define AFG1062_VAL_MAX_AMPL_IN_50OHM               (10.0)
#define AFG1062_VAL_MAX_AMPL_IN_OPEN                (20.0)
#define AFG1062_VAL_MIN_AMPL_IN_50OHM               (1.0e-3)
#define AFG1062_VAL_MIN_AMPL_IN_OPEN                (2.0e-3)

    /*- Maximum/Minimum Amplitude Value for model 1062 in high frequency-*/
#define AFG1062_VAL_MAX_AMPL_IN_50OHM_HIGH_FREQ               (5.0)
#define AFG1062_VAL_MAX_AMPL_IN_OPEN_HIGH_FREQ                (10.0)
#define AFG1062_VAL_MIN_AMPL_IN_50OHM_HIGH_FREQ               (1.0e-3)
#define AFG1062_VAL_MIN_AMPL_IN_OPEN_HIGH_FREQ                (2.0e-3)
/*- Offset Range ------------------------------------------------------------*/
#define TKAFG1K_VAL_MAX_OFFSET_IN_50OHM             (10.0)
#define TKAFG1K_VAL_MAX_OFFSET_IN_OPEN              (20.0)
#define TKAFG1K_VAL_MIN_OFFSET_IN_50OHM             (-10.0)
#define TKAFG1K_VAL_MIN_OFFSET_IN_OPEN              (-20.0)


/*- Minimum Pulse Width -----------------------------------------------------*/
#define AFG1022_VAL_MIN_PUL_WID                     (40e-9)
#define AFG1062_VAL_MIN_PUL_WID                     (17e-9)


/*- Maximum Waveform Size ---------------------------------------------------*/
#define AFG1022_VAL_MAX_WFM_SIZE                    8192
#define AFG1062_VAL_MAX_WFM_SIZE                    1048576
/*- Minimum Waveform Size ---------------------------------------------------*/
#define TKAFG1K_VAL_MIN_WFM_SIZE                    2

/*- Maximum Burst Count Size-------------------------------------------------*/
#define AFG1022_VAL_MAX_BURST_COUNT					50000
#define AFG1062_VAL_MAX_BURST_COUNT					1000000


/*****************************************************************************
 *---------------------------- Useful Macros --------------------------------*
 *****************************************************************************/
    /*- PI ------------------------------------------------------------------*/
#define PI                                          3.1415926

    /*- I/O buffer size -----------------------------------------------------*/
#define BUFFER_SIZE                                 (512L)

// #define TKAFG1K_IO_SESSION_TYPE                  IVI_VAL_VISA_SESSION_TYPE

    /*- 488.2 Event Status Register (ESR) Bits ------------------------------*/
#define IEEE_488_2_ERROR_MASK                       0x3C

    /*- Inner Error Code ----------------------------------------------------*/
#define TKAFG1K_ERROR_UNKNOWN_ARB_WFM               (IVI_SPECIFIC_ERROR_BASE + 0x300)

    /*- Waveform Quantum ----------------------------------------------------*/
#define TKAFG1K_VAL_WFM_QUANTUM                     1

    /*- Defined value for command to add additional signal ------------------*/
#define TKAFG1K_VAL_ADD_SIGNAL_NOTHING              "\"\""
#define TKAFG1K_VAL_ADD_SIGNAL_NOISE                "\"NOIS\""
#define TKAFG1K_VAL_ADD_SIGNAL_EXTERNAL             "\"EXT\""
#define TKAFG1K_VAL_ADD_SIGNAL_BOTH                 "\"BOTH\""

    /*- List of channels passed to the Ivi_BuildChannelTable function -------*/
#define CHAN1                                       "1"
#define CHAN2                                       "2"

#define AFG_CHANNEL_LIST                            "1,2"

#define TKAFG1K_VAL_WAVEFORM_TYPE_QUANTUM           4
#define TKAFG1K_VAL_RUNMODE_QUANTUM                 4
#define TKAFG1K_VAL_MODULATION_QUANTUM              9

    /*- Signal Modulation Type -*/
#define TKAFG1K_VAL_MODULATION_AM                   0
#define TKAFG1K_VAL_MODULATION_FM                   1
#define TKAFG1K_VAL_MODULATION_PM                   2
#define TKAFG1K_VAL_MODULATION_FSK                  3
#define TKAFG1K_VAL_MODULATION_PWM                  4

    /*- Waveform Classification -*/
#define TKAFG1K_VAL_WAVEFORM_TYPE0                  0
#define TKAFG1K_VAL_WAVEFORM_TYPE1                  1
#define TKAFG1K_VAL_WAVEFORM_TYPE2                  2
#define TKAFG1K_VAL_WAVEFORM_TYPE3                  3

    /*- Macros for access to enum range table -------------------------------*/
#define tkafg1k_GetCmdFromIntValue(value, table, cmd) \
    	Ivi_GetViInt32EntryFromValue (value, table, VI_NULL, VI_NULL,\
    								  VI_NULL, VI_NULL, cmd, VI_NULL)

static IviRangeTableEntry attrAFG1062BurstCountRangeTableEntries[] =
	{
		{TKAFG1K_VAL_BURST_INFINITY, TKAFG1K_VAL_BURST_INFINITY, 0, "", 0},
		{1, AFG1062_VAL_MAX_BURST_COUNT, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062BurstCountRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062BurstCountRangeTableEntries,
	};

static IviRangeTableEntry attrPSKDeviationRangeTableEntries[] =
	{
		{0, 2, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrPSKDeviationRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPSKDeviationRangeTableEntries,
	};

static IviRangeTableEntry attrASKAmplitudeRangeTableEntries[] =
	{
		{0, 1, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrASKAmplitudeRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrASKAmplitudeRangeTableEntries,
	};

static IviRangeTableEntry attrASKInternalRateRangeTableEntries[] =
	{
		{0.002, 100000, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrASKInternalRateRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrASKInternalRateRangeTableEntries,
	};

static IviRangeTableEntry attrPSKInternalRateRangeTableEntries[] =
	{
		{0.002, 100000, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrPSKInternalRateRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPSKInternalRateRangeTableEntries,
	};

static IviRangeTableEntry attrPSKSourceRangeTableEntries[] =
	{
		{TKAFG1K_VAL_PSK_INTERNAL, 0, 0, "INT", 0},
		{TKAFG1K_VAL_PSK_EXTERNAL, 0, 0, "EXT", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrPSKSourceRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPSKSourceRangeTableEntries,
	};

static IviRangeTableEntry attrASKSourceRangeTableEntries[] =
	{
		{TKAFG1K_VAL_ASK_INTERNAL, 0, 0, "INT", 0},
		{TKAFG1K_VAL_ASK_EXTERNAL, 0, 0, "EXT", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrASKSourceRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrASKSourceRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062ArbWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_ARB, TKAFG1K_VAL_MIN_FREQ, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062ArbWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062ArbWfmSweepFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022SquareWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_SQUARE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022SquareWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022SquareWfmSweepFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022PulseWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1022_VAL_MAX_FREQ_PULSE_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022PulseWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022PulseWfmInBurstFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062PulseWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1062_VAL_MAX_FREQ_PULSE_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062PulseWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062PulseWfmInBurstFuncFrequencyRangeTableEntries,
	};





static IviRangeTableEntry attrAFG1022SquareWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1022_VAL_MAX_FREQ_SQUARE_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022SquareWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022SquareWfmInBurstFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062SquareWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1062_VAL_MAX_FREQ_SQUARE_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062SquareWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062SquareWfmInBurstFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022RampWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1022_VAL_MAX_FREQ_RAMP_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022RampWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022RampWfmInBurstFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062RampWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1062_VAL_MAX_FREQ_RAMP_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062RampWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062RampWfmInBurstFuncFrequencyRangeTableEntries,
	};


static IviRangeTableEntry attrAFG1062ArbFrequencyInBurstRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1062_VAL_MAX_FREQ_ARB_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062ArbFrequencyInBurstRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062ArbFrequencyInBurstRangeTableEntries,
	};
static IviRangeTableEntry attrAFG1022ArbFrequencyInBurstRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1022_VAL_MAX_FREQ_ARB_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022ArbFrequencyInBurstRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022ArbFrequencyInBurstRangeTableEntries,
	};
static IviRangeTableEntry attrAFG1062ArbFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_ARB, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062ArbFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062ArbFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022ArbFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_ARB, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022ArbFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022ArbFrequencyRangeTableEntries,
	};


static IviRangeTableEntry attrAFG1062PulseWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_PULSE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062PulseWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062PulseWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022PulseWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_PULSE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022PulseWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022PulseWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062RampWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_RAMP, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062RampWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062RampWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022RampWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_RAMP, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022RampWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022RampWfmFuncFrequencyRangeTableEntries,
	};


static IviRangeTableEntry attrAFG1062RampWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_RAMP, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062RampWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062RampWfmSweepFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022RampWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_RAMP, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022RampWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022RampWfmSweepFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062SineWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_SINE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062SineWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062SineWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022SineWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_SINE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022SineWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022SineWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062SineWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1062_VAL_MAX_FREQ_SINE_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062SineWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062SineWfmInBurstFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022SineWfmInBurstFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ_IN_BURST, AFG1022_VAL_MAX_FREQ_SINE_IN_BURST, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022SineWfmInBurstFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022SineWfmInBurstFuncFrequencyRangeTableEntries,
	};



static IviRangeTableEntry attrAFG1062SineWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_SINE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062SineWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062SineWfmSweepFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022SineWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_SINE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022SineWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022SineWfmSweepFrequencyRangeTableEntries,
	};


static IviRangeTableEntry attrAFG1062SquareWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_SQUARE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062SquareWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062SquareWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022SquareWfmFuncFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_SQUARE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022SquareWfmFuncFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022SquareWfmFuncFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1062SquareWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1062_VAL_MAX_FREQ_SQUARE, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1062SquareWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1062SquareWfmSweepFrequencyRangeTableEntries,
	};

static IviRangeTableEntry attrAFG1022ArbWfmSweepFrequencyRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MIN_FREQ, AFG1022_VAL_MAX_FREQ_ARB, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrAFG1022ArbWfmSweepFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022ArbWfmSweepFrequencyRangeTableEntries,
	};






static ViBoolean waveformAndRunModeCombination[TKAFG1K_VAL_RUNMODE_QUANTUM][TKAFG1K_VAL_WAVEFORM_TYPE_QUANTUM] = {
/*	Sine,Square,Ramp	Pulse	Noise		Arb*/
    {   VI_TRUE,    VI_TRUE,    VI_TRUE,	VI_TRUE},          /* Continuous Mode  */
    {   VI_TRUE,    VI_TRUE,    VI_FALSE,	VI_TRUE},          /* Modulation Mode  */
    {   VI_TRUE,    VI_FALSE,   VI_FALSE,	VI_TRUE},          /* Sweep Mode       */
    {   VI_TRUE,    VI_TRUE,    VI_FALSE,	VI_TRUE},          /* Burst Mode       */
};

static ViBoolean waveformAndModulationCombination[TKAFG1K_VAL_MODULATION_QUANTUM][TKAFG1K_VAL_WAVEFORM_TYPE_QUANTUM] = {
/*	Sine,Square,Ramp	Pulse	Noise		Arb*/
    {   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* AM Modulation    */
    {   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* FM Modulation    */
    {   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* PM Modulation    */
    {   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* FSK Modulation   */
    {   VI_FALSE,   VI_TRUE,    VI_FALSE,    VI_FALSE},          /* PWM Modulation   */
	{   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* ASK Modulation   */         
	{   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* PSK Modulation   */
	{   VI_TRUE,    VI_FALSE,   VI_FALSE,    VI_TRUE},          /* Sweep Modulation   */         
	{   VI_TRUE,    VI_TRUE,    VI_FALSE,    VI_TRUE},          /* Burst Modulation   */
};

    /*- Defined values for attribute TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE----*/
#define TKAFG1K_VAL_MAX_WAVEFORMS                   (4L)
#define TKAFG1K_VAL_LAST_WAVEFORM_HANDLE            (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE + TKAFG1K_VAL_MAX_WAVEFORMS - 1L)



    /*- Defined value for length of arbitrary waveform and sequence names -*/

#define TKAFG1K_VAL_NAME_LENGTH                     (9L)
/*
    The driver uses this structure in its utility functions for creating and
    removing arbitray waveforms.
*/
typedef struct wfmNode
{
    ViInt32 wfmSize;
    ViChar  wfmName[TKAFG1K_VAL_NAME_LENGTH];
} wfmNode;
typedef wfmNode *wfmNodePtr;

/*****************************************************************************
 *-------------- Utility Function Declarations (Non-Exported) ---------------*
 *****************************************************************************/

static ViStatus tkafg1k_InitAttributes (ViSession vi, ViInt32 model);

static ViStatus tkafg1k_ConfigureModelDependantCallbacks (ViSession vi,
                                                          ViInt32 model);

static ViStatus tkafg1k_DefaultInstrSetup (ViSession openInstrSession);

static ViStatus tkafg1k_CheckStatus (ViSession vi);

static ViStatus tkafg1k_QueryOperationMode (ViSession vi, ViSession io,
                                            ViConstString channelName,
                                            ViInt32* operationMode);

static ViStatus tkafg1k_VerifyOutputMode   (ViSession vi, ViInt32 outputMode);

static ViStatus tkafg1k_VerifyOutputModeByChannel   (ViSession vi,
                                                     ViConstString channelName,
                                                     ViInt32 outputMode);

static ViStatus tkafg1k_CreateNewWaveform (ViSession vi, ViSession io,
                                           ViInt32 wfmSize, ViReal64 wfmData[],
                                           ViInt32 wfmHandle );



static ViStatus tkafg1k_CreateNewStandardShapeWaveform (ViSession vi,
                                                        ViSession io,
                                                        ViInt32 wfmSize,
                                                        ViInt32 wfmType,
                                                        ViInt32 wfmHandle);

static ViStatus tkafg1k_CreateArbRecords (ViSession vi);

static ViStatus tkafg1k_VerifyWfmCreatable (ViSession vi, ViInt32 wfmSize,
                                            ViReal64 wfmData[]);

static ViStatus tkafg1k_VerifyWfmBySlotCreatable (ViSession vi, ViInt32 wfmSize,
                                                  ViReal64 wfmData[]);

static ViStatus tkafg1k_VerifyInterpolateWfmCreatable (ViSession vi,
                                                       ViInt32 wfmSize,
                                                       ViReal64 startPointData,
                                                       ViReal64 endPointData);

static ViStatus tkafg1k_VerifyInterpolateWfmBySlotCreatable (
    ViSession vi,
    ViInt32 wfmSize,
    ViReal64 startPointData,
    ViReal64 endPointData);

static ViStatus tkafg1k_VerifyStandardShapeWfmCreatable (ViSession vi,
                                                         ViInt32 wfmSize,
                                                         ViInt32 wfmType);

static ViStatus tkafg1k_VerifyStandardShapeWfmBySlotCreatable (ViSession vi,
                                                               ViInt32 wfmSize,
                                                               ViInt32 wfmType);

static ViStatus tkafg1k_VerifyWfmHandle (ViSession vi, ViInt32 wfmHandle);

static ViStatus tkafg1k_GetNewWfmInfo (ViSession vi, ViInt32 *wfmHandle);

static ViStatus tkafg1k_GetNumDefinedWaveforms (ViSession vi, ViInt32 *numWfms);

static ViStatus tkafg1k_UpdateDriverWfmRecord (ViSession vi, ViInt32 wfmHandle,
                                               ViInt32 wfmSize);

static ViStatus tkafg1k_WfmExists (ViSession vi, ViInt32 wfmHandle,
                                   ViBoolean *wfmExists);

static ViStatus tkafg1k_ClearDriverWfmRecord (ViSession vi, ViInt32 wfmHandle);

static ViStatus tkafg1k_GetWfmSize (ViSession vi, ViSession io,
                                    ViInt32 wfmHandle, ViInt32* wfmSize);
static ViStatus tkafg1k_GetSweepFrequencyRangeTable( ViSession vi, ViConstString channelName,
                                                              IviRangeTablePtr *rangeTablePtr);

static ViStatus tkafg1k_Min (ViSession vi, ViInt32 digitsofPrecision,
                             ViReal64 a, ViReal64 b, ViReal64 *minValue);

    /*- I/O Operation Utility Functions -*/

static ViStatus tkafg1k_WriteCmd ( ViSession vi, ViSession io, ViConstString channelName, IviRangeTablePtr rt, 
                                   ViString format, ViInt32 value );
                                   
static ViStatus tkafg1k_ReadCmd ( ViSession vi, ViSession io,  ViConstString channelName, IviRangeTablePtr rt, 
                                  ViString format, ViInt32* value );

static ViStatus tkafg1k_WriteChannelIndependentCmd ( ViSession vi, ViSession io, IviRangeTablePtr rt, ViString format, 
                                                     ViInt32 value ); 
                                                    
static ViStatus tkafg1k_ReadChannelIndependentCmd ( ViSession vi, ViSession io, IviRangeTablePtr rt, ViString format,
                                                    ViInt32* value );

static ViStatus tkafg1k_WriteState( ViSession vi, ViSession io,  ViConstString channelName, ViString format, 
                                    ViBoolean value );
                                    
static ViStatus tkafg1k_ReadState( ViSession vi, ViSession io,  ViConstString channelName, ViString format, 
                                   ViBoolean* value );

static ViStatus tkafg1k_WriteReal64( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViReal64 value ); 
                                     
static ViStatus tkafg1k_ReadReal64( ViSession vi, ViSession io,  ViConstString channelName, ViString format,
                                    ViReal64* value );

static ViStatus tkafg1k_WriteChannelIndependentReal64( ViSession vi, ViSession io, ViString format, ViReal64 value);

static ViStatus tkafg1k_ReadChannelIndependentReal64( ViSession vi, ViSession io, ViString format, ViReal64* value); 

static ViStatus tkafg1k_WriteInt32( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViInt32 value );
                                     
static ViStatus tkafg1k_ReadInt32( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViInt32* value );                                   

static ViStatus tkafg1k_RunModeAllowable ( ViSession vi, ViInt32 waveform, ViInt32 runMode, 
                                     ViBoolean* allowance );
                                    
static ViStatus tkafg1k_ModulationTypeAllowable ( ViSession vi, ViInt32 waveform, 
                                                  ViInt32 modulationType, ViBoolean* allowance );

/*****************************************************************************
        Functions reserved for class driver use only.
        End-users should not call these functions.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_IviInit (ViRsrc resourceName, ViBoolean IDQuery,
                                   ViBoolean reset, ViSession vi);

ViStatus _VI_FUNC tkafg1k_IviClose (ViSession vi);

/*****************************************************************************
 *----------------- Callback Declarations (Non-Exported) --------------------*
 *****************************************************************************/

    /*- Global Session Callbacks --------------------------------------------*/

static ViStatus _VI_FUNC tkafg1k_CheckStatusCallback (ViSession vi,
                                                      ViSession io);

    /*- Attribute callbacks -------------------------------------------------*/

static ViStatus _VI_FUNC tkafg1kAttrDriverRevision_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    const ViConstString cacheValue);

static ViStatus _VI_FUNC tkafg1kAttrInstrumentManufacturer_ReadCallback (
    ViSession vi, ViSession io, ViConstString channelName,
    ViAttr attributeId, const ViConstString cacheValue);

static ViStatus _VI_FUNC tkafg1kAttrInstrumentModel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId, const ViConstString cacheValue);

static ViStatus _VI_FUNC tkafg1kAttrFirmwareRevision_ReadCallback (
    ViSession vi, ViSession io, ViConstString channelName,
    ViAttr attributeId, const ViConstString cacheValue);

static ViStatus _VI_FUNC tkafg1kAttrIdQueryResponse_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    const ViConstString cacheValue);

/***---  Basic Operation Attributes  ---*************************************/
static ViStatus _VI_FUNC tkafg1kAttrOperationMode_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrOperationMode_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrOperationMode_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrContinuousEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrContinuousEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);


static ViStatus _VI_FUNC tkafg1kAttrOutputModeByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);
static ViStatus _VI_FUNC tkafg1kAttrOutputModeByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrOutputEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrOutputEnabled_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);
static ViStatus _VI_FUNC tkafg1kAttrOutputImpedance_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrOutputImpedance_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

/***---  Function Waveform Attributes  ---***********************************/
static ViStatus _VI_FUNC tkafg1kAttrFuncWaveform_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncWaveform_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);
static ViStatus _VI_FUNC tkafg1kAttrFuncWaveform_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncAmplitude_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncAmplitude_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrFuncAmplitude_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncDCOffset_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncDCOffset_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrFuncDCOffset_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_RangeTableCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    IviRangeTablePtr *rangeTablePtr);
static ViStatus _VI_FUNC tkafg1kAttrFuncStartPhase_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrFuncStartPhase_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrFuncStartPhase_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);


/***---  Pulse Waveform Attributes  ---**************************************/




/***---  Arbitrary Waveform Attributes  ---**********************************/
static ViStatus _VI_FUNC tkafg1kAttrArbWaveformHandle_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrArbWaveformHandle_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);
static ViStatus _VI_FUNC tkafg1kAttrArbWaveformHandle_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrArbGain_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrArbGain_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrArbGain_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrArbOffset_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrArbOffset_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrArbOffset_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_RangeTableCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    IviRangeTablePtr *rangeTablePtr);
static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

/***---  Trigger Attributes  ---*********************************************/




/***---  Burst Attributes  ---***********************************************/
static ViStatus _VI_FUNC tkafg1kAttrBurstEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrBurstEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrBurstCount_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrBurstCount_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

/***---  Sweep Waveform Attributes  ---**************************************/
















/***---  Waveform Appendant Attributes  ---**********************************/




/***---  Modulation Configuration ---****************************************/
static ViStatus _VI_FUNC tkafg1kAttrModulationEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

/***---  Amplitude Modulation Attributes  ---********************************/
static ViStatus _VI_FUNC tkafg1kAttrAMEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrAMEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrAMEnabled_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);

static ViStatus _VI_FUNC tkafg1kAttrAMSource_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrAMSource_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrAMInternalFrequencyByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrAMInternalFrequencyByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveformByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);
static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveformByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveformByChannel_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrAMDepthByChannel_ReadCallBack (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrAMDepthByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

/***---  Frequency Modulation Attributes  ---********************************/
static ViStatus _VI_FUNC tkafg1kAttrFMEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrFMEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrFMEnabled_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);

static ViStatus _VI_FUNC tkafg1kAttrFMSource_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);
static ViStatus _VI_FUNC tkafg1kAttrFMSource_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrFMDeviationByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrFMDeviationByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrFMInternalFrequencyByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrFMInternalFrequencyByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveformByChannel_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveformByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveformByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

/***---  Frequency Shift Key Attributes  ---*********************************/
static ViStatus _VI_FUNC tkafg1kAttrFSKEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrFSKEnabled_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);

static ViStatus _VI_FUNC tkafg1kAttrFSKEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrFSKHopFrequency_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrFSKHopFrequency_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrFSKInternalRate_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrFSKInternalRate_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrFSKSource_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrFSKSource_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

/***---  Phase Modulation Attributes  ---************************************/
static ViStatus _VI_FUNC tkafg1kAttrPMEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrPMEnabled_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);

static ViStatus _VI_FUNC tkafg1kAttrPMEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrPMSource_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrPMSource_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrPMDeviationByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrPMDeviationByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPMInternalFrequencyByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrPMInternalFrequencyByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPMInternalWaveformByChannel_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrPMInternalWaveformByChannel_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrPMInternalWaveformByChannel_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

/***---  Pulse Width Modulation Attributes  ---******************************/
static ViStatus _VI_FUNC tkafg1kAttrPWMEnabled_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);
static ViStatus _VI_FUNC tkafg1kAttrPWMEnabled_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean *value);
static ViStatus _VI_FUNC tkafg1kAttrPWMEnabled_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrPWMDeviation_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);
static ViStatus _VI_FUNC tkafg1kAttrPWMDeviation_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);
static ViStatus _VI_FUNC tkafg1kAttrPWMInternalFrequency_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalFrequency_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalWaveform_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalWaveform_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalWaveform_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrPWMSource_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrPWMSource_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

/***---  Miscellaneous Attributes  ---***************************************/

/***--- Hidden Attributes --*************************************************/

static ViStatus _VI_FUNC tkafg1kAttrAmplitude_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrAmplitude_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrFrequency_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrFrequency_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrOffset_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrOffset_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);


static ViStatus _VI_FUNC tkafg1kAttrWaveform_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrWaveform_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrBurstMode_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrBurstMode_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViInt32 value);



static ViStatus _VI_FUNC tkafg1kAttrPulseDutyCycle_CheckCallback (
    ViSession vi,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPulseDutyCycle_ReadCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrPulseDutyCycle_WriteCallback (
    ViSession vi,
    ViSession io,
    ViConstString channelName,
    ViAttr attributeId,
    ViReal64 value);



static ViStatus _VI_FUNC tkafg1kAttrSweepEnabled_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrSweepEnabled_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrSweepStartFrequency_RangeTableCallback (ViSession vi,
                                                                            ViConstString channelName,
                                                                            ViAttr attributeId,
                                                                            IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC tkafg1kAttrSweepStartFrequency_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrSweepStartFrequency_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrSweepStopFrequency_RangeTableCallback (ViSession vi,
                                                                           ViConstString channelName,
                                                                           ViAttr attributeId,
                                                                           IviRangeTablePtr *rangeTablePtr);

static ViStatus _VI_FUNC tkafg1kAttrSweepStopFrequency_ReadCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrSweepStopFrequency_WriteCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrMaxWaveformSize_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrFmDeviationByChannel_CheckCallback (ViSession vi,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrAskEnabled_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrAskEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value);

static ViStatus _VI_FUNC tkafg1kAttrAskEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrPskEnabled_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrPskEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value);

static ViStatus _VI_FUNC tkafg1kAttrPskEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value);

static ViStatus _VI_FUNC tkafg1kAttrAskSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrAskSource_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrPskSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value);

static ViStatus _VI_FUNC tkafg1kAttrPskSource_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value);

static ViStatus _VI_FUNC tkafg1kAttrAskInternalRate_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrAskInternalRate_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPskInternalRate_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrPskInternalRate_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrAskAmplitude_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrAskAmplitude_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPskDeviation_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value);

static ViStatus _VI_FUNC tkafg1kAttrPskDeviation_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrPskDeviation_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value);

static ViStatus _VI_FUNC tkafg1kAttrBurstCount_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr);




/*****************************************************************************
 *------------ User-Callable Functions (Exportable Functions) ---------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: tkafg1k_init
 * Purpose:  VXIplug&play required function.  Calls the
 *           tkafg1k_InitWithOptions function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_init (ViRsrc resourceName, ViBoolean IDQuery,
                                 ViBoolean resetDevice, ViSession *newVi)
{
    ViStatus    error = VI_SUCCESS;

    if (newVi == VI_NULL)
    {
        Ivi_SetErrorInfo (VI_NULL, VI_FALSE, IVI_ERROR_INVALID_PARAMETER,
                          VI_ERROR_PARAMETER4, "Null address for Instrument Handle");
        checkErr( IVI_ERROR_INVALID_PARAMETER);
    }

    checkErr( tkafg1k_InitWithOptions (resourceName, IDQuery, resetDevice,
                                        "", newVi));

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_InitWithOptions
 * Purpose:  This function creates a new IVI session and calls the
 *           IviInit function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_InitWithOptions( ViRsrc resourceName,
                                           ViBoolean IDQuery,
                                           ViBoolean resetDevice,
                                           ViConstString optionString,
                                           ViSession *newVi )
{
    ViStatus    error = VI_SUCCESS;
    ViSession   vi = VI_NULL;
    ViChar      newResourceName[IVI_MAX_MESSAGE_BUF_SIZE];
    ViChar      newOptionString[IVI_MAX_MESSAGE_BUF_SIZE];
    ViBoolean   isLogicalName;

    if (newVi == VI_NULL)
    {
        Ivi_SetErrorInfo (VI_NULL, VI_FALSE, IVI_ERROR_INVALID_PARAMETER,
                          VI_ERROR_PARAMETER5, "Null address for Instrument Handle");
        checkErr( IVI_ERROR_INVALID_PARAMETER);
    }

    *newVi = VI_NULL;

    checkErr( Ivi_GetInfoFromResourceName( resourceName, (ViString)optionString,
                                           newResourceName, newOptionString, &isLogicalName));

    /* create a new interchangeable driver */
    checkErr( Ivi_SpecificDriverNew ("tkafg1k", newOptionString, &vi));
    if (!isLogicalName)
    {
        ViInt32 oldFlag = 0;

        checkErr (Ivi_GetAttributeFlags (vi, IVI_ATTR_IO_RESOURCE_DESCRIPTOR, &oldFlag));
        checkErr (Ivi_SetAttributeFlags (vi, IVI_ATTR_IO_RESOURCE_DESCRIPTOR, oldFlag & 0xfffb | 0x0010));
        checkErr (Ivi_SetAttributeViString (vi, "", IVI_ATTR_IO_RESOURCE_DESCRIPTOR, 0, newResourceName));
    }

    /* init the driver */
    checkErr( tkafg1k_IviInit (newResourceName, IDQuery, resetDevice, vi));
    if (isLogicalName)
        checkErr( Ivi_ApplyDefaultSetup (vi));
    *newVi = vi;

Error:
    if (error < VI_SUCCESS)
        Ivi_Dispose (vi);

    return error;
}

/*****************************************************************************
 * Function: tkafg1k_IviInit
 * Purpose:  This function is called by tkafg1k_InitWithOptions
 *           or by an IVI class driver.  This function initializes the I/O
 *           interface, optionally resets the device, optionally performs an
 *           ID query, and sends a default setup to the instrument.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_IviInit (ViRsrc resourceName, ViBoolean IDQuery,
                                    ViBoolean reset, 
                                    ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    ViSession   io = VI_NULL;
    ViInt32     model = TKAFG1K_VAL_MODEL_AFG1022;

    /*- Open Session --------------------------------------------------------*/
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
        viCheckErr( viSetAttribute (io, VI_ATTR_TMO_VALUE, 10000 ));
        viCheckErr( viSetBuf (io, VI_READ_BUF | VI_WRITE_BUF, 4000));
        viCheckErr( viSetAttribute (io, VI_ATTR_WR_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS));
        viCheckErr( viSetAttribute (io, VI_ATTR_RD_BUF_OPER_MODE, VI_FLUSH_ON_ACCESS));

        /*- Identification Query ------------------------------------------------*/
        if (IDQuery)
        {
            ViChar rdBuffer[BUFFER_SIZE];
            ViBoolean idQueryResult = VI_FALSE;

            viCheckErr (viQueryf( io, "*IDN?", "%s", rdBuffer) );

      		#define VALID_RESPONSE_STRING_START_AFG1022        "TEKTRONIX,AFG1022"
            #define VALID_RESPONSE_STRING_START_AFG1062        "TEKTRONIX,AFG1062"
            if( strncmp (rdBuffer, VALID_RESPONSE_STRING_START_AFG1022, strlen(VALID_RESPONSE_STRING_START_AFG1022)) == 0 )
            {
                idQueryResult = VI_TRUE;
                model = TKAFG1K_VAL_MODEL_AFG1022;
            }
            else if( strncmp (rdBuffer, VALID_RESPONSE_STRING_START_AFG1062, strlen(VALID_RESPONSE_STRING_START_AFG1062)) == 0 )
            {
                idQueryResult = VI_TRUE;
                model = TKAFG1K_VAL_MODEL_AFG1062;
            }
            if( idQueryResult == VI_FALSE)
            {
                viCheckErr( VI_ERROR_FAIL_ID_QUERY);
            }
        }
    }

    if( (Ivi_Simulating(vi)) || (!IDQuery) )
    {
        ViChar rdBuffer[BUFFER_SIZE];
        checkErr( Ivi_GetAttributeViString (vi, VI_NULL, IVI_ATTR_DRIVER_SETUP,
                                            0, BUFFER_SIZE, rdBuffer));

        if (strstr(rdBuffer, "AFG1022"))
        {
            model = TKAFG1K_VAL_MODEL_AFG1022;
        }
		else if (strstr(rdBuffer, "AFG1062"))
        {
            model = TKAFG1K_VAL_MODEL_AFG1062;
        }
        /*-------------------------------------*/
        else if (strstr(rdBuffer, "AFG"))
        {
            viCheckErr ( TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL );
        }
    }

    /*- Build Channel Table -------------------------------------------------*/

    checkErr( Ivi_BuildChannelTable (vi, AFG_CHANNEL_LIST, VI_FALSE, VI_NULL));

    /*- Add attributes ------------------------------------------------------*/
    checkErr( tkafg1k_InitAttributes (vi, model));

    /*- Reset instrument ----------------------------------------------------*/
    if (reset)
        checkErr( tkafg1k_reset (vi));
    else  /*- Send Default Instrument Setup ---------------------------------*/
        checkErr( tkafg1k_DefaultInstrSetup (vi));

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    if (error < VI_SUCCESS)
    {
        if (!Ivi_Simulating (vi) && io)
            viClose (io);
    }
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_close
 * Purpose:  This function closes the instrument.
 *
 *           Notes:
 *           (1) You must unlock the session when you call tkafg1k_close.
 *
 *           (2) After calling tkafg1k_close, you cannot use the instrument
 *               driver again until you call tkafg1k_init or
 *               tkafg1k_InitWithOptions.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_close (ViSession vi)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    checkErr( tkafg1k_IviClose (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    Ivi_Dispose (vi);

    return error;
}

/*****************************************************************************
 * Function: tkafg1k_IviClose
 * Purpose:  This function performs all of the drivers clean-up operations
 *           except for closing the IVI session.  This function is called by
 *           tkafg1k_close or by an IVI class driver.
 *
 *           Note:  This function must close the I/O session and set
 *           IVI_ATTR_IO_SESSION to 0.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_IviClose (ViSession vi)
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
 * Function: tkafg1k_reset
 * Purpose:  This function resets the instrument.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_reset (ViSession vi)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
        viCheckErr( viPrintf (io, "*RST"));
    }

    checkErr( tkafg1k_DefaultInstrSetup (vi));

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ResetWithDefaults
 * Purpose:  This function resets the instrument and applies default settings
 *           from the IVI Configuration Store based on the logical name
 *           from which the session was created.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ResetWithDefaults (ViSession vi)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));
    checkErr( tkafg1k_reset(vi));
    checkErr( Ivi_ApplyDefaultSetup(vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/****************************************************************************
 *  Function: tkafg1k_Disable
 *  Purpose:  This function places the instrument in a quiescent state as
 *            quickly as possible.
 ****************************************************************************/
ViStatus _VI_FUNC tkafg1k_Disable (ViSession vi)
{
    return TKAFG1K_ERROR_DISABLE_UNSUPPORTED;
}



/*****************************************************************************
 * Function: tkafg1k_revision_query
 * Purpose:  This function returns the driver and instrument revisions.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_revision_query (ViSession vi, ViChar driverRev[], ViChar instrRev[])
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (driverRev == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 2, "Null address for Driver Revision");
    if (instrRev == VI_NULL)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "Null address for Instrument Revision");

    checkErr( Ivi_GetAttributeViString (vi, VI_NULL, TKAFG1K_ATTR_SPECIFIC_DRIVER_REVISION,
                                        0, 256, driverRev));

    checkErr( Ivi_GetAttributeViString (vi, "", TKAFG1K_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                        0, 256, instrRev));

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession(vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_error_query
 * Purpose:  This function queries the instrument error queue and returns
 *           the result.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_error_query (ViSession vi, ViInt32 *errCode,
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
 * Function: tkafg1k_error_message
 * Purpose:  This function translates the error codes returned by this
 *           instrument driver into user-readable strings.
 *
 *           Note:  The caller can pass VI_NULL for the vi parameter.  This
 *           is useful if one of the init functions fail.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_error_message (ViSession vi, ViStatus errorCode, ViChar errorMessage[256])
{
    ViStatus    error = VI_SUCCESS;

    static      IviStringValueTable errorTable =
    {
            {TKAFG1K_ERROR_NO_WFMS_AVAILABLE,               "Waveform structure run out of use"                             },
            {TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL,          "Specified model is not supported"                              },
            {TKAFG1K_ERROR_ABORT_GENERATION_UNSUPPORTED,    "signal generation abortion is not supported"                   },
            {TKAFG1K_ERROR_CHANNELS_DIFFERENT,              "Attribute values of the two channels are different"            },
            {TKAFG1K_ERROR_COMBINATION_UNSUPPORTED,         "The combination of waveform and run mode is unsupported"       },
            {TKAFG1K_ERROR_INVALID_GROUP_VALUE,             "A group of value is invalid"                                   },
            {TKAFG1K_ERROR_DISABLE_UNSUPPORTED,             "Disable function unsupported"},
            IVIFGEN_ERROR_CODES_AND_MSGS,
            {VI_NULL,                                       VI_NULL}
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
 * Function: tkafg1k_InvalidateAllAttributes
 * Purpose:  This function invalidates the cached value of all attributes.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_InvalidateAllAttributes (ViSession vi)
{
    return Ivi_InvalidateAllAttributes(vi);
}

/*****************************************************************************
 * Function: tkafg1k_GetError and tkafg1k_ClearError Functions
 * Purpose:  These functions enable the instrument driver user to
 *           get or clear the error information the driver associates with the
 *           IVI session.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_GetError (ViSession vi, ViStatus *errorCode, ViInt32 bufferSize, ViChar description[])
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
        checkErr( Ivi_GetAttributeViString(vi, VI_NULL, IVI_ATTR_ERROR_ELABORATION, 0, 256, elaboration));
        checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, IVI_ATTR_SECONDARY_ERROR, 0, &secondary));
        checkErr( Ivi_GetAttributeViInt32(vi, VI_NULL, IVI_ATTR_PRIMARY_ERROR, 0, &primary));
    }

    /* Format data */
    if (primary != VI_SUCCESS)
    {
        ViChar msg[256] = "";
        checkErr( tkafg1k_error_message (vi, primary, msg));
        appendPoint += sprintf(appendPoint, "Primary Error: (Hex 0x%08X) %s\n", primary, msg);
    }

    if (secondary != VI_SUCCESS)
    {
        ViChar msg[256] = "";
        checkErr( tkafg1k_error_message (vi, secondary, msg));
        appendPoint += sprintf(appendPoint, "Secondary Error: (Hex 0x%08X) %s\n", secondary, msg);
    }

    if (elaboration[0])
    {
        sprintf(appendPoint, "Elaboration: %s", elaboration);
    }

    actualSize = (ViInt32)strlen(errorMessage) + 1;

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

ViStatus _VI_FUNC tkafg1k_ClearError (ViSession vi)
{
    return Ivi_ClearErrorInfo (vi);
}

/*****************************************************************************
 * Function: tkafg1k_GetNextCoercionRecord
 * Purpose:  This function enables the instrument driver user to obtain
 *           the coercion information associated with the IVI session.
 *           This function retrieves and clears the oldest instance in which
 *           the instrument driver coerced a value the instrument driver user
 *           specified to another value.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_GetNextCoercionRecord (ViSession vi,
                                                 ViInt32 bufferSize,
                                                 ViChar  record[])
{
    return Ivi_GetNextCoercionString (vi, bufferSize, record);
}

/****************************************************************************
 *  Function: tkafg1k_GetNextInterchangeWarning,
 *            tkafg1k_ResetInterchangeCheck, and
 *            tkafg1k_ClearInterchangeWarnings
 *  Purpose:  These functions allow the user to retrieve interchangeability
 *            warnings, reset the driver's interchangeability checking
 *            state, and clear all previously logged interchangeability warnings.
 ****************************************************************************/
ViStatus _VI_FUNC tkafg1k_GetNextInterchangeWarning (ViSession vi,
                                                     ViInt32 bufferSize,
                                                     ViChar warnString[])
{
    return Ivi_GetNextInterchangeCheckString (vi, bufferSize, warnString);
}

ViStatus _VI_FUNC tkafg1k_ResetInterchangeCheck (ViSession vi)
{
    return Ivi_ResetInterchangeCheck (vi);
}

ViStatus _VI_FUNC tkafg1k_ClearInterchangeWarnings (ViSession vi)
{
    return Ivi_ClearInterchangeWarnings (vi);
}

/*****************************************************************************
 * Function: tkafg1k_LockSession and tkafg1k_UnlockSession Functions
 * Purpose:  These functions enable the instrument driver user to lock the
 *           session around a sequence of driver calls during which other
 *           execution threads must not disturb the instrument state.
 *
 *           NOTE:  The callerHasLock parameter must be a local variable
 *           initialized to VI_FALSE and passed by reference, or you can pass
 *           VI_NULL.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_LockSession (ViSession vi, ViBoolean *callerHasLock)
{
    return Ivi_LockSession(vi,callerHasLock);
}
ViStatus _VI_FUNC tkafg1k_UnlockSession (ViSession vi, ViBoolean *callerHasLock)
{
    return Ivi_UnlockSession(vi,callerHasLock);
}

/****************************************************************************
 *  Function: tkafg1k_GetChannelName
 *  Purpose:  This function returns the highest-level channel name that
 *            corresponds to the specific driver channel string that is in
 *            the channel table at an index you specify.
 ****************************************************************************/
ViStatus _VI_FUNC tkafg1k_GetChannelName ( ViSession vi, ViInt32 index, ViInt32 bufferSize,
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

    actualSize = (ViInt32)strlen(channelName) + 1;

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

/*****************************************************************************
 * Function: tkafg1k_ConfigureOperationMode
 * Purpose:  This function configures the operation mode of the function
 *           generator.  The operation mode determines how the function
 *           generator produces waveforms.  For example, you can choose to
 *           continuously generate waveform, or to generate a discrete
 *           burst of waveform cycles based on a trigger event.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureOperationMode (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 operationMode)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_OPERATION_MODE,
                                    IVI_VAL_DIRECT_USER_CALL, operationMode);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureOutputMode
 * Purpose:  This function configures the output mode of the function
 *           generator.  The output mode determines the kind of waveform the
 *           function generator produces.  For example, you can choose to
 *           generate a standard waveform, an arbitrary waveform.
 * 
 *           Notes:
 *           This function is not based on channel. If you specify an
 *           instrument with two channels, the function configures output
 *           mode for both channels.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureOutputMode (ViSession vi,
                                               ViInt32 outputMode)
{
    return Ivi_SetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE,
                                    IVI_VAL_DIRECT_USER_CALL, outputMode);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureOutputModeByChannel
 * Purpose:  This function configures the output mode of the function
 *           generator by channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureOutputModeByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViInt32 outputMode )
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL,
                                    IVI_VAL_DIRECT_USER_CALL, outputMode);

}

/*****************************************************************************
 * Function: tkafg1k_ConfigureOutputImpedance
 * Purpose:  This function configures the output impedance for the channel
 *           you specify.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureOutputImpedance (ViSession vi,
                                                    ViConstString channelName,
                                                    ViReal64 outputImpedance)
{
    return Ivi_SetAttributeViReal64 (vi, channelName,
                                     TKAFG1K_ATTR_OUTPUT_IMPEDANCE,
                                     IVI_VAL_DIRECT_USER_CALL, outputImpedance);
}



/*****************************************************************************
 * Function: tkafg1k_ConfigureOutputEnabled
 * Purpose:  This function configures whether the signal the function
 *           generator produces appears at the channel's output connector.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_ConfigureOutputEnabled (ViSession vi,
                                                   ViConstString channelName,
                                                   ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName,
                                      TKAFG1K_ATTR_OUTPUT_ENABLED,
                                      IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_InitiateGeneration
 * Purpose:  This function initiates signal generation.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_InitiateGeneration (ViSession vi)
{
    return VI_SUCCESS;
}

/*****************************************************************************
 * Function: tkafg1k_AbortGeneration
 * Purpose:  This function aborts a previously initiated signal generation.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_AbortGeneration (ViSession vi)
{
    return TKAFG1K_ERROR_ABORT_GENERATION_UNSUPPORTED;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureStandardWaveform
 * Purpose:  This function configures the attributes of the function
 *           generator that affect standard waveform generation.  These
 *           attributes are the waveform, amplitude, DC offset, frequency,
 *           and start phase.
 *
 *           Notes:
 *           (1) You must set the output mode to TKAFG1K_VAL_OUTPUT_FUNC
 *               before calling this function.
 *
 *           (2) If the waveform parameter is set to TKAFG1K_VAL_WFM_DC, this
 *               function ignores the amplitude, frequency, and start phase
 *               parameters. If the waveform parameter is set to
 *               TKAFG1K_VAL_WFM_PRN, this function ignores the frequency and
 *               start phase parameters.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureStandardWaveform (ViSession vi,
                                                     ViConstString channelName,
                                                     ViInt32 waveform,
                                                     ViReal64 amplitude,
                                                     ViReal64 dcOffset,
                                                     ViReal64 frequency,
                                                     ViReal64 startPhase)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    /* Set attributes: */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_FUNC_WAVEFORM, 0, waveform), 3, "Standard Waveform");

    /* Pre-set offset to 0 */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_DC_OFFSET, 0, 0), 5, "DC Offset");

    if(waveform == TKAFG1K_VAL_WFM_PRN)
    {
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_AMPLITUDE, 0, amplitude), 4, "Amplitude");
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_DC_OFFSET, 0, dcOffset), 5, "DC Offset");
    }
    else if(waveform == TKAFG1K_VAL_WFM_PULS)
    {
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_AMPLITUDE, 0, amplitude), 4, "Amplitude");
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_DC_OFFSET, 0, dcOffset), 5, "DC Offset");
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_FREQUENCY, 0, frequency), 6, "Frequency");
    }
    else
    {
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_AMPLITUDE, 0, amplitude), 4, "Amplitude");
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_DC_OFFSET, 0, dcOffset), 5, "DC Offset");
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_FREQUENCY, 0, frequency), 6, "Frequency");
        viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FUNC_START_PHASE, 0, startPhase), 7, "Start Phase");
    }

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}






/*****************************************************************************
 * Function: tkafg1k_QueryArbWfmCapabilities
 * Purpose:  This function returns the attributes of the function generator
 *           that are related to creating arbitrary waveforms.  These
 *           attributes are the maximum number of waveforms, waveform
 *           quantum, minimum waveform size, and maximum waveform size.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_QueryArbWfmCapabilities (ViSession vi,
                                                    ViInt32 *maxNumWfms,
                                                    ViInt32 *wfmQuantum,
                                                    ViInt32 *minWfmSize,
                                                    ViInt32 *maxWfmSize)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    /* Get attributes */
    if (maxNumWfms)
        viCheckParm( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS, 0, maxNumWfms), 2, "Max Number of Waveforms");

    if (wfmQuantum)
        viCheckParm( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, wfmQuantum), 3, "Waveform Quantum");

    if (minWfmSize)
        viCheckParm( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, minWfmSize), 4, "Min Waveform Size");

    if (maxWfmSize)
        viCheckParm( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, maxWfmSize), 5, "Max Waveform Size");

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureSampleRate
 * Purpose:  This function configures the sample rate attribute, which
 *           determines the rate at which the function generator produces
 *           arbitrary waveforms.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureSampleRate (ViSession vi,
                                                        ViReal64 sampleRate)
{
    return Ivi_SetAttributeViReal64 (vi, VI_NULL, TKAFG1K_ATTR_ARB_SAMPLE_RATE,
                                     IVI_VAL_DIRECT_USER_CALL, sampleRate);
}

/*****************************************************************************
 * Function: tkafg1k_CreateArbWaveform
 * Purpose:  This function creates an arbitrary waveform and returns a handle
 *           that identifies that waveform.  You use the handles this function
 *           returns to specify what waveform to generate with the
 *           tkafg1k_ConfigureArbWaveform function.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_CreateArbWaveform (ViSession vi, ViInt32 wfmSize,
                                              ViReal64 wfmData[],
                                              ViInt32 *wfmHandle)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  newWfmHandle = VI_NULL;
    ViChar  *dataBuffer = VI_NULL;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (!wfmData)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 3, "NULL address for wfmData");

    if (!wfmHandle)
        viCheckParm ( IVI_ERROR_INVALID_PARAMETER, 4, "NULL address for wfmHandle");

    checkErr( tkafg1k_VerifyWfmCreatable(vi, wfmSize, wfmData));
    checkErr( tkafg1k_GetNewWfmInfo (vi, &newWfmHandle));

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        checkErr( tkafg1k_CreateNewWaveform(vi, io, wfmSize, wfmData, newWfmHandle) );
    }

    checkErr( tkafg1k_UpdateDriverWfmRecord (vi, newWfmHandle, wfmSize) );

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    if (dataBuffer)
        Ivi_Free (vi, dataBuffer);

    /* if there is an error, do not return a handle. */
    if (error < VI_SUCCESS)
        newWfmHandle = VI_NULL;
    *wfmHandle = newWfmHandle;

    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePulseDutyCycle
 * Purpose:  This function configures the attribute of the function generator
 *           that are related to pulse waveform. These attributes are pulse
 *           duty cylce, leading edge time and trailing edge time.
 *
 *           Notes:
 *           (1) Because the attributes set in this function can only be
 *               operated correctly in PULSE waveform, the driver limits its
 *               accessibility to PULSE waveform. To ensure this function works,
 *               you should configure waveform shape to PULSE before using this
 *               function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePulseDutyCycle (ViSession vi,
                                                  ViConstString channelName,
                                                  ViReal64 dutyCycle)
{
    ViStatus error = VI_SUCCESS;
    checkErr( Ivi_LockSession (vi, VI_NULL));
    viCheckParm ( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_PULSE_DUTY_CYCLE,
                                IVI_VAL_DIRECT_USER_CALL, dutyCycle), 3, "Duty Cycle");
Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*****************************************************************************
 * Function: tkafg1k_CreateStandardShapeArbWfm
 * Purpose:  This function creates a standard shape arbitrary waveform and
 *           returns a handle that identifies that waveform.  You use the
 *           handles this function returns to specify what waveform to generate
 *           with the tkafg1k_ConfigureArbWaveform function.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_CreateStandardShapeArbWfm (ViSession vi,
                                                     ViInt32 wfmSize,
                                                     ViInt32 wfmType,
                                                     ViInt32 *wfmHandle)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32  newWfmHandle = VI_NULL;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (!wfmHandle)
        viCheckParm ( IVI_ERROR_INVALID_PARAMETER, 4, "NULL address for wfmHandle");

    checkErr (tkafg1k_VerifyStandardShapeWfmCreatable (vi, wfmSize, wfmType) );
    checkErr( tkafg1k_GetNewWfmInfo (vi, &newWfmHandle));

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        checkErr ( tkafg1k_CreateNewStandardShapeWaveform (vi, io, wfmSize, wfmType, newWfmHandle) );
    }

    checkErr( tkafg1k_UpdateDriverWfmRecord (vi, newWfmHandle, wfmSize));

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    /* if there is an error, do not return a handle. */
    if (error < VI_SUCCESS)
        newWfmHandle = VI_NULL;
    *wfmHandle = newWfmHandle;

    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_GetArbitraryWaveformBySlot
 * Purpose:  This function returns the waveform handle on a specified
 *           slot.  If the specified slot is empty, the function returns
 *           VI_NULL as the waveform handle.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_GetArbitraryWaveformBySlot (ViSession vi,
                                                      ViInt32 slot,
                                                      ViInt32 *wfmHandle)
{
    ViStatus    error = VI_SUCCESS;
    wfmNodePtr  wfmStruct = VI_NULL;
    checkErr( Ivi_LockSession (vi, VI_NULL));

    checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      0, (ViAddr *)(&wfmStruct)));

    if (wfmStruct[slot].wfmSize)
        *wfmHandle = slot;
    else
        *wfmHandle = VI_NULL;

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_CreateArbWaveformBySlot
 * Purpose:  This function creates an arbitrary waveform on a specified slot
 *           and returns a handle that identifies that waveform.  You use
 *           the handles this function returns to specify what waveform to
 *           generate with the tkafg1k_ConfigureArbWaveform function.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_CreateArbWaveformBySlot (ViSession vi,
                                                   ViInt32 slot, ViInt32 wfmSize,
                                                   ViReal64 wfmData[],
                                                   ViBoolean overwrite,
                                                   ViInt32 *wfmHandle)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  newWfmHandle = VI_NULL;
    ViChar  *dataBuffer = VI_NULL;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (!wfmData)
        viCheckParm( IVI_ERROR_INVALID_PARAMETER, 4, "NULL address for wfmData");

    if (!wfmHandle)
        viCheckParm ( IVI_ERROR_INVALID_PARAMETER, 5, "NULL address for wfmHandle");

    if (VI_FALSE == overwrite) {
        checkErr( tkafg1k_GetArbitraryWaveformBySlot(vi, slot, &newWfmHandle));
        if (newWfmHandle)
            viCheckErrElab( TKAFG1K_ERROR_NO_WFMS_AVAILABLE,
                            "The slot is not free for creating new waveform.");

        checkErr( tkafg1k_VerifyWfmCreatable (vi, wfmSize, wfmData));
    } else {
        checkErr( tkafg1k_VerifyWfmBySlotCreatable (vi, wfmSize, wfmData));
    }

    newWfmHandle = slot;

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        checkErr( tkafg1k_CreateNewWaveform(vi, io, wfmSize, wfmData, newWfmHandle) );
    }

    checkErr( tkafg1k_UpdateDriverWfmRecord (vi, newWfmHandle, wfmSize) );

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    if (dataBuffer)
        Ivi_Free (vi, dataBuffer);

    /* if there is an error, do not return a handle. */
    if (error < VI_SUCCESS)
        newWfmHandle = VI_NULL;
    *wfmHandle = newWfmHandle;

    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}


/*****************************************************************************
 * Function: tkafg1k_CreateStandardShapeArbWfmBySlot
 * Purpose:  This function creates a standard shape arbitrary waveform and
 *           returns a handle that identifies that waveform.  You use the
 *           handles this function returns to specify what waveform to generate
 *           with the tkafg1k_ConfigureArbWaveform function.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_CreateStandardShapeArbWfmBySlot (ViSession vi,
                                                           ViInt32 slot,
                                                           ViInt32 wfmSize,
                                                           ViInt32 wfmType,
                                                           ViBoolean overwrite,
                                                           ViInt32 *wfmHandle)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32  newWfmHandle = VI_NULL;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    if (!wfmHandle)
        viCheckParm ( IVI_ERROR_INVALID_PARAMETER, 5, "NULL address for wfmHandle");

    if (VI_FALSE == overwrite) {
        checkErr( tkafg1k_GetArbitraryWaveformBySlot(vi, slot, &newWfmHandle));
        if (newWfmHandle)
            viCheckErrElab( TKAFG1K_ERROR_NO_WFMS_AVAILABLE,
                            "The slot is not free for creating new waveform.");

        checkErr (tkafg1k_VerifyStandardShapeWfmCreatable (vi, wfmSize, wfmType) );
    } else {
        checkErr (tkafg1k_VerifyStandardShapeWfmBySlotCreatable (vi, wfmSize, wfmType) );
    }

    newWfmHandle = slot;

    if (!Ivi_Simulating(vi))                /* call only when locked */
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        checkErr ( tkafg1k_CreateNewStandardShapeWaveform (vi, io, wfmSize, wfmType, newWfmHandle) );
    }

    checkErr( tkafg1k_UpdateDriverWfmRecord (vi, newWfmHandle, wfmSize));

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    /* if there is an error, do not return a handle. */
    if (error < VI_SUCCESS)
        newWfmHandle = VI_NULL;
    *wfmHandle = newWfmHandle;

    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureArbWaveform
 * Purpose:  This function configures the attributes of the function
 *           generator that affect arbitrary waveform generation.  These
 *           attributes are the arbitrary waveform handle, gain, and offset.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_ConfigureArbWaveform (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 wfmHandle,
                                                  ViReal64 arbGain,
                                                  ViReal64 arbOffset)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

    /* Pre-set offset to 0 */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_ARB_OFFSET,
                                           0, 0), 5, "Arbitrary Offset");

    /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName,
                                          TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE,
                                          0, wfmHandle), 3, "Waveform Handle");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_ARB_GAIN,
                                           0, arbGain), 4, "Arbitrary Gain");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_ARB_OFFSET,
                                           0, arbOffset), 5, "Arbitrary Offset");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}





/*****************************************************************************
 * Function: tkafg1k_ConfigureArbFrequency
 * Purpose:  This function configures the arbitrary waveform frequency,
 *           which is the rate at which the function generator produces
 *           one cycle of an arbitrary waveform.
 *
 *           Notes:
 *           You must set the output mode to TKAFG1K_VAL_OUTPUT_ARB before
 *           calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureArbFrequency (ViSession vi,
                                                          ViConstString channelName,
                                                          ViReal64 arbFrequency)
{
    return Ivi_SetAttributeViReal64 (vi, channelName,
                                     TKAFG1K_ATTR_ARB_FREQUENCY,
                                     IVI_VAL_DIRECT_USER_CALL, arbFrequency);
}



/*****************************************************************************
 * Function: tkafg1k_ConfigureBurstEnabled
 * Purpose:  This function configures whether to enable burst mode.
 *
 *           Notes:
 *           (1) To enable burst mode, except for this function, you can also
 *               use tkafg1k_ConfigureOperationMode function and configure
 *               operation mode to TKAFG1K_VAL_OPERATE_BURST.
 *
 *           (2) To enhance program correctness make sure to set appropriate
 *               waveform shape before calling this function.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureBurstEnabled (ViSession vi,
                                                 ViConstString channelName,
                                                 ViBoolean enabled)
{
    ViStatus  error = VI_SUCCESS;
    checkErr( Ivi_LockSession (vi, VI_NULL));

    checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_BURST_ENABLED,
                                            0, enabled) );

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureBurstCount
 * Purpose:  This function configures the burst count.  When you set the
 *           operation mode to burst, the burst count determines how many
 *           waveform cycles the function generator produces after each trigger
 *           event.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_ConfigureBurstCount (ViSession vi,
                                                 ViConstString channelName,
                                                 ViInt32 count)
{
    return Ivi_SetAttributeViInt32 (vi, channelName,
                                    TKAFG1K_ATTR_BURST_COUNT,
                                    IVI_VAL_DIRECT_USER_CALL, count);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureBurstMode
 * Purpose:  This function configures the burst mode to triggered or gated.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureBurstMode (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 burstMode)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_BURST_MODE,
                                    IVI_VAL_DIRECT_USER_CALL, burstMode);
}



/*****************************************************************************
 * Function: tkafg1k_ConfigureAMEnabled
 * Purpose:  This function configures whether the function generator applies
 *           amplitude modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureAMEnabled (ViSession vi,
                                              ViConstString channelName,
                                              ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_AM_ENABLED,
                                      IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureAMSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when amplitude modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureAMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_AM_SOURCE,
                                    IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureAMInternal
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal amplitude modulation source.
 *           These attributes are the modulation depth, waveform, and
 *           frequency.
 *
 *           Notes:
 *           (1) This function is not based on channel.
 *
 *           (2) You should configure AM source to internal before calling
 *               this function.
 *
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_ConfigureAMInternal (ViSession vi, ViReal64 amDepth,
                                                ViInt32 amWaveform, ViReal64 amFrequency)
{
    ViStatus error = VI_SUCCESS;
	ViInt32 chan1Source, chan2Source;   
    checkErr( Ivi_LockSession (vi, VI_NULL));
    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN1, TKAFG1K_ATTR_AM_SOURCE, 0, &chan1Source) );
    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN2, TKAFG1K_ATTR_AM_SOURCE, 0, &chan2Source) );
    if( (chan1Source != TKAFG1K_VAL_AM_INTERNAL) || (chan2Source != TKAFG1K_VAL_AM_INTERNAL) )
    {
        error = IVI_ERROR_INVALID_CONFIGURATION;
        viCheckErr (error);
    }

    /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL,
                                          TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM, 0,
                                          amWaveform), 3, "AM Waveform");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL,
                                           TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY, 0,
                                           amFrequency), 4, "AM Frequency");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL,
                                          TKAFG1K_ATTR_AM_INTERNAL_DEPTH, 0,
                                          amDepth), 2, "AM Depth");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureAMInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal amplitude modulation source to
 *           a channel. These attributes are the modulation depth, waveform,
 *           and frequency.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureAMInternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 amDepth,
                                                        ViInt32 amWaveform,
                                                        ViReal64 amFrequency)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName,
                                          TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, 0,
                                          amWaveform), 4, "AM Waveform");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 0,
                                           amFrequency), 5, "AM Frequency");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL, 0,
                                          amDepth), 3, "AM Depth");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureAMExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external amplitude modulation source to
 *           a channel. These attributes are the modulation depth.
 *
 *           Notes:
 *           This function is not channel-based.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureAMExternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 amDepth)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL, 0,
                                          amDepth), 3, "AM Depth");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFMEnabled
 * Purpose:  This function configures whether the function generator applies
 *           frequency modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFMEnabled (ViSession vi,
                                               ViConstString channelName,
                                               ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_FM_ENABLED,
                                     IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFMSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when frequency modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_FM_SOURCE,
                                    IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFMInternal
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal frequency modulation source.
 *           These attributes are the peak deviation, waveform,
 *           and frequency.
 *
 *           Notes:
 *           (1) This function is not based on channel.
 *
 *           (2) You should configure FM source to internal before calling
 *               this function.
 *****************************************************************************/
ViStatus _VI_FUNC  tkafg1k_ConfigureFMInternal (ViSession vi, ViReal64 fmDeviance,
                                                ViInt32 fmWaveform, ViReal64 fmFrequency)
{
    ViStatus error = VI_SUCCESS;
	ViInt32 chan1Source, chan2Source; 
    checkErr( Ivi_LockSession (vi, VI_NULL));
    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN1, TKAFG1K_ATTR_FM_SOURCE, 0, &chan1Source) );
    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN2, TKAFG1K_ATTR_FM_SOURCE, 0, &chan2Source) );
    if( (chan1Source != TKAFG1K_VAL_FM_INTERNAL) || (chan2Source != TKAFG1K_VAL_FM_INTERNAL) )
    {
        error = IVI_ERROR_INVALID_CONFIGURATION;
        viCheckErr (error);
    }

    /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, VI_NULL,
                                          TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM, 0,
                                          fmWaveform), 3, "FM Waveform");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL,
                                           TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY, 0,
                                           fmFrequency), 4, "FM Frequency");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, VI_NULL,
                                          TKAFG1K_ATTR_FM_INTERNAL_DEVIATION, 0,
                                          fmDeviance), 2, "FM Peak Deviance");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFMInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal frequency modulation source
 *           to a channel. These attributes are the peak deviation, waveform,
 *           and frequency.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFMInternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 fmDeviance,
                                                        ViInt32 fmWaveform,
                                                        ViReal64 fmFrequency)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName,
                                          TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, 0,
                                          fmWaveform), 4, "FM Waveform");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, 0,
                                           fmFrequency), 5, "FM Frequency");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL, 0,
                                          fmDeviance), 3, "FM Peak Deviance");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFMExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external frequency modulation source
 *           to a channel. The attribute is the peak deviation.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFMExternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 fmDeviance)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL, 0,
                                          fmDeviance), 3, "FM Peak Deviance");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePMEnabled
 * Purpose:  This function configures whether the function generator applies
 *           phase modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePMEnabled (  ViSession vi,
                                                ViConstString channelName,
                                                ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PM_ENABLED,
                                        IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePMSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when phase modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePMSource (   ViSession vi,
                                                ViConstString channelName,
                                                ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_PM_SOURCE,
                                        IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePMInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal phase modulation source
 *           to a channel. These attributes are the peak deviation, waveform,
 *           and frequency.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePMInternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 pmDeviation,
                                                        ViInt32 pmWaveform,
                                                        ViReal64 pmFrequency)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName,
                                          TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, 0,
                                          pmWaveform), 4, "PM Waveform");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, 0,
                                           pmFrequency), 5, "PM Frequency");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL, 0,
                                           pmDeviation), 3, "PM Peak Deviance");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePMExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external phase modulation source to
 *           a channel. These attributes are the peak deviation.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePMExternalByChannel (ViSession vi,
                                                        ViConstString channelName,
                                                        ViReal64 pmDeviation)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL, 0,
                                          pmDeviation), 3, "PM Peak Deviance");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFSKEnabled
 * Purpose:  This function configures whether the function generator applies
 *           FSK modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFSKEnabled ( ViSession vi,
                                                ViConstString channelName,
                                                ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_FSK_ENABLED,
                                        IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFSKSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when FSK modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFSKSource (  ViSession vi,
                                                ViConstString channelName,
                                                ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_FSK_SOURCE,
                                        IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFSKInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal FSK modulation source
 *           to a channel. These attributes are the hop frequency and
 *           internal rate.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFSKInternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 hopFrequency,
                                                         ViReal64 rate)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_FSK_HOP_FREQUENCY, 0,
                                          hopFrequency), 3, "FSK Hop Frequency");

    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_FSK_INTERNAL_RATE, 0,
                                          rate), 4, "FSK Internal Rate");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureFSKExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external FSK modulation source
 *           to a channel. The attribute is the hop frequency.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureFSKExternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 hopFrequency)
{
    return Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FSK_HOP_FREQUENCY,
                                        IVI_VAL_DIRECT_USER_CALL, hopFrequency);
}


/*****************************************************************************
 * Function: tkafg1k_ConfigureASKEnabled
 * Purpose:  This function configures whether the function generator applies
 *           ASK modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureASKEnabled ( ViSession vi,
                                                ViConstString channelName,
                                                ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_ASK_ENABLED,
                                        IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureASKSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when ASK modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureASKSource (  ViSession vi,
                                                ViConstString channelName,
                                                ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ASK_SOURCE,
                                        IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureASKInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal ASK modulation source
 *           to a channel. These attributes are the amplitude and
 *           internal rate.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureASKInternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 amplitude,
                                                         ViReal64 rate)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_ASK_AMPLITUDE, 0,
                                          amplitude), 3, "ASK Amplitude");

    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_ASK_INTERNAL_RATE, 0,
                                          rate), 4, "ASK Internal Rate");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigureASKExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external ASK modulation source
 *           to a channel. The attribute is the amplitude.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigureASKExternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 amplitude)
{
    return Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_ASK_AMPLITUDE,
                                        IVI_VAL_DIRECT_USER_CALL, amplitude);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePSKEnabled
 * Purpose:  This function configures whether the function generator applies
 *           PSK modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePSKEnabled ( ViSession vi,
                                                ViConstString channelName,
                                                ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PSK_ENABLED,
                                        IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePSKSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when PSK modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePSKSource (  ViSession vi,
                                                ViConstString channelName,
                                                ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_PSK_SOURCE,
                                        IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePSKInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal PSK modulation source
 *           to a channel. These attributes are the deviation and
 *           internal rate.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePSKInternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 deviation,
                                                         ViReal64 rate)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_PSK_DEVIATION, 0,
                                          deviation), 3, "PSK Deviation");

    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                          TKAFG1K_ATTR_PSK_INTERNAL_RATE, 0,
                                          rate), 4, "PSK Internal Rate");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePSKExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external PSK modulation source
 *           to a channel. The attribute is the deviation.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePSKExternalByChannel (ViSession vi,
                                                         ViConstString channelName,
                                                         ViReal64 deviation)
{
    return Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_PSK_DEVIATION,
                                        IVI_VAL_DIRECT_USER_CALL, deviation);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePWMEnabled
 * Purpose:  This function configures whether the function generator applies
 *           PWM modulation to a channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePWMEnabled ( ViSession vi,
                                                ViConstString channelName,
                                                ViBoolean enabled)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PWM_ENABLED,
                                        IVI_VAL_DIRECT_USER_CALL, enabled);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePWMSource
 * Purpose:  This function specifies the source of the modulating signal the
 *           function generator uses for the channel when PWM modulation
 *           is enabled.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePWMSource (ViSession vi,
                                              ViConstString channelName,
                                              ViInt32 source)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_PWM_SOURCE,
                                        IVI_VAL_DIRECT_USER_CALL, source);
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePWMInternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's internal PWM source
 *           to a channel. These attributes are the peak deviation, waveform,
 *           and frequency.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePWMInternalByChannel (   ViSession vi,
                                                            ViConstString channelName,
                                                            ViReal64 pwmDeviation,
                                                            ViInt32 pwmWaveform,
                                                            ViReal64 pwmFrequency)
{
    ViStatus    error = VI_SUCCESS;

    checkErr( Ivi_LockSession (vi, VI_NULL));

        /* Set attributes */
    viCheckParm( Ivi_SetAttributeViInt32 (vi, channelName,
                                          TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM, 0,
                                          pwmWaveform), 4, "PWM Waveform");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                           TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY, 0,
                                           pwmFrequency), 5, "PWM Frequency");
    viCheckParm( Ivi_SetAttributeViReal64 (vi, channelName,
                                            TKAFG1K_ATTR_PWM_DEVIATION, 0,
                                            pwmDeviation), 3, "PWM Peak Deviance");

    checkErr( tkafg1k_CheckStatus (vi));

Error:
    Ivi_UnlockSession (vi, VI_NULL);
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_ConfigurePWMExternalByChannel
 * Purpose:  This function configures the attributes that control the
 *           function generator's external PWM source to a channel. The
 *           attribute is the peak deviation.
 *
 *           Notes:
 *           This function is based on channel.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_ConfigurePWMExternalByChannel (   ViSession vi,
                                                            ViConstString channelName,
                                                            ViReal64 pwmDeviation)
{
    return Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_PWM_DEVIATION,
                                        IVI_VAL_DIRECT_USER_CALL, pwmDeviation);
}

/*****************************************************************************
 * Function: tkafg1k_GetAttribute<type> Functions
 * Purpose:  These functions enable the instrument driver user to get
 *           attribute values directly.  There are typesafe versions for
 *           ViInt32, ViReal64, ViString, ViBoolean, and ViSession attributes.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_GetAttributeViInt32 (ViSession vi, ViConstString channelName,
                                                ViAttr attributeId, ViInt32 *value)
{
    return Ivi_GetAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                    value);
}
ViStatus _VI_FUNC tkafg1k_GetAttributeViReal64 (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViReal64 *value)
{
    return Ivi_GetAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     value);
}
ViStatus _VI_FUNC tkafg1k_GetAttributeViString (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViInt32 bufSize,
                                                 ViChar value[])
{
    return Ivi_GetAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     bufSize, value);
}
ViStatus _VI_FUNC tkafg1k_GetAttributeViBoolean (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViBoolean *value)
{
    return Ivi_GetAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}
ViStatus _VI_FUNC tkafg1k_GetAttributeViSession (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViSession *value)
{
    return Ivi_GetAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}

/*****************************************************************************
 * Function: tkafg1k_SetAttribute<type> Functions
 * Purpose:  These functions enable the instrument driver user to set
 *           attribute values directly.  There are typesafe versions for
 *           ViInt32, ViReal64, ViString, ViBoolean, and ViSession datatypes.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_SetAttributeViInt32 (ViSession vi, ViConstString channelName,
                                                ViAttr attributeId, ViInt32 value)
{
    return Ivi_SetAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                    value);
}
ViStatus _VI_FUNC tkafg1k_SetAttributeViReal64 (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViReal64 value)
{
    return Ivi_SetAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     value);
}
ViStatus _VI_FUNC tkafg1k_SetAttributeViString (ViSession vi, ViConstString channelName,
                                                 ViAttr attributeId, ViConstString value)
{
    return Ivi_SetAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                     value);
}
ViStatus _VI_FUNC tkafg1k_SetAttributeViBoolean (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViBoolean value)
{
    return Ivi_SetAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}
ViStatus _VI_FUNC tkafg1k_SetAttributeViSession (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViSession value)
{
    return Ivi_SetAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}

/*****************************************************************************
 * Function: tkafg1k_CheckAttribute<type> Functions
 * Purpose:  These functions enable the instrument driver user to check
 *           attribute values directly.  These functions check the value you
 *           specify even if you set the TKAFG1K_ATTR_RANGE_CHECK
 *           attribute to VI_FALSE.  There are typesafe versions for ViInt32,
 *           ViReal64, ViString, ViBoolean, and ViSession datatypes.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_CheckAttributeViInt32 (ViSession vi, ViConstString channelName,
                                                  ViAttr attributeId, ViInt32 value)
{
    return Ivi_CheckAttributeViInt32 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                      value);
}
ViStatus _VI_FUNC tkafg1k_CheckAttributeViReal64 (ViSession vi, ViConstString channelName,
                                                   ViAttr attributeId, ViReal64 value)
{
    return Ivi_CheckAttributeViReal64 (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                       value);
}
ViStatus _VI_FUNC tkafg1k_CheckAttributeViString (ViSession vi, ViConstString channelName,
                                                   ViAttr attributeId, ViConstString value)
{
    return Ivi_CheckAttributeViString (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                       value);
}
ViStatus _VI_FUNC tkafg1k_CheckAttributeViBoolean (ViSession vi, ViConstString channelName,
                                                    ViAttr attributeId, ViBoolean value)
{
    return Ivi_CheckAttributeViBoolean (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                        value);
}
ViStatus _VI_FUNC tkafg1k_CheckAttributeViSession (ViSession vi, ViConstString channelName,
                                                    ViAttr attributeId, ViSession value)
{
    return Ivi_CheckAttributeViSession (vi, channelName, attributeId, IVI_VAL_DIRECT_USER_CALL,
                                        value);
}

/*****************************************************************************
 * Function: viWrite and viRead Functions
 * Purpose:  These functions enable the instrument driver user to
 *           write and read commands directly to and from the instrument.
 * 
 *           Notes: 1) These functions bypass the IVI attribute state caching.  
 *                  viWrite invalidates the cached values for all
 *                  attributes.
 *                  2) These functions are supported with the IVI Compliance
 *                  Package (ICP) 4.6.1 and later. If you are using an
 *                  earlier version of ICP, you can still use the <prefix>_WriteInstrData
 *                  and <prefix>_ReadInstrData functions under the Obsolete folder.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_viWrite (ViSession vi, ViByte buffer[], ViInt64 count, ViInt64 *returnCount)
{
    return Ivi_viWrite (vi, buffer, count, returnCount);
}
ViStatus _VI_FUNC tkafg1k_viRead (ViSession vi, ViInt64 bufferSize, ViByte buffer[], ViInt64 *returnCount)
{
    return Ivi_viRead (vi, bufferSize, buffer, returnCount);
}

/*****************************************************************************
 * Function: WriteInstrData and ReadInstrData Functions
 * Purpose:  These functions enable the instrument driver user to
 *           write and read commands directly to and from the instrument.
 *
 *           Notes: 1) These functions bypass the IVI attribute state caching.
 *                  WriteInstrData invalidates the cached values for all
 *                  attributes.
 *                  2) These functions are obsolete since IVI Compliance
 *                  Package (ICP) 4.6.1. You can use tkafg1k_viWrite
 *                  and tkafg1k_viRead instead.
 *****************************************************************************/
ViStatus _VI_FUNC tkafg1k_WriteInstrData (ViSession vi, ViConstString writeBuffer)
{
    return Ivi_WriteInstrData (vi, writeBuffer);
}
ViStatus _VI_FUNC tkafg1k_ReadInstrData (ViSession vi, ViInt32 numBytes,
                                          ViChar rdBuf[], ViInt32 *bytesRead)
{
    return Ivi_ReadInstrData (vi, numBytes, rdBuf, bytesRead);
}

/*****************************************************************************
 *-------------------- Utility Functions (Not Exported) ---------------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: tkafg1k_QueryOperationMode
 * Purpose:  This utility function query current operation mode(run mode) of the
 *           instrument. The instrument could be in run mode of continuous,
 *           modulation, sweep, burst.
 *****************************************************************************/
static ViStatus tkafg1k_QueryOperationMode (ViSession vi, ViSession io, ViConstString channelName, ViInt32* operationMode)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViInt32     burst;
    ViBoolean   modulation;
    memset(rdBuffer, 0, sizeof(ViChar)*BUFFER_SIZE);

    /*- Check if run mode is sweep -*/
    viCheckErr ( viQueryf (io, "SOUR%s:FREQ:MODE?", "%s", channelName, rdBuffer) );
    if( !CompareStrings(rdBuffer, 0, "SWE", 0, 0) )
    {
        *operationMode = TKAFG1K_VAL_OPERATE_SWEEP;
        return error;
    }

    /*- Check if run mode is burst -*/
    viCheckErr ( viQueryf (io, "SOUR%s:BURS:STAT?", "%d", channelName, &burst) );
    if(burst != 0)
    {
        *operationMode = TKAFG1K_VAL_OPERATE_BURST;
        return error;
    }

    /*- Check if run mode is modulation -*/
        /*- Check if AM Enabled -*/
    checkErr ( tkafg1k_GetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_AM_ENABLED, &modulation) );
    if( modulation == VI_TRUE )
    {
        *operationMode = TKAFG1K_VAL_OPERATE_MODULATION;
        return error;
    }

        /*- Check if FM Enabled -*/
    checkErr ( tkafg1k_GetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_FM_ENABLED, &modulation) );
    if( modulation == VI_TRUE)
    {
        *operationMode = TKAFG1K_VAL_OPERATE_MODULATION;
        return error;
    }

        /*- Check if FSK Enabled -*/
    checkErr ( tkafg1k_GetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_FSK_ENABLED, &modulation) );
    if( modulation == VI_TRUE)
    {
        *operationMode = TKAFG1K_VAL_OPERATE_MODULATION;
        return error;
    }

        /*- Check if PM Enabled -*/
    checkErr ( tkafg1k_GetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PM_ENABLED, &modulation) );
    if( modulation == VI_TRUE)
    {
        *operationMode = TKAFG1K_VAL_OPERATE_MODULATION;
        return error;
    }

        /*- Check if PWM Enabled -*/
    checkErr ( tkafg1k_GetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PWM_ENABLED, &modulation) );
    if( modulation == VI_TRUE)
    {
        *operationMode = TKAFG1K_VAL_OPERATE_MODULATION;
        return error;
    }

    /*- Set operation mode to continuous if all modulation is disabled -*/
   *operationMode = TKAFG1K_VAL_OPERATE_CONTINUOUS;

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyOutputMode
 * Purpose:  This utility function verifies that the instrument is currently
 *           in a specific output mode.  If the instrument is not in the
 *           correct output mode, the function returns the
 *           IVI_ERROR_INVALID_CONFIGURATION error.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyOutputMode(ViSession vi, ViInt32 outputMode)
{
    ViStatus error = VI_SUCCESS;

    ViInt32  actualMode;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, &actualMode) );

    if (outputMode != actualMode)
    {
        ViInt32 actualElab = 0;
        ViChar   errElab[BUFFER_SIZE];
        ViString errMode[2] = { "Standard Waveform", "Arbitrary Waveform" };

        switch (outputMode)
        {
            case TKAFG1K_VAL_OUTPUT_FUNC:
                actualElab = 0;
                break;
            case TKAFG1K_VAL_OUTPUT_ARB:
                actualElab = 1;
                break;
        }

        sprintf(errElab, "The instrument must be in the %s mode.", errMode[actualElab]);
        viCheckErrElab( IVI_ERROR_INVALID_CONFIGURATION, errElab);
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyOutputModeByChannel
 * Purpose:  This utility function verifies that the specified channel of the
 *           instrument is currently in a specific output mode.  If the channel
 *           is not in the correct output mode, the function returns the
 *           IVI_ERROR_INVALID_CONFIGURATION error.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyOutputModeByChannel   (ViSession vi, ViConstString channelName, ViInt32 outputMode)
{
    ViStatus error = VI_SUCCESS;

    ViInt32  actualMode;

    checkErr( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, &actualMode) );

    if (outputMode != actualMode)
    {
        ViInt32 actualElab = 0;
        ViChar   errElab[BUFFER_SIZE];
        ViString errMode[2] = { "Standard Waveform", "Arbitrary Waveform" };

        switch (outputMode)
        {
            case TKAFG1K_VAL_OUTPUT_FUNC:
                actualElab = 0;
                break;
            case TKAFG1K_VAL_OUTPUT_ARB:
                actualElab = 1;
                break;
        }

        sprintf(errElab, "The instrument must be in the %s mode.", errMode[actualElab]);
        viCheckErrElab( IVI_ERROR_INVALID_CONFIGURATION, errElab);
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_CreateNewWaveform
 * Purpose:  This function creates an arbitrary waveform using the passed
 *           waveform handle.
 *****************************************************************************/
static ViStatus tkafg1k_CreateNewWaveform (ViSession vi, ViSession io, ViInt32 wfmSize,
                                              ViReal64 wfmData[], ViInt32 wfmHandle )
{
    ViStatus          error = VI_SUCCESS;
    ViInt16           *binData=VI_NULL;
    ViInt32           i;
	ViInt32           activeMem;
	IviRangeTablePtr  table;
	ViString          memoryName;
	
	checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, 0, &activeMem) );
	checkErr( Ivi_GetAttrRangeTable (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, &table) );
	checkErr( tkafg1k_GetCmdFromIntValue(activeMem, table, &memoryName) ); 
	
    checkErr( Ivi_Alloc (vi, ((ViInt32)sizeof(ViInt16))*(wfmSize), (ViAddr *)(&binData)));

    for (i = 0; i < wfmSize; i++)
         binData[i] = (ViInt16) (0x1FFF*(wfmData[i]+1.0));

    viCheckErr( viPrintf (io, "DATA:DEF %s,%d", memoryName, wfmSize) );         /* Define the point number in edit memory */
    viCheckErr( viPrintf (io, "DATA:DATA %s,%*hb;", memoryName, wfmSize, binData));       /* Pass data to the edit memory */

	/* Copy data from edit memory to specified waveform. In this case, if memoryName = Edit Memory, then it is the same as Edit Memory 1  */ 
	viCheckErr ( viPrintf (io, "DATA:COPY USER%d,%s",wfmHandle, memoryName) );
    

Error:
    if (binData)
        Ivi_Free (vi, binData);
    return error;
}


/*****************************************************************************
 * Function: tkafg1k_CreateNewStandardShapeWaveform
 * Purpose:  This function creates an new standard shape arbitrary waveform
 *           using the passed waveform handle, waveform size and waveform
 *           type.
 *****************************************************************************/
static ViStatus tkafg1k_CreateNewStandardShapeWaveform (ViSession vi, ViSession io, ViInt32 wfmSize, ViInt32 wfmType,
                                                        ViInt32 wfmHandle)
{
    ViStatus error = VI_SUCCESS;
    ViChar waveName[BUFFER_SIZE], waveHandle[BUFFER_SIZE];
	ViInt32 activeMem;
	IviRangeTablePtr table;
	ViString memoryName;
    memset (waveName, 0, sizeof(ViChar)*BUFFER_SIZE);
    memset (waveHandle, 0, sizeof(ViChar)*BUFFER_SIZE);
	
	checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, 0, &activeMem) );
	checkErr( Ivi_GetAttrRangeTable (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, &table) );
	checkErr( tkafg1k_GetCmdFromIntValue(activeMem, table, &memoryName) );

    viCheckErr ( viPrintf (io, "DATA:DEF %s,%d", memoryName, wfmSize) );                  /* Define the point number in edit memory */
    switch(wfmType)
    {
        case TKAFG1K_VAL_ARB_WFM_SINE:
        {
            strncpy(waveName, "SIN", BUFFER_SIZE);
            break;
        }
        case TKAFG1K_VAL_ARB_WFM_SQUARE:
        {
            strncpy(waveName, "SQU", BUFFER_SIZE);
            break;
        }
        case TKAFG1K_VAL_ARB_WFM_PULS:
        {
            strncpy(waveName, "PULS", BUFFER_SIZE);
            break;
        }
        case TKAFG1K_VAL_ARB_WFM_RAMP:
        {
            strncpy(waveName, "RAMP", BUFFER_SIZE);
            break;
        }
        case TKAFG1K_VAL_ARB_WFM_PRN:
        {
            strncpy(waveName, "NOIS", BUFFER_SIZE);
            break;
        }
        default:
        {
            error = IVI_ERROR_INVALID_PARAMETER;
            viCheckErr (error);
        }
    }
    viCheckErr ( viPrintf (io, "DATA:DEF %s,%s", memoryName, waveName) );


    viCheckErr ( viPrintf (io, "DATA:COPY USER%d,%s", waveHandle, memoryName) );

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_CreateArbRecords
 * Purpose:  This utility function creates new array of waveform
 *           structures and assigns pointers to the arrays to the hidden
 *           attributes TKAFG1K_ATTR_WFM_STRUCTURE.  This function is
 *           called from the tkafg1k_InitAttributes function as
 *           part of the initialization of the driver.
 *****************************************************************************/
static ViStatus tkafg1k_CreateArbRecords (ViSession vi)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 maxNumWfms;
    wfmNodePtr newWfmStruct = VI_NULL;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS,
                                       0, &maxNumWfms));

    checkErr( Ivi_Alloc (vi, ((ViInt32)sizeof(wfmNode))*maxNumWfms,  (ViAddr *)(&newWfmStruct)));

    checkErr( Ivi_SetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      0, (ViAddr)newWfmStruct));

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_GetNumDefinedWaveforms
 * Purpose:  This utility function returns the number of arbitrary waveforms
 *           the user has created.
 *****************************************************************************/
static ViStatus tkafg1k_GetNumDefinedWaveforms (ViSession vi, ViInt32 *numWfms)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  maxNumWfms, tmpNumWfms = 0;
    ViInt16  i;

    wfmNodePtr wfmStruct = VI_NULL;

    checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      0, (ViAddr *)(&wfmStruct)));
    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS,
                                       0, &maxNumWfms));

    /* Determine the current number of defined waveforms */
    for (i = 0; i < maxNumWfms; i++)
    {
        if (wfmStruct[i].wfmSize)
            tmpNumWfms++;
    }

Error:
    if (error < VI_SUCCESS)
        *numWfms = 0;
    else
        *numWfms = tmpNumWfms;
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyWfmCreatable
 * Purpose:  This utility function verifies that a user-specified waveform is
 *           of valid size, that the data in the waveform is valid, and that
 *           there is memory available for the new waveform.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyWfmCreatable (ViSession vi, ViInt32 wfmSize,
                                             ViReal64 wfmData[])
{
    ViStatus error = VI_SUCCESS;
    ViInt32 maxWfms, currentWfms, wfmQuantum, minWfmSize, maxWfmSize, i, compare = 0;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS, 0, &maxWfms));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, &wfmQuantum));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, &minWfmSize));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, &maxWfmSize));

    checkErr( tkafg1k_GetNumDefinedWaveforms (vi, &currentWfms));

    if (currentWfms >= maxWfms)
        viCheckErrElab( TKAFG1K_ERROR_NO_WFMS_AVAILABLE,
                                    "There are no free waveform structure to create new waveform.");

    if ((wfmSize < minWfmSize) || (wfmSize > maxWfmSize) || (wfmSize % wfmQuantum))
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "Invalid Waveform Length");

    for (i = 0; i < wfmSize; i++)
    {
        viCheckErr( Ivi_CompareWithPrecision(4, fabs(wfmData[i]), 1.0, &compare));
        if (compare > 0)
            break;
    }

    if (compare > 0)
    {
        ViChar errElab[BUFFER_SIZE];
        sprintf (errElab, "Element number %d = %.3lf of the waveform is not valid.", i, wfmData[i]);
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyWfmBySlotCreatable
 * Purpose:  This utility function verifies that a user-specified waveform is
 *           of valid size, that the data in the waveform is valid.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyWfmBySlotCreatable (ViSession vi, ViInt32 wfmSize,
                                             ViReal64 wfmData[])
{
    ViStatus error = VI_SUCCESS;
    ViInt32 wfmQuantum, minWfmSize, maxWfmSize, i, compare = 0;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, &wfmQuantum));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, &minWfmSize));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, &maxWfmSize));

    if ((wfmSize < minWfmSize) || (wfmSize > maxWfmSize) || (wfmSize % wfmQuantum))
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "Invalid Waveform Length");

    for (i = 0; i < wfmSize; i++)
    {
        viCheckErr( Ivi_CompareWithPrecision(4, fabs(wfmData[i]), 1.0, &compare));
        if (compare > 0)
            break;
    }

    if (compare > 0)
    {
        ViChar errElab[BUFFER_SIZE];
        sprintf (errElab, "Element number %d = %.3lf of the waveform is not valid.", i, wfmData[i]);
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyInterpolateWfmCreatable
 * Purpose:  This utility function verifies that a user-specified waveform is
 *           of valid size, that the data in the waveform is valid, and that
 *           there is memory available for the new waveform.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyInterpolateWfmCreatable (ViSession vi, ViInt32 wfmSize, ViReal64 startPointData,
                                                       ViReal64 endPointData)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 maxWfms, currentWfms, wfmQuantum, minWfmSize, maxWfmSize, data1Compare, data2Compare;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS, 0, &maxWfms));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, &wfmQuantum));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, &minWfmSize));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, &maxWfmSize));

    checkErr( tkafg1k_GetNumDefinedWaveforms (vi, &currentWfms));

    if (currentWfms >= maxWfms)
        viCheckErrElab( TKAFG1K_ERROR_NO_WFMS_AVAILABLE,
                                    "There are no free waveform structure to create new waveform.");

    if ((wfmSize < minWfmSize) || (wfmSize > maxWfmSize) || (wfmSize % wfmQuantum))
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "Invalid Waveform Length");

    viCheckErr( Ivi_CompareWithPrecision(4, fabs(startPointData), 1.0, &data1Compare));
    viCheckErr( Ivi_CompareWithPrecision(4, fabs(endPointData), 1.0, &data2Compare));

    if((data1Compare > 0) || (data2Compare > 0))
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr (error);
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyInterpolateWfmBySlotCreatable
 * Purpose:  This utility function verifies that a user-specified waveform is
 *           of valid size, that the data in the waveform is valid.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyInterpolateWfmBySlotCreatable (ViSession vi, ViInt32 wfmSize, ViReal64 startPointData,
                                                       ViReal64 endPointData)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 wfmQuantum, minWfmSize, maxWfmSize, data1Compare, data2Compare;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, &wfmQuantum));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, &minWfmSize));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, &maxWfmSize));

    if ((wfmSize < minWfmSize) || (wfmSize > maxWfmSize) || (wfmSize % wfmQuantum))
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "Invalid Waveform Length");

    viCheckErr( Ivi_CompareWithPrecision(4, fabs(startPointData), 1.0, &data1Compare));
    viCheckErr( Ivi_CompareWithPrecision(4, fabs(endPointData), 1.0, &data2Compare));

    if((data1Compare > 0) || (data2Compare > 0))
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr (error);
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyStandardShapeWfmCreatable
 * Purpose:  This utility function verifies that a user-specified waveform is
 *           of valid size, that the data in the waveform is valid, and that
 *           there is memory available for the new waveform.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyStandardShapeWfmCreatable (ViSession vi, ViInt32 wfmSize, ViInt32 wfmType)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 maxWfms, currentWfms, wfmQuantum, minWfmSize, maxWfmSize;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS, 0, &maxWfms));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, &wfmQuantum));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, &minWfmSize));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, &maxWfmSize));

    checkErr( tkafg1k_GetNumDefinedWaveforms (vi, &currentWfms));

    if (currentWfms >= maxWfms)
        viCheckErrElab( TKAFG1K_ERROR_NO_WFMS_AVAILABLE,
                                    "There are no free waveform structure to create new waveform.");

    if ((wfmSize < minWfmSize) || (wfmSize > maxWfmSize) || (wfmSize % wfmQuantum))
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "Invalid Waveform Length");

    if((wfmType < TKAFG1K_VAL_ARB_WFM_SINE) || (wfmType > TKAFG1K_VAL_ARB_WFM_PRN))
    {
        error = IVI_ERROR_INVALID_PARAMETER;
        viCheckParm (error, 3, "Waveform Type");
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyStandardShapeWfmBySlotCreatable
 * Purpose:  This utility function verifies that a user-specified waveform is
 *           of valid size, that the data in the waveform is valid.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyStandardShapeWfmBySlotCreatable (ViSession vi, ViInt32 wfmSize, ViInt32 wfmType)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 wfmQuantum, minWfmSize, maxWfmSize;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_WAVEFORM_QUANTUM, 0, &wfmQuantum));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE, 0, &minWfmSize));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE, 0, &maxWfmSize));

    if ((wfmSize < minWfmSize) || (wfmSize > maxWfmSize) || (wfmSize % wfmQuantum))
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "Invalid Waveform Length");

    if((wfmType < TKAFG1K_VAL_ARB_WFM_SINE) || (wfmType > TKAFG1K_VAL_ARB_WFM_PRN))
    {
        error = IVI_ERROR_INVALID_PARAMETER;
        viCheckParm (error, 3, "Waveform Type");
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_VerifyWfmHandle
 * Purpose:  This utility function determines if passed waveform handle is
 *           valid.
 *****************************************************************************/
static ViStatus tkafg1k_VerifyWfmHandle (ViSession vi, ViInt32 wfmHandle)
{
    ViStatus   error = VI_SUCCESS;
	ViInt32 model;
	checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model));
	if (model == TKAFG1K_VAL_MODEL_AFG1022)
	{
	    if( (wfmHandle < 0) || (wfmHandle > 255) )
	    {
	            error = IVI_ERROR_INVALID_VALUE;
	            viCheckErr (error);
	    }
	}else if (model == TKAFG1K_VAL_MODEL_AFG1022)
	{
	    if( (wfmHandle < 0) || (wfmHandle > 255) )
	    {
	            error = IVI_ERROR_INVALID_VALUE;
	            viCheckErr (error);
	    }
	}else{
		checkErr(TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL);
	}
Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_GetNewWfmInfo
 * Purpose:  This utility function determines the handle for a new waveform
 *           from the number of current user-defined waveforms.
 *****************************************************************************/
static ViStatus tkafg1k_GetNewWfmInfo (ViSession vi, ViInt32 *wfmHandle)
{
    ViStatus   error = VI_SUCCESS;
    ViInt32    tmpHandle = 0, maxWfms, i;
    wfmNodePtr wfmRecord = VI_NULL;

    checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE, 0, (ViAddr *)&wfmRecord));

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS, 0, &maxWfms));

    for (i = 0; i < maxWfms; i++)
    {
        if (!(wfmRecord[i].wfmSize))
        {
            tmpHandle = i;
            break;
        }
    }

Error:
    *wfmHandle = tmpHandle;
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_UpdateDriverWfmRecord
 * Purpose:  This utility function updates an element of an existing waveform
 *           data structure to reflect a newly created waveform.
 *****************************************************************************/
static ViStatus tkafg1k_UpdateDriverWfmRecord (ViSession vi, ViInt32 wfmHandle, ViInt32 wfmSize)
{
    ViStatus   error = VI_SUCCESS;
    ViInt32    index;
    wfmNodePtr wfmRecord = VI_NULL;

    checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      0, (ViAddr *)&wfmRecord));
    index = wfmHandle;
    wfmRecord[index].wfmSize = wfmSize;

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_WfmExists
 * Purpose:  This utilitiy function checks whether a waveform exists.
 *****************************************************************************/
static ViStatus tkafg1k_WfmExists (ViSession vi, ViInt32 wfmHandle, ViBoolean *wfmExists)
{
    ViStatus   error = VI_SUCCESS;
    ViInt32    index, maxWfms;
    wfmNodePtr wfmRecord = VI_NULL;

    checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      0, (ViAddr *)&wfmRecord));
    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS,
                                       0, &maxWfms));

    if ((wfmHandle > (TKAFG1K_VAL_LAST_WAVEFORM_HANDLE)) ||
                                (wfmHandle < (TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE)))
    {
        if(wfmHandle == TKAFG1K_VAL_WFM_EMEM)
        {
            *wfmExists = VI_TRUE;
        }
        else
        {
            *wfmExists = VI_FALSE;
        }
    }
    else
    {
        index =  wfmHandle;
        *wfmExists = wfmRecord[index].wfmSize != 0;
    }

Error:
    if (error < VI_SUCCESS)
    {
        *wfmExists = VI_FALSE;
    }
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_GetWfmSize
 * Purpose:  This utilitiy function return the size of a waveform.
 *****************************************************************************/
static ViStatus tkafg1k_GetWfmSize (ViSession vi, ViSession io, ViInt32 wfmHandle, ViInt32* wfmSize)
{
    ViStatus   error = VI_SUCCESS;
    ViBoolean wfmExists;
    ViInt32 index;
    wfmNodePtr wfmRecord = VI_NULL;
	ViInt32           activeMem;
	IviRangeTablePtr  table;
	ViString          memoryName;
	
	checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, 0, &activeMem) );
	checkErr( Ivi_GetAttrRangeTable (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, &table) );
	checkErr( tkafg1k_GetCmdFromIntValue(activeMem, table, &memoryName) );

    checkErr( tkafg1k_WfmExists(vi, wfmHandle, &wfmExists) );
    if (!wfmExists)
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, "The waveform does not exist.");

    if(wfmHandle == TKAFG1K_VAL_WFM_EMEM)
    {
        if (!Ivi_Simulating (vi)) {
            viCheckErr ( viQueryf (io, "DATA:POIN? %s", "%d", memoryName, wfmSize) );
        } else {
            ViInt32 model;
            checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model));
            switch (model) {
                case TKAFG1K_VAL_MODEL_AFG1022:
                    *wfmSize = AFG1022_VAL_MAX_WFM_SIZE;
                    break;
				case TKAFG1K_VAL_MODEL_AFG1062:
                    *wfmSize = AFG1062_VAL_MAX_WFM_SIZE;
                    break;
                default:
                    break;
            }
        }
    }
    else
    {
        checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE, 0, (ViAddr *)&wfmRecord) );

        index =  wfmHandle;
        *wfmSize = wfmRecord[index].wfmSize;
    }
Error:
    return error;
}




/*****************************************************************************
 * Function: tkafg1k_ClearDriverWfmRecord
 * Purpose:  This utility function clears the data in an existing waveform
 *           data structure.  If the waveform's handle parameter is
 *           TKAFG1K_VAL_ALL_WAVEFORMS, the function clears the
 *           data in all waveform data structures for the session.
 *****************************************************************************/
static ViStatus tkafg1k_ClearDriverWfmRecord (ViSession vi, ViInt32 wfmHandle)
{
    ViStatus   error = VI_SUCCESS;
    ViInt32    index, maxWfms;
    wfmNodePtr wfmRecord = VI_NULL;

    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS,
                                       0, &maxWfms));
    checkErr( Ivi_GetAttributeViAddr (vi, VI_NULL, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      0, (ViAddr *)&wfmRecord));

    if (wfmHandle == TKAFG1K_VAL_ALL_WAVEFORMS)
    {
        memset (wfmRecord, 0, (sizeof(wfmNode)*maxWfms));
    }
    else
    {
        index = wfmHandle;
        wfmRecord[index].wfmSize = 0;
        wfmRecord[index].wfmName[0] = '\0';
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_CheckStatus
 * Purpose:  This function checks the status of the instrument to detect
 *           whether the instrument has encountered an error.  This function
 *           is called at the end of most exported driver functions.  If the
 *           instrument reports an error, this function returns
 *           IVI_ERROR_INSTRUMENT_SPECIFIC.  The user can set the
 *           TKAFG1K_ATTR_QUERY_INSTRUMENT_STATUS attribute to VI_FALSE to disable this
 *           check and increase execution speed.
 *
 *           Note:  Call this function only when the session is locked.
 *****************************************************************************/
static ViStatus tkafg1k_CheckStatus (ViSession vi)
{
    ViStatus    error = VI_SUCCESS;

    if (Ivi_QueryInstrStatus (vi) && Ivi_NeedToCheckStatus (vi) && !Ivi_Simulating (vi))
    {
        checkErr( tkafg1k_CheckStatusCallback (vi, Ivi_IOSession(vi)));
        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_FALSE));
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: tkafg1k_DefaultInstrSetup
 * Purpose:  This function sends a default setup to the instrument.  The
 *           tkafg1k_reset function calls this function.  The
 *           tkafg1k_IviInit function calls this function when the
 *           user passes VI_FALSE for the reset parameter.  This function is
 *           useful for configuring settings that other instrument driver
 *           functions require.
 *****************************************************************************/
static ViStatus tkafg1k_DefaultInstrSetup (ViSession vi)
{
    ViStatus    error = VI_SUCCESS;
    ViChar    driverSetup[BUFFER_SIZE];
    ViString  matchPtr = VI_NULL;
    ViBoolean clearArbData = VI_FALSE;
	ViInt32           activeMem;
	IviRangeTablePtr  table;
	ViString          memoryName;
	
	checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, 0, &activeMem) );
	checkErr( Ivi_GetAttrRangeTable (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, &table) );
	checkErr( tkafg1k_GetCmdFromIntValue(activeMem, table, &memoryName) );

    /* Invalidate all attributes */
    checkErr( Ivi_InvalidateAllAttributes (vi));

    /* Check if clear all arbitrary waveforms */
    checkErr( Ivi_GetAttributeViString (vi, VI_NULL, TKAFG1K_ATTR_DRIVER_SETUP,
                                        0, BUFFER_SIZE, driverSetup));

    matchPtr = strstr (driverSetup, "ClearArbData");
    if (matchPtr)
    {
        sscanf (matchPtr, "ClearArbData is %hd", &clearArbData);
    }

    if (!clearArbData)
    {
        checkErr( tkafg1k_ClearDriverWfmRecord (vi, TKAFG1K_VAL_ALL_WAVEFORMS));

        if (!Ivi_Simulating(vi))
        {
            ViSession   io = Ivi_IOSession(vi);
            ViChar      catalog[BUFFER_SIZE], name[TKAFG1K_VAL_NAME_LENGTH];
            ViInt32     index = 0, size, handle, scanCnt;
            memset( catalog, 0, sizeof(ViChar)*BUFFER_SIZE );

            checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

            /* clear instrument */
            viCheckErr( viPrintf (io, "*CLS;"));

            /* retrieve all existing arbitrary waveforms */
			
			Delay(1);
            viCheckErr( viQueryf (io, "DATA:CAT?","%s",catalog ));
			//	viCheckErr( viRead (io, (ViPBuf)catalog, BUFFER_SIZE-1, &scanCnt));
            /* update the driver's waveform record to reflect sizes of existing waveforms */
            scanCnt = 1;
            while(scanCnt)
            {
                scanCnt = sscanf (catalog, "%*[,\"]%[^\"]%s", name, catalog);
                if (scanCnt <= 0)
                    break;
                if(strncmp(name, "USER1", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    index = 0;
                }
                else if(strncmp(name, "USER2", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    index = 1;
                }
                else if(strncmp(name, "USER3", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    index = 2;
                }
                else if(strncmp(name, "USER4", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    index = 3;
                }
				else if(strncmp(name, "EMEM", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    continue;
                }
				else if(strncmp(name, "EMEM1", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    continue;
                }
				else if(strncmp(name, "EMEM2", TKAFG1K_VAL_NAME_LENGTH) == 0)
                {
                    continue;
                }
                else
                {
                    error = TKAFG1K_ERROR_UNKNOWN_ARB_WFM;
                    viCheckErr (error);
                }

                viCheckErr ( viPrintf (io, "DATA:COPY %s,%s", memoryName, name) );
                viCheckErr ( viQueryf (io, "DATA:POIN? %s", "%d", memoryName, &size) );

                handle = index;
                checkErr( tkafg1k_UpdateDriverWfmRecord (vi, handle, size));
            }
        }
    }


    checkErr( tkafg1k_CheckStatus (vi));
    if (!Ivi_Simulating(vi))
    {
        ViSession   io = Ivi_IOSession(vi); /* call only when locked */

        checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));

        viCheckErr( viPrintf (io, "*CLS;"));
    }

Error:
    if(error == TKAFG1K_ERROR_UNKNOWN_ARB_WFM)
    {
        checkErr( tkafg1k_ClearDriverWfmRecord (vi, TKAFG1K_VAL_ALL_WAVEFORMS));
        error = TKAFG1K_ERROR_INIT_FAIL;
    }

    return error;
}



/*****************************************************************************
 * Function: tkafg1k_SetGetWaveformPointValue
 * Purpose: This function sets or gets waveform point value.
 *
 *****************************************************************************/
ViStatus _VI_FUNC   tkafg1k_SetGetWaveformPointValue (ViSession vi, 
		                                              ViInt32 pointIndex,
													  ViInt32 pointValue,
													  ViInt32 operationSelect,
													  ViInt32 editMemory,
													  ViInt32 *queryValue)
{
    ViStatus          error = VI_SUCCESS;
    ViInt32           model;
	ViString          memoryName;
	IviRangeTablePtr  table;

    checkErr( Ivi_LockSession (vi, VI_NULL)); 
    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );
	checkErr( Ivi_GetAttrRangeTable (vi, VI_NULL, TKAFG1K_ATTR_ACTIVE_MEMORY, &table) );
	checkErr( tkafg1k_GetCmdFromIntValue(editMemory, table, &memoryName) );
	
    if (!Ivi_Simulating(vi))                /* call only when locked */
	{
		ViSession   io = Ivi_IOSession(vi); /* call only when locked */

		checkErr( Ivi_SetNeedToCheckStatus (vi, VI_TRUE));
		switch(operationSelect)
		{
			case TKAFG1K_VAL_WFM_SETPOINT:
			{
				viCheckErr( viPrintf (io, "DATA:VAL %s,%d,%d", memoryName, pointIndex, pointValue));
				break;
			}
			case TKAFG1K_VAL_WFM_GETPOINT:
			{
				viCheckErr( viQueryf (io, "DATA:VAL? %s,%d", "%d", memoryName, pointIndex, queryValue));
				break;			
			}
			default:
			{
				error = IVI_ERROR_INVALID_PARAMETER;
				viCheckErr (error);
			}
		}		
	}

	checkErr( tkafg1k_CheckStatus (vi));
	
Error:
	Ivi_UnlockSession (vi, VI_NULL);
	return error;
}



/*****************************************************************************
 * Function: tkafg1k_Min
 * Purpose: Functions for instrument drivers to get the min value using the
 *          specifies digit precision.
 *****************************************************************************/
static ViStatus tkafg1k_Min (ViSession vi, ViInt32 digitsofPrecision, ViReal64 a, ViReal64 b, ViReal64 *minValue)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     compare;

    *minValue = a;

    viCheckErr (Ivi_CompareWithPrecision (digitsofPrecision, a, b, &compare));
    if (1 == compare)
        *minValue = b;

Error:
    return error;
}

    /*- I/O Operation Utility Functions -*/
/*****************************************************************************
 * Function: ReadCmd and WriteCmd Functions
 * Purpose: Functions for instrument drivers to read/write
            instrument command
 *****************************************************************************/
static ViStatus tkafg1k_WriteCmd ( ViSession vi, ViSession io, ViConstString channelName, IviRangeTablePtr rt,
                                   ViString format, ViInt32 value )
{
    ViStatus    error = VI_SUCCESS;
    ViString    cmd;

    viCheckErr ( Ivi_GetViInt32EntryFromValue (value, rt, VI_NULL,
                                             VI_NULL, VI_NULL, VI_NULL, &cmd, VI_NULL ));

    viCheckErr ( viPrintf(io, format, channelName, cmd) );

Error:
    return error;
}

static ViStatus tkafg1k_ReadCmd ( ViSession vi, ViSession io,  ViConstString channelName, IviRangeTablePtr rt,
                                  ViString format, ViInt32* value )
{
    ViStatus error = VI_SUCCESS;

    ViChar  rdBuffer[BUFFER_SIZE];
    memset(rdBuffer, 0, BUFFER_SIZE);

    viCheckErr ( viQueryf (io, format, "%s", channelName, rdBuffer) );

    viCheckErr ( Ivi_GetViInt32EntryFromString( rdBuffer, rt, value, VI_NULL, VI_NULL, VI_NULL, VI_NULL) );

Error:
    return error;
}

/*****************************************************************************
 * Function: ReadChannelIndependentCmd and WriteChannelIndependentCmd Functions
 * Purpose: Functions for instrument to read/write instrument channel
 *          independent command.
 *****************************************************************************/
static ViStatus tkafg1k_WriteChannelIndependentCmd ( ViSession vi, ViSession io, IviRangeTablePtr rt, ViString format,
                                                     ViInt32 value )
{
    ViStatus    error = VI_SUCCESS;
    ViString    cmd;

    viCheckErr ( Ivi_GetViInt32EntryFromValue (value, rt, VI_NULL,
                                             VI_NULL, VI_NULL, VI_NULL, &cmd, VI_NULL ));

    viCheckErr ( viPrintf(io, format, cmd) );

Error:
    return error;
}

static ViStatus tkafg1k_ReadChannelIndependentCmd ( ViSession vi, ViSession io, IviRangeTablePtr rt, ViString format,
                                                    ViInt32* value )
{
    ViStatus error = VI_SUCCESS;

    ViChar  rdBuffer[BUFFER_SIZE];
    memset(rdBuffer, 0, BUFFER_SIZE);

    viCheckErr ( viQueryf (io, format, "%s", rdBuffer) );

    viCheckErr ( Ivi_GetViInt32EntryFromString( rdBuffer, rt, value, VI_NULL, VI_NULL, VI_NULL, VI_NULL) );

Error:
    return error;
}

/*****************************************************************************
 * Function: ReadState and WriteState Functions
 * Purpose: Functions for instrument to read/write
            instrument state
 *****************************************************************************/
static ViStatus tkafg1k_WriteState ( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViBoolean value )
{
    ViStatus    error = VI_SUCCESS;

    viCheckErr ( viPrintf(io, format, channelName, (value? "ON" : "OFF")) );

Error:
    return error;
}

static ViStatus tkafg1k_ReadState ( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                    ViBoolean* value )
{
    ViStatus    error = VI_SUCCESS;
    ViInt32 state;

    viCheckErr ( viQueryf(io, format, "%d", channelName, &state) );

    if(state == 0)
    {
        *value = VI_FALSE;
    }
    else
    {
        *value = VI_TRUE;
    }

Error:
    return error;
}

/*****************************************************************************
 * Function: ReadReal64 and WriteReal64 Functions
 * Purpose: Functions for instrument to read/write
 *          instrument real value
 *****************************************************************************/
static ViStatus tkafg1k_WriteReal64( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViReal64 value )
{
    return ( viPrintf(io, format, channelName, value) );

}

static ViStatus tkafg1k_ReadReal64( ViSession vi, ViSession io,  ViConstString channelName, ViString format,
                                    ViReal64* value )
{
    return ( viQueryf(io, format, "%Le", channelName, value) );

}

/*****************************************************************************
 * Function: ReadChannelIndependentReal64 and WriteChannelIndependentReal64 Functions
 * Purpose: Functions for instrument to read/write channel independent
 *          instrument real value
 *****************************************************************************/
static ViStatus tkafg1k_WriteChannelIndependentReal64( ViSession vi, ViSession io, ViString format, ViReal64 value)
{
    return ( viPrintf(io, format, value) );
}

static ViStatus tkafg1k_ReadChannelIndependentReal64( ViSession vi, ViSession io, ViString format, ViReal64* value)
{
    return ( viQueryf(io, format, "%Le", value) );
}

/*****************************************************************************
 * Function: ReadInt32 and WriteInt32 Functions
 * Purpose: Functions for instrument to read/write
 *          instrument integer value
 *****************************************************************************/
static ViStatus tkafg1k_WriteInt32( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViInt32 value )
{
    return ( viPrintf(io, format, channelName, value) );
}

static ViStatus tkafg1k_ReadInt32( ViSession vi, ViSession io, ViConstString channelName, ViString format,
                                     ViInt32* value )
{
    return ( viQueryf(io, format, "%Ld", channelName, value) );
}

/*****************************************************************************
 * Function: RunModeAllowable Function
 * Purpose: Function for instrument drivers to verify whether the combination
            of specified waveform type and run mode type is allowable.
 *****************************************************************************/
static ViStatus tkafg1k_RunModeAllowable ( ViSession vi, ViInt32 waveform, ViInt32 runMode, ViBoolean* allowance )
{
    ViStatus    error = VI_SUCCESS;
    ViInt32 runModeIndex = 0,
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE1;

    switch(runMode)
    {
        case TKAFG1K_VAL_OPERATE_CONTINUOUS:
        {
             runModeIndex = 0;
             break;
        }
        case TKAFG1K_VAL_OPERATE_MODULATION:
        {
             runModeIndex = 1;
             break;
        }
        case TKAFG1K_VAL_OPERATE_SWEEP:
        {
             runModeIndex = 2;
             break;
        }
        case TKAFG1K_VAL_OPERATE_BURST:
        {
             runModeIndex = 3;
             break;
        }
        default:
        {
            error = IVI_ERROR_INVALID_PARAMETER;
            viCheckErr (error);
        }
    }

    switch(waveform)
    {
        case TKAFG1K_VAL_WFM_SINE:
        case TKAFG1K_VAL_WFM_SQUARE:
        case TKAFG1K_VAL_WFM_RAMP:
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE0;
            break;
        }
        case TKAFG1K_VAL_WFM_PULS:
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE1;
            break;
        }
        case TKAFG1K_VAL_WFM_PRN:
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE2;
            break;
        }
		case TKAFG1K_VAL_WFM_ARB:
		case TKAFG1K_VAL_WFM_USER:
        case TKAFG1K_VAL_WFM_EMEM:
		{
			wfmType = TKAFG1K_VAL_WAVEFORM_TYPE3;
			break;
		}
        default:
        {
            error = IVI_ERROR_INVALID_PARAMETER;
            viCheckErr (error);
        }
    }
    *allowance = waveformAndRunModeCombination[runModeIndex][wfmType];

Error:
    return error;
}

/*****************************************************************************
 * Function: ModulationTypeAllowable Function
 * Purpose: Function for instrument drivers to verify whether the combination
            of specified waveform type and modulation type is allowable.
 *****************************************************************************/
static ViStatus tkafg1k_ModulationTypeAllowable ( ViSession vi, ViInt32 waveform,
                                                  ViInt32 modulationType, ViBoolean* allowance )
{
    ViStatus error = VI_SUCCESS;
    ViInt32  wfmType = TKAFG1K_VAL_WAVEFORM_TYPE1;

    switch(waveform)
    {
        case TKAFG1K_VAL_WFM_SINE:
        case TKAFG1K_VAL_WFM_SQUARE:
        case TKAFG1K_VAL_WFM_RAMP:
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE0;
            break;
        }
        case TKAFG1K_VAL_WFM_PULS:
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE1;
            break;
        }
        case TKAFG1K_VAL_WFM_PRN:
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE2;
            break;
        }
		case TKAFG1K_VAL_WFM_ARB:
		case TKAFG1K_VAL_WFM_USER:
		case TKAFG1K_VAL_WFM_EMEM:	
        {
            wfmType = TKAFG1K_VAL_WAVEFORM_TYPE3;
            break;
        }
        default:
        {
            error = IVI_ERROR_INVALID_PARAMETER;
            viCheckErr (error);
        }
    }

    *allowance = waveformAndModulationCombination[modulationType][wfmType];

Error:
    return error;
}

/*****************************************************************************
 *------------------------ Global Session Callbacks -------------------------*
 *****************************************************************************/

/*****************************************************************************
 * Function: tkafg1k_CheckStatusCallback
 * Purpose:  This function queries the instrument to determine if it has
 *           encountered an error.  If the instrument has encountered an
 *           error, this function returns the IVI_ERROR_INSTRUMENT_SPECIFIC
 *           error code.  This function is called by the
 *           tkafg1k_CheckStatus utility function.  The
 *           Ivi_SetAttribute and Ivi_GetAttribute functions invoke this
 *           function when the optionFlags parameter includes the
 *           IVI_VAL_DIRECT_USER_CALL flag.
 *
 *           The user can disable calls to this function by setting the
 *           TKAFG1K_QUERY_INSTRUMENT_STATUS attribute to VI_FALSE.  The driver can
 *           disable the check status callback for a particular attribute by
 *           setting the IVI_VAL_DONT_CHECK_STATUS flag.
 *****************************************************************************/
static ViStatus _VI_FUNC tkafg1k_CheckStatusCallback (ViSession vi, ViSession io)
{
    ViStatus    error = VI_SUCCESS;

    ViInt16     esr = 0;

    viCheckErr( viQueryf (io, "*ESR?", "%hd", &esr));

    if (esr & IEEE_488_2_ERROR_MASK)
    {
        viCheckErr( IVI_ERROR_INSTR_SPECIFIC);
    }

Error:
    return error;
}

/*****************************************************************************
 *----------------- Attribute Range Tables and Callbacks --------------------*
 *****************************************************************************/

/*- TKAFG1K_ATTR_ID_QUERY_RESPONSE -*/

static ViStatus _VI_FUNC tkafg1kAttrIdQueryResponse_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViUInt32    retCnt;

    viCheckErr( viPrintf (io, "*IDN?"));
    viCheckErr( viRead (io, (ViPBuf)rdBuffer, BUFFER_SIZE-1, &retCnt));
    rdBuffer[retCnt] = 0;

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}

/*- TKAFG1K_ATTR_SPECIFIC_DRIVER_REVISION -*/

static ViStatus _VI_FUNC tkafg1kAttrDriverRevision_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      driverRevision[256];

    sprintf (driverRevision,
             "Driver: tkafg1k %d.%d, Compiler: %s %3.2f, "
             "Components: IVIEngine %.2f, VISA-Spec %.2f",
             TKAFG1K_MAJOR_VERSION, TKAFG1K_MINOR_VERSION,
             IVI_COMPILER_NAME, IVI_COMPILER_VER_NUM,
             IVI_ENGINE_MAJOR_VERSION + IVI_ENGINE_MINOR_VERSION/1000.0,
             Ivi_ConvertVISAVer(VI_SPEC_VERSION));

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, driverRevision));
Error:
    return error;
}

/*- TKAFG1K_ATTR_INSTRUMENT_FIRMWARE_REVISION -*/

static ViStatus _VI_FUNC tkafg1kAttrFirmwareRevision_ReadCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      idQ[BUFFER_SIZE], rdBuffer[BUFFER_SIZE];

    checkErr( Ivi_GetAttributeViString (vi, "", TKAFG1K_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));

    sscanf (idQ, "%*[^,],%*[^,],%*[^,],%256[^\n]", rdBuffer);

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}

/*- TKAFG1K_ATTR_INSTRUMENT_MANUFACTURER -*/

static ViStatus _VI_FUNC tkafg1kAttrInstrumentManufacturer_ReadCallback (ViSession vi,
                                                                          ViSession io,
                                                                          ViConstString channelName,
                                                                          ViAttr attributeId,
                                                                          const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViChar      idQ[BUFFER_SIZE];

    checkErr( Ivi_GetAttributeViString (vi, "", TKAFG1K_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));
    sscanf (idQ, "%256[^,]", rdBuffer);

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}

/*- TKAFG1K_ATTR_INSTRUMENT_MODEL -*/

static ViStatus _VI_FUNC tkafg1kAttrInstrumentModel_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   const ViConstString cacheValue)
{
    ViStatus    error = VI_SUCCESS;
    ViChar      rdBuffer[BUFFER_SIZE];
    ViChar      idQ[BUFFER_SIZE];

    checkErr( Ivi_GetAttributeViString (vi, "", TKAFG1K_ATTR_ID_QUERY_RESPONSE,
                                        0, BUFFER_SIZE, idQ));
    sscanf (idQ, "%*[^,],%256[^,]", rdBuffer);

    checkErr( Ivi_SetValInStringCallback (vi, attributeId, rdBuffer));

Error:
    return error;
}

/*- TKAFG1K_ATTR_OPERATION_MODE -*/

static IviRangeTableEntry attrOperationModeRangeTableEntries[] =
{
    {TKAFG1K_VAL_OPERATE_CONTINUOUS, 0, 0, "CONTINUOUS", 0},
    {TKAFG1K_VAL_OPERATE_MODULATION, 0, 0, "MODULATION", 0},
    {TKAFG1K_VAL_OPERATE_SWEEP, 0, 0, "SWEEP", 0},
    {TKAFG1K_VAL_OPERATE_BURST, 0, 0, "BURST", 0},
    {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrOperationModeRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_FALSE,
    VI_FALSE,
    VI_NULL,
    attrOperationModeRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrOperationMode_CheckCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    checkErr ( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value) );

    checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );
    checkErr ( tkafg1k_RunModeAllowable (vi, waveform, value, &allowance) );
    if(!allowance)
    {
        error = IVI_ERROR_INVALID_CONFIGURATION;
        viCheckErr (error);
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrOperationMode_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    if(value == TKAFG1K_VAL_OPERATE_CONTINUOUS)
    {
        checkErr (Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE) );
    }
    else if(value == TKAFG1K_VAL_OPERATE_MODULATION)
    {
        checkErr (Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) );
    }
	else if(value == TKAFG1K_VAL_OPERATE_SWEEP)
    {
        checkErr (Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_SWEEP_ENABLED, 0, VI_TRUE) );
    }
    else if(value == TKAFG1K_VAL_OPERATE_BURST)
    {
        checkErr (Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_BURST_ENABLED, 0, VI_TRUE) );
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrOperationMode_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViInt32 *value)
{
    ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_QueryOperationMode(vi, io, channelName, value) );

Error:
    return error;
}

/*- TKAFG1K_ATTR_CONTINUOUS_ENABLED -*/

static ViStatus _VI_FUNC tkafg1kAttrContinuousEnabled_CheckCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    /*- It is not admitted to set TKAFG1K_ATTR_CONTINUOUS_ENABLED to disabled -*/
    if(value == VI_FALSE)
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr (error);
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrContinuousEnabled_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    if(value == VI_TRUE)
    {
        viCheckErr ( viPrintf (io, "SOUR%s:FREQ:MODE CW", channelName) );
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_OUTPUT_MODE -*/
static ViStatus _VI_FUNC tkafg1kAttrOutputMode_WriteCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViInt32 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_SetAttributeViInt32(vi, CHAN1, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, value) );

    checkErr( tkafg1k_SetAttributeViInt32(vi, CHAN2, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrOutputMode_ReadCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViInt32 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 chan1Value, chan2Value;

    checkErr( tkafg1k_GetAttributeViInt32(vi, CHAN1, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, &chan1Value) );

    checkErr( tkafg1k_GetAttributeViInt32(vi, CHAN2, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, &chan2Value) );

    if(chan1Value == chan2Value)
    {
        *value = chan1Value;
    }
    else
    {
        error = TKAFG1K_ERROR_CHANNELS_DIFFERENT;
        viCheckErr(error);
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_ACTIVE_MEMORY -*/



static IviRangeTableEntry attrActiveOneMemoryRangeTableEntries[] =
	{
		{TKAFG1K_VAL_OUTPUT_EMEM, 0, 0, "EMEM", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrActiveOneMemoryRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrActiveOneMemoryRangeTableEntries,
	};

/*- TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL -*/

static IviRangeTableEntry attrOutputModeRangeTableEntries[] =
{
        {TKAFG1K_VAL_OUTPUT_FUNC, 0, 0, "FUNC", 0},
        {TKAFG1K_VAL_OUTPUT_ARB, 0, 0, "ARB", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrOutputModeRangeTable =
{
        IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrOutputModeRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrOutputModeByChannel_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 *value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;

    checkErr ( Ivi_GetAttributeViInt32(vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

    if(waveform < TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE)
    {
        *value = TKAFG1K_VAL_OUTPUT_FUNC;
    }
    else
    {
        *value = TKAFG1K_VAL_OUTPUT_ARB;
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrOutputModeByChannel_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;

    ViInt32     originalWaveform, currentWaveform, newWaveform, model;

    checkErr( Ivi_GetAttributeViInt32(vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &currentWaveform) );
    checkErr( Ivi_GetAttributeViInt32(vi, channelName, TKAFG1K_ATTR_ORIGINAL_WAVEFORM, 0, &originalWaveform) );
	checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );
	
    if (value == TKAFG1K_VAL_OUTPUT_FUNC)
    {
        newWaveform = (originalWaveform < TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE)?
                       originalWaveform : TKAFG1K_VAL_WFM_SINE;
    }
    else
    {
        ViBoolean exists = VI_FALSE;
        if((originalWaveform >= TKAFG1K_VAL_FIRST_WAVEFORM_HANDLE)
                                && (originalWaveform != TKAFG1K_VAL_WFM_EMEM ))
        {
            tkafg1k_WfmExists (vi, originalWaveform, &exists);
            if(!exists)
            {
				newWaveform = TKAFG1K_VAL_WFM_EMEM;
            }
            else
            {
                newWaveform = originalWaveform;
            }
        }
        else
        {
			newWaveform = TKAFG1K_VAL_WFM_EMEM;
        }
    }

    checkErr (Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, newWaveform) );
    checkErr( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_WAVEFORM, 0, currentWaveform));

Error:
    return error;
}

/*- TKAFG1K_ATTR_REF_CLOCK_SOURCE -*/

static IviRangeTableEntry attrRefClockSourceRangeTableEntries[] =
    {
        {TKAFG1K_VAL_REF_CLOCK_INTERNAL, 0, 0, "INT", 0},
        {TKAFG1K_VAL_REF_CLOCK_EXTERNAL, 0, 0, "EXT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };
static IviRangeTable attrRefClockSourceRangeTable =
    {
        IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrRefClockSourceRangeTableEntries,
    };



/*- TKAFG1K_ATTR_OUTPUT_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrOutputEnabled_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViBoolean value)
{
    return ( tkafg1k_WriteState(vi, io, channelName, "OUTP%s:STAT %s", value) );

}

static ViStatus _VI_FUNC tkafg1kAttrOutputEnabled_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViBoolean *value)
{
    return ( tkafg1k_ReadState(vi, io, channelName, "OUTP%s:STAT?", value) );

}

/*- TKAFG1K_ATTR_OUTPUT_IMPEDANCE -*/
static IviRangeTableEntry attrOutputImpedanceRangeTableEntries[] =
{
        {TKAFG1K_VAL_IMPEDANCE_INFINITY, TKAFG1K_VAL_IMPEDANCE_INFINITY, 0, VI_NULL, 0},
        {1.0, 10000.0, 50.0, VI_NULL, 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrOutputImpedanceRangeTable =
{
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOutputImpedanceRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrOutputImpedance_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    if( value == TKAFG1K_VAL_IMPEDANCE_INFINITY)
    {
        viCheckErr( viPrintf(io, "OUTP%s:IMP INF", channelName) );
    }
    else
    {
        checkErr( tkafg1k_WriteReal64(vi, io, channelName, "OUTP%s:IMP %Le", value) );
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrOutputImpedance_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_ReadReal64(vi, io, channelName, "OUTP%s:IMP?", value) );
    if(*value >= 9.9E+37)
    {
        *value = TKAFG1K_VAL_IMPEDANCE_INFINITY;
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_FUNC_WAVEFORM -*/

static IviRangeTableEntry attrFuncWaveformRangeTableEntries[] =
	{
		{TKAFG1K_VAL_WFM_SINE, 0, 0, "SIN", 0},
		{TKAFG1K_VAL_WFM_SQUARE, 0, 0, "SQU", 0},
		{TKAFG1K_VAL_WFM_RAMP, 0, 0, "RAMP", 0},
		{TKAFG1K_VAL_WFM_PULS, 0, 0, "PULS", 0},
		{TKAFG1K_VAL_WFM_PRN, 0, 0, "PRN", 0},
		{TKAFG1K_VAL_WFM_STAIRDOWN, 0, 0, "StairDown", 0}, 
		{TKAFG1K_VAL_WFM_STAIRUP, 0, 0, "StairUp", 0}, 
		{TKAFG1K_VAL_WFM_STAIR, 0, 0, "Stair", 0}, 
		{TKAFG1K_VAL_WFM_TRAPEZOID, 0, 0, "Trapezoid", 0}, 
		{TKAFG1K_VAL_WFM_ROUNDHALF, 0, 0, "RoundHalf", 0}, 
		{TKAFG1K_VAL_WFM_ABSSINE, 0, 0, "AbsSine", 0}, 
		{TKAFG1K_VAL_WFM_ABSHALFSINE, 0, 0, "AbsHalfSine", 0}, 
		{TKAFG1K_VAL_WFM_CLIPPEDSINE, 0, 0, "ClippedSine", 0}, 
		{TKAFG1K_VAL_WFM_CHOPPEDSINE, 0, 0, "ChoppedSine", 0}, 
		{TKAFG1K_VAL_WFM_NEGRAMP, 0, 0, "NegRamp", 0}, 
		{TKAFG1K_VAL_WFM_OSCDECAY, 0, 0, "OscDecay", 0}, 
		{TKAFG1K_VAL_WFM_OSCRISE, 0, 0, "OscRise", 0}, 
		{TKAFG1K_VAL_WFM_CODEDPULSE, 0, 0, "CodedPulse", 0}, 
		{TKAFG1K_VAL_WFM_POSPULSE, 0, 0, "PosPulse", 0}, 
		{TKAFG1K_VAL_WFM_NEGPULSE, 0, 0, "NegPulse", 0}, 
		{TKAFG1K_VAL_WFM_EXPRISE, 0, 0, "ExpRise", 0}, 
		{TKAFG1K_VAL_WFM_EXPDECAY, 0, 0, "ExpDecay", 0}, 
		{TKAFG1K_VAL_WFM_SINC, 0, 0, "Sinc", 0}, 
		{TKAFG1K_VAL_WFM_TAN, 0, 0, "Tan", 0}, 
		{TKAFG1K_VAL_WFM_COTAN, 0, 0, "Cotan", 0}, 
		{TKAFG1K_VAL_WFM_SQUAREROOT, 0, 0, "SquareRoot", 0}, 
		{TKAFG1K_VAL_WFM_X_2, 0, 0, "X^2", 0}, 
		{TKAFG1K_VAL_WFM_HAVERSINE, 0, 0, "HaverSine", 0}, 
		{TKAFG1K_VAL_WFM_LORENTZ, 0, 0, "Lorentz", 0}, 
		{TKAFG1K_VAL_WFM_LN_X, 0, 0, "Ln(x)", 0}, 
		{TKAFG1K_VAL_WFM_X_3, 0, 0, "X^3", 0}, 
		{TKAFG1K_VAL_WFM_CAUCHYDISTR, 0, 0, "CauchyDistr", 0}, 
		{TKAFG1K_VAL_WFM_BESSELJ, 0, 0, "BesselJ", 0}, 
		{TKAFG1K_VAL_WFM_BESSELY, 0, 0, "BesselY", 0}, 
		{TKAFG1K_VAL_WFM_ERRORFUNC, 0, 0, "ErrorFunc", 0}, 
		{TKAFG1K_VAL_WFM_AIRY, 0, 0, "Airy", 0}, 
		{TKAFG1K_VAL_WFM_RECTANGLE, 0, 0, "Rectangle", 0}, 
		{TKAFG1K_VAL_WFM_GAUSS, 0, 0, "Gauss", 0}, 
		{TKAFG1K_VAL_WFM_HAMMING, 0, 0, "Hamming", 0}, 
		{TKAFG1K_VAL_WFM_HANNING, 0, 0, "Hanning", 0}, 
		{TKAFG1K_VAL_WFM_BARTLETT, 0, 0, "Bartlett", 0}, 
		{TKAFG1K_VAL_WFM_BLACKMAN, 0, 0, "Blackman", 0}, 
		{TKAFG1K_VAL_WFM_LAYLIGHT, 0, 0, "Laylight", 0}, 
		{TKAFG1K_VAL_WFM_TRIANGLE, 0, 0, "Triangle", 0}, 
		{TKAFG1K_VAL_WFM_DC, 0, 0, "DC", 0}, 
		{TKAFG1K_VAL_WFM_HEART, 0, 0, "Heart", 0}, 
		{TKAFG1K_VAL_WFM_ROUND, 0, 0, "Round", 0}, 
		{TKAFG1K_VAL_WFM_CHIRP, 0, 0, "Chirp", 0}, 
		{TKAFG1K_VAL_WFM_RHOMBUS, 0, 0, "Rhombus", 0}, 
		{TKAFG1K_VAL_WFM_CARDIAC, 0, 0, "Cardiac", 0}, 
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrFuncWaveformRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrFuncWaveformRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrFuncWaveform_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViInt32 value)
{

    return ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFuncWaveform_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViInt32 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncWaveform_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViInt32 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_FUNC));
    checkErr( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value));

Error:
    return error;
}

/*- TKAFG1K_ATTR_FUNC_AMPLITUDE -*/
static ViStatus _VI_FUNC tkafg1kAttrFuncAmplitude_CheckCallback (ViSession vi,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr (tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_FUNC));

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncAmplitude_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{
    return ( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_AMPLITUDE, 0, value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFuncAmplitude_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_AMPLITUDE, 0, value) );

Error:
    return error;
}

/*- TKAFG1K_ATTR_FUNC_DC_OFFSET -*/

static ViStatus _VI_FUNC tkafg1kAttrFuncDCOffset_CheckCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_FUNC));

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncDCOffset_WriteCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 value)
{
    return ( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_OFFSET, 0, value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFuncDCOffset_ReadCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_OFFSET, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{

    return ( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FREQUENCY, 0, value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FREQUENCY, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_CheckCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_FUNC) );
    checkErr( Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value));

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncFrequency_RangeTableCallback (ViSession vi,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               IviRangeTablePtr *rangeTablePtr)
{
    ViStatus         error = VI_SUCCESS;
    IviRangeTablePtr tblPtr = VI_NULL;
    ViInt32         operationMode;
    ViInt32         waveform;
    ViInt32         model;

    checkErr( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_OPERATION_MODE, 0, &operationMode) );
    checkErr( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform ) );
    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );

    switch  (waveform)
    {
        case TKAFG1K_VAL_WFM_SINE:
        case TKAFG1K_VAL_WFM_PRN:
        {
            /* Sine Waveform Range Table in Burst Mode */
            if( operationMode == TKAFG1K_VAL_OPERATE_BURST)
            {
                if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022SineWfmInBurstFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062SineWfmInBurstFuncFrequencyRangeTable;
                }
            }
            /* Sine Waveform Range Table in other Modes */
            else
            {
				
				if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022SineWfmFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062SineWfmFuncFrequencyRangeTable;
                }
                
            }
            break;
        }
        case TKAFG1K_VAL_WFM_SQUARE:
        {
			
             /* Square Waveform Range Table in Burst Mode */
            if( operationMode == TKAFG1K_VAL_OPERATE_BURST)
            {
				
				if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022SquareWfmInBurstFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062SquareWfmInBurstFuncFrequencyRangeTable;
                }
                
            }
            /* Square Waveform Range Table in other Modes */
            else
            {
				if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022SquareWfmFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062SquareWfmFuncFrequencyRangeTable;
                }
                
            }
            break;
        }
        case TKAFG1K_VAL_WFM_RAMP:
        {
			
            /* Ramp Waveform Range Table in Burst Mode */
            if( operationMode == TKAFG1K_VAL_OPERATE_BURST)
            {
            	if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022RampWfmInBurstFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062RampWfmInBurstFuncFrequencyRangeTable;
                }
				
            }
            /* Ramp Waveform Range Table in other Modes */
            else
            {
				if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022RampWfmFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062RampWfmFuncFrequencyRangeTable;
                }
                
            }
            break;
        }
        case TKAFG1K_VAL_WFM_PULS:
        {
            /* Pulse Waveform Range Table in Burst Mode */
            if( operationMode == TKAFG1K_VAL_OPERATE_BURST)
            {
				if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022PulseWfmInBurstFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1062PulseWfmInBurstFuncFrequencyRangeTable;
                }
                
                
            }
            /* Pulse Waveform Range Table in other Modes */
            else
            {
				
				if( (model == TKAFG1K_VAL_MODEL_AFG1022))
                {
                    tblPtr = &attrAFG1022PulseWfmFuncFrequencyRangeTable;
                }
                else if( (model == TKAFG1K_VAL_MODEL_AFG1062) )
                {
                    tblPtr = &attrAFG1022PulseWfmFuncFrequencyRangeTable;
                }
                
            }
            break;
        }
        default:
        {
            tblPtr = VI_NULL;
        }
    }

Error:
    *rangeTablePtr = tblPtr;
    return error;
}



/*- TKAFG1K_ATTR_FUNC_START_PHASE -*/
static IviRangeTableEntry attrFuncStartPhaseRangeTableEntries[] =
{
        {-180.00, 180.00, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrFuncStartPhaseRangeTable =
{
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrFuncStartPhaseRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrFuncStartPhase_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PHAS:ADJ %LeDEG", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFuncStartPhase_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 rad;

    checkErr( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PHAS:ADJ?", &rad) );

    *value = rad*180.0/(PI);

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFuncStartPhase_CheckCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_FUNC) );

    checkErr( Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value) );

Error:
    return error;
}

/*- TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH -*/
static IviRangeTableEntry attrFuncDutyCycleHighRangeTableEntries[] =
{
        {50.0, 50.0, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrFuncDutyCycleHighRangeTable =
{
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrFuncDutyCycleHighRangeTableEntries,
};

/*- TKAFG1K_ATTR_PULSE_PERIOD -*/
static IviRangeTableEntry attrPulsePeriodRangeTableEntries[] =
    {
        {(2.0e-8), 1000, 0, "", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
    };
static IviRangeTable attrPulsePeriodRangeTable =
    {
        IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPulsePeriodRangeTableEntries,
    };

static ViStatus _VI_FUNC tkafg1kAttrPulseDutyCycle_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;

    checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );
    if(waveform != TKAFG1K_VAL_WFM_PULS)
    {
        viCheckErrElab( IVI_ERROR_INVALID_CONFIGURATION, "The output waveform must be PULSE");
    }

    checkErr ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PULS:DCYC?", value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPulseDutyCycle_WriteCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PULS:DCYC %Le", value) );
}


/*- TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE -*/
static IviRangeTableEntry attrArbWaveformHandleRangeTableEntries[] =
	{
		{TKAFG1K_VAL_WFM_EMEM, 0, 0, "EMEM", 0},
		{TKAFG1K_VAL_WFM_USER0, 0, 0, "USER0", 0}, 
		{TKAFG1K_VAL_WFM_USER1, 0, 0, "USER1", 0}, 
		{TKAFG1K_VAL_WFM_USER2, 0, 0, "USER2", 0}, 
		{TKAFG1K_VAL_WFM_USER3, 0, 0, "USER3", 0}, 
		{TKAFG1K_VAL_WFM_USER4, 0, 0, "USER4", 0}, 
		{TKAFG1K_VAL_WFM_USER5, 0, 0, "USER5", 0}, 
		{TKAFG1K_VAL_WFM_USER6, 0, 0, "USER6", 0}, 
		{TKAFG1K_VAL_WFM_USER7, 0, 0, "USER7", 0}, 
		{TKAFG1K_VAL_WFM_USER8, 0, 0, "USER8", 0}, 
		{TKAFG1K_VAL_WFM_USER9, 0, 0, "USER9", 0}, 
		{TKAFG1K_VAL_WFM_USER10, 0, 0, "USER10", 0}, 
		{TKAFG1K_VAL_WFM_USER11, 0, 0, "USER11", 0}, 
		{TKAFG1K_VAL_WFM_USER12, 0, 0, "USER12", 0}, 
		{TKAFG1K_VAL_WFM_USER13, 0, 0, "USER13", 0}, 
		{TKAFG1K_VAL_WFM_USER14, 0, 0, "USER14", 0}, 
		{TKAFG1K_VAL_WFM_USER15, 0, 0, "USER15", 0}, 
		{TKAFG1K_VAL_WFM_USER16, 0, 0, "USER16", 0}, 
		{TKAFG1K_VAL_WFM_USER17, 0, 0, "USER17", 0}, 
		{TKAFG1K_VAL_WFM_USER18, 0, 0, "USER18", 0}, 
		{TKAFG1K_VAL_WFM_USER19, 0, 0, "USER19", 0}, 
		{TKAFG1K_VAL_WFM_USER20, 0, 0, "USER20", 0}, 
		{TKAFG1K_VAL_WFM_USER21, 0, 0, "USER21", 0}, 
		{TKAFG1K_VAL_WFM_USER22, 0, 0, "USER22", 0}, 
		{TKAFG1K_VAL_WFM_USER23, 0, 0, "USER23", 0}, 
		{TKAFG1K_VAL_WFM_USER24, 0, 0, "USER24", 0}, 
		{TKAFG1K_VAL_WFM_USER25, 0, 0, "USER25", 0}, 
		{TKAFG1K_VAL_WFM_USER26, 0, 0, "USER26", 0}, 
		{TKAFG1K_VAL_WFM_USER27, 0, 0, "USER27", 0}, 
		{TKAFG1K_VAL_WFM_USER28, 0, 0, "USER28", 0}, 
		{TKAFG1K_VAL_WFM_USER29, 0, 0, "USER29", 0}, 
		{TKAFG1K_VAL_WFM_USER30, 0, 0, "USER30", 0}, 
		{TKAFG1K_VAL_WFM_USER31, 0, 0, "USER31", 0}, 
		{TKAFG1K_VAL_WFM_USER32, 0, 0, "USER32", 0}, 
		{TKAFG1K_VAL_WFM_USER33, 0, 0, "USER33", 0}, 
		{TKAFG1K_VAL_WFM_USER34, 0, 0, "USER34", 0}, 
		{TKAFG1K_VAL_WFM_USER35, 0, 0, "USER35", 0}, 
		{TKAFG1K_VAL_WFM_USER36, 0, 0, "USER36", 0}, 
		{TKAFG1K_VAL_WFM_USER37, 0, 0, "USER37", 0}, 
		{TKAFG1K_VAL_WFM_USER38, 0, 0, "USER38", 0}, 
		{TKAFG1K_VAL_WFM_USER39, 0, 0, "USER39", 0}, 
		{TKAFG1K_VAL_WFM_USER40, 0, 0, "USER40", 0}, 
		{TKAFG1K_VAL_WFM_USER41, 0, 0, "USER41", 0}, 
		{TKAFG1K_VAL_WFM_USER42, 0, 0, "USER42", 0}, 
		{TKAFG1K_VAL_WFM_USER43, 0, 0, "USER43", 0}, 
		{TKAFG1K_VAL_WFM_USER44, 0, 0, "USER44", 0}, 
		{TKAFG1K_VAL_WFM_USER45, 0, 0, "USER45", 0}, 
		{TKAFG1K_VAL_WFM_USER46, 0, 0, "USER46", 0}, 
		{TKAFG1K_VAL_WFM_USER47, 0, 0, "USER47", 0}, 
		{TKAFG1K_VAL_WFM_USER48, 0, 0, "USER48", 0}, 
		{TKAFG1K_VAL_WFM_USER49, 0, 0, "USER49", 0}, 
		{TKAFG1K_VAL_WFM_USER50, 0, 0, "USER50", 0}, 
		{TKAFG1K_VAL_WFM_USER51, 0, 0, "USER51", 0}, 
		{TKAFG1K_VAL_WFM_USER52, 0, 0, "USER52", 0}, 
		{TKAFG1K_VAL_WFM_USER53, 0, 0, "USER53", 0}, 
		{TKAFG1K_VAL_WFM_USER54, 0, 0, "USER54", 0}, 
		{TKAFG1K_VAL_WFM_USER55, 0, 0, "USER55", 0}, 
		{TKAFG1K_VAL_WFM_USER56, 0, 0, "USER56", 0}, 
		{TKAFG1K_VAL_WFM_USER57, 0, 0, "USER57", 0}, 
		{TKAFG1K_VAL_WFM_USER58, 0, 0, "USER58", 0}, 
		{TKAFG1K_VAL_WFM_USER59, 0, 0, "USER59", 0}, 
		{TKAFG1K_VAL_WFM_USER60, 0, 0, "USER60", 0}, 
		{TKAFG1K_VAL_WFM_USER61, 0, 0, "USER61", 0}, 
		{TKAFG1K_VAL_WFM_USER62, 0, 0, "USER62", 0}, 
		{TKAFG1K_VAL_WFM_USER63, 0, 0, "USER63", 0}, 
		{TKAFG1K_VAL_WFM_USER64, 0, 0, "USER64", 0}, 
		{TKAFG1K_VAL_WFM_USER65, 0, 0, "USER65", 0}, 
		{TKAFG1K_VAL_WFM_USER66, 0, 0, "USER66", 0}, 
		{TKAFG1K_VAL_WFM_USER67, 0, 0, "USER67", 0}, 
		{TKAFG1K_VAL_WFM_USER68, 0, 0, "USER68", 0}, 
		{TKAFG1K_VAL_WFM_USER69, 0, 0, "USER69", 0}, 
		{TKAFG1K_VAL_WFM_USER70, 0, 0, "USER70", 0}, 
		{TKAFG1K_VAL_WFM_USER71, 0, 0, "USER71", 0}, 
		{TKAFG1K_VAL_WFM_USER72, 0, 0, "USER72", 0}, 
		{TKAFG1K_VAL_WFM_USER73, 0, 0, "USER73", 0}, 
		{TKAFG1K_VAL_WFM_USER74, 0, 0, "USER74", 0}, 
		{TKAFG1K_VAL_WFM_USER75, 0, 0, "USER75", 0}, 
		{TKAFG1K_VAL_WFM_USER76, 0, 0, "USER76", 0}, 
		{TKAFG1K_VAL_WFM_USER77, 0, 0, "USER77", 0}, 
		{TKAFG1K_VAL_WFM_USER78, 0, 0, "USER78", 0}, 
		{TKAFG1K_VAL_WFM_USER79, 0, 0, "USER79", 0}, 
		{TKAFG1K_VAL_WFM_USER80, 0, 0, "USER80", 0}, 
		{TKAFG1K_VAL_WFM_USER81, 0, 0, "USER81", 0}, 
		{TKAFG1K_VAL_WFM_USER82, 0, 0, "USER82", 0}, 
		{TKAFG1K_VAL_WFM_USER83, 0, 0, "USER83", 0}, 
		{TKAFG1K_VAL_WFM_USER84, 0, 0, "USER84", 0}, 
		{TKAFG1K_VAL_WFM_USER85, 0, 0, "USER85", 0}, 
		{TKAFG1K_VAL_WFM_USER86, 0, 0, "USER86", 0}, 
		{TKAFG1K_VAL_WFM_USER87, 0, 0, "USER87", 0}, 
		{TKAFG1K_VAL_WFM_USER88, 0, 0, "USER88", 0}, 
		{TKAFG1K_VAL_WFM_USER89, 0, 0, "USER89", 0}, 
		{TKAFG1K_VAL_WFM_USER90, 0, 0, "USER90", 0}, 
		{TKAFG1K_VAL_WFM_USER91, 0, 0, "USER91", 0}, 
		{TKAFG1K_VAL_WFM_USER92, 0, 0, "USER92", 0}, 
		{TKAFG1K_VAL_WFM_USER93, 0, 0, "USER93", 0}, 
		{TKAFG1K_VAL_WFM_USER94, 0, 0, "USER94", 0}, 
		{TKAFG1K_VAL_WFM_USER95, 0, 0, "USER95", 0}, 
		{TKAFG1K_VAL_WFM_USER96, 0, 0, "USER96", 0}, 
		{TKAFG1K_VAL_WFM_USER97, 0, 0, "USER97", 0}, 
		{TKAFG1K_VAL_WFM_USER98, 0, 0, "USER98", 0}, 
		{TKAFG1K_VAL_WFM_USER99, 0, 0, "USER99", 0}, 
		{TKAFG1K_VAL_WFM_USER100, 0, 0, "USER100", 0}, 
		{TKAFG1K_VAL_WFM_USER101, 0, 0, "USER101", 0}, 
		{TKAFG1K_VAL_WFM_USER102, 0, 0, "USER102", 0}, 
		{TKAFG1K_VAL_WFM_USER103, 0, 0, "USER103", 0}, 
		{TKAFG1K_VAL_WFM_USER104, 0, 0, "USER104", 0}, 
		{TKAFG1K_VAL_WFM_USER105, 0, 0, "USER105", 0}, 
		{TKAFG1K_VAL_WFM_USER106, 0, 0, "USER106", 0}, 
		{TKAFG1K_VAL_WFM_USER107, 0, 0, "USER107", 0}, 
		{TKAFG1K_VAL_WFM_USER108, 0, 0, "USER108", 0}, 
		{TKAFG1K_VAL_WFM_USER109, 0, 0, "USER109", 0}, 
		{TKAFG1K_VAL_WFM_USER110, 0, 0, "USER110", 0}, 
		{TKAFG1K_VAL_WFM_USER111, 0, 0, "USER111", 0}, 
		{TKAFG1K_VAL_WFM_USER112, 0, 0, "USER112", 0}, 
		{TKAFG1K_VAL_WFM_USER113, 0, 0, "USER113", 0}, 
		{TKAFG1K_VAL_WFM_USER114, 0, 0, "USER114", 0}, 
		{TKAFG1K_VAL_WFM_USER115, 0, 0, "USER115", 0}, 
		{TKAFG1K_VAL_WFM_USER116, 0, 0, "USER116", 0}, 
		{TKAFG1K_VAL_WFM_USER117, 0, 0, "USER117", 0}, 
		{TKAFG1K_VAL_WFM_USER118, 0, 0, "USER118", 0}, 
		{TKAFG1K_VAL_WFM_USER119, 0, 0, "USER119", 0}, 
		{TKAFG1K_VAL_WFM_USER120, 0, 0, "USER120", 0}, 
		{TKAFG1K_VAL_WFM_USER121, 0, 0, "USER121", 0}, 
		{TKAFG1K_VAL_WFM_USER122, 0, 0, "USER122", 0}, 
		{TKAFG1K_VAL_WFM_USER123, 0, 0, "USER123", 0}, 
		{TKAFG1K_VAL_WFM_USER124, 0, 0, "USER124", 0}, 
		{TKAFG1K_VAL_WFM_USER125, 0, 0, "USER125", 0}, 
		{TKAFG1K_VAL_WFM_USER126, 0, 0, "USER126", 0}, 
		{TKAFG1K_VAL_WFM_USER127, 0, 0, "USER127", 0}, 
		{TKAFG1K_VAL_WFM_USER128, 0, 0, "USER128", 0}, 
		{TKAFG1K_VAL_WFM_USER129, 0, 0, "USER129", 0}, 
		{TKAFG1K_VAL_WFM_USER130, 0, 0, "USER130", 0}, 
		{TKAFG1K_VAL_WFM_USER131, 0, 0, "USER131", 0}, 
		{TKAFG1K_VAL_WFM_USER132, 0, 0, "USER132", 0}, 
		{TKAFG1K_VAL_WFM_USER133, 0, 0, "USER133", 0}, 
		{TKAFG1K_VAL_WFM_USER134, 0, 0, "USER134", 0}, 
		{TKAFG1K_VAL_WFM_USER135, 0, 0, "USER135", 0}, 
		{TKAFG1K_VAL_WFM_USER136, 0, 0, "USER136", 0}, 
		{TKAFG1K_VAL_WFM_USER137, 0, 0, "USER137", 0}, 
		{TKAFG1K_VAL_WFM_USER138, 0, 0, "USER138", 0}, 
		{TKAFG1K_VAL_WFM_USER139, 0, 0, "USER139", 0}, 
		{TKAFG1K_VAL_WFM_USER140, 0, 0, "USER140", 0}, 
		{TKAFG1K_VAL_WFM_USER141, 0, 0, "USER141", 0}, 
		{TKAFG1K_VAL_WFM_USER142, 0, 0, "USER142", 0}, 
		{TKAFG1K_VAL_WFM_USER143, 0, 0, "USER143", 0}, 
		{TKAFG1K_VAL_WFM_USER144, 0, 0, "USER144", 0}, 
		{TKAFG1K_VAL_WFM_USER145, 0, 0, "USER145", 0}, 
		{TKAFG1K_VAL_WFM_USER146, 0, 0, "USER146", 0}, 
		{TKAFG1K_VAL_WFM_USER147, 0, 0, "USER147", 0}, 
		{TKAFG1K_VAL_WFM_USER148, 0, 0, "USER148", 0}, 
		{TKAFG1K_VAL_WFM_USER149, 0, 0, "USER149", 0}, 
		{TKAFG1K_VAL_WFM_USER150, 0, 0, "USER150", 0}, 
		{TKAFG1K_VAL_WFM_USER151, 0, 0, "USER151", 0}, 
		{TKAFG1K_VAL_WFM_USER152, 0, 0, "USER152", 0}, 
		{TKAFG1K_VAL_WFM_USER153, 0, 0, "USER153", 0}, 
		{TKAFG1K_VAL_WFM_USER154, 0, 0, "USER154", 0}, 
		{TKAFG1K_VAL_WFM_USER155, 0, 0, "USER155", 0}, 
		{TKAFG1K_VAL_WFM_USER156, 0, 0, "USER156", 0}, 
		{TKAFG1K_VAL_WFM_USER157, 0, 0, "USER157", 0}, 
		{TKAFG1K_VAL_WFM_USER158, 0, 0, "USER158", 0}, 
		{TKAFG1K_VAL_WFM_USER159, 0, 0, "USER159", 0}, 
		{TKAFG1K_VAL_WFM_USER160, 0, 0, "USER160", 0}, 
		{TKAFG1K_VAL_WFM_USER161, 0, 0, "USER161", 0}, 
		{TKAFG1K_VAL_WFM_USER162, 0, 0, "USER162", 0}, 
		{TKAFG1K_VAL_WFM_USER163, 0, 0, "USER163", 0}, 
		{TKAFG1K_VAL_WFM_USER164, 0, 0, "USER164", 0}, 
		{TKAFG1K_VAL_WFM_USER165, 0, 0, "USER165", 0}, 
		{TKAFG1K_VAL_WFM_USER166, 0, 0, "USER166", 0}, 
		{TKAFG1K_VAL_WFM_USER167, 0, 0, "USER167", 0}, 
		{TKAFG1K_VAL_WFM_USER168, 0, 0, "USER168", 0}, 
		{TKAFG1K_VAL_WFM_USER169, 0, 0, "USER169", 0}, 
		{TKAFG1K_VAL_WFM_USER170, 0, 0, "USER170", 0}, 
		{TKAFG1K_VAL_WFM_USER171, 0, 0, "USER171", 0}, 
		{TKAFG1K_VAL_WFM_USER172, 0, 0, "USER172", 0}, 
		{TKAFG1K_VAL_WFM_USER173, 0, 0, "USER173", 0}, 
		{TKAFG1K_VAL_WFM_USER174, 0, 0, "USER174", 0}, 
		{TKAFG1K_VAL_WFM_USER175, 0, 0, "USER175", 0}, 
		{TKAFG1K_VAL_WFM_USER176, 0, 0, "USER176", 0}, 
		{TKAFG1K_VAL_WFM_USER177, 0, 0, "USER177", 0}, 
		{TKAFG1K_VAL_WFM_USER178, 0, 0, "USER178", 0}, 
		{TKAFG1K_VAL_WFM_USER179, 0, 0, "USER179", 0}, 
		{TKAFG1K_VAL_WFM_USER180, 0, 0, "USER180", 0}, 
		{TKAFG1K_VAL_WFM_USER181, 0, 0, "USER181", 0}, 
		{TKAFG1K_VAL_WFM_USER182, 0, 0, "USER182", 0}, 
		{TKAFG1K_VAL_WFM_USER183, 0, 0, "USER183", 0}, 
		{TKAFG1K_VAL_WFM_USER184, 0, 0, "USER184", 0}, 
		{TKAFG1K_VAL_WFM_USER185, 0, 0, "USER185", 0}, 
		{TKAFG1K_VAL_WFM_USER186, 0, 0, "USER186", 0}, 
		{TKAFG1K_VAL_WFM_USER187, 0, 0, "USER187", 0}, 
		{TKAFG1K_VAL_WFM_USER188, 0, 0, "USER188", 0}, 
		{TKAFG1K_VAL_WFM_USER189, 0, 0, "USER189", 0}, 
		{TKAFG1K_VAL_WFM_USER190, 0, 0, "USER190", 0}, 
		{TKAFG1K_VAL_WFM_USER191, 0, 0, "USER191", 0}, 
		{TKAFG1K_VAL_WFM_USER192, 0, 0, "USER192", 0}, 
		{TKAFG1K_VAL_WFM_USER193, 0, 0, "USER193", 0}, 
		{TKAFG1K_VAL_WFM_USER194, 0, 0, "USER194", 0}, 
		{TKAFG1K_VAL_WFM_USER195, 0, 0, "USER195", 0}, 
		{TKAFG1K_VAL_WFM_USER196, 0, 0, "USER196", 0}, 
		{TKAFG1K_VAL_WFM_USER197, 0, 0, "USER197", 0}, 
		{TKAFG1K_VAL_WFM_USER198, 0, 0, "USER198", 0}, 
		{TKAFG1K_VAL_WFM_USER199, 0, 0, "USER199", 0}, 
		{TKAFG1K_VAL_WFM_USER200, 0, 0, "USER200", 0}, 
		{TKAFG1K_VAL_WFM_USER201, 0, 0, "USER201", 0}, 
		{TKAFG1K_VAL_WFM_USER202, 0, 0, "USER202", 0}, 
		{TKAFG1K_VAL_WFM_USER203, 0, 0, "USER203", 0}, 
		{TKAFG1K_VAL_WFM_USER204, 0, 0, "USER204", 0}, 
		{TKAFG1K_VAL_WFM_USER205, 0, 0, "USER205", 0}, 
		{TKAFG1K_VAL_WFM_USER206, 0, 0, "USER206", 0}, 
		{TKAFG1K_VAL_WFM_USER207, 0, 0, "USER207", 0}, 
		{TKAFG1K_VAL_WFM_USER208, 0, 0, "USER208", 0}, 
		{TKAFG1K_VAL_WFM_USER209, 0, 0, "USER209", 0}, 
		{TKAFG1K_VAL_WFM_USER210, 0, 0, "USER210", 0}, 
		{TKAFG1K_VAL_WFM_USER211, 0, 0, "USER211", 0}, 
		{TKAFG1K_VAL_WFM_USER212, 0, 0, "USER212", 0}, 
		{TKAFG1K_VAL_WFM_USER213, 0, 0, "USER213", 0}, 
		{TKAFG1K_VAL_WFM_USER214, 0, 0, "USER214", 0}, 
		{TKAFG1K_VAL_WFM_USER215, 0, 0, "USER215", 0}, 
		{TKAFG1K_VAL_WFM_USER216, 0, 0, "USER216", 0}, 
		{TKAFG1K_VAL_WFM_USER217, 0, 0, "USER217", 0}, 
		{TKAFG1K_VAL_WFM_USER218, 0, 0, "USER218", 0}, 
		{TKAFG1K_VAL_WFM_USER219, 0, 0, "USER219", 0}, 
		{TKAFG1K_VAL_WFM_USER220, 0, 0, "USER220", 0}, 
		{TKAFG1K_VAL_WFM_USER221, 0, 0, "USER221", 0}, 
		{TKAFG1K_VAL_WFM_USER222, 0, 0, "USER222", 0}, 
		{TKAFG1K_VAL_WFM_USER223, 0, 0, "USER223", 0}, 
		{TKAFG1K_VAL_WFM_USER224, 0, 0, "USER224", 0}, 
		{TKAFG1K_VAL_WFM_USER225, 0, 0, "USER225", 0}, 
		{TKAFG1K_VAL_WFM_USER226, 0, 0, "USER226", 0}, 
		{TKAFG1K_VAL_WFM_USER227, 0, 0, "USER227", 0}, 
		{TKAFG1K_VAL_WFM_USER228, 0, 0, "USER228", 0}, 
		{TKAFG1K_VAL_WFM_USER229, 0, 0, "USER229", 0}, 
		{TKAFG1K_VAL_WFM_USER230, 0, 0, "USER230", 0}, 
		{TKAFG1K_VAL_WFM_USER231, 0, 0, "USER231", 0}, 
		{TKAFG1K_VAL_WFM_USER232, 0, 0, "USER232", 0}, 
		{TKAFG1K_VAL_WFM_USER233, 0, 0, "USER233", 0}, 
		{TKAFG1K_VAL_WFM_USER234, 0, 0, "USER234", 0}, 
		{TKAFG1K_VAL_WFM_USER235, 0, 0, "USER235", 0}, 
		{TKAFG1K_VAL_WFM_USER236, 0, 0, "USER236", 0}, 
		{TKAFG1K_VAL_WFM_USER237, 0, 0, "USER237", 0}, 
		{TKAFG1K_VAL_WFM_USER238, 0, 0, "USER238", 0}, 
		{TKAFG1K_VAL_WFM_USER239, 0, 0, "USER239", 0}, 
		{TKAFG1K_VAL_WFM_USER240, 0, 0, "USER240", 0}, 
		{TKAFG1K_VAL_WFM_USER241, 0, 0, "USER241", 0}, 
		{TKAFG1K_VAL_WFM_USER242, 0, 0, "USER242", 0}, 
		{TKAFG1K_VAL_WFM_USER243, 0, 0, "USER243", 0}, 
		{TKAFG1K_VAL_WFM_USER244, 0, 0, "USER244", 0}, 
		{TKAFG1K_VAL_WFM_USER245, 0, 0, "USER245", 0}, 
		{TKAFG1K_VAL_WFM_USER246, 0, 0, "USER246", 0}, 
		{TKAFG1K_VAL_WFM_USER247, 0, 0, "USER247", 0}, 
		{TKAFG1K_VAL_WFM_USER248, 0, 0, "USER248", 0}, 
		{TKAFG1K_VAL_WFM_USER249, 0, 0, "USER249", 0}, 
		{TKAFG1K_VAL_WFM_USER250, 0, 0, "USER250", 0}, 
		{TKAFG1K_VAL_WFM_USER251, 0, 0, "USER251", 0}, 
		{TKAFG1K_VAL_WFM_USER252, 0, 0, "USER252", 0}, 
		{TKAFG1K_VAL_WFM_USER253, 0, 0, "USER253", 0}, 
		{TKAFG1K_VAL_WFM_USER254, 0, 0, "USER254", 0}, 
		{TKAFG1K_VAL_WFM_USER255, 0, 0, "USER255", 0}, 
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrArbWaveformHandleRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrArbWaveformHandleRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrArbWaveformHandle_WriteCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 value)
{

    return ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, value) );
}

static ViStatus _VI_FUNC tkafg1kAttrArbWaveformHandle_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbWaveformHandle_CheckCallback (ViSession vi,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 value)
{
    ViStatus error = VI_SUCCESS;
    ViBoolean wfmExists;

    checkErr( tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_ARB));

    checkErr( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value) );

    if(value != TKAFG1K_VAL_WFM_EMEM)
    {
        checkErr( tkafg1k_WfmExists (vi, value, &wfmExists) );

        if(wfmExists == VI_FALSE)
        {
            ViChar errElab[BUFFER_SIZE] = {0};
            switch( value )
            {
                case TKAFG1K_VAL_WFM_USER1:
                {
                    sprintf(errElab, "The specified waveform TKAFG1K_VAL_WFM_USER1 does not exist.");
                    break;
                }
                case TKAFG1K_VAL_WFM_USER2:
                {
                    sprintf(errElab, "The specified waveform TKAFG1K_VAL_WFM_USER2 does not exist.");
                    break;
                }
                case TKAFG1K_VAL_WFM_USER3:
                {
                    sprintf(errElab, "The specified waveform TKAFG1K_VAL_WFM_USER3 does not exist.");
                    break;
                }
                case TKAFG1K_VAL_WFM_USER4:
                {
                    sprintf(errElab, "The specified waveform TKAFG1K_VAL_WFM_USER4 does not exist.");
                    break;
                }
            }
            viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
        }
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_ARB_GAIN -*/
static ViStatus _VI_FUNC tkafg1kAttrArbGain_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 amplitude = value*2.0;

    checkErr( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_AMPLITUDE, 0, amplitude) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbGain_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64    amplitude;

    checkErr( Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_AMPLITUDE, 0, &amplitude) );
    *value = amplitude/2.0;

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbGain_CheckCallback (ViSession vi,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_VerifyOutputModeByChannel(vi, channelName, TKAFG1K_VAL_OUTPUT_ARB) );

Error:
    return error;
}

/*- TKAFG1K_ATTR_ARB_OFFSET -*/

static ViStatus _VI_FUNC tkafg1kAttrArbOffset_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( Ivi_SetAttributeViReal64(vi, channelName, TKAFG1K_ATTR_OFFSET, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbOffset_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( Ivi_GetAttributeViReal64(vi, channelName, TKAFG1K_ATTR_OFFSET, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbOffset_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( tkafg1k_VerifyOutputModeByChannel(vi, channelName, TKAFG1K_VAL_OUTPUT_ARB) );

 Error:
    return error;
}

/*- TKAFG1K_ATTR_ARB_SAMPLE_RATE -*/

static ViStatus _VI_FUNC tkafg1kAttrArbSampleRate_ReadCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
	ViInt32  model;
    checkErr( tkafg1k_VerifyOutputMode(vi, TKAFG1K_VAL_OUTPUT_ARB) );     
	checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model));
	if (model == TKAFG1K_VAL_MODEL_AFG1022)
		*value = 125e6;
	else if (model == TKAFG1K_VAL_MODEL_AFG1062)
		*value = 300e6;
Error:
    return error;
}

/*- TKAFG1K_ATTR_MAX_WAVEFORM_SIZE -*/
static ViStatus _VI_FUNC tkafg1kAttrMaxWaveformSize_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViInt32 *value)
{
	ViStatus    error = VI_SUCCESS;
	ViInt32     model; 
	
	checkErr ( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );     
	
	if (model == TKAFG1K_VAL_MODEL_AFG1022){
		*value = AFG1022_VAL_MAX_WFM_SIZE;
	}else if (model == TKAFG1K_VAL_MODEL_AFG1062){
		*value = AFG1062_VAL_MAX_WFM_SIZE;
	}else{
		error = TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL;
		viCheckErr (error);		
	}
    
Error:
    return error;
}


/*- TKAFG1K_ATTR_ARB_FREQUENCY -*/

static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_RangeTableCallback (ViSession vi,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     IviRangeTablePtr *rangeTablePtr)
{
    ViStatus    error = VI_SUCCESS;
    IviRangeTablePtr    tblPtr = VI_NULL;
    ViInt32     model;
    ViInt32     operationMode;

    checkErr ( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );
    checkErr (Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_OPERATION_MODE, 0, &operationMode));

    if( model == TKAFG1K_VAL_MODEL_AFG1022 )

    {
        if (TKAFG1K_VAL_OPERATE_BURST == operationMode)
            tblPtr = &attrAFG1022ArbFrequencyInBurstRangeTable;
        else
            tblPtr = &attrAFG1022ArbFrequencyRangeTable;
    }
    else if( model == TKAFG1K_VAL_MODEL_AFG1062 )
    {
        if (TKAFG1K_VAL_OPERATE_BURST == operationMode)
            tblPtr = &attrAFG1062ArbFrequencyInBurstRangeTable;
        else
            tblPtr = &attrAFG1062ArbFrequencyRangeTable;
    }
Error:
    *rangeTablePtr = tblPtr;
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_WriteCallback (ViSession vi,
                                                                 ViSession io,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FREQUENCY, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_ReadCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_FREQUENCY, 0, value) );

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrArbFrequency_CheckCallback (ViSession vi,
                                                                 ViConstString channelName,
                                                                 ViAttr attributeId,
                                                                 ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr( tkafg1k_VerifyOutputModeByChannel (vi, channelName, TKAFG1K_VAL_OUTPUT_ARB) );

    checkErr( Ivi_DefaultCheckCallbackViReal64 (vi, channelName, attributeId, value) );

Error:
    return error;
}



/*- TKAFG1K_ATTR_BURST_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrBurstEnabled_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_RunModeAllowable (vi, waveform, TKAFG1K_VAL_OPERATE_BURST, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrBurstEnabled_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    if(value == VI_TRUE)
    {
        viCheckErr ( viPrintf(io, "SOUR%s:BURS:STAT ON", channelName) );
    }
    else
    {
        viCheckErr ( viPrintf(io, "SOUR%s:BURS:STAT OFF", channelName) );
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_BURST_COUNT -*/
static IviRangeTableEntry attrAFG1022BurstCountRangeTableEntries[] =
	{
		{TKAFG1K_VAL_BURST_INFINITY, TKAFG1K_VAL_BURST_INFINITY, 0, "", 0},
		{1, AFG1022_VAL_MAX_BURST_COUNT, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrAFG1022BurstCountRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAFG1022BurstCountRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrBurstCount_WriteCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViInt32 value)
{
    ViStatus error = VI_SUCCESS;

    if(value == TKAFG1K_VAL_BURST_INFINITY)
    {
        viCheckErr( viPrintf (io, "SOUR%s:BURS:NCYC %s", channelName, "INF") );
    }
    else
    {
        checkErr( tkafg1k_WriteInt32(vi, io, channelName, "SOUR%s:BURS:NCYC %d", value) );
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrBurstCount_ReadCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViInt32 *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 count;
    ViReal64 largeCount;

    checkErr( tkafg1k_ReadInt32 (vi, io, channelName, "SOUR%s:BURS:NCYC?", &count) );

    if( (count < 1) || (count > 1000000) )
    {
        viCheckErr ( viQueryf (io, "SOUR%s:BURS:NCYC?", "%Le", channelName, &largeCount) );
        if( fabs (largeCount/9.9e37 - 1) < 1.0e-5 )
        {
            *value = TKAFG1K_VAL_BURST_INFINITY;

        }
        else
        {
            error = IVI_ERROR_INVALID_VALUE;
            viCheckErr (error);
        }
    }
    else
    {
        *value = count;
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_BURST_MODE -*/
static IviRangeTableEntry attrBurstModeRangeTableEntries[] =
{
        {TKAFG1K_VAL_BURST_TRIGGER, 0, 0, "TRIG", 0},
        {TKAFG1K_VAL_BURST_GATE, 0, 0, "GAT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrBurstModeRangeTable =
{
        IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrBurstModeRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrBurstMode_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value)
{
    return (tkafg1k_WriteCmd (vi, io, channelName, &attrBurstModeRangeTable, "source%s:burst:mode %s", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrBurstMode_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
    return (tkafg1k_ReadCmd (vi, io, channelName, &attrBurstModeRangeTable, "source%s:burst:mode?", value) );
}


/*- TKAFG1K_ATTR_MODULATION_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrModulationEnabled_WriteCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     modulationType;
    ViInt32     waveform;

    if(value == VI_TRUE)
    {
        ViBoolean allowance;
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, &modulationType) );
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, modulationType, &allowance) );
        if(!allowance)
        {
            /*- If waveform is Pulse, change modulation to PWM -*/
            if(waveform == TKAFG1K_VAL_WFM_PULS)
            {
                modulationType =  TKAFG1K_VAL_MODULATION_PWM;
            }
            /*- If waveform is DC or Noise, Modulation is unsupported -*/
            else if( waveform == TKAFG1K_VAL_WFM_PRN )
            {
                error = TKAFG1K_ERROR_COMBINATION_UNSUPPORTED;
                viCheckErr (error);
            }
            /*- If other waveform is specified, change modulation to AM -*/
            else
            {
                modulationType = TKAFG1K_VAL_MODULATION_AM;
            }
        }

        switch(modulationType)
        {
            case TKAFG1K_VAL_MODULATION_AM:
            {
                checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_AM_ENABLED, 0, VI_TRUE) );
                break;
            }
            case TKAFG1K_VAL_MODULATION_FM:
            {
                checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_FM_ENABLED, 0, VI_TRUE) );
                break;
            }
            case TKAFG1K_VAL_MODULATION_PM:
            {
                checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PM_ENABLED, 0, VI_TRUE) );
                break;
            }
            case TKAFG1K_VAL_MODULATION_FSK:
            {
                checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_FSK_ENABLED, 0, VI_TRUE) );
                break;
            }
            case TKAFG1K_VAL_MODULATION_PWM:
            {
                checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_PWM_ENABLED, 0, VI_TRUE) );
                break;
            }
        }
    }
    else
    {
        checkErr ( Ivi_SetAttributeViBoolean (vi, channelName, TKAFG1K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE) );
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_ORIGINAL_MODULATION -*/
static IviRangeTableEntry attrOriginalModulationRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MODULATION_AM, 0, 0, "", 0},
		{TKAFG1K_VAL_MODULATION_FM, 0, 0, "", 0},
		{TKAFG1K_VAL_MODULATION_PM, 0, 0, "", 0},
		{TKAFG1K_VAL_MODULATION_FSK, 0, 0, "", 0},
		{TKAFG1K_VAL_MODULATION_PWM, 0, 0, "", 0},
		{TKAFG1K_VAL_MODULATION_ASK, 0, 0, "", 0},
		{TKAFG1K_VAL_MODULATION_PSK, 0, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrOriginalModulationRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrOriginalModulationRangeTableEntries,
	};

/*- TKAFG1K_ATTR_AM_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrAMEnabled_CheckCallback (ViSession vi,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_AM, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAMEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:AM:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_AM) );
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAMEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
    return ( tkafg1k_ReadState(vi, io, channelName, "SOUR%s:AM:STAT?", value) );
}

/*- TKAFG1K_ATTR_AM_SOURCE -*/
static IviRangeTableEntry attrAMSourceRangeTableEntries[] =
{
        {TKAFG1K_VAL_AM_INTERNAL, 0, 0, "INT", 0},
        {TKAFG1K_VAL_AM_EXTERNAL, 0, 0, "EXT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrAMSourceRangeTable =
{
        IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrAMSourceRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrAMSource_WriteCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrAMSourceRangeTable, "SOUR%s:AM:SOUR %s", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAMSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrAMSourceRangeTable, "SOUR%s:AM:SOUR?", value) );
}

/*- TKAFG1K_ATTR_AM_INTERNAL_DEPTH -*/
static IviRangeTableEntry attrAMInternalDepthRangeTableEntries[] =
	{
		{0.00, 100.00, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrAMInternalDepthRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAMInternalDepthRangeTableEntries,
	};


static ViStatus _VI_FUNC tkafg1kAttrAMInternalDepth_CheckCallback(ViSession vi,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32  chan1Source, chan2Source;

    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN1, TKAFG1K_ATTR_AM_SOURCE, 0, &chan1Source) );
    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN2, TKAFG1K_ATTR_AM_SOURCE, 0, &chan2Source) );
    if( (chan1Source != TKAFG1K_VAL_AM_INTERNAL) || (chan2Source != TKAFG1K_VAL_AM_INTERNAL) )
    {
        error = IVI_ERROR_INVALID_CONFIGURATION;
        viCheckErr (error);
    }

    checkErr ( Ivi_DefaultCheckCallbackViReal64(vi, channelName, TKAFG1K_ATTR_AM_INTERNAL_DEPTH, value) );

Error:
    return error;
}


static ViStatus _VI_FUNC tkafg1kAttrAMInternalDepth_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( tkafg1k_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL, value ) );


Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAMInternalDepth_ReadCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value)
{
    return ( tkafg1k_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL, value) );
}


/*- TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL -*/
static ViStatus _VI_FUNC tkafg1kAttrAMDepthByChannel_ReadCallBack (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:AM:DEPT?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAMDepthByChannel_WriteCallback (ViSession vi,
                                                                    ViSession io,
                                                                    ViConstString channelName,
                                                                    ViAttr attributeId,
                                                                    ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:AM:DEPT %Le", value) );
}

/*- TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM -*/
static IviRangeTableEntry attrAMInternalWaveformRangeTableEntries[] =
	{
		{TKAFG1K_VAL_AM_INTERNAL_SINE, 0, 0, "SIN", 0},
		{TKAFG1K_VAL_AM_INTERNAL_SQUARE, 0, 0, "SQU", 0},
		{TKAFG1K_VAL_AM_INTERNAL_RAMP_UP, 0, 0, "RAMP", 0},
		{TKAFG1K_VAL_AM_INTERNAL_PRN, 0, 0, "PRN", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER0, 0, 0, "USER0", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER1, 0, 0, "USER1", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER2, 0, 0, "USER2", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER3, 0, 0, "USER3", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER4, 0, 0, "USER4", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER5, 0, 0, "USER5", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER6, 0, 0, "USER6", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER7, 0, 0, "USER7", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER8, 0, 0, "USER8", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER9, 0, 0, "USER9", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER10, 0, 0, "USER10", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER11, 0, 0, "USER11", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER12, 0, 0, "USER12", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER13, 0, 0, "USER13", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER14, 0, 0, "USER14", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER15, 0, 0, "USER15", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER16, 0, 0, "USER16", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER17, 0, 0, "USER17", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER18, 0, 0, "USER18", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER19, 0, 0, "USER19", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER20, 0, 0, "USER20", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER21, 0, 0, "USER21", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER22, 0, 0, "USER22", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER23, 0, 0, "USER23", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER24, 0, 0, "USER24", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER25, 0, 0, "USER25", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER26, 0, 0, "USER26", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER27, 0, 0, "USER27", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER28, 0, 0, "USER28", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER29, 0, 0, "USER29", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER30, 0, 0, "USER30", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER31, 0, 0, "USER31", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER32, 0, 0, "USER32", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER33, 0, 0, "USER33", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER34, 0, 0, "USER34", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER35, 0, 0, "USER35", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER36, 0, 0, "USER36", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER37, 0, 0, "USER37", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER38, 0, 0, "USER38", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER39, 0, 0, "USER39", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER40, 0, 0, "USER40", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER41, 0, 0, "USER41", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER42, 0, 0, "USER42", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER43, 0, 0, "USER43", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER44, 0, 0, "USER44", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER45, 0, 0, "USER45", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER46, 0, 0, "USER46", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER47, 0, 0, "USER47", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER48, 0, 0, "USER48", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER49, 0, 0, "USER49", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER50, 0, 0, "USER50", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER51, 0, 0, "USER51", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER52, 0, 0, "USER52", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER53, 0, 0, "USER53", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER54, 0, 0, "USER54", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER55, 0, 0, "USER55", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER56, 0, 0, "USER56", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER57, 0, 0, "USER57", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER58, 0, 0, "USER58", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER59, 0, 0, "USER59", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER60, 0, 0, "USER60", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER61, 0, 0, "USER61", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER62, 0, 0, "USER62", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER63, 0, 0, "USER63", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER64, 0, 0, "USER64", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER65, 0, 0, "USER65", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER66, 0, 0, "USER66", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER67, 0, 0, "USER67", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER68, 0, 0, "USER68", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER69, 0, 0, "USER69", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER70, 0, 0, "USER70", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER71, 0, 0, "USER71", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER72, 0, 0, "USER72", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER73, 0, 0, "USER73", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER74, 0, 0, "USER74", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER75, 0, 0, "USER75", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER76, 0, 0, "USER76", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER77, 0, 0, "USER77", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER78, 0, 0, "USER78", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER79, 0, 0, "USER79", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER80, 0, 0, "USER80", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER81, 0, 0, "USER81", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER82, 0, 0, "USER82", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER83, 0, 0, "USER83", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER84, 0, 0, "USER84", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER85, 0, 0, "USER85", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER86, 0, 0, "USER86", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER87, 0, 0, "USER87", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER88, 0, 0, "USER88", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER89, 0, 0, "USER89", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER90, 0, 0, "USER90", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER91, 0, 0, "USER91", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER92, 0, 0, "USER92", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER93, 0, 0, "USER93", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER94, 0, 0, "USER94", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER95, 0, 0, "USER95", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER96, 0, 0, "USER96", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER97, 0, 0, "USER97", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER98, 0, 0, "USER98", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER99, 0, 0, "USER99", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER100, 0, 0, "USER100", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER101, 0, 0, "USER101", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER102, 0, 0, "USER102", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER103, 0, 0, "USER103", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER104, 0, 0, "USER104", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER105, 0, 0, "USER105", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER106, 0, 0, "USER106", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER107, 0, 0, "USER107", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER108, 0, 0, "USER108", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER109, 0, 0, "USER109", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER110, 0, 0, "USER110", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER111, 0, 0, "USER111", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER112, 0, 0, "USER112", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER113, 0, 0, "USER113", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER114, 0, 0, "USER114", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER115, 0, 0, "USER115", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER116, 0, 0, "USER116", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER117, 0, 0, "USER117", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER118, 0, 0, "USER118", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER119, 0, 0, "USER119", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER120, 0, 0, "USER120", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER121, 0, 0, "USER121", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER122, 0, 0, "USER122", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER123, 0, 0, "USER123", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER124, 0, 0, "USER124", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER125, 0, 0, "USER125", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER126, 0, 0, "USER126", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER127, 0, 0, "USER127", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER128, 0, 0, "USER128", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER129, 0, 0, "USER129", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER130, 0, 0, "USER130", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER131, 0, 0, "USER131", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER132, 0, 0, "USER132", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER133, 0, 0, "USER133", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER134, 0, 0, "USER134", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER135, 0, 0, "USER135", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER136, 0, 0, "USER136", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER137, 0, 0, "USER137", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER138, 0, 0, "USER138", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER139, 0, 0, "USER139", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER140, 0, 0, "USER140", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER141, 0, 0, "USER141", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER142, 0, 0, "USER142", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER143, 0, 0, "USER143", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER144, 0, 0, "USER144", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER145, 0, 0, "USER145", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER146, 0, 0, "USER146", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER147, 0, 0, "USER147", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER148, 0, 0, "USER148", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER149, 0, 0, "USER149", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER150, 0, 0, "USER150", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER151, 0, 0, "USER151", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER152, 0, 0, "USER152", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER153, 0, 0, "USER153", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER154, 0, 0, "USER154", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER155, 0, 0, "USER155", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER156, 0, 0, "USER156", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER157, 0, 0, "USER157", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER158, 0, 0, "USER158", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER159, 0, 0, "USER159", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER160, 0, 0, "USER160", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER161, 0, 0, "USER161", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER162, 0, 0, "USER162", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER163, 0, 0, "USER163", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER164, 0, 0, "USER164", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER165, 0, 0, "USER165", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER166, 0, 0, "USER166", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER167, 0, 0, "USER167", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER168, 0, 0, "USER168", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER169, 0, 0, "USER169", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER170, 0, 0, "USER170", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER171, 0, 0, "USER171", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER172, 0, 0, "USER172", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER173, 0, 0, "USER173", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER174, 0, 0, "USER174", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER175, 0, 0, "USER175", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER176, 0, 0, "USER176", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER177, 0, 0, "USER177", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER178, 0, 0, "USER178", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER179, 0, 0, "USER179", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER180, 0, 0, "USER180", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER181, 0, 0, "USER181", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER182, 0, 0, "USER182", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER183, 0, 0, "USER183", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER184, 0, 0, "USER184", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER185, 0, 0, "USER185", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER186, 0, 0, "USER186", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER187, 0, 0, "USER187", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER188, 0, 0, "USER188", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER189, 0, 0, "USER189", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER190, 0, 0, "USER190", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER191, 0, 0, "USER191", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER192, 0, 0, "USER192", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER193, 0, 0, "USER193", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER194, 0, 0, "USER194", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER195, 0, 0, "USER195", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER196, 0, 0, "USER196", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER197, 0, 0, "USER197", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER198, 0, 0, "USER198", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER199, 0, 0, "USER199", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER200, 0, 0, "USER200", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER201, 0, 0, "USER201", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER202, 0, 0, "USER202", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER203, 0, 0, "USER203", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER204, 0, 0, "USER204", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER205, 0, 0, "USER205", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER206, 0, 0, "USER206", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER207, 0, 0, "USER207", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER208, 0, 0, "USER208", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER209, 0, 0, "USER209", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER210, 0, 0, "USER210", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER211, 0, 0, "USER211", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER212, 0, 0, "USER212", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER213, 0, 0, "USER213", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER214, 0, 0, "USER214", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER215, 0, 0, "USER215", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER216, 0, 0, "USER216", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER217, 0, 0, "USER217", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER218, 0, 0, "USER218", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER219, 0, 0, "USER219", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER220, 0, 0, "USER220", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER221, 0, 0, "USER221", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER222, 0, 0, "USER222", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER223, 0, 0, "USER223", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER224, 0, 0, "USER224", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER225, 0, 0, "USER225", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER226, 0, 0, "USER226", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER227, 0, 0, "USER227", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER228, 0, 0, "USER228", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER229, 0, 0, "USER229", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER230, 0, 0, "USER230", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER231, 0, 0, "USER231", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER232, 0, 0, "USER232", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER233, 0, 0, "USER233", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER234, 0, 0, "USER234", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER235, 0, 0, "USER235", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER236, 0, 0, "USER236", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER237, 0, 0, "USER237", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER238, 0, 0, "USER238", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER239, 0, 0, "USER239", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER240, 0, 0, "USER240", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER241, 0, 0, "USER241", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER242, 0, 0, "USER242", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER243, 0, 0, "USER243", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER244, 0, 0, "USER244", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER245, 0, 0, "USER245", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER246, 0, 0, "USER246", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER247, 0, 0, "USER247", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER248, 0, 0, "USER248", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER249, 0, 0, "USER249", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER250, 0, 0, "USER250", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER251, 0, 0, "USER251", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER252, 0, 0, "USER252", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER253, 0, 0, "USER253", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER254, 0, 0, "USER254", 0},
		{TKAFG1K_VAL_AM_INTERNAL_USER255, 0, 0, "USER255", 0},
		{TKAFG1K_VAL_AM_INTERNAL_EMEM, 0, 0, "EMEM", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrAMInternalWaveformRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrAMInternalWaveformRangeTableEntries,
	};


static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveform_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32  *value)
{
    ViStatus error = VI_SUCCESS;
    ViInt32 chan1Waveform;

    checkErr ( tkafg1k_GetAttributeViInt32 ( vi, channelName, TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &chan1Waveform ) );
    *value = chan1Waveform;
Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveform_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViInt32 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( tkafg1k_SetAttributeViInt32 ( vi, channelName, TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, value ) );

Error:
    return error;
}

/*- TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL -*/
static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveformByChannel_CheckCallback (ViSession vi,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    ViBoolean   wfmExists = VI_TRUE;

    checkErr( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value) );
    switch(value)
    {
        case TKAFG1K_VAL_AM_INTERNAL_USER1:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER1, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_AM_INTERNAL_USER2:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER2, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_AM_INTERNAL_USER3:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER3, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_AM_INTERNAL_USER4:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER4, &wfmExists) );
            break;
        }
    }

    if(wfmExists == VI_FALSE)
    {
        ViChar errElab[BUFFER_SIZE] = {0};
        switch( value )
        {
            case TKAFG1K_VAL_AM_INTERNAL_USER1:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_AM_INTERNAL_USER1 does not exist.");
                break;
            }
            case TKAFG1K_VAL_AM_INTERNAL_USER2:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_AM_INTERNAL_USER2 does not exist.");
                break;
            }
            case TKAFG1K_VAL_AM_INTERNAL_USER3:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_AM_INTERNAL_USER3 does not exist.");
                break;
            }
            case TKAFG1K_VAL_AM_INTERNAL_USER4:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_AM_INTERNAL_USER4 does not exist.");
                break;
            }
        }
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveformByChannel_ReadCallback (ViSession vi,
                                                                              ViSession io,
                                                                              ViConstString channelName,
                                                                              ViAttr attributeId,
                                                                              ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrAMInternalWaveformRangeTable, "SOUR%s:AM:INT:FUNC?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAMInternalWaveformByChannel_WriteCallback (ViSession vi,
                                                                               ViSession io,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrAMInternalWaveformRangeTable, "SOUR%s:AM:INT:FUNC %s", value) );
}

/*- TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY -*/
static IviRangeTableEntry attrAMInternalFrequencyRangeTableEntries[] =
	{
		{0.002, 20000.00, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrAMInternalFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrAMInternalFrequencyRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrAMInternalFrequency_WriteCallback (ViSession vi,
                                                                        ViSession io,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
    return ( tkafg1k_SetAttributeViReal64 ( vi, channelName, TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, value ) );
}


static ViStatus _VI_FUNC tkafg1kAttrAMInternalFrequency_ReadCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 *value)
{
    return ( tkafg1k_GetAttributeViReal64 ( vi, channelName, TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, value ) );
}

/*- TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL -*/
static ViStatus _VI_FUNC tkafg1kAttrAMInternalFrequencyByChannel_ReadCallback (ViSession vi,
                                                                               ViSession io,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:AM:INT:FREQ?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAMInternalFrequencyByChannel_WriteCallback (ViSession vi,
                                                                                ViSession io,
                                                                                ViConstString channelName,
                                                                                ViAttr attributeId,
                                                                                ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:AM:INT:FREQ %Le", value) );
}

/*- TKAFG1K_ATTR_FM_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrFMEnabled_CheckCallback (ViSession vi,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_FM, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFMEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:FM:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_FM) );
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFMEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
    return ( tkafg1k_ReadState (vi, io, channelName, "SOUR%s:FM:STAT?", value) );
}

/*- TKAFG1K_ATTR_FM_SOURCE -*/
static IviRangeTableEntry attrFMSourceRangeTableEntries[] =
{
        {TKAFG1K_VAL_FM_INTERNAL, 0, 0, "INT", 0},
        {TKAFG1K_VAL_FM_EXTERNAL, 0, 0, "EXT", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrFMSourceRangeTable =
{
        IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrFMSourceRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrFMSource_WriteCallback (ViSession vi,
                                                        ViSession io,
                                                        ViConstString channelName,
                                                        ViAttr attributeId,
                                                        ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrFMSourceRangeTable, "SOUR%s:FM:SOUR %s", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFMSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrFMSourceRangeTable, "SOUR%s:FM:SOUR?", value) );
}

/*- TKAFG1K_ATTR_FM_INTERNAL_DEVIATION -*/


static ViStatus _VI_FUNC tkafg1kAttrFMInternalDeviation_CheckCallback (ViSession vi,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     chan1Source, chan2Source;

    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN1, TKAFG1K_ATTR_FM_SOURCE, 0, &chan1Source) );
    checkErr ( Ivi_GetAttributeViInt32 (vi, CHAN2, TKAFG1K_ATTR_FM_SOURCE, 0, &chan2Source) );
    if( (chan1Source != TKAFG1K_VAL_FM_INTERNAL) || (chan2Source != TKAFG1K_VAL_FM_INTERNAL) )
    {
        error = IVI_ERROR_INVALID_CONFIGURATION;
        viCheckErr (error);
    }

    checkErr ( Ivi_DefaultCheckCallbackViReal64 (vi, channelName, TKAFG1K_ATTR_FM_INTERNAL_DEVIATION, value) );

Error:
    return error;
}


static ViStatus _VI_FUNC tkafg1kAttrFMInternalDeviation_WriteCallback (ViSession vi,
                                                                         ViSession io,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         ViReal64 value)
{
    ViStatus error = VI_SUCCESS;

    checkErr ( Ivi_SetAttributeViReal64 ( vi, CHAN1, TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL, 0, value ) );

    checkErr ( Ivi_SetAttributeViReal64 ( vi, CHAN2, TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL, 0, value ) );

Error:
    return error;
}


static ViStatus _VI_FUNC tkafg1kAttrFMInternalDeviation_ReadCallback (ViSession vi,
                                                                         ViSession io,
                                                                         ViConstString channelName,
                                                                         ViAttr attributeId,
                                                                         ViReal64 *value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64    chan1Deviation, chan2Deviation;

    checkErr ( Ivi_GetAttributeViReal64 ( vi, CHAN1, TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL, 0, &chan1Deviation ) );

    checkErr ( Ivi_GetAttributeViReal64 ( vi, CHAN2, TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL, 0, &chan2Deviation ) );

    if( fabs( chan1Deviation-chan2Deviation) > 1.0e-5 )
    {
        error = TKAFG1K_ERROR_CHANNELS_DIFFERENT;
        viCheckErr (error);
    }
    else
    {
        *value = chan1Deviation;
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL -*/
static ViStatus _VI_FUNC tkafg1kAttrFmDeviationByChannel_CheckCallback (ViSession vi,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	ViReal64    carrierFreq, totalFreq,upperLimit=AFG1022_VAL_MAX_FREQ_DEFAULT;
	ViInt32 	model;
    ViInt32     waveform;
	checkErr ( Ivi_GetAttributeViReal64 ( vi, channelName, TKAFG1K_ATTR_FREQUENCY, 0, &carrierFreq ) );
	if((value < 0 ) || (value > carrierFreq))
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr (error);
    }
	checkErr ( Ivi_GetAttributeViInt32 (  vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform ) );
    totalFreq = carrierFreq + value;

	checkErr( Ivi_GetAttributeViInt32 (vi,VI_NULL,TKAFG1K_ATTR_MODEL,0,&model));
	switch(waveform){
		case TKAFG1K_VAL_WFM_SINE:
        {
			if(model == TKAFG1K_VAL_MODEL_AFG1022)
				upperLimit = AFG1022_VAL_MAX_FREQ_SINE;
			else if (model == TKAFG1K_VAL_MODEL_AFG1062)
				upperLimit = AFG1062_VAL_MAX_FREQ_SINE;
            break;
        }
		case TKAFG1K_VAL_WFM_SQUARE:
        {
			if(model == TKAFG1K_VAL_MODEL_AFG1022)
				upperLimit = AFG1022_VAL_MAX_FREQ_SQUARE;
			else if (model == TKAFG1K_VAL_MODEL_AFG1062)
				upperLimit = AFG1062_VAL_MAX_FREQ_SQUARE;			
            break;
        }
        case TKAFG1K_VAL_WFM_RAMP:
        {
			if(model == TKAFG1K_VAL_MODEL_AFG1022)
				upperLimit = AFG1022_VAL_MAX_FREQ_RAMP;
			else if (model == TKAFG1K_VAL_MODEL_AFG1062)
				upperLimit = AFG1062_VAL_MAX_FREQ_RAMP;            
            break;
        }
        case TKAFG1K_VAL_WFM_EMEM:
        {
            if(model == TKAFG1K_VAL_MODEL_AFG1022)
				upperLimit = AFG1022_VAL_MAX_FREQ_ARB;
			else if (model == TKAFG1K_VAL_MODEL_AFG1062)
				upperLimit = AFG1062_VAL_MAX_FREQ_ARB;
            break;
        }
		default:
		{   if(waveform>=TKAFG1K_VAL_WFM_USER0 && waveform<=TKAFG1K_VAL_WFM_USER255){
				if(model == TKAFG1K_VAL_MODEL_AFG1022)
					upperLimit = AFG1022_VAL_MAX_FREQ_ARB;
				else if (model == TKAFG1K_VAL_MODEL_AFG1062){
					if(waveform >=TKAFG1K_VAL_WFM_USER32){
						error = IVI_ERROR_INVALID_PARAMETER;
						viCheckErr (error);						
					}else
						upperLimit = AFG1022_VAL_MAX_FREQ_ARB;
				}else{
					error = TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL;
					viCheckErr (error);
				}
			}else if(waveform >=TKAFG1K_VAL_WFM_STAIRDOWN && waveform <=TKAFG1K_VAL_WFM_CARDIAC)
					if(model == TKAFG1K_VAL_MODEL_AFG1022)
					upperLimit = AFG1022_VAL_MAX_FREQ_ARB;
				else if (model == TKAFG1K_VAL_MODEL_AFG1062){
						upperLimit = AFG1022_VAL_MAX_FREQ_ARB;
				}else{
					error = TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL;
					viCheckErr (error);
				}					
			else{
				error = IVI_ERROR_INVALID_PARAMETER;
				viCheckErr (error);
			}
			break;
		}
	}
	if(totalFreq > (upperLimit+1.0e-5) )
    {
		error = IVI_ERROR_INVALID_VALUE;
		viCheckErr (error);
	}
	
Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFMDeviationByChannel_ReadCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:FM:DEV?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFMDeviationByChannel_WriteCallback (ViSession vi,
                                                                        ViSession io,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:FM:DEV %Le", value) );
}

/*- TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM -*/
static IviRangeTableEntry attrFMInternalWaveformRangeTableEntries[] =
{
        {TKAFG1K_VAL_FM_INTERNAL_SINE, 0, 0, "SIN", 0},
        {TKAFG1K_VAL_FM_INTERNAL_SQUARE, 0, 0, "SQU", 0},
        {TKAFG1K_VAL_FM_INTERNAL_RAMP_UP, 0, 0, "RAMP", 0},
        {TKAFG1K_VAL_FM_INTERNAL_PRN, 0, 0, "PRN", 0},
        {TKAFG1K_VAL_FM_INTERNAL_USER0, 0, 0, "USER0", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER1, 0, 0, "USER1", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER2, 0, 0, "USER2", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER3, 0, 0, "USER3", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER4, 0, 0, "USER4", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER5, 0, 0, "USER5", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER6, 0, 0, "USER6", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER7, 0, 0, "USER7", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER8, 0, 0, "USER8", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER9, 0, 0, "USER9", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER10, 0, 0, "USER10", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER11, 0, 0, "USER11", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER12, 0, 0, "USER12", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER13, 0, 0, "USER13", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER14, 0, 0, "USER14", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER15, 0, 0, "USER15", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER16, 0, 0, "USER16", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER17, 0, 0, "USER17", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER18, 0, 0, "USER18", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER19, 0, 0, "USER19", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER20, 0, 0, "USER20", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER21, 0, 0, "USER21", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER22, 0, 0, "USER22", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER23, 0, 0, "USER23", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER24, 0, 0, "USER24", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER25, 0, 0, "USER25", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER26, 0, 0, "USER26", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER27, 0, 0, "USER27", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER28, 0, 0, "USER28", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER29, 0, 0, "USER29", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER30, 0, 0, "USER30", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER31, 0, 0, "USER31", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER32, 0, 0, "USER32", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER33, 0, 0, "USER33", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER34, 0, 0, "USER34", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER35, 0, 0, "USER35", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER36, 0, 0, "USER36", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER37, 0, 0, "USER37", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER38, 0, 0, "USER38", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER39, 0, 0, "USER39", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER40, 0, 0, "USER40", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER41, 0, 0, "USER41", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER42, 0, 0, "USER42", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER43, 0, 0, "USER43", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER44, 0, 0, "USER44", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER45, 0, 0, "USER45", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER46, 0, 0, "USER46", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER47, 0, 0, "USER47", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER48, 0, 0, "USER48", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER49, 0, 0, "USER49", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER50, 0, 0, "USER50", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER51, 0, 0, "USER51", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER52, 0, 0, "USER52", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER53, 0, 0, "USER53", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER54, 0, 0, "USER54", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER55, 0, 0, "USER55", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER56, 0, 0, "USER56", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER57, 0, 0, "USER57", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER58, 0, 0, "USER58", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER59, 0, 0, "USER59", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER60, 0, 0, "USER60", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER61, 0, 0, "USER61", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER62, 0, 0, "USER62", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER63, 0, 0, "USER63", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER64, 0, 0, "USER64", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER65, 0, 0, "USER65", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER66, 0, 0, "USER66", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER67, 0, 0, "USER67", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER68, 0, 0, "USER68", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER69, 0, 0, "USER69", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER70, 0, 0, "USER70", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER71, 0, 0, "USER71", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER72, 0, 0, "USER72", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER73, 0, 0, "USER73", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER74, 0, 0, "USER74", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER75, 0, 0, "USER75", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER76, 0, 0, "USER76", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER77, 0, 0, "USER77", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER78, 0, 0, "USER78", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER79, 0, 0, "USER79", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER80, 0, 0, "USER80", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER81, 0, 0, "USER81", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER82, 0, 0, "USER82", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER83, 0, 0, "USER83", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER84, 0, 0, "USER84", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER85, 0, 0, "USER85", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER86, 0, 0, "USER86", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER87, 0, 0, "USER87", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER88, 0, 0, "USER88", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER89, 0, 0, "USER89", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER90, 0, 0, "USER90", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER91, 0, 0, "USER91", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER92, 0, 0, "USER92", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER93, 0, 0, "USER93", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER94, 0, 0, "USER94", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER95, 0, 0, "USER95", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER96, 0, 0, "USER96", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER97, 0, 0, "USER97", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER98, 0, 0, "USER98", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER99, 0, 0, "USER99", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER100, 0, 0, "USER100", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER101, 0, 0, "USER101", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER102, 0, 0, "USER102", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER103, 0, 0, "USER103", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER104, 0, 0, "USER104", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER105, 0, 0, "USER105", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER106, 0, 0, "USER106", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER107, 0, 0, "USER107", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER108, 0, 0, "USER108", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER109, 0, 0, "USER109", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER110, 0, 0, "USER110", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER111, 0, 0, "USER111", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER112, 0, 0, "USER112", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER113, 0, 0, "USER113", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER114, 0, 0, "USER114", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER115, 0, 0, "USER115", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER116, 0, 0, "USER116", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER117, 0, 0, "USER117", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER118, 0, 0, "USER118", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER119, 0, 0, "USER119", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER120, 0, 0, "USER120", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER121, 0, 0, "USER121", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER122, 0, 0, "USER122", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER123, 0, 0, "USER123", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER124, 0, 0, "USER124", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER125, 0, 0, "USER125", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER126, 0, 0, "USER126", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER127, 0, 0, "USER127", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER128, 0, 0, "USER128", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER129, 0, 0, "USER129", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER130, 0, 0, "USER130", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER131, 0, 0, "USER131", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER132, 0, 0, "USER132", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER133, 0, 0, "USER133", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER134, 0, 0, "USER134", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER135, 0, 0, "USER135", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER136, 0, 0, "USER136", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER137, 0, 0, "USER137", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER138, 0, 0, "USER138", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER139, 0, 0, "USER139", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER140, 0, 0, "USER140", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER141, 0, 0, "USER141", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER142, 0, 0, "USER142", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER143, 0, 0, "USER143", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER144, 0, 0, "USER144", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER145, 0, 0, "USER145", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER146, 0, 0, "USER146", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER147, 0, 0, "USER147", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER148, 0, 0, "USER148", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER149, 0, 0, "USER149", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER150, 0, 0, "USER150", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER151, 0, 0, "USER151", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER152, 0, 0, "USER152", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER153, 0, 0, "USER153", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER154, 0, 0, "USER154", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER155, 0, 0, "USER155", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER156, 0, 0, "USER156", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER157, 0, 0, "USER157", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER158, 0, 0, "USER158", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER159, 0, 0, "USER159", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER160, 0, 0, "USER160", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER161, 0, 0, "USER161", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER162, 0, 0, "USER162", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER163, 0, 0, "USER163", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER164, 0, 0, "USER164", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER165, 0, 0, "USER165", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER166, 0, 0, "USER166", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER167, 0, 0, "USER167", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER168, 0, 0, "USER168", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER169, 0, 0, "USER169", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER170, 0, 0, "USER170", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER171, 0, 0, "USER171", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER172, 0, 0, "USER172", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER173, 0, 0, "USER173", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER174, 0, 0, "USER174", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER175, 0, 0, "USER175", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER176, 0, 0, "USER176", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER177, 0, 0, "USER177", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER178, 0, 0, "USER178", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER179, 0, 0, "USER179", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER180, 0, 0, "USER180", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER181, 0, 0, "USER181", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER182, 0, 0, "USER182", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER183, 0, 0, "USER183", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER184, 0, 0, "USER184", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER185, 0, 0, "USER185", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER186, 0, 0, "USER186", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER187, 0, 0, "USER187", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER188, 0, 0, "USER188", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER189, 0, 0, "USER189", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER190, 0, 0, "USER190", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER191, 0, 0, "USER191", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER192, 0, 0, "USER192", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER193, 0, 0, "USER193", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER194, 0, 0, "USER194", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER195, 0, 0, "USER195", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER196, 0, 0, "USER196", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER197, 0, 0, "USER197", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER198, 0, 0, "USER198", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER199, 0, 0, "USER199", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER200, 0, 0, "USER200", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER201, 0, 0, "USER201", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER202, 0, 0, "USER202", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER203, 0, 0, "USER203", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER204, 0, 0, "USER204", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER205, 0, 0, "USER205", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER206, 0, 0, "USER206", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER207, 0, 0, "USER207", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER208, 0, 0, "USER208", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER209, 0, 0, "USER209", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER210, 0, 0, "USER210", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER211, 0, 0, "USER211", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER212, 0, 0, "USER212", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER213, 0, 0, "USER213", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER214, 0, 0, "USER214", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER215, 0, 0, "USER215", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER216, 0, 0, "USER216", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER217, 0, 0, "USER217", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER218, 0, 0, "USER218", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER219, 0, 0, "USER219", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER220, 0, 0, "USER220", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER221, 0, 0, "USER221", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER222, 0, 0, "USER222", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER223, 0, 0, "USER223", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER224, 0, 0, "USER224", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER225, 0, 0, "USER225", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER226, 0, 0, "USER226", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER227, 0, 0, "USER227", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER228, 0, 0, "USER228", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER229, 0, 0, "USER229", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER230, 0, 0, "USER230", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER231, 0, 0, "USER231", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER232, 0, 0, "USER232", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER233, 0, 0, "USER233", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER234, 0, 0, "USER234", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER235, 0, 0, "USER235", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER236, 0, 0, "USER236", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER237, 0, 0, "USER237", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER238, 0, 0, "USER238", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER239, 0, 0, "USER239", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER240, 0, 0, "USER240", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER241, 0, 0, "USER241", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER242, 0, 0, "USER242", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER243, 0, 0, "USER243", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER244, 0, 0, "USER244", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER245, 0, 0, "USER245", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER246, 0, 0, "USER246", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER247, 0, 0, "USER247", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER248, 0, 0, "USER248", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER249, 0, 0, "USER249", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER250, 0, 0, "USER250", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER251, 0, 0, "USER251", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER252, 0, 0, "USER252", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER253, 0, 0, "USER253", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER254, 0, 0, "USER254", 0}, 
        {TKAFG1K_VAL_FM_INTERNAL_USER255, 0, 0, "USER255", 0}, 
		{TKAFG1K_VAL_FM_INTERNAL_EMEM, 0, 0, "EMEM", 0},
        {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrFMInternalWaveformRangeTable =
{
        IVI_VAL_DISCRETE,
        VI_FALSE,
        VI_FALSE,
        VI_NULL,
        attrFMInternalWaveformRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveform_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViInt32 value)
{
    return ( tkafg1k_SetAttributeViInt32 ( vi, channelName, TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, value ) );
}



static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveform_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 *value)
{
    return ( tkafg1k_GetAttributeViInt32 ( vi, channelName, TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, value ) );
}


/*- TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL -*/
static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveformByChannel_CheckCallback (ViSession vi,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    ViBoolean   wfmExists = VI_TRUE;

    checkErr( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value) );
    switch(value)
    {
        case TKAFG1K_VAL_FM_INTERNAL_USER1:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER1, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_FM_INTERNAL_USER2:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER2, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_FM_INTERNAL_USER3:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER3, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_FM_INTERNAL_USER4:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER4, &wfmExists) );
            break;
        }
    }

    if(wfmExists == VI_FALSE)
    {
        ViChar errElab[BUFFER_SIZE] = {0};
        switch( value )
        {
            case TKAFG1K_VAL_FM_INTERNAL_USER1:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_FM_INTERNAL_USER1 does not exist.");
                break;
            }
            case TKAFG1K_VAL_FM_INTERNAL_USER2:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_FM_INTERNAL_USER2 does not exist.");
                break;
            }
            case TKAFG1K_VAL_FM_INTERNAL_USER3:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_FM_INTERNAL_USER3 does not exist.");
                break;
            }
            case TKAFG1K_VAL_FM_INTERNAL_USER4:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_FM_INTERNAL_USER4 does not exist.");
                break;
            }
        }
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveformByChannel_ReadCallback (ViSession vi,
                                                                              ViSession io,
                                                                              ViConstString channelName,
                                                                              ViAttr attributeId,
                                                                              ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrFMInternalWaveformRangeTable, "SOUR%s:FM:INT:FUNC?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFMInternalWaveformByChannel_WriteCallback (ViSession vi,
                                                                               ViSession io,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrFMInternalWaveformRangeTable, "SOUR%s:FM:INT:FUNC %s", value) );
}

/*- TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY -*/
static IviRangeTableEntry attrFMInternalFrequencyRangeTableEntries[] =
	{
		{0.002, 20000.0, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrFMInternalFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrFMInternalFrequencyRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrFMInternalFrequency_WriteCallback (ViSession vi,
                                                                        ViSession io,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
    return ( tkafg1k_SetAttributeViReal64 ( vi, channelName, TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, value ) );
}

static ViStatus _VI_FUNC tkafg1kAttrFMInternalFrequency_ReadCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 *value)
{
    return ( tkafg1k_GetAttributeViReal64 ( vi, channelName, TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, value ) );
}


/*- TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL -*/
static ViStatus _VI_FUNC tkafg1kAttrFMInternalFrequencyByChannel_ReadCallback (ViSession vi,
                                                                               ViSession io,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:FM:INT:FREQ?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFMInternalFrequencyByChannel_WriteCallback (ViSession vi,
                                                                                ViSession io,
                                                                                ViConstString channelName,
                                                                                ViAttr attributeId,
                                                                                ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:FM:INT:FREQ %Le", value) );
}

/*- TKAFG1K_ATTR_FSK_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrFSKEnabled_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_FSK, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrFSKEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
    return ( tkafg1k_ReadState (vi, io, channelName, "SOUR%s:FSK:STAT?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFSKEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:FSK:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_FSK) );
    }

Error:
    return error;
}


static ViStatus _VI_FUNC tkafg1kAttrFSKHopFrequency_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:FSK:FREQ?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFSKHopFrequency_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:FSK:FREQ %Le", value) );
}

/*- TKAFG1K_ATTR_FSK_INTERNAL_RATE -*/
static IviRangeTableEntry attrFSKInternalRateRangeTableEntries[] =
	{
		{0.002, 100000, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrFSKInternalRateRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrFSKInternalRateRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrFSKInternalRate_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:FSK:INT:RATE?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFSKInternalRate_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:FSK:INT:RATE %Le", value) );
}

/*- TKAFG1K_ATTR_FSK_SOURCE -*/
static IviRangeTableEntry attrFSKSourceRangeTableEntries[] =
{
    {TKAFG1K_VAL_FSK_INTERNAL, 0, 0, "INT", 0},
    {TKAFG1K_VAL_FSK_EXTERNAL, 0, 0, "EXT", 0},
    {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrFSKSourceRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrFSKSourceRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrFSKSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrFSKSourceRangeTable, "SOUR%s:FSK:SOUR?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFSKSource_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrFSKSourceRangeTable, "SOUR%s:FSK:SOUR %s", value) );
}

/*- TKAFG1K_ATTR_PM_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrPMEnabled_CheckCallback (ViSession vi,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_PM, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPMEnabled_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViBoolean *value)
{
    return ( tkafg1k_ReadState (vi, io, channelName, "SOUR%s:PM:STAT?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPMEnabled_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:PM:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_PM) );
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_PM_SOURCE -*/
static IviRangeTableEntry attrPMSourceRangeTableEntries[] =
{
    {TKAFG1K_VAL_PM_INTERNAL, 0, 0, "INT", 0},
    {TKAFG1K_VAL_PM_EXTERNAL, 0, 0, "EXT", 0},
    {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrPMSourceRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrPMSourceRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrPMSource_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrPMSourceRangeTable, "SOUR%s:PM:SOUR?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPMSource_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrPMSourceRangeTable, "SOUR%s:PM:SOUR %s", value) );
}

/*- TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL -*/
static IviRangeTableEntry attrPMDeviationRangeTableEntries[] =
{
    {0, 180, 0, "", 0},
    {IVI_RANGE_TABLE_LAST_ENTRY}
};

static IviRangeTable attrPMDeviationRangeTable =
{
    IVI_VAL_RANGED,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrPMDeviationRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrPMDeviationByChannel_ReadCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 *value)
{
    ViStatus    error = VI_SUCCESS;
    ViReal64    rad;

    checkErr ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PM:DEV?", &rad) );

    *value = rad*180.0/(PI);

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPMDeviationByChannel_WriteCallback (ViSession vi,
                                                                        ViSession io,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PM:DEV %LeDEG", value) );
}

/*- TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL -*/
static IviRangeTableEntry attrPMInternalFrequencyRangeTableEntries[] =
	{
		{0.002, 20000.00, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrPMInternalFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPMInternalFrequencyRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrPMInternalFrequencyByChannel_ReadCallback (ViSession vi,
                                                                               ViSession io,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PM:INT:FREQ?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPMInternalFrequencyByChannel_WriteCallback (ViSession vi,
                                                                                ViSession io,
                                                                                ViConstString channelName,
                                                                                ViAttr attributeId,
                                                                                ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PM:INT:FREQ %Le", value) );
}

/*- TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL -*/
static IviRangeTableEntry attrPMInternalWaveformRangeTableEntries[] =
	{
		{TKAFG1K_VAL_PM_INTERNAL_SINE, 0, 0, "SIN", 0},
		{TKAFG1K_VAL_PM_INTERNAL_SQUARE, 0, 0, "SQU", 0},
		{TKAFG1K_VAL_PM_INTERNAL_RAMP_UP, 0, 0, "RAMP", 0},
		{TKAFG1K_VAL_PM_INTERNAL_PRN, 0, 0, "PRN", 0},
		{TKAFG1K_VAL_PM_INTERNAL_USER0, 0, 0, "USER0", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER1, 0, 0, "USER1", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER2, 0, 0, "USER2", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER3, 0, 0, "USER3", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER4, 0, 0, "USER4", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER5, 0, 0, "USER5", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER6, 0, 0, "USER6", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER7, 0, 0, "USER7", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER8, 0, 0, "USER8", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER9, 0, 0, "USER9", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER10, 0, 0, "USER10", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER11, 0, 0, "USER11", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER12, 0, 0, "USER12", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER13, 0, 0, "USER13", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER14, 0, 0, "USER14", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER15, 0, 0, "USER15", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER16, 0, 0, "USER16", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER17, 0, 0, "USER17", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER18, 0, 0, "USER18", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER19, 0, 0, "USER19", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER20, 0, 0, "USER20", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER21, 0, 0, "USER21", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER22, 0, 0, "USER22", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER23, 0, 0, "USER23", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER24, 0, 0, "USER24", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER25, 0, 0, "USER25", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER26, 0, 0, "USER26", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER27, 0, 0, "USER27", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER28, 0, 0, "USER28", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER29, 0, 0, "USER29", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER30, 0, 0, "USER30", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER31, 0, 0, "USER31", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER32, 0, 0, "USER32", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER33, 0, 0, "USER33", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER34, 0, 0, "USER34", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER35, 0, 0, "USER35", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER36, 0, 0, "USER36", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER37, 0, 0, "USER37", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER38, 0, 0, "USER38", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER39, 0, 0, "USER39", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER40, 0, 0, "USER40", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER41, 0, 0, "USER41", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER42, 0, 0, "USER42", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER43, 0, 0, "USER43", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER44, 0, 0, "USER44", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER45, 0, 0, "USER45", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER46, 0, 0, "USER46", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER47, 0, 0, "USER47", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER48, 0, 0, "USER48", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER49, 0, 0, "USER49", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER50, 0, 0, "USER50", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER51, 0, 0, "USER51", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER52, 0, 0, "USER52", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER53, 0, 0, "USER53", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER54, 0, 0, "USER54", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER55, 0, 0, "USER55", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER56, 0, 0, "USER56", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER57, 0, 0, "USER57", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER58, 0, 0, "USER58", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER59, 0, 0, "USER59", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER60, 0, 0, "USER60", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER61, 0, 0, "USER61", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER62, 0, 0, "USER62", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER63, 0, 0, "USER63", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER64, 0, 0, "USER64", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER65, 0, 0, "USER65", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER66, 0, 0, "USER66", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER67, 0, 0, "USER67", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER68, 0, 0, "USER68", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER69, 0, 0, "USER69", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER70, 0, 0, "USER70", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER71, 0, 0, "USER71", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER72, 0, 0, "USER72", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER73, 0, 0, "USER73", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER74, 0, 0, "USER74", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER75, 0, 0, "USER75", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER76, 0, 0, "USER76", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER77, 0, 0, "USER77", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER78, 0, 0, "USER78", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER79, 0, 0, "USER79", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER80, 0, 0, "USER80", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER81, 0, 0, "USER81", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER82, 0, 0, "USER82", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER83, 0, 0, "USER83", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER84, 0, 0, "USER84", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER85, 0, 0, "USER85", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER86, 0, 0, "USER86", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER87, 0, 0, "USER87", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER88, 0, 0, "USER88", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER89, 0, 0, "USER89", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER90, 0, 0, "USER90", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER91, 0, 0, "USER91", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER92, 0, 0, "USER92", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER93, 0, 0, "USER93", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER94, 0, 0, "USER94", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER95, 0, 0, "USER95", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER96, 0, 0, "USER96", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER97, 0, 0, "USER97", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER98, 0, 0, "USER98", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER99, 0, 0, "USER99", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER100, 0, 0, "USER100", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER101, 0, 0, "USER101", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER102, 0, 0, "USER102", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER103, 0, 0, "USER103", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER104, 0, 0, "USER104", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER105, 0, 0, "USER105", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER106, 0, 0, "USER106", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER107, 0, 0, "USER107", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER108, 0, 0, "USER108", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER109, 0, 0, "USER109", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER110, 0, 0, "USER110", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER111, 0, 0, "USER111", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER112, 0, 0, "USER112", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER113, 0, 0, "USER113", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER114, 0, 0, "USER114", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER115, 0, 0, "USER115", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER116, 0, 0, "USER116", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER117, 0, 0, "USER117", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER118, 0, 0, "USER118", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER119, 0, 0, "USER119", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER120, 0, 0, "USER120", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER121, 0, 0, "USER121", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER122, 0, 0, "USER122", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER123, 0, 0, "USER123", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER124, 0, 0, "USER124", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER125, 0, 0, "USER125", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER126, 0, 0, "USER126", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER127, 0, 0, "USER127", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER128, 0, 0, "USER128", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER129, 0, 0, "USER129", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER130, 0, 0, "USER130", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER131, 0, 0, "USER131", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER132, 0, 0, "USER132", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER133, 0, 0, "USER133", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER134, 0, 0, "USER134", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER135, 0, 0, "USER135", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER136, 0, 0, "USER136", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER137, 0, 0, "USER137", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER138, 0, 0, "USER138", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER139, 0, 0, "USER139", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER140, 0, 0, "USER140", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER141, 0, 0, "USER141", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER142, 0, 0, "USER142", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER143, 0, 0, "USER143", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER144, 0, 0, "USER144", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER145, 0, 0, "USER145", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER146, 0, 0, "USER146", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER147, 0, 0, "USER147", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER148, 0, 0, "USER148", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER149, 0, 0, "USER149", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER150, 0, 0, "USER150", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER151, 0, 0, "USER151", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER152, 0, 0, "USER152", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER153, 0, 0, "USER153", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER154, 0, 0, "USER154", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER155, 0, 0, "USER155", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER156, 0, 0, "USER156", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER157, 0, 0, "USER157", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER158, 0, 0, "USER158", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER159, 0, 0, "USER159", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER160, 0, 0, "USER160", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER161, 0, 0, "USER161", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER162, 0, 0, "USER162", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER163, 0, 0, "USER163", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER164, 0, 0, "USER164", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER165, 0, 0, "USER165", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER166, 0, 0, "USER166", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER167, 0, 0, "USER167", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER168, 0, 0, "USER168", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER169, 0, 0, "USER169", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER170, 0, 0, "USER170", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER171, 0, 0, "USER171", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER172, 0, 0, "USER172", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER173, 0, 0, "USER173", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER174, 0, 0, "USER174", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER175, 0, 0, "USER175", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER176, 0, 0, "USER176", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER177, 0, 0, "USER177", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER178, 0, 0, "USER178", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER179, 0, 0, "USER179", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER180, 0, 0, "USER180", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER181, 0, 0, "USER181", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER182, 0, 0, "USER182", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER183, 0, 0, "USER183", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER184, 0, 0, "USER184", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER185, 0, 0, "USER185", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER186, 0, 0, "USER186", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER187, 0, 0, "USER187", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER188, 0, 0, "USER188", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER189, 0, 0, "USER189", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER190, 0, 0, "USER190", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER191, 0, 0, "USER191", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER192, 0, 0, "USER192", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER193, 0, 0, "USER193", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER194, 0, 0, "USER194", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER195, 0, 0, "USER195", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER196, 0, 0, "USER196", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER197, 0, 0, "USER197", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER198, 0, 0, "USER198", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER199, 0, 0, "USER199", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER200, 0, 0, "USER200", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER201, 0, 0, "USER201", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER202, 0, 0, "USER202", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER203, 0, 0, "USER203", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER204, 0, 0, "USER204", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER205, 0, 0, "USER205", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER206, 0, 0, "USER206", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER207, 0, 0, "USER207", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER208, 0, 0, "USER208", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER209, 0, 0, "USER209", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER210, 0, 0, "USER210", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER211, 0, 0, "USER211", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER212, 0, 0, "USER212", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER213, 0, 0, "USER213", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER214, 0, 0, "USER214", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER215, 0, 0, "USER215", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER216, 0, 0, "USER216", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER217, 0, 0, "USER217", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER218, 0, 0, "USER218", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER219, 0, 0, "USER219", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER220, 0, 0, "USER220", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER221, 0, 0, "USER221", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER222, 0, 0, "USER222", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER223, 0, 0, "USER223", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER224, 0, 0, "USER224", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER225, 0, 0, "USER225", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER226, 0, 0, "USER226", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER227, 0, 0, "USER227", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER228, 0, 0, "USER228", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER229, 0, 0, "USER229", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER230, 0, 0, "USER230", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER231, 0, 0, "USER231", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER232, 0, 0, "USER232", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER233, 0, 0, "USER233", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER234, 0, 0, "USER234", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER235, 0, 0, "USER235", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER236, 0, 0, "USER236", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER237, 0, 0, "USER237", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER238, 0, 0, "USER238", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER239, 0, 0, "USER239", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER240, 0, 0, "USER240", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER241, 0, 0, "USER241", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER242, 0, 0, "USER242", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER243, 0, 0, "USER243", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER244, 0, 0, "USER244", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER245, 0, 0, "USER245", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER246, 0, 0, "USER246", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER247, 0, 0, "USER247", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER248, 0, 0, "USER248", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER249, 0, 0, "USER249", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER250, 0, 0, "USER250", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER251, 0, 0, "USER251", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER252, 0, 0, "USER252", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER253, 0, 0, "USER253", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER254, 0, 0, "USER254", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_USER255, 0, 0, "USER255", 0}, 
		{TKAFG1K_VAL_PM_INTERNAL_EMEM, 0, 0, "EMEM", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrPMInternalWaveformRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPMInternalWaveformRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrPMInternalWaveformByChannel_CheckCallback (ViSession vi,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    ViBoolean   wfmExists = VI_TRUE;

    checkErr( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value) );
    switch(value)
    {
        case TKAFG1K_VAL_PM_INTERNAL_USER1:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER1, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_PM_INTERNAL_USER2:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER2, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_PM_INTERNAL_USER3:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER3, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_PM_INTERNAL_USER4:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER4, &wfmExists) );
            break;
        }
    }

    if(wfmExists == VI_FALSE)
    {
        ViChar errElab[BUFFER_SIZE] = {0};
        switch( value )
        {
            case TKAFG1K_VAL_PM_INTERNAL_USER1:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PM_INTERNAL_USER1 does not exist.");
                break;
            }
            case TKAFG1K_VAL_PM_INTERNAL_USER2:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PM_INTERNAL_USER2 does not exist.");
                break;
            }
            case TKAFG1K_VAL_PM_INTERNAL_USER3:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PM_INTERNAL_USER3 does not exist.");
                break;
            }
            case TKAFG1K_VAL_PM_INTERNAL_USER4:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PM_INTERNAL_USER4 does not exist.");
                break;
            }
        }
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPMInternalWaveformByChannel_ReadCallback (ViSession vi,
                                                                              ViSession io,
                                                                              ViConstString channelName,
                                                                              ViAttr attributeId,
                                                                              ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrPMInternalWaveformRangeTable, "SOUR%s:PM:INT:FUNC?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPMInternalWaveformByChannel_WriteCallback (ViSession vi,
                                                                               ViSession io,
                                                                               ViConstString channelName,
                                                                               ViAttr attributeId,
                                                                               ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrPMInternalWaveformRangeTable, "SOUR%s:PM:INT:FUNC %s", value) );
}

/*- TKAFG1K_ATTR_PWM_ENABLED -*/
static ViStatus _VI_FUNC tkafg1kAttrPWMEnabled_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_PWM, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPWMEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
    return ( tkafg1k_ReadState (vi, io, channelName, "SOUR%s:PWM:STAT?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPWMEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
    ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:PWM:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_PWM) );
    }

Error:
    return error;
}

/*- TKAFG1K_ATTR_PWM_DEVIATION -*/
static ViStatus _VI_FUNC tkafg1kAttrPWMDeviation_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViReal64 value)
{
    ViStatus    error = VI_SUCCESS;
    ViReal64    deviation;
    ViReal64    pulseDutyCycle;

    checkErr ( Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_PULSE_DUTY_CYCLE, 0, &pulseDutyCycle) );
    deviation = value;

    if(value < 0 || value >50)
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr (error);
    }

    if(deviation > (pulseDutyCycle) || deviation >(100-pulseDutyCycle))
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr (error);
    }

Error:
    return error;
}


static ViStatus _VI_FUNC tkafg1kAttrPWMDeviation_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PWM:DEV:DCYC?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPWMDeviation_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PWM:DEV:DCYC %Lf", value) );
}

/*- TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY -*/
static IviRangeTableEntry attrPWMInternalFrequencyRangeTableEntries[] =
	{
		{0.002, 20000.00, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrPWMInternalFrequencyRangeTable =
	{
		IVI_VAL_RANGED,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPWMInternalFrequencyRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalFrequency_ReadCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PWM:INT:FREQ?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalFrequency_WriteCallback (ViSession vi,
                                                                        ViSession io,
                                                                        ViConstString channelName,
                                                                        ViAttr attributeId,
                                                                        ViReal64 value)
{
    return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PWM:INT:FREQ %Le", value) );
}

/*- TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM -*/
static IviRangeTableEntry attrPWMInternalWaveformRangeTableEntries[] =
	{
		{TKAFG1K_VAL_PWM_INTERNAL_SINE, 0, 0, "SIN", 0},
		{TKAFG1K_VAL_PWM_INTERNAL_SQUARE, 0, 0, "SQU", 0},
		{TKAFG1K_VAL_PWM_INTERNAL_RAMP_UP, 0, 0, "RAMP", 0},
		{TKAFG1K_VAL_PWM_INTERNAL_PRN, 0, 0, "PRN", 0},
		{TKAFG1K_VAL_PWM_INTERNAL_USER0, 0, 0, "USER0", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER1, 0, 0, "USER1", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER2, 0, 0, "USER2", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER3, 0, 0, "USER3", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER4, 0, 0, "USER4", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER5, 0, 0, "USER5", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER6, 0, 0, "USER6", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER7, 0, 0, "USER7", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER8, 0, 0, "USER8", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER9, 0, 0, "USER9", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER10, 0, 0, "USER10", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER11, 0, 0, "USER11", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER12, 0, 0, "USER12", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER13, 0, 0, "USER13", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER14, 0, 0, "USER14", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER15, 0, 0, "USER15", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER16, 0, 0, "USER16", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER17, 0, 0, "USER17", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER18, 0, 0, "USER18", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER19, 0, 0, "USER19", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER20, 0, 0, "USER20", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER21, 0, 0, "USER21", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER22, 0, 0, "USER22", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER23, 0, 0, "USER23", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER24, 0, 0, "USER24", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER25, 0, 0, "USER25", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER26, 0, 0, "USER26", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER27, 0, 0, "USER27", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER28, 0, 0, "USER28", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER29, 0, 0, "USER29", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER30, 0, 0, "USER30", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER31, 0, 0, "USER31", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER32, 0, 0, "USER32", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER33, 0, 0, "USER33", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER34, 0, 0, "USER34", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER35, 0, 0, "USER35", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER36, 0, 0, "USER36", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER37, 0, 0, "USER37", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER38, 0, 0, "USER38", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER39, 0, 0, "USER39", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER40, 0, 0, "USER40", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER41, 0, 0, "USER41", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER42, 0, 0, "USER42", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER43, 0, 0, "USER43", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER44, 0, 0, "USER44", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER45, 0, 0, "USER45", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER46, 0, 0, "USER46", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER47, 0, 0, "USER47", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER48, 0, 0, "USER48", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER49, 0, 0, "USER49", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER50, 0, 0, "USER50", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER51, 0, 0, "USER51", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER52, 0, 0, "USER52", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER53, 0, 0, "USER53", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER54, 0, 0, "USER54", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER55, 0, 0, "USER55", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER56, 0, 0, "USER56", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER57, 0, 0, "USER57", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER58, 0, 0, "USER58", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER59, 0, 0, "USER59", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER60, 0, 0, "USER60", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER61, 0, 0, "USER61", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER62, 0, 0, "USER62", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER63, 0, 0, "USER63", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER64, 0, 0, "USER64", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER65, 0, 0, "USER65", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER66, 0, 0, "USER66", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER67, 0, 0, "USER67", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER68, 0, 0, "USER68", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER69, 0, 0, "USER69", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER70, 0, 0, "USER70", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER71, 0, 0, "USER71", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER72, 0, 0, "USER72", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER73, 0, 0, "USER73", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER74, 0, 0, "USER74", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER75, 0, 0, "USER75", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER76, 0, 0, "USER76", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER77, 0, 0, "USER77", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER78, 0, 0, "USER78", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER79, 0, 0, "USER79", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER80, 0, 0, "USER80", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER81, 0, 0, "USER81", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER82, 0, 0, "USER82", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER83, 0, 0, "USER83", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER84, 0, 0, "USER84", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER85, 0, 0, "USER85", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER86, 0, 0, "USER86", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER87, 0, 0, "USER87", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER88, 0, 0, "USER88", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER89, 0, 0, "USER89", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER90, 0, 0, "USER90", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER91, 0, 0, "USER91", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER92, 0, 0, "USER92", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER93, 0, 0, "USER93", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER94, 0, 0, "USER94", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER95, 0, 0, "USER95", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER96, 0, 0, "USER96", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER97, 0, 0, "USER97", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER98, 0, 0, "USER98", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER99, 0, 0, "USER99", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER100, 0, 0, "USER100", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER101, 0, 0, "USER101", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER102, 0, 0, "USER102", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER103, 0, 0, "USER103", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER104, 0, 0, "USER104", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER105, 0, 0, "USER105", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER106, 0, 0, "USER106", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER107, 0, 0, "USER107", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER108, 0, 0, "USER108", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER109, 0, 0, "USER109", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER110, 0, 0, "USER110", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER111, 0, 0, "USER111", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER112, 0, 0, "USER112", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER113, 0, 0, "USER113", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER114, 0, 0, "USER114", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER115, 0, 0, "USER115", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER116, 0, 0, "USER116", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER117, 0, 0, "USER117", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER118, 0, 0, "USER118", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER119, 0, 0, "USER119", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER120, 0, 0, "USER120", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER121, 0, 0, "USER121", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER122, 0, 0, "USER122", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER123, 0, 0, "USER123", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER124, 0, 0, "USER124", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER125, 0, 0, "USER125", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER126, 0, 0, "USER126", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER127, 0, 0, "USER127", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER128, 0, 0, "USER128", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER129, 0, 0, "USER129", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER130, 0, 0, "USER130", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER131, 0, 0, "USER131", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER132, 0, 0, "USER132", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER133, 0, 0, "USER133", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER134, 0, 0, "USER134", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER135, 0, 0, "USER135", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER136, 0, 0, "USER136", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER137, 0, 0, "USER137", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER138, 0, 0, "USER138", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER139, 0, 0, "USER139", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER140, 0, 0, "USER140", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER141, 0, 0, "USER141", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER142, 0, 0, "USER142", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER143, 0, 0, "USER143", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER144, 0, 0, "USER144", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER145, 0, 0, "USER145", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER146, 0, 0, "USER146", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER147, 0, 0, "USER147", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER148, 0, 0, "USER148", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER149, 0, 0, "USER149", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER150, 0, 0, "USER150", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER151, 0, 0, "USER151", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER152, 0, 0, "USER152", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER153, 0, 0, "USER153", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER154, 0, 0, "USER154", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER155, 0, 0, "USER155", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER156, 0, 0, "USER156", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER157, 0, 0, "USER157", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER158, 0, 0, "USER158", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER159, 0, 0, "USER159", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER160, 0, 0, "USER160", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER161, 0, 0, "USER161", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER162, 0, 0, "USER162", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER163, 0, 0, "USER163", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER164, 0, 0, "USER164", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER165, 0, 0, "USER165", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER166, 0, 0, "USER166", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER167, 0, 0, "USER167", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER168, 0, 0, "USER168", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER169, 0, 0, "USER169", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER170, 0, 0, "USER170", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER171, 0, 0, "USER171", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER172, 0, 0, "USER172", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER173, 0, 0, "USER173", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER174, 0, 0, "USER174", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER175, 0, 0, "USER175", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER176, 0, 0, "USER176", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER177, 0, 0, "USER177", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER178, 0, 0, "USER178", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER179, 0, 0, "USER179", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER180, 0, 0, "USER180", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER181, 0, 0, "USER181", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER182, 0, 0, "USER182", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER183, 0, 0, "USER183", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER184, 0, 0, "USER184", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER185, 0, 0, "USER185", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER186, 0, 0, "USER186", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER187, 0, 0, "USER187", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER188, 0, 0, "USER188", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER189, 0, 0, "USER189", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER190, 0, 0, "USER190", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER191, 0, 0, "USER191", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER192, 0, 0, "USER192", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER193, 0, 0, "USER193", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER194, 0, 0, "USER194", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER195, 0, 0, "USER195", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER196, 0, 0, "USER196", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER197, 0, 0, "USER197", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER198, 0, 0, "USER198", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER199, 0, 0, "USER199", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER200, 0, 0, "USER200", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER201, 0, 0, "USER201", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER202, 0, 0, "USER202", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER203, 0, 0, "USER203", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER204, 0, 0, "USER204", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER205, 0, 0, "USER205", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER206, 0, 0, "USER206", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER207, 0, 0, "USER207", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER208, 0, 0, "USER208", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER209, 0, 0, "USER209", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER210, 0, 0, "USER210", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER211, 0, 0, "USER211", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER212, 0, 0, "USER212", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER213, 0, 0, "USER213", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER214, 0, 0, "USER214", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER215, 0, 0, "USER215", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER216, 0, 0, "USER216", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER217, 0, 0, "USER217", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER218, 0, 0, "USER218", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER219, 0, 0, "USER219", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER220, 0, 0, "USER220", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER221, 0, 0, "USER221", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER222, 0, 0, "USER222", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER223, 0, 0, "USER223", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER224, 0, 0, "USER224", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER225, 0, 0, "USER225", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER226, 0, 0, "USER226", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER227, 0, 0, "USER227", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER228, 0, 0, "USER228", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER229, 0, 0, "USER229", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER230, 0, 0, "USER230", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER231, 0, 0, "USER231", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER232, 0, 0, "USER232", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER233, 0, 0, "USER233", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER234, 0, 0, "USER234", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER235, 0, 0, "USER235", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER236, 0, 0, "USER236", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER237, 0, 0, "USER237", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER238, 0, 0, "USER238", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER239, 0, 0, "USER239", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER240, 0, 0, "USER240", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER241, 0, 0, "USER241", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER242, 0, 0, "USER242", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER243, 0, 0, "USER243", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER244, 0, 0, "USER244", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER245, 0, 0, "USER245", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER246, 0, 0, "USER246", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER247, 0, 0, "USER247", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER248, 0, 0, "USER248", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER249, 0, 0, "USER249", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER250, 0, 0, "USER250", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER251, 0, 0, "USER251", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER252, 0, 0, "USER252", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER253, 0, 0, "USER253", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER254, 0, 0, "USER254", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_USER255, 0, 0, "USER255", 0}, 
		{TKAFG1K_VAL_PWM_INTERNAL_EMEM, 0, 0, "EMEM", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};
static IviRangeTable attrPWMInternalWaveformRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrPWMInternalWaveformRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalWaveform_CheckCallback (ViSession vi,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViInt32 value)
{
    ViStatus    error = VI_SUCCESS;
    ViBoolean wfmExists = VI_TRUE;

    checkErr( Ivi_DefaultCheckCallbackViInt32 (vi, channelName, attributeId, value) );
    switch(value)
    {
        case TKAFG1K_VAL_PWM_INTERNAL_USER1:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER1, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_PWM_INTERNAL_USER2:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER2, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_PWM_INTERNAL_USER3:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER3, &wfmExists) );
            break;
        }
        case TKAFG1K_VAL_PWM_INTERNAL_USER4:
        {
            checkErr( tkafg1k_WfmExists (vi, TKAFG1K_VAL_WFM_USER4, &wfmExists) );
            break;
        }
    }

    if(wfmExists == VI_FALSE)
    {
        ViChar errElab[BUFFER_SIZE] = {0};
        switch( value )
        {
            case TKAFG1K_VAL_PWM_INTERNAL_USER1:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PWM_INTERNAL_USER1 does not exist.");
                break;
            }
            case TKAFG1K_VAL_PWM_INTERNAL_USER2:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PWM_INTERNAL_USER2 does not exist.");
                break;
            }
            case TKAFG1K_VAL_PWM_INTERNAL_USER3:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PWM_INTERNAL_USER3 does not exist.");
                break;
            }
            case TKAFG1K_VAL_PWM_INTERNAL_USER4:
            {
                sprintf(errElab, "The specified waveform TKAFG1K_VAL_PWM_INTERNAL_USER4 does not exist.");
                break;
            }
        }
        viCheckErrElab( IVI_ERROR_INVALID_VALUE, errElab);
    }

Error:
    return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalWaveform_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrPWMInternalWaveformRangeTable, "SOUR%s:PWM:INT:FUNC?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPWMInternalWaveform_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrPWMInternalWaveformRangeTable, "SOUR%s:PWM:INT:FUNC %s", value) );
}

/*- TKAFG1K_ATTR_PWM_SOURCE -*/
static IviRangeTableEntry attrPWMSourceRangeTableEntries[] =
{
    {TKAFG1K_VAL_PWM_INTERNAL, 0, 0, "INT", 0},
    {TKAFG1K_VAL_PWM_EXTERNAL, 0, 0, "EXT", 0},
    {IVI_RANGE_TABLE_LAST_ENTRY}
};
static IviRangeTable attrPWMSourceRangeTable =
{
    IVI_VAL_DISCRETE,
    VI_TRUE,
    VI_TRUE,
    VI_NULL,
    attrPWMSourceRangeTableEntries,
};

static ViStatus _VI_FUNC tkafg1kAttrPWMSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName, &attrPWMSourceRangeTable, "SOUR%s:PWM:SOUR?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPWMSource_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value)
{
    return ( tkafg1k_WriteCmd (vi, io, channelName, &attrPWMSourceRangeTable, "SOUR%s:PWM:SOUR %s", value) );
}

/*- TKAFG1K_ATTR_AMPLITUDE -*/
static ViStatus _VI_FUNC tkafg1kAttrAmplitude_CheckCallback (ViSession vi,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value)
{
    ViStatus    error = VI_SUCCESS;
    ViReal64    amplitudeUpperLimit, amplitudeLowerLimit;
    ViReal64    impedance;
	ViInt32		model;
	checkErr (Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model));
    checkErr( Ivi_GetAttributeViReal64(vi, channelName, TKAFG1K_ATTR_OUTPUT_IMPEDANCE, 0, &impedance) );
	 
    
	if (model == TKAFG1K_VAL_MODEL_AFG1022){
	    /* Limit in Open Circuit */
	    if(impedance == TKAFG1K_VAL_IMPEDANCE_INFINITY)
	    {
	        amplitudeUpperLimit = AFG1022_VAL_MAX_AMPL_IN_OPEN;
	        amplitudeLowerLimit = AFG1022_VAL_MIN_AMPL_IN_OPEN;
	    }
	    /* Limit in impedance of 50 */
	    else if(impedance == 50)
	    {
	        amplitudeUpperLimit = AFG1022_VAL_MAX_AMPL_IN_50OHM;
	        amplitudeLowerLimit = AFG1022_VAL_MIN_AMPL_IN_50OHM;
	    }
	}else if (model == TKAFG1K_VAL_MODEL_AFG1062){
		ViReal64    frequency;
    	checkErr( Ivi_GetAttributeViReal64(vi, channelName, TKAFG1K_ATTR_FREQUENCY, 0, &frequency) );
		if (frequency <=25e6){
			/* Limit in Open Circuit */
		    if(impedance == TKAFG1K_VAL_IMPEDANCE_INFINITY)
		    {
		        amplitudeUpperLimit = AFG1062_VAL_MAX_AMPL_IN_OPEN;
		        amplitudeLowerLimit = AFG1062_VAL_MIN_AMPL_IN_OPEN;
		    }
		    /* Limit in impedance of 50 */
		    else if(impedance == 50)
		    {
		        amplitudeUpperLimit = AFG1062_VAL_MAX_AMPL_IN_50OHM;
		        amplitudeLowerLimit = AFG1062_VAL_MIN_AMPL_IN_50OHM;
		    }
		}else{
			/* Limit in Open Circuit */
		    if(impedance == TKAFG1K_VAL_IMPEDANCE_INFINITY)
		    {
		        amplitudeUpperLimit = AFG1062_VAL_MAX_AMPL_IN_OPEN_HIGH_FREQ;
		        amplitudeLowerLimit = AFG1062_VAL_MIN_AMPL_IN_OPEN_HIGH_FREQ;
		    }
		    /* Limit in impedance of 50 */
		    else if(impedance == 50)
		    {
		        amplitudeUpperLimit = AFG1062_VAL_MAX_AMPL_IN_50OHM_HIGH_FREQ;
		        amplitudeLowerLimit = AFG1062_VAL_MIN_AMPL_IN_50OHM_HIGH_FREQ;
		    }
		}
	}
Error:
    return error;
}




static ViStatus _VI_FUNC tkafg1kAttrAmplitude_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 *value)
{
    return ( tkafg1k_ReadReal64(vi, io, channelName, "SOUR%s:VOLT:LEV:IMM:AMPL?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAmplitude_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value)
{
    ViStatus error = VI_SUCCESS;
    ViReal64 offset;

    viCheckErr (Ivi_GetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_OFFSET, 0, &offset));

    viCheckErr (viPrintf (io, "SOUR%s:VOLT:OFFS 0", channelName));

    viCheckErr (Ivi_InvalidateAttribute (vi, channelName, TKAFG1K_ATTR_OFFSET));

    checkErr (tkafg1k_WriteReal64(vi, io, channelName, "SOUR%s:VOLT:LEV:IMM:AMPL %Le", value));

    viCheckErr (Ivi_SetAttributeViReal64 (vi, channelName, TKAFG1K_ATTR_OFFSET, 0, offset));
Error:
    return error;
}

/*- TKAFG1K_ATTR_OFFSET -*/
    
static ViStatus _VI_FUNC tkafg1kAttrOffset_CheckCallback (ViSession vi,
                                                          ViConstString channelName,
                                                          ViAttr attributeId,
                                                          ViReal64 value)
{
    ViStatus    error = VI_SUCCESS;
    ViReal64    offsetUpperLimit, offsetLowerLimit;
    ViReal64    amplitude;
    ViReal64    impedance;


    checkErr( Ivi_GetAttributeViReal64(vi, channelName, TKAFG1K_ATTR_AMPLITUDE, 0, &amplitude) );

    checkErr( Ivi_GetAttributeViReal64(vi, channelName, TKAFG1K_ATTR_OUTPUT_IMPEDANCE, 0, &impedance) );

    /* Limit in Open Circuit */
    if(impedance == TKAFG1K_VAL_IMPEDANCE_INFINITY)
    {
        offsetUpperLimit = TKAFG1K_VAL_MAX_OFFSET_IN_OPEN;
        offsetLowerLimit = TKAFG1K_VAL_MIN_OFFSET_IN_OPEN;
    }
    else
    {
        offsetUpperLimit = TKAFG1K_VAL_MAX_OFFSET_IN_50OHM;
        offsetLowerLimit = TKAFG1K_VAL_MIN_OFFSET_IN_50OHM;
    }

    /*- To ensure that set offset plus amplitude does not exceeds voltage high limit and voltage lower limit -*/
    if( ((value+amplitude/2) > offsetUpperLimit) ||((value-amplitude/2) < offsetLowerLimit) )
    {
        error = IVI_ERROR_INVALID_VALUE;
        viCheckErr(error);
    }

Error:
    return error;
}

   

static ViStatus _VI_FUNC tkafg1kAttrOffset_ReadCallback (ViSession vi,
                                                         ViSession io,
                                                         ViConstString channelName,
                                                         ViAttr attributeId,
                                                         ViReal64 *value)
{
    return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:VOLT:OFFS?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrOffset_WriteCallback (ViSession vi,
                                                          ViSession io,
                                                          ViConstString channelName,
                                                          ViAttr attributeId,
                                                          ViReal64 value)
{
    return ( tkafg1k_WriteReal64(vi, io, channelName, "SOUR%s:VOLT:OFFS %Le", value) );
}

/*- TKAFG1K_ATTR_FREQUENCY -*/
static ViStatus _VI_FUNC tkafg1kAttrFrequency_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViReal64 *value)
{
    return ( tkafg1k_ReadReal64(vi, io, channelName, "SOUR%s:FREQ?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrFrequency_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViReal64 value)
{

    return ( tkafg1k_WriteReal64(vi, io, channelName, "SOUR%s:FREQ %Le", value) );
}

/*- TKAFG1K_ATTR_WAVEFORM -*/
static IviRangeTableEntry attrWaveformRangeTableEntries[] =
	{
		{TKAFG1K_VAL_WFM_SINE, 0, 0, "SIN", 0},
		{TKAFG1K_VAL_WFM_SQUARE, 0, 0, "SQU", 0},
		{TKAFG1K_VAL_WFM_RAMP, 0, 0, "RAMP", 0},
		{TKAFG1K_VAL_WFM_PULS, 0, 0, "PULS", 0},
		{TKAFG1K_VAL_WFM_PRN, 0, 0, "PRN", 0},
		{TKAFG1K_VAL_WFM_STAIRDOWN, 0, 0, "StairDown", 0}, 
		{TKAFG1K_VAL_WFM_STAIRUP, 0, 0, "StairUp", 0}, 
		{TKAFG1K_VAL_WFM_STAIR, 0, 0, "Stair", 0}, 
		{TKAFG1K_VAL_WFM_TRAPEZOID, 0, 0, "Trapezoid", 0}, 
		{TKAFG1K_VAL_WFM_ROUNDHALF, 0, 0, "RoundHalf", 0}, 
		{TKAFG1K_VAL_WFM_ABSSINE, 0, 0, "AbsSine", 0}, 
		{TKAFG1K_VAL_WFM_ABSHALFSINE, 0, 0, "AbsHalfSine", 0}, 
		{TKAFG1K_VAL_WFM_CLIPPEDSINE, 0, 0, "ClippedSine", 0}, 
		{TKAFG1K_VAL_WFM_CHOPPEDSINE, 0, 0, "ChoppedSine", 0}, 
		{TKAFG1K_VAL_WFM_NEGRAMP, 0, 0, "NegRamp", 0}, 
		{TKAFG1K_VAL_WFM_OSCDECAY, 0, 0, "OscDecay", 0}, 
		{TKAFG1K_VAL_WFM_OSCRISE, 0, 0, "OscRise", 0}, 
		{TKAFG1K_VAL_WFM_CODEDPULSE, 0, 0, "CodedPulse", 0}, 
		{TKAFG1K_VAL_WFM_POSPULSE, 0, 0, "PosPulse", 0}, 
		{TKAFG1K_VAL_WFM_NEGPULSE, 0, 0, "NegPulse", 0}, 
		{TKAFG1K_VAL_WFM_EXPRISE, 0, 0, "ExpRise", 0}, 
		{TKAFG1K_VAL_WFM_EXPDECAY, 0, 0, "ExpDecay", 0}, 
		{TKAFG1K_VAL_WFM_SINC, 0, 0, "Sinc", 0}, 
		{TKAFG1K_VAL_WFM_TAN, 0, 0, "Tan", 0}, 
		{TKAFG1K_VAL_WFM_COTAN, 0, 0, "Cotan", 0}, 
		{TKAFG1K_VAL_WFM_SQUAREROOT, 0, 0, "SquareRoot", 0}, 
		{TKAFG1K_VAL_WFM_X_2, 0, 0, "X^2", 0}, 
		{TKAFG1K_VAL_WFM_HAVERSINE, 0, 0, "HaverSine", 0}, 
		{TKAFG1K_VAL_WFM_LORENTZ, 0, 0, "Lorentz", 0}, 
		{TKAFG1K_VAL_WFM_LN_X, 0, 0, "Ln(x)", 0}, 
		{TKAFG1K_VAL_WFM_X_3, 0, 0, "X^3", 0}, 
		{TKAFG1K_VAL_WFM_CAUCHYDISTR, 0, 0, "CauchyDistr", 0}, 
		{TKAFG1K_VAL_WFM_BESSELJ, 0, 0, "BesselJ", 0}, 
		{TKAFG1K_VAL_WFM_BESSELY, 0, 0, "BesselY", 0}, 
		{TKAFG1K_VAL_WFM_ERRORFUNC, 0, 0, "ErrorFunc", 0}, 
		{TKAFG1K_VAL_WFM_AIRY, 0, 0, "Airy", 0}, 
		{TKAFG1K_VAL_WFM_RECTANGLE, 0, 0, "Rectangle", 0}, 
		{TKAFG1K_VAL_WFM_GAUSS, 0, 0, "Gauss", 0}, 
		{TKAFG1K_VAL_WFM_HAMMING, 0, 0, "Hamming", 0}, 
		{TKAFG1K_VAL_WFM_HANNING, 0, 0, "Hanning", 0}, 
		{TKAFG1K_VAL_WFM_BARTLETT, 0, 0, "Bartlett", 0}, 
		{TKAFG1K_VAL_WFM_BLACKMAN, 0, 0, "Blackman", 0}, 
		{TKAFG1K_VAL_WFM_LAYLIGHT, 0, 0, "Laylight", 0}, 
		{TKAFG1K_VAL_WFM_TRIANGLE, 0, 0, "Triangle", 0}, 
		{TKAFG1K_VAL_WFM_DC, 0, 0, "DC", 0}, 
		{TKAFG1K_VAL_WFM_HEART, 0, 0, "Heart", 0}, 
		{TKAFG1K_VAL_WFM_ROUND, 0, 0, "Round", 0}, 
		{TKAFG1K_VAL_WFM_CHIRP, 0, 0, "Chirp", 0}, 
		{TKAFG1K_VAL_WFM_RHOMBUS, 0, 0, "Rhombus", 0}, 
		{TKAFG1K_VAL_WFM_CARDIAC, 0, 0, "Cardiac", 0}, 
		{TKAFG1K_VAL_WFM_USER0, 0, 0, "USER0", 0},
		{TKAFG1K_VAL_WFM_USER1, 0, 0, "USER1", 0},
		{TKAFG1K_VAL_WFM_USER2, 0, 0, "USER2", 0},
		{TKAFG1K_VAL_WFM_USER3, 0, 0, "USER3", 0},
		{TKAFG1K_VAL_WFM_USER4, 0, 0, "USER4", 0},
		{TKAFG1K_VAL_WFM_USER5, 0, 0, "USER5", 0},
		{TKAFG1K_VAL_WFM_USER6, 0, 0, "USER6", 0},
		{TKAFG1K_VAL_WFM_USER7, 0, 0, "USER7", 0},
		{TKAFG1K_VAL_WFM_USER8, 0, 0, "USER8", 0},
		{TKAFG1K_VAL_WFM_USER9, 0, 0, "USER9", 0},
		{TKAFG1K_VAL_WFM_USER10, 0, 0, "USER10", 0},
		{TKAFG1K_VAL_WFM_USER11, 0, 0, "USER11", 0},
		{TKAFG1K_VAL_WFM_USER12, 0, 0, "USER12", 0},
		{TKAFG1K_VAL_WFM_USER13, 0, 0, "USER13", 0},
		{TKAFG1K_VAL_WFM_USER14, 0, 0, "USER14", 0},
		{TKAFG1K_VAL_WFM_USER15, 0, 0, "USER15", 0},
		{TKAFG1K_VAL_WFM_USER16, 0, 0, "USER16", 0},
		{TKAFG1K_VAL_WFM_USER17, 0, 0, "USER17", 0},
		{TKAFG1K_VAL_WFM_USER18, 0, 0, "USER18", 0},
		{TKAFG1K_VAL_WFM_USER19, 0, 0, "USER19", 0},
		{TKAFG1K_VAL_WFM_USER20, 0, 0, "USER20", 0},
		{TKAFG1K_VAL_WFM_USER21, 0, 0, "USER21", 0},
		{TKAFG1K_VAL_WFM_USER22, 0, 0, "USER22", 0},
		{TKAFG1K_VAL_WFM_USER23, 0, 0, "USER23", 0},
		{TKAFG1K_VAL_WFM_USER24, 0, 0, "USER24", 0},
		{TKAFG1K_VAL_WFM_USER25, 0, 0, "USER25", 0},
		{TKAFG1K_VAL_WFM_USER26, 0, 0, "USER26", 0},
		{TKAFG1K_VAL_WFM_USER27, 0, 0, "USER27", 0},
		{TKAFG1K_VAL_WFM_USER28, 0, 0, "USER28", 0},
		{TKAFG1K_VAL_WFM_USER29, 0, 0, "USER29", 0},
		{TKAFG1K_VAL_WFM_USER30, 0, 0, "USER30", 0},
		{TKAFG1K_VAL_WFM_USER31, 0, 0, "USER31", 0},
		{TKAFG1K_VAL_WFM_USER32, 0, 0, "USER32", 0},
		{TKAFG1K_VAL_WFM_USER33, 0, 0, "USER33", 0},
		{TKAFG1K_VAL_WFM_USER34, 0, 0, "USER34", 0},
		{TKAFG1K_VAL_WFM_USER35, 0, 0, "USER35", 0},
		{TKAFG1K_VAL_WFM_USER36, 0, 0, "USER36", 0},
		{TKAFG1K_VAL_WFM_USER37, 0, 0, "USER37", 0},
		{TKAFG1K_VAL_WFM_USER38, 0, 0, "USER38", 0},
		{TKAFG1K_VAL_WFM_USER39, 0, 0, "USER39", 0},
		{TKAFG1K_VAL_WFM_USER40, 0, 0, "USER40", 0},
		{TKAFG1K_VAL_WFM_USER41, 0, 0, "USER41", 0},
		{TKAFG1K_VAL_WFM_USER42, 0, 0, "USER42", 0},
		{TKAFG1K_VAL_WFM_USER43, 0, 0, "USER43", 0},
		{TKAFG1K_VAL_WFM_USER44, 0, 0, "USER44", 0},
		{TKAFG1K_VAL_WFM_USER45, 0, 0, "USER45", 0},
		{TKAFG1K_VAL_WFM_USER46, 0, 0, "USER46", 0},
		{TKAFG1K_VAL_WFM_USER47, 0, 0, "USER47", 0},
		{TKAFG1K_VAL_WFM_USER48, 0, 0, "USER48", 0},
		{TKAFG1K_VAL_WFM_USER49, 0, 0, "USER49", 0},
		{TKAFG1K_VAL_WFM_USER50, 0, 0, "USER50", 0},
		{TKAFG1K_VAL_WFM_USER51, 0, 0, "USER51", 0},
		{TKAFG1K_VAL_WFM_USER52, 0, 0, "USER52", 0},
		{TKAFG1K_VAL_WFM_USER53, 0, 0, "USER53", 0},
		{TKAFG1K_VAL_WFM_USER54, 0, 0, "USER54", 0},
		{TKAFG1K_VAL_WFM_USER55, 0, 0, "USER55", 0},
		{TKAFG1K_VAL_WFM_USER56, 0, 0, "USER56", 0},
		{TKAFG1K_VAL_WFM_USER57, 0, 0, "USER57", 0},
		{TKAFG1K_VAL_WFM_USER58, 0, 0, "USER58", 0},
		{TKAFG1K_VAL_WFM_USER59, 0, 0, "USER59", 0},
		{TKAFG1K_VAL_WFM_USER60, 0, 0, "USER60", 0},
		{TKAFG1K_VAL_WFM_USER61, 0, 0, "USER61", 0},
		{TKAFG1K_VAL_WFM_USER62, 0, 0, "USER62", 0},
		{TKAFG1K_VAL_WFM_USER63, 0, 0, "USER63", 0},
		{TKAFG1K_VAL_WFM_USER64, 0, 0, "USER64", 0},
		{TKAFG1K_VAL_WFM_USER65, 0, 0, "USER65", 0},
		{TKAFG1K_VAL_WFM_USER66, 0, 0, "USER66", 0},
		{TKAFG1K_VAL_WFM_USER67, 0, 0, "USER67", 0},
		{TKAFG1K_VAL_WFM_USER68, 0, 0, "USER68", 0},
		{TKAFG1K_VAL_WFM_USER69, 0, 0, "USER69", 0},
		{TKAFG1K_VAL_WFM_USER70, 0, 0, "USER70", 0},
		{TKAFG1K_VAL_WFM_USER71, 0, 0, "USER71", 0},
		{TKAFG1K_VAL_WFM_USER72, 0, 0, "USER72", 0},
		{TKAFG1K_VAL_WFM_USER73, 0, 0, "USER73", 0},
		{TKAFG1K_VAL_WFM_USER74, 0, 0, "USER74", 0},
		{TKAFG1K_VAL_WFM_USER75, 0, 0, "USER75", 0},
		{TKAFG1K_VAL_WFM_USER76, 0, 0, "USER76", 0},
		{TKAFG1K_VAL_WFM_USER77, 0, 0, "USER77", 0},
		{TKAFG1K_VAL_WFM_USER78, 0, 0, "USER78", 0},
		{TKAFG1K_VAL_WFM_USER79, 0, 0, "USER79", 0},
		{TKAFG1K_VAL_WFM_USER80, 0, 0, "USER80", 0},
		{TKAFG1K_VAL_WFM_USER81, 0, 0, "USER81", 0},
		{TKAFG1K_VAL_WFM_USER82, 0, 0, "USER82", 0},
		{TKAFG1K_VAL_WFM_USER83, 0, 0, "USER83", 0},
		{TKAFG1K_VAL_WFM_USER84, 0, 0, "USER84", 0},
		{TKAFG1K_VAL_WFM_USER85, 0, 0, "USER85", 0},
		{TKAFG1K_VAL_WFM_USER86, 0, 0, "USER86", 0},
		{TKAFG1K_VAL_WFM_USER87, 0, 0, "USER87", 0},
		{TKAFG1K_VAL_WFM_USER88, 0, 0, "USER88", 0},
		{TKAFG1K_VAL_WFM_USER89, 0, 0, "USER89", 0},
		{TKAFG1K_VAL_WFM_USER90, 0, 0, "USER90", 0},
		{TKAFG1K_VAL_WFM_USER91, 0, 0, "USER91", 0},
		{TKAFG1K_VAL_WFM_USER92, 0, 0, "USER92", 0},
		{TKAFG1K_VAL_WFM_USER93, 0, 0, "USER93", 0},
		{TKAFG1K_VAL_WFM_USER94, 0, 0, "USER94", 0},
		{TKAFG1K_VAL_WFM_USER95, 0, 0, "USER95", 0},
		{TKAFG1K_VAL_WFM_USER96, 0, 0, "USER96", 0},
		{TKAFG1K_VAL_WFM_USER97, 0, 0, "USER97", 0},
		{TKAFG1K_VAL_WFM_USER98, 0, 0, "USER98", 0},
		{TKAFG1K_VAL_WFM_USER99, 0, 0, "USER99", 0},
		{TKAFG1K_VAL_WFM_USER100, 0, 0, "USER100", 0},
		{TKAFG1K_VAL_WFM_USER101, 0, 0, "USER101", 0},
		{TKAFG1K_VAL_WFM_USER102, 0, 0, "USER102", 0},
		{TKAFG1K_VAL_WFM_USER103, 0, 0, "USER103", 0},
		{TKAFG1K_VAL_WFM_USER104, 0, 0, "USER104", 0},
		{TKAFG1K_VAL_WFM_USER105, 0, 0, "USER105", 0},
		{TKAFG1K_VAL_WFM_USER106, 0, 0, "USER106", 0},
		{TKAFG1K_VAL_WFM_USER107, 0, 0, "USER107", 0},
		{TKAFG1K_VAL_WFM_USER108, 0, 0, "USER108", 0},
		{TKAFG1K_VAL_WFM_USER109, 0, 0, "USER109", 0},
		{TKAFG1K_VAL_WFM_USER110, 0, 0, "USER110", 0},
		{TKAFG1K_VAL_WFM_USER111, 0, 0, "USER111", 0},
		{TKAFG1K_VAL_WFM_USER112, 0, 0, "USER112", 0},
		{TKAFG1K_VAL_WFM_USER113, 0, 0, "USER113", 0},
		{TKAFG1K_VAL_WFM_USER114, 0, 0, "USER114", 0},
		{TKAFG1K_VAL_WFM_USER115, 0, 0, "USER115", 0},
		{TKAFG1K_VAL_WFM_USER116, 0, 0, "USER116", 0},
		{TKAFG1K_VAL_WFM_USER117, 0, 0, "USER117", 0},
		{TKAFG1K_VAL_WFM_USER118, 0, 0, "USER118", 0},
		{TKAFG1K_VAL_WFM_USER119, 0, 0, "USER119", 0},
		{TKAFG1K_VAL_WFM_USER120, 0, 0, "USER120", 0},
		{TKAFG1K_VAL_WFM_USER121, 0, 0, "USER121", 0},
		{TKAFG1K_VAL_WFM_USER122, 0, 0, "USER122", 0},
		{TKAFG1K_VAL_WFM_USER123, 0, 0, "USER123", 0},
		{TKAFG1K_VAL_WFM_USER124, 0, 0, "USER124", 0},
		{TKAFG1K_VAL_WFM_USER125, 0, 0, "USER125", 0},
		{TKAFG1K_VAL_WFM_USER126, 0, 0, "USER126", 0},
		{TKAFG1K_VAL_WFM_USER127, 0, 0, "USER127", 0},
		{TKAFG1K_VAL_WFM_USER128, 0, 0, "USER128", 0},
		{TKAFG1K_VAL_WFM_USER129, 0, 0, "USER129", 0},
		{TKAFG1K_VAL_WFM_USER130, 0, 0, "USER130", 0},
		{TKAFG1K_VAL_WFM_USER131, 0, 0, "USER131", 0},
		{TKAFG1K_VAL_WFM_USER132, 0, 0, "USER132", 0},
		{TKAFG1K_VAL_WFM_USER133, 0, 0, "USER133", 0},
		{TKAFG1K_VAL_WFM_USER134, 0, 0, "USER134", 0},
		{TKAFG1K_VAL_WFM_USER135, 0, 0, "USER135", 0},
		{TKAFG1K_VAL_WFM_USER136, 0, 0, "USER136", 0},
		{TKAFG1K_VAL_WFM_USER137, 0, 0, "USER137", 0},
		{TKAFG1K_VAL_WFM_USER138, 0, 0, "USER138", 0},
		{TKAFG1K_VAL_WFM_USER139, 0, 0, "USER139", 0},
		{TKAFG1K_VAL_WFM_USER140, 0, 0, "USER140", 0},
		{TKAFG1K_VAL_WFM_USER141, 0, 0, "USER141", 0},
		{TKAFG1K_VAL_WFM_USER142, 0, 0, "USER142", 0},
		{TKAFG1K_VAL_WFM_USER143, 0, 0, "USER143", 0},
		{TKAFG1K_VAL_WFM_USER144, 0, 0, "USER144", 0},
		{TKAFG1K_VAL_WFM_USER145, 0, 0, "USER145", 0},
		{TKAFG1K_VAL_WFM_USER146, 0, 0, "USER146", 0},
		{TKAFG1K_VAL_WFM_USER147, 0, 0, "USER147", 0},
		{TKAFG1K_VAL_WFM_USER148, 0, 0, "USER148", 0},
		{TKAFG1K_VAL_WFM_USER149, 0, 0, "USER149", 0},
		{TKAFG1K_VAL_WFM_USER150, 0, 0, "USER150", 0},
		{TKAFG1K_VAL_WFM_USER151, 0, 0, "USER151", 0},
		{TKAFG1K_VAL_WFM_USER152, 0, 0, "USER152", 0},
		{TKAFG1K_VAL_WFM_USER153, 0, 0, "USER153", 0},
		{TKAFG1K_VAL_WFM_USER154, 0, 0, "USER154", 0},
		{TKAFG1K_VAL_WFM_USER155, 0, 0, "USER155", 0},
		{TKAFG1K_VAL_WFM_USER156, 0, 0, "USER156", 0},
		{TKAFG1K_VAL_WFM_USER157, 0, 0, "USER157", 0},
		{TKAFG1K_VAL_WFM_USER158, 0, 0, "USER158", 0},
		{TKAFG1K_VAL_WFM_USER159, 0, 0, "USER159", 0},
		{TKAFG1K_VAL_WFM_USER160, 0, 0, "USER160", 0},
		{TKAFG1K_VAL_WFM_USER161, 0, 0, "USER161", 0},
		{TKAFG1K_VAL_WFM_USER162, 0, 0, "USER162", 0},
		{TKAFG1K_VAL_WFM_USER163, 0, 0, "USER163", 0},
		{TKAFG1K_VAL_WFM_USER164, 0, 0, "USER164", 0},
		{TKAFG1K_VAL_WFM_USER165, 0, 0, "USER165", 0},
		{TKAFG1K_VAL_WFM_USER166, 0, 0, "USER166", 0},
		{TKAFG1K_VAL_WFM_USER167, 0, 0, "USER167", 0},
		{TKAFG1K_VAL_WFM_USER168, 0, 0, "USER168", 0},
		{TKAFG1K_VAL_WFM_USER169, 0, 0, "USER169", 0},
		{TKAFG1K_VAL_WFM_USER170, 0, 0, "USER170", 0},
		{TKAFG1K_VAL_WFM_USER171, 0, 0, "USER171", 0},
		{TKAFG1K_VAL_WFM_USER172, 0, 0, "USER172", 0},
		{TKAFG1K_VAL_WFM_USER173, 0, 0, "USER173", 0},
		{TKAFG1K_VAL_WFM_USER174, 0, 0, "USER174", 0},
		{TKAFG1K_VAL_WFM_USER175, 0, 0, "USER175", 0},
		{TKAFG1K_VAL_WFM_USER176, 0, 0, "USER176", 0},
		{TKAFG1K_VAL_WFM_USER177, 0, 0, "USER177", 0},
		{TKAFG1K_VAL_WFM_USER178, 0, 0, "USER178", 0},
		{TKAFG1K_VAL_WFM_USER179, 0, 0, "USER179", 0},
		{TKAFG1K_VAL_WFM_USER180, 0, 0, "USER180", 0},
		{TKAFG1K_VAL_WFM_USER181, 0, 0, "USER181", 0},
		{TKAFG1K_VAL_WFM_USER182, 0, 0, "USER182", 0},
		{TKAFG1K_VAL_WFM_USER183, 0, 0, "USER183", 0},
		{TKAFG1K_VAL_WFM_USER184, 0, 0, "USER184", 0},
		{TKAFG1K_VAL_WFM_USER185, 0, 0, "USER185", 0},
		{TKAFG1K_VAL_WFM_USER186, 0, 0, "USER186", 0},
		{TKAFG1K_VAL_WFM_USER187, 0, 0, "USER187", 0},
		{TKAFG1K_VAL_WFM_USER188, 0, 0, "USER188", 0},
		{TKAFG1K_VAL_WFM_USER189, 0, 0, "USER189", 0},
		{TKAFG1K_VAL_WFM_USER190, 0, 0, "USER190", 0},
		{TKAFG1K_VAL_WFM_USER191, 0, 0, "USER191", 0},
		{TKAFG1K_VAL_WFM_USER192, 0, 0, "USER192", 0},
		{TKAFG1K_VAL_WFM_USER193, 0, 0, "USER193", 0},
		{TKAFG1K_VAL_WFM_USER194, 0, 0, "USER194", 0},
		{TKAFG1K_VAL_WFM_USER195, 0, 0, "USER195", 0},
		{TKAFG1K_VAL_WFM_USER196, 0, 0, "USER196", 0},
		{TKAFG1K_VAL_WFM_USER197, 0, 0, "USER197", 0},
		{TKAFG1K_VAL_WFM_USER198, 0, 0, "USER198", 0},
		{TKAFG1K_VAL_WFM_USER199, 0, 0, "USER199", 0},
		{TKAFG1K_VAL_WFM_USER200, 0, 0, "USER200", 0},
		{TKAFG1K_VAL_WFM_USER201, 0, 0, "USER201", 0},
		{TKAFG1K_VAL_WFM_USER202, 0, 0, "USER202", 0},
		{TKAFG1K_VAL_WFM_USER203, 0, 0, "USER203", 0},
		{TKAFG1K_VAL_WFM_USER204, 0, 0, "USER204", 0},
		{TKAFG1K_VAL_WFM_USER205, 0, 0, "USER205", 0},
		{TKAFG1K_VAL_WFM_USER206, 0, 0, "USER206", 0},
		{TKAFG1K_VAL_WFM_USER207, 0, 0, "USER207", 0},
		{TKAFG1K_VAL_WFM_USER208, 0, 0, "USER208", 0},
		{TKAFG1K_VAL_WFM_USER209, 0, 0, "USER209", 0},
		{TKAFG1K_VAL_WFM_USER210, 0, 0, "USER210", 0},
		{TKAFG1K_VAL_WFM_USER211, 0, 0, "USER211", 0},
		{TKAFG1K_VAL_WFM_USER212, 0, 0, "USER212", 0},
		{TKAFG1K_VAL_WFM_USER213, 0, 0, "USER213", 0},
		{TKAFG1K_VAL_WFM_USER214, 0, 0, "USER214", 0},
		{TKAFG1K_VAL_WFM_USER215, 0, 0, "USER215", 0},
		{TKAFG1K_VAL_WFM_USER216, 0, 0, "USER216", 0},
		{TKAFG1K_VAL_WFM_USER217, 0, 0, "USER217", 0},
		{TKAFG1K_VAL_WFM_USER218, 0, 0, "USER218", 0},
		{TKAFG1K_VAL_WFM_USER219, 0, 0, "USER219", 0},
		{TKAFG1K_VAL_WFM_USER220, 0, 0, "USER220", 0},
		{TKAFG1K_VAL_WFM_USER221, 0, 0, "USER221", 0},
		{TKAFG1K_VAL_WFM_USER222, 0, 0, "USER222", 0},
		{TKAFG1K_VAL_WFM_USER223, 0, 0, "USER223", 0},
		{TKAFG1K_VAL_WFM_USER224, 0, 0, "USER224", 0},
		{TKAFG1K_VAL_WFM_USER225, 0, 0, "USER225", 0},
		{TKAFG1K_VAL_WFM_USER226, 0, 0, "USER226", 0},
		{TKAFG1K_VAL_WFM_USER227, 0, 0, "USER227", 0},
		{TKAFG1K_VAL_WFM_USER228, 0, 0, "USER228", 0},
		{TKAFG1K_VAL_WFM_USER229, 0, 0, "USER229", 0},
		{TKAFG1K_VAL_WFM_USER230, 0, 0, "USER230", 0},
		{TKAFG1K_VAL_WFM_USER231, 0, 0, "USER231", 0},
		{TKAFG1K_VAL_WFM_USER232, 0, 0, "USER232", 0},
		{TKAFG1K_VAL_WFM_USER233, 0, 0, "USER233", 0},
		{TKAFG1K_VAL_WFM_USER234, 0, 0, "USER234", 0},
		{TKAFG1K_VAL_WFM_USER235, 0, 0, "USER235", 0},
		{TKAFG1K_VAL_WFM_USER236, 0, 0, "USER236", 0},
		{TKAFG1K_VAL_WFM_USER237, 0, 0, "USER237", 0},
		{TKAFG1K_VAL_WFM_USER238, 0, 0, "USER238", 0},
		{TKAFG1K_VAL_WFM_USER239, 0, 0, "USER239", 0},
		{TKAFG1K_VAL_WFM_USER240, 0, 0, "USER240", 0},
		{TKAFG1K_VAL_WFM_USER241, 0, 0, "USER241", 0},
		{TKAFG1K_VAL_WFM_USER242, 0, 0, "USER242", 0},
		{TKAFG1K_VAL_WFM_USER243, 0, 0, "USER243", 0},
		{TKAFG1K_VAL_WFM_USER244, 0, 0, "USER244", 0},
		{TKAFG1K_VAL_WFM_USER245, 0, 0, "USER245", 0},
		{TKAFG1K_VAL_WFM_USER246, 0, 0, "USER246", 0},
		{TKAFG1K_VAL_WFM_USER247, 0, 0, "USER247", 0},
		{TKAFG1K_VAL_WFM_USER248, 0, 0, "USER248", 0},
		{TKAFG1K_VAL_WFM_USER249, 0, 0, "USER249", 0},
		{TKAFG1K_VAL_WFM_USER250, 0, 0, "USER250", 0},
		{TKAFG1K_VAL_WFM_USER251, 0, 0, "USER251", 0},
		{TKAFG1K_VAL_WFM_USER252, 0, 0, "USER252", 0},
		{TKAFG1K_VAL_WFM_USER253, 0, 0, "USER253", 0},
		{TKAFG1K_VAL_WFM_USER254, 0, 0, "USER254", 0},
		{TKAFG1K_VAL_WFM_USER255, 0, 0, "USER255", 0},
		{TKAFG1K_VAL_WFM_EMEM, 0, 0, "EMEM", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrWaveformRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrWaveformRangeTableEntries,
	};


static ViStatus _VI_FUNC tkafg1kAttrWaveform_ReadCallback (ViSession vi,
                                                           ViSession io,
                                                           ViConstString channelName,
                                                           ViAttr attributeId,
                                                           ViInt32 *value)
{
    return ( tkafg1k_ReadCmd (vi, io, channelName,  &attrWaveformRangeTable, "SOUR%s:FUNC:SHAP?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrWaveform_WriteCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 value)
{
	return ( tkafg1k_WriteCmd (vi, io, channelName, &attrWaveformRangeTable, "SOUR%s:FUNC:SHAP %s", value) );
}

/*- TKAFG1K_ATTR_VOLTAGE_UPPER_LIMIT -*/

/*- TKAFG1K_ATTR_VOLTAGE_LOWER_LIMIT -*/

/*- TKAFG1K_ATTR_MODEL -*/
static IviRangeTableEntry attrModelRangeTableEntries[] =
	{
		{TKAFG1K_VAL_MODEL_AFG1022, 0, 0, "", 0},
		{TKAFG1K_VAL_MODEL_AFG1062, 0, 0, "", 0},
		{IVI_RANGE_TABLE_LAST_ENTRY}
	};

static IviRangeTable attrModelRangeTable =
	{
		IVI_VAL_DISCRETE,
        VI_TRUE,
        VI_TRUE,
        VI_NULL,
        attrModelRangeTableEntries,
	};

static ViStatus _VI_FUNC tkafg1kAttrSweepEnabled_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
	ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr( Ivi_GetAttributeViInt32(vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_RunModeAllowable (vi, waveform, TKAFG1K_VAL_OPERATE_SWEEP, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }
Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrSweepEnabled_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
    if(value == VI_TRUE)
    {
        viCheckErr( viPrintf(io, "SOUR%s:FREQ:MODE SWE", channelName) );
    }
    else
    {
        viCheckErr( viPrintf(io, "SOUR%s:FREQ:MODE CW", channelName) );
    }	

Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrSweepStartFrequency_RangeTableCallback (ViSession vi,
                                                                            ViConstString channelName,
                                                                            ViAttr attributeId,
                                                                            IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;

	checkErr ( tkafg1k_GetSweepFrequencyRangeTable (vi, channelName, &tblPtr) );

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrSweepStartFrequency_ReadCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 *value)
{
	return ( tkafg1k_ReadReal64(vi, io, channelName, "SOUR%s:FREQ:STAR?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrSweepStartFrequency_WriteCallback (ViSession vi,
                                                                       ViSession io,
                                                                       ViConstString channelName,
                                                                       ViAttr attributeId,
                                                                       ViReal64 value)
{
	return ( tkafg1k_WriteReal64(vi, io, channelName, "SOUR%s:FREQ:STAR %Le", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrSweepStopFrequency_RangeTableCallback (ViSession vi,
                                                                           ViConstString channelName,
                                                                           ViAttr attributeId,
                                                                           IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
	checkErr ( tkafg1k_GetSweepFrequencyRangeTable (vi, channelName, &tblPtr) );

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrSweepStopFrequency_ReadCallback (ViSession vi,
                                                                     ViSession io,
                                                                     ViConstString channelName,
                                                                     ViAttr attributeId,
                                                                     ViReal64 *value)
{
	return (tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:FREQ:STOP?", value) ); 
}

static ViStatus _VI_FUNC tkafg1kAttrSweepStopFrequency_WriteCallback (ViSession vi,
                                                                      ViSession io,
                                                                      ViConstString channelName,
                                                                      ViAttr attributeId,
                                                                      ViReal64 value)
{
	return (tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:FREQ:STOP %Le", value));
}


/*****************************************************************************
 * Function: tkafg1k_GetSweepFrequencyRangeTable
 * Purpose: Functions for instrument drivers to dynamically set sweep
 *          start and stop frequency range table.
 *****************************************************************************/
static ViStatus tkafg1k_GetSweepFrequencyRangeTable( ViSession vi, ViConstString channelName,
                                                              IviRangeTablePtr *rangeTablePtr)
{
    ViStatus    error = VI_SUCCESS;
    IviRangeTablePtr    tblPtr = VI_NULL;
    ViInt32     waveform;
    ViInt32     model;

    checkErr( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform ) );
    checkErr( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );

    switch  (waveform)
    {
        case TKAFG1K_VAL_WFM_SINE:
        {
            if( model == TKAFG1K_VAL_MODEL_AFG1022)
            {
                tblPtr = &attrAFG1022SineWfmSweepFrequencyRangeTable;
            }
            else if(model == TKAFG1K_VAL_MODEL_AFG1062)
            {
                tblPtr = &attrAFG1062SineWfmSweepFrequencyRangeTable;
            }
            break;
        }
        case TKAFG1K_VAL_WFM_SQUARE:
        {
            if( model == TKAFG1K_VAL_MODEL_AFG1022)
            {
                tblPtr = &attrAFG1022SquareWfmSweepFrequencyRangeTable;
            }
            else if(model == TKAFG1K_VAL_MODEL_AFG1062)
            {
                tblPtr = &attrAFG1062SquareWfmSweepFrequencyRangeTable;
            }
            break;
        }
        case TKAFG1K_VAL_WFM_RAMP:
        {
            if( model == TKAFG1K_VAL_MODEL_AFG1022)
            {
                tblPtr = &attrAFG1022RampWfmSweepFrequencyRangeTable;
            }
            else if(model == TKAFG1K_VAL_MODEL_AFG1062)
            {
                tblPtr = &attrAFG1062RampWfmSweepFrequencyRangeTable;
            }
            break;
        }
        case TKAFG1K_VAL_WFM_EMEM:
        {
            if( model == TKAFG1K_VAL_MODEL_AFG1022)
            {
                tblPtr = &attrAFG1022ArbWfmSweepFrequencyRangeTable;
            }
            else if(model == TKAFG1K_VAL_MODEL_AFG1062)
            {
                tblPtr = &attrAFG1062ArbWfmSweepFrequencyRangeTable;
            }
            break;
        }
        default:
        {
			if(waveform>=TKAFG1K_VAL_WFM_USER0 && waveform<=TKAFG1K_VAL_WFM_USER255){
				if(model == TKAFG1K_VAL_MODEL_AFG1022)
					tblPtr = &attrAFG1022ArbWfmSweepFrequencyRangeTable;
				else if (model == TKAFG1K_VAL_MODEL_AFG1062){
					if(waveform >=TKAFG1K_VAL_WFM_USER32){
						error = IVI_ERROR_INVALID_PARAMETER;
						viCheckErr (error);						
					}else
						tblPtr = &attrAFG1062ArbWfmSweepFrequencyRangeTable;
				}else{
					error = TKAFG1K_ERROR_INVALID_SPECIFIC_MODEL;
					viCheckErr (error);
				}
			}else if(waveform >=TKAFG1K_VAL_WFM_STAIRDOWN && waveform <=TKAFG1K_VAL_WFM_CARDIAC)
					if( model == TKAFG1K_VAL_MODEL_AFG1022)
		            {
		                tblPtr = &attrAFG1022ArbWfmSweepFrequencyRangeTable;
		            }
		            else if(model == TKAFG1K_VAL_MODEL_AFG1062)
		            {
		                tblPtr = &attrAFG1062ArbWfmSweepFrequencyRangeTable;
		            }					
			else{
				tblPtr = VI_NULL;
				error = IVI_ERROR_INVALID_PARAMETER;
				viCheckErr (error);
			}
            break;
        }
    }

Error:
    *rangeTablePtr = tblPtr;
    return error;
}



static ViStatus _VI_FUNC tkafg1kAttrAskEnabled_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_ASK, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }
	
Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAskEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
	return ( tkafg1k_ReadState (vi, io, channelName, "SOUR%s:ASK:STAT?", value) ); 
}

static ViStatus _VI_FUNC tkafg1kAttrAskEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
	ViStatus    error = VI_SUCCESS;

    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:ASK:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_ASK) );
    }

Error:
    return error;

}

static ViStatus _VI_FUNC tkafg1kAttrPskEnabled_CheckCallback (ViSession vi,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
    ViInt32     waveform;
    ViBoolean   allowance;

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_GetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_WAVEFORM, 0, &waveform) );

        checkErr ( tkafg1k_ModulationTypeAllowable (vi, waveform, TKAFG1K_VAL_MODULATION_PSK, &allowance) );
        if(!allowance)
        {
            error = IVI_ERROR_INVALID_CONFIGURATION;
            viCheckErr (error);
        }
    }

Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrPskEnabled_ReadCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViBoolean *value)
{
	return ( tkafg1k_ReadState (vi, io, channelName, "SOUR%s:PSK:STAT?", value) ); 
}

static ViStatus _VI_FUNC tkafg1kAttrPskEnabled_WriteCallback (ViSession vi,
                                                              ViSession io,
                                                              ViConstString channelName,
                                                              ViAttr attributeId,
                                                              ViBoolean value)
{
	ViStatus	error = VI_SUCCESS;
    checkErr ( tkafg1k_WriteState (vi, io, channelName, "SOUR%s:PSK:STAT %s", value) );

    if(value == VI_TRUE)
    {
        checkErr ( Ivi_SetAttributeViInt32 (vi, channelName, TKAFG1K_ATTR_ORIGINAL_MODULATION, 0, TKAFG1K_VAL_MODULATION_PSK) );
    }
	
Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrAskSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
	return ( tkafg1k_ReadCmd (vi, io, channelName, &attrASKSourceRangeTable, "SOUR%s:ASK:SOUR?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAskSource_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value)
{
	return ( tkafg1k_WriteCmd (vi, io, channelName, &attrASKSourceRangeTable, "SOUR%s:ASK:SOUR %s", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPskSource_ReadCallback (ViSession vi,
                                                            ViSession io,
                                                            ViConstString channelName,
                                                            ViAttr attributeId,
                                                            ViInt32 *value)
{
	return ( tkafg1k_ReadCmd (vi, io, channelName, &attrPSKSourceRangeTable, "SOUR%s:PSK:SOUR?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPskSource_WriteCallback (ViSession vi,
                                                             ViSession io,
                                                             ViConstString channelName,
                                                             ViAttr attributeId,
                                                             ViInt32 value)
{
	return ( tkafg1k_WriteCmd (vi, io, channelName, &attrPSKSourceRangeTable, "SOUR%s:PSK:SOUR %s", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAskInternalRate_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value)
{
	return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:ASK:INT:RATE?", value) ); 
}

static ViStatus _VI_FUNC tkafg1kAttrAskInternalRate_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
	return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:ASK:INT:RATE %Le", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPskInternalRate_ReadCallback (ViSession vi,
                                                                  ViSession io,
                                                                  ViConstString channelName,
                                                                  ViAttr attributeId,
                                                                  ViReal64 *value)
{
	return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PSK:INT:RATE?", value) ); 
}

static ViStatus _VI_FUNC tkafg1kAttrPskInternalRate_WriteCallback (ViSession vi,
                                                                   ViSession io,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   ViReal64 value)
{
	return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PSK:INT:RATE %Le", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAskAmplitude_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value)
{
	return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:ASK:AMPL?", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrAskAmplitude_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
	return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:ASK:AMPL %Le", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPskDeviation_ReadCallback (ViSession vi,
                                                               ViSession io,
                                                               ViConstString channelName,
                                                               ViAttr attributeId,
                                                               ViReal64 *value)
{
	return ( tkafg1k_ReadReal64 (vi, io, channelName, "SOUR%s:PSK:DEV?", value) ); 
}

static ViStatus _VI_FUNC tkafg1kAttrPskDeviation_WriteCallback (ViSession vi,
                                                                ViSession io,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
	return ( tkafg1k_WriteReal64 (vi, io, channelName, "SOUR%s:PSK:DEV %Le", value) );
}

static ViStatus _VI_FUNC tkafg1kAttrPskDeviation_CheckCallback (ViSession vi,
                                                                ViConstString channelName,
                                                                ViAttr attributeId,
                                                                ViReal64 value)
{
	ViStatus	error = VI_SUCCESS;
	checkErr ( Ivi_DefaultCheckCallbackViReal64(vi, channelName, TKAFG1K_ATTR_PSK_DEVIATION, value) );
Error:
	return error;
}

static ViStatus _VI_FUNC tkafg1kAttrBurstCount_RangeTableCallback (ViSession vi,
                                                                   ViConstString channelName,
                                                                   ViAttr attributeId,
                                                                   IviRangeTablePtr *rangeTablePtr)
{
	ViStatus	error = VI_SUCCESS;
	IviRangeTablePtr	tblPtr = VI_NULL;
    ViInt32     model;
    
    checkErr ( Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG1K_ATTR_MODEL, 0, &model) );
    if( model == TKAFG1K_VAL_MODEL_AFG1022 )
    {
		tblPtr = &attrAFG1022BurstCountRangeTable;
    }
    else if( model == TKAFG1K_VAL_MODEL_AFG1062 )
    {
		tblPtr = &attrAFG1062BurstCountRangeTable;
	}

Error:
	*rangeTablePtr = tblPtr;
	return error;
}

/*****************************************************************************
 * Function: tkafg1k_InitAttributes
 * Purpose:  This function adds attributes to the IVI session, initializes
 *           instrument attributes, and sets attribute invalidation
 *           dependencies.
 *****************************************************************************/
static ViStatus tkafg1k_InitAttributes (ViSession vi, ViInt32 model)
{
    ViStatus    error = VI_SUCCESS;
    ViInt32     flags = 0;

    /*-- Inherent Instrument Attributes---------------------------------------------------*/
    /*- Specific Driver Revision -*/
    checkErr( Ivi_SetAttrReadCallbackViString (vi, TKAFG1K_ATTR_SPECIFIC_DRIVER_REVISION,
                                               tkafg1kAttrDriverRevision_ReadCallback));

    /*- Class Specific Major Version -*/
    checkErr( Ivi_SetAttributeViInt32 (vi, "", TKAFG1K_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION,
                                       0, TKAFG1K_CLASS_SPEC_MAJOR_VERSION));

    /*- Class Specific Minor Version -*/
    checkErr( Ivi_SetAttributeViInt32 (vi, "", TKAFG1K_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION,
                                       0, TKAFG1K_CLASS_SPEC_MINOR_VERSION));

    /*- Supported Instrument Models -*/
    checkErr( Ivi_SetAttributeViString (vi, "", TKAFG1K_ATTR_SUPPORTED_INSTRUMENT_MODELS,
                                        0, TKAFG1K_SUPPORTED_INSTRUMENT_MODELS));

    /*- Instrument Firmware Revision -*/
    checkErr( Ivi_GetAttributeFlags (vi, TKAFG1K_ATTR_INSTRUMENT_FIRMWARE_REVISION, &flags));
    checkErr( Ivi_SetAttributeFlags (vi, TKAFG1K_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr( Ivi_SetAttrReadCallbackViString (vi, TKAFG1K_ATTR_INSTRUMENT_FIRMWARE_REVISION,
                                               tkafg1kAttrFirmwareRevision_ReadCallback));

    /*- Instrument Manufacturer -*/
    checkErr( Ivi_GetAttributeFlags (vi, TKAFG1K_ATTR_INSTRUMENT_MANUFACTURER, &flags));
    checkErr( Ivi_SetAttributeFlags (vi, TKAFG1K_ATTR_INSTRUMENT_MANUFACTURER,
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr( Ivi_SetAttrReadCallbackViString (vi, TKAFG1K_ATTR_INSTRUMENT_MANUFACTURER,
                                               tkafg1kAttrInstrumentManufacturer_ReadCallback));

    /*- Instrument Model -*/
    checkErr( Ivi_GetAttributeFlags (vi, TKAFG1K_ATTR_INSTRUMENT_MODEL, &flags));
    checkErr( Ivi_SetAttributeFlags (vi, TKAFG1K_ATTR_INSTRUMENT_MODEL,
                                     flags | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION));
    checkErr( Ivi_SetAttrReadCallbackViString (vi, TKAFG1K_ATTR_INSTRUMENT_MODEL,
                                               tkafg1kAttrInstrumentModel_ReadCallback));

    /*- Specific Driver Vendor -*/
    checkErr( Ivi_SetAttributeViString (vi, "", TKAFG1K_ATTR_SPECIFIC_DRIVER_VENDOR,
                                        0, TKAFG1K_DRIVER_VENDOR));

    /*- Specific Driver Description -*/
    checkErr( Ivi_SetAttributeViString (vi, "", TKAFG1K_ATTR_SPECIFIC_DRIVER_DESCRIPTION,
                                        0, TKAFG1K_DRIVER_DESCRIPTION));

    /*- Check Status Callback -*/
    checkErr( Ivi_SetAttributeViAddr (vi, VI_NULL, IVI_ATTR_CHECK_STATUS_CALLBACK, 0,
                                      tkafg1k_CheckStatusCallback));

    /*- Group Capabilities -*/
    checkErr( Ivi_SetAttributeViString (vi, "", TKAFG1K_ATTR_GROUP_CAPABILITIES, 0,
                                        "IviFgenBase,"
                                        "IviFgenStdFunc,"
                                        "IviFgenPulseWfm,"
                                        "IviFgenArbWfm,"
                                        "IviFgenArbFrequency,"
                                        "IviFgenTrigger,"
                                        "IviFgenInternalTrigger,"
                                        "IviFgenBurst,"
                                        "IviFgenSweep,"
                                        "IviFgenModulation,"
                                        "IviFgenModulateAM,"
                                        "IviFgenModulateFM,"
                                        "IviFgenModulateFSK,"
                                        "IviFgenModulatePM,"
                                        "IviFgenModulatePWM"    ));

    /*-- Basic Instrument Operation ------------------------------------------------------*/
    /*- Operation Mode -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_OPERATION_MODE,
                                       "TKAFG1K_ATTR_OPERATION_MODE",
                                       TKAFG1K_VAL_OPERATE_CONTINUOUS,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                       tkafg1kAttrOperationMode_ReadCallback,
                                       tkafg1kAttrOperationMode_WriteCallback,
                                       &attrOperationModeRangeTable));
    checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi, TKAFG1K_ATTR_OPERATION_MODE,
                                               tkafg1kAttrOperationMode_CheckCallback));
																				  
    /*- Continuous Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_CONTINUOUS_ENABLED,
                                         "TKAFG1K_ATTR_CONTINUOUS_ENABLED", VI_TRUE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_HIDDEN | IVI_VAL_NOT_READABLE,
                                         VI_NULL,
                                         tkafg1kAttrContinuousEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_CONTINUOUS_ENABLED,
                                                 tkafg1kAttrContinuousEnabled_CheckCallback));

    /*- Output Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_OUTPUT_ENABLED,
                                         "TKAFG1K_ATTR_OUTPUT_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL,
                                         tkafg1kAttrOutputEnabled_ReadCallback,
                                         tkafg1kAttrOutputEnabled_WriteCallback));

    /*- Output Impedance -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_OUTPUT_IMPEDANCE,
                                        "TKAFG1K_ATTR_OUTPUT_IMPEDANCE", 50.0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrOutputImpedance_ReadCallback,
                                        tkafg1kAttrOutputImpedance_WriteCallback,
                                        &attrOutputImpedanceRangeTable, 0));
	
	/*- Active Memory -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_ACTIVE_MEMORY,
	                                   "TKAFG1K_ATTR_ACTIVE_MEMORY",
	                                   TKAFG1K_VAL_OUTPUT_EMEM, IVI_VAL_ALWAYS_CACHE,
	                                   VI_NULL, VI_NULL, &attrActiveOneMemoryRangeTable));

    /*- Output Mode -*/
	
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_OUTPUT_MODE,
                                       "TKAFG1K_ATTR_OUTPUT_MODE",
                                       TKAFG1K_VAL_OUTPUT_FUNC,
                                       IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                       VI_NULL, VI_NULL, &attrOutputModeRangeTable));

    /*- Output Mode by Channel -*/																								 
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL,
                                       "TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL",
                                       TKAFG1K_VAL_OUTPUT_FUNC,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                       tkafg1kAttrOutputModeByChannel_ReadCallback,
                                       tkafg1kAttrOutputModeByChannel_WriteCallback,
                                       &attrOutputModeRangeTable));

    /*- Reference Clock Source -*/

    /*-- Standard Waveform Operation------------------------------------------------------*/
    /*- Function Amplitude -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FUNC_AMPLITUDE,
                                        "TKAFG1K_ATTR_FUNC_AMPLITUDE", 1.00,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        tkafg1kAttrFuncAmplitude_ReadCallback,
                                        tkafg1kAttrFuncAmplitude_WriteCallback,
                                        VI_NULL, 0));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_FUNC_AMPLITUDE,
                                                tkafg1kAttrFuncAmplitude_CheckCallback));

    /*- Function Waveform -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_FUNC_WAVEFORM,
                                       "TKAFG1K_ATTR_FUNC_WAVEFORM",
                                       TKAFG1K_VAL_WFM_SINE,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                       tkafg1kAttrFuncWaveform_ReadCallback,
                                       tkafg1kAttrFuncWaveform_WriteCallback,
                                       &attrFuncWaveformRangeTable));
    checkErr( Ivi_SetAttrCheckCallbackViInt32 (vi, TKAFG1K_ATTR_FUNC_WAVEFORM,
                                               tkafg1kAttrFuncWaveform_CheckCallback));
	

    /*- Function DC Offset -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FUNC_DC_OFFSET,
                                        "TKAFG1K_ATTR_FUNC_DC_OFFSET", 0.00,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        tkafg1kAttrFuncDCOffset_ReadCallback,
                                        tkafg1kAttrFuncDCOffset_WriteCallback,
                                        VI_NULL, 0));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_FUNC_DC_OFFSET,
                                                tkafg1kAttrFuncDCOffset_CheckCallback));

    /*- Function Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FUNC_FREQUENCY,
                                        "TKAFG1K_ATTR_FUNC_FREQUENCY", 1000000.00,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        tkafg1kAttrFuncFrequency_ReadCallback,
                                        tkafg1kAttrFuncFrequency_WriteCallback,
                                        VI_NULL, 0));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_FUNC_FREQUENCY,
                                                tkafg1kAttrFuncFrequency_CheckCallback));
    checkErr( Ivi_SetAttrRangeTableCallback (vi, TKAFG1K_ATTR_FUNC_FREQUENCY,
                                                     tkafg1kAttrFuncFrequency_RangeTableCallback));

    /*- Start Phase -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FUNC_START_PHASE,
                                        "TKAFG1K_ATTR_FUNC_START_PHASE", 0.00,
                                        IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrFuncStartPhase_ReadCallback,
                                        tkafg1kAttrFuncStartPhase_WriteCallback,
                                        &attrFuncStartPhaseRangeTable, 0));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_FUNC_START_PHASE,
                                                tkafg1kAttrFuncStartPhase_CheckCallback));

    /*- Duty Cycle High -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH,
                                        "TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH", 50.00,
                                        IVI_VAL_MULTI_CHANNEL, VI_NULL, VI_NULL,
                                        &attrFuncDutyCycleHighRangeTable, 0));


    /*-- Pulse Waveform Operation ---------------------------------------------------------*/

    /*- Duty Cycle -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_PULSE_DUTY_CYCLE,
                                        "TKAFG1K_ATTR_PULSE_DUTY_CYCLE", 50,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                        tkafg1kAttrPulseDutyCycle_ReadCallback,
                                        tkafg1kAttrPulseDutyCycle_WriteCallback,
                                        VI_NULL, 0));
    /*-- Arbitrary Waveform Operation------------------------------------------------------*/
    /*- Arbitrary Waveform Handle -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE,
	                                   "TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE",
	                                   TKAFG1K_VAL_WFM_EMEM,
	                                   IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
	                                   tkafg1kAttrArbWaveformHandle_ReadCallback,
	                                   tkafg1kAttrArbWaveformHandle_WriteCallback,
	                                   &attrArbWaveformHandleRangeTable));
    checkErr( Ivi_SetAttrCheckCallbackViInt32 (vi, TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE,
                                               tkafg1kAttrArbWaveformHandle_CheckCallback));

    /*- Gain -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_ARB_GAIN,
                                        "TKAFG1K_ATTR_ARB_GAIN", 0.5,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        tkafg1kAttrArbGain_ReadCallback,
                                        tkafg1kAttrArbGain_WriteCallback, VI_NULL, 0));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_ARB_GAIN,
                                                tkafg1kAttrArbGain_CheckCallback));

    /*- Offset -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_ARB_OFFSET,
                                        "TKAFG1K_ATTR_ARB_OFFSET", 0.00,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        tkafg1kAttrArbOffset_ReadCallback,
                                        tkafg1kAttrArbOffset_WriteCallback, VI_NULL,
                                        0));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_ARB_OFFSET,
                                                tkafg1kAttrArbOffset_CheckCallback));

    /*- Sample Rate -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_ARB_SAMPLE_RATE,
                                        "TKAFG1K_ATTR_ARB_SAMPLE_RATE", 1000000000.0,
                                        IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        VI_NULL, VI_NULL, VI_NULL, 0));

    /*- Maximum Number of Waveforms -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_MAX_NUM_WAVEFORMS,
                                       "TKAFG1K_ATTR_MAX_NUM_WAVEFORMS",
                                       TKAFG1K_VAL_MAX_WAVEFORMS,
                                       IVI_VAL_NOT_USER_WRITABLE,
                                       VI_NULL, VI_NULL, VI_NULL));

    /*- Waveform Quantum -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_WAVEFORM_QUANTUM,
                                       "TKAFG1K_ATTR_WAVEFORM_QUANTUM",
                                       TKAFG1K_VAL_WFM_QUANTUM,
                                       IVI_VAL_NOT_USER_WRITABLE,
                                       VI_NULL, VI_NULL, VI_NULL));

    /*- Minimum Waveforms Size -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_MIN_WAVEFORM_SIZE,
                                       "TKAFG1K_ATTR_MIN_WAVEFORM_SIZE",
                                       TKAFG1K_VAL_MIN_WFM_SIZE,
                                       IVI_VAL_NOT_USER_WRITABLE,
                                       VI_NULL, VI_NULL, VI_NULL));

    /*- Maximum Waveform Size -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE,
	                                   "TKAFG1K_ATTR_MAX_WAVEFORM_SIZE", 131072,
	                                   IVI_VAL_NOT_USER_WRITABLE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
	                                   tkafg1kAttrMaxWaveformSize_ReadCallback,
	                                   VI_NULL, VI_NULL));

    /*- Arbitrary Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_ARB_FREQUENCY,
                                        "TKAFG1K_ATTR_ARB_FREQUENCY", 1000000.00,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_USE_CALLBACKS_FOR_SIMULATION,
                                        tkafg1kAttrArbFrequency_ReadCallback,
                                        tkafg1kAttrArbFrequency_WriteCallback,
                                        VI_NULL, 0));
    checkErr (Ivi_SetAttrRangeTableCallback (vi, TKAFG1K_ATTR_ARB_FREQUENCY,
                                             tkafg1kAttrArbFrequency_RangeTableCallback));
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_ARB_FREQUENCY,
                                                tkafg1kAttrArbFrequency_CheckCallback));

    
    /*- Burst Configuration ---------------------------------------------------------------*/
    /*- Burst Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_BURST_ENABLED,
                                         "TKAFG1K_ATTR_BURST_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_HIDDEN | IVI_VAL_NOT_READABLE,
                                         VI_NULL,
                                         tkafg1kAttrBurstEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_BURST_ENABLED,
                                                 tkafg1kAttrBurstEnabled_CheckCallback));

    /*- Burst Count -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_BURST_COUNT,
	                                   "TKAFG1K_ATTR_BURST_COUNT", 5,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrBurstCount_ReadCallback,
	                                   tkafg1kAttrBurstCount_WriteCallback,
	                                   &attrAFG1022BurstCountRangeTable));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, TKAFG1K_ATTR_BURST_COUNT,
	                                         tkafg1kAttrBurstCount_RangeTableCallback));

    /*- Burst Mode -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_BURST_MODE,
                                       "TKAFG1K_ATTR_BURST_MODE",
                                       TKAFG1K_VAL_BURST_TRIGGER,
                                       IVI_VAL_MULTI_CHANNEL,
                                       tkafg1kAttrBurstMode_ReadCallback,
                                       tkafg1kAttrBurstMode_WriteCallback,
                                       &attrBurstModeRangeTable));

    /*- Sweep Configuration ---------------------------------------------------------------*/

    /*-- Waveform Appendant ---------------------------------------------------------------*/


    /*- Modulation Configuration ----------------------------------------------------------*/
    /*- Modulation Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_MODULATION_ENABLED,
                                         "TKAFG1K_ATTR_MODULATION_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_HIDDEN | IVI_VAL_NOT_READABLE,
                                         VI_NULL,
                                         tkafg1kAttrModulationEnabled_WriteCallback));

    /*- Origianl Modulation Type -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_ORIGINAL_MODULATION,
                                       "TKAFG1K_ATTR_ORIGINAL_MODULATION",
                                       TKAFG1K_VAL_MODULATION_AM,
                                       IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                       VI_NULL, VI_NULL,
                                       &attrOriginalModulationRangeTable));

    /*-- AM Configuration -----------------------------------------------------------------*/
    /*- AM Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_AM_ENABLED,
                                         "TKAFG1K_ATTR_AM_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                         tkafg1kAttrAMEnabled_ReadCallback,
                                         tkafg1kAttrAMEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_AM_ENABLED,
                                                 tkafg1kAttrAMEnabled_CheckCallback));

    /*- AM Source -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_AM_SOURCE,
                                       "TKAFG1K_ATTR_AM_SOURCE",
                                       TKAFG1K_VAL_AM_INTERNAL,
                                       IVI_VAL_MULTI_CHANNEL,
                                       tkafg1kAttrAMSource_ReadCallback,
                                       tkafg1kAttrAMSource_WriteCallback,
                                       &attrAMSourceRangeTable));

    /*- AM Internal Depth -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_DEPTH,
                                        "TKAFG1K_ATTR_AM_INTERNAL_DEPTH", 50.00,
                                        IVI_VAL_NEVER_CACHE, VI_NULL, VI_NULL,
                                        &attrAMInternalDepthRangeTable, 0));

    /*- AM Internal Waveform -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM,
                                       "TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM",
                                       TKAFG1K_VAL_AM_INTERNAL_SINE,
                                       IVI_VAL_NEVER_CACHE, VI_NULL, VI_NULL,
                                       &attrAMInternalWaveformRangeTable));

    /*- AM Internal Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY,
                                        "TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY",
                                        10000.00, IVI_VAL_NEVER_CACHE, VI_NULL,
                                        VI_NULL, &attrAMInternalFrequencyRangeTable,
                                        0));

    /*- AM Depth By Channel -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL,
                                        "TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL", 50.00,
                                        IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrAMDepthByChannel_ReadCallBack,
                                        tkafg1kAttrAMDepthByChannel_WriteCallback,
                                        &attrAMInternalDepthRangeTable, 0));

    /*- AM Internal Waveform By Channel -*/
	checkErr (Ivi_AddAttributeViInt32 (vi,
	                                   TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL,
	                                   "TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL",
	                                   TKAFG1K_VAL_AM_INTERNAL_SINE,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrAMInternalWaveformByChannel_ReadCallback,
	                                   tkafg1kAttrAMInternalWaveformByChannel_WriteCallback,
	                                   &attrAMInternalWaveformRangeTable));
    checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi,
                                               TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL,
                                               tkafg1kAttrAMInternalWaveformByChannel_CheckCallback));

    /*- AM Internal Frequency By Channel -*/
    checkErr (Ivi_AddAttributeViReal64 (vi,
                                        TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
                                        "TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL",
                                        10000.00, IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrAMInternalFrequencyByChannel_ReadCallback,
                                        tkafg1kAttrAMInternalFrequencyByChannel_WriteCallback,
                                        &attrAMInternalFrequencyRangeTable, 0));

    /*-- FM Configuration -----------------------------------------------------------------*/
    /*- FM Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_FM_ENABLED,
                                         "TKAFG1K_ATTR_FM_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                         tkafg1kAttrFMEnabled_ReadCallback,
                                         tkafg1kAttrFMEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_FM_ENABLED,
                                                 tkafg1kAttrFMEnabled_CheckCallback));

    /*- FM Source -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_FM_SOURCE,
                                       "TKAFG1K_ATTR_FM_SOURCE",
                                       TKAFG1K_VAL_FM_INTERNAL,
                                       IVI_VAL_MULTI_CHANNEL,
                                       tkafg1kAttrFMSource_ReadCallback,
                                       tkafg1kAttrFMSource_WriteCallback,
                                       &attrFMSourceRangeTable));

    /*- FM Deviation -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_DEVIATION,
                                        "TKAFG1K_ATTR_FM_INTERNAL_DEVIATION",
                                        100000.0, IVI_VAL_NEVER_CACHE, VI_NULL,
                                        VI_NULL, VI_NULL, 0));

    /*- FM Deviation By Channel -*/
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL,
	                                    "TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL", 0,
	                                    IVI_VAL_MULTI_CHANNEL,
	                                    tkafg1kAttrFMDeviationByChannel_ReadCallback,
	                                    tkafg1kAttrFMDeviationByChannel_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi,
	                                            TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL,
	                                            tkafg1kAttrFmDeviationByChannel_CheckCallback));

    /*- FM Internal Waveform -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM,
                                       "TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM",
                                       TKAFG1K_VAL_FM_INTERNAL_SINE,
                                       IVI_VAL_NEVER_CACHE, VI_NULL, VI_NULL,
                                       &attrFMInternalWaveformRangeTable));

    /*- FM Internal Waveform By Channel -*/
	checkErr (Ivi_AddAttributeViInt32 (vi,
	                                   TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL,
	                                   "TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL",
	                                   TKAFG1K_VAL_FM_INTERNAL_SINE,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrFMInternalWaveformByChannel_ReadCallback,
	                                   tkafg1kAttrFMInternalWaveformByChannel_WriteCallback,
	                                   &attrFMInternalWaveformRangeTable));
    checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi,
                                               TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL,
                                               tkafg1kAttrFMInternalWaveformByChannel_CheckCallback));

    /*- FM Internal Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY,
                                        "TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY",
                                        10000.00, IVI_VAL_NEVER_CACHE, VI_NULL,
                                        VI_NULL, &attrFMInternalFrequencyRangeTable,
                                        0));

    /*- FM Internal Frequency By Channel -*/
    checkErr (Ivi_AddAttributeViReal64 (vi,
                                        TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL,
                                        "TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL",
                                        10000.0, IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrFMInternalFrequencyByChannel_ReadCallback,
                                        tkafg1kAttrFMInternalFrequencyByChannel_WriteCallback,
                                        &attrFMInternalFrequencyRangeTable, 0));

    checkErr( Ivi_AddAttributeViString (vi, TKAFG1K_ATTR_ID_QUERY_RESPONSE,
                                        "TKAFG1K_ATTR_ID_QUERY_RESPONSE",
                                        "TEKTRONIX,AFG1022",
                                        IVI_VAL_NOT_USER_WRITABLE,
                                        tkafg1kAttrIdQueryResponse_ReadCallback,
                                        VI_NULL));

    /*-- FSK Configuration ----------------------------------------------------------------*/
    /*- FSK Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_FSK_ENABLED,
                                         "TKAFG1K_ATTR_FSK_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                         tkafg1kAttrFSKEnabled_ReadCallback,
                                         tkafg1kAttrFSKEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_FSK_ENABLED,
                                                 tkafg1kAttrFSKEnabled_CheckCallback));

    /*- FSK Hop Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FSK_HOP_FREQUENCY,
                                        "TKAFG1K_ATTR_FSK_HOP_FREQUENCY", 1000000.0,
                                        IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrFSKHopFrequency_ReadCallback,
                                        tkafg1kAttrFSKHopFrequency_WriteCallback,
                                        VI_NULL, 0));
    checkErr (Ivi_SetAttrRangeTableCallback (vi, TKAFG1K_ATTR_FSK_HOP_FREQUENCY,
                                             tkafg1kAttrFuncFrequency_RangeTableCallback));

    /*- FSK Internal Rate -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FSK_INTERNAL_RATE,
                                        "TKAFG1K_ATTR_FSK_INTERNAL_RATE", 50,
                                        IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrFSKInternalRate_ReadCallback,
                                        tkafg1kAttrFSKInternalRate_WriteCallback,
                                        &attrFSKInternalRateRangeTable, 0));

    /*- FSK Source -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_FSK_SOURCE,
                                       "TKAFG1K_ATTR_FSK_SOURCE",
                                       TKAFG1K_VAL_FSK_INTERNAL,
                                       IVI_VAL_MULTI_CHANNEL,
                                       tkafg1kAttrFSKSource_ReadCallback,
                                       tkafg1kAttrFSKSource_WriteCallback,
                                       &attrFSKSourceRangeTable));

    /*-- PM Configuration -----------------------------------------------------------------*/
    /*- PM Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_PM_ENABLED,
                                         "TKAFG1K_ATTR_PM_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                         tkafg1kAttrPMEnabled_ReadCallback,
                                         tkafg1kAttrPMEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_PM_ENABLED,
                                                 tkafg1kAttrPMEnabled_CheckCallback));

    /*- PM Source -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_PM_SOURCE,
                                       "TKAFG1K_ATTR_PM_SOURCE",
                                       TKAFG1K_VAL_PM_INTERNAL,
                                       IVI_VAL_MULTI_CHANNEL,
                                       tkafg1kAttrPMSource_ReadCallback,
                                       tkafg1kAttrPMSource_WriteCallback,
                                       &attrPMSourceRangeTable));

    /*- PM Deviation By Channel -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL,
                                        "TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL", 90,
                                        IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrPMDeviationByChannel_ReadCallback,
                                        tkafg1kAttrPMDeviationByChannel_WriteCallback,
                                        &attrPMDeviationRangeTable, 0));

    /*- PM Internal Frequency By Channel -*/
    checkErr (Ivi_AddAttributeViReal64 (vi,
                                        TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL,
                                        "TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL",
                                        10000.00, IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrPMInternalFrequencyByChannel_ReadCallback,
                                        tkafg1kAttrPMInternalFrequencyByChannel_WriteCallback,
                                        &attrPMInternalFrequencyRangeTable, 0));

    /*- PM Internal Waveform By Channel -*/
	checkErr (Ivi_AddAttributeViInt32 (vi,
	                                   TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL,
	                                   "TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL",
	                                   TKAFG1K_VAL_PM_INTERNAL_SINE,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrPMInternalWaveformByChannel_ReadCallback,
	                                   tkafg1kAttrPMInternalWaveformByChannel_WriteCallback,
	                                   &attrPMInternalWaveformRangeTable));
    checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi,
                                               TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL,
                                               tkafg1kAttrPMInternalWaveformByChannel_CheckCallback));

    /*-- PWM Configuration ----------------------------------------------------------------*/
    /*- PWM Enabled -*/
    checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_PWM_ENABLED,
                                         "TKAFG1K_ATTR_PWM_ENABLED", VI_FALSE,
                                         IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                         tkafg1kAttrPWMEnabled_ReadCallback,
                                         tkafg1kAttrPWMEnabled_WriteCallback));
    checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_PWM_ENABLED,
                                                 tkafg1kAttrPWMEnabled_CheckCallback));

    /*- PWM Source -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_PWM_SOURCE,
                                       "TKAFG1K_ATTR_PWM_SOURCE",
                                       TKAFG1K_VAL_PWM_INTERNAL,
                                       IVI_VAL_MULTI_CHANNEL,
                                       tkafg1kAttrPWMSource_ReadCallback,
                                       tkafg1kAttrPWMSource_WriteCallback,
                                       &attrPWMSourceRangeTable));

    /*- PWM Deviation -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_PWM_DEVIATION,
                                        "TKAFG1K_ATTR_PWM_DEVIATION", 5.0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
                                        tkafg1kAttrPWMDeviation_ReadCallback,
                                        tkafg1kAttrPWMDeviation_WriteCallback,
                                        VI_NULL, 0));

    /*- PWM Internal Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY,
                                        "TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY",
                                        10000.00, IVI_VAL_MULTI_CHANNEL,
                                        tkafg1kAttrPWMInternalFrequency_ReadCallback,
                                        tkafg1kAttrPWMInternalFrequency_WriteCallback,
                                        &attrPWMInternalFrequencyRangeTable, 0));

    /*- PWM Internal Waveform -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM,
	                                   "TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM",
	                                   TKAFG1K_VAL_PWM_INTERNAL_SINE,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrPWMInternalWaveform_ReadCallback,
	                                   tkafg1kAttrPWMInternalWaveform_WriteCallback,
	                                   &attrPWMInternalWaveformRangeTable));
    checkErr (Ivi_SetAttrCheckCallbackViInt32 (vi,
                                               TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM,
                                               tkafg1kAttrPWMInternalWaveform_CheckCallback));

    /*- PWM Width -*/

    /*- Hidden Attributes -----------------------------------------------------------------*/
    /*- Waveform Structure -*/
    checkErr (Ivi_AddAttributeViAddr (vi, TKAFG1K_ATTR_WFM_STRUCTURE,
                                      "TKAFG1K_ATTR_WFM_STRUCTURE", VI_NULL,
                                      IVI_VAL_HIDDEN, VI_NULL, VI_NULL));
    checkErr( tkafg1k_CreateArbRecords(vi));

    /*- Amplitude -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_AMPLITUDE,
                                        "TKAFG1K_ATTR_AMPLITUDE", 1,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        tkafg1kAttrAmplitude_ReadCallback,
                                        tkafg1kAttrAmplitude_WriteCallback, VI_NULL,
                                        0));

    /*- Frequency -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_FREQUENCY,
                                        "TKAFG1K_ATTR_FREQUENCY", 1000000,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_HIDDEN,
                                        tkafg1kAttrFrequency_ReadCallback,
                                        tkafg1kAttrFrequency_WriteCallback, VI_NULL,
                                        0));

    /*- Offset -*/
    checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_OFFSET,
                                        "TKAFG1K_ATTR_OFFSET", 0,
                                        IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
                                        tkafg1kAttrOffset_ReadCallback,
                                        tkafg1kAttrOffset_WriteCallback, VI_NULL, 0));

    /*- Waveform -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_WAVEFORM,
	                                   "TKAFG1K_ATTR_WAVEFORM", TKAFG1K_VAL_WFM_SINE,
	                                   IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
	                                   tkafg1kAttrWaveform_ReadCallback,
	                                   tkafg1kAttrWaveform_WriteCallback,
	                                   &attrWaveformRangeTable));
																				  

    /*- Original Waveform -*/
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_ORIGINAL_WAVEFORM,
	                                   "TKAFG1K_ATTR_ORIGINAL_WAVEFORM",
	                                   TKAFG1K_VAL_WFM_SINE,
	                                   IVI_VAL_MULTI_CHANNEL | IVI_VAL_HIDDEN,
	                                   VI_NULL, VI_NULL, &attrWaveformRangeTable));

    /*- Voltage Upper Limit -*/

    /*- Voltage Lower Limit -*/

    /*- Model -*/
    checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_MODEL, "TKAFG1K_ATTR_MODEL",
                                       model, IVI_VAL_HIDDEN, VI_NULL, VI_NULL,
                                       &attrModelRangeTable));
	checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_SWEEP_ENABLED,
	                                     "TKAFG1K_ATTR_SWEEP_ENABLED", VI_FALSE,
	                                     IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE | IVI_VAL_HIDDEN,
	                                     VI_NULL,
	                                     tkafg1kAttrSweepEnabled_WriteCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_SWEEP_START_FREQUENCY,
	                                    "TKAFG1K_ATTR_SWEEP_START_FREQUENCY", 100000,
	                                    IVI_VAL_MULTI_CHANNEL,
	                                    tkafg1kAttrSweepStartFrequency_ReadCallback,
	                                    tkafg1kAttrSweepStartFrequency_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, TKAFG1K_ATTR_SWEEP_START_FREQUENCY,
	                                         tkafg1kAttrSweepStartFrequency_RangeTableCallback));
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY,
	                                    "TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY", 1000000,
	                                    IVI_VAL_MULTI_CHANNEL,
	                                    tkafg1kAttrSweepStopFrequency_ReadCallback,
	                                    tkafg1kAttrSweepStopFrequency_WriteCallback,
	                                    VI_NULL, 0));
	checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_ASK_ENABLED,
	                                     "TKAFG1K_ATTR_ASK_ENABLED", VI_FALSE,
	                                     IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
	                                     tkafg1kAttrAskEnabled_ReadCallback,
	                                     tkafg1kAttrAskEnabled_WriteCallback));
	checkErr (Ivi_AddAttributeViBoolean (vi, TKAFG1K_ATTR_PSK_ENABLED,
	                                     "TKAFG1K_ATTR_PSK_ENABLED", VI_FALSE,
	                                     IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
	                                     tkafg1kAttrPskEnabled_ReadCallback,
	                                     tkafg1kAttrPskEnabled_WriteCallback));
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_ASK_SOURCE,
	                                   "TKAFG1K_ATTR_ASK_SOURCE",
	                                   TKAFG1K_VAL_ASK_INTERNAL,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrAskSource_ReadCallback,
	                                   tkafg1kAttrAskSource_WriteCallback,
	                                   &attrASKSourceRangeTable));
	checkErr (Ivi_AddAttributeViInt32 (vi, TKAFG1K_ATTR_PSK_SOURCE,
	                                   "TKAFG1K_ATTR_PSK_SOURCE",
	                                   TKAFG1K_VAL_PSK_INTERNAL,
	                                   IVI_VAL_MULTI_CHANNEL,
	                                   tkafg1kAttrPskSource_ReadCallback,
	                                   tkafg1kAttrPskSource_WriteCallback,
	                                   &attrPSKSourceRangeTable));
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_ASK_INTERNAL_RATE,
	                                    "TKAFG1K_ATTR_ASK_INTERNAL_RATE", 50,
	                                    IVI_VAL_MULTI_CHANNEL,
	                                    tkafg1kAttrAskInternalRate_ReadCallback,
	                                    tkafg1kAttrAskInternalRate_WriteCallback,
	                                    &attrASKInternalRateRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_PSK_INTERNAL_RATE,
	                                    "TKAFG1K_ATTR_PSK_INTERNAL_RATE", 50,
	                                    IVI_VAL_MULTI_CHANNEL,
	                                    tkafg1kAttrPskInternalRate_ReadCallback,
	                                    tkafg1kAttrPskInternalRate_WriteCallback,
	                                    &attrPSKInternalRateRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_ASK_AMPLITUDE,
	                                    "TKAFG1K_ATTR_ASK_AMPLITUDE", 0.5,
	                                    IVI_VAL_MULTI_CHANNEL,
	                                    tkafg1kAttrAskAmplitude_ReadCallback,
	                                    tkafg1kAttrAskAmplitude_WriteCallback,
	                                    &attrASKAmplitudeRangeTable, 0));
	checkErr (Ivi_AddAttributeViReal64 (vi, TKAFG1K_ATTR_PSK_DEVIATION,
	                                    "TKAFG1K_ATTR_PSK_DEVIATION", 0,
	                                    IVI_VAL_MULTI_CHANNEL | IVI_VAL_NEVER_CACHE,
	                                    tkafg1kAttrPskDeviation_ReadCallback,
	                                    tkafg1kAttrPskDeviation_WriteCallback,
	                                    &attrPSKDeviationRangeTable, 0));
	checkErr (Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_PSK_DEVIATION,
	                                            tkafg1kAttrPskDeviation_CheckCallback));
	checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_PSK_ENABLED,
	                                             tkafg1kAttrPskEnabled_CheckCallback));
	checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_ASK_ENABLED,
	                                             tkafg1kAttrAskEnabled_CheckCallback));
	checkErr (Ivi_SetAttrRangeTableCallback (vi, TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY,
	                                         tkafg1kAttrSweepStopFrequency_RangeTableCallback));
	checkErr (Ivi_SetAttrCheckCallbackViBoolean (vi, TKAFG1K_ATTR_SWEEP_ENABLED,
	                                             tkafg1kAttrSweepEnabled_CheckCallback));

    /* ----------------------------------------------------------------------------------- */
    /*-- Add Invalidation -----------------------------------------------------------------*/
    /* ----------------------------------------------------------------------------------- */

    /*- Output Impedance -*/
    /* Invalidation List:   TKAFG1K_ATTR_AMPLITUDE
                            TKAFG1K_ATTR_OFFSET
                            TKAFG1K_ATTR_VOLTAGE_UPPER_LIMIT
                            TKAFG1K_ATTR_VOLTAGE_LOWER_LIMIT                */
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_OUTPUT_IMPEDANCE,
                                            TKAFG1K_ATTR_AMPLITUDE, VI_FALSE));
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_OUTPUT_IMPEDANCE,
                                            TKAFG1K_ATTR_OFFSET, VI_FALSE));

    /* Sweep Time */
    /* Invalidation List:   TKAFG1K_ATTR_SWEEP_HOLD_TIME
                            TKAFG1K_ATTR_SWEEP_RETURN_TIME
     */

    /* Sweep Hold Time */
    /* Invalidation List:   TKAFG1K_ATTR_SWEEP_TIME
                            TKAFG1K_ATTR_SWEEP_RETURN_TIME
     */

    /* Sweep Return Time */
    /* Invalidation List:   TKAFG1K_ATTR_SWEEP_TIME
                            TKAFG1K_ATTR_SWEEP_HOLD_TIME
     */

    /* Frequency */
    /* Invalidation List:   TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL
     */
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_FREQUENCY,
                                            TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL,
                                            VI_FALSE));

    /* Waveform */
    /* Invalidation List:   TKAFG1K_ATTR_SWEEP_START_FREQUENCY
                            TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY
                            TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL
                            TKAFG1K_ATTR_FSK_HOP_FREQUENCY
                            TKAFG1K_ATTR_FREQUENCY
    */
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_WAVEFORM,
                                            TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL,
                                            VI_FALSE));
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_WAVEFORM,
                                            TKAFG1K_ATTR_FSK_HOP_FREQUENCY, VI_FALSE));
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_WAVEFORM,
                                            TKAFG1K_ATTR_FREQUENCY, VI_FALSE));
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_AMPLITUDE,
                                            TKAFG1K_ATTR_OFFSET, VI_TRUE));
    checkErr (Ivi_AddAttributeInvalidation (vi, TKAFG1K_ATTR_OFFSET,
                                            TKAFG1K_ATTR_AMPLITUDE, VI_TRUE));

/***---  Add Callback Functions  ---***********************************************************/
    checkErr (tkafg1k_ConfigureModelDependantCallbacks (vi, model));

Error:
    return error;
}

static ViStatus tkafg1k_ConfigureModelDependantCallbacks (ViSession vi, ViInt32 model)
{
    ViStatus    error = VI_SUCCESS;
    /*- TKAFG1K_ATTR_OUTPUT_MODE -*/
    checkErr( Ivi_SetAttrWriteCallbackViInt32 (vi, TKAFG1K_ATTR_OUTPUT_MODE, tkafg1kAttrOutputMode_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViInt32 (vi, TKAFG1K_ATTR_OUTPUT_MODE, tkafg1kAttrOutputMode_ReadCallback) );

    /*- TKAFG1K_ATTR_AMPLITUDE -*/
    checkErr( Ivi_SetAttrCheckCallbackViReal64 ( vi, TKAFG1K_ATTR_AMPLITUDE,
                                                    tkafg1kAttrAmplitude_CheckCallback) );

    /* TKAFG1K_ATTR_OFFSET */
    checkErr( Ivi_SetAttrCheckCallbackViReal64 ( vi, TKAFG1K_ATTR_OFFSET,
                                                    tkafg1kAttrOffset_CheckCallback) );

    /*- TKAFG1K_ATTR_ARB_SAMPLE_RATE -*/
    checkErr( Ivi_SetAttrReadCallbackViReal64 (vi, TKAFG1K_ATTR_ARB_SAMPLE_RATE,
                                                        tkafg1kAttrArbSampleRate_ReadCallback) );
    /*- TKAFG1K_ATTR_MAX_WAVEFORM_SIZE -*/
    checkErr( Ivi_SetAttrReadCallbackViInt32 ( vi, TKAFG1K_ATTR_MAX_WAVEFORM_SIZE,
                                               tkafg1kAttrMaxWaveformSize_ReadCallback) );

    /*- TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM -*/
    checkErr( Ivi_SetAttrWriteCallbackViInt32 (vi, TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM,
                                                    tkafg1kAttrAMInternalWaveform_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViInt32 (vi, TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM,
                                                    tkafg1kAttrAMInternalWaveform_ReadCallback) );

    /*- TKAFG1K_ATTR_AM_INTERNAL_DEPTH -*/
    checkErr( Ivi_SetAttrWriteCallbackViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_DEPTH,
                                                    tkafg1kAttrAMInternalDepth_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_DEPTH,
                                                    tkafg1kAttrAMInternalDepth_ReadCallback) );
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_DEPTH,
                                                    tkafg1kAttrAMInternalDepth_CheckCallback) );

    /*- TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY -*/
    checkErr( Ivi_SetAttrWriteCallbackViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY,
                                                    tkafg1kAttrAMInternalFrequency_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViReal64 (vi, TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY,
                                                    tkafg1kAttrAMInternalFrequency_ReadCallback) );

    /*- TKAFG1K_ATTR_FM_INTERNAL_DEVIATION -*/
    checkErr( Ivi_SetAttrWriteCallbackViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_DEVIATION,
                                                    tkafg1kAttrFMInternalDeviation_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_DEVIATION,
                                                    tkafg1kAttrFMInternalDeviation_ReadCallback) );
    checkErr( Ivi_SetAttrCheckCallbackViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_DEVIATION,
                                                    tkafg1kAttrFMInternalDeviation_CheckCallback) );

    /*- TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM -*/
    checkErr( Ivi_SetAttrWriteCallbackViInt32 (vi, TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM,
                                                    tkafg1kAttrFMInternalWaveform_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViInt32 (vi, TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM,
                                                    tkafg1kAttrFMInternalWaveform_ReadCallback) );

    /*- TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY -*/
    checkErr( Ivi_SetAttrWriteCallbackViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY,
                                                    tkafg1kAttrFMInternalFrequency_WriteCallback) );
    checkErr( Ivi_SetAttrReadCallbackViReal64 (vi, TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY,
                                                    tkafg1kAttrFMInternalFrequency_ReadCallback) );

    /*- TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL -*/
    checkErr( Ivi_SetAttrCheckCallbackViReal64 ( vi, TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL,
                                                    tkafg1kAttrFmDeviationByChannel_CheckCallback) );

    /*- TKAFG1K_ATTR_PWM_DEVIATION -*/
    checkErr( Ivi_SetAttrCheckCallbackViReal64 ( vi, TKAFG1K_ATTR_PWM_DEVIATION,
                                                    tkafg1kAttrPWMDeviation_CheckCallback) );

Error:
    return error;
}

