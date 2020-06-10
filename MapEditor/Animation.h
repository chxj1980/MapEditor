#pragma once
#include "texture.h"
  

//������
class CAnimation :
	public CTexture
{
public:
	CAnimation(void);
	~CAnimation(void);
	//��ʼ������Ҫָ��ÿ��ÿ��֡��,�Լ������ٶ�
	virtual	 void		Create(LPCTSTR Filename, int FramesPerRow, int FramesPerCol,float FPS);
	//�滭
	virtual  void		Draw(CDC* pDC,int xDest,int yDest,int nDestWidth=0,int nDestHeight=0);


	//����һ��֡����  ����ʼ��ţ�����֡����
    void		SetFramesQueue(int StartNum,int length) ;
	//��һ֡  
    void		PrevFrame(float fDeltaTime) ;   
    //��һ֡  
    void		NextFrame(float fDeltaTime);    
	  
    //�趨�����ٶ�
	void		SetSpeed(float FPS) { m_fSpeed=1.0f/FPS; }  
	//��ͶӰ��������ΪͼƬ�ĵײ����м�λ��
	void		SetProjCenter(){ SetHotSpot(m_FrameWidth/2,m_FrameHeight); }
	//�����Ƿ�ɼ� 
	void		SetVisible(bool visible){ m_bVisible=visible;}  
	//�жϵ�ǰһ�ζ����Ƿ񲥷Ž���
	bool		IsFrameEnd(){ return m_nCurFrame==(m_nStartFrame+m_TotalFrames-1); }
	//�趨��ǰ֡���
	void		SetCurFrame(int index){   m_nCurFrame = index ;   }
	//��ȡ�ٶȣ�fps��֡��
	float		GetSpeed() const { return 1.0f/m_fSpeed; }
	//��ȡ��ǰ֡���
	int			GetCurFrame() const { return m_nCurFrame; }
	int			GetFrameWidth(){ return m_FrameWidth; }
	int			GetFrameHeight(){return m_FrameHeight; }
	//��ȡ��ʼ֡���
	int			GetStartFrame() const { return m_nStartFrame; }
    //��ȡһ�ζ������г���  
    int			GetFramesCount() {      return m_TotalFrames ;  }                  
    //��ȡÿ�ж������г��ȣ�ͼƬ�и��  
	int			GetFramesPerRow() {return m_FramesPerRow;}  
	int			GetFramesPerCol() {return m_FramesPerCol;}  
	//���õ�ǰ֡,����֡��ż������֡��Ŷ�Ӧ��ͼƬԴ����λ�ã�
    void		SetFrameRect(int index) ;  
	                                      
public:

	CRect		m_SrcRect;		//Դ����(ͼƬ)
	CRect		m_DestRect;		//Ŀ�ľ��Σ���Ļ��
protected:
	//����һ֡����ʱ��
	float		m_fSpeed;
	float		m_fSinceLastFrame;

	int			m_nStartFrame;	//��ʼ֡���
	int			m_nCurFrame ; //��ǰ֡��� �ӵ�1֡��ʼ��  
	int			m_TotalFrames ; //һ��֡����������Ҫ���Ŷ���֡ 

    int			m_FrameWidth; //ÿ֡��Ⱥ͸߶�
    int			m_FrameHeight;
    int			m_FramesPerRow ; //ͼƬÿ1�ж���֡��          
    int			m_FramesPerCol ; //ͼƬÿ1�ж���֡��
	bool		m_bVisible;
};

