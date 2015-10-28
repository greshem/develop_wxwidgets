// Test dialog

#ifndef __Test__header_show
#define __Test__header_show


#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class TestShow 
///////////////////////////////////////////////////////////////////////////////
class TestShow : public wxDialog 
{
 DECLARE_EVENT_TABLE()

	private:
		wxString filename;	
	protected:
		wxButton* m_button2;
		wxComboBox* m_comboBox1;

	    wxButton *WxButtonSelect;                                                                       
    	wxButton *WxButtonOK;
    	wxButton *WxButtonCancel; 
 		wxTextCtrl *WxTextCtrlLog ;
	

	public:
		TestShow (wxString, wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE);
		~TestShow ();
	void OnButtonClickOK( wxCommandEvent& event );
	void OnButtonClickCancel( wxCommandEvent& event );
	void OnButtonSelect( wxCommandEvent& event );



	private:
	enum{
		ID_WXBUTTON_ONE=1044,
		ID_WXTEXTCTRL_LOG=1055,
	};
};

#endif //Test_header

