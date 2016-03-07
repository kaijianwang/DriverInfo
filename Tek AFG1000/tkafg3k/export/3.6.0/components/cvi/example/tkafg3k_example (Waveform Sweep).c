/***************************************************************************** 
 *  Copyright 2005-2013, National Instruments Corporation.  All Rights Reserved.   * 
 *****************************************************************************/

/*****************************************************************************
 *  tkafg3k Instrument Driver Sample Program                              
 *  Developed with LabWindows/CVI 2012
 *  Original Release:                                   
 *
 *  Purpose:  This sample program initializes the function generator, configures
 *            it to output a waveform sweep, and displays a message 
 *            pop-up dialog.
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

/* -------------------------------------------------------------------------- */
/* ============================== Main Entry ================================ */
/* -------------------------------------------------------------------------- */
int main ()
{
    ViSession   tkafg3k;
    ViStatus    error = VI_SUCCESS;
    ViString    popUpMsg = "The function generator is outputting the waveform "  
                           "that you configured.\n\nPress <Enter> to continue";

    /* Initialize */
    checkErr( tkafg3k_InitWithOptions ("GPIB::11::INSTR", VI_TRUE, VI_TRUE,
                                        TKAFG3K_EXAMPLE_INIT_OPTION,
                                        &tkafg3k));

    /* Set trigger */
    checkErr( tkafg3k_ConfigureTriggerSource (tkafg3k, "1", TKAFG3K_VAL_INTERNAL_TRIGGER));
    checkErr( tkafg3k_ConfigureInternalTriggerRate (tkafg3k, 1000.0));

    /* Configure sweep settings */
    checkErr( tkafg3k_ConfigureSweep (tkafg3k, "1", 100000, 1000000, 0.01, TKAFG3K_VAL_SWEEP_LINEAR));
    checkErr( tkafg3k_ConfigureSweepEnabled (tkafg3k, "1", VI_TRUE));

    /* Enables the output */
    checkErr( tkafg3k_ConfigureOutputEnabled (tkafg3k, "1", VI_TRUE));


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
