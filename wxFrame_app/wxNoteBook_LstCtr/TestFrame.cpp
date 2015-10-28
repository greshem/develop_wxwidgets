#include "TestFrame.h"
#include <wx/msgdlg.h>
#include <wx/menu.h>
#include <wx/listctrl.h>

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

/////////////////////////////////MENU/////////////////////////////////////	

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

/////////////////////////////////MENU/////////////////////////////////////	

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALL, 5 );
	
	
	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText3->Wrap( -1 );
	bSizer2->Add( m_staticText3, 0, wxALL, 5 );
	
	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	m_notebook2->AddPage( m_panel1, wxT("a page"), false );
	m_panel2 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_button3 = new wxButton( m_panel2, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button3, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer14, 1, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	m_notebook2->AddPage( m_panel2, wxT("a page"), false );
	m_panel4 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_button5 = new wxButton( m_panel4, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button5, 0, wxALL, 5 );
	
	m_button6 = new wxButton( m_panel4, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button6, 0, wxALL, 5 );
	
	bSizer4->Add( bSizer15, 1, wxEXPAND, 5 );
	
	m_panel4->SetSizer( bSizer4 );
	m_panel4->Layout();
	bSizer4->Fit( m_panel4 );
	m_notebook2->AddPage( m_panel4, wxT("a page"), true );
	m_panel5 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
//------------------------------------------------------------------------
	m_listCtrl1 = new wxListCtrl( m_panel5, wxID_ANY, wxDefaultPosition, wxSize( 630,250 ), wxLC_ICON|wxLC_REPORT );

	/////////增加list头部的数据
	 long    nPos = 0;
    wxListItem Item;
    Item.SetText( _("Mac") );
    m_listCtrl1->InsertColumn( nPos, Item );
    m_listCtrl1->SetColumnWidth( nPos++, 140 );

    Item.SetText( _("IP") );
    m_listCtrl1->InsertColumn( nPos, Item );
    m_listCtrl1->SetColumnWidth( nPos++, 90 );

    Item.SetText( _("ConnectStatus") );
    m_listCtrl1->InsertColumn( nPos, Item );
    m_listCtrl1->SetColumnWidth( nPos++, 120 );

    Item.SetText( _("ProcessID") );
    m_listCtrl1->InsertColumn( nPos, Item );
    m_listCtrl1->SetColumnWidth( nPos++, 100 );

    Item.SetText( _("ConnectTime") );
    m_listCtrl1->InsertColumn( nPos, Item );
    m_listCtrl1->SetColumnWidth( nPos++, 90 );

    //Item.SetText( _("LoginUser") );
    Item.SetText( _("command_line") );
    m_listCtrl1->InsertColumn( nPos, Item );
    //设置长度, list 一个 row  的长度. 
    m_listCtrl1->SetColumnWidth( nPos++, 180 );
   /////////头部数据增加结束

//-----------------在列表中添加数据-------------------------------------------------------

	 StationListData data;
     wxString msg;
	 int count =1;
     msg.Printf(wxT(" aa:bb:cc:dd:ee:%d"), count);
  	 	data.mac =msg;
     msg.Printf(wxT("192.168.1.%d"), count);
     	data.ip = wxT("192.158.1.1");
     msg.Printf(wxT("fauluer_%d"), count);
     	data.connectStatus = msg;
     msg.Printf(wxT("%d"), count);
     	data.processId = msg;
        //msg.Printf(wxT("%s"),  cmdline);
     msg.Printf(wxT("%d"), count);
     	data.connectTime = msg;
     //wxString cmdline(it->cmdline, wxConvUTF8);
     //	data.loginUser = cmdline;
	data.loginUser = msg;

 	 nPos = m_listCtrl1->GetItemCount();
    long    nSubPos = 1;
    m_listCtrl1->InsertItem(nPos, data.mac);
    m_listCtrl1->SetItem(nPos, nSubPos++, data.ip);
    m_listCtrl1->SetItem(nPos, nSubPos++, data.connectStatus);
    m_listCtrl1->SetItem(nPos, nSubPos++, data.processId);
    m_listCtrl1->SetItem(nPos, nSubPos++, data.connectTime);
    m_listCtrl1->SetItem(nPos, nSubPos++, data.loginUser);

//------------------------------------------------------------------------
	bSizer6->Add( m_listCtrl1, 0, wxALL, 5 );
//------------------------------------------------------------------------
	m_panel5->SetSizer( bSizer6 );
	m_panel5->Layout();
	bSizer6->Fit( m_panel5 );
	m_notebook2->AddPage( m_panel5, wxT("a page"), false );
	
	bSizer1->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar3 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	//connect events
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::MessageBox ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	 	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::MessageBox ), NULL, this );
}
void MyFrame1::MessageBox( wxCommandEvent& event )
{
	 wxMessageBox(wxT("Hello World!"));	
}

