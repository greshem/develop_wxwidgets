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
int main()
{
	wxString f = wxFindFirstFile(wxT("/etc/*"));
	char filename[256];
	while ( !f.empty() )
	{
		f = wxFindNextFile();
		//单独打印会出现错误, 拷贝了然后再进行打印.  
		//printf("%s\n", f.mb_str());
	
		string  	 name(f.mb_str());
		//strncpy(filename, f.mb_str(), sizeof(filename));
		cout<<name<<endl;
		//printf("%s|\n", filename);
	}
}
