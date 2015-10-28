#include <stdlib.h>
//#include <QzjUnit.hpp>
//#include <Baselib.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
//#include <gtest/gtest.h>
//2011_03_09 by greshem. 

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>


using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //#exit(-1);
    }
	char buffer[1024];
    printf("%s\n", "datetime.cpp");
	wxDateTime  tm(time(NULL));
	wxString stime=tm.FormatDate();
		 stime=tm.FormatDate();
	//wxString::Printf(wxT("%s"), stime);
	//stime.Printf(_T("%s"), "qianqian\n");
	//printf("%s\n", stime.ToAscii());	
	strncpy(buffer, stime.mb_str(), sizeof(buffer));
	printf("%s\n", buffer);
	return 0;
}
