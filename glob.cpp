#include <wx/wx.h>


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

int glob_test(wxArrayString &out);
int main()
{
	wxArrayString output;
	glob_test(output);
}

int glob_test(wxArrayString &out)
{
	wxString f = wxFindFirstFile(wxT("/tmp/*.dat"));
	while ( !f.empty() )
	{
		string  	 name(f.mb_str());
		cout<<name<<endl;
		out.Add(f);

		f = wxFindNextFile();
	}
	return 1;
}
