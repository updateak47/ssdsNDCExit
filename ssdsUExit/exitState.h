// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SSDSUEXIT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SSDSUEXIT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SSDSUEXIT_EXPORTS
#define SSDSUEXIT_API __declspec(dllexport)
#else
#define SSDSUEXIT_API __declspec(dllimport)
#endif

#include <direct.h>
#include <malloc.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include "ndcdatac.h"
#include "ndcdatae.h"
#include "exutil.h"

using namespace std;
using std::ifstream;

// This class is exported from the SSDSUEXIT.dll
class SSDSUEXIT_API CSSDSUEXIT {
public:
	CSSDSUEXIT(void);
	// TODO: add your methods here.

};

std::string getConfigurationFile();

void writeLog(char[], char*, char*);
void writeBuffer(char[], char*, char*);
void manageActuatingSignal(char[], char*, char*);
bool canUse(const char *);
bool fileExists(string);
bool convertToBool(char);
char* _readFile(char*);
string readFile(char*);
string readConfig(std::string);
void writeLog(string, string);
void writeBuffer(string, string);
ifstream::pos_type filesize(const char*);


extern "C" SSDSUEXIT_API unsigned short intelliCamExit(unsigned char);
extern "C" SSDSUEXIT_API unsigned short biometricsExit(unsigned char);