#include<windows.h>
#include<stdio.h>
#include<tchar.h>
/************************************** */
int chess_2[3][3];
/*****************************************/

struct CHESSSTATE  //上一次
{

	int flag;
	int redchess[3];		
	int greenchess[3];
	BOOL player;			
	BOOL move;
	int selchess;	
	int win;	

};/////////////////////////////////////////////////////////////////////////未使用

struct CHESS  //现状态棋盘
{

	int         redchess[3];		
	int         greenchess[3];
	POINT       p[3][3];
	BOOL        player;	    //=0 红色玩家 =1绿色玩家
	int         r;			//棋子半径
	BOOL        move;       //移动状态
	int         selchess;	//选择的棋子位置 0~8 如果 9 没有选择
	int         win;	    //=-1 没有玩家赢 =0 红色玩家赢 =1绿色玩家赢
	BOOL        twink;      //闪烁状态
	CHESSSTATE  prestate;
}chess;//////////////////////////////////////////////////////////////////////

 
BOOLEAN InitWindowClass (HINSTANCE hInstance,int nCmdShow);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
int WINAPI WinMain (HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	MSG msg;

	if(!InitWindowClass(hInstance,nCmdShow))
	{
		MessageBox(NULL, "ERROR!", "OK" ,NULL);
		return 1;
	}
	
	while (GetMessage(&msg,NULL,0,0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int limit(int a1,int a2)
{	 	
		if(a1==0){
			if(a2==3||a2==1||a2==4)return 1;	else return 0;}
		else if(a1==1){
			if(a2==0||a2==2||a2==4)return 1;	else return 0;}
		else if(a1==2){
			if(a2==1||a2==4||a2==5)return 1;	else return 0;}
		else if(a1==3){
			if(a2==0||a2==4||a2==6)return 1;	else return 0;}
		else if(a1==4){
			return 1;}
		else if(a1==5){
			if(a2==2||a2==4||a2==8)return 1;	else return 0;}
		else if(a1==6){
			if(a2==3||a2==4||a2==7)return 1;	else return 0;}
		else if(a1==7){
			if(a2==6||a2==4||a2==8)return 1;	else return 0;}
		else if(a1==8){
			if(a2==4||a2==5||a2==7)return 1;	else return 0;}
		else return 0;

}
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam)
{	

     HDC hdc;
     PAINTSTRUCT ps;
     POINT point;
     int len,m,n,wide=100;
     int cent_x,cent_y;
     RECT rect; 
	 

								  


 switch(message)
	{
	 case WM_CREATE://初始化程序
			chess.redchess[0]=0;
			chess.redchess[1]=1;
			chess.redchess[2]=2;
			chess.greenchess[0]=6; 
			chess.greenchess[1]=7;
			chess.greenchess[2]=8;
			chess.player=0;
			chess.r=20;
			chess.move=0;
			chess.selchess=9;
			chess.win=0;
			chess.twink=0;
			int i,j;
			for(i=0;i<3;i++)
				for(j=0;j<3;j++)
					chess_2[i][j]=0;
			break;

	case WM_PAINT:
           
		hdc = BeginPaint(hWnd, &ps);
            GetClientRect(hWnd,&rect);//根据窗口大小取坐标
			cent_x=(rect.right-rect.left)/2;
			cent_y=(rect.bottom-rect.top)/2;
			for (i=0;i<=2;i++){
				for (j=0;j<=2;j++)
				{
					chess.p[i][j].x=cent_x+(j-1)*wide;
					chess.p[i][j].y=cent_y+(i-1)*wide;
				}
			}
			///////////////////////////////////////////////////////////////////////////////////////////////
			HPEN pen;
			pen=CreatePen(PS_SOLID,3,RGB(0,0,0));
			SelectObject(hdc,pen);
			MoveToEx(hdc,chess.p[0][0].x,chess.p[0][0].y,(LPPOINT) NULL);
				  
			LineTo(hdc,chess.p[0][2].x,chess.p[0][2].y );
			LineTo(hdc,chess.p[2][2].x,chess.p [2][2].y);
			LineTo(hdc,chess.p[2][0].x,chess.p[2][0].y);
			LineTo(hdc,chess.p[0][0].x,chess.p[0][0].y ); ////////////画口字形
			for(i=0;i<3;i++){
				for(j=0;j<3;j++)
				{
					MoveToEx(hdc,chess.p[1][1].x,chess.p[1][1].y,(LPPOINT) NULL);
					LineTo(hdc,chess.p[i][j].x,chess.p[i][j].y );//////////画米字
				}
            }
			////////////////////////////////////////////////////////////////////////////////////////////////
			HBRUSH brush1,brush2;
			brush1=CreateSolidBrush(RGB(255,0,0));//////////红色
			SelectObject(hdc,brush1);
			for(i=0;i<3;i++)
			{
				m=chess.redchess[i]/3;///////////行
				n=chess.redchess[i]%3;///////////列
				Ellipse(hdc,chess.p[m][n].x-chess.r,chess.p[m][n].y-chess.r,chess.p[m][n].x+chess.r,chess.p[m][n].y+chess.r);//棋子半径
			}
			brush2=CreateSolidBrush(RGB(0,255,0));
			SelectObject(hdc,brush2);
			for(i=0;i<3;i++)
			{
				m=chess.greenchess[i]/3;   ///////////行
				n=chess.greenchess[i]%3;   ///////////列
				Ellipse(hdc,chess.p[m][n].x-chess.r,chess.p[m][n].y-chess.r,chess.p[m][n].x+chess.r,chess.p[m][n].y+chess.r);
			}////////////////////////////////////////////////初始状态，3红旗3白旗
			
			
			if(chess.win==1)    MessageBox(hWnd,"红色玩家获胜","恭喜",MB_OK);//判断输赢的结果输出
			if(chess.win==2)	MessageBox(hWnd,"绿色玩家获胜","恭喜",MB_OK);


            if(chess.twink==1 && chess.move==1)/////////闪烁+移动
			{
				m=chess.selchess/3;//////////行
				n=chess.selchess%3;//////////列
				if(chess.player==0)//////////=0 红色玩家 =1绿色玩家
				SelectObject(hdc,brush1);
				else SelectObject(hdc,brush2);
				Ellipse(hdc,chess.p[m][n].x-2*chess.r+10,chess.p[m][n].y-2*chess.r+10,chess.p[m][n].x+2*chess.r-10,chess.p[m][n].y+2*chess.r-10);//放大
			}
			
			DeleteObject(brush1);
			DeleteObject(brush2);
			DeleteObject(pen);
			chess.player?TextOut(hdc,10,10,"绿家走棋",8):TextOut(hdc,10,10,"红家走棋",8);////////////=0 红色玩家 =1绿色玩家
			chess.move?TextOut(hdc,10,30,"请选择一个位置",14):TextOut(hdc,10,30,"请选择一颗棋子",14);//
           	EndPaint(hWnd, &ps);
			break;
case WM_TIMER:
			chess.twink=1-chess.twink;     /////////闪烁BOOL值
			m=chess.selchess/3;            ///////////行
			n=chess.selchess%3;            ///////////列
			rect.left  =chess.p[m][n].x-2*chess.r;
			rect.top   =chess.p[m][n].y-2*chess.r;
			rect.right =chess.p[m][n].x+2*chess.r;
			rect.bottom=chess.p[m][n].y+2*chess.r;
			InvalidateRect(hWnd,&rect,TRUE);
			break;
case WM_LBUTTONDOWN:
			point.x=LOWORD(lParam);
			point.y=HIWORD(lParam);
			if(chess.move==0)	          /////////此期没有在移动状态！！
			{
				if(chess.player==0)	      /////////红色玩家
				{				          //////////判断选择的棋子哪一颗
					for(i=0;i<3;i++)
					{
						m=chess.redchess[i]/3;           /////////行
						n=chess.redchess[i]%3;           /////////列
					    len=(chess.p[m][n].x-point.x)*(chess.p[m][n].x-point.x)+(chess.p[m][n].y-point.y)*(chess.p[m][n].y-point.y);
						if(len<=chess.r*chess.r)
						{
							chess.selchess=chess.redchess[i];              //选择的棋子位置 0~8 如果 9 没有选择
							SetTimer(hWnd,1,180,NULL);
							break;
						}
					}

				}
				////////同理
				else				//the green palyer
				{
					for(i=0;i<3;i++)
					{
						m=chess.greenchess[i]/3;
						n=chess.greenchess[i]%3;
						len=(chess.p[m][n].x-point.x)*(chess.p[m][n].x-point.x)+(chess.p[m][n].y-point.y)*(chess.p[m][n].y-point.y);
						if(len<=chess.r*chess.r)
						{
							chess.selchess=chess.greenchess[i];
							SetTimer(hWnd,1,180,NULL);
							break;
						}
					}
				}
				if(chess.selchess!=9)           //选择的棋子位置 0~8 如果 9 没有选择
					chess.move=1;

			InvalidateRect(hWnd,NULL,TRUE);
			}
			else///////////////////////////////////////////////////////////////////////////////////////////此期在移动状态！！
			{
               int first_touch = chess.selchess;
			   int second_touch;
               for(i=0;i<3;i++)
			   for(j=0;j<3;j++)
			   {
				   len=(chess.p[i][j].x-point.x)*(chess.p[i][j].x-point.x)+(chess.p[i][j].y-point.y)*(chess.p[i][j].y-point.y);
						if(len<=chess.r*chess.r+10)
						{
							second_touch= i*3+j;              //选择的棋子位置 0~8 如果 9 没有选择
							break;
						}
			 
							 
			   }
              
					  for(i=0;i<3;i++)
					  {
						  if(chess.redchess[i]==second_touch || chess.greenchess[i]==second_touch)
						  {
							  	InvalidateRect(hWnd,NULL,TRUE);
								break; 
						  }
					  }
					  if(i>=3)
					  {
						  chess.move=0;
						  for(i=0;i<3;i++)
						  {
							  if(chess.redchess[i]==first_touch)
							  {
								  if(limit(first_touch,second_touch))///用limit()检测是否跳格下棋
								  {
									 if(chess.player==0)
									 {
										chess.redchess[i]=second_touch;
										chess.player=1;
									 }
								  }else break;
								  
							  }
						     else if(chess.greenchess[i]==first_touch)
							 {
								if(limit(first_touch,second_touch))///用limit()检测是否跳格下棋
								{
								    if(chess.player==1)
									{
									    chess.greenchess[i]=second_touch;
									    chess.player=0;
									}
								}else break;
							 }
						  }
					  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////判断输赢
			int k=0;
			if(chess.player==1)
			{
				for(i=0;i<3;i++)
					if(chess.redchess[i]==4)
					{ 
					   for(i=0;i<3;i++)
					   {  k +=chess.redchess[i];  }
					   if(k==12) chess.win=1;
					}
		 
			}
			else
			{
                for(i=0;i<3;i++)
				    if(chess.greenchess[i]==4)
					{ 
					   for(i=0;i<3;i++)
					   {  k +=chess.greenchess[i];  }
					   if(k==12)  chess.win=2;
					}
		 
			}
			KillTimer(hWnd,1);
			/*************************************************/
			  }
			InvalidateRect(hWnd,NULL,TRUE);
	break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	TCHAR szTitle[]= "qqq";
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

