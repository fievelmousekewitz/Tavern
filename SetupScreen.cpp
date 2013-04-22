// SetupScreen.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "SetupScreen.h"


// SetupScreen dialog

IMPLEMENT_DYNAMIC(SetupScreen, CDialog)

SetupScreen::SetupScreen(CWnd* pParent /*=NULL*/)
	: CDialog(SetupScreen::IDD, pParent)
{

}

SetupScreen::~SetupScreen()
{
}

void SetupScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SetupScreen, CDialog)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDOK, &SetupScreen::OnBnClickedOk)
END_MESSAGE_MAP()


// SetupScreen message handlers
BOOL SetupScreen::OnInitDialog() {
	CDialog::OnInitDialog();
	SetDlgItemText(IDC_VERNUM,TAVERNVERSION);

		//Set dialog to full screen
	int cx, cy;
	HDC dc = ::GetDC(NULL);
	cx = GetDeviceCaps(dc,HORZRES) +
		GetSystemMetrics(SM_CXBORDER);
	cy = GetDeviceCaps(dc,VERTRES) + 
		GetSystemMetrics(SM_CYBORDER);
	::ReleaseDC(0,dc);

	::SetWindowPos(m_hWnd, HWND_TOPMOST,
		-(GetSystemMetrics(SM_CXBORDER)+1),
		-(GetSystemMetrics(SM_CYBORDER)+1),
		cx+1,cy+1,SWP_NOZORDER);
return true;
SetDlgItemText(IDC_EDIT1,theApp.defaultid);

}


#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void SetupScreen::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_TAVERN_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_TAVERN_DIALOG));
	}
}
#endif


BOOL SetupScreen::OnEraseBkgnd(CDC* pDC) {
	BOOL bRet = CDialog::OnEraseBkgnd(pDC);
    // let the things happen after this call else it will erase everything

	CBitmap bitmap;
    // loading the bitmap
    bitmap.LoadBitmap(IDB_BITMAP5);
    // get the bitmap size
    BITMAP bmp;
    bitmap.GetBitmap(&bmp);
 
    // create memory DC
    CDC memDc;
    memDc.CreateCompatibleDC(pDC);
    memDc.SelectObject(&bitmap);
 
    // drawing into the dialog
    pDC->BitBlt(0,0,bmp.bmWidth,bmp.bmHeight,&memDc,0,0,SRCCOPY);
return bRet;
}

void SetupScreen::OnBnClickedOk()
{
	CString dd;
	GetDlgItemText(IDC_EDIT1,dd);
	theApp.defaultid = dd;
	OnOK();
}
