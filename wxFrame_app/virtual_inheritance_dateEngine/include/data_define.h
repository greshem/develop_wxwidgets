#ifndef __DATA__DEFINED__HEADER
#define  __DATA__DEFINED__HEADER

#ifdef WINDOWSCODE
#define PACKED
#pragma pack(1)
#else
#define PACKED __attribute__((__packed__))
#endif

//wxwidgets 的界面的struct 的信息.  
//------------------------------------------------------------------------
//1. 第一个页面， 基本信息. 
//		接口: BaseDataEngine::GetBaseInfo( BaseInfo &out)
typedef struct _BaseInfo {
	char server_name[32]; 	// 服务器名称
	char status;		  	// 模拟器工作状态.
	char inner_network[32]; // 内部网络号. 
	char inner_node[32];	// 内部node 号.	
	char ex_network[32];	// 外部node号.
	char mac_addr[16];		// 网卡地址.
	char frame_type[16];	// 帧类型. 
	char 	reverse[7];
} PACKED BaseInfo ;
//sizeof = 32 + 1 + 32 + 32 +32 +16 +16  + 7 = 168 
//------------------------------------------------------------------------
//2.  第二个页面, 共享文件夹目录
//		接口: void BaseDataEngine::GetShareDir(vector<string> &share_dir)
//		notice: 一个共享目录一个 char path[256];
		
//------------------------------------------------------------------------
//3. 第三个页面, 工作站管理
//		接口: void GetAllWorkStation(vector<Workstation> &out);
typedef struct _Workstation {
	char mac_addr[16];		// 网卡地址.
	char inner_network[32]; // 内部网络号. 
	char status;			//工作状态
	int	 connect_time;		//连接时间. 
	char cur_used_file[128];//当前读取文件. 
	char 	reverse[3];
} PACKED Workstation ;
//sizeof = 16 + 32 + 1 + 4 + 128   + 3 = 184 

//------------------------------------------------------------------------
//4. 第四个页面, 进程管理
//		接口. void BaseDataEngine::GetAllProcess(vector<nw_process> &out);
typedef struct _nw_process {
	char mac_addr[16];		// 网卡地址.
	char inner_network[32]; // 内部网络号. 
	char process_name [32]; // 进程名称. 
	char status;			// 进程状态. 
	char reverse[15];	
} PACKED nw_process   ;
//sizeof =  16 +32 + 32 + 1 + 15   = 96

//------------------------------------------------------------------------
//5. 第五个页面, 日志管理 
//		接口: void BaseDataEngine::GetNwServLog(vector<string> &logStr)
//		notice: 有几种日志, 现在只实现 nwserv.log
//########################################################################

#endif
