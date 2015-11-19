// CallIContextMenu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
#include <shlobj.h>
#include <comdef.h>
#include <atlconv.h>

int _tmain(int argc, _TCHAR* argv[])
{
    CoInitialize(nullptr);

	HRESULT hr = E_FAIL;

	CComPtr<IShellFolder> spDesktopFolder;
	hr = SHGetDesktopFolder(&spDesktopFolder);
	if (FAILED(hr))
		return 1;

	LPITEMIDLIST pidlFolder = nullptr;
	hr = spDesktopFolder->ParseDisplayName(nullptr, nullptr, L"C:\\Program Files (x86)\\KuGou\\KGMusic", nullptr, &pidlFolder, nullptr);
	if (FAILED(hr))
		return 2;

	CComPtr<IShellFolder> spShellFolder;
	hr = spDesktopFolder->BindToObject(pidlFolder, nullptr, IID_IShellFolder, reinterpret_cast<LPVOID*>(&spShellFolder));
	if (FAILED(hr))
		return 3;

	LPITEMIDLIST pidlFile = nullptr;
	hr = spShellFolder->ParseDisplayName(nullptr, nullptr, L"KuGou.exe", nullptr, &pidlFile, nullptr);
	if (FAILED(hr))
		return 4;

	{
		CComPtr<IContextMenu> spContextMenu;
		hr = spShellFolder->GetUIObjectOf(nullptr, 1, const_cast<LPCITEMIDLIST*>(&pidlFile), IID_IContextMenu, nullptr, reinterpret_cast<LPVOID*>(&spContextMenu));
		if (FAILED(hr))
			return 5;

		HMENU hMenu = CreatePopupMenu();
		if (hMenu != nullptr)
		{
			hr = spContextMenu->QueryContextMenu(hMenu, 0, 1, 0x7FFF, CMF_VERBSONLY);
			if (SUCCEEDED(hr))
			{		
				CMINVOKECOMMANDINFO info = { 0 };
				info.cbSize = sizeof(info);
				info.lpVerb = "taskbarpin";
				spContextMenu->InvokeCommand(&info);
			}

			DestroyMenu(hMenu);
		}
	}

    CoUninitialize();
	return 0;
}

//
//
//HRESULT GetContextMenuForFSItem(PCTSTR path, IContextMenu**ppCM)
//{
//    PIDLIST_ABSOLUTE pidlAbs;
//    HRESULT hr = SHParseDisplayName(path, 0, &pidlAbs, 0, 0);
//    if (!hr)
//    {
//        IShellFolder*pSF;
//        PCUITEMID_CHILD pidlLast;
//        hr = SHBindToParent(pidlAbs, IID_IShellFolder, (void**)&pSF, &pidlLast);
//        if (!hr)
//        {
//            hr = pSF->GetUIObjectOf(0, 1, &pidlLast, IID_IContextMenu, 0, (void**)ppCM);
//            pSF->Release();
//        }
//        ILFree(pidlAbs);
//    }
//    return hr;
//}
//
//int main()
//{
//    CoInitialize(0);
//    WCHAR buf[MAX_PATH];
//    GetWindowsDirectory(buf, MAX_PATH); /* Arbitrary filesystem item */
//    IContextMenu*pCM;
//    HRESULT hr = GetContextMenuForFSItem(L"C:\\Program Files (x86)\\KuGou\\KGMusic\\KuGou.exe", &pCM);
//    if (!hr)
//    {
//        HMENU hMenu = CreatePopupMenu();
//        hr = pCM->QueryContextMenu(hMenu, 0, 1, 0x7fff, 0);
//        if (hr > 0)
//        {
//            UINT c = GetMenuItemCount(hMenu), i = 0;
//            for (; i<c; ++i)
//            {
//                GetMenuString(hMenu, i, buf, MAX_PATH, MF_BYPOSITION);
//                if (GetMenuState(hMenu, i, MF_BYPOSITION)&MF_SEPARATOR) lstrcpy(buf, _T("--separator--"));
//                printf("%.2u=%ws\n", i, buf);
//                /*
//                Call IContextMenu::GetCommandString  to get the verb
//                or IContextMenu::InvokeCommand to execute
//                */
//            }
//        }
//        pCM->Release();
//        DestroyMenu(hMenu);
//    }
//    CoUninitialize();
//    return 0;
//}
//
//
//#include <shlobj.h>
//
//HRESULT GetUIObjectOfFile(HWND hwnd, LPCWSTR pszPath, REFIID riid, void **ppv)
//{
//    *ppv = NULL;
//    HRESULT hr;
//    LPITEMIDLIST pidl;
//    SFGAOF sfgao;
//    if (SUCCEEDED(hr = SHParseDisplayName(pszPath, NULL, &pidl, 0, &sfgao))) {
//        IShellFolder *psf;
//        LPCITEMIDLIST pidlChild;
//        if (SUCCEEDED(hr = SHBindToParent(pidl, IID_IShellFolder,
//            (void**)&psf, &pidlChild))) {
//            hr = psf->GetUIObjectOf(hwnd, 1, &pidlChild, riid, NULL, ppv);
//            psf->Release();
//        }
//        CoTaskMemFree(pidl);
//    }
//    return hr;
//}
//
//#define SCRATCH_QCM_FIRST 1
//#define SCRATCH_QCM_LAST  0x7FFF
//
//void OnContextMenu(HWND hwnd, HWND hwndContext, UINT xPos, UINT yPos)
//{
//  //  IContextMenu *pContextMenu;
//  //  if (SUCCEEDED(GetUIObjectOfFile(hwnd, L"C:\\Program Files(x86)\\KuGou\\KGMusic\\KuGou.exe",
//   //     IID_IContextMenu, (void**)&pcm))) 
//    
//   // {
//        IShellFolder *pShellFolder = nullptr;
//            SHGetDesktopFolder(&pShellFolder);
//        
//            LPITEMIDLIST pidlTarget;
//            pShellFolder->ParseDisplayName(NULL, NULL, (LPWSTR)L"C:\\Program Files (x86)\\KuGou\\KGMusic", NULL, &pidlTarget, NULL);
//        
//            IShellFolder *pShellTarget = nullptr;
//            LPITEMIDLIST pidl = nullptr;
//            auto i = pShellFolder->BindToObject(pidlTarget, NULL, IID_IShellFolder, (LPVOID*)(&pShellTarget));
//           // SHBindToParent(pidlTarget, IID_IShellFolder, (LPVOID*)(&pShellTarget), const_cast<LPCITEMIDLIST*>(&pidl));
//
//            pShellTarget->ParseDisplayName(nullptr, nullptr, L"KuGou.exe", nullptr, &pidl, nullptr);
//
//            DWORD dwCode = GetLastError();
//            IContextMenu *pContextMenu = nullptr;
//            pShellTarget->GetUIObjectOf(nullptr, 1, const_cast<LPCITEMIDLIST*>(&pidl), IID_IContextMenu, nullptr, reinterpret_cast<LPVOID*>(&pContextMenu));
//            //pShellFolder->GetUIObjectOf(nullptr, 1, const_cast<LPCITEMIDLIST*>(&pidlTarget), IID_IContextMenu, nullptr, reinterpret_cast<LPVOID*>(&pContextMenu));
//        
//            //     CMINVOKECOMMANDINFO cmd = { 0 };
//            //     cmd.cbSize = sizeof(CMINVOKECOMMANDINFO);
//            //     cmd.lpVerb = reinterpret_cast<LPCSTR>("properties");
//            //     cmd.nShow = SW_SHOW;
//            //     cmd.hwnd = reinterpret_cast<HWND>(2363078);
//            //
//            //     pContextMenu->InvokeCommand(&cmd);
//
//            HMENU hmenu = CreatePopupMenu();
//            if (hmenu) {
//                if (SUCCEEDED(pContextMenu->QueryContextMenu(hmenu, 0,
//                    SCRATCH_QCM_FIRST, SCRATCH_QCM_LAST,
//                    0x00000002))) {
//
//                    for (int i = 0; i < 50; i++)
//                    {
//                        char szText[MAX_PATH] = { 0 };
//                        pContextMenu->GetCommandString(i, GCS_HELPTEXTA, nullptr, szText, MAX_PATH);
//                        printf("%d: %s\n", i, szText);
//                    }
//                    CMINVOKECOMMANDINFO info = { 0 };
//                    info.cbSize = sizeof(info);
//                    info.hwnd = hwnd;
//					info.lpVerb = "taskbarpin";// reinterpret_cast<LPCSTR>(2);
//                    pContextMenu->InvokeCommand(&info);
//                }
//                DestroyMenu(hmenu);
//            }
//       // pContextMenu->Release();
//  //  }
//}
//
//int main()
//{
//    CoInitialize(nullptr);
//    OnContextMenu(reinterpret_cast<HWND>(2363078), 0, 0, 0);
//    CoUninitialize();
//    return 0;
//}