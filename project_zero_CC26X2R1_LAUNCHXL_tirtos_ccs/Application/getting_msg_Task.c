/******************************************************************************

   @file  project_zero.c

   @brief This file contains the Project Zero sample application for use
        with the CC2650 Bluetooth Low Energy Protocol Stack.

   Group: WCS, BTS
   Target Device: cc13x2_26x2

 ******************************************************************************
   
 Copyright (c) 2015-2021, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************
   
   
 *****************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include <string.h>

#if (!(defined __TI_COMPILER_VERSION__) && !(defined __GNUC__))
#include <intrinsics.h>
#endif

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/drivers/utils/List.h>

//#include <xdc/runtime/Log.h> // Comment this in to use xdc.runtime.Log
#include <ti/common/cc26xx/uartlog/UartLog.h>  // Comment out if using xdc Log

#include <ti/display/AnsiColor.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/sys_ctrl.h)

#include <icall.h>
#include <bcomdef.h>
/* This Header file contains all BLE API and icall structure definition */
#include <icall_ble_api.h>

/* Bluetooth Profiles */
#include <devinfoservice.h>
#include <profiles/project_zero/data_service.h>
#include <profiles/oad/cc26xx/oad.h>

/* Includes needed for reverting to factory and erasing external flash */
#include <ti/common/cc26xx/oad/oad_image_header.h>
#include <ti/drivers/dpl/HwiP.h>
#include <ti/drivers/NVS.h>
#include DeviceFamily_constructPath(driverlib/flash.h)

/* Application specific includes */
#include <ti_drivers_config.h>

#include "getting_msg_Task.h"
#include "ti_ble_config.h"
#include <util.h>

/*  disassembly   */
#include "disassembly/disassambler.h"

/*********************************************************************
 * MACROS
 */

// Spin if the expression is not true
#define APP_ASSERT(expr) if(!(expr)) {project_zero_spin();}

#define UTIL_ARRTOHEX_REVERSE     1
#define UTIL_ARRTOHEX_NO_REVERSE  0

/*********************************************************************
 * CONSTANTS
 */
// Task configuration

#define PZ_TASK_PRIORITY                     2

#ifndef PZ_TASK_STACK_SIZE
#define PZ_TASK_STACK_SIZE                   2048
#endif
// Internal Events used by OAD profile


// Internal Events for RTOS application


// Bitwise OR of all RTOS events to pend on

// Types of messages that can be sent to the user application task from other
// tasks or interrupts. Note: Messages from BLE Stack are sent differently.


// Supervision timeout conversion rate to miliseconds


// Connection interval conversion rate to miliseconds

// message sizes

/*********************************************************************
 * TYPEDEFS
 */
// Struct for messages sent to the application task

/*********************************************************************
 * GLOBAL VARIABLES
 */
// Task configuration
Task_Struct pzTask_2;
#if defined __TI_COMPILER_VERSION__
#pragma DATA_ALIGN(appTaskStack_2, 8)
#elif defined(__GNUC__) || defined(__clang__)
__attribute__ ((aligned (8)))
#else
#pragma data_alignment=8
#endif
uint8_t appTaskStack_2[PZ_TASK_STACK_SIZE];

/*********************************************************************
 * LOCAL VARIABLES
 */

// Entity ID globally used to check for source and/or destination of messages


// Event globally used to post local events and pend on system and
// local events.


// Queue object used for app messages

// Advertising handles


// Per-handle connection info


// List to store connection handles for set phy command status's


// List to store connection handles for queued param updates


/*
 * Initial LED pin configuration table
 *   - LEDs CONFIG_PIN_RLED & CONFIG_PIN_GLED are off.
 */



// Clock instance for RPA read events.


// Variable used to store the number of messages pending once OAD completes
// The application cannot reboot until all pending messages are sent


// Flag to be stored in NV that tracks whether service changed
// indications needs to be sent out

// Address mode


// Current Random Private Address


/*********************************************************************
 * LOCAL FUNCTIONS
 */

/* Task functions */
static void GettingMsg_init(void);
static void GettingMsg_taskFxn(UArg a0,
                                UArg a1);

/* Event message processing functions */


/* Profile value change handlers */

/* Stack or profile callback function */


/* Connection handling functions */


/* Button handling functions */

/* Utility functions */


/**************************disassembler***********************/



/*********************************************************************
 * EXTERN FUNCTIONS
 */


/*********************************************************************
 * PROFILE CALLBACKS
 */
// GAP Bond Manager Callbacks


/*********************************************************************
 * PUBLIC FUNCTIONS
 */

/*********************************************************************
 * @fn     project_zero_spin
 *
 * @brief   Spin forever
 */


/*********************************************************************
 * @fn      ProjectZero_createTask
 *
 * @brief   Task creation function for the Project Zero.
 */
void GettingMsg_createTask(void)
{
    Task_Params taskParams;

    // Configure task
    Task_Params_init(&taskParams);
    taskParams.stack = appTaskStack_2;
    taskParams.stackSize = PZ_TASK_STACK_SIZE;
    taskParams.priority = PZ_TASK_PRIORITY;

    Task_construct(&pzTask_2, GettingMsg_taskFxn, &taskParams, NULL);
}

/*********************************************************************
 * @fn      ProjectZero_init
 *
 * @brief   Called during initialization and contains application
 *          specific initialization (ie. hardware initialization/setup,
 *          table initialization, power up notification, etc), and
 *          profile initialization/setup.
 */
static void GettingMsg_init(void)
{

}

/*********************************************************************
 * @fn      ProjectZero_taskFxn
 *
 * @brief   Application task entry point for the Project Zero.
 *
 * @param   a0, a1 - not used.
 */
static void GettingMsg_taskFxn(UArg a0, UArg a1)
{
    // Initialize application
    GettingMsg_init();

    // Application main loop


}

/*********************************************************************
 * @fn      ProjectZero_processL2CAPMsg
 *
 * @brief   Process L2CAP messages and events.
 *
 * @param   pMsg - L2CAP signal buffer from stack
 *
 * @return  None
 */


/*********************************************************************
 * @fn      ProjectZero_checkSvcChgndFlag
 *
 * @brief   Process an incoming OAD reboot
 *
 * @param   flag - mask of events received
 *
 * @return  none
 */


/*********************************************************************
 * @fn      ProjectZero_processStackEvent
 *
 * @brief   Process stack event. The event flags received are user-selected
 *          via previous calls to stack APIs.
 *
 * @param   stack_event - mask of events received
 *
 * @return  none
 */


/*********************************************************************
 * @fn      ProjectZero_processGATTMsg
 *
 * @brief   Process GATT messages and events.
 *
 * @param   pMsg - message to process
 *
 * @return  TRUE if safe to deallocate incoming message, FALSE otherwise.
 */

/*********************************************************************
 * @fn      ProjectZero_processApplicationMessage
 *
 * @brief   Handle application messages
 *
 *          These are messages not from the BLE stack, but from the
 *          application itself.
 *
 *          For example, in a Software Interrupt (Swi) it is not possible to
 *          call any BLE APIs, so instead the Swi function must send a message
 *          to the application Task for processing in Task context.
 *
 * @param   pMsg  Pointer to the message of type pzMsg_t.
 */


/*********************************************************************
 * @fn      ProjectZero_processGapMessage
 *
 * @brief   Process an incoming GAP event.
 *
 * @param   pMsg - message to process
 */


/*********************************************************************
 * @fn      ProjectZero_processAdvEvent
 *
 * @brief   Process advertising event in app context
 *
 * @param   pEventData
 *
 * @return  TRUE if safe to deallocate incoming message, FALSE otherwise.
 */

/*********************************************************************
 * @fn      ProjectZero_processPairState
 *
 * @brief   Process the new paring state.
 *
 * @param   pPairData - pointer to pair state data container
 */

/*********************************************************************
 * @fn      ProjectZero_processPasscode
 *
 * @brief   Process the Passcode request.
 *
 * @param   pReq - pointer to passcode req
 */

/*********************************************************************
 * @fn      ProjectZero_processConnEvt
 *
 * @brief   Process connection event.
 *
 * @param pReport pointer to connection event report
 */

/*********************************************************************
 * @fn      ProjectZero_clockHandler
 *
 * @brief   clock handler function
 *
 * @param   arg - argument from the clock initiator
 *
 * @return  none
 */

/*********************************************************************
 * @fn      ProjectZero_connEvtCB
 *
 * @brief   Connection event callback.
 *
 * @param pReport pointer to connection event report
 */

/*********************************************************************
 * @fn      ProjectZero_processCmdCompleteEvt
 *
 * @brief   Process an incoming OSAL HCI Command Complete Event.
 *
 * @param   pMsg - message to process
 */


/*********************************************************************
 * @fn      ProjectZero_handleUpdateLinkParamReq
 *
 * @brief   Receive and respond to a parameter update request sent by
 *          a peer device
 *
 * @param   pReq - pointer to stack request message
 */


/*********************************************************************
 * @fn      ProjectZero_handleUpdateLinkEvent
 *
 * @brief   Receive and parse a parameter update that has occurred.
 *
 * @param   pEvt - pointer to stack event message
 */


/*********************************************************************
 * @fn      ProjectZero_addConn
 *
 * @brief   Add a device to the connected device list
 *
 * @param   connHandle - connection handle
 *
 * @return  bleMemAllocError if a param update event could not be sent. Else SUCCESS.
 */

/*********************************************************************
 * @fn      ProjectZero_getConnIndex
 *
 * @brief   Find index in the connected device list by connHandle
 *
 * @param   connHandle - connection handle
 *
 * @return  the index of the entry that has the given connection handle.
 *          if there is no match, MAX_NUM_BLE_CONNS will be returned.
 */


/*********************************************************************
 * @fn      ProjectZero_clearConnListEntry
 *
 * @brief   Clear the connection information structure held locally.
 *
 * @param   connHandle - connection handle
 *
 * @return  SUCCESS if connHandle found valid index or bleInvalidRange
 *          if index wasn't found. LINKDB_CONNHANDLE_ALL will always succeed.
 */


/*********************************************************************
 * @fn      ProjectZero_removeConn
 *
 * @brief   Remove a device from the connected device list
 *
 * @param   connHandle - connection handle
 *
 * @return  index of the connected device list entry where the new connection
 *          info is removed from.
 *          if connHandle is not found, MAX_NUM_BLE_CONNS will be returned.
 */


/*********************************************************************
 * @fn      ProjectZero_sendParamUpdate
 *
 * @brief   Remove a device from the connected device list
 *
 * @param   connHandle - connection handle
 */

/*********************************************************************
 * @fn      ProjectZero_updatePHYStat
 *
 * @brief   Update the auto phy update state machine
 *
 * @param   eventCode - HCI LE Event code
 *          pMsg - message to process
 */



/*
 * @brief   Handle a write request sent from a peer device.
 *
 *          Invoked by the Task based on a message received from a callback.
 *
 *          When we get here, the request has already been accepted by the
 *          service and is valid from a BLE protocol perspective as well as
 *          having the correct length as defined in the service implementation.
 *
 * @param   pCharData  pointer to malloc'd char write data
 *
 * @return  None.
 */


/*
 * @brief   Handle a CCCD (configuration change) write received from a peer
 *          device. This tells us whether the peer device wants us to send
 *          Notifications or Indications.
 *
 * @param   pCharData  pointer to malloc'd char write data
 *
 * @return  None.
 */


/******************************************************************************
 *****************************************************************************
 *
 *  Handlers of direct system callbacks.
 *
 *  Typically enqueue the information or request as a message for the
 *  application Task for handling.
 *
 ****************************************************************************
 *****************************************************************************/

/*
 *  Callbacks from the Stack Task context (GAP or Service changes)
 *****************************************************************************/

/*********************************************************************
 * @fn      ProjectZero_advCallback
 *
 * @brief   GapAdv module callback
 *
 * @param   pMsg - message to process
 *          pBuf - data potentially accompanying event
 *          arg - not used
 */

/*********************************************************************
 * @fn      ProjectZero_pairStateCb
 *
 * @brief   Pairing state callback.
 *
 * @param   connHandle - connection handle
 *          state - pair state
 *          status - pair status
*/

/*********************************************************************
 * @fn      ProjectZero_passcodeCb
 *
 * @brief   Passcode callback.
 *
 * @param   pDeviceAddr - not used
 *          connHandle - connection handle
 *          uiInpuits - if TRUE, the local device should accept a passcode input
 *          uiOutputs - if TRUE, the local device should display the passcode
 *          numComparison - the code that should be displayed for numeric
 *          comparison pairing. If this is zero, then passcode pairing is occurring.
 */



/*********************************************************************
 * @fn      ProjectZero_DataService_ValueChangeCB
 *
 * @brief   Callback for characteristic change when a peer writes to us
 *
 * @param   connHandle - connection handle
 *          paramID - the parameter ID maps to the characteristic written to
 *          len - length of the data written
 *          pValue - pointer to the data written
 */



/*********************************************************************
 * @fn      ProjectZero_DataService_CfgChangeCB
 *
 * @brief   Callback for when a peer enables or disables the CCCD attribute,
 *          indicating they are interested in notifications or indications.
 *
 * @param   connHandle - connection handle
 *          paramID - the parameter ID maps to the characteristic written to
 *          len - length of the data written
 *          pValue - pointer to the data written
 */


/*********************************************************************
 * @fn      ProjectZero_processOadWriteCB
 *
 * @brief   Process an OAD event
 *
 * @param   connHandle - the connection Handle this request is from.
 * @param   bim_var    - bim_var to set before resetting.
 *
 * @return  None.
 */

/*
 *  Callbacks from Swi-context
 *****************************************************************************/




/******************************************************************************
 *****************************************************************************
 *
 *  Utility functions
 *
 ****************************************************************************
 *****************************************************************************/

/*********************************************************************
 * @fn     ProjectZero_enqueueMsg
 *
 * @brief  Utility function that sends the event and data to the application.
 *         Handled in the task loop.
 *
 * @param  event    Event type
 * @param  pData    Pointer to message data
 */


/*********************************************************************
 * @fn     util_arrtohex
 *
 * @brief   Convert {0x01, 0x02} to "01:02"
 *
 * @param   src - source byte-array
 * @param   src_len - length of array
 * @param   dst - destination string-array
 * @param   dst_len - length of array
 *
 * @return  array as string
 */

/*********************************************************************
 * @fn     util_getLocalNameStr
 *
 * @brief   Extract the LOCALNAME from Scan/AdvData
 *
 * @param   data - Pointer to the advertisement or scan response data
 * @param   len  - Length of advertisment or scan repsonse data
 *
 * @return  Pointer to null-terminated string with the adv local name.
 */


/*********************************************************************
 * @fn      projectZero_eraseExternalFlash
 *
 * @brief   Utility function that erases external flash content
 *
 * @return  void
 */


/*********************************************************************
*********************************************************************/
