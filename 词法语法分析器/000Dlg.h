// 000Dlg.h : header file
//

#if !defined(AFX_000DLG_H__7E1A857C_BC5A_466C_A4E9_BFD72D24920C__INCLUDED_)
#define AFX_000DLG_H__7E1A857C_BC5A_466C_A4E9_BFD72D24920C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy000Dlg dialog

class CMy000Dlg : public CDialog
{
// Construction
public:
	void e();
	void e1();
	void t();
	void t1();
	void f();
	void scaner();
	CMy000Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy000Dlg)
	enum { IDD = IDD_MY000_DIALOG };
	CListCtrl	m_listcontrl1;
	CEdit	m_edit1;
	CString	m_edit2;
	CString	m_edit3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy000Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy000Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	afx_msg void OnChangeEdit1();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_000DLG_H__7E1A857C_BC5A_466C_A4E9_BFD72D24920C__INCLUDED_)
