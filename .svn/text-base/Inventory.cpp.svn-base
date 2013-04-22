// Inventory.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "Inventory.h"

#define VK_OEM_3 0x23
#define VK_LBRACE 219
#define VK_RBRACE 221
#define VK_ENTER 13
#define VK_PLUS 187  //MOD_SHIFT

#define IPARTNUM 0
#define INVNUM 1

// Inventory dialog

IMPLEMENT_DYNAMIC(Inventory, CDialog)

Inventory::Inventory(CWnd* pParent /*=NULL*/)
	: CDialog(Inventory::IDD, pParent)
{


}

Inventory::~Inventory()
{
}

void Inventory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Inventory, CDialog)
	ON_WM_ERASEBKGND()
ON_MESSAGE(WM_HOTKEY,OnHotKey)
ON_MESSAGE(WM_DESTROY,OnOK)
ON_MESSAGE(WM_SETTEXT,OnSetText)
//ON_MESSAGE(WM_CTLCOLORSTATIC,OnCtlColor)
ON_WM_CTLCOLOR()

ON_BN_CLICKED(IDC_BUTTON1, &Inventory::OnBnClickedButton1)
END_MESSAGE_MAP()



BOOL Inventory::OnInitDialog()
{
	CDialog::OnInitDialog();
int cx, cy;
Addsome = false;
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

if(RegisterHotKey(this->m_hWnd,100,NULL,VK_LBRACE) && 
	RegisterHotKey(this->m_hWnd,200,NULL,VK_RBRACE) &&
		RegisterHotKey(this->m_hWnd,150,MOD_SHIFT,VK_PLUS) && 
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





LRESULT Inventory::OnHotKey(WPARAM wParam, LPARAM lParam) {
CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);
CEdit* pull = (CEdit*)GetDlgItem(IDC_EDIT2);
CEdit* invq = (CEdit*)GetDlgItem(IDC_EDIT3);

CString whob;
	CString AddCount;
		//int indexnum,length;
		CString szValue;
int oldsum,newsum;

switch(wParam) {
		
	case 100: // Left Bracket [
	
	SetDlgItemText(IDC_EDIT1,NULL);
	SetDlgItemText(IDC_EDIT2,NULL);
	SetDlgItemText(IDC_EDIT3,NULL);
	SetDlgItemText(IDC_EDIT4,NULL);
	SetDlgItemText(IDC_EDIT5,NULL);
	

	edit->SetFocus();
	return true;


	case 150:

		Addsome = true;
		invq->SetFocus();
		break;

	case 200: // Right Bracket ]
			GetDlgItemText(IDC_EDIT1,whob);
			s = whob;
			for (size_t i=0; i<this->partdb.size(); ++i)
			{
				if (partdb[i][0].CompareNoCase(s) == 0)
				{
					SetDlgItemText(IDC_EDIT2,partdb[i][PARTDESC]);
					SetDlgItemText(IDC_EDIT5,partdb[i][IUM]);
	
						for(size_t j=0; j<this->invdb.size(); ++j)
						{
							if (  invdb[j][IPARTNUM].CompareNoCase(s) == 0) 
							{
								if (Addsome) 
								{
									SetDlgItemText(IDC_EDIT6,L"Scanned already.");
									Addsome = false;
									CString oldtext;
									GetDlgItemText(IDC_EDIT3,AddCount);
									GetDlgItemText(IDC_EDIT1,oldtext);
									oldtext += " (+";
									oldtext += AddCount;
									oldtext += ")";
									SetDlgItemText(IDC_EDIT1,oldtext);

									GetDlgItemText(IDC_EDIT3,AddCount);
									//oldsum = atoi(AddCount);
									oldsum = _ttoi(AddCount);
									newsum = _ttoi(invdb[j][INVNUM]);
									newsum += oldsum;
									AddCount.Format(L"%i", newsum);
									SetDlgItemText(IDC_EDIT3,AddCount);
									SetDlgItemText(IDC_EDIT4,AddCount);


									this->invdb[j][INVNUM] = AddCount;
									invq->SetFocus();
									invq->SetSel(0,-1);
									return true;
								}//addsome

							SetDlgItemText(IDC_EDIT3,invdb[j][INVNUM]);
							SetDlgItemText(IDC_EDIT4,invdb[j][INVNUM]);
						}
					}



			if (Addsome)
				{
					Addsome = false;
			
					for (size_t i=0; i<this->partdb.size(); ++i)
					{
						if (this->partdb[i][0].CompareNoCase(s) == 0)
						{
							SetDlgItemText(IDC_EDIT6,L"First Scan");
							vector <CString> b;
							GetDlgItemText(IDC_EDIT3,AddCount);
							b.push_back(partdb[i][IPARTNUM]);
							b.push_back(AddCount);
				
							this->invdb.push_back(b);
							SetDlgItemText(IDC_EDIT4,AddCount);
							invq->SetFocus();
							invq->SetSel(0,-1);
							return true;
						}
					}

			}





				invq->SetFocus();
				invq->SetSel(0,-1);
				return 0;
			}
		}
			//If nothing is found...
				SetDlgItemText(IDC_EDIT2,L"ITEM NOT FOUND");
				SetDlgItemText(IDC_EDIT3,L"");
				SetDlgItemText(IDC_EDIT4,L"");
				SetDlgItemText(IDC_EDIT5,L"");
				PLAY_EXCLAMATION
	break;
	
	case 300: // Enter Key (to save the order qty)
	 CString itm,howmany,newitem;
	 GetDlgItemText(IDC_EDIT1,itm);
	 GetDlgItemText(IDC_EDIT3,howmany);
		for(size_t k=0; k<this->invdb.size(); ++k)
		{
			if (this->invdb[k][IPARTNUM].CompareNoCase(itm) == 0)
			{
				this->invdb[k][INVNUM] = howmany;
				SetDlgItemText(IDC_EDIT4,howmany);
				return true;
			}
		}
	//else.....
		
for (size_t i=0; i<this->partdb.size(); ++i)
		{
			if (theApp.idlg.partdb[i][0].CompareNoCase(s) == 0)
			{
				vector <CString> b;
				b.push_back(partdb[i][IPARTNUM]);
				b.push_back(howmany);
				

				this->invdb.push_back(b);
				SetDlgItemText(IDC_EDIT4,howmany);
				return 0;
			}
		}
PLAY_EXCLAMATION
MessageBox(L"WARNING: Item not stored. Does item exist?",L"WARNING",NULL);


		return true;

}//switch wParam
	
		return true;
	
}





LRESULT Inventory::OnOK(WPARAM wParam,LPARAM lParam) {
	//save before we close!
	this->writeinvdb();

	CDialog::OnOK();
	return true;
}

// Inventory message handlers

BOOL Inventory::OnEraseBkgnd(CDC* pDC) {
BOOL bRet = CDialog::OnEraseBkgnd(pDC);
    // let the things happen after this call else it will erase everything

CBitmap bitmap;
    // loading the bitmap
    bitmap.LoadBitmap(IDB_BITMAP6);
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


void Inventory::OnBnClickedButton1()
{
	this->writeinvdb();
	CDialog::OnOK();
	// TODO: Add your control notification handler code here
}

HBRUSH Inventory::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{


	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if ( nCtlColor == CTLCOLOR_STATIC ) 
	{
	
	//	pDC->SetBkColor(RGB(0, 0, 255));
		
		return hbr;
	}
	else 
		return CDialog::OnCtlColor(pDC,pWnd,nCtlColor); 
	
}

LRESULT Inventory::OnSetText(WPARAM wParam,LPARAM lParam)
{
   LRESULT Result = Default();
   Invalidate();
   UpdateWindow();
   return Result;
}