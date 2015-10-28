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
#include <sstream>
#include "protocol.h"
#include "../data_engine/data_define.h"

using namespace std;

template <class T>stringstream&  dump_type_to_istream(stringstream &str, T &in)
{
	return str;
} 

template<> 
stringstream & dump_type_to_istream(stringstream &str,int &in)
{
	str<<"int"<<in<<endl;
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,REQUEST  &in)
{
	str  << "mark=" << in.mark<<"|";
	str  << "size=" << in.size<<"|";
	str  << "main_function=" << in.main_function<<"|";
	str  << "sub_function=" << in.sub_function<<"|";
	str  << "reverse=" << string(in.reverse)<<"|";
	//str  << "data=" << string(in.data)<<"|";
	str<<"|";
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,IPXADDR  &in)
{
	str  << "network=" << in.network<<"|";
	str  << "node=" << string(in.node)<<"|";
	str  << "sock=" << in.sock<<"|";
	str  << "reverse=" << string(in.reverse)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,WKSINFO  &in)
{
	str  << "login_time=" << in.login_time<<"|";
	str  << "conn_id=" << in.conn_id<<"|";
	str  << "nwconn_pid=" << in.nwconn_pid<<"|";
	str  << "username=" << string(in.username)<<"|";
	str  << "reverse=" << string(in.reverse)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,NWCONN_INFO  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,FRAME  &in)
{
	str  << "data[MAX_FRAME_DATA_SIZE]=" << in.data[MAX_FRAME_DATA_SIZE]<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,BaseInfo  &in)
{
	str  << "server_name=" << string(in.server_name)<<"|";
	str  << "status=" << in.status<<"|";
	str  << "inner_network=" << string(in.inner_network)<<"|";
	str  << "inner_node=" << string(in.inner_node)<<"|";
	str  << "ex_network=" << string(in.ex_network)<<"|";
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "frame_type=" << string(in.frame_type)<<"|";
	str  << "reverse=" << string(in.reverse)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,Workstation  &in)
{
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "inner_network=" << string(in.inner_network)<<"|";
	str  << "status=" << in.status<<"|";
	str  << "connect_time=" << in.connect_time<<"|";
	str  << "cur_used_file=" << string(in.cur_used_file)<<"|";
	str  << "reverse=" << string(in.reverse)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,nw_process  &in)
{
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "inner_network=" << string(in.inner_network)<<"|";
	str  << "status=" << in.status<<"|";
	str  << "reverse=" << string(in.reverse)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_1_to_402  &in)
{
	str  << "item=" << string(in.item)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_501  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "node_addr=" << string(in.node_addr)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_505  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "node_addr=" << string(in.node_addr)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_506  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "node_addr=" << string(in.node_addr)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_507  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_508  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_509  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_510  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_511  &in)
{
	str  << "filename=" << string(in.filename)<<"|";
	str  << "start_time=" << in.start_time<<"|";
	str  << "end_time=" << in.end_time<<"|";
	str  << "pttern=" << string(in.pttern)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_512  &in)
{
	str  << "filename=" << string(in.filename)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,request_513  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  << "mac_addr=" << string(in.mac_addr)<<"|";
	str  << "node_addr=" << string(in.node_addr)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,tagResult  &in)
{
	str  << "frame_count=" << in.frame_count<<"|";
	str <<"cur_frame="<< in.cur_frame<<"|";
	str  << "result=" << in.result<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_1_to_402  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_501  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  << "ppid=" << in.ppid<<"|";
	str  << "WCHAN=" << string(in.WCHAN)<<"|";
	str  << "elapsed_time=" << in.elapsed_time<<"|";
	str  << "cmdline=" << string(in.cmdline)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_505  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_506  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  << "prog_name=" << string(in.prog_name)<<"|";
	str  << "filename=" << string(in.filename)<<"|";
	str << "|";
	//str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_507  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_508  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_509  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_510  &in)
{
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_511  &in)
{
/*			char 		filename[256]; 
			int         log_time;    //...
			int         log_length;	//日志的长度
			char        log_data[0]; 后面的都是日志，偏移log_length
*/
	str  << "filename=" << string(in.filename)<<"|";
	str  << "log_time=" << in.log_time<<"|";
	str  << "log_length="<<in.log_length<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_512  &in)
{
	str  << "pid=" << in.pid<<"|";
	str  <<"user="<<string(in.user)<<"|";
	str  <<"access="<<string(in.access)<<"|";
	str  << "prog_name=" << string(in.command)<<"|";
	str<<"|";
	return str;
};
template<> stringstream& dump_type_to_istream(stringstream &str,response_513  &in)
{
	str  << "core_dump_filename=" << string(in.core_dump_filename)<<"|";
	str<<"|";
	return str;
};
//########################################################################
//########################################################################
//########################################################################
//########################################################################
//########################################################################
// 注意 流不能 str << endl; 就把流清空掉了. 
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_501>  &in)
{
	vector<response_501>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str, *it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_502>  &in)
{
	vector<response_502>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_503>  &in)
{
	vector<response_503>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_504>  &in)
{
	vector<response_504>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}

template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_505>  &in)
{
	vector<response_505>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_506>  &in)
{
	vector<response_506>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}

template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_507>  &in)
{
	vector<response_507>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_508>  &in)
{
	vector<response_508>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_509>  &in)
{
	vector<response_509>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_510>  &in)
{
	vector<response_510>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_511>  &in)
{
	vector<response_511>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_512>  &in)
{
	vector<response_512>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
template<> stringstream& dump_type_to_istream(stringstream &str,vector<response_513>  &in)
{
	vector<response_513>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type_to_istream<>(str,*it);
	}
	return str;
}
