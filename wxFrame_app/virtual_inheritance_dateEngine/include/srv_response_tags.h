
//2011_04_02_14:13:40   星期六   add by greshem
// 注意. 
// 	tagContent 需要每个 协议自己定义.  
// 	tagResult
#ifndef __SRV_RESPONSE_TAGS_H__
#define __SRV_RESPONSE_TAGS_H__

#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((packed))
#endif

	typedef struct _tagResult {
	int frame_count; //一共有几个分片.
	int cur_frame;
	int result;
	}  PACKED tagResult;
	//sizeof = 4 + 4 + 4 = 12
	// 错误值: 协议错误|没有数据|正常|没有对应的命令| 程序已经存在|  
	// 头部 +  tagResult  + |tagContent|tagContent|tagContent|tagContent  
//==========================================================================
// 1-402.
// 	配置文件的set get  add  
// 		mark 
// 		size 
// 		main_func
// 		sub_func
		
				
		typedef struct _response_1_to_402 {
		} PACKED response_1_to_402;
		//sizeof = 1 = 1
		// 如何判断是请求这个值 还是 请求修改这个值， 用size 
		// size - 头部 为0   请求数据, 
		// size - 头部 > 0   则是 请求修改数据, 没有则是添加配置项.

	// 返回包:
	// 	header|tagResult|
//==========================================================================
// 501. 
// 	MAIN_USER_501_GET_STATION_LIST
// 	获取nwconn 的客户端的列表. 
// 	tagContent=501_respense;
	typedef struct _response_501 {
		int   pid;			//pid	 ps -elf 4个字段.
		int   ppid;			//父进程pid ps -elf 5个字段.
		char  WCHAN[32];		//当前系统调用的状态. ps -elf 11个字段.
		int   elapsed_time;		//elapsed time from start up to now 
		char  cmdline[64];	//启动参数. ps -elf 第14 个字段以后. 
	}  PACKED response_501;
//	返回包
//		tagHeader + tagResult |respense_501|respense_501|respense_501|respense_501|....
//		sizeof = 4 + 4  +32+4  +64 =108 
//========================================================================
	typedef struct _response_502 {
	}  PACKED response_502;
//	sizeof = 1 = 1

//========================================================================
typedef struct _response_503 {
	}  PACKED response_503;
//	sizeof = 1 = 1

//========================================================================
typedef struct _response_504 {
	}  PACKED response_504;
//	sizeof = 1 = 1

//#==========================================================================
//505. 	
// 	MAIN_USER_505_KILL_NWCONN 
// 	杀掉指定的进程 

//	tagContent{} 没有内容. 
	typedef struct _response_505 {
	} PACKED  response_505;
//	sizeof = 1 = 1
//	返回包:
//		tagHeader + tagResult

//==========================================================================
//506. 
//lsof -p pid 
// 		MAIN_USER_506_CURRENT_ACCESS_FILE	
// 		获取谁 占用那些文件. 
	//tagContent 
		typedef struct _response_506 {
		int 	pid;
		char	prog_name[32];
		char 	filename[256];
	} PACKED  response_506 ;
	
//返回包:	
//	tagHeader + tagResult + reponse_507|reponse_507| reponse_507|....
//	sizeof = 4+32+256 = 292


//==========================================================================
//507. 
//	MAIN_USER_507_START_NWSERV
//		启动 nwserv 假如已经 启动了 但是还是要求启动, 返回错误. 
//		tagResult= ok|没有这个进程| 没有文件. 
	typedef struct _response_507 {
	}  PACKED response_507;
	
//	sizeof = 1 = 1
//返回包:	
//tagHeader + tagResult

//==========================================================================
//508. 
	// MAIN_USER_508_STOP_NWSERV
	// 	停止. 
	// tagResult= ok|没有这个进程| 没有文件. 
	typedef struct _response_508 {
	} PACKED  response_508;

//	sizeof = 1 = 1
//返回包:	
//tagHeader + tagResult

//==========================================================================
//509.	
// MAIN_USER_509_RESTART_NWSERV	 
// 重启
// tagResult= ok|没有这个进程| 没有文件. 
	typedef struct _response_509 {
	}  PACKED response_509;

//sizeof = 1 = 1
//返回包:	
//tagHeader + tagResult


//==========================================================================
//510. 
//	MAIN_USER_510_REFRESH_ALL 
//		刷新

//	tagResult= ok
	typedef struct _response_510 {
	 } PACKED response_510;

//sizeof = 1 = 1
//返回包:	
//tagHeader + tagResult
//==========================================================================
//511. 
// 	MAIN_USER_511_GET_LOG
// 		获取日志.
/*
	整个511的响应结构是: 
	
	| REQUEST      |
	| tagResult    |
	| response_511 |
	| log_data     |
	................
	| response_511 |
	| log_data     |


*/
		 typedef struct _response_511 {
			char 		   filename[256];
			int            log_time;    //...
			int            log_length;	//日志的长度
			#ifdef WINDOWSCODE
			#else
			char           log_data[0]; 
			#endif						/*后面的都是日志，偏移log_length
										之后将会是下一个response_511结构
										至于日志个数是由客户的请求决定的
										*/
		} PACKED response_511;
//	sizeof = 256 + 4 + 4 + 0 = 264
		//这里整个包 tagContent 只有一片. 
//返回包:
	//header|tagResult|reponse_511 
	//sizeof(header|tagResult|reponse_511 )= header.size
//==========================================================================
//512. 
//	MAIN_USER_512_WHO_USE_THIS_FILE
//	获取 指定文件谁在占用
//命令: fuser filename -v 	
//返回列: USER        PID ACCESS COMMAND
//	tagResult = 文件不存在| 没有程序 |ok| 
	typedef struct  _response_512 {
		char	user[16];
		int 	pid;
		char	access[16];
		char	command[64]; 
		int 	null;
	} PACKED response_512 ;
//sizeof = 16 + 4 + 16+64 +4 = 104
	//repense_512 返回结构.  有 >=0  个. 	
//返回包:
	//header|tagResult|reponse_512|reponse_512|reponse_512|...

//==========================================================================
//513. 
//	MAIN_USER_513_GEN_CORE_DUMP	
//	生成指定的进程的 core dump 转储文件. 
//	tagResult = 无法生成| gdb 不存在| 权限不够| 
//	tagConnect = response_513 
	typedef struct _response_513 {
		char core_dump_filename[64];
	}  PACKED response_513;
//sizeof = 64 = 64
//返回包:
//		header|tagResult|reponse_512|...

//==========================================================================
//514. 
//	main_514_NWSERV_IS_OK
//	tagResult = pid 
//	tagConnect = response_514
	typedef struct _response_514 {
	int pid;
	} PACKED  response_514;
//sizeof = 4 = 4
//返回包:
//		header|tagResult|reponse_514|...

//==========================================================================
//515. 
//	main_515_LOGIN_CHECK_PASSWD
//	tagResult = ret_code
//	tagContent = response_515
	typedef struct _response_515 {
	int ret_x;
	int ret_y;
	int ret_z;
	} PACKED  response_515;
//sizeof = 4+4+4 = 12
//返回包:
//		header|tagResult|response_515|...	

//==========================================================================
//516. 
//	main_516_GET_SYSTEM_INFO
//	tagResult = ret_code
//	tagContent = response_516
	typedef struct _response_516 {
	int CPUUsage;
	int MemUsage;
	int StationCount;
	int ServerStatus;
	char eths[64];
	} PACKED  response_516;
//sizeof = 4+4+4+4 +64 = 80
//返回包:
//		header|tagResult|response_516|...	

//==========================================================================
//517. 
//	main_517_FILE_EXISTS
//	tagResult = ret_code
//	tagContent = response_517
	typedef struct _response_517 {
	char filename[64];
	} PACKED  response_517;
//sizeof = 64  = 64
//返回包:
//		header|tagResult|response_517|...	

#endif
