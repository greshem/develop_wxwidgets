#include "protocol.h"
template <class T>void  specific_value( T &in)
{
} 

template<> void  specific_value(int &in)
{
	in=1111;
}
template<> void specific_value(REQUEST  &in)
{
	in.mark=11111 ;
	in.size=11111 ;
	in.main_function=11111 ;
	in.sub_function=11111 ;
	memset(in.reverse, '1', sizeof(in.reverse));
	#ifdef WINDOWSCODE
	#else
	memset(in.data, '1', sizeof(in.data));
	#endif
};
template<> void specific_value(IPXADDR  &in)
{
	in.network=11111 ;
	memset(in.node, '1', sizeof(in.node));
	in.sock=11111 ;
	memset(in.reverse, '1', sizeof(in.reverse));
};
template<> void specific_value(WKSINFO  &in)
{
	in.login_time=11111 ;
	in.conn_id=11111 ;
	in.nwconn_pid=11111 ;
	memset(in.username, '1', sizeof(in.username));
	memset(in.reverse, '1', sizeof(in.reverse));
};
template<> void specific_value(NWCONN_INFO  &in)
{
};
template<> void specific_value(FRAME  &in)
{
	in.data[MAX_FRAME_DATA_SIZE]=11111 ;
};
template<> void specific_value(BaseInfo  &in)
{
	memset(in.server_name, '1', sizeof(in.server_name));
	in.status=11111 ;
	memset(in.inner_network, '1', sizeof(in.inner_network));
	memset(in.inner_node, '1', sizeof(in.inner_node));
	memset(in.ex_network, '1', sizeof(in.ex_network));
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.frame_type, '1', sizeof(in.frame_type));
	memset(in.reverse, '1', sizeof(in.reverse));
};
template<> void specific_value(Workstation  &in)
{
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.inner_network, '1', sizeof(in.inner_network));
	in.status=11111 ;
	in.connect_time=11111 ;
	memset(in.cur_used_file, '1', sizeof(in.cur_used_file));
	memset(in.reverse, '1', sizeof(in.reverse));
};
template<> void specific_value(nw_process  &in)
{
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.inner_network, '1', sizeof(in.inner_network));
	in.status=11111 ;
	memset(in.reverse, '1', sizeof(in.reverse));
};
template<> void specific_value(request_1_to_402  &in)
{
	memset(in.item, '1', sizeof(in.item));
};
template<> void specific_value(request_501  &in)
{
	in.pid=11111 ;
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.node_addr, '1', sizeof(in.node_addr));
};
template<> void specific_value(request_505  &in)
{
	in.pid=11111 ;
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.node_addr, '1', sizeof(in.node_addr));
};
template<> void specific_value(request_506  &in)
{
	in.pid=11111 ;
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.node_addr, '1', sizeof(in.node_addr));
};
template<> void specific_value(request_507  &in)
{
};
template<> void specific_value(request_508  &in)
{
};
template<> void specific_value(request_509  &in)
{
};
template<> void specific_value(request_510  &in)
{
};
template<> void specific_value(request_511  &in)
{
	//in.log_type=11111 ;
	memset(in.filename,'\0', sizeof(in.filename)-1);	
	memset(in.filename, 'a', sizeof(in.filename)-1);	
	in.start_time=11111 ;
	in.end_time=11111 ;
	memset(in.pttern, '1', sizeof(in.pttern));
};
template<> void specific_value(request_512  &in)
{
	memset(in.filename, '1', sizeof(in.filename));
};
template<> void specific_value(request_513  &in)
{
	in.pid=11111 ;
	memset(in.mac_addr, '1', sizeof(in.mac_addr));
	memset(in.node_addr, '1', sizeof(in.node_addr));
};
template<> void specific_value(tagResult  &in)
{
	in.frame_count=11111 ;
	in.result=11111 ;
};
template<> void specific_value(response_1_to_402  &in)
{
};
template<> void specific_value(response_501  &in)
{
	in.pid=11111 ;
	in.ppid=11111 ;
	memset(in.WCHAN, '1', sizeof(in.WCHAN));
	in.elapsed_time=11111 ;
	memset(in.cmdline, '1', sizeof(in.cmdline));
};
template<> void specific_value(response_505  &in)
{
};
template<> void specific_value(response_506  &in)
{
	in.pid=11111 ;
	memset(in.prog_name, '1', sizeof(in.prog_name));
	memset(in.filename, '1', sizeof(in.filename));
};
template<> void specific_value(response_507  &in)
{
};
template<> void specific_value(response_508  &in)
{
};
template<> void specific_value(response_509  &in)
{
};
template<> void specific_value(response_510  &in)
{
};
template<> void specific_value(response_511  &in)
{
//	in.frame_count=11111 ;
//	in.cur_frame=11111 ;
//	in.logfile_type = 0;
	
	memset(in.filename,'\0', sizeof(in.filename)-1);	
	memset(in.filename, 'a', sizeof(in.filename)-1);
	in.log_length = 0;
};
template<> void specific_value(response_512  &in)
{
	in.pid=11111 ;
	memset(in.command, '1', sizeof(in.command));
};
template<> void specific_value(response_513  &in)
{
	memset(in.core_dump_filename, '1', sizeof(in.core_dump_filename));
};
