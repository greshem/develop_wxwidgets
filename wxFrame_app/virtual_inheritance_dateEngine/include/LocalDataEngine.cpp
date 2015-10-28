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
	return "������������";
}

int LocalDataEngine::init()
{
	return 1;
}


void LocalDataEngine::GetBaseInfo( BaseInfo &out)
{
	//ͨ�� class Conf �ӿڻ�ȡ����. 
};
void LocalDataEngine::GetShareDir(vector<string> &share_dir)
{
	//ͨ�� class Conf ��ȡ����. 
};


void LocalDataEngine::GetAllProcess(vector<nw_process> &out)
{
	//ͨ�� ps -el |grep nwconn ������ȡ����. 
	// ��ͨ����ȡproc ����Ϣ��ȡ���̵���������Ϣ. 
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
	//��ȡ /var/log/nwserv.log
	
 	fstream file("/var/log/nwserv.log", ios::in);
    string line;
    while(std::getline(file, line, '\n'))
    {
        //cout<<line<<endl;
		logStr.push_back(line);
	}
	file.close();
}

//ȫ�ֲ˵�.
int LocalDataEngine::StartNwserv()   //��ʼ.
{
	string outstring;
	//int shell_ret=shell_exec<char>(string("service nwserv  start "), outstring);	
	//int shell_ret=shell_exec<char>(string("nwserv"), outstring);	
	int shell_ret = system("nwserv");
	//int shell_ret = execle("/usr/sbin/nwserv","nwserv",0,0);
	log::Instance()->logger(":  service nwserv start: ��� %d \n", shell_ret);
	printf(" start ���= %d\n",  shell_ret);
	return shell_ret;
}

int	LocalDataEngine::StopNwserv()   //ֹͣ.
{
	string outstring;
	//int shell_ret=shell_exec<char>(string("service nwserv  stop "), outstring);	
	//int shell_ret=shell_exec<char>(string("nwserv -k "), outstring);	
	int shell_ret = system("nwserv -k");
	//int shell_ret = execle("/usr/sbin/nwserv","nwserv","-k",NULL);
	log::Instance()->logger("service nwserv stop: ��� %d \n", shell_ret);
	printf(" stop ���= %d\n",  shell_ret);
	return shell_ret;
}

int	LocalDataEngine::RestartNwserv()//����.
{
	string outstring;
	//int 	shell_ret=shell_exec<char>(string("service nwserv  restart "), outstring);	
	int shell_ret=StopNwserv();	
	shell_ret=StartNwserv();
	log::Instance()->logger(" service nwserv restart: ��� %d \n", shell_ret);
	printf(" restart ���= %d\n",  shell_ret);
	return shell_ret;
}



//��һ��ҳ��.
//========================================================================
string  LocalDataEngine::GetServerName()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(2,0);	
	cout<<"����������: ��ȡ������"<<string(item)<<endl;
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
//�ڲ������.
string LocalDataEngine::GetInnerNetwork()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(3,0);	
	cout<<"�ڲ������: ��ȡ������"<<string(item)<<endl;
	return string(item);
}
int 	LocalDataEngine::SetInnerWork(string inner_work)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret = conf.set_item(3,0, inner_work);	
	cout<<"Set�ڲ������. "<<inner_work<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;
}

//========================================================================
//�ⲿ�����.
string LocalDataEngine::GetNetwork()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(4,0);	
	cout<<"�ⲿ�����: ��ȡ������"<<string(item)<<endl;
	return string(item);
}

int		LocalDataEngine::SetNetWork(	string network)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret  = conf.set_item(4,0, network);	
	cout<<"set �ⲿ�����: ��ȡ������"<<string(network)<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;

}

//========================================================================
string LocalDataEngine::GetNIC()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(4,1);	
	cout<<"�����豸: ��ȡ������"<<string(item)<<endl;
	return string(item);
}

int LocalDataEngine::SetNIC(string nic)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret = conf.set_item(4,1, nic);	
	cout<<"Set �����豸: ��ȡ������"<<string(nic)<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;
}


//========================================================================
string LocalDataEngine::GetFrameType()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(4,2);	
	cout<<"֡����: ��ȡ������"<<string(item)<<endl;
	return string(item);
}
int LocalDataEngine::SetFrameType(string frame_type)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	int ret= conf.set_item(4,2, frame_type);	
	cout<<"Set֡����: ���õ���"<<frame_type<<endl;

 	conf.save_file("/etc/nwserv.conf");
	return ret;;
}

string LocalDataEngine::GetServerStatus() //������״̬.
{
	static int i=0;
	i++;
	string output;
	int shell_ret=shell_exec<char>(string(" pidof nwserv"), output);
	if(shell_ret==0)
	{
		//fixme  ���� gb2312 ֮��  û���� ��������ʾ.
		//return string("����");	
		return string("running");	
	}
	return string("stop");

}
string LocalDataEngine::GetMemoryUsage() //�ڴ�ռ����.
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

string LocalDataEngine::GetCpuUsage() //CPUռ����.
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

string LocalDataEngine::GetStationCount() //�ͻ�������.
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
	cout<<"����: ��ȡ������"<<string(item)<<endl;
	return string(item);
}

int LocalDataEngine::SetPasswd(string passwd)
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	char item[64] = {0};
	strncpy(item, passwd.c_str(), sizeof(item));	
	int ret=conf.set_item(12,2, item);
	log::Instance()->logger("��������: �������� %s ret=%d \n", passwd.c_str(), ret);
	//cout<<"����: ��ȡ������"<<string(item)<<endl;
 	conf.save_file("/etc/nwserv.conf");
	return ret;
}




//========================================================================
//�ڶ���ҳ��:  �ж�·���Ƿ����.
bool LocalDataEngine::CheckDirExists(string strServerPath)
{
	bool ret = true;
#ifdef WINDOWSCODE
#else
	struct stat sb;
	if (stat(strServerPath.c_str(), &sb) == -1) 
	{
    	cout<<"LocalDataEngine��ȡĿ¼��Ϣʧ��"<<endl;
        exit(EXIT_FAILURE);
    }
	ret = S_ISDIR(sb.st_mode);
#endif
	return ret;
}
//�ڶ���ҳ��: ·������.
string LocalDataEngine::GetVolName()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(1,0);	
	cout<<"VolName: ��ȡ������"<<string(item)<<endl;
	return item;
}
string LocalDataEngine::GetVolPath()
{
	nw_conf_parser conf;
	conf.parse_file("/etc/nwserv.conf");
	string item = conf.get_item(1,1);	
	cout<<"VolPath: ��ȡ������"<<string(item)<<endl;
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
//������ҳ��, �ͻ����б�. 
//========================================================================
void LocalDataEngine::GetAllWorkStation(vector<Workstation> &out)
{
}
void LocalDataEngine::GetAllWorkStation(vector<response_501> &out)
{
	//ͨ�� ps -el |grep nwconn ������ȡ����. 
	vector<string> cmds;
	// cmds.push_back("ps -elf");
	// cmds.push_back("ps -elf|grep init");
	// cmds.push_back("ps -elf|grep nwserv");
	// cmds.push_back("ps -elf|grep gnome");
	cmds.push_back("ps -elf|grep nwconn");
	cmds.push_back("ps -elf|grep nwconn");
	cmds.push_back("ps -elf|grep nwconn");


	string outstring;
	log::Instance()->logger("LocalDataEngine:GetAllWorkStation  ��Ӧ��������ʾ����. \n");
	int shell_ret;

	int offset=rand()%(cmds.size()-1);
	string cmd=cmds.at(offset);
	shell_ret=shell_exec<char>(cmd, outstring);  
	log::Instance()->logger("ִ�е�������: %s\n", cmd.c_str());
	
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
       log::Instance()->logger("%s ����ɹ�\n", buffer);
    }    
    else 
    {    
       log::Instance()->logger("%s ����ʧ��\n", buffer);
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

//���ĸ�ҳ�� ��־. ;
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
		log::Instance()->logger("��־��ȡ���� %s\n",  cmd.c_str());
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

		log::Instance()->logger("��־��ȡ���� %s\n",  cmd.c_str());

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
