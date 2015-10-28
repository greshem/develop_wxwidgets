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
//#include <windows.h>
#define IN  
#define OUT 
#define DWORD unsigned long 
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
 		wxTextCtrl *WxTextCtrlLog ;
	

	public:
		TestDialog ( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~TestDialog ();
	void OnButtonClickOK( wxCommandEvent& event );
	void OnButtonClickCancel( wxCommandEvent& event );
	void OnButtonSelect( wxCommandEvent& event );
	DWORD	EncodeUTF8(  IN  char	*lpszSource,IN  DWORD dwSourceCodePage, OUT char	*lpszTarget,IN  DWORD		dwTargetCodePage );
//	long  EncodeUTF8(char *,long,  char *,long);
	private:
	enum{
		ID_WXBUTTON_ONE=1044,
		ID_WXTEXTCTRL_LOG=1055,
	};
};

#endif //Test_header

