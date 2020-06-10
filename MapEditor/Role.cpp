#include "StdAfx.h"
#include "Role.h"
#include "BlockLayer.h"
#include "MapEditor.h"


CRole::CRole(void)
{
	m_Direction = 0;
	m_bVisible = true;
	m_Type = 2;
	m_ResID = 0;
}


CRole::~CRole(void)
{
}
void	CRole::Create(int PosX,int PosY)
{
	m_PosX =PosX; m_PosY = PosY;

}

void	CRole::Update(float fElapsedTime)
{
	if(!m_bVisible)
		return;
	theApp.m_ResMgr.m_Role.UpdateDirection(m_Direction);
	theApp.m_ResMgr.m_Role.Update(fElapsedTime);

	
}
void CRole::Draw(CDC* pDC)
{
	if(!m_bVisible)
		return;
	CPoint destPos;
	destPos = MapToView(m_PosX,m_PosY);
	theApp.m_ResMgr.m_Role.Draw(pDC,destPos.x,destPos.y);
}


bool	CRole::CanPass(int dx,int dy)
{
	//������һ�������꣬���ڵ�ͼ�Ǹ�������
	int iPosX = m_PosX+dx;
	int iPosY = m_PosY+dy;
	//int width =  GetMapWidth();
	//int height = GetMapHeight();
	if(iPosX<g_MapWidth&&iPosX>=0&&iPosY<g_MapHeight&&iPosY>=0)
	{//�ϰ������飬true��ʾ����ͨ����false��ʾ����ͨ��
		if(CBlockLayer::GetInstance()->IsPassable(iPosX,iPosY))
			return true;
	}
	return false;
}