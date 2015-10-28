/****************************************************************************
* Description	数据从命令行过来 ,不同层次上的转换.  单行_ascii  转 单个结构;  veoctor<单行> 转 vector<单个结构> ; vector<单个结构> 转 char * 
* @param 	
* @return 	
* @notice 	
****************************************************************************/
#ifndef __CMD_STR_TO_STRUCT_HEADER__
#define __CMD_STR_TO_STRUCT_HEADER__

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
#include "../include/protocol.h"

class Cmd_str_to_struct
{
public:
	//static vector<string> m_vec_users;
//从命令行 中的一行 转 struct
public:
	Cmd_str_to_struct();

	static int 	change(const string &in , response_501  &out); //客户端列表. 
	static int 	change(const string &in , response_502  &out);  
	static int 	change(const string &in , response_503  &out);  
	static int 	change(const string &in , response_504  &out);  
	static int 	change(const string &in , response_505  &out); //杀死进程.
	static int 	change(const string &in , response_506  &out); //程序占用那些文件.
	static int 	change(const string &in , response_507  &out); //启动.
	static int 	change(const string &in , response_508  &out); //关闭.
	static int 	change(const string &in , response_509  &out); //重启.
	static int 	change(const string &in , response_510  &out); //刷新.
	static int 	change(const string &in , response_511  &out); //获取日志.
	static int 	change(const string &in , response_512  &out); //某文件谁在占用. 
	static int 	change(const string &in , response_513  &out); //core dump 

//命令行的所有的转 到容器里面的数据. 
public:
	static int 	change_2_vec(const vector<string> &in , vector<response_501>  &out); //客户端列表. 
	static int 	change_2_vec(const vector<string> &in , vector<response_502>  &out); 
	static int 	change_2_vec(const vector<string> &in , vector<response_503>  &out); 
	static int 	change_2_vec(const vector<string> &in , vector<response_504>  &out); 
	static int 	change_2_vec(const vector<string> &in , vector<response_505>  &out); //杀死进程.
	static int 	change_2_vec(const vector<string> &in , vector<response_506>  &out); //程序占用那些文件.
	static int  change_2_vec_from_procfd(const vector<string>&in,vector<response_506>&out);
	static int 	change_2_vec(const vector<string> &in , vector<response_507>  &out); //启动.
	static int 	change_2_vec(const vector<string> &in , vector<response_508>  &out); //关闭.
	static int 	change_2_vec(const vector<string> &in , vector<response_509>  &out); //重启.
	static int 	change_2_vec(const vector<string> &in , vector<response_510>  &out); //刷新.
	static int 	change_2_vec(const vector<string> &in , vector<response_511>  &out); //获取日志.
	static int 	change_2_vec(const vector<string> &in , vector<response_512>  &out); //某文件谁在占用. 
	static int 	change_2_vec(const vector<string> &in , vector<response_513>  &out); // core dump 


//容器里面的数据 转到 buffer 便于传输. 
public:
	 static char *	change_vec_to_net_buffer(const vector<response_501>  &in,  int&out_len); //客户端列表. 
	 static char *	change_vec_to_net_buffer(const vector<response_502>  &in,  int&out_len); 
	 static char *	change_vec_to_net_buffer(const vector<response_503>  &in,  int&out_len); 
	 static char *	change_vec_to_net_buffer(const vector<response_504>  &in,  int&out_len); 
	 static char *	change_vec_to_net_buffer(const vector<response_505>  &in,  int&out_len); //杀死进程.
	 static char *	change_vec_to_net_buffer(const vector<response_506>  &in,  int&out_len); //程序占用那些文件.
	 static char *	change_vec_to_net_buffer(const vector<response_507>  &in,  int&out_len); //启动.
	 static char *	change_vec_to_net_buffer(const vector<response_508>  &in,  int&out_len); //关闭.
	 static char *	change_vec_to_net_buffer(const vector<response_509>  &in,  int&out_len); //重启.
	 static char *	change_vec_to_net_buffer(const vector<response_510>  &in,  int&out_len); //刷新.
	 static char *	change_vec_to_net_buffer(const vector<response_511>  &in,  int&out_len); //获取日志.
	 static char *	change_vec_to_net_buffer(const vector<response_512>  &in,  int&out_len); //某文件谁在占用. 
	 static char *	change_vec_to_net_buffer(const vector<response_513>  &in,  int&out_len); //coredump 

//从buffer 的数据 再放入容器里面的数据便于数据验证. 
public:

	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_501> &out ); //客户端列表.
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_502> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_503> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_504> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_505> &out ); //杀死.
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_506> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_507> &out );
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_508> &out );
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_509> &out );
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_510> &out );
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_511> &out );
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_512> &out );
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_513> &out );

	public:
	static int get_all_user(vector<string> &out);
};
#endif  //__CMD_STR_TO_STRUCT_HEADER__

