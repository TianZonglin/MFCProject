// mfctest_2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfctest_2.h"
#include "mfctest_2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int Red=0,Green=0,Blue=0;
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
// CMfctest_2Dlg dialog

CMfctest_2Dlg::CMfctest_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMfctest_2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMfctest_2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfctest_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMfctest_2Dlg)
	DDX_Control(pDX, IDC_EDIT3, m_edit_blue);
	DDX_Control(pDX, IDC_EDIT2, m_edit_green);
	DDX_Control(pDX, IDC_EDIT1, m_edit_red);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_scro_blue);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_scro_green);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_scro_red);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMfctest_2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMfctest_2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1_start)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2_reset)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3_exit)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1red)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2green)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3blue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfctest_2Dlg message handlers

BOOL CMfctest_2Dlg::OnInitDialog()
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
	m_scro_red.SetScrollRange(0,255);
	m_scro_red.SetScrollPos(255);
	m_scro_green.SetScrollRange(0,255);
	m_scro_green.SetScrollPos(255);
	m_scro_blue.SetScrollRange(0,255);
	m_scro_blue.SetScrollPos(255);
	Changecolor(m_scro_red.GetScrollPos(),m_scro_green.GetScrollPos(),m_scro_blue.GetScrollPos());
    changenum();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMfctest_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMfctest_2Dlg::OnPaint() 
{
	CPaintDC dc(this);
	
	CDC* pDC=GetDC();
	CPen pen,*oldpen ;
	CBrush brush,*oldbrush;
	pen.CreatePen(NULL,1,RGB(0,0,0));
	brush.CreateSolidBrush(RGB(Red,Green,Blue));
    oldpen=pDC->SelectObject(&pen);
	oldbrush=pDC->SelectObject(&brush);
    pDC->Ellipse(210,30,380,200);
    pDC->SelectObject(oldpen);
	pDC->SelectObject(oldbrush);
    //pen.DeleteObject();
    //brush.DeleteObject();
    //ReleaseDC(pDC);  
	changenum();
	/*********************************************/
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
HCURSOR CMfctest_2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMfctest_2Dlg::OnButton1_start() 
{
	// TODO: Add your control notification handler code here
	MessageBox("            ¿ªÊ¼£¡","notion",NULL); 

	
}

void CMfctest_2Dlg::OnButton2_reset() 
{
	// TODO: Add your control notification handler code here
    	m_scro_red.SetScrollPos(255);
		m_scro_green.SetScrollPos(255);
		m_scro_blue.SetScrollPos(255);
		Changecolor(255,255,255);
		Invalidate();
	
}

void CMfctest_2Dlg::OnButton3_exit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CMfctest_2Dlg::Changecolor(int red,int green,int blue)
{

	
     	Red=red;
		Green=green;
		Blue=blue;
//		return RGB(red,green,blue);
		UpdateData(TRUE);//FALSE}
}


void CMfctest_2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
   

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CMfctest_2Dlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int inPos=0;

	switch(nSBCode)
	{	
	case SB_THUMBTRACK:
		 if(pScrollBar==&m_scro_red)
		{
              m_scro_red.SetScrollPos(nPos);
             
		}
		if(pScrollBar==&m_scro_green)
		{
              m_scro_green.SetScrollPos(nPos);
              
		}
		if(pScrollBar==&m_scro_blue)
		{
              m_scro_blue.SetScrollPos(nPos);
              
		}   
		 inPos=0;
	   break;
	case SB_PAGEUP:
		inPos =-10;
		break;
	case SB_PAGEDOWN:
		inPos =10;	
		break;

	case SB_LINEDOWN:
		inPos=10;
	//	if(inPos<0)
		//	inPos=0;
		break;	
	case SB_LINEUP:
		inPos=-10;
		if(inPos>255)
			inPos=255;
		break;
	}
   Changecolor(m_scro_red.GetScrollPos(),m_scro_green.GetScrollPos(),m_scro_blue.GetScrollPos());
   
    if(pScrollBar==&m_scro_red)
		{
		      inPos +=Red;
			  if(inPos>255)
			     inPos=255;
			  if(inPos<0)
			      inPos=0;
              m_scro_red.SetScrollPos(inPos);
             
		}
		if(pScrollBar==&m_scro_green)
		{
			inPos +=Green;
			  if(inPos>255)
			     inPos=255;
			  if(inPos<0)
			      inPos=0;
              m_scro_green.SetScrollPos(inPos);
              
		}
		if(pScrollBar==&m_scro_blue)
		{
			inPos +=Blue;
			  if(inPos>255)
			     inPos=255;
			  if(inPos<0)
			      inPos=0;
              m_scro_blue.SetScrollPos(inPos);
              
		}   
	
	Changecolor(m_scro_red.GetScrollPos(),m_scro_green.GetScrollPos(),m_scro_blue.GetScrollPos());
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
    Invalidate();
}


void CMfctest_2Dlg::OnChangeEdit1red() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMfctest_2Dlg::OnChangeEdit2green() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMfctest_2Dlg::OnChangeEdit3blue() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMfctest_2Dlg::changenum()
{
    char sPos[10];
	itoa(Red,sPos,10);
	m_edit_red.SetSel(0,-1);
	m_edit_red.ReplaceSel(sPos);
    itoa(Green,sPos,10);
	m_edit_green.SetSel(0,-1);
	m_edit_green.ReplaceSel(sPos);
	itoa(Blue,sPos,10);
	m_edit_blue.SetSel(0,-1);
	m_edit_blue.ReplaceSel(sPos);
	UpdateData(FALSE);
}
