// lightDlg.h : header file
//

#if !defined(AFX_LIGHTDLG_H__B0054545_581A_4D92_B653_27CD723E6DCA__INCLUDED_)
#define AFX_LIGHTDLG_H__B0054545_581A_4D92_B653_27CD723E6DCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLightDlg dialog

class CLightDlg : public CDialog
{
// Construction
public:
	CLightDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLightDlg)
	enum { IDD = IDD_LIGHT_DIALOG };
	CEdit	m_edit2green;
	CEdit	m_edit2red;
	CEdit	m_edit1red;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLightDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton5(); 
	afx_msg void OnButton4();
	afx_msg void OnChangeEdit2red();
	afx_msg void OnChangeEdit3green();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHTDLG_H__B0054545_581A_4D92_B653_27CD723E6DCA__INCLUDED_)
