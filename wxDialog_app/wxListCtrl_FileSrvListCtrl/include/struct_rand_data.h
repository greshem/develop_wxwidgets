#include "protocol.h"
#include "../data_engine/tools.h"
#include "../data_engine/data_define.h"
template <class T>void  rand_data( T &in)
{
} 

template<> void  rand_data(int &in)
{
	in=1111;
}
template<> void rand_data(REQUEST  &in)
{
	in.mark=rand() ;
	in.size=rand() ;
	in.main_function=rand() ;
	in.sub_function=rand() ;
	rand_mem_with_ascii<char> (in.reverse, sizeof(in.reverse));
};
template<> void rand_data(IPXADDR  &in)
{
	in.network=rand() ;
	rand_mem_with_ascii<char> (in.node, sizeof(in.node));
	in.sock=rand() ;
	rand_mem_with_ascii<char> (in.reverse, sizeof(in.reverse));
};
template<> void rand_data(WKSINFO  &in)
{
	in.login_time=rand() ;
	in.conn_id=rand() ;
	in.nwconn_pid=rand() ;
	rand_mem_with_ascii<char> (in.username, sizeof(in.username));
	rand_mem_with_ascii<char> (in.reverse, sizeof(in.reverse));
};
template<> void rand_data(NWCONN_INFO  &in)
{
};
template<> void rand_data(FRAME  &in)
{
	in.data[MAX_FRAME_DATA_SIZE]=rand() ;
};
template<> void rand_data(BaseInfo  &in)
{
	rand_mem_with_ascii<char> (in.server_name, sizeof(in.server_name));
	in.status=rand() ;
	rand_mem_with_ascii<char> (in.inner_network, sizeof(in.inner_network));
	rand_mem_with_ascii<char> (in.inner_node, sizeof(in.inner_node));
	rand_mem_with_ascii<char> (in.ex_network, sizeof(in.ex_network));
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.frame_type, sizeof(in.frame_type));
	rand_mem_with_ascii<char> (in.reverse, sizeof(in.reverse));
};
template<> void rand_data(Workstation  &in)
{
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.inner_network, sizeof(in.inner_network));
	in.status=rand() ;
	in.connect_time=rand() ;
	rand_mem_with_ascii<char> (in.cur_used_file, sizeof(in.cur_used_file));
	rand_mem_with_ascii<char> (in.reverse, sizeof(in.reverse));
};
template<> void rand_data(nw_process  &in)
{
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.inner_network, sizeof(in.inner_network));
	in.status=rand() ;
	rand_mem_with_ascii<char> (in.reverse, sizeof(in.reverse));
};
template<> void rand_data(request_1_to_402  &in)
{
	rand_mem_with_ascii<char> (in.item, sizeof(in.item));
};
template<> void rand_data(request_501  &in)
{
	in.pid=rand() ;
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.node_addr, sizeof(in.node_addr));
};
template<> void rand_data(request_505  &in)
{
	in.pid=rand() ;
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.node_addr, sizeof(in.node_addr));
};
template<> void rand_data(request_506  &in)
{
	in.pid=rand() ;
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.node_addr, sizeof(in.node_addr));
};
template<> void rand_data(request_507  &in)
{
};
template<> void rand_data(request_508  &in)
{
};
template<> void rand_data(request_509  &in)
{
};
template<> void rand_data(request_510  &in)
{
};
template<> void rand_data(request_511  &in)
{
	rand_mem_with_ascii<char> (in.filename, sizeof(in.filename));
	in.start_time=rand() ;
	in.end_time=rand() ;
//	rand_mem_with_ascii<char> (in.pttern, sizeof(in.pttern));
};
template<> void rand_data(request_512  &in)
{
	rand_mem_with_ascii<char> (in.filename, sizeof(in.filename));
};
template<> void rand_data(request_513  &in)
{
	in.pid=rand() ;
	rand_mem_with_ascii<char> (in.mac_addr, sizeof(in.mac_addr));
	rand_mem_with_ascii<char> (in.node_addr, sizeof(in.node_addr));
};
template<> void rand_data(tagResult  &in)
{
	in.frame_count=rand() ;
	in.result=rand() ;
};
template<> void rand_data(response_1_to_402  &in)
{
};
template<> void rand_data(response_501  &in)
{
	in.pid=rand() ;
	in.ppid=rand() ;
	rand_mem_with_ascii<char> (in.WCHAN, sizeof(in.WCHAN));
	in.elapsed_time=rand() ;
	rand_mem_with_ascii<char> (in.cmdline, sizeof(in.cmdline));
};
template<> void rand_data(response_505  &in)
{
};
template<> void rand_data(response_506  &in)
{
	in.pid=rand() ;
	rand_mem_with_ascii<char> (in.prog_name, sizeof(in.prog_name));
	rand_mem_with_ascii<char> (in.filename, sizeof(in.filename));
};
template<> void rand_data(response_507  &in)
{
};
template<> void rand_data(response_508  &in)
{
};
template<> void rand_data(response_509  &in)
{
};
template<> void rand_data(response_510  &in)
{
};
template<> void rand_data(response_511  &in)
{

	rand_mem_with_ascii<char> (in.filename, sizeof(in.filename));
	in.log_length=rand() ;
};
template<> void rand_data(response_512  &in)
{
	in.pid=rand() ;
	rand_mem_with_ascii<char> (in.command, sizeof(in.command));
};
template<> void rand_data(response_513  &in)
{
	rand_mem_with_ascii<char> (in.core_dump_filename, sizeof(in.core_dump_filename));
};
