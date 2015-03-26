#pragma once

#include "MfcLib/Img/PictureExLoader.h"
#include "AGuiObject/road/IRoad.h"
using namespace AGuiObj;

// CTestRollingnews 对话框

class CTestRoadOwnDraw : public CDialog
{
	DECLARE_DYNAMIC(CTestRoadOwnDraw)

public:
	CTestRoadOwnDraw(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestRoadOwnDraw();

// 对话框数据
	enum { IDD = IDD_DIALOG_ROLLINGBEWS };

private:
	CPictureExLoader*    m_pPictureExLoader;
	IRoad*               m_pRoolingNews;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnRoolingnews();
	afx_msg void OnDestroy();
};
