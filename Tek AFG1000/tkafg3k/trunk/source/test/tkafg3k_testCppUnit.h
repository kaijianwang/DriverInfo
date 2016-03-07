#include <cppunit\extensions\HelperMacros.h>
using namespace CppUnit;	

class DriverFunctionalityTest : public TestFixture
{
	CPPUNIT_TEST_SUITE( DriverFunctionalityTest);		
	
    /***** Begin of Basic Operation Group Testing *****/

	CPPUNIT_TEST(testTKAFG3K_ATTR_OUTPUT_MODE_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index2);

	CPPUNIT_TEST(testTKAFG3K_ATTR_REF_CLOCK_SOURCE_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_REF_CLOCK_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_REF_CLOCK_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index2);

    /***** End of Basic Operation Group Testing *****/

    /***** Begin of Standard Function Output Group Testing *****/

    /***** End of Standard Function Output Group Testing *****/

    /***** Begin of Pulse Waveform Generation Group Testing *****/

    /***** End of Pulse Waveform Generation Group Testing *****/

    /***** Begin of Arbitrary Waveform Output Group Testing *****/

	CPPUNIT_TEST(testTKAFG3K_ATTR_ARB_SAMPLE_RATE_defaultValue_ReadWrite_NullChannel_Index0);

	CPPUNIT_TEST(testTKAFG3K_ATTR_MAX_NUM_WAVEFORMS_defaultValue_ReadOnly_NullChannel_Index0);

	CPPUNIT_TEST(testTKAFG3K_ATTR_WAVEFORM_QUANTUM_defaultValue_ReadOnly_NullChannel_Index0);

	CPPUNIT_TEST(testTKAFG3K_ATTR_MIN_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0);

	CPPUNIT_TEST(testTKAFG3K_ATTR_MAX_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0);

	CPPUNIT_TEST(testTKAFG3K_ATTR_ACTIVE_MEMORY_defaultValue_ReadWrite_NullChannel_Index0);

    /***** End of Arbitrary Waveform Output Group Testing *****/

    /***** Begin of Triggering Group Testing *****/



	CPPUNIT_TEST(testTKAFG3K_ATTR_TRIGGER_MODE_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_TRIGGER_MODE_DiscreteValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_TRIGGER_MODE_DiscreteValue_ReadWrite_NullChannel_Index2);

	CPPUNIT_TEST(testTKAFG3K_ATTR_TRIGGER_SLOPE_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index2);

	CPPUNIT_TEST(testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_CloseminimumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ClosemaximumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_RandomValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ViolationMinValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ViolationMaxValue_ReadWrite_NullChannel_Index1);

    /***** End of Triggering Group Testing *****/

    /***** Begin of Bursting Group Testing *****/

    /***** End of Bursting Group Testing *****/

    /***** Begin of Sweeping Group Testing *****/

    /***** End of Sweeping Group Testing *****/

    /***** Begin of Waveform Appendant Group Testing *****/

    /***** End of Waveform Appendant Group Testing *****/

    /***** Begin of Modulation Group Testing *****/

    /***** End of Modulation Group Testing *****/

    /***** Begin of Amplitude Modulation Group Testing *****/

	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_CloseminimumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ClosemaximumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_RandomValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ViolationMinValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ViolationMaxValue_ReadWrite_NullChannel_Index1);

	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index2);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index3);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index4);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index5);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index6);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index7);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index8);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index9);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index10);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index11);

	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_NullChannel_Index1);

    /***** End of Amplitude Modulation Group Testing *****/

    /***** Begin of Frequency Modulation Group Testing *****/



	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_DEVIATION_defaultValue_ReadWrite_NullChannel_Index0);

	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index2);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index3);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index4);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index5);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index6);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index7);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index8);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index9);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index10);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index11);

	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_NullChannel_Index0);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_NullChannel_Index1);
	CPPUNIT_TEST(testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_NullChannel_Index1);

    /***** End of Frequency Modulation Group Testing *****/

    /***** Begin of FSK Modulation Group Testing *****/

    /***** End of FSK Modulation Group Testing *****/

    /***** Begin of Phase Modulation Group Testing *****/

    /***** End of Phase Modulation Group Testing *****/

    /***** Begin of Pulse Width Modulation Group Testing *****/

    /***** End of Pulse Width Modulation Group Testing *****/

    /***** Begin of Miscellaneous Attributes Group Testing *****/

	CPPUNIT_TEST(testTKAFG3K_ATTR_ID_QUERY_RESPONSE_defaultValue_ReadOnly_NullChannel_Index0);

    /***** End of Miscellaneous Attributes Group Testing *****/

    /***** Begin of API Testing *****/

    CPPUNIT_TEST(test_tkafg3k_ConfigureActiveMemory_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureActiveMemory_activeMemory_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureOperationMode_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOperationMode_operationMode_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputMode_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputMode_outputMode_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputMode_outputMode_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputMode_outputMode_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputModeByChannel_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureRefClockSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index2);


    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputEnabled_enabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureOutputEnabled_enabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index12);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_waveform_Invalid);
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The amplitude's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The DCOffset's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureRampSymmetry_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeRandomValue_Index1);
     
    CPPUNIT_TEST(test_tkafg3k_ConfigurePulseWaveform_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The dutyCycle's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The leadingEdgeTime's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The trailingEdgeTime's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    CPPUNIT_TEST(test_tkafg3k_ConfigurePulseDelay_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The delay's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureSampleRate_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The sampleRate_Samps's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    CPPUNIT_TEST(test_tkafg3k_CreateArbWaveform_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_CreateLineInterpolateArbWfm_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_CreateStandardShapeArbWfm_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_GetArbitraryWaveformBySlot_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_CreateArbWaveformBySlot_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_CreateLineInterpolateArbWfmBySlot_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_CreateStandardShapeArbWfmBySlot_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_QueryArbWfmCapabilities_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureArbWaveform_DefaultParameter);

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The gain_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The offset_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    CPPUNIT_TEST(test_tkafg3k_ClearArbWaveform_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_ClearArbWaveformBySlot_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureArbFrequency_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerSource_triggerSource_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerSource_triggerSource_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerSource_triggerSource_Invalid);
  
    CPPUNIT_TEST(test_tkafg3k_ForceTrigger_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerOutputMode_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureInternalTriggerRate_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalTriggerSlope_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstDelay_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstEnabled_burstEnabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstEnabled_burstEnabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstCount_burstCount_RangeRandomValue_Index2);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstMode_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstMode_burstMode_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstMode_burstMode_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureBurstMode_burstMode_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEnabled_sweepEnabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEnabled_sweepEnabled_FALSE); 
        
      
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The stopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_time_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_time_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_time_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_time_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_time_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_type_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_type_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweep_type_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The stopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_time_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_time_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_time_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_time_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_time_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_holdTime_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_holdTime_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_holdTime_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_holdTime_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_holdTime_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_returnTime_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_returnTime_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_returnTime_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_returnTime_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_returnTime_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_type_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_type_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepEx_type_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepMode_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepMode_sweepMode_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepMode_sweepMode_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureSweepMode_sweepMode_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseAppendantEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseAppendantEnabled_noiseAppendantEnabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseAppendantEnabled_noiseAppendantEnabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseLevel_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalAppendEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalAppendEnabled_externalAppendantEnabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureExternalAppendEnabled_externalAppendantEnabled_FALSE); 


        
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMEnabled_enabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMEnabled_enabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMSource_source_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMSource_source_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMSource_source_Invalid);
                
           
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationWaveform_Invalid);
                
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeRandomValue_Index1);
           
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Invalid);
                
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMExternalByChannel_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeRandomValue_Index1);
                                
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMEnabled_enabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMEnabled_enabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMSource_source_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMSource_source_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMSource_source_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationWaveform_Invalid);
                
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Invalid);
             
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFMExternalByChannel_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

    CPPUNIT_TEST(test_tkafg3k_ConfigurePMEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMEnabled_enabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMEnabled_enabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMSource_source_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMSource_source_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMSource_source_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeRandomValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Invalid);
                
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMExternalByChannel_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKEnabled_enabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKEnabled_enabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKSource_source_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKSource_source_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKSource_source_Invalid);
                
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKInternalByChannel_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigureFSKExternalByChannel_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
       
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMEnabled_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMEnabled_enabled_TRUE);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMEnabled_enabled_FALSE); 
        
        
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMSource_DefaultParameter);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMSource_source_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMSource_source_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMSource_source_Invalid);
                
          
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_DefaultParameter);
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index2);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index3);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index4);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index5);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index6);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index7);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index8);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index9);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index10);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index11);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Invalid);
                
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1);
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1);
        
    CPPUNIT_TEST(test_tkafg3k_ConfigurePWMExternalByChannel_DefaultParameter);
      
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Percent's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    CPPUNIT_TEST(test_tkafg3k_InitiateGeneration_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_AbortGeneration_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_CopyWfmDataBetweenEditMemory_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_SaveLoadInstrumentSettings_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_SaveLoadWaveformData_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_SetGetWaveformPointValue_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_reset_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_ResetWithDefaults_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_Disable_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_self_test_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_revision_query_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_error_query_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_error_message_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_InvalidateAllAttributes_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_GetChannelName_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_viWrite_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_viRead_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_WriteInstrData_DefaultParameter);
        
    CPPUNIT_TEST(test_tkafg3k_ReadInstrData_DefaultParameter);

    /***** End of API Testing *****/

	CPPUNIT_TEST_SUITE_END();

public:
	void setUp();
	void tearDown();	
	

	void testTKAFG3K_ATTR_OUTPUT_MODE_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index2();

	void testTKAFG3K_ATTR_REF_CLOCK_SOURCE_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_REF_CLOCK_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_REF_CLOCK_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index2();

	void testTKAFG3K_ATTR_ARB_SAMPLE_RATE_defaultValue_ReadWrite_NullChannel_Index0();

	void testTKAFG3K_ATTR_MAX_NUM_WAVEFORMS_defaultValue_ReadOnly_NullChannel_Index0();

	void testTKAFG3K_ATTR_WAVEFORM_QUANTUM_defaultValue_ReadOnly_NullChannel_Index0();

	void testTKAFG3K_ATTR_MIN_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0();

	void testTKAFG3K_ATTR_MAX_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0();

	void testTKAFG3K_ATTR_ACTIVE_MEMORY_defaultValue_ReadWrite_NullChannel_Index0();

	void testTKAFG3K_ATTR_TRIGGER_MODE_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_TRIGGER_MODE_DiscreteValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_TRIGGER_MODE_DiscreteValue_ReadWrite_NullChannel_Index2();

	void testTKAFG3K_ATTR_TRIGGER_SLOPE_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index2();

	void testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_CloseminimumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ClosemaximumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_RandomValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ViolationMinValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ViolationMaxValue_ReadWrite_NullChannel_Index1();

	void testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_CloseminimumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ClosemaximumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_RandomValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ViolationMinValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ViolationMaxValue_ReadWrite_NullChannel_Index1();

	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index2();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index3();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index4();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index5();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index6();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index7();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index8();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index9();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index10();
	void testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index11();

	void testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_NullChannel_Index1();

	void testTKAFG3K_ATTR_FM_INTERNAL_DEVIATION_defaultValue_ReadWrite_NullChannel_Index0();

	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index2();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index3();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index4();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index5();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index6();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index7();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index8();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index9();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index10();
	void testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index11();

	void testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_NullChannel_Index0();
	void testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_NullChannel_Index1();
	void testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_NullChannel_Index1();

	void testTKAFG3K_ATTR_ID_QUERY_RESPONSE_defaultValue_ReadOnly_NullChannel_Index0();
        
    void test_tkafg3k_ConfigureActiveMemory_DefaultParameter();
    void test_tkafg3k_ConfigureActiveMemory_activeMemory_Invalid();
        
    void test_tkafg3k_ConfigureOperationMode_DefaultParameter();
    void test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index1();
    void test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index2();
    void test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index3();
    void test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index4();
    void test_tkafg3k_ConfigureOperationMode_operationMode_Invalid();
        
    void test_tkafg3k_ConfigureOutputMode_DefaultParameter();
    void test_tkafg3k_ConfigureOutputMode_outputMode_Valid_Item_Index1();
    void test_tkafg3k_ConfigureOutputMode_outputMode_Valid_Item_Index2();
    void test_tkafg3k_ConfigureOutputMode_outputMode_Invalid();
        
    void test_tkafg3k_ConfigureOutputModeByChannel_DefaultParameter();
    void test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index1();
    void test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index2();
    void test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Invalid();
        
    void test_tkafg3k_ConfigureRefClockSource_DefaultParameter();
    void test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Valid_Item_Index1();
    void test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Valid_Item_Index2();
    void test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Invalid();
        
    void test_tkafg3k_ConfigureOutputImpedance_DefaultParameter();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index2();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index2();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index2(); 
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index2();
    void test_tkafg3k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index2();
        
    void test_tkafg3k_ConfigureOutputEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureOutputEnabled_enabled_TRUE();
    void test_tkafg3k_ConfigureOutputEnabled_enabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureStandardWaveform_DefaultParameter();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index12();
    void test_tkafg3k_ConfigureStandardWaveform_waveform_Invalid();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The amplitude's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The DCOffset's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureRampSymmetry_DefaultParameter();
    void test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigurePulseWaveform_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The dutyCycle's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The leadingEdgeTime's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The trailingEdgeTime's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_ConfigurePulseDelay_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The delay's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_ConfigureSampleRate_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The sampleRate_Samps's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_CreateArbWaveform_DefaultParameter();
        
    void test_tkafg3k_CreateLineInterpolateArbWfm_DefaultParameter();
        
    void test_tkafg3k_CreateStandardShapeArbWfm_DefaultParameter();
        
    void test_tkafg3k_GetArbitraryWaveformBySlot_DefaultParameter();
        
    void test_tkafg3k_CreateArbWaveformBySlot_DefaultParameter();
        
    void test_tkafg3k_CreateLineInterpolateArbWfmBySlot_DefaultParameter();
        
    void test_tkafg3k_CreateStandardShapeArbWfmBySlot_DefaultParameter();
        
    void test_tkafg3k_QueryArbWfmCapabilities_DefaultParameter();
        
    void test_tkafg3k_ConfigureArbWaveform_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The gain_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The offset_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_ClearArbWaveform_DefaultParameter();
        
    void test_tkafg3k_ClearArbWaveformBySlot_DefaultParameter();
        
    void test_tkafg3k_ConfigureArbFrequency_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_ConfigureTriggerSource_DefaultParameter();
    void test_tkafg3k_ConfigureTriggerSource_triggerSource_Valid_Item_Index1();
    void test_tkafg3k_ConfigureTriggerSource_triggerSource_Valid_Item_Index2();
    void test_tkafg3k_ConfigureTriggerSource_triggerSource_Invalid();
        
    void test_tkafg3k_ForceTrigger_DefaultParameter();
        
    void test_tkafg3k_ConfigureTriggerOutputMode_DefaultParameter();
    void test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Valid_Item_Index1();
    void test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Valid_Item_Index2();
    void test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Invalid();
        
    void test_tkafg3k_ConfigureInternalTriggerRate_DefaultParameter();
    void test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureExternalTriggerSlope_DefaultParameter();
    void test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Valid_Item_Index1();
    void test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Valid_Item_Index2();
    void test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Invalid();
        
    void test_tkafg3k_ConfigureBurstDelay_DefaultParameter();
    void test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureBurstEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureBurstEnabled_burstEnabled_TRUE();
    void test_tkafg3k_ConfigureBurstEnabled_burstEnabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureBurstCount_DefaultParameter();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index2();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index2();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index2(); 
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index2();
    void test_tkafg3k_ConfigureBurstCount_burstCount_RangeRandomValue_Index2();
        
    void test_tkafg3k_ConfigureBurstMode_DefaultParameter();
    void test_tkafg3k_ConfigureBurstMode_burstMode_Valid_Item_Index1();
    void test_tkafg3k_ConfigureBurstMode_burstMode_Valid_Item_Index2();
    void test_tkafg3k_ConfigureBurstMode_burstMode_Invalid();
        
    void test_tkafg3k_ConfigureSweepEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureSweepEnabled_sweepEnabled_TRUE();
    void test_tkafg3k_ConfigureSweepEnabled_sweepEnabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureSweep_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The stopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigureSweep_time_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweep_time_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweep_time_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureSweep_time_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureSweep_time_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureSweep_type_Valid_Item_Index1();
    void test_tkafg3k_ConfigureSweep_type_Valid_Item_Index2();
    void test_tkafg3k_ConfigureSweep_type_Invalid();
        
    void test_tkafg3k_ConfigureSweepEx_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The stopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigureSweepEx_time_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_time_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_time_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureSweepEx_time_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_time_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_holdTime_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_holdTime_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_holdTime_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureSweepEx_holdTime_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_holdTime_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_returnTime_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_returnTime_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_returnTime_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureSweepEx_returnTime_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_returnTime_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureSweepEx_type_Valid_Item_Index1();
    void test_tkafg3k_ConfigureSweepEx_type_Valid_Item_Index2();
    void test_tkafg3k_ConfigureSweepEx_type_Invalid();
        
    void test_tkafg3k_ConfigureSweepMode_DefaultParameter();
    void test_tkafg3k_ConfigureSweepMode_sweepMode_Valid_Item_Index1();
    void test_tkafg3k_ConfigureSweepMode_sweepMode_Valid_Item_Index2();
    void test_tkafg3k_ConfigureSweepMode_sweepMode_Invalid();
        
    void test_tkafg3k_ConfigureNoiseAppendantEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureNoiseAppendantEnabled_noiseAppendantEnabled_TRUE();
    void test_tkafg3k_ConfigureNoiseAppendantEnabled_noiseAppendantEnabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureNoiseLevel_DefaultParameter();
    void test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureExternalAppendEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureExternalAppendEnabled_externalAppendantEnabled_TRUE();
    void test_tkafg3k_ConfigureExternalAppendEnabled_externalAppendantEnabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureAMEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureAMEnabled_enabled_TRUE();
    void test_tkafg3k_ConfigureAMEnabled_enabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureAMSource_DefaultParameter();
    void test_tkafg3k_ConfigureAMSource_source_Valid_Item_Index1();
    void test_tkafg3k_ConfigureAMSource_source_Valid_Item_Index2();
    void test_tkafg3k_ConfigureAMSource_source_Invalid();
        
    void test_tkafg3k_ConfigureAMInternal_DefaultParameter();
    void test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigureAMInternal_modulationWaveform_Invalid();
    void test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureAMInternalByChannel_DefaultParameter();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Invalid();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureAMExternalByChannel_DefaultParameter();
    void test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureFMEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureFMEnabled_enabled_TRUE();
    void test_tkafg3k_ConfigureFMEnabled_enabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureFMSource_DefaultParameter();
    void test_tkafg3k_ConfigureFMSource_source_Valid_Item_Index1();
    void test_tkafg3k_ConfigureFMSource_source_Valid_Item_Index2();
    void test_tkafg3k_ConfigureFMSource_source_Invalid();
        
    void test_tkafg3k_ConfigureFMInternal_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigureFMInternal_modulationWaveform_Invalid();
    void test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureFMInternalByChannel_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Invalid();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureFMExternalByChannel_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_ConfigurePMEnabled_DefaultParameter();
    void test_tkafg3k_ConfigurePMEnabled_enabled_TRUE();
    void test_tkafg3k_ConfigurePMEnabled_enabled_FALSE();  
        
        
    void test_tkafg3k_ConfigurePMSource_DefaultParameter();
    void test_tkafg3k_ConfigurePMSource_source_Valid_Item_Index1();
    void test_tkafg3k_ConfigurePMSource_source_Valid_Item_Index2();
    void test_tkafg3k_ConfigurePMSource_source_Invalid();
        
    void test_tkafg3k_ConfigurePMInternalByChannel_DefaultParameter();
    void test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeRandomValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Invalid();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigurePMExternalByChannel_DefaultParameter();
    void test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureFSKEnabled_DefaultParameter();
    void test_tkafg3k_ConfigureFSKEnabled_enabled_TRUE();
    void test_tkafg3k_ConfigureFSKEnabled_enabled_FALSE();  
        
        
    void test_tkafg3k_ConfigureFSKSource_DefaultParameter();
    void test_tkafg3k_ConfigureFSKSource_source_Valid_Item_Index1();
    void test_tkafg3k_ConfigureFSKSource_source_Valid_Item_Index2();
    void test_tkafg3k_ConfigureFSKSource_source_Invalid();
        
    void test_tkafg3k_ConfigureFSKInternalByChannel_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigureFSKExternalByChannel_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_ConfigurePWMEnabled_DefaultParameter();
    void test_tkafg3k_ConfigurePWMEnabled_enabled_TRUE();
    void test_tkafg3k_ConfigurePWMEnabled_enabled_FALSE();  
        
        
    void test_tkafg3k_ConfigurePWMSource_DefaultParameter();
    void test_tkafg3k_ConfigurePWMSource_source_Valid_Item_Index1();
    void test_tkafg3k_ConfigurePWMSource_source_Valid_Item_Index2();
    void test_tkafg3k_ConfigurePWMSource_source_Invalid();
        
    void test_tkafg3k_ConfigurePWMInternalByChannel_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index1();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index2();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index3();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index4();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index5();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index6();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index7();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index8();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index9();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index10();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index11();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Invalid();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1(); 
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1();
    void test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1();
        
    void test_tkafg3k_ConfigurePWMExternalByChannel_DefaultParameter();
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Percent's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
        
    void test_tkafg3k_InitiateGeneration_DefaultParameter();
        
    void test_tkafg3k_AbortGeneration_DefaultParameter();
        
    void test_tkafg3k_CopyWfmDataBetweenEditMemory_DefaultParameter();
        
    void test_tkafg3k_SaveLoadInstrumentSettings_DefaultParameter();
        
    void test_tkafg3k_SaveLoadWaveformData_DefaultParameter();
        
    void test_tkafg3k_SetGetWaveformPointValue_DefaultParameter();
        
    void test_tkafg3k_reset_DefaultParameter();
        
    void test_tkafg3k_ResetWithDefaults_DefaultParameter();
        
    void test_tkafg3k_Disable_DefaultParameter();
        
    void test_tkafg3k_self_test_DefaultParameter();
        
    void test_tkafg3k_revision_query_DefaultParameter();
        
    void test_tkafg3k_error_query_DefaultParameter();
        
    void test_tkafg3k_error_message_DefaultParameter();
        
    void test_tkafg3k_InvalidateAllAttributes_DefaultParameter();
        
    void test_tkafg3k_GetChannelName_DefaultParameter();
        
    void test_tkafg3k_viWrite_DefaultParameter();
        
    void test_tkafg3k_viRead_DefaultParameter();
        
    void test_tkafg3k_WriteInstrData_DefaultParameter();
        
    void test_tkafg3k_ReadInstrData_DefaultParameter();
};
	