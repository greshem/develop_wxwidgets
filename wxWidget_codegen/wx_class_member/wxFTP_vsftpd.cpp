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

#include <wx/protocol/ftp.h>
//#include <wx/ftp.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
//wxFTP::Abort()
//wxFTP::AcceptIfActive(wxSocketBase*)
//wxFTP::ChDir(wxString const&)
//wxFTP::Close()
//wxFTP::Connect(wxSockAddress&, bool)
//wxFTP::Connect(wxString const&)
//wxFTP::DoSimpleCommand(wchar_t const*, wxString const&)
//wxFTP::FileExists(wxString const&)
//wxFTP::GetActivePort()
//wxFTP::GetClassInfo() const
//wxFTP::GetFileSize(wxString const&)
//wxFTP::GetInputStream(wxString const&)
//wxFTP::GetList(wxArrayString&, wxString const&, bool)
//wxFTP::GetOutputStream(wxString const&)
//wxFTP::GetPassivePort()
//wxFTP::GetPort()
//wxFTP::GetPortCmdArgument(wxIPV4address const&, wxIPV4address const&)
//wxFTP::GetResult()
//wxFTP::MkDir(wxString const&)
//wxFTP::Pwd()
//wxFTP::Rename(wxString const&, wxString const&)
//wxFTP::RmDir(wxString const&)
//wxFTP::RmFile(wxString const&)
//wxFTP::SendCommand(wxString const&)
//wxFTP::SetDefaultTimeout(unsigned int)
//wxFTP::SetTransferMode(wxFTP::TransferMode)
//wxFTP::wxCreateObject()
//wxFTP::~wxFTP()
//wxFTP::wxFTP()
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
	wxString wxLogo(_T("wxFTP"));
	
	wxFTP  ftp;

	ftp.SetUser("user");
    ftp.SetPassword("password");

    //if ( !ftp.Connect("ftp.wxwindows.org") )
    if ( !ftp.Connect("192.168.1.73") )
    {
        wxLogError("Couldn't connect");
        return;
    }

    //ftp.ChDir("/pub");
    ftp.ChDir("/pub");
    //wxInputStream *in = ftp.GetInputStream("wxWidgets-4.2.0.tar.gz");
    wxInputStream *in = ftp.GetInputStream("tmp");
    if ( !in )
    {
        wxLogError("Coudln't get file");
    }
    else
    {
        size_t size = in->GetSize();
        char *data = new char[size];
        if ( !in->Read(data, size) )
        {
            wxLogError("Read error");
        }
        else
        {
		}
	return 0;
}
