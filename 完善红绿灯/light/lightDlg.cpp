// lightDlg.cpp : implementation file
//

#include "stdafx.h"
#include "light.h"
#include "lightDlg.h"
#include "carr.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//typedef carr* carrr;
int Red=0,Green=0,Blue=0;
int light=0,setredtime=30,setgreentime=30;
int timenum=30,setred=0,setgreen=0;
int flage=0,flagecar=0,num=0,type=0;
int numbegin=0;

POINT pos1[100];
POINT pos2[100];
carr *car[100];
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
// CLightDlg dialog

CLightDlg::CLightDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLightDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLightDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLightDlg)
	DDX_Control(pDX, IDC_EDIT3, m_edit2green);
	DDX_Control(pDX, IDC_EDIT2, m_edit2red);
	DDX_Control(pDX, IDC_EDIT1, m_edit1red);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLightDlg, CDialog)
	//{{AFX_MSG_MAP(CLightDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2red)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3green)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLightDlg message handlers

BOOL CLightDlg::OnInitDialog()
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
	SetTimer(1,1000,NULL);
    SetTimer(2,50,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLightDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLightDlg::OnPaint() 
{

	
	      CDC* pDC=GetDC();
	      CPaintDC dc(this);
	      CPen *oldpen;
          CBrush *oldbrush;
		  int Red[3]={0,0,0};
		  int Green[3]={0,0,0};
		  int Blue[3]={0,0,0};
		  int carpoint1[3]={0,0,0};
          int carpoint2[3]={0,0,0};
		  int carpoint3[3]={0,0,0};
         pDC->MoveTo(30,150);
		 pDC->LineTo(1000,150);
		 pDC->MoveTo(30,300);
		 pDC->LineTo(1000,300);
	switch(light)
	{
	case 0:
		 Red[0]=0;Green[0]=255;Blue[0]=0;
		 Red[1]=0;Green[1]=0;Blue[1]=0;
		 Red[2]=0;Green[2]=0;Blue[2]=0;
		 break;
	case 1:
	   	Red[0]=0;Green[0]=0;Blue[0]=0;
		 Red[1]=0;Green[1]=0;Blue[1]=0;
		 Red[2]=255;Green[2]=255;Blue[2]=0;
		 break;
	case 2:
		 Red[0]=0;Green[0]=0;Blue[0]=0;
		 Red[1]=255;Green[1]=0;Blue[1]=0;
		 Red[2]=0;Green[2]=0;Blue[2]=0;
		 break;
	}
    for(int i=0;i<3;i++)
	{
		 CPen  pen;
		 CBrush brush;
		pen.CreatePen(PS_SOLID,1,RGB(Red[i],Green[i],Blue[i]));
		brush.CreateSolidBrush(RGB(Red[i],Green[i],Blue[i])); 	
		oldpen=pDC->SelectObject(&pen);
		oldbrush=pDC->SelectObject(&brush);
		pDC->Ellipse(50,500-i*60,100,550-i*60);
		pen.DeleteObject();
		brush.DeleteObject();
	}
        CPen  *oldpen2;
		CBrush *oldbrush2;
    for(i=numbegin;i<num ;i++)
	{  
		CPen pen;
		CBrush brush;
		pen.CreatePen(PS_SOLID,1,RGB(car[i]->colorred,car[i]->colorgreen,car[i]->colorblue));
		brush.CreateHatchBrush( car[i]->style,RGB(car[i]->colorred,car[i]->colorgreen,car[i]->colorblue)); 
		oldpen=pDC->SelectObject(&pen);
		oldbrush=pDC->SelectObject(&brush);
		pDC->Rectangle(pos1[i].x,pos1[i].y,pos2[i].x,pos2[i].y);
		pDC->SelectObject(oldpen);
		pDC->SelectObject(oldbrush);
		pen.DeleteObject();
		brush.DeleteObject();
	}
    pDC->SelectObject(oldpen);
	pDC->SelectObject(oldbrush);
   
    ReleaseDC(pDC); 
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
HCURSOR CLightDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLightDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		
		TCHAR sPos[10];
		itoa(timenum,sPos,10);
		m_edit1red.SetSel(0,-1);
		m_edit1red.ReplaceSel(sPos);
		if(flage==0)
		{
		  if(timenum==5)
		  {
			light=1;Invalidate();
		  }
		  if(timenum==0)
		  {
			light=2;
			flage=1;
			timenum=setredtime;
			Invalidate();
		  }
		}
		else
		{
			if(timenum==0)
			{
				light=0;
				flage=0;
				timenum=setgreentime;
				Invalidate();
			}
		}
		/****************************************************/
        /**********************随即出车*******************************/
	  
      if(rand()%2==0 && timenum%6==0)
	  {
	  	car[num]=new carr(rand(),num,5);     
		pos1[num].x=car[num]->positionx;
		pos1[num].y=car[num]->positiony;
		pos2[num].x=car[num]->positionxx;
		pos2[num].y=car[num]->positionyy;
        num =(num+1)%100;		
		flagecar=1;
		Invalidate();

	  }
					   /*************************试验品****************************/
									  /*if(num==0)
									  {
										pos1[num].x=1000;  pos1[num].y=200;
										pos2[num].x=1100;	pos2[num].y=300;
										num=1;
										Invalidate();
									  }*/
					 /*************************************************************/
	timenum--;

	}

	if(nIDEvent==2)
	{
       //汽车行走
		if(flagecar==1)
		{       
			if(numbegin<num)
			{                          
			    car[numbegin]->car_run(0,100,0,flage,-1,timenum);
                pos1[numbegin].x =car[numbegin]->positionx;
				pos2[numbegin].x =car[numbegin]->positionxx;
                 if(pos2[numbegin].x<50)
                        numbegin++;
			}
				int j=numbegin+1;
			   for(int i=j;i<num;i++)
			   {
				   car[i]->car_run(car[i-1]->speed,car[i-1]->positionxx,0,flage,car[i-1]->carnum,timenum);
				   pos1[i].x =car[i]->positionx;
				   pos2[i].x =car[i]->positionxx;
				   /****************************************/
                   if(pos2[i].x<30)
                         numbegin++;
				   //****************************************/
			   }  
					   /***************************试验品***************************/
								/*	if(num==1)
									{
									pos1[0].x -=5;
									pos2[0].x -=5;
									}*/
					 /********************************************************************/ 
		}
	   Invalidate();
	}
   
	

	CDialog::OnTimer(nIDEvent);
}



void CLightDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
void CLightDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	int light=0;
    int timenum=0;
    int flage=0;
	Invalidate();
}

void CLightDlg::OnChangeEdit2red() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	TCHAR sPos_red[10];
    m_edit2red.GetLine(10, sPos_red);
    setredtime=atoi( sPos_red);

}

void CLightDlg::OnChangeEdit3green() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
    TCHAR sPos_green[10];
	m_edit2green.GetLine(10, sPos_green);
	setgreentime=atoi(sPos_green);
}
