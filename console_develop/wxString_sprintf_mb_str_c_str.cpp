
#include <wx/string.h>
#include <wx/wx.h> 

#define CHAR char

int main()
{

	int    dwErrorCode ;
	int    dwErrorLine ;
	char 	buffer[1024]={0};

	wxString	strMsg ;
	strMsg.Printf( _T("DLXP20081210  Status: %d Source: %s Line %d\n"), dwErrorCode , "linux" , dwErrorLine ) ;
	
	strncpy(buffer, strMsg.mb_str( wxConvUTF8), sizeof(buffer));;
	//strncpy(buffer, "strMsg.mb_str()", sizeof(buffer));;
	printf("%s\n", buffer);
}
