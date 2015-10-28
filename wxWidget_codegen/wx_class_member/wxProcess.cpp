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
#include <wx/process.h>


//wxProcess::Detach()
//wxProcess::Exists(int)
//wxProcess::GetClassInfo() const
//wxProcess::Init(wxEvtHandler*, int, int)
//wxProcess::IsErrorAvailable() const
//wxProcess::IsInputAvailable() const
//wxProcess::IsInputOpened() const
//wxProcess::Kill(int, wxSignal, int)
//wxProcess::OnTerminate(int, int)
//wxProcess::Open(wxString const&, int)
//wxProcess::SetPipeStreams(wxInputStream*, wxOutputStream*, wxInputStream*)
//wxProcess::wxCreateObject()
//wxProcess::~wxProcess()
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxProcess");
	wxString wxLogo(_T("wxProcess"));
	
	//wxDateTime  tm(time(NULL));
	wxProcess  a;
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
