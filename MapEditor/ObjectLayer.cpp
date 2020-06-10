#include "StdAfx.h"
#include "BlockLayer.h"
#include "ObjectLayer.h"
#include "MapEditor.h"

void CSceneObj::Create(int ResID,INT PosX,INT PosY)
{
	m_ResID =ResID;
	m_PosX =PosX; m_PosY = PosY;

	int width = theApp.m_ResMgr.GetObj(ResID).GetWidth();
	int height = theApp.m_ResMgr.GetObj(ResID).GetHeight();
	CPoint destPos = MapToView(m_PosX,m_PosY);
	m_Rect.left = destPos.x;
	m_Rect.top = destPos.y;
	m_Rect.right = m_Rect.left+width;
	m_Rect.bottom = m_Rect.top+height;

	m_HotX = 0;
	m_HotY = height;
}
void CSceneObj::Update(float fElapsedTime)
{
	
}
void CSceneObj::Draw(CDC* pDC)
{
	if(m_ResID==-1)
		return;
	CPoint destPos = MapToView(m_PosX,m_PosY);

	m_Rect.MoveToXY(destPos);
//	m_Rect.OffsetRect(-m_HotX,-m_HotY);


	theApp.m_ResMgr.GetObj(m_ResID).SetHotSpot(m_HotX,m_HotY);
	m_Rect.OffsetRect(-m_HotX,-m_HotY);
	//��������ѡ�У���͸����ʾ
	if(m_bChecked)
		theApp.m_ResMgr.GetObj(m_ResID).Draw(pDC,destPos.x,destPos.y+HALF_TILEHEIGHT,m_Rect.Width(),m_Rect.Height(),128);
	else
		theApp.m_ResMgr.GetObj(m_ResID).Draw(pDC,destPos.x,destPos.y+HALF_TILEHEIGHT,m_Rect.Width(),m_Rect.Height());
		

}


void CSceneObj::SetScale(float scale)
{
	if(m_ResID ==-1)
		return;
	//���ߴ��¼����
	int width = theApp.m_ResMgr.GetObj(m_ResID).GetWidth();
	int height = theApp.m_ResMgr.GetObj(m_ResID).GetHeight();
	width = int(width *scale);
	height = int(height * scale);
	SetSize(width ,height);
}

void CSceneObj::SetViewPos(int x,int y)
{
	m_Rect.MoveToXY(x,y);
	//int width = m_Rect.Width();
	//int height = m_Rect.Height();
	POINT  pt;
		//��Ļ����ת��Ϊ��ͼ����
	pt = ViewToMap(x,y);
	if(pt.x>=0&&pt.x< g_MapWidth&&pt.y>=0&&pt.y< g_MapHeight )
		SetPos(pt.x,pt.y);
}

//�Զ���������,
bool CompareZOrder(const CSceneObj& obj1, const CSceneObj& obj2)
{
  if(obj1.m_Rect.bottom<obj2.m_Rect.bottom)
	  return true;

  return false;
}

CObjectLayer::CObjectLayer()
{
	m_bVisible =true;
}
CObjectLayer::~CObjectLayer()
{
	Destroy();
}
void CObjectLayer::Create(int MapWidth,int MapHeight,int TileWidth,int TileHeight)
{
	Destroy();

	m_ObjSet.resize(0);
	m_MonsterSet.resize(0);
}
//�������
void CObjectLayer::AddRole(float x,float y)
{
	if(x>=0&&x<g_MapWidth&&y>=0&&y<g_MapHeight )
	{
		//��������
		//if(m_Role.m_ResID==-1)
		//	return;
		////����Ͷ�ŵص�
		//m_Role.Create(x,y);
		////ָ������
		//m_Role.SetDirection(rand()%16);

	}
}
//��ӹ���
void	CObjectLayer::AddMonster(int ResId,int x,int y)
{
	if(ResId==-1)
		return;
	POINT  pt;
	//��Ļ����ת��Ϊ��ͼ����
	pt = ViewToMap(x,y);
	if(pt.x>=0&&pt.x<g_MapWidth&&pt.y>=0&&pt.y<g_MapHeight )
	{
		CMonster pMonster;
	
		pMonster.Create(ResId,pt.x,pt.y);

		//�������һ������
		pMonster.SetDirection(rand()%16);
		m_MonsterSet.push_back(pMonster);
	}
}


//�������
void CObjectLayer::AddObject(CSceneObj& obj)
{
	int index=-1;
	//�ж�λ���Ƿ��غ�
	for(size_t i = 0;i<m_ObjSet.size();i++) 
	{
		if (m_ObjSet.at(i).m_PosX == obj.m_PosX&&m_ObjSet.at(i).m_PosY==obj.m_PosY)
		{
			index = i;
			break;
		}
	}
	if(index!=-1)
		m_ObjSet.at(index) = obj;
	else
		m_ObjSet.push_back(obj);
	
}

void CObjectLayer::Update(float fElapsedTime)
{
	if(m_ObjSet.size()==0)
		return;
	for(size_t i=0;i<m_ObjSet.size();i++)
		m_ObjSet[i].Update(fElapsedTime);
	//��ɫ���£����Ժ�����
//	m_Role.Update(fElapsedTime);
	ZOrderSort();
}

void CObjectLayer::Draw(CDC* pDC)
{
	if(!m_bVisible||m_ObjSet.size()==0)
		return;
	//�ȶ�������������ֵ���Ӵ�С��˳���������������ֵ��ı����ֵС���ڵ�������ʵ���ڵ�Ч��
	
	//�������ֵ�Ӵ�С��˳����ͼ
	for(size_t i=0;i<m_ObjSet.size();i++)
		m_ObjSet[i].Draw(pDC);
	//����ɫ�����Ժ�����
//	m_Role.Draw(pDC);
}
//ʹ��STL�Դ�������������CEntity*���鰴�����ֵ�Ӵ�С˳������
void CObjectLayer::ZOrderSort()
{
	sort(m_ObjSet.begin(),m_ObjSet.end(),CompareZOrder);
}
//tile�ߴ綼һ��������ÿ����С����ͬ
void CObjectLayer::SetSize(int index,int width,int height)
{
	int ResID = m_ObjSet.at(index).m_ResID;
	if(ResID ==-1)
		return;
	//���ߴ��¼����
	m_ObjSet.at(index).SetSize(width,height);

}

//ɾ��һ������
void CObjectLayer::DelObject(int index)
{
	if(index!=-1)
		m_ObjSet.erase(m_ObjSet.begin()+index);
}

void CObjectLayer::DelObject(CSceneObj obj)
{
	for(vector<CSceneObj>::iterator it = m_ObjSet.begin();it!= m_ObjSet.end();) 
	{
		if (*it == obj)
			it = m_ObjSet.erase(it++);
		else
			it++;
	}
	
}

//�ж϶�Ӧ��Ļ��(x,y)���ĵ�ͼ�ϵ������Ƿ�ѡ��
int CObjectLayer::GetCurIndex(CPoint point)
{
	//����һ��ѡ���������ڷ�ѡ��״̬
	for(size_t i=0;i<m_ObjSet.size();i++)
		m_ObjSet.at(i).SetChecked(false);

	for(size_t i=0;i<m_ObjSet.size();i++)
		if(m_ObjSet.at(i).m_Rect.PtInRect(point))
		{
			m_ObjSet.at(i).SetChecked(true);
			return i;
		}
		
	return -1;
}

CSceneObj*	CObjectLayer::GetCurChose(CPoint point)
{

	for(size_t i=0;i<m_ObjSet.size();i++)
		m_ObjSet.at(i).SetChecked(false);
	
	for(size_t i=0;i<m_ObjSet.size();i++)
		if(m_ObjSet.at(i).m_Rect.PtInRect(point))
		{
			m_ObjSet.at(i).SetChecked(true);
			return &m_ObjSet.at(i);
		}
		
	return NULL;
}

CSceneObj* CObjectLayer::GetSceneObj(CSceneObj obj)
{
	
	for(size_t i=0;i<m_ObjSet.size();i++)
	{
		if(m_ObjSet.at(i)==obj)
			return &m_ObjSet.at(i);
	}
	return NULL;
}

void CObjectLayer::SetScale(float scale)
{

	for(size_t i=0;i<m_ObjSet.size();i++)
	{
		m_ObjSet.at(i).SetScale(scale);
	}

}

void CObjectLayer::Destroy()
{	
	
	m_ObjSet.clear(); 
	m_MonsterSet.clear();
}