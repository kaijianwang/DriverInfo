/*****************************************************************************
 *  Function Test Code for
 *  Tektronics AFG3000 Series Arbitrary Funtion Generator Instrument Driver         
 *  LabWindows/CVI Instrument Driver                                     
 *  By: Penar Zhu, National Instruments                              
 *      PH. 86-21-65557838   Fax 86-21-65556244                              
 *                                                                           
 *  Modification History:                                                    
 *
 *  	 Thursday, July 8, 2005 - Created. 
 *                                                                           
 *****************************************************************************/

#include <ansi_c.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CUnit.h"
#include "Basic.h"

#include "tkafg3k.c" 

/* Global Variable */
ViSession vi = VI_NULL;

/*************************************************************************************
 *
 * Unit Test Code for Basic Instrument Operation And Standard Waveform 
 *	
 *************************************************************************************/ 

/* Basic Instrument Operation Function:
 *		
 *		tkafg3k_ConfigureOperationMode (ViSession vi, ViConstString channelName, ViInt32 outputMode);
 *		tkafg3k_ConfigureOutputMode (ViSession vi, ViInt32 outputMode);
 *		tkafg3k_ConfigureOutputModeByChannel (ViSession vi, ViConstString channelName, ViInt32 outputMode );
 *		tkafg3k_ConfigureRefClockSource (ViSession vi, ViInt32 refClockSource);
 *		tkafg3k_ConfigureOutputImpedance (ViSession vi, ViConstString channelName, ViReal64 outputImpedance);
 *		tkafg3k_ConfigureOutputEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_InitiateGeneration (ViSession vi);
 *		tkafg3k_AbortGeneration (ViSession vi);
 *
 * Standard Waveform Function:
 *
 *		tkafg3k_ConfigureStandardWaveform (ViSession vi, ViConstString channelName, ViInt32 waveform,
 *                                          ViReal64 amplitude, ViReal64 dcOffset, ViReal64 frequency, ViReal64 startPhase);
 *		tkafg3k_ConfigureRampSymmetry (ViSession vi, ViConstString channelName, ViReal64 rampSymmetry);
 *		tkafg3k_ConfigurePulseWaveform (ViSession vi, ViConstString channelName, ViReal64 period, ViReal64 dutyCycle,
 *											ViReal64 leadingEdgeTime, ViReal64 trailingEdgeTime);
 *		tkafg3k_ConfigurePulseDelay (ViSession vi, ViConstString channelName, ViReal64 delay);
 */

/* test of basic instrument operation and standard waveform default */ 
void testFuncBasicInstrumentOperationAndStandardWaveformDefault()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50 Ohm
						Waveform:				SINE
						Amplitude:				10
						Offset:					5
						Frequency:				100000000
						Start Phase:			0
		 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of basic instrument operation and standard waveform case1 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
	
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50 Ohm	
						Waveform:				RAMP
						Amplitude:				10
						Offset:					5
						Frequency:				1000000
						Start Phase:			0	
						Ramp Symmetry:			10%
		 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_RAMP, 10, 5, 1000000, 0) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRampSymmetry (vi, channel, 10) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of basic instrument operation and standard waveform case2 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase2()  
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50 Ohm	
						Waveform:				PULSE
						Amplitude:				10
						Offset:					5
						Frequency:				50000000
						Start Phase:			0	
						Duty Cycle:				50%
						Leading Edge Time:		6 ns
						Trailing Edge Time:		6 ns
						Pulse Delay:			0
		 */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PULS, 10, 5, 50000000, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePulseWaveform (vi, channel, 50, 6.0e-9, 6.0e-9) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePulseDelay (vi, channel, 0) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}		
}		

/* test of basic instrument operation and standard waveform case3 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase3()  
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );

		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				INFINITE
						Waveform:				SQUARE
						Amplitude:				20
						Offset:					0
						Frequency:				50000000 						
						Start Phase:			180
		 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, TKAFG3K_VAL_IMPEDANCE_INFINITY) ); 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SQUARE, 20, 0, 50000000, 180) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 	
	}
}

/* test of basic instrument operation and standard waveform case4 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase4()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				1 Ohm
						Waveform:				TKAFG3K_VAL_WFM_SINC
						Amplitude:				0.375
						Offset:					0
						Frequency:				1000000
						Start Phase:			90
		 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 1) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINC, 0.375, 0, 1000000, 90) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 	
	}		
}

/* test of basic instrument operation and standard waveform case5 */  
void testFuncBasicInstrumentOperationAndStandardWaveformCase5()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
	
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				INFINITY
						Waveform:				TKAFG3K_VAL_WFM_PRN
						Amplitude:				2
						Offset:					8
						Frequency:				1000000
						Start Phase:			0
		*/
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, TKAFG3K_VAL_IMPEDANCE_INFINITY) ); 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PRN, 2, 8, 1000000, 0) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 	
	}
}

/* test of basic instrument operation and standard waveform case6 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase6()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50 Ohm
						Waveform:				TKAFG3K_VAL_WFM_SINC
						Amplitude:				10
						Offset:					0
						Frequency:				0.001
						Start Phase:			0 
		*/
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINC, 10, 0, 0.001, 0) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of basic instrument operation and standard waveform case7 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase7()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
	
		/* Data:
						Clock:					Internal 
						Operation Mode:			TKAFG3K_VAL_OPERATE_MODULATION
						Impedance:				50 Ohm
						Waveform:				TKAFG3K_VAL_WFM_GAUS
						Amplitude:				10
						Offset:					0
						Frequency:				1000000
						Start Phase:			0 	
		*/
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );		

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_GAUS, 10, 0, 1000000, 0) );		
	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_MODULATION) ); 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of basic instrument operation and standard waveform case8 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase8()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
						Clock:					Internal
						Operation Mode:			TKAFG3K_VAL_OPERATE_SWEEP
						Impedance:				50 Ohm 
						Waveform:				TKAFG3K_VAL_WFM_LOR
						Amplitude:				10
						Offset:					0
						Frequency:				1000000
						Start Phase:			0
		*/
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_LOR, 10, 0, 1000000, 0) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_SWEEP) ); 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of basic instrument operation and standard waveform case9 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase9()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
						Clock:					Internal
						Operation Mode:			TKAFG3K_VAL_OPERATE_BURST
						Impedance:				50 Ohm 
						Waveform:				TKAFG3K_VAL_WFM_ERIS
						Amplitude:				10
						Offset:					0
						Frequency:				1000000
						Start Phase:			0
		*/
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS ==  tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_ERIS, 10, 0, 1000000, 0) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_BURST) ); 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of basic instrument operation and standard waveform case10 */
void testFuncBasicInstrumentOperationAndStandardWaveformCase10()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );		

		/* Data:
						Clock:					Internal
						Operation Mode:			TKAFG3K_VAL_OPERATE_CONTINUOUS
						Impedance:				50 Ohm 
						Waveform:				TKAFG3K_VAL_WFM_EDEC
						Amplitude:				10
						Offset:					-5
						Frequency:				1000000
						Start Phase:			0
		*/		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS ==  tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_EDEC, 10, -5, 1000000, 0) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/* test of basic instrument operation and standard waveform case11 */ 
void testFuncBasicInstrumentOperationAndStandardWaveformCase11()
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

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
						Clock:					Internal
						Operation Mode:			TKAFG3K_VAL_OPERATE_CONTINUOUS
						Impedance:				50 Ohm 
						Waveform:				TKAFG3K_VAL_WFM_HAV
						Amplitude:				10 
						Offset:					0
						Frequency:				1000000
						Start Phase:			0
		*/
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS ==  tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_HAV, 10, -5, 1000000, 0) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 	
	}
}

/*************************************************************************************
 *
 * Unit Test Code for Basic Instrument Operation And Arbitrary Waveform 
 *	
 *************************************************************************************/
/* arbitrary waveform suite intialization */
int testArbWfmInit()
{
 	ViStatus result;
 	
 	tkafg3k_close(vi); 
 	vi = VI_NULL;
 	
 	// GPIB
 	// result = tkafg3k_InitWithOptions ("GPIB0::11::INSTR", VI_TRUE, VI_TRUE, "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1,DriverSetup=Model AFG3102 and ClearArbData is 1", &vi); 
 	
 	// USB
 	result = tkafg3k_InitWithOptions (	"USB0::0x0699::0x0343::Ja8::INSTR", 
 										VI_TRUE, VI_TRUE,
 										"Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1,DriverSetup=Model AFG3102 and ClearArbData is 1",
 										&vi);
 										
 	if(result == VI_SUCCESS)
 		return 0;
 		
 	return 1;
}

/* Basic Instrument Operation Function:
 *
 *		tkafg3k_ConfigureOperationMode (ViSession vi, ViConstString channelName, ViInt32 outputMode);
 *		tkafg3k_ConfigureOutputMode (ViSession vi, ViInt32 outputMode);
 *		tkafg3k_ConfigureOutputModeByChannel (ViSession vi, ViConstString channelName, ViInt32 outputMode );
 *		tkafg3k_ConfigureRefClockSource (ViSession vi, ViInt32 refClockSource);
 *		tkafg3k_ConfigureOutputImpedance (ViSession vi, ViConstString channelName, ViReal64 outputImpedance);
 *		tkafg3k_ConfigureOutputEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_InitiateGeneration (ViSession vi);
 *		tkafg3k_AbortGeneration (ViSession vi);
 *
 * Arbitrary Waveform Function:
 *
 *		tkafg3k_QueryArbWfmCapabilities (ViSession vi, ViInt32 *maxNumWfms, ViInt32 *wfmQuantum, ViInt32 *minWfmSize, ViInt32 *maxWfmSize);
 *		tkafg3k_CreateArbWaveform (ViSession vi, ViInt32 wfmSize, ViReal64 wfmData[], ViInt32 *wfmHandle);
 *		tkafg3k_CreateLineInterpolateArbWfm (ViSession vi, ViInt32 wfmSize, ViReal64 startPointData, ViReal64 endPointData, ViInt32* wfmHandle);
 *		tkafg3k_CreateStandardShapeArbWfm (ViSession vi, ViInt32 wfmSize, ViInt32 wfmType, ViInt32 *wfmHandle);
 *		tkafg3k_ConfigureSampleRate (ViSession vi, ViReal64 sampleRate);
 *		tkafg3k_ConfigureArbWaveform (ViSession vi, ViConstString channelName, ViInt32 wfmHandle, ViReal64 arbGain, ViReal64 arbOffset);
 *		tkafg3k_ClearArbWaveform (ViSession vi, ViInt32 wfmHandle);
 *		tkafg3k_ConfigureArbFrequency (ViSession vi, ViConstString channelName, ViReal64 arbFrequency);
 */
 
#define TEST_ARBITRARY_WAVEFORM_DATA_SIZE			120  

static ViReal64 arbWfmData1[TEST_ARBITRARY_WAVEFORM_DATA_SIZE] = { 	
	-0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 
	0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0, 0, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8, -0.9,
	-0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 
	0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0, 0, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8, -0.9,
	-0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,  
	0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0, 0, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8, -0.9, 
};

static ViReal64 arbWfmData2[TEST_ARBITRARY_WAVEFORM_DATA_SIZE] = {
	-0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
	0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9,
	0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 
	0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 
	0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 
	0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0, 0, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8, -0.9, 
};

static ViReal64 arbWfmData3[TEST_ARBITRARY_WAVEFORM_DATA_SIZE] = {
	0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0, 0, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8, -0.9,
	-0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9,
	-0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9,
    -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9,
	-0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9,
   -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
};

static ViReal64 arbWfmData4[TEST_ARBITRARY_WAVEFORM_DATA_SIZE] = {
	-0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0, 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9,
	0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9,
	0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9, 0.9,
	0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0, 0, -0.1, -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8, -0.9, 
    -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9,
	-0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9, -0.9,
};

/* test of create and clear arbitrary waveform case1 */
/* prerequisite:
			Clear All Arbitrary Waveform in instrument 
 */ 
void testFuncCreateAndClearArbitraryWaveformCase1()
{
	ViInt32 wfmHandle;
	
	CU_ASSERT ( 0 == testArbWfmInit() );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle) );								

	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData2, &wfmHandle) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData3, &wfmHandle) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData4, &wfmHandle) );	
}

/* test of create and clear arbitrary waveform case2 */
void testFuncCreateAndClearArbitraryWaveformCase2()
{
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4; 	

	CU_ASSERT ( 0 == testArbWfmInit() ); 
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) );								
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData2, &wfmHandle2) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData3, &wfmHandle3) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData4, &wfmHandle4) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ClearArbWaveform (vi, wfmHandle2) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ClearArbWaveform (vi, wfmHandle3) ); 
}

/* test of create and clear arbitrary waveform case3 */
void testFuncCreateAndClearArbitraryWaveformCase3()
{
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4; 	

	CU_ASSERT ( 0 == testArbWfmInit() ); 
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) );								
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData2, &wfmHandle2) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData3, &wfmHandle3) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData4, &wfmHandle4) );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ClearArbWaveform (vi, wfmHandle1) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ClearArbWaveform (vi, wfmHandle2) );	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle1) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, 0.9, -0.9, &wfmHandle2) );
}

/* test of create and clear arbitrary waveform case4 */
ViInt32 testStandardArbitraryWaveform[] = {
							TKAFG3K_VAL_ARB_WFM_SINE,
							TKAFG3K_VAL_ARB_WFM_SQUARE,
							TKAFG3K_VAL_ARB_WFM_PULS,
							TKAFG3K_VAL_ARB_WFM_RAMP,
							TKAFG3K_VAL_ARB_WFM_PRN,
};

#define TEST_STANDARD_ARBITRARY_WAVEFORM_QUANTUM			5

void testFuncCreateAndClearArbitraryWaveformCase4()
{
	ViInt32 wfmHandle[4]; 	
	ViInt32 waveform;
	ViInt32 j;

	CU_ASSERT ( 0 == testArbWfmInit() );  
	
	for(j=0; j<4; j++)
	{
		waveform = testStandardArbitraryWaveform[j];
		CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, waveform, wfmHandle+j) );
	}
}

/* test of create and clear arbitrary waveform case5 */
void testFuncCreateAndClearArbitraryWaveformCase5()
{
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4; 
	
	CU_ASSERT ( 0 == testArbWfmInit() );    
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) );	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_RAMP, &wfmHandle3) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_PRN, &wfmHandle4) );	
	
	/* Clear all waveforms */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ClearArbWaveform (vi, TKAFG3K_VAL_ALL_WAVEFORMS) );
}

/* test of basic instrument operation and arbitrary waveform case1 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase1()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		CU_ASSERT ( 0 == testArbWfmInit() );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50 Ohm	
						Waveform:				TKAFG3K_VAL_WFM_USER1
						arbGain:				5
						Offset:					5
						Frequency:				50000000
		 */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );		
	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/* test of basic instrument operation and arbitrary waveform case2 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase2()  
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;

	CU_ASSERT ( 0 == testArbWfmInit() ); 	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );

		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				INFINITY	
						Waveform:				TKAFG3K_VAL_WFM_USER1
						arbGain:				10
						Offset:					0
						Frequency:				50000000
		 */	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, TKAFG3K_VAL_IMPEDANCE_INFINITY) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 10, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}		
}

/* test of basic instrument operation and arbitrary waveform case3 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase3()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1, wfmHandle2;
	
	CU_ASSERT ( 0 == testArbWfmInit() ); 
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) );	
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				1	
						Waveform:				TKAFG3K_VAL_WFM_USER2
						arbGain:				0.187
						Offset:					0
						Frequency:				50000000
		 */	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 1) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle2, 0.187, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );		
	}
}

/* test of basic instrument operation and arbitrary waveform case4 */ 
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase4()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3;
	
	CU_ASSERT ( 0 == testArbWfmInit() );
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_SINE, &wfmHandle3) ); 

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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50	
						Waveform:				TKAFG3K_VAL_WFM_USER3
						arbGain:				5
						Offset:					5
						Frequency:				1000
		 */	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle3, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 1000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of basic instrument operation and arbitrary waveform case5 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase5()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4;
	
	CU_ASSERT ( 0 == testArbWfmInit() );

	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, 0.9, -0.9, &wfmHandle3) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_SQUARE, &wfmHandle4) ); 	

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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50	
						Waveform:				TKAFG3K_VAL_WFM_USER4
						arbGain:				5
						Offset:					5
						Frequency:				0.001
		 */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle4, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 0.001) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}		
}

/* test of basic instrument operation and arbitrary waveform case6 */ 
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase6()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4;
	
	CU_ASSERT ( 0 == testArbWfmInit() );

	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, 0.9, -0.9, &wfmHandle3) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_PULS, &wfmHandle4) ); 	

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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Modulation
						Impedance:				50	
						Waveform:				TKAFG3K_VAL_WFM_USER4
						arbGain:				5
						Offset:					5
						Frequency:				50000000
		 */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_MODULATION) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle4, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}		
}

/* test of basic instrument operation and arbitrary waveform case7 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase7()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4;
	
	CU_ASSERT ( 0 == testArbWfmInit() );

	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, 0.9, -0.9, &wfmHandle3) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_RAMP, &wfmHandle4) ); 	

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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Sweep
						Impedance:				50	
						Waveform:				TKAFG3K_VAL_WFM_USER4
						arbGain:				5
						Offset:					5
						Frequency:				50000000
		 */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_SWEEP) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle4, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}		
}

/* test of basic instrument operation and arbitrary waveform case8 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase8()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1, wfmHandle2, wfmHandle3, wfmHandle4;
	
	CU_ASSERT ( 0 == testArbWfmInit() );

	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, -0.9, 0.9, &wfmHandle2) ); 
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, 0.9, -0.9, &wfmHandle3) ); 	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, TKAFG3K_VAL_ARB_WFM_PRN, &wfmHandle4) ); 	
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Burst
						Impedance:				50	
						Waveform:				TKAFG3K_VAL_WFM_USER4
						arbGain:				5
						Offset:					5
						Frequency:				50000000
		 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_BURST) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle4, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );		
	}
}

/* test of basic instrument operation and arbitrary waveform case9 */
void testFuncBasicInstrumentOperationAndArbitraryWaveformCase9()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;
	
	CU_ASSERT ( 0 == testArbWfmInit() );

	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData2, &wfmHandle1) ); 
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
						Clock:					Internal
						Operation Mode:			Continuous
						Impedance:				50	
						Waveform:				TKAFG3K_VAL_WFM_USER1
						arbGain:				5
						Offset:					5
						Sample Rate:			50000000*TEST_ARBITRARY_WAVEFORM_DATA_SIZE
		 */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureRefClockSource (vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );		 
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 5, 5) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );		
	}
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSampleRate (vi, 50000000*TEST_ARBITRARY_WAVEFORM_DATA_SIZE) ); 
}


/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And Burst Configuration 
 *	
 *************************************************************************************/

/* Triggering Function:
 *
 *		tkafg3k_ConfigureTriggerSource (ViSession vi, ViConstString channelName, ViInt32 trigSource);					
 *		tkafg3k_ForceTrigger (ViSession vi);
 *		tkafg3k_ConfigureTriggerOutputMode (ViSession vi, ViConstString channelName, ViInt32 outputMode);
 *		tkafg3k_ConfigureInternalTriggerRate (ViSession vi, ViReal64 rate);
 *		tkafg3k_ConfigureExternalTriggerSlope (ViSession vi, ViInt32 triggerSlope);
 *		
 * Burst Configuration Function:
 *
 *		tkafg3k_ConfigureBurstEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled); 
 *		tkafg3k_ConfigureBurstCount (ViSession vi, ViConstString channelName, ViInt32 burstCount);
 *		tkafg3k_ConfigureBurstMode (ViSession vi, ViConstString channelName, ViInt32 burstMode);
 */

/* test of waveform operation and burst configuration case1 */
void testFuncWaveformOperationAndBurstConfigurationCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			Internal
		 				Internal Trigger Rate:	1
		 				Burst Enabled:			VI_TRUE
		 				Burst Count:			5
		 				Burst Mode:				Triggered
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) ); 
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_INTERNAL_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate (vi, 1) );
		
		/* Burst Configuration */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstCount (vi, channel, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstMode (vi, channel, TKAFG3K_VAL_BURST_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and burst configuration case2 */
void testFuncWaveformOperationAndBurstConfigurationCase2()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_PULS
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			Internal
		 				Internal Trigger Rate:	1000.0
		 				Burst Enabled:			VI_TRUE
		 				Burst Count:			5
		 				Burst Mode:				Gate
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PULS, 10, 5, 50000000, 0) );  		
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_INTERNAL_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate (vi, 1000.0) );
	
		/* Burst Configuration */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstCount (vi, channel, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstMode (vi, channel, TKAFG3K_VAL_BURST_GATE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstEnabled (vi, channel, VI_TRUE) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and burst configuration case3 */
void testFuncWaveformOperationAndBurstConfigurationCase3()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SQUARE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			Internal
		 				Internal Trigger Rate:	1000.0
		 				Burst Enabled:			VI_TRUE
		 				Burst Count:			INFINITY
		 				Burst Mode:				Trigger
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SQUARE, 10, 5, 50000000, 0) );  		
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_INTERNAL_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate (vi, 1000.0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerOutputMode (vi, TKAFG3K_VAL_TRIGGER_TRIGGER) );
		
		/* Burst Configuration */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstCount (vi, channel, TKAFG3K_VAL_BURST_INFINITY) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstMode (vi, channel, TKAFG3K_VAL_BURST_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstEnabled (vi, channel, VI_TRUE) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}		
}

/* test of waveform operation and burst configuration case4 */
void testFuncWaveformOperationAndBurstConfigurationCase4()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_RAMP
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			Internal
		 				Internal Trigger Rate:	1000.0
		 				Burst Enabled:			VI_TRUE
		 				Burst Count:			1000000
		 				Burst Mode:				Trigger
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_RAMP, 10, 5, 1000000, 0) );  		
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_INTERNAL_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate (vi, 1000.0) );
	
		/* Burst Configuration */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstCount (vi, channel, 1000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstMode (vi, channel, TKAFG3K_VAL_BURST_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstEnabled (vi, channel, VI_TRUE) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}		
}

/* test of waveform operation and burst configuration case5 */
void testFuncWaveformOperationAndBurstConfigurationCase5()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	

		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINC
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			External
		 				External Trigger Slope:	Positive
		 				Burst Enabled:			VI_TRUE
		 				Burst Count:			1
		 				Burst Mode:				Trigger
		*/

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINC, 10, 5, 1000000, 0) );  		
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope (vi, TKAFG3K_VAL_TRIGGER_POSITIVE) );
	
		/* Burst Configuration */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstCount (vi, channel, 1) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstMode (vi, channel, TKAFG3K_VAL_BURST_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstEnabled (vi, channel, VI_TRUE) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and burst configuration case6 */
void testFuncWaveformOperationAndBurstConfigurationCase6()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_USER1
		 				Gain:					5
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			External
		 				External Trigger Slope:	Negative
		 				Burst Enabled:			VI_TRUE
		 				Burst Count:			5
		 				Burst Mode:				Trigger
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, TKAFG3K_VAL_WFM_USER1, 5, 5) ); 		
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope (vi, TKAFG3K_VAL_TRIGGER_NEGATIVE) );
	
		/* Burst Configuration */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstCount (vi, channel, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstMode (vi, channel, TKAFG3K_VAL_BURST_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureBurstEnabled (vi, channel, VI_TRUE) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}				
}

/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And Sweep Configuration 
 *	
 *************************************************************************************/

/* Sweep Configuration Function:
 *
 *			tkafg3k_ConfigureSweepEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);
 *			tkafg3k_ConfigureSweep (ViSession vi, ViConstString channelName, ViReal64 startFrequency,
 *                                    	ViReal64 stopFrequency, ViReal64 time, ViInt32 type);			
 *			tkafg3k_ConfigureSweepEx (ViSession vi, ViConstString channelName, ViReal64 startFrequency,
 *                                      ViReal64 stopFrequency, ViReal64 time, ViReal64 holdTime, ViReal64 returnTime, 
 *                                      ViInt32 type);
 */

/* test of waveform operation and sweep configuration case1 */
void testFuncWaveformOperationAndSweepConfigurationCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
			
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1000
		 				Sweep Stop Freq:		1000000
		 				Sweep Time:				1 
		 				Sweep Type:				Linear
		 				Sweep Mode:				REPEAT
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );				
		
		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweep (vi, channel, 1000, 1000000, 1, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepMode (vi, channel, TKAFG3K_VAL_SWEEP_AUTO) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and sweep configuration case2 */
void testFuncWaveformOperationAndSweepConfigurationCase2() 
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SQUARE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1
		 				Sweep Stop Freq:		50000000
		 				Sweep Time:				1 
		 				Sweep Type:				Logarithmic
		*/

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SQUARE, 10, 5, 50000000, 0) );				

		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweep (vi, channel, 1, 50000000, 1, TKAFG3K_VAL_SWEEP_LOGARITHMIC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and sweep configuration case3 */
void testFuncWaveformOperationAndSweepConfigurationCase3() 
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_RAMP
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1000000
		 				Sweep Stop Freq:		1
		 				Sweep Time:				100 
		 				Sweep Type:				Linear
		*/		

 		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_RAMP, 10, 5, 1000000, 0) );

		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweep (vi, channel, 1000000, 1, 100, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and sweep configuration case4 */
void testFuncWaveformOperationAndSweepConfigurationCase4() 
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINC
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1000
		 				Sweep Stop Freq:		1000000
		 				Sweep Time:				90
		 				Sweep Hold Time:		5
		 				Sweep Return Time:		5
		 				Sweep Type:				Linear
		*/		

 		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINC, 10, 5, 1000000, 0) );
		
		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEx (vi, channel, 1000, 1000000, 90, 5, 5, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

 /* test of waveform operation and sweep configuration case5 */
void testFuncWaveformOperationAndSweepConfigurationCase5()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			ARB
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_USER1
		 				Gain:					5
		 				Offset:					5
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1
		 				Sweep Stop Freq:		50000000
		 				Sweep Time:				80
		 				Sweep Hold Time:		10
		 				Sweep Return Time:		10
		 				Sweep Type:				Linear
		*/	
		
 		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, TKAFG3K_VAL_WFM_USER1, 5, 5) );
		
		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEx (vi, channel, 1, 50000000, 80, 10, 10, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );		
	}
}

/* test of waveform operation and sweep configuration case6 */
void testFuncWaveformOperationAndSweepConfigurationCase6()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
			
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			Internal
		 				Internal Trigger Rate:	1		 				
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1000
		 				Sweep Stop Freq:		1000000
		 				Sweep Time:				1 
		 				Sweep Type:				Linear
						Sweep Mode:				Trigger 
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );				
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_INTERNAL_TRIGGER) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate (vi, 1) );		
		
		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweep (vi, channel, 1000, 1000000, 1, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepMode (vi, channel, TKAFG3K_VAL_SWEEP_MANUAL) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and sweep configuration case7 */
void testFuncWaveformOperationAndSweepConfigurationCase7()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			External
		 				External Trigger Slope:	Positive		 				
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1000
		 				Sweep Stop Freq:		1000000
		 				Sweep Time:				1 
		 				Sweep Type:				Linear
						Sweep Mode:				Trigger 
		*/		
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );				
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope (vi, TKAFG3K_VAL_TRIGGER_POSITIVE) );		
		
		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweep (vi, channel, 1000, 1000000, 1, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepMode (vi, channel, TKAFG3K_VAL_SWEEP_MANUAL) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}

/* test of waveform operation and sweep configuration case8 */
void testFuncWaveformOperationAndSweepConfigurationCase8()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Trigger Source:			External
		 				External Trigger Slope:	Negative		 				
		 				Sweep Enabled:			VI_TRUE
		 				Sweep Start Freq:		1000
		 				Sweep Stop Freq:		1000000
		 				Sweep Time:				1 
		 				Sweep Type:				Linear
						Sweep Mode:				Trigger 
		*/		
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );				
		
		/* Triggering */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureTriggerSource (vi, channel, TKAFG3K_VAL_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope (vi, TKAFG3K_VAL_TRIGGER_NEGATIVE) );		
		
		/* Sweep Configuration */		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweep (vi, channel, 1000, 1000000, 1, TKAFG3K_VAL_SWEEP_LINEAR) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepEnabled (vi, channel, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureSweepMode (vi, channel, TKAFG3K_VAL_SWEEP_MANUAL) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );
	}
}
	
/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And Waveform Appendant 
 *	
 *************************************************************************************/

/* Waveform Appendant Function:
 *
 *		tkafg3k_ConfigureNoiseAppendantEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);				
 *		tkafg3k_ConfigureNoiseLevel (ViSession vi, ViConstString channelName, ViReal64 level);	
 *		tkafg3k_ConfigureExternalAppendEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);
 */

/* test of waveform operation and waveform appendant case1 */
void testFuncWaveformOperationAndWaveformAppendantCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:				FUNC
		 				Impedance:					50
		 				Waveform:					TKAFG3K_VAL_WFM_SINE
		 				Amplitude:					10
		 				Offset:						5
		 				Phase:						0
		 				Noise Appendant Enabled:	VI_TRUE
		 				Noise Level:				50 %
		 				External Appendant Enabled:	VI_FALSE
		*/		
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );			
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );	
	
		/* Waveform Appendant */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureNoiseLevel (vi, channel, 50) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureNoiseAppendantEnabled (vi, channel, VI_TRUE) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalAppendEnabled (vi, channel, VI_FALSE) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of waveform operation and waveform appendant case2 */
void testFuncWaveformOperationAndWaveformAppendantCase2()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, CHAN1, VI_FALSE) );

	/* Data:
	 				Output Mode:				FUNC
	 				Impedance:					50
	 				Waveform:					TKAFG3K_VAL_WFM_SINC
	 				Amplitude:					10
	 				Offset:						5
	 				Phase:						0
	 				Noise Appendant Enabled:	VI_TRUE
	 				Noise Level:				10 %
	 				External Appendant Enabled:	VI_TRUE
	*/
		
	/* Waveform Operation */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, CHAN1, TKAFG3K_VAL_OUTPUT_FUNC) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, CHAN1, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, CHAN1, 50) );			
		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, CHAN1, TKAFG3K_VAL_WFM_SINC, 10, 5, 1000000, 0) );			

	/* Waveform Appendant */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureNoiseLevel (vi, CHAN1, 10) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureNoiseAppendantEnabled (vi, CHAN1, VI_TRUE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalAppendEnabled (vi, CHAN1, VI_TRUE) );	
		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, CHAN1, VI_TRUE) ); 		
}

/* test of waveform operation and waveform appendant case3 */
void testFuncWaveformOperationAndWaveformAppendantCase3()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, CHAN1, VI_FALSE) );
		
	/* Data:
	 				Output Mode:				ARB
	 				Impedance:					50
	 				Waveform:					TKAFG3K_VAL_WFM_USER1
	 				Gain:						5
	 				Offset:						5
	 				Phase:						0
	 				Noise Appendant Enabled:	VI_FALSE
	 				External Appendant Enabled:	VI_TRUE
	*/		

	/* Waveform Operation */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, CHAN1, TKAFG3K_VAL_OUTPUT_ARB) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, CHAN1, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, CHAN1, 50) );
		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, CHAN1, TKAFG3K_VAL_WFM_USER1, 5, 5) ); 
		
	/* Waveform Appendant */
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureNoiseAppendantEnabled (vi, CHAN1, VI_FALSE) );
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureExternalAppendEnabled (vi, CHAN1, VI_TRUE) );	
		
	CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, CHAN1, VI_TRUE) ); 
		
}

/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And AM 
 *	
 *************************************************************************************/
 
/* Amplitude Modulation Function:
 *	
 *		tkafg3k_ConfigureAMEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_ConfigureAMSource (ViSession vi, ViConstString channelName, ViInt32 source); 
 *		tkafg3k_ConfigureAMInternal (ViSession vi, ViReal64 amDepth, ViInt32 amWaveform, ViReal64 amFrequency);
 *		tkafg3k_ConfigureAMInternalByChannel (ViSession vi, ViConstString channelName, ViReal64 amDepth,
 *												ViInt32 amWaveform, ViReal64 amFrequency); 
 *		tkafg3k_ConfigureAMExternalByChannel (ViSession vi, ViConstString channelName, ViReal64 amDepth);
 */ 
 
/* test of waveform operation and AM case1 */
void testFuncWaveformOperationAndAMCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				AM Enabled:				VI_TRUE
		 				AM Source:				Internal
		 				AM Depth:				120 %
		 				AM Waveform:			TKAFG3K_VAL_AM_INTERNAL_SINE
		 				AM Frequency:			50000
		*/		

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );		
		
		/* AM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMSource (vi, channel, TKAFG3K_VAL_AM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel (vi, channel, 120, TKAFG3K_VAL_AM_INTERNAL_SINE, 50000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMEnabled (vi, channel, VI_TRUE) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/* test of waveform operation and AM case2 */ 
void testFuncWaveformOperationAndAMCase2()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_AM_INTERNAL_SQUARE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				AM Enabled:				VI_TRUE
		 				AM Source:				Internal
		 				AM Depth:				50 %
		 				AM Waveform:			TKAFG3K_VAL_AM_INTERNAL_SINE
		 				AM Frequency:			50000
		*/			
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );
		
		/* AM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMSource (vi, channel, TKAFG3K_VAL_AM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel (vi, channel, 50, TKAFG3K_VAL_AM_INTERNAL_SQUARE, 50000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMEnabled (vi, channel, VI_TRUE) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/* test of waveform operation and AM case3 */ 
void testFuncWaveformOperationAndAMCase3()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;
	
	CU_ASSERT ( 0 == testArbWfmInit() ); 	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 	
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			ARB
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_USER1
		 				Gain:					5
		 				Offset:					5
		 				AM Enabled:				VI_TRUE
		 				AM Source:				Internal
		 				AM Depth:				50 %
		 				AM Waveform:			TKAFG3K_VAL_AM_INTERNAL_USER1
		 				AM Frequency:			1000
		*/
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 5, 5) );

		/* AM */ 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMSource (vi, channel, TKAFG3K_VAL_AM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel (vi, channel, 50, TKAFG3K_VAL_AM_INTERNAL_USER1, 1000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMEnabled (vi, channel, VI_TRUE) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}		
}

/* test of waveform operation and AM case4 */ 
void testFuncWaveformOperationAndAMCase4()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				AM Enabled:				VI_TRUE
		 				AM Source:				External
		 				AM Depth:				120 %
		*/			
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );
		
		/* AM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMSource (vi, channel, TKAFG3K_VAL_AM_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMExternalByChannel (vi, channel, 120) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMEnabled (vi, channel, VI_TRUE) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}		
}

/* test of waveform operation and AM case5 */
void testFuncWaveformOperationAndAMCase5()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				AM Enabled:				VI_TRUE
		 				AM Source:				Internal
		 				AM Depth:				120 %
		 				AM Waveform:			TKAFG3K_VAL_AM_INTERNAL_SINE
		 				AM Frequency:			50000
		*/		

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );		
		
		/* AM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMSource (vi, CHAN1, TKAFG3K_VAL_AM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMSource (vi, CHAN2, TKAFG3K_VAL_AM_INTERNAL) ); 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 120, TKAFG3K_VAL_AM_INTERNAL_SINE, 50000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureAMEnabled (vi, channel, VI_TRUE) );

		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And FM 
 *	
 *************************************************************************************/

/* FM Function:
 *
 *		tkafg3k_ConfigureFMEnabled (ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_ConfigureFMSource (ViSession vi, ViConstString channelName, ViInt32 source);
 *		tkafg3k_ConfigureFMInternal (ViSession vi, ViReal64 fmDeviation, ViInt32 fmWaveform, ViReal64 fmFrequency);
 *		tkafg3k_ConfigureFMInternalByChannel (ViSession vi, ViConstString channelName, ViReal64 fmDeviance,
 *                                           	ViInt32 fmWaveform, ViReal64 fmFrequency);
 *		tkafg3k_ConfigureFMExternalByChannel (ViSession vi, ViConstString channelName, ViReal64 fmDeviance);
 */

/* test of waveform operation and FM case1 */
void testFuncWaveformOperationAndFMCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				FM Enabled:				VI_TRUE
		 				FM Source:				Internal
		 				FM Deviation:			1000000	
		 				FM Waveform:			TKAFG3K_VAL_FM_INTERNAL_SINE
		 				FM Frequency:			1000
		 */

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );
		
		/* FM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMSource (vi, channel, TKAFG3K_VAL_FM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel (vi, channel, 1000000, TKAFG3K_VAL_FM_INTERNAL_SINE, 1000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );  		
	}		
}

/* test of waveform operation and FM case2 */ 
void testFuncWaveformOperationAndFMCase2()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SQUARE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				25000000
		 				FM Enabled:				VI_TRUE
		 				FM Source:				Internal
		 				FM Deviation:			25000000	
		 				FM Waveform:			TKAFG3K_VAL_ARB_WFM_SQUARE
		 				FM Frequency:			1000
		 */		

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SQUARE, 10, 5, 25000000, 0) );

		/* FM */  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMSource (vi, channel, TKAFG3K_VAL_FM_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel (vi, channel, 25000000, TKAFG3K_VAL_ARB_WFM_SQUARE, 1000) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMEnabled (vi, channel, VI_TRUE) );   
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );  		
	}		
}

/* test of waveform operation and FM case3 */ 
void testFuncWaveformOperationAndFMCase3()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_RAMP
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				FM Enabled:				VI_TRUE
		 				FM Source:				Internal
		 				FM Deviation:			0	
		 				FM Waveform:			TKAFG3K_VAL_AM_INTERNAL_RAMP_UP
		 				FM Frequency:			50000
		 */
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_RAMP, 10, 5, 1000000, 0) );
		
		/* FM */  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMSource (vi, channel, TKAFG3K_VAL_FM_INTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel (vi, channel, 0, TKAFG3K_VAL_AM_INTERNAL_RAMP_UP, 50000) );  		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMEnabled (vi, channel, VI_TRUE) );   
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );  	
	}
}

/* test of waveform operation and FM case4 */ 
void testFuncWaveformOperationAndFMCase4()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;

	CU_ASSERT ( 0 == testArbWfmInit() ); 	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) ); 
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );

		/* Data:
		 				Output Mode:			ARB
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_USER1
		 				Gain:					5
		 				Offset:					5
		 				Frequency:				25000000
		 				FM Enabled:				VI_TRUE
		 				FM Source:				External
		 				FM Deviation:			25000000	
		 */

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 25000000) );
		
		/* FM */  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMSource (vi, channel, TKAFG3K_VAL_FM_EXTERNAL) );  
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMExternalByChannel (vi, channel, 25000000) );  		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMEnabled (vi, channel, VI_TRUE) );   
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );  	
	}
}

/* test of waveform operation and FM case5 */ 
void testFuncWaveformOperationAndFMCase5()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	

		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				FM Enabled:				VI_TRUE
		 				FM Source:				Internal
		 				FM Deviation:			1000000	
		 				FM Waveform:			TKAFG3K_VAL_FM_INTERNAL_SINE
		 				FM Frequency:			1000
		 */
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );
		
		/* FM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMSource (vi, CHAN1, TKAFG3K_VAL_FM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMSource (vi, CHAN2, TKAFG3K_VAL_FM_INTERNAL) ); 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMInternal (vi, 1000000, TKAFG3K_VAL_FM_INTERNAL_SINE, 1000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) );  		
	}
}

/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And PM 
 *	
 *************************************************************************************/

/* PM Function:
 *
 *		tkafg3k_ConfigurePMEnabled ( ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_ConfigurePMSource (	ViSession vi, ViConstString channelName, ViInt32 source);
 *		tkafg3k_ConfigurePMInternalByChannel (ViSession vi, ViConstString channelName, ViReal64 pmDeviation,
 *                                           	ViInt32 pmWaveform, ViReal64 pmFrequency);
 *		tkafg3k_ConfigurePMExternalByChannel (ViSession vi, ViConstString channelName, ViReal64 pmDeviation);
 */

/* test of waveform operation and PM case1 */
void testFuncWaveformOperationAndPMCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	

		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				PM Enabled:				VI_TRUE
		 				PM Source:				Internal
		 				PM Deviation:			180	
		 				PM Waveform:			TKAFG3K_VAL_PM_INTERNAL_SINE
		 				PM Frequency:			1000
		 */	
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 1000000, 0) );
	
		/* PM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMSource (vi, channel, TKAFG3K_VAL_PM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel (vi, channel, 180, TKAFG3K_VAL_FM_INTERNAL_SINE, 1000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of waveform operation and PM case2 */
void testFuncWaveformOperationAndPMCase2()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINC
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				PM Enabled:				VI_TRUE
		 				PM Source:				Internal
		 				PM Deviation:			90
		 				PM Waveform:			TKAFG3K_VAL_PM_INTERNAL_RAMP_UP
		 				PM Frequency:			50000
		 */			

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINC, 10, 5, 1000000, 0) );
	
		/* PM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMSource (vi, channel, TKAFG3K_VAL_PM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel (vi, channel, 90, TKAFG3K_VAL_PM_INTERNAL_RAMP_UP, 50000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of waveform operation and PM case3 */
void testFuncWaveformOperationAndPMCase3()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;

	CU_ASSERT ( 0 == testArbWfmInit() ); 	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) );
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			ARB
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_USER1
		 				Gain:					5
		 				Offset:					5
		 				Frequency:				50000000
		 				PM Enabled:				VI_TRUE
		 				PM Source:				Internal
		 				PM Deviation:			0
		 				PM Waveform:			TKAFG3K_VAL_PM_INTERNAL_USER1
		 				PM Frequency:			0.002		 				
		 */		

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 25000000) );		

		/* PM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMSource (vi, channel, TKAFG3K_VAL_PM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel (vi, channel, 0, TKAFG3K_VAL_PM_INTERNAL_USER1, 0.002) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/* test of waveform operation and PM case4 */
void testFuncWaveformOperationAndPMCase4()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_RAMP
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				PM Enabled:				VI_TRUE
		 				PM Source:				External
		 				PM Deviation:			180			 				
		 */	
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_RAMP, 10, 5, 1000000, 0) );		

		/* PM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMSource (vi, channel, TKAFG3K_VAL_PM_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMExternalByChannel (vi, channel, 180) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}		
}

/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And FSK 
 *	
 *************************************************************************************/

/* FSK Function:
 *
 *		tkafg3k_ConfigureFSKEnabled ( ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_ConfigureFSKSource ( ViSession vi, ViConstString channelName, ViInt32 source);
 *		tkafg3k_ConfigureFSKInternalByChannel (ViSession vi, ViConstString channelName, ViReal64 hopFrequency, ViReal64 rate);
 *		tkafg3k_ConfigureFSKExternalByChannel (ViSession vi, ViConstString channelName, ViReal64 hopFrequency);
 */

/* test of waveform operation And FSK case1 */
void testFuncWaveformOperationAndFSKCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINE
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				100000000
		 				FSK Enabled:			VI_TRUE
		 				FSK Source:				Internal
		 				FSK Hop Freq:			100000000
		 				FSK Internal Rate:		1000000
		 */			
	
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINE, 10, 5, 100000000, 0) );
		
		/* FSK */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKSource (vi, channel, TKAFG3K_VAL_FSK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKInternalByChannel (vi, channel, 100000000, 1000000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}			
}

/* test of waveform operation And FSK case2 */
void testFuncWaveformOperationAndFSKCase2()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_SINC
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1000000
		 				FSK Enabled:			VI_TRUE
		 				FSK Source:				Internal
		 				FSK Hop Freq:			0.01
		 				FSK Internal Rate:		0.002
		 */			

		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_SINC, 10, 5, 1000000, 0) );		
		
		/* FSK */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKSource (vi, channel, TKAFG3K_VAL_FSK_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKInternalByChannel (vi, channel, 0.01, 0.002) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/* test of waveform operation And FSK case3 */
void testFuncWaveformOperationAndFSKCase3()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;

	CU_ASSERT ( 0 == testArbWfmInit() ); 	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) );
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			ARB
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_USER1
		 				Gain:					5
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				50000000
		 				FSK Enabled:			VI_TRUE
		 				FSK Source:				External
		 				FSK Hop Freq:			1000
		 */			
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_ARB) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbWaveform (vi, channel, wfmHandle1, 5, 5) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureArbFrequency (vi, channel, 50000000) );
		
		/* FSK */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKSource (vi, channel, TKAFG3K_VAL_FSK_EXTERNAL) );	
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKExternalByChannel	(vi, channel, 1000) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureFSKEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 
	}
}

/*************************************************************************************
 *
 * Unit Test Code for Waveform Operation And PWM 
 *	
 *************************************************************************************/
 
/* PWM Function:
 *
 *		tkafg3k_ConfigurePWMEnabled ( ViSession vi, ViConstString channelName, ViBoolean enabled);
 *		tkafg3k_ConfigurePWMSource (ViSession vi, ViConstString channelName, ViInt32 source);
 *		tkafg3k_ConfigurePWMInternalByChannel (	ViSession vi, ViConstString channelName, ViReal64 pwmDeviation,
 *                                               ViInt32 pwmWaveform, ViReal64 pwmFrequency);
 *		tkafg3k_ConfigurePWMExternalByChannel (	ViSession vi, ViConstString channelName, ViReal64 pwmDeviation);                                                
 */

/* test of waveform operation and PWM case1 */
void testFuncWaveformOperationAndPWMCase1()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_PULS 
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				1
		 				PWM Enabled:			VI_TRUE
		 				PWM Source:				Internal
		 				PWM Deviation:			49.9			
		 				PWM Waveform:			TKAFG3K_VAL_PWM_INTERNAL_SINE
		 				PWM Frequency:			0.002
		 */
	
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PULS, 10, 5, 1, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePulseWaveform (vi, channel, 50, 5.0e-9, 5.0e-9) );
		
		/* PWM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMSource (vi, channel, TKAFG3K_VAL_PWM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel (vi, channel, 49.9, TKAFG3K_VAL_PWM_INTERNAL_SINE, 0.002) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of waveform operation and PWM case2 */
void testFuncWaveformOperationAndPWMCase2()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_PULS 
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				50000000
		 				PWM Enabled:			VI_TRUE
		 				PWM Source:				Internal
		 				PWM Deviation:			10			
		 				PWM Waveform:			TKAFG3K_VAL_PWM_INTERNAL_RAMP_DOWN
		 				PWM Frequency:			50000
		 */		
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );	
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PULS, 10, 5, 50000000, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePulseWaveform (vi, channel, 50, 5.0e-9, 5.0e-9) );

		/* PWM */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMSource (vi, channel, TKAFG3K_VAL_PWM_INTERNAL) ); 
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel (vi, channel, 10, TKAFG3K_VAL_PWM_INTERNAL_RAMP_DOWN, 50000) );     
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}
}

/* test of waveform operation and PWM case3 */  
void testFuncWaveformOperationAndPWMCase3()
{
	ViChar channel[BUFFER_SIZE];
	ViInt32 i;
	ViInt32 wfmHandle1;

	CU_ASSERT ( 0 == testArbWfmInit() ); 	
	
	CU_ASSERT ( VI_SUCCESS == tkafg3k_CreateArbWaveform (vi, TEST_ARBITRARY_WAVEFORM_DATA_SIZE, arbWfmData1, &wfmHandle1) );
	
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_PULS 
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				50000000
		 				PWM Enabled:			VI_TRUE
		 				PWM Source:				Internal
		 				PWM Deviation:			10			
		 				PWM Waveform:			TKAFG3K_VAL_PWM_INTERNAL_USER1
		 				PWM Frequency:			50000
		 */
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PULS, 10, 5, 50000000, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePulseWaveform (vi, channel, 50, 5.0e-9, 5.0e-9) );
		
		/* PWM */   		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMSource (vi, channel, TKAFG3K_VAL_PWM_INTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel (vi, channel, 10, TKAFG3K_VAL_PWM_INTERNAL_USER1, 50000) ); 		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}		
}

/* test of waveform operation and PWM case4 */  
void testFuncWaveformOperationAndPWMCase4()
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
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_FALSE) );	
		
		/* Data:
		 				Output Mode:			FUNC
		 				Impedance:				50
		 				Waveform:				TKAFG3K_VAL_WFM_PULS 
		 				Amplitude:				10
		 				Offset:					5
		 				Phase:					0
		 				Frequency:				50000000
		 				PWM Enabled:			VI_TRUE
		 				PWM Source:				External
		 				PWM Deviation:			10			
		 */		
		
		/* Waveform Operation */
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel (vi, channel, TKAFG3K_VAL_OUTPUT_FUNC) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOperationMode (vi, channel, TKAFG3K_VAL_OPERATE_CONTINUOUS) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputImpedance (vi, channel, 50) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureStandardWaveform (vi, channel, TKAFG3K_VAL_WFM_PULS, 10, 5, 50000000, 0) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePulseWaveform (vi, channel, 50, 5.0e-9, 5.0e-9) );
		
		/* PWM */   		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMSource (vi, channel, TKAFG3K_VAL_PWM_EXTERNAL) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMExternalByChannel (vi, channel, 10) );
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigurePWMEnabled (vi, channel, VI_TRUE) );
		
		CU_ASSERT ( VI_SUCCESS == tkafg3k_ConfigureOutputEnabled (vi, channel, VI_TRUE) ); 		
	}		
}


CU_TestInfo testArrayFuncBasicInstrOperAndStanWfm[] = {
		
		{ "basic instrument operation and standard waveform default",				
										testFuncBasicInstrumentOperationAndStandardWaveformDefault		},	

		{ "basic instrument operation and standard waveform case1",
										testFuncBasicInstrumentOperationAndStandardWaveformCase1		},

		{ "basic instrument operation and standard waveform case2",
										testFuncBasicInstrumentOperationAndStandardWaveformCase2		},

		{ "basic instrument operation and standard waveform case3",
										testFuncBasicInstrumentOperationAndStandardWaveformCase3		},

		{ "basic instrument operation and standard waveform case4",
										testFuncBasicInstrumentOperationAndStandardWaveformCase4		},

		{ "basic instrument operation and standard waveform case5",
										testFuncBasicInstrumentOperationAndStandardWaveformCase5		},

		{ "basic instrument operation and standard waveform case6",
										testFuncBasicInstrumentOperationAndStandardWaveformCase6		},

		{ "basic instrument operation and standard waveform case7",
										testFuncBasicInstrumentOperationAndStandardWaveformCase7		},
										
		{ "basic instrument operation and standard waveform case8",
										testFuncBasicInstrumentOperationAndStandardWaveformCase8		},

		{ "basic instrument operation and standard waveform case9",
										testFuncBasicInstrumentOperationAndStandardWaveformCase9		},

		{ "basic instrument operation and standard waveform case10",
										testFuncBasicInstrumentOperationAndStandardWaveformCase10		},

		{ "basic instrument operation and standard waveform case11",
										testFuncBasicInstrumentOperationAndStandardWaveformCase11		},
										
		CU_TEST_INFO_NULL,
};


CU_TestInfo testArrayFuncBasicInstrOperAndArbWfm[] = {

		{ "create and clear arbitrary waveform case1",
										testFuncCreateAndClearArbitraryWaveformCase1					},
										
		{ "create and clear arbitrary waveform case2",
										testFuncCreateAndClearArbitraryWaveformCase2					},
		
		{ "create and clear arbitrary waveform case3",
										testFuncCreateAndClearArbitraryWaveformCase3					},
		
		{ "create and clear arbitrary waveform case4",
										testFuncCreateAndClearArbitraryWaveformCase4					},

		{ "create and clear arbitrary waveform case5",
										testFuncCreateAndClearArbitraryWaveformCase5					},

		{ "basic instrument operation and arbitrary waveform case1",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase1		},

		{ "basic instrument operation and arbitrary waveform case2",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase2		},

		{ "basic instrument operation and arbitrary waveform case3",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase3		},

		{ "basic instrument operation and arbitrary waveform case4",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase4		},

		{ "basic instrument operation and arbitrary waveform case5",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase5		},
										
		{ "basic instrument operation and arbitrary waveform case6",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase6		},

		{ "basic instrument operation and arbitrary waveform case7",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase7		},

		{ "basic instrument operation and arbitrary waveform case8",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase8		},
										
		{ "basic instrument operation and arbitrary waveform case9",
										testFuncBasicInstrumentOperationAndArbitraryWaveformCase9		},
		
		CU_TEST_INFO_NULL,												
};


CU_TestInfo testArrayFuncWfmOperAndBurstConfig[] = {

		{ "waveform operation and burst configuration case1",
										testFuncWaveformOperationAndBurstConfigurationCase1				},
		
		{ "waveform operation and burst configuration case2",
										testFuncWaveformOperationAndBurstConfigurationCase2				},

		{ "waveform operation and burst configuration case3",
										testFuncWaveformOperationAndBurstConfigurationCase3				},
										
		{ "waveform operation and burst configuration case4",
										testFuncWaveformOperationAndBurstConfigurationCase4				},
										
		{ "waveform operation and burst configuration case5",
										testFuncWaveformOperationAndBurstConfigurationCase5				},

		{ "waveform operation and burst configuration case6",
										testFuncWaveformOperationAndBurstConfigurationCase6				},
		
		CU_TEST_INFO_NULL,	
};

CU_TestInfo testArrayFuncWfmOperAndSweepConfig[] = {

		{ "waveform operation and sweep configuration case1",
										testFuncWaveformOperationAndSweepConfigurationCase1				},

		{ "waveform operation and sweep configuration case2",
										testFuncWaveformOperationAndSweepConfigurationCase2				},

		{ "waveform operation and sweep configuration case3",
										testFuncWaveformOperationAndSweepConfigurationCase3				},

		{ "waveform operation and sweep configuration case4",
										testFuncWaveformOperationAndSweepConfigurationCase4				},
		
		{ "waveform operation and sweep configuration case5",
										testFuncWaveformOperationAndSweepConfigurationCase5				},

		{ "waveform operation and sweep configuration case6",
										testFuncWaveformOperationAndSweepConfigurationCase6				},
 
		{ "waveform operation and sweep configuration case7",
										testFuncWaveformOperationAndSweepConfigurationCase7				},

		{ "waveform operation and sweep configuration case8",
										testFuncWaveformOperationAndSweepConfigurationCase8				},
		CU_TEST_INFO_NULL,		
};

CU_TestInfo testArrayFuncWfmOperAndWfmAppend[] = {

		{ "waveform operation and waveform appendant case1",
										testFuncWaveformOperationAndWaveformAppendantCase1				},	
		
		{ "waveform operation and waveform appendant case2",
										testFuncWaveformOperationAndWaveformAppendantCase2				},

		{ "waveform operation and waveform appendant case3",
										testFuncWaveformOperationAndWaveformAppendantCase3				},
		
		CU_TEST_INFO_NULL,
};

CU_TestInfo testArrayFuncWfmOperAndAM[] = {

		{ "waveform operation and AM case1",	testFuncWaveformOperationAndAMCase1						},
		{ "waveform operation and AM case2",	testFuncWaveformOperationAndAMCase2						},		
		{ "waveform operation and AM case3",	testFuncWaveformOperationAndAMCase3						},
		{ "waveform operation and AM case4",	testFuncWaveformOperationAndAMCase4						},
		{ "waveform operation and AM case5",	testFuncWaveformOperationAndAMCase5						},
		CU_TEST_INFO_NULL,
};

CU_TestInfo testArrayFuncWfmOperAndFM[] = {

		{ "waveform operation and FM case1",	testFuncWaveformOperationAndFMCase1						},	
		{ "waveform operation and FM case2",	testFuncWaveformOperationAndFMCase2						},
		{ "waveform operation and FM case3",	testFuncWaveformOperationAndFMCase3						},
		{ "waveform operation and FM case4",	testFuncWaveformOperationAndFMCase4						},
		{ "waveform operation and FM case5",	testFuncWaveformOperationAndFMCase5						},
		CU_TEST_INFO_NULL,  
};

CU_TestInfo testArrayFuncWfmOperAndPM[] = {

		{ "waveform operation and PM case1",	testFuncWaveformOperationAndPMCase1						},
		{ "waveform operation and PM case2",	testFuncWaveformOperationAndPMCase2						},
		{ "waveform operation and PM case3",	testFuncWaveformOperationAndPMCase3						},
		{ "waveform operation and PM case4",	testFuncWaveformOperationAndPMCase4						},
		CU_TEST_INFO_NULL,
};

CU_TestInfo testArrayFuncWfmOperAndFSK[] = {

		{ "waveform operation and FSK case1",	testFuncWaveformOperationAndFSKCase1					},
		{ "waveform operation and FSK case2",	testFuncWaveformOperationAndFSKCase2					},
		{ "waveform operation and FSK case3",   testFuncWaveformOperationAndFSKCase3					},
		CU_TEST_INFO_NULL,		
};

CU_TestInfo testArrayFuncWfmOperAndPWM[] = {

		{ "waveform operation and PWM case1",	testFuncWaveformOperationAndPWMCase1					},
		{ "waveform operation and PWM case2",	testFuncWaveformOperationAndPWMCase2					},
		{ "waveform operation and PWM case3",	testFuncWaveformOperationAndPWMCase3					},
		{ "waveform operation and PWM case4",	testFuncWaveformOperationAndPWMCase4					},
		CU_TEST_INFO_NULL,
};

CU_SuiteInfo suites[] = { 
	
		{ "unit test code for basic instrument operation and standard waveform",	NULL, NULL,	testArrayFuncBasicInstrOperAndStanWfm 	},
  		{ "unit test code for basic instrument operation and arbitrary waveform",	NULL, NULL,	testArrayFuncBasicInstrOperAndArbWfm	}, 
    	{ "unit test code for waveform operation and burst configuration",			NULL, NULL, testArrayFuncWfmOperAndBurstConfig		},
 		{ "unit test code for waveform operation and sweep configuration",			NULL, NULL, testArrayFuncWfmOperAndSweepConfig		},
		{ "unit test code for waveform operation and waveform appendant",			NULL, NULL, testArrayFuncWfmOperAndWfmAppend		},
 		{ "unit test code for waveform operation and AM",							NULL, NULL, testArrayFuncWfmOperAndAM				},
 		{ "unit test code for waveform operation and FM",							NULL, NULL, testArrayFuncWfmOperAndFM				},
 		{ "unit test code for waveform operation and PM",							NULL, NULL, testArrayFuncWfmOperAndPM				},
 		{ "unit test code for waveform operation and FSK",							NULL, NULL, testArrayFuncWfmOperAndFSK				},
 		{ "unit test code for waveform operation and PWM",							NULL, NULL, testArrayFuncWfmOperAndPWM				},
  		CU_SUITE_INFO_NULL,  		
};

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
   	if(CUE_SUCCESS != CU_register_suites(suites))
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
