#include "StdAfx.h"
#include "IniFile.h"
#pragma warning(disable:4996)

CIniFile::CIniFile(void)
{
}


CIniFile::~CIniFile(void)
{
}
// дINI�ļ��@
void CIniFile::WriteIniFile(const TCHAR* lpSection,const TCHAR* lpKey,const TCHAR* lpValue)
{
	static TCHAR szPath[MAX_PATH];
	memset(szPath,0x00,sizeof(szPath));
	_stprintf(szPath,TEXT("%s%s"),GetCurrentApPath(),INIFILELPATH);
	WritePrivateProfileString(lpSection,lpKey,lpValue,szPath);
}

// ��INI�ļ��������ַ���
CString CIniFile::GetIniFileString(const TCHAR* lpSection,const TCHAR* lpKey)
{
	static TCHAR szPath[MAX_PATH];
	memset(szPath,0x00,sizeof(szPath));
	_stprintf(szPath,TEXT("%s%s"),GetCurrentApPath(),INIFILELPATH);

	CString szValue;
	DWORD dwSize = 1000;
	GetPrivateProfileString(lpSection,lpKey,TEXT(""),
		szValue.GetBuffer(dwSize),dwSize,szPath);
	
	szValue.ReleaseBuffer();
	szValue.Replace(TEXT("\\n"),TEXT("\n"));	
	return szValue;
}

// ��INI�ļ�,����INT
int CIniFile::GetIniFileInt(const TCHAR* lpSection,const TCHAR* lpKey)
{
	static TCHAR szPath[MAX_PATH];
	memset(szPath,0x00,sizeof(szPath));
	_stprintf(szPath,TEXT("%s%s"),GetCurrentApPath(),INIFILELPATH);
	CString str = szPath;
	return GetPrivateProfileInt(lpSection,lpKey,0,szPath);
}

// ������INI�ļ�·��
CString  CIniFile::GetCurrentApPath()
{
	TCHAR szCurDir[MAX_PATH];
	memset(szCurDir,0x00,sizeof(szCurDir));
	GetCurrentDirectory(MAX_PATH,szCurDir);
	CString strPath_temp;
	strPath_temp = szCurDir;
	strPath_temp += _T("\\");
	
	return strPath_temp;
}