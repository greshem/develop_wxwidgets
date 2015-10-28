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

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
#include <wx/tarstrm.h>
 

//wxTarOutputStream::Close()
//wxTarOutputStream::CloseEntry()
//wxTarOutputStream::CopyEntry(wxArchiveEntry*, wxArchiveInputStream&)
//wxTarOutputStream::CopyEntry(wxTarEntry*, wxTarInputStream&)
//wxTarOutputStream::Init(wxTarFormat)
//wxTarOutputStream::ModifyHeader()
//wxTarOutputStream::OnSysSeek(long long, wxSeekMode)
//wxTarOutputStream::OnSysWrite(void const*, unsigned int)
//wxTarOutputStream::PaxHeaderPath(wxString const&, wxString const&)
//wxTarOutputStream::PutNextDirEntry(wxString const&, wxDateTime const&)
//wxTarOutputStream::PutNextEntry(wxArchiveEntry*)
//wxTarOutputStream::PutNextEntry(wxString const&, wxDateTime const&, long long)
//wxTarOutputStream::PutNextEntry(wxTarEntry*)
//wxTarOutputStream::SetExtendedHeader(wxString const&, wxString const&)
//wxTarOutputStream::SetHeaderDate(wxString const&, wxDateTime const&)
//wxTarOutputStream::SetHeaderNumber(int, long long)
//wxTarOutputStream::SetHeaderPath(wxString const&)
//wxTarOutputStream::SetHeaderString(int, wxString const&)
//wxTarOutputStream::Sync()
//wxTarOutputStream::WriteHeaders(wxTarEntry&)
//wxTarOutputStream::~wxTarOutputStream()
//wxTarOutputStream::wxTarOutputStream(wxOutputStream*, wxTarFormat, wxMBConv&)
//wxTarOutputStream::wxTarOutputStream(wxOutputStream&, wxTarFormat, wxMBConv&)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxTarOutputStream a;
	return 0;
}
