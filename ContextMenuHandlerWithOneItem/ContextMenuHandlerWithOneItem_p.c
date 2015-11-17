

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Nov 17 16:28:23 2015
 */
/* Compiler settings for ContextMenuHandlerWithOneItem.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "ContextMenuHandlerWithOneItem_i.h"

#define TYPE_FORMAT_STRING_SIZE   3                                 
#define PROC_FORMAT_STRING_SIZE   1                                 
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _ContextMenuHandlerWithOneItem_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } ContextMenuHandlerWithOneItem_MIDL_TYPE_FORMAT_STRING;

typedef struct _ContextMenuHandlerWithOneItem_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } ContextMenuHandlerWithOneItem_MIDL_PROC_FORMAT_STRING;

typedef struct _ContextMenuHandlerWithOneItem_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } ContextMenuHandlerWithOneItem_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const ContextMenuHandlerWithOneItem_MIDL_TYPE_FORMAT_STRING ContextMenuHandlerWithOneItem__MIDL_TypeFormatString;
extern const ContextMenuHandlerWithOneItem_MIDL_PROC_FORMAT_STRING ContextMenuHandlerWithOneItem__MIDL_ProcFormatString;
extern const ContextMenuHandlerWithOneItem_MIDL_EXPR_FORMAT_STRING ContextMenuHandlerWithOneItem__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISimpleContextMenuHandler_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISimpleContextMenuHandler_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const ContextMenuHandlerWithOneItem_MIDL_PROC_FORMAT_STRING ContextMenuHandlerWithOneItem__MIDL_ProcFormatString =
    {
        0,
        {

			0x0
        }
    };

static const ContextMenuHandlerWithOneItem_MIDL_TYPE_FORMAT_STRING ContextMenuHandlerWithOneItem__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISimpleContextMenuHandler, ver. 0.0,
   GUID={0xA57766BD,0x9674,0x4509,{0x9A,0xE5,0xFD,0x36,0xCE,0xBB,0x5A,0xAA}} */

#pragma code_seg(".orpc")
static const unsigned short ISimpleContextMenuHandler_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ISimpleContextMenuHandler_ProxyInfo =
    {
    &Object_StubDesc,
    ContextMenuHandlerWithOneItem__MIDL_ProcFormatString.Format,
    &ISimpleContextMenuHandler_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISimpleContextMenuHandler_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    ContextMenuHandlerWithOneItem__MIDL_ProcFormatString.Format,
    &ISimpleContextMenuHandler_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(3) _ISimpleContextMenuHandlerProxyVtbl = 
{
    0,
    &IID_ISimpleContextMenuHandler,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy
};

const CInterfaceStubVtbl _ISimpleContextMenuHandlerStubVtbl =
{
    &IID_ISimpleContextMenuHandler,
    &ISimpleContextMenuHandler_ServerInfo,
    3,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    ContextMenuHandlerWithOneItem__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _ContextMenuHandlerWithOneItem_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISimpleContextMenuHandlerProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _ContextMenuHandlerWithOneItem_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISimpleContextMenuHandlerStubVtbl,
    0
};

PCInterfaceName const _ContextMenuHandlerWithOneItem_InterfaceNamesList[] = 
{
    "ISimpleContextMenuHandler",
    0
};


#define _ContextMenuHandlerWithOneItem_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ContextMenuHandlerWithOneItem, pIID, n)

int __stdcall _ContextMenuHandlerWithOneItem_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_ContextMenuHandlerWithOneItem_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo ContextMenuHandlerWithOneItem_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ContextMenuHandlerWithOneItem_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ContextMenuHandlerWithOneItem_StubVtblList,
    (const PCInterfaceName * ) & _ContextMenuHandlerWithOneItem_InterfaceNamesList,
    0, /* no delegation */
    & _ContextMenuHandlerWithOneItem_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

