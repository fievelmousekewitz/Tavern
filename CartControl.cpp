// CartControl.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "CartControl.h"


#define VK_OEM_3 0x23
#define VK_LBRACE 219
#define VK_RBRACE 221
#define VK_ENTER 13
#define VK_QUESTION 187

#define CARTNO 0
#define CARTPARTNUM 1
#define SUGGESTED 2
#define ADDED 3


#define PARTNUM 0
#define PARTDESC 1
#define MIN 2
#define STOCK 3
#define MAX 4
#define SAFETY 5
#define IUM 6
#define VENDORNAME 7
#define ORDERQNUM 8

// CCartControl dialog

IMPLEMENT_DYNAMIC(CCartControl, CDialog)

CCartControl::CCartControl(CWnd* pParent /*=NULL*/)
	: CDialog(CCartControl::IDD, pParent)
{

}

CCartControl::~CCartControl()
{
}

void CCartControl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCartControl, CDialog)
	ON_MESSAGE(WM_HOTKEY,OnHotKey)
	ON_MESSAGE(WM_DESTROY,OnOK)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON1, &CCartControl::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCartControl message handlers
BOOL CCartControl::OnInitDialog()
{
	CDialog::OnInitDialog();
	this->WhatCart = "NOCART";
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


	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	//SetIcon(m_hIcon, TRUE);			// Set big icon
//	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


if(RegisterHotKey(this->m_hWnd,100,NULL,VK_LBRACE) && 
	RegisterHotKey(this->m_hWnd,200,NULL,VK_RBRACE) && 
		RegisterHotKey(this->m_hWnd,400,NULL,VK_ENTER))
			
		
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

void CCartControl::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
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






LRESULT CCartControl::OnHotKey(WPARAM wParam, LPARAM lParam) {
	CEdit* cartnobox = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* added = (CEdit*)GetDlgItem(IDC_EDIT5);
	CEdit* partnobox = (CEdit*)GetDlgItem(IDC_EDIT2);
	CString whob;
	CString szValue;
	
	switch(wParam) {
		
		case 100: // Left Bracket [
	
		//	SetDlgItemText(IDC_EDIT1,NULL);
			SetDlgItemText(IDC_EDIT2,NULL);
			SetDlgItemText(IDC_EDIT3,NULL);
			SetDlgItemText(IDC_EDIT4,NULL);
			SetDlgItemText(IDC_EDIT5,NULL);
			partnobox->SetFocus();
			break;

		case 200: // Right Bracket ]
			GetDlgItemText(IDC_EDIT2,whob);
			
			if (whob.Left(4) == L"CART") {
				this->WhatCart = whob;
				SetDlgItemText(IDC_EDIT1,whob);
				SetDlgItemText(IDC_EDIT2,L"");
				return true;
			}
			if (this->WhatCart == L"NOCART") {
				SetDlgItemText(IDC_EDIT1,L"NO CART!");
				PLAY_EXCLAMATION
				return true;
			}
			
			s = whob;
			
			for (size_t i=0; i<theApp.idlg.partdb.size(); ++i)
			{
				if ( theApp.idlg.partdb[i][0].CompareNoCase(s) == 0 )
				{
					SetDlgItemText(IDC_EDIT3,theApp.idlg.partdb[i][PARTDESC]);
		
			for(size_t j = 0;j < cartorderdb.size();++j )	
			{
			 //I hope no one ever sees this code...
						if (this->cartorderdb[j][CARTPARTNUM].CompareNoCase(s) == 0) 
						{
						//	MessageBox(L"FOUNDPARTNUM",L"GRAR");
							if (this->cartorderdb[j][CARTNO].CompareNoCase(this->WhatCart) == 0) 
							{
							//	MessageBox(L"FOUND PART",L"FOUND PART");
								if (this->cartorderdb[j].size() > SUGGESTED) //SUGGESTED
									SetDlgItemText(IDC_EDIT4,this->cartorderdb[j][SUGGESTED]);
								if (this->cartorderdb[j].size() > ADDED) {
								SetDlgItemText(IDC_EDIT5,this->cartorderdb[j][ADDED]);
								SetDlgItemText(IDC_EDIT6,this->cartorderdb[j][ADDED]);
								}
								added->SetFocus();
								added->SetSel(0,-1);
								return true;
							}//cartorderdb == 0
						}
					}//cartorderdb for
				//else.....
					SetDlgItemText(IDC_EDIT4,L"???");
				added->SetFocus();
				added->SetSel(0,-1);
				return true;
			}//if part = part
		}//for part = part


			//If nothing is found...
			SetDlgItemText(IDC_EDIT2,L"ITEM NOT FOUND");
			SetDlgItemText(IDC_EDIT3,L"");
			SetDlgItemText(IDC_EDIT4,L"");
			SetDlgItemText(IDC_EDIT5,L"");
			SetDlgItemText(IDC_EDIT6,L"");
			SetDlgItemText(IDC_EDIT7,L"");
			PLAY_EXCLAMATION
			return true;
	

	case 400: // Enter Key (to save the cartorder qty)
		CString howmany,newitem;
		// GetDlgItemText(IDC_EDIT1,itm);
		GetDlgItemText(IDC_EDIT5,howmany);
		vector <CString> y;
		for(size_t k=0; k<this->cartorderdb.size(); ++k)
		{
			if (this->cartorderdb[k][CARTPARTNUM].CompareNoCase(s) == 0 && 
				this->cartorderdb[k][CARTNO].CompareNoCase(this->WhatCart) == 0)
			{
				if (this->cartorderdb[k].size() > ADDED) {
				this->cartorderdb[k][ADDED] = howmany;
				SetDlgItemText(IDC_EDIT6,howmany);
				}
				
				return true;
			}
	}
	//else.....
		
		for (size_t i=0; i<theApp.idlg.partdb.size(); ++i)
		{
			if (theApp.idlg.partdb[i][0].CompareNoCase(s) == 0)
			{
				vector <CString> b;
				b.push_back(this->WhatCart);
				b.push_back(theApp.idlg.partdb[i][PARTNUM]);
				b.push_back(L"???"); //Suggested value does not exist for this part

				b.push_back(howmany);
				
				this->cartorderdb.push_back(b);
				SetDlgItemText(IDC_EDIT6,howmany);
				return true;
			}
		}
	PLAY_EXCLAMATION
	MessageBox(L"WARNING: Item not stored. Does item exist?",L"WARNING",NULL);
	
	return true;

}//switch wParam
	
return true;
	
}




LRESULT CCartControl::OnOK(WPARAM wParam,LPARAM lParam) { //WPARAM wParam,LPARAM lParam
	//save before we close!
	this->writecartorderdb();

	CDialog::OnOK();
	return true;
}


BOOL CCartControl::OnEraseBkgnd(CDC* pDC) {
	BOOL bRet = CDialog::OnEraseBkgnd(pDC);
    // let the things happen after this call else it will erase everything

	CBitmap bitmap;
    // loading the bitmap
    bitmap.LoadBitmap(IDB_BITMAP8);
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



void CCartControl::OnBnClickedButton1()
{
	this->writecartorderdb();
	CDialog::OnOK();
	// TODO: Add your control notification handler code here
}