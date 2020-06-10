#pragma once
#include <vector>
using std::vector;
#include "Texture.h"

//ȫ�ֱ����ͺ���

#ifdef __cplusplus
extern "C"
{
#endif


	//��ש�Ŀ�͸�
	extern int		g_TileWidth;
	extern int		g_TileHeight;
	//��ͼ�Ŀ�͸ߣ��Դ�ש����Ϊ��λ
	extern int		g_MapWidth;
	extern int		g_MapHeight;

	extern int		g_GridWidth;
	extern int		g_GridHeight;

	//��ͼͼ����Ӱ�Χ�������ԭ�㣨���Ͻǣ�ƫ�ƣ���Tile��͸�Ϊ��λƫ��
	extern int		g_offsetX;
	extern int		g_offsetY;
	//�Ƿ���ʾ����
	extern bool		g_bShowGrid;
	//��ͼ�Ƿ�ɼ�
	extern bool		g_bVisible;
	

	//��¼��Ԫ��ԭʼ�ߴ�
	extern int		g_OrgTileWidth;
	extern int		g_OrgTileHeight;

#define HALF_TILEWIDTH	g_TileWidth/2
#define HALF_TILEHEIGHT  g_TileHeight/2

#define HALF_GRIDWIDTH	g_GridWidth/2
#define HALF_GRIDHEIGHT  g_GridHeight/2

	//����
	void	DrawGrid(CDC* pDC);
	
	//���ص�ͼ��Χ����
	RECT	GetBoundRect();

	inline SIZE	GetTileSize(){	SIZE sz = { g_TileWidth,g_TileHeight}; return sz;	}
	//�ж��Ƿ�Ϊ��
	bool	IsEmpty();

	//��Ļ����ת����ͼ����
	inline POINT	ViewToMap(int x,int y)
	{
		x = x- g_offsetX;
		y=(y - g_MapWidth *g_TileHeight/2 -g_offsetY)*2;
		
		POINT pt;
		pt.x=(x-y)/g_TileWidth;
		pt.y=(x+y)/g_TileWidth;

		return pt;
	}
	
	//��ͼ����ת����Ļ����
	inline POINT	MapToView(INT x,INT y)
	{
		POINT pt;
		pt.x=(y+x)*g_TileWidth/2;
		pt.y=(g_MapWidth-1+y-x)*g_TileHeight/2;
		//����ƫ��ֵ
		pt.x += g_offsetX;
		pt.y += g_offsetY;
		return pt;
	}
	//��Ļ����ת��Ϊ��Ԫ������
	inline POINT ViewToGrid(int x,int y)
	{
		x = x- g_offsetX;

		y = (y - g_MapWidth*(g_TileWidth/g_GridWidth) *HALF_GRIDHEIGHT - g_offsetY)*2;  

		POINT pt;
		pt.x=(x-y)/g_GridWidth;
		pt.y=(x+y)/g_GridWidth;

		return pt;
	}

	//��ͼ����ת����Ļ����
	inline POINT GridToView(int x,int y)
	{
		POINT pt;
		pt.x=(y+x)*HALF_GRIDWIDTH;
		pt.y=(g_MapWidth*(g_TileWidth/g_GridWidth)-1+y-x)*HALF_GRIDHEIGHT;
		//����ƫ��ֵ
		pt.x += g_offsetX;
		pt.y += g_offsetY;
		return pt;
	}


#ifdef __cplusplus
}
#endif
