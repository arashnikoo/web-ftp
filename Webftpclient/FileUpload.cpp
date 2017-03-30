#include "FileUpload.h"
#include "stdafx.h"

FileUpload::FileUpload(void)
{
}


FileUpload::~FileUpload(void)
{
}

MemoryStruct FileUpload::Upload(const char* url, const char* filePath)
{
	struct curl_httppost *formpost=NULL;
	struct curl_httppost *lastptr=NULL;
	struct curl_slist *headerlist=NULL;
	static const char buf[] = "Expect:";

	CURL *curl;
	CURLcode res;
	struct stat file_info;
	struct MemoryStruct chunk; 
	chunk.memory=NULL;
    chunk.size = 0;

	curl_global_init(CURL_GLOBAL_ALL);	
		
	/* Fill in the file upload field */ 
	curl_formadd(&formpost,
				&lastptr,
				CURLFORM_COPYNAME, "sendfile",
				CURLFORM_FILE, filePath,
				CURLFORM_END);

	headerlist = curl_slist_append(headerlist, buf);

	curl = curl_easy_init();
	headerlist = curl_slist_append(headerlist, buf);

	if (curl)
	{		
		curl_easy_setopt(curl, CURLOPT_URL, url);		
		curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);		
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);	
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

		res = curl_easy_perform(curl);		
		
		curl_formfree(formpost);
		curl_slist_free_all (headerlist);
		curl_easy_cleanup(curl);

	}else{

		cout<<"Error loading module."<<endl;
	}

	curl_global_cleanup();

	return chunk;
}

void* FileUpload::newrealloc(void *ptr, size_t size) {
    if(ptr)
        return realloc(ptr, size);
    else
        return malloc(size);
}
 
size_t FileUpload::WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void *data) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)data;
    mem->memory = (char *)newrealloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory) {
        memcpy(&(mem->memory[mem->size]), ptr, realsize);
        mem->size += realsize;
        mem->memory[mem->size] = 0;
    }
    return realsize;
}
