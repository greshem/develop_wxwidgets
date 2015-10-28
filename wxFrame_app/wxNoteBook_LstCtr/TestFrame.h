#ifndef __noname__
#define __noname__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
enum {
wxID_VIEW1=1000,
wxID_TOOL1=100,
//wxID_ABOUT = 100
};

struct StationListData 
{
    wxString mac;
    wxString ip; 
    wxString connectStatus;
    wxString processId;
    wxString connectTime;
    wxString loginUser;
};


class MyFrame1 : public wxFrame 
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
	
	
		wxNotebook* m_notebook2;
		wxPanel* m_panel1;
		wxStaticText* m_staticText2;
		
		wxStaticText* m_staticText3;
		wxPanel* m_panel2;
		
		wxButton* m_button3;
		wxPanel* m_panel4;
		
		wxButton* m_button5;
		wxButton* m_button6;
		wxPanel* m_panel5;
		wxStatusBar* m_statusBar3;
		
		wxListCtrl* m_listCtrl1;
		virtual void MessageBox( wxCommandEvent& event );
	
	public:
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 679,542 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MyFrame1();
	
};

#endif //__noname__
