#ifdef WINDOWSCODE
#define snprintf _snprintf
#define access _access
#define mkdir _mkdir
#include <windows.h>
#include <io.h>
#include <direct.h>
#else
#endif
#include "log.h"
#include "tools.h"
#include <algorithm>
#include <fstream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <vector> 

class log* log::m_data = NULL;
FILE *log::m_fp =NULL;
log::log(string filename=string("all.log"))
{
	int ret = access("log",0);
	if(ret == -1)
	
	#ifdef WINDOWSCODE
	mkdir("log");
	#else
	mkdir("log", 0777);
	#endif

	if(m_fp==NULL)
	{
		//m_fp=fopen(filename.c_str(), "a"); 
		//��־�ļ��򿪵�ģʽ  ���ļ��Ĵ�С�Ƿ�任������Ե�����, a��ʽ һֱ������, 
	
		if(access("all.log", 0) == 0)
			save_file(); 

		m_fp=fopen(filename.c_str(), "wb");
		if(m_fp==NULL)
		{
			printf("open file error \n");
			exit(-1);
		}
	}
}

void log::save_file()
{
	char file[64];
	int i = 0;

	memset(file, 0, sizeof(file));
	while(1)
	{
		snprintf(file, sizeof(file),  "log/all_%d.log", i);
		//����.
		if(access(file, 0) == 0)		
		{	
			i++;
			continue;
		}
		else
		{
			rename("all.log", file);
			break;
		}
	}
	return;
}

//fixme ���ִ���������, ��������� ��ʱ��ӡ����. 
int log::loggerError(char *format, ...)
{
	int ret_len=fprintf(m_fp,"[����]");
	va_list(marker);
	va_start(marker, format);
	ret_len+= logger(format,marker);
	va_end(marker);
	return ret_len;	
}

//fixme ���ִ���������, ��������� ��ʱ��ӡ����. 
int log::loggerWarn(char *format, ...)
{
	int ret_len=fprintf(m_fp,"[����]");
	va_list(marker);
	va_start(marker, format);
	ret_len+= logger(format,marker);
	va_end(marker);
	return ret_len;
}

//fixme ���ִ���������, ��������� ��ʱ��ӡ����. 
int log::loggerNotice(char *format, ...)
{
	int ret_len=fprintf(m_fp,"[ע��]");
	va_list(marker);
	va_start(marker, format);
	ret_len+= logger(format,marker);
	va_end(marker);
	return ret_len;
}

int log::logger( char *format, ...)
{	

	int string_len=0;
	static char tmp[1024];
	memset(tmp,'\0', sizeof(tmp));
	va_list(marker);
	va_start(marker, format);
	
	//vsprintf(tmp, format, marker);
	vsnprintf(tmp,	sizeof(tmp), format, marker);
	va_end(marker);

	char time_str[256]={0};
    time_t t;
    t=time(NULL);
	#ifdef WINDOWSCODE
	string_len = (int)strftime(time_str, sizeof(time_str), "%Y_%m_%d_%H:%M:%S", localtime(&t));
	#else
    string_len = (int)strftime(time_str, sizeof(time_str), "%Y_%m_%d_%T", localtime(&t));
	#endif
	//snprintf(tmp, sizeof(tmp), "%s: %s",  time_str, tmp);

	string_len+=fprintf(m_fp,"%s: %s",  time_str, tmp);
	// int len=strlen(tmp);
	// int ret=write(fileno(m_fp), tmp, len );
	// if(ret != len)
	// {
	// 	printf("д��ĳ��Ⱥ� �ļ����Ȳ�һ��\n");
	// }
	//
	if(ftell(m_fp)> 1024*1024*1)
	{
	
		fseek(m_fp, 0,SEEK_SET);
		fflush(m_fp);
		if(ftell(m_fp) != 0)
		{
			fprintf(m_fp, "����1M �ļ���λʧ��, \n");
		}
	}
	return string_len;
}


class log* log::Instance()
{
	if(m_data == NULL)//δ����ʼ��
	{ 
		m_data = new log;
	}
	return m_data;
}
