#include "main.h"


/*
------------------------------------------------------------------ -
Description:
Creates the actual 'lnk' file(assumes COM has been initialized).

Parameters :
		   pszTargetfile - File name of the link's target.
		   pszTargetargs - Command line arguments passed to link's target.
		   pszLinkfile - File name of the actual link file being created.
		   pszDescription - Description of the linked item.
		   iShowmode - ShowWindow() constant for the link's target.
		   pszCurdir - Working directory of the active link.
		   pszIconfile - File name of the icon file used for the link.
		   iIconindex - Index of the icon in the icon file.

	   Returns:
HRESULT value >= 0 for success, < 0 for failure.
	--------------------------------------------------------------------
*/
HRESULT CreateShortCut(LPCWSTR pszTargetfile, LPCWSTR pszTargetargs,
	LPCWSTR pszLinkfile, LPCWSTR pszDescription,
	int iShowmode, LPCWSTR pszCurdir,
	LPCWSTR pszIconfile, int iIconindex)
{
	HRESULT       hRes;                  /* Returned COM result code */
	IShellLink*   pShellLink;            /* IShellLink object pointer */
	IPersistFile* pPersistFile;          /* IPersistFile object pointer */
	int           iWideCharsWritten;     /* Number of wide characters written */

	CoInitialize(NULL);

	hRes = E_INVALIDARG;
	if ((pszTargetfile != NULL) && (strlen(pszTargetfile) > 0))
	{
		hRes = CoCreateInstance(
			&CLSID_ShellLink,     /* pre-defined CLSID of the IShellLink object */
			NULL,                /* pointer to parent interface if part of aggregate */
			CLSCTX_INPROC_SERVER, /* caller and called code are in same process */
			&IID_IShellLink,      /* pre-defined interface of theIShellLink object */
			&pShellLink);         /* Returns a pointer to the IShellLink object */

		if (SUCCEEDED(hRes))
		{
			/* Set the fields in the IShellLink object */
			hRes = pShellLink->lpVtbl->SetPath(pShellLink,pszTargetfile);
			hRes = pShellLink->lpVtbl->SetArguments(pShellLink,pszTargetargs);
			if (pszDescription !=NULL && strlen(pszDescription) > 0)
			{
				hRes = pShellLink->lpVtbl->SetDescription(pShellLink,pszDescription);
			}
			if (iShowmode > 0)
			{
				hRes = pShellLink->lpVtbl->SetShowCmd(pShellLink,iShowmode);
			}
			if (pszCurdir != NULL && strlen(pszCurdir) > 0)
			{
				hRes = pShellLink->lpVtbl->SetWorkingDirectory(pShellLink,pszCurdir);
			}
			if (pszIconfile != NULL && strlen(pszIconfile) > 0 && iIconindex >= 0)
			{
				hRes = pShellLink->lpVtbl->SetIconLocation(pShellLink,pszIconfile, iIconindex);
			}

			/* Use the IPersistFile object to save the shell link */
			hRes = pShellLink->lpVtbl->QueryInterface(
				pShellLink,                /* existing IShellLink object */
				&IID_IPersistFile,         /* pre-defined interface of the IPersistFile object */
				&pPersistFile);            /* returns a pointer to the IPersistFile object */

			if (SUCCEEDED(hRes))
			{
				/* We save the IPersistFile object to a file (the Path given in argument, in LPCWSTR) */
				hRes = pPersistFile->lpVtbl->Save(pPersistFile, pszLinkfile, TRUE);
				pPersistFile->lpVtbl->Release(pPersistFile);
			}
			pShellLink->lpVtbl->Release(pShellLink);
		}
	}
	return (hRes);
}



/*
Example in a main :

*/

int main(int argc, char** argv)
{

	HRESULT shortcuttest = CreateShortCut(L"cmd.exe",L"/c ping 8.8.8.8", L"C:\\Users\\MyLab\\Desktop\\test.lnk",NULL, SW_SHOWNORMAL,NULL,NULL,0);:w

	return 0;
}
