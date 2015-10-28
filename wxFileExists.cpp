#include <wx/string.h>
#include <wx/wx.h> 
#include <wx/filefn.h>

#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{	
	if(::wxFileExists(wxT("/etc/passwd")))
	{
		printf("etc  passwd exists");
	}
	else
	{
		printf ("etc passwd not exists");
	}
}
