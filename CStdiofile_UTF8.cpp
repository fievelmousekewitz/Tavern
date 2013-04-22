#include "stdafx.h"
#include "CStdioFile_UTF8.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/**
 * Read an UTF8 encoded string from storage and convert it as appropriate.
 * The code is snipped from the MFC implementation of CStdioFile::ReadString
 * and adapted as appropriate.
 */
LPTSTR CStdioFile_UTF8::ReadString(LPTSTR lpsz, UINT nMax)
{
	ASSERT(lpsz != NULL);
	ASSERT(AfxIsValidAddress(lpsz, nMax));
	ASSERT(m_pStream != NULL);

	if (lpsz == NULL) {
		AfxThrowInvalidArgException();
	}

	char *buf = new char[nMax]; 
	BOOL read_failed = fgets(buf, nMax, m_pStream) == NULL;
	if (read_failed && !feof(m_pStream)) {
		clearerr(m_pStream);
		AfxThrowFileException(CFileException::generic, _doserrno, m_strFileName);
	}
    if (!read_failed) {
#if defined(_UNICODE)	
    	WCHAR *wbuf = new WCHAR[nMax];
    	MultiByteToWideChar(CP_UTF8, 0, buf, strlen(buf)+1, wbuf, nMax);
    	wcsncpy(lpsz, wbuf, nMax);
    	delete [] wbuf;
#else
    	strncpy(lpsz, buf, nMax);
#endif
        delete [] buf;
    }

	return read_failed ? NULL : lpsz;
}

/**
 * Read an UTF8 encoded string from storage and convert it as appropriate.
 * The code is snipped from the MFC implementation of CStdioFile::ReadString
 * and adapted as appropriate.
 */
BOOL CStdioFile_UTF8::ReadString(CString& rString)
{
	ASSERT_VALID(this);

	rString = _T("");    // empty string without deallocating
	const int nMaxSize = 128;
	LPTSTR lpsz = rString.GetBuffer(nMaxSize);
	LPTSTR lpszResult;
	int nLen = 0;
	for (;;)
	{
		// Required conversions are done here. If the MFC implementation had
        // called ReadString here as well, instead of _fgetts directly, I
        // wouldn't have to do this override at all.
        lpszResult = ReadString(lpsz, nMaxSize+1);
		rString.ReleaseBuffer();

		// handle error/eof case
		if (lpszResult == NULL && !feof(m_pStream))
		{
			clearerr(m_pStream);
			AfxThrowFileException(CFileException::generic, _doserrno,
				m_strFileName);
		}

		// if string is read completely or EOF
		if (lpszResult == NULL ||
			(nLen = (int)lstrlen(lpsz)) < nMaxSize ||
			lpsz[nLen-1] == '\n')
			break;

		nLen = rString.GetLength();
		lpsz = rString.GetBuffer(nMaxSize + nLen) + nLen;
	}

	// remove '\n' from end of string if present
	lpsz = rString.GetBuffer(0);
	nLen = rString.GetLength();
	if (nLen != 0 && lpsz[nLen-1] == '\n')
		rString.GetBufferSetLength(nLen-1);

	return nLen != 0;
}

/**
 * Write the given string in UTF8 format to storage.
 * The code is snipped from the MFC implementation of CStdioFile::WriteString
 * and adapted as appropriate.
 */
void CStdioFile_UTF8::WriteString(LPCTSTR lpsz)
{
	ASSERT(lpsz != NULL);
	ASSERT(m_pStream != NULL);
	
	if (lpsz == NULL) {
		AfxThrowInvalidArgException();
	}

#if defined(_UNICODE)
	int lpsz_len = lstrlen(lpsz);
	int buf_len = WideCharToMultiByte(CP_UTF8, 0, lpsz, lpsz_len, 0, 0, 0, 0)+1;
	char *buf = new char[buf_len+1];
	WideCharToMultiByte(CP_UTF8, 0, lpsz, lpsz_len, buf, buf_len, 0, 0);
	buf[buf_len] = 0;
	if (fputs(buf, m_pStream) == EOF) {
		AfxThrowFileException(CFileException::diskFull, _doserrno, m_strFileName);
	}
	delete [] buf;
#else
	if (fputs(lpsz, m_pStream) == EOF) {
		AfxThrowFileException(CFileException::diskFull, _doserrno, m_strFileName);
	}
#endif
}

/**
 * Checks for a valid UTF8 Byte Order Mark at the beginning of the file.
 * Resets the file position os side effect.
 */
BOOL CStdioFile_UTF8::ReadBOM()
{
	const char utf8_bom[] = {'\xef', '\xbb', '\xbf'};
	BOOL ok = FALSE;

    SeekToBegin();
	char buf[3];
	if (Read(buf, 3) == 3) {
		ok = strncmp(buf, utf8_bom, 3) == 0;
	}

	if (!ok) SeekToBegin(); // Reset to beginning if BOM not present

	return ok;
}

/**
 * Writes an UTF8 Byte order Mark at the beginning of the file.
 * Resets the file position os side effect.
 */
void CStdioFile_UTF8::WriteBOM()
{
	const char utf8_bom[] = {'\xef', '\xbb', '\xbf'};

    SeekToBegin();
	Write(utf8_bom, sizeof(utf8_bom));
}
