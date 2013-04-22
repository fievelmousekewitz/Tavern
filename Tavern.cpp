// Tavern.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Tavern.h"
#include "TavernDlg.h"
#include "MenuDlg.h"
#include "Inventory.h"
#include "SplashWnd.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CTavernApp

BEGIN_MESSAGE_MAP(CTavernApp, CWinApp)
END_MESSAGE_MAP()


// CTavernApp construction
CTavernApp::CTavernApp()
	: CWinApp()
{
	
	// TODO: add construction code here,
	
}


// The one and only CTavernApp object
CTavernApp theApp;

// CTavernApp initialization

BOOL CTavernApp::InitInstance()
{
	
    // SHInitExtraControls should be called once during your application's initialization to initialize any
    // of the Windows Mobile specific controls such as CAPEDIT and SIPPREF.
    SHInitExtraControls();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("ACTITavern"));

	m_WinMsg_ui=RegisterWindowMessage(_T("ONMESSAGE"));
    m_Mutex_h=::CreateMutex(NULL, FALSE, L"TavernApp");
	defaultid="";

    if (!m_Mutex_h || (GetLastError() == ERROR_ALREADY_EXISTS || GetLastError() == ERROR_ACCESS_DENIED))
    {
    return false;
	}
   
		CSplashWnd::EnableSplashScreen(TRUE);
		m_pMainWnd = &mdlg;
		
		INT_PTR nResponse = mdlg.DoModal();

	
			if (nResponse == IDOK)
			{
	//do nothing
			}
	

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
  
}//init
