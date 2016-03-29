/*****************************************************************************
 *  Attribute Test Code for
 *  Tektronics AFG3000 Series Arbitrary Funtion Generator Instrument Driver         
 *  LabWindows/CVI Instrument Driver                                     
 *  By: Penar Zhu, National Instruments                              
 *      PH. 86-21-65557838   Fax 86-21-65556244                              
 *                                                                           
 *  Modification History:                                                    
 *
 *  	 Thursday, June 21, 2005 - Created. 
 *                                                                           
 *****************************************************************************/
 
 
#include <ansi_c.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CUnit.h"
#include "Basic.h"
					
#include "tkafg3k.c" 

/* Global Variables */
ViSession vi = VI_NULL;

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_WFM_STRUCTURE 
 *	
 *******************************************************/

/* Function using TKAFG3K_ATTR_WFM_STRUCTURE:
 *			tkafg3k_InitAttributes (ViSession vi, ViInt32 model)
 *			tkafg3k_CreateArbRecords (ViSession vi)
 *			tkafg3k_GetNumDefinedWaveforms (ViSession vi, ViInt32 *numWfms)
 *			tkafg3k_GetNewWfmInfo (ViSession vi, ViInt32 *wfmHandle)
 *			tkafg3k_UpdateDriverWfmRecord (ViSession vi, ViInt32 wfmHandle, ViInt32 wfmSize)
 *			tkafg3k_WfmExists (ViSession vi, ViInt32 wfmHandle, ViBoolean *wfmExists)
 *			tkafg3k_GetWfmSize (ViSession vi, ViInt32 wfmHandle, ViInt32* wfmSize)
 *			tkafg3k_SetWfmSize (ViSession vi, ViInt32 wfmHandle, ViInt32 wfmSize)
 *			tkafg3k_ClearDriverWfmRecord (ViSession vi, ViInt32 wfmHandle)
 */
 
/* test of waveform structure default initialization */
/* Pre-set arbitrary waveform according to the following definition */
#define TEST_DEFAULT_ARB_WFM_NUMBER			1
#define TEST_ARB_WFM_USER1_EXIST			1
#define TEST_ARB_WFM_USER2_EXIST			0
#define TEST_ARB_WFM_USER3_EXIST			0
#define TEST_ARB_WFM_USER4_EXIST			0
void testAttrWfmStructureDefaultInitialize()
{
	/*  Intialize tkafg3k_ATTR_WFM_STRUCTURE
		tkafg3k_init 
			-->  tkafg3k_InitAttributes
					-->  tkafg3k_CreateArbRecords
					-->	 tkafg3k_DefaultInstrSetup
							-->  tkafg3k_ClearDriverWfmRecord
							-->  tkafg3k_UpdateDriverWfmRecord
	 */
	 
	ViSession localVi;
	wfmNodePtr wfmRecord = VI_NULL;
	ViInt32	maxNumWfms, index = 0;
	ViInt32 actualNumWfms = 0;
	ViBoolean wfmExists;
	
    CU_ASSERT ( VI_SUCCESS == tkafg3k_init ("GPIB0::11::INSTR", VI_FALSE, VI_FALSE, &localVi) );
    
	CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (localVi, VI_NULL, TKAFG3K_ATTR_MAX_NUM_WAVEFORMS, 0, &maxNumWfms));
    CU_ASSERT ( maxNumWfms > 0 );
    
    CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViAddr (localVi, VI_NULL, TKAFG3K_ATTR_WFM_STRUCTURE, 0, (ViAddr *)&wfmRecord) );    

	for(index=0; index<maxNumWfms; index++)
	{
		switch(index)
		{
			case 0:
			{
				wfmExists = TEST_ARB_WFM_USER1_EXIST;
				break;
			}
			case 1:
			{
				wfmExists = TEST_ARB_WFM_USER2_EXIST;
				break;
			}
			case 2:
			{
				wfmExists = TEST_ARB_WFM_USER3_EXIST;
				break;
			}
			case 3:
			{
				wfmExists = TEST_ARB_WFM_USER4_EXIST;
				break;
			}
		}
		
		if(wfmExists)
		{
			CU_ASSERT ( 0 != (wfmRecord+index)->wfmSize );	
			actualNumWfms++;
		}
		else
		{
			CU_ASSERT ( 0 == (wfmRecord+index)->wfmSize );		
		}
	}
	CU_ASSERT (actualNumWfms <= maxNumWfms);
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_close(localVi) );
}

/* test of waveform structure clear arbitrary initialization */
void testAttrWfmStructureClearArbInitialize()
{
	/*  Intialize TKAFG3K_ATTR_WFM_STRUCTURE
		tkafg3k_init 
			-->  tkafg3k_InitAttributes
					-->  tkafg3k_CreateArbRecords
					-->	 tkafg3k_DefaultInstrSetup
							-->  tkafg3k_ClearAllArbWaveform
	 */
	ViSession localVi;
	wfmNodePtr wfmRecord = VI_NULL;
	ViInt32	maxNumWfms, i;
	
    CU_ASSERT ( VI_SUCCESS == tkafg3k_init ("GPIB0::11::INSTR", VI_FALSE, VI_FALSE, &localVi) ); 
	
	// Specify SETUP parameter to clear arbitrary waveforms.
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViString (localVi, "", TKAFG3K_ATTR_DRIVER_SETUP, 0, "ClearArbData is 1") );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_DefaultInstrSetup (localVi) );
	
	CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (localVi, VI_NULL, TKAFG3K_ATTR_MAX_NUM_WAVEFORMS, 0, &maxNumWfms));
    CU_ASSERT ( maxNumWfms > 0 );
    
    CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViAddr (localVi, VI_NULL, TKAFG3K_ATTR_WFM_STRUCTURE, 0, (ViAddr *)&wfmRecord) );    
	for(i=0; i<maxNumWfms; i++)
	{
		CU_ASSERT ( 0 == (wfmRecord+i)->wfmSize );
	}	

	CU_ASSERT ( VI_SUCCESS == tkafg3k_close(localVi) );  	
}

/* test of waveform structure in utility functions */
/*
 *			tkafg3k_InitAttributes (ViSession vi, ViInt32 model)
 *			tkafg3k_CreateArbRecords (ViSession vi)
 *			tkafg3k_GetNumDefinedWaveforms (ViSession vi, ViInt32 *numWfms)
 *			tkafg3k_GetNewWfmInfo (ViSession vi, ViInt32 *wfmHandle)
 *			tkafg3k_UpdateDriverWfmRecord (ViSession vi, ViInt32 wfmHandle, ViInt32 wfmSize)
 *			tkafg3k_WfmExists (ViSession vi, ViInt32 wfmHandle, ViBoolean *wfmExists)
 *			tkafg3k_GetWfmSize (ViSession vi, ViInt32 wfmHandle, ViInt32* wfmSize)
 *			tkafg3k_SetWfmSize (ViSession vi, ViInt32 wfmHandle, ViInt32 wfmSize)
 *			tkafg3k_ClearDriverWfmRecord (ViSession vi, ViInt32 wfmHandle)
 */
#define TEST_WFMSTRUCT_UTIL_IN_DEFAULT		1
void testAttrWfmStructureUitility()
{
	ViInt32 numWfms;
	ViInt32 wfmHandle;
	ViBoolean wfmExists;
	ViInt32 setWfmSize = 100, getWfmSize;
	
	/* Test Waveform Structure utility functions in default initialization */
	if(TEST_WFMSTRUCT_UTIL_IN_DEFAULT)
	{
		/* Test in default initialilzation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetNumDefinedWaveforms(vi, &numWfms) );
		CU_ASSERT ( TEST_DEFAULT_ARB_WFM_NUMBER	== numWfms);
	}
	/* Test Waveform Structure utility functions in clear arbitrary */
	else
	{
		/* Specify SETUP parameter to clear arbitrary waveforms */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViString (vi, "", TKAFG3K_ATTR_DRIVER_SETUP, 0, "ClearArbData=1") );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_DefaultInstrSetup (vi) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetNumDefinedWaveforms(vi, &numWfms) );
		CU_ASSERT ( 0 == numWfms); 		
	}
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetNewWfmInfo(vi, &wfmHandle) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_UpdateDriverWfmRecord(vi, wfmHandle, setWfmSize) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, wfmHandle, &wfmExists) );
	CU_ASSERT ( VI_TRUE == wfmExists );

}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AMPLITUDE 
 * Questionable
 *	
 *******************************************************/

/* Attribute using TKAFG3K_ATTR_AMPLITUDE:
 *						TKAFG3K_ATTR_FUNC_AMPLITUDE
 *						TKAFG3K_ATTR_ARB_GAIN
 *						TKAFG3K_ATTR_OFFSET
 *
 * TKAFG3K_ATTR_AMPLITUDE depends on:
 *						TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT 		
 *						TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT 	
 *						TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 *
 * Attribute Flag:
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:		1
 */

/* test of amplitude flag */
void testAttrAmplitudeFlag()
{
	/* Test In default environment */
	ViReal64 value;

	/* First change impedance to 50 Ohm */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, CHAN1, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, CHAN2, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) ); 	
	
	/* Not User Accessible */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_AMPLITUDE, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_AMPLITUDE, 2) );
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_AMPLITUDE, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_AMPLITUDE, 2) );	
}

/* test of amplitude read and write in default settings */
void testAttrAmplitudeReadAndWriteDefault()
{
	ViReal64 value, originalValue;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* First change impedance to 50 Ohm */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );

		/* change offset to 0 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0, 0	) );
																
		/* Set to default value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 1) );																
																
		/* Check Default Value (Ensure that instrument is in default settings) */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-1) < 1.0e-5 );
	
		/* Set amplitude with valid value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 
																			AFG310X_VAL_MIN_AMPL_IN_50OHM) );		/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MIN_AMPL_IN_50OHM) < 1.0e-5 );	
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 2.0) );			/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-2) < 1.0e-5 );	
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 
																			AFG310X_VAL_MAX_AMPL_IN_50OHM) );		/* Upper Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MAX_AMPL_IN_50OHM) < 1.0e-5 );	
	
		/* Set Amplitude with improper value */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 0) );			/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );		/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );																
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 11.0) );		/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );		/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );	
	}
}

/* test of amplitude read and write in INFINITE impedance */
void testAttrAmplitudeReadAndWriteInInfiniteImpedance()
{
	ViReal64 value, originalValue;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* First change impedance to INFINITE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, TKAFG3K_VAL_IMPEDANCE_INFINITY	) );
		
		/* change offset to 0 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0, 0	) );		
		
		/* Set amplitude with valid value */  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 
																			AFG310X_VAL_MIN_AMPL_IN_OPEN) );			/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MIN_AMPL_IN_OPEN) < 1.0e-5 );	

		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 10.0) );			/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-10.0) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 
																			AFG310X_VAL_MAX_AMPL_IN_OPEN) );			/* Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MAX_AMPL_IN_OPEN) < 1.0e-5 );	
	
		/* Set Amplitude with improper value */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 0) );				/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 21.0) );			/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );		
	}		
}

/* test of amplitude read and write in minimum impedance (1 Ohm) */
void testAttrAmplitudeReadAndWriteInMinimunImpedance()
{
	ViReal64 value, originalValue;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* First change impedance to 1 Ohm */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 1 ) );
		
		/* change offset to 0 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0, 0	) );
		
		/* Set amplitude with valid value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 
																			AFG310X_VAL_MIN_AMPL_IN_50OHM) );			/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MIN_AMPL_IN_50OHM) < 1.0e-5 );	
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 20.0e-3) );			/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-20.0e-3) < 1.0e-5 );	
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 392.0e-3) );		/* Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );
		CU_ASSERT ( fabs(value-392.0e-3) < 1.0e-5 );	
		
		/* Set Amplitude with improper value */ 
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 0) );				/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 1.0) );			/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AMPLITUDE) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );		
		
	}
}

/* test of amplitude read and write with random impedance */
void testAttrAmplitudeReadAndWriteInRandomImpedance()
{
	ViReal64 impedanceValue, randValue;
	ViReal64 amplitudeValue;
	ViReal64 highLimit, lowLimit;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	time_t originalTime, currentTime;
	
	time(&originalTime);
	while(1)
	{
		for(i=0; i<2; i++)
		{
			if(i == 0)
			{
				strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
			}
			else
			{
				strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
			}			
		
			randValue = (rand()+1.0-1.0)/RAND_MAX;
			if(randValue < 1.0/10000.0)
			{
				continue;
			}
			impedanceValue = randValue*10000;
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, impedanceValue) );		/* Set With Random Value */
		
			randValue = (rand()+1.0-1.0)/RAND_MAX;
			if(randValue < 1.0/2000.0)
			{
				continue;
			}		
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &highLimit) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &lowLimit) );
			amplitudeValue = randValue*(highLimit-lowLimit)/2.0;
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, amplitudeValue) );
		}
		
		time(&currentTime);
		if(currentTime - originalTime > 10)
		{
			break;
		}
	}
}

/* Test of amplitude with offset */
void testAttrAmplitudeWithOffset()
{
	ViChar channel[BUFFER_SIZE];
	ViReal64 highLimit, lowLimit; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}				
		
		/* First change impedance to 50 Ohm */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );		
		
		/* Set Amplitude to 10 V */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 10) );		
		
		/* Set Offset to 5 V */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 5) );		
		
		/* Try to set offset large than 5V so the total voltage exceeds voltage upper limit */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 5.1) );
		
		/* Change impedance to INFINITE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 
																						TKAFG3K_VAL_IMPEDANCE_INFINITY ) );		
		/* Set Amplitude to 2 V */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 2) );	
		
		/* Set Offset to 9 V */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 9) );
		
		/* Try to Set Offset large than 9 V so the total voltage exceeds voltage upper limit */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 10) );		
		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_OFFSET 
 * Questionable  
 *	
 *******************************************************/

/* Attribute using TKAFG3K_ATTR_OFFSET:
 *							TKAFG3K_ATTR_FUNC_DC_OFFSET
 *							TKAFG3K_ATTR_ARB_OFFSET
 *							TKAFG3K_ATTR_AMPLITUDE
 * 
 * TKAFG3K_ATTR_OFFSET depends on:
 *						TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT 		
 *						TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT 	
 *						TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 *
 * Attribute Flag:
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:		0
 */						

/* test of offset flag */
void testAttrOffsetFlag()
{
	/* Test In default environment */
	ViReal64 value;

	/* First change impedance to 50 Ohm */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, CHAN1, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, CHAN2, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );
	
	/* Not User Accessible */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_OFFSET, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_OFFSET, 2) );
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_OFFSET, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_OFFSET, 2) );
}

/* test of offset read and wirte in dafault settings */
void testAttrOffsetReadAndWriteDefault()
{
	ViReal64 value, originalValue;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* First change impedance to 50 Ohm */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );
		/* Set Amplitude to relative low level */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 2) );	
	
		/* Set offset with valid value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 
																	AFG310X_VAL_MIN_OFFSET_IN_50OHM) );			/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MIN_OFFSET_IN_50OHM) < 1.0e-5 );	
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 2.0) );		/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );
		CU_ASSERT ( fabs(value-2) < 1.0e-5 );	
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 
																	AFG310X_VAL_MAX_OFFSET_IN_50OHM) );		/* Upper Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MAX_OFFSET_IN_50OHM) < 1.0e-5 );	
	
		/* Set Amplitude with improper value */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, -6.0) );				/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );																
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 6.0) );			/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );																
	}
}

/* test of amplitude read and write in INFINITE impedance */
void testAttrOffsetReadAndWriteInInfiniteImpedance()
{
	ViReal64 amplitude;
	ViReal64 value, originalValue;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* First change impedance to INFINITE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 
																	0, TKAFG3K_VAL_IMPEDANCE_INFINITY	) );
		/* Set Amplitude to relative low level */
		amplitude = 2;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, amplitude) );
		
		/* Set amplitude with valid value */  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 
																	(AFG310X_VAL_MIN_OFFSET_IN_OPEN+amplitude/2) ) );		/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MIN_OFFSET_IN_OPEN-amplitude/2) < 1.0e-5 );	

		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 0) );			/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );
		CU_ASSERT ( fabs(value) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 
																	(AFG310X_VAL_MAX_OFFSET_IN_OPEN-amplitude/2) ) );		/* Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );
		CU_ASSERT ( fabs(value-AFG310X_VAL_MAX_OFFSET_IN_OPEN+amplitude/2) < 1.0e-5 );	
	
		/* Set Amplitude with improper value */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, -10) );				/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &originalValue) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 10) );			/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OFFSET) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &value) );			/* Check if value changed */
		CU_ASSERT ( fabs(value-originalValue) < 1.0e-5 );		
	}	
}

/* test of offset read and write in minimum impedance (1 Ohm) */
void testAttrOffsetReadAndWriteInMinimunImpedance()
{
	ViReal64 amplitude;
	ViReal64 value, originalValue;
	ViReal64 highLimit, lowLimit; 	
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* First change impedance to 1 Ohm */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 1 ) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 
																							AFG310X_VAL_MIN_AMPL_IN_50OHM ) );	
	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &highLimit) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &lowLimit) ); 
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0,
																				(lowLimit+AFG310X_VAL_MIN_AMPL_IN_50OHM) ) );	/* Low Limit */
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0, 0 ) );
																				
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0,
																				(highLimit-AFG310X_VAL_MIN_AMPL_IN_50OHM) ) );	/* high Limit */
		
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0, lowLimit ) );					/* below low limit */	
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OFFSET, 0, highLimit ) );				/* above high limit */
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FREQUENCY 
 *	
 *******************************************************/
 
/* Attribute using TKAFG3K_ATTR_FREQUENCY:
 *						TKAFG3K_ATTR_FUNC_FREQUENCY
 *						TKAFG3K_ATTR_ARB_FREQUENCY
 *						TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL
 * 
 * TKAFG3K_ATTR_FREQUENCY depends on (directly call):
 *						TKAFG3K_ATTR_FUNC_FREQUENCY
 *						TKAFG3K_ATTR_ARB_FREQUENCY
 * 
 * TKAFG3K_ATTR_FREQUENCY depends on (Invalidation):
 *						TKAFG3K_ATTR_WAVEFORM
 *						TKAFG3K_ATTR_PULSE_PERIOD
 *						TKAFG3K_ATTR_OPERATION_MODE
 *
 * TKAFG3K_ATTR_FREQUENCY depends on (indirectly from arbitrary frequency call):
 *						TKAFG3K_ATTR_ARB_SAMPLE_RATE                       
 *
 * TKAFG3K_ATTR_FREQUENCY depends on (indirectly from waveform invalidation):
 *						TKAFG3K_ATTR_OUTPUT_MODE
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 *						TKAFG3K_ATTR_FUNC_WAVEFORM
 *						TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE
 *
 * Attribute Flag:
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:		1000000
 */
 
/* test of frequency flag */
void testAttrFrequencyFlag()
{
	ViReal64 value;
	
	/* Not user readable and writeable */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FREQUENCY, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FREQUENCY, 1000000) );
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FREQUENCY, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FREQUENCY, 1000000) );	
}

/* test of frequency read and write */
void testAttrFrequencyReadAndWrite()
{
	ViReal64 value;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 5000000 ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FREQUENCY) );  
		CU_ASSERT ( fabs(value-5000000) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 1000000 ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FREQUENCY) );  
		CU_ASSERT ( fabs(value-1000000) < 1.0e-5 );		
	}
}

/* test of frequency dependency */
void testAttrFrequencyDependency()
{
	ViReal64 originalValue, value, valueAfterInvalidate;
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* default settings */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) );
		
		/* TKAFG3K_ATTR_FUNC_FREQUENCY */
		/* Set Waveform to SINE */	
		originalValue = 100000000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 100000000) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value) );
		CU_ASSERT ( fabs(value-100000000) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &valueAfterInvalidate) );
		CU_ASSERT ( fabs(valueAfterInvalidate-100000000) < 1.0e-5 ); 
		
		/* TKAFG3K_ATTR_WAVEFORM && TKAFG3K_ATTR_FUNC_WAVEFORM */
		/* Change Waveform to SQUARE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_SQUARE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value) );
		CU_ASSERT ( fabs(value-originalValue) > 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &valueAfterInvalidate) );
		CU_ASSERT ( fabs(valueAfterInvalidate-originalValue) > 1.0e-5 );	
		
		/* TKAFG3K_ATTR_ARB_FREQUENCY && TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		/* Change Output Mode to Arbitrary */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, 100) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value) ); 
		CU_ASSERT ( fabs(value-100) < 1.0e-5);
		
		/* TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE */
		/* Change Arbitrary Waveform to user1 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, TKAFG3K_VAL_WFM_USER1) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, 300) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value) ); 
		CU_ASSERT ( fabs(value-300) < 1.0e-5);		

		/* TKAFG3K_ATTR_PULSE_PERIOD */
		/* Change Output Mode to Func */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_FUNC) ); 	
		/* Change Waveform to Pulse */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 5e-3) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value) ); 
		CU_ASSERT ( fabs(value-200) < 1.0e-5);	
		
		/* TKAFG3K_ATTR_OPERATION_MODE */
		/* Change Waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		/* Change Operation Mode to Continuous */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 		
		/* Set Frequency to Maximum in Continuous Mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, AFG310X_VAL_MAX_FREQ_SINE) );
		/* Change Operation Mode to Burst */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_BURST) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &value) );            		
		CU_ASSERT ( AFG310X_VAL_MAX_FREQ_SINE != value );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_WAVEFORM 
 *	
 *******************************************************/

/* Attribute setting TKAFG3K_ATTR_WAVEFORM (directly):
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 *						TKAFG3K_ATTR_FUNC_WAVEFORM
 *						TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE
 * 
 * Attribute setting TKAFG3K_ATTR_WAVEFORM (indirectly): 
 *						TKAFG3K_ATTR_OUTPUT_MODE
 *
 * Attribute And Run Mode Combination:
 *						TKAFG3K_ATTR_OPERATION_MODE
 *						TKAFG3K_ATTR_CONTINUOUS_ENABLED     	
 *						TKAFG3K_ATTR_MODULATION_ENABLED     	
 *						TKAFG3K_ATTR_SWEEP_ENABLED          	
 *						TKAFG3K_ATTR_BURST_ENABLED          	
 *						TKAFG3K_ATTR_AM_ENABLED
 *						TKAFG3K_ATTR_FM_ENABLED
 *						TKAFG3K_ATTR_FSK_ENABLED
 *						TKAFG3K_ATTR_PM_ENABLED
 *						TKAFG3K_ATTR_PWM_ENABLED
 *
 * TKAFG3K_ATTR_WAVEFORM invalidate:
 *						TKAFG3K_ATTR_SWEEP_START_FREQUENCY
 *						TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY
 *						TKAFG3K_ATTR_FSK_HOP_FREQUENCY
 *						TKAFG3K_ATTR_FREQUENCY
 *
 * Attribute Flag:		
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:		TKAFG3K_VAL_WFM_SINE  
 */

/* test of waveform flag */
void testAttrWaveformFlag()
{
	ViInt32 value;
	
	/* Not user readable and writeable */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );	
}

/* test of waveform read and write */
static ViInt32 testStandardWaveformArray[] = {
							TKAFG3K_VAL_WFM_SINE,     
							TKAFG3K_VAL_WFM_SQUARE,   
							TKAFG3K_VAL_WFM_DC,
							TKAFG3K_VAL_WFM_RAMP,
							TKAFG3K_VAL_WFM_PULS,
							TKAFG3K_VAL_WFM_PRN,
							TKAFG3K_VAL_WFM_SINC,
							TKAFG3K_VAL_WFM_GAUS,
							TKAFG3K_VAL_WFM_LOR,
							TKAFG3K_VAL_WFM_ERIS,
							TKAFG3K_VAL_WFM_EDEC,
							TKAFG3K_VAL_WFM_HAV,
							};
							
static ViInt32 testArbitraryWaveformArray[] = {
							TKAFG3K_VAL_WFM_USER1,
							TKAFG3K_VAL_WFM_USER2,
							TKAFG3K_VAL_WFM_USER3,
							TKAFG3K_VAL_WFM_USER4,
							TKAFG3K_VAL_WFM_EDIT,
							};

#define TEST_STANDARD_WAVEFORM_QUANTUM		12
#define TEST_ARBITRARY_WAVEFORM_QUANTUM		5
void testAttrWaveformReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform, readWaveform;
	ViBoolean exists;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   	
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_WAVEFORM) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &readWaveform) );
			CU_ASSERT ( waveform == readWaveform );
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_TRUE)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
				CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_WAVEFORM) );
				CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &readWaveform) );
				CU_ASSERT ( waveform == readWaveform );			
			}
		}
	}
}

/* test of waveform dependency */
void testAttrWaveformDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 originalWaveform, readWaveform;
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Default Settings */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, 0, TKAFG3K_VAL_WFM_EDIT) );  				
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );

		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL && TKAFG3K_ATTR_FUNC_WAVEFORM && TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE*/
		/* Set Waveform to square */ 
		originalWaveform = TKAFG3K_VAL_WFM_SQUARE;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, originalWaveform) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &readWaveform) );
		CU_ASSERT ( originalWaveform == readWaveform );		
		
		/* change output mode to arbitrary waveform */ 
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &readWaveform ) );
		CU_ASSERT ( originalWaveform != readWaveform );
		
		/* Set waveform to USER1 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, 0, TKAFG3K_VAL_WFM_USER1) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &readWaveform ) ); 
		CU_ASSERT ( TKAFG3K_VAL_WFM_USER1 == readWaveform );
		
		/* change output mode back to function waveform */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &readWaveform ) );
		CU_ASSERT ( originalWaveform == readWaveform ); 
		
		/* Back to dafault settings */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );		
	}
}

/* test of waveform and run mode combination */
static ViInt32 testRunModeArray[] = {

					TKAFG3K_VAL_OPERATE_CONTINUOUS,
					TKAFG3K_VAL_OPERATE_MODULATION,
					TKAFG3K_VAL_OPERATE_SWEEP,
					TKAFG3K_VAL_OPERATE_BURST,
};
#define TEST_RUN_MODE_QUANTUM		4 
void testAttrWaveformWithRunModeCombination()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j, k;
	ViInt32 waveform, readWaveform, runMode;
	ViBoolean exists, allowance;
	
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
	
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)   
		{
			/* back to continuous mode */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testStandardWaveformArray[j]; 
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			for(k=0; k<TEST_RUN_MODE_QUANTUM; k++)
			{
				// ViStatus combination;
				runMode = testRunModeArray[k];
				CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, runMode, &allowance) );

				if(allowance)
				{
					CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, runMode) );				
				}
				else
				{
					CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, runMode) );					
				}
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++) 
		{

			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_TRUE)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
				for(k=0; k<TEST_RUN_MODE_QUANTUM; k++)
				{
					runMode = testRunModeArray[k];
					CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, runMode, &allowance) );
					if(allowance)
					{					
						CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, runMode) );
					}
					else 
					{
						CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, runMode) );						
					}
				}						
			}
		}
	}		
}

/* test of waveform invalidation */
void testAttrWaveformInvalidation()
{
	ViChar channel[BUFFER_SIZE]; 
	ViReal64 originalFreq, frequency;
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Default Settings */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );		
		
		/* TKAFG3K_ATTR_FREQUENCY */  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 100000000) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SQUARE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( 100000000 != frequency );
		
		originalFreq = frequency;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_RAMP) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( frequency != originalFreq );
		
		/* TKAFG3K_ATTR_SWEEP_START_FREQUENCY */
		/* change back to sine waveform */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		/* change to sweep mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_SWEEP) );
		/* change start frequency to 100,000,000 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, 0, 100000000) );
		
		/* change waveform to square */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SQUARE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( 100000000 != frequency );
		
		/* change waveform to ramp */
		originalFreq = frequency;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_RAMP) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( frequency != originalFreq );
		
		/* TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY */
		/* change back to sine waveform */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		/* change to sweep mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_SWEEP) );
		/* change start frequency to 100,000,000 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY, 0, 100000000) );

		/* change waveform to square */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SQUARE) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( 100000000 != frequency );
		
		/* change waveform to ramp */
		originalFreq = frequency;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_RAMP) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( frequency != originalFreq );
		
		/* TKAFG3K_ATTR_FSK_HOP_FREQUENCY */
		/* change back to sine waveform */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		/* change to modulation mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_MODULATION) );	
		/* change to FSK mudulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_FSK_ENABLED, 0, VI_TRUE) );
		/* change start frequency to 100,000,000 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, 0, 100000000) );
		
		/* change waveform to square */  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SQUARE) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( 100000000 != frequency );		
		
		/* change waveform to ramp */
		originalFreq = frequency;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_RAMP) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( frequency != originalFreq );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ORIGINAL_WAVEFORM 
 *	
 *******************************************************/

/* Attribute setting TKAFG3K_ATTR_ORIGINAL_WAVEFORM (directly):
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 * 
 * Attribute setting TKAFG3K_ATTR_ORIGINAL_WAVEFORM (indirectly): 
 *						TKAFG3K_ATTR_OUTPUT_MODE
 *
 * Attribute Flag:		
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:		TKAFG3K_VAL_WFM_SINE  
 */

/* test of original waveform flag */ 
void testAttrOriginalWaveformFlag()
{
	ViInt32 value;
	
	/* Not user readable and writeable */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );			
}

/* test of original waveform read and write */
void testAttrOriginalWaveformReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform, readWaveform;
	ViBoolean exists;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );

		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, waveform) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, &readWaveform) );
			CU_ASSERT ( waveform == readWaveform );
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, waveform) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, &readWaveform) );
			CU_ASSERT ( waveform == readWaveform );			
		}
		
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, -1) );
	}
}

/* test of original waveform dependency */
void testAttrOriginalWaveformDependency()
{
	ViInt32 waveform;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SQUARE) );
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, &waveform) );
		CU_ASSERT ( TKAFG3K_VAL_WFM_SQUARE == waveform );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_USER1) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) ); 		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_WAVEFORM, 0, &waveform) );
		CU_ASSERT ( TKAFG3K_VAL_WFM_USER1 == waveform );		
	}	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT depends on (Invalidation):
 *						TKAFG3K_ATTR_OUTPUT_IMPEDANCE												
 *
 * Attribute Flag:		
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *						IVI_VAL_NOT_WRITABLE
 */

/* test of voltage upper limit flag */
void testAttrVoltageUpperLimitFlag() 
{
	ViReal64 value; 
	
	/* Not user readable and writeable */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 1) );
	
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 1) );
}

/* test of voltage upper limit read and write */
void testAttrVoltageUpperLimitReadAndWrite()
{
	ViReal64	originalValue, value;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );	
		
		// Not Writable
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, 1) );
		
		// Upper Limit in impedance of 1 Ohm
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 1 ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &value) );
		
		// Upper Limit in impedance of 10 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 10 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );
		
		// Upper Limit in impedance of 20 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 20 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );	
		
		// Upper Limit in impedance of 40 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 40 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );
		
		// Upper Limit in impedance of 50 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );		
	}		
}


/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT depends on (Invalidation):
 *						TKAFG3K_ATTR_OUTPUT_IMPEDANCE												
 *
 * Attribute Flag:		
 *						IVI_VAL_HIDDEN 
 *						IVI_VAL_MULTI_CHANNEL
 *						IVI_VAL_NOT_WRITABLE 
 */

/* test of voltage lower limit flag*/
void testAttrVoltageLowerLimitFlag()
{
	ViReal64 value; 
	
	/* Not user readable and writeable */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 1) );
	
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, &value) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 1) );	
}

/* test of voltage lower limit read and write */
void testAttrVoltageLowerLimitReadAndWrite()
{
	ViReal64	originalValue, value;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (	vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );	
		
		// Not user writable
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );		
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, 1) ); 		
		
		// Upper Limit in impedance of 1 Ohm
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 1 ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &value) );
		
		// Upper Limit in impedance of 10 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 10 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );
		
		// Upper Limit in impedance of 20 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 20 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );	
		
		// Upper Limit in impedance of 40 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 40 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );
		
		// Upper Limit in impedance of 50 Ohm
		originalValue = value;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50 ) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 ( vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &value) ); 
		CU_ASSERT ( originalValue != value );		
	}		
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_CONTINUOUS_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_CONTINUOUS_ENABLED used by:
 * 						TKAFG3K_ATTR_OPERATION_MODE
 *						
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE 
 *						IVI_VAL_HIDDEN
 *						IVI_VAL_NOT_READABLE
 */
 
/* test of continuous enabled flag */ 
void testAttrContinuousEnabledFlag()
{
	ViBoolean value = VI_FALSE;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		/* Not user readable and writable */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, VI_TRUE ) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, &value ) ); 

		/* Set the value to true */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE ) );
	
		/* Change waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		/* Change the value to false by enable other operation mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE ) );
		
		/* Set the value to true again */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE ) );		
	}

}

/* test of continuous enabled read and write */
void testAttrContinuousEnabledReadAndWrite()
{
	ViBoolean value = VI_FALSE; 
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* only value of VI_TRUE is approved */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE ) );
	
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_FALSE ) ); 
		
		/* it is not readable */
		CU_ASSERT ( VI_SUCCESS != Ivi_GetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, &value ) );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_MODULATION_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_MODULATION_ENABLED used by:
 * 						TKAFG3K_ATTR_OPERATION_MODE
 * 
 * Related Attribute:
 *						TKAFG3K_ATTR_WAVEFORM
 *						
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE 
 *						IVI_VAL_HIDDEN
 *						IVI_VAL_NOT_READABLE
 */

/* test of modulation enabled flag */
void testAttrModulationEnabledFlag()
{
	ViBoolean value = VI_FALSE;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Not user readable and writable */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, VI_TRUE ) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, &value ) );
		
		/* Never cache */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE ) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE ) );
		
		/* Not readable */
		CU_ASSERT ( VI_SUCCESS != Ivi_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, &value) );
	}
}

/* test of modulation enabled write */
void testAttrModulationEnabledWrite()
{
	ViBoolean value = VI_FALSE;
	ViBoolean allowance;
	ViBoolean exists;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j, waveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* test of mudulation enabled TRUE with different waveform type */	
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)   
		{
			/* back to continuous mode */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testStandardWaveformArray[j]; 
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_MODULATION, &allowance) );

			if(allowance)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) );			
			}
			else
			{																													
				CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) );			
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++) 
		{

			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_TRUE)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
				
				CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_MODULATION, &allowance) );

				if(allowance)
				{
					CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) );			
				}
				else
				{																													
					CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) );			
				}
			}
		}
		
		/* test of mudulation enabled FALSE with waveform PULSE */  	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) );
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_FALSE) );	
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_SWEEP_ENABLED used by:
 * 						TKAFG3K_ATTR_OPERATION_MODE
 * 
 * Related Attribute:
 *						TKAFG3K_ATTR_WAVEFORM
 *						
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE 
 *						IVI_VAL_HIDDEN
 *						IVI_VAL_NOT_READABLE
 */

/* test of Sweep Enabled Flag */
void testAttrSweepEnabledFlag()
{
	ViBoolean value = VI_FALSE;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Not user readable and writable */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, VI_TRUE ) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, &value ) );
		
		/* Never cache */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE ) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE ) );
		
		/* Not readable */
		CU_ASSERT ( VI_SUCCESS != Ivi_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, &value) );
	}
}

/* test of sweep enabled write */
void testAttrSweepEnabledWrite()
{
	ViBoolean value = VI_FALSE;
	ViBoolean allowance;
	ViBoolean exists;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j, waveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* test of sweep enabled TRUE with different waveform type */	
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)   
		{
			/* back to continuous mode */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testStandardWaveformArray[j]; 
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_SWEEP, &allowance) );

			if(allowance)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE) );			
			}
			else
			{																													
				CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE) );			
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++) 
		{

			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_TRUE)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
				
				CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_SWEEP, &allowance) );

				if(allowance)
				{
					CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE) );			
				}
				else
				{																													
					CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE) );			
				}

			}
		}
		
		/* test of mudulation enabled FALSE with waveform SINE */  	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_TRUE) );
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_SWEEP_ENABLED, 0, VI_FALSE) );	
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_BURST_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_BURST_ENABLED used by:
 * 						TKAFG3K_ATTR_OPERATION_MODE
 * 
 * Related Attribute:
 *						TKAFG3K_ATTR_WAVEFORM
 *						
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE 
 *						IVI_VAL_HIDDEN
 *						IVI_VAL_NOT_READABLE
 */

/* test of burst enabled flag */
void testAttrBurstEnabledFlag()
{
	ViBoolean value = VI_FALSE;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Not user readable and writable */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_BURST_ENABLED, VI_TRUE ) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_BURST_ENABLED, &value ) );
		
		/* Never cache */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE ) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_CONTINUOUS_ENABLED, 0, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE ) );
		
		/* Not readable */
		CU_ASSERT ( VI_SUCCESS != Ivi_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, &value) );
	}	
}

/* test of burst enabled write */
void testAttrBurstEnabledWrite()
{
	ViBoolean value = VI_FALSE;
	ViBoolean allowance;
	ViBoolean exists;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j, waveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* test of sweep enabled TRUE with different waveform type */	
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)   
		{
			/* back to continuous mode */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testStandardWaveformArray[j]; 
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_BURST, &allowance) );

			if(allowance)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE) );			
			}
			else
			{																													
				CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE) );			
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++) 
		{

			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) ); 
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_TRUE)
			{
				CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
				
				CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_BURST, &allowance) );

				if(allowance)
				{
					CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE) );			
				}
				else
				{																													
					CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE) );			
				}

			}
		}
		
		/* test of mudulation enabled FALSE with waveform SINE */  	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_TRUE) );
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_BURST_ENABLED, 0, VI_FALSE) );	
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ORIGINAL_MODULATION 
 *	
 *******************************************************/
/* TKAFG3K_ATTR_ORIGINAL_MODULATION dependency (CALL):
 *						TKAFG3K_ATTR_MODULATION_ENABLED
 * 						TKAFG3K_ATTR_AM_ENABLED
 *						TKAFG3K_ATTR_FM_ENABLED
 *						TKAFG3K_ATTR_PM_ENABLED
 *						TKAFG3K_ATTR_FSK_ENABLED
 *						TKAFG3K_ATTR_PWM_ENABLED
 * 
 * Attribute Flag:
 * 						IVI_VAL_MULTI_CHANNEL
 * 						IVI_VAL_HIDDEN
 *
 * Default Value:
 *						TKAFG3K_VAL_MODULATION_AM
 */
 
#define TEST_MODULATION_TYPE_QUANTUM		5	
static ViInt32 testModulationTypeArray[] = {

	TKAFG3K_VAL_MODULATION_AM,
	TKAFG3K_VAL_MODULATION_FM,
	TKAFG3K_VAL_MODULATION_PM,
	TKAFG3K_VAL_MODULATION_FSK,
	TKAFG3K_VAL_MODULATION_PWM,
}; 

/* test of original modulation flag */
void testAttrOriginalModulationFlag()
{
	ViInt32 value;
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ORIGINAL_MODULATION, TKAFG3K_VAL_MODULATION_AM) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ORIGINAL_MODULATION, &value) );
	
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ORIGINAL_MODULATION, TKAFG3K_VAL_MODULATION_AM) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ORIGINAL_MODULATION, &value) );	
}

/* test of original modulation read and write */
void testAttrOriginalModulationReadAndWrite()
{
	ViChar channel[BUFFER_SIZE];	
	ViInt32 modulationType, readModulationType;
	ViInt32 i, j;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		for(j=0; j<TEST_MODULATION_TYPE_QUANTUM; j++)
		{
			modulationType = testModulationTypeArray[j];
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, modulationType ) );
			
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, &readModulationType ) );
			CU_ASSERT ( modulationType == readModulationType);
		}
		
		/* value out of range table */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, (TKAFG3K_VAL_MODULATION_AM-100) ) );         	
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, (TKAFG3K_VAL_MODULATION_PWM+100) ) );     
	}		
}

/* test of original modulation dependency */
void testAttrOriginalModulationDependency()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 modulationType;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		/* Enable AM Modulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_AM_ENABLED, 0, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, &modulationType) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_AM_ENABLED, 0, VI_FALSE) ); 
		CU_ASSERT ( TKAFG3K_VAL_MODULATION_AM == modulationType );
		
		/* Enable FM Modulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_FM_ENABLED, 0, VI_TRUE) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, &modulationType) );
		CU_ASSERT ( TKAFG3K_VAL_MODULATION_FM == modulationType );
		
		/* Enable PM Modulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_PM_ENABLED, 0, VI_TRUE) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, &modulationType) );
		CU_ASSERT ( TKAFG3K_VAL_MODULATION_PM == modulationType );	
		
		/* Enable FSK Modulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_FSK_ENABLED, 0, VI_TRUE) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, &modulationType) );
		CU_ASSERT ( TKAFG3K_VAL_MODULATION_FSK == modulationType );	
		
		/* Enable PWM Modulation */
		/* Change waveform to pulse */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_TRUE) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ORIGINAL_MODULATION, 0, &modulationType) );
		CU_ASSERT ( TKAFG3K_VAL_MODULATION_PWM == modulationType );			
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PULSE_WIDTH 
 *	
 *******************************************************/
/* TKAFG3K_ATTR_PULSE_WIDTH dependency (CALL):
 *						TKAFG3K_ATTR_PWM_DEVIATION
 * 
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 * 						IVI_VAL_NEVER_CACHE
 * 						IVI_VAL_HIDDEN
 *						IVI_VAL_NOT_WRITABLE
 *
 * Default Value:
 *						500.0e-9
 */

/* test of pulse width flag */
void testAttrPulseWidthFlag()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i; 	
	ViReal64 originalValue, readValue;
	ViSession io;
	
	io = Ivi_IOSession(vi);
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		/* Not user readable and writable */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, 500.0e-9) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, &readValue) );
	
		/* Not writable */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, 0, 500.0e-9) );
	
		/* Never Cache */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );	
		CU_ASSERT ( VI_SUCCESS == viPrintf(io, "SOUR%s:PULS:HOLD DUTY", channel) );
	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 1.0e5) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, 0, &readValue) );
	
		/* change frequency */
		originalValue = readValue;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 1.0e4) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, 0, &readValue) ); 	
		CU_ASSERT ( originalValue != readValue);
	}
}

/* test of pulse width read */
void testAttrPulseWidthRead()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i; 	
	ViReal64 originalValue, readValue; 	
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );   
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 ( vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		/* Set Frequency to 10 Hz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 10) ); 
		/* Set Duty Cycle to 50% */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 0, 50) );
		/* Get Pulse Width */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, 0, &readValue) ); 
		CU_ASSERT ( (readValue-50.0e-3) < 1.0e-6 );
		
		/* Set Frequency to 50 Hz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50) );		
		/* Set Duty Cycle to 20% */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 0, 20) );		
		/* Get Pulse Width */
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_WIDTH, 0, &readValue) ); 
		CU_ASSERT ( (readValue-4.0e-3) < 1.0e-6 );     		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_CHANNEL_COUNT 
 *	
 *******************************************************/
 
/* (Inherent Attribute)
 * Read / Not Writable
 */
 
/* test of channel count read */ 
void testAttrChannelCountRead()
{
	ViInt32 channelCount;

	/* Read */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_CHANNEL_COUNT, &channelCount) );
	CU_ASSERT ( 2 == channelCount );
	
	/* Not Writable */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_CHANNEL_COUNT, 2) );      
}

/*******************************************************
 *
 * Unit Test Code for 	TKAFG3K_ATTR_OUTPUT_MODE 
 *	
 *******************************************************/

/* Attribute Flag:
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						TKAFG3K_VAL_OUTPUT_FUNC
 */
 
/* test of output mode flag */ 
void testAttrOutputModeFlag()
{
	ViInt32 outputMode;
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  		
	
	/* firstly set output mode to func */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, TKAFG3K_VAL_OUTPUT_FUNC) );
	
	/* set output mode by channel to arbitrary */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_ARB) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_ARB) );  	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, &outputMode) ); 	
	CU_ASSERT ( TKAFG3K_VAL_OUTPUT_FUNC != outputMode );
}

/* test of output mode read and write */
void testAttrOutputModeReadAndWrite()
{
	ViInt32 outputMode; 
	
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	
	/* firstly set output mode to func */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, 0, TKAFG3K_VAL_OUTPUT_FUNC) );
	CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, 0, &outputMode) );
	CU_ASSERT ( TKAFG3K_VAL_OUTPUT_FUNC == outputMode );
	
	/* change waveform to USER1 in channel 1 */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_USER1) );
	CU_ASSERT ( VI_SUCCESS != Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, 0, &outputMode) ); 
	
	/* change waveform to USER1 in channel 2 */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_USER1) ); 
	CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, 0, &outputMode) ); 
	CU_ASSERT ( TKAFG3K_VAL_OUTPUT_ARB == outputMode ); 
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL depends on (CALL):
 *						TKAFG3K_ATTR_OUTPUT_MODE
 *
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						TKAFG3K_VAL_OUTPUT_FUNC
 */

/* test of output mode by channel flag */
void testAttrOutputModeByChannelFlag()
{
	ViChar channel[BUFFER_SIZE]; 	
	ViInt32 outputMode; 
	ViInt32 i;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Never Cache */
		/* Set Operation Mode to Continuous */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
				
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );
		/* change waveform to arbitrary */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_USER1) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, &outputMode) );
		CU_ASSERT ( TKAFG3K_VAL_OUTPUT_FUNC != outputMode );
	}
}

/* test of output mode by channel read and write */
void testAttrOutputModeByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 	
	ViInt32 outputMode, waveform;
	ViInt32 i;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, &waveform) );
		CU_ASSERT ( TKAFG3K_VAL_WFM_SINE == waveform );
		
		/* Set value out of range table */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_ARB+100) ); 		
	}
}

/* test of output mode by channel dependency */
void testAttrOutputModeByChannelDepenency()
{
	ViInt32 outputMode;
	
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  	
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG3K_VAL_OUTPUT_FUNC) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, 0, TKAFG3K_VAL_OUTPUT_ARB) );
	
	CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, &outputMode) );
	CU_ASSERT ( TKAFG3K_VAL_OUTPUT_FUNC != outputMode );
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_REF_CLOCK_SOURCE 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *						None
 *
 * Default Value:
 *						TKAFG3K_VAL_REF_CLOCK_INTERNAL
 */
 
/* test of reference source read and write */
void testAttrReferenceSourceReadAndWrite()
{
	ViInt32 referenceSource;
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_REF_CLOCK_SOURCE, TKAFG3K_VAL_REF_CLOCK_EXTERNAL) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_REF_CLOCK_SOURCE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_REF_CLOCK_SOURCE, &referenceSource) );
	CU_ASSERT ( TKAFG3K_VAL_REF_CLOCK_EXTERNAL == referenceSource );
	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_OUTPUT_ENABLED 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						VI_FALSE
 */

/* test of output enabled read and write */
void testAttrOutputEnabledReadAndWrite()
{
	ViBoolean enabled = VI_FALSE;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 	
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_OUTPUT_ENABLED, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute ( vi, channel, TKAFG3K_ATTR_OUTPUT_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean ( vi, channel, TKAFG3K_ATTR_OUTPUT_ENABLED, &enabled) );
		CU_ASSERT ( VI_TRUE == enabled );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_OUTPUT_IMPEDANCE 
 *	
 *******************************************************/
 
/*
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Invalidation: 		TKAFG3K_ATTR_AMPLITUDE
 *						TKAFG3K_ATTR_OFFSET
 *						TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT
 *						TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT
 *
 * Default Value:
 *						50 Ohm
 */

/* test of output impedance read and write */
void testAttrOuputImpedanceReadAndWrite()
{
	ViReal64 readValue;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 	
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 1.0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, &readValue) );
		CU_ASSERT ( fabs(readValue-1.0) < 1.0e-6 );
		
		/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50.0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, &readValue) );
		CU_ASSERT ( fabs(readValue-50.0) < 1.0e-6 );		
		
		/* Upper Limit */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 10000.0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, &readValue) );
		CU_ASSERT ( fabs(readValue-10000.0) < 1.0e-6 );
		
		/* INFINITE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, TKAFG3K_VAL_IMPEDANCE_INFINITY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, &readValue) );
		CU_ASSERT ( readValue == TKAFG3K_VAL_IMPEDANCE_INFINITY );	
		
		/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0.9) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, &readValue) );
		CU_ASSERT ( fabs(readValue-0.9) > 1.0e-6 );	
		
		/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 10001.0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, &readValue) );
		CU_ASSERT ( fabs(readValue-10001.0) > 1.0e-6 );		
	}
}

/* test of output impedance invalidation */
void testAttrOuputImpedanceInvalidation()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 originalAmplitude, originalOffset, originalUpperLimit, originalLowerLimit;
	ViReal64 amplitude, offset, upperLimit, lowerLimit;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
				 
		/* Set in 50 Ohm */		
		originalAmplitude = 10.0;
		originalOffset = 5.0;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 50.0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, originalAmplitude) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, originalOffset) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &originalUpperLimit) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &originalLowerLimit) );

		/* change output impedance to 1 Ohm */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 0, 1.0) ); 		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, &amplitude) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, &offset) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT, 0, &upperLimit) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT, 0, &lowerLimit) );
		
		CU_ASSERT ( fabs (amplitude - originalAmplitude) > 1.0e-6 );
		CU_ASSERT ( fabs (offset - originalOffset) > 1.0e-6 ); 	
		CU_ASSERT ( fabs (upperLimit - originalUpperLimit) > 1.0e-6 );
		CU_ASSERT ( fabs (lowerLimit - originalLowerLimit) > 1.0e-6 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_OPERATION_MODE 
 *	
 *******************************************************/
 
/*
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					TKAFG3K_VAL_OPERATE_CONTINUOUS
 */

/* test of operation mode flag */
void testAttrOperationModeFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 operationMode;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Never Cache */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, 0, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) );
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_CONTINUOUS != operationMode );
	}
}

/* test of operation mode read and write */
void testAttrOperationModeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 operationMode;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* test operation mode switch with SINE waveform */
		/* test of run mode combination with waveform has been tested in waveform attribute */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) ); 		
		
		/* change run mode to modulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_MODULATION) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_MODULATION == operationMode ); 

		/* change run mode to sweep */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_SWEEP) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_SWEEP == operationMode ); 

		/* change run mode to burst */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_BURST) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_BURST == operationMode );		
		

		/* test operation mode with PULSE waveform */
		/* return to continuous mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		
		/* change run mode to modulation */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_MODULATION) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_MODULATION == operationMode );
		
		/* change run mode to sweep */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_SWEEP) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_SWEEP != operationMode );
		
		/* change run mode to burst */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_BURST) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_BURST == operationMode );
		
		/* test operation mode with DC waveform */
		/* return to continuous mode */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_DC) );
		
		/* change run mode to modulation */ 
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_MODULATION) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_MODULATION != operationMode );	
		
		/* change run mode to sweep */ 
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_SWEEP) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_SWEEP != operationMode );
		
		/* change run mode to burst */ 
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, TKAFG3K_VAL_OPERATE_BURST) ); 	
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, &operationMode) ); 
		CU_ASSERT ( TKAFG3K_VAL_OPERATE_BURST != operationMode );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_WAVEFORM 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_FUNC_WAVEFORM depends on:
 *					TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 * 
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					TKAFG3K_VAL_WFM_SINE
 */

/* test of func waveform flag */
void testAttrFuncWaveformFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* NEVER CACHE */
		/* change to SINE waveform */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_HAV) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, &waveform) );
		CU_ASSERT ( TKAFG3K_VAL_WFM_SINE != waveform );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, &waveform) );
		CU_ASSERT ( TKAFG3K_VAL_WFM_EDIT == waveform );
	}
}

/* test of func waveform read and write */
void testAttrFuncWaveformReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform, readWaveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_FUNC) );  
		
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, waveform) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, &readWaveform) );
			CU_ASSERT ( waveform == readWaveform );
		}
		
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, -1) );
	}
}

/* test of func waveform dependency */
void testAttrFuncWaveformDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, TKAFG3K_VAL_OUTPUT_ARB) ); 	
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_SINE) );	
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_AMPLITUDE 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_FUNC_AMPLITUDE depends on:
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL  
 *						TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 *						TKAFG3K_ATTR_FUNC_DC_OFFSET
 *
 * Attribute Flag:
 *   					IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						1
 */
 
/* test of func amplitude flag */ 
void testAttrFuncAmplitudeFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	amplitude;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 0) );
		
		/* NEVER CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 5.0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 4.0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, &amplitude) );
		CU_ASSERT ( 5.0 != amplitude );		
	}
}
 
/* test of func amplitude read and write */
void testAttrFuncAmplitudeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	amplitude;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 0) );

		/* Amplitude */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 				/* Upper Value */
																					AFG310X_VAL_MAX_AMPL_IN_50OHM) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, &amplitude) );
		CU_ASSERT ( fabs(amplitude-AFG310X_VAL_MAX_AMPL_IN_50OHM) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 				/* Lower Value */
																					AFG310X_VAL_MIN_AMPL_IN_50OHM) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, &amplitude) );
		CU_ASSERT ( fabs(amplitude-AFG310X_VAL_MIN_AMPL_IN_50OHM) < 1.0e-5 );	
		
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 				/* Above Upper Value */
																					(AFG310X_VAL_MAX_AMPL_IN_50OHM+1) ) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, &amplitude) );
		CU_ASSERT ( fabs(amplitude-AFG310X_VAL_MAX_AMPL_IN_50OHM-1) > 1.0e-5 );		
		
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 				/* Below Lower Value */
																					(AFG310X_VAL_MIN_AMPL_IN_50OHM-1) ) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, &amplitude) );
		CU_ASSERT ( fabs(amplitude-AFG310X_VAL_MIN_AMPL_IN_50OHM+1) > 1.0e-5 );			
	}
}

/* test of func amplitude dependency */ 
void testAttrFuncAmplitudeDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	amplitude;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 0) );
		
		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_ARB) );	
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 0, 1.0) );
		
		/* TKAFG3K_ATTR_OUTPUT_IMPEDANCE 
		   && TKAFG3K_ATTR_FUNC_DC_OFFSET 
		   have been tested in attribtue TKAFG3K_ATTR_AMPLITUDE
		 */
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_DC_OFFSET 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_FUNC_DC_OFFSET depends on:
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL  
 *						TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 *						TKAFG3K_ATTR_FUNC_AMPLITUDE
 *
 * Attribute Flag:
 *   					IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						0
 */

 /* test of func dc offset flag */
void testAttrFuncDCOffsetFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	offset;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 1) );		
		
		/* NEVER CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 5) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 4) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, &offset) );
		CU_ASSERT ( fabs(offset-5) > 1.0e-5 );
	 }
}

/* test of func dc offset read and write */
void testAttrFuncDCOffsetReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	offset;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 2) );	
		
		/* dc offset */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 4) );		/* upper limit */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, &offset) );
		CU_ASSERT ( fabs(offset-4) < 1.0e-5 );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, -4) );	/* lower limit */  		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, &offset) );
		CU_ASSERT ( fabs(offset+4) < 1.0e-5 );		
		
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 6) );		/* above upper limit */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, &offset) );
		CU_ASSERT ( fabs(offset-6) > 1.0e-5 );		

		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, -6) );	/* below lower limit */  		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, &offset) );
		CU_ASSERT ( fabs(offset+6) > 1.0e-5 );	
	}
}

/* test of func dc offset dependency */
void testAttrFuncDCOffsetDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	offset;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_AMPLITUDE, 2) );

		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_DC_OFFSET, 0) );
		
		/* TKAFG3K_ATTR_OUTPUT_IMPEDANCE 
		   && TKAFG3K_ATTR_FUNC_DC_OFFSET 
		   have been tested in attribtue TKAFG3K_ATTR_AMPLITUDE
		 */		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_FREQUENCY 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_FUNC_FREQUENCY depends on:
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL  
 *						TKAFG3K_ATTR_FUNC_WAVEFORM
 *						TKAFG3K_ATTR_OPERATION_MODE
 *
 * Attribute Flag:
 *   					IVI_VAL_MULTI_CHANNEL 
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						0
 */
 
/* test of func frequency flag */
void testAttrFuncFrequencyFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	frequency;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		
		/* Never Cache */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, 50000) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 100000) );    
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &frequency) );
		CU_ASSERT ( fabs(frequency-50000) > 1.0e-5 );
	}
}

/* test of func frequency read and write */
void testAttrFuncFrequencyReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;  
	ViInt32	waveform;  	
	ViReal64 frequency, readFreq, maxFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, 
																							TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );

		/* test of frequency read and write in standard waveform, continuous operation mode */
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, waveform) );
			
			switch(waveform)
			{
				case TKAFG3K_VAL_WFM_SINE:
				case TKAFG3K_VAL_WFM_DC:  
				case TKAFG3K_VAL_WFM_PRN:  				
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SINE;
					break;
				}
				case TKAFG3K_VAL_WFM_SQUARE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SQUARE;				
					break;
				}
				case TKAFG3K_VAL_WFM_RAMP:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_RAMP;
					break;
				}
				case TKAFG3K_VAL_WFM_PULS:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_PULSE;				
					break;
				}
				case TKAFG3K_VAL_WFM_SINC:
				case TKAFG3K_VAL_WFM_GAUS:
				case TKAFG3K_VAL_WFM_LOR:
				case TKAFG3K_VAL_WFM_ERIS:
				case TKAFG3K_VAL_WFM_EDEC:
				case TKAFG3K_VAL_WFM_HAV:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_DEFAULT;
					break;
				}
			}
			
			/* maximum value */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, maxFreq) );			
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );
			CU_ASSERT ( fabs(readFreq-maxFreq) < 1.0e-5 );
			
			/* normal value */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, 100000) );			
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );
			CU_ASSERT ( fabs(readFreq-100000) < 1.0e-5 );						
			
			/* minimum value */
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, 1.0e-3) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) ); 
			CU_ASSERT ( fabs(readFreq-1.0e-3) < 1.0e-5 );	
			
			/* above maximum value */
			frequency = maxFreq+1;
			CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, frequency ) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );  
			CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );	
			
			/* below minimum value */
			frequency = 0.5e-3;
			CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, frequency ) );
			CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );  
			CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );			
		}
		
		/* back to SINE waveform, change to burst mode */
		waveform = TKAFG3K_VAL_WFM_SINE;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FUNC_WAVEFORM, 0, waveform) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0,
																						TKAFG3K_VAL_OPERATE_BURST) );
		
		maxFreq = AFG310X_VAL_MAX_FREQ_SINE_IN_BURST;

		/* maximum value */  		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, maxFreq) );			
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );
		CU_ASSERT ( fabs(readFreq-maxFreq) < 1.0e-5 );	
		
		/* normal value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, 100000) );			
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );
		CU_ASSERT ( fabs(readFreq-100000) < 1.0e-5 );
		
		/* minimum value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, 1.0e-3) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) ); 
		CU_ASSERT ( fabs(readFreq-1.0e-3) < 1.0e-5 );
		
		/* above maximum value */
		frequency = maxFreq+1;
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, frequency ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );  
		CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );
		
		/* below minimum value */
		frequency = 0.5e-3;
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, frequency ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, &readFreq) );  
		CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );		
	}
}

/* test of func frequency dependency */
void testAttrFuncFrequencyDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;  
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, 0, 
																							TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );

		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_FREQUENCY, 0, 100000) );	
		
 		/* TKAFG3K_ATTR_FUNC_WAVEFORM
 		   && TKAFG3K_ATTR_OPERATION_MODE 
 		   have been tested in TKAFG3K_ATTR_FREQUENCY
 		 */
	}																							
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_START_PHASE 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_FUNC_START_PHASE depend on: 
 *						TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL							 
 *
 * Attribute Flag:
 *   					IVI_VAL_MULTI_CHANNEL 
 *
 * Default Value:
 *						0
 */

/* test of func start phase read and write */
void testAttrFuncStartPhaseReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	startPhase;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
																							
		/* Upper Limit */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, 180) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, &startPhase) );
		CU_ASSERT ( fabs(startPhase-180) < 0.1 );
		
		/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, 0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, &startPhase) );
		CU_ASSERT ( fabs(startPhase-0) < 0.1 );		
		
		/* Lower Limit */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, -180) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, &startPhase) );
		CU_ASSERT ( fabs(startPhase+180) < 0.1 )		
		
		/* Above Upper Limit */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, 181) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, &startPhase) );
		CU_ASSERT ( fabs(startPhase-181) > 1.0e-5 );		
		
		/* Below Lower Limit */
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, -181) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, &startPhase) );
		CU_ASSERT ( fabs(startPhase+181) > 1.0e-5 );		
	}
}

/* test of func start phase dependency */
void testAttrFuncStartPhaseDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64	startPhase;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );
																							
		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_ARB) );	
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_START_PHASE, 0, 0) );
	}																							
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_DUTY_CYCLE_HIGH 
 *	
 *******************************************************/

/* Attribute Flag:
 *   					IVI_VAL_MULTI_CHANNEL 
 *
 * Default Value:
 *						50.0
 */

/* test of func duty cycle high default value */
void testAttrFuncDutyCycleHighDefault()
{
	ViReal64	dutyCycle; 	

	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FUNC_DUTY_CYCLE_HIGH, &dutyCycle) );
	CU_ASSERT ( fabs(dutyCycle-50) < 1.0e-5 );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FUNC_DUTY_CYCLE_HIGH, &dutyCycle) );
	CU_ASSERT ( fabs(dutyCycle-50) < 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY 
 *	
 *******************************************************/

/* Attribute Flag:
 *   					IVI_VAL_MULTI_CHANNEL 
 *
 * Default Value:
 *						50.0
 */

/* test of func ramp symmetry read and write */
void testAttrFuncRampSymmetryReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;	
	ViReal64 rampSymmetry;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		/* Upper Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, 100) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, &rampSymmetry) );
		CU_ASSERT ( fabs(rampSymmetry-100) < 1.0e-5 );
		
		/* Normal Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, 50) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, &rampSymmetry) );
		CU_ASSERT ( fabs(rampSymmetry-50) < 1.0e-5 );
		
		/* Lower Value */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, 0) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, &rampSymmetry) );
		CU_ASSERT ( fabs(rampSymmetry-0) < 1.0e-5 );
		
		/* Above Upper Value */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, 101) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, &rampSymmetry) );
		CU_ASSERT ( fabs(rampSymmetry-101) > 1.0e-5 );		
		
		/* Below Lower Value */
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, -1) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY) );
		CU_ASSERT ( VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY, 0, &rampSymmetry) );
		CU_ASSERT ( fabs(rampSymmetry+1) > 1.0e-5 );		
	}		
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE depends on:
 *					TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 * 
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					TKAFG3K_VAL_WFM_EDIT
 */

/* test of arb waveform handle flag */
void testAttrArbWaveformHandleFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViInt32 waveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}		
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, 
																							TKAFG3K_VAL_WFM_EDIT) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, &waveform) );
		CU_ASSERT ( TKAFG3K_VAL_WFM_USER1 != waveform );
	}
}

/* test of arb waveform handle read and write */
void testAttrArbWaveformHandleReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j; 
	ViInt32 waveform, readWaveform;
	ViBoolean exists = VI_FALSE;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
																							
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_TRUE)
			{
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, &readWaveform) );
				CU_ASSERT ( waveform == readWaveform );
			}			
		}
	}
}

/* test of arb waveform handle dependency */
void testAttrArbWaveformHandleDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j; 
	ViInt32 waveform, readWaveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
																							
		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE, 
																							TKAFG3K_VAL_WFM_EDIT) );																						
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ARB_GAIN 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_ARB_GAIN depends on:
 *					TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 *					TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 *					TKAFG3K_ATTR_ARB_OFFSET					
 * 
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					0.5
 */ 

/* test of arb gain flag */
void testAttrArbGainFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 gain;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, 0) );		
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, 0.5) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AMPLITUDE, 0, 2.0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, &gain) );
		CU_ASSERT ( fabs(gain-0.5) > 1.0e-5 ); 
	}
}

/* test of arb gain read and write */
void testAttrArbGainReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 gain, readGain;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, 0) );			
		
		/* Upper Limit */
		gain = AFG310X_VAL_MAX_AMPL_IN_50OHM/2.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, gain) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, &readGain) );
		CU_ASSERT ( fabs(readGain-gain) < 1.0e-5 );
		
		/* Normal Value */
		gain = 0.5;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, gain) ); 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, &readGain) );
		CU_ASSERT ( fabs(readGain-gain) < 1.0e-5 ); 		
		
		/* Lower Limit */
		gain = AFG310X_VAL_MIN_AMPL_IN_50OHM/2.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, gain ) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, &readGain) );
		CU_ASSERT ( fabs(readGain-gain) < 1.0e-5 );
		
		/* Above Upper Limit */
		gain = AFG310X_VAL_MAX_AMPL_IN_50OHM/2.0+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, gain ) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, &readGain) );
		CU_ASSERT ( fabs(readGain-gain) > 1.0e-5 ); 
		
		/* Below Lower Limit */
		gain = AFG310X_VAL_MIN_AMPL_IN_50OHM/2.0-1.0e-3;		
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, gain ) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, &readGain) );
		CU_ASSERT ( fabs(readGain-gain) > 1.0e-5 );  																					 
	}
}

/* test of arb gain dependency */
void testAttrArbGainDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 gain, readGain;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		/* back to default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_ARB) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, 0) );	
		
		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, 
																							TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, 0, 2.0) );
		
		/* TKAFG3K_ATTR_OUTPUT_IMPEDANCE 
		   && TKAFG3K_ATTR_ARB_OFFSET 
		   have been tested in attribtue TKAFG3K_ATTR_AMPLITUDE
		 */		
		
	}		
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ARB_OFFSET 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_ARB_OFFSET depends on:
 *					TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 *					TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 *					TKAFG3K_ATTR_ARB_GAIN					
 * 
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					0
 */

/* test of arb offset flag */
void testAttrArbOffsetFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 offset;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, 0.5) );			
		
		/* IVI_VAL_NEVER_CACHE */																			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, 5) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OFFSET, 0, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, &offset) );
		CU_ASSERT ( fabs(offset-5) > 1.0e-5 ); 
	}
}

/* test of arb offset read and write */
void testAttrArbOffsetReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 offset, readOffset;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_OUTPUT_IMPEDANCE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_GAIN, 0.5) );	
		
		/* Upper Limit */
		offset = 5;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, offset) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, &readOffset) );
		CU_ASSERT ( fabs (readOffset-offset) < 1.0e-5 );
		
		/* Normal Value */
		offset = 0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, offset) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, &readOffset) );
		CU_ASSERT ( fabs (readOffset-offset) < 1.0e-5 );
		
		/* Lower Limit */
		offset = -5;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, offset) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, &readOffset) );
		CU_ASSERT ( fabs (readOffset-offset) < 1.0e-5 );	
		
		/* Above Upper Limit */
		offset = 6;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, offset) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, &readOffset) );
		CU_ASSERT ( fabs (readOffset-offset) > 1.0e-5 );
		
		/* Below Lower Limit */
		offset = -6;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, offset) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, &readOffset) );
		CU_ASSERT ( fabs (readOffset-offset) > 1.0e-5 );		
	}		
}

/* test of arb offset dependency */
void testAttrArbOffsetDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 offset;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_ARB) );		
		
		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																							TKAFG3K_VAL_OUTPUT_FUNC) );		
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_OFFSET, 0) );	
		
 		/* TKAFG3K_ATTR_OUTPUT_IMPEDANCE
 		   && TKAFG3K_ATTR_ARB_GAIN		
 		   have been tested in TKAFG3K_ATTR_OFFSET 
 		 */
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ARB_SAMPLE_RATE 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_ARB_SAMPLE_RATE depends on:
 * 							TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL								
 *							TKAFG3K_ATTR_ARB_FREQUENCY
 *							TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE
 *  
 * Attribute Flag:
 *				  			IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *							1000000000.0
 */

/* test of arb sample rate flag */
void testAttrArbSampleRateFlag()
{
	ViReal64 sampleRate;
		
	/* back to default setting */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE,
																							TKAFG3K_VAL_OUTPUT_ARB) );
																							
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER1) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER1) );		
																							
	/* IVI_VAL_NEVER_CACHE */	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, 100) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_ARB_FREQUENCY, 10) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_ARB_FREQUENCY, 10) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &sampleRate) );
	CU_ASSERT ( 100 != sampleRate );	
	
	/* Non - Multiple channel */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, 100) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_ARB_FREQUENCY, 10) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &sampleRate) ); 	
}

/* test of arb sample rate read and write */
void testAttrArbSampleRateReadAndWrite()
{
	ViReal64 sampleRate, readSampleRate;	
	
	/* back to default setting */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE,
																							TKAFG3K_VAL_OUTPUT_ARB) );
																							
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER1) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER1) );	

	/* point size of 100 */
	/* Maximum value */
	sampleRate = 5000000000.00;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, sampleRate) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &readSampleRate) );
	CU_ASSERT ( fabs(readSampleRate-sampleRate) < 1.0e-5 );
	
	/* Normal Value */
	sampleRate = 100;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, sampleRate) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &readSampleRate) );
	CU_ASSERT ( fabs(readSampleRate-sampleRate) < 1.0e-5 );
	
	/* Minimum value */
	sampleRate = 0.1;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, sampleRate) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &readSampleRate) );
	CU_ASSERT ( fabs(readSampleRate-sampleRate) < 1.0e-5 );	
	
	/* Above Maximum Value */
	sampleRate = 5100000000.00;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, sampleRate) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &readSampleRate) );
	CU_ASSERT ( fabs(readSampleRate-sampleRate) > 1.0e-5 );	
	
	/* Below Minimum value */
	sampleRate = 0.05;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, sampleRate) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &readSampleRate) );
	CU_ASSERT ( fabs(readSampleRate-sampleRate) > 1.0e-5 );		
}

/* test of arb sample rate dependency */
void testAttrArbSampleRateDependency()
{
	ViReal64 sampleRate;
	
	/* back to default setting */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE,
																							TKAFG3K_VAL_OUTPUT_ARB) );
																							
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER1) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER1) );	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, 1000000000.0) );																								
	
	/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE,
																							TKAFG3K_VAL_OUTPUT_FUNC) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &sampleRate) );

	/* TKAFG3K_ATTR_ARB_FREQUENCY */
	/* back to arb output mode */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE,
																							TKAFG3K_VAL_OUTPUT_ARB) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_ARB_FREQUENCY,
																							100) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &sampleRate) ); 
	
	/* TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, 1000000000.0) );
	/* Number of point is 200 in USER2 */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																							TKAFG3K_VAL_WFM_USER2) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, &sampleRate) );   																							
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_MAX_NUM_WAVEFORMS 
 *	
 *******************************************************/

/* Flag:
 *					IVI_VAL_NOT_USER_WRITABLE
 *
 * Default Value:
 *					TKAFG3K_VAL_MAX_WAVEFORMS
 */

/* test of max num waveforms flag and default value*/
void testAttrMaxNumWaveformsFlagAndDefault()
{
	ViInt32 maxNumWaveforms;
	
	/* IVI_VAL_NOT_USER_WRITABLE */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_MAX_NUM_WAVEFORMS, 2) );  

	/* Default Value */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_MAX_NUM_WAVEFORMS, &maxNumWaveforms) );
	CU_ASSERT ( TKAFG3K_VAL_MAX_WAVEFORMS == maxNumWaveforms );
	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_WAVEFORM_QUANTUM 
 *	
 *******************************************************/

/* Flag:
 *					IVI_VAL_NOT_USER_WRITABLE
 *
 * Default Value:
 *					TKAFG3K_VAL_WFM_QUANTUM
 */
 
/* test of waveform quantum flag and default value */
void testAttrWaveformQuantumFlagAndDefault()  
{
	ViInt32 quantum;
	
	/* IVI_VAL_NOT_USER_WRITABLE */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_WAVEFORM_QUANTUM, 2) );	

	/* Default Value */  
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_WAVEFORM_QUANTUM, &quantum) ); 
	CU_ASSERT ( TKAFG3K_VAL_WFM_QUANTUM == quantum );
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_MIN_WAVEFORM_SIZE 
 *	
 *******************************************************/
 
/* Flag:
 *					IVI_VAL_NOT_USER_WRITABLE
 *
 * Default Value:
 *					TKAFG3K_VAL_MIN_WFM_SIZE
 */

/* test of min waveform size flag and default value */ 
void testAttrMinWaveformSizeFlagAndDefault()
{
	ViInt32		minWfmSize;
	
	/* IVI_VAL_NOT_USER_WRITABLE */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_MIN_WAVEFORM_SIZE, 2) );	

	/* Default Value */  	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_MIN_WAVEFORM_SIZE, &minWfmSize) );
	CU_ASSERT ( TKAFG3K_VAL_MIN_WFM_SIZE == minWfmSize );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_MAX_WAVEFORM_SIZE 
 *	
 *******************************************************/
 
/*
 * Attribute Flag:
 *					IVI_VAL_NOT_USER_WRITABLE
 *					IVI_VAL_USE_CALLBACKS_FOR_SIMULATION
 *
 * Default Value:
 *					16384
 */ 

/* test of max waveform size flag */
void testAttrMaxWaveformSizeFlagAndRead()
{
	ViInt32		maxWfmSize;
	
	/* IVI_VAL_NOT_USER_WRITABLE */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_MAX_WAVEFORM_SIZE, 2) );
	
	/* Read Value */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_MAX_WAVEFORM_SIZE, &maxWfmSize) );
	CU_ASSERT ( AFG3102_VAL_MAX_WFM_SIZE == maxWfmSize );
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_ARB_FREQUENCY 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_ARB_FREQUENCY depends on: 
 *					TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL
 *					TKAFG3K_ATTR_ARB_SAMPLE_RATE
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					1000000.00
 */

/* test of arb frequency flag */
void testAttrArbFrequencyFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 frequency;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																								TKAFG3K_VAL_OUTPUT_ARB) );
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, 1000 ) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 100) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &frequency) );
		CU_ASSERT ( fabs(frequency-1000) > 1.0e-5 );
	}
}

/* test of arb frequency read and write */
void testAttrArbFrequencyReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 frequency, readFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																								TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																								TKAFG3K_VAL_WFM_USER1) );
		
		/* Maximum Value */
		frequency = AFG310X_VAL_MAX_FREQ_ARB;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );
		
		/* Normal Value */
		frequency = 1000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );		
		
		/* Minimum Value */
		frequency = TKAFG3K_VAL_MIN_FREQ;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );
		
		/* Above Maximum Value */
		frequency = AFG310X_VAL_MAX_FREQ_ARB+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );		
		
		/* Below Minimum Value */
		frequency = TKAFG3K_VAL_MIN_FREQ/2.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );		
	}
}

/* test of arb frequency dependency */
void testAttrArbFrequencyDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 frequency;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																								TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE,
																								TKAFG3K_VAL_WFM_USER1) );
	}
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																								TKAFG3K_VAL_OUTPUT_FUNC) );	
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, 1000) );
		
		/* TKAFG3K_ATTR_ARB_SAMPLE_RATE */
		/* back to arbitrary mode */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL,
																								TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_ARB_SAMPLE_RATE, 1000) );		 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_ARB_FREQUENCY, &frequency) );
		CU_ASSERT ( fabs (frequency-10) < 1.0e-5 );
	}
}
					
/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_TRIGGER_SOURCE 
 *	
 *******************************************************/
 
/*
 * Default Value:
 *					TKAFG3K_VAL_INTERNAL_TRIGGER
 */ 

static ViInt32 testTriggerSourceArray[] = 
{
			TKAFG3K_VAL_INTERNAL_TRIGGER,	
			TKAFG3K_VAL_EXTERNAL
};

/* test of trigger source read and write */
void testAttrTriggerSourceReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j; 
	ViInt32 triggerSource, readTriggerSource;
		
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		/* value in range table */
		for(j=0; j<2; j++)
		{
			triggerSource = testTriggerSourceArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_TRIGGER_SOURCE, triggerSource) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_TRIGGER_SOURCE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_TRIGGER_SOURCE, &readTriggerSource) );
			CU_ASSERT ( triggerSource == readTriggerSource );
		}
		
		/* value out of range table */
		triggerSource = TKAFG3K_VAL_EXTERNAL + 100; 
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_TRIGGER_SOURCE, triggerSource) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_TRIGGER_SOURCE, &readTriggerSource) );
		CU_ASSERT ( triggerSource != readTriggerSource );	
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_TRIGGER_MODE 
 *	
 *******************************************************/

/* 
 *	Default Value:
 *				  	TKAFG3K_VAL_TRIGGER_TRIGGER
 */
 
/* test of trigger mode read and write */
static testTriggerMode[2] = {
				TKAFG3K_VAL_TRIGGER_TRIGGER,					
				TKAFG3K_VAL_TRIGGER_SYNC,
};

void testAttrTriggerModeReadAndWrite()
{
	ViInt32 j;    
	ViInt32 triggerMode, readTriggerMode;
	
	/* value in range table */   
	for(j=0; j<2; j++)  
	{
		triggerMode = testTriggerMode[j];
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_MODE, triggerMode) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_MODE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_MODE, &readTriggerMode) );
		CU_ASSERT ( triggerMode == readTriggerMode );
	}
	
	/* value out of range table */ 	
	triggerMode = TKAFG3K_VAL_TRIGGER_SYNC + 100;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_MODE, triggerMode) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_MODE, &readTriggerMode) );
	CU_ASSERT ( triggerMode != readTriggerMode );
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_TRIGGER_SLOPE 
 *	
 *******************************************************/

/*   
 *  Default Value:
 *					TKAFG3K_VAL_TRIGGER_POSITIVE
 */

/* test of trigger slope read and write */
static ViInt32 testTriggerSlope[2] = {

					TKAFG3K_VAL_TRIGGER_POSITIVE,
					TKAFG3K_VAL_TRIGGER_NEGATIVE					
};

void testAttrTriggerSlopeReadAndWrite()
{
	ViInt32 j; 	
	ViInt32 triggerSlope, readTriggerSlope;

	/* value in range table */   
	for(j=0; j<2; j++) 
	{
		triggerSlope = testTriggerSlope[j];
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_SLOPE, triggerSlope) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_SLOPE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_SLOPE, &readTriggerSlope) );
		CU_ASSERT ( triggerSlope == readTriggerSlope );	
	}
	
	/* value out of range table */ 
	triggerSlope = TKAFG3K_VAL_TRIGGER_NEGATIVE + 100;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_SLOPE, triggerSlope) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_TRIGGER_SLOPE, &readTriggerSlope) );
	CU_ASSERT ( triggerSlope != readTriggerSlope );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE 
 *	
 *******************************************************/

/*
 *  Default Value:
 *						1000.0
 */
 
/* test of internal trigger rate read and write */
void testAttrInternalTriggerRateReadAndWrite()
{
	ViReal64 triggerRate, readTriggerRate;

	/* Upper Limit */
	triggerRate = 1000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, triggerRate) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, &readTriggerRate) );
	CU_ASSERT ( fabs (readTriggerRate - triggerRate) < 1.0e-5 );
	
	/* Normal Value */
	triggerRate = 1.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, triggerRate) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, &readTriggerRate) );
	CU_ASSERT ( fabs (readTriggerRate - triggerRate) < 1.0e-5 );
	
	/* Lower Limit */
	triggerRate = 0.002;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, triggerRate) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, &readTriggerRate) );
	CU_ASSERT ( fabs (readTriggerRate - triggerRate) < 1.0e-5 );
	
	/* Above Upper Limit */
	triggerRate = 1001.0;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, triggerRate) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, &readTriggerRate) );
	CU_ASSERT ( fabs (readTriggerRate - triggerRate) > 1.0e-5 );	
	
	/* Below Lower Limit */
	triggerRate = 0.001;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, triggerRate) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE, &readTriggerRate) );
	CU_ASSERT ( fabs (readTriggerRate - triggerRate) > 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_BURST_COUNT 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  Default Value:
 *						5
 */

/* test of burst count read and write */
void testAttrBurstCountReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViInt32 burstCount, readBurstCount;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Upper Limit */
		burstCount = 1000000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, burstCount) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_BURST_COUNT) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, &readBurstCount) );
		CU_ASSERT ( readBurstCount == burstCount );
		
		/* Normal Value */
		burstCount = 1000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, burstCount) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_BURST_COUNT) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, &readBurstCount) );
		CU_ASSERT ( readBurstCount == burstCount );
		
		/* Lower Limit */
		burstCount = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, burstCount) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_BURST_COUNT) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, &readBurstCount) );
		CU_ASSERT ( readBurstCount == burstCount );		
		
		/* INFINITE */
		burstCount = TKAFG3K_VAL_BURST_INFINITY;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, burstCount) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_BURST_COUNT) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, &readBurstCount) );
		CU_ASSERT ( readBurstCount == burstCount );	
		
		/* Above Upper Limit */
		burstCount = 1000001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, burstCount) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, &readBurstCount) );
		CU_ASSERT ( readBurstCount != burstCount );		
		
		/* Below Lower Limit */
		burstCount = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, burstCount) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_COUNT, &readBurstCount) );
		CU_ASSERT ( readBurstCount != burstCount );			
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_BURST_MODE 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  Default Value:
 *						TKAFG3K_VAL_BURST_TRIGGER
 */ 
 
/* test of burst mode read and write */
static ViInt32 testBurstMode[2] = {
						
						TKAFG3K_VAL_BURST_TRIGGER,
						TKAFG3K_VAL_BURST_GATE
};

void testAttrBurstModeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j; 
	ViInt32 burstMode, readBurstMode;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		for(j=0; j<2; j++)
		{
			burstMode = testBurstMode[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_MODE, burstMode) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_BURST_MODE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_MODE, &readBurstMode) );
			CU_ASSERT ( burstMode == readBurstMode );
		}
		
		burstMode = TKAFG3K_VAL_BURST_GATE + 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_MODE, burstMode) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_BURST_MODE, &readBurstMode) );
		CU_ASSERT ( burstMode != readBurstMode );  
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_TYPE 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  Default Value:
 *						TKAFG3K_VAL_SWEEP_LINEAR
 */ 

/* test of sweep type read and write */
static ViInt32 testSweepType[2] = {
						TKAFG3K_VAL_SWEEP_LINEAR,
						TKAFG3K_VAL_SWEEP_LOGARITHMIC
};

void testAttrSweepTypeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j; 
	ViInt32 sweepType, readSweepType;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		for(j=0; j<2; j++)
		{
			sweepType = testSweepType[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_TYPE, sweepType) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TYPE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_TYPE, &readSweepType) );
			CU_ASSERT ( sweepType == readSweepType );
		}
		
		sweepType = TKAFG3K_VAL_SWEEP_LOGARITHMIC + 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_TYPE, sweepType) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TYPE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_TYPE, &readSweepType) );
		CU_ASSERT ( sweepType != readSweepType );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_MODE
 *
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  Default Value:
 *						TKAFG3K_VAL_SWEEP_AUTO
 */ 

/* test of burst mode read and write */
static ViInt32 testSweepMode[2] = {
						
						TKAFG3K_VAL_SWEEP_AUTO,
						TKAFG3K_VAL_SWEEP_MANUAL
};

void testAttrSweepModeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j; 
	ViInt32 sweepMode, readSweepMode;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		for(j=0; j<2; j++)
		{
			sweepMode = testSweepMode[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_MODE, sweepMode) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_MODE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_MODE, &readSweepMode) );
			CU_ASSERT ( sweepMode == readSweepMode );
		}			
		
		sweepMode = TKAFG3K_VAL_SWEEP_AUTO + 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_MODE, sweepMode) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_SWEEP_MODE, &readSweepMode) );
		CU_ASSERT ( sweepMode != readSweepMode );  		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_TIME 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  TKAFG3K_ATTR_SWEEP_TIME depends on (Invalidation):
 *						TKAFG3K_ATTR_SWEEP_HOLD_TIME
 *						TKAFG3K_ATTR_SWEEP_RETURN_TIME
 *	
 *  TKAFG3K_ATTR_SWEEP_TIME Invalidate:
 *						TKAFG3K_ATTR_SWEEP_HOLD_TIME
 *						TKAFG3K_ATTR_SWEEP_RETURN_TIME
 *
 *  Default Value:
 *						0.01
 */ 

/* test of sweep time read and write */
void testAttrSweepTimeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 sweepTime, readSweepTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Upper Limit */ 
		sweepTime = 100;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime - sweepTime) < 1.0e-5 );
		
		/* Normal Value */
		sweepTime = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime - sweepTime) < 1.0e-5 );
		
		/* Lower Limit */
		sweepTime = 0.01;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime - sweepTime) < 1.0e-5 );		
		
		/* Above Upper Limit */
		sweepTime = 101;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime - sweepTime) > 1.0e-5 );	
		
		/* Below Lower Limit */
		sweepTime = 0.005;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime - sweepTime) > 1.0e-5 );		
	}
}

/* test of sweep time dependency */
void testAttrSweepTimeDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 sweepTime, readSweepTime, holdTime, returnTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* Pre-set sweep time to maximum value */
		sweepTime = 100;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		
		/* TKAFG3K_ATTR_SWEEP_HOLD_TIME */
		/* set hold time to 10 s */
		holdTime = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime-sweepTime) > 1.0e-5 );
		
		/* back to maximum value */
		sweepTime = 100;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );		
		
		/* TKAFG3K_ATTR_SWEEP_RETURN_TIME */
		/* set return time to 10 s */
		returnTime = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime-sweepTime) > 1.0e-5 );
	}
}

/* test of sweep time invalidation */
void testAttrSweepTimeInvalidation()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 sweepTime, holdTime, readHoldTime, returnTime, readReturnTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* pre-set time */
		sweepTime = 40;
		holdTime = 30;
		returnTime = 30;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		
		/* change sweep time to maximum value */
		sweepTime = 100;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );  		
		
		/* TKAFG3K_ATTR_SWEEP_HOLD_TIME */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) );
		CU_ASSERT ( fabs (readHoldTime-holdTime) > 1.0e-5 );
		
		/* TKAFG3K_ATTR_SWEEP_RETURN_TIME */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_HOLD_TIME 
 *	
 *******************************************************/
 
/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  TKAFG3K_ATTR_SWEEP_TIME depends on (Invalidation):
 *						TKAFG3K_ATTR_SWEEP_TIME
 *						TKAFG3K_ATTR_SWEEP_RETURN_TIME
 *	
 *  TKAFG3K_ATTR_SWEEP_TIME Invalidate:
 *						TKAFG3K_ATTR_SWEEP_TIME
 *						TKAFG3K_ATTR_SWEEP_RETURN_TIME
 *
 *  Default Value:
 *						0
 */ 

/* test of sweep hold time read and write */
void testAttrSweepHoldTimeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 holdTime, readHoldTime;
	ViReal64 sweepTime, returnTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Upper Limit */
		holdTime = 99.99;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) ); 
		CU_ASSERT ( fabs (readHoldTime-holdTime) < 1.0e-5 );
		
		/* Normal Value */
		holdTime = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) ); 
		CU_ASSERT ( fabs (readHoldTime-holdTime) < 1.0e-5 );
		
		/* Lower Limit */
		holdTime = 0; 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) ); 
		CU_ASSERT ( fabs (readHoldTime-holdTime) < 1.0e-5 );
		
		/* Above Upper Limit */
		holdTime = 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) ); 
		CU_ASSERT ( fabs (readHoldTime-holdTime) > 1.0e-5 );
		
		/* Below Lower Limit */
		holdTime = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) ); 
		CU_ASSERT ( fabs (readHoldTime-holdTime) > 1.0e-5 );		
	}
}

/* test of sweep hold time dependency */
void testAttrSweepHoldTimeDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 holdTime, readHoldTime;
	ViReal64 sweepTime, returnTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Pre-set sweep hold time to maximum value */
		holdTime = 99.99;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		
		/* TKAFG3K_ATTR_SWEEP_TIME */
		/* set sweep time to 10 s */
		sweepTime = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) );
		CU_ASSERT ( fabs (readHoldTime-holdTime) > 1.0e-5 );
		
		/* sweep hold time back to maximum value */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) );  
		
		/* TKAFG3K_ATTR_SWEEP_RETURN_TIME */
		returnTime = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) );		
		CU_ASSERT ( fabs (readHoldTime-holdTime) > 1.0e-5 );  		
	}
}

/* test of sweep hold time invalidation */
void testAttrSweepHoldTimeInvalidation()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 holdTime;
	ViReal64 sweepTime, readSweepTime, returnTime, readReturnTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* default setting */
		holdTime = 40;
		sweepTime = 30;
		returnTime = 30;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		
		/* change sweep hold time to maximum */
		holdTime = 99.99;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		
		/* TKAFG3K_ATTR_SWEEP_TIME */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime-sweepTime) > 1.0e-5 );
		
		/* TKAFG3K_ATTR_SWEEP_RETURN_TIME */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_RETURN_TIME 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  TKAFG3K_ATTR_SWEEP_TIME depends on (Invalidation):
 *						TKAFG3K_ATTR_SWEEP_TIME
 *						TKAFG3K_ATTR_SWEEP_HOLD_TIME
 *	
 *  TKAFG3K_ATTR_SWEEP_TIME Invalidate:
 *						TKAFG3K_ATTR_SWEEP_TIME
 *						TKAFG3K_ATTR_SWEEP_HOLD_TIME
 *
 *  Default Value:
 *						0.001
 */

/* test of sweep return time read and write */
void testAttrSweepReturnTimeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 returnTime, readReturnTime; 
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* Upper Limit */
		returnTime = 99.99;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) < 1.0e-5 );
		
		/* Normal Value */
		returnTime = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) < 1.0e-5 );
		
		/* Lower Limit */
		returnTime = 0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) < 1.0e-5 );		

		/* Above Upper Limit */
		returnTime = 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );	
		
		/* Below Lower Limit */
		returnTime = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );		
	}
}

/* test of sweep return time dependency */
void testAttrSweepReturnTimeDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 returnTime, readReturnTime; 
	ViReal64 sweepTime, holdTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Pre-set return time to maximum value */
		returnTime = 99.99;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) ); 
		
		/* TKAFG3K_ATTR_SWEEP_TIME */
		/* set sweep time to 10 s */
		sweepTime = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );
	
		/* back to maximum value */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );	
		
		/* TKAFG3K_ATTR_SWEEP_HOLD_TIME */
		/* set hold time to 10 s */
		holdTime = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, &readReturnTime) );
		CU_ASSERT ( fabs (readReturnTime-returnTime) > 1.0e-5 );		
	}
}

/* test of sweep return time invalidation */
void testAttrSweepReturnTimeInvalidation()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i; 
	ViReal64 returnTime; 
	ViReal64 sweepTime, readSweepTime, holdTime, readHoldTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* default setting */
		returnTime = 40;
		sweepTime = 30;
		holdTime = 30;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, sweepTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, holdTime) ); 
		
		/* change sweep return time to maximum value */
		returnTime = 99.99;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_RETURN_TIME, returnTime) );	
		
		/* TKAFG3K_ATTR_SWEEP_TIME */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_TIME, &readSweepTime) );
		CU_ASSERT ( fabs (readSweepTime-sweepTime) > 1.0e-5 );
		
		/* TKAFG3K_ATTR_SWEEP_HOLD_TIME */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_HOLD_TIME, &readHoldTime) ); 		
		CU_ASSERT ( fabs (readHoldTime-holdTime) > 1.0e-5 );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_START_FREQUENCY 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  TKAFG3K_ATTR_SWEEP_START_FREQUENCY depends on (Invalidation):
 *						TKAFG3K_ATTR_WAVEFORM
 *
 *  Default Value:
 *						100000
 */

/* test of sweep start frequency read and write */
void testAttrSweepStartFrequencyReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViReal64 startFreq, readStartFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* test of start frequency read and write in standard waveform */
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			ViReal64 maxFreq;
			ViBoolean allowance;
			
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_SWEEP, &allowance) );
			if(!allowance)
			{
				continue;
			}
			
			switch(waveform)
			{
				case TKAFG3K_VAL_WFM_SINE:
				case TKAFG3K_VAL_WFM_DC:  
				case TKAFG3K_VAL_WFM_PRN:  				
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SINE;
					break;
				}
				case TKAFG3K_VAL_WFM_SQUARE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SQUARE;				
					break;
				}
				case TKAFG3K_VAL_WFM_RAMP:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_RAMP;
					break;
				}
				case TKAFG3K_VAL_WFM_PULS:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_PULSE;				
					break;
				}
				case TKAFG3K_VAL_WFM_SINC:
				case TKAFG3K_VAL_WFM_GAUS:
				case TKAFG3K_VAL_WFM_LOR:
				case TKAFG3K_VAL_WFM_ERIS:
				case TKAFG3K_VAL_WFM_EDEC:
				case TKAFG3K_VAL_WFM_HAV:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_DEFAULT;
					break;
				}
			}
			
			/* Upper Limit */
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, maxFreq) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-maxFreq) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-maxFreq) < 1.0e-5 );
			
			/* Normal Value */
			startFreq = 1000;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );
			
			/* Lower Limit */
			startFreq = 1;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );
			
			/* Above Upper Limit */
			startFreq = AFG310X_VAL_MAX_FREQ_SINE+1;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-startFreq) > 1.0e-5 );	
			
			/* Below Lower Limit */
			startFreq = 0.5;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
			CU_ASSERT ( fabs (readStartFreq-startFreq) > 1.0e-5 );			
		}
		
		/* test of start frequency read and write in arbitrary waveform */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_EDIT) );
		
		/* Upper Limit */ 
		startFreq = AFG310X_VAL_MAX_FREQ_ARB;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );
		
		/* Normal Value */
		startFreq = 1000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
		
		/* Lower Limit */
		startFreq = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) < 1.0e-5 );	
		
		/* Above Upper Limit */
		startFreq = AFG310X_VAL_MAX_FREQ_ARB+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) > 1.0e-5 );	
			
		/* Below Lower Limit */
		startFreq = 0.5;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, startFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStartFreq) );
		CU_ASSERT ( fabs (readStartFreq-startFreq) > 1.0e-5 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY 
 *	
 *******************************************************/

/*
 *  Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 *  TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY depends on (Invalidation):
 *						TKAFG3K_ATTR_WAVEFORM
 *
 *  Default Value:
 *						1000000
 */

void testAttrSweepStopFrequencyReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViReal64 stopFreq, readStopFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* test of start frequency read and write in standard waveform */
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			ViReal64 maxFreq;
			ViBoolean allowance;
			
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_RunModeAllowable (vi, waveform, TKAFG3K_VAL_OPERATE_SWEEP, &allowance) );
			if(!allowance)
			{
				continue;
			}
			
			switch(waveform)
			{
				case TKAFG3K_VAL_WFM_SINE:
				case TKAFG3K_VAL_WFM_DC:  
				case TKAFG3K_VAL_WFM_PRN:  				
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SINE;
					break;
				}
				case TKAFG3K_VAL_WFM_SQUARE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SQUARE;				
					break;
				}
				case TKAFG3K_VAL_WFM_RAMP:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_RAMP;
					break;
				}
				case TKAFG3K_VAL_WFM_PULS:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_PULSE;				
					break;
				}
				case TKAFG3K_VAL_WFM_SINC:
				case TKAFG3K_VAL_WFM_GAUS:
				case TKAFG3K_VAL_WFM_LOR:
				case TKAFG3K_VAL_WFM_ERIS:
				case TKAFG3K_VAL_WFM_EDEC:
				case TKAFG3K_VAL_WFM_HAV:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_DEFAULT;
					break;
				}
			}
			
			/* Upper Limit */
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY, maxFreq) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-maxFreq) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-maxFreq) < 1.0e-5 );
			
			/* Normal Value */
			stopFreq = 1000;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
			
			/* Lower Limit */
			stopFreq = 1;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
			
			/* Above Upper Limit */
			stopFreq = maxFreq+1;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-stopFreq) > 1.0e-5 );
			
			/* Below Lower Limit */
			stopFreq = 0.5;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
			CU_ASSERT ( fabs (readStopFreq-stopFreq) > 1.0e-5 );
		}
		
		/* test of start frequency read and write in arbitrary waveform */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_EDIT) );
		
		/* Upper Limit */ 
		stopFreq = AFG310X_VAL_MAX_FREQ_ARB;		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );
		
		/* Normal Value */
		stopFreq = 1000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );
			
		/* Lower Limit */
		stopFreq = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) < 1.0e-5 );	
		
		/* Above Upper Limit */
		stopFreq = AFG310X_VAL_MAX_FREQ_ARB+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) > 1.0e-5 );
		
		/* Below Lower Limit */
		stopFreq = 0.5;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, stopFreq) ); 			
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_SWEEP_START_FREQUENCY, &readStopFreq) );
		CU_ASSERT ( fabs (readStopFreq-stopFreq) > 1.0e-5 );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_APPEND_NOISE_ENABLED 
 *	
 *******************************************************/

/* Associated Attribute:
 *						TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED
 *
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						VI_FALSE
 */ 

 /* test of append noise enabled read and write */
 void testAttrAppendNoiseEnabledReadAndWrite()
 {
 	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	
	ViInt32 operationMode = TKAFG3K_VAL_OPERATE_CONTINUOUS;
	
	/* Noise is permitted only in Continuous, Sweep and Burst Mode */ 
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		enabled = VI_FALSE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );

		/* Continuous Mode */ 
		enabled = VI_TRUE;
		operationMode = TKAFG3K_VAL_OPERATE_CONTINUOUS;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, operationMode) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );		
		
		enabled = VI_FALSE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );
		
		/* Modulation Mode */ 
		enabled = VI_TRUE;
		operationMode = TKAFG3K_VAL_OPERATE_MODULATION;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, operationMode) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );		
		
		enabled = VI_FALSE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );
		
		/* Sweep Mode */ 
		enabled = VI_TRUE;
		operationMode = TKAFG3K_VAL_OPERATE_SWEEP;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, operationMode) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );		
		
		enabled = VI_FALSE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );
		
		/* Burst Mode */
		enabled = VI_TRUE;
		operationMode = TKAFG3K_VAL_OPERATE_BURST;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, operationMode) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );		
		
		enabled = VI_FALSE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
		CU_ASSERT ( readEnabled == enabled );		
	} 
 }

/* test of append noise enabled association */
void testAttrAppendNoiseEnabledAssociation()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	

	/* Channel 1 */		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );		
		
	/* Set Append External to VI_TRUE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, VI_TRUE) );
		
	enabled = VI_TRUE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );
		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );
		
	/* Set Append External to VI_FALSE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, VI_FALSE) );  
		
	enabled = VI_TRUE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );
		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );		
		
	/* Channel 2 */			
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );		
		
	/* Set Append External to VI_TRUE */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, VI_TRUE) );
		
	enabled = VI_TRUE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );
		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );
		
	/* Set Append External to VI_FALSE */
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, VI_FALSE) );  
		
	enabled = VI_TRUE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );
		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, &readEnabled) );
	CU_ASSERT ( enabled == readEnabled );				
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_APPEND_NOISE_LEVEL 
 *	
 *******************************************************/
 
/* Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						10
 */
 
/* test of append noise level read and write */
static ViInt32 appendNoiseRunModeArray[] = {
					TKAFG3K_VAL_OPERATE_CONTINUOUS,
					TKAFG3K_VAL_OPERATE_SWEEP,
					TKAFG3K_VAL_OPERATE_BURST
};

#define TEST_APPENDNOISE_RUNMODE_QUANTUM		3
void testAttrAppendNoiseLevelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViReal64 level, readLevel;	
	ViInt32 operationMode = TKAFG3K_VAL_OPERATE_CONTINUOUS; 
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		for(j=0; j<TEST_APPENDNOISE_RUNMODE_QUANTUM; j++)
		{
			/* Continuous Mode */
			operationMode = appendNoiseRunModeArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, operationMode) ); 
		
			/* Upper Limit */
			level = 50.0;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, level) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, &readLevel) );
			CU_ASSERT ( fabs (readLevel-level) < 1.0e-5 );
		
			/* Normal Value */
			level = 10.0;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, level) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, &readLevel) );
			CU_ASSERT ( fabs (readLevel-level) < 1.0e-5 );
		
			/* Lower Limit */
			level = 0;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, level) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, &readLevel) );
			CU_ASSERT ( fabs (readLevel-level) < 1.0e-5 );		

			/* Above Upper Limit */
			level = 51.0;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, level) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, &readLevel) );
			CU_ASSERT ( fabs (readLevel-level) > 1.0e-5 );		
		
			/* Below Lower Limit */
			level = -1;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, level) );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, &readLevel) );
			CU_ASSERT ( fabs (readLevel-level) > 1.0e-5 );			
		}
		
		operationMode = TKAFG3K_VAL_OPERATE_MODULATION;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_OPERATION_MODE, operationMode) );        
		
		/* Normal Value */
		level = 10.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, level) );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_APPEND_NOISE_LEVEL, &readLevel) );
		CU_ASSERT ( fabs (readLevel-level) > 1.0e-5 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED 
 *	
 *******************************************************/

/* Associated Attribute:
 *						TKAFG3K_ATTR_APPEND_NOISE_ENABLED
 *
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						VI_FALSE
 */

/* test of append external enabled read and write */
void testAttrAppendExternalEnabledReadAndWrite()
{
	ViBoolean enabled, readEnabled;	
		
	/* Channel 1 */
	enabled = VI_TRUE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );
		
	enabled = VI_FALSE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );
	
	/* Channel 2 */
	enabled = VI_TRUE;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled != enabled );
		
	enabled = VI_FALSE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );	
}

/* test of append external enabled read and write in AFG3021 and AFG3022 model */
void testAttrAppendExternalEnabledReadAndWriteInAFG302XModel()
{
	ViBoolean enabled, readEnabled;	 
	
	tkafg3k_close(vi);
	vi = VI_NULL;
	
	tkafg3k_InitWithOptions ("GPIB0::11::INSTR", VI_FALSE, VI_TRUE, "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1,DriverSetup=Model AFG3021", &vi);
		
	/* Channel 1 */
	enabled = VI_TRUE;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS != Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );

	/* Channel 2 */
	enabled = VI_TRUE;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS != Ivi_InvalidateAttribute (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS != tkafg3k_GetAttributeViBoolean (vi, CHAN2, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	
	tkafg3k_close(vi);
	vi = VI_NULL;
	
	tkafg3k_init ("GPIB0::11::INSTR", VI_TRUE, VI_TRUE, &vi);
}

/* test of append external enabled association */
void testAttrAppendExternalEnabledAssociation()
{
	ViInt32 i;
	ViBoolean enabled, readEnabled;	
	
	/* Channel 1 */
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
		
	/* Set Append Noise Enabled to VI_TRUE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, VI_TRUE) );
		
	enabled = VI_TRUE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );
		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );		
		
	/* Set Append Noise Enabled to VI_FALSE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_NOISE_ENABLED, VI_FALSE) );				
		
	enabled = VI_TRUE; 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );
		
	enabled = VI_FALSE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, enabled) );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, CHAN1, TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED, &readEnabled) );
	CU_ASSERT ( readEnabled == enabled );	
}


/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_AM_ENABLED depend on (Directly Call):
 *					TKAFG3K_ATTR_MODULATION_ENABLED
 *
 * Related Attribute: 
 *					TKAFG3K_ATTR_WAVEFORM
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					VI_FALSE
 */

/* test of AM enabled flag */
void testAttrAMEnabledFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* Change Waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );

		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, VI_TRUE) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );
	}
}

/* test of AM enabled read and write */
void testAttrAMEnabledReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean enabled, readEnabled;	
	ViBoolean allowance;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_AM, &allowance) );  
			if(allowance)
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 
		
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists = VI_FALSE;
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_FALSE)
			{
				continue;
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) ); 
		
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_AM, &allowance) );
			if(allowance)
			{
				enabled = VI_TRUE; 
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 
		
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 			
			}
		}
	}
}

/* test of AM enabled dependency */
void testAttrAMEnabledDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* change waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, enabled) );		
		
		/* TKAFG3K_ATTR_MODULATION_ENABLED */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_FALSE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_SOURCE 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					TKAFG3K_VAL_AM_INTERNAL
 */

static ViInt32 testAMSourceArray[] = {
						TKAFG3K_VAL_AM_INTERNAL,
						TKAFG3K_VAL_AM_EXTERNAL
};

/* test of AM source read and write */
void testAttrAMSourceArrayReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 source, readSource;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		for(j=0; j<2; j++)
		{
			source = testAMSourceArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_SOURCE, source) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_SOURCE, &readSource) );
			CU_ASSERT ( source == readSource );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_SOURCE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_SOURCE, &readSource) ); 			
			CU_ASSERT ( source == readSource ); 			
		}
		
		source = TKAFG3K_VAL_AM_EXTERNAL + 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_SOURCE, source) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_SOURCE, &readSource) );
		CU_ASSERT ( source != readSource );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_INTERNAL_DEPTH 
 *	
 *******************************************************/

/* 
 * Attribute Flag: 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					50
 */

/* test of AM internal depth flag */
void testAttrAMInternalDepthFlag()
{
	ViReal64 depth = 100, readDepth;

	/* Change AM source to internal */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_AM_SOURCE, TKAFG3K_VAL_AM_INTERNAL) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_AM_SOURCE, TKAFG3K_VAL_AM_INTERNAL) );
	
	/* Set AM internal depth to 100 */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
		
	/* IVI_VAL_NEVER_CACHE */
	/* change am internal depth by channel */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, 50) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, 50) );   

	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) );
	CU_ASSERT ( fabs (readDepth-depth) > 1.0e-5 );
}

/* test of AM internal depth read and write */
void testAttrAMInternalDepthReadAndWrite()
{
	ViReal64 depth, readDepth;

	/* Change AM source to internal */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_AM_SOURCE, TKAFG3K_VAL_AM_INTERNAL) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_AM_SOURCE, TKAFG3K_VAL_AM_INTERNAL) );	
	
	/* Upper Limit */
	depth = 120;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) ); 
	CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
	
	/* Normal Value */
	depth = 50;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) ); 
	CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
	
	/* Lower Limit */
	depth = 0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) ); 
	CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
	
	/* Above Upper LImit */
	depth = 121;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) ); 
	CU_ASSERT ( fabs (readDepth-depth) > 1.0e-5 );	
	
	/* Below Lower Limit */
	depth = -1;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) ); 
	CU_ASSERT ( fabs (readDepth-depth) > 1.0e-5 );	
	
	/* Change AM source of Channel 1 to external */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_AM_SOURCE, TKAFG3K_VAL_AM_EXTERNAL) );
	
	/* Normal Value */
	depth = 50;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, &readDepth) ); 
	CU_ASSERT ( fabs (readDepth-depth) > 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM 
 *	
 *******************************************************/

/*
 * Attribtue Flag:
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						TKAFG3K_VAL_AM_INTERNAL_SINE
 */

/* test of AM internal waveform flag */
void testAttrAMInternalWaveformFlag()
{
	ViInt32 carrier, readCarrier;
	
	carrier = TKAFG3K_VAL_AM_INTERNAL_SINE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, carrier) );
	
	/* IVI_VAL_NEVER_CACHE */
	/* change internal waveform by channel to SQUARE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, TKAFG3K_VAL_AM_INTERNAL_SQUARE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, TKAFG3K_VAL_AM_INTERNAL_SQUARE) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, &readCarrier) );
	CU_ASSERT ( readCarrier != carrier );
}

/* test of AM internal waveform read and write */
static ViInt32 testAMInternalStandardWaveformArray[] = {
							TKAFG3K_VAL_AM_INTERNAL_SINE,
							TKAFG3K_VAL_AM_INTERNAL_SQUARE,
							TKAFG3K_VAL_AM_INTERNAL_TRIANGLE,
							TKAFG3K_VAL_AM_INTERNAL_RAMP_UP,
							TKAFG3K_VAL_AM_INTERNAL_RAMP_DOWN,
							TKAFG3K_VAL_AM_INTERNAL_PRN,
};

static ViInt32 testAMInternalArbitraryWaveformArray[] = {
							TKAFG3K_VAL_AM_INTERNAL_USER1,
							TKAFG3K_VAL_AM_INTERNAL_USER2,
							TKAFG3K_VAL_AM_INTERNAL_USER3,
							TKAFG3K_VAL_AM_INTERNAL_USER4,
};

#define TEST_AM_INTERNAL_STANDARD_WAVEFORM_QUANTUM			6
#define TEST_AM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM			4
void testAttrAMInternalWaveformReadAndWrite()
{
	ViInt32 carrier, readCarrier; 
	ViInt32 waveform;
	ViInt32 i;
	ViBoolean exists;
	
	for(i=0; i<TEST_AM_INTERNAL_STANDARD_WAVEFORM_QUANTUM; i++)
	{
		carrier = testAMInternalStandardWaveformArray[i];
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, carrier) );   
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, &readCarrier) );
		CU_ASSERT ( carrier == readCarrier );
	}
	
	for(i=0; i<TEST_AM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM; i++)
	{
		carrier = testAMInternalArbitraryWaveformArray[i];
		waveform = testArbitraryWaveformArray[i];
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
		if(exists)
		{
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, carrier) ); 	
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, &readCarrier) );
			CU_ASSERT ( carrier == readCarrier );		
		}
		else 
		{
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, carrier) ); 	
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, &readCarrier) );
			CU_ASSERT ( carrier != readCarrier );			
		}
	}
	
	carrier = TKAFG3K_VAL_AM_INTERNAL_USER4+1;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, carrier) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, &readCarrier) );
	CU_ASSERT ( carrier != readCarrier );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY 
 *	
 *******************************************************/

/*
 * Attribtue Flag:
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						10000.0
 */

/* test of AM internal frequency flag */
void testAttrAMInternalFrequencyFlag()
{
	ViReal64 frequency, readFreq;	
	
	frequency = 1000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency) );
	
	/* IVI_VAL_NEVER_CACHE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 500.0) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 500.0) );	

	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );
}

/* test of AM internal frequency read and write */
void testAttrAMInternalFrequencyReadAndWrite()
{
	ViReal64 frequency, readFreq;	

	/* Upper Limit */
	frequency = 50000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	/* Normal Value */
	frequency = 1000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	/* Lower Limit */
	frequency = 0.002;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	/* Above Upper Limit */
	frequency = 50001.0;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
	
	/* Below Lower Limit */
	frequency = 0.001;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL depend on (Directly Call):
 *						TKAFG3K_ATTR_AM_INTERNAL_DEPTH
 *
 * Attribtue Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						50
 */ 
 
/* test of AM depth by channel read and write */
void testAttrAMDepthByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 depth, readDepth; 
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		/* Upper Limit */
		depth = 120;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, depth) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
		
		/* Normal Value */
		depth = 50;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, depth) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
		
		/* Lower Limit */
		depth = 0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, depth) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );		
		
		/* Above Upper Limit */
		depth = 121;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, depth) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) > 1.0e-5 );
	
		/* Below Lower Limit */
		depth = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, depth) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
		CU_ASSERT ( fabs (readDepth-depth) > 1.0e-5 );		
	}
}

/* test of AM depth by channel dependency */
void testAttrAMDepthByChannelDependency()
{
	ViReal64 depth, readDepth; 		
	
	/* TKAFG3K_ATTR_AM_INTERNAL_DEPTH */
	depth = 50;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_DEPTH, depth) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
	CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL, &readDepth) );
	CU_ASSERT ( fabs (readDepth-depth) < 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL depend on (Directly Call):
 *						TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM
 *
 * Attribtue Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						TKAFG3K_VAL_AM_INTERNAL_SINE
 */

/* test of AM internal waveform by channel read and write */
void testAttrAMInternalWaveformByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform, readWaveform, baseWaveform; 
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		for(j=0; j<TEST_AM_INTERNAL_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testAMInternalStandardWaveformArray[j];
					
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
			CU_ASSERT ( readWaveform == waveform );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
			CU_ASSERT ( readWaveform == waveform );			
		}
		
		for(j=0; j<TEST_AM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists;
			waveform = testAMInternalArbitraryWaveformArray[j];
			baseWaveform = testArbitraryWaveformArray[j]; 
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, baseWaveform, &exists) );
			if(exists)
			{
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
				CU_ASSERT ( readWaveform == waveform );
				CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
				CU_ASSERT ( readWaveform == waveform );				
			}
			else
			{
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
				CU_ASSERT ( readWaveform != waveform );				
			}
		}
		
		waveform = TKAFG3K_VAL_AM_INTERNAL_USER4+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
		CU_ASSERT ( readWaveform != waveform );		
	}		
}

/* test of AM internal waveform by channel dependency */
void testAMInternalWaveformByChannelDependency()
{
	ViInt32 waveform, readWaveform;
	
	/* TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM */
	waveform = TKAFG3K_VAL_AM_INTERNAL_SINE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM, TKAFG3K_VAL_AM_INTERNAL_SINE) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
	CU_ASSERT ( waveform == readWaveform );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
	CU_ASSERT ( waveform == readWaveform );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL depend on (Directly Call):
 *						TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY
 *
 * Attribtue Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						10000.0
 */ 

/* test of AM internal frequency by channel read and write */
void testAttrAMInternalFrequencyByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 frequency, readFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Upper Limit */
		frequency = 50000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 
																												frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Normal Value */
		frequency = 1000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 
																												frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Lower Limit */
		frequency = 0.002;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 
																												frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Above Upper Limit */
		frequency = 50001.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 
																												frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
		
		/* Below Lower Limit */
		frequency = 0.001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, 
																												frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL,
																												&readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );		
	}
}

/* test of AM internal frequency dependency */
void testAttrAMInternalFrequencyDependency()
{
	ViReal64 frequency, readFreq;
	
	/* TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY */
	frequency = 1000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY, frequency ) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq ) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq ) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_AM_ENABLED depend on (Directly Call):
 *					TKAFG3K_ATTR_MODULATION_ENABLED
 *
 * Related Attribute: 
 *					TKAFG3K_ATTR_WAVEFORM
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					VI_FALSE
 */

/* test of FM enabled flag */
void testAttrFMEnabledFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, VI_TRUE) );	
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, VI_TRUE) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &enabled) );
		CU_ASSERT ( VI_TRUE != enabled );
	}
}

/* test of FM enabled read and write */
void testAttrFMEnabledReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean enabled, readEnabled;
	ViBoolean allowance;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );   			
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_FM, &allowance) );
			if(allowance)
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) );
				CU_ASSERT ( enabled == readEnabled ); 
			
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) ); 
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) );  
				CU_ASSERT ( enabled == readEnabled ); 
			}
			else
			{
				enabled = VI_TRUE;  
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled );
			
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled );
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists = VI_FALSE;
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_FALSE)
			{
				continue;
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_FM, &allowance) );
			if(allowance)
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled );
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 			
			}
		}
	}
}

/* test of FM Enabled dependency */
void testAttrFMEnabledDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean enabled, readEnabled;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) ); 
		
		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, enabled) ); 
		
		/* TKAFG3K_ATTR_MODULATION_ENABLED */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, VI_FALSE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_SOURCE 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					TKAFG3K_VAL_FM_INTERNAL
 */
 
/* test of FM source read and write */
static ViInt32 testFMSourceArray[] = {
						TKAFG3K_VAL_FM_INTERNAL,
						TKAFG3K_VAL_FM_EXTERNAL,
};

void testAttrFMSourceReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 source, readSource;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}		

		for(j=0; j<2; j++)
		{
			source = testFMSourceArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FM_SOURCE, source) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FM_SOURCE, &readSource) );
			CU_ASSERT ( readSource == source );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_SOURCE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FM_SOURCE, &readSource) );
			CU_ASSERT ( readSource == source );			
		}
		
		source = TKAFG3K_VAL_FM_EXTERNAL+100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FM_SOURCE, source) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FM_SOURCE, &readSource) );
		CU_ASSERT ( readSource != source );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_INTERNAL_DEVIATION 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					1000000.0
 */ 

/* test of FM internal deviation flag */
void testAttrFMInternalDeviationFlag()
{
	ViReal64 deviation, readDeviation;
	
	/* Pre-set waveform to SINE and frequency to 1000000 */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) ); 
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) ); 
	
	deviation = 1000;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, 1000) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, 1000000.0 ) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, 1000000.0 ) );	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
}

/* test of FM internal deviation read and write */
void testAttrFMInternalDeviationReadAndWrite()
{
	ViReal64 deviation, readDeviation;
	
	/* FM Source to internal */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_FM_SOURCE, 0, TKAFG3K_VAL_FM_INTERNAL) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_FM_SOURCE, 0, TKAFG3K_VAL_FM_INTERNAL) ); 
	
	/* Pre-set waveform to SINE and frequency to 1000000 */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) ); 
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) );
	
	/* set deviation to max value */
	deviation = 1000000;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	
	/* set deviation to normal value */
	deviation = 1000;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );	

	/* set deviation to min value */
	deviation = 0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	
	/* above max value */
	deviation = 1000001;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
	
	/* below min value */
	deviation = -1;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );	
	
	/* change frequency to 50M Hz */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );	
	
	/* set deviation to max value */
	deviation = 50000000;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	
	/* set deviation to normal value */
	deviation = 1000;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );	

	/* set deviation to min value */
	deviation = 0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
	CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );	
	
	/* above max value */
	deviation = 50000001;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
	
	/* below min value */
	deviation = -1;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );

	/* FM Source to external */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_FM_SOURCE, 0, TKAFG3K_VAL_FM_EXTERNAL) );

	/* Pre-set waveform to SINE and frequency to 1000000 */
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) ); 
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) );
	CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) );
	
	/* set deviation to normal value */
	deviation = 1000;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, deviation) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_DEVIATION, &readDeviation) );
	CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					TKAFG3K_VAL_FM_INTERNAL_SINE
 */ 

/* test of FM internal waveform flag */
void testAttrFMInternalWaveformFlag()
{
	ViInt32 waveform, readWaveform;
	
	waveform = TKAFG3K_VAL_FM_INTERNAL_SINE;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, waveform) );
																						
    CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN1, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL,
    																				TKAFG3K_VAL_FM_INTERNAL_SQUARE) );
    CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, CHAN2, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL,
    																				TKAFG3K_VAL_FM_INTERNAL_SQUARE) );	    																				
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, &readWaveform) );			    																				
	CU_ASSERT ( readWaveform != waveform );
}

/* test of FM internal waveform read and write */
static ViInt32 testFMInternalStandardWaveformArray[] = {
							TKAFG3K_VAL_FM_INTERNAL_SINE,
							TKAFG3K_VAL_FM_INTERNAL_SQUARE,
							TKAFG3K_VAL_FM_INTERNAL_TRIANGLE,
							TKAFG3K_VAL_FM_INTERNAL_RAMP_UP,
							TKAFG3K_VAL_FM_INTERNAL_RAMP_DOWN,
							TKAFG3K_VAL_FM_INTERNAL_PRN,
};

static ViInt32 testFMInternalArbitraryWaveformArray[] = {
							TKAFG3K_VAL_FM_INTERNAL_USER1,
							TKAFG3K_VAL_FM_INTERNAL_USER2,
							TKAFG3K_VAL_FM_INTERNAL_USER3,
							TKAFG3K_VAL_FM_INTERNAL_USER4,
};

#define TEST_FM_INTERNAL_STANDARD_WAVEFORM_QUANTUM			6
#define TEST_FM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM			4

void testAttrFMInternalWaveformReadAndWrite()
{
	ViInt32 carrier, readCarrier; 
	ViInt32 waveform;
	ViInt32 i;
	ViBoolean exists;
	
	for(i=0; i<TEST_FM_INTERNAL_STANDARD_WAVEFORM_QUANTUM; i++)
	{
		carrier = testFMInternalStandardWaveformArray[i];

		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, carrier) );   
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, &readCarrier) );
		CU_ASSERT ( carrier == readCarrier );		
	}
	
	for(i=0; i<TEST_FM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM; i++)
	{
		carrier = testFMInternalArbitraryWaveformArray[i];
		waveform = testArbitraryWaveformArray[i];  
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
		if(exists)
		{
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, carrier) ); 	
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, &readCarrier) );
			CU_ASSERT ( carrier == readCarrier );				
		}
		else
		{
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, carrier) ); 	
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, &readCarrier) );
			CU_ASSERT ( carrier != readCarrier );		
		}
	}
	
	carrier = TKAFG3K_VAL_FM_INTERNAL_USER4+1;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, carrier) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM, &readCarrier) );
	CU_ASSERT ( carrier != readCarrier );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY 
 *	
 *******************************************************/	

/*
 * Attribute Flag:
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					10000.0
 */ 

/* test of FM internal frequency flag */
void testAttrFMInternalFrequencyFlag()
{
	ViReal64 frequency, readFreq;
	
	frequency = 1000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, frequency) );
	
	/* IVI_VAL_NEVER_CACHE */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN1, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, 500.0) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, CHAN2, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, 500.0) );	

	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );
}

/* test of FM internal frequency read and write */
void testAttrFMInternalFrequencyReadAndWrite()
{
	ViReal64 frequency, readFreq;	

	/* Upper Limit */
	frequency = 50000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	/* Normal Value */
	frequency = 1000.0;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	/* Lower Limit */
	frequency = 0.002;
	CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
	
	/* Above Upper Limit */
	frequency = 50001.0;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
	
	/* Below Lower Limit */
	frequency = 0.001;
	CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, frequency) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, VI_NULL, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY, &readFreq) );
	CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL 
 *	
 *******************************************************/	
 
/* TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL depend on (Invalidation);
 *					TKAFG3K_ATTR_FREQUENCY
 *					TKAFG3K_ATTR_WAVEFORM
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					1000000.0 
 */

/* test of FM deviation by channel read and write */
void testAttrFMDeviationByChannelReadAndWrite()
{
	ViReal64 deviation, readDeviation;
	ViReal64 maxFreq;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean allowance;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_FM, &allowance ) );
			if(allowance != VI_TRUE)
			{
				continue;
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, VI_TRUE) );
			switch(waveform)
			{
				case TKAFG3K_VAL_WFM_SINE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SINE/2.0;
					break;
				}
				case TKAFG3K_VAL_WFM_SQUARE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SQUARE/2.0; 				
					break;
				}
				case TKAFG3K_VAL_WFM_RAMP:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_RAMP/2.0; 						
					break;
				}
				case TKAFG3K_VAL_WFM_SINC:
				case TKAFG3K_VAL_WFM_GAUS:
				case TKAFG3K_VAL_WFM_LOR:
				case TKAFG3K_VAL_WFM_ERIS:
				case TKAFG3K_VAL_WFM_EDEC:
				case TKAFG3K_VAL_WFM_HAV:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_DEFAULT/2.0; 				
					break;
				}
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, maxFreq) );
			
			/* Upper Limit */
			deviation = maxFreq;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			
			/* Normal Value */
			deviation = maxFreq/2.0;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );			
			
			/* Lower Limit */
			deviation = 0;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			
			/* Above Upper Limit */
			deviation = maxFreq+1;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
			
			/* Below Lower Limit */
			deviation = -1;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
			CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );			
		}
		
		waveform = TKAFG3K_VAL_WFM_EDIT;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
		
		maxFreq = AFG302X_VAL_MAX_FREQ_ARB/2.0;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, maxFreq) ); 
		
		/* Upper Limit */
		deviation = maxFreq;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			
		/* Normal Value */
		deviation = maxFreq/2.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );			
			
		/* Lower Limit */
		deviation = 0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
			
		/* Above Upper Limit */
		deviation = maxFreq+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
			
		/* Below Lower Limit */
		deviation = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );		
	}	
}

/* test of FM deviation by channel dependency */
void testAttrFMDeviationByChannelDependency()
{
	ViReal64 deviation, readDeviation;
	ViReal64 maxFreq;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
 
 		/* Pre-set waveform to SINE, frequency to 50M Hz, FM deviation by channel to 50 MHz */
 		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
 		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
 		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FM_ENABLED, VI_TRUE) );
 		deviation = 50000000;
 		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
 		
 		/* TKAFG3K_ATTR_FREQUENCY */
 		/* change frequency to 100MHz */
 		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 100000000) );
 		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
 		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
 		
 		/* back waveform to SINE, frequency to 50M Hz, FM deviation by channel to 50 MHz */
 		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
 		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
 		deviation = 50000000;
 		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, deviation) );
 		
 		/* TKAFG3K_ATTR_WAVEFORM */ 
 		/* change waveform to TKAFG3K_VAL_WFM_SQUARE */
 		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SQUARE) );
 		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL, &readDeviation) );
 		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 ); 		
 	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL 
 *	
 *******************************************************/

/* Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						TKAFG3K_VAL_FM_INTERNAL_SINE
 */

/* test of FM internal waveform by channel read and write */
void testAttrFMInternalWaveformByChannelReadAndWrite()
{
	ViInt32 carrier, readCarrier;
	ViInt32 waveform;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViBoolean exists;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		for(j=0; j<TEST_FM_INTERNAL_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			carrier = testFMInternalStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, carrier) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, &readCarrier) );
			CU_ASSERT ( readCarrier == carrier );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, &readCarrier) );
			CU_ASSERT ( readCarrier == carrier );			
		}
		
		for(j=0; j<TEST_FM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			carrier = testFMInternalArbitraryWaveformArray[j];
			waveform = testArbitraryWaveformArray[j];
			
			// tkafg3k_WfmExists (ViSession vi, ViInt32 wfmHandle, ViBoolean *wfmExists)
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists (vi, waveform, &exists) );
			
			if(exists)
			{
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, 
													TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, carrier) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, 
													TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, &readCarrier) );
				CU_ASSERT ( readCarrier == carrier );
				CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, 
													TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, &readCarrier) );
				CU_ASSERT ( readCarrier == carrier );				
			}		
			else
			{
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, 
													TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, carrier) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, 
													TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL, &readCarrier) );
				CU_ASSERT ( readCarrier != carrier );				
			}
		}
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL 
 *	
 *******************************************************/

/* Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						10000.0
 */

void testAttrFMInternalFrequencyByChannelReadAndWrite()
{
	ViReal64 frequency, readFreq;
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* Upper Limit */
		frequency = 50000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );		
		
		/* Normal Value */
		frequency = 10000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );	
		
		/* Lower Limit */
		frequency = 0.002;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) < 1.0e-5 );
		
		/* Above Upper Limit */
		frequency = 50001.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );

		/* Below Lower Limit */
		frequency = 0.001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, 
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel,
												TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs(readFreq-frequency) > 1.0e-5 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FSK_ENABLED 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_FSK_ENABLED depend on (Directly Call):
 *					TKAFG3K_ATTR_MODULATION_ENABLED
 *
 * Related Attribute: 
 *					TKAFG3K_ATTR_WAVEFORM
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					VI_FALSE
 */

/* test of FSK enabled flag */
void testAttrFSKEnabledFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		/* IVI_VAL_NEVER_CACHE */	
		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &enabled) );
		CU_ASSERT ( VI_TRUE != enabled );
	}
}

/* test of FSK enabled read and write */
void testAttrFSKEnabledReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean enabled, readEnabled;	
	ViBoolean allowance;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}		

		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_FSK, &allowance) );
			if(allowance)
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 
		
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else 
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 			
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists = VI_FALSE;
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_FALSE)
			{
				continue;
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) ); 
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_FSK, &allowance) );
			if(allowance)
			{
				enabled = VI_TRUE; 
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 
		
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 			
			}	
		}
	}
}

/* test of FSK enabled dependency */
void testAttrFSKEnabledDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* change waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, enabled) );		
		
		/* TKAFG3K_ATTR_MODULATION_ENABLED */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_FALSE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FSK_SOURCE 
 *	
 *******************************************************/

/* Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default value:
 *					TKAFG3K_VAL_FSK_INTERNAL
 */

/* test of FSK source read and write */
static ViInt32 testFSKSourceArray[] = {
						TKAFG3K_VAL_FSK_INTERNAL,
						TKAFG3K_VAL_FSK_EXTERNAL,
};

void testAttrFSKSourceReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 source, readSource;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		for(j=0; j<2; j++)
		{
			source = testFSKSourceArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FSK_SOURCE, source) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FSK_SOURCE, &readSource) );
			CU_ASSERT ( source == readSource );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_SOURCE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FSK_SOURCE, &readSource) ); 			
			CU_ASSERT ( source == readSource ); 
		}
		
		source = TKAFG3K_VAL_FSK_EXTERNAL + 100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FSK_SOURCE, source) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_FSK_SOURCE, &readSource) );
		CU_ASSERT ( source != readSource );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FSK_HOP_FREQUENCY 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_FSK_HOP_FREQUENCY depends on (Invalidation):
 *					TKAFG3K_ATTR_WAVEFORM					
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default value:
 *					1000000.0
 */

/* test of FSK hop frequency read and write */
void testAttrFSHHopFrequencyReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViReal64 frequency, readFreq, maxFreq;
	ViInt32 waveform;
	ViBoolean allowance;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		waveform = TKAFG3K_VAL_WFM_SINE;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, VI_TRUE) );

		/* STANDARD WAVEFORM */
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_FSK, &allowance) ); 
			if(!allowance)
			{
				continue;
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			switch(waveform)
			{
				case TKAFG3K_VAL_WFM_SINE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SINE;
					break;
				}
				case TKAFG3K_VAL_WFM_SQUARE:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_SQUARE;  
					break;
				}
				case TKAFG3K_VAL_WFM_RAMP:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_RAMP;  
					break;
				}
				case TKAFG3K_VAL_WFM_SINC:
				case TKAFG3K_VAL_WFM_GAUS:
				case TKAFG3K_VAL_WFM_LOR:
				case TKAFG3K_VAL_WFM_ERIS:
				case TKAFG3K_VAL_WFM_EDEC:
				case TKAFG3K_VAL_WFM_HAV:
				{
					maxFreq = AFG310X_VAL_MAX_FREQ_DEFAULT;  
					break;	
				}
			}
			
			/* Upper Limit */
			frequency = maxFreq;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );			
			
			/* Normal Value */
			frequency = 1000.0;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
			
			/* Lower Limit */
			frequency = 0.01;
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );	
			
			/* Above Upper Limit */
			frequency = maxFreq+1;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
			
			/* Below Lower Limit */
			frequency = 0.005;
			CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
			CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
		}

		/* ARBITRARY WAVEFORM */ 		
		waveform = TKAFG3K_VAL_WFM_EDIT;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) ); 		
		
		maxFreq = AFG310X_VAL_MAX_FREQ_ARB;
		
		/* Upper Limit */
		frequency = maxFreq;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Normal Value */
		frequency = 1000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Lower Limit */
		frequency = 0.01;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Above Upper Limit */
		frequency = maxFreq+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
		
		/* Below Lower Limit */
		frequency = 0.005;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_HOP_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_FSK_INTERNAL_RATE 
 *	
 *******************************************************/

/*
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default value:
 *					50.0
 */

/* test of FSK internal rate read and write */
void testAttrFSKInternalRateReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViReal64 rate, readRate;

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}		

		/* Pre-set to SINE waveform, FSK modualtion */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_FSK_ENABLED, VI_TRUE) );
		
		/* Upper Limit */
		rate = 1000000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, rate) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) < 1.0e-5 );
		
		/* Normal Value */
		rate = 50.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, rate) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) < 1.0e-5 );
		
		/* Lower Limit */
		rate = 0.002;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, rate) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) < 1.0e-5 );
		
		/* Above Upper Limit */
		rate = 1000001.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, rate) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) > 1.0e-5 );
		
		/* Below Lower Limit */
		rate = 0.001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, rate) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FSK_INTERNAL_RATE, &readRate) );
		CU_ASSERT ( fabs (readRate-rate) > 1.0e-5 );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PM_ENABLED 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_PM_ENABLED depend on (Directly Call):
 *					TKAFG3K_ATTR_MODULATION_ENABLED
 *
 * Related Attribute: 
 *					TKAFG3K_ATTR_WAVEFORM
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					VI_FALSE
 */ 

/* test of PM enabled flag */
void testAttrPMEnabledFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;		

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* Change Waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );

		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_AM_ENABLED, VI_TRUE) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );
	}
}

/* test of PM enabled read and write */
void testAttrPMEnabledReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean enabled, readEnabled;	
	ViBoolean allowance;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		for(j=0; j<TEST_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testStandardWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_PM, &allowance) );  
			if(allowance)
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 
		
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
		}
		
		for(j=0; j<TEST_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists = VI_FALSE;
			
			waveform = testArbitraryWaveformArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, waveform, &exists) );
			if(exists == VI_FALSE)
			{
				continue;
			}
			
			CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, waveform) );
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_ModulationTypeAllowable (vi, waveform, TKAFG3K_VAL_MODULATION_PM, &allowance) );			
			if(allowance)
			{
				enabled = VI_TRUE; 
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 
		
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 				
			}
			else
			{
				enabled = VI_TRUE;
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled != readEnabled ); 				
				
				enabled = VI_FALSE;
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) ); 
				CU_ASSERT ( enabled == readEnabled ); 			
			}
		}
	}
}

/* test of PM enabled dependency */
void testAttrPMEnabledDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* change waveform to SINE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		
		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, enabled) );		
		
		/* TKAFG3K_ATTR_MODULATION_ENABLED */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_MODULATION_ENABLED, 0, VI_FALSE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );
	}		
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PM_SOURCE 
 *	
 *******************************************************/

/* Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						TKAFG3K_VAL_PM_INTERNAL
 */

/* test of PM source read and write */
static ViInt32 testPMSourceArray[] = {
							TKAFG3K_VAL_PM_INTERNAL,
							TKAFG3K_VAL_PM_EXTERNAL,
};

/* test of PM source read and write */
void testAttrPMSourceReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 source, readSource;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Pre-set to SINE, PM */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PM_ENABLED, VI_TRUE) );
		
		for(j=0; j<2; j++)
		{
			source = testPMSourceArray[j];
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_SOURCE, source) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_SOURCE, &readSource) );
			CU_ASSERT ( source == readSource );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_SOURCE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_SOURCE, &readSource) );
			CU_ASSERT ( source == readSource );			
		}
		
		source = TKAFG3K_VAL_PM_EXTERNAL+100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_SOURCE, source) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_SOURCE, &readSource) );
		CU_ASSERT ( source != readSource );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL 
 *	
 *******************************************************/ 

/* Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					0
 */

/* test of PM deviation by channel read and write */
void testAttrPMDeviationByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViReal64 deviation, readDeviation;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Upper Limit */
		deviation = 180;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 0.005);
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 0.005 );
		
		/* Normal Value */
		deviation = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 0.005 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 0.005 );	
		
		/* Lower Limit */
		deviation = 0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 0.005 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 0.005 );			
		
		/* Above Upper Limit */
		deviation = 181;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 0.005 );

		/* Below Lower Limit */ 
		deviation = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 0.005 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL 
 *	
 *******************************************************/ 
 
/* Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						10000.0
 */

/* test of PM internal frequency by channel read and write */
void testAttrPMInternalFrequencyByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViReal64 frequency, readFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Upper Limit */
		frequency = 50000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Normal Value */
		frequency = 10000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Lower Limit */
		frequency = 0.002;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Above Upper Limit */
		frequency = 50001.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );

		/* Below Lower Limit */
		frequency = 0.001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL 
 *	
 *******************************************************/  

/* Attribute Flag:
 * 						IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *						TKAFG3K_VAL_PM_INTERNAL_SINE
 */

/* test of PM internal waveform by channel */
static ViInt32 testPMInternalStandardWaveformArray[] = {
								TKAFG3K_VAL_PM_INTERNAL_SINE,
								TKAFG3K_VAL_PM_INTERNAL_SQUARE,
								TKAFG3K_VAL_PM_INTERNAL_TRIANGLE,
								TKAFG3K_VAL_PM_INTERNAL_RAMP_UP,
								TKAFG3K_VAL_PM_INTERNAL_RAMP_DOWN,
								TKAFG3K_VAL_PM_INTERNAL_PRN,
								};

static ViInt32 testPMInternalArbitraryWaveformArray[] = {
								TKAFG3K_VAL_PM_INTERNAL_USER1,
								TKAFG3K_VAL_PM_INTERNAL_USER2,
								TKAFG3K_VAL_PM_INTERNAL_USER3,
								TKAFG3K_VAL_PM_INTERNAL_USER4,
								};

#define TEST_PM_INTERNAL_STANDARD_WAVEFORM_QUANTUM				6
#define TEST_PM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM				4

void testAttrPMInternalWaveformByChannelReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform, readWaveform, baseWaveform; 
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		for(j=0; j<TEST_PM_INTERNAL_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testPMInternalStandardWaveformArray[j];
					
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
			CU_ASSERT ( readWaveform == waveform );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
			CU_ASSERT ( readWaveform == waveform );			
		}		

		for(j=0; j<TEST_PM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists;
			waveform = testPMInternalArbitraryWaveformArray[j];
			baseWaveform = testArbitraryWaveformArray[j]; 
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, baseWaveform, &exists) );
			if(exists)
			{
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
				CU_ASSERT ( readWaveform == waveform );
				CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
				CU_ASSERT ( readWaveform == waveform );				
			}
			else
			{
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
				CU_ASSERT ( readWaveform != waveform );				
			}
		}
		
		waveform = TKAFG3K_VAL_PM_INTERNAL_USER4+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, waveform) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL, &readWaveform) );
		CU_ASSERT ( readWaveform != waveform );	
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PWM_ENABLED 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_PWM_ENABLED depend on (Directly Call):
 *					TKAFG3K_ATTR_MODULATION_ENABLED
 *
 * Related Attribute: 
 *					TKAFG3K_ATTR_WAVEFORM
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					VI_FALSE
 */

/* test of PWM enabled flag */
void testAttrPWMEnabledFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
		
		/* Change waveform to PULSE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );

		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, enabled) );
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_SINE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );
	}		
}

/* test of PWM enabled read and write */
void testAttrPWMEnabledReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViBoolean enabled, readEnabled;	

	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* change waveform to PULSE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );

		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled == readEnabled );
		
		enabled = VI_FALSE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, enabled) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled == readEnabled );
	}		
}

/* test of PWM enabled dependency */
void testAttrPWMEnabledDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform;
	ViBoolean enabled, readEnabled;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) ); 
		
		enabled = VI_TRUE;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, enabled) ); 
		
		/* TKAFG3K_ATTR_MODULATION_ENABLED */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, VI_FALSE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, &readEnabled) );
		CU_ASSERT ( enabled != readEnabled );		
	}	
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PWM_SOURCE 
 *	
 *******************************************************/

/* Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					TKAFG3K_VAL_PWM_INTERNAL
 */

/* test of PWM source read and write */
static ViInt32 testPWMSourceArray[] = {
						TKAFG3K_VAL_PWM_INTERNAL,
						TKAFG3K_VAL_PWM_EXTERNAL,
						};

void testAttrPWMSourceReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 source, readSource;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* Pre-set to PULSE, PWM */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, VI_TRUE) );
		
		for(j=0; j<2; j++)
		{
			source = testPWMSourceArray[j];  		
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_SOURCE, source) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_SOURCE, &readSource) );  
			CU_ASSERT ( readSource == source );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PWM_SOURCE) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_SOURCE, &readSource) );  
			CU_ASSERT ( readSource == source );			
		}
		
		source = TKAFG3K_VAL_PWM_EXTERNAL+100;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_SOURCE, source) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_SOURCE, &readSource) );  
		CU_ASSERT ( readSource != source );
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PWM_DEVIATION 
 *	
 *******************************************************/

/* Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						5.0
 */

/* test of PWM deviation flag */
void testAttrPWMDeviationFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 deviation, readDeviation;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
		
		/* Pre-set waveform to PULSE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 1) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		
		deviation = 49.9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, deviation) );
		
		/* IVI_VAL_NEVER_CACHE */	
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 1000000) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 20) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );
	}
}

/* test of PWM deviation read and write */
void testAttrPWMDeviationReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 deviation, readDeviation;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 1) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		
		/* Upper Limit */
		deviation = 49.9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, deviation) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );
		
		/* Normal Value */
		deviation = 20;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, deviation) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );		
		
		/* Lower Limit */
		deviation = 0.1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, deviation) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) < 1.0e-5 );		
		
		/* Above Upper Limit */
		deviation = 50;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );		
		
		/* Below Lower Limit */
		deviation = 0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, deviation) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_DEVIATION, &readDeviation) );
		CU_ASSERT ( fabs (readDeviation-deviation) > 1.0e-5 );			
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY 
 *	
 *******************************************************/

/* Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					10000.0
 */

/* test of PWM internal frequency read and write */
void testAttrPWMInternalFrequencyReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 frequency, readFreq;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Upper Limit */
		frequency = 50000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Normal Value */
		frequency = 10000.0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );	
		
		/* Lower Limit */
		frequency = 0.002;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) < 1.0e-5 );
		
		/* Above Upper Limit */
		frequency = 50001.0;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );
	
		/* Below Lower Limit */
		frequency = 0.001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, frequency) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_FREQUENCY, &readFreq) );
		CU_ASSERT ( fabs (readFreq-frequency) > 1.0e-5 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM 
 *	
 *******************************************************/

/* Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL
 *
 * Default Value:
 *					TKAFG3K_VAL_PWM_INTERNAL_SINE
 */

/* test of PWM internal waveform read and write */
static ViInt32 testAttrPWMStandardWaveformArray[] = {
								TKAFG3K_VAL_PWM_INTERNAL_SINE,
								TKAFG3K_VAL_PWM_INTERNAL_SQUARE,
								TKAFG3K_VAL_PWM_INTERNAL_TRIANGLE,
								TKAFG3K_VAL_PWM_INTERNAL_RAMP_UP,
								TKAFG3K_VAL_PWM_INTERNAL_RAMP_DOWN,
								TKAFG3K_VAL_PWM_INTERNAL_PRN,
								};

static ViInt32 testAttrPWMArbitraryWaveformArray[] = {
								TKAFG3K_VAL_PWM_INTERNAL_USER1,
								TKAFG3K_VAL_PWM_INTERNAL_USER2,
								TKAFG3K_VAL_PWM_INTERNAL_USER3,
								TKAFG3K_VAL_PWM_INTERNAL_USER4,
								};

#define TEST_PWM_INTERNAL_STANDARD_WAVEFORM_QUANTUM			6
#define TEST_PWM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM		4

void testAttrPWMInternalWaveformReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i, j;
	ViInt32 waveform, readWaveform, baseWaveform;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}			

		/* Pre-set to PULSE, PWM */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViBoolean (vi, channel, TKAFG3K_ATTR_PWM_ENABLED, VI_TRUE) );
		
		for(j=0; j<TEST_PWM_INTERNAL_STANDARD_WAVEFORM_QUANTUM; j++)
		{
			waveform = testAttrPWMStandardWaveformArray[j];
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, waveform) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, &readWaveform) );
			CU_ASSERT ( readWaveform == waveform );
			CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM) );
			CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, &readWaveform) );
			CU_ASSERT ( readWaveform == waveform );			
		}
		
		for(j=0; j<TEST_PWM_INTERNAL_ARBITRARY_WAVEFORM_QUANTUM; j++)
		{
			ViBoolean exists; 
			waveform = testAttrPWMArbitraryWaveformArray[j];
			baseWaveform = testArbitraryWaveformArray[j];  
			
			CU_ASSERT ( VI_SUCCESS == tkafg3k_WfmExists(vi, baseWaveform, &exists) );
			if(exists)
			{			
				CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, &readWaveform) );
				CU_ASSERT ( readWaveform == waveform );
				CU_ASSERT ( VI_SUCCESS == Ivi_InvalidateAttribute (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, &readWaveform) );
				CU_ASSERT ( readWaveform == waveform );			
			}
			else 
			{
				CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, waveform) );
				CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, &readWaveform) );
				CU_ASSERT ( readWaveform != waveform );				
			}
		}
		
		waveform = TKAFG3K_VAL_PWM_INTERNAL_USER4+1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, waveform) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM, &readWaveform) );
		CU_ASSERT ( readWaveform != waveform );			
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PULSE_PERIOD 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_PULSE_PERIOD depend on:
 *						TKAFG3K_ATTR_FREQUENCY
 *
 * Attribute Flag:
 *						IVI_VAL_MULTI_CHANNEL  
 *						IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *						1.0e-6
 */

/* test of pulse period read and write */
void testAttrPulsePeriodFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 period, readPeriod;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}		

		/* Pre-set to PULSE, period to 1 */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );		
		period = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, period) );
		
		/* IVI_VAL_NEVER_CACHE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 10) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, &readPeriod) );
		CU_ASSERT ( fabs (readPeriod-period) > 1.0e-5 );
	}
}

/* test of pulse period read and write */
void testAttrPulsePeriodReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 period, readPeriod;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}		

		/* Upper Limit */
		period = 1000;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, period) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, &readPeriod) );
		CU_ASSERT ( fabs (readPeriod-period) < 1.0e-5 );
		
		/* Normal Value */
		period = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, period) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, &readPeriod) );
		CU_ASSERT ( fabs (readPeriod-period) < 1.0e-5 );		
		
		/* Lower Limit */
		period = 2.0e-8;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, period) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, &readPeriod) );
		CU_ASSERT ( fabs (readPeriod-period) < 1.0e-5 );
		
		/* Above Upper Limit */
		period = 1001;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, period) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, &readPeriod) );
		CU_ASSERT ( fabs (readPeriod-period) > 1.0e-5 );	
		
		/* Below Lower Limit */
		period = 1.0e-8;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, period) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, &readPeriod) );
		CU_ASSERT ( fabs (readPeriod-period) > 1.0e-9 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PULSE_DUTY_CYCLE 
 *	
 *******************************************************/
 
/* TKAFG3K_ATTR_PULSE_DUTY_CYCLE depends on:
 *					TKAFG3K_ATTR_PULSE_PERIOD
 *					TKAFG3K_ATTR_FREQUENCY
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					50
 */

/* test of pulse duty cycle flag */
void testAttrPulseDutyCycleFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 dutyCycle, readDutyCycle;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	
	
		/* Pre-set to PULSE */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		/* set frequency to 1 Hz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 1) );
		
		/* duty cycle 10% */
		dutyCycle = 10;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, dutyCycle) );
		
		/* change frequency to 50 MHz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, &readDutyCycle) );
		CU_ASSERT ( fabs (readDutyCycle-dutyCycle) > 1.0e-5 );
	}
}

/* test of pulse duty cycle read and write */
void testAttrPulseDutyCycleReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 dutyCycle, readDutyCycle;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* Pre-set to PULSE, frequency 50 MHz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		
		/* Upper Limit */
		dutyCycle = 40;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, dutyCycle) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, &readDutyCycle) );
		CU_ASSERT ( fabs (readDutyCycle-dutyCycle) < 0.005 );
		
		/* Normal Value */
		dutyCycle = 50;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, dutyCycle) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, &readDutyCycle) );
		CU_ASSERT ( fabs (readDutyCycle-dutyCycle) < 0.005 );
		
		/* Lower Limit */
		dutyCycle = 60;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, dutyCycle) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, &readDutyCycle) );
		CU_ASSERT ( fabs (readDutyCycle-dutyCycle) < 0.005 );	
		
		/* Above Upper Limit */
		dutyCycle = 61;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, dutyCycle) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, &readDutyCycle) );
		CU_ASSERT ( fabs (readDutyCycle-dutyCycle) > 0.005 );		
		
		/* Below Lower Limit */
		dutyCycle = 39;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, dutyCycle) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, &readDutyCycle) );
		CU_ASSERT ( fabs (readDutyCycle-dutyCycle) > 0.005 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PULSE_LEADING_TIME 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_PULSE_LEADING_TIME depends on:
 *					TKAFG3K_ATTR_PULSE_PERIOD
 *					TKAFG3K_ATTR_FREQUENCY
 *					TKAFG3K_ATTR_PULSE_DUTY_CYCLE
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					5.0e-9
 */

/* test of pulse leading time flag */
void testAttrPulseLeadingTimeFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 leadingTime, readLeadingTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Pre-set to PULSE, frequency 50 MHz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		
		/* leading time */
		leadingTime = 7.5e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		
		/* change duty cycle to 60% */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 60) ); 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) > 1.0e-10 );
	}
}

/* test of pulse leading time read and write */
void testAttrPulseLeadingTimeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 leadingTime, readLeadingTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* Pre-set to PULSE, frequency 50 MHz, duty cycle 50% */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		
		/* Upper Limit */
		leadingTime = 7.5e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) < 5.0e-11 );
		
		/* Normal Value */
		leadingTime = 6.0e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) < 5.0e-11 );
		
		/* Lower Limit */
		leadingTime = 5.0e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) < 5.0e-11 );
		
		/* Above Upper Limit */
		leadingTime = 8.0e-9;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) > 5.0e-11 );	
		
		/* Below Lower Limit */
		leadingTime = 4.0e-9;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) > 5.0e-11 );			
	}
}

/* test of pulse leading time dependency */
void testAttrPulseLeadingTimeDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViReal64 leadingTime, readLeadingTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* Default Setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 10) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		
		/* pulse leading time 6.24s */
		leadingTime = 6.24;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, leadingTime) );
		
		/* TKAFG3K_ATTR_PULSE_DUTY_CYCLE */
		/* change duty cycle to 20% */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 20) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) > 5.0e-11 );
		
		/* TKAFG3K_ATTR_FREQUENCY or TKAFG3K_ATTR_PULSE_PERIOD */
		/* change frequency to 50M Hz */
		leadingTime = readLeadingTime;
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, &readLeadingTime) );
		CU_ASSERT ( fabs (readLeadingTime-leadingTime) > 5.0e-11 );		
	}
}

/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PULSE_TRAILING_TIME 
 *	
 *******************************************************/

/* TKAFG3K_ATTR_PULSE_TRAILING_TIME depends on:
 *					TKAFG3K_ATTR_PULSE_PERIOD
 *					TKAFG3K_ATTR_FREQUENCY
 *					TKAFG3K_ATTR_PULSE_DUTY_CYCLE
 *					TKAFG3K_ATTR_PULSE_LEADING_TIME
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					5.0e-9
 */

/* test of pulse trailing time flag */
void testAttrPulseTrailingTimeFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 trailingTime, readTrailingTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* Pre-set to PULSE, frequency 50 MHz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, 5.0e-9) );
		
		/* trailing time */
		trailingTime = 7.5e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) ); 
		
		/* IVI_VAL_NEVER_CACHE */
		/* change duty cycle to 60 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 60) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) > 5.0e-11 );
	}
}

/* test of pulse trailing time read and write */
void testAttrPulseTrailingTimeReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 trailingTime, readTrailingTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* Pre-set to PULSE, frequency 50 MHz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, 5.0e-9) );
		
		/* Upper Limit */
		trailingTime = 7.5e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) < 5.0e-11 );
		
		/* Normal Value */
		trailingTime = 6.0e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) < 5.0e-11 );	
		
		/* Lower Limit */
		trailingTime = 5.0e-9;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) < 5.0e-11 );		
		
		/* Above Upper Limit */
		trailingTime = 8.0e-9;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) > 5.0e-11 );		
		
		/* Below Lower Limit */
		trailingTime = 4.5e-9;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) > 5.0e-11 );			
	}
}

/* test of pulse trailing time dependency */   
void testAttrPulseTrailingTimeDependency()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 trailingTime, readTrailingTime;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}

		/* default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 10) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, 5.0e-9) );
		
		/* pulse trailing time 6.24 */
		trailingTime = 6.24;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, trailingTime) );
		
		/* IVI_VAL_NEVER_CACHE */
		/* change duty cycle to 20% */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 20) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) > 5.0e-11 ); 
		
		/* duty cycle to 50%, change frequency to 50 MHz */
		trailingTime = readTrailingTime;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_DUTY_CYCLE, 50) );
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) > 5.0e-11 ); 
		
		/* change pulse leading time to 7.5 ns */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEADING_TIME, 7.5e-9) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_TRAILING_TIME, &readTrailingTime) );
		CU_ASSERT ( fabs (readTrailingTime-trailingTime) > 5.0e-11 );		
	}
}
 
/*******************************************************
 *
 * Unit Test Code for TKAFG3K_ATTR_PULSE_LEAD_DELAY 
 *	
 *******************************************************/ 

/* TKAFG3K_ATTR_PULSE_LEAD_DELAY depends on:
 *					TKAFG3K_ATTR_PULSE_PERIOD
 *					TKAFG3K_ATTR_FREQUENCY										
 *
 * Attribute Flag:
 *					IVI_VAL_MULTI_CHANNEL 
 *					IVI_VAL_NEVER_CACHE
 *
 * Default Value:
 *					0
 */

/* test of pulse lead delay flag */
void testAttrPulseLeadDelayFlag()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 delay, readDelay;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}	

		/* default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 10) );
		
		/* delay 1s */
		delay = 1;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, delay) );
		
		/* change frequency to 50 MHz */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_FREQUENCY, 0, 50000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, &readDelay) );
		CU_ASSERT ( fabs (readDelay-delay) > 5.0e-11 );
	}
}

/* test of pulse lead delay read and write */
void testAttrPulseLeadDelayReadAndWrite()
{
	ViChar channel[BUFFER_SIZE]; 
	ViInt32 i;
	ViInt32 waveform;
	ViReal64 delay, readDelay;
	
	for(i=0; i<2; i++)
	{
		if(i == 0)
		{
			strncpy(channel, CHAN1, BUFFER_SIZE*sizeof(ViChar));
		}
		else
		{
			strncpy(channel, CHAN2, BUFFER_SIZE*sizeof(ViChar));
		}
	
		/* default setting */
		CU_ASSERT ( VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, channel, TKAFG3K_ATTR_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_PERIOD, 10) );
		
		/* Normal Value */
		delay = 2;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, delay) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, &readDelay) );
		CU_ASSERT ( fabs (readDelay-delay) < 1.0e-5 );
		
		/* Lower Limit */
		delay = 0;
		CU_ASSERT ( VI_SUCCESS == tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, delay) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, &readDelay) );
		CU_ASSERT ( fabs (readDelay-delay) < 1.0e-5 );		
		
		/* Above Upper Limit */
		delay = 10.1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, delay) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, &readDelay) );
		CU_ASSERT ( fabs (readDelay-delay) > 1.0e-5 );		
		
		/* Below Lower Limit */
		delay = -1;
		CU_ASSERT ( VI_SUCCESS != tkafg3k_SetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, delay) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_GetAttributeViReal64 (vi, channel, TKAFG3K_ATTR_PULSE_LEAD_DELAY, &readDelay) );
		CU_ASSERT ( fabs (readDelay-delay) > 1.0e-5 );			
	}
}


/*******************************************************************************************************************
 *
 * 		All Attribute Test Cases 
 *
 *******************************************************************************************************************/
 
/* TKAFG3K_ATTR_WFM_STRUCTURE Test Cases */
CU_TestInfo testArrayForAttrWfmStructure[] = {
  		
  		{ "waveform structure default initialization", 			testAttrWfmStructureDefaultInitialize 				},
  		{ "waveform structure clear arbitrary initialization", 	testAttrWfmStructureClearArbInitialize 				},
		{ "waveform structure in utility functions", 			testAttrWfmStructureUitility 						},
  		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_AMPLITUDE Test Cases */
CU_TestInfo testArrayForAttrAmplitude[] = {

		{ "amplitude flag",  									testAttrAmplitudeFlag 								},
		{ "amplitude read and write in default settings", 		testAttrAmplitudeReadAndWriteDefault				},
		{ "amplitude read and write in INFINITE impedance", 	testAttrAmplitudeReadAndWriteInInfiniteImpedance	},
		{ "amplitude read and write in minimum impedance",		testAttrAmplitudeReadAndWriteInMinimunImpedance		},
		{ "amplitude read and write with random impedance", 	testAttrAmplitudeReadAndWriteInRandomImpedance		},
		{ "amplitude with offset",								testAttrAmplitudeWithOffset							},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_OFFSET Test Cases */
CU_TestInfo testArrayForAttrOffset[] = {

		{ "offset flag", 										testAttrOffsetFlag									},
		{ "offset read and wirte in dafault settings",			testAttrOffsetReadAndWriteDefault					},
		{ "offset read and write in INFINITE impedance",		testAttrOffsetReadAndWriteInInfiniteImpedance		},
		{ "offset read and write in minimum impedance",			testAttrOffsetReadAndWriteInMinimunImpedance		},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FREQUENCY Test Cases */
CU_TestInfo testArrayForAttrFrequency[] = {
   
   		{ "frequency flag",										testAttrFrequencyFlag								},
		{ "frequency read and write",							testAttrFrequencyReadAndWrite						},
		{ "frequency dependency",								testAttrFrequencyDependency							},
		CU_TEST_INFO_NULL,															
};

/* TKAFG3K_ATTR_WAVEFORM Test Cases */
CU_TestInfo testArrayForAttrWaveform[] = {
		{ "waveform flag",										testAttrWaveformFlag								},
		{ "waveform read and write",							testAttrWaveformReadAndWrite						},
		{ "waveform dependency",								testAttrWaveformDependency							},
		{ "waveform and run mode combination",					testAttrWaveformWithRunModeCombination				},
		{ "waveform invalidation",								testAttrWaveformInvalidation						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_ORIGINAL_WAVEFORM Test Cases */
CU_TestInfo testArrayAttrOriginalWaveform[] = {

		{ "original waveform flag",								testAttrOriginalWaveformFlag						},
		{ "original waveform read and write",					testAttrOriginalWaveformReadAndWrite				},
		{ "original waveform dependency",						testAttrOriginalWaveformDependency					},
		CU_TEST_INFO_NULL,
};	

/* TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT Test Cases */
CU_TestInfo testArrayAttrVoltageUpperLimit[] = {

		{ "voltage upper limit flag",							testAttrVoltageUpperLimitFlag						},
		{ "voltage upper limit read and write", 				testAttrVoltageUpperLimitReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT Test Cases */
CU_TestInfo testArrayAttrVoltageLowerLimit[] = {

		{ "voltage lower limit flag",							testAttrVoltageLowerLimitFlag						},
		{ "voltage lower limit read and write",					testAttrVoltageLowerLimitReadAndWrite				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_CONTINUOUS_ENABLED Test Cases */
CU_TestInfo testArrayAttrContinuousEnabled[] = {

		{ "continuous enabled flag",							testAttrContinuousEnabledFlag						},
		{ "continuous enabled read and write",					testAttrContinuousEnabledReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_MODULATION_ENABLED Test Cases */
CU_TestInfo testArrayAttrModulationEnabled[] = {

		{ "modulation enabled flag",							testAttrModulationEnabledFlag						},
		{ "modulation enabled write",							testAttrModulationEnabledWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_SWEEP_ENABLED Test Cases */
CU_TestInfo testArrayAttrSweepEnabled[] = {

		{ "sweep enabled flag",									testAttrSweepEnabledFlag							},
		{ "sweep enabled write",								testAttrSweepEnabledWrite							},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_BURST_ENABLED Test Cases */
CU_TestInfo testArrayAttrBurstEnabled[] = {

		{ "burst enabled flag",									testAttrBurstEnabledFlag							},
		{ "burst enabled write",								testAttrBurstEnabledWrite							},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_ORIGINAL_MODULATION Test Cases */
CU_TestInfo testArrayAttrOriginalModulation[] = {

		{ "original modulation flag",							testAttrOriginalModulationFlag						},
		{ "original modulation read and write",					testAttrOriginalModulationReadAndWrite				},
		{ "original modulation dependency",						testAttrOriginalModulationDependency				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PULSE_WIDTH Test Cases */
CU_TestInfo testArrayAttrPulseWidth[] = {

		{ "pulse width flag",									testAttrPulseWidthFlag								},
		{ "pulse width read",									testAttrPulseWidthRead								},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_CHANNEL_COUNT Test Cases */
CU_TestInfo testArrayAttrChannelCount[] = {

		{ "channel count read",									testAttrChannelCountRead							},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_OUTPUT_MODE Test Cases */
CU_TestInfo testArrayAttrOutputMode[] = {

		{ "output mode flag",									testAttrOutputModeFlag								},
		{ "output mode read and write",							testAttrOutputModeReadAndWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrOutputModeByChannel[] = {

		{ "output mode by channel flag",						testAttrOutputModeByChannelFlag						},
		{ "output mode by channel read and write",				testAttrOutputModeByChannelReadAndWrite				},
		{ "output mode by channel dependency",					testAttrOutputModeByChannelDepenency				},
		CU_TEST_INFO_NULL, 
};

/* TKAFG3K_ATTR_REF_CLOCK_SOURCE Test Case */
CU_TestInfo testArrayAttrReferenceSource[] = {

		{ "reference source read and write",					testAttrReferenceSourceReadAndWrite					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_OUTPUT_ENABLED Test Case */
CU_TestInfo testArrayAttrOutputEnabled[] = {

		{ "output enabled read and write",						testAttrOutputEnabledReadAndWrite					},				
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_OUTPUT_IMPEDANCE Test Cases */
CU_TestInfo testArrayAttrOutputImpedance[] = {

		{ "output impedance read and write",					testAttrOuputImpedanceReadAndWrite					},
		{ "output impedance invalidation",						testAttrOuputImpedanceInvalidation					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_OPERATION_MODE Test Cases */
CU_TestInfo testArrayAttrOperationMode[] = {

		{ "operation mode flag",								testAttrOperationModeFlag							},
		{ "operation mode read and write",						testAttrOperationModeReadAndWrite					},						
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FUNC_WAVEFORM Test Cases */
CU_TestInfo testArrayAttrFuncWaveform[] = {

		{ "func waveform flag",									testAttrFuncWaveformFlag							},
		{ "func waveform read and write",						testAttrFuncWaveformReadAndWrite					},
		{ "func waveform dependency",							testAttrFuncWaveformDependency						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FUNC_AMPLITUDE Test Cases */
CU_TestInfo testArrayAttrFuncAmplitude[] = {
	  	
	  	{ "func amplitude flag",								testAttrFuncAmplitudeFlag							},
	  	{ "func amplitude read and write",						testAttrFuncAmplitudeReadAndWrite					},
	  	{ "func amplitude dependency",							testAttrFuncAmplitudeDependency						},
	  	CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FUNC_DC_OFFSET Test Cases */
CU_TestInfo testArrayAttrFuncDCOffset[] = {

		{ "func dc offset flag",								testAttrFuncDCOffsetFlag							},
		{ "func dc offset read and write",						testAttrFuncDCOffsetReadAndWrite					},
		{ "func dc offset dependency",							testAttrFuncDCOffsetDependency						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FUNC_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrFuncFrequency[] = {
		
		{ "func frequency flag",								testAttrFuncFrequencyFlag							},
		{ "func frequency read and write",						testAttrFuncFrequencyReadAndWrite					},
		{ "func frequency dependency",							testAttrFuncFrequencyDependency						},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_FUNC_START_PHASE Test Cases */
CU_TestInfo testArrayAttrFuncStartPhase[] = {

		{ "func start phase read and write",					testAttrFuncStartPhaseReadAndWrite					},
		{ "func start phase dependency",						testAttrFuncStartPhaseDependency					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FUNC_DUTY_CYCLE_HIGH Test Cases */
CU_TestInfo testArrayAttrFuncDutyCycle[] = {

		{ "func duty cycle default",							testAttrFuncDutyCycleHighDefault					},							
		CU_TEST_INFO_NULL,  
};

/* TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY Test Cases */
CU_TestInfo testArrayAttrFuncRampSymmetry[] = {

		{ "func ramp symmetry read and write",					testAttrFuncRampSymmetryReadAndWrite				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE Test Cases */
CU_TestInfo testArrayAttrArbWaveformHandle[] = {

		{ "arb waveform handle flag",							testAttrArbWaveformHandleFlag						},
		{ "arb waveform handle read and write",					testAttrArbWaveformHandleReadAndWrite				},
		{ "arb waveform handle dependency",						testAttrArbWaveformHandleDependency					},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_ARB_GAIN Test Cases */
CU_TestInfo testArrayAttrArbGain[] = {

		{ "arb gain flag",										testAttrArbGainFlag									},	
		{ "arb gain read and write",							testAttrArbGainReadAndWrite							},
		{ "arb gain dependency",								testAttrArbGainDependency							},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_ARB_OFFSET Test Cases */
CU_TestInfo testArrayAttrArbOffset[] = {

		{ "arb offset flag",									testAttrArbOffsetFlag								},	
		{ "arb offset read and write",							testAttrArbOffsetReadAndWrite						},
		{ "arb offset dependency",								testAttrArbOffsetDependency							},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_ARB_SAMPLE_RATE Test Cases */
CU_TestInfo testArrayAttrArbSampleRate[] = {

		{ "arb sample rate flag",								testAttrArbSampleRateFlag							},								
		{ "arb sample rate read and write",						testAttrArbSampleRateReadAndWrite					},
		{ "arb sample rate dependency",							testAttrArbSampleRateDependency						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_MAX_NUM_WAVEFORMS Test Cases */
CU_TestInfo testArrayAttrMaxNumWaveforms[] = {

		{ "max num waveforms flag",								testAttrMaxNumWaveformsFlagAndDefault				},
		CU_TEST_INFO_NULL, 
};

/* TKAFG3K_ATTR_WAVEFORM_QUANTUM Test Cases */
CU_TestInfo testArrayAttrWaveformQuantum[] = {

		{ "waveform quantum flag and default value",			testAttrWaveformQuantumFlagAndDefault				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_MIN_WAVEFORM_SIZE Test Cases */
CU_TestInfo testArrayAttrMinWaveformSize[] = {

		{ "min waveform size flag and default value",			testAttrMinWaveformSizeFlagAndDefault				},
		CU_TEST_INFO_NULL, 		
};

/* TKAFG3K_ATTR_MAX_WAVEFORM_SIZE Test Cases */
CU_TestInfo testArrayAttrMaxWaveformSize[] = {

		{ "max waveform size flag",								testAttrMaxWaveformSizeFlagAndRead					},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_ARB_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrArbFrequency[] = {

		{ "arb frequency flag",									testAttrArbFrequencyFlag							},
		{ "arb freuqency read and write",						testAttrArbFrequencyReadAndWrite					},
		{ "arb frequency dependency",							testAttrArbFrequencyDependency						},
		CU_TEST_INFO_NULL,	
};

/* TKAFG3K_ATTR_TRIGGER_SOURCE Test Cases */
CU_TestInfo testArrayAttrTriggerSource[] = {

		{ "trigger source read and write",						testAttrTriggerSourceReadAndWrite					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_TRIGGER_MODE Test Cases */
CU_TestInfo testArrayAttrTriggerMode[] = {

		{ "trigger mode read and write",						testAttrTriggerModeReadAndWrite						},						
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_TRIGGER_SLOPE Test Cases */
CU_TestInfo testArrayAttrTriggerSlope[] = {

		{ "trigger slope read and write",						testAttrTriggerSlopeReadAndWrite					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE Test Cases */
CU_TestInfo testArrayAttrInternalTriggerRate[] = {
		
		{ "internal trigger rate read and write",				testAttrInternalTriggerRateReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_BURST_COUNT Test Cases */
CU_TestInfo testArrayAttrBurstCount[] = {

		{ "burst count read and write",							testAttrBurstCountReadAndWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_BURST_MODE Test Cases */
CU_TestInfo testArrayAttrBurstMode[] = {

		{ "burst mode read and write",							testAttrBurstModeReadAndWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_SWEEP_TYPE Test Cases */
CU_TestInfo testArrayAttrSweepType[] = {

		{ "sweep type read and write",							testAttrSweepTypeReadAndWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_SWEEP_MODE Test Cases */
CU_TestInfo testArrayAttrSweepMode[] = {

		{ "sweep mode read and write",							testAttrSweepModeReadAndWrite						},
		CU_TEST_INFO_NULL,  		
};

/* TKAFG3K_ATTR_SWEEP_TIME Test Cases */
CU_TestInfo testArrayAttrSweepTime[] = {

		{ "sweep time read and write",							testAttrSweepTimeReadAndWrite						},
		{ "sweep time dependency",								testAttrSweepTimeDependency							},
		{ "sweep time invalidation",							testAttrSweepTimeInvalidation						},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_SWEEP_HOLD_TIME Test Cases */
CU_TestInfo testArrayAttrSweepHoldTime[] = {
	
		{ "sweep hold time read and write",						testAttrSweepHoldTimeReadAndWrite					},	
		{ "sweep hold time dependency",							testAttrSweepHoldTimeDependency						},
		{ "sweep hold time invalidation",						testAttrSweepHoldTimeInvalidation					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_SWEEP_RETURN_TIME Test Cases */
CU_TestInfo testArrayAttrSweepReturnTime[] = {

		{ "sweep return time read and write",					testAttrSweepReturnTimeReadAndWrite					},
		{ "sweep return time dependency",						testAttrSweepReturnTimeDependency					},
		{ "sweep return time invalidation",						testAttrSweepReturnTimeInvalidation					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_SWEEP_START_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrSweepStartFrequency[] = {

		{ "sweep start frequency read and write",				testAttrSweepStartFrequencyReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrSweepStopFrequency[] = {

		{ "sweep stop frequency read and write",				testAttrSweepStopFrequencyReadAndWrite				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_APPEND_NOISE_ENABLED Test Cases */
CU_TestInfo testArrayAttrAppendNoiseEnabled[] = {

		{ "append noise enabled read and write",				testAttrAppendNoiseEnabledReadAndWrite				},
		{ "append noise enabled association",					testAttrAppendNoiseEnabledAssociation				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_APPEND_NOISE_LEVEL Test Cases */
CU_TestInfo testArrayAttrAppendNoiseLevel[] = {

		{ "append noise level read and write",					testAttrAppendNoiseLevelReadAndWrite				},					
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED Test Cases */
CU_TestInfo testArrayAttrAppendExternalEnabled[] = {

		{ "append external enabled read and write",				testAttrAppendExternalEnabledReadAndWrite			},
		{ "append external enabled read and write in AFG302X",  testAttrAppendExternalEnabledReadAndWriteInAFG302XModel	},
		{ "append external enabled association",				testAttrAppendExternalEnabledAssociation			},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_AM_ENABLED Test Cases */
CU_TestInfo testArrayAttrAMEnabled[] = {

		{ "AM flag",											testAttrAMEnabledFlag								},	
		{ "AM read and write",									testAttrAMEnabledReadAndWrite						},
		{ "AM Dependency",										testAttrAMEnabledDependency							},
		CU_TEST_INFO_NULL,			
};

/* TKAFG3K_ATTR_AM_SOURCE Test Cases */
CU_TestInfo testArrayAttrAMSource[] = {

		{ "AM source read and write",							testAttrAMSourceArrayReadAndWrite					}, 							
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_AM_INTERNAL_DEPTH Test Cases */
CU_TestInfo testArrayAttrAMInternalDepth[] = {

		{ "AM internal depth flag",								testAttrAMInternalDepthFlag							},
		{ "AM internal depth read and write",					testAttrAMInternalDepthReadAndWrite					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM Test Cases */
CU_TestInfo testArrayAttrAMInternalWaveform[] = {

		{ "AM internal waveform flag",							testAttrAMInternalWaveformFlag						},
		{ "AM internal waveform read and write",				testAttrAMInternalWaveformReadAndWrite				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrAMInternalFrequency[] = {

		{ "AM internal frequency flag",							testAttrAMInternalFrequencyFlag						},											
		{ "AM internal frequency read and write",				testAttrAMInternalFrequencyReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrAMDepthByChannel[] = {

		{ "AM depth by channel read and write",					testAttrAMDepthByChannelReadAndWrite				},
		{ "AM depth by channel dependency",						testAttrAMDepthByChannelDependency					},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrAMInternalWaveformByChannel[] = {

		{ "AM internal waveform by channel read and write",		testAttrAMInternalWaveformByChannelReadAndWrite		},
		{ "AM internal waveform by channel dependency",			testAMInternalWaveformByChannelDependency			},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrAMInternalFrequencyByChannel[] = {

		{ "AM internal frequency by channel read and write",	testAttrAMInternalFrequencyByChannelReadAndWrite	},
		{ "AM internal frequency by channel dependency",		testAttrAMInternalFrequencyDependency				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FM_ENABLED Test Cases */
CU_TestInfo testArrayAttrFMEnabled[] = {

		{ "FM enabled flag",									testAttrFMEnabledFlag								},
		{ "FM enabled read and write",							testAttrFMEnabledReadAndWrite						},
		{ "FM enabled dependency",								testAttrFMEnabledDependency							},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FM_SOURCE Test Cases */
CU_TestInfo testArrayAttrFMSource[] = {

		{ "FM source read and write",							testAttrFMSourceReadAndWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FM_INTERNAL_DEVIATION Test Cases */
CU_TestInfo testArrayAttrFMInternalDeviation[] = {

		{ "FM internal deviation flag",							testAttrFMInternalDeviationFlag						},	
		{ "FM internal deviation read and write",				testAttrFMInternalDeviationReadAndWrite				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM Test Cases */
CU_TestInfo testArrayAttrFMInternalWaveform[] = {

		{ "FM internal waveform flag",							testAttrFMInternalWaveformFlag						},
		{ "FM internal waveform read and write",				testAttrFMInternalWaveformReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrFMInternalFrequency[] = {
		
		{ "FM internal frequency flag",							testAttrFMInternalFrequencyFlag						},
		{ "FM internal frequency read and write",				testAttrFMInternalFrequencyReadAndWrite				},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrFMDeviationByChannel[] = {
						  
		{ "FM deviation by channel read and write",				testAttrFMDeviationByChannelReadAndWrite			},
		{ "FM deviation by channel dependency",					testAttrFMDeviationByChannelDependency				},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrFMInternalWaveformByChannel[] = {

		{ "FM internal waveform by channel read and write",		testAttrFMInternalWaveformByChannelReadAndWrite		},	
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrFMInternalFrequencyByChannel[] = {

		{ "FM internal frequency by channel read and write",	testAttrFMInternalFrequencyByChannelReadAndWrite	},	
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_FSK_ENABLED Test Cases */
CU_TestInfo testArrayAttrFSKEnabled[] = {

		{ "FSK enabled flag",									testAttrFSKEnabledFlag								},	
		{ "FSK enabled read and write",							testAttrFSKEnabledReadAndWrite						},
		{ "FSK enabled dependency",								testAttrFSKEnabledDependency						},
		CU_TEST_INFO_NULL, 
};

/* TKAFG3K_ATTR_FSK_SOURCE Test Cases */
CU_TestInfo testArrayAttrFSKSource[] = {

		{ "FSK source read and write",							testAttrFSKSourceReadAndWrite						},							
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_FSK_HOP_FREQUENCY Test Cases */
CU_TestInfo testArrayAttrFSKHopFrequency[] = {

		{ "FSK hop frequency read and write",					testAttrFSHHopFrequencyReadAndWrite					},
		CU_TEST_INFO_NULL,			
};

/* TKAFG3K_ATTR_FSK_INTERNAL_RATE Test Cases */
CU_TestInfo testArrayAttrFSKInternalRate[] = {

		{ "FSK internal rate read and write",					testAttrFSKInternalRateReadAndWrite					},					
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PM_ENABLED Test Cases */
CU_TestInfo testArrayAttrPMEnabled[] = {

		{ "PM enabled flag",									testAttrPMEnabledFlag								},	
		{ "PM enabled read and write",							testAttrPMEnabledReadAndWrite						},
		{ "PM enabled dependency",								testAttrPMEnabledDependency							},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_PM_SOURCE Test Cases */
CU_TestInfo testArrayAttrPMSource[] = {

		{ "PM source read and write",							testAttrPMSourceReadAndWrite						},							
		CU_TEST_INFO_NULL,	
};

/* TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrPMDeviationByChannel[] = {

		{ "PM deviation by channel read and write",				testAttrPMDeviationByChannelReadAndWrite			},							
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrPMInternalFrequencyByChannel[] = {

		{ "PM internal frequency by channel read and write",	testAttrPMInternalFrequencyByChannelReadAndWrite	},	
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL Test Cases */
CU_TestInfo testArrayAttrPMInternalWaveformByChannel[] = {

		{ "PM internal waveform by channel read and write",		testAttrPMInternalWaveformByChannelReadAndWrite		},	
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_PWM_ENABLED Test Cases */
CU_TestInfo testArrayAttrPWMEnabled[] = {


		{ "PWM enabled flag",									testAttrPWMEnabledFlag								},
		{ "PWM enabled read and write",							testAttrPWMEnabledReadAndWrite						},
		{ "PWM enabled dependency",								testAttrPWMEnabledDependency						},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_PWM_SOURCE Test Cases */
CU_TestInfo testArrayAttrPWMSource[] = {

		{ "PWM source read and write",							testAttrPWMSourceReadAndWrite						},							
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PWM_DEVIATION Test Cases */
CU_TestInfo testArrayAttrPWMDeviation[] = {

		{ "PWM deviation flag",									testAttrPWMDeviationFlag							},								
		{ "PWM deviation read and write",						testAttrPWMDeviationReadAndWrite					},
		CU_TEST_INFO_NULL,	
};

/* TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM Test Cases */
CU_TestInfo testArrayAttrPWMInternalWaveform[] = {

		{ "PWM internal waveform read and write",				testAttrPWMInternalWaveformReadAndWrite				},				
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PULSE_PERIOD Test Cases */
CU_TestInfo testArrayAttrPulsePeriod[] = {

		{ "pulse period flag",									testAttrPulsePeriodFlag								},
		{ "pulse period read and write",						testAttrPulsePeriodReadAndWrite						},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PULSE_DUTY_CYCLE Test Cases */
CU_TestInfo testArrayAttrPulseDutyCycle[] = {

		{ "pulse duty cycle flag",								testAttrPulseDutyCycleFlag							},
		{ "pulse duty cycle read and write",					testAttrPulseDutyCycleReadAndWrite					},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_PULSE_LEADING_TIME Test Cases */
CU_TestInfo testArrayAttrPulseLeadingTime[] = {

		{ "pulse leading time flag",							testAttrPulseLeadingTimeFlag						},
		{ "pulse leading time read and write",					testAttrPulseLeadingTimeReadAndWrite				},
		{ "pulse leading time dependency",						testAttrPulseLeadingTimeDependency					},
		CU_TEST_INFO_NULL,		
};

/* TKAFG3K_ATTR_PULSE_TRAILING_TIME Test Cases */
CU_TestInfo testArrayAttrPulseTrailingTime[] = {

		{ "pulse trailing time flag",							testAttrPulseTrailingTimeFlag						},
		{ "pulse trailing time read and write",					testAttrPulseTrailingTimeReadAndWrite				}, 
		{ "pulse trailing time dependency",						testAttrPulseTrailingTimeDependency					},
		CU_TEST_INFO_NULL,
};

/* TKAFG3K_ATTR_PULSE_LEAD_DELAY Test Cases */
CU_TestInfo testArrayAttrPulseLeadDelay[] = {

		{ "pulse lead delay flag",								testAttrPulseLeadDelayFlag							},							
		{ "pulse lead delay read and write",					testAttrPulseLeadDelayReadAndWrite					},
		CU_TEST_INFO_NULL,	
};

/* ALL Test Suites */
CU_SuiteInfo attributeSuites[] = {
  		
//	  	{ "TKAFG3K_ATTR_WFM_STRUCTURE test suite", 						NULL, NULL, testArrayForAttrWfmStructure 				},
		// Test For Amplitude And Offset are aborted for uncertain updated formula used to decide 
		// Maximum value for amplitude and offset.						
//	  	{ "TKAFG3K_ATTR_AMPLITUDE test suite", 							NULL, NULL, testArrayForAttrAmplitude 					},
//		{ "TKAFG3K_ATTR_OFFSET test suite",								NULL, NULL, testArrayForAttrOffset						},
//		{ "TKAFG3K_ATTR_FREQUENCY test suite", 							NULL, NULL, testArrayForAttrFrequency					},
//		{ "TKAFG3K_ATTR_WAVEFORM test suite",							NULL, NULL, testArrayForAttrWaveform					},
//		{ "TKAFG3K_ATTR_ORIGINAL_WAVEFORM test suite", 					NULL, NULL, testArrayAttrOriginalWaveform				},
//		{ "TKAFG3K_ATTR_VOLTAGE_UPPER_LIMIT test suite",				NULL, NULL, testArrayAttrVoltageUpperLimit				}, 
//		{ "TKAFG3K_ATTR_VOLTAGE_LOWER_LIMIT test suite",				NULL, NULL, testArrayAttrVoltageLowerLimit				},
//		{ "TKAFG3K_ATTR_CONTINUOUS_ENABLED test suite", 				NULL, NULL, testArrayAttrContinuousEnabled  			},
//		{ "TKAFG3K_ATTR_MODULATION_ENABLED test suite", 				NULL, NULL, testArrayAttrModulationEnabled				},
//		{ "TKAFG3K_ATTR_SWEEP_ENABLED test suite",						NULL, NULL, testArrayAttrSweepEnabled					},
//		{ "TKAFG3K_ATTR_BURST_ENABLED test suite",						NULL, NULL, testArrayAttrBurstEnabled					},
//		{ "TKAFG3K_ATTR_ORIGINAL_MODULATION test suite",    			NULL, NULL, testArrayAttrOriginalModulation				},
//		{ "TKAFG3K_ATTR_PULSE_WIDTH test suite",						NULL, NULL, testArrayAttrPulseWidth						},
//		{ "TKAFG3K_ATTR_CHANNEL_COUNT test suite",						NULL, NULL, testArrayAttrChannelCount					},
//		{ "TKAFG3K_ATTR_OUTPUT_MODE test suite",						NULL, NULL, testArrayAttrOutputMode						},
//		{ "TKAFG3K_ATTR_OUTPUT_MODE_BY_CHANNEL test suite",				NULL, NULL, testArrayAttrOutputModeByChannel			},
//		{ "TKAFG3K_ATTR_REF_CLOCK_SOURCE test suite",					NULL, NULL, testArrayAttrReferenceSource				},
//		{ "TKAFG3K_ATTR_OUTPUT_ENABLED test suite",						NULL, NULL, testArrayAttrOutputEnabled					},
//		{ "TKAFG3K_ATTR_OUTPUT_IMPEDANCE test suite",					NULL, NULL, testArrayAttrOutputImpedance				},
//		{ "TKAFG3K_ATTR_OPERATION_MODE test suite",						NULL, NULL, testArrayAttrOperationMode					},
//		{ "TKAFG3K_ATTR_FUNC_WAVEFORM test suite",						NULL, NULL, testArrayAttrFuncWaveform					},
//		{ "TKAFG3K_ATTR_FUNC_AMPLITUDE test suite",						NULL, NULL, testArrayAttrFuncAmplitude					},
//		{ "TKAFG3K_ATTR_FUNC_DC_OFFSET test suite",						NULL, NULL, testArrayAttrFuncDCOffset					},
//		{ "TKAFG3K_ATTR_FUNC_FREQUENCY test suite",						NULL, NULL, testArrayAttrFuncFrequency					},
//		{ "TKAFG3K_ATTR_FUNC_START_PHASE test suite",					NULL, NULL, testArrayAttrFuncStartPhase					},
//		{ "TKAFG3K_ATTR_FUNC_DUTY_CYCLE_HIGH test suite",				NULL, NULL, testArrayAttrFuncDutyCycle					},
//		{ "TKAFG3K_ATTR_FUNC_RAMP_SYMMETRY test suite",					NULL, NULL, testArrayAttrFuncRampSymmetry				},
//		{ "TKAFG3K_ATTR_ARB_WAVEFORM_HANDLE test suite",				NULL, NULL, testArrayAttrArbWaveformHandle				},
//		{ "TKAFG3K_ATTR_ARB_GAIN test suite",							NULL, NULL, testArrayAttrArbGain						},
//		{ "TKAFG3K_ATTR_ARB_OFFSET test suite",							NULL, NULL, testArrayAttrArbOffset						},
//		{ "TKAFG3K_ATTR_ARB_SAMPLE_RATE test suite",					NULL, NULL, testArrayAttrArbSampleRate					},
//		{ "TKAFG3K_ATTR_MAX_NUM_WAVEFORMS test suite",					NULL, NULL, testArrayAttrMaxNumWaveforms				},
//		{ "TKAFG3K_ATTR_WAVEFORM_QUANTUM test suite",					NULL, NULL, testArrayAttrWaveformQuantum				},
//		{ "TKAFG3K_ATTR_MIN_WAVEFORM_SIZE test suite",					NULL, NULL, testArrayAttrMinWaveformSize				},
//		{ "TKAFG3K_ATTR_MAX_WAVEFORM_SIZE test suite",					NULL, NULL, testArrayAttrMaxWaveformSize				},
//		{ "TKAFG3K_ATTR_ARB_FREQUENCY test suite",						NULL, NULL, testArrayAttrArbFrequency					},
//		{ "TKAFG3K_ATTR_TRIGGER_SOURCE test suite",						NULL, NULL, testArrayAttrTriggerSource					},
//		{ "TKAFG3K_ATTR_TRIGGER_MODE test suite",						NULL, NULL, testArrayAttrTriggerMode					},
//		{ "TKAFG3K_ATTR_TRIGGER_SLOPE test suite",						NULL, NULL, testArrayAttrTriggerSlope					},
//		{ "TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE test suite",				NULL, NULL, testArrayAttrInternalTriggerRate			},
//		{ "TKAFG3K_ATTR_BURST_COUNT test suite",						NULL, NULL, testArrayAttrBurstCount						},
//		{ "TKAFG3K_ATTR_BURST_MODE test suite",							NULL, NULL, testArrayAttrBurstMode						},
//		{ "TKAFG3K_ATTR_SWEEP_TYPE test suite",							NULL, NULL, testArrayAttrSweepType						},
//		{ "TKAFG3K_ATTR_SWEEP_MODE test suite",							NULL, NULL, testArrayAttrSweepMode						},
//		{ "TKAFG3K_ATTR_SWEEP_TIME test suite",							NULL, NULL, testArrayAttrSweepTime						},
//		{ "TKAFG3K_ATTR_SWEEP_HOLD_TIME test suite",					NULL, NULL, testArrayAttrSweepHoldTime					},
//		{ "TKAFG3K_ATTR_SWEEP_RETURN_TIME test suite",					NULL, NULL, testArrayAttrSweepReturnTime				},
//		{ "TKAFG3K_ATTR_SWEEP_START_FREQUENCY test suite",				NULL, NULL, testArrayAttrSweepStartFrequency			},
//		{ "TKAFG3K_ATTR_SWEEP_STOP_FREQUENCY test suite",				NULL, NULL, testArrayAttrSweepStopFrequency				},
//		{ "TKAFG3K_ATTR_APPEND_NOISE_ENABLED test suite",				NULL, NULL, testArrayAttrAppendNoiseEnabled				},
//		{ "TKAFG3K_ATTR_APPEND_NOISE_LEVEL test suite",					NULL, NULL, testArrayAttrAppendNoiseLevel				},
//		{ "TKAFG3K_ATTR_APPEND_EXTERNAL_ENABLED test suite",			NULL, NULL, testArrayAttrAppendExternalEnabled			},
//		{ "TKAFG3K_ATTR_AM_ENABLED test suite",							NULL, NULL, testArrayAttrAMEnabled						},
//		{ "TKAFG3K_ATTR_AM_SOURCE test suite",							NULL, NULL, testArrayAttrAMSource						},
//		{ "TKAFG3K_ATTR_AM_INTERNAL_DEPTH test suite",					NULL, NULL, testArrayAttrAMInternalDepth				},
//		{ "TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM test suite",				NULL, NULL, testArrayAttrAMInternalWaveform				},
//		{ "TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY test suite",				NULL, NULL, testArrayAttrAMInternalFrequency			},
//		{ "TKAFG3K_ATTR_AM_DEPTH_BY_CHANNEL test suite",				NULL, NULL, testArrayAttrAMDepthByChannel				},
//		{ "TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL test suite",	NULL, NULL, testArrayAttrAMInternalWaveformByChannel	},
//		{ "TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL test suite",   NULL, NULL, testArrayAttrAMInternalFrequencyByChannel	},
//		{ "TKAFG3K_ATTR_FM_ENABLED test suite",							NULL, NULL, testArrayAttrFMEnabled						},  		
//		{ "TKAFG3K_ATTR_FM_SOURCE test suite",							NULL, NULL, testArrayAttrFMSource						},
//		{ "TKAFG3K_ATTR_FM_INTERNAL_DEVIATION test suite",				NULL, NULL, testArrayAttrFMInternalDeviation			},
//		{ "TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM test suite",				NULL, NULL, testArrayAttrFMInternalWaveform				},
//		{ "TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY test suite",				NULL, NULL, testArrayAttrFMInternalFrequency			},
// 		{ "TKAFG3K_ATTR_FM_DEVIATION_BY_CHANNEL test suite",			NULL, NULL, testArrayAttrFMDeviationByChannel			},
// 		{ "TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL test suite",	NULL, NULL, testArrayAttrFMInternalWaveformByChannel	},
//		{ "TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL test suite",	NULL, NULL, testArrayAttrFMInternalFrequencyByChannel	},
//		{ "TKAFG3K_ATTR_FSK_ENABLED test suite",						NULL, NULL, testArrayAttrFSKEnabled						},
//		{ "TKAFG3K_ATTR_FSK_SOURCE test suite",							NULL, NULL, testArrayAttrFSKSource						},
//		{ "TKAFG3K_ATTR_FSK_HOP_FREQUENCY test suite",					NULL, NULL, testArrayAttrFSKHopFrequency				},
//		{ "TKAFG3K_ATTR_FSK_INTERNAL_RATE test suite",					NULL, NULL, testArrayAttrFSKInternalRate				},
// 		{ "TKAFG3K_ATTR_PM_ENABLED test suite",							NULL, NULL, testArrayAttrPMEnabled						},
// 		{ "TKAFG3K_ATTR_PM_SOURCE test suite",							NULL, NULL, testArrayAttrPMSource						},
// 		{ "TKAFG3K_ATTR_PM_DEVIATION_BY_CHANNEL test suite",			NULL, NULL, testArrayAttrPMDeviationByChannel			},
// 		{ "TKAFG3K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL test suite",	NULL, NULL, testArrayAttrPMInternalFrequencyByChannel	},
//		{ "TKAFG3K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL test suite",	NULL, NULL, testArrayAttrPMInternalWaveformByChannel	},
//		{ "TKAFG3K_ATTR_PWM_ENABLED test suite",						NULL, NULL, testArrayAttrPWMEnabled						},
// 		{ "TKAFG3K_ATTR_PWM_SOURCE test suite",							NULL, NULL, testArrayAttrPWMSource						},
// 		{ "TKAFG3K_ATTR_PWM_DEVIATION test suite",						NULL, NULL, testArrayAttrPWMDeviation					},
//		{ "TKAFG3K_ATTR_PWM_INTERNAL_WAVEFORM test suite",				NULL, NULL, testArrayAttrPWMInternalWaveform			},
//		{ "TKAFG3K_ATTR_PULSE_PERIOD test suite",						NULL, NULL, testArrayAttrPulsePeriod					},
// 		{ "TKAFG3K_ATTR_PULSE_DUTY_CYCLE test suite",					NULL, NULL, testArrayAttrPulseDutyCycle					},
// 		{ "TKAFG3K_ATTR_PULSE_LEADING_TIME test suite",					NULL, NULL, testArrayAttrPulseLeadingTime				},
// 		{ "TKAFG3K_ATTR_PULSE_TRAILING_TIME test suite",				NULL, NULL, testArrayAttrPulseTrailingTime				},
// 		{ "TKAFG3K_ATTR_PULSE_LEAD_DELAY test suite",					NULL, NULL, testArrayAttrPulseLeadDelay					},
  		CU_SUITE_INFO_NULL,
};

/******************************************************
 *
 * Test Environment Initialization && Cleanup
 *
 ******************************************************/
void testInit()
{								    
	// GPIB
	// tkafg3k_init ("GPIB0::11::INSTR", VI_TRUE, VI_TRUE, &vi); 
 	
 	// USB
 	tkafg3k_init ("USB0::0x0699::0x0343::Ja8::INSTR", VI_TRUE, VI_TRUE, &vi); 
}

void testClose()
{
 	tkafg3k_close(vi); 	
 	vi = VI_NULL;
}

main()
{
	CU_pSuite pSuite = NULL;
	CU_pTest  pTest = NULL;
	char lock;
	
   	/* initialize the CUnit test registry */
   	if (CUE_SUCCESS != CU_initialize_registry())
      	return CU_get_error();

   	/* add a suite to the registry */
   	if(CUE_SUCCESS != CU_register_suites(attributeSuites))
   	{
      	CU_cleanup_registry();
      	return CU_get_error();   		
   	}

   	/* Run all tests using the CUnit Basic interface */
   	CU_basic_set_mode(CU_BRM_VERBOSE);

	testInit();
	
   	CU_basic_run_tests();
    
    testClose();
    
   	scanf("%c", &lock);
   
   	CU_cleanup_registry();
   	return CU_get_error();
}
