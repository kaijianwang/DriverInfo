/***************************************************************************** 
 *  Copyright 2005-2015, National Instruments Corporation.  All Rights Reserved.   * 
 *****************************************************************************/

/*****************************************************************************
 *  tkafg3k Instrument Driver Sample Program                              
 *  Developed with LabWindows/CVI 2012                                     
 *  Original Release:                                   
 *
 *  Purpose:  This sample program initializes the function generator, creates a
 *            arbitrary waveform, configures it to output a arbitrary waveform, 
 *            copy waveform form edit memory1 to edit memory 2, and displays a 
 *            message pop-up dialog.
 *
 *            To run this sample program, do the following:
 *            1) Create a new project in LabWindows/CVI.
 *            2) Add this file to the project.  To add files to the project,
 *               select the Add Files To Project from the Edit menu of the 
 *               Project window.
 *            3) Add one of the following files to the project:
 *               tkafg3k.fp, tkafg3k.c, or tkafg3k.lib.
 *            4) Check that the resource name used in tkafg3k_InitWithOptions()
 *               is correct. If simulating, change flag to simulate.
 *            5) Run the project.
 *
 *  Note:     The function is only supported by double-channel AFG3kC models: 
 *            AFG3052C, AFG3102C, AFG3252C, AFG3022C.
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
#include "tkafg3k.h"

 
/* If the instrument is not available, please enable simulation to run this	  *
 * example. 		                                                          *
 *  - To enable simulation, change the "Simulate=0" to "Simulate=1"           *
 *    specify the model to simulate by setting the "Model : 284" string.      */
#define TKAFG3K_EXAMPLE_INIT_OPTION  "Simulate=0,RangeCheck=1,QueryInstrStatus=0,Cache=1"
#define TKAFG3K_EXAMPLE_ARB_WFM_SIZE 1000

main ()

{
    ViSession   tkafg3k;
	ViInt32     i, iArbWfmHandle;
    ViReal64    rData[TKAFG3K_EXAMPLE_ARB_WFM_SIZE];
    ViStatus    error = VI_SUCCESS;
    ViString    popUpMsg = "The function generator is outputting the waveform"  
                           "that you configured.\n\nPress <Enter> to continue";

    /* Initialize */
    checkErr( tkafg3k_InitWithOptions ("GPIB::11::INSTR", VI_TRUE, VI_TRUE,
                                        TKAFG3K_EXAMPLE_INIT_OPTION,
                                        &tkafg3k));
	
	/* Clear arbitrary waveforms in memory */
    checkErr( tkafg3k_ClearArbWaveform (tkafg3k, -1));

    /* Create an arbitrary waveform and upload it to the instrument */
    for (i = 0; i < TKAFG3K_EXAMPLE_ARB_WFM_SIZE; ++i)
    {
        rData[i] = 1.0;
    }
	
	checkErr( tkafg3k_CreateArbWaveform (tkafg3k,
                                         TKAFG3K_EXAMPLE_ARB_WFM_SIZE,
                                         rData, &iArbWfmHandle));
	/* Set the output mode to arbitrary waveform output */
    checkErr( tkafg3k_ConfigureOutputModeByChannel (tkafg3k, "1", TKAFG3K_VAL_OUTPUT_ARB));
	checkErr( tkafg3k_ConfigureOutputModeByChannel (tkafg3k, "2", TKAFG3K_VAL_OUTPUT_ARB));
	
	/* Configures the arbitrary waveform */
    checkErr( tkafg3k_ConfigureArbWaveform (tkafg3k, "1", iArbWfmHandle, 0.5, 0.0));
	
	/* Copy waveform data in the edit memory 1 to the edit memory 2 */
    checkErr( tkafg3k_CopyWfmDataBetweenEditMemory (tkafg3k, TKAFG3K_VAL_OUTPUT_EMEM1, TKAFG3K_VAL_OUTPUT_EMEM2));
	
	
    MessagePopup ("Message", popUpMsg);
                                        
Error:
    if (error != VI_SUCCESS)
        {
            ViChar   errStr[2048];

            tkafg3k_GetError (tkafg3k, &error, 2048, errStr);
            MessagePopup ("Error!", errStr);
        }

    if (tkafg3k)
        tkafg3k_close (tkafg3k);
}
