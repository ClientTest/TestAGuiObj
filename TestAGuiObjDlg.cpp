
// TestAGuiObjDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "AGuiObject/AGuiObjectQuote.h"
#include "MfcLib/MfcLibQuote.h"
#include "UILib/UILibQuote.h"
#include "WinLib/WinLibQuote.h"
#include "AGuiLOG/AGuiLOGQuote.h"
#include "Tools/AGuiToolsQuote.h"

#include "TestAGuiObj.h"
#include "TestAGuiObjDlg.h"
#include "afxdialogex.h"
#include "TestJsonMain.h"
#include "TestAGuiOperator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestAGuiObjDlg �Ի���




CTestAGuiObjDlg::CTestAGuiObjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestAGuiObjDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	
}

void CTestAGuiObjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestAGuiObjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ROOLINGNEWS, &CTestAGuiObjDlg::OnBnClickedBtnRoolingnews)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_HTML, &CTestAGuiObjDlg::OnBnClickedBtnHtml)
	ON_BN_CLICKED(IDC_BTN_HTMLROOLNEWS, &CTestAGuiObjDlg::OnBnClickedBtnHtmlroolnews)
	ON_BN_CLICKED(IDC_BTN_MYHTMLVIEW, &CTestAGuiObjDlg::OnBnClickedBtnMyhtmlview)
END_MESSAGE_MAP()


// CTestAGuiObjDlg ��Ϣ�������

BOOL CTestAGuiObjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	AGuiObj::AGuiLog()->Init(this,"AGuiObj");
	AGuiObj::AGuiLog()->WhgRegisterHotKey();

	//whgtest
	m_testDBUtil.TestDBMain();
	TestJsonMain();
	TestAguiOperatorMain();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestAGuiObjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestAGuiObjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestAGuiObjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestAGuiObjDlg::OnBnClickedBtnRoolingnews()
{
	CTestRoadOwnDraw   m_testRollingnews;
	m_testRollingnews.DoModal();
}


void CTestAGuiObjDlg::OnDestroy()
{
	AGuiObj::AGuiLog()->Destroy();
	CDialogEx::OnDestroy();
}


void CTestAGuiObjDlg::OnBnClickedBtnHtml()
{
	if(!m_testHtmlCtrl.GetSafeHwnd())
	{
		m_testHtmlCtrl.Create(IDD_DLG_HTMLCTRL,this);
	}
	m_testHtmlCtrl.ShowWindow(SW_SHOW);
}


void CTestAGuiObjDlg::OnBnClickedBtnHtmlroolnews()
{
	if(!m_testRollingNewsHtml.GetSafeHwnd())
	{
		m_testRollingNewsHtml.Create(IDD_DIALOG_RN_HTML,this);
	}
	m_testRollingNewsHtml.ShowWindow(SW_SHOW);
	
}


void CTestAGuiObjDlg::OnBnClickedBtnMyhtmlview()
{
	if(!m_testMyHtmlView.GetSafeHwnd())
	{
		m_testMyHtmlView.Create(IDD_DLG_TEST_MYHTMLVIEW,this);
	}
	m_testMyHtmlView.ShowWindow(SW_SHOW);
}
