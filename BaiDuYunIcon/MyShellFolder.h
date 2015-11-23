// MyShellFolder.h : CMyShellFolder 的声明

#pragma once
#include "resource.h"       // 主符号
#include "BaiDuYunIcon_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CMyShellFolder
class ATL_NO_VTABLE CMyShellFolder :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMyShellFolder, &CLSID_MyShellFolder>,
    public IShellFolder,
    public IPersistFolder
{
public:
    CMyShellFolder();
    ~CMyShellFolder();

DECLARE_REGISTRY_RESOURCEID(IDR_MYSHELLFOLDER)

DECLARE_NOT_AGGREGATABLE(CMyShellFolder)

BEGIN_COM_MAP(CMyShellFolder)
    COM_INTERFACE_ENTRY(IShellFolder)
    COM_INTERFACE_ENTRY(IPersistFolder)
    COM_INTERFACE_ENTRY(IPersist)
END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
    // IPersist
    STDMETHOD(GetClassID)(CLSID*);

    // IPersistFolder
    STDMETHOD(Initialize)(LPCITEMIDLIST);

    // IShellFolder
    STDMETHOD(BindToObject)(LPCITEMIDLIST, LPBC, REFIID, void**);
    STDMETHOD(CompareIDs)(LPARAM, LPCITEMIDLIST, LPCITEMIDLIST);
    STDMETHOD(CreateViewObject)(HWND, REFIID, void**);
    STDMETHOD(EnumObjects)(HWND, DWORD, LPENUMIDLIST*);
    STDMETHOD(GetAttributesOf)(UINT, LPCITEMIDLIST*, LPDWORD);
    STDMETHOD(GetUIObjectOf)(HWND, UINT, LPCITEMIDLIST*, REFIID, LPUINT, void**);

    STDMETHOD(BindToStorage)(LPCITEMIDLIST, LPBC, REFIID, void**)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(GetDisplayNameOf)(LPCITEMIDLIST, DWORD, LPSTRRET)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(ParseDisplayName)(HWND, LPBC, LPOLESTR, LPDWORD, LPITEMIDLIST*, LPDWORD)
    {
        return E_NOTIMPL;
    }
    STDMETHOD(SetNameOf)(HWND, LPCITEMIDLIST, LPCOLESTR, DWORD, LPITEMIDLIST*)
    {
        return E_NOTIMPL;
    }

private:
};

OBJECT_ENTRY_AUTO(__uuidof(MyShellFolder), CMyShellFolder)
