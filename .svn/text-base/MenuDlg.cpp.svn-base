// MenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "MenuDlg.h"
#include "Inventory.h"
#include "TavernDlg.h"
#include "SplashWnd.h"
#include "WIPInventory.h"
//#include <led_drvr.h>

//using Microsoft.WindowsCE.Forms;





// MenuDlg dialog

IMPLEMENT_DYNAMIC(MenuDlg, CDialog)

MenuDlg::MenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MenuDlg::IDD, pParent)
{

	whatbutton = 0;


}

MenuDlg::~MenuDlg()
{
}

void MenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MenuDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MenuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MenuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MenuDlg::OnBnClickedButton3)
	ON_WM_ERASEBKGND()
	ON_CBN_SELCHANGE(IDC_COMBO1, &MenuDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT2, &MenuDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &MenuDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MenuDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &MenuDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// MenuDlg message handlers




BOOL MenuDlg::OnInitDialog()
{
//	InputPanel IP;

	CDialog::OnInitDialog();
	CSplashWnd::ShowSplashScreen(4000, IDB_BITMAP3);
	CString xf;
	
	theApp.idlg.opendb();       //invlist.csv [main parts file from vantage]
	//theApp.jdlg.openjobdb();    //jobcomp.csv [main jobs file from vantage]
	theApp.dlg.openorderdb();
	theApp.cdlg.opencartorderdb();
	theApp.widlg.openwipdb();
	
	
    xf.Format(L"%i",theApp.idlg.openinvdb(L"General"));   //orders.csv
	SetDlgItemText(IDC_EDIT2,xf);
	SetDlgItemText(IDC_COMBO1,L"General");

	//theApp.dlg.opendb(); 
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

PLAY_START

return true;
}


void MenuDlg::OnBnClickedButton1()
{
	theApp.dlg.DoModal();
	//theApp.m_pMainWnd = &theApp.dlg;

	//m_pMainWnd = &dlg;
	//this->whatbutton = ORDERSCREEN;
	//this->OnOK();

}

void MenuDlg::OnBnClickedButton2()
{
	theApp.idlg.DoModal();
}

void MenuDlg::OnBnClickedButton3()
{
	theApp.wdlg.DoModal();
	// TODO: Add your control notification handler code here
}

BOOL MenuDlg::OnEraseBkgnd(CDC* pDC) {
	BOOL bRet = CDialog::OnEraseBkgnd(pDC);
    // let the things happen after this call else it will erase everything

	CBitmap bitmap;
    // loading the bitmap
    bitmap.LoadBitmap(IDB_BITMAP2);
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


void MenuDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_COMBO1,combopick);
	int many=0;
	CString manys;
	many = theApp.idlg.openinvdb(combopick);
	manys.Format(L"%i",many);
	SetDlgItemText(IDC_EDIT2,manys);
}


void MenuDlg::CountLines() {

	//CStdioFile inFile("myfilename", CFile::modeRead);
	CStdioFile CLFile;
	CString sRow;
	CString rowcount;
	int nRow;

	for (int i = 0;csvfiles[i][0];i++) 
	{
		CLFile.Open(csvfiles[i][1], CStdioFile::modeRead);
		nRow=1;
		// Iterate through the Rows
		while( CLFile.ReadString(sRow) != FALSE )
		{
			nRow++;
		}
		rowcount.Format(L"%i",nRow);
		csvfiles[i][1] = rowcount;
		CLFile.Close();
	}


}
void MenuDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void MenuDlg::OnBnClickedButton4()
{
	theApp.cdlg.DoModal();

	// TODO: Add your control notification handler code here
}

void MenuDlg::OnBnClickedButton5()
{
// PlaySound("SystemAsterisk", 0, SND_ALIAS Or SND_ASYNC)
CDialog::OnOK();

	// TODO: Add your control notification handler code here
}

void MenuDlg::OnBnClickedButton6()
{
	theApp.setupdlg.DoModal();

}
