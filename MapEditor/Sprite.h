#pragma once
#include "Animation.h"


enum SPRITESTATE
{
	STAND = 0,
	MOVE  = 1,
	FIGHT = 2,
	DEATH = 3,
};
//�����ࡣ˵����ÿ���������4�鶯�����ֱ���վ�������ߣ��򶷣��������ض�������

class CSprite
{
public:
	CSprite(void);
	~CSprite(void);
	void	Create(LPCSTR AniFile);

	void	Update(float fElapsedTime);
	void	Draw(CDC* pDC,int xDest,int yDest);

	//��ײ���
	bool	CollidesWith(CSprite& spr) ; 
	
	void	SetState(SPRITESTATE state){ m_State= state; }
	
	
	void	UpdateDirection(int direction);
	//�������߶���
	void	UpdateWalk(float fElapsedTime);
	//���¹�������
	void	UpdateAttack(float fElapsedTime);
	//����վ������
	void	UpdateStand(float fElapsedTime);
	//������������
	void	UpdateDeath(float fElapsedTime);
public:
	//վ����������
	CAnimation		m_StandAni;
	//���߶�������
	CAnimation		m_WalkAni;
	//������������
	CAnimation		m_AttackAni;
	//�������ض���
	CAnimation		m_DeathAni;

	//����״̬
	SPRITESTATE	m_State;
	
	//�Ƿ����ڹ���
	bool		m_bIsAttack;
};

