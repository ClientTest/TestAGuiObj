// TestRollingnews.cpp : 实现文件
//

#include "stdafx.h"
#include "TestAGuiObj.h"
#include "TestRoad_OwnDraw.h"
#include "afxdialogex.h"


// CTestRollingnews 对话框

IMPLEMENT_DYNAMIC(CTestRoadOwnDraw, CDialog)

CTestRoadOwnDraw::CTestRoadOwnDraw(CWnd* pParent /*=NULL*/)
	: CDialog(CTestRoadOwnDraw::IDD, pParent)
{
	m_pPictureExLoader=NULL;
	m_pRoolingNews=NULL;
}

CTestRoadOwnDraw::~CTestRoadOwnDraw()
{
}

void CTestRoadOwnDraw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestRoadOwnDraw, CDialog)
	ON_BN_CLICKED(IDC_BTN_ROOLINGNEWS, &CTestRoadOwnDraw::OnBnClickedBtnRoolingnews)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTestRollingnews 消息处理程序


void CTestRoadOwnDraw::OnBnClickedBtnRoolingnews()
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
	m_pRoolingNews->AppendRoolingNew(sInfo,1);
}

BOOL CTestRoadOwnDraw::OnInitDialog()
{
	if(!m_pPictureExLoader)
	{
		m_pPictureExLoader = new CPictureExLoader();
	}
	if(!m_pRoolingNews)
	{
		m_pRoolingNews = AGuiObj::CreateRoadOwnDraw(GetDlgItem(IDC_STATIC_ROOLINGNEWS)->GetSafeHwnd());
		m_pRoolingNews->SetPictureExLoader(m_pPictureExLoader);
		m_pRoolingNews->SetBackGroundColor(RGB(255,255,255));
		m_pRoolingNews->ModifyAddStyle(RN_STYLE_CIRCLE_LAST);
		m_pRoolingNews->ModifyAddStyle(RN_STYLE_UP_NOW);

		m_pRoolingNews->SetWindowPos(NULL,110,10,570,60,SWP_NOZORDER);
	}
	return CDialog::OnInitDialog();
}

void CTestRoadOwnDraw::OnDestroy()
{
	CDialog::OnDestroy();

	if(m_pPictureExLoader)
	{
		m_pPictureExLoader->Clear();
		delete m_pPictureExLoader;
		m_pPictureExLoader=NULL;
	}
	if(m_pRoolingNews)
	{
		delete m_pRoolingNews;
		m_pRoolingNews=NULL;
	}
}
