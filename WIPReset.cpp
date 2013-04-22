// WIPReset.cpp : implementation file
//

#include "stdafx.h"
#include "Tavern.h"
#include "WIPReset.h"
#include "WIPInventory.h"


// WIPReset dialog

IMPLEMENT_DYNAMIC(WIPReset, CDialog)

WIPReset::WIPReset(CWnd* pParent /*=NULL*/)
	: CDialog(WIPReset::IDD, pParent)
{

}

WIPReset::~WIPReset()
{
}

void WIPReset::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WIPReset, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &WIPReset::OnBnClickedButtonResume)
	ON_BN_CLICKED(IDC_BUTTON2, &WIPReset::OnBnClickedButtonNEW)
	ON_BN_CLICKED(IDC_BUTTON3, &WIPReset::OnBnClickedButton3)
END_MESSAGE_MAP()



int WIPReset::ClearDeptScans(CString dept) {
int total=0;

			for (size_t i=0; i<theApp.widlg.wipdb.size(); ++i)
				{
					if (theApp.widlg.wipdb[i][WIP_DEPT].CompareNoCase(dept) == 0) {
						theApp.widlg.wipdb.erase(theApp.widlg.wipdb.begin()+i);
						--i;
						total++;
						}
				}

return total;
}//ClearDeptScans



int WIPReset::CountDepartmentScans(CString dept) {
	int total=0;


			for (size_t i=0; i<theApp.widlg.wipdb.size(); ++i)
				{
					if (theApp.widlg.wipdb[i][WIP_DEPT].CompareNoCase(dept) == 0) {
						total++;
						}
				}

return total;
}//ClearDeptScans

CString WIPReset::DeptScanToText(int x) {
	CString t;
	t.Format(L"%02d",x);
	return t;
}






// WIPReset message handlers
BOOL WIPReset::OnInitDialog()
{
	SetDlgItemText(IDC_STATIC_DP,theApp.wipdepartment+L" Record Count: " + DeptScanToText(CountDepartmentScans(theApp.wipdepartment)) );


return true;
}
void WIPReset::OnBnClickedButtonResume()
{
	theApp.widlg.DoModal();
	CDialog::OnOK();
}

void WIPReset::OnBnClickedButtonNEW()
{

	if (AfxMessageBox(L"Erase ALL "+theApp.wipdepartment+L" records?",MB_YESNO,NULL) == IDNO) 
		return;

	ClearDeptScans(theApp.wipdepartment);
	theApp.widlg.DoModal();
	CDialog::OnOK();

	// TODO: Add your control notification handler code here
}

void WIPReset::OnBnClickedButton3()
{
	CDialog::OnOK();
}
