

/* this ALWAYS GENERATED file contains the RPC client stubs */


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

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "RPC_lab2_interface_h.h"

#define TYPE_FORMAT_STRING_SIZE   43                                
#define PROC_FORMAT_STRING_SIZE   239                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _RPC_lab2_interface_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } RPC_lab2_interface_MIDL_TYPE_FORMAT_STRING;

typedef struct _RPC_lab2_interface_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } RPC_lab2_interface_MIDL_PROC_FORMAT_STRING;

typedef struct _RPC_lab2_interface_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } RPC_lab2_interface_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const RPC_lab2_interface_MIDL_TYPE_FORMAT_STRING RPC_lab2_interface__MIDL_TypeFormatString;
extern const RPC_lab2_interface_MIDL_PROC_FORMAT_STRING RPC_lab2_interface__MIDL_ProcFormatString;
extern const RPC_lab2_interface_MIDL_EXPR_FORMAT_STRING RPC_lab2_interface__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: RPC_lab2_interface, ver. 1.0,
   GUID={0x64fd4134,0x1300,0x11eb,{0xad,0xc1,0x02,0x42,0xac,0x12,0x00,0x02}} */

handle_t interface_handle;


static const RPC_CLIENT_INTERFACE RPC_lab2_interface___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x64fd4134,0x1300,0x11eb,{0xad,0xc1,0x02,0x42,0xac,0x12,0x00,0x02}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE RPC_lab2_interface_v1_0_c_ifspec = (RPC_IF_HANDLE)& RPC_lab2_interface___RpcClientInterface;

extern const MIDL_STUB_DESC RPC_lab2_interface_StubDesc;

static RPC_BINDING_HANDLE RPC_lab2_interface__MIDL_AutoBindHandle;


int RPC_login( 
    /* [in] */ handle_t IdHandle,
    /* [string][in] */ unsigned char *username,
    /* [string][in] */ unsigned char *password)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RPC_lab2_interface_StubDesc,
                  (PFORMAT_STRING) &RPC_lab2_interface__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&IdHandle);
    return ( int  )_RetVal.Simple;
    
}


void RPC_logout( void)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RPC_lab2_interface_StubDesc,
                  (PFORMAT_STRING) &RPC_lab2_interface__MIDL_ProcFormatString.Format[46],
                  ( unsigned char * )0);
    
}


int RPC_download( 
    /* [string][in] */ const unsigned char *pathToFile,
    /* [size_is][out][in] */ unsigned char *data,
    /* [out][in] */ unsigned int *sizePayload,
    /* [out][in] */ unsigned int *fileFullSize)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RPC_lab2_interface_StubDesc,
                  (PFORMAT_STRING) &RPC_lab2_interface__MIDL_ProcFormatString.Format[70],
                  ( unsigned char * )&pathToFile);
    return ( int  )_RetVal.Simple;
    
}


int RPC_upload( 
    /* [string][in] */ const unsigned char *pathToFile,
    /* [in] */ int sizePayload,
    /* [size_is][in] */ unsigned char *data,
    /* [in] */ unsigned int fileFullSize)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RPC_lab2_interface_StubDesc,
                  (PFORMAT_STRING) &RPC_lab2_interface__MIDL_ProcFormatString.Format[124],
                  ( unsigned char * )&pathToFile);
    return ( int  )_RetVal.Simple;
    
}


int RPC_delete( 
    /* [string][in] */ const unsigned char *pathToFile)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RPC_lab2_interface_StubDesc,
                  (PFORMAT_STRING) &RPC_lab2_interface__MIDL_ProcFormatString.Format[178],
                  ( unsigned char * )&pathToFile);
    return ( int  )_RetVal.Simple;
    
}


void RPC_exit( void)
{

    NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&RPC_lab2_interface_StubDesc,
                  (PFORMAT_STRING) &RPC_lab2_interface__MIDL_ProcFormatString.Format[214],
                  ( unsigned char * )0);
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const RPC_lab2_interface_MIDL_PROC_FORMAT_STRING RPC_lab2_interface__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RPC_login */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	NdrFcShort( 0x8 ),	/* 8 */
/* 18 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 20 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter username */

/* 28 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 30 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 32 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter password */

/* 34 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 36 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 38 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 40 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 42 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 44 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RPC_logout */

/* 46 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 48 */	NdrFcLong( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0x1 ),	/* 1 */
/* 54 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 62 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Procedure RPC_download */

/* 70 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 72 */	NdrFcLong( 0x0 ),	/* 0 */
/* 76 */	NdrFcShort( 0x2 ),	/* 2 */
/* 78 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 80 */	NdrFcShort( 0x38 ),	/* 56 */
/* 82 */	NdrFcShort( 0x40 ),	/* 64 */
/* 84 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 86 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 88 */	NdrFcShort( 0x1 ),	/* 1 */
/* 90 */	NdrFcShort( 0x1 ),	/* 1 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pathToFile */

/* 94 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 96 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 98 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter data */

/* 100 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 104 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter sizePayload */

/* 106 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter fileFullSize */

/* 112 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
/* 114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 120 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RPC_upload */

/* 124 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x3 ),	/* 3 */
/* 132 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 134 */	NdrFcShort( 0x10 ),	/* 16 */
/* 136 */	NdrFcShort( 0x8 ),	/* 8 */
/* 138 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 140 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x1 ),	/* 1 */
/* 146 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pathToFile */

/* 148 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 150 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 152 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Parameter sizePayload */

/* 154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 158 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter data */

/* 160 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 164 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Parameter fileFullSize */

/* 166 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 168 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 172 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 174 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 176 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RPC_delete */

/* 178 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 180 */	NdrFcLong( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x4 ),	/* 4 */
/* 186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 194 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pathToFile */

/* 202 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 204 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 206 */	NdrFcShort( 0x4 ),	/* Type Offset=4 */

	/* Return value */

/* 208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RPC_exit */

/* 214 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x5 ),	/* 5 */
/* 222 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 230 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const RPC_lab2_interface_MIDL_TYPE_FORMAT_STRING RPC_lab2_interface__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/*  4 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x0,	/* FC_RP */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x1 ),	/* 1 */
/* 14 */	0x40,		/* Corr desc:  constant, val=1024 */
			0x0,		/* 0 */
/* 16 */	NdrFcShort( 0x400 ),	/* 1024 */
/* 18 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 20 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 22 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 24 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 26 */	
			0x11, 0x0,	/* FC_RP */
/* 28 */	NdrFcShort( 0x2 ),	/* Offset= 2 (30) */
/* 30 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 32 */	NdrFcShort( 0x1 ),	/* 1 */
/* 34 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 36 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 38 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 40 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short RPC_lab2_interface_FormatStringOffsetTable[] =
    {
    0,
    46,
    70,
    124,
    178,
    214
    };


static const MIDL_STUB_DESC RPC_lab2_interface_StubDesc = 
    {
    (void *)& RPC_lab2_interface___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &interface_handle,
    0,
    0,
    0,
    0,
    RPC_lab2_interface__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x801026e, /* MIDL Version 8.1.622 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

