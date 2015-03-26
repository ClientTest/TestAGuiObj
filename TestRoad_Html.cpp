// TestRollingNewsHtml.cpp : 实现文件
//

#include "stdafx.h"
#include "TestAGuiObj.h"
#include "TestRoad_Html.h"
#include "afxdialogex.h"
#include "MfcLib/AGuiFun/AGuiPath.h"

// CTestRollingNewsHtml 对话框

IMPLEMENT_DYNAMIC(CTestRoadHtml, CDialogEx)

CTestRoadHtml::CTestRoadHtml(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestRoadHtml::IDD, pParent)
{
	m_pHtmlRoolingNews=NULL;
}

CTestRoadHtml::~CTestRoadHtml()
{
}

void CTestRoadHtml::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestRoadHtml, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_SEND, &CTestRoadHtml::OnBnClickedBtnSend)
	ON_BN_CLICKED(IDC_CHECK_UPNOW, &CTestRoadHtml::OnBnClickedCheckUpnow)
	ON_BN_CLICKED(IDC_CHECK_CIRCLE, &CTestRoadHtml::OnBnClickedCheckCircle)
END_MESSAGE_MAP()


// CTestRollingNewsHtml 消息处理程序
BOOL CTestRoadHtml::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_pHtmlRoolingNews = CreateRoadHtml();
	m_pHtmlRoolingNews->HideScroll();
	m_pHtmlRoolingNews->SetIndirPreant(this);
	m_pHtmlRoolingNews->CreateFromStatic(IDC_STATIC,this);

	CRect rt;
	GetClientRect(&rt);
	rt.top=100;
	rt.bottom=rt.top+60;
	m_pHtmlRoolingNews->MoveWindow(rt);

	//m_pHtmlRoolingNews->LoadFromResource(IDR_HTML_MARQUEE);
	CString strFilePath="";
	strFilePath.Format("%shtml\\Marquee.htm",AGuiFun::GetConfigPath());
	m_pHtmlRoolingNews->Navigate(strFilePath);
	//m_pHtmlRoolingNews->SetBackGroundColor("#DFD4CF");
	m_pHtmlRoolingNews->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CTestRoadHtml::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pHtmlRoolingNews)
	{
		delete m_pHtmlRoolingNews;
		m_pHtmlRoolingNews=NULL;
	}
}


void CTestRoadHtml::OnBnClickedBtnSend()
{
	static int nIndex=0;
	nIndex++;

	STBigItemHead* sInfo =new STBigItemHead;

	if(nIndex%2==0)
	{
		sInfo->sTip="黄河之水天上来，奔流到海不复回。高堂明镜悲白发，朝如青丝暮成雪。";
		sInfo->msgStateType=MSG_STRING;

	}else
	{
		sInfo->nFromUserID="13146149";
		sInfo->sFromUserName="49";
		sInfo->nToUserID="13146149";
		sInfo->sToUserName="49";
		sInfo->sUnitName="个";
		sInfo->sItemName="硕果累累";
		sInfo->sSendTime="03-25 14:07";
		sInfo->sPicName="face\\itembox\\1.gif";
		sInfo->sTip="";
		sInfo->nItemNum=3;
		sInfo->nRoomID=10000;
		sInfo->srcWealthIndex=3;
		sInfo->actWealthIndex=37;
		sInfo->msgStateType=MSG_GIFTINFO;
	}
	m_pHtmlRoolingNews->AppendRoolingNew(sInfo,1);
}


void CTestRoadHtml::OnBnClickedCheckUpnow()
{
	if(!m_pHtmlRoolingNews)
		return;

	CButton* btnCheck=(CButton*)GetDlgItem(IDC_CHECK_UPNOW);
	if(btnCheck->GetCheck()==BST_CHECKED)
	{
		m_pHtmlRoolingNews->ModifyAddStyle(RN_STYLE_UP_NOW);
	}else
	{
		m_pHtmlRoolingNews->ModifyRemoveStyle(RN_STYLE_UP_NOW);
	}
}


void CTestRoadHtml::OnBnClickedCheckCircle()
{
	if(!m_pHtmlRoolingNews)
		return;

	CButton* btnCheck=(CButton*)GetDlgItem(IDC_CHECK_CIRCLE);
	if(btnCheck->GetCheck()==BST_CHECKED)
	{
		m_pHtmlRoolingNews->ModifyAddStyle(RN_STYLE_CIRCLE_LAST);
	}else
	{
		m_pHtmlRoolingNews->ModifyRemoveStyle(RN_STYLE_CIRCLE_LAST);
	}
}