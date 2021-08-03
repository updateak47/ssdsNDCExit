//
// $Id: Exports/Interface/ndcdatac.h 1.12 2010/01/22 18:33:25IST Bhat, Ravi (br185000) Exp  $
//

//
// (c) Copyright 1998 NCR Financial Solutions Group Limited.
//                Solutions For Services, Dundee
//
/*
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³    This file should be included within any C++ code which needs to access ³
³    the common data directly, rather than through the data store workers.  ³
³                                                                           ³
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
// $Log: Exports/Interface/ndcdatac.h  $
// Revision 1.12 2010/01/22 18:33:25IST Bhat, Ravi (br185000) 
// ANDC400_to_trunk
// Revision 1.11.1.2 2010/01/22 18:33:25IST sh185057 
// GRIT 445992 Integrated in to ANDC0400_DevPath
// Revision 1.11.1.1.1.2 2010/01/12 15:24:44IST Hundwani, Sunny Kumar (sh185057) 
// Updated to remove NDCDATA dependency
// Revision 1.11.1.1.1.1 2008/08/07 16:08:17IST Hundwani, Sunny Kumar (sh185057) 
// Duplicate revision
// Revision 1.10.1.2 2008/08/07 11:38:17BST Glencross, Stephen (SG515142) 
// G403339 To DevPath
// Revision 1.10.1.1 2007/04/10 11:23:46BST Glencross, Stephen (SG515142) 
// Duplicate revision
// Revision 1.9.1.3 2007/04/10 11:23:46BST pd515063 
// Class updated for build
// Revision 1.9.1.2 2007/03/16 16:42:02GMT jv512049 
// RFC 330530 - Integrate Coin Dispenser support
// Revision 1.9.1.1.2.1 2007/01/18 22:01:03IST sp185027 
// Duplicate revision
// Revision 1.8 2004/03/09 17:20:06GMT sc230002 
// // GRIT 242237 - updates to get the UCDI store data in sscorewcl
// Revision 1.7  2002/11/12 15:32:44Z  PD515063
// GRIT 229252 (EMV Exits update) - inclusion of mUtil.h causing build issue in exits
// mUtil.h removed from this file and included where required (only vmaptabl.cpp affected)
// Revision 1.5  2000/05/30 10:23:04Z  RR500009
// Added CreateNewIntegerStore() and CreateNewStringStore()
// Revision 1.4  2000/05/02 13:47:19Z  rl400003
// RFC 207598 -- User Defined CDI stores
// Revision 1.3  2000/03/01 11:44:03Z  rl400003
// User Defined CDI stores, Unifinished work Backup.
// Revision 1.1  1998/01/29 18:24:38  stepheng
// Initial Revision
//
// +------------------------------------------------------------------------------+
//

#ifndef NDC_DATA_C_H
#define NDC_DATA_C_H

// UCDI definitions ////////////////////////////////////////////////////////////////
//
// names over this size will be truncated.
// if a change is made to the max size of names all previous UCDIpersist files will fail as
// the key size is fixed.
//
const int MAX_SIZE_OF_UCDI_NAME =40;

// maximum size of any UCDI ini file line, ie name+data+type
//
const int MAXSIZEOFLINE = 255;

// enums passed to COMCDIstore/UCDI objects to identify data types.
//
//
//  COMInt,COMstr,COMreal. COMintArray are for System defined CDI stores i.e StoreID != 0;
//
//  The others are for User Defined CDI stores:
//	Value		|Meaning								|Author Equiv.
//  --------------------------------------------------------------
//  NonPUCDI	|normal UCDI which is NON-Persistent	|Normal
//	ResetPUCDI  |re-settable persistent UCDI store		|Persist
//  NormPUCDI	|NON-resettable persistent UCDI store.	|Persist Reset
//
//
enum COMVariantstoreTypes { COMint = 1, COMstr, COMreal, COMintArray,NonPUCDI = 1, NormPUCDI = 2, ResetPUCDI = 3};
typedef enum COMVariantstoreTypes UCDItype;




//
////////////////////////////////////////////////////////////////////////////////////




// Include the enumerated types used by the findindex() function.
//
// RFC 324333 - avoid deprecation warnings
#include "nodeprecate.h"

#include "ndcdatae.h"

#include <string.h>
#include <stdlib.h>

#if defined MICROSOFT_NT
  #if !defined(NDCDATA_LIB)
    #define IMP_OR_EXP __declspec(dllimport)
  #else
    #define IMP_OR_EXP __declspec(dllexport)
  #endif
#endif


IMP_OR_EXP void initCommonData(void);

/*
**
** The FindIndex function is used to perform a lookup on
** the given variable ID number, this is then used as a
** parameter for all the Get and Put functions.
**
*/

IMP_OR_EXP long	  FindIndex( eVarID );

/*
** The Get???Val routines return the value of the variable referenced
** by the eVarID parameter.
*/
IMP_OR_EXP long    GetIntVal( long index);
IMP_OR_EXP double  GetRealVal( long index);
IMP_OR_EXP char *  GetStringVal( long index);	/* Note the return is a duplicate
																it is YOUR responsibility to free() it */

//New methods added for Array CDI store
IMP_OR_EXP long    GetIntArrayVal( long ID, long index);
IMP_OR_EXP char *  GetStringArrayVal (long ID, long index);


// the UCDI versions
IMP_OR_EXP long    GetIntVal( const char * name);
IMP_OR_EXP char *  GetStringVal( const char * name);	/* Note the return is a duplicate
																it is YOUR responsibility to free() it */

/*
**	The put routines will validate that the eVarID refers to a 'C'
** writable variable.
*/

IMP_OR_EXP void PutIntVal( long index, long val);
IMP_OR_EXP void PutRealVal( long index, double val);
IMP_OR_EXP void PutStringVal( long index, char * val );

//New method added for Array CDI store
IMP_OR_EXP void PutIntArrayVal( long id, long index, long val);

// the UCDI versions
IMP_OR_EXP void PutIntVal(const char * name , long val);
IMP_OR_EXP void PutStringVal(const char * name, char * val );
IMP_OR_EXP bool StoreUserIntegerStore(const char * name, long val, char *type = "Normal");
IMP_OR_EXP bool StoreUserStringStore(const char * name, char * val, char *type = "Normal" );

// GRIT 242237 - updates to get the UCDI store data also 
// This function implmented to get the GetIntVal( const char * name)
// from GetProcAdress() because the other one is not a C export.
extern "C" __declspec (dllexport) long    GetIntValUCDI( const char * name);

// GRIT 445992 - Update to get UCDI string store
// This function implemented to get the GetIntVal( const char * name) and
//PutStringValUCDI(const char * name, char * val)from GetProcAdress()
//because the other one is not a C export.
extern "C" __declspec (dllexport) char * GetStringValUCDI( const char * name);
extern "C" __declspec (dllexport) void   PutStringValUCDI(const char * name, char * val);

/*
** The following routine should be called to reset the Persistent stores to their
** default values.
*/

IMP_OR_EXP void   ResetPersistentCommonData( void );


//////////////////////////////////////////////////////
// mCduCdiInt - Common Data Interface Integer Variable
//
class mCduCdiInt
{
  public:

	mCduCdiInt()
    {
      _id = idLastVar;
    };

    mCduCdiInt( eVarID id )
    {
      _id = id;
    };

    ~mCduCdiInt()
    {
      _id = idLastVar;
    };

    void Put( long val )
    {
      PutIntVal( _id, val );
    };

    long Get() const
    {
      return GetIntVal( _id );
    };

    operator long() const
    {
      return Get();
    };

    mCduCdiInt& operator=( long val )
    {
      Put( val );
      return *this;
    };

	//S08-22 Can now assign an object of type mCduCdiInt to a similar object
	mCduCdiInt& operator=( mCduCdiInt& cdiInt )
    {
      Put( cdiInt.Get());
      return *this;
    };

  private:
    eVarID _id;
};


//////////////////////////////////////////////////////
// mCduCdiString - Common Data Interface Integer Variable
//
class mCduCdiString
{
  public:

	  mCduCdiString( eVarID id )
    {
		  _id = id;
      _str = NULL;
  	};

	  ~mCduCdiString()
    {
		  _id = idLastVar;
      if (_str)
      {
         free( _str );
         _str = NULL;
      }
  	};

	  void Put( const char * val )
    {
		  PutStringVal( _id, (char *)val );	// cast required until the prototype
                  											// for PutStringVal is fixed
  	};

	  void Put( long val )
    {
		  PutIntVal( _id, val );
  	};

	  // Returned character pointer intended for immediate use only. It may be
	  // invalidated by any activity on this object or the referenced variable
	  // inside the CDI.
	  const char * Get()
    {
		  char * buf;
		  buf = GetStringVal( _id );
      if (_str)
      {
         free( _str );
         _str = NULL;
      }
  		_str = _strdup(buf);	// Make a safe copy of string

      if (buf)
		    free( buf );

		  return (const char *)_str;
	  };

	  operator const char *()
    {
		  return Get();
	  };

	  mCduCdiString& operator=( const char * val )
    {
		  Put( val );
		  return *this;
	  };

	//S08-22 Can now assign an object of type mCduCdiString to a similar object
	  mCduCdiString& operator=( mCduCdiString& cdiStr )
    {
		Put( cdiStr.Get());
		return *this;
	};

  	mCduCdiString& operator=( long val )
    {
		  Put( val );

		  return *this;
	  };


  private:
	  eVarID _id;
	  char * _str;
};

//*****************************************************************************************

//////////////////////////////////////////////////////
// mCduCdiIntArray - Common Data Interface Array Integer Variable
//

class mCduCdiIntArray
{
  public:
    mCduCdiIntArray( eVarID id , long size)
    {
      _id = id;
      _size = size;
    };

    ~mCduCdiIntArray()
    {
      _id = idLastVar;
    };

    void Put( long val , long index)
    {
      PutIntArrayVal( _id, index, val );
    };

    long Get(long index) const
    {
      return GetIntArrayVal( _id, index);
    };

    mCduCdiIntArray& operator=( long val ) //This method puts same value in the whole array
    {
        for(int i = 0; i < _size; i++)
        {
            Put( val, i );
        }
        return *this;
    };

    //S08-22 Can now assign an object of type mCduCdiIntArray to a similar object
    mCduCdiIntArray& operator=( mCduCdiIntArray& cdiIntArray )
    {
        for(int i = 0; i < _size; i++)
        {
            Put( cdiIntArray.Get(i),i);
        }
      return *this;
    };

    long operator[](int subscript)
    {
        if(subscript >= 0 || subscript < _size)
        {
            return Get(subscript);
        }
        else
        {
            return 0;
        }

    }

  private:
    mCduCdiIntArray()
    {
      _id = idLastVar;
    };

    eVarID _id;
    long _size;
};

//*****************************************************************************************




#if defined MICROSOFT_NT
#undef IMP_OR_EXP
#endif


#endif

