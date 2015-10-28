#include <wx/wx.h>
#include "wx/wxprec.h"
BEGIN_DECLARE_EVENT_TYPES()
//    DECLARE_LOCAL_EVENT_TYPE(wxEVT_MY_CUSTOM_COMMAND, 7777)
END_DECLARE_EVENT_TYPES()

DEFINE_EVENT_TYPE(wxEVT_MY_CUSTOM_COMMAND)

#define EVT_MY_CUSTOM_COMMAND(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( \
        wxEVT_MY_CUSTOM_COMMAND, id, wxID_ANY, \
        (wxObjectEventFunction)(wxEventFunction) wxStaticCastEvent( wxCommandEventFunction, &fn ), \
        (wxObject *) NULL \
    ),

class TestFrame : public wxFrame
{
public:
    TestFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    virtual ~TestFrame();

    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    void OnFireCustom(wxCommandEvent& event);

	void OnFireCustom_2(wxCommandEvent& WXUNUSED(event));
    void OnProcessCustom(wxCommandEvent& event);

protected:
    unsigned m_nPush;
private:
    DECLARE_EVENT_TABLE()
};
enum
{
    Event_Quit = 1,
    Event_About,
    Event_Connect,
    Event_Custom,
  Event_Custom_2,


};
