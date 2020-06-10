#pragma once

#include "Texture.h"
#include "Animation.h"
#include "Sprite.h"
#include "Monster.h"

//��Դ�����࣬�����еĳ�����Դ���й���
class CResManager
{
public:
	CResManager(void);
	~CResManager(void);
	//���س�����Դ
	void	LoadSceneRes();

	void	LoadSpriteRes();
	//���ش�שtileͼƬ����
	CArray<CTexture>& GetTileRes(){ return m_TileImages; }
	//��������ͼƬ����
	CArray<CTexture>& GetObjRes(){ return m_ObjImages; }
	//���ع��Ｏ��
	CArray<CSprite>&  GetMonsterRes(){ return m_MonsterSet; }
	//���ر��Ϊindex��tileͼƬ
	CTexture&		GetTile(int index){ return m_TileImages.GetAt(index); }
	//���ر��Ϊindex������ͼƬ
	CTexture&		  GetObj(int index){ return m_ObjImages.GetAt(index); }
	//�ͷ���Դ
	void	Destroy();
	//��ָ��Ŀ¼�µ�ͼƬ�ļ�ȫ�����ص�ͼƬ������
	void	LoadImages(CArray<CTexture>& imglist,CString strPath);

public:
	//��Ŵ�שtile��ͼƬ����
	CArray<CTexture> m_TileImages;
	//��������ͼƬ����
	CArray<CTexture> m_ObjImages;
	//��ײ����ͼƬ
	CTexture		m_BlockImage;
	//���������ͼƬ
	CTexture		m_TriggerImage;

	CArray<CTexture> m_SpriteThumb;
	CArray<CSprite> m_MonsterSet;

	CSprite			m_Role;
	

};

