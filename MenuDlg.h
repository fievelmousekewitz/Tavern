#pragma once
#include "Tavern.h"

#define ORDERSCREEN 1
#define INVENTORYSCREEN 2
#define MAGIC 3
#define MENU 4


#define OSHIPPING L"Shipping.csv"
#define OSHIMS L"Shims.csv"
#define OFREEZERS L"Freezers.csv"
#define OCORE L"Core.csv"
#define OCOREP8A L"CoreP8A.csv"
#define OCONSUMABLES L"Consumables.csv"
#define OCABINET L"Cabinet.csv"
#define OCRIBMASTER L"Cribmaster.csv"
#define OAHPAINT L"AHPaint.csv"
#define ORAWPARTS L"RawParts.csv"
#define OHARDWARE L"Hardware.csv"
#define OMETALDETAILS L"MetalDetails.csv"
#define OGENERAL L"orders.csv"



// MenuDlg dialog

class MenuDlg : public CDialog
{
	DECLARE_DYNAMIC(MenuDlg)

public:
	MenuDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MenuDlg();
	CComboBox *listselect;
	CString combopick;
	int whatbutton;
	vector < vector<CString> > csvfiles;

// Dialog Data
	enum { IDD = IDD_OPENMENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCbnSelchangeCombo1();
	void CountLines();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
