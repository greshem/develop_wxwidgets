

#include <wx/fileconf.h>
#include <wx/filename.h>


#include <wx/string.h>
#include <wx/wx.h> 

void write_diskplat()
{

	//一定要写成绝对路径, 否则会失败. 20m;  
	wxFileConfig OptionIni( wxEmptyString, wxEmptyString,  _T("/root/develop_wxwidgets/console_develop/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

    //wxFileConfig OptionIni( wxEmptyString, wxEmptyString, _T("option.ini"), wxEmptyString, wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent );
	OptionIni.Write(_T("SuperUser/UserName"), _T("Admin"));
	OptionIni.Write(_T("SuperUser/Password"), wxEmptyString);
	OptionIni.Write(_T("AutoWks/AddType"), 2);
	OptionIni.Write(_T("AutoWks/PreName"), _T("WKS"));
	OptionIni.Write(_T("AutoWks/NameCode"), 3);
	OptionIni.Write(_T("AutoWks/Template"), wxEmptyString ) ;

	OptionIni.Write(_T("AllocIP/DynamicIP"), false);
	OptionIni.Write(_T("AllocIP/IpList"), _T("127.0.0.1|eth0"));
	OptionIni.Write(_T("AllocIP/StartIP"), _T("192.168.1.1") );
	OptionIni.Write(_T("AllocIP/StopIP"), wxT("192.168.1.100"));
	OptionIni.Write(_T("Other/LogError"), false);

	OptionIni.Write(_T("Other/ManPass"), _T(""));
	OptionIni.Write(_T("Other/SuperPass"), _T(""));
	OptionIni.Flush();
}

using namespace std;
int main(int argc, char *argv[])
{
	write_diskplat();
}
