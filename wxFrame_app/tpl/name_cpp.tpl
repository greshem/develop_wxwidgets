///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "[%name%]Frame.h"
#include <wx/msgdlg.h>
#include <wx/timer.h>
#include <wx/event.h>




///////////////////////////////////////////////////////////////////////////

BEGIN_EVENT_TABLE([%name%]Frame, wxFrame)
	//系统菜单, 响应函数.  
	EVT_MENU(wxID_VIEW1, [%name%]Frame::OnView) 						//( wxCommandEvent& event )
	EVT_BUTTON(wxID_BUTTON1, [%name%]Frame::OnButton1) 		//( wxCommandEvent& event )
	EVT_BUTTON(wxID_BUTTON2, [%name%]Frame::OnButton2) 		//( wxCommandEvent& event )
	EVT_BUTTON(wxID_BUTTON3, [%name%]Frame::OnButton3) 		//( wxCommandEvent& event )
	//EVT_CHOICE(ID_CHOICE_LOG_FILE, [%name%]Frame::OnLogFileChoice) 	//( wxCommandEvent& event )
	EVT_TIMER (wxID_TIMER, [%name%]Frame::OnTimer)						//( wxTimerEvent & event )

END_EVENT_TABLE()


[%name%]Frame::[%name%]Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
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
	//menu部分结束.
	//==========================================================================

	//==========================================================================
	//3个巨大的button
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button2 = new wxButton( this, wxID_BUTTON1, wxT("MyButton"), wxDefaultPosition, wxSize( 500,100 ), 0 );
	bSizer2->Add( m_button2, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );
	
	m_button16 = new wxButton( this, wxID_BUTTON2, wxT("MyButton"), wxDefaultPosition, wxSize( 500,100 ), 0 );
	sbSizer1->Add( m_button16, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_button17 = new wxButton( this, wxID_BUTTON3, wxT("MyButton"), wxDefaultPosition, wxSize( 500,100 ), 0 );
	bSizer4->Add( m_button17, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	//3个巨大的button
	//==========================================================================
	
	this->SetSizer( bSizer1 );
	this->Layout();


	//定时器.
	wxTimer *timer= new wxTimer(this, wxID_TIMER);
	timer->Start(1000);  
}

[%name%]Frame::~[%name%]Frame()
{
}
void [%name%]Frame::OnView ( wxCommandEvent& event )
{
	wxMessageBox(wxT("onView"));
}

void [%name%]Frame::OnButton1 ( wxCommandEvent& event )
{
	wxMessageBox(wxT("onButton1"));
}

void [%name%]Frame::OnButton2 ( wxCommandEvent& event )
{
	wxMessageBox(wxT("onButton2"));
}
void [%name%]Frame::OnButton3( wxCommandEvent& event )
{
	wxMessageBox(wxT("onButton3"));
}


void [%name%]Frame::OnTimer ( wxTimerEvent & event )
{
	wxMessageBox(wxT("onTimer"));
}


