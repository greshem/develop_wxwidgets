
#include <wx/string.h>
#include <wx/wx.h> 


#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
bool IsStringHaveSpace(wxString szTemp)
{
	wxString strTemp = _T(" ");
	wxString strche;
	wxString strchs;
	
	if (!szTemp.IsEmpty())
	{
		strchs = szTemp.Left(1);
		strche = szTemp.Right(1);
		if ((strchs.Cmp(strTemp) == 0) || (strche.Cmp(strTemp) == 0))
		{
			return true;
		}
	}
	return false;
}


using namespace std;
int main(int argc, char *argv[])
{
	assert(IsStringHaveSpace(_T("aaa bbbb cc ")));
	assert(IsStringHaveSpace(_T("aaa\tcc")));
	assert(IsStringHaveSpace(_T("aaa\ncc")));
}


