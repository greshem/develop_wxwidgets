
#include <wx/string.h>
#include <wx/wx.h> 

#define CHAR char
void test_format_wc_str();

int main()
{

	int    dwErrorCode ;
	int    dwErrorLine ;
	char 	buffer[1024]={0};

	wxString  test=_T("free bsd ");
	wxString	strMsg ;
	strMsg.Printf( _T("DLXP20081210  Status: %d Source: %s Line %d  %s \n"), dwErrorCode , "linux" , dwErrorLine , test.wc_str()) ;
	
	strncpy(buffer, strMsg.mb_str( wxConvUTF8), sizeof(buffer));;
	//strncpy(buffer, "strMsg.mb_str()", sizeof(buffer));;
	printf("%s\n", buffer);

	test_format_wc_str();
	
}

void test_format_wc_str()
{
	wxString logger;
	wxString str_ip=wxT("172.16.10.10");
	logger.Printf(_T("getLazyServer %s \n"), str_ip.wc_str());
	//logger.Format(_T("getLazyServer %s \n"), str_ip.wc_str());
	printf("%s\n" , logger.mb_str().data());
}

