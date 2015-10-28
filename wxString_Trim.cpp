#include <wx/wx.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
long testunit(  )
{
	wxString test(_T("   123456    "));
	test.Trim();	  //delete from left
	test.Trim(false); // delete from right 
	printf("|%s|\n", test.mb_str().data());

	return 1;
}

int main()
{
	
	testunit();
}

