#include "StdAfx.h"
#include "EventLayer.h"
#include "MapEditor.h"

CEventLayer::CEventLayer(void)
{
	m_bVisible =true;
}


CEventLayer::~CEventLayer(void)
{
	Destroy();
}
void CEventLayer::Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight)
{
	Destroy();

	m_TriggerArray.resize(0);
	
}
void CEventLayer::Draw(CDC* pDC)
{
	if(!m_bVisible)
		return;
	POINT pt;
	for(size_t i=0;i<m_TriggerArray.size();i++)
	{
		int x = m_TriggerArray.at(i).GetPosX();
		int y = m_TriggerArray.at(i).GetPosY();
		pt = GridToView(x,y);
		theApp.m_ResMgr.m_TriggerImage.Draw(pDC,pt.x,pt.y,g_GridWidth,g_GridHeight);
	}

}

//�ж�λ�ڵ�ͼ��x��y�����Ƿ��Ǵ�����
bool CEventLayer::IsTrigger(int x,int y)
{	//�������������飬�ж��Ƿ��д�����������ָ�������غ�
	for(size_t i=0;i<m_TriggerArray.size();i++)
		if(m_TriggerArray.at(i).GetPosX()==x&&m_TriggerArray.at(i).GetPosY()==y)
			return true;
	return false;
}

CTrigger& CEventLayer::GetTriggerByID(int id)
{
	for(size_t i=0;i<m_TriggerArray.size();i++)
		if(m_TriggerArray.at(i).GetTriggerID() == id)
			return m_TriggerArray.at(i);
	return CTrigger(0,0,0,0,0);
}

//ɾ��λ�ڵ�ͼ�ϣ�x��y�����Ĵ�����
void CEventLayer::DelTrigger(int x,int y)
{

	for(size_t i=0;i<m_TriggerArray.size();i++)
		if(m_TriggerArray.at(i).GetPosX()==x&&m_TriggerArray.at(i).GetPosY()==y)
		{
			m_TriggerArray.erase(m_TriggerArray.begin()+ i);
			return;
		}
}