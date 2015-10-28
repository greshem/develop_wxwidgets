#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/image.h"
#include "wx/splash.h"
#include "wx/mediactrl.h"


#if !defined(__WXMSW__) && !defined(__WXPM__)
//    #include "../sample.xpm"
#endif

/*
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
*/
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title);

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

private:
    DECLARE_EVENT_TABLE()
};

enum
{
    Minimal_Run = wxID_HIGHEST + 1
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MyFrame::OnQuit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
END_EVENT_TABLE()

//IMPLEMENT_APP(MyApp)
/*
bool MyApp::OnInit()
{
    wxImage::AddHandler(new wxPNGHandler);

    MyFrame *frame = new MyFrame(_T("wxSplashScreen sample application"));

    wxBitmap bitmap;
    if (bitmap.LoadFile(_T("splash.png"), wxBITMAP_TYPE_PNG))
    {
        new wxSplashScreen(bitmap,
            wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
            6000, frame, wxID_ANY, wxDefaultPosition, wxDefaultSize,
            wxSIMPLE_BORDER|wxSTAY_ON_TOP);
    }
    wxYield();
    frame->Show(true);

    return true;
}
*/
MyFrame::MyFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title)
{
//    SetIcon(wxICON(sample));

#if wxUSE_MENUS
    wxMenu *menuFile = new wxMenu;

    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, _T("&About...\tF1"), _T("Show about frame"));

    menuFile->Append(wxID_EXIT, _T("E&xit\tAlt-X"), _T("Quit this program"));

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuFile, _T("&File"));
    menuBar->Append(helpMenu, _T("&Help"));

    SetMenuBar(menuBar);
#endif

#if wxUSE_STATUSBAR
    CreateStatusBar(2);
    SetStatusText(_T("Welcome to wxWidgets!"));
#endif
}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
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
