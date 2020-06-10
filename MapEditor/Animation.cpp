#include "StdAfx.h"
#include "Animation.h"


CAnimation::CAnimation(void)
{

	ZeroMemory(&m_SrcRect,sizeof(m_SrcRect));
	m_FrameWidth=0;
	m_FrameHeight=0;
	m_fSinceLastFrame=-1.0f;
	m_fSpeed=0;
	m_nCurFrame=0;//��ǰ֡���
	m_nStartFrame=0;
	m_TotalFrames=0;
	m_SrcRect.SetRectEmpty();		//Դ����(ͼƬ)
	m_DestRect.SetRectEmpty();
	m_bVisible = true;
}


CAnimation::~CAnimation(void)
{
}


void CAnimation::Create(LPCTSTR Filename, int FramesPerRow, int FramesPerCol,float FPS)
{
	CTexture::Create(Filename);
	m_FramesPerRow=FramesPerRow;
	m_FramesPerCol=FramesPerCol;

	m_FrameWidth=GetWidth()/m_FramesPerRow;
	m_FrameHeight=GetHeight()/m_FramesPerCol;
	//�����ٶ�
	SetSpeed(FPS);
	//����֡����  

	SetFrameRect(m_nCurFrame);
}

//����֡����  
void CAnimation::SetFramesQueue(int StartNum,int length)   
{  
    //��ֵ�������г���  
	m_nStartFrame = StartNum;
    m_TotalFrames = length ;   
}  



//����һ֡  
void CAnimation::PrevFrame(float fDeltaTime)  
{  
	//����ÿ��������֡ʱ���
	if(m_fSinceLastFrame == -1.0f)
		m_fSinceLastFrame=0.0f;
	else
		m_fSinceLastFrame += fDeltaTime;//�ۼ�ʱ��Ƭ��
	//��ʱ�����ڲ���һ֡����ʱ��ʱ���Ž���ѭ��
	while(m_fSinceLastFrame >= m_fSpeed)
	{	
		m_fSinceLastFrame -= m_fSpeed;
		if( m_nCurFrame <= m_nStartFrame||m_nCurFrame > (m_nStartFrame+m_TotalFrames-1) )  
		{  
		    m_nCurFrame = m_nStartFrame+m_TotalFrames-1 ;  
		}     
		else  
		{  
			m_nCurFrame-- ;  
		}  
	
	}
	SetFrameRect(m_nCurFrame);

}  
//������һ֡  
void CAnimation::NextFrame(float fDeltaTime)   
{  
	//����ÿ��������֡ʱ���
	if(m_fSinceLastFrame == -1.0f)
		m_fSinceLastFrame=0.0f;
	else
		m_fSinceLastFrame += fDeltaTime;//�ۼ�ʱ��Ƭ��
	//��ʱ�����ڲ���һ֡����ʱ��ʱ���Ž���ѭ��
	while(m_fSinceLastFrame >= m_fSpeed)
	{	
		m_fSinceLastFrame -= m_fSpeed;
		//������Ž������ص���ʼ֡���
		if(m_nCurFrame<m_nStartFrame||m_nCurFrame >= (m_nStartFrame+m_TotalFrames-1) )  
		{  
			m_nCurFrame = m_nStartFrame ;  
		}  
		else  
		{  //��ǰ֡���
			m_nCurFrame++ ;  	
		}  
	}  
	//�л�֡
	SetFrameRect(m_nCurFrame);
}  

//���ƾ���  
void CAnimation::Draw(CDC* pDC,int xDest,int yDest,int nDestWidth,int nDestHeight)   
{  
    if(!m_bVisible)  
		return ;
	if(nDestWidth ==0)
		nDestWidth=m_SrcRect.Width();
	if(nDestHeight==0)
		nDestHeight=m_SrcRect.Height();
	return CTexture::Draw(pDC,xDest,yDest,nDestWidth,nDestHeight,m_SrcRect.left,m_SrcRect.top,m_SrcRect.Width(),m_SrcRect.Height());
		
}  

//���ݵ�ǰ֡��ţ��������Ӧ��ԴͼƬ����λ��
void CAnimation::SetFrameRect(int index)
{
	//Դ����Y���� �� m_nCurFrame��ǰ֡��ţ�m_FramesPerRowÿ��֡��
    int Y = m_nCurFrame / m_FramesPerRow;  
    //Դ����X����   
    int X = m_nCurFrame - Y * m_FramesPerRow;     

	m_SrcRect.left	= X*m_FrameWidth;
    m_SrcRect.top	= Y*m_FrameHeight;
    m_SrcRect.right	= m_SrcRect.left + m_FrameWidth;
    m_SrcRect.bottom	= m_SrcRect.top + m_FrameHeight;
	
}

//void CAnimation::MoveInMap(int dx,int dy)
//{
//	m_PosX+=dx;
//	m_PosY+=dy;
//}
////Ͷ�ŵ���ͼ�ϣ�x,y��λ��
//void CAnimation::MoveToMap(int x,int y)
//{
//	m_PosX = x;
//	m_PosY = y;
//}