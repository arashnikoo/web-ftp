#pragma once

class PathUtil
{
public:
	PathUtil(void);
	~PathUtil(void);
	static string GetPath(const char*);
	static bool FileExists(const char*);
	static string FullPath(const char* partialPath );	
};

