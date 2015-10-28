
#include <wx/wx.h> 
#include <wx/string.h>
#include <wx/stdpaths.h>

#include <wx/filename.h>

//注意两者的输出有微妙的区别,  后面有没有 / 确实可以导致 程序不启动 之前 又碰到过的bug. 花了2-3h 了.
///root/develop_wxwidgets 
///root/develop_wxwidgets/ 

wxString get_exe_path()
{
   	wxStandardPathsBase& stdp = wxStandardPaths::Get();
    wxFileName exeFile(stdp.GetExecutablePath()); 
    wxString strExePath = exeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);
	return  strExePath;
}

int main()
{
	wxString pwd=::wxGetCwd();
	printf("#pwd %s \n", pwd.mb_str().data());

	wxString pwd2= get_exe_path();
	printf("#pwd %s \n", pwd2.mb_str().data());
	return 0;
}



