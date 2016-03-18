#include "tkafg1k.h"
#include  "tkafg1k_testCppUnit.h"

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
	checkErr(tkafg1k_InitWithOptions ("USB0::0x0699::0x0353::1525004::INSTR",VI_TRUE,VI_TRUE,"Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1",&vi));	
	}
	else
	{
		checkErr(tkafg1k_reset(vi));
	}
	
Error:
	return error;
}

void testClose()
{
	tkafg1k_close(vi);
	vi = VI_NULL;
}

void DriverFunctionalityTest::setUp()
{
	testInit();
}

void DriverFunctionalityTest::tearDown()
{
	testClose();
}

/****************************************************************************
 *------------------------- Attribute Test --------------------------------*
 ****************************************************************************/
	


 /****************************************************************************
 * Default Value Test
 * ViInt32
 * Read & Write
 ****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 defaultValue = TKAFG1K_VAL_OPERATE_CONTINUOUS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,   returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_CONTINUOUS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_MODULATION;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_SWEEP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_BURST;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 defaultValue = TKAFG1K_VAL_OPERATE_CONTINUOUS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_CONTINUOUS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_MODULATION;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_SWEEP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OPERATION_MODE_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_OPERATION_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OPERATE_BURST;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_defaultValue_ReadWrite_NullChannel_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE;
	ViInt32 defaultValue = TKAFG1K_VAL_OUTPUT_FUNC;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OUTPUT_FUNC;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_OUTPUT_ARB;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_OUTPUT_FUNC;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_OUTPUT_FUNC;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_OUTPUT_ARB;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_OUTPUT_FUNC;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_OUTPUT_FUNC;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_OUTPUT_ARB;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 defaultValue = 50.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ClosemaximumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 0 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = 1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_CloseminimumValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 CloseminimumValue = 1.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ClosemaximumValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ClosemaximumValue = 10000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_RandomValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 returnValue;

	ViReal64 randomValue = 1.0 + rand() % 100 * 9999 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMinValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = 0;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMaxValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = 10001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 defaultValue = 50.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ClosemaximumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 0 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = 1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_CloseminimumValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 CloseminimumValue = 1.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ClosemaximumValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ClosemaximumValue = 10000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_RandomValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 returnValue;

	ViReal64 randomValue = 1.0 + rand() % 100 * 9999 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMinValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = 0;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_OUTPUT_IMPEDANCE_ViolationMaxValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_OUTPUT_IMPEDANCE;
	ViReal64 ViolationValue = 10001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_WFM_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_RAMP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_PULS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_LORENTZ;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_HAVERSINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_WFM_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_RAMP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_PULS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_LORENTZ;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_HAVERSINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_AMPLITUDE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_AMPLITUDE;
	ViReal64 defaultValue = 1.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_AMPLITUDE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_AMPLITUDE;
	ViReal64 defaultValue = 1.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DC_OFFSET_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DC_OFFSET;
	ViReal64 defaultValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DC_OFFSET_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DC_OFFSET;
	ViReal64 defaultValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_FREQUENCY;
	ViReal64 defaultValue = 1000000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_FREQUENCY;
	ViReal64 defaultValue = 1000000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 defaultValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 ClosemaximumValue = 360;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 360 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 ViolationValue = 361;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 defaultValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 ClosemaximumValue = 360;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 360 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_START_PHASE_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_START_PHASE;
	ViReal64 ViolationValue = 361;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 defaultValue = 50.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 CloseminimumValue = 50.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 ClosemaximumValue = 50.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 returnValue;

	ViReal64 randomValue = 50.0 + rand() % 100 * 0 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 ViolationValue = 49;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 ViolationValue = 51;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 defaultValue = 50.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 CloseminimumValue = 50.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 ClosemaximumValue = 50.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 returnValue;

	ViReal64 randomValue = 50.0 + rand() % 100 * 0 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 ViolationValue = 49;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FUNC_DUTY_CYCLE_HIGH;
	ViReal64 ViolationValue = 51;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PULSE_DUTY_CYCLE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PULSE_DUTY_CYCLE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PULSE_DUTY_CYCLE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PULSE_DUTY_CYCLE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;


	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 defaultValue = TKAFG1K_VAL_WFM_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER60;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER120;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER220;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 defaultValue = TKAFG1K_VAL_WFM_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER60;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER120;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_USER220;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_WAVEFORM_HANDLE_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_WAVEFORM_HANDLE;
	ViInt32 discreteValue = TKAFG1K_VAL_WFM_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_GAIN_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_GAIN;
	ViReal64 defaultValue = 0.5;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_GAIN_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_GAIN;
	ViReal64 defaultValue = 0.5;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_OFFSET_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_OFFSET;
	ViReal64 defaultValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_OFFSET_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_OFFSET;
	ViReal64 defaultValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read Only
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_SAMPLE_RATE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG1K_ATTR_ARB_SAMPLE_RATE;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, VI_NULL, attributeId, 0, &returnValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_FREQUENCY;
	ViReal64 defaultValue = 1000000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ARB_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ARB_FREQUENCY;
	ViReal64 defaultValue = 1000000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_OUTPUT_MODE_BY_CHANNEL, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read Only
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_MAX_NUM_WAVEFORMS_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG1K_ATTR_MAX_NUM_WAVEFORMS;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read Only
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_WAVEFORM_QUANTUM_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG1K_ATTR_WAVEFORM_QUANTUM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read Only
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_MIN_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG1K_ATTR_MIN_WAVEFORM_SIZE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read Only
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_MAX_WAVEFORM_SIZE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG1K_ATTR_MAX_WAVEFORM_SIZE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ACTIVE_MEMORY_defaultValue_ReadWrite_NullChannel_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ACTIVE_MEMORY;
	ViInt32 defaultValue = TKAFG1K_VAL_OUTPUT_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, VI_NULL, attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 defaultValue = 5;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Close Minimum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 CloseminimumValue = 0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(CloseminimumValue == returnValue);
}

/****************************************************************************
* Close Maximum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ClosemaximumValue = 0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(ClosemaximumValue == returnValue);
}

/****************************************************************************
* Random Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 returnValue;

	ViInt32 randomValue = (int)(0 + rand() % 100 * 0 / 100.00);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(randomValue == returnValue);
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = 1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Close Minimum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_CloseminimumValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 CloseminimumValue = 1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(CloseminimumValue == returnValue);
}

/****************************************************************************
* Close Maximum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ClosemaximumValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ClosemaximumValue = 500000;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(ClosemaximumValue == returnValue);
}

/****************************************************************************
* Random Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_RandomValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 returnValue;

	ViInt32 randomValue = (int)(1 + rand() % 100 * 499999 / 100.00);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(randomValue == returnValue);
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMinValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = 0;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMaxValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = 500001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 defaultValue = 5;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Close Minimum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 CloseminimumValue = 0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(CloseminimumValue == returnValue);
}

/****************************************************************************
* Close Maximum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ClosemaximumValue = 0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(ClosemaximumValue == returnValue);
}

/****************************************************************************
* Random Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 returnValue;

	ViInt32 randomValue = (int)(0 + rand() % 100 * 0 / 100.00);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(randomValue == returnValue);
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = 1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Close Minimum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_CloseminimumValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 CloseminimumValue = 1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(CloseminimumValue == returnValue);
}

/****************************************************************************
* Close Maximum Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ClosemaximumValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ClosemaximumValue = 500000;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(ClosemaximumValue == returnValue);
}

/****************************************************************************
* Random Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_RandomValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 returnValue;

	ViInt32 randomValue = (int)(1 + rand() % 100 * 499999 / 100.00);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(randomValue == returnValue);
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMinValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = 0;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViInt32
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_COUNT_ViolationMaxValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_COUNT;
	ViInt32 ViolationValue = 500001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_MODE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_BURST_MODE;
	ViInt32 defaultValue = TKAFG1K_VAL_BURST_TRIGGER;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_MODE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_BURST_TRIGGER;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_MODE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_BURST_GATE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_MODE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_BURST_MODE;
	ViInt32 defaultValue = TKAFG1K_VAL_BURST_TRIGGER;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_MODE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_BURST_TRIGGER;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_BURST_MODE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_BURST_MODE;
	ViInt32 discreteValue = TKAFG1K_VAL_BURST_GATE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue  ,  returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_SWEEP_START_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_SWEEP_START_FREQUENCY;
	ViReal64 defaultValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_SWEEP_START_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_SWEEP_START_FREQUENCY;
	ViReal64 defaultValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_SWEEP_STOP_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY;
	ViReal64 defaultValue = 1000000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_SWEEP_STOP_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_SWEEP_STOP_FREQUENCY;
	ViReal64 defaultValue = 1000000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_AM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_AM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 defaultValue = 50.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 CloseminimumValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ClosemaximumValue = 100.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ViolationValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 defaultValue = 50.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 CloseminimumValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ClosemaximumValue = 100.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_DEPTH_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_DEPTH;
	ViReal64 ViolationValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER55;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER120;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER220;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index10()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER55;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER120;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER220;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index10()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 defaultValue = 50.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 100.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 ViolationValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 defaultValue = 50.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 100.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_DEPTH_BY_CHANNEL;
	ViReal64 ViolationValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER55;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER120;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER220;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index10()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER55;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER120;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_USER220;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index10()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_AM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e3);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_AM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_FM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_FM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_DEVIATION_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_DEVIATION;
	ViReal64 defaultValue = 1000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_DEVIATION_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_DEVIATION;
	ViReal64 defaultValue = 1000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER40;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER90;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER190;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER40;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER90;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER190;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ClosemaximumValue = 20000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ClosemaximumValue = 20000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL;
	ViReal64 defaultValue = 10;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_DEVIATION_BY_CHANNEL;
	ViReal64 defaultValue = 10;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER40;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER90;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER190;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER40;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER90;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_USER190;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_FM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 defaultValue = 10000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 20000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 defaultValue = 10000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 20000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_HOP_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_HOP_FREQUENCY;
	ViReal64 defaultValue = 1000000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_HOP_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_HOP_FREQUENCY;
	ViReal64 defaultValue = 1000000.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 ClosemaximumValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 ViolationValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 ClosemaximumValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_INTERNAL_RATE_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_INTERNAL_RATE;
	ViReal64 ViolationValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_FSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FSK_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_FSK_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_FSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_FSK_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_FSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_FSK_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_PM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_PM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 defaultValue = 90;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 180;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 180 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e1);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 ViolationValue = 181;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 defaultValue = 90;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 180;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 180 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e1);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_DEVIATION_BY_CHANNEL;
	ViReal64 ViolationValue = 181;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_FREQUENCY_BY_CHANNEL;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_PM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER60;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER180;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_1_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 defaultValue = TKAFG1K_VAL_PM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER0;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER20;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER60;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_USER180;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL_DiscreteValue_ReadWrite_Channel_2_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_PM_INTERNAL_WAVEFORM_BY_CHANNEL;
	ViInt32 discreteValue = TKAFG1K_VAL_PM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;


	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_PWM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_PWM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_DEVIATION_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_DEVIATION;
	ViReal64 defaultValue = 5.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_DEVIATION_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_DEVIATION;
	ViReal64 defaultValue = 5.0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 20001;


	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 defaultValue = 10000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 ClosemaximumValue = 20000.00;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_FREQUENCY;
	ViReal64 ViolationValue = 20001;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_PWM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER2;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER3;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER4;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_1_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 defaultValue = TKAFG1K_VAL_PWM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_SINE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_SQUARE;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index3()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_RAMP_UP;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index4()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_PRN;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index5()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER1;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index6()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER2;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index7()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER3;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index8()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_USER4;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM_DiscreteValue_ReadWrite_Channel_2_Index9()
{
	ViAttr attributeId = TKAFG1K_ATTR_PWM_INTERNAL_WAVEFORM;
	ViInt32 discreteValue = TKAFG1K_VAL_PWM_INTERNAL_EMEM;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, "2", TKAFG1K_ATTR_FUNC_WAVEFORM, 0, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViString
* Read Only
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ID_QUERY_RESPONSE_defaultValue_ReadOnly_NullChannel_Index0()
{
	ViAttr attributeId = TKAFG1K_ATTR_ID_QUERY_RESPONSE;

	ViInt32 buf_size = 1024;
	ViChar returnValue[1024];

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViString(vi, VI_NULL, attributeId, 0, buf_size, returnValue));
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 ClosemaximumValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 ViolationValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 ClosemaximumValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_INTERNAL_RATE_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_INTERNAL_RATE;
	ViReal64 ViolationValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 defaultValue = 0.5;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 ClosemaximumValue = 1;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 1 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 ViolationValue = 2;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 defaultValue = 0.5;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 ClosemaximumValue = 1;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 1 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_AMPLITUDE_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_AMPLITUDE;
	ViReal64 ViolationValue = 2;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_ASK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_ASK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_ASK_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_ASK_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_ASK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_ASK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_ASK_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_ASK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_ASK_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_ENABLED_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "1", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViBoolean
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_ENABLED_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_ENABLED;
	ViBoolean trueValue = VI_TRUE;
	ViBoolean falseValue = VI_FALSE;
	ViBoolean returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, trueValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(trueValue == returnValue);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViBoolean(vi, "2", attributeId, 0, falseValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViBoolean(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT(falseValue == returnValue);

}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 ClosemaximumValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 ViolationValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 defaultValue = 50;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 CloseminimumValue = 0.002;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 ClosemaximumValue = 100000;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e2);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 returnValue;

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e2);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 ViolationValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_INTERNAL_RATE_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_INTERNAL_RATE;
	ViReal64 ViolationValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 defaultValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e2);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_CloseminimumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_ClosemaximumValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 ClosemaximumValue = 2;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e1);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_RandomValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 2 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_ViolationMinValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_ViolationMaxValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 ViolationValue = 3;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "1", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 defaultValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(defaultValue, returnValue, abs(defaultValue) / 10e1);
}

/****************************************************************************
* Close Minimum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_CloseminimumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 CloseminimumValue = 0;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e2);
}

/****************************************************************************
* Close Maximum Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_ClosemaximumValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 ClosemaximumValue = 2;
	ViReal64 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e1);
}

/****************************************************************************
* Random Value Test
* ViReal64
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_RandomValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 returnValue;

	ViReal64 randomValue = 0 + rand() % 100 * 2 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, randomValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViReal64(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_DOUBLES_EQUAL(randomValue, returnValue, abs(randomValue) / 10e1);
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_ViolationMinValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 ViolationValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}

/****************************************************************************
* Violation Value Test
* ViReal64
* Read & Write
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_DEVIATION_ViolationMaxValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_DEVIATION;
	ViReal64 ViolationValue = 3;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64(vi, "2", attributeId, 0, ViolationValue));
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_SOURCE_defaultValue_ReadWrite_Channel_1_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_PSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_SOURCE_DiscreteValue_ReadWrite_Channel_1_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PSK_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "1", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "1", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
* Default Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_SOURCE_defaultValue_ReadWrite_Channel_2_Index0()
{

	ViAttr attributeId = TKAFG1K_ATTR_PSK_SOURCE;
	ViInt32 defaultValue = TKAFG1K_VAL_PSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(defaultValue  , returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index1()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PSK_INTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}

/****************************************************************************
* Discrete Value Test
* ViInt32
* Read & Write
****************************************************************************/
void DriverFunctionalityTest::testTKAFG1K_ATTR_PSK_SOURCE_DiscreteValue_ReadWrite_Channel_2_Index2()
{
	ViAttr attributeId = TKAFG1K_ATTR_PSK_SOURCE;
	ViInt32 discreteValue = TKAFG1K_VAL_PSK_EXTERNAL;
	ViInt32 returnValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_SetAttributeViInt32(vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_InvalidateAttribute(vi, "2", attributeId));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS , Ivi_GetAttributeViInt32(vi, "2", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT_INTS_EQUAL(discreteValue, returnValue);
}


/****************************************************************************
*------------------------- Function Test ---------------------------------*
****************************************************************************/


/****************************************************************************
* tkafg1k_ConfigureOperationMode Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOperationMode_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOperationMode(vi, "1", TKAFG1K_VAL_OPERATE_CONTINUOUS));
}


/****************************************************************************
* tkafg1k_ConfigureOperationMode Ring Parameter "operationMode" Test
****************************************************************************/

/****************************************************************************
* operationMode Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOperationMode_operationMode_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOperationMode(vi, "1", TKAFG1K_VAL_OPERATE_CONTINUOUS));
}

/****************************************************************************
* operationMode Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOperationMode_operationMode_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOperationMode(vi, "1", TKAFG1K_VAL_OPERATE_MODULATION));
}

/****************************************************************************
* operationMode Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOperationMode_operationMode_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOperationMode(vi, "1", TKAFG1K_VAL_OPERATE_SWEEP));
}

/****************************************************************************
* operationMode Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOperationMode_operationMode_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOperationMode(vi, "1", TKAFG1K_VAL_OPERATE_BURST));
}

/****************************************************************************
* operationMode Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOperationMode_operationMode_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOperationMode(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureOutputMode Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputMode_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputMode(vi, TKAFG1K_VAL_OUTPUT_FUNC));
}


/****************************************************************************
* tkafg1k_ConfigureOutputMode Ring Parameter "outputMode" Test
****************************************************************************/

/****************************************************************************
* outputMode Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputMode_outputMode_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputMode(vi, TKAFG1K_VAL_OUTPUT_FUNC));
}

/****************************************************************************
* outputMode Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputMode_outputMode_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputMode(vi,  TKAFG1K_VAL_OUTPUT_ARB));
}

/****************************************************************************
* outputMode Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputMode_outputMode_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOutputMode(vi,  INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureOutputModeByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputModeByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputModeByChannel(vi, "1", TKAFG1K_VAL_OUTPUT_FUNC));
}


/****************************************************************************
* tkafg1k_ConfigureOutputModeByChannel Ring Parameter "outputMode" Test
****************************************************************************/

/****************************************************************************
* outputMode Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputModeByChannel(vi, "1", TKAFG1K_VAL_OUTPUT_FUNC));
}

/****************************************************************************
* outputMode Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputModeByChannel_outputMode_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputModeByChannel(vi, "1", TKAFG1K_VAL_OUTPUT_ARB));
}

/****************************************************************************
* outputMode Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputModeByChannel_outputMode_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOutputModeByChannel(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureOutputImpedance Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", 50.0));
}


/****************************************************************************
* tkafg1k_ConfigureOutputImpedance Ranged Parameter "impedance" Test
****************************************************************************/

/****************************************************************************
* impedance Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", minimumValue));
}

/****************************************************************************
* impedance Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOutputImpedance(vi, "1", belowMinimumValue));
}

/****************************************************************************
* impedance Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", maximumValue));
}

/****************************************************************************
* impedance Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOutputImpedance(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* impedance Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 0 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", randomValue));
}

/****************************************************************************
* impedance Range Minimum Value Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeMinimumValue_Index2()
{
	ViReal64 minimumValue = 1.0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", minimumValue));
}

/****************************************************************************
* impedance Range Below Minimum Value Test Index2
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeBelowMinimumValue_Index2()
{
	ViReal64 belowMinimumValue = 0;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOutputImpedance(vi, "1", belowMinimumValue));
}

/****************************************************************************
* impedance Range Maximum Value Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeMaximumValue_Index2()
{
	ViReal64 maximumValue = 10000.0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", maximumValue));
}

/****************************************************************************
* impedance Range Above Maximum Value Test Index2
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeAboveMaximumValue_Index2()
{
	ViReal64 aboveMaximumValue = 10001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureOutputImpedance(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* impedance Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputImpedance_impedance_RangeRandomValue_Index2()
{

	ViReal64 randomValue = 1.0 + rand() % 100 * 9999 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputImpedance(vi, "1", randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureOutputEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureOutputEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureOutputEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureOutputEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureStandardWaveform Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, 0.00));
}


/****************************************************************************
* tkafg1k_ConfigureStandardWaveform Ring Parameter "waveform" Test
****************************************************************************/

/****************************************************************************
* waveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SQUARE, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_RAMP, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_PULS, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index5()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_PRN, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index6()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_LORENTZ, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Valid_Item_Index7()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_HAVERSINE, 1.00, 0.00, 1000000.00, 0.00));
}

/****************************************************************************
* waveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_waveform_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureStandardWaveform(vi, "1", INVALID_ENUM_VALUE, 1.00, 0.00, 1000000.00, 0.00));
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
* tkafg1k_ConfigureStandardWaveform Ranged Parameter "startPhase" Test
****************************************************************************/

/****************************************************************************
* startPhase Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_startPhase_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, minimumValue));
}

/****************************************************************************
* startPhase Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_startPhase_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, belowMinimumValue));
}

/****************************************************************************
* startPhase Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_startPhase_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 360;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, maximumValue));
}

/****************************************************************************
* startPhase Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_startPhase_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 361;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, aboveMaximumValue));
}

/****************************************************************************
* startPhase Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureStandardWaveform_startPhase_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 360 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureStandardWaveform(vi, "1", TKAFG1K_VAL_WFM_SINE, 1.00, 0.00, 1000000.00, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureSampleRate Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureSampleRate_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureSampleRate(vi, 1000000000.0));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The sampleRate_Samps's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_CreateArbWaveform Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_CreateArbWaveform_DefaultParameter()
{
	ViInt32 waveformHandle;
	ViReal64 wfmdata[5] = { 1.00,2.00,-1.00,-3.00,1.04 };
	
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_CreateArbWaveform(vi, 5, wfmdata, &waveformHandle));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_CreateStandardShapeArbWfm Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_CreateStandardShapeArbWfm_DefaultParameter()
{
	ViInt32 waveformHandle;
	ViReal64 wfmdata[5] = { 1.00,2.00,-1.00,-3.00,1.04 };
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_CreateStandardShapeArbWfm(vi, 5, TKAFG1K_VAL_WFM_SINE, &waveformHandle));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformType's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_GetArbitraryWaveformBySlot Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_GetArbitraryWaveformBySlot_DefaultParameter()
{
	ViInt32 waveformHandle;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_GetArbitraryWaveformBySlot(vi, 0, &waveformHandle));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_CreateArbWaveformBySlot Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_CreateArbWaveformBySlot_DefaultParameter()
{
	ViInt32 waveformHandle;
	ViReal64 wfmdata[5] = { 1.00,2.00,-1.00,-3.00,1.04 };

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL,TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_CreateArbWaveformBySlot(vi, 0, 5, wfmdata, VI_TRUE, &waveformHandle));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The slot's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The waveformSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_CreateStandardShapeArbWfmBySlot Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_CreateStandardShapeArbWfmBySlot_DefaultParameter()
{
	ViInt32 waveformHandle;
	ViReal64 wfmdata[5] = { 1.00,2.00,-1.00,-3.00,1.04 };
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_CreateStandardShapeArbWfmBySlot(vi, 0, 5, TKAFG1K_VAL_WFM_SINE, VI_FALSE, &waveformHandle));
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
* tkafg1k_QueryArbWfmCapabilities Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_QueryArbWfmCapabilities_DefaultParameter()
{
	ViInt32 maximumNumberOfWaveforms;
	ViInt32 waveformQuantum;
	ViInt32 minimumWaveformSize;
	ViInt32 maximumWaveformSize;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_QueryArbWfmCapabilities(vi, &maximumNumberOfWaveforms, &waveformQuantum, &minimumWaveformSize, &maximumWaveformSize));
}



/****************************************************************************
* tkafg1k_ConfigureArbWaveform Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_DefaultParameter()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_EMEM, 0.5, 0.0));
}


/****************************************************************************
* tkafg1k_ConfigureArbWaveform Ring Parameter "waveformHandle" Test
****************************************************************************/

/****************************************************************************
* waveformHandle Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Valid_Item_Index1()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_USER1, 0.5, 0.00));
}

/****************************************************************************
* waveformHandle Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Valid_Item_Index2()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_USER20, 0.5, 0.00));
}

/****************************************************************************
* waveformHandle Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Valid_Item_Index3()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_USER60, 0.5, 0.00));
}

/****************************************************************************
* waveformHandle Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Valid_Item_Index4()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_USER120, 0.5, 0.00));
}

/****************************************************************************
* waveformHandle Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Valid_Item_Index5()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_USER220, 0.5, 0.00));
}

/****************************************************************************
* waveformHandle Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Valid_Item_Index6()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbWaveform(vi, "1", TKAFG1K_VAL_WFM_EMEM, 0.5, 0.00));
}

/****************************************************************************
* waveformHandle Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbWaveform_waveformHandle_Invalid()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureArbWaveform(vi, "1", INVALID_ENUM_VALUE, 0.5, 0.00));
}

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The gain_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The offset_V's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_ConfigureArbFrequency Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureArbFrequency_DefaultParameter()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, Ivi_SetAttributeViInt32(vi, VI_NULL, TKAFG1K_ATTR_OUTPUT_MODE, 0, TKAFG1K_VAL_OUTPUT_ARB));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureArbFrequency(vi, "1", 1000000.00));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The frequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_ConfigureBurstEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureBurstEnabled Boolean Parameter "burstEnabled" Test
****************************************************************************/
/****************************************************************************
* burstEnabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstEnabled_burstEnabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* burstEnabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstEnabled_burstEnabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureBurstCount Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", 5));
}


/****************************************************************************
* tkafg1k_ConfigureBurstCount Ranged Parameter "burstCount" Test
****************************************************************************/

/****************************************************************************
* burstCount Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index1()
{
	ViInt32 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", minimumValue));
}

/****************************************************************************
* burstCount Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index1()
{
	ViInt32 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureBurstCount(vi, "1", belowMinimumValue));
}

/****************************************************************************
* burstCount Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index1()
{
	ViInt32 maximumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", maximumValue));
}

/****************************************************************************
* burstCount Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index1()
{
	ViInt32 aboveMaximumValue = 1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureBurstCount(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* burstCount Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeRandomValue_Index1()
{

	ViInt32 randomValue = (int)(0 + rand() % 100 * 0 / 100.00);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", randomValue));
}

/****************************************************************************
* burstCount Range Minimum Value Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeMinimumValue_Index2()
{
	ViInt32 minimumValue = 1;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", minimumValue));
}

/****************************************************************************
* burstCount Range Below Minimum Value Test Index2
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeBelowMinimumValue_Index2()
{
	ViInt32 belowMinimumValue = 0;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureBurstCount(vi, "1", belowMinimumValue));
}

/****************************************************************************
* burstCount Range Maximum Value Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeMaximumValue_Index2()
{
	ViInt32 maximumValue = 500000;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", maximumValue));
}

/****************************************************************************
* burstCount Range Above Maximum Value Test Index2
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeAboveMaximumValue_Index2()
{
	ViInt32 aboveMaximumValue = 1000001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureBurstCount(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* burstCount Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstCount_burstCount_RangeRandomValue_Index2()
{

	ViInt32 randomValue = (int)(1 + rand() % 100 * 499999 / 100.00);

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstCount(vi, "1", randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureBurstMode Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstMode_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstMode(vi, "1", TKAFG1K_VAL_BURST_TRIGGER));
}


/****************************************************************************
* tkafg1k_ConfigureBurstMode Ring Parameter "burstMode" Test
****************************************************************************/

/****************************************************************************
* burstMode Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstMode_burstMode_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstMode(vi, "1", TKAFG1K_VAL_BURST_TRIGGER));
}

/****************************************************************************
* burstMode Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstMode_burstMode_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureBurstMode(vi, "1", TKAFG1K_VAL_BURST_GATE));
}

/****************************************************************************
* burstMode Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureBurstMode_burstMode_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureBurstMode(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureAMEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureAMEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureAMSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMSource_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMSource(vi, "1", TKAFG1K_VAL_AM_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigureAMSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMSource_source_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMSource(vi, "1", TKAFG1K_VAL_AM_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMSource_source_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMSource(vi, "1", TKAFG1K_VAL_AM_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMSource_source_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureAMInternal Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}


/****************************************************************************
* tkafg1k_ConfigureAMInternal Ranged Parameter "modulationDepth" Test
****************************************************************************/

/****************************************************************************
* modulationDepth Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationDepth_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, minimumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationDepth_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternal(vi, belowMinimumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationDepth_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, maximumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationDepth_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternal(vi, aboveMaximumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationDepth_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, randomValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigureAMInternal Ring Parameter "modulationWaveform" Test
****************************************************************************/

/****************************************************************************
* modulationWaveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SQUARE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_RAMP_UP, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_PRN, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index5()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_USER0, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index6()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_USER20, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index7()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_USER55, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index8
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index8()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_USER120, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index9
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index9()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_USER220, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index10
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Valid_Item_Index10()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_EMEM, 10000.00));
}

/****************************************************************************
* modulationWaveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationWaveform_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternal(vi, 50.00, INVALID_ENUM_VALUE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigureAMInternal Ranged Parameter "modulationFrequency" Test
****************************************************************************/

/****************************************************************************
* modulationFrequency Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationFrequency_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
* modulationFrequency Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationFrequency_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, belowMinimumValue));
}

/****************************************************************************
* modulationFrequency Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationFrequency_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 20000.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
* modulationFrequency Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationFrequency_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, aboveMaximumValue));
}

/****************************************************************************
* modulationFrequency Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternal_modulationFrequency_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternal(vi, 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureAMInternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}


/****************************************************************************
* tkafg1k_ConfigureAMInternalByChannel Ranged Parameter "modulationDepth" Test
****************************************************************************/

/****************************************************************************
* modulationDepth Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationDepth_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", minimumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternalByChannel(vi, "1", belowMinimumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationDepth_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", maximumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternalByChannel(vi, "1", aboveMaximumValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationDepth Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationDepth_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", randomValue, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigureAMInternalByChannel Ring Parameter "modulationWaveform" Test
****************************************************************************/

/****************************************************************************
* modulationWaveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SQUARE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_RAMP_UP, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_PRN, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_USER0, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_USER20, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_USER55, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index8
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_USER120, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index9
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_USER220, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index10
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Valid_Item_Index10()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_EMEM, 10000.00));
}

/****************************************************************************
* modulationWaveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationWaveform_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, INVALID_ENUM_VALUE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigureAMInternalByChannel Ranged Parameter "modulationFrequency" Test
****************************************************************************/

/****************************************************************************
* modulationFrequency Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationFrequency_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
* modulationFrequency Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationFrequency_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, belowMinimumValue));
}

/****************************************************************************
* modulationFrequency Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationFrequency_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 20000.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
* modulationFrequency Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationFrequency_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, aboveMaximumValue));
}

/****************************************************************************
* modulationFrequency Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMInternalByChannel_modulationFrequency_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMInternalByChannel(vi, "1", 50.00, TKAFG1K_VAL_AM_INTERNAL_SINE, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureAMExternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMExternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMExternalByChannel(vi, "1", 50.00));
}


/****************************************************************************
* tkafg1k_ConfigureAMExternalByChannel Ranged Parameter "modulationDepth" Test
****************************************************************************/

/****************************************************************************
* modulationDepth Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMExternalByChannel_modulationDepth_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMExternalByChannel(vi, "1", minimumValue));
}

/****************************************************************************
* modulationDepth Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMExternalByChannel_modulationDepth_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMExternalByChannel(vi, "1", belowMinimumValue));
}

/****************************************************************************
* modulationDepth Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMExternalByChannel_modulationDepth_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMExternalByChannel(vi, "1", maximumValue));
}

/****************************************************************************
* modulationDepth Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMExternalByChannel_modulationDepth_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 101;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureAMExternalByChannel(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* modulationDepth Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureAMExternalByChannel_modulationDepth_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.00 + rand() % 100 * 100 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureAMExternalByChannel(vi, "1", randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureFMEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureFMEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureFMSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMSource_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMSource(vi, "1", TKAFG1K_VAL_FM_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigureFMSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMSource_source_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMSource(vi, "1", TKAFG1K_VAL_FM_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMSource_source_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMSource(vi, "1", TKAFG1K_VAL_FM_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMSource_source_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureFMInternal Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, 10000.00));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/****************************************************************************
* tkafg1k_ConfigureFMInternal Ring Parameter "modulationWaveform" Test
****************************************************************************/

/****************************************************************************
* modulationWaveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SQUARE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_RAMP_UP, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_PRN, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index5()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_USER1, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index6()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_USER40, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index7()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_USER90, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index8
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index8()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_USER190, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index9
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Valid_Item_Index9()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_EMEM, 10000.00));
}

/****************************************************************************
* modulationWaveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationWaveform_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMInternal(vi, 990, INVALID_ENUM_VALUE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigureFMInternal Ranged Parameter "modulationFrequency_Hz" Test
****************************************************************************/

/****************************************************************************
* modulationFrequency_Hz Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationFrequency_Hz_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, belowMinimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationFrequency_Hz_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 20000.0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, aboveMaximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternal_modulationFrequency_Hz_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternal(vi, 990, TKAFG1K_VAL_FM_INTERNAL_SINE, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureFMInternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, 10000.0));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/****************************************************************************
* tkafg1k_ConfigureFMInternalByChannel Ring Parameter "modulationWaveform" Test
****************************************************************************/

/****************************************************************************
* modulationWaveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SQUARE, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_RAMP_UP, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_PRN, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_USER1, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_USER40, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_USER90, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index8
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_USER190, 10000.0));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index9
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_EMEM, 10000.0));
}

/****************************************************************************
* modulationWaveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationWaveform_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, INVALID_ENUM_VALUE, 10000.0));
}

/****************************************************************************
* tkafg1k_ConfigureFMInternalByChannel Ranged Parameter "modulationFrequency_Hz" Test
****************************************************************************/

/****************************************************************************
* modulationFrequency_Hz Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, belowMinimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 20000.0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, aboveMaximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMInternalByChannel(vi, "1", 0.5, TKAFG1K_VAL_FM_INTERNAL_SINE, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureFMExternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFMExternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFMExternalByChannel(vi, "1", 0.5));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_ConfigurePMEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigurePMEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigurePMSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMSource_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMSource(vi, "1", TKAFG1K_VAL_PM_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigurePMSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMSource_source_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMSource(vi, "1", TKAFG1K_VAL_PM_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMSource_source_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMSource(vi, "1", TKAFG1K_VAL_PM_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMSource_source_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigurePMInternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}


/****************************************************************************
* tkafg1k_ConfigurePMInternalByChannel Ranged Parameter "peakDeviation" Test
****************************************************************************/

/****************************************************************************
* peakDeviation Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_peakDeviation_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", minimumValue, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* peakDeviation Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMInternalByChannel(vi, "1", belowMinimumValue, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* peakDeviation Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_peakDeviation_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 180;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", maximumValue, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* peakDeviation Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 181;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMInternalByChannel(vi, "1", aboveMaximumValue, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* peakDeviation Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_peakDeviation_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 180 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", randomValue, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigurePMInternalByChannel Ring Parameter "modulationWaveform" Test
****************************************************************************/

/****************************************************************************
* modulationWaveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SQUARE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_RAMP_UP, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_PRN, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_USER0, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_USER20, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_USER60, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index8
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_USER180, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index9
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_EMEM, 10000.00));
}

/****************************************************************************
* modulationWaveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationWaveform_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, INVALID_ENUM_VALUE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigurePMInternalByChannel Ranged Parameter "modulationFrequency_Hz" Test
****************************************************************************/

/****************************************************************************
* modulationFrequency_Hz Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, belowMinimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 20000.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 20001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, aboveMaximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMInternalByChannel(vi, "1", 90, TKAFG1K_VAL_PM_INTERNAL_SINE, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigurePMExternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMExternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMExternalByChannel(vi, "1", 90));
}


/****************************************************************************
* tkafg1k_ConfigurePMExternalByChannel Ranged Parameter "peakDeviation" Test
****************************************************************************/

/****************************************************************************
* peakDeviation Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMExternalByChannel_peakDeviation_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMExternalByChannel(vi, "1", minimumValue));
}

/****************************************************************************
* peakDeviation Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMExternalByChannel_peakDeviation_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMExternalByChannel(vi, "1", belowMinimumValue));
}

/****************************************************************************
* peakDeviation Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMExternalByChannel_peakDeviation_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 180;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMExternalByChannel(vi, "1", maximumValue));
}

/****************************************************************************
* peakDeviation Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMExternalByChannel_peakDeviation_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 181;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePMExternalByChannel(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* peakDeviation Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePMExternalByChannel_peakDeviation_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 180 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePMExternalByChannel(vi, "1", randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureFSKEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureFSKEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureFSKSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKSource_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKSource(vi, "1", TKAFG1K_VAL_FSK_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigureFSKSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKSource_source_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKSource(vi, "1", TKAFG1K_VAL_FSK_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKSource_source_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKSource(vi, "1", TKAFG1K_VAL_FSK_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKSource_source_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFSKSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureFSKInternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKInternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, 50));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/****************************************************************************
* tkafg1k_ConfigureFSKInternalByChannel Ranged Parameter "internalRate" Test
****************************************************************************/

/****************************************************************************
* internalRate Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKInternalByChannel_internalRate_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, minimumValue));
}

/****************************************************************************
* internalRate Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKInternalByChannel_internalRate_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, belowMinimumValue));
}

/****************************************************************************
* internalRate Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKInternalByChannel_internalRate_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 100000;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, maximumValue));
}

/****************************************************************************
* internalRate Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKInternalByChannel_internalRate_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, aboveMaximumValue));
}

/****************************************************************************
* internalRate Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKInternalByChannel_internalRate_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKInternalByChannel(vi, "1", 1000000.0, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureFSKExternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureFSKExternalByChannel_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureFSKExternalByChannel(vi, "1", 1000000.0));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The hopFrequency's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_ConfigurePWMEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigurePWMEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMEnabled_enabled_TRUE()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMEnabled_enabled_FALSE()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigurePWMSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMSource_DefaultParameter()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMSource(vi, "1", TKAFG1K_VAL_PWM_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigurePWMSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMSource_source_Valid_Item_Index1()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMSource(vi, "1", TKAFG1K_VAL_PWM_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMSource_source_Valid_Item_Index2()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMSource(vi, "1", TKAFG1K_VAL_PWM_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMSource_source_Invalid()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePWMSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigurePWMInternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_DefaultParameter()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, 10000.00));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Hz's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/****************************************************************************
* tkafg1k_ConfigurePWMInternalByChannel Ring Parameter "modulationWaveform" Test
****************************************************************************/

/****************************************************************************
* modulationWaveform Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index1()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index2()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SQUARE, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index3
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index3()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_RAMP_UP, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index4
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index4()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_PRN, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index5
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index5()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_USER1, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index6
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index6()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_USER2, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index7
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index7()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_USER3, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index8
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index8()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_USER4, 10000.00));
}

/****************************************************************************
* modulationWaveform Valid Item Test Index9
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Valid_Item_Index9()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_EMEM, 10000.00));
}

/****************************************************************************
* modulationWaveform Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationWaveform_Invalid()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, INVALID_ENUM_VALUE, 10000.00));
}

/****************************************************************************
* tkafg1k_ConfigurePWMInternalByChannel Ranged Parameter "modulationFrequency_Hz" Test
****************************************************************************/

/****************************************************************************
* modulationFrequency_Hz Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, minimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, belowMinimumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 20000.00;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, maximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 20001;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, aboveMaximumValue));
}

/****************************************************************************
* modulationFrequency_Hz Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMInternalByChannel_modulationFrequency_Hz_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 19999.998 / 100.00;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMInternalByChannel(vi, "1", 5.0, TKAFG1K_VAL_PWM_INTERNAL_SINE, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigurePWMExternalByChannel Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePWMExternalByChannel_DefaultParameter()
{
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS, tkafg1k_SetAttributeViInt32(vi, "1", TKAFG1K_ATTR_FUNC_WAVEFORM, TKAFG1K_VAL_WFM_PULS));
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePWMExternalByChannel(vi, "1", 5.0));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The peakDeviation_Percent's related attribute doesn't have RangeTable, fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_InitiateGeneration Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_InitiateGeneration_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_InitiateGeneration(vi));
}



/****************************************************************************
* tkafg1k_AbortGeneration Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_AbortGeneration_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(TKAFG1K_ERROR_ABORT_GENERATION_UNSUPPORTED,  tkafg1k_AbortGeneration(vi));
}



/****************************************************************************
* tkafg1k_SetGetWaveformPointValue Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_SetGetWaveformPointValue_DefaultParameter()
{
	ViInt32 queryValue;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_SetGetWaveformPointValue(vi, 0, 0, 0, 0, &queryValue));
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
* tkafg1k_reset Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_reset_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_reset(vi));
}



/****************************************************************************
* tkafg1k_ResetWithDefaults Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ResetWithDefaults_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ResetWithDefaults(vi));
}



/****************************************************************************
* tkafg1k_Disable Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_Disable_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(TKAFG1K_ERROR_DISABLE_UNSUPPORTED,  tkafg1k_Disable(vi));
}



/****************************************************************************
* tkafg1k_revision_query Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_revision_query_DefaultParameter()
{
	ViChar driverRev[1024];
	ViChar instrRev[1024] ;
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_revision_query(vi, driverRev, instrRev));
}



/****************************************************************************
* tkafg1k_error_query Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_error_query_DefaultParameter()
{
	ViInt32 errorCode;
	ViChar errorMessage[1024];
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_error_query(vi, &errorCode, errorMessage));
}



/****************************************************************************
* tkafg1k_error_message Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_error_message_DefaultParameter()
{
	ViChar errorMessage[1024];
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_error_message(vi, VI_NULL, errorMessage));
}



/****************************************************************************
* tkafg1k_InvalidateAllAttributes Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_InvalidateAllAttributes_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_InvalidateAllAttributes(vi));
}



/****************************************************************************
* tkafg1k_GetChannelName Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_GetChannelName_DefaultParameter()
{
	ViChar channelName[1024];
	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_GetChannelName(vi, 1, 1024, channelName));
}


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The index's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/* Error: The bufferSize's RangeTable type isn't 'Coerced' or 'Ranged', fail to generate auto test code*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


/****************************************************************************
* tkafg1k_viWrite Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_viWrite_DefaultParameter()
{

//	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_viWrite(vi, VI_NULL, VI_NULL, &numberOfBytesWritten));
}



/****************************************************************************
* tkafg1k_viRead Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_viRead_DefaultParameter()
{

//	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_viRead(vi, VI_NULL, VI_NULL, &numberOfBytesRead));
}



/****************************************************************************
* tkafg1k_ConfigureASKEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureASKEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigureASKSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKSource_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKSource(vi, "1", TKAFG1K_VAL_ASK_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigureASKSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKSource_source_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKSource(vi, "1", TKAFG1K_VAL_ASK_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKSource_source_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKSource(vi, "1", TKAFG1K_VAL_ASK_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKSource_source_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigureASKInternalByChan Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", 0.5, 50));
}


/****************************************************************************
* tkafg1k_ConfigureASKInternalByChan Ranged Parameter "amplitude" Test
****************************************************************************/

/****************************************************************************
* amplitude Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_amplitude_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", minimumValue, 50));
}

/****************************************************************************
* amplitude Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_amplitude_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKInternalByChan(vi, "1", belowMinimumValue, 50));
}

/****************************************************************************
* amplitude Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_amplitude_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 1;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", maximumValue, 50));
}

/****************************************************************************
* amplitude Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_amplitude_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 2;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKInternalByChan(vi, "1", aboveMaximumValue, 50));
}

/****************************************************************************
* amplitude Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_amplitude_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 1 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", randomValue, 50));
}

/****************************************************************************
* tkafg1k_ConfigureASKInternalByChan Ranged Parameter "internalRate" Test
****************************************************************************/

/****************************************************************************
* internalRate Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_internalRate_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", 0.5, minimumValue));
}

/****************************************************************************
* internalRate Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_internalRate_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKInternalByChan(vi, "1", 0.5, belowMinimumValue));
}

/****************************************************************************
* internalRate Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_internalRate_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 100000;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", 0.5, maximumValue));
}

/****************************************************************************
* internalRate Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_internalRate_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKInternalByChan(vi, "1", 0.5, aboveMaximumValue));
}

/****************************************************************************
* internalRate Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKInternalByChan_internalRate_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKInternalByChan(vi, "1", 0.5, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigureASKExternalByChan Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKExternalByChan_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKExternalByChan(vi, "1", 0.5));
}


/****************************************************************************
* tkafg1k_ConfigureASKExternalByChan Ranged Parameter "NewParameter" Test
****************************************************************************/

/****************************************************************************
* NewParameter Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKExternalByChan_NewParameter_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKExternalByChan(vi, "1", minimumValue));
}

/****************************************************************************
* NewParameter Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKExternalByChan_NewParameter_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKExternalByChan(vi, "1", belowMinimumValue));
}

/****************************************************************************
* NewParameter Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKExternalByChan_NewParameter_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 1;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKExternalByChan(vi, "1", maximumValue));
}

/****************************************************************************
* NewParameter Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKExternalByChan_NewParameter_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 2;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigureASKExternalByChan(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* NewParameter Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigureASKExternalByChan_NewParameter_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 1 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigureASKExternalByChan(vi, "1", randomValue));
}


/****************************************************************************
* tkafg1k_ConfigurePSKEnabled Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKEnabled_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigurePSKEnabled Boolean Parameter "enabled" Test
****************************************************************************/
/****************************************************************************
* enabled Boolean TRUE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKEnabled_enabled_TRUE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKEnabled(vi, "1", VI_TRUE));
}

/****************************************************************************
* enabled Boolean FALSE Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKEnabled_enabled_FALSE()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKEnabled(vi, "1", VI_FALSE));
}


/****************************************************************************
* tkafg1k_ConfigurePSKSource Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKSource_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKSource(vi, "1", TKAFG1K_VAL_PSK_INTERNAL));
}


/****************************************************************************
* tkafg1k_ConfigurePSKSource Ring Parameter "source" Test
****************************************************************************/

/****************************************************************************
* source Valid Item Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKSource_source_Valid_Item_Index1()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKSource(vi, "1", TKAFG1K_VAL_PSK_INTERNAL));
}

/****************************************************************************
* source Valid Item Test Index2
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKSource_source_Valid_Item_Index2()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKSource(vi, "1", TKAFG1K_VAL_PSK_EXTERNAL));
}

/****************************************************************************
* source Invalid Item Test
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKSource_source_Invalid()
{

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKSource(vi, "1", INVALID_ENUM_VALUE));
}


/****************************************************************************
* tkafg1k_ConfigurePSKInternalByChan Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", 0, 50));
}


/****************************************************************************
* tkafg1k_ConfigurePSKInternalByChan Ranged Parameter "deviation" Test
****************************************************************************/

/****************************************************************************
* deviation Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_deviation_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", minimumValue, 50));
}

/****************************************************************************
* deviation Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_deviation_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKInternalByChan(vi, "1", belowMinimumValue, 50));
}

/****************************************************************************
* deviation Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_deviation_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 2;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", maximumValue, 50));
}

/****************************************************************************
* deviation Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_deviation_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 3;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKInternalByChan(vi, "1", aboveMaximumValue, 50));
}

/****************************************************************************
* deviation Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_deviation_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 2 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", randomValue, 50));
}

/****************************************************************************
* tkafg1k_ConfigurePSKInternalByChan Ranged Parameter "internalRate" Test
****************************************************************************/

/****************************************************************************
* internalRate Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_internalRate_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0.002;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", 0, minimumValue));
}

/****************************************************************************
* internalRate Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_internalRate_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -0.998;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKInternalByChan(vi, "1", 0, belowMinimumValue));
}

/****************************************************************************
* internalRate Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_internalRate_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 100000;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", 0, maximumValue));
}

/****************************************************************************
* internalRate Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_internalRate_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 100001;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKInternalByChan(vi, "1", 0, aboveMaximumValue));
}

/****************************************************************************
* internalRate Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKInternalByChan_internalRate_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0.002 + rand() % 100 * 99999.998 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKInternalByChan(vi, "1", 0, randomValue));
}


/****************************************************************************
* tkafg1k_ConfigurePSKExternalByChan Default Parameter Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKExternalByChan_DefaultParameter()
{

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKExternalByChan(vi, "1", 0));
}


/****************************************************************************
* tkafg1k_ConfigurePSKExternalByChan Ranged Parameter "NewParameter" Test
****************************************************************************/

/****************************************************************************
* NewParameter Range Minimum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKExternalByChan_NewParameter_RangeMinimumValue_Index1()
{
	ViReal64 minimumValue = 0;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKExternalByChan(vi, "1", minimumValue));
}

/****************************************************************************
* NewParameter Range Below Minimum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKExternalByChan_NewParameter_RangeBelowMinimumValue_Index1()
{
	ViReal64 belowMinimumValue = -1;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKExternalByChan(vi, "1", belowMinimumValue));
}

/****************************************************************************
* NewParameter Range Maximum Value Test Index1
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKExternalByChan_NewParameter_RangeMaximumValue_Index1()
{
	ViReal64 maximumValue = 2;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKExternalByChan(vi, "1", maximumValue));
}

/****************************************************************************
* NewParameter Range Above Maximum Value Test Index1
* Should Fail!
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKExternalByChan_NewParameter_RangeAboveMaximumValue_Index1()
{
	ViReal64 aboveMaximumValue = 3;

	CPPUNIT_ASSERT(VI_SUCCESS != tkafg1k_ConfigurePSKExternalByChan(vi, "1", aboveMaximumValue));
}

/****************************************************************************
* NewParameter Range Random Value Test
****************************************************************************/
void DriverFunctionalityTest::test_tkafg1k_ConfigurePSKExternalByChan_NewParameter_RangeRandomValue_Index1()
{

	ViReal64 randomValue = 0 + rand() % 100 * 2 / 100.00;

	CPPUNIT_ASSERT_INTS_EQUAL(VI_SUCCESS ,  tkafg1k_ConfigurePSKExternalByChan(vi, "1", randomValue));
}
