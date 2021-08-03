//
// +--------------------------- Copyright Information ----------------------------+
//
//				(c) Copyright 2010 NCR Financial Solutions Group Limited.
//							Solutions For Services, Dundee
//
// +------------------------------------------------------------------------------+
//

#ifndef NDCCUSTM_H
#define NDCCUSTM_H

//------------------ Includes ----------------------------------

#include "ndccusti.h"

//------------------ Function Protoypes ------------------------

NDCCDU_EXPORT unsigned char NDCCDU_APIENTRY StoreScreen(const char* ScreenData, 
														unsigned long ScreenDataLength);

NDCCDU_EXPORT unsigned char NDCCDU_APIENTRY RetrieveScreen(unsigned short ScreenGroup, 
														   unsigned short ScreenNumber, 
														   char** ScreenData, 
														   unsigned long* ScreenDataLength);

NDCCDU_EXPORT unsigned char NDCCDU_APIENTRY RetrieveKeyboard(unsigned short KeyboardNumber, 
															 char** KeyboardData, 
															 unsigned long* KeyboardDataLength);

NDCCDU_EXPORT void NDCCDU_APIENTRY DisplayScreen(unsigned short ScreenGroup, 
												 unsigned short ScreenNumber, 
												 unsigned short UpdateKeyboard, 
												 unsigned short AllowIdle);

NDCCDU_EXPORT void NDCCDU_APIENTRY StoreScreenUpdateData(const char* ScreenData, 
														 unsigned long ScreenDataLength);

NDCCDU_EXPORT unsigned int NDCCDU_APIENTRY NDCKeyMultipleEntryHooks(const unsigned char keyValue,float mouseX,float mouseY);
#endif // NDCCUSTM_H

