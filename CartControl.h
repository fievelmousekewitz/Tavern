#pragma once

#define CARTORDERDBFILENAME L"carts.csv"

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

class CCartControl : public CDialog
{
	DECLARE_DYNAMIC(CCartControl)

public:
	LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);
	LRESULT OnOK(WPARAM wParam,LPARAM lParam); 
	CString WhatCart; //What Cart are we working on?
	CCartControl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCartControl();


	CStdioFile cartorderdbfile;
	CString s;
	vector < vector<CString> > cartorderdb;

	vector <CString> v;
	vector <CString> z;


// Dialog Data
	enum { IDD = IDD_CART };

	
	bool opencartorderdb() {
	
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");

		if (!cartorderdbfile.Open(CARTORDERDBFILENAME, CStdioFile::modeCreate | CStdioFile::shareDenyWrite |
			CStdioFile::modeNoTruncate | CFile::typeText, &e)) {
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}
	
		int index;
		
		while( cartorderdbfile.ReadString( line ) ) 
		{
			line.TrimRight();
			z.clear();
			index = 0;
			CString field;
			
			while (AfxExtractSubString(field,line,index,_T('^')))
			{
				z.push_back(field);
				++index;
			}

			//here's a little kludge to sweep the bad data under the rug...
			while (z.size() <= ADDED) {
				z.push_back(L"0");
			}

			cartorderdb.push_back(z);
		}

		cartorderdbfile.Close();
		return true;

	}

	bool writecartorderdb() {
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");
		if (!cartorderdbfile.Open(CARTORDERDBFILENAME, CStdioFile::modeCreate | CFile::modeWrite | CFile::typeText, &e)) 
		{
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}

		vector < vector<CString> >::iterator it;
		vector<CString>::iterator its;

		for (it = cartorderdb.begin(); it != cartorderdb.end(); it++)
		{
			line = "";
			for(its = (*it).begin(); its < (*it).end(); its++)
			{
				
				line += *its; 
				if (its < (*it).end() -1) {
					line += '^';
				}
				
			}
			cartorderdbfile.WriteString( line );
		}
	cartorderdbfile.Close();
	return true;
	}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
	#endif
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButton1();


};
