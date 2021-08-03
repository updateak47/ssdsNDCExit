// $Id: CommonUtilities/Exports/Interface/nodeprecate.h 1.1 2006/05/18 15:48:17BST jv512049 Exp  $
//
// (c) Copyright 2006 NCR Financial Solutions Division Limited.
//                GSE, Dundee
//
//
//    Program:  Advance NDC
//
//     Module:  CommonUtilities
//
//              RFC 32333 - Compiler migration to Visual Studio 2005
//
//    Purpose:  Define compiler preprocessor variables to suppress unwanted warnings
//              that some of the C/C++ calls we use have been deprecated.
//              We do not want to spend time on updating so many calls.
//
//     Author:  Jan Vesely
//
// +--------------------------- Source Control Comments --------------------------+
// $ProjectName: f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/CommonUtilitiesADI.pj $
// $Log: CommonUtilities/Exports/Interface/nodeprecate.h  $
// Revision 1.1 2006/05/18 15:48:17BST jv512049 
// Initial revision
// Member added to project f:/NCR/FSD/SelfService/Advance/SSDS/InterDomain/Components/CommonUtilitiesADI.pj
// +------------------------------------------------------------------------------+


#ifndef _NO_DEPRECATE_H
#define _NO_DEPRECATE_H

#if _MSC_VER > 1200

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif

#ifndef _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif

#endif

#endif //_NO_DEPRECATE_H
