/***************************************************************************** 
 *  Copyright 2016, National Instruments Corporation.  All Rights Reserved.   * 
 *****************************************************************************/

/*****************************************************************************
 *  tkafg1k Instrument Driver Sample Program                              
 *  Developed with LabWindows/CVI 12.0.1
 *  Original Release:                                   
 *
 *  Purpose:  This sample program initializes the function generator, configures
 *            it to output a arbitrary waveform, and displays a message 
 *            pop-up dialog.
 *
 *            To run this sample program, do the following:
 *            1) Create a new project in LabWindows/CVI.
 *            2) Add this file to the project.  To add files to the project,
 *               select the Add Files To Project from the Edit menu of the 
 *               Project window.
 *            3) Add one of the following files to the project:
 *               tkafg1k.fp, tkafg1k.c, or tkafg1k.lib.
 *            4) Check that the resource name used in tkafg1k_InitWithOptions()
 *               is correct. If simulating, change flag to simulate.
 *            5) Run the project.
 *
 *            VCC or Borland Users:
 *            This example uses CVI's MessagePopup() to display the
 *            measured value.  Replace this MessagePopup() function with a 
 *            printf() or similar display function.  Remove the include 
 *            statement: #include <userint.h> from the source code.  Follow 
 *            the directions for CVI users given above.
 *****************************************************************************/

#include <stdio.h>
#include <userint.h>
#include "tkafg1k.h"

/* If the instrument is not available, please enable simulation to run this	  *
 * example. 		                                                          *
 *  - To enable simulation, change the "Simulate=0" to "Simulate=1"           *
 *    specify the model to simulate by setting the "Model : 284" string.      */
#define TKAFG1K_EXAMPLE_INIT_OPTION  "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1"
#define TKAFG1K_EXAMPLE_ARB_WFM_SIZE 500
//#define TKAFG1K_EXAMPLE_ARB_WFM_SIZE 5
/* -------------------------------------------------------------------------- */
/* ============================== Main Entry ================================ */
/* -------------------------------------------------------------------------- */
int main ()
{
    ViSession   tkafg1k;
    ViInt32     i, iArbWfmHandle;
    ViReal64    rData[TKAFG1K_EXAMPLE_ARB_WFM_SIZE];
    ViStatus    error = VI_SUCCESS;
    ViString    popUpMsg = "The function generator is outputting the waveform "  
                           "that you configured.\n\nPress <Enter> to continue";

    /* Initialize */
    checkErr( tkafg1k_InitWithOptions ("USB0::0x0699::0x0353::1525004::INSTR", VI_TRUE, VI_TRUE,
                                        TKAFG1K_EXAMPLE_INIT_OPTION,
                                        &tkafg1k));

    /* Create an arbitrary waveform and upload it to the instrument */
    for (i = 0; i < TKAFG1K_EXAMPLE_ARB_WFM_SIZE; ++i)
    {
        rData[i] = 2.0;
    }
    checkErr( tkafg1k_CreateArbWaveform (tkafg1k,
                                         TKAFG1K_EXAMPLE_ARB_WFM_SIZE,
                                         rData, &iArbWfmHandle));

    /* Set the output mode to arbitrary waveform output */
    checkErr( tkafg1k_ConfigureOutputModeByChannel (tkafg1k, "1", TKAFG1K_VAL_OUTPUT_ARB));

    /* Configure other output parameters */
    checkErr( tkafg1k_ConfigureOutputImpedance (tkafg1k, "1", 50));

    /* Configures the arbitrary waveform */
    checkErr( tkafg1k_ConfigureArbWaveform (tkafg1k, "1", iArbWfmHandle, 0.5, 0));
    checkErr( tkafg1k_ConfigureArbFrequency (tkafg1k, "1", 1000000)); 

    /* Configure the opeartion mode and enables the output */
    checkErr( tkafg1k_ConfigureOperationMode (tkafg1k, "1", TKAFG1K_VAL_OPERATE_CONTINUOUS));
    checkErr( tkafg1k_ConfigureOutputEnabled (tkafg1k, "1", VI_TRUE));


    MessagePopup ("Message", popUpMsg);
                                        
Error:
    if (error != VI_SUCCESS)
        {
            ViChar   errStr[2048];

            tkafg1k_GetError (tkafg1k, &error, 2048, errStr);
            MessagePopup ("Error!", errStr);
        }

    if (tkafg1k)
        tkafg1k_close (tkafg1k);
}
