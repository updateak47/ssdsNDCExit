//
// $Id: CommonUtilitiesNDC/Sources/Include/debugout.h 1.7 2004/08/27 19:16:08IST Vesely, Jan (JV512049) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
//
//    Program:  SSDS NDC
//     Module:  DEBUGOUT
//      Class:  DebugOut
// SuperClass:  None.
//    Purpose:  Utility function to provide Debug Output to a file
//              or named pipe.
//
//     Author:  Stephen Glencross
//
// +--------------------------- Source Control Comments --------------------------+
//
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/CommonUtilitiesNDC.pj $
//
// $Log: CommonUtilitiesNDC/Sources/Include/debugout.h  $
// Revision 1.7 2004/08/27 19:16:08IST Vesely, Jan (JV512049) 
// GRIT 248025 - improve performance by introducing a DebugLog registry setting
//                          also code review updates of G248010
// Revision 1.6  2004/05/26 11:00:54Z  as515646
// Problem Determination updates
// Revision 1.5  1999/04/20 14:40:33Z  stepheng
// Updated To allow logging to be started at anytime
// Revision 1.4  1998/07/06 12:01:35  stepheng
// Removed #define for DBON - should be in project settings
// Revision 1.3  1998/04/23 18:59:55  stepheng
// Allows one handle to be accessed per process,
// before a handle was being created per instance of the DebugOut class
// Revision 1.2  1998/04/07 14:26:06  stepheng
// Took out file logging as Client program now complete.
// Revision 1.1  1998/01/29 18:58:36  stepheng
// Initial Revision
//
// +------------------------------------------------------------------------------+
//
//
//      18-09-1997   12:05:36p , Rev 1.0, s_glencross(1616)
//      Second attempt at creating Visual Age Archive
//
//      18-09-1997   12:05:36p , Rev 1.0, s_glencross(1616)
//      Initial Visual Age Port
//
//      20-04-1997   10:52:30a , Rev 2.0, s_glencross(1616)
//      Altered pipe mechanism, now opens, writes, closes pipe
//      to allow multi-process communication
//
//      23-08-1996   09:03:22a , Rev 1.0, s_glencross(1616)
//      Original Release.
//
#ifndef DEBUGOUT_H
#define DEBUGOUT_H


#if defined DBON

#include <stdarg.h>


#if defined MICROSOFT_NT
    #if !defined(DEBUGOUT_LIB)
        #define IMP_OR_EXP __declspec(dllimport)
    #else
        #define IMP_OR_EXP __declspec(dllexport)
    #endif
#endif


class IMP_OR_EXP DebugOut
{
  public:
    DebugOut(const char* debugName = "debug");

    ~DebugOut();

    void debug (char*, ...);

  private:
    HANDLE hPipe;
	char* _debugName; // GRIT 248025 - will keep a local copy other creates problems
	                  //               when constructed without specifying a name or when name destroyed
};

void WriteEvent(char* dataToLog, WCHAR* wSource, int eventType); // GRIT 248025
char * NiceControls(const char* dataWithControls); // GRIT 248010

#if defined MICROSOFT_NT
#undef IMP_OR_EXP
#endif

#define DBG(debugMessage) debugMessage

#else

#define DBG(debugMessage)

#endif // DBON

#endif // DEBUGOUT_H