// SceneWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MapEditor.h"
#include "SceneResWnd.h"
#include "MapEditorDoc.h"
#include "MainFrm.h"
#define IDC_TABCTRL			11

// CSceneResWnd

IMPLEMENT_DYNAMIC(CSceneResWnd, CDockablePane)

CSceneResWnd::CSceneResWnd()
{

}

CSceneResWnd::~CSceneResWnd()
{
}


BEGIN_MESSAGE_MAP(CSceneResWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()

END_MESSAGE_MAP()



// CSceneResWnd ��Ϣ�������


int CSceneResWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// ����ѡ�����:
	if (!m_wndTabs.Create(CMFCTabCtrl::STYLE_3D_ONENOTE , rectDummy, this, 11))
	{
		TRACE0("δ�ܴ���ѡ�����\n");
		return -1;      // δ�ܴ���
	}
	//������ש����ͼ���
	m_TileDlg.Create(NULL,_T(""),WS_VISIBLE | WS_CLIPCHILDREN, rectDummy, &m_wndTabs,12);//.Create(IDD_THUMBDLG,&m_wndTabs);
	m_TileDlg.CreateThumbList(theApp.m_ResMgr.GetTileRes(),64,32);
	
	//����������������ͼ���
	m_ObjectDlg.Create(NULL,_T(""),WS_VISIBLE | WS_CLIPCHILDREN, rectDummy, &m_wndTabs,13);
	m_ObjectDlg.CreateThumbList(theApp.m_ResMgr.GetObjRes());
	//�������
	m_SpriteDlg.Create(NULL,_T(""),WS_VISIBLE | WS_CLIPCHILDREN, rectDummy, &m_wndTabs,14);
	m_SpriteDlg.CreateThumbList(theApp.m_ResMgr.m_SpriteThumb);


	//NPC���
//	m_NpcDlg.Create(IDD_THUMBDLG,&m_wndTabs);
//	m_NpcDlg.CreateThumbList(theApp.m_ResMgr.GetNpcSet());
	// ����ש����ͼ���ڸ��ӵ�ѡ�:
	m_wndTabs.AddTab(&m_TileDlg, _T("����"), (UINT)0, FALSE);
	// ��������������ͼ���ڸ��ӵ�ѡ�:
	m_wndTabs.AddTab(&m_ObjectDlg, _T("����"), (UINT)1,FALSE);

	m_wndTabs.AddTab(&m_SpriteDlg, _T("����"), (UINT)2,FALSE);
	
	//m_wndTabs.AddTab(&m_NpcDlg,_T("NPC"), (UINT)3, FALSE);

	AdjustLayout();
	
	return 0;
}


void CSceneResWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	AdjustLayout();
}

void CSceneResWnd::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	m_wndTabs.SetWindowPos (this, -1, -1, rectClient.Width(), rectClient.Height(), SWP_NOMOVE | SWP_NOZORDER);

}



BEGIN_MESSAGE_MAP(CTileThumbDlg, CThumbWnd)
	ON_NOTIFY(NM_CLICK,IDC_THUMBLIST,OnSelectListItem)
END_MESSAGE_MAP()

void CTileThumbDlg::OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMapEditorDoc* pDoc = (CMapEditorDoc*)pFrame->GetActiveDocument();
	m_iCurSelItem = pNMLV->iItem;
	if(m_iCurSelItem!=-1&&!::IsEmpty())
	{
		pDoc->OnLayerTile();
		pDoc->m_CurSelObj = m_iCurSelItem;

	}

	*pResult = 0;
}

BEGIN_MESSAGE_MAP(CObjThumbDlg, CThumbWnd)
	ON_NOTIFY(NM_CLICK,IDC_THUMBLIST,OnSelectListItem)
END_MESSAGE_MAP()

void CObjThumbDlg::OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMapEditorDoc* pDoc = (CMapEditorDoc*)pFrame->GetActiveDocument();
	m_iCurSelItem = pNMLV->iItem;
	if(m_iCurSelItem!=-1&&!::IsEmpty())
	{
		pDoc->OnLayerObject();
		pDoc->m_CurSelObj = m_iCurSelItem;
		
	}

	*pResult = 0;
}

BEGIN_MESSAGE_MAP(CSpriteThumbDlg, CThumbWnd)
	ON_NOTIFY(NM_CLICK,IDC_THUMBLIST,OnSelectListItem)
END_MESSAGE_MAP()

void CSpriteThumbDlg::OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMapEditorDoc* pDoc = (CMapEditorDoc*)pFrame->GetActiveDocument();
	m_iCurSelItem = pNMLV->iItem;
	if(m_iCurSelItem!=-1&&!::IsEmpty())
	{
		pDoc->OnLayerObject();

	}

	*pResult = 0;
}