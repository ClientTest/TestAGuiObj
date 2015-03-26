// TestHtmlCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestAGuiObj.h"
#include "TestHtmlCtrl.h"
#include "afxdialogex.h"

#include "MfcLib/AGuiFun/AGuiPath.h"
#include "Tools/json/reader.h"
#include "Tools/json/value.h"
#include "Tools/json/writer.h"

// CTestHtmlCtrl �Ի���

IMPLEMENT_DYNAMIC(CTestHtmlCtrl, CDialogEx)

CTestHtmlCtrl::CTestHtmlCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestHtmlCtrl::IDD, pParent)
{
	m_pHtmlCtrl=NULL;
}

CTestHtmlCtrl::~CTestHtmlCtrl()
{
}

void CTestHtmlCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestHtmlCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_SEND, &CTestHtmlCtrl::OnBnClickedBtnSend)
	ON_BN_CLICKED(IDC_CHECK_SET_BG, &CTestHtmlCtrl::OnBnClickedCheckSetBg)
	ON_BN_CLICKED(IDC_BTN_CLEAN, &CTestHtmlCtrl::OnBnClickedBtnClean)
	ON_BN_CLICKED(IDC_BTN_RECORD, &CTestHtmlCtrl::OnBnClickedBtnRecord)
	ON_BN_CLICKED(IDC_BTN_AUTOSCROLL, &CTestHtmlCtrl::OnBnClickedBtnAutoscroll)
END_MESSAGE_MAP()


// CTestHtmlCtrl ��Ϣ�������
void CTestHtmlCtrl::OnReceiveHtmlHref(CString strMsg)
{
	strMsg.Replace("\'","\"");//���Ӳ���json�ַ����еĵ����ű���ת��Ϊ˫���ţ���������쳣
	try
	{
		Json::Value pkt;
		Json::Reader reader;
		std::string pktData(strMsg.GetBuffer(),strMsg.GetLength());
		reader.parse(pktData,pkt);
		std::string pktCmd = pkt["cmd"].asString();
		if(pktCmd == "link_open_url")
		{
			std::string sUrl = pkt["url"].asString();
			CString strUrl = sUrl.c_str();
			if(strUrl=="")
			{
				return;
			}
			ShellExecute(GetSafeHwnd(),NULL,strUrl,NULL,NULL,SW_SHOWNORMAL) ;
		}
	}catch(...)
	{
	}
}

void CTestHtmlCtrl::OnBnClickedBtnSend()
{
	CString strMsg;
	static int i=0;
	i++;
	try
	{
		Json::FastWriter writer;
		Json::Value parameters;
		parameters["cmd"] = (Json::Value)"link_open_url";
		parameters["url"] = (Json::Value)"www.baidu.com";
		std::string hrefParam = writer.write(parameters);
		CString strHrefParam = hrefParam.c_str();
		strHrefParam.Replace("\"","\'");//���Ӳ���json�ַ����е�˫���ű���ת��Ϊ�����ţ�������ת�쳣
		strMsg.Format("<a href=\"htmllocalehref:%s\">%d_%s</a>",strHrefParam,i,"����ٶ�");
	}
	catch(...)
	{
	}
	

	CString str="�����׺���Ϊˮ����ȴ��ɽ�����ơ�һ��þ�����ǣ����ǳȻ�����ʱ��";
	strMsg = str+strMsg;
	m_pHtmlCtrl->AddStrMessage(strMsg);
}

BOOL CTestHtmlCtrl::OnInitDialog()
{
	if(!m_pHtmlCtrl)
	{
		m_pHtmlCtrl=CreateMyHtmlCtrl();
		m_pHtmlCtrl->SetUseDefaultHtml(true);

		m_pHtmlCtrl->SetUseDefaultWrite(true);
		m_pHtmlCtrl->SetBkColor(RGB(223,212,207));
		COLORREF highlight,shadow,dlight,track,darkshadow,base,arrow,face;
		highlight =(COLORREF)strtol("0x89B8DC", NULL, 16);
		shadow = (COLORREF)strtol("0x89B8DC", NULL, 16);
		dlight = (COLORREF)strtol("0xE0EDF9", NULL, 16);
		track = (COLORREF)strtol("0xE0EDF9", NULL, 16);
		darkshadow = (COLORREF)strtol("0xE0EDF9", NULL, 16);
		base = (COLORREF)strtol("0x89B8DC", NULL, 16);
		arrow = (COLORREF)strtol("0xFFFFFF", NULL, 16);
		face = (COLORREF)strtol("0xe0e9fa", NULL, 16);
		m_pHtmlCtrl->SetScrollBarColor(highlight,shadow,dlight,track,darkshadow,base,arrow,face);

		m_pHtmlCtrl->CreateFromStatic(IDC_STATIC,this);
		m_pHtmlCtrl->SetHtmlHrefListener(this);

		CRect rt;
		GetClientRect(&rt);
		m_pHtmlCtrl->SetClientWidth(rt.Width() - 38);
	}

	return CDialogEx::OnInitDialog();
}

void CTestHtmlCtrl::OnDestroy()
{
	CDialogEx::OnDestroy();
	if(m_pHtmlCtrl)
	{
		delete m_pHtmlCtrl;
		m_pHtmlCtrl=NULL;
	}
}


void CTestHtmlCtrl::OnBnClickedCheckSetBg()
{
	if(!m_pHtmlCtrl)
		return;

	CButton* btnCheck=(CButton*)GetDlgItem(IDC_CHECK_SET_BG);
	if(btnCheck->GetCheck()==BST_CHECKED)
	{
		CString strImg;
		strImg.Format("%sface\\bg\\HtmlStaticBg.jpg",AGuiFun::GetConfigPath());
		m_pHtmlCtrl->SetBackGroundImg(strImg);
		m_pHtmlCtrl->ClearContend();
	}
}


void CTestHtmlCtrl::OnBnClickedBtnClean()
{
	if(m_pHtmlCtrl)
		m_pHtmlCtrl->ClearContend();
}


void CTestHtmlCtrl::OnBnClickedBtnRecord()
{
	if(!m_pHtmlCtrl)
		return;

	static bool bRecord=false;
	bRecord=!bRecord;
	if(bRecord)
	{
		CTime time = CTime::GetCurrentTime();
		CString strFileName;
		strFileName.Format("¼��_%04d%02d%02d_%02d%02d%02d",time.GetYear(),time.GetMonth(),time.GetDay(),time.GetHour(),time.GetMinute(),time.GetSecond());
		CFileDialog m_SaveDlg(false,".html",strFileName,0,"html�ļ�(*.html)|*.html||");
		if(m_SaveDlg.DoModal()==IDCANCEL)
		{
			bRecord=!bRecord;
			return;  
		}
		CString strCMFile; 
		strCMFile=m_SaveDlg.GetPathName(); 
		FILE *hFile = fopen(strCMFile, "w");
		if(hFile != NULL)
		{
			fclose(hFile);
			m_pHtmlCtrl->RecordStart(strCMFile);
			m_strRecordPathFile=strCMFile;
			GetDlgItem(IDC_BTN_RECORD)->SetWindowText("ֹͣ¼��");
		}else
			MessageBox("��ȡ�ļ�����!");
		
	}else
	{
		m_pHtmlCtrl->RecordStop();
		GetDlgItem(IDC_BTN_RECORD)->SetWindowText("��ʼ¼��");

		CString strMsg,strOpenLink;
		strOpenLink.Format("<a href=\"link_open_recordfile:filePath=%s&\">%s</a>",m_strRecordPathFile,"�������");
		strMsg.Format("ֹͣ¼���������֡���%s���ļ���",strOpenLink);
		m_pHtmlCtrl->AddStrMessage(strMsg);
		
	}
}


void CTestHtmlCtrl::OnBnClickedBtnAutoscroll()
{
	if(!m_pHtmlCtrl)
		return;

	static bool bAutoScroll=true;
	bAutoScroll=!bAutoScroll;
	if(bAutoScroll)
	{
		m_pHtmlCtrl->StopAutoScroll(false);
		GetDlgItem(IDC_BTN_AUTOSCROLL)->SetWindowText("ֹͣ����");
	}else
	{
		m_pHtmlCtrl->StopAutoScroll(true);
		GetDlgItem(IDC_BTN_AUTOSCROLL)->SetWindowText("��ʼ����");
	}
}
