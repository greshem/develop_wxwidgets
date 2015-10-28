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
#include <wx/dir.h>

//wxDir::Exists(wxString const&)
//wxDir::FindFirst(wxString const&, wxString const&, int)
//wxDir::GetAllFiles(wxString const&, wxArrayString*, wxString const&, int)
//wxDir::GetFirst(wxString*, wxString const&, int) const
//wxDir::GetName() const
//wxDir::GetNext(wxString*) const
//wxDir::GetTotalSize(wxString const&, wxArrayString*)
//wxDir::HasFiles(wxString const&)
//wxDir::HasSubDirs(wxString const&)
//wxDir::IsOpened() const
//wxDir::Open(wxString const&)
//wxDir::Traverse(wxDirTraverser&, wxString const&, int) const
//wxDir::~wxDir()
//wxDir::wxDir(wxString const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxDir");
	wxString wxLogo(_T("wxDir"));
	
	//wxDateTime  tm(time(NULL));
	//wxDir  a(_T("/etc/"));
	wxDir  a;
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
