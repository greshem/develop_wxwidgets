
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/string.h>
#include <wx/wx.h> 
#include <wx/protocol/ftp.h>
//зЂвт: wxInitialize();
//ftp://ftp.wxwindows.org/pub/2.8.6/wxWidgets-2.8.6.tar.gz
int main()
{
	wxInitialize();

  	wxFTP ftp;

    //if you don't use these lines anonymous login will be used
    //ftp.SetUser("user");
	ftp.SetUser(wxT("anonymous"));
    ftp.SetPassword(_T(""));
    //ftp.SetPassword("password");

    if ( !ftp.Connect(wxT("ftp.wxwindows.org")) )
    {
        wxLogError(wxT("Couldn't connect"));
        return 1;
    }

    //ftp.ChDir(_T("/pub"));
    wxInputStream *in = ftp.GetInputStream(_T("/pub/2.8.6/wxWidgets-2.8.6.tar.gz"));
    if ( !in )
    {
        wxLogError(wxT("Coudln't get file"));
    }
    else
    {
        size_t size = in->GetSize();
        char *data = new char[size];
        if ( !in->Read(data, size) )
        {
            wxLogError(wxT("Read error"));
        }
        else
        {
        }

        delete [] data;
        delete in;
    }
	if(! wxFileExists(wxT("wxWidgets-2.8.6.tar.gz")))
	{
		wxLogError(wxT("file download error\n"));
	}
	else
	{
		wxLogError(wxT("file download ok\n"));
	}


}

