#pragma once


// CNewMapDlg �Ի���

class CNewMapDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewMapDlg)

public:
	CNewMapDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewMapDlg();

// �Ի�������
	enum { IDD = IDD_NEWMAPDLG };
	int	m_iMapWidth;
	int m_iMapHeight;
	int m_iTileWidth;
	int m_iTileHeight;

	CComboBox m_ctrTileSize;
	CString		m_strSize;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCreatemap();
	virtual BOOL OnInitDialog();
};
