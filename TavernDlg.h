// TavernDlg.h : header file
//
//#include "csvreader2.h"

#include "atlconv.h"
#include "afx.h"
#include <iostream>
#include <vector>
#include <sstream>
//#include "Inventory.h"


//#include <stdio.h>
//#include "stdiofileex.h"

#define ORDERDBFILENAME L"orders.csv"
#define PARTNUM 0
#define PARTDESC 1
#define MIN 2
#define STOCK 3
#define MAX 4
#define SAFETY 5
#define IUM 6
#define VENDORNAME 7
#define ORDERQNUM 8


	


#pragma once


using namespace std;


// CTavernDlg dialog



class CTavernDlg : public CDialog
{
// Construction
public:
	LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);
	LRESULT OnOK(WPARAM wParam,LPARAM lParam); 
	CTavernDlg(CWnd* pParent = NULL);	// standard constructor
	bool Addsome;
	CStdioFile orderdbfile;
	CString s;
	vector < vector<CString> > orderdb;

	vector <CString> v;
	vector <CString> z;

	bool openorderdb() {
	
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");

		if (!orderdbfile.Open(ORDERDBFILENAME, CStdioFile::modeCreate | CStdioFile::shareDenyWrite |
			CStdioFile::modeNoTruncate | CFile::typeText, &e)) {
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}
	
		int index;
		
		while( orderdbfile.ReadString( line ) ) 
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
			orderdb.push_back(z);
		}

		orderdbfile.Close();
		return true;

	}




	bool writeorderdb() {
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");
		if (!orderdbfile.Open(ORDERDBFILENAME, CStdioFile::modeCreate | CFile::modeWrite | CFile::typeText, &e)) 
		{
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}

		vector < vector<CString> >::iterator it;
		vector<CString>::iterator its;

		for (it = orderdb.begin(); it != orderdb.end(); it++)
		{
			line = "";
			for(its = (*it).begin(); its < (*it).end(); its++)
			{
				
				line += *its; 
				if (its < (*it).end() -1) {
					line += '^';
				}
				
			}
			orderdbfile.WriteString( line );
		}
	orderdbfile.Close();
	return true;
	}



// Dialog Data
	enum { IDD = IDD_TAVERN_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
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





class PartWhse {
public:
	CString PartNum;
	int minqty,onhand,maxqty;
};


