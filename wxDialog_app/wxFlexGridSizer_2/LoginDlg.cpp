//登陆画面. 
#include "LoginDlg.h"
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/msgdlg.h>

BEGIN_EVENT_TABLE(LoginDlg, wxDialog)
EVT_BUTTON(wxID_OK, LoginDlg::OnButtonClickOK)
EVT_BUTTON(wxID_CANCEL, LoginDlg::OnButtonClickCancel)
EVT_COMBOBOX(ID_WXCOMBOBOX_USE_CONNECT,LoginDlg::WxComboBoxUseConnectSelected)
END_EVENT_TABLE()


LoginDlg::LoginDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) 
: wxDialog( parent, id, title, pos, size, style, name )
, m_bItemSetOk(TRUE)
{
	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	// 4x2  的布局
	wxFlexGridSizer *flexGridSizer = new wxFlexGridSizer(4, 2, 0, 0);
	flexGridSizer->AddGrowableCol(1);
	sizer->Add(flexGridSizer, 0, wxEXPAND);

	wxArrayString			strArrayConnect;
	strArrayConnect.Add(_("Local connect"));
	strArrayConnect.Add(_("Remote connect"));
	wxStaticText *m_WxStaticText1 = new wxStaticText(this, wxID_ANY, _("use connect:"), wxDefaultPosition, wxDefaultSize, 0, wxT("WxStaticText1"));
	m_WxComboBoxUseConnect = new wxComboBox(this, ID_WXCOMBOBOX_USE_CONNECT, wxT(""), wxDefaultPosition, wxSize( 160,21 ), strArrayConnect, wxCB_READONLY | wxWANTS_CHARS, wxDefaultValidator, wxT("m_ComBoxNode"));
	m_WxComboBoxUseConnect->Select(0);
	flexGridSizer->Add(m_WxStaticText1, 0, wxALL, 10);
	flexGridSizer->Add(m_WxComboBoxUseConnect, 0, wxALL, 10);


	wxStaticText *WxStaticText2 = new wxStaticText(this, wxID_ANY, _("server IP:"), wxDefaultPosition, wxDefaultSize, 0, wxT("WxStaticText1"));
	m_WxMyTextServerIP = new MyTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 160,21 ), wxTE_LEFT );
	flexGridSizer->Add(WxStaticText2, 0, wxALL, 10);
	flexGridSizer->Add(m_WxMyTextServerIP, 0, wxALL, 10);
	wxString strValue = m_WxComboBoxUseConnect->GetValue();
	if (strValue == _("Local connect"))
	{
		m_WxMyTextServerIP->SetValue(wxT("127.0.0.1"));
		m_WxMyTextServerIP->Enable(FALSE);
	}

	wxStaticText *WxStaticText3 = new wxStaticText(this, wxID_ANY, _("user name:"), wxDefaultPosition, wxDefaultSize, 0, wxT("WxStaticText1"));
	m_WxTextUserName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 160,21 ), wxTE_LEFT );
	flexGridSizer->Add(WxStaticText3, 0, wxALL, 10);
	flexGridSizer->Add(m_WxTextUserName, 0, wxALL, 10);

	wxStaticText *WxStaticText4 = new wxStaticText(this, wxID_ANY, _("password:"), wxDefaultPosition, wxDefaultSize, 0, wxT("WxStaticText1"));
	m_WxTextPassword = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 160,21 ), wxTE_PASSWORD );
	flexGridSizer->Add(WxStaticText4, 0, wxALL, 10);
	flexGridSizer->Add(m_WxTextPassword, 0, wxALL, 10);


	wxBoxSizer *Sizer7 = new wxBoxSizer( wxHORIZONTAL );
	m_WxButtonOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
	m_WxButtonCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
	Sizer7->Add(m_WxButtonOK, 0, wxALL, 10);
	Sizer7->Add(m_WxButtonCancel, 0, wxALL, 10);
	sizer->Add(Sizer7, 0, wxALIGN_CENTRE);
	//########################################################################
	//第五列
	wxBoxSizer *Sizer8 = new wxBoxSizer( wxHORIZONTAL );
	m_WxButtonOK = new wxButton(this, wxID_OK, _("OK_null"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
	m_WxButtonCancel = new wxButton(this, wxID_CANCEL, _("Cancel_null"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
	Sizer8->Add(m_WxButtonOK, 0, wxALL, 10);
	Sizer8->Add(m_WxButtonCancel, 0, wxALL, 10);
	sizer->Add(Sizer8, 0, wxALIGN_CENTRE);
	//########################################################################


	SetSizer(sizer);
	sizer->Fit( this );
	sizer->SetSizeHints( this );
}

LoginDlg::~LoginDlg(void)
{
}

void LoginDlg::OnButtonClickOK( wxCommandEvent& event )
{
	if (!CheckCtrlValueValid())
	{
		m_bItemSetOk = FALSE;
		return;
	}
	else
	{
		m_bItemSetOk = TRUE;
	}

	wxDialog::EndModal(wxID_OK);
}
void LoginDlg::OnButtonClickCancel( wxCommandEvent& event )
{
	wxDialog::EndModal(wxID_CANCEL);
	exit(-1);
}

void LoginDlg::WxComboBoxUseConnectSelected(wxCommandEvent& event )
{
	// insert your code here
	wxString strValue = m_WxComboBoxUseConnect->GetValue();
	if (strValue == _("Local connect"))
	{
		m_WxMyTextServerIP->SetValue(wxT("127.0.0.1"));
		m_WxMyTextServerIP->Enable(FALSE);
	}
	else
	{
		m_WxMyTextServerIP->SetValue(wxT(""));
		m_WxMyTextServerIP->Enable(TRUE);
	}
}

bool LoginDlg::CheckUserNameValid()
{
	wxString strUserName = m_WxTextUserName->GetValue();
	strUserName.Replace( wxT(" "), wxT("") );
	if( strUserName.length() == 0 )
	{
		wxMessageBox( _("user name can't is null!"),_("error"), wxOK | wxICON_INFORMATION, NULL);
		m_WxTextUserName->SetFocus();
		return FALSE;
	}

	//这里添加用户名的有效性


	return TRUE;
}

//check 服务器ip是否有效
bool LoginDlg::CheckServerIPValid()
{
	wxString strIP = m_WxMyTextServerIP->GetValue();
	strIP.Replace( wxT(" "), wxT("") );

	if( strIP.length() == 0 )
	{
		wxMessageBox( _("IP can't is null!"),_("error"), wxOK | wxICON_INFORMATION, NULL);
		m_WxMyTextServerIP->SetFocus();
		return FALSE;
	}

	long	dwIP = IpStringToDword( strIP );
	if( dwIP == 0 )
	{
		wxMessageBox( _("IP error,please re-entry!"),_("error"), wxOK | wxICON_INFORMATION, NULL);
		m_WxMyTextServerIP->SetFocus();
		return FALSE;
	}

	return TRUE;
}

//passwd验证.
bool LoginDlg::CheckPasswordValid()
{
	wxString strPassword = m_WxTextPassword->GetValue();
	strPassword.Replace( wxT(" "), wxT("") );

	if( strPassword.length() == 0 )
	{
		wxMessageBox( _("password can't is null!"),_("error"), wxOK | wxICON_INFORMATION, NULL);
		m_WxTextPassword->SetFocus();
		return FALSE;
	}

	//fixme这里添加密码的正确性

	return TRUE;
}

//检查所有的控件的是否有效.
bool LoginDlg::CheckCtrlValueValid()
{
	if( !CheckUserNameValid() )
		return FALSE;

	if( !CheckServerIPValid() )
		return FALSE;

	if( !CheckPasswordValid() )
		return FALSE;

	return TRUE;
}

//ip字符串转int.
long LoginDlg::IpStringToDword(const wxString &s)
{
	wxString IpString = s;

	long val;

	long Result = 1;
	for (int i = 3; i >= 0; i--)
	{
		if (i > 0 && IpString.Find('.') == wxNOT_FOUND)
			return 0;
		if (!IpString.BeforeFirst('.').ToLong(&val))
			return 0;
		if (val>255)
			return 0;
		Result |= val << (8*i);
		IpString = IpString.AfterFirst('.');
	}
	if (IpString.compare(wxT("")) != 0)
		return 0;

	return Result;
}

bool LoginDlg::GetItemSetOk()
{
	return m_bItemSetOk;
}



