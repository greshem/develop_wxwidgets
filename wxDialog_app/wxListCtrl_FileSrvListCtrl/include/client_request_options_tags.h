// 
// #2011_04_02_13:36:06   星期六   add by greshem
// 
// #注意. 对每个客户端协议的 请求的  请求的 选项 的 tag 一般 不会 超过,  64 个字节
// 
//==========================================================================
// 1-402.
// 	配置文件的 set get add 
// 		mark 
// 		size 
// 		main_func
// 		sub_func
#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((packed))
#endif

		typedef struct  _request_1_to_402 {
			char item[64];
		} PACKED request_1_to_402;

// sizeof = 64 = 64
// 	如何判断是请求这个值 还是 请求修改这个值， 用size 
// 	size - 头部 为0   请求数据. 
// 	size - 头部 > 0   则是 请求修改数据.  没有则是添加配置项.
//	请求包:
//		header| tagRequest|


//==========================================================================
//501.  
//	MAIN_USER_501_GET_STATION_LIST
//	获取nwconn 的客户端的列表. 
	typedef struct _request_501 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_501;
//sizeof = 4 + 32 + 16 =52
//	size - 头部== 0 , 获取 全部的 nwconn 
//	请求包:
//		header|501_request|

//========================================================================
typedef struct _request_502 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_502;

//========================================================================
typedef struct _request_503 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_503;

//========================================================================
typedef struct _request_504 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_504;
//#==========================================================================
//505. 
//	MAIN_USER_505_KILL_NWCONN 
//	杀掉指定的进程 
	typedef struct _request_505 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_505;
//sizeof = 4 + 32 + 16 = 52
//	size - 头部 == 0 , 杀死全部的nwconn
//	请求包:
//		header|505_request|

//#==========================================================================
//506. 
//	MAIN_USER_506_CURRENT_ACCESS_FILE	
//	获取谁 占用那些文件. 

	typedef struct _request_506 {
		int pid;
		char mac_addr[32];
		char node_addr[16];
	} PACKED request_506 ;

//sizeof = 4 + 32 + 16 = 52
//	假如  size - 头部==0,  返回所有的nwconn 实用的所有的文件, uniq 一下, 并统计每个文件的实用 频率.  	
//	请求包:
//		header|506_request|

//==========================================================================
//507. 
//	MAIN_USER_507_START_NWSERV
//		启动 nwserv 假如已经 启动了 但是还是要求启动, 返回错误. 
		typedef struct _request_507 {
		} PACKED request_507;
// sizeof = 1 = 1	
//		size - 头部 ==0  这里应该不要什么参数. 
//		size - 头部 > 0 错误. 

//	请求包:
//		header| 

//==========================================================================
//508. 
//	MAIN_USER_508_STOP_NWSERV
//		停止. 
		typedef struct _request_508 {
		} PACKED request_508 ;	
//sizeof = 1 = 1
// 		size - 头部 ==0  这里应该不要什么参数. 
// 			size - 头部 > 0 错误. 
//	请求包:
//		header| 

//#==========================================================================
//509.	
//	MAIN_USER_509_RESTART_NWSERV	 
//	重启
	typedef struct _request_509 {
		} PACKED request_509;	
//sizeof = 1 = 1
//		size - 头部 ==0  这里应该不要什么参数. 
//		size - 头部 > 0 错误. 

//	请求包:
//		header| 
//#==========================================================================
// 510. MAIN_USER_510_REFRESH_ALL 
// 		刷新
	typedef struct _request_510 {
		} PACKED request_510;	
// sizeof = 1 = 1
		// size - 头部 ==0  这里应该不要什么参数. 
		// size - 头部 > 0 错误. 
//	请求包:
//		header| 

//#==========================================================================
//511. MAIN_USER_511_GET_LOG
//		获取日志.
	typedef struct _request_511 {
		char 	filename[256]; 	//对应的日志文件. 
		int		start_time; //开始时间. 
		int  	end_time;	//结束时间. 	
		char 	pttern[32]; //日志是否包含这样的字符串.
	} PACKED request_511;	
//sizeof = 256 + 4 + 4 + 32 = 296
//	size - 头部 == 0  获取 /var/log/nwserv.log 的全部的日志,   	
//  sizeof(size - 头部) == sizeof(501_request) 正确。
// 	请求包:
// 		header|511_request|
			
//#==========================================================================
// 512. 
// 	MAIN_USER_512_WHO_USE_THIS_FILE
// 	获取 指定文件谁在占用
	typedef struct _request_512 {
		char filename[256];
	} PACKED request_512;
// sizeof = 256 = 256
// 假如 size - 头部 == 0 是错误的请求. 
// 假如  filename[0]==NULL 也是错误, 
// 假如 filename 是绝对路径,  但是  filename 不存在 也是错误. 

//	请求包:
//		header|512_request|
//#==========================================================================

//513. 
//	MAIN_USER_513_GEN_CORE_DUMP	
//	生成指定的进程的 core dump 转储文件. 
		typedef struct _request_513 {
			int pid;
			char mac_addr[32];
			char node_addr[16];
		} PACKED request_513;
//sizeof = 4 + 32 + 16 = 52
// 	假如 size - 头部 == 0  转储 当前所有程序 的 core-dump
//	请求包:
//		header|513_request|
