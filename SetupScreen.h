#pragma once


// SetupScreen dialog

class SetupScreen : public CDialog
{
	DECLARE_DYNAMIC(SetupScreen)

public:
	SetupScreen(CWnd* pParent = NULL);   // standard constructor
	virtual ~SetupScreen();

// Dialog Data
	enum { IDD = IDD_SETUP };
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
