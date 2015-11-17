// SimpleContextMenuHandler.h : CSimpleContextMenuHandler ������

#pragma once
#include "resource.h"       // ������



#include "ContextMenuHandlerWithOneItem_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CSimpleContextMenuHandler

class ATL_NO_VTABLE CSimpleContextMenuHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleContextMenuHandler, &CLSID_SimpleContextMenuHandler>,
	public IShellExtInit,
    public IContextMenu
{
public:
    CSimpleContextMenuHandler();
    ~CSimpleContextMenuHandler();

DECLARE_REGISTRY_RESOURCEID(IDR_SIMPLECONTEXTMENUHANDLER)

DECLARE_NOT_AGGREGATABLE(CSimpleContextMenuHandler)

BEGIN_COM_MAP(CSimpleContextMenuHandler)
	COM_INTERFACE_ENTRY(IShellExtInit)
    COM_INTERFACE_ENTRY(IContextMenu)
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
    // IShellExtInit
    STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

    // IContextMenu
#ifdef _WIN64
    STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
#else
    STDMETHODIMP GetCommandString(UINT, UINT, UINT*, LPSTR, UINT);
#endif
    STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
    STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

private:
    TCHAR m_szFile[MAX_PATH];
};

OBJECT_ENTRY_AUTO(__uuidof(SimpleContextMenuHandler), CSimpleContextMenuHandler)
