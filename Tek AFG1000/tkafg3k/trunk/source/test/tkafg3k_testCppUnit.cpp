#include  "tkafg3k_testCppUnit.h"
#include "tkafg3k.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

#define INVALID_ENUM_VALUE    -5000   /*Invalid enum parameter value*/

CPPUNIT_TEST_SUITE_REGISTRATION(DriverFunctionalityTest);
/****************************************************************************
 *------------------------------- Global Variable --------------------------*
 ****************************************************************************/
ViSession vi = VI_NULL;

ViStatus testInit()
{
	ViStatus error = VI_SUCCESS;

	if ( vi == NULL)
	{
		checkErr(tkafg3k_InitWithOptions ("landis",VI_TRUE,VI_TRUE,"Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1",&vi));	
	}
	else
	{
		checkErr(tkafg3k_reset(vi));
	}
Error:
	return error;
}

void testClose()
{
	tkafg3k_close(vi);
	vi = VI_NULL;
}

void DriverFunctionalityTest::setUp()
{
	testInit();
}

void DriverFunctionalityTest::tearDown(){}

/****************************************************************************
 *------------------------- Attribute Test --------------------------------*
 ****************************************************************************/
	

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_OUTPUT_MODE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_OUTPUT_MODE ;
	ViInt32 defaultValue = TKAFG3K_VAL_OUTPUT_FUNC ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_OUTPUT_MODE ;
	ViInt32 discreteValue = TKAFG3K_VAL_OUTPUT_FUNC ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG3K_ATTR_OUTPUT_MODE ;
	ViInt32 discreteValue = TKAFG3K_VAL_OUTPUT_ARB ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_REF_CLOCK_SOURCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_REF_CLOCK_SOURCE ;
	ViInt32 defaultValue = TKAFG3K_VAL_REF_CLOCK_INTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_REF_CLOCK_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_REF_CLOCK_SOURCE ;
	ViInt32 discreteValue = TKAFG3K_VAL_REF_CLOCK_INTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_REF_CLOCK_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG3K_ATTR_REF_CLOCK_SOURCE ;
	ViInt32 discreteValue = TKAFG3K_VAL_REF_CLOCK_EXTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_ARB_SAMPLE_RATE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_ARB_SAMPLE_RATE ;
	/* AFG3252 default value */
	ViReal64 defaultValue = 2000000000.0 ;	
	ViReal64 returnValue;
	
	/* Note: This attribute is readonly. It requires to set OUTPUT_MODE to ARB before read.
	 */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, TKAFG3K_ATTR_OUTPUT_MODE, 0, TKAFG3K_VAL_OUTPUT_ARB));
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
		
/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read Only
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_MAX_NUM_WAVEFORMS_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG3K_ATTR_MAX_NUM_WAVEFORMS ;
	ViInt32 returnValue;
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));	
}
			
		
/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read Only
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_WAVEFORM_QUANTUM_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG3K_ATTR_WAVEFORM_QUANTUM ;
	ViInt32 returnValue;
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));	
}
			
		
/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read Only
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_MIN_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG3K_ATTR_MIN_WAVEFORM_SIZE ;
	ViInt32 returnValue;
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));	
}
			
		
/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read Only
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_MAX_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG3K_ATTR_MAX_WAVEFORM_SIZE ;
	ViInt32 returnValue;
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_ACTIVE_MEMORY_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_ACTIVE_MEMORY ;
	ViInt32 defaultValue = TKAFG3K_VAL_OUTPUT_EMEM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_TRIGGER_MODE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_TRIGGER_MODE ;
	ViInt32 defaultValue = TKAFG3K_VAL_TRIGGER_TRIGGER ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_TRIGGER_MODE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_TRIGGER_MODE ;
	ViInt32 discreteValue = TKAFG3K_VAL_TRIGGER_TRIGGER ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_TRIGGER_MODE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG3K_ATTR_TRIGGER_MODE ;
	ViInt32 discreteValue = TKAFG3K_VAL_TRIGGER_SYNC ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_TRIGGER_SLOPE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_TRIGGER_SLOPE ;
	ViInt32 defaultValue = TKAFG3K_VAL_TRIGGER_POSITIVE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_TRIGGER_SLOPE ;
	ViInt32 discreteValue = TKAFG3K_VAL_TRIGGER_POSITIVE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_TRIGGER_SLOPE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG3K_ATTR_TRIGGER_SLOPE ;
	ViInt32 discreteValue = TKAFG3K_VAL_TRIGGER_NEGATIVE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE ;
	ViReal64 defaultValue = 1000.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE ;
	ViReal64 CloseminimumValue = 0.002 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE ;
	ViReal64 ClosemaximumValue = 1000000.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE ;
	ViReal64 returnValue;
    
    ViReal64 randomValue = 0.002 + rand() % 100 * 999999.998 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));

	/* Note: This command is has a coerced parameter, but the driver didn't implement it as an coerced attribute. 
	 * So this test might be failed.
	 */	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE;
	ViReal64 ViolationValue = -0.998 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testTKAFG3K_ATTR_INTERNAL_TRIGGER_RATE_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_INTERNAL_TRIGGER_RATE;
	ViReal64 ViolationValue = 1.000001E6 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_DEPTH ;
	ViReal64 defaultValue = 50.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_DEPTH ;
	ViReal64 CloseminimumValue = 0.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_DEPTH ;
	ViReal64 ClosemaximumValue = 120.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_DEPTH ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.00 + rand() % 100 * 120 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_DEPTH_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ViolationValue = 121 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 defaultValue = TKAFG3K_VAL_AM_INTERNAL_SINE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_SINE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_SQUARE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_TRIANGLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_RAMP_UP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_RAMP_DOWN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_PRN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_USER1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_USER2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index9()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_USER3 ;	
	ViInt32 returnValue;

	/* Note: On some model the specific User3 does not exist. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index10()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_USER4 ;	
	ViInt32 returnValue;

	/* Note: On some model the specific User4 does not exist. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index11()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_AM_INTERNAL_EMEM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY ;
	ViReal64 defaultValue = 10000.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY ;
	ViReal64 CloseminimumValue = 0.002 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY ;
	ViReal64 ClosemaximumValue = 50000.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testTKAFG3K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 50001 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_DEVIATION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_DEVIATION ;
	ViReal64 defaultValue = 100000.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 defaultValue = TKAFG3K_VAL_FM_INTERNAL_SINE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_SINE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_SQUARE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_TRIANGLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_RAMP_UP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_RAMP_DOWN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_PRN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_USER1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_USER2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index9()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_USER3 ;	
	ViInt32 returnValue;

	/* Note: In some model, the user3 doesn't existed. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index10()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_USER4 ;	
	ViInt32 returnValue;

	/* Note: In some model, the user4 doesn't existed. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_NullChannel_Index11()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_WAVEFORM ;
	ViInt32 discreteValue = TKAFG3K_VAL_FM_INTERNAL_EMEM ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY ;
	ViReal64 defaultValue = 10000.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY ;
	ViReal64 CloseminimumValue = 0.002 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY ;
	ViReal64 ClosemaximumValue = 50000.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY ;
	ViReal64 returnValue;
      
    ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;
          
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, VI_NULL, attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testTKAFG3K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG3K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 50001 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, VI_NULL, attributeId, 0, ViolationValue));
}
		
		
/****************************************************************************
 * Default Value Test	  												    
 * ViString
 * Read Only
 ****************************************************************************/		
void DriverFunctionalityTest::testTKAFG3K_ATTR_ID_QUERY_RESPONSE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG3K_ATTR_ID_QUERY_RESPONSE ;
		
	ViInt32 buf_size = 1024;
	ViChar returnValue[1024];

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViString (vi, VI_NULL, attributeId, 0, buf_size, returnValue));	
}
			

/****************************************************************************
 *------------------------- Function Test ---------------------------------*
 ****************************************************************************/
    
 
/****************************************************************************
 * tkafg3k_ConfigureActiveMemory Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureActiveMemory_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureActiveMemory(vi, TKAFG3K_VAL_OUTPUT_EMEM));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureActiveMemory Ring Parameter "activeMemory" Test  
 ****************************************************************************/
            
/****************************************************************************
 * activeMemory Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureActiveMemory_activeMemory_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureActiveMemory(vi, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureOperationMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOperationMode_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOperationMode(vi, "1", TKAFG3K_VAL_OPERATE_CONTINUOUS));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureOperationMode Ring Parameter "operationMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * operationMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOperationMode(vi, "1", TKAFG3K_VAL_OPERATE_CONTINUOUS));
}
                    
/****************************************************************************
 * operationMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOperationMode(vi, "1", TKAFG3K_VAL_OPERATE_MODULATION));
}
                    
/****************************************************************************
 * operationMode Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOperationMode(vi, "1", TKAFG3K_VAL_OPERATE_SWEEP));
}
                    
/****************************************************************************
 * operationMode Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOperationMode_operationMode_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOperationMode(vi, "1", TKAFG3K_VAL_OPERATE_BURST));
}
                    
/****************************************************************************
 * operationMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOperationMode_operationMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOperationMode(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureOutputMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputMode_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputMode(vi, TKAFG3K_VAL_OUTPUT_FUNC));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureOutputMode Ring Parameter "outputMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * outputMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputMode_outputMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputMode(vi, TKAFG3K_VAL_OUTPUT_FUNC));
}
                    
/****************************************************************************
 * outputMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputMode_outputMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputMode(vi, TKAFG3K_VAL_OUTPUT_ARB));
}
                    
/****************************************************************************
 * outputMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputMode_outputMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOutputMode(vi, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureOutputModeByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputModeByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel(vi, "1", TKAFG3K_VAL_OUTPUT_FUNC));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureOutputModeByChannel Ring Parameter "outputMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * outputMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel(vi, "1", TKAFG3K_VAL_OUTPUT_FUNC));
}
                    
/****************************************************************************
 * outputMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputModeByChannel(vi, "1", TKAFG3K_VAL_OUTPUT_ARB));
}
                    
/****************************************************************************
 * outputMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputModeByChannel_outputMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOutputModeByChannel(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureRefClockSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRefClockSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRefClockSource(vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureRefClockSource Ring Parameter "referenceClockSource" Test  
 ****************************************************************************/
            
/****************************************************************************
 * referenceClockSource Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRefClockSource(vi, TKAFG3K_VAL_REF_CLOCK_INTERNAL));
}
                    
/****************************************************************************
 * referenceClockSource Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRefClockSource(vi, TKAFG3K_VAL_REF_CLOCK_EXTERNAL));
}
                    
/****************************************************************************
 * referenceClockSource Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRefClockSource_referenceClockSource_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureRefClockSource(vi, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureOutputImpedance Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", 50.0));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureOutputImpedance Ranged Parameter "impedance" Test  
 ****************************************************************************/
                
/****************************************************************************
 * impedance Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", minimumValue));
}

/****************************************************************************
 * impedance Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOutputImpedance(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * impedance Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", maximumValue));
}

/****************************************************************************
 * impedance Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 10001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOutputImpedance(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * impedance Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 0 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", randomValue));
}
                
/****************************************************************************
 * impedance Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index2()                
{
    ViReal64 minimumValue = 1.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", minimumValue));
}

/****************************************************************************
 * impedance Range Below Minimum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index2()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOutputImpedance(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * impedance Range Maximum Value Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index2()                
{
    ViReal64 maximumValue = 10000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", maximumValue));
}

/****************************************************************************
 * impedance Range Above Maximum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index2()                
{
    ViReal64 aboveMaximumValue = 10001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureOutputImpedance(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * impedance Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index2()                
{
	 
	ViReal64 randomValue = 1.0 + rand() % 100 * 9999 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputImpedance(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureOutputEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureOutputEnabled Boolean Parameter "enabled" Test  
 ****************************************************************************/
/****************************************************************************
 * enabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputEnabled_enabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * enabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureOutputEnabled_enabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureOutputEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureStandardWaveform Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, 0.00));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureStandardWaveform Ring Parameter "waveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * waveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SQUARE, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_DC, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_RAMP, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_PULS, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_PRN, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINC, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_GAUS, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_LOR, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_ERIS, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_EDEC, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Valid Item Test Index12
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Valid_Item_Index12()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_HAV, 1.00, 0.00, 1000000.00, 0.00));
}
                    
/****************************************************************************
 * waveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_waveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureStandardWaveform(vi, "1", INVALID_ENUM_VALUE, 1.00, 0.00, 1000000.00, 0.00));
}    
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The amplitude's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The DCOffset's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                                
/****************************************************************************
 * tkafg3k_ConfigureStandardWaveform Ranged Parameter "startPhase" Test  
 ****************************************************************************/
                
/****************************************************************************
 * startPhase Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = -180.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, minimumValue));
}

/****************************************************************************
 * startPhase Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -181 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, belowMinimumValue));
}
                
/****************************************************************************
 * startPhase Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 180.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, maximumValue));
}

/****************************************************************************
 * startPhase Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 181 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, aboveMaximumValue));
}
                
/****************************************************************************
 * startPhase Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureStandardWaveform_startPhase_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = -180.00 + rand() % 100 * 360 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureStandardWaveform(vi, "1", TKAFG3K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureRampSymmetry Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRampSymmetry_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRampSymmetry(vi, "1", 50.0));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureRampSymmetry Ranged Parameter "rampSymmetry" Test  
 ****************************************************************************/
                
/****************************************************************************
 * rampSymmetry Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRampSymmetry(vi, "1", minimumValue));
}

/****************************************************************************
 * rampSymmetry Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureRampSymmetry(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * rampSymmetry Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 100.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRampSymmetry(vi, "1", maximumValue));
}

/****************************************************************************
 * rampSymmetry Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 101 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureRampSymmetry(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * rampSymmetry Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureRampSymmetry_rampSymmetry_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 100 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureRampSymmetry(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigurePulseWaveform Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePulseWaveform_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS));

    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePulseWaveform(vi, "1", 50, 5.0e-8, 5.0e-8));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The dutyCycle's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The leadingEdgeTime's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The trailingEdgeTime's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ConfigurePulseDelay Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePulseDelay_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, 0, TKAFG3K_VAL_WFM_PULS));
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePulseDelay(vi, "1", 0.0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The delay's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ConfigureSampleRate Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSampleRate_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSampleRate(vi, 1000000000.0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The sampleRate_Samps's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_CreateArbWaveform Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CreateArbWaveform_DefaultParameter()
{
    ViInt32 waveformHandle;
	ViReal64 wfm [1000] = {0.1};
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateArbWaveform(vi, 1000, wfm, &waveformHandle));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveform(vi, waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_CreateLineInterpolateArbWfm Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CreateLineInterpolateArbWfm_DefaultParameter()
{
    ViInt32 waveformHandle;

    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfm(vi, 1000, 0.0, 1, &waveformHandle));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveform(vi, waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startPointData's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The endPointData's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_CreateStandardShapeArbWfm Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CreateStandardShapeArbWfm_DefaultParameter()
{
    ViInt32 waveformHandle;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfm(vi, 1000, 0, &waveformHandle));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveform(vi, waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformType's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_GetArbitraryWaveformBySlot Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_GetArbitraryWaveformBySlot_DefaultParameter()
{
    ViInt32 waveformHandle;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_GetArbitraryWaveformBySlot(vi, 0, &waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_CreateArbWaveformBySlot Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CreateArbWaveformBySlot_DefaultParameter()
{
    ViInt32 waveformHandle;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateArbWaveformBySlot(vi, 0, 0, VI_NULL, VI_FALSE, &waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_CreateLineInterpolateArbWfmBySlot Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CreateLineInterpolateArbWfmBySlot_DefaultParameter()
{
    ViInt32 waveformHandle;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateLineInterpolateArbWfmBySlot(vi, 0, 0, 0.0, 0.0, VI_FALSE, &waveformHandle));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveformBySlot(vi, waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startPointData's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The endPointData's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_CreateStandardShapeArbWfmBySlot Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CreateStandardShapeArbWfmBySlot_DefaultParameter()
{
    ViInt32 waveformHandle;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateStandardShapeArbWfmBySlot(vi, 0, 0, 0, VI_FALSE, &waveformHandle));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveformBySlot(vi, waveformHandle));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformType's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_QueryArbWfmCapabilities Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_QueryArbWfmCapabilities_DefaultParameter()
{
    ViInt32 maximumNumberOfWaveforms;
    ViInt32 waveformQuantum;
    ViInt32 minimumWaveformSize;
    ViInt32 maximumWaveformSize;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_QueryArbWfmCapabilities(vi, &maximumNumberOfWaveforms, &waveformQuantum, &minimumWaveformSize, &maximumWaveformSize));
}
 
    
 
/****************************************************************************
 * tkafg3k_ConfigureArbWaveform Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureArbWaveform_DefaultParameter()
{
    ViInt32 waveformHandle;
	ViReal64 wfm [1000] = {0.1};
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CreateArbWaveform(vi, 1000, wfm, &waveformHandle));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureArbWaveform(vi, "1", waveformHandle, 0.5, 0.00));
	CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveform(vi, waveformHandle));
}
 
              
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The gain_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The offset_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ClearArbWaveform Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ClearArbWaveform_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveform(vi, 0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformHandle's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ClearArbWaveformBySlot Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ClearArbWaveformBySlot_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ClearArbWaveformBySlot(vi, 0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ConfigureArbFrequency Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureArbFrequency_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureArbFrequency(vi, "1", 1000000.00));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ConfigureTriggerSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureTriggerSource(vi, "1", TKAFG3K_VAL_INTERNAL_TRIGGER));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureTriggerSource Ring Parameter "triggerSource" Test  
 ****************************************************************************/
            
/****************************************************************************
 * triggerSource Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerSource_triggerSource_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureTriggerSource(vi, "1", TKAFG3K_VAL_INTERNAL_TRIGGER));
}
                    
/****************************************************************************
 * triggerSource Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerSource_triggerSource_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureTriggerSource(vi, "1", TKAFG3K_VAL_EXTERNAL));
}
                    
/****************************************************************************
 * triggerSource Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerSource_triggerSource_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureTriggerSource(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ForceTrigger Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ForceTrigger_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ForceTrigger(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_ConfigureTriggerOutputMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerOutputMode_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureTriggerOutputMode(vi, TKAFG3K_VAL_OUTPUT_FUNC));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureTriggerOutputMode Ring Parameter "outputMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * outputMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureTriggerOutputMode(vi, TKAFG3K_VAL_OUTPUT_FUNC));
}
                    
/****************************************************************************
 * outputMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureTriggerOutputMode(vi, TKAFG3K_VAL_OUTPUT_ARB));
}
                    
/****************************************************************************
 * outputMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureTriggerOutputMode_outputMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureTriggerOutputMode(vi, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureInternalTriggerRate Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureInternalTriggerRate_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate(vi, 1000.0));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureInternalTriggerRate Ranged Parameter "triggerRate" Test  
 ****************************************************************************/
                
/****************************************************************************
 * triggerRate Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate(vi, minimumValue));
}

/****************************************************************************
 * triggerRate Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureInternalTriggerRate(vi, belowMinimumValue));
}
                
/****************************************************************************
 * triggerRate Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 1000000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate(vi, maximumValue));
}

/****************************************************************************
 * triggerRate Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 1.000001E6 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureInternalTriggerRate(vi, aboveMaximumValue));
}
                
/****************************************************************************
 * triggerRate Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureInternalTriggerRate_triggerRate_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 999999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureInternalTriggerRate(vi, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureExternalTriggerSlope Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalTriggerSlope_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope(vi, TKAFG3K_VAL_TRIGGER_POSITIVE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureExternalTriggerSlope Ring Parameter "triggerSlope" Test  
 ****************************************************************************/
            
/****************************************************************************
 * triggerSlope Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope(vi, TKAFG3K_VAL_TRIGGER_POSITIVE));
}
                    
/****************************************************************************
 * triggerSlope Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureExternalTriggerSlope(vi, TKAFG3K_VAL_TRIGGER_NEGATIVE));
}
                    
/****************************************************************************
 * triggerSlope Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalTriggerSlope_triggerSlope_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureExternalTriggerSlope(vi, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureBurstDelay Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstDelay_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstDelay(vi, "1", 0));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureBurstDelay Ranged Parameter "burstDelay" Test  
 ****************************************************************************/
                
/****************************************************************************
 * burstDelay Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstDelay(vi, "1", minimumValue));
}

/****************************************************************************
 * burstDelay Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstDelay(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * burstDelay Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 85 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstDelay(vi, "1", maximumValue));
}

/****************************************************************************
 * burstDelay Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 86 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstDelay(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * burstDelay Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstDelay_burstDelay_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 85 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstDelay(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureBurstEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureBurstEnabled Boolean Parameter "burstEnabled" Test  
 ****************************************************************************/
/****************************************************************************
 * burstEnabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstEnabled_burstEnabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * burstEnabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstEnabled_burstEnabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureBurstCount Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", 5));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureBurstCount Ranged Parameter "burstCount" Test  
 ****************************************************************************/
                
/****************************************************************************
 * burstCount Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index1()                
{
    ViInt32 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", minimumValue));
}

/****************************************************************************
 * burstCount Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index1()                
{
    ViInt32 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstCount(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * burstCount Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index1()                
{
    ViInt32 maximumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", maximumValue));
}

/****************************************************************************
 * burstCount Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index1()                
{
    ViInt32 aboveMaximumValue = 1000001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstCount(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * burstCount Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeRandomValue_Index1()                
{
	 
	ViInt32 randomValue = (int)(0 + rand() % 100 * 0 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", randomValue));
}
                
/****************************************************************************
 * burstCount Range Minimum Value Test Index2
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index2()                
{
    ViInt32 minimumValue = 1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", minimumValue));
}

/****************************************************************************
 * burstCount Range Below Minimum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index2()                
{
    ViInt32 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstCount(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * burstCount Range Maximum Value Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index2()                
{
    ViInt32 maximumValue = 1000000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", maximumValue));
}

/****************************************************************************
 * burstCount Range Above Maximum Value Test Index2
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index2()                
{
    ViInt32 aboveMaximumValue = 1.000001E6 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstCount(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * burstCount Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstCount_burstCount_RangeRandomValue_Index2()                
{
	 
	ViInt32 randomValue = (int)(1 + rand() % 100 * 999999 / 100.00);
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstCount(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureBurstMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstMode_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstMode(vi, "1", TKAFG3K_VAL_BURST_TRIGGER));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureBurstMode Ring Parameter "burstMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * burstMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstMode_burstMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstMode(vi, "1", TKAFG3K_VAL_BURST_TRIGGER));
}
                    
/****************************************************************************
 * burstMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstMode_burstMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureBurstMode(vi, "1", TKAFG3K_VAL_BURST_GATE));
}
                    
/****************************************************************************
 * burstMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureBurstMode_burstMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureBurstMode(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureSweepEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureSweepEnabled Boolean Parameter "sweepEnabled" Test  
 ****************************************************************************/
/****************************************************************************
 * sweepEnabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEnabled_sweepEnabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * sweepEnabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEnabled_sweepEnabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureSweep Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, 0.01, TKAFG3K_VAL_SWEEP_LINEAR));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The stopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                                
/****************************************************************************
 * tkafg3k_ConfigureSweep Ranged Parameter "time" Test  
 ****************************************************************************/
                
/****************************************************************************
 * time Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_time_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, minimumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * time Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_time_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.999 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, belowMinimumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * time Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_time_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 300 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, maximumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * time Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_time_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 301 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, aboveMaximumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * time Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_time_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.001 + rand() % 100 * 299.999 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, randomValue, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * tkafg3k_ConfigureSweep Ring Parameter "type" Test  
 ****************************************************************************/
            
/****************************************************************************
 * type Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_type_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, 0.01, TKAFG3K_VAL_SWEEP_LINEAR));
}
                    
/****************************************************************************
 * type Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_type_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, 0.01, TKAFG3K_VAL_SWEEP_LOGARITHMIC));
}
                    
/****************************************************************************
 * type Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweep_type_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweep(vi, "1", 100000, 1000000, 0.01, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureSweepEx Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The startFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The stopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                                
/****************************************************************************
 * tkafg3k_ConfigureSweepEx Ranged Parameter "time" Test  
 ****************************************************************************/
                
/****************************************************************************
 * time Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_time_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, minimumValue, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * time Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_time_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.999 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, belowMinimumValue, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * time Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_time_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 300 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, maximumValue, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * time Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_time_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 301 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, aboveMaximumValue, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * time Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_time_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.001 + rand() % 100 * 299.999 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, randomValue, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                                
/****************************************************************************
 * tkafg3k_ConfigureSweepEx Ranged Parameter "holdTime" Test  
 ****************************************************************************/
                
/****************************************************************************
 * holdTime Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_holdTime_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, minimumValue, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * holdTime Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_holdTime_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, belowMinimumValue, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * holdTime Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_holdTime_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 300.001 - 0.001 - 0.01 ;
    /*
	 * time + holdTime + returnTime <= 300.001
	 */
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, maximumValue, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * holdTime Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_holdTime_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 301 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, aboveMaximumValue, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * holdTime Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_holdTime_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 300 / 100.00;	
	/*
	 * time + holdTime + returnTime <= 300.001
	 */
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, randomValue, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                                
/****************************************************************************
 * tkafg3k_ConfigureSweepEx Ranged Parameter "returnTime" Test  
 ****************************************************************************/
                
/****************************************************************************
 * returnTime Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_returnTime_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, minimumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * returnTime Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_returnTime_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, belowMinimumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * returnTime Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_returnTime_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 300.001 - 0 - 0.01 ;
    /*
	 * time + holdTime + returnTime <= 300.001
	 */
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, maximumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}

/****************************************************************************
 * returnTime Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_returnTime_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 301 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, aboveMaximumValue, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * returnTime Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_returnTime_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 300 / 100.00;	
	/*
	 * time + holdTime + returnTime <= 300.001
	 */
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, randomValue, TKAFG3K_VAL_SWEEP_LINEAR));
}
                
/****************************************************************************
 * tkafg3k_ConfigureSweepEx Ring Parameter "type" Test  
 ****************************************************************************/
            
/****************************************************************************
 * type Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_type_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, 0.001, TKAFG3K_VAL_SWEEP_LINEAR));
}
                    
/****************************************************************************
 * type Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_type_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, 0.001, TKAFG3K_VAL_SWEEP_LOGARITHMIC));
}
                    
/****************************************************************************
 * type Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepEx_type_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepEx(vi, "1", 100000, 1000000, 0.01, 0, 0.001, INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureSweepMode Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepMode_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepMode(vi, "1", TKAFG3K_VAL_SWEEP_AUTO));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureSweepMode Ring Parameter "sweepMode" Test  
 ****************************************************************************/
            
/****************************************************************************
 * sweepMode Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepMode_sweepMode_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepMode(vi, "1", TKAFG3K_VAL_SWEEP_AUTO));
}
                    
/****************************************************************************
 * sweepMode Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepMode_sweepMode_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureSweepMode(vi, "1", TKAFG3K_VAL_SWEEP_MANUAL));
}
                    
/****************************************************************************
 * sweepMode Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureSweepMode_sweepMode_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureSweepMode(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureNoiseAppendantEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseAppendantEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseAppendantEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureNoiseAppendantEnabled Boolean Parameter "noiseAppendantEnabled" Test  
 ****************************************************************************/
/****************************************************************************
 * noiseAppendantEnabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseAppendantEnabled_noiseAppendantEnabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseAppendantEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * noiseAppendantEnabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseAppendantEnabled_noiseAppendantEnabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseAppendantEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureNoiseLevel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseLevel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseLevel(vi, "1", 10));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureNoiseLevel Ranged Parameter "noiseLevel" Test  
 ****************************************************************************/
                
/****************************************************************************
 * noiseLevel Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseLevel(vi, "1", minimumValue));
}

/****************************************************************************
 * noiseLevel Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureNoiseLevel(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * noiseLevel Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseLevel(vi, "1", maximumValue));
}

/****************************************************************************
 * noiseLevel Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 51 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureNoiseLevel(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * noiseLevel Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureNoiseLevel_noiseLevel_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 50 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureNoiseLevel(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureExternalAppendEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalAppendEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureExternalAppendEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureExternalAppendEnabled Boolean Parameter "externalAppendantEnabled" Test  
 ****************************************************************************/
/****************************************************************************
 * externalAppendantEnabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalAppendEnabled_externalAppendantEnabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureExternalAppendEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * externalAppendantEnabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureExternalAppendEnabled_externalAppendantEnabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureExternalAppendEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureAMEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureAMEnabled Boolean Parameter "enabled" Test  
 ****************************************************************************/
/****************************************************************************
 * enabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMEnabled_enabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * enabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMEnabled_enabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureAMSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMSource(vi, "1", TKAFG3K_VAL_AM_INTERNAL));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureAMSource Ring Parameter "source" Test  
 ****************************************************************************/
            
/****************************************************************************
 * source Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMSource_source_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMSource(vi, "1", TKAFG3K_VAL_AM_INTERNAL));
}
                    
/****************************************************************************
 * source Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMSource_source_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMSource(vi, "1", TKAFG3K_VAL_AM_EXTERNAL));
}
                    
/****************************************************************************
 * source Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMSource_source_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMSource(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureAMInternal Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureAMInternal Ranged Parameter "modulationDepth" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationDepth Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, minimumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
 * modulationDepth Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternal(vi, belowMinimumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * modulationDepth Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 120.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, maximumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
 * modulationDepth Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 121 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternal(vi, aboveMaximumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * modulationDepth Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationDepth_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.00 + rand() % 100 * 120 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, randomValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * tkafg3k_ConfigureAMInternal Ring Parameter "modulationWaveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * modulationWaveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SQUARE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_TRIANGLE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_RAMP_UP, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_RAMP_DOWN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_PRN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_USER1, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_USER2, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_USER3, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_USER4, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_EMEM, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationWaveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternal(vi, 50.00, INVALID_ENUM_VALUE, 10000.00));
}    
                                
/****************************************************************************
 * tkafg3k_ConfigureAMInternal Ranged Parameter "modulationFrequency" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationFrequency Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
 * modulationFrequency Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, belowMinimumValue));
}
                
/****************************************************************************
 * modulationFrequency Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50000.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
 * modulationFrequency Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 50001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, aboveMaximumValue));
}
                
/****************************************************************************
 * modulationFrequency Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternal_modulationFrequency_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternal(vi, 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureAMInternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureAMInternalByChannel Ranged Parameter "modulationDepth" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationDepth Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", minimumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
 * modulationDepth Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternalByChannel(vi, "1", belowMinimumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * modulationDepth Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 120.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", maximumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
 * modulationDepth Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 121 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternalByChannel(vi, "1", aboveMaximumValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * modulationDepth Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationDepth_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.00 + rand() % 100 * 120 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", randomValue, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * tkafg3k_ConfigureAMInternalByChannel Ring Parameter "modulationWaveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * modulationWaveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SQUARE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_TRIANGLE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_RAMP_UP, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_RAMP_DOWN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_PRN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_USER1, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_USER2, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_USER3, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_USER4, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_EMEM, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationWaveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, INVALID_ENUM_VALUE, 10000.00));
}    
                                
/****************************************************************************
 * tkafg3k_ConfigureAMInternalByChannel Ranged Parameter "modulationFrequency" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationFrequency Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
 * modulationFrequency Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, belowMinimumValue));
}
                
/****************************************************************************
 * modulationFrequency Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50000.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
 * modulationFrequency Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 50001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, aboveMaximumValue));
}
                
/****************************************************************************
 * modulationFrequency Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMInternalByChannel_modulationFrequency_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG3K_VAL_AM_INTERNAL_SINE, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureAMExternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMExternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMExternalByChannel(vi, "1", 50.00));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigureAMExternalByChannel Ranged Parameter "modulationDepth" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationDepth Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMExternalByChannel(vi, "1", minimumValue));
}

/****************************************************************************
 * modulationDepth Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMExternalByChannel(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * modulationDepth Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 120.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMExternalByChannel(vi, "1", maximumValue));
}

/****************************************************************************
 * modulationDepth Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 121 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureAMExternalByChannel(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * modulationDepth Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureAMExternalByChannel_modulationDepth_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.00 + rand() % 100 * 120 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureAMExternalByChannel(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureFMEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureFMEnabled Boolean Parameter "enabled" Test  
 ****************************************************************************/
/****************************************************************************
 * enabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMEnabled_enabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * enabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMEnabled_enabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureFMSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMSource(vi, "1", TKAFG3K_VAL_FM_INTERNAL));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureFMSource Ring Parameter "source" Test  
 ****************************************************************************/
            
/****************************************************************************
 * source Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMSource_source_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMSource(vi, "1", TKAFG3K_VAL_FM_INTERNAL));
}
                    
/****************************************************************************
 * source Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMSource_source_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMSource(vi, "1", TKAFG3K_VAL_FM_EXTERNAL));
}
                    
/****************************************************************************
 * source Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMSource_source_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMSource(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureFMInternal Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, 10000.00));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/****************************************************************************
 * tkafg3k_ConfigureFMInternal Ring Parameter "modulationWaveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * modulationWaveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index1()
{
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SQUARE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_TRIANGLE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_RAMP_UP, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_RAMP_DOWN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_PRN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_USER1, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_USER2, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_USER3, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_USER4, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_EMEM, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationWaveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMInternal(vi, 100000.0, INVALID_ENUM_VALUE, 10000.00));
}    
                                
/****************************************************************************
 * tkafg3k_ConfigureFMInternal Ranged Parameter "modulationFrequency_Hz" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationFrequency_Hz Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, belowMinimumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 50001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, aboveMaximumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternal_modulationFrequency_Hz_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternal(vi, 100000.0, TKAFG3K_VAL_FM_INTERNAL_SINE, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureFMInternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, 10000.0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/****************************************************************************
 * tkafg3k_ConfigureFMInternalByChannel Ring Parameter "modulationWaveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * modulationWaveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SQUARE, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_TRIANGLE, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_RAMP_UP, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_RAMP_DOWN, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_PRN, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_USER1, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_USER2, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_USER3, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_USER4, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_EMEM, 10000.0));
}
                    
/****************************************************************************
 * modulationWaveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationWaveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, INVALID_ENUM_VALUE, 10000.0));
}    
                                
/****************************************************************************
 * tkafg3k_ConfigureFMInternalByChannel Ranged Parameter "modulationFrequency_Hz" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationFrequency_Hz Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, belowMinimumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50000.0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 50001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, aboveMaximumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMInternalByChannel(vi, "1", 0, TKAFG3K_VAL_FM_INTERNAL_SINE, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureFMExternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFMExternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFMExternalByChannel(vi, "1", 0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ConfigurePMEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigurePMEnabled Boolean Parameter "enabled" Test  
 ****************************************************************************/
/****************************************************************************
 * enabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMEnabled_enabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * enabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMEnabled_enabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigurePMSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMSource(vi, "1", TKAFG3K_VAL_PM_INTERNAL));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigurePMSource Ring Parameter "source" Test  
 ****************************************************************************/
            
/****************************************************************************
 * source Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMSource_source_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMSource(vi, "1", TKAFG3K_VAL_PM_INTERNAL));
}
                    
/****************************************************************************
 * source Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMSource_source_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMSource(vi, "1", TKAFG3K_VAL_PM_EXTERNAL));
}
                    
/****************************************************************************
 * source Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMSource_source_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMSource(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigurePMInternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigurePMInternalByChannel Ranged Parameter "peakDeviation" Test  
 ****************************************************************************/
                
/****************************************************************************
 * peakDeviation Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", minimumValue, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
 * peakDeviation Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMInternalByChannel(vi, "1", belowMinimumValue, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * peakDeviation Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 180 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", maximumValue, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
 * peakDeviation Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 181 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMInternalByChannel(vi, "1", aboveMaximumValue, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * peakDeviation Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_peakDeviation_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 180 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", randomValue, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}
                
/****************************************************************************
 * tkafg3k_ConfigurePMInternalByChannel Ring Parameter "modulationWaveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * modulationWaveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SQUARE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_TRIANGLE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_RAMP_UP, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_RAMP_DOWN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_PRN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_USER1, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_USER2, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_USER3, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index10()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_USER4, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index11()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_EMEM, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationWaveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, INVALID_ENUM_VALUE, 10000.00));
}    
                                
/****************************************************************************
 * tkafg3k_ConfigurePMInternalByChannel Ranged Parameter "modulationFrequency_Hz" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationFrequency_Hz Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, belowMinimumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50000.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 50001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, aboveMaximumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG3K_VAL_PM_INTERNAL_SINE, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigurePMExternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMExternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMExternalByChannel(vi, "1", 90));
}
 
                    
/****************************************************************************
 * tkafg3k_ConfigurePMExternalByChannel Ranged Parameter "peakDeviation" Test  
 ****************************************************************************/
                
/****************************************************************************
 * peakDeviation Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMExternalByChannel(vi, "1", minimumValue));
}

/****************************************************************************
 * peakDeviation Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -1 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMExternalByChannel(vi, "1", belowMinimumValue));
}
                
/****************************************************************************
 * peakDeviation Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 180 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMExternalByChannel(vi, "1", maximumValue));
}

/****************************************************************************
 * peakDeviation Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 181 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePMExternalByChannel(vi, "1", aboveMaximumValue));
}
                
/****************************************************************************
 * peakDeviation Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePMExternalByChannel_peakDeviation_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0 + rand() % 100 * 180 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePMExternalByChannel(vi, "1", randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureFSKEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKEnabled_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureFSKEnabled Boolean Parameter "enabled" Test  
 ****************************************************************************/
/****************************************************************************
 * enabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKEnabled_enabled_TRUE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * enabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKEnabled_enabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigureFSKSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKSource(vi, "1", TKAFG3K_VAL_FSK_INTERNAL));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigureFSKSource Ring Parameter "source" Test  
 ****************************************************************************/
            
/****************************************************************************
 * source Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKSource_source_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKSource(vi, "1", TKAFG3K_VAL_FSK_INTERNAL));
}
                    
/****************************************************************************
 * source Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKSource_source_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKSource(vi, "1", TKAFG3K_VAL_FSK_EXTERNAL));
}
                    
/****************************************************************************
 * source Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKSource_source_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFSKSource(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigureFSKInternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKInternalByChannel_DefaultParameter()
{
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, 50));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                                
/****************************************************************************
 * tkafg3k_ConfigureFSKInternalByChannel Ranged Parameter "internalRate" Test  
 ****************************************************************************/
                
/****************************************************************************
 * internalRate Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, minimumValue));
}

/****************************************************************************
 * internalRate Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, belowMinimumValue));
}
                
/****************************************************************************
 * internalRate Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 1000000 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, maximumValue));
}

/****************************************************************************
 * internalRate Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 1.000001E6 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, aboveMaximumValue));
}
                
/****************************************************************************
 * internalRate Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKInternalByChannel_internalRate_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 999999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigureFSKExternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigureFSKExternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigureFSKExternalByChannel(vi, "1", 1000000.0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_ConfigurePWMEnabled Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMEnabled_DefaultParameter()
{
	// PWM requires Square waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_SQUARE);

    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMEnabled(vi, "1", VI_FALSE));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigurePWMEnabled Boolean Parameter "enabled" Test  
 ****************************************************************************/
/****************************************************************************
 * enabled Boolean TRUE Test
 ****************************************************************************/            
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMEnabled_enabled_TRUE()
{            
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);

    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
 * enabled Boolean FALSE Test
 ****************************************************************************/ 
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMEnabled_enabled_FALSE()
{            
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMEnabled(vi, "1", VI_FALSE));
}
            
 
/****************************************************************************
 * tkafg3k_ConfigurePWMSource Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMSource_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMSource(vi, "1", TKAFG3K_VAL_PWM_INTERNAL));
}
 
    
/****************************************************************************
 * tkafg3k_ConfigurePWMSource Ring Parameter "source" Test  
 ****************************************************************************/
            
/****************************************************************************
 * source Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMSource_source_Valid_Item_Index1()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMSource(vi, "1", TKAFG3K_VAL_PWM_INTERNAL));
}
                    
/****************************************************************************
 * source Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMSource_source_Valid_Item_Index2()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMSource(vi, "1", TKAFG3K_VAL_PWM_EXTERNAL));
}
                    
/****************************************************************************
 * source Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMSource_source_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePWMSource(vi, "1", INVALID_ENUM_VALUE));
}    
                
 
/****************************************************************************
 * tkafg3k_ConfigurePWMInternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_DefaultParameter()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, 10000.00));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/****************************************************************************
 * tkafg3k_ConfigurePWMInternalByChannel Ring Parameter "modulationWaveform" Test  
 ****************************************************************************/
            
/****************************************************************************
 * modulationWaveform Valid Item Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);

	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index2
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{

	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SQUARE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index3
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_TRIANGLE, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index4
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_RAMP_UP, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index5
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_RAMP_DOWN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index6
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_PRN, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index7
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_USER1, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index8
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_USER2, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index9
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_USER3, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index10
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index10()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_USER4, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Valid Item Test Index11
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index11()
{
	// PWM requires TKAFG3K_VAL_WFM_PULS waveform
	tkafg3k_SetAttributeViInt32(vi, "1", TKAFG3K_ATTR_FUNC_WAVEFORM, TKAFG3K_VAL_WFM_PULS);
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_EMEM, 10000.00));
}
                    
/****************************************************************************
 * modulationWaveform Invalid Item Test
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationWaveform_Invalid()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, INVALID_ENUM_VALUE, 10000.00));
}    
                                
/****************************************************************************
 * tkafg3k_ConfigurePWMInternalByChannel Ranged Parameter "modulationFrequency_Hz" Test  
 ****************************************************************************/
                
/****************************************************************************
 * modulationFrequency_Hz Range Minimum Value Test Index1
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1()                
{
    ViReal64 minimumValue = 0.002 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Below Minimum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()                
{
    ViReal64 belowMinimumValue = -0.998 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, belowMinimumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Maximum Value Test Index1
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1()                
{
    ViReal64 maximumValue = 50000.00 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
 * modulationFrequency_Hz Range Above Maximum Value Test Index1
 * Should Fail!  
 ****************************************************************************/	
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()                
{
    ViReal64 aboveMaximumValue = 50001 ;
    
    CPPUNIT_ASSERT(VI_SUCCESS != tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, aboveMaximumValue));
}
                
/****************************************************************************
 * modulationFrequency_Hz Range Random Value Test
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1()                
{
	 
	ViReal64 randomValue = 0.002 + rand() % 100 * 49999.998 / 100.00;	
	
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG3K_VAL_PWM_INTERNAL_SINE, randomValue));
}
                
 
/****************************************************************************
 * tkafg3k_ConfigurePWMExternalByChannel Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ConfigurePWMExternalByChannel_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ConfigurePWMExternalByChannel(vi, "1", 5.0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Percent's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_InitiateGeneration Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_InitiateGeneration_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_InitiateGeneration(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_AbortGeneration Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_AbortGeneration_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_AbortGeneration(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_CopyWfmDataBetweenEditMemory Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_CopyWfmDataBetweenEditMemory_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_CopyWfmDataBetweenEditMemory(vi, 0, 0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The sourceEditMemory's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The targetEditMemory's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_SaveLoadInstrumentSettings Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_SaveLoadInstrumentSettings_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_SaveLoadInstrumentSettings(vi, 0, ""));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The operationSelect's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_SaveLoadWaveformData Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_SaveLoadWaveformData_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_SaveLoadWaveformData(vi, 0, "", 0));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The operationSelect's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The editMemory's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_SetGetWaveformPointValue Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_SetGetWaveformPointValue_DefaultParameter()
{
    ViInt32 queryValue;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_SetGetWaveformPointValue(vi, 0, 0, 0, 0, &queryValue));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The pointIndex's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The pointValue's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The operationSelect's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The editMemory's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_reset Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_reset_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_reset(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_ResetWithDefaults Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ResetWithDefaults_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ResetWithDefaults(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_Disable Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_Disable_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_Disable(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_self_test Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_self_test_DefaultParameter()
{
    ViChar buff[255];
	ViInt16 selfTestResult;

    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_self_test(vi, &selfTestResult, buff));
}
 
    
 
/****************************************************************************
 * tkafg3k_revision_query Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_revision_query_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_revision_query(vi, "", ""));
}
 
    
 
/****************************************************************************
 * tkafg3k_error_query Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_error_query_DefaultParameter()
{
    ViInt32 errorCode;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_error_query(vi, &errorCode, ""));
}
 
    
 
/****************************************************************************
 * tkafg3k_error_message Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_error_message_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_error_message(vi, VI_NULL, ""));
}
 
    
 
/****************************************************************************
 * tkafg3k_InvalidateAllAttributes Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_InvalidateAllAttributes_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_InvalidateAllAttributes(vi));
}
 
    
 
/****************************************************************************
 * tkafg3k_GetChannelName Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_GetChannelName_DefaultParameter()
{
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_GetChannelName(vi, 0, 0, ""));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The index's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The bufferSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                
 
/****************************************************************************
 * tkafg3k_viWrite Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_viWrite_DefaultParameter()
{
    // TODO
    //CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_viWrite(vi, VI_NULL, VI_NULL, &numberOfBytesWritten));
}
 
    
 
/****************************************************************************
 * tkafg3k_viRead Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_viRead_DefaultParameter()
{
    // TODO
    //CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_viRead(vi, VI_NULL, VI_NULL, &numberOfBytesRead));
}
 
    
 
/****************************************************************************
 * tkafg3k_WriteInstrData Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_WriteInstrData_DefaultParameter()
{
    // TODO
    //CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_WriteInstrData(vi, ""));
}
 
    
 
/****************************************************************************
 * tkafg3k_ReadInstrData Default Parameter Test  
 ****************************************************************************/
void DriverFunctionalityTest::test_tkafg3k_ReadInstrData_DefaultParameter()
{
    ViInt32 numBytesRead;
    
    CPPUNIT_ASSERT(VI_SUCCESS == tkafg3k_ReadInstrData(vi, 0, "", &numBytesRead));
}
 
    
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The numberOfBytesToRead's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
                