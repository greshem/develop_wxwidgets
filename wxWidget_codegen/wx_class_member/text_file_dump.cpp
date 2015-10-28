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

#include <wx/textfile.h>


using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        exit(-1);
    }
    //printf("%s\n", "wxTextFile.cpp");
	wxString wxLogo(_T("wxTextFile.cpp"));
	wxString infile(argv[1], wxConvUTF8);
	wxTextFile passwd( infile );
	passwd.Open();
	wxString wxLine;
	for ( wxLine = passwd.GetFirstLine(); !passwd.Eof(); wxLine = passwd.GetNextLine() )
	{
		string str(wxLine.mb_str());
		cout<<str.c_str()<<endl;
	}
	
	wxDateTime  tm(time(NULL));
	return 0;
}
