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
#include <wx/zipstrm.h>

#include <wx/zstream.h>

#include <wx/wfstream.h>


//wxZlibInputStream::CanHandleGZip()
//wxZlibInputStream::Init(int)
//wxZlibInputStream::OnSysRead(void*, unsigned long)
//wxZlibInputStream::~wxZlibInputStream()
//wxZlibInputStream::wxZlibInputStream(wxInputStream*, int)
//wxZlibInputStream::wxZlibInputStream(wxInputStream&, int)
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxZlibInputStream");
	wxString wxLogo(_T("wxZlibInputStream"));
	
	//wxDateTime  tm(time(NULL));
	wxZlibInputStream  a;

    wxFFileOutputStream out(_T("test.zip"));
    wxZipOutputStream zip(out);
    wxTextOutputStream txt(zip);
    wxString sep(wxFileName::GetPathSeparator());

    zip.PutNextEntry(_T("entry1.txt"));
    txt << _T("Some text for entry1.txt\n");

    zip.PutNextEntry(_T("subdir") + sep + _T("entry2.txt"));
    txt << _T("Some text for subdir/entry2.txt\n");


	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
