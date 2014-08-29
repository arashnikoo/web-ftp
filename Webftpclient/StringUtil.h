#include "stdafx.h"
#include "Util.h"

#pragma once
class StringUtil
{
	public:
		StringUtil(void);
		~StringUtil(void);
		static vector<string> split(const string &, char );
		static vector<string> &split(const string &, char, vector<string> &);
		static char* StringToCharPt(string);
		static bool Replace(string& str, const string& from, const string& to);
   
};


