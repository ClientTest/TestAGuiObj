#pragma once
#include "UILib/html/IHtmlView_My.h"
using namespace AGuiObj;

// CTestMyHtmlView �Ի���

class CTestHtmlViewMy : public CDialogEx
{
	DECLARE_DYNAMIC(CTestHtmlViewMy)

public:
	CTestHtmlViewMy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestHtmlViewMy();

// �Ի�������
	enum { IDD = IDD_DLG_TEST_MYHTMLVIEW };

private:
	IHtmlView_My*         m_pMyHtmlView;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnSend();
};
