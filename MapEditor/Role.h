#pragma once
//#include "Animation.h"
#include "Entity.h"

//Ԥ���ӿڣ���ʱû����
class CRole:public CEntity
{
public:
	CRole();
	~CRole(void);
	void	Create(int PosX,int PosY);
	void	Update(float fElapsedTime);
	void	Draw(CDC* pDC);
	void	SetDirection(int dir){ 	m_Direction = dir; }
	bool	CanPass(int dx,int dy);

public:
	bool	m_bVisible;
	//��Է���
	int		m_Direction;
};

