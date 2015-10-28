/********************************************************************************************
* Description -  主要用来解析和操作 /etc/nwserv.conf 文件. 暂时没有存储 配置文件的注释的文字. 
* Author -      qianzhongjie@gmail.com
* Date -        2011_03_25_13:23:29
* *******************************************************************************************/
#ifndef __CONF_PARSER_H__
#define __CONF_PARSER_H__
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

using namespace std;


class  nw_conf_parser
{
	private:
		vector< vector<string> > m_data;
		map<int, vector<string> > m_map_data;


	public:
		int parse_file(string file);
		int save_file (string file);
		int  save_file_with_comment(string file);


		int dump();
	
		int  set_item(int main_type, int sub_type, const string & input );
		int  set_item(int main_type, int sub_type, const char * input  );

		string  	get_item(int main_type, int  sub_type);
		int  		get_item(int main_type, int sub_type, string &out); 
		int  		get_item(int main_type, int sub_type, char *out);

		int  add_item(int main_type, int sub_type,  char *content);
		int  add_item(int main_type, int sub_type,  const string & content);

		static int vec_vec_str_to_map(vector<vector<string> >  &in , map<int, vector<string> >  &out);

		static int dump_map(map<int, vector<string> > &in,  ostream &out,  string separator, bool with_comment);
		int check_item(int main_type, int sub_type);

	public:
		vector<int>  get_keys();
		int get_max_sub(int main_type);
};

#define MAIN_NOT_EXIST -1
#define SUB_NOT_EXIST  -2


#endif

