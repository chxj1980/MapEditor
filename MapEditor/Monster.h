#pragma once
#include "Animation.h"
#include "Role.h"
//Ԥ���ӿڣ���ʱû����


class CMonster:public CRole
{
public:
	CMonster(void);
	~CMonster(void);
	void	Create(int ResID,int PosX,int PosY);
	void	Update(float fElapsedTime);
	void	Draw(CDC* pDC);

	//�������߶���
	void	UpdateWalk(float fElapsedTime);
	////���¹�������
	//void	UpdateAttack(float fElapsedTime);
	//������
	void	DetectDistance(CRole *role);
public:
	int		m_fDistance;
};

