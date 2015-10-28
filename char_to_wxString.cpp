

#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/string.h>
#include <wx/wx.h> 

int main()
{
	//char * ת wxString 
	char buffer[1024]="linux server";
 	wxString  wxstr = wxString( "test", wxConvUTF8);
	wxString  wxstr2= wxString(buffer, wxConvUTF8);
	printf("%s\n", wxstr.mb_str().data());
	printf("%s\n", wxstr2.mb_str().data());
	
}
