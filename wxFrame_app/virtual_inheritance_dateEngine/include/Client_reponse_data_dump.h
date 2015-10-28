/********************************************************************************************
* Description -  对接受到的包 进行存储, 并供外面调用获取数据, 并验证数据的完整性. 
* 				1-402 协议都放在 nw_conf_parser 类里面.
* 				500-513 之后的数据每个协议 都放在malloc出来的内存. 
* Author -      qianzhongjie@gmail.com
* Date -        2011_04_11_15:16:19
* *******************************************************************************************/
//#include "../../data_engine/log.cpp"
//#include <gtest/gtest.h>
#ifndef CLIENT_REPONSE_DATA_DUMPER_HEADER
#define CLIENT_REPONSE_DATA_DUMPER_HEADER
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
#include "conf_parser.h"
#include "IniFile.hpp"
#include "protocol.h"
#include "Cmd_str_to_struct.h"

//========================================================================
//结构体的定义. 
class Client_reponse_data_dump;
typedef int (Client_reponse_data_dump::*data_dump_fun)(char *, int );

typedef struct _register_data_dump_fun
{
	char function_name[64];
	data_dump_fun fun;
	unsigned long main_function;
	unsigned long sub_function;
}register_data_dump_fun;


//========================================================================
class Client_reponse_data_dump {
private:
	nw_conf_parser  m_conf;
	int 	m_dump_to_stdout; //打印到屏幕
	int 	m_dump_to_file; //打印到文件.
	int		m_Dump;

private:
	char 	*m_501_buffer;
	int		m_501_buffer_len;
	int		m_501_data_len;	
public:
	int		dump_501_data();
	char 	*get_501_data( int &data_len);

private:
	char 	*m_506_buffer;
	int		m_506_buffer_len;
	int		m_506_data_len;	
public:
	int		dump_506_data();
	char 	*get_506_data( int &data_len);

private:
	char 	*m_511_buffer;
	int		m_511_buffer_len;
	int		m_511_data_len;	
	int 	m_511_file_len;
public:
	int		dump_511_data();
	char 	*get_511_data( int &data_len);
private:
	char 	*m_512_buffer;
	int		m_512_buffer_len;
	int		m_512_data_len;	
public:
	int		dump_512_data();
	char 	*get_512_data( int &data_len);
public:
//内部的函数数组
 	int write_to_bin_file(char *filename,  char *data, int data_len);
	static register_data_dump_fun  m_register_data_dump_fun_array[];
	void	setDump(int dump_setting);
	Client_reponse_data_dump();
	~Client_reponse_data_dump();
public:

	int dump_reponse_main_01_VOLUMES(char *data , int data_len);
	int dump_reponse_main_02_SERVERNAME(char *data , int data_len);
	int dump_reponse_main_03_INTERNAL_NETWORK(char *data , int data_len);
	int dump_reponse_main_04_IPX_DEVICES(char *data , int data_len);
	int dump_reponse_main_05_SPECIAL_DEVICEC_FLAGS(char *data , int data_len);
	int dump_reponse_main_06_VERSION_SPOOFING(char *data , int data_len);
	int dump_reponse_main_07_PASSWORD_HANDLEING(char *data , int data_len);
	int dump_reponse_main_08_NOT_USING(char *data , int data_len);
	int dump_reponse_main_09_CREATE_MODE(char *data , int data_len);
	int dump_reponse_main_10_UID_RIGHTS(char *data , int data_len);
	int dump_reponse_main_11_GID_RIGHTS(char *data , int data_len);
	int dump_reponse_main_12_SUPERVISOR_LOGIN(char *data , int data_len);
	int dump_reponse_main_13_USER_LOGIN(char *data , int data_len);
	int dump_reponse_main_14_NOT_USING_14(char *data , int data_len);
	int dump_reponse_main_15_MAPPING_OF_LOGINS(char *data , int data_len);
	int dump_reponse_main_16_TESTS_ON_STARTUP(char *data , int data_len);
	int dump_reponse_main_17_TESTS(char *data , int data_len);
	int dump_reponse_main_18_TESTS(char *data , int data_len);
	int dump_reponse_main_21_NO_SUMMARY_21(char *data , int data_len);
	int dump_reponse_main_22_NO_SUMMARY_22(char *data , int data_len);
	int dump_reponse_main_31_NO_SUMMARY_31(char *data , int data_len);
	int dump_reponse_main_40_NO_SUMMARY_40(char *data , int data_len);
	int dump_reponse_main_41_NO_SUMMARY_41(char *data , int data_len);
	int dump_reponse_main_42_NO_SUMMARY_42(char *data , int data_len);
	int dump_reponse_main_45_NO_SUMMARY_45(char *data , int data_len);
	int dump_reponse_main_46_NO_SUMMARY_46(char *data , int data_len);
	int dump_reponse_main_47_NO_SUMMARY_47(char *data , int data_len);
	int dump_reponse_main_100_NO_SUMMARY_100(char *data , int data_len);
	int dump_reponse_main_101_NO_SUMMARY_101(char *data , int data_len);
	int dump_reponse_main_102_NO_SUMMARY_102(char *data , int data_len);
	int dump_reponse_main_103_NO_SUMMARY_103(char *data , int data_len);
	int dump_reponse_main_104_NO_SUMMARY_104(char *data , int data_len);
	int dump_reponse_main_105_NO_SUMMARY_105(char *data , int data_len);
	int dump_reponse_main_106_NO_SUMMARY_106(char *data , int data_len);
	int dump_reponse_main_200_NO_SUMMARY_200(char *data , int data_len);
	int dump_reponse_main_201_NO_SUMMARY_201(char *data , int data_len);
	int dump_reponse_main_202_NO_SUMMARY_202(char *data , int data_len);
	int dump_reponse_main_210_NO_SUMMARY_210(char *data , int data_len);
	int dump_reponse_main_211_NO_SUMMARY_211(char *data , int data_len);
	int dump_reponse_main_300_NO_SUMMARY_300(char *data , int data_len);
	int dump_reponse_main_301_NO_SUMMARY_301(char *data , int data_len);
	int dump_reponse_main_302_NO_SUMMARY_302(char *data , int data_len);
	int dump_reponse_main_310_NO_SUMMARY_310(char *data , int data_len);
	int dump_reponse_main_400_NO_SUMMARY_400(char *data , int data_len);
	int dump_reponse_main_401_NO_SUMMARY_401(char *data , int data_len);
	int dump_reponse_main_402_NO_SUMMARY_402(char *data , int data_len);

	int dump_reponse_main_501_GET_STATION_LIST(char *data , int data_len);
	int dump_reponse_main_502_NOTIFY_STATION_LOGIN(char *data , int data_len);
	int dump_reponse_main_503_NOTIFY_STATION_LOGOUT(char *data , int data_len);
	int dump_reponse_main_504_NOTIFY_NWCONN_EXITING(char *data , int data_len);
	int dump_reponse_main_505_KILL_NWCONN(char *data , int data_len);
	int dump_reponse_main_506_CURRENT_ACCESS_FILE(char *data , int data_len);
	int dump_reponse_main_507_START_NWSERV(char *data , int data_len);
	int dump_reponse_main_508_STOP_NWSERV(char *data , int data_len);
	int dump_reponse_main_509_RESTART_NWSERV(char *data , int data_len);
	int dump_reponse_main_510_REFRESH_ALL(char *data , int data_len);
	int dump_reponse_main_511_GET_LOG(char *data , int data_len);
	int dump_reponse_main_512_WHO_USE_THIS_FILE(char *data , int data_len);
	int dump_reponse_main_513_GEN_CORE_DUMP(char *data , int data_len);
	int dump_reponse_main_514_NWSERV_IS_OK (char *data , int data_len);
	int dump_reponse_main_515_LOGIN_CHECK_PASSWD (char *data , int data_len);
	int dump_reponse_main_516_GET_SYSTEM_INFO (char *data , int data_len);

	int dump_reponse_main_517_FILE_EXISTS (char *data , int data_len);

public:
 data_dump_fun find_function(unsigned long main, unsigned long sub);
 int dispatch_to_dump(char *data, int length);
private:
	vector<response_501> m_vec_response501;
	vector<response_502> m_vec_response502;
	vector<response_503> m_vec_response503;
	vector<response_504> m_vec_response504;
	vector<response_505> m_vec_response505;
	vector<response_506> m_vec_response506;
	vector<response_507> m_vec_response507;
	vector<response_508> m_vec_response508;
	vector<response_509> m_vec_response509;
	vector<response_510> m_vec_response510;
	vector<response_511> m_vec_response511;
	vector<response_512> m_vec_response512;
	vector<response_513> m_vec_response513;
	vector<response_514> m_vec_response514;
	vector<response_515> m_vec_response515;
	vector<response_516> m_vec_response516;
public:

	void 	 get_vec_response501( vector<response_501> &in);
	void 	 get_vec_response502( vector<response_502> &in);
	void 	 get_vec_response503( vector<response_503> &in);
	void 	 get_vec_response504( vector<response_504> &in);
	void 	 get_vec_response505( vector<response_505> &in);
	void 	 get_vec_response506( vector<response_506> &in);
	void 	 get_vec_response507( vector<response_507> &in);
	void 	 get_vec_response508( vector<response_508> &in);
	void 	 get_vec_response509( vector<response_509> &in);
	void 	 get_vec_response510( vector<response_510> &in);
	void 	 get_vec_response511( vector<response_511> &in);
	void 	 get_vec_response512( vector<response_512> &in);
	void 	 get_vec_response513( vector<response_513> &in);
	void 	 get_vec_response514( vector<response_514> &in);
	void 	 get_vec_response515( vector<response_515> &in);
	void 	 get_vec_response516( vector<response_516> &in);
	
};
#endif  //CLIENT_REPONSE_DATA_DUMPER_HEADER
