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
#include <wx/module.h>
 

//wxModule::DoCleanUpModules(wxModuleList const&)
//wxModule::DoInitializeModule(wxModule*, wxModuleList&)
//wxModule::GetClassInfo() const
//wxModule::InitializeModules()
//wxModule::RegisterModules()
//wxModule::RegisterModule(wxModule*)
//wxModule::UnregisterModule(wxModule*)
//

using namespace std;
//class Module : public wxModule;
class Module : public wxModule
{
	bool OnInit()
	{
		return true;
	}
	void OnExit()
	{
	}
};
int main(int argc, char *argv[])
{
	
	//wxModule a;
	Module a;
	return 0;
}
