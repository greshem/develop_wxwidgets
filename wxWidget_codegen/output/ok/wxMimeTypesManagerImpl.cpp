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
#include <wx/unix/mimetype.h>
 

//wxMimeTypesManagerImpl::AddFallback(wxFileTypeInfo const&)
//wxMimeTypesManagerImpl::AddMailcapInfo(wxString const&, wxString const&, wxString const&, wxString const&, wxString const&)
//wxMimeTypesManagerImpl::AddMimeTypeInfo(wxString const&, wxString const&, wxString const&)
//wxMimeTypesManagerImpl::AddToMimeData(wxString const&, wxString const&, wxMimeTypeCommands*, wxArrayString const&, wxString const&, bool)
//wxMimeTypesManagerImpl::Associate(wxFileTypeInfo const&)
//wxMimeTypesManagerImpl::CheckKDEDirsExist(wxString const&, wxString const&)
//wxMimeTypesManagerImpl::ClearData()
//wxMimeTypesManagerImpl::DoAssociation(wxString const&, wxString const&, wxMimeTypeCommands*, wxArrayString const&, wxString const&)
//wxMimeTypesManagerImpl::EnumAllFileTypes(wxArrayString&)
//wxMimeTypesManagerImpl::GetCommand(wxString const&, unsigned int) const
//wxMimeTypesManagerImpl::GetFileTypeFromExtension(wxString const&)
//wxMimeTypesManagerImpl::GetFileTypeFromMimeType(wxString const&)
//wxMimeTypesManagerImpl::GetGnomeMimeInfo(wxString const&)
//wxMimeTypesManagerImpl::GetKDEMimeInfo(wxString const&)
//wxMimeTypesManagerImpl::GetMimeInfo(wxString const&)
//wxMimeTypesManagerImpl::Initialize(int, wxString const&)
//wxMimeTypesManagerImpl::InitIfNeeded()
//wxMimeTypesManagerImpl::LoadGnomeDataFromKeyFile(wxString const&, wxArrayString const&)
//wxMimeTypesManagerImpl::LoadGnomeMimeFilesFromDir(wxString const&, wxArrayString const&)
//wxMimeTypesManagerImpl::LoadGnomeMimeTypesFromMimeFile(wxString const&)
//wxMimeTypesManagerImpl::LoadKDEAppsFilesFromDir(wxString const&)
//wxMimeTypesManagerImpl::LoadKDEApp(wxString const&)
//wxMimeTypesManagerImpl::LoadKDELinkFilesFromDir(wxString const&, wxArrayString const&)
//wxMimeTypesManagerImpl::LoadKDELinksForMimeSubtype(wxString const&, wxString const&, wxString const&, wxArrayString const&)
//wxMimeTypesManagerImpl::LoadKDELinksForMimeType(wxString const&, wxString const&, wxArrayString const&)
//wxMimeTypesManagerImpl::ProcessOtherMailcapField(MailcapLineData&, wxString const&)
//wxMimeTypesManagerImpl::ReadMailcap(wxString const&, bool)
//wxMimeTypesManagerImpl::ReadMimeTypes(wxString const&)
//wxMimeTypesManagerImpl::Unassociate(wxFileType*)
//wxMimeTypesManagerImpl::WriteKDEMimeFile(int, bool)
//wxMimeTypesManagerImpl::WriteMimeInfo(int, bool)
//wxMimeTypesManagerImpl::WriteToMailCap(int, bool)
//wxMimeTypesManagerImpl::WriteToMimeTypes(int, bool)
//wxMimeTypesManagerImpl::WriteToNSMimeTypes(int, bool)
//wxMimeTypesManagerImpl::~wxMimeTypesManagerImpl()
//wxMimeTypesManagerImpl::wxMimeTypesManagerImpl()
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxMimeTypesManagerImpl a;
	return 0;
}
