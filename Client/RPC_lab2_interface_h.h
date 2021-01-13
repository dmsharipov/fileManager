

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for RPC_lab2_interface.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __RPC_lab2_interface_h_h__
#define __RPC_lab2_interface_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __RPC_lab2_interface_INTERFACE_DEFINED__
#define __RPC_lab2_interface_INTERFACE_DEFINED__

/* interface RPC_lab2_interface */
/* [implicit_handle][version][uuid] */ 

#define	IO_BUF_SIZE	( 1024 )

int RPC_login( 
    /* [in] */ handle_t IdHandle,
    /* [string][in] */ unsigned char *username,
    /* [string][in] */ unsigned char *password);

void RPC_logout( void);

int RPC_download( 
    /* [string][in] */ const unsigned char *pathToFile,
    /* [size_is][out][in] */ unsigned char *data,
    /* [out][in] */ unsigned int *sizePayload,
    /* [out][in] */ unsigned int *fileFullSize);

int RPC_upload( 
    /* [string][in] */ const unsigned char *pathToFile,
    /* [in] */ int sizePayload,
    /* [size_is][in] */ unsigned char *data,
    /* [in] */ unsigned int fileFullSize);

int RPC_delete( 
    /* [string][in] */ const unsigned char *pathToFile);

void RPC_exit( void);


extern handle_t interface_handle;


extern RPC_IF_HANDLE RPC_lab2_interface_v1_0_c_ifspec;
extern RPC_IF_HANDLE RPC_lab2_interface_v1_0_s_ifspec;
#endif /* __RPC_lab2_interface_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


