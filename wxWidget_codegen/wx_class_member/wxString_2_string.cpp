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
    }
	//1. std::string -> wxString
	string   strstring = "string";
	wxString  wxstr = wxString( strstring.c_str(), wxConvUTF8);

	//2.  wxString -> std::string 
	string tmp(wxstr.mb_str());
	cout<< tmp <<endl;	
	return 0;
}
