#pragma once
#include "Entity.h"

//Ԥ���ӿڣ���ʱûʲô��

class CCreature:public CEntity
{
public:
	CCreature(void);
	~CCreature(void);

	void	Create(int PosX,int PosY);
	void	Update(float fElapsedTime);
	void	Draw(CDC* pDC);
	void	SetDirection(int dir){ 	m_Direction = dir; }
	bool	CanPass(int dx,int dy);

public:
	bool	m_bVisible;
	//��Է���
	int			m_Direction;
};

