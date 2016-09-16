#include<windows.h>
#include<stdio.h>
#include<tchar.h>
 
BOOLEAN InitWindowClass (HINSTANCE hInstance,int nCmdShow);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

int flag=0;
 
int a[10][10];
int aa=0;
int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
	int m,n;
	for(m=0;m<10;m++){
    for(n=0;n<10;n++){
     a[m][n]=0;
	}     }
	if(!InitWindowClass(hInstance,nCmdShow))
	{
		MessageBox(NULL, "ERROR!", "OK" ,NULL);
		return 1;
	}
	
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	
	int x=0,y=0;  
    int i;	
	POINT pp;
   
    HDC hDc;
	PAINTSTRUCT PtStr;
    int  static xx[100],yy[100];
	int static icount=0;
    
 
 switch(message)
	{

		
case WM_LBUTTONDOWN: 

	    flag=1;
		icount++; 
			UpdateWindow(hWnd);
	    InvalidateRect(hWnd,NULL,FALSE);                     //产生WM_PAINT消息 
        break;
case WM_RBUTTONDOWN:   
	    flag=0;
		icount++; 
		UpdateWindow(hWnd);
	    InvalidateRect(hWnd,NULL,FALSE);                     //产生WM_PAINT消息 
        break;  


case WM_PAINT:

 		HBRUSH hBrush;
		HPEN hPen;
		hDc=BeginPaint(hWnd,&PtStr);
		hPen=(HPEN)GetStockObject(BLACK_PEN);
		hBrush=(HBRUSH)GetStockObject(DKGRAY_BRUSH);
		SelectObject(hDc,hBrush);
		SelectObject(hDc,hPen);


		for( i=0;i<4;i++)    {    MoveToEx(hDc,0,70*i,NULL);    	LineTo(hDc,210,70*i);   }//划横线
		for(i=0;i<4;i++)     { 	  MoveToEx(hDc,70*i,0,NULL);    	LineTo(hDc,70*i,210);   }//画竖线
	
		if(flag==1)///////////////////////////////////////////////////
        {
			GetCursorPos(&pp);  
		ScreenToClient(hWnd,&pp);
		hDc = GetDC(hWnd); 
 		hPen=(HPEN)GetStockObject(BLACK_PEN);	
     	hBrush=(HBRUSH)GetStockObject(BLACK_BRUSH);  a[pp.x/70][pp.y/70]=1	;//左键黑色
        SelectObject(hDc,hBrush);
		SelectObject(hDc,hPen); 
	



		if( pp.x>210||pp.y>210)  break;
		if((a[pp.x/70][pp.y/70])){///////////////////
		for(i=0;i<icount;i++){
		xx[i]=pp.x;
		yy[i]=pp.y; 
        Ellipse(hDc, xx[i]/70*70+5, yy[i]/70*70+5, xx[i]/70*70+70-5, yy[i]/70*70+70-5); 
		}}
        for(i=0;i<3;i++){
		if(a[0][i]==1)
			if(a[1][i]==1)
			    if(a[2][i]==1)aa=1; 
		if(a[i][0]==1)
			if(a[i][1]==1)
			    if(a[i][2]==1)aa=1; 
		if(a[0][0]==1)
			if(a[1][1]==1)
			    if(a[2][2]==1)aa=1; 
		if(a[2][0]==1)
			if(a[1][1]==1)
			    if(a[0][2]==1)aa=1; 
	    }if(aa)MessageBox(hWnd,"黑棋赢了 ！","哈哈哈",NULL); 
		}
 
    	
		else    {
			   
		GetCursorPos(&pp);  
		ScreenToClient(hWnd,&pp);
		hDc = GetDC(hWnd); 
		hPen=(HPEN)GetStockObject(BLACK_PEN);	
        hBrush=(HBRUSH)GetStockObject(WHITE_BRUSH);  a[pp.x/70][pp.y/70]=2	;//右键白色 
        SelectObject(hDc,hBrush);
		SelectObject(hDc,hPen); 
	  

		if( pp.x>210||pp.y>210)  break;
		if(1){
		for(i=0;i<icount;i++){
		xx[i]=pp.x;
		yy[i]=pp.y; 
        Ellipse(hDc, xx[i]/70*70+5, yy[i]/70*70+5, xx[i]/70*70+70-5, yy[i]/70*70+70-5); 
		}}
		aa=0;
        for(i=0;i<3;i++){
		if(a[0][i]==2)
			if(a[1][i]==2)
			    if(a[2][i]==2)aa=1; 
		if(a[i][0]==2)
			if(a[i][1]==2)
			    if(a[i][2]==2)aa=1; 
		if(a[0][0]==2)
			if(a[1][1]==2)
			    if(a[2][2]==2)aa=1; 
		if(a[2][0]==2)
			if(a[1][1]==2)
			    if(a[0][2]==2)aa=1; 
		
		}if(aa)MessageBox(hWnd,"白棋赢了 ！","哈哈哈",NULL); }

		EndPaint(hWnd,&PtStr);
	    break; 


	case WM_DESTROY:
		PostQuitMessage(0);
		break;
default:
		return DefWindowProc(hWnd,message,wParam,lParam);
		break;
	}
return 0;
}



BOOLEAN InitWindowClass(HINSTANCE hInstance,int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hWnd;
	TCHAR szWindowClass[]= "rfregesg";
	TCHAR szTitle[]= "真nan哈";
	wcex.cbSize=sizeof(WNDCLASSEX);
	wcex.style=0;
	wcex.lpfnWndProc=WndProc;
	wcex.cbClsExtra=0;
	wcex.cbWndExtra=0;
	wcex.hInstance=hInstance;
	wcex.hIcon=LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);
	wcex.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName=NULL;
	wcex.lpszClassName=szWindowClass;
	wcex.hIconSm=LoadIcon(wcex.hInstance,MAKEINTRESOURCE(IDI_APPLICATION));
	if(!RegisterClassEx(&wcex))
		return FALSE;
	hWnd=CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,
		CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	if(!hWnd)
		return FALSE;
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	return TRUE;
}

