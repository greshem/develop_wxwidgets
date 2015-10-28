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
#include <wx/convauto.h>
 

//wxConvAuto::DetectBOM(char const*, unsigned int)
//wxConvAuto::FromWChar(char*, unsigned int, wchar_t const*, unsigned int) const
//wxConvAuto::InitFromBOM(wxConvAuto::BOMType)
//wxConvAuto::InitFromInput(char const**, unsigned int*)
//wxConvAuto::SkipBOM(char const**, unsigned int*) const
//wxConvAuto::ToWChar(wchar_t*, unsigned int, char const*, unsigned int) const
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxConvAuto a;
	return 0;
}
