// MSVSSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MSVSSample.h"

#include <SQLAPI.h>
#include <iostream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

void Sample1(SAConnection& con, const char *szQuery)
{
	SACommand cmd(&con);
	cmd.setCommandText(szQuery);
	cmd.Execute();

	while(cmd.FetchNext())
		cout << cmd[1].asString().GetMultiByteChars() << endl;
}

void Sample2(SAConnection& con, const wchar_t *lpszQuery)
{
	SACommand cmd(&con);
	cmd.setCommandText(lpszQuery);
	cmd.Execute();

	while(cmd.FetchNext())
		cout << cmd[1].asString().GetMultiByteChars() << endl;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
	}

		
	SAConnection con;
	
	try
	{
		con.Connect(_TSA("mysql"), _TSA("root"), _TSA(""), SA_MySQL_Client);
		
		Sample1(con, "select user()");			
		
		Sample2(con, L"select user()");
		
		con.Disconnect();
	}
	catch(SAException& x)
	{
		cerr << x.ErrText().GetMultiByteChars() << endl;
	}

	// ***************************
	// SAString conversion samples
	// ***************************
	SAString sTest(_TSA("Samle string 1"));

	const char* szString = sTest.GetMultiByteChars();
	const wchar_t* wszString = sTest.GetWideChars();

	// std::[w]string
	string stdString = "Samle string 2";
	wstring wstdString = L"Samle string 2";

	sTest = stdString.c_str();
	sTest = wstdString.c_str();

	stdString = sTest.GetMultiByteChars();
	wstdString = sTest.GetWideChars();

	// MFC CString
	CString sMFCString(_T("Sample string 3"));
	
	sTest = (LPCTSTR)sMFCString;

	sMFCString = (const SAChar*)sTest;

    CString sCmd = _T("INSERT INTO IEX_VPC_LABEL (LABEL_ID, LABEL_SEQ_NO, LABEL_NAME, IS_SYSTEM) VALUES (:1, :2, :3, :4) ");

    SACommand cmd;
    cmd.setCommandText((LPCTSTR)sCmd);



    // escape quote

    CString sName = _TSA("...");
    sName.Replace(_T("'"), _T("''"));



    cmd << _TSA("ccc")
        << (long)11
        << sName
        << true;

    cmd.Execute();

	return nRetCode;
}


