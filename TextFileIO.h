///////////////////////////////////////////////////////////////////////////////
// You can read,modify,delete or reuse this code in any where you liked to.
// But tou SHOULD NEVER DELETE the following copyright infomation.
// Copyright(C) 2005-2006 cokkiy.org cokkiy@gmail.com
////////////////////////////////////////////////////////////////////////////////

//********************************************************
//
//        ANSI/UNT8/UTF16-Big Endian/UTF16-Little Endian
//            File read and write in line mode
//
//            Copyright(c) 2005 cokkiy@gmail.com
//
//  Please attention:The Ansi version function DOSE NOT test any more,
//  If you want use this file in ANSI program,please test it yourself
//********************************************************


#ifndef _TEXTFILEIO_H_
#define _TEXTFILEIO_H_

#pragma once

#include <stdio.h>
#include <string>
using namespace std;
#include <windows.h>
#include <tchar.h>

// Define tstring
#ifdef UNICODE||_UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif
// define ReadLine
#ifdef UNICODE||_UNICODE
#define ReadLine ReadLineW
#else
#define ReadLine ReadLineA
#endif

// Define WriteLine
#ifdef UNICODE||_UNICODE
#define WriteLine WriteLineW
#else
#define WriteLine WriteLineA
#endif

// Define check file encoding type
#ifdef UNICODE||_UNICODE
#define CheckFileEncodingType CheckFileEncodingTypeW
#else
#define CheckFileEncodingType CheckFileEncodingTypeA
#endif

// CTextFileIO class declaration
class CTextFileIO
{
public:
	CTextFileIO(void);
public:
	~CTextFileIO(void);
public:
	CTextFileIO(const WCHAR* filename,  WCHAR *mode=L"rb");
	CTextFileIO(const char *filename,char *mode="rb");
public:
	// Open the file
	BOOL OpenW(const WCHAR* const filename,  WCHAR *mode=L"rb");
	BOOL OpenA(const char* const filename, char *mode="rb");
private:
	// Internale FILE object 
	FILE* _file;

public:
	// Read a line from a MBCS file 
	// Return value:if end of file,return value is false,else is true
	bool _ReadLine(string& s, int eol='\n', int eof=EOF);
	// Read aline from a UNICODE file
	// Return value:if end of file,return value is false,else is true
	bool _ReadLine(wstring& s, wint_t eol=L'\n', wint_t eof=WEOF);

	// ANSI version of read line
	inline bool ReadLineA(std::string &s);
	inline bool ReadLineA(LPCSTR s);
	// Unicode version of read line
	bool ReadLineW(std::wstring &ws);
	inline bool ReadLineW(LPCWSTR ws);

public:
	// To write an ANSI zero-terminated string (please consider using STL instead)
	bool _WriteLine(const char* const s, int ret = '\r',int newline='\n', size_t length = -1);

	// To write a Unicode zero-terminated string (please consider using STL instead)
	bool _WriteLine(const wchar_t* const s, wint_t =L'\r', wint_t newline = L'\n', size_t length = -1);

	// To write an ANSI STL string
	bool _WriteLine(const std::string& s, int ret = '\r',int newline='\n')
	{
		return _WriteLine(s.c_str(), ret,newline, s.size());
	};

	// To write a Unicode STL string
	bool _WriteLine(const std::wstring& s, wint_t ret=L'\r', wint_t newline = L'\n')
	{
		return _WriteLine(s.c_str(), ret, newline, s.size());
	};
	// ANSI version of write line
	bool WriteLineA(const char* const s);
	bool WriteLineA(const std::string &s)
	{
		return WriteLineA(s.c_str());
	}
	// Unicode version of write line
	bool WriteLineW(const wchar_t* const ws);
	bool WriteLineW(const std::wstring &ws)
	{
		return WriteLineW(ws.c_str());
	};

public:
	// Text file encoding type enum
	enum EncodingType {ANSI,UTF16_LE,UTF16_BE,UTF32_LE,UTF32_BE,UTF_8};
private:
	// File encoding type
	EncodingType encodingType;
public:
	// Check file encoding type
	static EncodingType CheckFileEncodingTypeW(const WCHAR* const filename);
	static EncodingType CheckFileEncodingTypeA(const char* const filename);
public:
	// Get current open file's encoding type
	CTextFileIO::EncodingType GetEncodingType(void)
	{
		return encodingType;
	}
	// Omit file encoding tag
	int OmitEncodingTag(EncodingType type);
	// Indicate file can be read or not
	bool _IsValidate;
public:

	// Check file is validate to read
	bool IsValidate(void)
	{
		return _IsValidate;
	}

	// Write the encoding type tag an beginner of file
	void WriteEncodingTag(EncodingType type);
};

#endif
