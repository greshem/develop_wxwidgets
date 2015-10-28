#include <wx/string.h>
#include <wx/wx.h> 
int main() 	
{
	wxCopyFile(wxT("/etc/passwd"), wxT("/tmp/passwd"));
	if( wxFileExists(wxT("/tmp/passwd")))
	{
		printf("%s\n", "file copy success\n");
	}
	else
	{
		wxMessageBox(wxT("file copy failure\n"));
	}
}
