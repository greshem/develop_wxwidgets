
#include <wx/string.h>
#include <wx/wx.h> 
#include <wx/tokenzr.h>

#include <string> 
#include <sstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

//::wxStringTokenize
//wxArrayString wxStringTokenize(const wxString& str,const wxString& delims = wxDEFAULT_DELIMITERS,wxStringTokenizerMode mode = wxTOKEN_DEFAULT)


int main()
{
	//wxArrayString str_array =::wxStringTokenize(wxT("aa bb cc dd ee ff "));
	wxArrayString str_array =::wxStringTokenize(wxT("aa|bb|cc|dd|ee|ff "), wxT("|"));

	int count= str_array.GetCount();
	for(int i=0; i<count; i++)
	{
		string str(str_array.Item(i).mb_str());
		cout<< str<<endl;
	}

}
