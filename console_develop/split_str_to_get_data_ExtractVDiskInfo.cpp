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

//只能处理下面的字符串 
//VMWARE|3
//VMWARE|3|不行
//VMWARE|3333|444 不行.

void  ExtractVDiskInfo(const wxString& strDisk, wxString &VDiskName, int &VDiskIndex)
{
    wxString DiskStr = strDisk;
    if (DiskStr.Find('|') == wxNOT_FOUND)
    {
        VDiskName = DiskStr;
        VDiskIndex = 0;
    }
    else
    {
        VDiskName = DiskStr.BeforeFirst('|');
        DiskStr = DiskStr.AfterFirst('|');
        long val;
        if (!DiskStr.ToLong(&val))
            VDiskIndex = 0;
        else
            VDiskIndex = val;
    }
}

int main()
{
	wxString input_str( _T("VMWARE|3333"));
	wxString name;
	int		index;
	ExtractVDiskInfo(input_str ,  name, index);

	string name_stl(name.mb_str());
	printf("%s, %d \n", name_stl.c_str(), index );
		
	return 1;
}

