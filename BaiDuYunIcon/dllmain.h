// dllmain.h : 模块类的声明。

class CBaiDuYunIconModule : public ATL::CAtlDllModuleT< CBaiDuYunIconModule >
{
public :
	DECLARE_LIBID(LIBID_BaiDuYunIconLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_BAIDUYUNICON, "{4A2301A7-5E46-4A15-83D4-3408DF74DEA4}")
};

extern class CBaiDuYunIconModule _AtlModule;
