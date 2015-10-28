#include <wx/string.h>
#include <wx/wx.h> 

int main(int argc, char* argv[])
{


 	wxString  wxstr = wxString(argv[1], wxConvUTF8);

	if(wxstr == wxEmptyString)
	{
		printf("[%s] is empty string \n", wxstr.mb_str().data());
	}
	else
	{
		printf("[%s] is not empty string \n", wxstr.mb_str().data());
	}

	//wxEmptyString;
	//wxT("");
}

