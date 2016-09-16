// HuaTuDlg.h : header file
//

#if !defined(AFX_HUATUDLG_H__666CF1EC_3546_4A7B_A7E6_9F1DE421199C__INCLUDED_)
#define AFX_HUATUDLG_H__666CF1EC_3546_4A7B_A7E6_9F1DE421199C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHuaTuDlg dialog

class CHuaTuDlg : public CDialog
{
// Construction
public:
	CHuaTuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHuaTuDlg)
	enum { IDD = IDD_HUATU_DIALOG };
	CButton	m_button;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	CListBox	m_list;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaTuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHuaTuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeList1();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	afx_msg void OnRadio8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUATUDLG_H__666CF1EC_3546_4A7B_A7E6_9F1DE421199C__INCLUDED_)
