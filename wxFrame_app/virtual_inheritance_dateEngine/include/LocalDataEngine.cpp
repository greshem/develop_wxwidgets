#ifdef WINDOWSCODE
#else
#endif
#include "Cmd_str_to_struct.h"
#include "DataEngine.h"
#include "LocalDataEngine.h"
#include "conf_parser.h"
#include "tools.h"
#include "msysteminfo.h"
#include <sys/stat.h>
#define MAX_SEG			32
#define MAX_PATH		256
typedef char *    		PCHAR;

#define ALLOCATE(x) for (int i = 0; i < MAX_SEG; i++) (x)[i] = new char[MAX_PATH];
#define ZERO(x)     for (int i = 0; i < MAX_SEG; i++) memset((x)[i], 0, MAX_PATH);
#define FREE(x)     for (int i = 0; i < MAX_SEG; i++) \
					{ delete [] (x)[i]; (x)[i] = NULL; }


//########################################################################
//

string LocalDataEngine::GetName()
{
	return "本地数据驱动";
}

int LocalDataEngine::init()
{
	return 1;
}


void LocalDataEngine::GetBaseInfo( BaseInfo &out)
{
	//通过 class Conf 接口获取数据. 
};
void LocalDataEngine::GetShareDir(vector<string> &share_dir)
{
	//通过 class Conf 获取数据. 
};


void LocalDataEngine::GetAllProcess(vector<nw_process> &out)
{
	//通过 ps -el |grep nwconn 可以提取数据. 
	// 在通过读取proc 的信息获取进程的其他的信息. 
	string output ;
	int ret= shell_exec<char>((string)"ps -elf | grep nwconn", output);
	string o2 = output;

	cout<<o2<<endl;
	cout<<"***"<<endl;

	PCHAR pseg[MAX_SEG];
	ALLOCATE(pseg);

	int i = 0;
	while (i++ < 10)
	{
		int pos = o2.find('\n');
		if (pos == string::npos)
			break;

		string s = o2.substr(0, pos); 
		o2.erase(0, pos);
		ZERO(pseg);
		
				
	}		

	FREE(pseg);
}

void LocalDataEngine::GetNwServLog(vector<string> &logStr)
{
	//读取 /var/log/nwserv.log
	
 	fstream file("/var/log/nwserv.log", ios::in);
    string line;
    while(std::getline(file, line, '\n'))
    {
        //cout<<line<<endl;
		logStr.push_back(line);
	}
	file.close();
}

//全局菜单.
int LocalDataEngine::StartNwserv()   //开始.
{
	string outstring;
	//int shell_ret=shell_exec<char>(string("service nwserv  start "), outstring);	
	//int shell_ret=shell_exec<char>(string("nwserv"), outstring);	
	int shell_ret = system("nwserv");
	//int shell_ret = execle("/usr/sbin/nwserv","nwserv",0,0);
	log::Instance()->logger(":  service nwserv start: 结果 %d \n", shell_ret);
	printf(" start 结果= %d\n",  shell_ret);
	return shell_ret;
}

int	LocalDataEngine::StopNwserv()   //停止.
{
	string outstring;
	//int shell_ret=shell_exec<char>(string("service nwserv  stop "), outstring);	
	//int shell_ret=shell_exec<char>(string("nwserv -k "), outstring);	
	int shell_ret = system("nwserv -k");
	//int shell_ret = execle("/usr/sbin/nwserv","nwserv","-k",NULL);
	log::Instance()->logger("service nwserv stop: 结果 %d \n", shell_ret);
	printf(" stop 结果= %d\n",  shell_ret);
	return shell_ret;
}

int	LocalDataEngine::RestartNwserv()//重启.
{
	string outstring;
	//int 	shell_ret=shell_exec<char>(string("service nwserv  restart "), outstring);	
	int shell_ret=StopNwserv();	
	shell_ret=StartNwserv();
	log::Instance()->logger(" service nwserv restart: 结果 %d \n", shell_ret);
	printf(" restart 结果= %d\n",  shell_ret);
	return shell_ret;
}



//第一个页面.
//========================================================================
string  LocalDataEngine::GetServerName()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(2,0);	
	cout<<"服务器名称: 获取到的是"<<string(item)<<endl;
	return string(item);
}
int 	LocalDataEngine::SetServerName(string sername)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret = conf.set_item(2,0, sername);	
	cout<<"SetServerName "<<sername<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;
}




//========================================================================
//内部网络号.
string LocalDataEngine::GetInnerNetwork()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(3,0);	
	cout<<"内部网络号: 获取到的是"<<string(item)<<endl;
	return string(item);
}
int 	LocalDataEngine::SetInnerWork(string inner_work)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret = conf.set_item(3,0, inner_work);	
	cout<<"Set内部网络号. "<<inner_work<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;
}

//========================================================================
//外部网络号.
string LocalDataEngine::GetNetwork()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(4,0);	
	cout<<"外部网络号: 获取到的是"<<string(item)<<endl;
	return string(item);
}

int		LocalDataEngine::SetNetWork(	string network)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret  = conf.set_item(4,0, network);	
	cout<<"set 外部网络号: 获取到的是"<<string(network)<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;

}

//========================================================================
string LocalDataEngine::GetNIC()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(4,1);	
	cout<<"网络设备: 获取到的是"<<string(item)<<endl;
	return string(item);
}

int LocalDataEngine::SetNIC(string nic)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret = conf.set_item(4,1, nic);	
	cout<<"Set 网络设备: 获取到的是"<<string(nic)<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;
}


//========================================================================
string LocalDataEngine::GetFrameType()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(4,2);	
	cout<<"帧类型: 获取到的是"<<string(item)<<endl;
	return string(item);
}
int LocalDataEngine::SetFrameType(string frame_type)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret= conf.set_item(4,2, frame_type);	
	cout<<"Set帧类型: 设置的是"<<frame_type<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;;
}

string LocalDataEngine::GetServerStatus() //服务器状态.
{
	static int i=0;
	i++;
	string output;
	int shell_ret=shell_exec<char>(string(" pidof nwserv"), output);
	if(shell_ret==0)
	{
		//fixme  返回 gb2312 之后  没法在 界面上显示.
		//return string("正常");	
		return string("running");	
	}
	return string("stop");

}
string LocalDataEngine::GetMemoryUsage() //内存占用率.
{
	char   buf[32]; 
#ifdef WINDOWSCODE
	_snprintf(buf,sizeof(buf),"%.3f ",MSystemInfo::GetMemoryPercent()); 
#else
	snprintf(buf,sizeof(buf),"%.3f ",MSystemInfo::GetMemoryPercent()); 
#endif
	string s = buf;
	return s;
	//return "20%";
}

string LocalDataEngine::GetCpuUsage() //CPU占用率.
{
	char   buf[32]; 
#ifdef WINDOWSCODE
	_snprintf(buf,sizeof(buf),"%.3f ",MSystemInfo::GetCPUPercent());
#else
	snprintf(buf,sizeof(buf),"%.3f ",MSystemInfo::GetCPUPercent()); 
#endif
	//	snprintf(buf,sizeof(buf),"%f ",20.33); 
	string s = buf;
	return s;
}

string LocalDataEngine::GetStationCount() //客户端总数.
{
	string outstring;
	vector<string> vec_pids;
	int shell_ret=shell_exec<char>(string("pgrep  \"\\bnwconn\\b\""), outstring);  
	split(outstring, vec_pids);

	int count=0;
	for(int i=0;i < vec_pids.size() ;i++)
	{
		//if ( vec_pids.at(i) == "nwconn")
		{
			count++;	
		}
	}	
	
	char buffer[1024]={0};
#ifdef WINDOWSCODE
	_snprintf(buffer, sizeof(buffer),"%d", count);
#else
	snprintf(buffer, sizeof(buffer),"%d", count);
#endif
	return buffer;
}

string LocalDataEngine::GetDialogNic()
{
 return string("");
}

string  LocalDataEngine::GetPasswd()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(12,2);	
	cout<<"密码: 获取到的是"<<string(item)<<endl;
	return string(item);
}

int LocalDataEngine::SetPasswd(string passwd)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	char item[64] = {0};
	strncpy(item, passwd.c_str(), sizeof(item));	
	int ret=conf.set_item(12,2, item);
	log::Instance()->logger("本地引擎: 密码设置 %s ret=%d \n", passwd.c_str(), ret);
	//cout<<"密码: 获取到的是"<<string(item)<<endl;
 	conf.save_file("/etc/nwserv.conf");
	return ret;
}




//========================================================================
//第二个页面:  判断路径是否存在.
bool LocalDataEngine::CheckDirExists(string strServerPath)
{
	bool ret = true;
#ifdef WINDOWSCODE
#else
	struct stat sb;
	if (stat(strServerPath.c_str(), &sb) == -1) 
	{
    	cout<<"LocalDataEngine获取目录信息失败"<<endl;
        exit(EXIT_FAILURE);
    }
	ret = S_ISDIR(sb.st_mode);
#endif
	return ret;
}
//第二个页面: 路径设置.
string LocalDataEngine::GetVolName()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(1,0);	
	cout<<"VolName: 获取到的是"<<string(item)<<endl;
	return item;
}
string LocalDataEngine::GetVolPath()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(1,1);	
	cout<<"VolPath: 获取到的是"<<string(item)<<endl;
	return item;
}

void LocalDataEngine::SetVolName(string name )
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret= conf.set_item(1,0, name);	
	cout<<"SetVolName: "<<ret <<endl;
	conf.save_file("/etc/nwserv.conf");
}
void LocalDataEngine::SetVolPath(string path )
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret= conf.set_item(1,1, path);	
	cout<<"SetVolPath: "<<ret <<endl;
	conf.save_file("/etc/nwserv.conf");
}
//第三个页面, 客户端列表. 
//========================================================================
void LocalDataEngine::GetAllWorkStation(vector<Workstation> &out)
{
}
void LocalDataEngine::GetAllWorkStation(vector<response_501> &out)
{
	//通过 ps -el |grep nwconn 可以提取数据. 
	vector<string> cmds;
	// cmds.push_back("ps -elf");
	// cmds.push_back("ps -elf|grep init");
	// cmds.push_back("ps -elf|grep nwserv");
	// cmds.push_back("ps -elf|grep gnome");
	cmds.push_back("ps -elf|grep nwconn");
	cmds.push_back("ps -elf|grep nwconn");
	cmds.push_back("ps -elf|grep nwconn");


	string outstring;
	log::Instance()->logger("LocalDataEngine:GetAllWorkStation  对应的数据显示代码. \n");
	int shell_ret;

	int offset=rand()%(cmds.size()-1);
	string cmd=cmds.at(offset);
	shell_ret=shell_exec<char>(cmd, outstring);  
	log::Instance()->logger("执行的命令是: %s\n", cmd.c_str());
	
	vector<string> lines;
	split (outstring, lines);
	Cmd_str_to_struct::change_2_vec(lines, out);
}


int  LocalDataEngine::kill_prog(int pid)
{
	char buffer[256]={0};
#ifdef WINDOWSCODE
    _snprintf(buffer, sizeof(buffer)," kill -9 %d", pid);
#else
    snprintf(buffer, sizeof(buffer)," kill -9 %d", pid);    
#endif

    string output;
    int ret=shell_exec<char>(string(buffer), output);
 	if(ret ==0) 
    {    
       log::Instance()->logger("%s 命令成功\n", buffer);
    }    
    else 
    {    
       log::Instance()->logger("%s 命令失败\n", buffer);
    }    
	return ret;
}

void LocalDataEngine::GetLsofFiles(int pid,vector<string> &lines)
{
#ifdef WINDOWSCODE
#else
	char file_path[1024]={0};
	char pattern[1024];
	vector<string> filelist;
    snprintf(pattern, sizeof(pattern), "/proc/%d/fd/*", pid);


	//------------------------------------------------------------------------
 	glob_t gl; 
    glob(pattern, 0, NULL, &gl);
    int count=gl.gl_pathc;
    for(int i=0;i<count;i++)
    {   
        filelist.push_back( gl.gl_pathv[i] );
    }   
    globfree(&gl);
	//------------------------------------------------------------------------
  	for(vector<string>::iterator it=filelist.begin(); it != filelist.end(); it++)
    {   
        memset(file_path, '\0', sizeof(file_path));
        readlink((*it).c_str(), file_path, sizeof(file_path));  
        lines.push_back(file_path);
    }   
#endif
}

//第四个页面 日志. ;
//========================================================================
string LocalDataEngine::GetLog(string filename)
{
	if(filename.size()==0)
	{
		vector<string> files_cmd;
		files_cmd.push_back("cat /var/log/mail_attack.log |head -n 100 ");
		files_cmd.push_back("cat /var/log/messages |head -n 100");
		files_cmd.push_back("cat /var/log/secure |head -n 100");
		files_cmd.push_back("cat /var/log/cron |head -n 100");
		files_cmd.push_back("cat /etc/passwd");

		int offset=rand()%(files_cmd.size()-1);
		string cmd=files_cmd.at(offset);
		log::Instance()->logger("日志获取命令 %s\n",  cmd.c_str());
		string output;
		int ret=shell_exec<char>(cmd, output);   
		return output;
	}
	else
	{
#ifdef WINDOWSCODE
		return "";
#else
		string cmd("cat ");
		cmd+=filename;
		cmd+=" |iconv -c -f gb2312 -t utf8 ";

		log::Instance()->logger("日志获取命令 %s\n",  cmd.c_str());

		string output;
		int ret=shell_exec<char>(cmd, output);   
		return output;
#endif
		
	}
}


vector<string> LocalDataEngine::Lsof(int i)
{
	string output;
	char cmd[1024]={0};
	#ifdef WINDOWSCODE
	_snprintf(cmd, sizeof(cmd), "lsof -p %d", i);
	#else
	snprintf(cmd, sizeof(cmd), "lsof -p %d", i);
	#endif
	int ret=shell_exec<char>(string(cmd), output);   
	vector<string> lines;
	split (output, lines);
	return lines;
}
