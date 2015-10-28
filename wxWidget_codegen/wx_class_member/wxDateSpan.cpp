#include <stdlib.h>
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
        //exit(-1);
    }
    //printf("%s\n", "wxDateSpan.cpp");
	wxString wxLogo(_T("wxDateSpan.cpp"));
	
	wxDateSpan a(2011, 03, 0, 22); 
	wxDateSpan b(2011, 03, 0, 23); 
	a.Week();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
