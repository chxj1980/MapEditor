
#include "stdafx.h"

#include "PropertiesWnd.h"
#include "Resource.h"
#include "MainFrm.h"
#include "MapEditor.h"
#include "MapEditorDoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar

CPropertiesWnd::CPropertiesWnd()
{
}

CPropertiesWnd::~CPropertiesWnd()
{
}

BEGIN_MESSAGE_MAP(CPropertiesWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()

	ON_REGISTERED_MESSAGE(AFX_WM_PROPERTY_CHANGED, OnPropertyChanged)
	ON_WM_SETFOCUS()
	ON_WM_SETTINGCHANGE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar ��Ϣ�������
//
//int CPropertiesWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	CRect rectDummy;
//	rectDummy.SetRectEmpty();
//
//	//������������
//	if (!m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2))
//	{
//		TRACE0("δ�ܴ�����������\n");
//		return -1;      // δ�ܴ���
//	}
//
//	InitPropList();
//	
//	AdjustLayout();
//	return 0;
//}
//
//void CPropertiesWnd::OnSize(UINT nType, int cx, int cy)
//{
//	CDockablePane::OnSize(nType, cx, cy);
//	AdjustLayout();
//}
//void CPropertiesWnd::AdjustLayout()
//{
//	if (GetSafeHwnd() == NULL)
//	{
//		return;
//	}
//
//	CRect rectClient;
//	GetClientRect(rectClient);
//
//	m_wndPropList.SetWindowPos(NULL, rectClient.left, rectClient.top , rectClient.Width(), rectClient.Height() , SWP_NOACTIVATE | SWP_NOZORDER);
//}
//
//
//
//void CPropertiesWnd::InitPropList()
//{
//	SetPropListFont();
//
//	m_wndPropList.EnableHeaderCtrl(FALSE);
//	m_wndPropList.EnableDescriptionArea();
//	m_wndPropList.SetVSDotNetLook();
//	m_wndPropList.MarkModifiedProperties();
//
//	
//	//��ͼ������
//	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("��ͼ����"));
//	//��ͼ��͸�Ϊֻ�����ԣ��ڴ�����ͼʱָ����֮�󲻿ɸ���
//	CMFCPropertyGridProperty* pProp = new CMFCPropertyGridProperty(_T("��ͼ���"), (_variant_t)0, _T("��ͼ����Ԫ�����"));
//	pProp->AllowEdit(FALSE);
//	pGroup1->AddSubItem(pProp);
//
//	pProp = new CMFCPropertyGridProperty( _T("��ͼ�߶�"), (_variant_t)0, _T("��ͼ����Ԫ�����"));
//	pProp->AllowEdit(FALSE);
//	pGroup1->AddSubItem(pProp);
//
//	pProp = new CMFCPropertyGridProperty(_T("ͼ����"), (_variant_t)0, _T("��Ԫ��ͼ��Ŀ��"));
//	pProp->AllowEdit(FALSE);
//	pGroup1->AddSubItem(pProp);
//	pProp = new CMFCPropertyGridProperty(_T("ͼ��߶�"), (_variant_t)0, _T("��Ԫ��ͼ��ĸ߶�"));
//	pProp->AllowEdit(FALSE);
//	pGroup1->AddSubItem(pProp);
//
//	//��ӵ�ͼ��Ϣ������
//	m_wndPropList.AddProperty(pGroup1);
//	
//	//ͼ��������
//	CMFCPropertyGridProperty* pGroup2 = new CMFCPropertyGridProperty(_T("ͼ��"));
//	
//	pProp = new CMFCPropertyGridProperty(_T("��ǰͼ��"), _T(""), _T("ָ����ͼ��ǰ���༭��ͼ�㡣"));
//	pProp->AddOption(_T("�����"));
//	pProp->AddOption(_T("�����"));
//	pProp->AddOption(_T("�ϰ���"));
//	pProp->AddOption(_T("�¼���"));
//	pProp->AllowEdit(FALSE);
//	pGroup2->AddSubItem(pProp);
//	pGroup2->AddSubItem(new CMFCPropertyGridProperty(_T("�Ƿ�ɼ�"), (_variant_t)false, _T("ָ����ǰͼ���Ƿ�ɼ���true�ɼ���false���ء�")));
//	m_wndPropList.AddProperty(pGroup2);
//
//	//������������
//	CMFCPropertyGridProperty* pGroup3 = new CMFCPropertyGridProperty(_T("������"));
//	
//	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("������ID"), _T(""), _T("ÿ������������һ��IDֵ��ͨ��IDֵ��ȡ��������")));
//	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ͼID"), _T(""), _T("ָ����������ָ��ĵ�ͼID��")));
//	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ʼXλ��"),_T(""), _T("ָ�������л��󣬽�ɫ���ֵĳ�ʼX����λ�á�")));
//	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ʼYλ��"), _T(""), _T("ָ�������л��󣬽�ɫ���ֵĳ�ʼY����λ�á�")));
//	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ɫ����"), _T(""), _T("ָ�������л��󣬽�ɫ�ĳ�����0~8�ֱ��ʾ8������")));
//	m_wndPropList.AddProperty(pGroup3);
//
//	m_wndPropList.ExpandAll(false);
//}
//
//void CPropertiesWnd::OnSetFocus(CWnd* pOldWnd)
//{
//	CDockablePane::OnSetFocus(pOldWnd);
//	m_wndPropList.SetFocus();
//}
//
//void CPropertiesWnd::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
//{
//	CDockablePane::OnSettingChange(uFlags, lpszSection);
//	SetPropListFont();
//}
//
//void CPropertiesWnd::SetPropListFont()
//{
//	::DeleteObject(m_fntPropList.Detach());
//
//	LOGFONT lf;
//	afxGlobalData.fontRegular.GetLogFont(&lf);
//
//	NONCLIENTMETRICS info;
//	info.cbSize = sizeof(info);
//
//	afxGlobalData.GetNonClientMetrics(info);
//
//	lf.lfHeight = info.lfMenuFont.lfHeight;
//	lf.lfWeight = info.lfMenuFont.lfWeight;
//	lf.lfItalic = info.lfMenuFont.lfItalic;
//
//	m_fntPropList.CreateFontIndirect(&lf);
//
//	m_wndPropList.SetFont(&m_fntPropList);
//
//}
//
//void CPropertiesWnd::SetLayerIndexProp(int iLayerIndex)
//{	
//	CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(1);
//
//	switch (iLayerIndex)
//	{
//	case 0:
//		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�����"));
//		break;
//	case 1:
//		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�����"));
//		break;
//	case 2:
//		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�ϰ���"));
//		break;
//	case 3:
//		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�¼���"));
//		break;
//	}
//}
//
//bool CPropertiesWnd::GetTriggerProp(CTrigger& trigger)
//{
//
//	CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(2);
//	COleVariant var;
//	
//	var =pProp->GetSubItem(0)->GetValue();
//	if(var == (_variant_t)_T(""))
//	{
//		MessageBox(_T("�����ô�������IDֵ"),_T("��ʾ"));
//		ShowPane(true,false,true);
//		ExpandPropGroup(2);
//		return false;
//	}
//	else
//	{
//		var.ChangeType(VT_I4);
//		trigger.SetTriggerID(var.intVal);
//	}
//
//	var = pProp->GetSubItem(1)->GetValue();
//	if(var == (_variant_t)_T(""))
//	{
//		MessageBox(_T("�����ô�����ָ��ĵ�ͼID"),_T("��ʾ"));
//		ShowPane(true,false,true);
//		ExpandPropGroup(2);
//		return false;
//	}
//	else
//	{
//		var.ChangeType(VT_I4);
//		trigger.SetMapID(var.intVal);
//	}
//	var =pProp->GetSubItem(2)->GetValue();
//	if(var == (_variant_t)_T(""))
//	{
//		MessageBox(_T("�����ý�ɫ��ʼXλ��"),_T("��ʾ"));
//		ShowPane(true,false,true);
//		ExpandPropGroup(2);
//		return false;
//	}
//	else
//	{
//		var.ChangeType(VT_I4);
//		trigger.SetStartPosX(var.intVal);
//	}
//	var =pProp->GetSubItem(3)->GetValue();
//	if(var == (_variant_t)_T(""))
//	{
//		MessageBox(_T("�����ý�ɫ��ʼYλ��"),_T("��ʾ"));
//		ShowPane(true,false,true);
//		ExpandPropGroup(2);
//		return false;
//	}
//	else
//	{
//		var.ChangeType(VT_I4);
//		trigger.SetStartPosY(var.intVal);
//	}
//
//	var =pProp->GetSubItem(4)->GetValue();
//	if(var == (_variant_t)_T(""))
//	{
//		MessageBox(_T("�����ý�ɫ������"),_T("��ʾ"));
//		ShowPane(true,false,true);
//		ExpandPropGroup(2);
//		return false;
//	}
//	else
//	{
//		var.ChangeType(VT_I4);
//		trigger.SetDirection(var.intVal);
//	}
//	ClearTriggerProp();
//	return true;
//}
//
//void CPropertiesWnd::ClearTriggerProp()
//{
//	CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(2);
//	for(int i=0;i<5;i++)
//		pProp->GetSubItem(i)->SetValue(_T(""));
//}
//
//
//
//LRESULT CPropertiesWnd::OnPropertyChanged(WPARAM,LPARAM lParam)
//{
//	CMFCPropertyGridProperty* pProp = (CMFCPropertyGridProperty*) lParam; 
//
//	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
//	CMapEditorDoc* pDoc = (CMapEditorDoc*)pFrame->GetActiveDocument();
//	ASSERT_VALID(pDoc);
//	if (!pDoc)
//		return 0;
//	
//	CMFCPropertyGridProperty* pProp1= m_wndPropList.GetProperty(0);
//	COleVariant var;
//	var = pProp1->GetSubItem(2)->GetValue();
//	var.ChangeType(VT_I4);
//	int orgTileWidth = var.intVal;
//
//	var = pProp1->GetSubItem(3)->GetValue();
//	var.ChangeType(VT_I4);
//	int orgTileHeight = var.intVal;
//
//	var = pProp1->GetSubItem(4)->GetValue();
//	var.ChangeType(VT_I4);
//	int orgOffsetX = var.intVal;
//
//	var = pProp1->GetSubItem(5)->GetValue();
//	var.ChangeType(VT_I4);
//	int orgOffsetY = var.intVal;
//
//	var = pProp->GetValue(); //��ȡ�ı�֮���ֵ  
//
//	CString strName = pProp->GetName();
//	
////	pDoc->UpdateAllViews(NULL);
//	return 0; 
//}



int CPropertiesWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	//������������
	if (!m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2))
	{
		TRACE0("δ�ܴ�����������\n");
		return -1;      // δ�ܴ���
	}

	InitPropList();
	
	AdjustLayout();
	return 0;
}

void CPropertiesWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}
void CPropertiesWnd::AdjustLayout()
{
	if (GetSafeHwnd() == NULL)
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	m_wndPropList.SetWindowPos(NULL, rectClient.left, rectClient.top , rectClient.Width(), rectClient.Height() , SWP_NOACTIVATE | SWP_NOZORDER);
}



void CPropertiesWnd::InitPropList()
{
	SetPropListFont();

	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea();
	m_wndPropList.SetVSDotNetLook();
	m_wndPropList.MarkModifiedProperties();

	
	//��ͼ������
	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("��ͼ����"));
	//��ͼ��͸�Ϊֻ�����ԣ��ڴ�����ͼʱָ����֮�󲻿ɸ���
	CMFCPropertyGridProperty* pProp = new CMFCPropertyGridProperty(_T("��ͼ���"), (_variant_t)0, _T("��ͼ����Ԫ�����"));
	pProp->AllowEdit(FALSE);
	pGroup1->AddSubItem(pProp);

	pProp = new CMFCPropertyGridProperty( _T("��ͼ�߶�"), (_variant_t)0, _T("��ͼ����Ԫ�����"));
	pProp->AllowEdit(FALSE);
	pGroup1->AddSubItem(pProp);

	pProp = new CMFCPropertyGridProperty(_T("ͼ����"), (_variant_t)0, _T("��Ԫ��ͼ��Ŀ��"));
	pProp->AllowEdit(FALSE);
	pGroup1->AddSubItem(pProp);
	pProp = new CMFCPropertyGridProperty(_T("ͼ��߶�"), (_variant_t)0, _T("��Ԫ��ͼ��ĸ߶�"));
	pProp->AllowEdit(FALSE);
	pGroup1->AddSubItem(pProp);

	//��ӵ�ͼ��Ϣ������
	m_wndPropList.AddProperty(pGroup1);
	
	//ͼ��������
	CMFCPropertyGridProperty* pGroup2 = new CMFCPropertyGridProperty(_T("ͼ��"));
	
	pProp = new CMFCPropertyGridProperty(_T("��ǰͼ��"), _T(""), _T("ָ����ͼ��ǰ���༭��ͼ�㡣"));
	pProp->AddOption(_T("�����"));
	pProp->AddOption(_T("�����"));
	pProp->AddOption(_T("�ϰ���"));
	pProp->AddOption(_T("�¼���"));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pGroup2->AddSubItem(new CMFCPropertyGridProperty(_T("�Ƿ�ɼ�"), (_variant_t)false, _T("ָ����ǰͼ���Ƿ�ɼ���true�ɼ���false���ء�")));
	m_wndPropList.AddProperty(pGroup2);

	//������������
	CMFCPropertyGridProperty* pGroup3 = new CMFCPropertyGridProperty(_T("������"));
	
	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("������ID"), _T(""), _T("ÿ������������һ��IDֵ��ͨ��IDֵ��ȡ��������")));
	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ͼID"), _T(""), _T("ָ����������ָ��ĵ�ͼID��")));
	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ʼXλ��"),_T(""), _T("ָ�������л��󣬽�ɫ���ֵĳ�ʼX����λ�á�")));
	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ʼYλ��"), _T(""), _T("ָ�������л��󣬽�ɫ���ֵĳ�ʼY����λ�á�")));
	pGroup3->AddSubItem(new CMFCPropertyGridProperty(_T("��ɫ����"), _T(""), _T("ָ�������л��󣬽�ɫ�ĳ�����0~8�ֱ��ʾ8������")));
	m_wndPropList.AddProperty(pGroup3);

	m_wndPropList.ExpandAll(false);
}

void CPropertiesWnd::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
	m_wndPropList.SetFocus();
}

void CPropertiesWnd::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CDockablePane::OnSettingChange(uFlags, lpszSection);
	SetPropListFont();
}

void CPropertiesWnd::SetPropListFont()
{
	::DeleteObject(m_fntPropList.Detach());

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);

	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);

	afxGlobalData.GetNonClientMetrics(info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;

	m_fntPropList.CreateFontIndirect(&lf);

	m_wndPropList.SetFont(&m_fntPropList);

}

void CPropertiesWnd::SetLayerIndexProp(int iLayerIndex)
{	
	CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(1);

	switch (iLayerIndex)
	{
	case 0:
		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�����"));
		break;
	case 1:
		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�����"));
		break;
	case 2:
		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�ϰ���"));
		break;
	case 3:
		pProp->GetSubItem(0)->SetValue((_variant_t)_T("�¼���"));
		break;
	}
}

bool CPropertiesWnd::GetTriggerProp(CTrigger& trigger)
{

	CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(2);
	COleVariant var;
	
	var =pProp->GetSubItem(0)->GetValue();
	if(var == (_variant_t)_T(""))
	{
		MessageBox(_T("�����ô�������IDֵ"),_T("��ʾ"));
		ShowPane(true,false,true);
		ExpandPropGroup(2);
		return false;
	}
	else
	{
		var.ChangeType(VT_I4);
		trigger.SetTriggerID(var.intVal);
	}

	var = pProp->GetSubItem(1)->GetValue();
	if(var == (_variant_t)_T(""))
	{
		MessageBox(_T("�����ô�����ָ��ĵ�ͼID"),_T("��ʾ"));
		ShowPane(true,false,true);
		ExpandPropGroup(2);
		return false;
	}
	else
	{
		var.ChangeType(VT_I4);
		trigger.SetMapID(var.intVal);
	}
	var =pProp->GetSubItem(2)->GetValue();
	if(var == (_variant_t)_T(""))
	{
		MessageBox(_T("�����ý�ɫ��ʼXλ��"),_T("��ʾ"));
		ShowPane(true,false,true);
		ExpandPropGroup(2);
		return false;
	}
	else
	{
		var.ChangeType(VT_I4);
		trigger.SetStartPosX(var.intVal);
	}
	var =pProp->GetSubItem(3)->GetValue();
	if(var == (_variant_t)_T(""))
	{
		MessageBox(_T("�����ý�ɫ��ʼYλ��"),_T("��ʾ"));
		ShowPane(true,false,true);
		ExpandPropGroup(2);
		return false;
	}
	else
	{
		var.ChangeType(VT_I4);
		trigger.SetStartPosY(var.intVal);
	}

	var =pProp->GetSubItem(4)->GetValue();
	if(var == (_variant_t)_T(""))
	{
		MessageBox(_T("�����ý�ɫ������"),_T("��ʾ"));
		ShowPane(true,false,true);
		ExpandPropGroup(2);
		return false;
	}
	else
	{
		var.ChangeType(VT_I4);
		trigger.SetDirection(var.intVal);
	}
	ClearTriggerProp();
	return true;
}

void CPropertiesWnd::ClearTriggerProp()
{
	CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(2);
	for(int i=0;i<5;i++)
		pProp->GetSubItem(i)->SetValue(_T(""));
}



LRESULT CPropertiesWnd::OnPropertyChanged(WPARAM,LPARAM lParam)
{
	CMFCPropertyGridProperty* pProp = (CMFCPropertyGridProperty*) lParam; 

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMapEditorDoc* pDoc = (CMapEditorDoc*)pFrame->GetActiveDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return 0;
	//Ԥ���ӿں���
//	pDoc->UpdateAllViews(NULL);
	return 0; 
}