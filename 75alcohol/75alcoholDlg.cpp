
// 75alcoholDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "75alcohol.h"
#include "75alcoholDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CAboutDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy75alcoholDlg 对话框



CMy75alcoholDlg::CMy75alcoholDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY75ALCOHOL_DIALOG, pParent)
	, Bconcentration(_T("75"))
	, Aconcentration(_T("95"))
	, Avolume(_T(""))
	, Bvolume(_T(""))
	, addwater(_T(""))
	, addalcohol(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy75alcoholDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, Bconcentration);
	DDX_Text(pDX, IDC_EDIT1, Aconcentration);
	DDX_Text(pDX, IDC_EDIT2, Avolume);
	DDX_Text(pDX, IDC_EDIT6, Bvolume);
	DDX_Text(pDX, IDC_EDIT3, addwater);
	DDX_Text(pDX, IDC_EDIT5, addalcohol);
	DDX_Text(pDX, IDC_EDIT5, addalcohol);
	DDX_Text(pDX, IDC_EDIT3, addwater);
}

BEGIN_MESSAGE_MAP(CMy75alcoholDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMy75alcoholDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy75alcoholDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy75alcoholDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy75alcoholDlg 消息处理程序

BOOL CMy75alcoholDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy75alcoholDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy75alcoholDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy75alcoholDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy75alcoholDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

CString changeuinttocstring(unsigned int i) {
	char answer[256];
	memset(answer, '0', sizeof(answer));
	_itoa(i, answer, 10);
	CString ans = CA2T(answer);
	return ans;
}
void CMy75alcoholDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	unsigned int Av = atoi(CT2A(Avolume));//浓酒精容积
	unsigned int Bv = atoi(CT2A(Bvolume));//稀酒精容积
	unsigned int Ac = atoi(CT2A(Aconcentration));
	unsigned int Bc = atoi(CT2A(Bconcentration));
	unsigned check = 0;
	addwater = __T("");
	if (Ac > 0) check++;
	if (Av > 0) check++;
	if (Bc > 0) check++;
	if (Bv > 0) check++;
	if (check != 3) {
		MessageBox(__T("需要在四个框中填入三个数字"));
	}
	else if (Ac < Bc && Ac != 0) {
		MessageBox(__T("浓酒精浓度小于稀酒精"));
		Aconcentration = __T("95");
		Bconcentration = __T("75");
	}
	else {
		if (Ac == 0 && Av) {//计算浓酒精浓度
			unsigned int Acanswer = 1.0 * (1ll * Bc * Bv) / Av;
			Aconcentration = changeuinttocstring(Acanswer);
			double danswer= 1.0 * (1ll * Bc * Bv) / Av;
			CString sanswer=__T(" ");
			sanswer.Format(__T("浓酒精浓度为%.4f"),danswer);
			MessageBox(sanswer, __T("计算结果"));
		}
		else if (Av == 0 && Ac) {//计算浓酒精容积
			unsigned int Avanswer = 1.0 * (1ll * Bc * Bv) / Ac;
			Avolume = changeuinttocstring(Avanswer);
			double danswer = 1.0 * (1ll * Bc * Bv) / Ac;
			addwater = changeuinttocstring(Bv-Avanswer);
			CString sanswer=__T(" ");
			sanswer.Format(__T("浓酒精量为%.4fmL,加水量为%.4fmL"), danswer, Bv-danswer);
			MessageBox(sanswer, __T("计算结果"));
		}
		else if (Bc == 0 && Bv) {//计算稀酒精浓度
			unsigned int Bcanswer = 1.0 * (1ll * Ac * Av) / Bv;
			Bconcentration = changeuinttocstring(Bcanswer);
			double danswer = 1.0 * (1ll * Ac * Av) / Bv;
			CString sanswer = __T(" ");
			sanswer.Format(__T("稀酒精浓度为%.4f"), danswer);
			MessageBox(sanswer, __T("计算结果"));
		}
		else if (Bv == 0 && Bc) {//计算稀酒精容积
			unsigned int Bvanswer = 1.0 * (1ll * Ac * Av) / Bc;
			Bvolume = changeuinttocstring(Bvanswer);
			double danswer = 1.0 * (1ll * Ac * Av) / Bc;
			CString sanswer=__T(" ");
			sanswer.Format(__T("稀酒精量为%.4fmL,加水量为%.4fmL"), danswer, danswer - Av);
			MessageBox(sanswer, __T("计算结果"));
			addwater = changeuinttocstring(Bvanswer - Av);
		}
	}

	UpdateData(FALSE);
}


void CMy75alcoholDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	unsigned int Av = atoi(CT2A(Avolume));
	unsigned int Bv = atoi(CT2A(Bvolume));
	unsigned int Ac = atoi(CT2A(Aconcentration));
	unsigned int Bc = atoi(CT2A(Bconcentration));
	unsigned check = 0;
	Avolume = __T("");
	Bvolume = __T("");
	Aconcentration = __T("95");
	Bconcentration = __T("75");
	addalcohol = __T("");
	addwater = __T("");
	UpdateData(FALSE);
}


void CAboutDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

}
