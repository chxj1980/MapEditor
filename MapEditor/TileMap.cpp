#include "StdAfx.h"
#include "TileMap.h"
#include "MapEditor.h"


CTileMap::CTileMap(void)
{

}


CTileMap::~CTileMap(void)
{
	Destroy();
}
void	CTileMap::Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight)
{
	Destroy();
	
	g_MapWidth=MapWidth;
	g_MapHeight=MapHeight;
	g_TileWidth=TileWidth;
	g_TileHeight=TileHeight;

	g_OrgTileWidth = TileWidth;
	g_OrgTileHeight = TileHeight;
	m_TileLayer.Create(MapWidth, MapHeight, TileWidth, TileHeight);
	//������ʼ��
	m_ObjectLayer.Create(MapWidth, MapHeight, TileWidth, TileHeight);
	//�ϰ���
	m_BlockLayer.Create(MapWidth, MapHeight, TileWidth, TileHeight);
	//�¼���
	m_EventLayer.Create(MapWidth, MapHeight, TileWidth, TileHeight);
	
}
void	CTileMap::Update(float fElapsedTime)
{
	if(!g_bVisible||IsEmpty())
		return;

	m_ObjectLayer.Update(fElapsedTime);
}
void	CTileMap::Draw(CDC* pDC)
{
	if(!g_bVisible||IsEmpty())
		return;
	//�����
	m_TileLayer.Draw(pDC);
//	if(g_bShowGrid)
		::DrawGrid(pDC);
	//�����
	m_ObjectLayer.Draw(pDC);
	//�ϰ���
	m_BlockLayer.Draw(pDC);
	//�¼���
	m_EventLayer.Draw(pDC);
	
}


//����
void	CTileMap::SetScale(float scale)
{	
	g_TileWidth = g_OrgTileWidth*scale; 
	g_TileHeight = g_OrgTileHeight*scale;
}

//�趨��ͼ����ƫ�ƣ�cx����ƫ�ƣ�cy����ƫ��
void	CTileMap::SetOffSet(int cx,int cy)
{
	g_offsetX =cx ;
	g_offsetY = cy;
}


void	CTileMap::Destroy()
{
	m_TileLayer.Destroy();
	//�����
	m_ObjectLayer.Destroy();
	//�ϰ���
	m_BlockLayer.Destroy();
	//�¼���
	m_EventLayer.Destroy();
}

bool CTileMap::SaveMapData(LPCTSTR filename)
{
	MAPHEADER MapHeader;
	MapHeader.MapWidth=g_MapWidth;
	MapHeader.MapHeight=g_MapHeight;
	MapHeader.TileWidth= g_TileWidth;
	MapHeader.TileHeight=g_TileHeight;
	MapHeader.SceneObjCount= m_ObjectLayer.GetObjSet().size();
	MapHeader.MonsterCount = m_ObjectLayer.GetMonsterSet().size();
	FILE* fp;
	if(0 != _tfopen_s(&fp, filename, _T("wb")))
		return false;

	//�ȴ����ļ�ͷ��Ϣ
	fwrite(&MapHeader,sizeof(MapHeader),1,fp);

	size_t	size = m_TileLayer.GetTileSet().size();
	CTile tile;
	//�ȴ���TileLayer������
	for(size_t i=0;i<size;i++)
	{
		tile = m_TileLayer.GetTileSet().at(i);
		fwrite(&tile,sizeof(tile),1,fp);
	}

	//�ٴ���ObjectLayer����
	CSceneObj	obj;
	CRole		role;
	CMonster	monster;

	for(int i=0;i< MapHeader.SceneObjCount;i++)
	{	//�ж���������
	
		obj = m_ObjectLayer.GetObjSet().at(i);
		//��¼��������
		fwrite(&obj,sizeof(obj),1,fp);
	}

	for(int i=0;i< MapHeader.MonsterCount;i++)
	{
		monster = m_ObjectLayer.GetMonsterSet().at(i);
		fwrite(&monster,sizeof(monster),1,fp);
	}
		
	role = m_ObjectLayer.GetRole();	
	fwrite(&role,sizeof(role),1,fp);
	
	
	//�ٴ���BlockLayer����
	size = m_BlockLayer.GetBlockArray().size();
	for(size_t i=0;i<size;i++)
	{
		bool bPassable = m_BlockLayer.GetBlockArray().at(i);
		fwrite(&bPassable,sizeof(bPassable),1,fp);
	}
	//�ٴ���EventLayer����
	size = m_EventLayer.GetTriggerArray().size();
	fwrite(&size,sizeof(size),1,fp);
	for(size_t i=0;i<size;i++)
	{

		CTrigger trigger = m_EventLayer.GetTriggerArray().at(i);
		fwrite(&trigger,sizeof(trigger),1,fp);
	}

	fclose(fp);
	return true;
}

//���ص�ͼ����
bool CTileMap::LoadMapData(LPCTSTR filename)
{
	FILE* fp;
	if(0 != _tfopen_s(&fp, filename, _T("rb")))
		return false;
	MAPHEADER MapHeader;
	fread(&MapHeader,sizeof(MapHeader),1,fp);
	Create(MapHeader.MapWidth,MapHeader.MapHeight,MapHeader.TileWidth,MapHeader.TileHeight);

	//�ȶ�ȡTileLayer������
	CTile tile;
	for(size_t i=0;i<m_TileLayer.GetTileSet().size();i++)
	{
		fread(&tile,sizeof(tile),1,fp);
		m_TileLayer.GetTileSet().at(i) = tile;
	}

	//�ٶ�ȡObjectLayer����
	
	CSceneObj	obj;
	CRole		role;
	CMonster	monster;
	for(int i=0;i<MapHeader.SceneObjCount;i++)
	{
			fread(&obj,sizeof(obj),1,fp);
			m_ObjectLayer.GetObjSet().push_back(obj);
	}

	for(int i=0;i<MapHeader.MonsterCount;i++)
	{
		fread(&monster,sizeof(monster),1,fp);
		m_ObjectLayer.GetMonsterSet().push_back(monster);
	}
	
	fread(&role,sizeof(role),1,fp);
	m_ObjectLayer.SetRole(role);
		
	//�ٶ�ȡBlockLayer����
	bool bPassable;
	for(size_t i=0;i<m_BlockLayer.GetBlockArray().size();i++)
	{
		fread(&bPassable,sizeof(bPassable),1,fp);
		m_BlockLayer.GetBlockArray().at(i) = bPassable;
	}
	//�ٶ�ȡEventLayer����
	int size = 0;
	fread(&size,sizeof(size),1,fp);
	for(int i=0;i<size;i++)
	{
		CTrigger trigger;
		fread(&trigger,sizeof(trigger),1,fp);
		m_EventLayer.GetTriggerArray().push_back(trigger);
	}

	fclose(fp);
	
	return true;
}



