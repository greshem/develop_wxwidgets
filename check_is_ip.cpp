
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
#include <dirent.h>

#include <wx/wx.h>
#include <wx/file.h>


//#include "../../diskplat.h"


//来自于: diskplat param.cpp,  DWORD IpStringToDword(const wxString &s)
//添加了  判断是不是 255 的 逻辑。 
typedef  unsigned int  DWORD ;
DWORD check_is_ip(const wxString &s)
{
	if(s.IsEmpty()) return 0;

    wxString IpString =s;
    DWORD Result = 0;
    long val;


    if (IpString.Find('.') == wxNOT_FOUND)
        return 0;
    if (!IpString.BeforeFirst('.').ToLong(&val))
        return 0;
    Result = val << 24;
	if(val >255)
	{
		return 0;
	}

    IpString = IpString.AfterFirst('.');
    if (IpString.Find('.') == wxNOT_FOUND)
        return 0;
    if (!IpString.BeforeFirst('.').ToLong(&val))
        return 0;
    Result |= val << 16;
	if(val>255)
	{
		return 0;
	}

    IpString = IpString.AfterFirst('.');
    if (IpString.Find('.') == wxNOT_FOUND)
        return 0;
    if (!IpString.BeforeFirst('.').ToLong(&val))
        return 0;
    Result |= val << 8;
	if(val>255)
	{
		return 0;
	}


    IpString = IpString.AfterFirst('.');
    if (!IpString.ToLong(&val))
        return 0;
	if(val>255)
	{
		return 0;
	}

    Result |= val;

    return Result;
}


#include <wx/string.h>
#include <wx/wx.h> 

int main(int argc, char *argv[])
{
	//char * 转 wxString 
	wxString  wxstr2= wxString(argv[1], wxConvUTF8);

	if(check_is_ip(wxstr2))
	{
		printf("is ip \n");
	}
	else
	{
		printf("is not ip \n");
	}	
	
}
