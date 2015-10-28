///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __[%name%]Frame_header__
#define __[%name%]Frame_header__


#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/timer.h>
#include <wx/event.h>



///////////////////////////////////////////////////////////////////////////

#define wxID_VIEW1 1000
#define wxID_TOOL1 1001

#define wxID_BUTTON1 8001
#define wxID_BUTTON2 8002
#define wxID_BUTTON3 8003

#define wxID_TIMER	 9004
///////////////////////////////////////////////////////////////////////////////
/// Class [%name%]Frame
///////////////////////////////////////////////////////////////////////////////
class [%name%]Frame : public wxFrame 
{
private:
	DECLARE_EVENT_TABLE()   
protected:
	wxStatusBar* m_statusBar1;
	wxMenuBar* m_menubar1;
	wxMenu* m_menu1;
	wxMenu* m_menu2;
	wxMenu* m_menu3;
	wxMenu* m_menu4;
	wxMenu* m_menu5;
	wxButton* m_button2;
	wxButton* m_button16;
	wxButton* m_button17;
	
public:
	[%name%]Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 818,552 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
	~[%name%]Frame();
	
	
	void OnView ( wxCommandEvent& event );
	void OnButton1 ( wxCommandEvent& event );
	void OnButton2 ( wxCommandEvent& event );
	void OnButton3 ( wxCommandEvent& event );
	void OnTimer ( wxTimerEvent & event );


};

#endif //__[%name%]Frame_header__

