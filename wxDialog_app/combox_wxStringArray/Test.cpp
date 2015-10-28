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
	// m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	// m_comboBox1->SetValue(wxT("bbb"));
	// m_comboBox1->SetValue(wxT("bbb2"));
	// m_comboBox1->SetValue(wxT("bbb3"));
	// m_comboBox1->SetValue(wxT("bbb4"));
	// m_comboBox1->SetValue(wxT("bbb5"));
	
	wxArrayString m_DiskCharComboStrings;
	m_DiskCharComboStrings.Add(_T("C:"));
	m_DiskCharComboStrings.Add(_T("D:"));
	m_DiskCharComboStrings.Add(_T("E:"));
	m_DiskCharComboStrings.Add(_T("F:"));
	m_DiskCharComboStrings.Add(_T("G:"));
	m_DiskCharComboStrings.Add(_T("H:"));
	m_DiskCharComboStrings.Add(_T("I:"));
	m_DiskCharComboStrings.Add(_T("J:"));
	m_DiskCharComboStrings.Add(_T("K:"));
	m_DiskCharComboStrings.Add(_T("L:"));
	m_DiskCharComboStrings.Add(_T("M:"));
	m_DiskCharComboStrings.Add(_T("N:"));
	m_DiskCharComboStrings.Add(_T("O:"));
	m_DiskCharComboStrings.Add(_T("P:"));
	m_DiskCharComboStrings.Add(_T("Q:"));
	m_DiskCharComboStrings.Add(_T("R:"));
	m_DiskCharComboStrings.Add(_T("S:"));
	m_DiskCharComboStrings.Add(_T("T:"));
	m_DiskCharComboStrings.Add(_T("U:"));
	m_DiskCharComboStrings.Add(_T("V:"));
	m_DiskCharComboStrings.Add(_T("W:"));
	m_DiskCharComboStrings.Add(_T("X:"));
	m_DiskCharComboStrings.Add(_T("Y:"));
	m_DiskCharComboStrings.Add(_T("Z:"));

    m_comboBox1= new wxComboBox( this, wxID_ANY, _T(""), wxDefaultPosition, wxSize(120, -1), m_DiskCharComboStrings, wxCB_READONLY );
	m_comboBox1->SetValue(wxT("disk name "));
    //itemFlexGridSizer4->Add(m_DiskCharCombo, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);
    
	sbSizer1->Add( m_comboBox1, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
}

TestDialog::~TestDialog()
{
}



