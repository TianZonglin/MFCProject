// 1q1qDlg.h : header file
//

#if !defined(AFX_1Q1QDLG_H__2AA70ACF_BE5C_44B2_97EA_69CCEB2C8557__INCLUDED_)
#define AFX_1Q1QDLG_H__2AA70ACF_BE5C_44B2_97EA_69CCEB2C8557__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1q1qDlg dialog

class CMy1q1qDlg : public CDialog
{
// Construction
public:
	void draw_place();
	void Draw_car();
	CMy1q1qDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1q1qDlg)
	enum { IDD = IDD_MY1Q1Q_DIALOG };
	int		m_edit1;
	int		m_edit2;
	int		m_edit3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1q1qDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1q1qDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1Q1QDLG_H__2AA70ACF_BE5C_44B2_97EA_69CCEB2C8557__INCLUDED_)
