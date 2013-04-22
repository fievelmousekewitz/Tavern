#pragma once
#if !defined(CSTDIOFILE_UTF8_INC_)
#define CSTDIOFILE_UTF8_INC_

/**
 * This class adapts the CStdioFile MFC class to read and write to UTF8 
 * encoded files. If the application is compiled with unicode support, all
 * UTF8 character sequences are handled, else only the normal ASCII7 subset.
 */
class CStdioFile_UTF8 : public CStdioFile
{
public:
	// Duplicate the standard constructors
	CStdioFile_UTF8() : CStdioFile() {}
	CStdioFile_UTF8(FILE* pOpenStream) : CStdioFile(pOpenStream) {}
	CStdioFile_UTF8(LPCTSTR lpszFileName, UINT nOpenFlags) : CStdioFile(lpszFileName, nOpenFlags) {}

    // Override these methods for UTF8 conversion
	virtual LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
	virtual BOOL ReadString(CString& rString);
	virtual void WriteString(LPCTSTR lpsz);

    // Read and write an optional Byte Order Mark
	BOOL ReadBOM();
	void WriteBOM();
};

#endif
