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
//wxStringList::Add(wchar_t const*)
//wxStringList::Delete(wchar_t const*)
//wxStringList::DoCopy(wxStringList const&)
//wxStringList::GetClassInfo() const
//wxStringList::ListToArray(bool) const
//wxStringList::Member(wchar_t const*) const
//wxStringList::Prepend(wchar_t const*)
//wxStringList::Sort()
//wxStringList::wxCreateObject()
//wxStringList::wxStringList()
//wxStringList::wxStringList(wchar_t const*, ...)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxStringList");
	wxString wxLogo(_T("wxStringList"));
	
	//wxDateTime  tm(time(NULL));
	wxStringList  a;
	a.Add(_T("bbbb"));
	a.Add(_T("bbbb2"));
	a.Add(_T("bbbb3"));
	a.Add(_T("bbbb4"));
	a.Add(_T("bbbb5"));
	//tm.Formatdate();
	wxStringList b(a);
	//b.DoCopy(a);
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
