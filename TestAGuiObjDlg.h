
// TestAGuiObjDlg.h : ͷ�ļ�
//

#pragma once

#include "MfcLib/AGuiFun/AGuiPath.h"
#include "AGuiLOG/IAGuiLOG.h"

#include "TestDBUtil.h"
#include "TestHtmlCtrl.h"
#include "TestHtmlView_My.h"
#include "TestRoad_Html.h"
#include "TestRoad_OwnDraw.h"

// CTestAGuiObjDlg �Ի���
class CTestAGuiObjDlg : public CDialogEx
{
// ����
public:
	CTestAGuiObjDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTAGUIOBJ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CTestDBUtil        m_testDBUtil;
	CTestHtmlCtrl      m_testHtmlCtrl;
	CTestHtmlViewMy    m_testMyHtmlView;
	CTestRoadHtml  m_testRollingNewsHtml;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
