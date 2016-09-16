// 000Dlg.cpp : implementation file
//
/*-----------------------------------------
单词符号	种别码	单词符号	种别码
  select	 1	       :	      17
    from	 2	       :=	      18
   where     3	       >	      20
  insert	 4     	   <>         21
   create  	 5	       <=	      22
    and      6	       <	      23
   单词 	 10	       >=	      24
   数字	     11	        =	      25
     *	     13	       ;	      26
     /	     14	       (	      27
     +	     15	       )	      28
     -	     16	       #	      0
------------------------------------------
select a from b where c=1 and d=1
------------------------------------------*/
#include "stdafx.h"
#include "000.h"
#include "000Dlg.h"
#include<stdio.h>
#include<string.h>
#include<iostream.h>
char prog[80],prog2[80],token[8];
char ch;
int syn,p,m=0,n,temp=0,right,row,sum=0;
char *rwtab[6]={"select","from","where","insert","create","and"};
CString str;
CString strrr,strrr2;
	char a[10];
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CMy000Dlg dialog

CMy000Dlg::CMy000Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy000Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy000Dlg)
	m_edit2 = _T("");
	m_edit3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy000Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy000Dlg)
	DDX_Control(pDX, IDC_LIST1, m_listcontrl1);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy000Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy000Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy000Dlg message handlers

BOOL CMy000Dlg::OnInitDialog()
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
	((CButton *)GetDlgItem(IDC_EDIT1))->SetFocus();
	m_edit1.SetWindowText("\r\n\r\n# < 结尾符 | 请勿删除 ! >");

	CRect rect;   
  
    // 获取编程语言列表视图控件的位置和大小   
    m_listcontrl1.GetClientRect(&rect);   
  
    // 为列表视图控件添加全行选中和栅格风格   
    m_listcontrl1.SetExtendedStyle(m_listcontrl1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);   
    m_listcontrl1.InsertColumn(0, _T("字符"), LVCFMT_CENTER, rect.Width()/4, 0);   
    m_listcontrl1.InsertColumn(1, _T("种别码"), LVCFMT_CENTER, rect.Width()/4, 1);   
    m_listcontrl1.InsertColumn(2, _T("字符"), LVCFMT_CENTER, rect.Width()/4, 2);  
	m_listcontrl1.InsertColumn(3, _T("种别码"), LVCFMT_CENTER, rect.Width()/4, 3);   
    // 初始化
        m_listcontrl1.InsertItem (0,    _T("select"));   
    m_listcontrl1.SetItemText(0, 1, _T("1"));   
    m_listcontrl1.SetItemText(0, 2, _T(":"));
	m_listcontrl1.SetItemText(0, 3, _T("17"));  
	    m_listcontrl1.InsertItem (1,    _T("from"));   
    m_listcontrl1.SetItemText(1, 1, _T("2"));   
    m_listcontrl1.SetItemText(1, 2, _T(":="));
	m_listcontrl1.SetItemText(1, 3, _T("18")); 
	    m_listcontrl1.InsertItem (2,    _T("where"));   
    m_listcontrl1.SetItemText(2, 1, _T("3"));   
    m_listcontrl1.SetItemText(2, 2, _T(">"));
	m_listcontrl1.SetItemText(2, 3, _T("20")); 
	    m_listcontrl1.InsertItem (3,    _T("insert"));   
    m_listcontrl1.SetItemText(3, 1, _T("4"));   
    m_listcontrl1.SetItemText(3, 2, _T("<>"));
	m_listcontrl1.SetItemText(3, 3, _T("21")); 
	    m_listcontrl1.InsertItem (4,    _T("create"));   
    m_listcontrl1.SetItemText(4, 1, _T("5"));   
    m_listcontrl1.SetItemText(4, 2, _T("<="));
	m_listcontrl1.SetItemText(4, 3, _T("22")); 
	    m_listcontrl1.InsertItem (5,    _T("and"));   
    m_listcontrl1.SetItemText(5, 1, _T("6"));   
    m_listcontrl1.SetItemText(5, 2, _T("<"));
	m_listcontrl1.SetItemText(5, 3, _T("23")); 
	    m_listcontrl1.InsertItem (6,    _T("单词"));   
    m_listcontrl1.SetItemText(6, 1, _T("10"));   
    m_listcontrl1.SetItemText(6, 2, _T(">="));
	m_listcontrl1.SetItemText(6, 3, _T("24")); 
	    m_listcontrl1.InsertItem (7,    _T("数字"));   
    m_listcontrl1.SetItemText(7, 1, _T("11"));   
    m_listcontrl1.SetItemText(7, 2, _T("="));
	m_listcontrl1.SetItemText(7, 3, _T("25")); 
	    m_listcontrl1.InsertItem (8,    _T("*"));   
    m_listcontrl1.SetItemText(8, 1, _T("13"));   
    m_listcontrl1.SetItemText(8, 2, _T(";"));
	m_listcontrl1.SetItemText(8, 3, _T("26")); 
	    m_listcontrl1.InsertItem (9,    _T("/"));   
    m_listcontrl1.SetItemText(9, 1, _T("14"));   
    m_listcontrl1.SetItemText(9, 2, _T("("));
	m_listcontrl1.SetItemText(9, 3, _T("27")); 
	    m_listcontrl1.InsertItem (10,    _T("+"));   
    m_listcontrl1.SetItemText(10, 1, _T("15"));   
    m_listcontrl1.SetItemText(10, 2, _T(")"));
	m_listcontrl1.SetItemText(10, 3, _T("28")); 
	    m_listcontrl1.InsertItem (11,    _T("-"));   
    m_listcontrl1.SetItemText(11, 1, _T("16"));   
    m_listcontrl1.SetItemText(11, 2, _T("#"));
	m_listcontrl1.SetItemText(11, 3, _T("0")); 

   
	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CMy000Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy000Dlg::OnPaint() 
{
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
HCURSOR CMy000Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy000Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	str.Empty();
	m_edit2="";
	GetDlgItem(IDC_EDIT2)->SetWindowText((""));
	p=0;
	row=1;
	//cout<<"Please input string:"<<endl;
	//do
	//{
	//	cin.get(ch);
	//	prog[p++]=ch;
	//}
	//while(ch!='#');
	p=0;

	do
	{
		////char a[10];itoa(syn,a,10);	MessageBox(a);
	    scaner();
	
		switch(syn)
		{
	
		//itoa(syn,a,10);
		//MessageBox(a);
		case 11: 
			strrr.Format("[ 种别码,字符: %d,%d ]",syn,sum); 
			m_edit2+=strrr+"\r\n";	
			UpdateData(FALSE);break;  //cout<<"("<<syn<<","<<sum<<")"<<endl;
	    case -1: 
			strrr.Format("Error in row %d",row);
			m_edit2+=strrr+"\r\n";
			UpdateData(FALSE);break;//cout<<"Error in row "<<row<<"!"<<endl; 
		case -2: 
			row=row++;break;
        default: //
			strrr.Format("[ 种别码,字符: %d,%s ]",syn,token); 
			m_edit2+=strrr+"\r\n";	
			UpdateData(FALSE);break;//cout<<"("<<syn<<","<<token<<")"<<endl;
			
		}//MessageBox(prog);
	}
	while (syn!=0);
	
	
}

void CMy000Dlg::scaner()
{

	//MessageBox(prog);
	for(n=0;n<8;n++) token[n]=NULL;
	ch=prog[p++];
	while(ch==' '||ch==13)
	{
		ch=prog[p];
		p++;
	}
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
		m=0;
		while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			token[m++]=ch;
			ch=prog[p++];
		}
		token[m++]='\0';
		p--;
		syn=10;
        
		
		for(n=0;n<6;n++)
			if(strcmp(token,rwtab[n])==0)
			{	
				syn=n+1;
				break;
			}

	}
	else if((ch>='0'&&ch<='9'))
	{
		{
			sum=0;
			while((ch>='0'&&ch<='9'))
			{
				sum=sum*10+ch-'0';
				ch=prog[p++];
			}
		}
		p--;
		syn=11;
		if(sum>32767)
			syn=-1;
	}
	else switch(ch)
	{
case'<':m=0;token[m++]=ch;
	ch=prog[p++];
	if(ch=='>')
	{
		syn=21;
		token[m++]=ch;
	}
	else if(ch=='=')
	{
		syn=22;
		token[m++]=ch;
	}
	else
	{
		syn=23;
		p--;
	}
	break;
case'>':m=0;token[m++]=ch;
	ch=prog[p++];
	if(ch=='=')
	{
		syn=24;
		token[m++]=ch;
	}
	else
	{
		syn=20;
		p--;
	}
	break;
case':':m=0;token[m++]=ch;
	ch=prog[p++];
	if(ch=='=')
	{
		syn=18;
		token[m++]=ch;
	}
	else
	{
		syn=17;
		p--;
	}
	break;
	
case'*':syn=13;token[0]=ch;break;
case'/':syn=14;token[0]=ch;break;
case'+':syn=15;token[0]=ch;break;
case'-':syn=16;token[0]=ch;break;
case'=':syn=25;token[0]=ch;break;
case';':syn=26;token[0]=ch;break;
case'(':syn=27;token[0]=ch;break;
case')':syn=28;token[0]=ch;break;
case'#':syn=0;token[0]=ch;break;
case'\n':syn=-2;break;
default: syn=-1;break;
	}



}

void CMy000Dlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMy000Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
    GetDlgItem(IDC_EDIT1)->GetWindowText(str);
    
	char *pStr =  (LPSTR)(LPCTSTR)str;
	strcpy(prog, pStr); 
	strcpy(prog2, pStr);
	MessageBox(prog2);

}
/*
ch=prog[p++];
if(ch=='=')
{
syn=24;
token[m++]=ch;
}
else
{
syn=20;
p--;
}
break;
#
*/
 void CMy000Dlg::OnButton3() 
 {
 	// TODO: Add your control notification handler code here
 		//str.Empty();
	m_edit3="";
	GetDlgItem(IDC_EDIT3)->SetWindowText((""));
 	right=1;
	temp=0;
 	e();

	do{
		if(right==1)
 		{
 			strrr2.Format("正误 1 : 分析成功");
 			m_edit3+=strrr2+"\r\n";
 			UpdateData(FALSE);//cout<<"分析成功"<<endl;
		}
		else
 		{
 			strrr2.Format("正误 0 :分析失败");
 			m_edit3+=strrr2+"\r\n";
 			UpdateData(FALSE);//cout<<"分析失败"<<endl;
 		}
	}while(prog2[temp]=='#');
}

void CMy000Dlg::f()
{
	//itoa(right,a,10);
    //MessageBox(a);
	while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
	if((prog2[temp]>='a'&&prog2[temp]<='z')||(prog2[temp]>='A'&&prog2[temp]<='Z'))
	{
		strrr2.Format("正误 %d : F->Litter",right);
		m_edit3+=strrr2+"\r\n";
		UpdateData(FALSE);
		//cout<<"F->i"<<endl;
		temp++;
	}
	else
    	//while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
	if(prog2[temp]=='(')
	{
		strrr2.Format("正误 %d : F->(E)",right);
		m_edit3+=strrr2+"\r\n";
		//UpdateData(FALSE);
		//cout<<"F->(E)"<<endl;
		temp++;
		e();
			while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
		if(prog2[temp]==')')
		{
			strrr2.Format("正误 %d : F->(E)",right);
			m_edit3+=strrr2+"\r\n";
			//
			//cout<<"F->(E)"<<endl;
			temp++;
		}
		else right=0;	

	}	
	else if(prog2[temp]=='+'||prog2[temp]=='-'||prog2[temp]=='*'||prog2[temp]=='/'||prog2[temp]==' '||prog2[temp]==13) right=1;
	else right =0;
UpdateData(FALSE);
}

void CMy000Dlg::t1()
{
	//itoa(right,a,10);
    //MessageBox(a);
	while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
	if(prog2[temp]=='*'||prog2[temp]=='+'||prog2[temp]=='-'||prog2[temp]=='/')
	{
		if(prog2[temp+1]=='*'||prog2[temp]=='+'||prog2[temp]=='-'||prog2[temp]=='/')right=0;
	}
	else if(prog2[temp]=='*'||prog2[temp]=='/')
	{
		strrr2.Format("正误 %d : T'->*/ FT'",right);
		m_edit3+=strrr2+"\r\n";
		//UpdateData(FALSE);
		//cout<<"T'->*FT'"<<endl;
		temp++;
		f();
		t1();
	}
	else	//while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
	if (prog2[temp]!='#'&&prog2[temp]!=')'&&prog2[temp]!='*'&&prog2[temp]!='/'&&prog2[temp]==' '&&prog2[temp]==13)
	{
		strrr2.Format("正误 %d : T'->^",right);
		m_edit3+=strrr2+"\r\n";
		
		//cout<<"T'->^"<<endl;
		right=0;
	}

	UpdateData(FALSE);
}

void CMy000Dlg::t()
{
////itoa(right,a,10);
  //  MessageBox(a);
	strrr2.Format("正误 %d : T->FT'",right);
	m_edit3+=strrr2+"\r\n";
	//
	//cout<<"T->FT'"<<endl;
	f();
	t1();
UpdateData(FALSE);
}

void CMy000Dlg::e1()
{	
//	itoa(right,a,10);
   // MessageBox(a);
	while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
	if(prog2[temp]=='+'||prog2[temp]=='-')
	{
		strrr2.Format("正误 %d : E'->+- TE'",right);
		m_edit3+=strrr2+"\r\n";
		//UpdateData(FALSE);
		//cout<<"E'->+TE'"<<endl;
		temp++;
		t();
		e1();
	}
	//	while(prog2[temp]==' '||prog2[temp]==13){	temp++;	  }
else if (prog2[temp]!='#'&&prog2[temp]!=')'&&prog2[temp]!='+'&&prog2[temp]!='-'&&prog2[temp]!='*'&&prog2[temp]!='/')
	{
		strrr2.Format("正误 %d : T'->^",right);
		m_edit3+=strrr2+"\r\n";
		
		//cout<<"T'->^"<<endl;
		return ;
	}
	else
	right=0;
UpdateData(FALSE);
}

void CMy000Dlg::e()
{

	strrr2.Format("正误 %d : E->TE'",right);
	m_edit3+=strrr2+"\r\n";
	
	//cout<<"E->TE'"<<endl;
	t();
	e1();
UpdateData(FALSE);
}

void CMy000Dlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}
