// carr.cpp: implementation of the carr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "light.h"
#include "carr.h"
#include "lightDlg.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

carr::carr(int a,int carnumre,int v )
{
         width= a%20+30;
		 switch(4)
		 {
		 case 0:
			 style=BS_SOLID;break;
		 case 1:
			 style=HS_CROSS;break;
		 case 2:
			 style=HS_FDIAGONAL;break;
		 case 3:
             style=HS_BDIAGONAL;break;
		 }
		 length=a%100+50;
         colorred=a%200;
		 colorgreen=a%256;
		 colorgreen=a%133;
		 ////////////////////////////
         vv=v;
		 speed=v;
		 carnum=carnumre;
		 //beginnum=beginnumm;
		 positionx=1000;
		 positiony=200;
		 positionxx=1000+length;
		 positionyy=200+width;
}
void carr::numbe()
{
       if(carnum==0)
			  {
                if( positionx<=100)
				{
				    carnum=-1;
				//	numm_1 ++;
				}
			  }
	  //beginnum=numm_1;

}
void carr::jiansu(int dis)
{
	if(dis<=vv*(vv-1)/2 && speed>0)
	{
		speed--;

	}
	if(dis<5)
	{
		speed=0;
	}
}
void carr::car_run(int speedre,int positionre,int statere,int statelight,int numre,int time)
	 { 
			 /*第一种方式
			 if(statelight==1)
			  {
			   int distance = positionx-positionre;
			   if(distance<=10)
			   {
				   speed=0;
			   }
			   else if(distance<=100  )
			   {
				   if(speedre !=0)
					 speed=speedre;
				   if(speedre==0 && speed>0)
					   speed --; 
			   }
				
			   
			  }
			  else
			  {
				  speed=5;

			  }
               positionx -=speed;
			   positionxx=positionx+length;
              if(carnum==0)
			  {
                 positionxx<=90;
				 carnum=-1;
			  }*/
	    carnum +=numre;
	    if(carnum==0)
		{
			speedre=0;
            positionre=100;
		}
	    int vt=vv*time;
       	int distance = positionx-positionre;
          if(speedre==0)
		  {
			   if((statelight==1 && vt>distance)||(statelight==0 && vt<distance))
			   {
				 jiansu(distance);
			   }
			    if(statelight==0 && vt<distance)
			   {
				   if(carnum !=0)
					   if(distance<=vv*(vv-1)/2 && speed>0)
						   speed--;
					if(distance<5)
						speed=0;
			   }
				if(statelight==0 && vt>=distance)
				{
					speed=vv;
				}
		  }
          else
		  {
			  if(statelight==1 && distance<vv*(vv-1)/2)
				  speed=speedre;
			  if(statelight==0&&distance<=vv)				    
					    speed=speedre;
			  if(statelight==0 && vt>=distance)
				{
					speed=vv;
				}
              

		  }

	     positionx -=speed;
	     positionxx=positionx+length;

         numbe();
	 }
carr::~carr()
{

}
