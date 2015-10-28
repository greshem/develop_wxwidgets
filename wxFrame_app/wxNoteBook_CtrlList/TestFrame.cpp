#include "TestFrame.h"
#include <wx/msgdlg.h>
#include <wx/menu.h>

BEGIN_EVENT_TABLE(MyFrame1, wxFrame)
EVT_BUTTON(wxID_OK, MyFrame1::OnButtonClick)
END_EVENT_TABLE()

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
    //menu²¿·Ö½áÊø.

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
	m_notebook2->AddPage( m_panel1, wxT("page 1"), false );
	m_panel2 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	m_button3 = new wxButton( m_panel2, wxID_ANY, wxT("Button 1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button3, 0, wxALL, 5 );
	
	bSizer3->Add( bSizer14, 1, wxEXPAND, 5 );
	
	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	m_notebook2->AddPage( m_panel2, wxT("page 2"), false );
	m_panel4 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxHtmlWindow* item = new wxHtmlWindow( m_panel4, wxID_ANY, wxDefaultPosition, wxSize(200, 130), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxHSCROLL|wxVSCROLL );
    item->SetPage(_("<h3>wxFrame Demo</h3>\n\nThis demonstrates a wxFrame containing a wxListBox, which itself contains a wxListBox and a wxHtmlWindow. There's also a wxMenuBar,wxToolBar and wxStatusBar."));
    //middleSizer30->Add(item, 0, wxALL, 10);
	
	bSizer4->Add( item, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button5 = new wxButton( m_panel4, wxID_OK, wxT("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button6 = new wxButton( m_panel4, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer4->Add( bSizer15, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel4->SetSizer( bSizer4 );
	m_panel4->Layout();
	bSizer4->Fit( m_panel4 );
	m_notebook2->AddPage( m_panel4, wxT("page 3"), true );
	m_panel5 = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	//m_listCtrl6 = new wxListCtrl(m_panel5, 1035, wxDefaultPosition, wxSize(600,400), wxLC_REPORT);
	m_listCtrl6 = new wxListCtrl( m_panel5, wxID_ANY, wxDefaultPosition, wxSize( 300,200 ), wxLC_REPORT );
	
	SetHeadText(m_listCtrl6);

	InsertData(m_listCtrl6);

	bSizer6->Add( m_listCtrl6, 0, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button11 = new wxButton( m_panel5, wxID_ANY, wxT("Add"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	bSizer16->Add( m_button11, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button12 = new wxButton( m_panel5, wxID_ANY, wxT("Modify"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button12, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button14 = new wxButton( m_panel5, wxID_OK, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_button14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer6->Add( bSizer16, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel5->SetSizer( bSizer6 );
	m_panel5->Layout();
	bSizer6->Fit( m_panel5 );
	m_notebook2->AddPage( m_panel5, wxT("page 4"), true );
	
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

void MyFrame1::SetHeadText(wxListCtrl *m_list)
{
	long    nPos = 0;
    wxListItem Item;

    Item.SetText( _("Name") );
   	m_list->InsertColumn( nPos, Item );
    m_list->SetColumnWidth( nPos++, 110 );

    Item.SetText( _("Age") );
    m_list->InsertColumn( nPos, Item );
    m_list->SetColumnWidth( nPos++, 110 );

    Item.SetText( _("Sex") );
    m_list->InsertColumn( nPos, Item );
    m_list->SetColumnWidth( nPos++, 110 );

    Item.SetText( _("Job") );
    m_list->InsertColumn( nPos, Item );
    m_list->SetColumnWidth( nPos++, 110 );

	return;
}

void MyFrame1::InsertData(wxListCtrl *m_list)
{
	int i = 0, count = 0;
	for(i = 0; i <= 6; i++)
        {
                StationListData data;
                wxString msg;
                msg.Printf(wxT("name_%d"), count);
                        data.name =msg;
                msg.Printf(wxT("age_%d"), count);
                        data.age = msg;
                msg.Printf(wxT("sex_%d"), count);
                        data.sex = msg;
		msg.Printf(wxT("job_%d"), count);
                        data.job = msg;

               	AddData(m_list,&data);
                count++;
        }
	
	return;
}

void MyFrame1::AddData(wxListCtrl *m_list, StationListData *pdata)
{
	long nPos = m_list->GetItemCount();

        long            nSubPos = 1;
        m_list->InsertItem( nPos, pdata->name);
        m_list->SetItem(nPos, nSubPos++, pdata->age);
        m_list->SetItem(nPos, nSubPos++, pdata->sex);
	m_list->SetItem(nPos, nSubPos++, pdata->job);

	return;
}

void MyFrame1::OnButtonClick(wxCommandEvent& event )
{
    //wxMessageBox( WxTextServerPath->GetValue());
    //wxFrame::EndModal(wxID_OK);
        exit(1);
}

