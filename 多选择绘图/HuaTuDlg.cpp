// HuaTuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HuaTu.h"
#include "HuaTuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int nPenStyle=PS_SOLID;
int nIndex=HS_DIAGCROSS;
int pos;
CString string;
CString str_list="Line";
COLORREF color1=RGB(255,0,0);
COLORREF color2=RGB(255,0,0);
int fleg=0;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaTuDlg dialog

CHuaTuDlg::CHuaTuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHuaTuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHuaTuDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHuaTuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHuaTuDlg)
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHuaTuDlg, CDialog)
	//{{AFX_MSG_MAP(CHuaTuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_RADIO6, OnRadio6)
	ON_BN_CLICKED(IDC_RADIO7, OnRadio7)
	ON_BN_CLICKED(IDC_RADIO8, OnRadio8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHuaTuDlg message handlers

BOOL CHuaTuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	 m_list.InsertString(0,"Line");
	 m_list.InsertString(1,"Circle");
	 m_list.InsertString(2,"Rectangle");
	 m_list.InsertString(3,"RoundRectangle");
	 m_combo1.InsertString(0,"Red");
	 m_combo1.InsertString(1,"Blue");
	 m_combo1.InsertString(2,"Green");
	 m_combo2.InsertString(0,"Red");
	 m_combo2.InsertString(1,"Blue");
	 m_combo2.InsertString(2,"Green");

     ((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);   //设置默认选项

	 ((CButton *)GetDlgItem(IDC_RADIO5))->SetCheck(TRUE);

	 CComboBox *pBox1 = (CComboBox *)GetDlgItem(IDC_COMBO1) ; 
	 pBox1->SetCurSel(0) ; 

	 CComboBox *pBox2 = (CComboBox *)GetDlgItem(IDC_COMBO2) ; 
	 pBox2->SetCurSel(0) ; 

	  CListBox *pList = (CListBox *)GetDlgItem(IDC_LIST1) ; 
	 pList->SetCurSel(0) ; 

	 return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHuaTuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHuaTuDlg::OnPaint() 
{
    CDC *pDC=GetDC();
	CPaintDC dc(this);	
	
    if(fleg==1)
	{
		CPen pen(nPenStyle,1,color1);
		CBrush brush(nIndex,color2);
		pDC->SelectObject(&pen);
		pDC->SelectObject(&brush);
		if(str_list=="Line")
		{ 
			pDC->MoveTo(380,25);
	     	pDC->LineTo(500,145);
		}
		else if(str_list=="Circle")
		{
			pDC->Ellipse(380,25,500,145);
		}
		else if(str_list=="Rectangle")
		{
			pDC->Rectangle(380,25,500,145);
		}
		else if(str_list=="RoundRectangle")
		{
			pDC->RoundRect(380,25,500,145,20,20);
		}
       
		//pDC->Ellipse(380,20,500,140);
	}
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHuaTuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CHuaTuDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	pos = m_list.GetCurSel();
    m_list.GetText(pos,str_list);
}

void CHuaTuDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	nPenStyle = PS_SOLID;

}

void CHuaTuDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	nPenStyle = PS_DASH;

}

void CHuaTuDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	nPenStyle = PS_DOT;

}

void CHuaTuDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	nPenStyle = PS_DASHDOT;

}

 
void CHuaTuDlg::OnButton1() 
{
    UpdateData(TRUE);
	fleg = 1;
	//MessageBox("sef","sde",MB_OK);
	//UpdateData(FALSE);
	Invalidate();
}

void CHuaTuDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	pos = m_combo1.GetCurSel();
    m_combo1.GetLBText(pos,string);
	if(string=="Red"){color1=RGB(255,0,0);}
	if(string=="Green"){color1=RGB(0,255,0);}
	if(string=="Blue"){color1=RGB(0,0,255);}
}

void CHuaTuDlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	pos = m_combo2.GetCurSel();
    m_combo2.GetLBText(pos,string);
	if(string=="Red"){color2=RGB(255,0,0);}
	if(string=="Green"){color2=RGB(0,255,0);}
	if(string=="Blue"){color2=RGB(0,0,255);}
}

void CHuaTuDlg::OnRadio5() 
{
	// TODO: Add your control notification handler code here
	nIndex = HS_DIAGCROSS;
}

void CHuaTuDlg::OnRadio6() 
{
	// TODO: Add your control notification handler code here
	nIndex = HS_CROSS;
}

void CHuaTuDlg::OnRadio7() 
{
	// TODO: Add your control notification handler code here
	nIndex = HS_FDIAGONAL;
}

void CHuaTuDlg::OnRadio8() 
{
	// TODO: Add your control notification handler code here
	nIndex = HS_BDIAGONAL;
}
