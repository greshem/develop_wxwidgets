#include "data_define.h"
#ifndef __DATAENGER__HEADER
#define __DATAENGER__HEADER

//#接口如下.  
//1. 第一个页面. 
#ifdef WINDOWSCODE
#else
#include <dirent.h>
#endif

#include <fstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "protocol.h"
#include "client_request.h"
//#include "tools.h"
using namespace std;



class BaseDataEngine
{
public:
		virtual string GetName();
		virtual int init();
public:
	virtual   	void GetBaseInfo( BaseInfo &out);
	virtual 	void GetShareDir(vector<string> &share_dir);
	
	virtual		void GetAllProcess(vector<nw_process> &out);
	virtual 	void GetNwServLog(vector<string> &logStr);

	//全局菜单
	virtual		int RestartNwserv();
	virtual 	int StopNwserv();
	virtual		int StartNwserv();	


	//第一个页面. 
	virtual 		string	 	GetWorkStatus();   //工作状态.
	virtual 		string  	GetServerName();   //服务器名.
	virtual 		string  	GetInnerNetwork(); //内部网络号.
	virtual 		string  	GetNetwork();      //网络.
	virtual 		string  	GetNIC();          //网卡.
	virtual 		string  	GetFrameType();    //frame帧类型.
	virtual 		string 		GetServerStatus(); //服务器状态.
	virtual 		string 		GetMemoryUsage(); //内存占用率.
	virtual			string		GetCpuUsage();		//Cpu占用率
	virtual 		string 		GetStationCount(); //内存占用率.
	virtual			string  	GetPasswd();			//密码.
	virtual 		int		SetPasswd(string passwd);			//设置密码.

	virtual			string 		GetDialogNic();
	//set
	virtual 	int 	SetServerName(string sername);
	virtual 	int 	SetInnerWork(string inner_work);
	virtual 	int		SetNetWork(	string network);
	virtual 	int		SetNIC(	string nic);
	virtual 	int		SetFrameType( string frame_type);	
	//第二个页面.
	//
	virtual string GetVolName();
	virtual string GetVolPath();

	virtual void SetVolName(string name );
	virtual void SetVolPath(string path );

	virtual bool CheckDirExists(string strServerPath);

	//第三个页面.
	//virtual void GetStationList(	
	virtual		void GetAllWorkStation(vector<Workstation> &out);
 	virtual		void GetAllWorkStation(vector<response_501> &out);
	virtual		int kill_prog(int pid);
	virtual     void GetLsofFiles(int,vector<string>&);
	//第4个页面.
	virtual string GetLog(string filename );

};



#endif  //__DATAENGER__HEADER

