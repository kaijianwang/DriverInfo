#include  "agn6k7kni_testCppUnit.h"
#include "agn6k7kni.h"
#include "string.h"
#include "math.h"

typedef struct
{
	ViReal64	minCurrent;
	ViReal64	maxCurrent;
	ViReal64	minVoltage;
	ViReal64	maxVoltage;
	ViReal64	maxResistance;
	ViReal64	maxOVPLimit;
	ViReal64	lowerRange;
} SInstrumentRanges, *SInstrumentRangesPtr;

static SInstrumentRanges gs_N6950ARanges =
{
	-10.2,   		/* Minimum Current 		*/
	102.0,  		/* Maximum Current 		*/
	0.009,    		/* Minimum Voltage 		*/
	9.18,    		/* Maximum Voltage 		*/
	0.1,  			/* Maximum Resistance 	*/
	10.8,    		/* Maximum OVP Limit 	*/   
	10.0,    		/* Lower Range          */
};

static SInstrumentRanges gs_N6951ARanges =
{
	-5.1,   		/* Minimum Current 		*/
	51.0,  			/* Maximum Current 		*/
	0.02,    		/* Minimum Voltage 		*/
	20.4,    		/* Maximum Voltage 		*/
	0.4,  			/* Maximum Resistance 	*/
	24.0,    		/* Maximum OVP Limit 	*/   
	5.0,    		/* Lower Range          */
};

static SInstrumentRanges gs_N6952ARanges =
{
	-2.55,   		/* Minimum Current 		*/
	25.5,  			/* Maximum Current 		*/
	0.04,    		/* Minimum Voltage 		*/
	40.8,    		/* Maximum Voltage 		*/
	1.6,  			/* Maximum Resistance 	*/
	48.0,    		/* Maximum OVP Limit 	*/   
	2.5,    		/* Lower Range          */
};

static SInstrumentRanges gs_N6953ARanges =
{
	-1.7,   		/* Minimum Current 		*/
	17.0,  			/* Maximum Current 		*/
	0.06,    		/* Minimum Voltage 		*/
	61.2,    		/* Maximum Voltage 		*/
	3.4,  			/* Maximum Resistance 	*/
	72.0,    		/* Maximum OVP Limit 	*/   
	1.67,    		/* Lower Range          */
};

static SInstrumentRanges gs_N6954ARanges =
{
	-1.275,   		/* Minimum Current 		*/
	12.75,  		/* Maximum Current 		*/
	0.08,    		/* Minimum Voltage 		*/
	81.6,    		/* Maximum Voltage 		*/
	6.4,  			/* Maximum Resistance 	*/
	96.0,    		/* Maximum OVP Limit 	*/   
	1.25,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6970ARanges =
{
	-10.2,   		/* Minimum Current 		*/
	102.0,  		/* Maximum Current 		*/
	0.009,    		/* Minimum Voltage 		*/
	9.18,    		/* Maximum Voltage 		*/
	0.05,  			/* Maximum Resistance 	*/
	10.8,    		/* Maximum OVP Limit 	*/   
	10.0,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6971ARanges =
{
	-5.1,   		/* Minimum Current 		*/
	51.0,  			/* Maximum Current 		*/
	0.02,    		/* Minimum Voltage 		*/
	20.4,    		/* Maximum Voltage 		*/
	0.2,  			/* Maximum Resistance 	*/
	24.0,    		/* Maximum OVP Limit 	*/   
	5.0,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6972ARanges =
{
	-2.55,   		/* Minimum Current 		*/
	25.5,  			/* Maximum Current 		*/
	0.04,    		/* Minimum Voltage 		*/
	40.8,    		/* Maximum Voltage 		*/
	0.8,  			/* Maximum Resistance 	*/
	48.0,    		/* Maximum OVP Limit 	*/   
	2.5,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6973ARanges =
{
	-1.7,   		/* Minimum Current 		*/
	17.0,  			/* Maximum Current 		*/
	0.06,    		/* Minimum Voltage 		*/
	61.2,    		/* Maximum Voltage 		*/
	1.7,  			/* Maximum Resistance 	*/
	72.0,    		/* Maximum OVP Limit 	*/   
	1.67,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6974ARanges =
{
	-1.275,   		/* Minimum Current 		*/
	12.75,  		/* Maximum Current 		*/
	0.08,    		/* Minimum Voltage 		*/
	81.6,    		/* Maximum Voltage 		*/
	3.2,  			/* Maximum Resistance 	*/
	96.0,    		/* Maximum OVP Limit 	*/   
	1.25,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6976ARanges =
{
	-1.7,   		/* Minimum Current 		*/
	17.0,  			/* Maximum Current 		*/
	0.12,    		/* Minimum Voltage 		*/
	122.4,    		/* Maximum Voltage 		*/
	6.8,  			/* Maximum Resistance 	*/
	144.0,    		/* Maximum OVP Limit 	*/   
	1.67,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N6977ARanges =
{
	-1.275,   		/* Minimum Current 		*/
	12.75,  		/* Maximum Current 		*/
	0.16,    		/* Minimum Voltage 		*/
	163.2,    		/* Maximum Voltage 		*/
	12.8,  			/* Maximum Resistance 	*/
	192.0,    		/* Maximum OVP Limit 	*/   
	1.25,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7950ARanges =
{
	-10.2,   		/* Minimum Current 		*/
	102.0,  		/* Maximum Current 		*/
	0.009,    		/* Minimum Voltage 		*/
	9.18,    		/* Maximum Voltage 		*/
	0.1,  			/* Maximum Resistance 	*/
	10.8,    		/* Maximum OVP Limit 	*/   
	10.0,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7951ARanges =
{
	-5.1,   		/* Minimum Current 		*/
	51.0,  			/* Maximum Current 		*/
	0.02,    		/* Minimum Voltage 		*/
	20.4,    		/* Maximum Voltage 		*/
	0.4,  			/* Maximum Resistance 	*/
	24.0,    		/* Maximum OVP Limit 	*/   
	5.0,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7952ARanges =
{
	-2.55,   		/* Minimum Current 		*/
	25.5,  			/* Maximum Current 		*/
	0.04,    		/* Minimum Voltage 		*/
	40.8,    		/* Maximum Voltage 		*/
	1.6,  			/* Maximum Resistance 	*/
	48.0,    		/* Maximum OVP Limit 	*/   
	2.5,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7953ARanges =
{
	-1.7,   		/* Minimum Current 		*/
	17.0,  			/* Maximum Current 		*/
	0.06,    		/* Minimum Voltage 		*/
	61.2,    		/* Maximum Voltage 		*/
	3.4,  			/* Maximum Resistance 	*/
	72.0,    		/* Maximum OVP Limit 	*/   
	1.67,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7954ARanges =
{
	-1.275,   		/* Minimum Current 		*/
	12.75,  		/* Maximum Current 		*/
	0.08,    		/* Minimum Voltage 		*/
	81.6,    		/* Maximum Voltage 		*/
	6.4,  			/* Maximum Resistance 	*/
	96.0,    		/* Maximum OVP Limit 	*/   
	1.25,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7970ARanges =
{
	-10.2,   		/* Minimum Current 		*/
	102.0,  		/* Maximum Current 		*/
	0.009,    		/* Minimum Voltage 		*/
	9.18,    		/* Maximum Voltage 		*/
	0.05,  			/* Maximum Resistance 	*/
	10.8,    		/* Maximum OVP Limit 	*/   
	10.0,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7971ARanges =
{
	-5.1,   		/* Minimum Current 		*/
	51.0,  			/* Maximum Current 		*/
	0.02,    		/* Minimum Voltage 		*/
	20.4,    		/* Maximum Voltage 		*/
	0.2,  			/* Maximum Resistance 	*/
	24.0,    		/* Maximum OVP Limit 	*/   
	5.0,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7972ARanges =
{
	-2.55,   		/* Minimum Current 		*/
	25.5,  			/* Maximum Current 		*/
	0.04,    		/* Minimum Voltage 		*/
	40.8,    		/* Maximum Voltage 		*/
	0.8,  			/* Maximum Resistance 	*/
	48.0,    		/* Maximum OVP Limit 	*/   
	2.5,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7973ARanges =
{
	-1.7,   		/* Minimum Current 		*/
	17.0,  			/* Maximum Current 		*/
	0.06,    		/* Minimum Voltage 		*/
	61.2,    		/* Maximum Voltage 		*/
	1.7,  			/* Maximum Resistance 	*/
	72.0,    		/* Maximum OVP Limit 	*/   
	1.67,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7974ARanges =
{
	-1.275,   		/* Minimum Current 		*/
	12.75,  		/* Maximum Current 		*/
	0.08,    		/* Minimum Voltage 		*/
	81.6,    		/* Maximum Voltage 		*/
	3.2,  			/* Maximum Resistance 	*/
	96.0,    		/* Maximum OVP Limit 	*/   
	1.25,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7976ARanges =
{
	-1.7,   		/* Minimum Current 		*/
	17.0,  			/* Maximum Current 		*/
	0.12,    		/* Minimum Voltage 		*/
	122.4,    		/* Maximum Voltage 		*/
	6.8,  			/* Maximum Resistance 	*/
	144.0,    		/* Maximum OVP Limit 	*/   
	1.67,    		/* Lower Range			*/
};

static SInstrumentRanges gs_N7977ARanges =
{
	-1.275,   		/* Minimum Current 		*/
	12.75,  		/* Maximum Current 		*/
	0.16,    		/* Minimum Voltage 		*/
	163.2,    		/* Maximum Voltage 		*/
	12.8,  			/* Maximum Resistance 	*/
	192.0,    		/* Maximum OVP Limit 	*/   
	1.25,    		/* Lower Range			*/
};

static SInstrumentRangesPtr pInstrumentModel = VI_NULL;

CPPUNIT_TEST_SUITE_REGISTRATION(DriverFunctionalityTest);
/****************************************************************************
 *------------------------------- Global Variable --------------------------*
 ****************************************************************************/
ViSession vi = VI_NULL;		

ViStatus testInit()
{
	ViStatus error = VI_SUCCESS;

	checkErr(agn6k7kni_init ("TCPIP0::A-N7952A-40001::inst0::INSTR",VI_TRUE,VI_FALSE,&vi));
	pInstrumentModel = &gs_N7952ARanges;
	
Error:
	return error;
}

void testClose()
{
	agn6k7kni_close(vi);
	vi = VI_NULL;
}

void DriverFunctionalityTest::setUp()
{
	testInit();
}

void DriverFunctionalityTest::tearDown(){}

/****************************************************************************
 *------------------------------ Test Templates ----------------------------*
 ****************************************************************************/
	

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SHARING_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_MAX_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_MAX_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_RANGE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_RANGE ;
	ViReal64 defaultValue = pInstrumentModel->lowerRange;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_DELAY_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_DELAY ;
	ViInt32 defaultValue = 60 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_DELAY_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_DELAY ;
	ViInt32 CloseminimumValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_DELAY_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_DELAY ;
	ViInt32 ClosemaximumValue = 3600 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_DELAY_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_DELAY ;
	 
	ViInt32 randomValue = 3202 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_DELAY_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_DELAY;
	ViInt32 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_DELAY_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_DELAY;
	ViInt32 ViolationValue = 3601 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_WATCHDOG_TIMER_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_START_TIME_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY_START_TIME ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_OCP_DELAY_START_SCHANGE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_START_TIME_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY_START_TIME ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_OCP_DELAY_START_SCHANGE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_START_TIME_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY_START_TIME ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_OCP_DELAY_START_CCTRANS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY ;
	ViReal64 defaultValue = 0.02 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY ;
	ViReal64 CloseminimumValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY ;
	ViReal64 ClosemaximumValue = 0.255 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY ;
	 
	ViReal64 randomValue = 0.19 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_DELAY_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_DELAY;
	ViReal64 ViolationValue = 1.255 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OCP_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OCP_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	/* Change priority mode to voltage priority. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_FUNCTION, 
				                 0, AGN6K7KNI_VAL_FUNCTION_VOLTAGE));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_RELAY_LOCK_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_RELAY_POLARITY_NORMAL ;	
	ViInt32 returnValue;

	/* Enables the output relay polarity. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED, 
							     0, VI_TRUE));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_RELAY_POLARITY_NORMAL ;	
	ViInt32 returnValue;

	/* Enables the output relay polarity. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED, 
							     0, VI_TRUE));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_RELAY_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_RELAY_POLARITY_REVERSE ;	
	ViInt32 returnValue;

	/* Enables the output relay polarity. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED, 
							     0, VI_TRUE));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_RELAY_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_RESISTANCE_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_RESISTANCE_LEVEL ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_RESISTANCE_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_RESISTANCE_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_HIGH ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_HIGH ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_BANDWIDTH ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_VOLTAGE_BANDWIDTH_LOW ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE ;
	ViReal64 defaultValue = 9.9E+37 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE ;
	ViReal64 CloseminimumValue = +3.92E-04 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE ;
	ViReal64 ClosemaximumValue = 9.9E37 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE ;
	 
	ViReal64 randomValue = 34565161435287711101342826796488327168.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e3 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_SLEW_RATE;
	ViReal64 ViolationValue = 9.91E37 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_RATE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_RATE ;
	ViReal64 defaultValue = 9.9E+37 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_RATE_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_RATE ;
	ViReal64 CloseminimumValue = +4.45E-04 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e4 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_RATE_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_RATE ;
	ViReal64 ClosemaximumValue = 9.9E37 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_RATE_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_RATE ;
	 
	ViReal64 randomValue = 69460676942231195525946166547146866688.00 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e4 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_RATE_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_RATE;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_SLEW_RATE_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_SLEW_RATE;
	ViReal64 ViolationValue = 9.91E37 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_LEVEL ;
	ViReal64 defaultValue = pInstrumentModel->maxCurrent / 100.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_FUNCTION, 
								 0, AGN6K7KNI_VAL_FUNCTION_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_LIMIT_NEGATIVE ;
	ViReal64 defaultValue = pInstrumentModel->minCurrent ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_LIMIT_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_LIMIT ;
	ViReal64 defaultValue = pInstrumentModel->maxCurrent / 100.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_FUNCTION, 
								 0, AGN6K7KNI_VAL_FUNCTION_VOLTAGE));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OVP_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OVP_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OVP_LIMIT_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OVP_LIMIT ;
	ViReal64 defaultValue = +4.800000E+01 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_LEVEL ;
	ViReal64 defaultValue = pInstrumentModel->minVoltage ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_STEP_TRIGGER_OUT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_SLOPE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_SLOPE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_ACQ_SLOPE_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_VOLTAGE_LEVEL ;
	ViReal64 defaultValue = pInstrumentModel->maxVoltage ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGERED_CURRENT_LEVEL ;
	ViReal64 defaultValue = pInstrumentModel->maxCurrent / 100.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_IMMEDIATE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index17()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index18()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_CURRENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index17()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index18()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index19()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_TRANSIENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index20()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ACQ_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_VOLTAGE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_STEP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_LIST ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_ARB ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_FIXED ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_STEP ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_LIST ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE_DiscreteValue_ReadWrite_Channel__Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CURRENT_TRANSIENT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRANSIENT_MODE_ARB ;	
	ViInt32 returnValue;

	/* Voltage and Current transient mode can not be set to arb at the same time. */
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_VOLTAGE_TRANSIENT_MODE, 
								 0, 1));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGERED_CURRENT_LEVEL ;
	ViReal64 defaultValue = pInstrumentModel->maxCurrent / 100.0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", AGN6K7KNI_ATTR_FUNCTION, 
								 0, AGN6K7KNI_VAL_FUNCTION_CURRENT));

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_SOFTWARE_TRIG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXTERNAL ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_IMMEDIATE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index17()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGER_SOURCE_DiscreteValue_ReadWrite_Channel__Index18()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGER_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_TRIG_PIN7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_TRIGGERED_VOLTAGE_LEVEL ;
	ViReal64 defaultValue = pInstrumentModel->minVoltage ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR1 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR1 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR2 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR3 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR4 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR5 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR6 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR7 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_OFF_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR8 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR1 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR1 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR2 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR3 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR4 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR5 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR6 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR7 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE_DiscreteValue_ReadWrite_NullChannel_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_ON_COUPLE_SOURCE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_EXPR8 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET ;
	ViReal64 CloseminimumValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET ;
	ViReal64 ClosemaximumValue = 1.023 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET ;
	 
	ViReal64 randomValue = 0.55 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_OFFSET;
	ViReal64 ViolationValue = 2.0229999999999997 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_RISE_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_RISE_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE ;
	ViReal64 CloseminimumValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_RISE_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE ;
	ViReal64 ClosemaximumValue = 1023 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_RISE_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE ;
	 
	ViReal64 randomValue = 61.86 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_RISE_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_RISE_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_RISE;
	ViReal64 ViolationValue = 1024 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_FALL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL ;
	ViReal64 defaultValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_FALL_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL ;
	ViReal64 CloseminimumValue = 0 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_FALL_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL ;
	ViReal64 ClosemaximumValue = 1023 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_FALL_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL ;
	 
	ViReal64 randomValue = 545.86 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_FALL_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL;
	ViReal64 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_DELAY_FALL_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_DELAY_FALL;
	ViReal64 ViolationValue = 1024 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_OUTPUT_COUPLE_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_TERMINATE_LAST_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CONSTANT_DWELL_TIME_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME ;
	ViReal64 defaultValue = 0.00100352 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CONSTANT_DWELL_TIME_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME ;
	ViReal64 CloseminimumValue = 0.00001024 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CONSTANT_DWELL_TIME_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME ;
	ViReal64 ClosemaximumValue = 0.30 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e4 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CONSTANT_DWELL_TIME_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME ;
	 
	ViReal64 randomValue = 0.24 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e3 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CONSTANT_DWELL_TIME_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME;
	ViReal64 ViolationValue = -0.99998976 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CONSTANT_DWELL_TIME_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CONSTANT_DWELL_TIME;
	ViReal64 ViolationValue = 250 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_WFM_COUNT_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_WFM_COUNT ;
	ViInt32 defaultValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_WFM_COUNT_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_WFM_COUNT ;
	ViInt32 CloseminimumValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_WFM_COUNT_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_WFM_COUNT ;
	ViInt32 ClosemaximumValue = 256 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_WFM_COUNT_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_WFM_COUNT ;
	 
	ViInt32 randomValue = 13 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_WFM_COUNT_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_WFM_COUNT;
	ViInt32 ViolationValue = 0 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ARB_WFM_COUNT_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ARB_WFM_COUNT;
	ViInt32 ViolationValue = 257 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_FUNCTION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_FUNCTION_CURRENT ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_FUNCTION_VOLTAGE ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_FUNCTION_CURRENT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_TERMINATE_LAST_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_STEP_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_STEP ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_LIST_STEP_AUTO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_STEP_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_STEP ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_LIST_STEP_AUTO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_STEP_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_STEP ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_LIST_STEP_ONCE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_COUNT_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_COUNT ;
	ViInt32 defaultValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_COUNT_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_COUNT ;
	ViInt32 CloseminimumValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_COUNT_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_COUNT ;
	ViInt32 ClosemaximumValue = 4096 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_COUNT_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_COUNT ;
	 
	ViInt32 randomValue = 3676 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_COUNT_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_COUNT;
	ViInt32 ViolationValue = 0 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_LIST_COUNT_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_LIST_COUNT;
	ViInt32 ViolationValue = 4097 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_WINDOW_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_WINDOW ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_MEAS_WINDOW_RECT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_WINDOW_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_WINDOW ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_MEAS_WINDOW_HANNING ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_WINDOW_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_WINDOW ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_MEAS_WINDOW_RECT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_TIME_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_TIME ;
	ViReal64 defaultValue = 1 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e3 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_TIME_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_TIME ;
	ViReal64 CloseminimumValue = 0.0003072 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e3 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_TIME_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_TIME ;
	ViReal64 ClosemaximumValue = 1258290000000 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_TIME_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_TIME ;
	 
	ViReal64 randomValue = 882905639520.30 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e3 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_TIME_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_TIME;
	ViReal64 ViolationValue = -0.9996928 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_MEASUREMENT_TIME_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_MEASUREMENT_TIME;
	ViReal64 ViolationValue = 1.258290000001E12 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL ;
	ViReal64 defaultValue = 0.00000512 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e7 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL ;
	ViReal64 CloseminimumValue = 0.00000512 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e7 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL ;
	ViReal64 ClosemaximumValue = 40000 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e7 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL ;
	 
	ViReal64 randomValue = 17998.01 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e7 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL;
	ViReal64 ViolationValue = -0.99999488 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_TIME_INTERVAL;
	ViReal64 ViolationValue = 40001 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_POINT_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_POINT ;
	ViInt32 defaultValue = 3906 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_POINT_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_POINT ;
	ViInt32 CloseminimumValue = 1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_POINT_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_POINT ;
	ViInt32 ClosemaximumValue = 524288 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_POINT_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_POINT ;
	 
	ViInt32 randomValue = 205225 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_POINT_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_POINT;
	ViInt32 ViolationValue = 0 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_POINT_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_POINT;
	ViInt32 ViolationValue = 524289 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_OFFSET_POINT_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT ;
	ViInt32 defaultValue = 0 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_OFFSET_POINT_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT ;
	ViInt32 CloseminimumValue = -524287 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_OFFSET_POINT_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT ;
	ViInt32 ClosemaximumValue = 2000000000 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_OFFSET_POINT_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT ;
	 
	ViInt32 randomValue = 813222758 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_OFFSET_POINT_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT;
	ViInt32 ViolationValue = -524288 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SWEEP_OFFSET_POINT_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_SWEEP_OFFSET_POINT;
	ViInt32 ViolationValue = 2.000000001E9 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_PERIOD_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_PERIOD ;
	ViReal64 defaultValue = 60 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT_DOUBLES_EQUAL( defaultValue, returnValue, abs(defaultValue) / 10e3 );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_PERIOD_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_PERIOD ;
	ViReal64 CloseminimumValue = 0.0001024 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( CloseminimumValue, returnValue, abs(CloseminimumValue) / 10e3 );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_PERIOD_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_PERIOD ;
	ViReal64 ClosemaximumValue = 60 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
			
	CPPUNIT_ASSERT_DOUBLES_EQUAL( ClosemaximumValue, returnValue, abs(ClosemaximumValue) / 10e3 );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_PERIOD_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_PERIOD ;
	 
	ViReal64 randomValue = 29.29 ;	
	ViReal64 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViReal64 (vi, "", attributeId, 0, &returnValue));
		
	CPPUNIT_ASSERT_DOUBLES_EQUAL( randomValue, returnValue, abs(randomValue) / 10e3 );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_PERIOD_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_PERIOD;
	ViReal64 ViolationValue = -0.9998976 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViReal64
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_PERIOD_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_PERIOD;
	ViReal64 ViolationValue = 61 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViReal64 (vi, "", attributeId, 0, ViolationValue));
}
		

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_VOLTAGE_MINMAX_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_VOLTAGE_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_CURRENT_MINMAX_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_ELOG_CURRENT_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_USER_PROTECTION_SOURCE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_USER_PROTECTION_SOURCE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_EXPRESSION_SOURCE_NONE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_UESR_PROTECTION_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_SENSE_FAULT_DET_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;	
	ViBoolean falseValue = VI_FALSE ;
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( trueValue == returnValue );	
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, VI_NULL, attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, VI_NULL, attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( falseValue == returnValue );		
	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_OFF ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_LATCHING ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_LIVE ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_INHIBIT_MODE ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_INHIBIT_MODE_OFF ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViBoolean
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_BUS_TRIGGER_ENABLED ;
	ViBoolean trueValue = VI_TRUE ;
	ViBoolean falseValue = VI_FALSE ;	
	ViBoolean returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, trueValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( trueValue == returnValue );
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViBoolean (vi, "", attributeId, 0, falseValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViBoolean (vi, "", attributeId, 0, &returnValue));

	CPPUNIT_ASSERT( falseValue == returnValue );	
	
}
			
		
/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read Only
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_INPUT_DATA_defaultValue_ReadOnly_Channel__Index0()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_INPUT_DATA ;
	ViInt32 returnValue;
	
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));	
}
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA ;
	ViInt32 defaultValue = 0 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Close Minimum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA_CloseminimumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA ;
	ViInt32 CloseminimumValue = 0 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, CloseminimumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( CloseminimumValue == returnValue );
}
			
/****************************************************************************
 * Close Maximum Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA_ClosemaximumValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA ;
	ViInt32 ClosemaximumValue = 127 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ClosemaximumValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( ClosemaximumValue == returnValue );	
}
			
/****************************************************************************
 * Random Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/			
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA_RandomValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA ;
	 
	ViInt32 randomValue = 101 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, randomValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( randomValue == returnValue );	
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/	
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA_ViolationMinValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA;
	ViInt32 ViolationValue = -1 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}

/****************************************************************************
 * Violation Value Test	  												    
 * ViInt32
 * Read & Write
 * Should Fail! 
 ****************************************************************************/
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA_ViolationMaxValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_OUTPUT_DATA;
	ViInt32 ViolationValue = 128 ;

	CPPUNIT_ASSERT(VI_SUCCESS != Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, ViolationValue));
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_1_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_1_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_1_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_2_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_2_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_2_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_3_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_3_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_3_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_4_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_4_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_4_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_5_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_5_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_5_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_6_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_6_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_6_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_defaultValue_ReadWrite_REP_7_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_7_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_POS ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY_DiscreteValue_ReadWrite_REP_7_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_POLARITY ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_POL_NEG ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_1_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));

	/* Inhibit is only valid for PIN3 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));

	/* On Couple is only valid for PIN4 to PIN7 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));

	/* Off Couple is only valid for PIN4 to PIN7 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_2_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));

	/* Fault is only valid for PIN1 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	
	/* Inhibit is only valid for PIN3 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));

	/* On Couple is only valid for PIN4 to PIN7 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));

	/* Off Couple is only valid for PIN4 to PIN7 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_3_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));

	/* Fault is only valid for PIN1 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	
	/* On Couple is only valid for PIN4 to PIN7 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));

	/* Off Couple is only valid for PIN4 to PIN7 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_4_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));

	/* Fault is only valid for PIN1 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));

	/* Inhibit is only valid for PIN3 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_5_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	
	/* Fault is only valid for PIN1 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));

	/* Inhibit is only valid for PIN3 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_5_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "5", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "5", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "5", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_6_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));

	/* Fault is only valid for PIN1 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));

	/* Inhibit is only valid for PIN3 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_6_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "6", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "6", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "6", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_defaultValue_ReadWrite_REP_7_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIO ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_DIN ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index6()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR4 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index7()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR5 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index8()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR6 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index9()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR7 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index10()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_EXPR8 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index11()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_FAULT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	
	/* Fault is only valid for PIN1 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index12()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_INHIBIT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));

	/* Inhibit is only valid for PIN3 */
	CPPUNIT_ASSERT( discreteValue != returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index13()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_ON_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index14()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_OFF_COUPLE ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index15()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_INPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION_DiscreteValue_ReadWrite_REP_7_Index16()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_DIGITAL_PIN_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_DIGITAL_PIN_FUNC_TRIG_OUTPUT ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "7", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "7", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "7", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			


/****************************************************************************
 * Default Value Test	  												    
 * ViReal64
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_LEVEL_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_LEVEL ;
	ViReal64 defaultValue = 0 ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_defaultValue_ReadWrite_NullChannel_Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index4()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
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
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_NullChannel_Index5()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, VI_NULL, attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, VI_NULL, attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, VI_NULL, attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	

///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_defaultValue_ReadWrite_REP_1_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_1_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_1_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_defaultValue_ReadWrite_REP_2_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_2_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_2_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_defaultValue_ReadWrite_REP_3_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_3_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_3_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_defaultValue_ReadWrite_REP_4_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_4_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_GT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_OPERATION_DiscreteValue_ReadWrite_REP_4_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_OPERATION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_OPERATION_LT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_defaultValue_ReadWrite_REP_1_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index3()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index4()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_1_Index5()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "1", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "1", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "1", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_defaultValue_ReadWrite_REP_2_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index3()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index4()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_2_Index5()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "2", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "2", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "2", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_defaultValue_ReadWrite_REP_3_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index3()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index4()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_3_Index5()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "3", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "3", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "3", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
//
///****************************************************************************
// * Default Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/		
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_defaultValue_ReadWrite_REP_4_Index0()
//{
//	
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 defaultValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, defaultValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	
//	CPPUNIT_ASSERT( defaultValue == returnValue );
//}
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index1()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_AHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index2()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_CURRENT ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index3()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_POWER ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index4()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_VOLTAGE ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}	
//			
///****************************************************************************
// * Discrete Value Test	  												    
// * ViInt32
// * Read & Write
// ****************************************************************************/				
//void DriverFunctionalityTest::testAGN6K7KNI_ATTR_THRESHOLD_FUNCTION_DiscreteValue_ReadWrite_REP_4_Index5()
//{
//	ViAttr attributeId = AGN6K7KNI_ATTR_THRESHOLD_FUNCTION ;
//	ViInt32 discreteValue = AGN6K7KNI_VAL_THRESHOLD_FUNC_WHOUR ;	
//	ViInt32 returnValue;
//
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "4", attributeId, 0, discreteValue));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "4", attributeId));
//	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "4", attributeId, 0, &returnValue));
//	CPPUNIT_ASSERT( discreteValue == returnValue );
//}				

/****************************************************************************
 * Default Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/		
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CALIBRATION_LEVEL_defaultValue_ReadWrite_Channel__Index0()
{
	
	ViAttr attributeId = AGN6K7KNI_ATTR_CALIBRATION_LEVEL ;
	ViInt32 defaultValue = AGN6K7KNI_VAL_CAL_LEVEL_P1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, defaultValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	
	CPPUNIT_ASSERT( defaultValue == returnValue );
}
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CALIBRATION_LEVEL_DiscreteValue_ReadWrite_Channel__Index1()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CALIBRATION_LEVEL ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_CAL_LEVEL_P1 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CALIBRATION_LEVEL_DiscreteValue_ReadWrite_Channel__Index2()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CALIBRATION_LEVEL ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_CAL_LEVEL_P2 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
			
/****************************************************************************
 * Discrete Value Test	  												    
 * ViInt32
 * Read & Write
 ****************************************************************************/				
void DriverFunctionalityTest::testAGN6K7KNI_ATTR_CALIBRATION_LEVEL_DiscreteValue_ReadWrite_Channel__Index3()
{
	ViAttr attributeId = AGN6K7KNI_ATTR_CALIBRATION_LEVEL ;
	ViInt32 discreteValue = AGN6K7KNI_VAL_CAL_LEVEL_P3 ;	
	ViInt32 returnValue;

	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_SetAttributeViInt32 (vi, "", attributeId, 0, discreteValue));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_InvalidateAttribute (vi, "", attributeId));
	CPPUNIT_ASSERT(VI_SUCCESS == Ivi_GetAttributeViInt32 (vi, "", attributeId, 0, &returnValue));
	CPPUNIT_ASSERT( discreteValue == returnValue );
}	
		