#include "StdAfx.h"
#include "Sprite.h"
//Ԥ���ӿ�
#include "TinyXml\tinyxml.h"

#ifdef _DEBUG
#pragma comment(lib,"TinyXml/TinyXmld.lib")
#else
#pragma comment(lib,"TinyXml/TinyXml.lib")
#endif


CSprite::CSprite(void)
{
	
	m_State= STAND;
	m_bIsAttack = false;
	
}


CSprite::~CSprite(void)
{
}

void	CSprite::Create(LPCSTR AniFile)
{
	TiXmlDocument* pDoc = new TiXmlDocument(AniFile);
	if(!pDoc->LoadFile())
		return;

	TiXmlElement* pRoot = pDoc->FirstChildElement("Sprite");
	TiXmlElement* pAniInfo = pRoot->FirstChildElement("animation");
	
	USES_CONVERSION;
	CString ResPath = A2T(pAniInfo->Attribute("ResPath"));
	int FramesPerRow = atoi( pAniInfo->Attribute("RowFrames"));
	int FramesPerCol = atoi( pAniInfo->Attribute("ColFrames"));
	int fps = atoi( pAniInfo->Attribute("fps"));
	m_WalkAni.Create(ResPath,FramesPerRow,FramesPerCol,fps);
	m_WalkAni.SetHotSpot(m_WalkAni.GetFrameWidth()/2,m_WalkAni.GetFrameHeight());

	pAniInfo = pAniInfo->NextSiblingElement();
	ResPath = A2T(pAniInfo->Attribute("ResPath"));
	FramesPerRow = atoi( pAniInfo->Attribute("RowFrames"));
	FramesPerCol = atoi( pAniInfo->Attribute("ColFrames"));
	fps = atoi( pAniInfo->Attribute("fps"));
	m_StandAni.Create(ResPath,FramesPerRow,FramesPerCol,fps);
	m_StandAni.SetHotSpot(m_StandAni.GetFrameWidth()/2,m_StandAni.GetFrameHeight());

	pRoot->NextSiblingElement();
	ResPath = A2T(pAniInfo->Attribute("ResPath"));
	FramesPerRow = atoi( pAniInfo->Attribute("RowFrames"));
	FramesPerCol = atoi( pAniInfo->Attribute("ColFrames"));
	fps = atoi( pAniInfo->Attribute("fps"));
	m_AttackAni.Create(ResPath,FramesPerRow,FramesPerCol,fps);
	m_AttackAni.SetHotSpot(m_AttackAni.GetFrameWidth()/2,m_AttackAni.GetFrameHeight());

	pRoot->NextSiblingElement();
	ResPath = A2T(pAniInfo->Attribute("ResPath"));
	FramesPerRow = atoi( pAniInfo->Attribute("RowFrames"));
	FramesPerCol = atoi( pAniInfo->Attribute("ColFrames"));
	fps = atoi( pAniInfo->Attribute("fps"));
	m_DeathAni.Create(ResPath,FramesPerRow,FramesPerCol,fps);
	m_DeathAni.SetHotSpot(m_DeathAni.GetFrameWidth()/2,m_DeathAni.GetFrameHeight());
	delete pDoc;
}
void	CSprite::Update(float fElapsedTime)
{

	//վ��
	UpdateStand(fElapsedTime);
}
void	CSprite::Draw(CDC* pDC,int xDest,int yDest)
{
	switch (m_State)
	{
	case MOVE:
		m_WalkAni.Draw(pDC,xDest, yDest);
		break;
	case FIGHT:
		m_AttackAni.Draw(pDC,xDest, yDest);
		break;
	case STAND:
		m_StandAni.Draw(pDC,xDest, yDest);
		break;
	case DEATH:
		m_DeathAni.Draw(pDC,xDest, yDest);
		break;
	default:
		return;
	}
}


void	CSprite::UpdateDirection(int direction)
{
	m_StandAni.SetFramesQueue(direction*m_StandAni.GetFramesPerRow(),m_StandAni.GetFramesPerCol());
	m_WalkAni.SetFramesQueue(direction*m_WalkAni.GetFramesPerRow(),m_WalkAni.GetFramesPerCol());
	m_AttackAni.SetFramesQueue(direction*m_AttackAni.GetFramesPerRow(),m_AttackAni.GetFramesPerCol());
	m_DeathAni.SetFramesQueue(direction*m_DeathAni.GetFramesPerRow(),m_DeathAni.GetFramesPerCol());
}

//����վ������
void	CSprite::UpdateStand(float fElapsedTime)
{
	SetState(STAND);
	m_StandAni.NextFrame(fElapsedTime);
}
//������������
void	CSprite::UpdateDeath(float fElapsedTime)
{
	SetState(DEATH);
	m_DeathAni.NextFrame(fElapsedTime);
}

//��ײ���  
bool CSprite::CollidesWith( CSprite& spr)  
{  
	RECT rect;
	//�жϰ�Χ�����Ƿ��ཻ
	if(IntersectRect(&rect,&spr.m_WalkAni.m_DestRect,&m_WalkAni.m_DestRect))
		return true;
    return false ;  
}  

