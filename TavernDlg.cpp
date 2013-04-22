// TavernDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "TavernDlg.h"
#include "windows.h"
#include "Inventory.h"
//#include "CSVReader2.h"
//#include "atlconv.h"
#include <fstream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



#define VK_OEM_3 0x23
#define VK_LBRACE 219
#define VK_RBRACE 221
#define VK_ENTER 13
#define VK_PLUS 0x2B //OEM PLUS sign

// CTavernDlg dialog
	



CTavernDlg::CTavernDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTavernDlg::IDD, pParent)
{

	


m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);


}

void CTavernDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTavernDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP

ON_MESSAGE(WM_HOTKEY,OnHotKey)
ON_MESSAGE(WM_DESTROY,OnOK)
ON_WM_ERASEBKGND()
ON_BN_CLICKED(IDC_BUTTON1, &CTavernDlg::OnBnClickedButton1)
END_MESSAGE_MAP()





// CTavernDlg message handlers

BOOL CTavernDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	Addsome = false;

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
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


if(RegisterHotKey(this->m_hWnd,100,NULL,VK_LBRACE) && 
	RegisterHotKey(this->m_hWnd,200,NULL,VK_RBRACE) && 
		RegisterHotKey(this->m_hWnd,150,NULL,VK_PLUS) &&
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

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CTavernDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
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





LRESULT CTavernDlg::OnHotKey(WPARAM wParam, LPARAM lParam) {
	CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CEdit* pull = (CEdit*)GetDlgItem(IDC_EDIT2);
	CEdit* orderq = (CEdit*)GetDlgItem(IDC_EDIT8);

	CString whob;
	CString szValue;
	CString AddCount;
	
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

			edit->SetFocus();
			break;

		case 150: //+

			Addsome = true;
			orderq->SetFocus();
			break;

		case 200: // Right Bracket ]
			GetDlgItemText(IDC_EDIT1,whob);
			s = whob;
			for (size_t i=0; i<theApp.idlg.partdb.size(); ++i)
			{
				if ( theApp.idlg.partdb[i][0].CompareNoCase(s) == 0 )
				{
					SetDlgItemText(IDC_EDIT2,theApp.idlg.partdb[i][PARTDESC]);
					SetDlgItemText(IDC_EDIT3,theApp.idlg.partdb[i][MIN]);
					SetDlgItemText(IDC_EDIT4,theApp.idlg.partdb[i][STOCK]);
					SetDlgItemText(IDC_EDIT5,theApp.idlg.partdb[i][MAX]);
					SetDlgItemText(IDC_EDIT6,theApp.idlg.partdb[i][SAFETY]);
					SetDlgItemText(IDC_EDIT7,theApp.idlg.partdb[i][IUM]);

					for(size_t j=0; j<this->orderdb.size(); ++j)
					{
						if (orderdb[j][PARTNUM].CompareNoCase(s) == 0) 
						{
							if (Addsome) 
							{
								Addsome = false;
								CString oldtext;
								GetDlgItemText(IDC_EDIT8,AddCount);
								GetDlgItemText(IDC_EDIT1,oldtext);
								oldtext += " (+";
								oldtext += AddCount;
								oldtext += ")";

								SetDlgItemText(IDC_EDIT1,oldtext);

								/*GetDlgItemText(IDC_EDIT8,AddCount);
								//oldsum = atoi(AddCount);
								oldsum = _ttoi(AddCount);
								newsum = _ttoi(orderdb[j][ORDERQNUM]);
								newsum += oldsum;
								AddCount.Format(L"%i", newsum);*/
								SetDlgItemText(IDC_EDIT9,orderdb[j][ORDERQNUM]);
								SetDlgItemText(IDC_EDIT8,orderdb[j][ORDERQNUM]);


							//	this->orderdb[j][ORDERQNUM] = AddCount;
								orderq->SetFocus();
								orderq->SetSel(0,-1);
								return true;
							}//addsome

							//No Addsome
							SetDlgItemText(IDC_EDIT8,this->orderdb[j][ORDERQNUM]);
							SetDlgItemText(IDC_EDIT9,this->orderdb[j][ORDERQNUM]);
							orderq->SetFocus();
							orderq->SetSel(0,-1);
							return true;
						}//orderdb == 0
					}//orderdb for

				if (Addsome)
				{
					Addsome = false;
					CString oldtext;
					GetDlgItemText(IDC_EDIT8,AddCount);
					GetDlgItemText(IDC_EDIT1,oldtext);
					oldtext += " (+";
					oldtext += AddCount;
					oldtext += ")";
			
					orderq->SetFocus();
					orderq->SetSel(0,-1);
					return true;
				}

			

				orderq->SetFocus();
				orderq->SetSel(0,-1);
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
	

	case 400: // Enter Key (to save the order qty)
		CString howmany,newitem;
		// GetDlgItemText(IDC_EDIT1,itm);
		GetDlgItemText(IDC_EDIT8,howmany);

		for(size_t k=0; k<this->orderdb.size(); ++k)
		{
			if (this->orderdb[k][PARTNUM].CompareNoCase(s) == 0)
			{
				this->orderdb[k][ORDERQNUM] = howmany;
				SetDlgItemText(IDC_EDIT9,howmany);
				return true;
			}
	}
	//else.....
		
		for (size_t i=0; i<theApp.idlg.partdb.size(); ++i)
		{
			if (theApp.idlg.partdb[i][0].CompareNoCase(s) == 0)
			{
				vector <CString> b;
				b.push_back(theApp.idlg.partdb[i][PARTNUM]);
				b.push_back(theApp.idlg.partdb[i][PARTDESC]);
				b.push_back(theApp.idlg.partdb[i][MIN]);
				b.push_back(theApp.idlg.partdb[i][STOCK]);
				
				b.push_back(theApp.idlg.partdb[i][MAX]);
				b.push_back(theApp.idlg.partdb[i][SAFETY]);
				b.push_back(theApp.idlg.partdb[i][IUM]);
				b.push_back(theApp.idlg.partdb[i][VENDORNAME]);
				b.push_back(howmany);
				
				this->orderdb.push_back(b);
				SetDlgItemText(IDC_EDIT9,howmany);
				return 0;
			}
		}
	PLAY_EXCLAMATION
	MessageBox(L"WARNING: Item not stored. Does item exist?",L"WARNING",NULL);
	
	return true;

}//switch wParam
	
return true;
	
}




LRESULT CTavernDlg::OnOK(WPARAM wParam,LPARAM lParam) { //WPARAM wParam,LPARAM lParam
	//save before we close!
	this->writeorderdb();

	CDialog::OnOK();
	return true;
}



BOOL CTavernDlg::OnEraseBkgnd(CDC* pDC) {
	BOOL bRet = CDialog::OnEraseBkgnd(pDC);
    // let the things happen after this call else it will erase everything

	CBitmap bitmap;
    // loading the bitmap
    bitmap.LoadBitmap(IDB_BITMAP1);
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

#endif

void CTavernDlg::OnBnClickedButton1()
{
	this->writeorderdb();
	CDialog::OnOK();
	// TODO: Add your control notification handler code here
}
