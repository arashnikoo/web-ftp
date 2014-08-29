#include "StringUtil.h"

StringUtil::StringUtil(void)
{

}


StringUtil::~StringUtil(void)
{

}

vector<string> StringUtil::split(const string &s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

vector<string> &StringUtil::split(const string &s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
	{
        elems.push_back(item);
    }

    return elems;
}

char * StringUtil::StringToCharPt(string value)
{
	char* cString = new char [value.length() + 1];
	strcpy(cString, value.c_str());

	return cString;
}

bool StringUtil::Replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}