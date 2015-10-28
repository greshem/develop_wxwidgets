

#include <wx/fileconf.h>
#include <wx/filename.h>


#include <wx/string.h>
#include <wx/wx.h> 

void write_diskplat()
{

	//一定要写成绝对路径, 否则会失败. bug_20m;  
	wxFileConfig OptionIni( wxEmptyString, wxEmptyString,  _T("/usr/share/rtiosrv/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig wksIni( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/wks.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig diskIni( wxEmptyString, wxEmptyString,  _T("/usr/share/rtiosrv/disk.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

    //wxFileConfig OptionIni( wxEmptyString, wxEmptyString, _T("option.ini"), wxEmptyString, wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent );

	OptionIni.Read(_T("SuperUser/UserName"), _T("Admin"));

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
void mdf_diskplat()
{
	//一定要写成绝对路径, 否则会失败. 20m;  
	wxFileConfig OptionIni( wxEmptyString, wxEmptyString,  _T("/usr/share/rtiosrv/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

    //wxFileConfig OptionIni( wxEmptyString, wxEmptyString, _T("option.ini"), wxEmptyString, wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent );
	OptionIni.Write(_T("SuperUser/UserName"), _T("mdf_admin"));
	OptionIni.Flush();

}

void test_init();
int get_wks_connt();

using namespace std;
int main(int argc, char *argv[])
{
	//write_diskplat();
	//mdf_diskplat();
	test_init();
 	get_wks_connt();

}

//用 codegen_wxFileConfig.pl 生成的 ini 配置文件初始化的代码.
void test_init()
{
	wxFileConfig disk_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/disk.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig dskgroup_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/dskgroup.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig graphmenu_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/graphmenu.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig hwc_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/hwc.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig option_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/option.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig recov_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/recov.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig server_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/server.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig wks_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/wks.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	wxFileConfig wksgroup_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/wksgroup.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

	wxString pcid = option_ini.Read(_T("Other/pcid"));
	printf("%s\n", pcid.mb_str().data());
}

int get_wks_connt()
{
	wxFileConfig wks_ini( wxEmptyString, wxEmptyString,   _T("/usr/share/rtiosrv/wks.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;
	int count= wks_ini.GetNumberOfGroups();
	printf("count =%d \n", count);	
	return count;
}


wxString FindMacByWksName_raw(const wxString& WksName)
{
	wxFileConfig *wksIni= new wxFileConfig( wxEmptyString, wxEmptyString,   _T("/usr/share/diskplat/wks.ini"), wxEmptyString,  wxCONFIG_USE_LOCAL_FILE|wxCONFIG_USE_NO_ESCAPE_CHARACTERS, *wxConvCurrent ) ;

	wxString Result ;

	//ReloadWksCfg2() ;
    long idx; 
    wxString group, strValue; 

    if(WksName.IsEmpty())
        return wxEmptyString;
    bool bGroup = wksIni->GetFirstGroup(group, idx); 
    while (bGroup)
    {
        wksIni->Read(group+_T("/WksName"), &strValue, wxEmptyString);
        if(WksName==strValue)
            return group;
        else
            bGroup = wksIni->GetNextGroup(group,idx);
    }
    return wxEmptyString;
}
