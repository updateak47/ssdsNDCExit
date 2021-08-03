//
// $Id: Exports/Interface/ndcdataf.h 1.2 2007/03/16 22:12:14IST Dryden, Jim (jd515051) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
/*
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³                     Control Harness Source File                           ³
³                           File: ndcdataf.h                                ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³                                                                           ³
³                          MODIFICATION RECORD                              ³
³                          ===================                              ³
³                                                                           ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄ´
³     Change     ³Version³Description                                  ³Init³
ÃÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄ´       ³                                             ³    ³
³ Date   ³GRIT No³       ³                                             ³    ³
ÃÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄ´
³18/03/96³ -     ³  00   ³ Original Release                            ³ GT ³
ÃÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄ´
*/
// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/NDCCore/NDCDATA.pj $
//
// $Log: Exports/Interface/ndcdataf.h  $
// Revision 1.2 2007/03/16 22:12:14IST Dryden, Jim (jd515051) 
// ANDC320_to_trunk
// Revision 1.1.3.2 2007/03/16 16:42:14GMT jv512049 
// RFC 330530 - Integrate Coin Dispenser support
// Revision 1.1.3.1.2.1 1998/01/29 23:53:44IST sp185027 
// Duplicate revision
//
// +------------------------------------------------------------------------------+
//

#ifndef NDC_DATA_F_H
#define NDC_DATA_F_H

/*
** Include the enumerated types used by the findindex() function.
*/

#include "ndcdatae.h"

#if defined MICROSOFT_NT
  #ifdef NDCDATA_LIB
    #define IMP_OR_EXP   extern "C" __declspec (dllexport)
  #else
    #define IMP_OR_EXP   extern "C" __declspec (dllimport)
  #endif
#endif  

IMP_OR_EXP void  InitCommonData(void);

/*
** The Get???Val routines return the value of the variable referenced
** by the eVarID parameter.
*/
IMP_OR_EXP long    GetIntVal( eVarID ID );
IMP_OR_EXP double  GetRealVal( eVarID ID );
IMP_OR_EXP char *  GetStringVal( eVarID ID );	/* Note the return is a duplicate
														                                  	 it is YOUR responsibility to free() it */

//New methods added for Array CDI store
IMP_OR_EXP long GetIntArrayVal( eVarID ID, long index);
IMP_OR_EXP char * GetStringArrayVal (eVarID ID, long index);


/*
**	The put routines will validate that the eVarID refers to a 'C'
** writable variable.
*/

IMP_OR_EXP void  PutIntVal( eVarID ID , long val);
IMP_OR_EXP void  PutRealVal( eVarID ID , double val);
IMP_OR_EXP void  PutStringVal( eVarID ID , char * val );

//New method added for Array CDI store
IMP_OR_EXP void  PutIntArrayVal( eVarID ID, long index, long val);


IMP_OR_EXP void * RegisterCDI ( void );
IMP_OR_EXP void   DeRegisterCDI ( void * CDIHandle);

IMP_OR_EXP void  FreeStringVal ( char * );

#ifdef MICROSOFT_NT
#undef IMP_OR_EXP
#endif

#endif

