// carr.h: interface for the carr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARR_H__4A33AA7A_4BBB_4625_89BE_16A51F0115A0__INCLUDED_)
#define AFX_CARR_H__4A33AA7A_4BBB_4625_89BE_16A51F0115A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "stdafx.h"
#include "light.h"
#include "lightDlg.h"
#include "carr.h"
class carr  
{
public:
	    carr(int a,int carnumre,int v);
	    virtual ~carr();
		int speed;                  // 速度整数0-5
        //int state;                  //状态0,1,2
        int carnum;                  //车号
		int positionx,positionxx;  
		int positiony,positionyy;   //位置
		int vv;                     //起始速度
	//	int beginnum;
		/*****************汽车款式***********************************/
		int style;      //brush阴影类型
		int colorred;   
		int colorgreen;
		int colorblue;   //车颜色
		/****************成员函数************************************/
        void car_run(int speedre,int positionre,int statere,int statelight,int numre,int time);
		void jiansu(int dis);
		void numbe();
private:
        int width;      //车宽度
		int length;     //车长度
		
};

#endif // !defined(AFX_CARR_H__4A33AA7A_4BBB_4625_89BE_16A51F0115A0__INCLUDED_)
