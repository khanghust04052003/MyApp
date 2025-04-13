
// MyAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MyApp.h"
#include "MyAppDlg.h"
#include "afxdialogex.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyAppDlg dialog



CMyAppDlg::CMyAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYAPP_DIALOG, pParent), m_nTimerID(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DISPLAY, m_timer);
	DDX_Control(pDX, IDC_BUTTON1, m_ColorButton);
}

BEGIN_MESSAGE_MAP(CMyAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyAppDlg::OnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMyAppDlg message handlers

BOOL CMyAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CFont font;
	font.CreatePointFont(90, _T("Courier New"));
	m_timer.SetFont(&font);

	// Xử lý trước 4 ảnh
	m_frames.resize(4);
	for (int i = 0; i < 4; i++)
	{
		std::string input = std::string("fig") + std::to_string(i) + std::string(".bmp");
		std::string output;
		BinaryImage::ImageBinary(input, 23, 41, 0, output);
		m_frames[i] = CString(output.c_str());
	}

	// Thêm hai dòng này để giảm flicker
	ModifyStyleEx(0, WS_EX_COMPOSITED);  // Bật double buffering
	m_timer.ModifyStyleEx(0, WS_EX_COMPOSITED);  // Cũng áp dụng cho control hiển thị

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyAppDlg::OnClickedButton1()
{
	// TODO: Add your control notification handler code here
	m_nTimerID = SetTimer(1, 144, nullptr);

	if (m_nTimerID == 0)
	{
		AfxMessageBox(_T("Can't create timer!"));
	}
}

void CMyAppDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1)
	{
		static int count = 0;
		m_timer.SetWindowTextW(m_frames[count % 4]); // Sử dụng khung hình đã xử lý
		count++;
		if (count >= 100)
		{
			KillTimer(1);
			count = 0;
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}
