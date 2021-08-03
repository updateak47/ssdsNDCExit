// SSDSUEXIT.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "exitState.h"
#include <dos.h>
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <sstream>
//#include <Afxdll_.h>


EXTERN_C IMAGE_DOS_HEADER __ImageBase;
using namespace std;
typedef HRESULT(STDAPICALLTYPE* FuncDllRegisterServer)();

#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1

char logpath[MAX_PATH], intelligentCamStore[MAX_PATH], stateflowPath[MAX_PATH], actuatingFile[MAX_PATH], triggerAlert[MAX_PATH];
char monitorCamera[10];

string __configfile = " ";

#pragma region working_tools

void c_tolower(basic_string<char>& s) {
	for (basic_string<char>::iterator p = s.begin();
		p != s.end(); ++p) {
		*p = tolower(*p);
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
bool end_with(char* _str, char lastChar)
{
	string str = (string)_str;
	int len = str.size() - 1; //strlen(str.c_str());
	int a = str.find_last_of(lastChar);
	if (a == len)
		return true;
	else return false;
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
void c_remove(string& str, char object)
{
	str.erase(std::remove(str.begin(), str.end(), object), str.end()); //defined algorithm.h
}
void c_trim_end(string& str, char trimChar)
{
	int a = str.find_last_of(trimChar);
	if (a == str.size() - 1)
		str = str.substr(0, str.size() - 1);
	//str.erase(str.size()-1)
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
wchar_t* c_convertToWS(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t buf[400];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, 400);
	//s = (string)buf;
	return buf;
}
void deleteFile(char* file)
{
	try
	{
		string dir = trim(file, " ");
		string _dir, _fname; char _path[200];
		if (hasFileExtension(dir.c_str()))
		{
			_dir = getDirectory(dir.c_str());  //get directory 
			_fname = getFilename(dir.c_str()); //get filename
		}
		else { _dir = dir; }
		std::strcpy(_path, _dir.c_str());
		//alter filename 
		string log_date = getDate();
		int dot = _fname.find_last_of(".");
		_fname.insert(dot, log_date);
		if (!end_with(_path, '\\'))
			strcat(_path, "\\");
		strcat(_path, _fname.c_str());
		std::remove(_path);
	}
	catch (const std::exception& ex)
	{
	}
}
#pragma endregion 

SSDSUEXIT_API unsigned short intelliCamExit(unsigned char StateType)
{
	long _nextState = 0;
	try
	{
		/*Define and declare*/
		mCduCdiInt *goodNextState = NULL;
		mCduCdiInt *badNextState = NULL;
		bool terminate = false; int ret = 0; char terminated[40];

		/*Get configuration settings*/
		strcpy_s(logpath, sizeof(logpath), readConfig("logPath").c_str());
		strcpy_s(intelligentCamStore, sizeof(intelligentCamStore), readConfig("intelliCamStore").c_str());
		strcpy_s(triggerAlert, sizeof(triggerAlert), readConfig("alertStore").c_str());
		strcpy_s(stateflowPath, sizeof(stateflowPath), readConfig("stateFlowPath").c_str());
		strcpy_s(monitorCamera, sizeof(monitorCamera), readConfig("monitorCam").c_str());

		Sleep(3500);

		//delete stateflowPath for a new entry
		deleteFile(stateflowPath);

		writeLog("AANDC Exit for Intelligent Camera.", stateflowPath);

		//mCduCdiInt goodNextState(idStateData1);

		goodNextState = new mCduCdiInt(idStateData1);
		badNextState = new mCduCdiInt(idStateData2);

		long goodState = goodNextState->Get();
		long badState = badNextState->Get();

		delete goodNextState;
		delete badNextState;

		writeLog("AANDC Exit call initialized.", stateflowPath);

		char buff[60];
		ret = sprintf_s(buff, sizeof(buff), "Good Next State = %d; Bad Next State = %d", goodState, badState);
		writeLog(buff, stateflowPath);

		/* call the iBuffer.buf created by Intelligent Camera Application
		*  to check if the camera was blocked during iCam capture  */
		//check if the iBuffer.buf exits 
		if (fileExists(intelligentCamStore))
		{
			string  _status = readFile(intelligentCamStore);
			string trimmedStat = trim(_status.c_str());
			char ch = trimmedStat[strlen(trimmedStat.c_str()) - 1];
			terminate = convertToBool(ch);
			writeBuffer(trimmedStat, triggerAlert);  //send camera status to IntelligentCAM.exe via exitAlert.xit
			writeLog("exitAlert.xit updated for email alert.", stateflowPath);
		}
		else
		{
			writeLog("iBuffer.buff does not exist.", stateflowPath);
			terminate = true;
		}
		ret = sprintf(terminated, "Card ejected = %s", terminate ? "true" : "false");
		writeLog(terminated, stateflowPath);
		if (terminate)   //camera blocked or it not is capturing 
		{
			_nextState = badState;
		}
		else
		{
			_nextState = goodState;  //camera not blocked and it is capturing 
		}

		unsigned short next_state = static_cast<short>(_nextState);

		char _bff[60];
		ret = sprintf_s(_bff, sizeof(_bff), "Current Next State (converted) = %d", next_state);
		writeLog(_bff, stateflowPath);

		//update intelligentCamStore
		string monitorCam = (string)monitorCamera;
		c_tolower(monitorCam);

		if (monitorCam == "true")
		{
			writeBuffer("IntelligentCAM=2", intelligentCamStore); //defaulted to non-capturing mode
		}
		else
			writeBuffer("IntelligentCAM=0", intelligentCamStore); //defaulted to capturing mode
	}
	catch (const std::exception& ex)
	{
		char msg[2000];
		sprintf(msg, "%sIntelliCamError::", "");
		strcat(msg, ex.what());
		writeLog(msg, logpath, " ");
	}

	catch (const std::runtime_error& ex)
	{
		char msg[2000];
		sprintf(msg, "%sIntelliCamError::", "");
		strcat(msg, ex.what());
		writeLog(msg, logpath, " ");
	}
	catch (...)
	{
		char msg[2000];
		sprintf(msg, "%s[IntelliCamError]::", "");
		writeLog(msg, logpath, " ");
	}

	return static_cast<short>(_nextState);

}
SSDSUEXIT_API unsigned short biometricsExit(unsigned char StateType)
{
	int _nextState = 0;
	try
	{
		//get configuration path
		strcpy(logpath, readConfig("logPath").c_str());
		strcpy(stateflowPath, readConfig("stateFlowPath").c_str());
		strcpy(actuatingFile, readConfig("actuatingfile").c_str());
		/*string _log(logpath);
		if (_log.empty())
			strcpy(logpath, "C:\\iPolicy\\ATMIdentifier\\Logs\\exit.log");*/
		Sleep(500);

		deleteFile(stateflowPath);
		writeLog("Enter exit call for AtmIdentifier", stateflowPath, " ");

		/* define states */
		mCduCdiInt templateID(idStateData0);
		mCduCdiInt goodNextState(idStateData1);
		mCduCdiInt badNextState(idStateData2);

		int terminate = false;

		int templateData = 0;
		char buff[60];
		int ret = 0;
		ret = sprintf(buff, "Good Next State = %d; Bad Next State = %d", goodNextState.Get(), badNextState.Get());
		writeLog(buff, stateflowPath, " ");

		_nextState = (int)badNextState.Get();

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
			_nextState = (int)goodNextState.Get();
		}
		else
		{
			_nextState = (int)badNextState.Get();
		}

		//stop the bio-scanner
		manageActuatingSignal("stop", actuatingFile, " ");

		char bff[60];
		ret = sprintf(bff, "Current Next State = %d", _nextState);
		writeLog(bff, stateflowPath, " ");
	}
	catch (const std::exception& ex)
	{
		/*std::cout<<ex.what();
		cerr<<ex.what();*/
		char msg[2000];
		//getDateTime().c_str()
		sprintf(msg, "%sBioExitError::", "");
		strcat(msg, ex.what());
		writeLog(msg, logpath, " ");
	}
	return _nextState;
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
		else { _dir = dir; }  //if it doesnt have file extension 

		int status = _mkdir(_dir.c_str());

		std::strcpy(_path, _dir.c_str());

		//alter by appending the date to the filename
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
	ofstream _file; string _fname(filename);
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
		strcat(c_log, "\r\n");

		bool _canuse = canUse(_path);
		int count = 5;
		while (!_canuse)
		{
			_canuse = canUse(_path);
			if (count == 0)
				break;
			count--;
		}
		_file.open(_path, ios::out);
		_file.write(c_log, strlen(c_log));
		_file.close();
	}
	catch (exception ex)
	{
		if (!_file && _file.is_open())
			_file.close();
		//cerr << ex.what();
		char msg[2000];
		sprintf(msg, "%s ReadError:: %s", getDateTime().c_str(), _fname.c_str());
		strcat(msg, ex.what());
		writeLog(msg, logpath, " ");
	}
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

#pragma ,region working_tools2
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
bool convertToBool(char ch)
{
	return ch == '0' ? false : true;
}
string readFile(char* file)
{
	ifstream iFile; string line;
	try
	{
		ifstream iFile(file);
		if (iFile.is_open())
		{
			getline(iFile, line);
		}
		else {
			throw exception("file not found or access denied.");
		}
		iFile.close();
	}
	catch (const std::exception& ex)
	{
		if (!iFile && iFile.is_open())
			iFile.close();
		char msg[2000];

		sprintf(msg, "%s ReadError:: %s", getDateTime().c_str(), file);
		strcat(msg, ex.what());
		writeLog(msg, logpath, NULL);
	}
	return line;
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

		sprintf(msg, "%s ReadError:: %s", getDateTime().c_str(), file);
		strcat(msg, ex.what());
		writeLog(msg, logpath, NULL);
	}
	return str;
}
ifstream::pos_type filesize(const char* filename)
{
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
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
	catch (const std::exception& ex)
	{
		if (!rFile && rFile.is_open())
			rFile.close();
		char msg[2000];
		sprintf(msg, "%s ConfigurationError:: %s ", getDateTime().c_str(), getFilename(__configfile.c_str()).c_str());
		strcat(msg, ex.what());
		writeLog(msg, logpath, " ");
	}
	return value;
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
		sprintf(msg, "%s getConfigurationFile()::", getDateTime().c_str());
		strcat(msg, ex.what());
		writeLog(msg, logpath, " ");
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
			sprintf(msg, "%s getConfigurationFile()::", getDateTime().c_str());
			strcat(msg, _ex.what());
			writeLog(msg, logpath, " ");
		}
	}
	string _s = c_replace2(s, "cfg");

	sprintf(cfg, "DLL File Path = %s", s.c_str());
	writeLog(cfg, logpath, " ");
	sprintf(cfg, "CFG File Path = %s", _s.c_str());
	writeLog(cfg, logpath, " ");
	return configfile = _s;
}
#pragma endregion 

CSSDSUEXIT::CSSDSUEXIT(void)
{
}
