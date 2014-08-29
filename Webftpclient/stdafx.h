// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#define CURL_STATICLIB

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>



#ifndef UNICODE  
  typedef std::string String; 
  
#else
  typedef std::wstring String; 
#endif

using namespace std;

struct MemoryStruct
{
	char *memory;
	size_t size;
};


// TODO: reference additional headers your program requires here
