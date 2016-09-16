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
		int speed;                  // �ٶ�����0-5
        //int state;                  //״̬0,1,2
        int carnum;                  //����
		int positionx,positionxx;  
		int positiony,positionyy;   //λ��
		int vv;                     //��ʼ�ٶ�
	//	int beginnum;
		/*****************������ʽ***********************************/
		int style;      //brush��Ӱ����
		int colorred;   
		int colorgreen;
		int colorblue;   //����ɫ
		/****************��Ա����************************************/
        void car_run(int speedre,int positionre,int statere,int statelight,int numre,int time);
		void jiansu(int dis);
		void numbe();
private:
        int width;      //�����
		int length;     //������
		
};

#endif // !defined(AFX_CARR_H__4A33AA7A_4BBB_4625_89BE_16A51F0115A0__INCLUDED_)
