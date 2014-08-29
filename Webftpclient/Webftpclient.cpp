	// Webftpclient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Webftpclient.h"
#include "StringUtil.h"
#include "PathUtil.h"
#include "FileUpload.h"
#include "Util.h"

string url;	
string username;
string password;
string filePattern;
string folder;

bool silentMode = false;

int main(int argc, TCHAR * argv[])
{	
	TCHAR pwd[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,pwd);
	vector<string> filesList;
	vector<MemoryStruct> responseList;
	bool success = setupvars(argc,argv);
	
	if (success)
	{
		url  = url + "?username=" + username + "&password=" + password + "&subfolder=" + folder;
		string absFilePath = PathUtil::FullPath(filePattern.c_str()).c_str();		
		
		string targetDir = PathUtil::GetPath(absFilePath.c_str());

		filePattern = absFilePath;

		StringUtil::Replace(filePattern,targetDir,"");
		CUtil::GetFileList(targetDir,filePattern,false,filesList);

		if (filesList.size()<1)
		{
			cout<<"No files to upload."<<endl;
			return 1;
		}

		for(int i=0; i<filesList.size();i++)
		{
			const char* thisFile = filesList.at(i).c_str();
			
			MemoryStruct response = FileUpload::Upload(
				url.c_str(),
				thisFile
				);

			responseList.push_back(response);
			cout << response.memory <<endl;						
		}
		
		return 0;

	}else{

		cout<< "Invalid paramter(s)!"<<endl<<endl;
		showhelp();
		return 1;
	}
}

bool setupvars(int length, TCHAR * values[])
{
	if (length <5)
		return false;
	try
	{
		url = values[1];

		for(int i=2 ; i < length; i++)
		{
			string thisParam = values[i];
			string key = thisParam.substr(0,2);
			string value;

			int sublength = thisParam.length()-3;
			
			if (sublength > 0 )
			{
				value = thisParam.substr(3,thisParam.length()-3);
			}			

			if (key=="-U" || key =="-u")
			{
				username = value;

			}else if(key=="-P" || key =="-p")
			{
				password = value;

			}else if (key=="-F" || key =="-f")
			{
				filePattern = value;

			}else if(key=="-D" || key =="-d")
			{
				folder = value;

			}else if (key=="-S" || key =="-s")
			{
				silentMode = true;
			}
		}

		if (&url && &username && &password && &filePattern)
		{
			return true;
		}else{

			return false;
		}

	}catch(exception& ex)
	{
		cout<<"Error parsing input"<<endl;		
		return false;
	}
}

void showhelp ()
{
	cout << "webtpclient [url] [-U:username] [-P:password] [-F:file(s)] [-D:folder] [-s]\r\n" <<endl;
	cout << " -S     Suppresses output (Optional)"<<endl;
	cout << " -F:    Specify destination sub-folder name (Optional) \r\n"<<endl;
	cout << "Usage:\t WebFtpClient http://127.0.0.1 -u:myuser -p:mypass -f:abc.csv"<<endl;
	cout << "\t WebFtpClient http://127.0.0.1 -u:myuser -p:mypass -f:myfile.csv -s"<<endl;
	cout << "\t WebFtpClient http://127.0.0.1 -u:myuser -u:mypass -f:*.txt -d:mySubFolder -S"<<endl;
	cout << "\r\n"<<endl;
}