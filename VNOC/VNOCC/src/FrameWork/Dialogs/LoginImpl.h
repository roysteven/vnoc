#pragma once
#include "ILogin.h"
#include "../IFrameWork.h"

class CLoginImpl
	: public ILogin
{
public:
	CLoginImpl(void);
	~CLoginImpl(void);
public:
	STDMETHOD( Initialize(IModule* UpperFrame=NULL) );
	STDMETHOD( UnInitialize() );
	STDMETHOD( Run() );
	STDMETHOD( Terminate() );
	STDMETHOD( Show(BOOL bShow=TRUE) );
	STDMETHOD( SetAccount(LPCTSTR userName) );
	VOID Login(LPCTSTR username,LPCTSTR pwd);
	STDMETHOD( GetCurrentUser(CString& userName,CString& cookie) );
	STDMETHOD( Logout(LPCTSTR username=NULL) );

private:
	IFrameWork* m_frame;
};

