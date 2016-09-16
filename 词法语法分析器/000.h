// 000.h : main header file for the 000 application
//

#if !defined(AFX_000_H__FD91847F_7ED0_48D9_8CB3_B347D311490B__INCLUDED_)
#define AFX_000_H__FD91847F_7ED0_48D9_8CB3_B347D311490B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy000App:
// See 000.cpp for the implementation of this class
//

class CMy000App : public CWinApp
{
public:
	CMy000App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy000App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy000App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_000_H__FD91847F_7ED0_48D9_8CB3_B347D311490B__INCLUDED_)
