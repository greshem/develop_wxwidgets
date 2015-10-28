#pragma once
#include <wx/dialog.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include "MyTextCtrl.h"


class LoginDlg : public wxDialog
{
	DECLARE_EVENT_TABLE()
public:
	LoginDlg(wxWindow* parent = NULL, wxWindowID id = wxID_ANY, const wxString& title = _("login"), 
		const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 450,600 ), 
		long style = wxDEFAULT_DIALOG_STYLE, const wxString& name = _("login") );
	~LoginDlg(void);

	bool GetItemSetOk();

private:
	void OnButtonClickOK( wxCommandEvent& event );
	void OnButtonClickCancel( wxCommandEvent& event );
	void WxComboBoxUseConnectSelected(wxCommandEvent& event );

	bool CheckUserNameValid();
	bool CheckServerIPValid();
	bool CheckPasswordValid();
	long IpStringToDword(const wxString &s);

	bool CheckCtrlValueValid();

private:
	wxComboBox	   *m_WxComboBoxUseConnect;
	MyTextCtrl	   *m_WxMyTextServerIP;
	wxTextCtrl	   *m_WxTextUserName;
	wxTextCtrl	   *m_WxTextPassword;	
	wxButton 		*m_WxButtonOK;
	wxButton 		*m_WxButtonCancel;

	bool			m_bItemSetOk;
private:
	enum{
		ID_WXCOMBOBOX_USE_CONNECT = 1044,
	};
};
