
// MapEditorView.h : CMapEditorView ��Ľӿ�
//

#pragma once
#define ID_TIMER_SCENE 101//��ʱ��ID



class CMapEditorView : public CScrollView
{
protected: // �������л�����
	CMapEditorView();
	DECLARE_DYNCREATE(CMapEditorView)

// ����
public:
	CMapEditorDoc* GetDocument() const;
	//�����ڴ�DC��С
	void	OnResetMemDC(void);
public:
	CDC		m_MemDC;                  //���ڻ�����ͼ���ڴ�DC
	CBitmap m_MemBmp;             //�ڴ��г�����ʱͼ���λͼ
	bool	m_bLButtonDown;
	//��¼������������ͼ���Ͻǵ�λ��
	CPoint	m_CurPt;
	CSize	m_Offset;
	//�ü�����
	CRgn	m_ClipRgn;
// ����
public:

	//����Ļ��(x��y)����ͼ��
	void AddTile(int x,int y);
	//����Ļ�ϣ�x,y��λ�û�����
	void AddObject(int x,int y);
	//����Ļ��(x,y)λ�����ϰ���
	void AddBlock(int x,int y);
	//����Ļ��(x,y)λ�������������
	void AddTrigger(int x,int y);
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	
protected:

// ʵ��
public:
	virtual ~CMapEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	afx_msg void OnDestroy();
	
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // MapEditorView.cpp �еĵ��԰汾
inline CMapEditorDoc* CMapEditorView::GetDocument() const
   { return reinterpret_cast<CMapEditorDoc*>(m_pDocument); }
#endif

