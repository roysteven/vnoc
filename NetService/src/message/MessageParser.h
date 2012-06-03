/********************************************************************
	created:	2012/05/13
	created:	13:05:2012   00:46
	filename: 	D:\vnoc\trunk\VNOC\VNOC\MsgAnalysis.h
	file path:	D:\vnoc\trunk\VNOC\VNOC\MsgAnalysis.h
	file base:	Message Analysis
	file ext:	h
	author:		Sum.
	
	purpose:	���ݰ������࣬������������(�ͻ���)
*********************************************************************/


#pragma once

#include "msgdef.h"


class CMessageParser
{
public:
	
	CMessageParser(){
		m_Instruct = 0;
	}

	~CMessageParser(){

	}

public:
	//����
	CMessage* Parse(byte* lpszData,size_t len);


private:

	CMessage* m_MessageStr;           //

	byte   m_Instruct;			  //ָ��			�����ָ�������ע�����ݰ��Ĺ���

	int _Head(CMessage* _Messsage,byte* lpszData,size_t len);

	int _Body(CMessage* _Messsage,byte* lpszData,size_t len);

	int _Tail(CMessage* _Messsage,byte* lpszData,int ParamLen,size_t len);

	CMessage* _MessageType();
	int  _GetMessageType();

	int _CheckUpLen(int Index,size_t len)
	{
		if (Index > (int)len)
		{
			return -1;
		}
		return 0;
	}

};
