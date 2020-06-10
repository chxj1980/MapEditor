#include "StdAfx.h"
#include "ResManager.h"


CResManager::CResManager(void)
{

}

CResManager::~CResManager(void)
{
	Destroy();
}

void CResManager::LoadSceneRes()
{
	Destroy();
	LoadImages(m_TileImages,CIniFile::GetIniFileString(_T("ResoursePath"),_T("TilePath")));
	LoadImages(m_ObjImages,CIniFile::GetIniFileString(_T("ResoursePath"),_T("ObjectPath")));
	LoadImages(m_ObjImages,CIniFile::GetIniFileString(_T("ResoursePath"),_T("BuildingPath")));	
	LoadImages(m_ObjImages,CIniFile::GetIniFileString(_T("ResoursePath"),_T("NpcPath")));
	//·�ϱ��ͼƬ
	m_BlockImage.Create(CIniFile::GetIniFileString(_T("ResoursePath"),_T("BlockPath")));
	//���������ͼƬ
	m_TriggerImage.Create(CIniFile::GetIniFileString(_T("ResoursePath"),_T("TriggerPath")));
}
void CResManager::LoadSpriteRes()
{
	//���ع�������ͼ
	LoadImages(m_SpriteThumb,CIniFile::GetIniFileString(_T("ResoursePath"),_T("MonsterThumbPath")));

	m_Role.Create("Data/Hero/��ɫ.xml");
	CSprite Monster;
	Monster.Create("Data/Monster/boss.xml");
	m_MonsterSet.Add(Monster);
	Monster.Create("Data/Monster/����.xml");
	m_MonsterSet.Add(Monster);
	Monster.Create("Data/Monster/С��.xml");
	m_MonsterSet.Add(Monster);
	Monster.Create("Data/Monster/Ы��.xml");
	m_MonsterSet.Add(Monster);
	Monster.Create("Data/Monster/���ñ�.xml");
	m_MonsterSet.Add(Monster);
	
}

void CResManager::Destroy()
{
	m_TileImages.RemoveAll();

	m_ObjImages.RemoveAll();

}

void CResManager::LoadImages(CArray<CTexture>& imglist,CString strPath)
{
	//�������ļ�Ŀ¼�µ�����ͼƬ�ļ������ļ��������ַ���������
	CFileFind	finder;
	BOOL bWorking = finder.FindFile(strPath+_T("*.*"));
	while(bWorking)
	{
		bWorking = finder.FindNextFile();
		if(finder.IsDirectory())
			continue;
		CString fileName = finder.GetFileName();
		LPCTSTR pszExt = _tcsrchr(fileName,_T('.'));
		if(pszExt)
		{	//��ΪCImage֧�ֵĸ�ʽ
			if((_tcsicmp(pszExt,_T(".bmp")) == 0)||(_tcsicmp(pszExt,_T(".png")) == 0)
					||(_tcsicmp(pszExt,_T(".tif")) == 0)||(_tcsicmp(pszExt,_T(".tiff")) == 0)
					||(_tcsicmp(pszExt,_T(".jpg")) == 0)||(_tcsicmp(pszExt,_T(".jpeg")) == 0)
					||(_tcsicmp(pszExt,_T(".gif")) == 0))
			{
				CTexture image;
				image.Create(strPath+fileName);
				imglist.Add(image);
			}
		}
	}
	finder.Close();
}

