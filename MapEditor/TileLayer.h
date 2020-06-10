#pragma once

#include "Layer.h"

//��ש�࣬�ذ�ש
class CTile
{
public:
	CTile():m_ResID(-1),m_PosX(0),m_PosY(0){}
	~CTile(){}

	void	Draw(CDC* pDC);
	//���ش�ש��Ӧ��ͼƬ���
	int		GetResID(){ return m_ResID; }
	//�趨��שͼƬ���
	void	SetResID(int ResID){ m_ResID = ResID; }
	//���ش�ש�ڵ�ͼ�ϵ�λ��
	CPoint	GetPos(){	return CPoint(m_PosX,m_PosY); }
	//�趨��שλ��
	void	SetPos(int x,int y){ m_PosX = x;m_PosY=y; }

	//�ÿ�
	void	SetEmpty(){ m_ResID=-1;m_PosX=0;m_PosY=0; }
public:
	//��ש��Ӧ��ͼƬ���
	int		m_ResID;
	//�ڵ�ͼ�ϵ�����
	int		m_PosX;
	int		m_PosY;

	int		m_HotX;
	int		m_HotY;
	
};


//�����
class CTileLayer
{
public:
	CTileLayer();
	virtual ~CTileLayer();
	//���������
	void	Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight);
	//����
	void	Draw(CDC* pDC);

	//ɾ����Ļ�ϣ�x,y�����Ĵ�ש
	void	DelTile(int x,int y);
	//����ש������ΪͼƬ�ı�ţ���Ļ����
	void	AddTile(int ResID,int x,int y);	

	void	Destroy(){	m_TileSet.clear(); }

	//���õ�ͼ�Ƿ�ɼ�
	void	SetVisible(bool bVisible){ m_bVisible = bVisible; }
	//���ص�ͼ�Ƿ�ɼ�
	bool	GetVisible(){ return m_bVisible; }

	//���ش�ש����
	vector<CTile>& GetTileSet(){ return m_TileSet; }
protected:
	//��ש����
	vector<CTile>	m_TileSet;
	bool			m_bVisible;
};