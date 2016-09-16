// mfctest_2Dlg.h : header file
//

#if !defined(AFX_MFCTEST_2DLG_H__BC03BC3E_DF22_4255_9C6B_544F87907A36__INCLUDED_)
#define AFX_MFCTEST_2DLG_H__BC03BC3E_DF22_4255_9C6B_544F87907A36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMfctest_2Dlg dialog

class CMfctest_2Dlg : public CDialog
{
// Construction
public:
	void changenum();
	void Changecolor(int red,int green ,int blue);
	CMfctest_2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMfctest_2Dlg)
	enum { IDD = IDD_MFCTEST_2_DIALOG };
	CEdit	m_edit_blue;
	CEdit	m_edit_green;
	CEdit	m_edit_red;
	CScrollBar	m_scro_blue;
	CScrollBar	m_scro_green;
	CScrollBar	m_scro_red;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfctest_2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMfctest_2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1_start();
	afx_msg void OnButton2_reset();
	afx_msg void OnButton3_exit();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnChangeEdit1red();
	afx_msg void OnChangeEdit2green();
	afx_msg void OnChangeEdit3blue();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTEST_2DLG_H__BC03BC3E_DF22_4255_9C6B_544F87907A36__INCLUDED_)
