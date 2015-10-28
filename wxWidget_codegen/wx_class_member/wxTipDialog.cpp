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
#include <wx/wfstream.h>

// 0000000000000360 T wxTipDialog::wxTipDialog(wxWindow*, wxTipProvider*, bool)
// 0000000000000360 T wxTipDialog::wxTipDialog(wxWindow*, wxTipProvider*, bool)
// 0000000000000000 T wxTipDialog::GetEventTable() const
// 0000000000000010 T wxTipDialog::GetEventHashTable() const


using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxTipDialog.cpp");
	wxString wxLogo(_T("wxTipDialog.cpp"));
	
	wxDateTime  tm(time(NULL));
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
