#pragma once
#include <vector>
using std::vector;
//#include "ThumbDlg.h"
#include "ThumbWnd.h"


class CSceneToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class CTileThumbDlg:public CThumbWnd
{
protected:
	DECLARE_MESSAGE_MAP()
	void OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult);
};

class CObjThumbDlg:public CThumbWnd
{
protected:
	DECLARE_MESSAGE_MAP()
	void OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult);
};

class CSpriteThumbDlg:public CThumbWnd
{
protected:
	DECLARE_MESSAGE_MAP()
	void OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult);
};
//������Դͣ�����
class CSceneResWnd : public CDockablePane
{
	DECLARE_DYNAMIC(CSceneResWnd)

public:
	CSceneResWnd();
	virtual ~CSceneResWnd();
	//��Ӧ����
	void AdjustLayout();

protected:
	//ѡ��ؼ�
	CMFCTabCtrl	m_wndTabs;
	//��ש����ͼ�Ӵ���
	CTileThumbDlg	m_TileDlg;
	//��������ͼ�Ӵ���
	CObjThumbDlg	m_ObjectDlg;
	//��������ͼ�Ӵ���
	CSpriteThumbDlg	m_SpriteDlg;

public:

	//���ص�ѡ�д�שͼƬ���
	int		GetCurSelTileIndex(){ return m_TileDlg.GetCurSelResID(); }
	//���ص�ǰѡ�е�����ͼƬ���
	int		GetCurSelObjectIndex(){ return m_ObjectDlg.GetCurSelResID(); }
	//���ص�ǰѡ�еĶ�����
	int		GetCurSelSpriteIndex(){ return m_SpriteDlg.GetCurSelResID(); }
	//���ص�ǰѡ��ѡ�����
	int		GetCurSetTab(){ return m_wndTabs.GetActiveTab(); }
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);



};


