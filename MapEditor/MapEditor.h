
// MapEditor.h : MapEditor Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "ResManager.h"

// CMapEditorApp:
// �йش����ʵ�֣������ MapEditor.cpp
//

class CMapEditorApp : public CWinAppEx
{
public:
	CMapEditorApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;
	//��Դ������
	CResManager m_ResMgr;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMapEditorApp theApp;
