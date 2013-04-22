#pragma once

#define JOBFILENAME L"jobcomp.csv"

// JobComp dialog

class JobComp : public CDialog
{
	DECLARE_DYNAMIC(JobComp)

public:
	JobComp(CWnd* pParent = NULL);   // standard constructor
	virtual ~JobComp();
	LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);
	LRESULT OnOK(WPARAM wParam,LPARAM lParam);


	CStdioFile jobdbfile;
	vector < vector<CString> > jobdb;

	vector <CString> v;


bool openjobdb() {
		LPCTSTR filename = JOBFILENAME;
		CString line;
		CFileException e;
		TCHAR strError[512] = _T("");

		if (!jobdbfile.Open(filename, CStdioFile::modeCreate | CStdioFile::shareDenyWrite |
			CStdioFile::modeNoTruncate | CFile::typeText, &e)) {
				e.GetErrorMessage(strError,512);
				AfxMessageBox(strError);
				return false;
		}
	
		
		while( jobdbfile.ReadString( line ) ) 
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
			jobdb.push_back(v);
		}

		jobdbfile.Close();
		return true;

	}


// Dialog Data
	enum { IDD = IDD_JOBCOMP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButton1();
};
