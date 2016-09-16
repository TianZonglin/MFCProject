// mfctest_2.h : main header file for the MFCTEST_2 application
//

#if !defined(AFX_MFCTEST_2_H__3135DEB0_11B6_4055_9487_C49D94DC2B1B__INCLUDED_)
#define AFX_MFCTEST_2_H__3135DEB0_11B6_4055_9487_C49D94DC2B1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfctest_2App:
// See mfctest_2.cpp for the implementation of this class
//

class CMfctest_2App : public CWinApp
{
public:
	CMfctest_2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfctest_2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMfctest_2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTEST_2_H__3135DEB0_11B6_4055_9487_C49D94DC2B1B__INCLUDED_)
