#pragma once
#include "Layer.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "BlockLayer.h"
#include "EventLayer.h"


struct MAPHEADER
{
	int MapWidth;
	int MapHeight;
	int TileWidth;
	int TileHeight;
	int SceneObjCount;
	int MonsterCount;
};

class CTileMap 
	
{
public:
	CTileMap(void);
	virtual ~CTileMap(void);

	//����
	void	Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight);
	//����
	void	Update(float fElapsedTime);
	//����
	void	Draw(CDC* pDC);
	//���ص�ͼ����
	bool	LoadMapData(LPCTSTR filename);
	//����ͼ���ݴ���.map�ļ���
	bool	SaveMapData(LPCTSTR filename);

	CTileLayer&	GetTileLayer(){	return m_TileLayer; }
	CObjectLayer&	GetObjectLayer(){ return m_ObjectLayer; }
	CBlockLayer&	GetBlockLayer(){ return m_BlockLayer; }
	CEventLayer&	GetEventLayer(){ return m_EventLayer; }


	//���ŵ�ͼ
	void	SetScale(float scale);
	//������ͼ
	void	SetOffSet(int cx,int cy);
	//������Ӿ��γߴ�
	CSize	GetBoundSize(){ return CSize((g_MapWidth + g_MapHeight)*g_TileWidth/2 ,(g_MapWidth + g_MapHeight)*g_TileHeight/2);}
	void	Destroy();
	
public:
	//�����
	CTileLayer		m_TileLayer;
	//�����
	CObjectLayer	m_ObjectLayer;
	//�ϰ���
	CBlockLayer		m_BlockLayer;
	//�¼���
	CEventLayer		m_EventLayer;
	
};

