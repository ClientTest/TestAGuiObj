// TestMyHtmlView.cpp : 实现文件
//

#include "stdafx.h"
#include "TestAGuiObj.h"
#include "TestHtmlView_My.h"
#include "afxdialogex.h"
#include "MfcLib/AGuiFun/AGuiPath.h"

// CTestMyHtmlView 对话框

IMPLEMENT_DYNAMIC(CTestHtmlViewMy, CDialogEx)

CTestHtmlViewMy::CTestHtmlViewMy(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestHtmlViewMy::IDD, pParent)
{
	m_pMyHtmlView=NULL;
}

CTestHtmlViewMy::~CTestHtmlViewMy()
{
}

void CTestHtmlViewMy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestHtmlViewMy, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_SEND, &CTestHtmlViewMy::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CTestMyHtmlView 消息处理程序


BOOL CTestHtmlViewMy::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_pMyHtmlView = CreateMyHtmlView();
	m_pMyHtmlView->HideScroll();
	m_pMyHtmlView->SetIndirPreant(this);
	m_pMyHtmlView->CreateFromStatic(IDC_STATIC,this);

	//m_pHtmlRoolingNews->LoadFromResource(IDR_HTML_MARQUEE);
	CString strFilePath="http://www.baidu.com";
	//strFilePath.Format("%shtml\\Marquee.htm",AGuiFun::GetConfigPath());
	m_pMyHtmlView->Navigate(strFilePath);
	m_pMyHtmlView->SetBackGroundColor("#DFD4CF");
	//m_pMyHtmlView->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CTestHtmlViewMy::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pMyHtmlView)
	{
		delete m_pMyHtmlView;
		m_pMyHtmlView=NULL;
	}
}


void CTestHtmlViewMy::OnBnClickedBtnSend()
{
}



