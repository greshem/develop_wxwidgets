#include "wx/wx.h"
#include "wx/image.h"
#include "wx/splash.h"
#include "wx/mediactrl.h"
#include <wx/frame.h>

class MyFrame : public wxFrame
{
public:
       MyFrame(const wxString& title);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
 private:
           DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_FILE,  MyFrame::OnQuit)
    EVT_MENU(wxID_HELP, MyFrame::OnAbout)
END_EVENT_TABLE()

enum
{
    Minimal_Run = wxID_HIGHEST + 1
};

MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
//	SetIcon(wxICON(sample));
	wxMenu *menuFile = new wxMenu;
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(wxID_HELP, _T("&About...\tF1"), _T("Show help frame"));

	menuFile->Append(wxID_FILE, _T("&File...\tAlt-X"), _T("Show file program"));

	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(menuFile, _T("&File"));
	menuBar->Append(helpMenu, _T("&About"));
	SetMenuBar(menuBar);
	Show(true);

 	CreateStatusBar(2);
 	SetStatusText(_T("Welcome to wxWidgets!"));
}

void MyFrame::OnQuit(wxCommandEvent & WXUNUSED(event))
{
 Close(true);
}

void MyFrame::OnAbout(wxCommandEvent & WXUNUSED(event))
{
    wxBitmap bitmap;
    if (bitmap.LoadFile(_T("splash.png"), wxBITMAP_TYPE_PNG))
    {
        wxImage image = bitmap.ConvertToImage();
        image.Rescale( bitmap.GetWidth()/2, bitmap.GetHeight()/2 );
        bitmap = wxBitmap(image);
        wxSplashScreen *splash = new wxSplashScreen(bitmap,
            wxSPLASH_CENTRE_ON_PARENT | wxSPLASH_NO_TIMEOUT,
            0, this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
            wxSIMPLE_BORDER|wxSTAY_ON_TOP);
        wxWindow *win = splash->GetSplashWindow();
#if wxUSE_MEDIACTRL
        wxMediaCtrl *media = new wxMediaCtrl( win, wxID_EXIT, _T("press.mpg"), wxPoint(2,2));
        media->Play();
#else
        wxStaticText *text = new wxStaticText( win, wxID_EXIT, _T("click somewhere\non image"), wxPoint(13,11) );
        text->SetBackgroundColour(*wxWHITE);
        text->SetForegroundColour(*wxBLACK);
        wxFont font = text->GetFont();
        font.SetPointSize(2*font.GetPointSize()/3);
        text->SetFont(font);
#endif
    }
}

