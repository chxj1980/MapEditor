#pragma once
#include "texture.h"


class CCurSelImage :
	public CTexture
{
public:
	CCurSelImage(void);
	~CCurSelImage(void);

	//����Ӧ��������ͼƬ
	void	Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight);

};

