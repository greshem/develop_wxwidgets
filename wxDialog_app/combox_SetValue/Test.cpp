//you are Test
#include "Test.h"

///////////////////////////////////////////////////////////////////////////
TestDialog::TestDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );

	//°´Å¥	
	m_button2 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_button2, 0, wxALL, 5 );

	//combox	
	m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_comboBox1->SetValue(wxT("bbb"));
	m_comboBox1->SetValue(wxT("bbb2"));
	m_comboBox1->SetValue(wxT("bbb3"));
	m_comboBox1->SetValue(wxT("bbb4"));
	m_comboBox1->SetValue(wxT("bbb5"));
	sbSizer1->Add( m_comboBox1, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
}

TestDialog::~TestDialog()
{
}



