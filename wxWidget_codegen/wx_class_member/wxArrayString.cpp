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
//wxArrayString::Add(wxString const&, unsigned long)
//wxArrayString::Alloc(unsigned long)
//wxArrayString::assign(wxString const*, wxString const*)
//wxArrayString::Clear()
//wxArrayString::Copy(wxArrayString const&)
//wxArrayString::DoSort()
//wxArrayString::Empty()
//wxArrayString::Free()
//wxArrayString::Grow(unsigned long)
//wxArrayString::Index(wchar_t const*, bool, bool) const
//wxArrayString::Init(bool)
//wxArrayString::Insert(wxString const&, unsigned long, unsigned long)
//wxArrayString::insert(wxString*, wxString const*, wxString const*)
//wxArrayString::operator=(wxArrayString const&)
//wxArrayString::operator==(wxArrayString const&) const
//wxArrayString::RemoveAt(unsigned long, unsigned long)
//wxArrayString::Remove(wchar_t const*)
//wxArrayString::reserve(unsigned long)
//wxArrayString::SetCount(unsigned long)
//wxArrayString::Shrink()
//wxArrayString::Sort(bool)
//wxArrayString::Sort(int (*)(wxString const&, wxString const&))
//wxArrayString::Sort(int (*)(wxString*, wxString*))
//wxArrayString::~wxArrayString()
//wxArrayString::wxArrayString(unsigned long, wchar_t const**)
//wxArrayString::wxArrayString(unsigned long, wxString const*)
//wxArrayString::wxArrayString(wxArrayString const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxArrayString");
	wxString wxLogo(_T("wxArrayString"));
	
	//wxDateTime  tm(time(NULL));
	wxArrayString  a;
	wxArrayString  b(a);
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
