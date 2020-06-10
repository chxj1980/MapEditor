
// MapEditorDoc.h : CMapEditorDoc ��Ľӿ�
//


#pragma once

#include "TileMap.h"
#include "PropertiesWnd.h"




class CMapEditorDoc : public CDocument
{
protected: // �������л�����
	CMapEditorDoc();
	DECLARE_DYNCREATE(CMapEditorDoc)

// ����
public:
	CPropertiesWnd* m_pPropWnd;
	
	CTileMap		m_Map;

	//��ǰ�༭��ͼ������,0:����㣬1������㣬2�����ϰ��㣬3���¼���
	int		m_iLayerIndex;

	//��Ƥ�������߱��
	bool	m_bEraser;

	//ͼ�����ع��߱��
	bool	m_bLayerVisible;
	//ѡ�񹤾߱��
	bool	m_bChose;
	//�϶�����
	bool	m_bDrug;
	//��ˢģʽ���
	bool	m_bBrush;
	//����ϵ��
	float	m_fScale;
	//��¼��ǰ���ͼ�ļ�·��
	CString	m_strMapFilePath;

	//��ǰѡ��������
	int		m_CurSelObj;
// ����
public:
	//��ʼ��״̬
	void	InitStates();
	//֪ͨView����ָ���ڴ�DC��С
	void	OnResetMemDC();
	//������קͼƬ
	void	DrawDrugImage(CDC *pDC,int destX,int destY);
	////��ȡ����Ļ��ĳһ���Ӧ�ĵ�ͼ�еĶ��������
	//int		GetCurChose(CPoint point);
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMapEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnLayerTile();
	afx_msg void OnUpdateLayerTile(CCmdUI *pCmdUI);
	afx_msg void OnLayerObject();
	afx_msg void OnUpdateLayerObject(CCmdUI *pCmdUI);
	afx_msg void OnLayerEvent();
	afx_msg void OnUpdateLayerEvent(CCmdUI *pCmdUI);
	afx_msg void OnLayerVisible();
	afx_msg void OnUpdateLayerVisible(CCmdUI *pCmdUI);
	afx_msg void OnLayerBlock();
	afx_msg void OnUpdateLayerBlock(CCmdUI *pCmdUI);
	afx_msg void OnEditEraser();
	afx_msg void OnUpdateEditEraser(CCmdUI *pCmdUI);
	afx_msg void OnViewShowGrid();
	afx_msg void OnUpdateViewShowGrid(CCmdUI *pCmdUI);
	afx_msg void OnViewZoomin();
	afx_msg void OnUpdateViewZoomin(CCmdUI *pCmdUI);
	afx_msg void OnViewZoomout();
	afx_msg void OnUpdateViewZoomout(CCmdUI *pCmdUI);
	afx_msg void OnViewNormal();
	afx_msg void OnUpdateViewNormal(CCmdUI *pCmdUI);
	afx_msg void OnMapPreview();

	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnFileSaveAs();
	
	afx_msg void OnUpdateFileSave(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI *pCmdUI);
	
	afx_msg void OnEditChose();
	afx_msg void OnUpdateEditChose(CCmdUI *pCmdUI);
	afx_msg void OnEditBrush();
	afx_msg void OnUpdateEditBrush(CCmdUI *pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI *pCmdUI);
	afx_msg void OnViewShowrole();
	afx_msg void OnUpdateViewShowrole(CCmdUI *pCmdUI);
	afx_msg void OnAppHelp();
	afx_msg void OnEditFill();
};

