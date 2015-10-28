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
#include <wx/stdpaths.h>
#include <wx/unix/stdpaths.h>
 

//wxStandardPaths::DetectPrefix()
//wxStandardPaths::GetConfigDir() const
//wxStandardPaths::GetDataDir() const
//wxStandardPaths::GetExecutablePath() const
//wxStandardPaths::GetInstallPrefix() const
//wxStandardPaths::GetLocalDataDir() const
//wxStandardPaths::GetLocalizedResourcesDir(wchar_t const*, wxStandardPathsBase::ResourceCat) const
//wxStandardPaths::GetPluginsDir() const
//wxStandardPaths::GetUserConfigDir() const
//wxStandardPaths::GetUserDataDir() const
//wxStandardPaths::SetInstallPrefix(wxString const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxStandardPaths a;
	return 0;
}
