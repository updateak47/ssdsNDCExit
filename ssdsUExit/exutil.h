//
// $Id: Exports/Interface/exutil.h 1.5 2010/03/24 17:12:44IST Bhat, Ravi (br185000) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
//   Author: Colin Beattie
//
//
//   Program: SSDS NDC
//
//   Module: EXUTIL
//
//   FS Number: 445-0630453
//
//   Functions:  AllocateMessageBuffer
//               FreeMessageBuffer
//               SendStatus
//               SendUnformattedData
//               PerformNDCState
//               DumpData
//               SetDigitalAudioPath
//               PrintToJournal (RFC 212697)
//
//   Purpose:    This file contains all the functions which can be exported to an
//               exit application from the SSDS-NDC Exits project
//
//
// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/NDCCore/EXUTIL.pj $
//
// $Log: Exports/Interface/exutil.h  $
// Revision 1.5 2010/03/24 17:12:44IST Bhat, Ravi (br185000) 
// ANDC400_to_trunk
// Revision 1.4.1.3 2010/03/24 17:12:44IST Veluru, Suresh (sv185025) 
// G456182 Merged onto devpath
// Revision 1.4.1.2.1.1 2010/01/27 21:19:55IST Veluru, Suresh (sv185025) 
// Duplicate revision
// Revision 1.4 2001/02/15 20:49:04IST Dryden, Jim (JD515051) 
// ANDC330_to_trunk
// Revision 1.3.2.1 2001/02/15 15:19:04GMT PT515698 
// Duplicate revision
// Revision 1.2.1.1  2001/02/15 15:19:04Z  AS515646
// Update for EMV/CAM2 Digital Audio callback
// Revision 1.2  2001/01/16 10:03:42Z  stepheng
// RFC 212697 - PrintToJournal callback function required to allow prints to Journal or EJ
// Revision 1.1  1998/01/29 18:26:14Z  stepheng
// Initial Revision
//
// +------------------------------------------------------------------------------+
//

#ifndef _EXUTIL_H
#define _EXUTIL_H

#if defined MICROSOFT_NT
    #if !defined(EXUTIL_LIB)
        #define IMP_OR_EXP __declspec(dllimport)
    #else
        #define IMP_OR_EXP __declspec(dllexport)
    #endif
#endif

// Return values for SendStatus and SendUnformattedData
const unsigned char MESSAGE_TRANSMITTED = 0;
const unsigned char FAILED_LINK_UP      = 1;
const unsigned char FAILED_LINK_DOWN    = 2;
const unsigned char ILLEGAL_MESSAGE     = 3;

// Return values for PerformNDCState
const unsigned char STATE_EXECUTED =                 0;
const unsigned char STATE_TYPE_ILLEGAL =             1;
const unsigned char STATE_TABLE_FAILED_VALIDATION =  2;
const unsigned char EXIT_STATE =                     3;
const unsigned char CARD_READ_STATE =                4;
const unsigned char TOO_MANY_INVOCATIONS =           5;

const unsigned char MAX_INVOCATIONS =				 2;

extern "C" IMP_OR_EXP char * AllocateMessageBuffer(unsigned int nNumChars);

extern "C" IMP_OR_EXP void FreeMessageBuffer(char *pchMessage);

extern "C" IMP_OR_EXP unsigned char SendStatus(char *pszData,
                                               unsigned char bSolicited,
                                               unsigned char bViaInterceptors);

extern "C" IMP_OR_EXP unsigned char SendUnformattedData(char *pszData,
                                                        unsigned char bViaInterceptors);

extern "C" IMP_OR_EXP unsigned char PerformNDCState(char cStateLetter,
                                                    unsigned long *pnNextStateNumber,
                                                    unsigned long *pnTableExitId);

extern "C" IMP_OR_EXP void DumpData(void);

// RFC 212697 - PrintToJournal callback function required to allow prints to Journal or EJ
//
extern "C" IMP_OR_EXP void PrintToJournal (char* JournalData,
                                           unsigned long DataLength,
                                           char* Response);
//RFC 390166
extern "C" IMP_OR_EXP bool PrintToReceipt (char* ReceiptData,
                                           unsigned long DataLength,
                                           char* Response);
extern "C" bool IMP_OR_EXP PrintToStatement (char* StatementData,
                                           unsigned long DataLength,
                                           char* Response);
//Added for compatibility with EMV
extern "C" IMP_OR_EXP void SetDigitalAudioPath(unsigned char language);


#if defined MICROSOFT_NT
#undef IMP_OR_EXP
#endif

#endif   // _EXUTIL_H
