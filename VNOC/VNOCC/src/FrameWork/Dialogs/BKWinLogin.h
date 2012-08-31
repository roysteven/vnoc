#pragma once
#include "../../BKWin/wtlhelper/whwindow.h"
#include "../../net/INet.h"
#include "../FrameBase.hpp"

class CLoginWnd:public CBkDialogImpl<CLoginWnd>
	,public CFrameBase
{
public:
	void		OnBkBtnClose();
	void		OnLoginClick();

	virtual BOOL ProcessXMessage(XMessage* msg);

public:
	BK_NOTIFY_MAP(IDC_RICHVIEW_WIN)
		BK_NOTIFY_ID_COMMAND(DlgControl_LoginWin_ImgBtn_Close,	OnBkBtnClose)
		BK_NOTIFY_ID_COMMAND(DlgControl_LoginWin_Button_Login,	OnLoginClick)
	BK_NOTIFY_MAP_END()

	BEGIN_MSG_MAP_EX_DECLARE(CLoginWnd)
};