#ifndef ___REQUEST_APPLY_HEADER___
#define ___REQUEST_APPLY_HEADER___

/********************************************************************************************
* Description -  ���￪ʼ ��� protocol.h ��ÿ��Э�鶨�� ��Ӧ��struct , 
* Author -      qianzhongjie@gmail.com
* Date -        2011_03_29_16:28:25
* �ͻ��˷�������. 
* 	header tagHeader
* 	����� tagXXXXXX  һ��. 
*  �ͻ��˷���˻�Ӧ. 
*	header tagHeader
*   ���ص� tagXXXXXX|tagXXXXXXX|tagXXXXXXX|.... , n������ʵ�����. 
*   ������ tagReturn, �����Ĵ���, ����Э�鲻����|û������| ��ȫ��ȷ| 
* ÿ�δ�������֮ǰ�� indent  -brs struct_declaration.h, �� struct �Ĵ�������һ��.
* 									--braces-on-struct-decl-line  �� { ���ں� typed ef struct ͬһ��.
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
// �ͻ��˵������struct 
#include "./client_request_options_tags.h"

//########################################################################
//����˵�Ӧ��� struct 
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
