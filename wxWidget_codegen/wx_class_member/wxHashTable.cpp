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
//2011_03_11 by greshem. 

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
//wxHashTable::DoCopy(wxHashTable const&)
//wxHashTable::DoDeleteContents(wxHashTableBase_Node*)
//wxHashTable::GetNextNode(unsigned long)
//wxHashTable::Next()
//wxHashTable::operator=(wxHashTable const&)
//wxHashTable::wxHashTable(wxHashTable const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxHashTable");
	wxString wxLogo(_T("wxHashTable"));
	
	//wxDateTime  tm(time(NULL));
	wxHashTable  a;
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
