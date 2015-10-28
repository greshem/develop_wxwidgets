#ifndef __LOGGER__HEADER__
#define __LOGGER__HEADER__

//########################################################################
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
 #include <stdarg.h>

using namespace std;

class log
{
private:
static	FILE *m_fp;	
	static log *m_data;

public:
	log(string filename);
	void save_file();
	int logger(char *format, ...);
	int loggerError(char *format, ...);
	int loggerWarn(char *format, ...);
	int loggerNotice(char *format, ...);


	static log *Instance();
};


//fixme �� log::Instance->logger() �滻�� LOG 
#define LOG(fmt, arg) log::Instance()->logger(fmt, ##arg)
#define LOG_WARN(fmt, arg) log::Instance()->logger("����:" fmt, ##arg)
#define LOG_ERROR(fmt, arg) log::Instance()->logger("����:" fmt, ##arg)
#define LOG_NOTICE(fmt, arg) log::Instance()->logger("ע��:" fmt, ##arg)

#endif //__LOGGER__HEADER__

