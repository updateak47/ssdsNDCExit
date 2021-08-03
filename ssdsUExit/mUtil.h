/*
This Revision: $Id: CommonUtilities/Exports/Interface/mUtil.h 1.25 2009/04/06 19:17:25IST Dryden, Jim (JD515051) Exp  $
+-----------------------------------------------------------------------------+
|                                                                             |
|   File Name  : mUtil.h                                                      |
|                                                                             |
|   Description: Interface for run-time core utilities                        |
|                                                                             |
+-----------------------------------------------------------------------------+
|                                                                             |
|         Copyright(C) NCR Financial Systems Group Ltd 1993 - 1998            |
|                                                                             |
|                      Solutions For Services, Dundee                         |
|                                                                             |
+-----------------------------------------------------------------------------+
|                                                                             |
|  All revision information is updated automatically from source code control |  
|  change records - please do not manually edit.                              |
|                                                                             |
+-----------------------------------------------------------------------------+
$Log: CommonUtilities/Exports/Interface/mUtil.h  $
Revision 1.25 2009/04/06 19:17:25IST Dryden, Jim (JD515051) 
AANDC340_to_trunk
Revision 1.23.1.3 2009/04/06 14:47:25BST Kilgore, Andrew (ak185068) 
RFC 425847 - Merge to 03.04.00
Revision 1.23.1.2 2009/03/19 14:31:26GMT Kilgore, Andrew (ak185068) 
RFC 423706 - Merge to IT3
Revision 1.23 2008/06/10 10:46:32BST Dryden, Jim (JD515051) 
ANDC330_to_trunk
Revision 1.22.1.2 2008/06/10 10:46:32BST Kilgore, Andrew (ak185068) 
RFC 392664 - Move mMutex to mUtil to allow sharing between OOXFS and FILEIO2
Revision 1.22 1998/06/04 10:04:22BST martinh 
Implemented grits 52 & 90 to resolve Unicode / Ascii conversion issues and embedded NULLs (verified by Callum M, Tim K, Iain G and Sandy B)
Revision 1.21  1998/02/12 16:31:56  martinh
Altered positioning of IMP_OR_EXP define in function delcarations
Revision 1.20  1998/01/05 14:20:44  martinh
Renamed conversion functions to AsInteger and AsReal
Revision 1.19  1997/12/19 09:35:26  martinh
Patch repair to mString interface (removed WCHAR and unicode conditional compiles)
Revision 1.18  1997/12/05 11:44:20  martinh
Inserted class definition for mStringImp
Revision 1.17  1997/11/27 11:15:18  martinh
Re-arranged definition order for mString members, etc.
Revision 1.16  1997/03/12 18:54:20  martinh
Tidied up mEvent class description
Revision 1.15  1997/03/12 17:54:20  TIMKILLE
Revision 1.14  1997/03/12 16:54:20  TIMKILLE
Revision 1.13  1997/03/12 15:54:20  TIMKILLE
Revision 1.12  1997/03/12 14:54:20  andywr
Added IsType method to mEvent.
Revision 1.11  1997/03/12 13:54:20  ikingham
Revised mEvent class to accord with Component Type Interface Spec - added asText() virtual method
Revision 1.10  1997/03/12 12:54:20  ikingham
Fixed missing colon in linline template of mDynarr
Revision 1.9  1997/03/12 11:54:20  ikingham
Removed extension #defines
Revision 1.8  1997/03/12 10:54:20  ikingham
Code Review: mDynarray no longer constructs objects mEvent class declaration moved to this file
Revision 1.7  1997/03/12 09:54:20  ikingham
Corrected 'little endian' problem in ExportAsBytes()
Added new private method ExportCore() to handle all cases.
Existing Export???() now simple call appropriate ExportCore()
Revision 1.6  1997/03/12 09:54:20  ikingham
RFC5236 - added new constructors
RFC5237 - added new export functions
Logical methods return BOOL, not int
Default length arg set to SHRT_MAX, not USHRT_MAX
Wrapped obsoleted metods in EXCL_LEGACY #defines
Revision 1.5  1997/03/12 09:54:20  ikingham
Wrapped legacy interfaces with #ifndef EXCL_LEGACY protection.
Added IMP_OR_EXP for friend functions
Corrected Export variants
Added omitted default arg values.
Revision 1.4  1997/03/12 09:54:20  ikingham
Implemented obsoleted functions in mString
Not tested
Revision 1.3  1997/03/12 09:54:20  ikingham
Added mList classes
Code compiles & links. Not tested
Revision 1.2  1997/03/12 09:54:20  ikingham
mString compiles & links - not tested
Revision 1.1  1997/03/12 09:54:20  ikingham
Initial Revision
+-----------------------------------------------------------------------------+
*/



#ifndef MUTIL_H_INCL	
#define MUTIL_H_INCL


// includes
#include <mapsdef.h>
#include <limits.h>


// import / export control
#if !defined MUTIL_LIB 
    #define IMP_OR_EXP             __declspec(dllimport)
#else
    #define IMP_OR_EXP             __declspec(dllexport)
#endif


/*
+-----------------------------------------------------------------------------+
|                                                                             |
|  mStringImp                                                                 |
|  ----------                                                                 |
|                                                                             |
+-----------------------------------------------------------------------------+
*/
class mStringImp
{
public:
    mStringImp();
    mStringImp(const TCHAR *pBuffer, const UINT Length);
    mStringImp(const char *pBuffer, const UINT Length);

    ~mStringImp();

public:
    UINT RefCount;

    TCHAR *TheString;
	UINT TheLength;
};

/*
+-----------------------------------------------------------------------------+
|                                                                             |
|  mString                                                                    |
|  -------                                                                    |
|                                                                             |
+-----------------------------------------------------------------------------+
*/
class IMP_OR_EXP mString
{
public:
    mString();
    mString(const mString &String);
    mString(const TCHAR *pBuffer, const UINT Offset = 0, const UINT Length = SHRT_MAX);
    mString(const char *pBuffer, const UINT Offset = 0, const UINT Length = SHRT_MAX);
    mString(const BYTE *pBuffer, const UINT NumChars, const UINT BytesPerChar);
    mString(const TCHAR	Char);
    mString(const char Char);
    mString(const long Integer);
 	mString(const double Real);
    
    ~mString();

public:
    int ReplaceStr(const mString &SearchString, const mString &ReplaceString, const UINT Offset = 0);

    mString &InsertStr(const mString &String, const UINT Offset = 0);
    mString &InsertStr(const TCHAR *pString, const UINT Offset = 0);

    IMP_OR_EXP friend int FindStr(const mString &StringToBeSearched, const mString &SearchString, const UINT Offset = 0);
    IMP_OR_EXP friend int FindStr(const mString &StringToBeSearched, const TCHAR *pSearchString, const UINT Offset = 0);

    IMP_OR_EXP friend mString Parse(mString &String, const mString &Delimiter);
    IMP_OR_EXP friend mString Parse(mString &String, const TCHAR *pDelimiter);
		
    IMP_OR_EXP friend mString SubStr(const mString &String, const UINT Offset = 0, const UINT Length = SHRT_MAX);
    IMP_OR_EXP friend mString SubStr(const TCHAR *pString, const UINT Offset = 0, const UINT Length = SHRT_MAX);

public:
    TCHAR *Export(TCHAR *pBuffer, const UINT Offset = 0, const UINT	NumChars = SHRT_MAX) const;
    char *Export(char *pBuffer, const UINT Offset = 0, const UINT NumChars = SHRT_MAX) const;
    BYTE *Export(BYTE *pBuffer, const UINT Offset = 0, const UINT NumChars = SHRT_MAX) const;

public:
    UINT GetLength() const;

    long AsInteger() const;
    double AsReal() const;

    BOOL IsInteger() const;
    BOOL IsReal() const;

public:
    mString &operator=(const mString &String);
    mString &operator=(const char *pBuffer);
    mString &operator=(const TCHAR Char);
    mString &operator=(const char Char);
    mString &operator=(const long Integer);
    mString &operator=(const double Real);

    mString &operator+=(const mString &String);
    mString &operator+=(const TCHAR *pBuffer);

    IMP_OR_EXP friend BOOL operator==(const mString &LeftStr, const mString &RightStr);	
    IMP_OR_EXP friend BOOL operator==(const mString &LeftStr, const TCHAR *pRightStr);	

    IMP_OR_EXP friend BOOL operator!=(const mString &LeftStr, const mString &RightStr);	
    IMP_OR_EXP friend BOOL operator!=(const mString &LeftStr, const TCHAR *pRightStr);	

    IMP_OR_EXP friend mString operator+(const mString &LeftStr, const mString &RightStr);
    IMP_OR_EXP friend mString operator+(const mString &LeftStr, const TCHAR *pRightStr);


#ifndef EXCL_LEGACY

    public:
		mString(const BYTE Byte);
        mString(const BYTE *pBuffer, const UINT Length);

		char *ExportASCIIZ(char *pBuffer, const UINT Offset = 0, const UINT Length = SHRT_MAX) const;
		TCHAR *ExportAsWCHAR(TCHAR *pBuffer, const UINT Offset = 0, const UINT Length = SHRT_MAX) const;
        BYTE *ExportAsBytes(BYTE *pBuffer, UINT NumChars = SHRT_MAX, const UINT BytesPerChar = sizeof(BYTE)) const;

		TCHAR operator[](const int Index) const;

		mString &operator=(const BYTE *pBuffer);
		mString &operator=(const BYTE Char);

	    IMP_OR_EXP friend int operator<(const mString &LeftStr, const mString &RightStr);
	    IMP_OR_EXP friend int operator>(const mString &LeftStr, const mString &RightStr);

	    IMP_OR_EXP friend int operator<=(const mString &LeftStr, const mString &RightStr);
	    IMP_OR_EXP friend int operator>=(const mString &LeftStr, const mString &RightStr);

	    IMP_OR_EXP friend mString operator^(const mString &LeftStr, const mString &RightStr);

		mString &asLower();
		mString &asUpper();

		void SecureBuffer();
#endif

private:	
    void DeReference();
    BYTE *ExportCore(BYTE *pBuffer, const UINT Offset, const UINT NumChars, const UINT BytesPerChar, const BOOL AddNull) const;

private:
    mStringImp *pImp;
};

/*
+-----------------------------------------------------------------------------+
|                                                                             |
|  mDynarr                                                                    |
|  -------                                                                    |
|                                                                             |
+-----------------------------------------------------------------------------+
*/

template <class T>
class mDynarr
{
public:
    mDynarr(UINT n = 2);
	~mDynarr();

public:
    T &operator[](UINT index);

    UINT size() const {return numItems;};

private:
    UINT numItems;

	T *items;
};


template <class T>
mDynarr<T>::mDynarr(UINT n) : numItems(n)
{
    // prepare new array
	items =(T *) new BYTE[(n * sizeof(T))];
    memset(items, NULL,(n * sizeof(T)));
}


template <class T>
mDynarr<T>::~mDynarr()
{
	delete [] items;
}


template <class T>
T &mDynarr<T>::operator[](UINT index)
{
    // check for resizing
    if(index >= numItems)
    {
        // prepare new array
        T *newItems =(T *) new BYTE[((index + 2) * sizeof(T))];

        // check status
        if(newItems != NULL)
        {
            // napalm
            memset(newItems, NULL,((index + 2) * sizeof(T)));

            // process existing list
            for(UINT count = 0; count < numItems; count++)
            {
                // copy over
                newItems[count] = items[count];
            }

            // delete existing list
            delete [] items;

            // adjust accordingly
            items = newItems;
            numItems = index + 2;
        }
        else
        {
            // allocation failed
            index = numItems;
        }
    }

    return items[index];
}


// provided macro for backward compatibility
#define mDYNARRDECL(T)    typedef mDynarr<##T##> T##Dynarr
#define mDYNARRDEFN(T)


/*
+-----------------------------------------------------------------------------+
|                                                                             |
|  mList                                                                      |
|  -----                                                                      |
|                                                                             |
+-----------------------------------------------------------------------------+
*/

class mListElement;

class IMP_OR_EXP mList
{
public:
    mList();
    ~mList();

public:
    void AddToEnd(void *x);
    void AddToFront(void *x);

    void *RemoveFromFront();
    void *RemoveFromEnd();

    void *RemoveFromMarker();
    void AddAfterMarker(void *x);

    int GetSize() const;

    void *PeekMarker();
	void ResetMarker();
    void MarkerToEnd();
    void IncMarker();
    void DecMarker();

private:
    mListElement *First, *Last, *Marker;
    int Size;
}; 


/*
+-----------------------------------------------------------------------------+
|                                                                             |
|  mEvent                                                                     |
|  ------                                                                     |
|                                                                             |
+-----------------------------------------------------------------------------+
*/

class IMP_OR_EXP mEvent
{
protected:
    mEvent(void);

public:
    virtual ~mEvent(void);

public:
    virtual BOOL asText(mString *eventInfo) = 0;

    // obsoleted
    virtual BOOLEAN IsType(int *aTI) const = 0;
};


/*
+-----------------------------------------------------------------------------+
|                                                                             |
|  mMutex                                                                     |
|  ------                                                                     |
|																			  |
|	  Simple encapsulation of the Win32 Mutex objects.  It enables simple     |
|	  Request - Release usage.												  |
|																			  |
|	  Be careful about the Mutex name - suggest reading MSDN for the Win32	  |
|	  CreateMutex()															  |
|																			  |
|	  If no name is specified, it covers only one process. If name is		  |
|	  supplied, it can serve and synchronise across processes, With XP,		  |
|	  however, the name can begin with Local\, Global\, Session\ prefix,	  |
|     so please read the docs if this is not clear.							  |
|																			  |
+-----------------------------------------------------------------------------+
*/

class IMP_OR_EXP mMutex
{
public:

	// Construct the object. SetName() can optionally be called later to supply a name.
	// It is only the first Request() call the actually creates/opens the Mutex object.
	mMutex(void);

	// Construct the object. SetName() can still be called later to supply a different name.
	mMutex(const TCHAR * name);

	~mMutex(void);

	// Closes the current Mutex object if it is already opened.
	void SetName(const TCHAR * name);

	// Requests access right to the Mutex object and blocks till it gets it.
	BOOL Request(void);

	// Releases the access right - need to call ReleaseMutex as this must work per thread
	//  requests and releases to the same Win32 Mutex object must go through
	//  the same instance of this mMutex class.
	BOOL Release(void);

private:

	// Helper methods and variables
	BOOL GetMutex(void);
	HANDLE aMutex;
	TCHAR * aName;
};

//**********************************************************************************
//
//		Template to allow easy creation of Singleton pattern from any defined
//		class, without having to modify the class internals
//
//**********************************************************************************
template <class T>
class Singleton
{
public:

	// Allow access to the singleton instance
	static T* Instance() 
	{
		// Static initialisation will happen only once
		static T * _instance = new T();
		
		return _instance;
	}

private:

	Singleton(); 

	~Singleton(); 

	Singleton(Singleton const&);  

	Singleton& operator=(Singleton const&);  
};

#undef IMP_OR_EXP


#endif
