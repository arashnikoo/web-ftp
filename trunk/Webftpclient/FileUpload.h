#include "stdafx.h"

#pragma once
class FileUpload
{
public:
	FileUpload(void);
	~FileUpload(void);
	static MemoryStruct Upload(const char* url, const char* filePath);
private:
	static void *newrealloc(void *, size_t);
	static size_t WriteMemoryCallback(void *, size_t, size_t , void *);
};

