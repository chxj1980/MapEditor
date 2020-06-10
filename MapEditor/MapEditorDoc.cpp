
// MapEditorDoc.cpp : CMapEditorDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MapEditor.h"
#endif

#include "MapEditorDoc.h"
#include "MainFrm.h"
#include "MapEditorView.h"
#include "NewMapDlg.h"
#include <propkey.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMapEditorDoc

IMPLEMENT_DYNCREATE(CMapEditorDoc, CDocument)
	
BEGIN_MESSAGE_MAP(CMapEditorDoc, CDocument)
	ON_COMMAND(ID_FILE_NEW,&CMapEditorDoc::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN,&CMapEditorDoc::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMapEditorDoc::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMapEditorDoc::OnFileSaveAs)
	ON_COMMAND(ID_LAYER_TILE, &CMapEditorDoc::OnLayerTile)
	ON_UPDATE_COMMAND_UI(ID_LAYER_TILE, &CMapEditorDoc::OnUpdateLayerTile)
	ON_COMMAND(ID_LAYER_OBJECT, &CMapEditorDoc::OnLayerObject)
	ON_UPDATE_COMMAND_UI(ID_LAYER_OBJECT, &CMapEditorDoc::OnUpdateLayerObject)
	ON_COMMAND(ID_LAYER_BLOCK, &CMapEditorDoc::OnLayerBlock)
	ON_UPDATE_COMMAND_UI(ID_LAYER_BLOCK, &CMapEditorDoc::OnUpdateLayerBlock)
	ON_COMMAND(ID_LAYER_EVENT, &CMapEditorDoc::OnLayerEvent)
	ON_UPDATE_COMMAND_UI(ID_LAYER_EVENT, &CMapEditorDoc::OnUpdateLayerEvent)
	ON_COMMAND(ID_LAYER_VISIBLE, &CMapEditorDoc::OnLayerVisible)
	ON_UPDATE_COMMAND_UI(ID_LAYER_VISIBLE, &CMapEditorDoc::OnUpdateLayerVisible)
	ON_COMMAND(ID_EDIT_ERASER, &CMapEditorDoc::OnEditEraser)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ERASER, &CMapEditorDoc::OnUpdateEditEraser)
	ON_COMMAND(ID_VIEW_ShowGrid, &CMapEditorDoc::OnViewShowGrid)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ShowGrid, &CMapEditorDoc::OnUpdateViewShowGrid)
	ON_COMMAND(ID_VIEW_ZOOMIN, &CMapEditorDoc::OnViewZoomin)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOMIN, &CMapEditorDoc::OnUpdateViewZoomin)
	ON_COMMAND(ID_VIEW_ZOOMOUT, &CMapEditorDoc::OnViewZoomout)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZOOMOUT, &CMapEditorDoc::OnUpdateViewZoomout)
	ON_COMMAND(ID_VIEW_NORMAL, &CMapEditorDoc::OnViewNormal)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NORMAL, &CMapEditorDoc::OnUpdateViewNormal)
	ON_COMMAND(ID_MAP_PREVIEW, &CMapEditorDoc::OnMapPreview)
	
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, &CMapEditorDoc::OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, &CMapEditorDoc::OnUpdateFileSaveAs)
	ON_COMMAND(ID_EDIT_CHOSE, &CMapEditorDoc::OnEditChose)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CHOSE, &CMapEditorDoc::OnUpdateEditChose)
	ON_COMMAND(ID_EDIT_BRUSH, &CMapEditorDoc::OnEditBrush)
	ON_UPDATE_COMMAND_UI(ID_EDIT_BRUSH, &CMapEditorDoc::OnUpdateEditBrush)
	ON_COMMAND(ID_EDIT_DELETE, &CMapEditorDoc::OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, &CMapEditorDoc::OnUpdateEditDelete)
	ON_COMMAND(ID_VIEW_SHOWROLE, &CMapEditorDoc::OnViewShowrole)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOWROLE, &CMapEditorDoc::OnUpdateViewShowrole)
	ON_COMMAND(ID_APP_HELP, &CMapEditorDoc::OnAppHelp)
	ON_COMMAND(ID_EDIT_FILL, &CMapEditorDoc::OnEditFill)
END_MESSAGE_MAP()


// CMapEditorDoc ����/����

CMapEditorDoc::CMapEditorDoc()
{
	// TODO: �ڴ����һ���Թ������
	
	m_iLayerIndex = -1;
	m_bEraser = false;
	
	m_bChose = false;
	//�϶�����
	m_bDrug = false;
	//��ˢģʽ���
	m_bBrush = false;

	m_fScale = 1.0f;
	m_CurSelObj = -1;
	m_strMapFilePath = _T("");
	m_pPropWnd = NULL;

}

CMapEditorDoc::~CMapEditorDoc()
{
}

BOOL CMapEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	m_pPropWnd = pFrame->GetPropWnd();
	return TRUE;
}




// CMapEditorDoc ���л�

void CMapEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMapEditorDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMapEditorDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMapEditorDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMapEditorDoc ���

#ifdef _DEBUG
void CMapEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMapEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG
void CMapEditorDoc::InitStates()
{
	//Ĭ����ʾ����
	g_bShowGrid = true;
	//Ĭ�ϵ�ǰ�༭��Ϊ�����
	m_iLayerIndex = 0;
	//Ĭ��Ϊ��ˢģʽ
	m_bBrush = true;
	m_CurSelObj = -1;
		
	//��������Ϣ����

	//���µ�ͼ��Ϣ����ֵ
	m_pPropWnd->SetMapSizeProp(g_MapWidth,g_MapHeight);
	m_pPropWnd->SetTileSizeProp(g_TileWidth,g_TileHeight);
	//����ͼ������ֵ
	m_pPropWnd->SetLayerIndexProp(m_iLayerIndex);
	m_pPropWnd->SetLayerVisibleProp(m_Map.GetTileLayer().GetVisible());
	UpdateAllViews(NULL);//ǿ�Ƶ���OnDraw����
}

// CMapEditorDoc ����
void CMapEditorDoc::OnFileNew()
{
	//�жϵ�ǰ�����Ƿ�ı�

	CNewMapDlg dlg;
	if(dlg.DoModal()!=IDOK)
		return;
	int MapWidth = dlg.m_iMapWidth;
	int MapHeight = dlg.m_iMapHeight;
	int TileWidth = dlg.m_iTileWidth;
	int TileHeight = dlg.m_iTileHeight;
	m_Map.Create(MapWidth,MapHeight,TileWidth,TileHeight);
	

	InitStates();
	//����DC
	OnResetMemDC();
 }
void CMapEditorDoc::OnFileOpen()
{


	CString strFilter = _T("��ͼ�ļ�|*.map|�����ļ�(*.*)|*.*||");
   
     CFileDialog dlg(TRUE,NULL,NULL,OFN_FILEMUSTEXIST,strFilter);
     if(IDOK!=dlg.DoModal())
         return;
	 m_strMapFilePath = dlg.GetPathName();
     //���ⲿ�ļ�װ�ص�Map������
     if(!m_Map.LoadMapData(dlg.GetPathName()))
     {
         AfxMessageBox(_T("���ص�ͼ�ļ�ʧ�ܣ�"));
         return;
     }
	
     //���������ڱ���������
     CString str;
     str.LoadString(AFX_IDS_APP_TITLE);
     AfxGetMainWnd()->SetWindowText(dlg.GetFileName()+_T("-")+str);

	 InitStates();
	 //����DC
	 OnResetMemDC();
}


//�л��������
void CMapEditorDoc::OnLayerTile()
{
	// TODO: �ڴ���������������
	m_iLayerIndex= 0 ;

	m_pPropWnd->SetLayerIndexProp(m_iLayerIndex);
	m_pPropWnd->SetLayerVisibleProp(m_Map.GetTileLayer().GetVisible());
}

void CMapEditorDoc::OnUpdateLayerTile(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_iLayerIndex== 0)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}
//�л��������
void CMapEditorDoc::OnLayerObject()
{
	// TODO: �ڴ���������������
	m_iLayerIndex = 1;

	m_pPropWnd->SetLayerIndexProp(m_iLayerIndex);
	m_pPropWnd->SetLayerVisibleProp(m_Map.GetObjectLayer().GetVisible());
}
void CMapEditorDoc::OnUpdateLayerObject(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_iLayerIndex== 1)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}

//�л����ϰ���
void CMapEditorDoc::OnLayerBlock()
{
	// TODO: �ڴ���������������
	m_iLayerIndex = 2;

	m_pPropWnd->SetLayerIndexProp(m_iLayerIndex);
	m_pPropWnd->SetLayerVisibleProp(m_Map.GetBlockLayer().GetVisible());

}
void CMapEditorDoc::OnUpdateLayerBlock(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_iLayerIndex== 2)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}


void CMapEditorDoc::OnLayerEvent()
{
	// TODO: �ڴ���������������
	m_iLayerIndex = 3;

	m_pPropWnd->SetLayerIndexProp(m_iLayerIndex);
	m_pPropWnd->SetLayerVisibleProp(m_Map.GetEventLayer().GetVisible());

}
void CMapEditorDoc::OnUpdateLayerEvent(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_iLayerIndex== 3)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}

//���ص�ǰͼ��
void CMapEditorDoc::OnLayerVisible()
{
	// TODO: �ڴ���������������
	switch (m_iLayerIndex)
	{
	case 0:
		m_Map.GetTileLayer().SetVisible(!m_Map.GetTileLayer().GetVisible());
		//���������Ը���
		m_pPropWnd->SetLayerVisibleProp(m_Map.GetTileLayer().GetVisible());
		break;
	case 1:
		m_Map.GetObjectLayer().SetVisible(!m_Map.GetObjectLayer().GetVisible());
		m_pPropWnd->SetLayerVisibleProp(m_Map.GetObjectLayer().GetVisible());
		break;
	case 2:
		m_Map.GetBlockLayer().SetVisible(!m_Map.GetBlockLayer().GetVisible());
		m_pPropWnd->SetLayerVisibleProp(m_Map.GetBlockLayer().GetVisible());
		break;
	case 3:
		m_Map.GetEventLayer().SetVisible(!m_Map.GetEventLayer().GetVisible());
		m_pPropWnd->SetLayerVisibleProp(m_Map.GetEventLayer().GetVisible());
		break;
	}
	UpdateAllViews(NULL);
}

void CMapEditorDoc::OnUpdateLayerVisible(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	switch (m_iLayerIndex)
	{
	case 0:
		//������ɼ�����Ѱ�ť��Ϊѡ��״̬
			pCmdUI->SetCheck(!m_Map.GetTileLayer().GetVisible());
		break;
	case 1:
			pCmdUI->SetCheck(!m_Map.GetObjectLayer().GetVisible());
		break;
	case 2:
			pCmdUI->SetCheck(!m_Map.GetBlockLayer().GetVisible());
		break;
	case 3:
			pCmdUI->SetCheck(!m_Map.GetEventLayer().GetVisible());
		break;
	}
}


void CMapEditorDoc::OnEditEraser()
{
	// TODO: �ڴ���������������
	m_bEraser = !m_bEraser;

}


void CMapEditorDoc::OnUpdateEditEraser(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_bEraser)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}


void CMapEditorDoc::OnViewShowGrid()
{
	// TODO: �ڴ���������������
	g_bShowGrid = !g_bShowGrid;

	UpdateAllViews(NULL);
}


void CMapEditorDoc::OnUpdateViewShowGrid(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(g_bShowGrid)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}
void CMapEditorDoc::OnViewZoomin()
{
	// TODO: �ڴ���������������
	m_fScale -=0.25;
	if(m_fScale<=0.25)
		m_fScale = 0.25;

	m_Map.SetScale(m_fScale);
	OnResetMemDC();
}
void CMapEditorDoc::OnUpdateViewZoomin(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
}


void CMapEditorDoc::OnViewZoomout()
{
	// TODO: �ڴ���������������
	m_fScale +=0.25;
	if(m_fScale>= 2.5)
		m_fScale = 2.5;

	m_Map.SetScale(m_fScale);
	OnResetMemDC();
}
void CMapEditorDoc::OnUpdateViewZoomout(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
}

void CMapEditorDoc::OnViewNormal()
{
	// TODO: �ڴ���������������
	m_fScale = 1.0;

	m_Map.SetScale(m_fScale);
	OnResetMemDC();
}
void CMapEditorDoc::OnUpdateViewNormal(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
}

void CMapEditorDoc::OnMapPreview()
{
	// TODO: �ڴ���������������
	//CPreviewDlg mapDlg;
	//mapDlg.DoModal();
}

void CMapEditorDoc::OnFileSave()
{
	// TODO: �ڴ���������������
	if(!m_strMapFilePath.IsEmpty())
	{	//��ǰ��ļ�·����Ϊ�գ�ֱ�Ӵ�ȡ
		m_Map.SaveMapData(m_strMapFilePath);	
		
		return;
	}
	
	CString strFilter;
	strFilter=_T("��ͼ�ļ�|*.map|�����ļ�(*.*)|*.*||");
	CFileDialog dlg(FALSE,NULL,NULL,NULL,strFilter);
	if(IDOK!=dlg.DoModal())
		return;
	//���û��ָ���ļ���չ������Ϊ�����һ��
	m_strMapFilePath = dlg.GetPathName();

	if(dlg.GetFileExt()==_T(""))
	{
		m_strMapFilePath +=_T(".map");
	}
	m_Map.SaveMapData(m_strMapFilePath);

	//���������ڱ���������
	CString str;
	str.LoadString(AFX_IDS_APP_TITLE);
	AfxGetMainWnd()->SetWindowText(dlg.GetFileName()+_T("-")+str);
	
}



void CMapEditorDoc::OnFileSaveAs()
{
	// TODO: �ڴ���������������
	CString strFilter;
	strFilter=_T("MAP��ͼ�ļ�|*.map||");
	CFileDialog dlg(FALSE,NULL,NULL,NULL,strFilter);
	if(IDOK!=dlg.DoModal())
		return;
	//���û��ָ���ļ���չ������Ϊ�����һ��
	m_strMapFilePath = dlg.GetPathName();

	if(dlg.GetFileExt()==_T(""))
	{
		m_strMapFilePath +=_T(".map");
	}
	m_Map.SaveMapData(m_strMapFilePath);
	
	//���������ڱ���������
	CString str;
	str.LoadString(AFX_IDS_APP_TITLE);
	AfxGetMainWnd()->SetWindowText(dlg.GetFileName()+_T("-")+str);
}




void CMapEditorDoc::OnUpdateFileSave(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
}


void CMapEditorDoc::OnUpdateFileSaveAs(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
}


void CMapEditorDoc::OnResetMemDC(void)
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CMapEditorView* pView = (CMapEditorView*)pFrame->GetActiveView();
	pView->OnResetMemDC();
}


void CMapEditorDoc::OnEditChose()
{
	// TODO: �ڴ���������������
	m_bChose = true;
	m_bBrush = false;
}


void CMapEditorDoc::OnUpdateEditChose(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_bChose)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}


void CMapEditorDoc::OnEditBrush()
{
	// TODO: �ڴ���������������
	m_bBrush = true;

	m_bChose = false;
	
}


void CMapEditorDoc::OnUpdateEditBrush(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	if(m_bBrush)
		pCmdUI->SetCheck();
	else
		pCmdUI->SetCheck(false);
}


void CMapEditorDoc::OnEditDelete()
{
	// TODO: �ڴ���������������
	
	if(m_CurSelObj != -1)
	if(m_iLayerIndex==1)
		m_Map.GetObjectLayer().DelObject(m_CurSelObj);

	UpdateAllViews(NULL);
	
		
}


void CMapEditorDoc::OnUpdateEditDelete(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(!m_bChose)
		pCmdUI->Enable(false);
	pCmdUI->SetCheck(false);
}


//������קͼƬ
void CMapEditorDoc::DrawDrugImage(CDC *pDC,int destX,int destY)
{
	if(m_bBrush&&m_CurSelObj!=-1)
	{
		CSize sz;
		switch (m_iLayerIndex)
		{
		case 0:

			theApp.m_ResMgr.GetTile(m_CurSelObj).Draw(pDC,destX-HALF_TILEWIDTH,destY-HALF_TILEHEIGHT,g_TileWidth,g_TileHeight,128);
			break;
		case 1:	
			sz.cx = theApp.m_ResMgr.GetObj(m_CurSelObj).GetWidth();
			sz.cy = theApp.m_ResMgr.GetObj(m_CurSelObj).GetHeight();
			theApp.m_ResMgr.GetObj(m_CurSelObj).SetHotSpot(sz.cx/2,sz.cy);
			theApp.m_ResMgr.GetObj(m_CurSelObj).Draw(pDC,destX,destY,128);
			break;
		case 2:

			theApp.m_ResMgr.m_BlockImage.Draw(pDC,destX-HALF_GRIDWIDTH,destY-HALF_GRIDHEIGHT,g_GridWidth,g_GridHeight,128);	
			break;
		case 3:

			theApp.m_ResMgr.m_TriggerImage.Draw(pDC,destX-HALF_GRIDWIDTH,destY-HALF_GRIDHEIGHT,g_GridWidth,g_GridHeight,128);	
			break;
		default:
			break;
		}

	}
}


void CMapEditorDoc::OnViewShowrole()
{
	// TODO: �ڴ���������������

	if(m_Map.GetObjectLayer().GetRole().m_ResID==-1)
		m_Map.GetObjectLayer().AddRole(1.5,1.5);
}


void CMapEditorDoc::OnUpdateViewShowrole(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	if(::IsEmpty())
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable();
	pCmdUI->SetCheck(false);//->Enable(false);
}


void CMapEditorDoc::OnAppHelp()
{
	// TODO: �ڴ���������������

	ShellExecute(AfxGetMainWnd()->GetSafeHwnd(),_T("open"),_T("����˵��.txt"),_T(""),_T(""),SW_SHOW );
}


void CMapEditorDoc::OnEditFill()
{
	// TODO: �ڴ���������������
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CSceneResWnd* pSceneWnd = pFrame->GetSceneResWnd();
	int index = pSceneWnd->GetCurSelTileIndex();
	if(index!=-1)
	{
		for(int y=0;y< g_MapHeight;y++)
			for(int x= g_MapWidth-1;x>=0;x--)
			{
				m_Map.GetTileLayer().GetTileSet().at(x+y* g_MapWidth).SetResID(index);
				m_Map.GetTileLayer().GetTileSet().at(x+y* g_MapWidth).SetPos(x,y);
			}
		SetModifiedFlag();
		UpdateAllViews(NULL);
	}
}
