// TestApp32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConfigFile.h"
#include <iostream>
#include <dos.h>
#include <io.h>
#include <stdlib.h>
#include <direct.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstring>
#include <string.h>
#include <iosfwd>
#include <windows.h>
#include <algorithm>
#include <ctime>
#include <sstream>



EXTERN_C IMAGE_DOS_HEADER __ImageBase;
using namespace std;

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

typedef HRESULT(STDAPICALLTYPE* FuncDllRegisterServer)();
char logpath[MAX_PATH], intelligentCamStore[MAX_PATH], stateflow_path[MAX_PATH], monitorCamera[10], triggerAlert[MAX_PATH];
char actuatingFile[MAX_PATH];

string __configfile = " ";

#define _MAX_PATH 128;
void writeLog(char[], char*, char*);
void writeBuffer(char[], char*, char*);
void writeLog(string, string);
void writeBuffer(string, string);

void ReadConfig(std::string);

class mCduCdiInt {
public:
	mCduCdiInt() : a(0) { std::cout << "mCduCdiInt::mCduCdiInt() [value = " << a << "]\n"; }
	~mCduCdiInt() { std::cout << "mCduCdiInt::~mCduCdiInt() [value = " << a << "]\n"; }
	long a;
};

#pragma region tools

void c_tolower(basic_string<char>& s) {
	for (basic_string<char>::iterator p = s.begin();
		p != s.end(); ++p) {
		*p = tolower(*p);
	}
}
bool fileExists(string file)
{
	try {
		if (access(file.c_str(), 0 | 4) != -1)
		{
			return true;     // file exists
		}
		else { // file doesn't exist
			return false;
		}
	}
	catch (const std::exception& ex)
	{
		return false;
	}

}
string getDateTime()
{
	time_t now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "[%d/%m/%Y %X]: ", &tstruct);
	return buf;
}
string getDate()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "_%d_%m_%Y", &tstruct);
	return buf;
}
char* _readFile(char* file)
{
	char str[200] = " "; ifstream iFile;
	char _file[200];
	try
	{
		if (fileExists(file)) {
			iFile.open(file, ios::in);
			while (!iFile.eof())
			{
				iFile.getline(str, 200);
				if (strlen(str) > 0) break;
			}
			iFile.close();
		}
		else {
			//sprintf(_file, "%s, file not found.", file);
			throw exception("file not found.");
		}
	}
	catch (exception ex)
	{
		if (!iFile && iFile.is_open())
			iFile.close();
		char msg[2000];
	}

	return str;
}
void c_trim_end(string& str, char trimChar)
{
	int a = str.find_last_of(trimChar);
	if (a == str.size() - 1)
		str = str.substr(0, str.size() - 1);
	//str.erase(str.size()-1)
}
std::string c_replace(std::string &s, std::string toReplace, std::string replaceWith)
{
	int rrplace = s.find(toReplace);
	if (rrplace == -1) return " ";
	return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}
string c_replace2(string s, string replaceWith)
{
	s.replace(s.length() - 3, 3, replaceWith);
	return s;
}
string getConfigurationFile()
{
	string configfile = " "; char _startup_path[1024]; char def_char = ' ';
	char cfg[1024]; string s;
	bool done = false;
	//char startup_path[1024]; //startup path variable
	//char *cd;
	//cd = _getcwd(_startup_path, sizeof(_startup_path)); //to get current working directory 
	try
	{
		char dll_directory[400] = " ";
		DWORD ret = GetModuleFileNameA((HINSTANCE)&__ImageBase, dll_directory, 1024);
		s = (string)dll_directory;
		done = true;
	}
	catch (exception ex)
	{
		char msg[2000];
		//sprintf(msg, "%s getConfigurationFile()::", getDateTime().c_str());
		strcat(msg, ex.what());
		//WriteLog(msg.c_str())
		//writeLog(msg);
	}
	if (!done) {
		try
		{
			wchar_t dll_directory[400]; //to store the directory of the dll
			DWORD ret = GetModuleFileNameW((HINSTANCE)&__ImageBase, dll_directory, 1024);
			if (ret)
			{
				WideCharToMultiByte(CP_ACP, 0, dll_directory, -1, _startup_path, 1024, &def_char, NULL);  //convert from wide char to narrow char array
			}
			s = (string)_startup_path;
		}
		catch (exception _ex)
		{
			char msg[2000];
			/*sprintf(msg, "%s getConfigurationFile()::", getDateTime().c_str());
			strcat (msg, _ex.what());*/
			//writeLog(msg, logpath, " ");
		}
	}
	string _s = c_replace2(s, "cfg");

	sprintf(cfg, "DLL File Path = %s", s.c_str());
	//writeLog(cfg, logpath, " ");
	sprintf(cfg, "CFG File Path = %s", _s.c_str());
	//writeLog(cfg, logpath, " ");
	return configfile = _s;
}
string getConfigurationFile2()
{
	char _configfile[400] = " ";
	string s;
	string configfile; char _startup_path[1024]; char def_char = ' ';
	bool done = false;
	//char startup_path[1024]; //startup path variable
	//char *cd;
	//cd = _getcwd(_startup_path, sizeof(_startup_path)); //to get current working directory 
	try
	{
		wchar_t dll_directory[400]; //to store the directory of the dll
		DWORD ret = GetModuleFileNameW((HINSTANCE)&__ImageBase, dll_directory, 1024);
		if (ret)
		{
			WideCharToMultiByte(CP_ACP, 0, dll_directory, -1, _startup_path, 1024, &def_char, NULL);  //convert from wide char to narrow char array
		}
		s = string(_startup_path);
		//string configfile = c_replace(s, "ssdsUExit.dll", "ssdsUExit.cfg");
		string _s = c_replace2(s, "cfg");
		configfile = c_replace(s, "TestApp32.exe", "TestApp32.cfg");
	}
	catch (exception _ex)
	{
	}
	if (!done) {
		try
		{
			char dll_directory[400];
			DWORD ret = GetModuleFileNameA((HINSTANCE)&__ImageBase, dll_directory, 1024);
			s = string(dll_directory);
			//string configfile = c_replace(s, "ssdsUExit.dll", "ssdsUExit.cfg");
			string _s = c_replace2(s, "cfg");
			configfile = c_replace(s, "TestApp32.exe", "TestApp32.cfg");
			done = true;
		}
		catch (exception ex)
		{
			cerr << ex.what();
		}
	}
	return configfile;
}
bool convertToBool(char ch)
{
	return ch == '0' ? false : true;
}
string getFilename(const char* fullpath)
{
	string str = (string)fullpath;
	int lastslash = str.find_last_of("\\");
	str = str.substr(lastslash + 1, str.size());
	return str;
}
string getDirectory(const char* fullpath)
{
	string str = (string)fullpath;
	int lastslash = str.find_last_of("\\");
	str = str.substr(0, lastslash);
	return str;
}
bool hasFileExtension(const char* fullpath)
{
	//string filename = getFilename(fullpath);
	string str = (string)fullpath;
	bool retval = false;
	if (!str.empty() || str != " ")
	{
		unsigned int lastdot = str.find_last_of(".");
		if (lastdot > 0 && lastdot < str.size())
			retval = true;
		else retval = false;
	}
	return retval;
}
string readFile(char* file)
{
	ifstream iFile;
	string line, _line;
	try
	{
		ifstream iFile(file);
		if (iFile.is_open())
		{
			getline(iFile, _line);
		}
		//line = _line;
		iFile.close();
	}
	catch (exception ex) {}
	return _line;
}
string trim(const char* _str, char* whitespace = " \t")
{
	string str = (string)_str;
	const int strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const int strEnd = str.find_last_not_of(whitespace);
	const int strRange = strEnd - strBegin + 1;
	str = str.substr(strBegin, strRange);
	return str;
}
bool end_with(char* _str, char lastChar)
{
	string str = (string)_str;
	int len = str.size() - 1; //strlen(str.c_str());
	int a = str.find_last_of(lastChar);
	if (a == len)
		return true;
	else return false;
}
void manageActuatingSignal(char _log[], char* directory, char* filename)
{
	ofstream lfile; string _fname(filename);
	try
	{
		char  _path[500]; char c_log[500]; string _dir;
		string dir = trim(directory, " ");
		if (hasFileExtension(dir.c_str()))
		{
			_dir = getDirectory(dir.c_str());  //get directory 
			_fname = getFilename(dir.c_str()); //get filename
		}
		else { _dir = dir; }

		int status = _mkdir(_dir.c_str());

		if (CreateDirectoryA(dir.c_str(), NULL) || ERROR_ALREADY_EXISTS == GetLastError())
		{
			std::strcpy(_path, _dir.c_str());
			if (!end_with(_path, '\\'))
				strcat(_path, "\\");
			strcat(_path, _fname.c_str());

			std::strcpy(c_log, _log);
			strcat(c_log, "\r");

			lfile.open(_path, ios::out);
			lfile.write(c_log, strlen(c_log));
			lfile.close();
		}
	}
	catch (exception ex)
	{
		if (!lfile && lfile.is_open())
			lfile.close();
		cerr << ex.what();
	}
}
unsigned short BiometricsExit()
{
	int _nextState = 0;
	try
	{
		char* file = "E:\\ATMBioClient\\CExit_Logs\\exit.log";
		strcpy(actuatingFile, file);

		//create an actuating signal for bioScanner

		string status("start");
		//start the bio-scanner
		manageActuatingSignal("start", actuatingFile, " ");

		while (status == "start")
		{
			status = readFile(actuatingFile);
			string str = trim(status.c_str(), " \r");
			status = str;
			if (status != "start")
			{
				break;
			}

		}
		/*call perform NDC State
		  return good next state if status is valid
		  return bad next state if status is invalid
		*/
		if (status == "valid")
		{
			//fingerprint was validated successfully
			_nextState = 1;
		}
		else
		{
			_nextState = 0;
		}

		//stop the bio-scanner
		manageActuatingSignal("stop", actuatingFile, " ");

	}
	catch (const std::exception& ex)
	{

	}
	return _nextState;
}
string readConfig(std::string key)
{
	string value = ""; ifstream rFile; string line;
	try
	{
		char _configfile[1025];
		c_trim_end(__configfile, ' ');
		if (__configfile.empty())
			//string configfile = getConfigurationFile();
			__configfile = getConfigurationFile();
		if (fileExists(__configfile))
		{
			strcpy(_configfile, __configfile.c_str());
			rFile.open(_configfile, ios::in);
			while (!rFile.eof())
			{
				std::getline(rFile, line);
				string::size_type position = line.find(key);
				if (position == std::string::npos)
					continue;
				value = line.substr(line.find("=") + 1);
				if (!value.empty()) {
					break;
				}
			}
			rFile.close();
		}
		else throw exception("cfg file not found.");
	}
	catch (exception ex)
	{
		if (!rFile && rFile.is_open())
			rFile.close();
		char msg[2000];
		//sprintf(msg, "%s ConfigurationError:: %s ", getDateTime().c_str(), getFilename(__configfile.c_str()).c_str());
		strcat(msg, ex.what());
		//writeLog(msg, logpath, " ");
	}
	return value;
}
bool canUse(const char *filename)
{
	ofstream myfile;
	try {
		ofstream myfile(filename, ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile.close();
			return true;
		}
		return false;
	}
	catch (const std::exception& ex)
	{
		if (!myfile)
			myfile.close();
		return false;
	}
}


long Get()
{
	return 140;
}
unsigned short DoCast()
{
	short a = 0;
	a = static_cast<short>(Get());
	return a;
}
#pragma endregion 


int _tmain(int argc, _TCHAR* argv[])
{
	long goodState = 0;
	long badState = 0;
	long nextstate = 0;
	int n = 0;
	mCduCdiInt *goodNextState = NULL; // good practice to initialize pointer variable to NULL
	mCduCdiInt *badNextState = new mCduCdiInt; // no need for () in C++ when using default contructor
	mCduCdiInt nextState;

	goodNextState = new mCduCdiInt(); // create new Level

	goodNextState->a = 140;
	badNextState->a = 2140;
	nextState.a = 140;

	goodState = goodNextState->a;
	badState = badNextState->a;

	delete goodNextState; // and remember to delete the objects we new-ed
	delete badNextState; // (the danger of forgetting to do this is why you
				  // should use unique_ptr or shared_ptr

	try
	{
		short a = DoCast();
		string file = getConfigurationFile();
		// unsigned int status = BiometricsExit();
		//readFile("C:\\iSuite\\iPolicy\\IntelligentCam\\iBuffer.buf");
		string conf = readConfig("logPath");
		

		/*Get configuration settings*/
		strcpy_s(logpath, sizeof(logpath), readConfig("logPath").c_str());
		strcpy_s(intelligentCamStore, sizeof(intelligentCamStore), readConfig("intelliCamStore").c_str());
		strcpy_s(triggerAlert, sizeof(triggerAlert), readConfig("alertStore").c_str());
		strcpy_s(monitorCamera, sizeof(monitorCamera), readConfig("monitorCam").c_str());

		writeLog("Enter AANDC exit for Intelligent camera.", logpath);
		writeLog("AANDC Exit call initialized.", logpath);

		bool terminate = false;
		if (fileExists(intelligentCamStore))
		{
			string  _status = readFile(intelligentCamStore);
			string trimmedStat = trim(_status.c_str());
			char ch = trimmedStat[strlen(trimmedStat.c_str()) - 1];
			terminate = convertToBool(ch);
			writeBuffer(trimmedStat, triggerAlert);  //send camera status to IntelligentCAM.exe via exitAlert.xit
			writeLog("exitAlert.xit updated for email alert.", logpath);
		}
		else
		{
			terminate = true;
		}
		char terminated[60];
		int ret = sprintf(terminated, "Card Ejected = %s", terminate ? "true" : "false");
		writeLog(terminated, logpath);
		if (terminate)   //camera blocked or it not is capturing 
		{
			nextstate = badState;
		}
		else
		{
			nextstate = goodState;  //camera not blocked and it is capturing 
		}
		unsigned short next_state = static_cast<short>(nextstate);

		char buff[60];
		ret = sprintf_s(buff, sizeof(buff), "Good Next State = %d; Bad Next State = %d", goodState, badState);

		writeLog(buff, conf);

		writeLog(buff, logpath);

		string monitorCam = (string)monitorCamera;
		c_tolower(monitorCam);

		if (monitorCam == "true")
		{
			//defaulted to non-capturing mode
			int a = 3;
			int b = a + 4;
		}
		getch();
	}

	catch (const std::exception& ex)
	{
		cerr << ex.what();
	}
	catch (const std::runtime_error& ex)
	{
		cerr << ex.what();
	}
	catch (...) {


	}
	return 0;
}
void writeLog(string log, string filepath)
{
	ofstream __file;
	try
	{
		char _log[200];	string _dir;
		string dir = trim(filepath.c_str(), " ");
		if (hasFileExtension(dir.c_str()))
		{
			_dir = getDirectory(dir.c_str()); //get directory 
		}
		int status = _mkdir(_dir.c_str());

		string log_date = getDate();
		int dot = filepath.find_last_of(".");
		filepath.insert(dot, log_date);

		sprintf_s(_log, sizeof(_log), "%s", getDateTime().c_str());
		strcat_s(_log, sizeof(_log), log.c_str());

		strcat(_log, "\r");

		bool _can_use = canUse(filepath.c_str());
		int count = 5;
		while (!_can_use)
		{
			_can_use = canUse(filepath.c_str());
			if (count == 0)
				break;
			count--;
		}
		__file.open(filepath.c_str(), ios::out | ios::app);
		__file.write(_log, strlen(_log));
		__file.close();
	}
	catch (exception ex)
	{
		if (!__file && __file.is_open())
			__file.close();
		cerr << ex.what();
	}
}
void writeBuffer(string log, string filepath)
{
	ofstream __file;
	try
	{
		char _log[200]; string _dir;

		string dir = trim(filepath.c_str(), " ");
		if (hasFileExtension(dir.c_str()))
		{
			_dir = getDirectory(dir.c_str()); //get directory 
		}
		int status = _mkdir(_dir.c_str());
		/*string log_date = getDate();
		int dot = filepath.find_last_of(".");
		filepath.insert(dot, log_date);*/

		//sprintf_s(_log, sizeof(_log), "%s", getDateTime().c_str());
		strcpy_s(_log, sizeof(_log), log.c_str());
		strcat(_log, "\r");

		bool _can_use = canUse(filepath.c_str());
		int count = 5;
		while (!_can_use)
		{
			_can_use = canUse(filepath.c_str());
			if (count == 0)
				break;
			count--;
		}

		__file.open(filepath.c_str(), ios::out);
		__file.write(_log, strlen(_log));
		__file.close();
	}
	catch (exception ex)
	{
		if (!__file && __file.is_open())
			__file.close();
		cerr << ex.what();
	}
}

void writeLog(char _log[], char* directory, char* filename)
{
	ofstream lfile; string _fname(filename);
	try
	{
		char  _path[500]; char c_log[500]; string _dir;
		string dir = trim(directory, " ");
		if (hasFileExtension(dir.c_str()))
		{
			_dir = getDirectory(dir.c_str()); //get directory 
			_fname = getFilename(dir.c_str()); //get filename
		}
		else { _dir = dir; }

		int status = _mkdir(_dir.c_str());
		std::strcpy(_path, _dir.c_str());
		//alter filename 
		string log_date = getDate();
		int dot = _fname.find_last_of(".");
		_fname.insert(dot, log_date);
		if (!end_with(_path, '\\'))
			strcat(_path, "\\");
		strcat(_path, _fname.c_str());
		sprintf(c_log, "%s", getDateTime().c_str());
		strcat(c_log, _log);
		//std::strcpy(c_log, _log);
		strcat(c_log, "\r\n");

		lfile.open(_path, ios::out | ios::app);
		lfile.write(c_log, strlen(c_log));
		lfile.close();
	}
	catch (exception ex)
	{
		if (!lfile && lfile.is_open())
			lfile.close();
		cerr << ex.what();
	}
}
void writeBuffer(char _log[], char* directory, char* filename)
{
	ofstream lfile; string _fname(filename);
	try
	{
		char  _path[500]; char c_log[500]; string _dir;
		string dir = trim(directory, " ");
		if (hasFileExtension(dir.c_str()))
		{
			_dir = getDirectory(dir.c_str()); //get directory 
			_fname = getFilename(dir.c_str()); //get filename
		}
		else { _dir = dir; }

		int status = _mkdir(_dir.c_str());
		std::strcpy(_path, _dir.c_str());
		if (!end_with(_path, '\\'))
			strcat(_path, "\\");
		strcat(_path, _fname.c_str());

		std::strcpy(c_log, _log);
		strcat(c_log, "\r");
		bool _canuse = canUse(_path);
		int count = 5;
		while (!_canuse)
		{
			_canuse = canUse(_path);
			if (count == 0)
				break;
			count--;
		}
		lfile.open(_path, ios::out);
		lfile.write(c_log, strlen(c_log));
		lfile.close();
	}
	catch (exception ex)
	{
		if (!lfile && lfile.is_open())
			lfile.close();
		cerr << ex.what();
	}
}
void ReadConfig(std::string key)
{
	char cd[128];
	char *abc;
	abc = getcwd(cd, sizeof(cd));

	bool alive = false;

	char* file = "C:\\AtmOneClients\AtmOneIntelligent\\ssdsUExit.cfg";
	if (access(file, 0 | 4) != -1) {
		// file exists
		alive = true;
	}

	if (alive)
	{
		int a = 2 * 4;
	}
	string tempstring = "";
	ifstream myFile;
	string line;
	myFile.open(file, ios::in);
	//	char* str;

	while (!myFile.eof())
	{
		string value = "";
		std::getline(myFile, line);
		string::size_type position = line.find(key);
		if (position == std::string::npos)
			continue;
		value = line.substr(line.find("=") + 1);
		if (!value.empty()) {
			break;
		}
	}

	//return str;

	while (std::getline(myFile, line))
	{
		// tempstring = line.;
		// std::string key;
		// if(std::getline(line, key) )
		// {
		   //std::string value;
		   ////if( std::getline(is_line, value) ) 
		   //  //store_line(key, value);
		// }
	}
	myFile.close();
}
