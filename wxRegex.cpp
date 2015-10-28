

#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/string.h>
#include <wx/wx.h> 
#include <wx/regex.h>

int main()
{
	wxString text=wxT("teresa@www.baidu.com");;

	wxRegEx reEmail( wxT("([^@]+)@([[:alnum:].-_].)+([[:alnum:]]+)"));
	if ( reEmail.Matches(text) )
	{
		wxString tmp = reEmail.GetMatch(text);
		wxString username = reEmail.GetMatch(text, 1);
		wxString tmp3	= reEmail.GetMatch(text,3);
		if ( reEmail.GetMatch(text, 3) == wxT("com") ) // .com TLD?
		{
			printf("%s\n", username.mb_str().data());	
		}
	}
}
