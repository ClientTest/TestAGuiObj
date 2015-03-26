#pragma once

#include "UILib/html/IHtmlCtrl_My.h"

using namespace AGuiObj;

// CTestHtmlCtrl 对话框

class CTestHtmlCtrl : public CDialogEx,public CMyHtmlHrefListener
{
	DECLARE_DYNAMIC(CTestHtmlCtrl)

public:
	CTestHtmlCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestHtmlCtrl();

// 对话框数据
	enum { IDD = IDD_DLG_HTMLCTRL };

private:
	IHtmlCtrl_My*         m_pHtmlCtrl;
	CString              m_strRecordPathFile;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnSend();
	afx_msg void OnBnClickedCheckSetBg();
	afx_msg void OnBnClickedBtnClean();
	afx_msg void OnBnClickedBtnRecord();
	afx_msg void OnBnClickedBtnAutoscroll();

	virtual void OnReceiveHtmlHref(CString strMsg);
};
