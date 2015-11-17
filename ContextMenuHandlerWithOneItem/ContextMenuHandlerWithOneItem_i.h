

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ContextMenuHandlerWithOneItem_i_h__
#define __ContextMenuHandlerWithOneItem_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISimpleContextMenuHandler_FWD_DEFINED__
#define __ISimpleContextMenuHandler_FWD_DEFINED__
typedef interface ISimpleContextMenuHandler ISimpleContextMenuHandler;

#endif 	/* __ISimpleContextMenuHandler_FWD_DEFINED__ */


#ifndef __SimpleContextMenuHandler_FWD_DEFINED__
#define __SimpleContextMenuHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class SimpleContextMenuHandler SimpleContextMenuHandler;
#else
typedef struct SimpleContextMenuHandler SimpleContextMenuHandler;
#endif /* __cplusplus */

#endif 	/* __SimpleContextMenuHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISimpleContextMenuHandler_INTERFACE_DEFINED__
#define __ISimpleContextMenuHandler_INTERFACE_DEFINED__

/* interface ISimpleContextMenuHandler */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ISimpleContextMenuHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A57766BD-9674-4509-9AE5-FD36CEBB5AAA")
    ISimpleContextMenuHandler : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ISimpleContextMenuHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISimpleContextMenuHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISimpleContextMenuHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISimpleContextMenuHandler * This);
        
        END_INTERFACE
    } ISimpleContextMenuHandlerVtbl;

    interface ISimpleContextMenuHandler
    {
        CONST_VTBL struct ISimpleContextMenuHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleContextMenuHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISimpleContextMenuHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISimpleContextMenuHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISimpleContextMenuHandler_INTERFACE_DEFINED__ */



#ifndef __ContextMenuHandlerWithOneItemLib_LIBRARY_DEFINED__
#define __ContextMenuHandlerWithOneItemLib_LIBRARY_DEFINED__

/* library ContextMenuHandlerWithOneItemLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ContextMenuHandlerWithOneItemLib;

EXTERN_C const CLSID CLSID_SimpleContextMenuHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("8A63CE35-B0E1-4621-9BC1-487FA9398D31")
SimpleContextMenuHandler;
#endif
#endif /* __ContextMenuHandlerWithOneItemLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


