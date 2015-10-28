
#include <wx/wx.h>
#include <wx/filename.h>
#include  <wx/stdpaths.h>

#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	wxStandardPathsBase& stdp = wxStandardPaths::Get();
	wxFileName exeFile(stdp.GetExecutablePath());
	wxString strExePath = exeFile.GetPath(wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR);

	printf("%s\n", strExePath.mb_str().data());
}
