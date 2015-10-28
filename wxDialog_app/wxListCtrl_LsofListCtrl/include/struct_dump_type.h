/********************************************************************************************
* Description -  由 gen_struct_dump_type_code.pl  生成 把data[0] 的选项去掉 , 编译不通过.  
* Author -      qianzhongjie@gmail.com
* Date -        2011_04_08_17:20:15
* *******************************************************************************************/
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
#include "../data_engine/data_define.h"
using namespace std;
template <class T>void  dump_type( T &in)
{
} 

template<> void dump_type(int &in)
{
	cout<<"int "<<in<<endl;
}
template<> void dump_type(REQUEST  &in)
{
	cout  << "mark=" << in.mark<<"|";
	cout  << "size=" << in.size<<"|";
	cout  << "main_function=" << in.main_function<<"|";
	cout  << "sub_function=" << in.sub_function<<"|";
	cout  << "reverse=" << string(in.reverse)<<"|";
	//cout  << "data=" << string(in.data)<<"|";
	cout<<endl;
};
template<> void dump_type(IPXADDR  &in)
{
	cout  << "network=" << in.network<<"|";
	cout  << "node=" << string(in.node)<<"|";
	cout  << "sock=" << in.sock<<"|";
	cout  << "reverse=" << string(in.reverse)<<"|";
	cout<<endl;
};
template<> void dump_type(WKSINFO  &in)
{
	cout  << "login_time=" << in.login_time<<"|";
	cout  << "conn_id=" << in.conn_id<<"|";
	cout  << "nwconn_pid=" << in.nwconn_pid<<"|";
	cout  << "username=" << string(in.username)<<"|";
	cout  << "reverse=" << string(in.reverse)<<"|";
	cout<<endl;
};
template<> void dump_type(NWCONN_INFO  &in)
{
	cout<<endl;
};
template<> void dump_type(FRAME  &in)
{
	cout  << "data[MAX_FRAME_DATA_SIZE]=" << in.data[MAX_FRAME_DATA_SIZE]<<"|";
	cout<<endl;
};
template<> void dump_type(BaseInfo  &in)
{
	cout  << "server_name=" << string(in.server_name)<<"|";
	cout  << "status=" << in.status<<"|";
	cout  << "inner_network=" << string(in.inner_network)<<"|";
	cout  << "inner_node=" << string(in.inner_node)<<"|";
	cout  << "ex_network=" << string(in.ex_network)<<"|";
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "frame_type=" << string(in.frame_type)<<"|";
	cout  << "reverse=" << string(in.reverse)<<"|";
	cout<<endl;
};
template<> void dump_type(Workstation  &in)
{
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "inner_network=" << string(in.inner_network)<<"|";
	cout  << "status=" << in.status<<"|";
	cout  << "connect_time=" << in.connect_time<<"|";
	cout  << "cur_used_file=" << string(in.cur_used_file)<<"|";
	cout  << "reverse=" << string(in.reverse)<<"|";
	cout<<endl;
};
template<> void dump_type(nw_process  &in)
{
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "inner_network=" << string(in.inner_network)<<"|";
	cout  << "status=" << in.status<<"|";
	cout  << "reverse=" << string(in.reverse)<<"|";
	cout<<endl;
};
template<> void dump_type(request_1_to_402  &in)
{
	cout  << "item=" << string(in.item)<<"|";
	cout<<endl;
};
template<> void dump_type(request_501  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "node_addr=" << string(in.node_addr)<<"|";
	cout<<endl;
};
template<> void dump_type(request_505  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "node_addr=" << string(in.node_addr)<<"|";
	cout<<endl;
};
template<> void dump_type(request_506  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "node_addr=" << string(in.node_addr)<<"|";
	cout<<endl;
};
template<> void dump_type(request_507  &in)
{
	cout<<endl;
};
template<> void dump_type(request_508  &in)
{
	cout<<endl;
};
template<> void dump_type(request_509  &in)
{
	cout<<endl;
};
template<> void dump_type(request_510  &in)
{
	cout<<endl;
};
template<> void dump_type(request_511  &in)
{
	cout  << "filename=" << string(in.filename)<<"|";
	cout  << "start_time=" << in.start_time<<"|";
	cout  << "end_time=" << in.end_time<<"|";
	cout  << "pttern=" << string(in.pttern)<<"|";
	cout<<endl;
};
template<> void dump_type(request_512  &in)
{
	cout  << "filename=" << string(in.filename)<<"|";
	cout<<endl;
};
template<> void dump_type(request_513  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  << "mac_addr=" << string(in.mac_addr)<<"|";
	cout  << "node_addr=" << string(in.node_addr)<<"|";
	cout<<endl;
};
template<> void dump_type(tagResult  &in)
{
	cout  << "frame_count=" << in.frame_count<<"|";
	cout <<"cur_frame="<< in.cur_frame<<"|";
	cout  << "result=" << in.result<<"|";
	cout<<endl;
};
template<> void dump_type(response_1_to_402  &in)
{
	cout<<endl;
};
template<> void dump_type(response_501  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  << "ppid=" << in.ppid<<"|";
	cout  << "WCHAN=" << string(in.WCHAN)<<"|";
	cout  << "elapsed_time=" << in.elapsed_time<<"|";
	cout  << "cmdline=" << string(in.cmdline)<<"|";
	cout<<endl;
};
template<> void dump_type(response_505  &in)
{
	cout<<endl;
};
template<> void dump_type(response_506  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  << "prog_name=" << string(in.prog_name)<<"|";
	cout  << "filename=" << string(in.filename)<<"|";
	cout<<endl;
};
template<> void dump_type(response_507  &in)
{
	cout<<endl;
};
template<> void dump_type(response_508  &in)
{
	cout<<endl;
};
template<> void dump_type(response_509  &in)
{
	cout<<endl;
};
template<> void dump_type(response_510  &in)
{
	cout<<endl;
};
template<> void dump_type(response_511  &in)
{
/*			char 		filename[256]; 
			int         log_time;    //...
			int         log_length;	//日志的长度
			char        log_data[0]; 后面的都是日志，偏移log_length
*/
	cout  << "filename=" << string(in.filename)<<"|";
	cout  << "log_time=" << in.log_time<<"|";
	cout  << "log_length="<<in.log_length<<"|";
	cout<<endl;
};
template<> void dump_type(response_512  &in)
{
	cout  << "pid=" << in.pid<<"|";
	cout  <<"user="<<string(in.user)<<"|";
	cout  <<"access="<<string(in.access)<<"|";
	cout  << "prog_name=" << string(in.command)<<"|";
	cout<<endl;
};
template<> void dump_type(response_513  &in)
{
	cout  << "core_dump_filename=" << string(in.core_dump_filename)<<"|";
	cout<<endl;
};

template<> void dump_type(vector<response_501>  &in)
{
	vector<response_501>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_502>  &in)
{
	vector<response_502>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_503>  &in)
{
	vector<response_503>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_504>  &in)
{
	vector<response_504>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}

template<> void dump_type(vector<response_505>  &in)
{
	vector<response_505>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_506>  &in)
{
	vector<response_506>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}

template<> void dump_type(vector<response_507>  &in)
{
	vector<response_507>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_508>  &in)
{
	vector<response_508>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_509>  &in)
{
	vector<response_509>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_510>  &in)
{
	vector<response_510>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_511>  &in)
{
	vector<response_511>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_512>  &in)
{
	vector<response_512>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}
template<> void dump_type(vector<response_513>  &in)
{
	vector<response_513>::iterator it;
	for(it=in.begin(); it!= in.end(); it++)
	{
		dump_type<>(*it);
	}
}

