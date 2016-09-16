// 1q1qDlg.cpp : implementation file
//

#include "stdafx.h"
#include "1q1q.h"
#include "1q1qDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int i=0,j=0;
bool fleg=0;
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
// CMy1q1qDlg dialog

CMy1q1qDlg::CMy1q1qDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1q1qDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1q1qDlg)
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1q1qDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1q1qDlg)
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1q1qDlg, CDialog)
	//{{AFX_MSG_MAP(CMy1q1qDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1q1qDlg message handlers

BOOL CMy1q1qDlg::OnInitDialog()
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
	SetTimer(1,70,NULL);//UINT time_result = 
 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1q1qDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1q1qDlg::OnPaint() 
{
	OnTimer(1);
    draw_place();
    Draw_car();

    //Draw_car();
    if(j>0)
	{
		m_edit1=100-j;
		if(m_edit1<0)m_edit1=0;
	}
	if(j>100)
	{
		m_edit2=40-j+100;
	    if(m_edit2<0)m_edit2=0;
	}
	if(j>140)
	{
		m_edit3=60-j+140;
		if(m_edit3<=0)m_edit3=0;
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
HCURSOR CMy1q1qDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1q1qDlg::Draw_car()
{ 
	CDC *pDC=GetDC();
	if(j>200){j=0;}
	//CDC *pDC=GetDC();	
	CPen pen1(PS_INSIDEFRAME,2,RGB(153,153,153));
	CBrush brush_gray(RGB(153,153,153));
	pDC->SelectObject(&pen1);
	if(j<=100&&j>0)
	{
		pDC->Rectangle(i*3,190,50+i*3,230);
		pDC->SelectObject(&brush_gray);
		pDC->Ellipse(110,60,140,90);
   		CBrush brush_green(RGB(0,255,0));
		pDC->SelectObject(&brush_green);
		pDC->Ellipse(50,60,80,90);
		
	}
    if(j<=140&&j>100)
	{		
	    pDC->Rectangle(i*3,190,50+i*3,230);
		pDC->SelectObject(&brush_gray);
		pDC->Ellipse(50,60,80,90);
		CBrush brush_yellow(RGB(255,255,0));
		pDC->SelectObject(&brush_yellow);
		pDC->Ellipse(80,60,110,90);
	}
    if(j<=200&&j>140  ) 
	{ 	
		pDC->Rectangle(i*3,190,50+i*3,230);
		pDC->SelectObject(&brush_gray);
		pDC->Ellipse(80,60,110,90);
   		CBrush brush_red(RGB(255,0,0));
		pDC->SelectObject(&brush_red);
		pDC->Ellipse(110,60,140,90);
		if(i>=83&&i<=90)	{i=i-2;//_sleep(5000)
	}
	}
	if(i>160)i=0;
	UpdateData(TRUE);
}


void CMy1q1qDlg::draw_place()
{
	CDC *pDC=GetDC();
	CBrush brush(RGB(153,153,153));
	CPen pen(NULL,2,RGB(153,153,153));
	pDC->SelectObject(&brush);
	pDC->SelectObject(&pen);
	pDC->Ellipse(50,60,80,90);
	pDC->Ellipse(80,60,110,90);
	pDC->Ellipse(110,60,140,90);
	pDC->MoveTo(20,180);
	pDC->LineTo(450,180);
	pDC->MoveTo(20,240);
	pDC->LineTo(450,240);
	
	pDC->MoveTo(302,180);
	pDC->LineTo(302,240);
	CPen pen1(PS_DASH ,1,RGB(153,153,153));
	pDC->SelectObject(&pen1);
	pDC->MoveTo(20,210);
    pDC->LineTo(450,210);
		UpdateData(TRUE);
}

void CMy1q1qDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent=1&&fleg==1)
	{  
		//UpdateData(TRUE);
		j=j+1; 
		i=i+1;	
		UpdateData(FALSE);
		Invalidate();	
	}
	CDialog::OnTimer(nIDEvent);
}

 
void CMy1q1qDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	fleg=1;
}

void CMy1q1qDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	fleg=0;
}

void CMy1q1qDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
	CDialog::OnCancel();

}

BOOL CMy1q1qDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CDialog::OnEraseBkgnd(pDC);
}
