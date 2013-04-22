#include "atlconv.h"
#include "afx.h"
#include <vector>
#include <iostream>
#include <sstream>
#pragma once

//REMOVE:#define INVDBFILENAME L"inventory.csv"
#define INVENTORYFILENAME L"invlist.csv"

// Inventory dialog

class Inventory : public CDialog
{
	DECLARE_DYNAMIC(Inventory)

public:
	Inventory(CWnd* pParent = NULL);   // standard constructor
	virtual ~Inventory();
	LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);
	LRESULT OnOK(WPARAM wParam,LPARAM lParam);
	LRESULT Inventory::OnSetText(WPARAM wParam,LPARAM lParam);
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
	CStdioFile partdbfile; 
	CStdioFile invdbfile;
	CString fn;
	CString s;
	
	vector < vector<CString> > partdb;
	vector < vector<CString> > invdb;
	bool Addsome;

	vector <CString> v;
	vector <CString> z;

int openinvdb(CString invdbfilename) {
	int linecount=0;
		fn = invdbfilename;
		fn += ".csv";
		invdb.clear();
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");

		if (!invdbfile.Open(fn, CStdioFile::modeCreate | CStdioFile::shareDenyWrite |
			CStdioFile::modeNoTruncate | CFile::typeText, &e)) {
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}
	
		
		while( invdbfile.ReadString( line ) ) 
		{
			linecount++;
			line.TrimRight();
			z.clear();
			int index = 0;
			CString field;
			while (AfxExtractSubString(field,line,index,_T('^')))
			{
				z.push_back(field);
				++index;
			}
			invdb.push_back(z);
		}

		invdbfile.Close();
		return linecount;

	}



bool opendb() {  
		LPCTSTR filename =INVENTORYFILENAME;
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");

		if (!partdbfile.Open(filename, CStdioFile::modeReadWrite | 
			CStdioFile::shareDenyWrite | CStdioFile::modeNoTruncate | CFile::typeText, &e)) {
			e.GetErrorMessage(strError,512);
			//AfxMessageBox(strError);
			MessageBox(NULL,strError,NULL);
			return false;
		}

	while( partdbfile.ReadString( line )   )
	{
		line.TrimRight();
		v.clear();
		int index = 0;
		CString field;
		while (AfxExtractSubString(field,line,index,_T('^')))
		{
			v.push_back(field);
			++index;
		}
		partdb.push_back(v);

	}
	partdbfile.Close();
	return true;

}



bool writeinvdb() {
		CString filename = fn;
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");
		if (!invdbfile.Open(filename, CStdioFile::modeCreate | CFile::modeWrite | CFile::typeText, &e)) 
		{
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}

		vector < vector<CString> >::iterator it;
		vector<CString>::iterator its;

		for (it = invdb.begin(); it != invdb.end(); it++)
		{
			line = "";
			for(its = (*it).begin(); its < (*it).end(); its++)
			{
				
				line += *its; 
				if (its < (*it).end() -1) {
					line += '^';
				}
				
			}
			invdbfile.WriteString( line );
		}
	invdbfile.Close();
	return true;
	}






// Dialog Data
	enum { IDD = IDD_INVENTORY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
