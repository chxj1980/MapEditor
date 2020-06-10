
#pragma once

#include "EventLayer.h"

//����ͣ������
class CPropertiesWnd : public CDockablePane
{
// ����
public:
	CPropertiesWnd();

	void AdjustLayout();

// ����
public:
	void SetVSDotNetLook(BOOL bSet)
	{
		m_wndPropList.SetVSDotNetLook(bSet);
		m_wndPropList.SetGroupNameFullWidth(bSet);
	}
	//�趨��ʾ��ͼ��С��Ϣ
	void SetMapSizeProp(int width,int height)
	{	
		CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(0);
		pProp->GetSubItem(0)->SetValue((_variant_t)width);
		pProp->GetSubItem(1)->SetValue((_variant_t)height);
	}
	//�趨��ʾ��ש��С��Ϣ
	void SetTileSizeProp(int width,int height)
	{	
		CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(0);
		pProp->GetSubItem(2)->SetValue((_variant_t)width);
		pProp->GetSubItem(3)->SetValue((_variant_t)height);
	}
	
	//�趨��ʾͼ����Ϣ
	void SetLayerIndexProp(int iLayerIndex);
	//��ʾͼ����Ϣ
	void SetLayerVisibleProp(bool bVisible)
	{
		CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(1);
		pProp->GetSubItem(1)->SetValue((_variant_t)bVisible);
	}
	//��ȡ����������
	bool GetTriggerProp(CTrigger& trigger);
	//չ����nIndex������
	void ExpandPropGroup(int nIndex)
	{
		CMFCPropertyGridProperty* pProp= m_wndPropList.GetProperty(nIndex);
		m_wndPropList.ExpandAll(false);
		pProp->Expand();
		SetFocus();
	}
private:
	//��մ���������
	void ClearTriggerProp();

protected:
	CFont			   m_fntPropList;
	//���Ը�ؼ�
	CMFCPropertyGridCtrl m_wndPropList;

// ʵ��
public:
	virtual ~CPropertiesWnd();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	//���Ըı��¼�����
	afx_msg LRESULT OnPropertyChanged(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()
	//��ʼ�������б�
	void InitPropList();
	void SetPropListFont();
};


