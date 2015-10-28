/****************************************************************************
* Description	���ݴ������й��� ,��ͬ����ϵ�ת��.  ����_ascii  ת �����ṹ;  veoctor<����> ת vector<�����ṹ> ; vector<�����ṹ> ת char * 
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
//�������� �е�һ�� ת struct
public:
	Cmd_str_to_struct();

	static int 	change(const string &in , response_501  &out); //�ͻ����б�. 
	static int 	change(const string &in , response_502  &out);  
	static int 	change(const string &in , response_503  &out);  
	static int 	change(const string &in , response_504  &out);  
	static int 	change(const string &in , response_505  &out); //ɱ������.
	static int 	change(const string &in , response_506  &out); //����ռ����Щ�ļ�.
	static int 	change(const string &in , response_507  &out); //����.
	static int 	change(const string &in , response_508  &out); //�ر�.
	static int 	change(const string &in , response_509  &out); //����.
	static int 	change(const string &in , response_510  &out); //ˢ��.
	static int 	change(const string &in , response_511  &out); //��ȡ��־.
	static int 	change(const string &in , response_512  &out); //ĳ�ļ�˭��ռ��. 
	static int 	change(const string &in , response_513  &out); //core dump 

//�����е����е�ת ���������������. 
public:
	static int 	change_2_vec(const vector<string> &in , vector<response_501>  &out); //�ͻ����б�. 
	static int 	change_2_vec(const vector<string> &in , vector<response_502>  &out); 
	static int 	change_2_vec(const vector<string> &in , vector<response_503>  &out); 
	static int 	change_2_vec(const vector<string> &in , vector<response_504>  &out); 
	static int 	change_2_vec(const vector<string> &in , vector<response_505>  &out); //ɱ������.
	static int 	change_2_vec(const vector<string> &in , vector<response_506>  &out); //����ռ����Щ�ļ�.
	static int  change_2_vec_from_procfd(const vector<string>&in,vector<response_506>&out);
	static int 	change_2_vec(const vector<string> &in , vector<response_507>  &out); //����.
	static int 	change_2_vec(const vector<string> &in , vector<response_508>  &out); //�ر�.
	static int 	change_2_vec(const vector<string> &in , vector<response_509>  &out); //����.
	static int 	change_2_vec(const vector<string> &in , vector<response_510>  &out); //ˢ��.
	static int 	change_2_vec(const vector<string> &in , vector<response_511>  &out); //��ȡ��־.
	static int 	change_2_vec(const vector<string> &in , vector<response_512>  &out); //ĳ�ļ�˭��ռ��. 
	static int 	change_2_vec(const vector<string> &in , vector<response_513>  &out); // core dump 


//������������� ת�� buffer ���ڴ���. 
public:
	 static char *	change_vec_to_net_buffer(const vector<response_501>  &in,  int&out_len); //�ͻ����б�. 
	 static char *	change_vec_to_net_buffer(const vector<response_502>  &in,  int&out_len); 
	 static char *	change_vec_to_net_buffer(const vector<response_503>  &in,  int&out_len); 
	 static char *	change_vec_to_net_buffer(const vector<response_504>  &in,  int&out_len); 
	 static char *	change_vec_to_net_buffer(const vector<response_505>  &in,  int&out_len); //ɱ������.
	 static char *	change_vec_to_net_buffer(const vector<response_506>  &in,  int&out_len); //����ռ����Щ�ļ�.
	 static char *	change_vec_to_net_buffer(const vector<response_507>  &in,  int&out_len); //����.
	 static char *	change_vec_to_net_buffer(const vector<response_508>  &in,  int&out_len); //�ر�.
	 static char *	change_vec_to_net_buffer(const vector<response_509>  &in,  int&out_len); //����.
	 static char *	change_vec_to_net_buffer(const vector<response_510>  &in,  int&out_len); //ˢ��.
	 static char *	change_vec_to_net_buffer(const vector<response_511>  &in,  int&out_len); //��ȡ��־.
	 static char *	change_vec_to_net_buffer(const vector<response_512>  &in,  int&out_len); //ĳ�ļ�˭��ռ��. 
	 static char *	change_vec_to_net_buffer(const vector<response_513>  &in,  int&out_len); //coredump 

//��buffer ������ �ٷ���������������ݱ���������֤. 
public:

	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_501> &out ); //�ͻ����б�.
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_502> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_503> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_504> &out );	
	static 	int net_buf_to_vec(char *netbuf, int len, vector<response_505> &out ); //ɱ��.
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

