// HuaTu.h : main header file for the HUATU application
//

#if !defined(AFX_HUATU_H__C6BBE54A_255C_4349_A696_8D5144F75832__INCLUDED_)
#define AFX_HUATU_H__C6BBE54A_255C_4349_A696_8D5144F75832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHuaTuApp:
// See HuaTu.cpp for the implementation of this class
//

class CHuaTuApp : public CWinApp
{
public:
	CHuaTuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHuaTuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHuaTuApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HUATU_H__C6BBE54A_255C_4349_A696_8D5144F75832__INCLUDED_)
