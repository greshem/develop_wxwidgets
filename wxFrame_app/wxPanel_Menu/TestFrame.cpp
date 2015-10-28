#include "TestFrame.h"
#include <wx/msgdlg.h>
MyFrame5::MyFrame5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

//########################################################################

 	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
    m_menubar1 = new wxMenuBar( 0 );
    m_menu1 = new wxMenu();
    wxMenuItem* m_menuItem2;
    m_menuItem2 = new wxMenuItem( m_menu1, wxID_OPEN, wxString( wxT("Open") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu1->Append( m_menuItem2 );

    m_menubar1->Append( m_menu1, wxT("File") );

    m_menu2 = new wxMenu();
    wxMenuItem* m_menuItem3;
    m_menuItem3 = new wxMenuItem( m_menu2, wxID_UNDO, wxString( wxT("Undo") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu2->Append( m_menuItem3 );

    m_menubar1->Append( m_menu2, wxT("Edit") );

    m_menu3 = new wxMenu();
    wxMenuItem* m_menuItem4;
    m_menuItem4 = new wxMenuItem( m_menu3, wxID_VIEW1, wxString( wxT("View1") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu3->Append( m_menuItem4 );

    m_menubar1->Append( m_menu3, wxT("View") );

    m_menu4 = new wxMenu();
    wxMenuItem* m_menuItem1;
    m_menuItem1 = new wxMenuItem( m_menu4, wxID_TOOL1, wxString( wxT("Tool1") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu4->Append( m_menuItem1 );

    m_menubar1->Append( m_menu4, wxT("Tools") );

    m_menu5 = new wxMenu();
    wxMenuItem* m_menuItem5;
    m_menuItem5 = new wxMenuItem( m_menu5, wxID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
    m_menu5->Append( m_menuItem5 );

    m_menubar1->Append( m_menu5, wxT("Help") );

    this->SetMenuBar( m_menubar1 );
//	m_menu5->Connect( wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame5::Help_box ), NULL, this );
	this->Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame5::Help_box ));


//########################################################################
//添加 panel 里面的东西. 
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
	//########################################################################
	
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

void MyFrame5::Help_box( wxCommandEvent& event )
{
	wxMessageBox(wxT("impl"));	
}
