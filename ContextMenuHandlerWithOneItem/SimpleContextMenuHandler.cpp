// SimpleContextMenuHandler.cpp : CSimpleContextMenuHandler µÄÊµÏÖ

#include "stdafx.h"
#include "SimpleContextMenuHandler.h"


// CSimpleContextMenuHandler
CSimpleContextMenuHandler::CSimpleContextMenuHandler()
{
    ZeroMemory(m_szFile, sizeof(TCHAR) * MAX_PATH);
}

CSimpleContextMenuHandler::~CSimpleContextMenuHandler()
{

}

STDMETHODIMP CSimpleContextMenuHandler::Initialize(
    LPCITEMIDLIST pidlFolder,
    LPDATAOBJECT pDataObj,
    HKEY hProgID)
{
    FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
    STGMEDIUM stg = { TYMED_HGLOBAL };

    if (FAILED(pDataObj->GetData(&fmt, &stg)))
        return E_INVALIDARG;

    HDROP hDrop = reinterpret_cast<HDROP>(GlobalLock(stg.hGlobal));
    if (hDrop == nullptr)
        return E_INVALIDARG;

    UINT uNumFiles = DragQueryFile(hDrop, 0xFFFFFFFF, nullptr, 0);
    if (uNumFiles == 0)
    {
        GlobalUnlock(stg.hGlobal);
        ReleaseStgMedium(&stg);
        return E_INVALIDARG;
    }

    HRESULT hr = S_OK;
    if (DragQueryFile(hDrop, 0, m_szFile, MAX_PATH) == 0)
        hr = E_INVALIDARG;

    GlobalUnlock(stg.hGlobal);
    ReleaseStgMedium(&stg);

    ATLTRACE(_T("CSimpleContextMenuHandler::Initialize: file is \"%s\""), m_szFile);
    return hr;
}

HRESULT CSimpleContextMenuHandler::QueryContextMenu(
    HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,
    UINT uidLastCmd, UINT uFlags)
{
    if (uFlags & CMF_DEFAULTONLY)
        return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0);

    InsertMenu(hmenu, uMenuIndex, MF_BYPOSITION,
        uidFirstCmd, _T("Open With Notepad++"));

    return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 1);
}

#ifdef _WIN64
HRESULT CSimpleContextMenuHandler::GetCommandString(
    UINT_PTR idCmd, UINT uFlags, UINT* pwReserved,
    LPSTR pszName, UINT cchMax)
#else
HRESULT CSimpleContextMenuHandler::GetCommandString(
    UINT idCmd, UINT uFlags, UINT* pwReserved,
    LPSTR pszName, UINT cchMax)
#endif
{
    USES_CONVERSION;

    // Check idCmd, it must be 0 since we have only one menu item.
    if (0 != idCmd)
        return E_INVALIDARG;

    // If Explorer is asking for a help string, copy our string into the
    // supplied buffer.
    if (uFlags & GCS_HELPTEXT)
    {
        LPCTSTR szText = _T("This is the simple shell extension's help");

        if (uFlags & GCS_UNICODE)
        {
            // We need to cast pszName to a Unicode string, and then use the
            // Unicode string copy API.
            lstrcpynW((LPWSTR)pszName, T2CW(szText), cchMax);
        }
        else
        {
            // Use the ANSI string copy API to return the help string.
            lstrcpynA(pszName, T2CA(szText), cchMax);
        }

        return S_OK;
    }

    return E_INVALIDARG;
}

HRESULT CSimpleContextMenuHandler::InvokeCommand(
    LPCMINVOKECOMMANDINFO pCmdInfo)
{
    // If lpVerb really points to a string, ignore this function call and bail out.
    if (0 != HIWORD(pCmdInfo->lpVerb))
        return E_INVALIDARG;

    // Get the command index - the only valid one is 0.
    switch (LOWORD(pCmdInfo->lpVerb))
    {
    case 0:
    {
        TCHAR *szCmd = _T("C:\\Program Files (x86)\\Notepad++\\notepad++.exe");
        ShellExecute(pCmdInfo->hwnd, _T("open"), szCmd, m_szFile, nullptr, SW_SHOW);
        return S_OK;
    }
    break;

    default:
        return E_INVALIDARG;
        break;
    }
}