// dllmain.h : 模块类的声明。

class CContextMenuHandlerWithOneItemModule : public ATL::CAtlDllModuleT< CContextMenuHandlerWithOneItemModule >
{
public :
	DECLARE_LIBID(LIBID_ContextMenuHandlerWithOneItemLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CONTEXTMENUHANDLERWITHONEITEM, "{05559871-738D-4AC6-ACB1-1F37496E48A3}")
};

extern class CContextMenuHandlerWithOneItemModule _AtlModule;
