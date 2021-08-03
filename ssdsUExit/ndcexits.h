//
// $Id: Exports/Interface/ndcexits.h 1.12.1.4 2013/07/25 16:20:05IST Joseph, Anju Maria (aj185076) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
//
//
//   File: ndcexits.h
//
//   Author: Colin Beattie
//
//
//   Program: SSDS NDC
//
//   Module: NDCEXITS
//
//   FS Number: 445-0630453
//
//   Classes in this file:   1) mSupervisorExitExecutor
//                           2) mGenericExitExecutor
//                           3) mVirtualController
//                           4) mNDCMsgSender
//                           5) mNDCMsgReceiver
//
//   1) See supexdo.cpp for description and usage
//   2) See genexdo.cpp for description and usage
//   3) See virtcont.cpp for description and usage
//   4) See ndcsend.cpp for description and usage
//   5) See ndcrecv.cpp for description and usage
//
//******************************************************************************/
//
// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/NDCCore/NDCEXITS.pj $
//
// $Log: Exports/Interface/ndcexits.h  $
// Revision 1.12.1.4 2013/07/25 16:20:05IST Joseph, Anju Maria (aj185076) 
// AANDC 10180 integrated
// Revision 1.12.1.3 2013/07/19 13:42:03IST Kotla, Sravani (sk185272) 
// AANDC-10180 Customisations: The message data should be logged to the DebugLog, when an incoming virtual controller reflects the message using the return codes 2 or 3
// Revision 1.12.1.2.1.3 2013/07/19 13:11:14IST Kotla, Sravani (sk185272) 
// AANDC-10180 Customisations: The message data should be logged to the DebugLog, when an incoming virtual controller reflects the message using the return codes 2 or 3
// Revision 1.12.1.2.1.2 2013/07/18 12:56:04IST Kotla, Sravani (sk185272) 
// AANDC-10180 Customisations: The message data should be logged to the DebugLog, when an incoming virtual controller reflects the message using the return codes 2 or 3
// Revision 1.12.1.2.1.1 2013/07/18 12:40:09IST Kotla, Sravani (sk185272) 
// AANDC-10180 Customisations: The message data should be logged to the DebugLog, when an incoming virtual controller reflects the message using the return codes 2 or 3
// Revision 1.12.1.2 2013/07/04 17:55:12IST Kotla, Sravani (sk185272) 
// Merging the updates of AANDC-2959
// Revision 1.12.1.1.1.4 2013/07/04 17:31:15IST Kotla, Sravani (sk185272) 
// AANDC-2959 Multiple sequential incoming virtual controllers when used with VC reflection
// Revision 1.12.1.1.1.3 2013/07/02 15:23:45IST Kotla, Sravani (sk185272) 
// AANDC-2959 Multiple sequential incoming virtual controllers when used with VC reflection
// Revision 1.12.1.1.1.2 2013/06/20 16:21:47IST Kotla, Sravani (sk185272) 
// AANDC-2959 Multiple sequential incoming virtual controllers when used with VC reflection
// Revision 1.12.1.1.1.1 2013/06/20 16:04:38IST Kotla, Sravani (sk185272) 
// AANDC-2959 Multiple sequential incoming virtual controllers when used with VC reflection
// Revision 1.12.1.1 2013/06/20 16:04:20IST Kotla, Sravani (sk185272) 
// AANDC-2959 Multiple sequential incoming virtual controllers when used with VC reflection
// Revision 1.12 2009/03/19 22:30:15IST Dryden, Jim (JD515051) 
// AANDC340_to_trunk
// Revision 1.11.1.2 2009/03/19 17:00:15GMT Kilgore, Andrew (ak185068) 
// RFC 419915 - Delivered for IT3
// Revision 1.11.1.1.1.3 2009/02/23 11:37:07GMT Kilgore, Andrew (ak185068) 
// RFC 419915 - Moved MaskMessageData function to lower level
// Revision 1.11.1.1.1.2 2009/01/26 11:16:33GMT Kilgore, Andrew (ak185068) 
// RFC 419915 - Added exported functions to mask message data including EMV formatted data
// Revision 1.11 2008/10/02 13:38:32BST Dryden, Jim (JD515051) 
// ANDC330_to_trunk
// Revision 1.10.1.6 2008/10/02 13:38:32BST Peat, Stephen James (sp185018) 
// Moved the creatation and desctuction of the NDCCommConnection used for message reflection to the constructor/destructor
// Revision 1.10.1.5.1.1 2008/09/25 12:07:18BST Peat, Stephen James (sp185018) 
// Duplicate revision
// Revision 1.10.1.4.1.2 2008/09/19 16:19:59BST Peat, Stephen James (sp185018) 
// Updates for SendMessageToTerminal Call 
//    - Removed injected semaphore and injectedProcessEvent method
//    - Added Message Flag enum values
// Revision 1.10.1.4.1.1 2008/09/16 16:27:58BST Peat, Stephen James (sp185018) 
// Duplicate revision
// Revision 1.10.1.1.1.2 2008/05/26 14:35:55BST Turner, Peter (PT515698) 
// hooks for all mode changes-  required updates
// Revision 1.10 2007/06/21 11:07:33BST jd515051 
// ANDC320_to_trunk
// Revision 1.9.3.4 2007/06/21 11:07:33BST ak185068 
// Merge changes to Main Branch
// Revision 1.9.3.3 2007/03/16 14:39:22GMT zy515747 
// RFC321325 - Message Reflection
// Revision 1.9.3.2.1.1 2007/02/14 16:28:57IST rg185040 
// Duplicate revision
// Revision 1.9.3.1.1.2 2007/02/08 18:56:29IST ss185068 
// GR1T 352808 : Migration Complete(Additional Trace details)
// Revision 1.9.1.1.1.4 2006/12/04 20:04:45IST ss185068 
// GR1T 352808:Updated to keep TraceMessageToJournal() in Protected area.
// Revision 1.9.1.1.1.3 2006/12/04 14:55:42IST ss185068 
// GR1T 352808 : Updated function TraceMessageToJournal()
// Revision 1.9.1.1.1.2 2006/11/23 16:11:32IST ss185068 
// GR1T352808 - Added function TraceMessageToJournal.
// Revision 1.9.1.1.1.1 2005/02/25 18:20:09IST ss185068 
// Duplicate revision
// Revision 1.8 2005/02/08 17:13:38GMT sp185018 
// RFC 246177 - Dial Up Support - Added Caller and timer members for Disconnect, Noop and CP message timer processing
// Revision 1.7 2005/02/01 13:24:51GMT sp185018 
// RFC 246177 - Dial Up support - Addition of worker context to allow re-starting of message receiver whenlow level dial up msg is received.
// Revision 1.6  2004/02/18 12:16:43Z  ba200004
// TAR 257785 - Message going missing if 2 messages sent from host at the same time
// Revision 1.5  2002/04/15 09:26:04Z  NG400008
// Revision 1.4  2001/06/04 16:50:48Z  rl400003
// TAR170749 -ASCII/EBCDIC Conversion
// Revision 1.3  2001/01/15 09:47:57Z  stepheng
// RFC 212677 - Additional 'C' exit hook to be actioned upon execution of the close state processing.
// Revision 1.2  1998/03/26 13:50:26Z  stepheng
// RTTI for Virtual Controller needed to be changed
// to work with the Visual C++ RTTI mechanism.  Virtual Controller 
// was posting messages that were being ignored by main 
// worker beacause the 'this' pointers were not based on the
// mConcreteWorker Class.
// Revision 1.1  1998/01/29 18:23:15  stepheng
// Initial Revision
//
// +------------------------------------------------------------------------------+
//

#ifndef _NDCEXITS_H
#define _NDCEXITS_H

#include "control.h"
#include "commsWC.h"
#include "datamanWC.h"
#include "flwcntrlWC.h"  // RFC 246177 Dialup Support
#include "vpicomms.h"  // Required for mNDCCommsConnectionID within mNDCMsgSender

class mIntegerGetter;
class mIntegerPutter;

class CSupervisorExitThread;
class CGenericExitThread;

#if defined MICROSOFT_NT
    #if !defined(NDCEXITS_LIB)
        #define IMP_OR_EXP __declspec(dllimport)
    #else
        #define IMP_OR_EXP __declspec(dllexport)
    #endif
#endif

class IMP_OR_EXP mSupervisorExitExecutor : public mDoer, public mConcreteWorker
{
friend class CSupervisorExitThread;

public:
   mSupervisorExitExecutor();
   ~mSupervisorExitExecutor();

   virtual void Start(mEventContext *pEventContext,
                     mWorkContext &ExecutingContext,
                     mWorkContext *pForwardContext);

   virtual mSignal *Stop(mEventContext *pEventContext,
                        mWorkContext &WorkContext);

   virtual mSignal *ProcessEvent(mEventContext *pEventContext,
                                 mWorkContext &WorkContext,
                                 const mEvent *pEvent);

   static const int SUPERVISOR_EXECUTED_SIGNAL_ID;
   static const int SUPERVISOR_NOT_EXECUTED_SIGNAL_ID;

   // Integer Getter work groups

   virtual void Add_CurrentMenu_Worker(mIntegerGetter *pCurrentMenu,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);
   virtual void Remove_CurrentMenu_Worker(mIntegerGetter *pCurrentMenu = NULL,
                                          unsigned short nWorkGroup = 0,
                                          unsigned short nIndex = 0);

   virtual void Add_Function_Worker(mIntegerGetter *pFunction,
                                    unsigned short nWorkGroup = 0,
                                    unsigned short nIndex = 0);
   virtual void Remove_Function_Worker(mIntegerGetter *pFunction = NULL,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);

   virtual void Add_CurrentInterface_Worker(mIntegerGetter *pCurrentInterface,
                                          unsigned short nWorkGroup = 0,
                                          unsigned short nIndex = 0);
   virtual void Remove_CurrentInterface_Worker(mIntegerGetter *pCurrentInterface = NULL,
                                             unsigned short nWorkGroup = 0,
                                             unsigned short nIndex = 0);

   // Integer Putter work groups

   virtual void Add_NextMenu_Worker(mIntegerPutter *pNextMenu,
                                    unsigned short nWorkGroup = 0,
                                    unsigned short nIndex = 0);
   virtual void Remove_NextMenu_Worker(mIntegerPutter *pNextMenu = NULL,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);

   virtual void Add_NextInterface_Worker(mIntegerPutter *pNextInterface,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);
   virtual void Remove_NextInterface_Worker(mIntegerPutter *pNextInterface = NULL,
                                          unsigned short nWorkGroup = 0,
                                          unsigned short nIndex = 0);

   virtual void Add_HostMenu_Worker(mIntegerPutter *pHostMenu,
                                    unsigned short nWorkGroup = 0,
                                    unsigned short nIndex = 0);
   virtual void Remove_HostMenu_Worker(mIntegerPutter *pHostMenu = NULL,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);

   virtual void Add_HostFunction_Worker(mIntegerPutter *pHostFunction,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);
   virtual void Remove_HostFunction_Worker(mIntegerPutter *pHostFunction = NULL,
                                          unsigned short nWorkGroup = 0,
                                          unsigned short nIndex = 0);

protected:
   CSupervisorExitThread *m_pSupervisorThread;

   mEventContext *m_pEventContext;

   mIntegerGetter *m_pCurrentMenu;
   mIntegerGetter *m_pFunction;
   mIntegerGetter *m_pCurrentInterface;

   mIntegerPutter *m_pNextMenu;
   mIntegerPutter *m_pNextInterface;
   mIntegerPutter *m_pHostMenu;
   mIntegerPutter *m_pHostFunction;
};

class IMP_OR_EXP mGenericExitExecutor : public mDoer, public mConcreteWorker
{
friend class CGenericExitThread;

public:
   mGenericExitExecutor();
   ~mGenericExitExecutor();

   virtual void Start(mEventContext *pEventContext,
                     mWorkContext &ExecutingContext,
                     mWorkContext *pForwardContext);

   virtual mSignal *Stop(mEventContext *pEventContext,
                        mWorkContext &WorkContext);

   virtual mSignal *ProcessEvent(mEventContext *pEventContext,
                                 mWorkContext &WorkContext,
                                 const mEvent *pEvent);

   static const int COMPLETED_SIGNAL_ID;

   enum GenericExitType
   {
      USAGE_SupervisorEntry = 0,
      USAGE_SupervisorExit,
      USAGE_SupervisorStop,
      USAGE_ClearFitness,
      USAGE_ClearDevice,
      USAGE_NDCSuspend,
      USAGE_Initialise,
      USAGE_CloseState,  // RFC 212677 - Additional 'C' exit hook to be actioned upon execution of the close state processing.
	  USAGE_ModeChange   // RFC 390161
   };

   // GenericExitType attribute
// SG VA Port   void set_Usage(GenericExitType nUsage);
   void set_Usage(int nUsage);

   // Integer Getter work groups
   virtual void Add_Parameter_Worker(mIntegerGetter *pParameter,
                                    unsigned short nWorkGroup = 0,
                                    unsigned short nIndex = 0);
   virtual void Remove_Parameter_Worker(mIntegerGetter *pParameter = NULL,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);

   // Integer Putter work groups
   virtual void Add_ReturnValue_Worker(mIntegerPutter *pReturnValue,
                                       unsigned short nWorkGroup = 0,
                                       unsigned short nIndex = 0);
   virtual void Remove_ReturnValue_Worker(mIntegerPutter *pReturnValue = NULL,
                                          unsigned short nWorkGroup = 0,
                                          unsigned short nIndex = 0);

protected:
   CGenericExitThread *m_pGenericThread;

   mEventContext *m_pEventContext;
   char ConvertUsageToChar();

   GenericExitType m_nUsage;
   mIntegerGetter *m_pParameter;
   mIntegerPutter *m_pReturnValue;
};

class CMessageMACer;
class CInterceptorThread;
class mEventContext;

class IMP_OR_EXP mVirtualController
{
friend class CInterceptorThread; // Needs access to m_pEC and m_strMessage

public:
   mVirtualController(BOOLEAN bOutbound);
   ~mVirtualController();

   void setOwningObject(mConcreteWorker * owner);
   
   // Signals which can be generated by NDC Message Senders or Receivers. Other
   // possible signals ('Successful' or 'Failed' are inherited from Message
   // Senders/Receivers, and are defined elsewhere. These are public because
   // they are required in the Transaction Handler code.
   static const int DELETED_SIGNAL_ID;
   static const int INVALID_MAC_SIGNAL_ID;
   static const int REFLECTED_SIGNAL_ID;

protected:
   CInterceptorThread *m_pInterceptorThread; // Used to execute interceptor
                                             // functions in a separate thread

   // Pointer to event context and message buffer are stored in order to be
   // accessible to interceptor thread
   mEventContext *m_pEC;
   mString m_strMessage;
   int m_intMsgFlags;

   // Sender bit in message contains one of these values 
   static const char HOST;
   static const char NDC;

   // Grit 222713 Class byte in message contains one of 
   static const char COMMAND;
   static const char UNSOL;

   // Grit 222713 Command byte in message contains
   static const char SEND;

   // Values for data when posting an event
   static const char VIRTUAL_MESSAGE_AVAILABLE;
   static const char DELETE_USER_MSG;
   static const char REPLY_USER_MSG;
   static const char FORWARD_USER_MSG;
   static const char MACING_COMPLETE;

   BOOLEAN m_bOutbound; // Set by constructor, and used to determine which global
                        // CInterceptor object (g_OutboundInterceptor or
                        // g_InboundInterceptor) to use. Also used in
                        // conjunction with sender bit in message to determine
                        // if message is being reflected or forwarded.

   CMessageMACer *m_pMessageMACer;  // Used by derived classes to add MAC to
   mString m_strMACedMessage;       // outgoing messages, and check MAC on
                                    // incoming messsages.

    //TAR 170749 - ASCII/EBCDIC conversion
    class mNDCMessageConverter *m_pNDCMessageConverter; 
};

class IMP_OR_EXP mNDCMsgSender : public mMsgSender, public mVirtualController
{
public:
   mNDCMsgSender();
   ~mNDCMsgSender();

   virtual void Start(mEventContext *pEC,
                     mWorkContext &WC,
                     mWorkContext *pFWC);

   virtual mSignal *ProcessEvent(mEventContext *pEC,
                                 mWorkContext &WC,
                                 const mEvent *pEvent);

   virtual mSignal *Stop(mEventContext *pEC,
                         mWorkContext &WC);
 
protected:
   BOOLEAN m_bBaseClassStarted;
   mStringStore *m_pInterceptedParcel;
   mStringGetter *m_pOriginalParcel;
   mString m_strMACedMessage; 
   mNDCCommsConnectionID *m_pCommsConnection;

private:
   static mCaller m_CPMsgSentClr;
   mString m_strDupMsgForReflectionForDebug;
};

class IMP_OR_EXP mNDCMsgReceiver : public mMsgReceiver, public mVirtualController
{
public:
   mNDCMsgReceiver();
   ~mNDCMsgReceiver();

   virtual void Start(mEventContext *pEC,
                     mWorkContext &WC,
                     mWorkContext *pFWC);

   virtual mSignal *ProcessEvent(mEventContext *pEC,
                                 mWorkContext &WC,
                                 const mEvent *pEvent);

   virtual mSignal *Stop(mEventContext *pEC,
                         mWorkContext &WC);


   enum MessageFlagsValue 
   {
     NoFlag = 0,
     HostMsgFlag = 1, 
     ExitMsgFlag = 2, 
     ViaInterceptorsFlag = 4,
	 ReflectedMsgFlag = 8,
     // Next MessageFlagsValue should be 16 as this is a bitmap.
   };

protected:
   double m_dTimeDelay;

   mMsgSender *m_pMessageSender;
   mStringStore *m_pReflectedMessage;
   BOOLEAN m_bMessageSenderActive;

   BOOLEAN m_bMACValid;
   BOOLEAN m_bMACExists;

   // Checks if the event flags the existence of a Virtual Message
   virtual mSignal *ProcessVirtualMessageEvent(mEventContext *pEC,
                                             mWorkContext &WC,
                                             const mEvent *pEvent);

     // Checks if the event flags the completion of the interceptor functions
   virtual mSignal *ProcessInterceptorEvent(mEventContext *pEC,
                                          mWorkContext &WC,
                                          const mEvent *pEvent);

   // Checks if the event flags the completion (success or failure) of the embedded message sender
   virtual mSignal *ProcessMessageSendEvent(mEventContext *pEC,
                                          mWorkContext &WC,
                                          const mEvent *pEvent);

   // Checks if the event flags the completion of MAC calculation or validation
   virtual mSignal *ProcessMACEvent(mEventContext *pEC,
                                    mWorkContext &WC,
                                    const mEvent *pEvent);

   // Checks if the event flags the arrival of a message from the host
   virtual mSignal *ProcessIncomingMessageEvent(mEventContext *pEC,
                                                mWorkContext &WC,
                                                const mEvent *pEvent);

   BOOLEAN m_bReflectingMessage;

   // Belongs in mMsgReceiver
   void GetMessage(const mEvent *pEvent, mString &strInputMessage);

   // The transaction handler is now required to start an NDC Message Sender
   // and NDC Message Receiver at the same time, instead of consecutively,
   // as previously. The function VirtualMessagesOnly, which sets the variables
   // m_bVirtualMessageOnly and m_pAssociatedSender, can be used by the
   // transaction handler to inhibit processing of all events other than
   // virtual message events sent by the specified NDC Message Sender
   BOOL m_bVirtualMessageOnly;
   mNDCMsgSender *m_pAssociatedSender;

public:
   void set_TimeDelay(double dTimeDelay);

   void VirtualMessagesOnly(BOOL bVirtualMessageOnly,
                           mNDCMsgSender *pSender = NULL);

private:
	//TAR 257785 - flag to prevent a message receiver processing more than one message
	bool m_bFirstMessage; 

  // RFC 246177 -Dial Up Support - Stores worker context so that message receiver can be
  // restarted if a dial-up level message is recieved that should not be feed up 
  // to the rest of the system.
  mWorkContext *m_pFWC; 
};

#if defined MICROSOFT_NT
#undef IMP_OR_EXP
#endif

#endif   // _NDCEXITS_H
