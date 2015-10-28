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
#include <wx/unix/stackwalk.h>
 

//wxStackWalker::FreeStack()
//wxStackWalker::InitFrames(wxStackFrame*, unsigned int, void**, char**)
//wxStackWalker::ProcessFrames(unsigned int)
//wxStackWalker::SaveStack(unsigned int)
//wxStackWalker::Walk(unsigned int, unsigned int)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxStackWalker a;
	return 0;
}
