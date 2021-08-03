//
// $Id: Exports/Interface/debuglog.h 1.3 2007/01/18 21:56:22IST Vesely, Jan (jv512049) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//

// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/NDCCore/DEBUGLOG.pj $
//
// $Log: Exports/Interface/debuglog.h  $
// Revision 1.3 2007/01/18 21:56:22IST Vesely, Jan (jv512049) 
// RFC 324333 - Compiler Migration to Studio 2005
// Revision 1.2 2002/10/07 12:52:34BST jdryden 
// MV-Trunk
// MV branch moved to main dev path
// Revision 1.1.2.2  2002/10/07 11:52:34Z  stepheng
// MV NDC Update - Removed any ADI Dependancy and Changes Build Structure to reflect ADI MV Split
// Revision 1.1.2.1  1998/01/29 18:26:30Z  stepheng
// Duplicate revision
// Revision 1.1  1998/01/29 18:26:30Z  stepheng
// Initial Revision
//
// +------------------------------------------------------------------------------+
//

#ifndef DEBUGLOG_H
#define DEBUGLOG_H

#include "mapsdef.h"

// RFC 324333 - fstream change
#if _MSC_VER > 1200
#include <iostream>
#include <fstream>
#else
#include <iostream.h>
#include <fstream.h>
#endif

#include "control.h"
#include "mutil.h"
#include "dataman.h"

#if defined MICROSOFT_NT
#if !defined(DEBUGLOG_LIB)
    #define IMP_OR_EXP __declspec(dllimport)
  #else
    #define IMP_OR_EXP __declspec(dllexport)
  #endif
#endif

/*
ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ                   typedefs                                                บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*/
typedef mStringGetterWorkGroup *   pmStringGetterWorkGroup;

class DebugOut;

/*
ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ                                                                           บ
บ                        Class Definitions                                  บ
บ                                                                           บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ
*/
class IMP_OR_EXP mDebugLog : public mDoer, public mConcreteWorker
{
  public:
    mDebugLog ();
    ~mDebugLog ();

    void     Start (mEventContext* , mWorkContext& , mWorkContext*);
    mSignal* Stop (mEventContext* , mWorkContext&);
    mSignal* ProcessEvent (mEventContext* , mWorkContext&, const mEvent*);

    void set_DebugTextLine (mString& debugText);
    void set_DebugOutput(mString& debugOut);

    mStringGetterWorkGroup * Add_DebugData_WorkGroup (unsigned short aWorkGroupId);
    void         Remove_DebugData_WorkGroup (unsigned short aWorkGroupId);

  private:
    mString DebugTextLine;
    char* DebugOutput;

    pmStringGetterWorkGroup pDebugDataWG; // Pointer to Debug Data WG.

    enum MaxDebugParameters { MAX_DEBUG_DATA_WORKERS = 255, MAX_PRINT_DATA_WORKERS = 255 };

    DebugOut * dbg;
};

#if defined MICROSOFT_NT
#undef IMP_OR_EXP
#endif

#endif
