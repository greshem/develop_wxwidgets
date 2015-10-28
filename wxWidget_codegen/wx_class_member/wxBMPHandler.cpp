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
//wxBMPHandler::DoCanRead(wxInputStream&)
//wxBMPHandler::DoLoadDib(wxImage*, int, int, int, int, int, long, wxInputStream&, bool, bool, bool)
//wxBMPHandler::GetClassInfo() const
//wxBMPHandler::LoadDib(wxImage*, wxInputStream&, bool, bool)
//wxBMPHandler::LoadFile(wxImage*, wxInputStream&, bool, int)
//wxBMPHandler::SaveDib(wxImage*, wxOutputStream&, bool, bool, bool)
//wxBMPHandler::SaveFile(wxImage*, wxOutputStream&, bool)
//wxBMPHandler::wxCreateObject()
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxBMPHandler");
	wxString wxLogo(_T("wxBMPHandler"));
	
	//wxDateTime  tm(time(NULL));
	wxBMPHandler  a;
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
