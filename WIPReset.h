#include "tavern.h"

#pragma once


// WIPReset dialog

class WIPReset : public CDialog
{
	DECLARE_DYNAMIC(WIPReset)

public:
	WIPReset(CWnd* pParent = NULL);   // standard constructor
	virtual ~WIPReset();

// Dialog Data
	enum { IDD = IDD_WIPRESET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonResume();
	afx_msg void OnBnClickedButtonNEW();
	int ClearDeptScans(CString dept);
	int CountDepartmentScans(CString dept);
	CString DeptScanToText(int x);
	afx_msg void OnBnClickedButton3();
};
