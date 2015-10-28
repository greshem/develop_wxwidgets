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
//wxFileName::AppendDir(wxString const&)
//wxFileName::AssignCwd(wxString const&)
//wxFileName::AssignDir(wxString const&, wxPathFormat)
//wxFileName::AssignHomeDir()
//wxFileName::AssignTempFileName(wxString const&)
//wxFileName::AssignTempFileName(wxString const&, wxFFile*)
//wxFileName::AssignTempFileName(wxString const&, wxFile*)
//wxFileName::Assign(wxFileName const&)
//wxFileName::Assign(wxString const&, wxPathFormat)
//wxFileName::Assign(wxString const&, wxString const&, wxPathFormat)
//wxFileName::Assign(wxString const&, wxString const&, wxString const&, wxPathFormat)
//wxFileName::Assign(wxString const&, wxString const&, wxString const&, wxString const&, bool, wxPathFormat)
//wxFileName::Clear()
//wxFileName::CreateTempFileName(wxString const&)
//wxFileName::CreateTempFileName(wxString const&, wxFFile*)
//wxFileName::CreateTempFileName(wxString const&, wxFile*)
//wxFileName::DirExists() const
//wxFileName::DirExists(wxString const&)
//wxFileName::DirName(wxString const&, wxPathFormat)
//wxFileName::FileExists() const
//wxFileName::FileExists(wxString const&)
//wxFileName::FileName(wxString const&, wxPathFormat)
//wxFileName::GetCwd(wxString const&)
//wxFileName::GetForbiddenChars(wxPathFormat)
//wxFileName::GetFormat(wxPathFormat)
//wxFileName::GetFullName() const
//wxFileName::GetFullPath(wxPathFormat) const
//wxFileName::GetHomeDir()
//wxFileName::GetHumanReadableSize(wxString const&, int) const
//wxFileName::GetHumanReadableSize(wxULongLongNative const&, wxString const&, int)
//wxFileName::GetLongPath() const
//wxFileName::GetPath(int, wxPathFormat) const
//wxFileName::GetPathSeparators(wxPathFormat)
//wxFileName::GetPathTerminators(wxPathFormat)
//wxFileName::GetShortPath() const
//wxFileName::GetSize() const
//wxFileName::GetSize(wxString const&)
//wxFileName::GetTempDir()
//wxFileName::GetTimes(wxDateTime*, wxDateTime*, wxDateTime*) const
//wxFileName::GetVolumeSeparator(wxPathFormat)
//wxFileName::InsertDir(unsigned long, wxString const&)
//wxFileName::IsAbsolute(wxPathFormat) const
//wxFileName::IsCaseSensitive(wxPathFormat)
//wxFileName::IsPathSeparator(wchar_t, wxPathFormat)
//wxFileName::IsValidDirComponent(wxString const&)
//wxFileName::MakeRelativeTo(wxString const&, wxPathFormat)
//wxFileName::Mkdir(int, int)
//wxFileName::Mkdir(wxString const&, int, int)
//wxFileName::Normalize(int, wxString const&, wxPathFormat)
//wxFileName::PrependDir(wxString const&)
//wxFileName::RemoveDir(unsigned long)
//wxFileName::Rmdir()
//wxFileName::Rmdir(wxString const&)
//wxFileName::SameAs(wxFileName const&, wxPathFormat) const
//wxFileName::SetCwd()
//wxFileName::SetCwd(wxString const&)
//wxFileName::SetFullName(wxString const&)
//wxFileName::SetPath(wxString const&, wxPathFormat)
//wxFileName::SetTimes(wxDateTime const*, wxDateTime const*, wxDateTime const*)
//wxFileName::SplitPath(wxString const&, wxString*, wxString*, wxString*, wxPathFormat)
//wxFileName::SplitPath(wxString const&, wxString*, wxString*, wxString*, wxString*, bool*, wxPathFormat)
//wxFileName::SplitVolume(wxString const&, wxString*, wxString*, wxPathFormat)
//wxFileName::StripExtension(wxString const&)
//wxFileName::Touch()
//

using namespace std;
int main(int argc, char *argv[])
{
	if(argc != 2)
    {
        printf("Usage: %s file_list \n", argv[0]);
        //exit(-1);
    }
    //printf("%s\n", "wxFileName");
	wxString wxLogo(_T("wxFileName"));
	
	//wxDateTime  tm(time(NULL));
	wxFileName  a;
	//tm.Formatdate();
	string str(wxLogo.mb_str());
	cout<<str.c_str()<<endl;
	return 0;
}
