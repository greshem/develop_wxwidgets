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
//2011_03_18 by greshem. 

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
#include <wx/file.h>
//wxFile::Access(wchar_t const*, wxFile::OpenMode)
//wxFile::Close()
//wxFile::Create(wchar_t const*, bool, int)
//wxFile::Eof() const
//wxFile::Exists(wchar_t const*)
//wxFile::Flush()
//wxFile::Length() const
//wxFile::Open(wchar_t const*, wxFile::OpenMode, int)
//wxFile::Read(void*, unsigned long)
//wxFile::Seek(long, wxSeekMode)
//wxFile::Tell() const
//wxFile::Write(void const*, unsigned long)
//wxFile::wxFile(wchar_t const*, wxFile::OpenMode)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        exit(-1);
    }
	wxString wxLogo(_T("wxFile"));
	
	//wxDateTime  tm(time(NULL));
	wxString filename(argv[1], wxConvUTF8);
	wxFile  a(filename , wxFile::read);;
	wxFileOffset length=a.Length();
	printf("%d\n", (int) length);
	char *buf=(char*)malloc(length+1);
	a.Read((void*)buf, length+1);
	buf[length]='\0';
	printf("%s", buf);
	
	return 0;
}
