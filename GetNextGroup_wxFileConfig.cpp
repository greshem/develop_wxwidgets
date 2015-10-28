#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/wx.h> 

void dump_diskplat(wxFileConfig &ini);
void dump_all_bootServer(wxFileConfig &ini);
using namespace std;


int main(int argc, char *argv[])
{
	wxFileConfig ini( wxEmptyString, wxEmptyString,   _T("//usr/share/diskplat//option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig wks_ini( wxEmptyString, wxEmptyString,   _T("//usr/share/diskplat//wks.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;



	dump_diskplat( ini );
	dump_all_bootServer(wks_ini);

	return 0;
}

void dump_diskplat(wxFileConfig &ini)
{
	printf("Other/BootServer=%s\n", ini.Read(_T("Other/BootServer"), _T("0")).mb_str().data());
}
void dump_all_bootServer(wxFileConfig &wks_ini)
{
	
    wxString strGroup ;
    wxString strKey ;
    long idx;
 	bool bGroup = wks_ini.GetFirstGroup(strGroup, idx);
    while (bGroup)
	{
		strKey = strGroup + _T("/BootServer") ;
		printf("[%s]\n", strGroup.mb_str().data());
		printf("Other/BootServer=%s\n", wks_ini.Read(strKey, _T("0")).mb_str().data());
		bGroup = wks_ini.GetNextGroup(strGroup,idx);
	}
}

