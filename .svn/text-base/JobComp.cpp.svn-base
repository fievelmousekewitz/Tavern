// JobComp.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "JobComp.h"
#include "windows.h"

#define VK_OEM_3 0x23
#define VK_LBRACE 219
#define VK_RBRACE 221
#define VK_ENTER 13


// JobComp dialog

IMPLEMENT_DYNAMIC(JobComp, CDialog)

JobComp::JobComp(CWnd* pParent /*=NULL*/)
	: CDialog(JobComp::IDD, pParent)
{

}

JobComp::~JobComp()
{
}

void JobComp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(JobComp, CDialog)
ON_MESSAGE(WM_HOTKEY,OnHotKey)
ON_MESSAGE(WM_DESTROY,OnOK)
ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_BUTTON1, &JobComp::OnBnClickedButton1)
END_MESSAGE_MAP()


// JobComp message handlers




BOOL JobComp::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	// TODO: Add extra initialization here

if(RegisterHotKey(this->m_hWnd,100,NULL,VK_LBRACE) && 
	RegisterHotKey(this->m_hWnd,200,NULL,VK_RBRACE) &&
		RegisterHotKey(this->m_hWnd,300,NULL,VK_ENTER))
		
      {   
       //   m_start.EnableWindow(false);
       //   m_stop.EnableWindow(true);
		  //MessageBox((LPCTSTR)"WORKED","WORKED",0);
		//MessageBox(NULL, L"Worked!", NULL);
		 // MessageBox(NULL,L"RegisterHotKey Succeed",NULL);
      }
      else
     MessageBox(NULL, L"RegisterHotKey failed",NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}



LRESULT JobComp::OnHotKey(WPARAM wParam, LPARAM lParam) {
CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);

CString whob;
		GetDlgItemText(IDC_EDIT1,whob);
		CString s = whob;
		//int indexnum,length;
		CString szValue;


switch(wParam) {
		
	case 100: // Left Bracket [
	
	SetDlgItemText(IDC_EDIT1,NULL);
	SetDlgItemText(IDC_EDIT2,NULL);
	SetDlgItemText(IDC_EDIT3,NULL);
	SetDlgItemText(IDC_EDIT4,NULL);
	SetDlgItemText(IDC_EDIT5,NULL);
	SetDlgItemText(IDC_EDIT6,NULL);
	SetDlgItemText(IDC_EDIT7,NULL);
	SetDlgItemText(IDC_EDIT8,NULL);
	SetDlgItemText(IDC_EDIT9,NULL);
	SetDlgItemText(IDC_EDIT10,NULL);
	SetDlgItemText(IDC_EDIT11,NULL);
	SetDlgItemText(IDC_EDIT12,NULL);

	edit->SetFocus();
	return true;

	case 200: // Right Bracket ]
		
		for (size_t i=0; i<this->jobdb.size(); ++i)
		{
			if (jobdb[i][0] == s)
			{
				if (jobdb[i][3] == L"TRIM") {
					SetDlgItemText(IDC_EDIT2,jobdb[i][2]); }
				if (jobdb[i][3] == L"LAY UP") {
					SetDlgItemText(IDC_EDIT3,jobdb[i][2]); }
				if (jobdb[i][3] == L"AUTOCLAVE") {
					SetDlgItemText(IDC_EDIT4,jobdb[i][2]); }
				if (jobdb[i][3] == L"TRIM") {
					SetDlgItemText(IDC_EDIT5,jobdb[i][2]); }
				if (jobdb[i][3] == L"OSP") {
					SetDlgItemText(IDC_EDIT9,jobdb[i][2]); }
				if (jobdb[i][3] == L"ASSY") {
					SetDlgItemText(IDC_EDIT6,jobdb[i][2]); }
				if (jobdb[i][3] == L"PAINT") {
					SetDlgItemText(IDC_EDIT7,jobdb[i][2]); }
				if (jobdb[i][3] == L"SHIPPING") {
					SetDlgItemText(IDC_EDIT8,jobdb[i][2]); }

				SetDlgItemText(IDC_EDIT10,jobdb[i][5]);
				SetDlgItemText(IDC_EDIT11,jobdb[i][6]);
				SetDlgItemText(IDC_EDIT12,jobdb[i][4]);
			}
		}
		

}

}




LRESULT JobComp::OnOK(WPARAM wParam,LPARAM lParam) {
	//save before we close!
	CDialog::OnOK();
	return true;
}

BOOL JobComp::OnEraseBkgnd(CDC* pDC) {
	BOOL bRet = CDialog::OnEraseBkgnd(pDC);
    // let the things happen after this call else it will erase everything

	CBitmap bitmap;
    // loading the bitmap
    bitmap.LoadBitmap(IDB_BITMAP7);
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
void JobComp::OnBnClickedButton1()
{
	CDialog::OnOK();
	// TODO: Add your control notification handler code here
}
