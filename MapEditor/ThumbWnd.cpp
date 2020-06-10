// ThumbWnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MapEditor.h"
#include "ThumbWnd.h"


// CThumbWnd

IMPLEMENT_DYNAMIC(CThumbWnd, CWnd)

CThumbWnd::CThumbWnd()
{
	m_iCurSelItem = -1;
	m_ThumbSize = CSize(64,64);
}

CThumbWnd::~CThumbWnd()
{
}


BEGIN_MESSAGE_MAP(CThumbWnd, CWnd)
	ON_NOTIFY(NM_CLICK,IDC_THUMBLIST,OnSelectListItem)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CThumbWnd ��Ϣ�������




int CThumbWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CRect rectDummy;
	rectDummy.SetRectEmpty();
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | LVS_ICON;

	if (!m_ListCtrl.Create(dwViewStyle, rectDummy, this, IDC_THUMBLIST))
	{
		TRACE0("δ�ܴ����б�\n");
		return -1;      // δ�ܴ���
	}
	m_ListCtrl.SetExtendedStyle(LVS_AUTOARRANGE);
	m_ListCtrl.SetBkColor(RGB(213,228,242));

	AdjustLayout();

	return 0;
}


void CThumbWnd::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	AdjustLayout();
}

void CThumbWnd::AdjustLayout()
{
	CRect rectClient;
	GetClientRect(rectClient);
	m_ListCtrl.SetWindowPos(this, rectClient.left , rectClient.top , rectClient.Width() - 1, rectClient.Height() - 1, SWP_NOACTIVATE | SWP_NOZORDER);
	m_ListCtrl.Arrange(LVA_DEFAULT);
}

//���ݴ����ͼƬ�б�������Ӧ������ͼ�б�
void CThumbWnd::CreateThumbList(CArray<CTexture>& imageList,int width,int height)
{

	m_ThumbSize.SetSize(width,height);
	m_ImageList.DeleteImageList();
	m_ImageList.Create(m_ThumbSize.cx, m_ThumbSize.cy, ILC_COLOR32|ILC_MASK,128,128);
	m_ListCtrl.SetImageList(&m_ImageList, TVSIL_NORMAL );
	for(int i=0;i<imageList.GetSize();i++)
	{
		AddThumb(imageList.GetAt(i));
	}
}
//������ͼ�б������һ������ͼ
void CThumbWnd::AddThumb(CTexture& srcImage)
{
	//�趨����ͼ��Ⱥ͸߶�
	int thumbWidth = m_ThumbSize.cx;
	int thumbHeight = min((LONG)srcImage.GetHeight(), m_ThumbSize.cy);                                         

	CClientDC cdc(this);

	CDC MemDC;           //���ڻ�����ͼ���ڴ�DC
	CBitmap MemBmp;      //�ڴ��г�����ʱͼ���λͼ
	MemDC.CreateCompatibleDC(&cdc);     //��������DC���������ڴ�DC
	MemBmp.CreateCompatibleBitmap(&cdc,thumbWidth,thumbHeight);//��������λͼ
	MemDC.SelectObject(&MemBmp);       //��λͼѡ����ڴ�DC
	MemDC.FillSolidRect(CRect(0,0,thumbWidth,thumbHeight),RGB(255,255, 255));//����

	srcImage.Draw(&MemDC,0,0,thumbWidth,thumbHeight);   //���ڴ�DC�л�ͼ
	
	CBitmap bmp;
	bmp.Attach(MemBmp.Detach());	
	
	MemDC.DeleteDC();                                       //ɾ��DC
	MemBmp.DeleteObject();

	m_ImageList.Add(&bmp,RGB(255,255,255));
	int nItem = m_ImageList.GetImageCount()-1;

	CString strItem = srcImage.GetFileName();
	int i=strItem.ReverseFind(_T('/'));
	strItem.Delete(0,i+1);
	//�����б���
	m_ListCtrl.InsertItem(nItem,strItem,nItem);

	bmp.DeleteObject();
}

void CThumbWnd::OnSelectListItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_iCurSelItem = pNMLV->iItem;

	*pResult = 0;
}