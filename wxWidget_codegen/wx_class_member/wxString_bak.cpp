#include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
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
#include <wx/encconv.h>
//2010_07_15 by qzj. 
//
//MLogFile logger;
using namespace std;
int main(int argc, char *argv[])
{
	//logger.Instance(MString(argv[0])+".log", 1000);
	//logger.WriteError("test", "test");
	//wxString str((size_t) 10,(wxChar )'a');
	//wxString str((wxChar )'a', (size_t) 10);
	//wxString tmp(_T("wenwen"));
	//string str("wenwen");
	//wxMBConv *conv=wxConvCurrent;
	//wxString str("wenwen");
	//wxString tmp=wxString(str.c_str(), *conv);
	//cout<<tmp;
	//############
	char ansii_str[100]="wenshuna";
	//wxString wxStr(ansii_str, wxConvUTF8);
	//wxString wxStr(ansii_str, wxConvCurrent);
	//wxString wxStr(ansii_str, wxConvASCII);
	//cout<<wxStr;
	wxString wxStr;
	printf("%s\n", wxStr.c_str());
	//############
	wxString str=_T("hello");
	str.Printf(_T("aaaaaaaaaaaaaaaaaaa"));
	cout<<str<<endl;
	return 1;
}
