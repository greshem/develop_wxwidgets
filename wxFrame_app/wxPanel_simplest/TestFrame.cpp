#include "TestFrame.h"
#include <wx/msgdlg.h>
MyFrame5::MyFrame5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( m_panel3, wxID_ANY, wxT("These are general settings."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer8->Add( m_staticText2, 0, wxALL, 5 );
	
	
	bSizer8->Add( 0, 0, 1, wxALIGN_TOP|wxEXPAND, 5 );
	
	m_checkBox2 = new wxCheckBox( m_panel3, wxID_ANY, wxT("Option 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox2->SetValue(true);
	
	bSizer8->Add( m_checkBox2, 0, wxALL, 5 );
	
	m_checkBox3 = new wxCheckBox( m_panel3, wxID_ANY, wxT("Option 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBox3->SetValue(true);
	
	bSizer8->Add( m_checkBox3, 0, wxALL, 5 );
	
	
	bSizer8->Add( 0, 0, 1, 0, 3 );
	
	m_staticText3 = new wxStaticText( m_panel3, wxID_ANY, wxT("Log filename:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer8->Add( m_staticText3, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl1 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_textCtrl1, 0, wxALL, 5 );
	
	m_button30 = new wxButton( m_panel3, wxID_ANY, wxT("Browse..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button30, 0, wxALL, 5 );
	
	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );
	
	m_panel3->SetSizer( bSizer8 );
	m_panel3->Layout();
	bSizer8->Fit( m_panel3 );
	bSizer7->Add( m_panel3, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer7 );
	this->Layout();
	m_button30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame5::MessageBox ), NULL, this );
}

MyFrame5::~MyFrame5()
{
	// Disconnect Events
	m_button30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame5::MessageBox ), NULL, this );
}

void MyFrame5::MessageBox( wxCommandEvent& event )
{
	wxMessageBox(wxT("impl"));	
}
