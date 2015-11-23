

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 23 17:20:12 2015
 */
/* Compiler settings for BaiDuYunIcon.idl:
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

#ifndef __BaiDuYunIcon_i_h__
#define __BaiDuYunIcon_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMyShellFolder_FWD_DEFINED__
#define __IMyShellFolder_FWD_DEFINED__
typedef interface IMyShellFolder IMyShellFolder;

#endif 	/* __IMyShellFolder_FWD_DEFINED__ */


#ifndef __MyShellFolder_FWD_DEFINED__
#define __MyShellFolder_FWD_DEFINED__

#ifdef __cplusplus
typedef class MyShellFolder MyShellFolder;
#else
typedef struct MyShellFolder MyShellFolder;
#endif /* __cplusplus */

#endif 	/* __MyShellFolder_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMyShellFolder_INTERFACE_DEFINED__
#define __IMyShellFolder_INTERFACE_DEFINED__

/* interface IMyShellFolder */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IMyShellFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B4697F41-10D6-4E49-AA09-746C3B71B7E8")
    IMyShellFolder : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IMyShellFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyShellFolder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyShellFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyShellFolder * This);
        
        END_INTERFACE
    } IMyShellFolderVtbl;

    interface IMyShellFolder
    {
        CONST_VTBL struct IMyShellFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyShellFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyShellFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyShellFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyShellFolder_INTERFACE_DEFINED__ */



#ifndef __BaiDuYunIconLib_LIBRARY_DEFINED__
#define __BaiDuYunIconLib_LIBRARY_DEFINED__

/* library BaiDuYunIconLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_BaiDuYunIconLib;

EXTERN_C const CLSID CLSID_MyShellFolder;

#ifdef __cplusplus

class DECLSPEC_UUID("893ADB83-76E5-4362-830A-137AAD5B8804")
MyShellFolder;
#endif
#endif /* __BaiDuYunIconLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


