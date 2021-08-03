#ifndef NDCDEF_H
#define NDCDEF_H

//
// $Id: NDCCore/Exports/Interface/ndcdef.h 1.5 2010/05/28 16:03:23IST Bhat, Ravi (br185000) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
//
//    Program:  SSDS NDC
//
//    Common constants and definitions.
//
// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/NDCCore.pj $
//
// $Log: NDCCore/Exports/Interface/ndcdef.h  $
// Revision 1.5 2010/05/28 16:03:23IST Bhat, Ravi (br185000) 
// ANDC400_to_trunk
// Revision 1.4.3.3 2010/05/28 16:03:23IST Gavarasana, Hima (hg185004) 
// G468400 - Renamed the constant
// Revision 1.4.3.2 2010/05/24 12:21:31IST Gavarasana, Hima (hg185004) 
// G463400 - Added Device_Not_COnfigured constant
// Revision 1.4.3.1 2004/08/27 18:38:49IST Gavarasana, Hima (hg185004) 
// Duplicate revision
// Revision 1.3.1.2  2004/03/15 09:32:26Z  pd515063
// TAR 260651 Error strings missing for EPPExpectedWorkerMissing and EPPUndeterminedError
// Revision 1.3.1.1  2002/03/20 16:35:20Z  pd515063
// Duplicate revision
// Revision 1.3  2002/03/20 16:35:20Z  AS515646
// Revision 1.2.1.2  2002/03/20 16:35:20Z  poolep
// Integrated EPP Development
// Revision 1.2.1.1  2001/02/07 13:53:04Z  poolep
// Duplicate revision
// Revision 1.2  2001/02/07 13:53:04Z  DM410006
// EMV new constants added  and Increased Constants for expanded fields
// Revision 1.1  1998/11/09 16:38:26Z  stepheng
// Initial revision
// Revision 1.3  1998/07/26 12:15:08  stepheng
// Updated mError to reflect component architecture
// Revision 1.2  1998/02/20 11:11:06  weirm
// Added mError IDs relating to EKC
// Revision 1.1  1998/01/29 18:48:58  stepheng
// Initial revision
//
// +------------------------------------------------------------------------------+
//
//     
//      18-12-1997   12:03:40p , Rev 1.0, s_glencross(1616)
//      LCM Munched file - trying to un-munch it
//     
//      14-11-1997   12:01:24p , Rev 2.0, r_robinson(165c)
//      Added constant MAX_FIT_NUMBER  RFC 5624
//      Added constants and enum related to a FIT Record
//
//      06-10-1997   02:16:00a , Rev 3.0, s_glencross(1616)
//      moved mError Definition into BORLAND_OS2 definition, causes error with
//      NDCCUST module
//
//     Thu Sep 25 17:23:08 1997, Rev 2.0, c_beattie(1658)
//      Error IDs for new memory management mErrors.
//
//      17-09-1997   01:11:46a , Rev 1.0, s_glencross(1616)
//      Initial Visual Age Port
//
//     Wed Sep 17 13:11:46 1997, Rev 6.0, c_beattie(1658)
//      Identifiers for new mError strings used in test environment when
//      interceptors have leaked or corrupted memory.
//
//     Tue Aug 05 15:41:20 1997, Rev 5.0, c_beattie(1658)
//      Centralise mError IDs in ndcdef.h
//
//      21-04-1997   04:02:10a , Rev 4.0, s_glencross(1616)
//      const defines for BORLAND only
//
//     Tue Apr 01 13:41:32 1997, Rev 3.0, p_nicholson(164e)
//      Additional constants for MAC field selection.
//
//     Tue Feb 11 09:16:10 1997, Rev 2.0, s_glencross(1616)
//      changed const char* pointer to const char * const pointer
//      to eliminate linker error.
//
//      03-02-1997   04:54:32a , Rev 1.0, s_glencross(1616)
//      Original Release.
//


typedef struct tagFITRecord
{
   int   FIT_Number;

   int   PIDDX;                  // Added so we can support exits
   int   PIDDX_Location;
   BOOL  PIDDX_ModIndex;
   BYTE  PFIID[5];
   int   PSTDX;                  // Added so we can support exits
   int   PSTDX_Branch,
         PSTDX_Logo;
   int   PAGDX;                  // Added so we can support exits
   int   PAGDX_Location;
   int   PMXPN;                  // Added so we can support exits
   int   PMXPN_MaxDigits,
         PMXPN_BlockType;
   int   PCKLN;                  // Added so we can support exits
   int   PCKLN_VerMethod,
         PCKLN_NumDigits;
   int   PINPD;                  // Added so we can support exits
   int   PINPD_PadChar,
         PINPD_EncryptType,
         PINPD_Key,
         PINPD_MsgCoord;
   int   PANDX_Location;
   int   PANLN;                  // Added so we can support exits
   int   PANLN_NumDigits;
   BOOL  PANLN_LocalCheck;
   int   PANPD;                  // Added so we can support exits
   int   PANPD_PINVerKey,
         PANPD_PANPad;
   int   PRCNT;                  // Added so we can support exits
   int   PRCNT_RetryCountLocation,
         PRCNT_RetryType;

   int   POFDX_PINOffset;
   BYTE  PDCTB_DESTable[8];
   BYTE  PEKEY_PINKey[8];
   BYTE  PINDX_IndexTable[3];
   int   PLNDX_Offset;

   int   PMMSR;                   // Added so we can support exits
   BOOL  PMMSR_SensorRequired;
   BOOL  PMMSR_CancelOnFailure;

   BYTE  PREF2_Index;
   BYTE  PVBDX_Offset;
   BYTE  PVBLN_Length;
   int   PBFMT;                  // A.S. Added for EPP 
   int   PBFMT_BlockType;
} FITRecord;

#if defined MICROSOFT_NT

const BYTE FIELD_SEPARATOR = 0x1c;
const BYTE GROUP_SEPARATOR = 0x1d;
const BYTE RECORD_SEPARATOR = 0x1e;

const int MAC_LENGTH = 8;

const int MAX_FIT_NUMBER = 999;                         // RSR 13/11/97  RFC 5624
                                                        //
const int  FINANCIAL_INSTITUTE_ID_LENGTH = 10;          //
const int  ENCRYPTED_PEKEY_LENGTH = 16;                 //
const int  DECIMALISATION_TABLE_LENGTH = 16;            //
enum PINDX_Access{ ALGORITHM_NUMBER = 0,                // For Uncompressed Array
                   FINANCIAL_INSTITUTION,               // of Reference Points
                   PIN_RETRY_COUNT,                     //
                   PAN,                                 //
                   LANGUAGE_CODE,                       //
                   PIN_OFFSET_DATA,                     //
                   INDEX_REFERENCE_POINT_ARRAY_LENGTH };//

const char * const MISSING_INPUT_DATA = "A01";
const char * const OUT_OF_RANGE = "B05";
const char * const DEV_NOT_CONFIGURED = "E02";

// MAC field selection field lengths
const int MAX_LEN_MAC_SEL_TRANS_REQ   = 47;
const int MAX_LEN_MAC_SEL_TRANS_REPLY = 36;
const int MAX_LEN_MAC_SEL_SOL_STATUS  = 11;	
const int MAX_LEN_MAC_SEL_OTHER       = 4;
const int MAX_LEN_MAC_SEL_TRACK1      = 6;
const int MAX_LEN_MAC_SEL_TRACK2      = 6;
const int MAX_LEN_MAC_SEL_TRACK3      = 11;
const int MAX_LEN_MAC_SEL_EMV_CONFIG  = 5;

// Card writer constants
const BYTE TRACK_END_SENTINEL    = 0x3f;
const BYTE TRACK1_START_SENTINEL = 0x25;
const BYTE TRACK2_START_SENTINEL = 0x3b;
const BYTE TRACK3_START_SENTINEL = 0x3b;

//
//-- mError ID's
//
//
//-- Customisation Layer
//
const int SSDSNDCPACKAGE_CL                   = 115;

const int StateNumber0NotExpected             = 1;
const int TransactionRequestNotExpected       = 2;
const int CloseStateNotExpected               = 3;


//-- Application Core
//
const int SSDSNDCPACKAGE_AC                   = 116;

const int FailedToReadRegistryFile            = 1;
const int FailedToLoadExitDll                 = 2;
const int FailedToLoadExitFunction            = 3;
const int OutboundInterceptorMemoryLeak       = 4;
const int OutboundInterceptorMemoryCorruption = 5;
const int InboundInterceptorMemoryLeak        = 6;
const int InboundInterceptorMemoryCorruption  = 7;
const int OutboundInterceptorMemoryError      = 8;
const int InboundInterceptorMemoryError       = 9;
const int IllegalEKCCommand                   = 10;
const int EKCResetAfterTimeout                = 11;
const int EKCNotConfigured                    = 12;
const int EPPExpectedWorkerMissing			  = 20; //TAR 260651 
const int EPPUndeterminedError				  = 21;

#endif // MICROSOFT_NT

#endif
