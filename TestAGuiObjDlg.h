
// TestAGuiObjDlg.h : 头文件
//

#pragma once

#include "MfcLib/AGuiFun/AGuiPath.h"
#include "AGuiLOG/IAGuiLOG.h"

#include "TestDBUtil.h"
#include "TestHtmlCtrl.h"
#include "TestHtmlView_My.h"
#include "TestRoad_Html.h"
#include "TestRoad_OwnDraw.h"

// CTestAGuiObjDlg 对话框
class CTestAGuiObjDlg : public CDialogEx
{
// 构造
public:
	CTestAGuiObjDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTAGUIOBJ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	CTestDBUtil        m_testDBUtil;
	CTestHtmlCtrl      m_testHtmlCtrl;
	CTestHtmlViewMy    m_testMyHtmlView;
	CTestRoadHtml  m_testRollingNewsHtml;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnRoolingnews();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnHtml();
	afx_msg void OnBnClickedBtnHtmlroolnews();
	afx_msg void OnBnClickedBtnMyhtmlview();
};
