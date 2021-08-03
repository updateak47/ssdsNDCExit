//
// $Id: SSCoreWCL/Exports/Interface/ndcdatae.h 1.129 2013/07/24 16:21:15IST Gavarasana, Hima (hg185004) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
/*
旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴??                  SSDS NDC Customisation Data Interface                   ??                          File: ndcdatae.h                                ??                                                                          ?쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴??Definitions in this file :-                                               ??                                                                          ??Enumerated Types for use by the Common Data DLL Functions                 ??                                                                          ?쳐컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴??                                                                          ??                         MODIFICATION RECORD                              ??                         ===================                              ??                                                                          ?쳐컴컴컴컴컴컴컴컫컴컴컴컫컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컫컴컴??    Change     ?ersion?escription                                  ?nit?쳐컴컴컴컫컴컴컴캑       ?                                            ?   ??Date   ?RIT No?      ?                                            ?   ?쳐컴컴컴컵컴컴컴컵컴컴컴컵컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컵컴컴??8/03/96?-     ? 00   ?Original Release                            ?GT ?쳐컴컴컴컵컴컴컴컵컴컴컴컵컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컵컴컴??6/09/96?-     ? 01   ?IDs added for Transoft error handling       ?GT ??       ?      ?      ?idCDIErrorNumber                            ?GT ??       ?      ?      ?idCDIErrorParam1-9                          ?GT ??       ?      ?      ?idCDIErrorMessage                           ?GT ??       ?      ?      ?idRejectStatus                              ?GT ?쳐컴컴컴컵컴컴컴컵컴컴컴컵컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컵컴컴?*/
// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/SSCoreWCL.pj $
//
// $Log: SSCoreWCL/Exports/Interface/ndcdatae.h  $
// Revision 1.129 2013/07/24 16:21:15IST Gavarasana, Hima (hg185004) 
// Added CDI index in code comments
// Revision 1.128 2013/07/22 20:06:47IST Gavarasana, Hima (hg185004) 
// AANDC-9462: new CDIs added to hold deposit limits received in buffer d of transaction reply messages
// Revision 1.127 2012/10/23 15:54:08IST Aremanda, Aparna (aa185078) 
// Merged idCurrCoinDisp(5008) to main branch.
// Revision 1.126.1.1 2012/10/22 16:31:26IST Aremanda, Aparna (aa185078) 
// idCurrCoinDisp cdi added
// Revision 1.126 2012/09/26 07:37:31IST Spafford, Michael (MS515892) 
// 575628 - CashIn Camera Support
// Revision 1.125 2012/08/16 10:08:13BST Bankapalli, Siva Prasad (sb185127) 
// RFC 582837 merged into Dev Path
// Revision 1.124 2012/03/23 11:22:29IST Maradani, Nageswara Rao (nm185020) 
// Merging RFC 579672 updates into devpath
// Revision 1.123 2012/03/15 19:56:56IST Duncan, Philip (pd515063) 
// G581006
// Revision 1.122 2012/03/09 13:48:36GMT Duncan, Philip (pd515063) 
// Modified name for G581006
// Revision 1.121 2012/03/07 12:00:50GMT Duncan, Philip (pd515063) 
// Added Int Array for CDM (Cash out) denominations per cassette type
// Revision 1.120 2012/02/16 06:43:55GMT Maradani, Nageswara Rao (nm185020) 
// Merging into devpath
// Revision 1.119.1.1 2012/02/09 13:32:01IST Maradani, Nageswara Rao (nm185020) 
// Added an integer CDI for for Host Tx Timeout
// Revision 1.119 2012/02/02 11:54:45IST Bankapalli, Siva Prasad (sb185127) 
// G576225 Code merged to trunk
// Revision 1.118 2011/07/01 16:48:14IST Chelamalasetty, Praveen (pc185011) 
// Product RFC 502921: Add OfflineEncashCounts and OfflineEncashTotal to ICashInCounters and CashInCounters, and create corresponding CDIs support
// Revision 1.117 2011/06/22 16:25:32IST Kolli, Vijay (vk185005) 
// GR1T 546873 - Added integer store to know whether promote is running or not
// Revision 1.116 2011/06/22 12:29:06IST Chelamalasetty, Praveen (pc185011) 
// 501971: RetractRecyleCounts
// Revision 1.115 2011/06/21 13:36:20IST Gavarasana, Hima (hg185004) 
// G538853 - new CDI added for CashInNotesPresent
// Revision 1.114 2011/03/07 11:51:24IST KONJERLA, SURESH (sk185201) 
// changing the CDI store name
// Revision 1.113 2011/03/04 11:32:26IST KONJERLA, SURESH (sk185201) 
// added a CDIstore
// Revision 1.112 2011/02/24 18:34:09IST Maradani, Nageswara Rao (nm185020) 
// Merging RFC 502345 updates into devpath
// Revision 1.111.2.1 2011/02/14 18:55:33IST Maradani, Nageswara Rao (nm185020) 
// Added a integer store to verify any device recovered during AER
// Revision 1.111 2010/12/28 10:59:35IST Gavarasana, Hima (hg185004) 
// G432058 - Timer 63 implementation
// Revision 1.110 2010/12/07 17:20:31IST Duncan, Philip (pd515063) 
// G490120 - modified CDIs for this RFC
// Revision 1.109 2010/12/06 13:52:19GMT Duncan, Philip (pd515063) 
// RFC 490120 - RFC to obtain correct retract counts on CDM retract
// Revision 1.108 2010/10/25 06:46:55BST Gavarasana, Hima (hg185004) 
// G485890 - Added new CDI for no of cash in retract operations
// Revision 1.107 2010/09/23 11:07:56IST Gavarasana, Hima (hg185004) 
// G477145 - Added comment to idBNA24VResetRequired to say it's no longer used
// Revision 1.106 2010/08/18 13:46:18IST Chacko, Anu (ac185092) 
// Updated CDI stores to store Promote and Relate enabled status
// Revision 1.105 2010/06/28 09:36:53IST Gavarasana, Hima (hg185004) 
// G463488 - Added new CDI for Cash In Device Variant
// Revision 1.104 2010/05/07 15:24:58IST Chacko, Anu (ac185092) 
// idReceiptCaptureBinStatus added for unsolicited message update for receipt capture bin
// Revision 1.103 2010/05/06 13:49:54LKT Maradani, Nageswara Rao (nm185020) 
// Removed idEJLevel
// Revision 1.102 2010/04/12 17:13:05IST Maradani, Nageswara Rao (nm185020) 
// Added idEJLevel to address RFC 444564
// Revision 1.101 2010/03/10 17:14:05IST Chacko, Anu (ac185092) 
// Updated idCardholderDisplayUnsol for cardholder display sensor unsol reporting
// Revision 1.100 2010/02/09 12:06:36LKT Chacko, Anu (ac185092) 
// idStateFlowSequence persistent string store updated
// Revision 1.99 2009/06/03 15:32:52LKT Pattullo, Euan (EP410005) 
// TAR 405403
// Revision 1.96 2009/03/25 10:40:58IST Maradani, Nageswara Rao (nm185020) 
// Added integer and string stores for 24V Reset requirement
// Revision 1.95 2009/03/20 08:59:58IST Gavarasana, Hima (hg185004) 
// G397941  - added new stores for SCPM support
// Revision 1.94 2008/10/10 10:56:19IST Maradani, Nageswara Rao (nm185020) 
// Removed unused CDI store
// Revision 1.93 2008/10/07 19:32:55IST Maradani, Nageswara Rao (nm185020) 
// Added store to preserve current print side
// Revision 1.92 2008/09/25 19:31:13IST Spafford, Michael (ms515892) 
// RFC G379467 Last Transaction Status counts should not be cumulative. New persistent integers defined idLastTransaction...
// Revision 1.90 2008/09/15 10:03:17BST Peat, Stephen James (sp185018) 
// Updates to support SendMessage To Terminal
// Revision 1.88 2008/07/04 11:16:37BST Glencross, Stephen (SG515142) 
// 398168: Biometric timers 80 & 81
// Revision 1.87 2008/06/24 13:08:51BST Maradani, Nageswara Rao (nm185020) 
// Updated for GR1T392679 - 2ST Receipt Print Support
// Revision 1.86 2008/06/18 17:10:54IST Kanike, Mahadevappa (mk185054) 
// idCamDeviceStatusEnabled (3767) store added to hold the unsol reporting to host flag
// Revision 1.85 2008/06/18 15:40:54IST Kanike, Mahadevappa (mk185054) 
// Added idCamCapacityStatus=1361 to hold the snapshots folder caapacity status to send only once for each occurance
// Revision 1.84 2008/06/10 15:59:05IST Kanike, Mahadevappa (mk185054) 
// Added new id CameraTSN (CDI store 2162) string store- to hold the current Transaction serial which is papulated by host replied data.
// Revision 1.83 2008/06/09 04:45:43IST Spafford, Michael (ms515892) 
// G393744 - BNA Configurable Retract Destination
// Revision 1.82 2008/06/03 14:27:25BST Chelamalasetty, Praveen (pc185011) 
// Added new IntegerArray for Per Transaction Encash Counts
// Revision 1.81 2008/05/20 19:33:00IST Gavarasana, Hima (hg185004) 
// G363870 - New CDI Array for BNA Sorted Indices
// Revision 1.80 2008/05/13 06:46:46IST ms515892 
// G387832 - Added idNoOfBNARetractBins integer store.
// Revision 1.79 2008/05/03 08:35:07BST sp185027 
// Updated code depending on review comments
// Revision 1.78 2008/04/21 19:42:45IST ms515892 
// G395068 - CDI to keep track of Total CashIn Retract counts
// Revision 1.77 2008/04/16 15:31:52BST ar185054 
// Added idVGEnableOption Persistent integer store 
// Revision 1.76 2008/04/16 17:24:34IST vp185015 
// renamed the created store idTransactionPoint to idBNATransactionPoint.
// Revision 1.75 2008/04/16 16:54:06IST vp185015 
// Created a new CDI store idTransactionPoint
// Revision 1.74 2008/04/05 21:17:53IST ms515892 
// G387832 - New and modified CDIs for BNA Status Handling re-design
// Revision 1.73 2008/03/26 07:28:06GMT sp185027 
// CDI Stores for Option 71
// Revision 1.72 2008/03/25 13:14:18IST ar185054 
// Freeing 2157 CDI store.Initially using for supporting VG but now not required. 
// Revision 1.71 2008/03/03 18:41:46IST vp185015 
// updated the member revision to reflect the latest update of AER.
// Revision 1.70 2008/02/19 12:46:24IST PC185011 
// changed the name of idClosestateCashinResets
// Revision 1.69 2008/02/13 21:19:31IST ak185068 
// Update comments to reflect new numbers
// Revision 1.68 2008/02/13 15:48:11GMT ak185068 
// Update to resolve numbering problems
// Revision 1.67 2008/02/13 14:23:41GMT ak185068 
// REWORK idDeltaDispensed IDs
// Revision 1.66 2008/02/11 07:14:42GMT vp185015 
// Merged branch 1.59.1.1.2.2 into 1.65.
// Revision 1.63 2008/01/25 10:00:25IST sb185074 
// TAR 367378 BNA Supplies status is incorrectly reported
// Revision 1.62 2008/01/24 15:13:42GMT+05:30 hg185004 
// G380088 - Code Review Comment - Renamed the CDI store 2155
// Revision 1.61 2008/01/10 18:29:34IST ar185054 
//  
// Revision 1.60 2008/01/04 18:45:45IST sv185025 
// Added new CDI store for Passport Requirement
// Revision 1.59 2007/12/27 12:59:41IST rk185022 
// GRIT 380669 - Added idTranReplyVoiceData CDI for Voice Guidance
// Revision 1.58 2007/12/06 14:55:31IST hg185004 
// G380088 - Added new CDI stores for bna counts as part of recycling implementation
// Revision 1.57 2007/12/03 18:50:28IST jv512049 
// Reserved new CDIs for ANDC 3.02 Passbook
// Revision 1.56 2007/11/30 12:40:52GMT hg185004 
// G380088 - new CDI's for Recycling
// Revision 1.54 2007/11/01 19:36:12IST rk185022 
// Added CDIs for Voice Guidance
// Revision 1.53 2007/03/20 10:16:44GMT jd515051 
// ANDC320_to_trunk
// Revision 1.51 2007/03/20 10:16:44GMT an185013 
// Updated for option 83 for CPM
// Revision 1.50 2007/02/19 16:20:33IST pd515063 
// MISSING CDIs FROM RECENT 3.1.1 MERGE RE-ADDED
// 
// ONLY CONFLICT WAS CDI 3751. idOption80 MOVED TO 3756 TO RESOLVE
// Revision 1.48 2007/02/14 14:37:00GMT ak185068 
// Added CDI Stores for SilentDebug AANDC Debugging Flag
// Revision 1.47 2007/02/14 14:11:18GMT se185004 
// RFC 329419: New CDI Stores have been added for Universal Printer Development
// Revision 1.45 2007/02/06 11:24:31IST ss185068 
// GR1T 355878 : idOption80(Persistent Integer Store added)
// Revision 1.44 2006/08/29 20:55:37IST jd515051 
// 311toTrunk
// rev 1.33
// Revision 1.33 2006/08/29 16:25:37BST pd515063 
// G346809 - Moved Cash-In CDIs to Trunk
// Revision 1.30.1.4.3.4.3.2 2006/06/29 11:27:27BST ms515892 
// TAR 323730 - Increase CDI array size for BNA counters.
// Revision 1.30.1.4.3.4.3.1 2006/04/24 05:18:27BST ms515892 
// Duplicate revision
// Revision 1.30.1.4.3.3 2006/03/15 23:10:08GMT+05:30 pd515063 
// G323089 - Integration issue corrected
// Revision 1.30.1.4.3.2 2006/03/15 17:24:05GMT pd515063 
// G323089 - Dual Dispenser Implementation
// Revision 1.30.1.4.3.1 2006/01/31 14:11:41GMT pd515063 
// Duplicate revision
// Revision 1.30.1.3 2005/11/22 15:58:07GMT+05:30 bm185019 
// GRIT325118 : Updated after the Code Review
// Revision 1.30.1.2 2005/10/12 20:34:18IST pd515063 
// GRIT RFC 322854 (TAR RFC 300868) - No support in AANDC for coupon attached to receipt in Promote
// Revision 1.30.1.1 2005/10/05 10:02:34BST pd515063 
// Duplicate revision
// Revision 1.30 2005/10/05 10:02:34BST rl400003 
// G 321945 CDI for initial note count was the wrong index
// Revision 1.29 2005/09/23 13:28:12BST jd515051 
// GR1T321945(TAR295400):Merged from  1.25.1.2  to 1.25.
// Revision 1.28 2005/09/29 16:12:43BST pc185011
// G320438 Added a new cdi store for BNA Variant: Store ID is 4064
// Revision 1.27 2005/09/29 20:35:34IST pc185011
// G320438: Added a new CDI Store for BNAVariant.
// Revision 1.26 2005/09/23 17:58:12IST an185013
// GR1T321945(TAR295400):Merged from  1.25.1.2  to 1.25.
// Created CDI stores for each cassette to store  the Initial count of Notes added.
// Revision 1.25.1.1 2005/08/18 18:10:49IST an185013
// Duplicate revision
// Revision 1.24 2005/07/19 14:38:16BST zy515747
// RFC 318015 - Journal Print of Tk2 Data
// Revision 1.23 2005/07/01 09:17:31BST rl400003
// Activity count not working when selective maccing on.
// Revision 1.22 2005/06/14 13:05:34BST rl400003
// G315842 Statement MEI incorrect
// Revision 1.21 2005/05/26 15:51:42BST as515646
// G314463 Clear ATR store
// Revision 1.20 2005/05/13 09:39:12BST as515646
// Remove DASH severity CDI
// Revision 1.19 2005/05/12 16:08:02BST as515646
// New CDI for DASH Severity
// Revision 1.18 2005/04/15 13:24:22BST rd210014
// RFC 311213. added 50 CDI Stores for BNA retract counts
// Revision 1.17 2005/04/14 16:15:48BST ms515892
// RFC 256059 - "m" State for PIN Entry and Language Select
// Revision 1.16 2005/03/16 15:29:10GMT rd400001
// GRIT RFC 302528 Support MV Statement printer
// Revision 1.15 2005/02/28 12:23:28CET zy515747
// GRIT309495 -6- change idDialup to idDialUpEnabled
// Revision 1.14 2005/02/16 11:21:44GMT sp185018
// RFC 246177 - Dial-Up Support - Fixed build issue with IdDialUpMsgOnCPOption
// Revision 1.13 2005/02/14 15:54:19GMT zy515747
// Updated idDecimalPointPosition to 1340
// Revision 1.12 2005/02/10 13:33:37GMT as515646
// G302468 from SP1
// Revision 1.11 2005/02/09 17:24:50GMT sp185018
// RFC 246177 - Dail Up Support - Clarification of Message after CP option CDI store name.
// Revision 1.10 2005/02/04 14:47:24GMT zy515747
// RFC246177 - Dialup
// Revision 1.9 2005/01/31 14:27:28GMT zy515747
// RFC246177 - Dialup
// Revision 1.8  2005/01/26 16:48:27Z  zy515747
// RFC246177 - Dialup
// Revision 1.7  2005/01/10 13:32:06Z  zy515747
// RFC246177  - Dialup
// Revision 1.6  2004/10/29 17:04:26Z  ms515892
// TAR 279273- Print Immediate Transaction Reply message being rejected when sent in OOS mode before to any Transaction, with MACing enabled.
// Revision 1.5  2004/08/26 10:33:33Z  JV512049
// TAR 269692 - new EJOffset CDI persistent integer
// Revision 1.4  2004/03/21 03:33:38Z  pd515063
// Revision 1.3  2004/02/01 12:51:46Z  jdryden
// case values upd
// Revision 1.3  2004/02/01 12:03:11Z  jdryden
// T243463
// case values update
// Revision 1.2  2004/01/15 13:29:58Z  as515646
// Revision 1.1  2003/09/12 14:12:14Z  rl400003
// Initial revision
// Revision 1.25  2003/09/12 14:12:14Z  YB410001
// Revision 1.24  2003/09/12 14:12:14Z  YB410001
// Revision 1.23  2003/08/14 10:01:31Z  zy515747
// RFC225234/5 - modified TCPIP CDI to function as VPI CDI
// Revision 1.22  2003/05/06 15:39:52Z  jdryden
// MV-Trunk
// MV branch moved to main dev path
// Revision 1.21.1.2  2003/05/06 15:39:52Z  rl400003
// grit232790  - 2x R9
// Revision 1.21.1.1  2003/01/07 14:55:10Z  rl400003
// Duplicate revision
// Revision 1.21  2003/01/07 14:55:10Z  rs515668
// RFC 221154
// Revision 1.20  2002/12/23 10:30:12Z  dm410006
// New Transaction Flags
// Revision 1.19  2002/06/26 16:48:35Z  PD515063
// Added new CDIs idTCPIPWindowHandle and idExitStateMessage
// This allows SendStatus method to call from another process
// Revision 1.18  2002/03/18 15:31:44Z  AS515646
// Revision 1.17.1.3  2002/03/18 15:31:44Z  AS515646
// Fixed problem where PIN cdi stores were created as strings instead of integers
// Revision 1.17.1.2  2002/03/12 11:08:20Z  AS515646
// Added two CDI stores for EPP
// Revision 1.17.1.1  2001/02/14 13:12:04Z  AS515646
// Duplicate revision
// Revision 1.17  2001/02/14 13:12:04Z  AS515646
// Revision 1.16  2001/02/14 13:12:03Z  DM410006
// Added CDI Store ID idEMVConfigMAC
// Revision 1.15  2000/10/17 09:21:18Z  poolep
// New CDI Stores for EJ Upload Funcitonlity
// Revision 1.14  2000/06/06 09:01:09Z  stepheng
// Updated branch to Tip
// Revision 1.13.2.5  2000/05/18 12:56:19Z  poolep
// New CDI Persistent String store for BNA MStatus ( idBNAMaintenanceData )
// Revision 1.13.2.4  2000/05/10 13:30:01Z  RR500009
// Declared new CPM stores for idCPMPrintData, idCPMEndorseFlag,
//  idCPMBuffera, idMICRdetected,idCPMConfiguration,
// idCPMChequeDestination, idCPMStampFlag, idCPMPrintOnReverseFlag
// Revision 1.13.2.3  2000/05/01 12:55:27Z  poolep
// Added new BNA Option (idOptionArray45) for including the Transaction Counts in the Transaction Request
// Revision 1.13.2.2  2000/04/26 10:19:15Z  poolep
// New CDI stored for CPMFunctionality
// Revision 1.13  2000/02/02 13:37:54Z  poolep
// Corrected enum comment for idBNAClrTimeDate to avoid future confusion
// Revision 1.12  2000/01/31 13:59:34Z  RR500009
// Added Stores for BNA
// Revision 1.11  2000/01/17 17:18:38  RR500009
// code review changes 18/1/2000
// Revision 1.10  2000/01/10 11:59:56  poolep
// test comment
// Revision 1.9  1999/12/17 15:22:46Z  poolep
// Changed new cdi storenames to be more descriptive Nos 1261, 3214-3217
// Revision 1.8  1999/12/17 15:22:46Z  RR500009
// Variables added for Bunch Note Acceptor
// Revision 1.7  1999/12/02 13:00:46  poolep
// Aptra Advance NDC Release 1.0
// New CDI stored for BNA and CPM Device
// Revision 1.6  1998/11/25 11:01:09Z  stepheng
// GRIT R1.01 S08-65 Screen Update Data
// Revision 1.5  1998/08/26 15:55:14  tomsma
// Added idTrBackupPrinterFlag
// Revision 1.4  1998/07/21 19:36:48  stepheng
// S08-226 Added FreshStart CDI to indicate that a cold start has occurred and
//        Default and Access Values should be loaded from disk
// Revision 1.3  1998/06/04 10:04:04  stepheng
// Added idConfigurationData saved to determine if a valid download has been saved.
// Revision 1.2  1998/03/23 11:14:29  stepheng
// Updated new Default and Access CDI functionality to provide
// Cacheable Persistent Stores, store value is not written to
// NVRAM until an explicit store is done.
// Revision 1.1  1998/01/29 18:28:41  stepheng
// Initial Revision
//
// +------------------------------------------------------------------------------+
//
//   Update Log
//   Date     ID                           Description
//   19/08/96 idStatusValAndQualifier      String store holding the status value and qualifier
//                                         should be set by the Decomposer.
//   19/08/96 idStatusValue                Do not use, the above superceeds it.
//   19/08/96 idFreshStartFlag             Reset the persistent data values at start when set.
//   16/09/96 idStatusValAndQualifier      Renamed to idRejectStatus
//   16/09/96 idCDIErrorNumber             Added for Transoft
//            idErrorParam1..9             ditto
//            idErrorMessage               ditto
//
//   22/04/97 idDepositPrintData           Used as buffer for Terminal to Central print messages
//
//   26/05/97 idSupervisorAutoReturn       Used to specify automatic return from supervisor as an option.
//   29/05/97 idCustomLayerStatus          Used to hold the state of the the Customisation Layer WAITING, IDLE, PROCESSING, TRANSACTION
//   24/06/97 idTransCountHi               Changed name from idTransCountHigh (RFC 5460)
//   25/06/97 idCurrentModeNVRAM           Renamed idCurrentMode to idCurrentModeNVRAM and added non persistant version of idCurrentMode
//            idReturnModeNVRAM            people should be using non-persitent version to assign mode change and determine mode.
//
//                                         Added for virtual controller stuff.
//   03/07/97 idVirtualMessage             Used to store message reply created by the virtual controller.
//            idTerminalStaus              Used to store field status fields of terminal status message prior to assembly of message.
//            idDeviceFaultStatus          Used to store status fields of device fault message prior to assembly of message
//            idTransactionRequestFields   Written by transaction request builder.
//
//   13/11/97 idBaseFit                    All Used for FIT Information.
//            idEncryptedPEKEY
//            idDecimalisationTable
//
//   08/12/97 idInitSupPassword            Initial Suppervisor Password
//   11/12/97 idInitSupPassword            Removed Initial Suppervisor Password - correct CDI already there idSupPassword
//   12/01/98 idPINEntryStatus             Added to communicate status of PIN Entry initiation from State Type T
//            idPINEntryInitated           Added to determine if PIN has already been entered by the Card Read PIN Entry Initiation State

//   19/03/98 idSetDefault                 Added to facilitate the storing of default and access values to disk.
//            idSetAccess
//
//   21/03/98 idStatementCancelled         Used by the Transaction Handler to coordinate output with the Status Handler
//            idSidewaysReceiptCancelled
//            idSidewaysReceiptPrinted
//
//   23/03/98 idTableExitId                RFC 5601 Used by NDC Exits to determine table entry that gave exit state
//
//   25/11/98 idScreenDispUpdate           GRIT R1.01 S08-65 Screen Update Data
//


#ifndef NDC_DATA_E_H
#define NDC_DATA_E_H

const int NOTE_COUNTERS_OFFSET_CDM1 = 3401;
const int NOTE_COUNTERS_OFFSET_CDM2 = 3431;
const int OFFSET_DISPENSED =  0;
const int OFFSET_NOTES_IN  = 10;
const int OFFSET_PURGED    = 20;

const int STD_NOTE_COUNTERS_OFFSET_CDM1 = 3461;
const int STD_NOTE_COUNTERS_OFFSET_CDM2 = 3471;


enum eVars { idLastVar = -1,

/******************** INTEGERS ***********************/

   idCardJammed                 =  1000,  // INTEGERS
   idCardRet,                   // 1001
   idCAVStarted,                // 1002
   idCIMVerifyCode,             // 1003
   idCurrStateNumber,           // 1004
   idCurrStateType,             // 1005
   idDecimalChar,               // 1006
   idDocPres,                   // 1007
   idDocumentDestination,       // 1008
   idDPMErrPos,                 // 1009
   idDPMSup,                    // 1010
   idDPMTrans,                  // 1011
   idEnvDispensed,              // 1012
   idEnvPresented,              // 1013
   idEnvSup,                    // 1014
   idFDKKeycodeBuffer,          // 1015
   idFitMatch,                  // 1016
   idJnlPrinted,                // 1017
   idJnlSup,                    // 1018
   idLanguageOffset,            // 1019
   idMsgMode,                   // 1020
   idNextStateNumber,           // 1021
   idOptionArray0,              // 1022
   idOptionArray1,              // 1023
   idOptionArray2,              // 1024
   idOptionArray3,              // 1025
   idOptionArray4,              // 1026
   idOptionArray5,              // 1027
   idOptionArray6,              // 1028
   idOptionArray7,              // 1029
   idOptionArray8,              // 1030
   idOptionArray9,              // 1031
   idOptionArray10,             // 1032
   idOptionArray11,             // 1033
   idOptionArray12,             // 1034
   idOptionArray13,             // 1035
   idOptionArray14,             // 1036
   idOptionArray15,             // 1037
   idPAGDX,                     // 1038
   idPANDX,                     // 1039
   idPANLN,                     // 1040
   idPANLN_LocalCheck,          // 1041
   idPANLN_NumDigits,           // 1042
   idPANPD,                     // 1043
   idPANPD_PANPad,              // 1044
   idPANPD_PINVerKey,           // 1045
   idPCKLN,                     // 1046
   idPCKLN_NumDigits,           // 1047
   idPCKLN_VerMethod,           // 1048
   idPDCTB0,                    // 1049
   idPDCTB1,                    // 1050
   idPDCTB2,                    // 1051
   idPDCTB3,                    // 1052
   idPDCTB4,                    // 1053
   idPDCTB5,                    // 1054
   idPDCTB6,                    // 1055
   idPDCTB7,                    // 1056
   idEnvelopeDispenserStatus,   // 1057
   idCardCaptureBinStatus,      // 1058
   idReceiptPaperStatus,        // 1059
   idReceiptRibbonStatus,       // 1060
   idReceiptPrintheadStatus,    // 1061
   idReceiptKnifeStatus,        // 1062
   idDepositoryBinStatus,       // 1063

   idBaseFit,                   // 1064

   idPEKEY0,                    // 1065
   idPEKEY1,                    // 1066
   idPEKEY2,                    // 1067
   idPEKEY3,                    // 1068
   idPEKEY4,                    // 1069
   idPEKEY5,                    // 1070
   idPEKEY6,                    // 1071
   idPEKEY7,                    // 1072

   idJournalPaperStatus,        // 1073
   idJournalRibbonStatus,       // 1074
   idJournalPrintheadStatus,    // 1075
   idJournalKnifeStatus,        // 1076
   idStatementPaperStatus,      // 1077
   idStatementRibbonStatus,     // 1078
   idStatementPrintheadStatus,  // 1079
   idStatementKnifeStatus,      // 1080
   idPFIID0,                    // 1081
   idPFIID1,                    // 1082
   idPFIID2,                    // 1083
   idPFIID3,                    // 1084
   idPFIID4,                    // 1085
   idStatementCaptureBinStatus, // 1086
   idFITMatchIndex,             // 1087

   idSetDefault,                // 1088
   idSetAccess,                 // 1089

   idTableExitId,               // 1090

   idPIDDX,                     // 1091
   idPIDDX_Location,            // 1092
   idPIDDX_ModIndex,            // 1093
   idPinAtt1,                   // 1094
   idPinAtt2,                   // 1095
   idPINDX0,                    // 1096
   idPINDX1,                    // 1097
   idPINDX2,                    // 1098

   idStatementCancelled,        // 1099 SG 21/03/98
   idSidewaysReceiptCancelled,  // 1100
   idSidewaysReceiptPrinted,    // 1101

   idPINPD,                     // 1102
   idPINPD_EncryptType,         // 1103
   idPINPD_PadChar,             // 1104
   idPLNDX,                     // 1105
   idPMMSR,                     // 1106
   idPMXPN,                     // 1107
   idPMXPN_BlockType,           // 1108
   idPMXPN_MaxDigits,           // 1109
   idPOFDX,                     // 1110
   idPRCNT,                     // 1111
   idPRCNT_RetryCountLocation,  // 1112
   idPRCNT_RetryType,           // 1113
   idPREF2,                     // 1114
   idPrimExStateData0,          // 1115
   idPrimExStateData1,          // 1116
   idPrimExStateData2,          // 1117
   idPrimExStateData3,          // 1118
   idPrimExStateData4,          // 1119
   idPrimExStateData5,          // 1120
   idPrimExStateData6,          // 1121
   idPrimExStateData7,          // 1122
   idPSTDX,                     // 1123
   idPSTDX_Branch,              // 1124
   idPSTDX_Logo,                // 1125
   idPVBDX,                     // 1126
   idPVBLN,                     // 1127
   idRcptPrinted,               // 1128
   idReadZo0Sta,                // 1129
   idReadZo1Sta,                // 1130
   idReadZo2Sta,                // 1131
   idReadZo3Sta,                // 1132
   idReadZo4Sta,                // 1133
   idReadZo5Sta,                // 1134
   idReadZo6Sta,                // 1135
   idReadZo7Sta,                // 1136
   idReadZo8Sta,                // 1137
   idReadZo9Sta,                // 1138
   idReceiptTop,                // 1139
   idRecSup,                    // 1140
   idScreenNumber,              // 1141
   idSecExStateData0,           // 1142
   idSecExStateData1,           // 1143
   idSecExStateData2,           // 1144
   idSecExStateData3,           // 1145
   idSecExStateData4,           // 1146
   idSecExStateData5,           // 1147
   idSecExStateData6,           // 1148
   idSecExStateData7,           // 1149
   idSOHDispActive,             // 1150
   idSOHInSup,                  // 1151
   idSOHOutSup,                 // 1152
   idStateData0,                // 1153
   idStateData1,                // 1154
   idStateData2,                // 1155
   idStateData3,                // 1156
   idStateData4,                // 1157
   idStateData5,                // 1158
   idStateData6,                // 1159
   idStateData7,                // 1160
   idStmtPrinted,               // 1161
   idStmtSup,                   // 1162
   idSupKeys,                   // 1163
   idT1Update,                  // 1164
   idT2Update,                  // 1165
   idT3Update,                  // 1166
   idTerExStateData0,           // 1167
   idTerExStateData1,           // 1168
   idTerExStateData2,           // 1169
   idTerExStateData3,           // 1170
   idTerExStateData4,           // 1171
   idTerExStateData5,           // 1172
   idTerExStateData6,           // 1173
   idTerExStateData7,           // 1174
   idTRFunctionID,              // 1175
   idFourExStateData0,          // 1176
   idFourExStateData1,          // 1177
   idFourExStateData2,          // 1178
   idFourExStateData3,          // 1179
   idFourExStateData4,          // 1180
   idFourExStateData5,          // 1181
   idFourExStateData6,          // 1182
   idFourExStateData7,          // 1183
   idFiveExStateData0,          // 1184
   idFiveExStateData1,          // 1185
   idFiveExStateData2,          // 1186
   idFiveExStateData3,          // 1187
   idFiveExStateData4,          // 1188
   idFiveExStateData5,          // 1189
   idFiveExStateData6,          // 1190
   idFiveExStateData7,          // 1191
   idSixExStateData0,           // 1192
   idSixExStateData1,           // 1193
   idSixExStateData2,           // 1194
   idSixExStateData3,           // 1195
   idSixExStateData4,           // 1196
   idSixExStateData5,           // 1197
   idSixExStateData6,           // 1198
   idSixExStateData7,           // 1199
   idSevenExStateData0,         // 1200
   idSevenExStateData1,         // 1201
   idSevenExStateData2,         // 1202
   idSevenExStateData3,         // 1203
   idSevenExStateData4,         // 1204
   idSevenExStateData5,         // 1205
   idSevenExStateData6,         // 1206
   idSevenExStateData7,         // 1207
   idEightExStateData0,         // 1208
   idEightExStateData1,         // 1209
   idEightExStateData2,         // 1210
   idEightExStateData3,         // 1211
   idEightExStateData4,         // 1212
   idEightExStateData5,         // 1213
   idEightExStateData6,         // 1214
   idEightExStateData7,         // 1215
   idCDIErrorNumber,            // 1216
   idStmtTop,                   // 1217
   idCurOrient,                 // 1218
   idBufBPoint,                 // 1219
   idBufCPoint,                 // 1220
   idAmtPoint,                  // 1221
   idCandNums,                  // 1222
   idCan1Used,                  // 1223
   idCand0Or,                   // 1224
   idCand1Or,                   // 1225
   idCand2Or,                   // 1226
   idCand0En,                   // 1227
   idCand1En,                   // 1228
   idCand2En,                   // 1229
   idDPMArch0,                  // 1230
   idDPMArch1,                  // 1231
   idDPMArch2,                  // 1232
   idDPMArch3,                  // 1233
   idDPMArch4,                  // 1234
   idDPMArch5,                  // 1235
   idDPMArch6,                  // 1236
   idDPMArch7,                  // 1237
   idDPMArch8,                  // 1238
   idDPMArch9,                  // 1239
   idDPMArch10,                 // 1240
   idDPMArch11,                 // 1241
   idDPMArch12,                 // 1242
   idDPMArch13,                 // 1243
   idDPMArch14,                 // 1244
   idDPMArch15,                 // 1245
   idDPMArch16,                 // 1246
   idFreeJDataEnable,           // 1247
   idScreenOffset,              // 1248
   idScreenGroupSize,           // 1249
   idCurrentMode,               // 1250
   idReturnMode,                // 1251
   idPANDCSOpt,                 // 1252
   idAudEchoOpt,                // 1253
   idDASRepOpt,                 // 1254
   idNotesToDispType1,          // 1255
   idNotesToDispType2,          // 1256
   idNotesToDispType3,          // 1257
   idNotesToDispType4,          // 1258
   idPINEntryStatus,            // 1259
   idPINEntryInitated,          // 1260
   idBNASuppliesStatus,			// 1261    //GRIT 326798 RFC 314428. this CDI store is no longer used for BNA. Created another cdi store 2151
   idCPMPocket1Status,			// 1262
   idCPMPocket2Status,			// 1263
   idCPMPocket3Status,			// 1264
   idCPMPocketCount,			// 1265
   idBankNote1Active,			// 1266
   idBankNote2Active,			// 1267
   idBankNote3Active,			// 1268
   idBankNote4Active,			// 1269
   idBankNote5Active,			// 1270
   idBankNote6Active,			// 1271
   idBankNote7Active,			// 1272
   idBankNote8Active,			// 1273
   idBankNote9Active,			// 1274
   idBankNote10Active,			// 1275
   idBankNote11Active,			// 1276
   idBankNote12Active,			// 1277
   idBankNote13Active,			// 1278
   idBankNote14Active,			// 1279
   idBankNote15Active,			// 1280
   idBankNote16Active,			// 1281
   idBankNote17Active,			// 1282
   idBankNote18Active,			// 1283
   idBankNote19Active,			// 1284
   idBankNote20Active,			// 1285
   idBankNote21Active,			// 1286
   idBankNote22Active,			// 1287
   idBankNote23Active,			// 1288
   idBankNote24Active,			// 1289
   idBankNote25Active,			// 1290
   idBankNote26Active,			// 1291
   idBankNote27Active,			// 1292
   idBankNote28Active,			// 1293
   idBankNote29Active,			// 1294
   idBankNote30Active,			// 1295
   idBankNote31Active,			// 1296
   idBankNote32Active,			// 1297
   idBankNote33Active,			// 1298
   idBankNote34Active,			// 1299
   idBankNote35Active,			// 1300
   idBankNote36Active,			// 1301
   idBankNote37Active,			// 1302
   idBankNote38Active,			// 1303
   idBankNote39Active,			// 1304
   idBankNote40Active,			// 1305
   idBankNote41Active,			// 1306
   idBankNote42Active,			// 1307
   idBankNote43Active,			// 1308
   idBankNote44Active,			// 1309
   idBankNote45Active,			// 1310
   idBankNote46Active,			// 1311
   idBankNote47Active,			// 1312
   idBankNote48Active,			// 1313
   idBankNote49Active,			// 1314
   idBankNote50Active,			// 1315
   idProgrammedCurrencyCount,	// 1316
   idSolStatusMsgSent,			// 1317
   idOptionArray45,				// 1318
   idMICRdetected,				// 1319
   idCPMConfiguration,			// 1320
   idCPMStampFlag,				// 1321
   idCPMPrintOnReverseFlag,		// 1322

   // Open Customisation Layer 5/6/2000
   idTRUserFunctionID,          // 1323
   idExecuteAndWait,            // 1324
   idPBFMT,	          			// 1325
   idPBFMT_BlockType,           // 1326
   idVPIUpdate,					// 1327

   // grit232790
   idTransBeingProcessed =1328,	// was 4049 TAR214120 DM 20/12/02
   idReadySentInTranFunc =1329,	// was 4050 TAR214120 DM 20/12/02
   idReceiptCount = 1330,		// 1330
   idReceiptLFFF  = 1331,		// 1331

   idInvalidStateFlag,			// 1332 TAR 243463
   idInvalidStateNumber,		// 1333 TAR 243463
   idTRMsgClassNo,				// 1334 TAR 279273 - Declare CDI store to store Transaction Reply Message Class Number.

   // RFC 246177 Block below added for Dial Up support
   idDialUpEnabled,				// 1335 Whether dialup protocol present or not - Set at Start of Day - // GRIT309495 - 6
   idDialUpLastMsgRequest,      // 1336 Flag used in outging dial-up header construction
   idDialUpDisconnectReceived,  // 1337 Flag set when a disconnect command has been received from the host
   idDialUpTreplyReceived,      // 1338 Flag used in outging dial-up header construction
   idDialUpHostMsgPending,      // 1339 Flag set when host header indicates more host msgs required to be sent.
   idDecimalPointPosition,		// 1340 TAR 283458 Neil G

   idStatementTop,				// 1341 GRIT 302528 MV_STATEMENT
   idStatementFF,				// 1342 GRIT 302528 MV_STATEMENT
   idNoPINNextStateFlag,		// 1343 RFC 256059 - Enter PIN & Language Select, "m" State

   // MV Statement Grit 315842
   idStatementLineCount,		// 1344
   idTSNFlag,                   // 1345 RUSSIA UPDATE 1/7/04

   idCouponPrint,				// 1346 TAR 300868 (GRIT 322854)
   idCouponDoCutType,			// 1347 TAR 300868 (GRIT 322854)
   idNightSafeCancel,			// 1348 TAR 312832 (GRIT 325118) 

   idCountersEntryType,			// 1349 GRIT 323089 for Dual Dispense
   idNumberOfHopperTypes,       // 1350 for Number of Coin Dispenser Hopper Types
   idNumberOfCassetteTypes,     // 1351 GRIT 352996 for Dual Dispense
   idLockCurrentScreen,     	// 1352 GRIT 380669 for Voice Guidance
   idVGSession,     		// 1353 GRIT 380669 for Voice Guidance
   idPassbookRibbonStatus = 1354,  // 1354
   idPassbookPrintheadStatus,        // 1355
   idPassbookCaptureBinStatus,      // 1356

   idCashInResets,				//1357 GR1T 383906
   idNumberOfEntryTimeOuts,		//1358 GR1T 392665
   idNoOfBNARetractBins,		//1359 GR1T 387832 - Number of Retract Bins available to BNA
   idCamCapacityStatus = 1361,//1361 GR1T 380673 - Snapshots folder Capacity status 

   idReceiptBackLineCount,	//1362	GR1T 392679
   idStatementBackLineCount,	//1363	GR1T 392679
   idPreviousMode = 1364,     // 1364,         RFC  390161 - Mode Change Hook
   idBNA24VResetRequired = 1365,	//1365,	No longer used
   idJournalLineCount = 1366,
   idReceiptCaptureBinStatus, //1367, Grit 465785 - unsolicited message update for receipt capture bin
   idCashInDeviceVariant, //1368 GR1T 463488 - Support for Cash In CDIs
   
   idPromoteEnabled,      //1369 RFC 474301 -Integrate .NET Promote and Relate components
   idRelateEnabled,       //1370
   idCashInRetractOperations, //1371 Number Of Cash In Retract Operations
   idDeviceRecoveredDuringAER,	//1372 AANDC-16947-Send Simulated Supervisor entry and exit to host after AER failure/success based on the SuppressSupervisorAERMessages registry
   idCashInNotesPresent, //1373 RFC 538853 - Add a new CDI for CashIn to report if Notes are in the device.
   idCRMCampaignActive,            //1374 GR1T 546873 Flag which will be set/reset when promote is in running/not running
   idHostTimeout,	//1375 RFC 579915
   idCameraFlowPoint,	//1376 RFC 575628
   idCashInDepositNoteNumberLimit, // 1377 AANDC-9462: Holds the Deposit note number limit data received in buffer d field of transaction reply message with bd3 (identifier) set to 002
   idCAMBuffer,	//1378 AANDC-12439: Indicates the transaction is a contact or contactless and also indicates the mode of transaction is EMV or MSD if the transaction is Contactless Transaction 
   idClearingRecycler, //1379 AANDC-11934: Runtime CDI to define whether INIT BNA is called from Test Cash or Test Cash is called from INIT BNA.

/******************** STRINGS ***********************/

   idAmtBuffer                  =  2000,   // STRINGS
   idAmtRead,                   // 2001
   idBufferA,                   // 2002
   idBufferB,                   // 2003
   idBufferC,                   // 2004
   idCAVAmtEntryBuff,           // 2005
   idCAVDifferenceSign,         // 2006
   idCAVDiffMagnitude,          // 2007
   idCAVResult,                 // 2008
   idCIMVerBuff,                // 2009
   idCurClasName,               // 2010
   idCurDocName,                // 2011
   idCurEnable,                 // 2012
   idDPMFlux,                   // 2013
   idOpBuffer,                  // 2014
   idPin1stBuf,                 // 2015
   idPin2ndBuf,                 // 2016
   idPrinterDataBlock1,         // 2017
   idPrinterDataBlock2,         // 2018
   idPrinterDataBlock3,         // 2019
   idPrinterDataBlock4,         // 2020
   idPrinterDataBlock5,         // 2021
   idPrinterDataBlock6,         // 2022
   idPrinterDataBlock7,         // 2023
   idPrinterDataBlock8,         // 2024
   idPrinterDataBlock9,         // 2025
   idPrinterDataBlock10,        // 2026
   idPrinterDataBlock11,        // 2027
   idPrinterDataBlock12,        // 2028
   idPrinterDataBlock13,        // 2029
   idPrinterFlag,               // 2030
   idProductId,                 // 2031
   idRdZo0Data,                 // 2032
   idRdZo1Data,                 // 2033
   idRdZo2Data,                 // 2034
   idRdZo3Data,                 // 2035
   idRdZo4Data,                 // 2036
   idRdZo5Data,                 // 2037
   idRdZo6Data,                 // 2038
   idRdZo7Data,                 // 2039
   idRdZo8Data,                 // 2040
   idRdZo9Data,                 // 2041
   idT1Data,                    // 2042
   idT2Data,                    // 2043
   idT3Data,                    // 2044
   idTimeVariantNo,             // 2045
   idTrack1AccNo,               // 2046
   idTrack1CountryCode,         // 2047
   idTrack1Forename,            // 2048
   idTrack1Format,              // 2049
   idTrack1OptionalData,        // 2050
   idTrack1Surname,             // 2051
   idTrack1Title,               // 2052
   idZoneVerRes,                // 2053
   idRejectStatus,              // 2054
   idCDIErrorMessage,           // 2055
   idCAVAuxStatus,              // 2056
   idTransactionSerialNo,       // 2057
   idCand0Clas,                 // 2058
   idCand1Clas,                 // 2059
   idCand2Clas,                 // 2060
   idCand0Doc,                  // 2061
   idCand1Doc,                  // 2062
   idCand2Doc,                  // 2063
   idCDIErrorParam1,            // 2064
   idCDIErrorParam2,            // 2065
   idCDIErrorParam3,            // 2066
   idCDIErrorParam4,            // 2067
   idCDIErrorParam5,            // 2068
   idCDIErrorParam6,            // 2069
   idCDIErrorParam7,            // 2070
   idCDIErrorParam8,            // 2071
   idCDIErrorParam9,            // 2072
   idLanguageCode,              // 2073
   idFinancialInstituteID,      // 2074
   idBankID,                    // 2075
   idPINRetryCount,             // 2076
   idPAN,                       // 2077
   idDepositPrintData,          // 2078
   idCustomLayerStatus,         // 2079
   idOptionStr,                 // 2080   - Added by GT to allow access to the option digits
                                //     using a pseudo string store.
   idVirtualMessage,            // 2081
   idTerminalStatus,            // 2082
   idDeviceFaultStatus,         // 2083
   idTransactionRequestFields,  // 2084
   idPINOffsetData,             // 2085
   idEncryptedPEKEY,            // 2086
   idDecimalisationTable,       // 2087
   idBackupPrinterFlag,			// 2088
   idScreenDispUpdate,			// 2089 GRIT R1.01 S08-65 Screen Update Data
   idDenomConfigType1,			// 2090
   idDenomConfigType2,			// 2091
   idDenomConfigType3,			// 2092
   idDenomConfigType4,			// 2093
   idDenomConfigType5,			// 2094
   idDenomConfigType6,			// 2095
   idDenomConfigType7,			// 2096
   idDenomConfigType8,			// 2097
   idDenomConfigType9,			// 2098
   idDenomConfigType10,			// 2099
   idDenomConfigType11,			// 2100
   idDenomConfigType12,			// 2101
   idDenomConfigType13,			// 2102
   idDenomConfigType14,			// 2103
   idDenomConfigType15,			// 2104
   idDenomConfigType16,			// 2105
   idDenomConfigType17,			// 2106
   idDenomConfigType18,			// 2107
   idDenomConfigType19,			// 2108
   idDenomConfigType20,			// 2109
   idDenomConfigType21,			// 2110
   idDenomConfigType22,			// 2111
   idDenomConfigType23,			// 2112
   idDenomConfigType24,			// 2113
   idDenomConfigType25,			// 2114
   idDenomConfigType26,			// 2115
   idDenomConfigType27,			// 2116
   idDenomConfigType28,			// 2117
   idDenomConfigType29,			// 2118
   idDenomConfigType30,			// 2119
   idDenomConfigType31,			// 2120
   idDenomConfigType32,			// 2121
   idDenomConfigType33,			// 2122
   idDenomConfigType34,			// 2123
   idDenomConfigType35,			// 2124
   idDenomConfigType36,			// 2125
   idDenomConfigType37,			// 2126
   idDenomConfigType38,			// 2127
   idDenomConfigType39,			// 2128
   idDenomConfigType40,			// 2129
   idDenomConfigType41,			// 2130
   idDenomConfigType42,			// 2131
   idDenomConfigType43,			// 2132
   idDenomConfigType44,			// 2133
   idDenomConfigType45,			// 2134
   idDenomConfigType46,			// 2135
   idDenomConfigType47,			// 2136
   idDenomConfigType48,			// 2137
   idDenomConfigType49,			// 2138
   idDenomConfigType50,			// 2139
   idCPMBuffera,                // 2140
   idCPMChequeDestination,      // 2141
   idCPMPrintData,              // 2142
   idExitStatusMessage,			// 2143
   idIndexCardWriteDevStatus,	// 2144   //AG HCL 15/12/03 TAR252902 To Send UnSol Msg When Card Write Fails
   idIndexCardWriteSev,			// 2145
   idIndexCardWriteString,		// 2146
   idIndexCardWriteSupp,		// 2147
   // RFC 246177 Two entries below added for Dial Up support
   idDialUpBin,             // 2148 Used in outgoing Dialup header
   idDialUpTerminalId,      // 2149 Used in outgoing Dialup header
   idATRData,               // 2150 GRIT314463
   idBNASuppliesData,		//2151 No longer used.
   idBarcodeBuffer,		// 2152 GRIT 330519
   idBarcodeFormat,			// 2153 GRIT 330519
   idBufferS,                           // 2154 Used to hold BufferS string
   idDepositDataForDispenseTransReadyB,	//2155 to hold the Deposit info to be reported in ReadyB
   idTranReplyVoiceData,            //2156 GRIT 380669 for Voice Guidance
   idBNACurrentSupplies = 2158,		// 2158 G387832 - Holds all current supplies data
   idBNACurrentFitness,				// 2159 G387832 - Holds all current fitness data
   idBNACassettesUsed,				// 2160 G387832 - Cassettes used in most recent BNA operation
   idBNALogToPhysCassMapping,		// 2161 G387832 - Contains deposit cassettes Logical type to Physical Position mapping info
   idCameraTSN,                     // 2162  G380673 - Holds the Transaction Serial Number data
   idBunchChequeTReplyBufferB,		// 2163 G397941 (SCPM) - Holds the buffer b data in transaction reply and does not include the buffer id character 'b'
   idBunchChequeTRequestChequeIDs,		// 2164 G397941 (SCPM) - Holds the cheque IDs included in transaction request. This store is used to validate buffer b of transaction reply
   idExcludedDevices,		//2165	RFC 419928 - 24Volt Reset - Contaisns the excluded device list
   idBNACassSensors,		//2166 RFC 362852 - TI Messaging support for GBxx
   idCustomFaults,			//2167 RFC 579672 - Display faults originating from a customisation on the ANDC Fault Display 
   idCashInDepositAmountLimit, // 2168 AANDC-9462: Holds the Deposit Amount Limit data received in buffer d field of transaction reply message with bd3 (identifier) set to 001
   idContactlessEMVData, //2169 AANDC-12439 - Holds the EMV data of the Contactless Card

/******************** PERSISTENT INTEGERS ***********************/

   idLastEnvSerialNo            =  3000,   // PERSISTENT INTEGERS
   idSupPassword,               // 3001
   idInitSupvMenu,              // 3002
   idInitSupvDisplay,           // 3003
   idPassInUse,                 // 3004
   idAutoExit,                  // 3005
   idAmountBuffLen,             // 3006
   idArchiveLiftedImageList,    // 3007
   idArchiveLiftedImages,       // 3008
   idAutoVoiceOption,           // 3009
   idBackCoinDisp1,             // 3010
   idBackCoinDisp2,             // 3011
   idBackCoinDisp3,             // 3012
   idBackCoinDisp4,             // 3013
   idBackDisp1,                 // 3014
   idBackDisp2,                 // 3015
   idBackDisp3,                 // 3016
   idBackDisp4,                 // 3017
   idBackNotes1,                // 3018
   idBackNotes2,                // 3019
   idBackNotes3,                // 3020
   idBackNotes4,                // 3021
   idBackPurge1,                // 3022
   idBackPurge2,                // 3023
   idBackPurge3,                // 3024
   idBackPurge4,                // 3025
   idBackCoinRem1,              // 3026
   idBackCoinRem2,              // 3027
   idBackCoinRem3,              // 3028
   idBackCoinRem4,              // 3029
   idBeepAtCardEject,           // 3030
   idBeepAtPresent,             // 3031
   idBeepInDeposit,             // 3032
   idCamCount,                  // 3033
   idCameraNAKReported,         // 3034
   idCamOption,                 // 3035
   idCancelClearPosn,           // 3036
   idCancelOnStmtWait,          // 3037
   idCardCapCount,              // 3038
   idCardCaptPrinted,           // 3039
   idCardThreshOpt,             // 3040
   idCheckMagnetism,            // 3041
   idCheckNSDOverfill,          // 3042
   idCheckZoneVerification,     // 3043
   idCoinDisp1,                 // 3044
   idCoinDisp2,                 // 3045
   idCoinDisp3,                 // 3046
   idCoinDisp4,                 // 3047
   idCoinRem1,                  // 3048
   idCoinRem2,                  // 3049
   idCoinRem3,                  // 3050
   idCoinRem4,                  // 3051
   idCommsKeyLoaded,            // 3052
   idCommsStatusPrinted,        // 3053
   idCoordNo,                   // 3054
   idCurrentModeNVRAM,          // 3055
   idDateOption,                // 3056
   idDefaultPrinter,            // 3057
   idDispenseStatusSent,        // 3058
   idDocEntryRetries,           // 3059
   idDownloadSave,              // 3060
   idDPMACount,                 // 3061
   idDPMBCount,                 // 3062
   idDPMCCount,                 // 3063
   idDPMDump,                   // 3064
   idDPMRejCount,               // 3065
   idEJHrsOpt,                  // 3066
   idEJRecOpt,                  // 3067
   idEJTamperOpt,               // 3068
   idEnvDepCount,               // 3069
   idEnvRepOpt,                 // 3070
   idExtendedOption,            // 3071
   idFastClearSOH,              // 3072
   idJournalMode,               // 3073
   idLastCoinDisp1,             // 3074
   idLastCoinDisp2,             // 3075
   idLastCoinDisp3,             // 3076
   idLastCoinDisp4,             // 3077
   idLastMesStatus,             // 3078
   idLastNotesDispType1,        // 3079
   idLastNotesDispType2,        // 3080
   idLastNotesDispType3,        // 3081
   idLastNotesDispType4,        // 3082
   idLeftRightFDKs,             // 3083
   idLiftImages,                // 3084
   idLiftImagesinList,          // 3085
   idMACKeyLoaded,              // 3086
   idMarginOpt,                 // 3087
   idMaxReceiptLines,           // 3088
   idMEIControlOpt,             // 3089
   idMMOption,                  // 3090
   idNotesDispType1,            // 3091
   idNotesDispType2,            // 3092
   idNotesDispType3,            // 3093
   idNotesDispType4,            // 3094
   idNotesInType1,              // 3095
   idNotesInType2,              // 3096
   idNotesInType3,              // 3097
   idNotesInType4,              // 3098
   idNotesPurgedType1,          // 3099
   idNotesPurgedType2,          // 3100
   idNotesPurgedType3,          // 3101
   idNotesPurgedType4,          // 3102
   idPowerFailRec,              // 3103
   idProductClass,              // 3104
   idReadyBOpt,                 // 3105
   idRemRelayOpt,               // 3106
   idReportCandidates,          // 3107
   idRestartMode,               // 3108
   idRetractUntakenNotes,       // 3109
   idReturnModeNVRAM,           // 3110
   idSW_IDOpt,                  // 3111
   idSCROption,                 // 3112
   idSMStatusOpt,               // 3113
   idStdCoin1,                  // 3114
   idStdCoin2,                  // 3115
   idStdCoin3,                  // 3116
   idStdCoin4,                  // 3117
   idStdNotes1,                 // 3118
   idStdNotes2,                 // 3119
   idStdNotes3,                 // 3120
   idStdNotes4,                 // 3121
   idSupvKeyReporting,          // 3122
   idSupvPswdRety,              // 3123
   idT1FormatOpt,               // 3124
   idT3WriteThreshOpt,          // 3125
   idTimer0,                    // 3126
   idTimer1,                    // 3127
   idTimer2,                    // 3128
   idTimer3,                    // 3129
   idTimer4,                    // 3130
   idTimer5,                    // 3131
   idTimer6,                    // 3132
   idTimer7,                    // 3133
   idTimer8,                    // 3134
   idTimer9,                    // 3135
   idTimer10,                   // 3136
   idTimer82,                   // 3137
   idTimer83,                   // 3138
   idTimer86,                   // 3139
   idTimer87,                   // 3140
   idTimer91,                   // 3141
   idTimer92,                   // 3142
   idTimer93,                   // 3143
   idTimer94,                   // 3144
   idTimer95,                   // 3145
   idTimer96,                   // 3146
   idTimer97,                   // 3147
   idTIOption,                  // 3148
   idTISensOpt,                 // 3149
   idTouchRepOpt,               // 3150
   idTraceOn,                   // 3151
   idTransInfOpt,               // 3152
   idWidthOption,               // 3153
   idNDCTraceNumber,            // 3154
   idStmtCapCount,              // 3155
   idTransCountLo,              // 3156
   idTransCountHi,              // 3157
   idSupervisorAutoReturn,      // 3158
   idEJLogSequenceNumber,       // 3159
   idConfigurationSaved,        // 3160
   idFreshStart,                // 3161
   idTimer77,					// 3162
   idTimer78,					// 3163
   idDeposCountDenom1 = 3164,	// 3164
   idDeposCountDenom2,			// 3165
   idDeposCountDenom3,			// 3166
   idDeposCountDenom4,			// 3167
   idDeposCountDenom5,			// 3168
   idDeposCountDenom6,			// 3169
   idDeposCountDenom7,			// 3170
   idDeposCountDenom8,			// 3171
   idDeposCountDenom9,			// 3172
   idDeposCountDenom10,			// 3173
   idDeposCountDenom11,			// 3174
   idDeposCountDenom12,			// 3175
   idDeposCountDenom13,			// 3176
   idDeposCountDenom14,			// 3177
   idDeposCountDenom15,			// 3178
   idDeposCountDenom16,			// 3179
   idDeposCountDenom17,			// 3180
   idDeposCountDenom18,			// 3181
   idDeposCountDenom19,			// 3182
   idDeposCountDenom20,			// 3183
   idDeposCountDenom21,			// 3184
   idDeposCountDenom22,			// 3185
   idDeposCountDenom23,			// 3186
   idDeposCountDenom24,			// 3187
   idDeposCountDenom25,			// 3188
   idDeposCountDenom26,			// 3189
   idDeposCountDenom27,			// 3190
   idDeposCountDenom28,			// 3191
   idDeposCountDenom29,			// 3192
   idDeposCountDenom30,			// 3193
   idDeposCountDenom31,			// 3194
   idDeposCountDenom32,			// 3195
   idDeposCountDenom33,			// 3196
   idDeposCountDenom34,			// 3197
   idDeposCountDenom35,			// 3198
   idDeposCountDenom36,			// 3199
   idDeposCountDenom37,			// 3200
   idDeposCountDenom38,			// 3201
   idDeposCountDenom39,			// 3202
   idDeposCountDenom40,			// 3203
   idDeposCountDenom41,			// 3204
   idDeposCountDenom42,			// 3205
   idDeposCountDenom43,			// 3206
   idDeposCountDenom44,			// 3207
   idDeposCountDenom45,			// 3208
   idDeposCountDenom46,			// 3209
   idDeposCountDenom47,			// 3210
   idDeposCountDenom48,			// 3211
   idDeposCountDenom49,			// 3212
   idDeposCountDenom50,			// 3213
   idTotalNotesEncashed,		// 3214
   idTotalNotesRefunded,		// 3215
   idTotalNotesToEscrow,		// 3216
   idTotalNotesRejected,		// 3217
   idBNAOption,					// 3218
   idBNAFitnessStatus,			// 3219 G387832 - Holds Application Level BNA fitness data
   idCPMFitnessStatus,			// 3220
   idCPMPocket1Count,			// 3221
   idCPMPocket2Count,			// 3222
   idCPMPocket3Count,			// 3223
   idBNALastDepositDirection,   // 3224
   idAcceptCountDenom1 = 3225,	// 3225
   idAcceptCountDenom2,			// 3226
   idAcceptCountDenom3,			// 3227
   idAcceptCountDenom4,			// 3228
   idAcceptCountDenom5,			// 3229
   idAcceptCountDenom6,			// 3230
   idAcceptCountDenom7,			// 3231
   idAcceptCountDenom8,			// 3232
   idAcceptCountDenom9,			// 3233
   idAcceptCountDenom10,		// 3234
   idAcceptCountDenom11,		// 3235
   idAcceptCountDenom12,		// 3236
   idAcceptCountDenom13,		// 3237
   idAcceptCountDenom14,		// 3238
   idAcceptCountDenom15,		// 3239
   idAcceptCountDenom16,		// 3240
   idAcceptCountDenom17,		// 3241
   idAcceptCountDenom18,		// 3242
   idAcceptCountDenom19,		// 3243
   idAcceptCountDenom20,		// 3244
   idAcceptCountDenom21,		// 3245
   idAcceptCountDenom22,		// 3246
   idAcceptCountDenom23,		// 3247
   idAcceptCountDenom24,		// 3248
   idAcceptCountDenom25,		// 3249
   idAcceptCountDenom26,		// 3250
   idAcceptCountDenom27,		// 3251
   idAcceptCountDenom28,		// 3252
   idAcceptCountDenom29,		// 3253
   idAcceptCountDenom30,		// 3254
   idAcceptCountDenom31,		// 3255
   idAcceptCountDenom32,		// 3256
   idAcceptCountDenom33,		// 3257
   idAcceptCountDenom34,		// 3258
   idAcceptCountDenom35,		// 3259
   idAcceptCountDenom36,		// 3260
   idAcceptCountDenom37,		// 3261
   idAcceptCountDenom38,		// 3262
   idAcceptCountDenom39,		// 3263
   idAcceptCountDenom40,		// 3264
   idAcceptCountDenom41,		// 3265
   idAcceptCountDenom42,		// 3266
   idAcceptCountDenom43,		// 3267
   idAcceptCountDenom44,		// 3268
   idAcceptCountDenom45,		// 3269
   idAcceptCountDenom46,		// 3270
   idAcceptCountDenom47,		// 3271
   idAcceptCountDenom48,		// 3272
   idAcceptCountDenom49,		// 3273
   idAcceptCountDenom50,	    // 3274
   idCPMEndorseFlag,            // 3275
   idPendingEJFlag,				// 3276
   idNumberEJRetriesLeft,		// 3277
   idEJLastCharRecvd,			// 3278
   idEJLastCharThisBlock,		// 3279
   idEJLastCharPrevBlock,		// 3280
   idEJOption60,				// 3281
   idEJOption61,				// 3282
   idEJTimer60,					// 3283
   idEJOffset,					// 3284 - TAR 269692
   // RFC 246177 Two entries below added for Dial Up support
   idDialUpMsgOnCPOption,		// 3285 Supervisor option controlling Message completion
   idDialUpHostHeaderEnabled,    // 3286 Supervisor option do we expect host msgs to have dial-up headers
   idDialUpTransactionCompletion,// 3287 1 = Transaction Completion ON, 0 = No TC
   idDialUpActivityTimer,        // 3288 Time in seconds for I'm Alive Redial - range  0 - 25,500
   idDialUpMessageSuppression,   // 3289 Suppress certain message for dialup - 1 = On, 0 = off
   idDialUpCPMessageTimer,       // 3290
   idDialUpErrorRedialTimer,     // 3291
   //RFC 311213 BNA Retract Count CDI Stores
   idRetractCountDenom1,		// 3292 - BNA Retract Count CDI Stores
   idRetractCountDenom2,		// 3293
   idRetractCountDenom3,		// 3294
   idRetractCountDenom4,		// 3295
   idRetractCountDenom5,		// 3296
   idRetractCountDenom6,		// 3297
   idRetractCountDenom7,		// 3298
   idRetractCountDenom8,		// 3299
   idRetractCountDenom9,		// 3300
   idRetractCountDenom10,		// 3301
   idRetractCountDenom11,		// 3302
   idRetractCountDenom12,		// 3303
   idRetractCountDenom13,		// 3304
   idRetractCountDenom14,		// 3305
   idRetractCountDenom15,		// 3306
   idRetractCountDenom16,		// 3307
   idRetractCountDenom17,		// 3308
   idRetractCountDenom18,		// 3309
   idRetractCountDenom19,		// 3310
   idRetractCountDenom20,		// 3311
   idRetractCountDenom21,		// 3312
   idRetractCountDenom22,		// 3313
   idRetractCountDenom23,		// 3314
   idRetractCountDenom24,		// 3315
   idRetractCountDenom25,		// 3316
   idRetractCountDenom26,		// 3317
   idRetractCountDenom27,		// 3318
   idRetractCountDenom28,		// 3319
   idRetractCountDenom29,		// 3320
   idRetractCountDenom30,		// 3321
   idRetractCountDenom31,		// 3322
   idRetractCountDenom32,		// 3323
   idRetractCountDenom33,		// 3324
   idRetractCountDenom34,		// 3325
   idRetractCountDenom35,		// 3326
   idRetractCountDenom36,		// 3327
   idRetractCountDenom37,		// 3328
   idRetractCountDenom38,		// 3329
   idRetractCountDenom39,		// 3330
   idRetractCountDenom40,		// 3331
   idRetractCountDenom41,		// 3332
   idRetractCountDenom42,		// 3333
   idRetractCountDenom43,		// 3334
   idRetractCountDenom44,		// 3335
   idRetractCountDenom45,		// 3336
   idRetractCountDenom46,		// 3337 
   idRetractCountDenom47,		// 3338
   idRetractCountDenom48,		// 3339
   idRetractCountDenom49,		// 3340
   idRetractCountDenom50,		// 3341
   idJournalTrack2,             // 3342 Holds Enhanced Config Param 37 - Print Track 2 to Journal if 001, don't if 000
   idInitialTotcass1 = 3343,	//TAR295400
   idInitialTotcass2,
   idInitialTotcass3,
   idInitialTotcass4,
   idRejectBinTotal,          //GBNA RFC 313834  //3347
   idDebugOutput,				//RFC 355963 //3348
   idDebugSetting = 3349,			//RFC 355963 //3349
   
   // RFC 329405 - CPM
   idEndorserRibbonSupplies = 3350,	// 3350
   idStampInkSupplies,			    // 3351
   idCaptureBin1Supplies,		    // 3352
   idCaptureBin2Supplies,		    // 3353
   idCaptureBin3Supplies,		    // 3354
   idOptionArray83,				    // 3355

   // GRIT 323089 - DualDispenser implementation
   idNotesDispType1_CDM1 = NOTE_COUNTERS_OFFSET_CDM1 + OFFSET_DISPENSED, //3401
   idNotesDispType2_CDM1,       //3402
   idNotesDispType3_CDM1,       //3403
   idNotesDispType4_CDM1,       //3404
   idNotesDispType5_CDM1,       //3405
   idNotesDispType6_CDM1,       //3406
   idNotesDispType7_CDM1,       //3407
   idNotesInType1_CDM1   = NOTE_COUNTERS_OFFSET_CDM1 + OFFSET_NOTES_IN, //3411  
   idNotesInType2_CDM1,         //3412
   idNotesInType3_CDM1,         //3413
   idNotesInType4_CDM1,         //3414
   idNotesInType5_CDM1,         //3415
   idNotesInType6_CDM1,         //3416
   idNotesInType7_CDM1,         //3417
   idNotesPurgedType1_CDM1 = NOTE_COUNTERS_OFFSET_CDM1 + OFFSET_PURGED, //3421
   idNotesPurgedType2_CDM1,     //3422
   idNotesPurgedType3_CDM1,     //3423
   idNotesPurgedType4_CDM1,     //3424
   idNotesPurgedType5_CDM1,     //3425
   idNotesPurgedType6_CDM1,     //3426
   idNotesPurgedType7_CDM1,     //3427

   idNotesDispType1_CDM2 = NOTE_COUNTERS_OFFSET_CDM2 + OFFSET_DISPENSED,	// 3431
   idNotesDispType2_CDM2,       //3432
   idNotesDispType3_CDM2,       //3433
   idNotesDispType4_CDM2,       //3434
   idNotesDispType5_CDM2,       //3435
   idNotesDispType6_CDM2,       //3436
   idNotesDispType7_CDM2,       //3437
   idNotesInType1_CDM2 = NOTE_COUNTERS_OFFSET_CDM2 + OFFSET_NOTES_IN,		// 3441
   idNotesInType2_CDM2,         //3442
   idNotesInType3_CDM2,         //3443
   idNotesInType4_CDM2,         //3444
   idNotesInType5_CDM2,         //3445
   idNotesInType6_CDM2,         //3446
   idNotesInType7_CDM2,         //3447
   idNotesPurgedType1_CDM2 = NOTE_COUNTERS_OFFSET_CDM2 + OFFSET_PURGED,		// 3451
   idNotesPurgedType2_CDM2,     //3452
   idNotesPurgedType3_CDM2,     //3453
   idNotesPurgedType4_CDM2,     //3454
   idNotesPurgedType5_CDM2,     //3455
   idNotesPurgedType6_CDM2,     //3456
   idNotesPurgedType7_CDM2,     //3457

   idStdNotes1_CDM1 = STD_NOTE_COUNTERS_OFFSET_CDM1, //3461
   idStdNotes2_CDM1,            //3462
   idStdNotes3_CDM1,            //3463
   idStdNotes4_CDM1,            //3464
   idStdNotes5_CDM1,            //3465
   idStdNotes6_CDM1,            //3466
   idStdNotes7_CDM1,            //3467

   idStdNotes1_CDM2 = STD_NOTE_COUNTERS_OFFSET_CDM2, //3471    
   idStdNotes2_CDM2,            //3472
   idStdNotes3_CDM2,            //3473     
   idStdNotes4_CDM2,            //3474     
   idStdNotes5_CDM2,            //3475     
   idStdNotes6_CDM2,            //3476     
   idStdNotes7_CDM2,            //3477 
   idOption76,                  //3478 
   idDispenseMoreThan99Notes,   //3479 AANDC-17560: Set this based on Option 76 bit 2 to support dispensing more than 99 notes.   

   // TAR 323730 - CDI stores for denom counts per BNA cassette
   idCass1CountDenom1 = 3501,	// 3501 - BNA Cass1 Count CDI Stores
   idCass1CountDenom2,
   idCass1CountDenom3,
   idCass1CountDenom4,
   idCass1CountDenom5,	
   idCass1CountDenom6,	
   idCass1CountDenom7,	
   idCass1CountDenom8,	
   idCass1CountDenom9,	
   idCass1CountDenom10,	
   idCass1CountDenom11,	
   idCass1CountDenom12,	
   idCass1CountDenom13,	
   idCass1CountDenom14,	
   idCass1CountDenom15,	
   idCass1CountDenom16,	
   idCass1CountDenom17,	
   idCass1CountDenom18,	
   idCass1CountDenom19,	
   idCass1CountDenom20,	
   idCass1CountDenom21,	
   idCass1CountDenom22,	
   idCass1CountDenom23,	
   idCass1CountDenom24,	
   idCass1CountDenom25,	
   idCass1CountDenom26,	
   idCass1CountDenom27,	
   idCass1CountDenom28,	
   idCass1CountDenom29,	
   idCass1CountDenom30,	
   idCass1CountDenom31,	
   idCass1CountDenom32,	
   idCass1CountDenom33,	
   idCass1CountDenom34,	
   idCass1CountDenom35,	
   idCass1CountDenom36,	
   idCass1CountDenom37,	
   idCass1CountDenom38,	
   idCass1CountDenom39,	
   idCass1CountDenom40,	
   idCass1CountDenom41,	
   idCass1CountDenom42,	
   idCass1CountDenom43,	
   idCass1CountDenom44,	
   idCass1CountDenom45,	
   idCass1CountDenom46,	
   idCass1CountDenom47,	
   idCass1CountDenom48,	
   idCass1CountDenom49,
   idCass1CountDenom50,

   idCass2CountDenom1 = 3551,	// 3551 - BNA Cass2 Count CDI Stores
   idCass2CountDenom2,		
   idCass2CountDenom3,
   idCass2CountDenom4,
   idCass2CountDenom5,	
   idCass2CountDenom6,	
   idCass2CountDenom7,	
   idCass2CountDenom8,	
   idCass2CountDenom9,	
   idCass2CountDenom10,	
   idCass2CountDenom11,	
   idCass2CountDenom12,	
   idCass2CountDenom13,	
   idCass2CountDenom14,	
   idCass2CountDenom15,	
   idCass2CountDenom16,	
   idCass2CountDenom17,	
   idCass2CountDenom18,	
   idCass2CountDenom19,	
   idCass2CountDenom20,	
   idCass2CountDenom21,	
   idCass2CountDenom22,	
   idCass2CountDenom23,	
   idCass2CountDenom24,	
   idCass2CountDenom25,	
   idCass2CountDenom26,	
   idCass2CountDenom27,	
   idCass2CountDenom28,	
   idCass2CountDenom29,	
   idCass2CountDenom30,	
   idCass2CountDenom31,	
   idCass2CountDenom32,	
   idCass2CountDenom33,	
   idCass2CountDenom34,	
   idCass2CountDenom35,	
   idCass2CountDenom36,	
   idCass2CountDenom37,	
   idCass2CountDenom38,	
   idCass2CountDenom39,	
   idCass2CountDenom40,	
   idCass2CountDenom41,	
   idCass2CountDenom42,	
   idCass2CountDenom43,	
   idCass2CountDenom44,	
   idCass2CountDenom45,	
   idCass2CountDenom46,	
   idCass2CountDenom47,	
   idCass2CountDenom48,	
   idCass2CountDenom49,
   idCass2CountDenom50,

   idCass3CountDenom1 = 3601,	// 3601 - BNA Cass3 Count CDI Stores
   idCass3CountDenom2,		
   idCass3CountDenom3,
   idCass3CountDenom4,
   idCass3CountDenom5,	
   idCass3CountDenom6,	
   idCass3CountDenom7,	
   idCass3CountDenom8,	
   idCass3CountDenom9,	
   idCass3CountDenom10,	
   idCass3CountDenom11,	
   idCass3CountDenom12,	
   idCass3CountDenom13,	
   idCass3CountDenom14,	
   idCass3CountDenom15,	
   idCass3CountDenom16,	
   idCass3CountDenom17,	
   idCass3CountDenom18,	
   idCass3CountDenom19,	
   idCass3CountDenom20,	
   idCass3CountDenom21,	
   idCass3CountDenom22,	
   idCass3CountDenom23,	
   idCass3CountDenom24,	
   idCass3CountDenom25,	
   idCass3CountDenom26,	
   idCass3CountDenom27,	
   idCass3CountDenom28,	
   idCass3CountDenom29,	
   idCass3CountDenom30,	
   idCass3CountDenom31,	
   idCass3CountDenom32,	
   idCass3CountDenom33,	
   idCass3CountDenom34,	
   idCass3CountDenom35,	
   idCass3CountDenom36,	
   idCass3CountDenom37,	
   idCass3CountDenom38,	
   idCass3CountDenom39,	
   idCass3CountDenom40,	
   idCass3CountDenom41,	
   idCass3CountDenom42,	
   idCass3CountDenom43,	
   idCass3CountDenom44,	
   idCass3CountDenom45,	
   idCass3CountDenom46,	
   idCass3CountDenom47,	
   idCass3CountDenom48,	
   idCass3CountDenom49,
   idCass3CountDenom50,

   idCass4CountDenom1 = 3651,	// 3651 - BNA Cass4 Count CDI Stores
   idCass4CountDenom2,		
   idCass4CountDenom3,
   idCass4CountDenom4,
   idCass4CountDenom5,	
   idCass4CountDenom6,	
   idCass4CountDenom7,	
   idCass4CountDenom8,	
   idCass4CountDenom9,	
   idCass4CountDenom10,	
   idCass4CountDenom11,	
   idCass4CountDenom12,	
   idCass4CountDenom13,	
   idCass4CountDenom14,	
   idCass4CountDenom15,	
   idCass4CountDenom16,	
   idCass4CountDenom17,	
   idCass4CountDenom18,	
   idCass4CountDenom19,	
   idCass4CountDenom20,	
   idCass4CountDenom21,	
   idCass4CountDenom22,	
   idCass4CountDenom23,	
   idCass4CountDenom24,	
   idCass4CountDenom25,	
   idCass4CountDenom26,	
   idCass4CountDenom27,	
   idCass4CountDenom28,	
   idCass4CountDenom29,	
   idCass4CountDenom30,	
   idCass4CountDenom31,	
   idCass4CountDenom32,	
   idCass4CountDenom33,	
   idCass4CountDenom34,	
   idCass4CountDenom35,	
   idCass4CountDenom36,	
   idCass4CountDenom37,	
   idCass4CountDenom38,	
   idCass4CountDenom39,	
   idCass4CountDenom40,	
   idCass4CountDenom41,	
   idCass4CountDenom42,	
   idCass4CountDenom43,	
   idCass4CountDenom44,	
   idCass4CountDenom45,	
   idCass4CountDenom46,	
   idCass4CountDenom47,	
   idCass4CountDenom48,	
   idCass4CountDenom49,
   idCass4CountDenom50,

   idRejectCountDenom1 = 3701,	// 3701 - BNA Reject Count CDI Stores
   idRejectCountDenom2,		
   idRejectCountDenom3,
   idRejectCountDenom4,
   idRejectCountDenom5,	
   idRejectCountDenom6,	
   idRejectCountDenom7,	
   idRejectCountDenom8,	
   idRejectCountDenom9,	
   idRejectCountDenom10,	
   idRejectCountDenom11,	
   idRejectCountDenom12,	
   idRejectCountDenom13,	
   idRejectCountDenom14,	
   idRejectCountDenom15,	
   idRejectCountDenom16,	
   idRejectCountDenom17,	
   idRejectCountDenom18,	
   idRejectCountDenom19,	
   idRejectCountDenom20,	
   idRejectCountDenom21,	
   idRejectCountDenom22,	
   idRejectCountDenom23,	
   idRejectCountDenom24,	
   idRejectCountDenom25,	
   idRejectCountDenom26,	
   idRejectCountDenom27,	
   idRejectCountDenom28,	
   idRejectCountDenom29,	
   idRejectCountDenom30,	
   idRejectCountDenom31,	
   idRejectCountDenom32,	
   idRejectCountDenom33,	
   idRejectCountDenom34,	
   idRejectCountDenom35,	
   idRejectCountDenom36,	
   idRejectCountDenom37,	
   idRejectCountDenom38,	
   idRejectCountDenom39,	
   idRejectCountDenom40,	
   idRejectCountDenom41,	
   idRejectCountDenom42,	
   idRejectCountDenom43,	
   idRejectCountDenom44,	
   idRejectCountDenom45,	
   idRejectCountDenom46,	
   idRejectCountDenom47,	
   idRejectCountDenom48,	
   idRejectCountDenom49,
   idRejectCountDenom50,
   
   idTimer61 = 3751,   // 3751 Barcode Timer - GRIT 330519
   idOptionArray48 = 3752, // 3752 Barcode Option GRIT 330519 
   idOption79,                  // 3753 for Coin Dispense Option
   idLastTrRepReqCoinDisp,      // 3754 for coin dispenser flag used to check if last transaction reply requested a coin dispense operation
   idCDMLastUsed,				// 3755 for dual dispenser - stores last used dispenser	
   
   idOption80 = 3756,                  // GR1T 355878 Alphanumeric State Updates
   idIncludeTrDataInReadyB = 3757,			// G380088 - Extension to Config parameters load
   idBNACass1BackupCount,		// BNA physical cassette counts CDI
   idBNACass2BackupCount,
   idBNACass3BackupCount,
   idBNACass4BackupCount,		// 3761

   idOption71,	// 3762 GR1T 392665
   idBNATransactionPoint,		// 3763 GR1T 394982 - Keeps track of where we got to in CashIn transaction
   idVGEnableOption,      // 3764 GR1T 380669 Supporting VG Functionality
   idBNARetractCountTotal,		// 3765 G395068 - Keeps track of total notes retracted during CashIn transaction
   idOption74,					// 3766 G393744 - BNA Configurable Retract Destination Option Setting
   idCamDeviceStatusEnabled,     // 3767 G380673 - Camera Support-to send unsol when this store enabled
   
   idTimer80,                   // 3768 G398168: Biometric timers 80 & 81
   idTimer81,                   // 3769 G398168: Biometric timers 80 & 81
   
   //RFC 379467: Last Transaction Status counts should not be cumulative
   idLastTransactionNotesRefunded, //3770
   idLastTransactionNotesRejected, //3771
   idLastTransactionNotesEncashed, //3772
   idLastTransactionNotesEscrowed, //3773
   idCardholderDisplayUnsol,//3774
   idTimer63, //3775 G432058 - Timer63 implementation
   idOfflineEncashTotal , // 3776 RFC 502921 - BNA OfflineEncash Counts & Total
   idOption41, // 3777 RFC 582837 - Send Track details on card retract 
  
/******************** PERSISTENT STRINGS ***********************/

   idCardClrDate                =  4000,  // PERSISTENT STRINGS
   idCashClrDate,               // 4001
   idCoinClrDate,               // 4002
   idConfigID,                  // 4003
   idCurrVersion,               // 4004
   idDPMRejectBinClrDate,       // 4005
   idEnvClrDate,                // 4006
   idLUNO,                      // 4007
   idMachineNo,                 // 4008
   idMACNo,                     // 4009  // SG Was idMACMCNo
   idSecurityFlags,             // 4010
   idOthMsgMAC,                 // 4011
   idPocketAClrDate,            // 4012
   idPocketBClrDate,            // 4013
   idPocketCClrDate,            // 4014
   idSolicStatusMAC,            // 4015
   idTr1MAC,                    // 4016
   idTr2MAC,                    // 4017
   idTr3MAC,                    // 4018
   idTrReplyMAC,                // 4019
   idTrReqMAC,                  // 4020
   idTSN,                       // 4021
   idTSNBackup,                 // 4022
   idVISAKeyA0,                 // 4023
   idVISAKeyA1,                 // 4024
   idVISAKeyA2,                 // 4025
   idVISAKeyA3,                 // 4026
   idVISAKeyA4,                 // 4027
   idVISAKeyA5,                 // 4028
   idVISAKeyB0,                 // 4029
   idVISAKeyB1,                 // 4030
   idVISAKeyB2,                 // 4031
   idVISAKeyB3,                 // 4032
   idVISAKeyB4,                 // 4033
   idVISAKeyB5,                 // 4034
   idBNAClrTimeDate,			// 4035
   idCPMPocket1ClrDate,			// 4036
   idCPMPocket2ClrDate,			// 4037
   idCPMPocket3ClrDate,			// 4038
   idBNAMaintenanceData = 4040,	// 4040
   idEJUploadMsg        = 4045, // 4045 I am not sure why thia
   idPendingEJCommand,			// 4046
   idEJCmdCode,					// 4047
   idEMVConfigMAC,				// 4048 DM EMC
   //idTransBeingProcessed,		// 4049 TAR214120 DM 20/12/02
   //idReadySentInTranFunc,		// 4050 TAR214120 DM 20/12/02
   idNDCTimeOUT = 4051,				// 4051	RFC 221154 RS 4/12/02
   idBNAFitnessData,				//4052 No longer used.
   idSWLeftMargin,		        //4053 RFC 329421 SE 02/03/06
   idRcptCharMapInfo,           //RFC 329419 SE 12/05/2006
   idJrnlCharMapInfo,           //RFC 329419 SE 12/05/2006
   idLastDepositTrRecyclingInfo, //4056 - Contains last transaction Recycle Data if previous transaction is deposit
   idDepositCassLogTypetoPhyPosMapping, // 4057 No longer used.
   idCPMLastDepositedTSN,		//4058 GRIT 380674 for ImageMarkPassportAgent
   idStateFlowSequence,         //4059 RFC 442527 for state flow trace
   idCDM2CashClrDate,         // 4060 RFC 576225 for Cash handler 2 counts clear date   
   idCDM1BinClrDate,          // 4061 AANDC-2251 for Cash handler 1 Bin counts clear date
   idCDM2BinClrDate,          // 4062 AANDC-2251 for Cash handler 2 Bin counts clear date
   
   /******************** PERSISTENT INTEGER ARRAYS ***********************/

   idCoinRem                    =  5000,  // Coin Counts
   idBackCoinRem                =  5001,
   idCoinDisp                   =  5002,
   idBackCoinDisp               =  5003,
   idCoinsToDisp                =  5004,
   idLastCoinDisp               =  5005,
   idStdCoin                    =  5006,
   idCoinsLoaded                =  5007,
   idCurrCoinDisp               =  5008,

   idNotesInCassettes = 5010,
   idBackNotesInCassettes,        // 5011
   idNotesDispensed,              // 5012
   idBackNotesDispensed,          // 5013
   idNotesToDispense,             // 5014
   idLastNotesDispensed,          // 5015
   idNotesPurged,                 // 5016
   idBackNotesPurged,             // 5017
   idNotesDispensed_CDM1,         // 5018
   idNotesInCassettes_CDM1,       // 5019
   idNotesPurged_CDM1,            // 5020
   idNotesDispensed_CDM2,         // 5021
   idNotesInCassettes_CDM2,       // 5022
   idNotesPurged_CDM2,            // 5023
   idInitialTotalNotes_CDM1,	  // 5024  
   idInitialTotalNotes_CDM2,      // 5025  
   idInitialTotalNotes,           // 5026
   idStdNotes,                    // 5027
   idStdNotes_CDM1,               // 5028
   idStdNotes_CDM2,               // 5029

   idDelta_dispensed1 = 5030,	  // 5030
   idDelta_dispensed2,			  // 5031	
   idDelta_rejected1,  			  // 5032
   idDelta_rejected2,			  // 5033

   idRecycleCassDepCountByNoteID,		// 5034 - G380088
   idRecycleCassDepCountByNDCType,		// 5035 - G381127 
   idRecycleCassDepCountByNDCType_CDM1,	// 5036 - For future use
   idRecycleCassDepCountByNDCType_CDM2,	// 5037

   idPerTransactionCAT2 = 5040,		// 5040
   idPerTransactionCAT3,			// 5041
   idAccumulatedCAT2,				// 5042
   idAccumulatedCAT3,				// 5043
   idBNASortedIndices,				// 5044
   idBNAPerTransEncash,				// 5045
   idBNARetractBinCounts,			// 5046 G393744 - BNA Configurable Retract Destination
   idBackupBNARetractBinCounts ,	// 5047 RFC 490120  

   idCDMRetractBinCounts ,			// 5048 RFC 490120 - CO Retract Counts reported by CI
   idCDMRetractBinCounts_CDM1 ,		// 5049 RFC 490120 - Reserved for future use
   idCDMRetractBinCounts_CDM2 ,		// 5050 RFC 490120 - Reserved for future use 
   idBNARejectEncashCountArray,		// 5051 GRIT 510925 - for Encash Reject count of  BNA
   idRetractRecycleCounts,			// 5052 RFC 501971 - Retract Recycle Counts 
   idOfflineEncashCounts ,			// 5053 RFC 502921 - BNA OfflineEncash Counts & Total 
   idCDMTypeDenoms,					// 5054 RFC 581006 - Stores the denom of the cassette
   idCDMTypeDenoms_CDM1,			// 5055 RFC 581006 - Stores the denom of the cassette
   idCDMTypeDenoms_CDM2,			// 5056 RFC 581006 - Stores the denom of the cassette
   idCass5CountByDenom,				// 5057 AANDC-13113 - BNA Cass5 Count CDI Stores
   idCass6CountByDenom,				// 5058 AANDC-13113 - BNA Cass6 Count CDI Stores
   idCass7CountByDenom,				// 5059 AANDC-13113 - BNA Cass7 Count CDI Stores
   idCass8CountByDenom,				// 5060 AANDC-13113 - BNA Cass8 Count CDI Stores
   idCass9CountByDenom,				// 5061 AANDC-13113 - BNA Cass9 Count CDI Stores
   idCass10CountByDenom,		    // 5062 AANDC-13113 - BNA Cass10 Count CDI Stores
   idRetract2CountByDenom,  		// 5063 AANDC-13113 - BNA Retract2 Count CDI Stores
   idCDM1RejectAndRetractBinCounts,	// 5064 AANDC-2251 for Cash handler 1 Reject and Retract Bin counts
   idCDM2RejectAndRetractBinCounts,	// 5065 AANDC-2251 for Cash handler 2 Reject and Retract Bin counts
};

typedef enum eVars eVarID;

#endif

