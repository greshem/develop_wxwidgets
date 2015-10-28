//########################################################################
#ifndef __CLIENT_HEADER__
#define __CLIENT_HEADER__

#ifdef WINDOWSCODE
#else
#include <dirent.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stringprep.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <locale.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>

#include "mthread.h"
#include "Client_reponse_data_dump.h"
#include "tcp_client_socket.h"
#include "max_sub_protocol.h"
//#include "../../include/protocol.h"

class Client;
typedef    int (Client::*func_data_process_ptr)(char * , int);

typedef struct _register_data_fun
{
    char function_name[64];
    func_data_process_ptr func;
    unsigned long main_function;
    unsigned long sub_function;
}register_data_fun;

typedef struct _cmd_args
{
	int main_function;
	int sub_function;
	char item[64];
}cmd_args;


class Client 
{

	//网络方面的东西. 
	private:
    	char m_buffer[(4096+sizeof(REQUEST))*2];
		int  m_recved;
		int  m_usec;
		int  m_sec;
	public:
		int		recv();
		int 	have_one_frame();
		int 	get_one_frame(FRAME & frame);
	public:
		int request_template(int main_function , int sub_function, char *data);
	private:
		static register_data_fun  m_register_data_function_array[];
		tcp_client_socket m_tcp_socket;
		max_sub_protocol m_max_sub;

	public:
		Client_reponse_data_dump m_cache;
	public:
		
		int init();
	//多线程方面的东西.
	public: 
		MThread m_recv_thread;
		int init_multi_thread();
		static void * __stdcall recv_thread(void *);


		int release();
		int is_ok();
	public:
		int build_one_frame(int main_function , int sub_function, 	char *data, int data_len, FRAME &out);
		func_data_process_ptr find_function(unsigned long main, unsigned long sub);
		int dispatch(char *in_header, int length);
		int is_readable();
		void set_time_out(int sec=0, int usec=1000)
		{
			m_sec= sec;
			m_usec=usec;
		};
		int recv_one_frame( FRAME &frame);

	public:
	int request_main_01_VOLUMES(char * data, int data_len);
	int request_main_02_SERVERNAME(char *data , int data_len);
	int request_main_03_INTERNAL_NETWORK(char *data , int data_len);
	int request_main_04_IPX_DEVICES(char *data , int data_len);
	int request_main_05_SPECIAL_DEVICEC_FLAGS(char *data , int data_len);
	int request_main_06_VERSION_SPOOFING(char *data , int data_len);
	int request_main_07_PASSWORD_HANDLEING(char *data , int data_len);
	int request_main_08_NOT_USING(char *data , int data_len);
	int request_main_09_CREATE_MODE(char *data , int data_len);
	int request_main_10_UID_RIGHTS(char *data , int data_len);
	int request_main_11_GID_RIGHTS(char *data , int data_len);
	int request_main_12_SUPERVISOR_LOGIN(char *data , int data_len);
	int request_main_13_USER_LOGIN(char *data , int data_len);
	int request_main_14_NOT_USING_14(char *data , int data_len);
	int request_main_15_MAPPING_OF_LOGINS(char *data , int data_len);
	int request_main_16_TESTS_ON_STARTUP(char *data , int data_len);
	int request_main_17_NO_SUMMARY_17(char *data , int data_len);
	int request_main_18_NO_SUMMARY_18(char *data , int data_len);
	int request_main_21_NO_SUMMARY_21(char *data , int data_len);
	int request_main_22_NO_SUMMARY_22(char *data , int data_len);
	int request_main_31_NO_SUMMARY_31(char *data , int data_len);
	int request_main_40_NO_SUMMARY_40(char *data , int data_len);
	int request_main_41_NO_SUMMARY_41(char *data , int data_len);
	int request_main_42_NO_SUMMARY_42(char *data , int data_len);
	int request_main_45_NO_SUMMARY_45(char *data , int data_len);
	int request_main_46_NO_SUMMARY_46(char *data , int data_len);
	int request_main_47_NO_SUMMARY_47(char *data , int data_len);
	int request_main_100_NO_SUMMARY_100(char *data , int data_len);
	int request_main_101_NO_SUMMARY_101(char *data , int data_len);
	int request_main_102_NO_SUMMARY_102(char *data , int data_len);
	int request_main_103_NO_SUMMARY_103(char *data , int data_len);
	int request_main_104_NO_SUMMARY_104(char *data , int data_len);
	int request_main_105_NO_SUMMARY_105(char *data , int data_len);
	int request_main_106_NO_SUMMARY_106(char *data , int data_len);
	int request_main_200_NO_SUMMARY_200(char *data , int data_len);
	int request_main_201_NO_SUMMARY_201(char *data , int data_len);
	int request_main_202_NO_SUMMARY_202(char *data , int data_len);
	int request_main_210_NO_SUMMARY_210(char *data , int data_len);
	int request_main_211_NO_SUMMARY_211(char *data , int data_len);
	int request_main_300_NO_SUMMARY_300(char *data , int data_len);
	int request_main_301_NO_SUMMARY_301(char *data , int data_len);
	int request_main_302_NO_SUMMARY_302(char *data , int data_len);
	int request_main_310_NO_SUMMARY_310(char *data , int data_len);
	int request_main_400_NO_SUMMARY_400(char *data , int data_len);
	int request_main_401_NO_SUMMARY_401(char *data , int data_len);
	int request_main_402_NO_SUMMARY_402(char *data , int data_len);
	int request_main_501_GET_STATION_LIST(char *data , int data_len);
	int request_main_502_NOTIFY_STATION_LOGIN(char *data , int data_len);
	int request_main_503_NOTIFY_STATION_LOGOUT(char *data , int data_len);
	int request_main_504_NOTIFY_NWCONN_EXITING(char *data , int data_len);
	int request_main_505_KILL_NWCONN(char *data , int data_len);
	int request_main_506_CURRENT_ACCESS_FILE(char *data , int data_len);
	int request_main_507_START_NWSERV(char *data , int data_len);
	int request_main_508_STOP_NWSERV(char *data , int data_len);
	int request_main_509_RESTART_NWSERV(char *data , int data_len);
	int request_main_510_REFRESH_ALL(char *data , int data_len);
	int request_main_511_GET_LOG(char *data , int data_len);
	int request_main_512_WHO_USE_THIS_FILE(char *data , int data_len);
	int request_main_513_GEN_CORE_DUMP(char *data , int data_len);
	int request_main_514_NWSERV_IS_OK (char *data , int data_len);

	int request_main_515_LOGIN_CHECK_PASSWD (char *data , int data_len);
	int request_main_516_GET_SYSTEM_INFO (char *data , int data_len);

	int request_main_517_FILE_EXISTS (char *data , int data_len);

};

#endif //__CLIENT_HEADER__

