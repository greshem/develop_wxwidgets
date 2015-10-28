
#include <wx/string.h>
#include <wx/wx.h> 
#define CHAR char
int main()
{
	wxString now=::wxNow();
	printf("%s\n", now.mb_str().data());	
}
