#include "TestFrame.h"
#include <wx/msgdlg.h>
#include <wx/timer.h>
#include <wx/event.h>


BEGIN_EVENT_TABLE(TestFrame, wxFrame)
    EVT_MENU(Event_Quit, TestFrame::OnQuit)
    EVT_MENU(Event_About, TestFrame::OnAbout)

    //EVT_MENU(Event_Connect, TestFrame::OnConnect)
    EVT_MENU(Event_Connect, TestFrame::OnProcessCustom)

    EVT_MENU(Event_Custom, TestFrame::OnFireCustom)
    EVT_MENU(Event_Custom_2, TestFrame::OnFireCustom_2)
    EVT_MY_CUSTOM_COMMAND(wxID_ANY, TestFrame::OnProcessCustom)

END_EVENT_TABLE()

//BEGIN_EVENT_TABLE(MyEvtHandler, wxEvtHandler)
//    EVT_MENU(Event_Test, MyEvtHandler::OnTest)
//END_EVENT_TABLE()
TestFrame::TestFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
       : wxFrame((wxFrame *)NULL, wxID_ANY, title, pos, size)
{
    m_nPush = 0;
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(Event_About, _T("&About...\tCtrl-A"), _T("Show about dialog"));
    menuFile->AppendSeparator();
    menuFile->Append(Event_Quit, _T("E&xit\tAlt-X"), _T("Quit this program"));

    wxMenu *menuEvent = new wxMenu;
    menuEvent->Append(Event_Connect, _T("&Connect\tCtrl-C"),
                     _T("Connect or disconnect the dynamic event handler"),
                     true /* checkable */);
    menuEvent->Append(Event_Custom, _T("Fire c&ustom event\tCtrl-U"),_T("Generate a custom event"));
    menuEvent->Append(Event_Custom_2, _T("Fire c&ustom event\tCtrl-U"),_T("Generate a custom event"));
  wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(menuFile, _T("&File"));
    menuBar->Append(menuEvent, _T("&Event"));
  SetMenuBar(menuBar);

}

TestFrame::~TestFrame()
{
    while ( m_nPush-- != 0 )
    {
        PopEventHandler(true /* delete handler */);
    }
}

void TestFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void TestFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
}

void TestFrame::OnFireCustom(wxCommandEvent& WXUNUSED(event))
{
    wxCommandEvent eventCustom(wxEVT_MY_CUSTOM_COMMAND);

    wxPostEvent(this, eventCustom);
}
void TestFrame::OnFireCustom_2(wxCommandEvent& WXUNUSED(event))
{
    wxCommandEvent eventCustom(wxEVT_MY_CUSTOM_COMMAND);

    wxPostEvent(this, eventCustom);
}

void TestFrame::OnProcessCustom(wxCommandEvent& WXUNUSED(event))
{
    wxLogMessage(_T("Got a custom event!"));
}
