// ContextMenuHandlerWithOneItem.cpp : DLL 导出的实现。


#include "stdafx.h"
#include "resource.h"
#include "ContextMenuHandlerWithOneItem_i.h"
#include "dllmain.h"


using namespace ATL;

// 用于确定 DLL 是否可由 OLE 卸载。
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}

// 返回一个类工厂以创建所请求类型的对象。
STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}

// DllRegisterServer - 在系统注册表中添加项。
STDAPI DllRegisterServer(void)
{
    return _AtlModule.DllRegisterServer(FALSE);
}

// DllUnregisterServer - 在系统注册表中移除项。
STDAPI DllUnregisterServer(void)
{
    return _AtlModule.DllUnregisterServer(FALSE);
}

// DllInstall - 按用户和计算机在系统注册表中逐一添加/移除项。
STDAPI DllInstall(BOOL bInstall, _In_opt_  LPCWSTR pszCmdLine)
{
    HRESULT hr = E_FAIL;
    static const wchar_t szUserSwitch[] = L"user";

    if (pszCmdLine != NULL)
    {
        if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
        {
            ATL::AtlSetPerUserRegistration(true);
        }
    }

    if (bInstall)
    {
        hr = DllRegisterServer();
        if (FAILED(hr))
        {
            DllUnregisterServer();
        }
    }
    else
    {
        hr = DllUnregisterServer();
    }

    return hr;
}


