#pragma once

#define IDC_THUMBLIST		80
// CThumbWnd

class CThumbWnd : public CWnd
{
	DECLARE_DYNAMIC(CThumbWnd)

public:
	CThumbWnd();
	virtual ~CThumbWnd();

	CListCtrl	m_ListCtrl;
	CImageList  m_ImageList;
	CSize	    m_ThumbSize;
	//��¼��ǰѡ�е�����
	int			m_iCurSelItem;
public:
	//��ʼ������ͼ�б�,Ĭ������ͼ��͸�Ϊ64
	void		CreateThumbList(CArray<CTexture>& imageList,int width = 64,int height =64);
	//������ͼ�б������һ��ͼƬ
	void		AddThumb(CTexture& srcImage);

	//��ȡ��ǰѡ�е�����
	int			GetCurSelResID(){	return m_iCurSelItem; }

protected:
	void	AdjustLayout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


