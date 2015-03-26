#pragma once
#include "UILib/html/IHtmlView_My.h"
using namespace AGuiObj;

// CTestMyHtmlView 对话框

class CTestHtmlViewMy : public CDialogEx
{
	DECLARE_DYNAMIC(CTestHtmlViewMy)

public:
	CTestHtmlViewMy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestHtmlViewMy();

// 对话框数据
	enum { IDD = IDD_DLG_TEST_MYHTMLVIEW };

private:
	IHtmlView_My*         m_pMyHtmlView;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnSend();
};
