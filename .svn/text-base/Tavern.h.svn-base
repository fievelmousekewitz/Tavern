// Tavern.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 
#include "TavernDlg.h"
#include "MenuDlg.h"
#include "Inventory.h"
#include "JobComp.h"
#include "CartControl.h"
#include "WIPStart.h"
#include "WIPInventory.h"
#include "SetupScreen.h"
#include "nled.h"
#include "WIPReset.h"

#define PLAY_EXCLAMATION PlaySound(_T("SystemExclamation"),0,SND_ALIAS | SND_ASYNC);
#define PLAY_START PlaySound(_T("SystemStart"),0,SND_ALIAS | SND_ASYNC);
#define PLAY_ASTERISK PlaySound(_T("SystemAsterisk"),0,SND_ALIAS | SND_ASYNC);

#define TAVERNVERSION L"Version 1.08"

// CTavernApp:
// See Tavern.cpp for the implementation of this class
//

class CTavernApp : public CWinApp
{
public:
	CTavernApp();
	CString employeeid;
	CString wipdepartment;
	CString defaultid;
// Overrides
public:
	virtual BOOL InitInstance();

// Place all significant initialization in InitInstance
	HANDLE m_Mutex_h;
    UINT m_WinMsg_ui;
// Implementation
		MenuDlg mdlg;
		CTavernDlg dlg;
		Inventory idlg;
		JobComp jdlg;
		CCartControl cdlg;
		SetupScreen setupdlg;
		WIPStart wdlg;
		WIPInventory widlg;  //side note: this was a stupid naming convention. Why would I do this?
		WIPReset wipresetdlg;

	DECLARE_MESSAGE_MAP()
};

extern CTavernApp theApp;
