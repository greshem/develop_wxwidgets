#ifndef ___REQUEST_APPLY_HEADER___
#define ___REQUEST_APPLY_HEADER___

/********************************************************************************************
* Description -  这里开始 针对 protocol.h 的每个协议定义 对应的struct , 
* Author -      qianzhongjie@gmail.com
* Date -        2011_03_29_16:28:25
* 客户端发送请求. 
* 	header tagHeader
* 	请求的 tagXXXXXX  一个. 
*  客户端服务端回应. 
*	header tagHeader
*   返回的 tagXXXXXX|tagXXXXXXX|tagXXXXXXX|.... , n个根据实际情况. 
*   返回码 tagReturn, 遇到的错误, 或者协议不存在|没有数据| 完全正确| 
* 每次代码生成之前用 indent  -brs struct_declaration.h, 把 struct 的代码正则一下.
* 									--braces-on-struct-decl-line  把 { 放在和 typed ef struct 同一行.
*

* *******************************************************************************************/
#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((packed))
#endif

//########################################################################
typedef struct _REQUEST {
	char			mark;
	unsigned int    size;        // total size of request packet
	unsigned int    main_function;    // function number
	unsigned int	 sub_function; //sub_function 
	char 	reverse[3];
	#ifdef WINDOWSCODE
	#else
	unsigned char    data[0];
	#endif
} PACKED REQUEST; 
//sizeof = 4 + 4 +4 +4  + 0 = 16


typedef struct _IPXADDR {
    unsigned int  	network;
    char  	node[6];
    unsigned short 	sock;
	char	 		reverse[4];
} PACKED IPXADDR;
//sizeof = 4 + 6 + 2 +  4 = 16 
#define ADDR_SIZE               sizeof(IPXADDR)


typedef struct _WKSINFO {
	IPXADDR       	addr;
	unsigned int  	login_time;
	unsigned int  	conn_id;
	unsigned int  	nwconn_pid;
    char          	username[32];
	char 			reverse[4];
} PACKED WKSINFO;
//sizeof = 16 +  4 + 4 +4 +32 + 4= 64



typedef struct _NWCONN_INFO {
	IPXADDR    nwconn_addr;
	WKSINFO    wksinfo;
} PACKED  NWCONN_INFO;
//########################################################################
//sizeof = 16 + 64 
// 客户端的请求的struct 
#include "./client_request_options_tags.h"

//########################################################################
//服务端的应答的 struct 
#include "./srv_response_tags.h"


//########################################################################
#define MAX_FRAME_DATA_SIZE 4096
typedef struct _FRAME {
    REQUEST header ;
    char data[MAX_FRAME_DATA_SIZE];
}FRAME ;
//sizeof = 4096 + 16 = 4112
typedef FRAME PACKAGE;
//########################################################################

#endif // ___REQUEST_APPLY_HEADER___
