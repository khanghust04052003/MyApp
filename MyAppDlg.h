
// MyAppDlg.h : header file
//

#pragma once
#include "BinaryImage.h"
#include "CColorButton.h"

// CMyAppDlg dialog
class CMyAppDlg : public CDialogEx
{
// Construction
public:
	CMyAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic m_timer;
	UINT_PTR m_nTimerID;
	std::vector<CString> m_frames;
	CColorButton m_ColorButton;

};
