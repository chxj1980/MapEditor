#pragma once
#include <algorithm>
#include <vector>
using std::vector;
#include "Layer.h"
#include "Entity.h"
#include "Role.h"
#include "Monster.h"

//������
class CSceneObj:public CEntity
{
public:
	CSceneObj(){ m_Type = 0;}
	~CSceneObj(){}
	BOOL operator==(const CSceneObj& obj) const throw()
	{
		return (m_Rect==obj.m_Rect);
	}

	void	Create(int ResID,INT PosX,INT PosY);
	void	Update(float fElapsedTime);
	void	Draw(CDC* pDC);
	//��������
	void	SetScale(float scale);

	void	SetViewPos(int x,int y);

};


//����ͼ���࣬ÿ����ͼ���ɷ���MapWidth*MapHeight������
class CObjectLayer 
{
public:
	CObjectLayer(void);
	~CObjectLayer(void);
	void	Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight);
	void	Update(float fElapsedTime);
	//����
	void	Draw(CDC* pDC);
	//�������
	void	ZOrderSort();

	//ɾ����index������
	void	DelObject(int index);
	//ɾ��ָ��������
	void	DelObject(CSceneObj obj);

	//�������
	void	AddObject(CSceneObj& obj);
	//�������
	void	AddRole(float x,float y);
	//��ӹ���
	void	AddMonster(int ResId,int x,int y);
	//�趨��ͼ�ϣ�x,y��������ĳߴ�,
	void	SetSize(int index,int width,int height);

	void	SetScale(float scale);
	void	Destroy();

	//���õ�ͼ�Ƿ�ɼ�
	void	SetVisible(bool bVisible){ m_bVisible = bVisible; }
	//���ص�ͼ�Ƿ�ɼ�
	bool	GetVisible(){ return m_bVisible; }
	//��ȡ��ǰ��ͼ�ϱ�ѡ�е������������������δѡ�У�����-1
	int		GetCurIndex(CPoint point);
	CSceneObj*		GetCurChose(CPoint point);

	CSceneObj*		GetSceneObj(CSceneObj obj);
	CRole&	GetRole(){	return m_Role;	}
	void	SetRole(CRole& role){ if(m_Role.m_ResID==-1) m_Role = role; }
	vector<CSceneObj>& GetObjSet(){	return m_ObjSet; }
	vector<CMonster>&  GetMonsterSet(){	return m_MonsterSet; }
protected:
	vector<CSceneObj>	m_ObjSet;
	vector<CMonster>	m_MonsterSet;
	//��Ϸ�д��ڵ�Ψһһ������
	CRole	 m_Role;
	
	bool	m_bVisible;
};

