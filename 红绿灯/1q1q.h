// 1q1q.h : main header file for the 1Q1Q application
//

#if !defined(AFX_1Q1Q_H__DB891B50_FC4E_4480_A6A2_109210BEA9E0__INCLUDED_)
#define AFX_1Q1Q_H__DB891B50_FC4E_4480_A6A2_109210BEA9E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1q1qApp:
// See 1q1q.cpp for the implementation of this class
//

class CMy1q1qApp : public CWinApp
{
public:
	CMy1q1qApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1q1qApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1q1qApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1Q1Q_H__DB891B50_FC4E_4480_A6A2_109210BEA9E0__INCLUDED_)
