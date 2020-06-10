#include "StdAfx.h"
#include "Texture.h"



CTexture::CTexture(void)
{

	m_SrcWidth = 0;
	m_SrcHeight = 0;
	m_HotX = 0;
	m_HotY = 0;

	m_FileName = _T("");
	//m_fScale = 1.0f;
}

CTexture::~CTexture(void)
{
}

void CTexture::Create(LPCTSTR FileName)
{
	m_FileName = FileName;
	if(m_FileName.IsEmpty())
		return;
	m_Image.Destroy();

	m_Image.Load(FileName);
	m_SrcWidth = m_Image.GetWidth();
	m_SrcHeight = m_Image.GetHeight();
	//Ŀ�����سߴ�Ĭ����Դͼ�ߴ���ͬ
	//m_DestWidth = m_Image.GetWidth();
	//m_DestHeight = m_Image.GetHeight();
	int srcBPP=m_Image.GetBPP();  
	if(srcBPP !=32)
	{
		COLORREF alpha=m_Image.GetPixel(0,0);
		m_Image.SetTransparentColor(alpha);
	}

}
void CTexture::Create(const CImage& srcImage)
{
    if(srcImage.IsNull())  
        return ;  
	//����ԭ��ͼ��  
    m_Image.Destroy();  
    //Դͼ�����  
	m_SrcWidth=srcImage.GetWidth();  
    m_SrcHeight=srcImage.GetHeight();
	////Ŀ�����سߴ�Ĭ����Դͼ�ߴ���ͬ
	//m_DestWidth = m_SrcWidth;
	//m_DestHeight = m_SrcHeight;

    BYTE* srcPtr=(BYTE*)srcImage.GetBits();  
    int srcBPP=srcImage.GetBPP();  
    int srcPitch=srcImage.GetPitch();   
 
    //������ͼ��  
    if(srcBPP==32)   //֧��alphaͨ��  
    {  
        m_Image.Create(m_SrcWidth,m_SrcHeight,srcBPP,1);  
    }  
    else  
    {  
        m_Image.Create(m_SrcWidth,m_SrcHeight,srcBPP,0);  
    }  
    //���ص�ɫ��  
    if(srcBPP<=8&&srcImage.IsIndexed())//��Ҫ��ɫ��  
    {  
        RGBQUAD pal[256];  
        int nColors=srcImage.GetMaxColorTableEntries();  
        if(nColors>0)  
        {       
            srcImage.GetColorTable(0,nColors,pal);  
            m_Image.SetColorTable(0,nColors,pal);//���Ƶ�ɫ�����  
        }     
    }   
    //Ŀ��ͼ�����  
    BYTE *destPtr=(BYTE*)m_Image.GetBits();  
    int destPitch=m_Image.GetPitch();  
    //����ͼ������  
    for(int i=0 ; i<m_SrcHeight;i++)  
    {  
        memcpy( destPtr+i*destPitch, srcPtr+i*srcPitch, abs(srcPitch) );  
    }  
	if (srcBPP == 32) //ȷ�ϸ�ͼ�����Alphaͨ�� 
	for (int i = 0; i < m_SrcWidth; i++)
		for (int j = 0; j < m_SrcHeight; j++)
		{
			byte *pByte = (byte *)m_Image.GetPixelAddress(i, j);
			pByte[0] = pByte[0] * pByte[3] / 255;
			pByte[1] = pByte[1] * pByte[3] / 255;
			pByte[2] = pByte[2] * pByte[3] / 255;
		}
	if(srcBPP!=32)
	{
		COLORREF alpha=m_Image.GetPixel(0,0);
		m_Image.SetTransparentColor(alpha);	
	}
	
 }
void CTexture::Draw(CDC* pDC,int xDest,int yDest,BYTE alpha)
{
	if(m_Image.IsNull())
		return;
	m_Image.AlphaBlend(pDC->m_hDC,xDest-m_HotX,yDest-m_HotY,m_SrcWidth,m_SrcHeight,0,0,m_SrcWidth,m_SrcHeight,alpha);
}

void CTexture::Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight,
				int xSrc,int ySrc,int nSrcWidth,int nSrcHeight)
{
	if(m_Image.IsNull())
		return;
	
	m_Image.Draw(pDC->m_hDC,xDest-m_HotX,yDest-m_HotY,nDestWidth,nDestHeight,xSrc,ySrc,nSrcWidth,nSrcHeight);
}
void CTexture::Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight)
{
	if(m_Image.IsNull())
		return;
	m_Image.Draw(pDC->m_hDC,xDest-m_HotX,yDest-m_HotY,nDestWidth,nDestHeight);
}

void CTexture::Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight,BYTE alpha)
{
	if(m_Image.IsNull())
		return;
	//if(nDestWidth==0)
	//	nDestWidth = m_SrcWidth;
	//if(nDestHeight==0)
	//	nDestHeight = m_SrcHeight;
	m_Image.AlphaBlend(pDC->m_hDC,xDest-m_HotX,yDest-m_HotY,nDestWidth,nDestHeight,0,0,m_SrcWidth,m_SrcHeight,alpha);
	
}