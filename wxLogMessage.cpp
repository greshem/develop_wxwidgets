#include <wx/string.h>
#include <wx/wx.h> 
int main()
{
	wxString msg;
	wxString strVDiskName=_T("WINXP");
	msg.Printf(_T("Remove SuperClient=> VDisk: %s") , strVDiskName.c_str() ) ;
	wxLogMessage( msg ) ;
}
