#pragma once
//ͼƬ�࣬��CImage�ļ򵥷�װ������ͼƬ�ļ��غͻ���

class CTexture
{
public:
	CTexture();
	~CTexture(void);
	CTexture& operator=(const CTexture &texture)
	{	
		if(this==&texture) 
			return *this; Destroy();
													
		this->Create (texture.m_Image);													
		this->m_FileName=texture.m_FileName;																
		this->m_SrcWidth = texture.m_SrcWidth;																
		this->m_SrcHeight = texture.m_SrcHeight;		
		this->m_HotX = texture.m_HotX;
		this->m_HotY = texture.m_HotY;
		return *this;		
	}
	//����һ��ͼͼƬ��Ĭ����ͼƬ���Ͻ���ɫΪ͸��ɫ	
	virtual  void	Create(LPCTSTR FileName);
	//����һ��ͼƬ��Ĭ����ͼƬ���Ͻ���ɫΪ͸��ɫ
	virtual  void	Create(const CImage& srcImage);
	//�򵥻�ͼ
	virtual  void	Draw(CDC* pDC,int xDest,int yDest,BYTE alpha);
	//����Ӧ��������ͼƬ
	virtual  void	Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight);
	//����Ӧ����ͼƬ����͸��ͨ��
	virtual  void	Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight,BYTE alpha);
	//����ԴͼƬ��һ����
	virtual  void	Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight,
					int xSrc,int ySrc,int nSrcWidth,int nSrcHeight);
	//���û��ƻ�׼������
	void	SetHotSpot(int x,int y){ m_HotX = x;	m_HotY = y;}
	CPoint	GetHotSpot(){	return CPoint(m_HotX,m_HotY); }
	//����ͼƬ����ɫ��
	void	SetColorKey(COLORREF alpha){ m_Image.SetTransparentColor(alpha);}
	//����CImage����
	CImage&	GetImage(){	return m_Image; }
	int		GetWidth(){	return m_SrcWidth;	}
	int		GetHeight(){ return m_SrcHeight; }
	CString GetFileName(){ return m_FileName; }
	//�ж��Ƿ�Ϊ��
	bool	IsEmpty(){return m_Image.IsNull(); }
	//����ͼƬ
	void	Destroy(){ m_Image.Destroy(); }
public:
	//ͼƬ���
	int		m_SrcWidth;
	//ͼƬ�߶�
	int		m_SrcHeight;
	//ͼƬԭ������
	int		m_HotX;
	int		m_HotY;
	//�ļ���
	CString		m_FileName;
	//���ͼƬ
	CImage		m_Image;

};

