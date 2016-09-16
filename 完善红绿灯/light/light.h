// light.h : main header file for the LIGHT application
//

#if !defined(AFX_LIGHT_H__915F8B56_478E_4FB6_8DD3_0CD23BE92877__INCLUDED_)
#define AFX_LIGHT_H__915F8B56_478E_4FB6_8DD3_0CD23BE92877__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLightApp:
// See light.cpp for the implementation of this class
//

class CLightApp : public CWinApp
{
public:
	CLightApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLightApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLightApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIGHT_H__915F8B56_478E_4FB6_8DD3_0CD23BE92877__INCLUDED_)
