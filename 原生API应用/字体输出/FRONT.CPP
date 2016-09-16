//和书上的输出一样；
#include "stdafx.h"
#include "windows.h"
#include "resource.h"
#include "math.h"


#define MAX_LOADSTRING 100
#define pi 3.14159


 
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
HFONT               CreateMyFont(CHAR *fontname,double height );
HFONT               CreateMyFont2(CHAR *fontname,double height );
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_FRONT, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_FRONT);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}


//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_FRONT);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_FRONT;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	PAINTSTRUCT ps;

	HDC hdc;
	HFONT font;
    HFONT font2;
	HFONT hF_black ;	//定义两种字体句柄
	TEXTMETRIC tm;	//定义一个TEXTMETRIC结构，用以记录字体信息
	double X0=700,Y0=350,r=80;
	double X1=700,Y1=150;//圆心，半径
	double X=0,Y=0,a=180,h=60; //起始角度
		unsigned int k=0,i=0;

	char lpsz_1[]="欲穷千里目更上一层楼";
	char lpsz_2[]="欲穷千里目更上一层楼";
 
 
 
	hF_black=CreateFont(		 	//创建自定义字体
						 40,			//字体的高度
						  0,		//由系统根据高宽比选取字体最佳宽度值
						  0,			//文本的倾斜度为0，表示水平
						  0,			//字体的倾斜度为0
						  FW_HEAVY,		//字体的粗度，FW_HEAVY为最粗
						  0,			//非斜体字
						  0,			//无下划线
						  0,			//无删除线
						  ANSI_CHARSET,	//表示所用的字符集为ANSI_CHARSET
						  OUT_DEFAULT_PRECIS,		//输出精度为缺省精度
						  CLIP_DEFAULT_PRECIS,		//剪裁精度为缺省精度
						  DEFAULT_QUALITY,		//输出质量为缺省值
						  DEFAULT_PITCH|FF_DONTCARE,//字间距和字体系列使用缺省值
						  "粗体字" ); 		//字体名称	
  
 
	switch (message) 
	{
	
		case WM_PAINT:
			hdc=BeginPaint(hWnd,&ps);	
                /////////////////////////////////////////////////////////////////////////////	
				SetTextColor(hdc,RGB(255,0,0));	
				for(i=0;i<strlen(lpsz_2);i+=2) 
                {
					font=CreateMyFont( "楷体_GB2312",h-=4);		
				    SelectObject(hdc,font); 
					GetTextMetrics(hdc,&tm); 
				 
					TextOut(hdc,X+i*20,Y,&lpsz_2[i],2); Y+=4;
				}
				////////////////////////////////////////////////////////////////////////////
				Y=Y+tm.tmHeight+tm.tmExternalLeading; //计算换行时下一行文本的输出坐标	
				for(i=0;i<strlen(lpsz_2);i+=2) 
                {
					font=CreateMyFont("楷体_GB2312",h+=4);		
				    SelectObject(hdc,font); 
					GetTextMetrics(hdc,&tm); 
					TextOut(hdc,X+i*20,Y,&lpsz_2[i],2) ; 
				} 
              	DeleteObject(font);	
                ////////////////////////////////////////////////////////////////////////////////
				h=10;
				Y=Y+tm.tmHeight+tm.tmExternalLeading; //计算换行时下一行文本的输出坐标	
				for(i=0;i<0.5*strlen(lpsz_2);i+=2) 
                {
					font=CreateMyFont("楷体_GB2312",h+=6);		
				    SelectObject(hdc,font); 
					GetTextMetrics(hdc,&tm); 
					TextOut(hdc,X+i*20,Y,&lpsz_2[i],2) ; Y-=4;
				}
				for(i=0.5*strlen(lpsz_2);i<strlen(lpsz_2);i+=2) 
                {
					Y+=6;		
				     SelectObject(hdc,font); 
					GetTextMetrics(hdc,&tm); 
					TextOut(hdc,X+i*20,Y,&lpsz_2[i],2) ; 
					font=CreateMyFont("楷体_GB2312",h-=6);
				}
              	DeleteObject(font);	

                /////////////////////////////////////////////////////////////////////
				Y=Y+tm.tmHeight+tm.tmExternalLeading+50;  
				
				h=10;
				for(i=0;i<strlen(lpsz_2);i+=2) 
                {
					font=CreateMyFont("楷体_GB2312",h+=log(i+95)*2);		
				    SelectObject(hdc,font); 
					GetTextMetrics(hdc,&tm); 
					TextOut(hdc,X+i*20,Y,&lpsz_2[i],2) ; Y-=log(i+9)*2;
				} 
              	DeleteObject(font);	
		        //////////////////////////////////////////////////////////////////// 
                SelectObject(hdc,hF_black);	 
			    GetTextMetrics(hdc,&tm); 
             	for(k=0;k<20;k+=2)
				{
					X=int (X0+r*cos(a*3.14/180));
					Y=int (Y0+r*sin(a*3.14/180));
					SetTextColor(hdc,RGB(0,0,255));	//设置文本颜色为红色
					TextOut(hdc,X,Y,&lpsz_1[k],2);
					a=a+36;
				}
				////////////////////////////////////////////////////fcewceeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeccccccccccc//////////////////
			
				X=0,Y=290;
				for(k=0;k<20;k+=2)
				{
					SetTextColor(hdc,RGB(0,0,0));	//设置文本颜色为红色
					TextOut(hdc,X+20*k,Y-sin(0.11*k*pi)*50  ,&lpsz_1[k],2);
				}
				X=0,Y=410;
				/////////////////////////////////////////////////////////////////////
				for(k=0;k<20;k+=2)
				{
					SetTextColor(hdc,RGB(0,0,0));	//设置文本颜色为红色
					TextOut(hdc,X+20*k,Y-cos(0.11*k*pi)*50  ,&lpsz_1[k],2);
				}
				//////////////////////////////////////////////////////////////////////////////
				h=40;r=110;
			 
				for(k=0;k<20;k+=2)
				{
					X=int (X1+r*cos(a*3.14/180));
					Y=int (Y1+r*sin(a*3.14/180));
					font2=CreateMyFont2( "楷体_GB2312",h-=3);	
					SelectObject(hdc,font2);	 
					SetTextColor(hdc,RGB(0,0,0));	 
					TextOut(hdc,X,Y,&lpsz_1[k],2);
					a=a+19;
				}
				//////////////////////////////////////////////////////////////////////



	 


		 
			EndPaint(hWnd,&ps);

			break;
		case WM_DESTROY:
			DeleteObject(hF_black);	//退出窗口时删除自定义字体
 
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

  HFONT CreateMyFont(CHAR *fontname,double height )
	{
		return CreateFont (
			height,
			20,
			0,
			0,
			300,
			0,
			0,
			0,
			GB2312_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH,
			fontname
			);
	}
   HFONT CreateMyFont2(CHAR *fontname,double height )
	{
		return CreateFont(
			height,
			0,
			0,
			0,
			700,
			0,
			0,
			0,
			GB2312_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH,
			fontname
			);
	}
	