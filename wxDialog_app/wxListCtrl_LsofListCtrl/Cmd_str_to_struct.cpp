#ifdef WINDOWSCODE
#undef access
#define access access
#else
#include <dirent.h>
#endif
#include "include/Cmd_str_to_struct.h"
#include "include/tools.h"
#include "include/sysinfo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <assert.h>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;
//########################################################################
//########################################################################
//########################################################################
//========================================================================
//cmd_input: ps -elf 
//每一行的格式如下: 
//F S UID        PID  PPID  C PRI  NI ADDR SZ WCHAN  STIME TTY          TIME CMD
//1 2 3			 4 		5   6  7   8  9    10  11     12    13          14   15 
//1 S root      1472     2  0  80   0 -     0 worker Apr11 ?        00:00:00 [rpciod/0]
//

int Cmd_str_to_struct::get_all_user( vector<string> &out)
{
	#ifdef WINDOWSCODE
	out.push_back(string("root"));
	out.push_back(string("bin"));
	out.push_back(string("daemon"));
	out.push_back(string("adm"));
	out.push_back(string("lp"));
	out.push_back(string("sync"));
	out.push_back(string("shutdown"));
	out.push_back(string("halt"));
	out.push_back(string("mail"));
	out.push_back(string("news"));
	out.push_back(string("uucp"));
	out.push_back(string("operator"));
	out.push_back(string("games"));
	out.push_back(string("gopher"));
	out.push_back(string("ftp"));
	out.push_back(string("nobody"));
	out.push_back(string("nscd"));
	out.push_back(string("vcsa"));
	out.push_back(string("rpc"));
	out.push_back(string("mailnull"));
	out.push_back(string("smmsp"));
	out.push_back(string("oprofile"));
	out.push_back(string("pcap"));
	out.push_back(string("ntp"));
	out.push_back(string("dbus"));
	out.push_back(string("avahi"));
	out.push_back(string("sshd"));
	out.push_back(string("rpcuser"));
	out.push_back(string("nfsnobody"));
	out.push_back(string("haldaemon"));
	out.push_back(string("avahi-autoipd"));
	out.push_back(string("xfs"));
	out.push_back(string("gdm"));
	out.push_back(string("sabayon"));
	out.push_back(string("amanda"));
	out.push_back(string("ident"));
	out.push_back(string("named"));
	out.push_back(string("cyrus"));
	out.push_back(string("distcache"));
	out.push_back(string("dovecot"));
	out.push_back(string("exim"));
	out.push_back(string("radiusd"));
	out.push_back(string("apache"));
	out.push_back(string("mailman"));
	out.push_back(string("fax"));
	out.push_back(string("mysql"));
	out.push_back(string("ais"));
	out.push_back(string("ldap"));
	out.push_back(string("postfix"));
	out.push_back(string("postgres"));
	out.push_back(string("privoxy"));
	out.push_back(string("pvm"));
	out.push_back(string("quagga"));
	out.push_back(string("radvd"));
	out.push_back(string("squid"));
	out.push_back(string("stap-server"));
	out.push_back(string("pegasus"));
	out.push_back(string("tomcat"));
	out.push_back(string("uuidd"));
	out.push_back(string("webalizer"));
	out.push_back(string("huanghaibo"));
	#else
	std::ifstream passwd("/etc/passwd");
	if(!passwd)
	{
		cout<<"open passwd failure \n"<<endl;
		log::Instance()->logger("etc/passwd 文件不能读取, 权限问题.\n");
		return 0;
	}
	
 	while (!passwd.eof()) 
    {   
        std::string line;
        std::getline(passwd, line);
	 	string::size_type pos_end=line.find_first_of(":");
		string user= line.substr(0, pos_end);
		//cout<<user<<endl;
		out.push_back(user);
	}	
	#endif

	return 1;
}

Cmd_str_to_struct::Cmd_str_to_struct()
{
}
int Cmd_str_to_struct::change(const string &in , response_501  &out)
{
	//cout<< in <<endl;
	memset(&out, '\0', sizeof(response_501));

	sysinfo sysinfo_time;
    unsigned long btime[2];

	string null;
	string pid;
	istringstream istr;
    istr.str(in);
	//开始三个略过. F S UID
	int i=0;
	for(i=0; i<3; i++)
	{
		if(! (istr >>null))
		{
			return 0;
		}	
	}

	//因为是pack 过的不能直接的  istr>> out.pid , 需要一个临时变量
	int tmp;
	if(!(istr >> tmp))
	{
		return 0;
	}
	out.pid=tmp;

	//PPID	
	if(!( istr >> tmp))
	{
		return 0;
	}
	out.ppid=tmp;

	//C PRI NI ADDR SZ	
	for(i=0; i<5; i++)
	{
		if(!(istr >> null))
		{
			return 0;
		}
	}

	out.elapsed_time=0;
	int time_sec;

    out.elapsed_time = sysinfo_time.proc_run_time(out.pid);		//获取进程时间填充elapsed_time

	//WCHAN
	string wchan;
	if(!(istr >> wchan))
	{
		return 0;
	}
	//存在隐患. 
	//memcpy(out.WCHAN, wchan.c_str(), wchan.size());
	strncpy(out.WCHAN, wchan.c_str(), sizeof(out.WCHAN));

	if(!(istr>>null))//STIME
	{
		return 0;
	}
	if(!(istr>>null )) //TTY
	{
		return 0;
	}

	if(!(istr>>null )) //TIME
	{
		return 0;
	}
	//CMDLINE
	string cmdline;
	if(!(istr>>cmdline )) //cmdline 的一个单词 
	{
		return 0;
	}

	while( istr>>null)
	{
		cmdline+=" ";
		cmdline+=null;
	}
	string result=trim<char>(cmdline);
	//memcpy(out.cmdline, result.c_str(), sizeof(out.cmdline));
	//最后一个字符设置成null.
	strncpy(out.cmdline, result.c_str(), sizeof(out.cmdline));

	return 1;
}

//========================================================================
//502
int Cmd_str_to_struct::change(const string &in , response_502  &out)
{
	return 1;
}

//========================================================================
//503
int Cmd_str_to_struct::change(const string &in , response_503  &out)
{
	return 1;
}
//========================================================================
//504
int Cmd_str_to_struct::change(const string &in , response_504  &out)
{
	return 1;
}



//========================================================================
//505 杀死进程.
int Cmd_str_to_struct::change(const string &in , response_505  &out)
{
	return 1;
}


//========================================================================
//程序占用那些文件. 
//lsof -p $pid 
//COMMAND   PID USER   FD      TYPE DEVICE SIZE/OFF NODE NAME
//migration   9 root  cwd       DIR    8,1    12288    2 /
//migration   9 root  rtd       DIR    8,1    12288    2 /
//migration   9 root  txt   unknown                      /proc/9/exe
//
int Cmd_str_to_struct::change(const string &in , response_506  &out)
{


	memset(&out, '\0', sizeof(response_501));

	string 	command;
	string 	pid;
	string 	user;
	string 	fd;
	string 	type;
	string 	device; 
	string 	size_off ;
	string 	node ;
	string 	name;

	istringstream istr;
    istr.str(in);

	if(!(	istr >> command))
	{
		return 0;
	}
	
	//有隐患, 可能会溢出.  
	//memcpy(out.prog_name, command.c_str(), command.size());	
	strncpy(out.prog_name, command.c_str(), sizeof(out.prog_name));	

	int tmp;
	
	if(!(istr >>tmp))
	{
		return 0;
	}
	out.pid=tmp;
	
	if(!(istr >>user))
	{
		return 0;
	}
	if(!(istr >>fd))
	{
		return 0;
	}
	if(!(istr>> type))
	{
		return 0;
	}
	if(!(istr >> device))
	{
		return 0;
	}
	if(!(istr >> size_off))
	{
		return 0;
	}
	if(!(istr >> node))
	{
		return 0;
	}

	if(!(istr >> name))
	{
		return 0;
	}
	//有隐患 可能会溢出.
	//memcpy(out.filename, name.c_str(), name.size());
	strncpy(out.filename, name.c_str(), sizeof(out.filename));

	return 1;
}

//========================================================================
//启动.
int Cmd_str_to_struct::change(const string &in , response_507  &out)
{
	return 1;
}

//========================================================================
//关闭
int Cmd_str_to_struct::change(const string &in , response_508  &out)
{
	return 1;
}

//========================================================================
//重启
int Cmd_str_to_struct::change(const string &in , response_509  &out)
{
	return 1;
}

//========================================================================
//刷新
int Cmd_str_to_struct::change(const string &in , response_510  &out)
{
	return 1;
}

//========================================================================
//获取日志.
int Cmd_str_to_struct::change(const string &in , response_511  &out)
{
	return 1;
}

//========================================================================
//某文件谁在占用 
// fuser /dev/urandom  -v
// fuser -v  /  -c
//
//                     USER        PID ACCESS COMMAND
// /dev/urandom:       root       1445 f.... cupsd
//                     root       4871 f.... gnome-keyring-d
//                     root       4953 f.... python
//                     root       4984 f.... gnote

class equal_user
	{
	private:
		string user;
	public:
		equal_user(string tmp):user(tmp){};
		bool operator  () (  string &a)
		{
			if( user == a )
			{
				return true;
			}
			else
			{
				return false;
			}
			//return (user.find(a)!=-1);
		}
	};

int Cmd_str_to_struct::change(const string &in , response_512  &out)
{

	
	static vector<string> vec_users;
	//vector<string> vec_users;
	if( vec_users.size() == 0)
	{
		log::Instance()->logger("用户数值为0 , 开始初始化\n");
		get_all_user(vec_users);
	}
	istringstream istr;
    istr.str(in);
	string user;
	string pid;
	string access;
	string command;

	if(!(istr>> user))
	{
		return 0;
	}
	
	
	// if(user=="USER")
	// {
	// 	return 0;
	// }
	//是fuser -v 输出的第二行. 
	if(user[0]=='/')
	{
		if(!(istr>> user))
		{
			return 0;
		}
	}

	if( find_if(vec_users.begin(), vec_users.end(),  equal_user(user)) == vec_users.end())
	{
		//cout<<"root 不存在"<<endl;
		log::Instance()->logger("%s 这个用户不存在,这行 %s 略过, 置空\n", user.c_str(), in.c_str());
		memset(&out, '\0', sizeof(out));
		return 1;
	}

	strncpy(out.user, user.c_str(), sizeof(out.user));

	int pid_tmp=0;
	if(!(istr>> pid_tmp))
	{
		return 0;
	}
	out.pid=pid_tmp;
	
	if(!(istr>>access))
	{
		return 0;
	}
	strncpy(out.access, access.c_str(), sizeof(out.access));

	if(!(istr>>command))
	{
		return 0;
	}
	strncpy(out.command, command.c_str(), sizeof(out.command));

	return 1;
}

//========================================================================
//core dump
int Cmd_str_to_struct::change(const string &in , response_513  &out)
{
	return 1;
}

//########################################################################
//########################################################################
//########################################################################
//########################################################################
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_501>  &out)
{
	response_501 tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}
//------------------------------------------------------------------------
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_502>  &out)
{
	response_502 tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}
//------------------------------------------------------------------------
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_503>  &out)
{
	response_503 tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}
//------------------------------------------------------------------------
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_504>  &out)
{
	response_504 tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_505>  &out)
{
	response_505  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_506>  &out)
{
	response_506  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_507>  &out)
{
	response_507  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_508>  &out)
{
	response_508  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}


//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_509>  &out)
{
	response_509  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_510>  &out)
{
	response_510  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_511>  &out)
{
	response_511  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}

//========================================================================
int Cmd_str_to_struct::change_2_vec(const vector<string> &in , vector<response_512>  &out)
{
	response_512  tmp;
	vector<string>::const_iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		change(*it , tmp);
		out.push_back(tmp);
	}
	return 1;
}


//########################################################################
//########################################################################
//########################################################################
//########################################################################

//====================================================================================================================
//客户端列表. 
char * 	Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_501>  &in,  int &out_len)
{

	size_t size=0;
	size=in.size() * sizeof(response_501);

	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 501 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}
	memset(sendbuf, 0, size);

	out_len=0;
	vector<response_501>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_501));
		pointer += sizeof(response_501);
		out_len+= sizeof(response_501);
	}

	return sendbuf;
}
//------------------------------------------------------------------------
char * 	Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_502>  &in,  int &out_len)
{
		return NULL;
}

//------------------------------------------------------------------------
char * 	Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_503>  &in,  int &out_len)
{
		return NULL;
}

//------------------------------------------------------------------------
char * 	Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_504>  &in,  int &out_len)
{
		return NULL;
}
//========================================================================
//杀死进程.
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_505>  &in,  int &out_len)
{

	size_t size=0;
	out_len=0;
	size=in.size() * sizeof(response_505);
	if(0 == size)
	{
		return NULL;
	}
	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 505 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}

	memset(sendbuf, 0, size);

	vector<response_505>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_505));
		pointer += sizeof(response_505);
		out_len+=sizeof(response_505);
	}

	return sendbuf;
}
//========================================================================
//程序占用那些文件.
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_506>  &in,  int &out_len)
{

	size_t size=0;
	out_len=0;
	size=in.size() * sizeof(response_506);

	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 506 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}

	memset(sendbuf, 0, size);

	vector<response_506>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_506));
		pointer += sizeof(response_506);
		out_len+= sizeof(response_506);
	}

	return sendbuf;
}

//========================================================================
//启动.
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_507>  &in,  int &out_len) 
{

	size_t size=0;
	size=in.size() * sizeof(response_507);
	if(0==size)
	{
		return NULL;
	}
	char*  sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 507 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}
	
	out_len=0;
	memset(sendbuf, 0, size);

	vector<response_507>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_507));
		pointer += sizeof(response_507);
		out_len += sizeof(response_507);
	}

	return sendbuf;
}

//========================================================================
//关闭.
char *	Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_508>  &in,  int &out_len)
{

	size_t size=0;
	size=in.size() * sizeof(response_508);
	if(0 == size)
	{
		return NULL;
	}
	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 508 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}

	memset(sendbuf, 0, size);
	out_len=0;

	vector<response_508>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_508));
		pointer += sizeof(response_508);
		out_len	+= sizeof(response_508);
	}

	return sendbuf;
}

//========================================================================
//重启.
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_509>  &in,  int &out_len)
{
	size_t size=0;
	out_len=0;
	size=in.size() * sizeof(response_509);
	if(size==0)
	{
		return NULL;
	}

	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 501 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}

	memset(sendbuf, 0, size);

	vector<response_509>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_509));
		pointer += sizeof(response_509);
		out_len += sizeof(response_509);
	}

	return sendbuf;
}

//========================================================================
//刷新.
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_510>  &in,  int &out_len)
{
	size_t size=0;
	size=in.size() * sizeof(response_510);
	if(0 == size)
	{
		return NULL;
	}
	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 510 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}

	memset(sendbuf, 0, size);
	out_len=0;

	vector<response_510>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_510));
		pointer += sizeof(response_510);
		out_len += sizeof(response_510);
	}

	return sendbuf;
}

//========================================================================
//获取日志.
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_511>  &in, int &out_len)
{

	size_t size=0;
	size=in.size() * sizeof(response_511);
	if(0 == size)
	{
		return NULL;
	}
	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 511 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}
	out_len=0;
	memset(sendbuf, 0, size);

	vector<response_511>::const_iterator it;
	int pointer = 0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_511));
		pointer += sizeof(response_511);
		out_len += sizeof(response_511);
	}

	return sendbuf;
}

//========================================================================
//某文件谁在占用. 
char *Cmd_str_to_struct::change_vec_to_net_buffer(const vector<response_512>  &in,  int &out_len)
{
	size_t size=0;
	size=in.size() * sizeof(response_512);

	char *sendbuf=new char[size];
	if(sendbuf==NULL)
	{
		log::Instance()->logger("PANIC: 501 vec_to_net_buf 内存不足, die.\n");
		exit(-1);
	}

	memset(sendbuf, 0, size);

	vector<response_512>::const_iterator it;
	int pointer = 0;
	out_len=0;

	for (it = in.begin(); it != in.end(); it++)
	{
		memcpy(sendbuf + pointer, &(*it), sizeof(response_512));
		pointer += sizeof(response_512);
		out_len+=  sizeof(response_512);
	}

	return sendbuf;
}

//########################################################################
//######################################################################
//######################################################################
//########################################################################

 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_501> &out )
{
	out.clear();
	int pointer = 0;
	response_501 tmp;

	assert((len%sizeof(response_501)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_501); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_501));	
		pointer += sizeof(response_501);
		out.push_back(tmp);
	}
	return 1;
}

 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_502> &out )
{
	out.clear();
	int pointer = 0;
	response_502 tmp;

	assert((len%sizeof(response_502)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_502); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_502));	
		pointer += sizeof(response_502);
		out.push_back(tmp);
	}
	return pointer;
}
 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_503> &out )
{
	out.clear();
	int pointer = 0;
	response_503 tmp;

	assert((len%sizeof(response_503)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_503); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_503));	
		pointer += sizeof(response_503);
		out.push_back(tmp);
	}
	return pointer;
}

 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_504> &out )
{
	out.clear();
	int pointer = 0;
	response_504 tmp;

	assert((len%sizeof(response_504)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_504); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_504));	
		pointer += sizeof(response_504);
		out.push_back(tmp);
	}
	return pointer;
}



 int  Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_505> &out )
{
	out.clear();
	int pointer = 0;
	response_505 tmp;

	assert((len%sizeof(response_505)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_505); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_505));	
		pointer += sizeof(response_505);
		out.push_back(tmp);
	}
	return pointer;
}


 int Cmd_str_to_struct::net_buf_to_vec (char *netbuf, int len, vector<response_506> &out )
{
	out.clear();
	int pointer = 0;
	response_506 tmp;

	assert((len%sizeof(response_506)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_506); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_506));	
		pointer += sizeof(response_506);
		out.push_back(tmp);
	}
	return 1;
}


 int  Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_507> &out )
{
	out.clear();
	int pointer = 0;
	response_507 tmp;

	assert((len%sizeof(response_507)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_507); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_507));	
		pointer += sizeof(response_507);
		out.push_back(tmp);
	}
	return pointer;
}


 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_508> &out )
{
	out.clear();
	int pointer = 0;
	response_508 tmp;

	assert((len%sizeof(response_508)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_508); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_508));	
		pointer += sizeof(response_508);
		out.push_back(tmp);
	}
	return pointer;
}


 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_509> &out )
{
	out.clear();
	int pointer = 0;
	response_509 tmp;

	assert((len%sizeof(response_509)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_509); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_509));	
		pointer += sizeof(response_509);
		out.push_back(tmp);
	}
	return pointer;
}


 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_510> &out )
{
	out.clear();
	int pointer = 0;
	response_510 tmp;

	assert((len%sizeof(response_510)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_510); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_510));	
		pointer += sizeof(response_510);
		out.push_back(tmp);
	}
	return pointer;
}


 int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_511> &out )
{
	out.clear();
	int pointer = 0;
	response_511 tmp;

	assert((len%sizeof(response_511)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_511); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_511));	
		pointer += sizeof(response_511);
		out.push_back(tmp);
	}
	return pointer;
}


int Cmd_str_to_struct::net_buf_to_vec(char *netbuf, int len, vector<response_512> &out )
{
	out.clear();
	int pointer = 0;
	response_512 tmp;

	assert((len%sizeof(response_512)) == 0);
	for(unsigned int i=0; i<len/sizeof(response_512); i++)
	{
		memcpy(&tmp,netbuf + pointer,sizeof(response_512));	
		pointer += sizeof(response_512);
		out.push_back(tmp);
	}
	return 1;
}
