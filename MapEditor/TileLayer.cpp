#include "StdAfx.h"
#include "TileLayer.h"
#include "MapEditor.h"

void CTile::Draw(CDC* pDC)
{ 
	if(m_ResID==-1)
		return;
	POINT pt = MapToView(m_PosX,m_PosY);
	theApp.m_ResMgr.GetTile(m_ResID).Draw(pDC,pt.x,pt.y,g_TileWidth,g_TileHeight);
}


CTileLayer::CTileLayer()
{
	m_bVisible = true;
}
CTileLayer::~CTileLayer()
{
	Destroy();
}
void CTileLayer::Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight)
{
	Destroy();

	m_TileSet.resize(g_MapWidth*g_MapHeight);

}


//����Ļ�ϣ�x,y��������ש������ΪͼƬ�ı�ţ�
void CTileLayer::AddTile(int ResID,int x,int y)
{
	if(ResID==-1)
		return;
	POINT  pt;
	//����Ļ����ת��Ϊ��ͼ����
	pt = ViewToMap(x,y);
	//�ж�Խ��
	if(pt.x>=0&&pt.x<g_MapWidth&&pt.y>=0&&pt.y<g_MapHeight)	
	{
		m_TileSet.at(pt.x+pt.y*g_MapWidth).SetResID(ResID);
		m_TileSet.at(pt.x+pt.y*g_MapWidth).SetPos(pt.x,pt.y);
	}		
}
//ɾ����Ļ�ϣ�x,y������ש
void CTileLayer::DelTile(int x,int y)
{
	POINT  pt;
	pt = ViewToMap(x,y);
	if(pt.x>=0&&pt.x<g_MapWidth&&pt.y>=0&&pt.y<g_MapHeight)	
		m_TileSet.at(pt.x+pt.y*g_MapWidth).SetEmpty();//�ÿ�
}

void CTileLayer::Draw(CDC* pDC)
{
	if(!m_bVisible)
		return;
	//��ͼ��,	����ͼԭ������Ϊ(0,g_MapWidth*g_TileHeight/2)

	for(int y=0;y<g_MapHeight;y++)
		for(int x=g_MapWidth-1;x>=0;x--)
		{	
			m_TileSet.at(x+y*g_MapWidth).Draw(pDC);
		}

}

