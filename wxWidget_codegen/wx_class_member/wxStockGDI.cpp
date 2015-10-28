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
//wxStockGDI::DeleteAll()
wxStockGDI::GetBrush(wxStockGDI::Item)
wxStockGDI::GetColour(wxStockGDI::Item)
wxStockGDI::GetCursor(wxStockGDI::Item)
wxStockGDI::GetFont(wxStockGDI::Item)
wxStockGDI::GetPen(wxStockGDI::Item)
wxStockGDI::~wxStockGDI()
wxStockGDI::wxStockGDI()


using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxStockGDI.cpp");
	wxString wxLogo(_T("wxStockGDI.cpp"));
	
	wxDateTime  tm(time(NULL));
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
