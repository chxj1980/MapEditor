#pragma once

#define    INIFILELPATH				TEXT("setting.ini") //�����ļ�·��

class CIniFile
{
public:
	CIniFile(void);
	~CIniFile(void);
	
	// дINI�ļ��@
	static void WriteIniFile(const TCHAR* lpSection,const TCHAR* lpKey,const TCHAR* lpValue);	
	// ��INI�ļ�,����INT
	static int  GetIniFileInt(const TCHAR* lpSection,const TCHAR* lpKey);	
	// ��INI�ļ��������ַ���
	static CString GetIniFileString(const TCHAR* lpSection,const TCHAR* lpKey);	
	// ������INI�ļ�·��
	static CString GetCurrentApPath();	
};

