#ifndef __noname__
#define __noname__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
enum {
wxID_VIEW1=1000,
wxID_TOOL1=100,
//wxID_ABOUT = 100
}; 
class MyFrame5 : public wxFrame 
{
	private:
	
	protected:

		wxStatusBar* m_statusBar1;
	    wxMenuBar* m_menubar1;
    	wxMenu* m_menu1;
    	wxMenu* m_menu2;
    	wxMenu* m_menu3;
    	wxMenu* m_menu4;
    	wxMenu* m_menu5;


		wxPanel* m_panel3;
		wxStaticText* m_staticText2;
		
		wxCheckBox* m_checkBox2;
		wxCheckBox* m_checkBox3;
		
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl1;
		wxButton* m_button30;
		
		// Virtual event handlers, overide them in your derived class
		//virtual void MessageBox( wxCommandEvent& event ){ event.Skip(); }
		virtual void MessageBox( wxCommandEvent& event );
		virtual void Help_box( wxCommandEvent& event );
		
	
	public:
		MyFrame5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 536,379 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MyFrame5();
	
};

#endif //__noname__

