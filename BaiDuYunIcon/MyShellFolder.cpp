// MyShellFolder.cpp : CMyShellFolder µÄÊµÏÖ

#include "stdafx.h"
#include "MyShellFolder.h"


// CMyShellFolder

CMyShellFolder::CMyShellFolder()
{

}

CMyShellFolder::~CMyShellFolder()
{

}

STDMETHODIMP CMyShellFolder::GetClassID(CLSID* pClsid)
{
    if (nullptr == pClsid)
        return E_POINTER;

    *pClsid = CLSID_MyShellFolder;
    return S_OK;
}

// Initialize() is passed the PIDL of the folder where our extension is.
// In our case, it's the PIDL for the desktop.
STDMETHODIMP CMyShellFolder::Initialize(LPCITEMIDLIST pidl)
{
    // No special init needed.
    return S_OK;
}

// BindToObject() is called when a folder in our part of the namespace is being
// browsed.  We create a new CShellFolderImpl, initialize it with the pidl 
// being browsed, and return that new object to the shell.
STDMETHODIMP CMyShellFolder::BindToObject(LPCITEMIDLIST pidl, LPBC pbcReserved,
    REFIID riid, void** ppvOut)
{
    return E_NOTIMPL;
}

// CompareIDs() is responsible for returning the sort order of two PIDLs.
// lParam is a pointer to a CListSortInfo set up by the caller.  Returns
// -1/0/1 like strcmp().
STDMETHODIMP CMyShellFolder::CompareIDs(LPARAM lParam,
    LPCITEMIDLIST pidl1,
    LPCITEMIDLIST pidl2)
{
    return 0;
}


// CreateViewObject() creates a new COM object that implements IShellView.
STDMETHODIMP CMyShellFolder::CreateViewObject(HWND hwndOwner,
    REFIID riid, void** ppvOut)
{
    return E_NOTIMPL;
}


// EnumObjects() creates a COM object that implements IEnumIDList.
STDMETHODIMP CMyShellFolder::EnumObjects(HWND hwndOwner, DWORD dwFlags,
    LPENUMIDLIST* ppEnumIDList)
{
    if (nullptr == ppEnumIDList)
        return E_POINTER;

    *ppEnumIDList = nullptr;
    return S_OK;
}

// GetAttributesOf() returns the attributes for the items whose PIDLs are
// passed in.
STDMETHODIMP CMyShellFolder::GetAttributesOf(UINT uCount, LPCITEMIDLIST aPidls[],
    LPDWORD pdwAttribs)
{
    // Our items are all just plain ol' items, so the attributes are always
    // 0.  Normally, the attributes returned come from the SFGAO_* constants.

    *pdwAttribs = 0;
    return S_OK;
}


// GetUIObjectOf() returns an interface used to handle events in Explorer's
// tree control.
STDMETHODIMP CMyShellFolder::GetUIObjectOf(HWND hwndOwner, UINT uCount,
    LPCITEMIDLIST* pPidl, REFIID riid,
    LPUINT puReserved, void** ppvReturn)
{
    *ppvReturn = NULL;

    // No additional interfaces supported.  Goodbye!

    return E_NOINTERFACE;
}
