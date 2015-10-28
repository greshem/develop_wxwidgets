

#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/string.h>
#include <wx/wx.h> 


int main()
{
	wxFileName path( wxT("/usr/share/diskplat/option.ini") );
	//wxFileName::DirName( );
	
	assert(   path.GetPath() == wxT("/usr/share/diskplat")); //注意不以 /结尾 
	assert(   path.GetName() == wxT("option"));
	assert(   path.GetFullName() == wxT("option.ini"));

	printf("%s\n", path.GetPath().mb_str().data());
	printf("%s\n", path.GetName().mb_str().data());
	printf("%s\n", path.GetFullName().mb_str().data());


	printf("Cwd: %s\n", wxFileName::GetCwd().mb_str().data());
}
