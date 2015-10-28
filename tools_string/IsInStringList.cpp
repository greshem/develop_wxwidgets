
#include <wx/string.h>
#include <wx/wx.h> 

bool  IsInStringList( wxString     &strFindstring,  wxString     &strStringlist ) 
{
	wxString        strSingleString ;
	wxString        strList = strStringlist ;
	bool            bFind = FALSE ;

	while ( !strList.IsEmpty() )
	{
		if ( strList.Find( '|' ) == wxNOT_FOUND )
		{
			strSingleString = strList ;
			strList = wxEmptyString ;
		}
		else
		{
			strSingleString = strList.BeforeFirst( '|' ) ;
			strList = strList.AfterFirst( '|' ) ;
		}

		if ( strSingleString == strFindstring )
		{
			bFind = TRUE ;
			break ;
		}
	}
	return bFind ;
}

int main()
{
	wxString needle=wxT("aaaa");
	wxString haystack = wxT("bbbb|cccc|aaaa|dddd|eeee");
   	if(IsInStringList(needle,  haystack))
	{
		printf("aaaa  IsIn    bbbb|cccc|aaaa|dddd|eeee\n");
	}

}
