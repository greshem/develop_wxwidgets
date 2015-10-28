#include <wx/fileconf.h>
#include <wx/filename.h>


#include <wx/string.h>
#include <wx/wx.h> 
//gen header with, /root/develop_wxwidgets/codegen_wxFileConfig.pl , 

void dump_diskplat(wxFileConfig &ini);
using namespace std;
int main(int argc, char *argv[])
{
	wxFileConfig ini( wxEmptyString, wxEmptyString,   _T("/tmp/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

	dump_diskplat( ini );
	printf("#not flush \n");
	return 0;
}

//########################################################################
void dump_diskplat(wxFileConfig &ini)
{

printf("ServerSync/AutoSyn=%s\n", ini.Read(_T("ServerSync/AutoSyn"), _T("1")).mb_str().data());
printf("ServerSync/Enable=%s\n", ini.Read(_T("ServerSync/Enable"), _T("1")).mb_str().data());
printf("ServerSync/IsMaster=%s\n", ini.Read(_T("ServerSync/IsMaster"), _T("1")).mb_str().data());
printf("ServerSync/SyncClientInfo=%s\n", ini.Read(_T("ServerSync/SyncClientInfo"), _T("1")).mb_str().data());

printf("Other/;ManPass=%s\n", ini.Read(_T("Other/;ManPass"), _T("F014936A8B8900F8F014936A8B8900F8888E4B176E93CD9D888E4B176E93CD9D")).mb_str().data());
printf("Other/AutoAddRecov=%s\n", ini.Read(_T("Other/AutoAddRecov"), _T("1")).mb_str().data());
printf("Other/BackupServer=%s\n", ini.Read(_T("Other/BackupServer"), _T("1")).mb_str().data());
printf("Other/BootCard=%s\n", ini.Read(_T("Other/BootCard"), _T("0")).mb_str().data());
printf("Other/BootDisk=%s\n", ini.Read(_T("Other/BootDisk"), _T("0")).mb_str().data());
printf("Other/BootServer=%s\n", ini.Read(_T("Other/BootServer"), _T("0")).mb_str().data());
printf("Other/BootType=%s\n", ini.Read(_T("Other/BootType"), _T("0")).mb_str().data());
printf("Other/ClientCache=%s\n", ini.Read(_T("Other/ClientCache"), _T("1")).mb_str().data());
printf("Other/ClientPass=%s\n", ini.Read(_T("Other/ClientPass"), _T("")).mb_str().data());
printf("Other/DhcpOption60=%s\n", ini.Read(_T("Other/DhcpOption60"), _T("0")).mb_str().data());
printf("Other/DhcpReplyNum=%s\n", ini.Read(_T("Other/DhcpReplyNum"), _T("26")).mb_str().data());
printf("Other/EnabedBootpd=%s\n", ini.Read(_T("Other/EnabedBootpd"), _T("0")).mb_str().data());
printf("Other/EnabedTftpd=%s\n", ini.Read(_T("Other/EnabedTftpd"), _T("0")).mb_str().data());
printf("Other/Gateway=%s\n", ini.Read(_T("Other/Gateway"), _T("0")).mb_str().data());
printf("Other/HotBackup=%s\n", ini.Read(_T("Other/HotBackup"), _T("1")).mb_str().data());
printf("Other/Hwc=%s\n", ini.Read(_T("Other/Hwc"), _T("0")).mb_str().data());
printf("Other/LogError=%s\n", ini.Read(_T("Other/LogError"), _T("1")).mb_str().data());
printf("Other/MainUserID=%s\n", ini.Read(_T("Other/MainUserID"), _T("0")).mb_str().data());
printf("Other/ManPass=%s\n", ini.Read(_T("Other/ManPass"), _T("23E2A071CCD92B8A888E4B176E93CD9D888E4B176E93CD9D888E4B176E93CD9D")).mb_str().data());
printf("Other/Memo=%s\n", ini.Read(_T("Other/Memo"), _T("1")).mb_str().data());
printf("Other/NetMask=%s\n", ini.Read(_T("Other/NetMask"), _T("1")).mb_str().data());
printf("Other/PortDisk=%s\n", ini.Read(_T("Other/PortDisk"), _T("7495")).mb_str().data());
printf("Other/PortPXE=%s\n", ini.Read(_T("Other/PortPXE"), _T("47138")).mb_str().data());
printf("Other/ReadWriteData=%s\n", ini.Read(_T("Other/ReadWriteData"), _T("1")).mb_str().data());
printf("Other/ReadWriteSpeed=%s\n", ini.Read(_T("Other/ReadWriteSpeed"), _T("1")).mb_str().data());
printf("Other/SelectTimeOut=%s\n", ini.Read(_T("Other/SelectTimeOut"), _T("22")).mb_str().data());
printf("Other/Server=%s\n", ini.Read(_T("Other/Server"), _T("0")).mb_str().data());
printf("Other/SetLog=%s\n", ini.Read(_T("Other/SetLog"), _T("1")).mb_str().data());
printf("Other/SuperPass=%s\n", ini.Read(_T("Other/SuperPass"), _T("")).mb_str().data());
printf("Other/WksGroup=%s\n", ini.Read(_T("Other/WksGroup"), _T("0")).mb_str().data());
printf("Other/WksPath=%s\n", ini.Read(_T("Other/WksPath"), _T("0")).mb_str().data());
printf("Other/\;ManPass=%s\n", ini.Read(_T("Other/\;ManPass"), _T("F014936A8B8900F8F014936A8B8900F8888E4B176E93CD9D888E4B176E93CD9D")).mb_str().data());
printf("Other/pcid=%s\n", ini.Read(_T("Other/pcid"), _T("FB2A96C25A34AF9C")).mb_str().data());
printf("Other/pctype=%s\n", ini.Read(_T("Other/pctype"), _T("0")).mb_str().data());

printf("DefaultPath/LogPath=%s\n", ini.Read(_T("DefaultPath/LogPath"), _T("/usr/share/rtiosrv/./rtiosrv.log")).mb_str().data());
printf("DefaultPath/RecovPath=%s\n", ini.Read(_T("DefaultPath/RecovPath"), _T("/tmp/")).mb_str().data());

printf("AllocIP/DynamicIP=%s\n", ini.Read(_T("AllocIP/DynamicIP"), _T("0")).mb_str().data());
printf("AllocIP/IpList=%s\n", ini.Read(_T("AllocIP/IpList"), _T("172.16.10.105")).mb_str().data());
printf("AllocIP/NetCartList=%s\n", ini.Read(_T("AllocIP/NetCartList"), _T("172.16.10.105|eth0|")).mb_str().data());
printf("AllocIP/StartIP=%s\n", ini.Read(_T("AllocIP/StartIP"), _T("172.16.10.11")).mb_str().data());
printf("AllocIP/StopIP=%s\n", ini.Read(_T("AllocIP/StopIP"), _T("172.16.10.254")).mb_str().data());

printf("AutoWks/AddType=%s\n", ini.Read(_T("AutoWks/AddType"), _T("1")).mb_str().data());
printf("AutoWks/NameCode=%s\n", ini.Read(_T("AutoWks/NameCode"), _T("3")).mb_str().data());
printf("AutoWks/PreName=%s\n", ini.Read(_T("AutoWks/PreName"), _T("WKS")).mb_str().data());
printf("AutoWks/Template=%s\n", ini.Read(_T("AutoWks/Template"), _T("WKS002")).mb_str().data());

printf("SuperUser/Password=%s\n", ini.Read(_T("SuperUser/Password"), _T("")).mb_str().data());
printf("SuperUser/UserName=%s\n", ini.Read(_T("SuperUser/UserName"), _T("Admin")).mb_str().data());

printf("LimitSpeed/LimitSpeed=%s\n", ini.Read(_T("LimitSpeed/LimitSpeed"), _T("0")).mb_str().data());
}

