/***************************************************************************** 
 *  (c)  2014, National Instruments, Corporation.  All Rights Reserved.      * 
 *****************************************************************************/

/*****************************************************************************
 *  agn6k7kni Instrument Driver Example Program                              
 *  Developed with LabWindows/CVI                                   
 *
 *  Purpose:  This sample program initializes the power supply, configures
 *            the external datalog system of the APS, retrieve the external
 *            datalog records and displays a message pop-up dialog.
 *
 *            To run this sample program, do the following:
 *            1) Create a new project in LabWindows/CVI.
 *            2) Add this file to the project.  To add files to the project,
 *               select the Add Files To Project from the Edit menu of the 
 *               Project window.
 *            3) Add one of the following files to the project:
 *               agn6k7kni.fp, agn6k7kni.c, or agn6k7kni.lib.
 *            4) Check that the resource name used in agn6k7kni_InitWithOptions()
 *               is correct. If simulating, change flag to simulate.
 *            5) Run the project.
 *
 *            VCC or Borland Users:
 *            This example uses CVI's MessagePopup() to display the
 *            measured value.  You will need to replace this function with a 
 *            printf() or similar display function.  You will then need to 
 *            remove the #include <userint.h> statement.  You can then follow 
 *            the above directions for CVI users.
 *
 *****************************************************************************/

#include <utility.h>
#include <userint.h>
#include <stdio.h>
#include "agn6k7kni.h"

void BuildErrorString (ViSession agn6k7kni, ViStatus error, ViString errStr);

int main (void)
{
    ViSession   agn6k7kni = VI_NULL;
    ViStatus    error = VI_SUCCESS;
    ViChar      popUpMsg[1024];
    
    ViReal64    datalogArr[10];
    ViInt32     i = 0,
                actualRecords = 0;
    ViChar      *pMsg = popUpMsg;

	popUpMsg[0] = '\0';
	/* 
	 If you want to run this sample program and the instrument is not present, set the Simulate flag to 1.
     ( Example for single slots: "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1,DriverSetup=Model:N7952A",)
	   Example for empty or double slots: "Simulate=1,RangeCheck=1,QueryInstrStatus=0,Cache=1,DriverSetup=Model:N7952A",)			
     */
    checkErr( agn6k7kni_InitWithOptions (
                                            "TCPIP0::A-N7952A-40001::inst0::INSTR",	/* resourceName */
                                            VI_TRUE,			/* IdQuery */
                                            VI_TRUE,			/* resetDevice */
                                            "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1",
                                            &agn6k7kni)
                                        );
    
    /*- Configure external datalog system. -----------------------------------------------------------*/
    
    /* To set Voltage datalog, Enables external datalog and enables logging */
    /* of the minimum and maximum voltage values. */
    checkErr( agn6k7kni_ConfigureElog (agn6k7kni, "1", AGN6K7KNI_VAL_ELOG_MEAS_FUNC_VOLTAGE, VI_TRUE, VI_TRUE));
    /* To set an integration period of 600 microseconds and enable seamless elog autoranging */ 
    checkErr( agn6k7kni_ConfigureElogMeasurement (agn6k7kni, "1", 0.0006, AGN6K7KNI_VAL_ELOG_CURRENT_RANGE_AUTO));
    
    checkErr( agn6k7kni_InitiateDatalog(agn6k7kni, "1"));
    checkErr( agn6k7kni_SendDatalogTrigger(agn6k7kni, "1"));

    
    /*- Read output state. ---------------------------------------------------------------------------*/
    
	Delay(2.0);
    
    checkErr( agn6k7kni_FetchDatalog(agn6k7kni, "1", 5000, 10, datalogArr, &actualRecords));

    popUpMsg[0] = 0;
    
    pMsg += sprintf (pMsg, "%s", "Elog Data are: \n");
    
    for (i = 0; i < actualRecords; ++i)
    {
        pMsg += sprintf(pMsg, "%lf\n", datalogArr[i]);
    }

#ifdef _CVI_
	MessagePopup ("Message", popUpMsg);
#else
	printf("Message:\n%s", popUpMsg);
#endif
	

Error:
    if (error != VI_SUCCESS)
        {
            ViChar   errStr[2048];

            BuildErrorString (agn6k7kni, error, errStr);
#ifdef _CVI_
            MessagePopup ("Error!", errStr);
#else
			printf("Message:\n%s", errStr);
#endif
        }
    
    if (agn6k7kni)
        agn6k7kni_close (agn6k7kni);
	
	return 0;
}

/*****************************************************************************
 * Function: BuildErrorString   
 * Purpose:  This function builds a string that describes the error that the 
 *           sample program encounters using the error information functions 
 *           that the instrument driver exports.
 *****************************************************************************/
void BuildErrorString (ViSession agn6k7kni, ViStatus error, ViString errStr)
{

    ViChar   tempStr[256], errElabStr[256];
    ViChar   *p = errStr;
    ViStatus primaryErr, secondaryErr;
            
    p += sprintf (p, "Driver Status:  (Hex 0x%x)", error);
                                
        /* Get description of the returned status code */
    agn6k7kni_error_message (agn6k7kni, error, tempStr);
    p += sprintf (p, " %s\n\n", tempStr);
        
        /* Get any additional error information */
    errElabStr[0] = 0;
    agn6k7kni_GetErrorInfo (agn6k7kni, &primaryErr, &secondaryErr, errElabStr);
    
    if (primaryErr == error)
        {
        if (secondaryErr != VI_SUCCESS)
            {
                p += sprintf (p, "Secondary Error:  (Hex 0x%x)", secondaryErr);
                                
                    /* Get description of the returned status code */
                agn6k7kni_error_message (agn6k7kni, secondaryErr, tempStr);
                p += sprintf (p, " %s\n\n", tempStr);
            }
        if (errElabStr[0] != 0)
            sprintf (p, "Elaboration:  %s", errElabStr);
        }
}
