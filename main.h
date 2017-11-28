#ifndef MAIN_H
#define MAIN_H
#endif

#include <ShObjIdl.h>
#include <ShlGuid.h>

HRESULT CreateShortCut(LPCWSTR pszTargetfile, LPCWSTR pszTargetargs,
	LPCWSTR pszLinkfile, LPCWSTR pszDescription,
	int iShowmode, LPCWSTR pszCurdir,
	LPCWSTR pszIconfile, int iIconindex);

	
	/*
	ARGS ARE : 
	L"",L"",NULL,NULL,SW_SHOWNORMAL,NULL,NULL,0
	*/
