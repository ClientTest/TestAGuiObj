#pragma once

#include "AGuiObject/road/IRoadHtml.h"
using namespace AGuiObj;
// CTestRollingNewsHtml �Ի���

class CTestRoadHtml : public CDialogEx
{
	DECLARE_DYNAMIC(CTestRoadHtml)

public:
	CTestRoadHtml(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestRoadHtml();

// �Ի�������
	enum { IDD = IDD_DIALOG_RN_HTML };

private:
	IRoadHtml*         m_pHtmlRoolingNews;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnSend();
	afx_msg void OnBnClickedCheckUpnow();
	afx_msg void OnBnClickedCheckCircle();
};
