#pragma once

//ʵ���࣬�����࣬��ɫ�࣬�����඼�Ӹ�������

class CEntity
{
public:
	CEntity();
	virtual ~CEntity(void);

	virtual void	Update(float fElapsedTime)=0;
	virtual void	Draw(CDC* pDC)=0;
	
	//��������
	virtual void	SetScale(float scale){}
	//���õ���ͼ�ϣ�x,y��λ��
	virtual void	SetPos(int x,int y){ m_PosX = x;m_PosY=y; }
	virtual POINT	GetPos(){	POINT pt={m_PosX,m_PosY}; return pt; }
	//�ƶ�����dx��dx����λ
	virtual void	Move(int dx,int dy){ m_PosX += dx;m_PosY +=dy; }
	//���ô�С
	virtual void	SetSize(int width,int height){ m_Rect.right = m_Rect.left +width; m_Rect.bottom = m_Rect.top +height; }
	virtual CSize	GetSize(){ return m_Rect.Size(); }
	//���û��ƻ�׼������
	void	SetHotSpot(int x,int y){ m_HotX = x;	m_HotY = y;}
	CPoint	GetHotSpot(){	return CPoint(m_HotX,m_HotY); }
	//����ѡ��
	virtual void	SetChecked(bool bChecked){ m_bChecked = bChecked; }
	virtual bool	GetChecked(){ return m_bChecked; }
	virtual int		GetType(){ return m_Type; }
	//�ÿ�
	virtual void	SetEmpty();
public:
	//ͼƬ���
	int		m_ResID;
	//�ڵ�ͼ�ϵ�����
	int		m_PosX;
	int		m_PosY;
	
	CRect	m_Rect; //��Χ����

	int		m_HotX;
	int		m_HotY;
	//�Ƿ����ѡ��
	bool	m_bChecked;
	//�������ͣ�0���������壬1�����2����ɫ
	int		m_Type;
};

