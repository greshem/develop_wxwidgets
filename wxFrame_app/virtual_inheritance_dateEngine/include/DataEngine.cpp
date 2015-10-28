#ifdef WINDOWSCODE
#else
#include <dirent.h>
#endif
#include "DataEngine.h"
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
#include "tools.h"
#include "log.h"
//########################################################################
//这个信息是一台机器基本是唯一的, 不容易变化. 

static void  fill_Baseinfo(BaseInfo &out)
{
	memset(&out, '\0', sizeof(out));
	strncpy(out.server_name, "rich_tech ", sizeof(out.server_name));
	out.status=0;
	strncpy(out.inner_network, "00000000", sizeof(out.inner_network));	
	strncpy(out.inner_node, "111111111", sizeof(out.inner_node));
	strncpy(out.ex_network, "222222222", sizeof(out.ex_network));
	strncpy(out.mac_addr, "11:22:33:44:55:66", sizeof(out.mac_addr));
	strncpy(out.frame_type, "802.2", sizeof(out.frame_type));
}
int BaseDataEngine::init()
{
	return 1;
}

//------------------------------------------------------------------------
string BaseDataEngine::GetName()
{
	return "虚拟数据驱动";
}

//随意填充 基本信息. 
void BaseDataEngine::GetBaseInfo( BaseInfo &out)
{
	RandData<>(out);	
};
//------------------------------------------------------------------------
//随意填充 共享信息. 
void BaseDataEngine::GetShareDir(vector<string> &share_dir)
{
	share_dir.push_back("/vld/disk");
	share_dir.push_back("/var/lib/share");
};

//------------------------------------------------------------------------
//随机填充 工作站信息. 
void BaseDataEngine::GetAllWorkStation(vector<Workstation> &out)
{
	Workstation tmp;
	for(int i=0; i<=10; i++)
	{	
		RandData<>(tmp);
		out.push_back(tmp);
	}
}
void BaseDataEngine::GetAllWorkStation(vector<response_501> &out)
{
}

int BaseDataEngine::kill_prog(int pid)
{
	return 1;
}

void BaseDataEngine::GetLsofFiles(int,vector<string>&)
{

}

//------------------------------------------------------------------------
//随意填充 进程信息. 
void BaseDataEngine::GetAllProcess(vector<nw_process> &out)
{
	nw_process  tmp;
	for(int i=0; i<=10; i++)
	{	
		RandData<>(tmp);
		out.push_back(tmp);
	}
}
//------------------------------------------------------------------------
//随意填充 日志信息. 
void BaseDataEngine::GetNwServLog(vector<string> &logStr)
{
	logStr.push_back("log line 1");
	logStr.push_back("log line 2");
	logStr.push_back("log line 3");
	logStr.push_back("log line 4");
}


//########################################################################
//

//全局菜单
int BaseDataEngine::RestartNwserv()
{
	return 0;
}

int BaseDataEngine::StopNwserv()
{
	return 0;
}

int BaseDataEngine::StartNwserv()
{
	return 0;
}


//第一个页面.
string BaseDataEngine::GetWorkStatus()
{
	return string("");
};
string BaseDataEngine::GetServerName()
{
	return string("");
}   
string BaseDataEngine::GetInnerNetwork()
{
	return string("");
}
string BaseDataEngine::GetNetwork()
{
	return string("");
}
string BaseDataEngine::GetNIC()
{
	return string("");
}
string BaseDataEngine::GetFrameType()    
{
	return string("");
}
string BaseDataEngine::GetServerStatus()
{
	return string("");
}
string BaseDataEngine::GetMemoryUsage()
{
	return string("");
}
string BaseDataEngine::GetCpuUsage()
{
	return string("");
}
string BaseDataEngine::GetStationCount()
{
	return string("");
}

string BaseDataEngine::GetDialogNic()
{
	return string("");
}

string BaseDataEngine::GetPasswd()
{
	return string("");
}

int	BaseDataEngine::SetPasswd(string passwd)		//设置密码.
{
	return 1;
}

int BaseDataEngine::SetServerName(string sername)
{
	return 1;
}
int BaseDataEngine::SetInnerWork(string inner_work)
{
	return 1;
}
int	BaseDataEngine::SetNetWork(	string network)
{
	return 1;
}
int	BaseDataEngine::SetNIC(	string nic)
{
	return 1;
}
int	BaseDataEngine::SetFrameType( string frame_type)
{
	return 1;
}

//第2个页面.
string BaseDataEngine::GetVolName()
{
	return "empty_vol_name";
}
string BaseDataEngine::GetVolPath()
{
	return "empty_vol_path";
}

void BaseDataEngine::SetVolName(string name )
{
}
void BaseDataEngine::SetVolPath(string path)
{
}

//第3个页面.
string  BaseDataEngine::GetLog(string filename)
{
	return string("this is log");
}
bool BaseDataEngine::CheckDirExists(string strServerPath)
{
	return true;
}
//第4个页面.
