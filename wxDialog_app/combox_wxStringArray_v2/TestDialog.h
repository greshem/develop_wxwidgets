// Test dialog

#ifndef __Test__header
#define __Test__header


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
/// Class TestDialog 
///////////////////////////////////////////////////////////////////////////////
class TestDialog : public wxDialog 
{
 DECLARE_EVENT_TABLE()

	private:
	
	protected:
		wxButton* m_button2;
		wxComboBox* m_comboBox1;

	    wxButton *WxButtonSelect;                                                                       
    	wxButton *WxButtonOK;
    	wxButton *WxButtonCancel; 
	
	public:
		TestDialog ( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~TestDialog ();
	void OnButtonClickOK( wxCommandEvent& event );
	void OnButtonClickCancel( wxCommandEvent& event );
	void OnButtonSelect( wxCommandEvent& event );
	void OnComboBoxUpdate ( wxCommandEvent& event );




	private:
	enum{
		ID_WXBUTTON_ONE=1044,
		ID_COMBOX=1088,
	};
};

#endif //Test_header

