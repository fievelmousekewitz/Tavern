#pragma once


// WIPStart dialog

class WIPStart : public CDialog
{
	DECLARE_DYNAMIC(WIPStart)

public:
	WIPStart(CWnd* pParent = NULL);   // standard constructor
	virtual ~WIPStart();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);
	LRESULT OnOK(WPARAM wParam,LPARAM lParam);

// Dialog Data
	enum { IDD = IDD_WIPSTART };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
};
