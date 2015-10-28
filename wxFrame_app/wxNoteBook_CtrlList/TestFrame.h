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
#include <wx/listctrl.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/html/htmlwin.h>

enum {
wxID_VIEW1=1000,
wxID_TOOL1=100,
//wxID_ABOUT = 100
};

struct StationListData
{
        wxString name;
        wxString age;
        wxString sex;
	wxString job;
};

class MyFrame1 : public wxFrame 
{
	DECLARE_EVENT_TABLE()
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
		wxListCtrl *m_listCtrl6;
		wxButton *m_button11;
		wxButton *m_button12;
		wxButton *m_button14;
		wxStatusBar* m_statusBar3;

		virtual void MessageBox( wxCommandEvent& event );
	
	public:
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 679,542 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~MyFrame1();
		void SetHeadText(wxListCtrl *);
		void InsertData(wxListCtrl *);
		void AddData(wxListCtrl *m_list, StationListData *data);
		void OnButtonClick( wxCommandEvent& event);
	
};

#endif //__noname__
