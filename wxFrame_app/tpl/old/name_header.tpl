// [% name %] dialog

#ifndef __[%name%]__header
#define __[%name%]__header


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
/// Class [%name%]Dialog 
///////////////////////////////////////////////////////////////////////////////
class [%name%]Dialog : public wxDialog 
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
		[%name%]Dialog ( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~[%name%]Dialog ();
	void OnButtonClickOK( wxCommandEvent& event );
	void OnButtonClickCancel( wxCommandEvent& event );
	void OnButtonSelect( wxCommandEvent& event );



	private:
	enum{
		ID_WXBUTTON_ONE=1044,
	};
};

#endif //[%name%]_header

