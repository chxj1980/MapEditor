#pragma once
#include <vector>
using std::vector;

#include "Layer.h"

//�ϰ���㣬���Ƶ�ͼ�Ƿ����ͨ��
class CBlockLayer 
	
{
public:
	CBlockLayer(void);
	~CBlockLayer(void);
	//ȡ�õ�ǰ��Ķ����ʵ��
	static  CBlockLayer*  GetInstance(){ return s_BlockLayer; }
	void	Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight);

	void	Draw(CDC* pDC);
	//�趨�ܷ�ͨ��
	void	SetPassable(int x,int y,bool bPassable){ m_bBlockArray.at(x+y*m_Width)= bPassable; }
	//�жϵ�ͼ��x,y�������ܷ�ͨ��
	bool	IsPassable(int x,int y){	return m_bBlockArray.at(x+y*m_Width); }

	//���õ�ͼ�Ƿ�ɼ�
	void	SetVisible(bool bVisible){ m_bVisible = bVisible; }
	//���ص�ͼ�Ƿ�ɼ�
	bool	GetVisible(){ return m_bVisible; }
	void	Destroy(){	m_bBlockArray.clear(); }

	vector<bool>& GetBlockArray(){ return m_bBlockArray; }
protected:
	//�ϰ������飬true��ʾ����ͨ����false��ʾ����ͨ��
	vector<bool> m_bBlockArray;
	//ÿ�и���
	int			m_Width;
	//ÿ�и���
	int			m_Height;

	bool		m_bVisible;
	static CBlockLayer* s_BlockLayer;
};

inline CBlockLayer* BlockLayer(){	return CBlockLayer::GetInstance(); }