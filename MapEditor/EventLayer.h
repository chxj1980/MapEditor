#pragma once
#include "Layer.h"

//��ͼ�¼��㣬ָ���ں�λ�ô�������ת��,

//�������ṹ
class CTrigger
{
public:
	CTrigger():m_TriggerID(0),m_PosX(0),m_PosY(0),m_MapID(0),m_iStartX(0),m_iStartY(0),m_Direction(0){}
	CTrigger(int TriggrtID,int MapID,int startX,int startY,int dir):m_TriggerID(TriggrtID),
				m_MapID(MapID),m_iStartX(startX),m_iStartY(startY),m_Direction(dir){ m_PosX=0;m_PosY = 0;}
	CTrigger& operator =(const CTrigger& trigger)
	{
		if(&trigger==this)
			return *this;
		m_TriggerID = trigger.m_TriggerID;;
		m_PosX = trigger.m_PosX;
		m_PosY = trigger.m_PosY;
		m_MapID = trigger.m_MapID;
		m_iStartX = trigger.m_iStartX;
		m_iStartY = trigger.m_iStartY;
		m_Direction = trigger.m_Direction;
		return *this;
	}
	~CTrigger(){}

	int		GetTriggerID(){ return m_TriggerID; }
	int		GetPosX(){ return m_PosX; }
	int		GetPosY(){ return m_PosY; }
	int		GetMapID(){ return m_MapID; }
	int		GetStartPosX(){ return m_iStartX; }
	int		GetStartPosY(){ return m_iStartY; }
	int		GetDirection(){ return m_Direction; }

	void	SetTriggerID(int id){  m_TriggerID = id; }
	void	SetPosX(int x){ m_PosX = x; }
	void	SetPosY(int y){ m_PosY = y; }
	void	SetMapID(int id){ m_MapID = id; }
	void	SetStartPosX(int startX){  m_iStartX = startX; }
	void	SetStartPosY(int startY){  m_iStartY = startY; }
	//0~7�ֱ��ʾ8������
	void	SetDirection(int dir){  m_Direction = dir; }
public:
	int		m_TriggerID; //������ID���
	int		m_PosX;		//�������ڵ�ͼ�ϵ�X����
	int		m_PosY;		//�������ڵ�ͼ�ϵ�Y����
	int		m_MapID; //ָ������͵ĵ�ͼ�ļ���
	int		m_iStartX;	//���͵���һ����ͼ���������ʼX����
	int		m_iStartY;	//���͵���һ����ͼ���������ʼY����
	int		m_Direction;	//���͵���һ����ͼ���������Եķ���
	
};


//�¼���
class CEventLayer
{
public:
	CEventLayer(void);
	~CEventLayer(void);
	//����
	void	Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight);
	//����
	void	Draw(CDC* pDC);
	//���ش���������
	vector<CTrigger>& GetTriggerArray(){ return m_TriggerArray; }
	//����ID��ȡ������
	CTrigger& GetTriggerByID(int id);
	//���ô�����
	void	AddTrigger(CTrigger& trigger){	m_TriggerArray.push_back(trigger);	}
	//ɾ��λ�ڵ�ͼ�ϣ�x��y�����Ĵ�����
	void	DelTrigger(int x,int y);
	//�ж�λ�ڵ�ͼ��x��y�����Ƿ��Ǵ�����
	bool	IsTrigger(int x,int y);
	//�ͷ�
	void	Destroy(){	m_TriggerArray.clear(); }

	//���õ�ͼ�Ƿ�ɼ�
	void	SetVisible(bool bVisible){ m_bVisible = bVisible; }
	//���ص�ͼ�Ƿ�ɼ�
	bool	GetVisible(){ return m_bVisible; }
protected:
	//���������飬��ͼ������һ��ͼ�鶼�п����Ǵ�����
	vector<CTrigger> m_TriggerArray;
	bool			m_bVisible;
};

