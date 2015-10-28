#include <wx/fileconf.h>
#include <wx/filename.h>


#include <wx/string.h>
#include <wx/wx.h> 
//gen header with, /root/develop_wxwidgets/codegen_wxFileConfig.pl , 

using namespace std;
void save_diskplat(wxFileConfig &ini);
int main(int argc, char *argv[])
{
	wxFileConfig ini( wxEmptyString, wxEmptyString,   _T("/tmp/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

	while(1)
	{
		save_diskplat( ini );
		sleep(1);
		printf("#not flush \n");
	}
	return 0;
}

//########################################################################
void save_diskplat(wxFileConfig &ini)
{
	//wxFileConfig ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;


	;
	ini.Write(_T("ServerSync/AutoSyn"), _T("1"));
	ini.Write(_T("ServerSync/Enable"), _T("1"));
	ini.Write(_T("ServerSync/IsMaster"), _T("1"));
	ini.Write(_T("ServerSync/SyncClientInfo"), _T("1"));
	;
	ini.Write(_T("Other/;ManPass"), _T("F014936A8B8900F8F014936A8B8900F8888E4B176E93CD9D888E4B176E93CD9D"));
	ini.Write(_T("Other/AutoAddRecov"), _T("1"));
	ini.Write(_T("Other/BackupServer"), _T("1"));
	ini.Write(_T("Other/BootCard"), _T("0"));
	ini.Write(_T("Other/BootDisk"), _T("0"));
	ini.Write(_T("Other/BootServer"), _T("0"));
	ini.Write(_T("Other/BootType"), _T("0"));
	ini.Write(_T("Other/ClientCache"), _T("1"));
	ini.Write(_T("Other/ClientPass"), _T(""));
	ini.Write(_T("Other/DhcpOption60"), _T("0"));
	ini.Write(_T("Other/DhcpReplyNum"), _T("26"));
	ini.Write(_T("Other/EnabedBootpd"), _T("0"));
	ini.Write(_T("Other/EnabedTftpd"), _T("0"));
	ini.Write(_T("Other/Gateway"), _T("0"));
	ini.Write(_T("Other/HotBackup"), _T("1"));
	ini.Write(_T("Other/Hwc"), _T("0"));
	ini.Write(_T("Other/LogError"), _T("1"));
	ini.Write(_T("Other/MainUserID"), _T("0"));
	ini.Write(_T("Other/ManPass"), _T("23E2A071CCD92B8A888E4B176E93CD9D888E4B176E93CD9D888E4B176E93CD9D"));
	ini.Write(_T("Other/Memo"), _T("1"));
	ini.Write(_T("Other/NetMask"), _T("1"));
	ini.Write(_T("Other/PortDisk"), _T("7495"));
	ini.Write(_T("Other/PortPXE"), _T("47138"));
	ini.Write(_T("Other/ReadWriteData"), _T("1"));
	ini.Write(_T("Other/ReadWriteSpeed"), _T("1"));
	ini.Write(_T("Other/SelectTimeOut"), _T("22"));
	ini.Write(_T("Other/Server"), _T("0"));
	ini.Write(_T("Other/SetLog"), _T("1"));
	ini.Write(_T("Other/SuperPass"), _T(""));
	ini.Write(_T("Other/WksGroup"), _T("0"));
	ini.Write(_T("Other/WksPath"), _T("0"));
	ini.Write(_T("Other/pcid"), _T("FB2A96C25A34AF9C"));
	ini.Write(_T("Other/pctype"), _T("0"));
	;
	ini.Write(_T("DefaultPath/LogPath"), _T("/usr/share/rtiosrv/./rtiosrv.log"));
	ini.Write(_T("DefaultPath/RecovPath"), _T("/tmp/"));
	;
	ini.Write(_T("AllocIP/DynamicIP"), _T("0"));
	ini.Write(_T("AllocIP/IpList"), _T("172.16.10.105"));
	ini.Write(_T("AllocIP/NetCartList"), _T("172.16.10.105|eth0|"));
	ini.Write(_T("AllocIP/StartIP"), _T("172.16.10.11"));
	ini.Write(_T("AllocIP/StopIP"), _T("172.16.10.254"));
	;
	ini.Write(_T("AutoWks/AddType"), _T("1"));
	ini.Write(_T("AutoWks/NameCode"), _T("3"));
	ini.Write(_T("AutoWks/PreName"), _T("WKS"));
	ini.Write(_T("AutoWks/Template"), _T("WKS002"));
	;
	ini.Write(_T("SuperUser/Password"), _T(""));
	ini.Write(_T("SuperUser/UserName"), _T("Admin"));
	;
	ini.Write(_T("LimitSpeed/LimitSpeed"), _T("0"));

  	ini.Flush();
	//ini.Save();
}

