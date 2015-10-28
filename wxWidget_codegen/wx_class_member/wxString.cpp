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
//wxString::AfterFirst(wchar_t) const
//wxString::AfterLast(wchar_t) const
//wxString::BeforeFirst(wchar_t) const
//wxString::BeforeLast(wchar_t) const
//wxString::CmpNoCase(wchar_t const*) const
//wxString::CmpNoCase(wxString const&) const
//wxString::Cmp(wchar_t const*) const
//wxString::Cmp(wxString const&) const
//wxString::EndsWith(wchar_t const*, wxString*) const
//wxString::Find(wchar_t, bool) const
//wxString::Find(wchar_t const*) const
//wxString::FormatV(wchar_t const*, __va_list_tag*)
//wxString::Format(wchar_t const*, ...)
//wxString::Freq(wchar_t) const
//wxString::FromAscii(char)
//wxString::FromAscii(char const*)
//wxString::GetWriteBuf(unsigned long)
//wxString::IsAscii() const
//wxString::IsNumber() const
//wxString::IsWord() const
//wxString::Left(unsigned long) const
//wxString::Lower() const
//wxString::MakeLower()
//wxString::MakeUpper()
//wxString::Matches(wchar_t const*) const
//wxString::mb_str(wxMBConv const&) const
//wxString::Mid(unsigned long, unsigned long) const
//wxString::Pad(unsigned long, wchar_t, bool)
//wxString::PrintfV(wchar_t const*, __va_list_tag*)
//wxString::Printf(wchar_t const*, ...)
//wxString::Replace(wchar_t const*, wchar_t const*, bool)
//wxString::Right(unsigned long) const
//wxString::Shrink()
//wxString::sprintf(wchar_t const*, ...)
//wxString::StartsWith(wchar_t const*, wxString*) const
//wxString::Strip(wxString::stripType) const
//wxString::ToAscii() const
//wxString::ToDouble(double*) const
//wxString::ToLong(long*, int) const
//wxString::ToLongLong(long long*, int) const
//wxString::ToULongLong(unsigned long long*, int) const
//wxString::ToULong(unsigned long*, int) const
//wxString::Trim(bool)
//wxString::Truncate(unsigned long)
//wxString::UngetWriteBuf()
//wxString::UngetWriteBuf(unsigned long)
//wxString::Upper() const
//wxString::wxString(char const*, wxMBConv const&, unsigned long)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxString");
	wxString wxLogo(_T("wxString"));
	
	//wxDateTime  tm(time(NULL));
	wxString  a;
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
