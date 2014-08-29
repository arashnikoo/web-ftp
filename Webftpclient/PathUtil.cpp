#include "stdafx.h"
#include "PathUtil.h"
#include "StringUtil.h"
#include <direct.h>

PathUtil::PathUtil(void)
{

}


PathUtil::~PathUtil(void)
{

}

string PathUtil::GetPath(const char* filePath)
{	
	string returnValue = "";
	vector<string> tokens;	
	tokens = StringUtil::split (filePath,'\\');	
	
	for( int t=0 ; t < (tokens.size()-1) ; ++t)
	{
		returnValue=returnValue+tokens.at(t)+"\\";
    }
    
	return returnValue;
}

bool PathUtil::FileExists(const char* path)
{
	if (FILE *file = fopen(path, "r"))
	{
        fclose(file);
        return true;
    } 
	else
	{
        return false;
    }
}

string PathUtil::FullPath(const TCHAR * partialPath )
{
   char full[_MAX_PATH];
   _fullpath( full, partialPath, _MAX_PATH );
   return string(full);
}